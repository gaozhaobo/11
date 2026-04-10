"""
Quest -> Robot bridge.

Polls Quest stream data from Flask and publishes robot commands back to Flask.
This keeps Unity/Quest side unchanged while preparing commands for Qt + MATLAB IK runtime.
"""

from __future__ import annotations

import argparse
import json
import math
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any
from urllib import error, parse, request


@dataclass
class BridgeConfig:
    server_url: str = "http://127.0.0.1:5555"
    robot_index: int = 1
    hand: str = "right"
    poll_hz: float = 20.0
    pos_scale: float = 1000.0  # m -> mm
    alpha: float = 0.35  # low-pass filter
    x_min: float = -600.0
    x_max: float = 600.0
    y_min: float = -600.0
    y_max: float = 600.0
    z_min: float = 0.0
    z_max: float = 800.0
    # 4x4 homogeneous transform from Quest world to robot base frame.
    # Default keeps old behavior: x<-x, y<-z, z<-y.
    t_robot_from_quest: list[list[float]] = field(
        default_factory=lambda: [
            [1.0, 0.0, 0.0, 0.0],
            [0.0, 0.0, 1.0, 0.0],
            [0.0, 1.0, 0.0, 0.0],
            [0.0, 0.0, 0.0, 1.0],
        ]
    )


class QuestRobotBridge:
    def __init__(self, config: BridgeConfig) -> None:
        self.cfg = config
        self._last_filtered: dict[str, float] | None = None
        self._last_timestamp: int = 0

    def run_forever(self) -> None:
        period = 1.0 / max(self.cfg.poll_hz, 1.0)
        print(
            "[Bridge] running at "
            f"{self.cfg.poll_hz:.1f} Hz, source={self.cfg.hand}_hand, robot_index={self.cfg.robot_index}"
        )

        while True:
            start = time.time()
            try:
                latest = self.fetch_latest_stream()
                command = self.build_robot_command(latest)
                if command is not None:
                    self.publish_robot_command(command)
                    self._last_timestamp = command["timestamp"]
            except Exception as exc:  # keep bridge alive
                print(f"[Bridge] error: {exc}")

            elapsed = time.time() - start
            sleep_time = period - elapsed
            if sleep_time > 0:
                time.sleep(sleep_time)

    def fetch_latest_stream(self) -> dict[str, Any]:
        query = parse.urlencode({"since": self._last_timestamp})
        url = f"{self.cfg.server_url}/api/stream/latest?{query}"
        return self._http_json("GET", url)

    def build_robot_command(self, latest: dict[str, Any]) -> dict[str, Any] | None:
        hand_key = "left_hand" if self.cfg.hand == "left" else "right_hand"
        hand_data = latest.get(hand_key)
        if not hand_data:
            return None

        joints = hand_data.get("joints") or []
        if len(joints) < 2:  # need at least palm + wrist
            return None

        palm = joints[0].get("position") or {"x": 0.0, "y": 0.0, "z": 0.0}
        wrist_rot = (joints[1].get("rotation") if len(joints) > 1 else None) or {
            "x": 0.0,
            "y": 0.0,
            "z": 0.0,
            "w": 1.0,
        }

        quest_pos_m = [
            float(palm.get("x", 0.0)),
            float(palm.get("y", 0.0)),
            float(palm.get("z", 0.0)),
        ]
        quest_q = _normalize_quat(
            [
                float(wrist_rot.get("x", 0.0)),
                float(wrist_rot.get("y", 0.0)),
                float(wrist_rot.get("z", 0.0)),
                float(wrist_rot.get("w", 1.0)),
            ]
        )

        robot_pos_m, robot_q = _transform_pose_quest_to_robot(
            quest_pos_m,
            quest_q,
            self.cfg.t_robot_from_quest,
        )

        # Convert meters to millimeters and apply workspace clamp + smoothing.
        pose = {
            "x": self._clamp(robot_pos_m[0] * self.cfg.pos_scale, self.cfg.x_min, self.cfg.x_max),
            "y": self._clamp(robot_pos_m[1] * self.cfg.pos_scale, self.cfg.y_min, self.cfg.y_max),
            "z": self._clamp(robot_pos_m[2] * self.cfg.pos_scale, self.cfg.z_min, self.cfg.z_max),
            "qx": robot_q[0],
            "qy": robot_q[1],
            "qz": robot_q[2],
            "qw": robot_q[3],
        }

        filtered = self._low_pass(pose)
        timestamp = int(hand_data.get("timestamp") or time.time() * 1000)

        return {
            "timestamp": timestamp,
            "source": "quest_robot_bridge",
            "mode": "ik_pose",
            "robot_index": self.cfg.robot_index,
            "target_pose": filtered,
            "target_joints": None,
            "meta": {
                "hand": self.cfg.hand,
                "note": "Absolute mapping: Palm position + Wrist quaternion transformed to robot base frame",
                "quest_joint_mapping": {
                    "position_joint": 0,
                    "orientation_joint": 1,
                },
                "workspace_mm": {
                    "x": [self.cfg.x_min, self.cfg.x_max],
                    "y": [self.cfg.y_min, self.cfg.y_max],
                    "z": [self.cfg.z_min, self.cfg.z_max],
                },
            },
        }

    def publish_robot_command(self, command: dict[str, Any]) -> None:
        url = f"{self.cfg.server_url}/api/robot/command"
        self._http_json("POST", url, command)

    def _low_pass(self, pose: dict[str, float]) -> dict[str, float]:
        if self._last_filtered is None:
            self._last_filtered = dict(pose)
            return pose

        a = self.cfg.alpha
        result = {
            key: (1.0 - a) * self._last_filtered[key] + a * value
            for key, value in pose.items()
        }

        q_norm = math.sqrt(
            result["qx"] ** 2 + result["qy"] ** 2 + result["qz"] ** 2 + result["qw"] ** 2
        )
        if q_norm > 1e-8:
            result["qx"] /= q_norm
            result["qy"] /= q_norm
            result["qz"] /= q_norm
            result["qw"] /= q_norm

        self._last_filtered = result
        return result

    @staticmethod
    def _clamp(value: float, vmin: float, vmax: float) -> float:
        return max(vmin, min(vmax, value))

    @staticmethod
    def _http_json(method: str, url: str, payload: dict[str, Any] | None = None) -> dict[str, Any]:
        data = None
        headers = {"Accept": "application/json"}

        if payload is not None:
            data = json.dumps(payload).encode("utf-8")
            headers["Content-Type"] = "application/json"

        req = request.Request(url=url, data=data, headers=headers, method=method)
        try:
            with request.urlopen(req, timeout=2.0) as resp:
                body = resp.read().decode("utf-8")
                return json.loads(body) if body else {}
        except error.HTTPError as exc:
            text = exc.read().decode("utf-8", errors="replace")
            raise RuntimeError(f"HTTP {exc.code} {method} {url}: {text}") from exc


# -----------------------------
# Pose transform math utilities
# -----------------------------

def _normalize_quat(q: list[float]) -> list[float]:
    n = math.sqrt(q[0] ** 2 + q[1] ** 2 + q[2] ** 2 + q[3] ** 2)
    if n < 1e-8:
        return [0.0, 0.0, 0.0, 1.0]
    return [q[0] / n, q[1] / n, q[2] / n, q[3] / n]


def _quat_to_rot(q: list[float]) -> list[list[float]]:
    x, y, z, w = q
    return [
        [1.0 - 2.0 * (y * y + z * z), 2.0 * (x * y - z * w), 2.0 * (x * z + y * w)],
        [2.0 * (x * y + z * w), 1.0 - 2.0 * (x * x + z * z), 2.0 * (y * z - x * w)],
        [2.0 * (x * z - y * w), 2.0 * (y * z + x * w), 1.0 - 2.0 * (x * x + y * y)],
    ]


def _rot_to_quat(r: list[list[float]]) -> list[float]:
    trace = r[0][0] + r[1][1] + r[2][2]
    if trace > 0.0:
        s = math.sqrt(trace + 1.0) * 2.0
        w = 0.25 * s
        x = (r[2][1] - r[1][2]) / s
        y = (r[0][2] - r[2][0]) / s
        z = (r[1][0] - r[0][1]) / s
    elif r[0][0] > r[1][1] and r[0][0] > r[2][2]:
        s = math.sqrt(1.0 + r[0][0] - r[1][1] - r[2][2]) * 2.0
        w = (r[2][1] - r[1][2]) / s
        x = 0.25 * s
        y = (r[0][1] + r[1][0]) / s
        z = (r[0][2] + r[2][0]) / s
    elif r[1][1] > r[2][2]:
        s = math.sqrt(1.0 + r[1][1] - r[0][0] - r[2][2]) * 2.0
        w = (r[0][2] - r[2][0]) / s
        x = (r[0][1] + r[1][0]) / s
        y = 0.25 * s
        z = (r[1][2] + r[2][1]) / s
    else:
        s = math.sqrt(1.0 + r[2][2] - r[0][0] - r[1][1]) * 2.0
        w = (r[1][0] - r[0][1]) / s
        x = (r[0][2] + r[2][0]) / s
        y = (r[1][2] + r[2][1]) / s
        z = 0.25 * s

    return _normalize_quat([x, y, z, w])


def _mat3_mul(a: list[list[float]], b: list[list[float]]) -> list[list[float]]:
    return [
        [
            a[row][0] * b[0][col] + a[row][1] * b[1][col] + a[row][2] * b[2][col]
            for col in range(3)
        ]
        for row in range(3)
    ]


def _mat3_vec_mul(a: list[list[float]], v: list[float]) -> list[float]:
    return [
        a[0][0] * v[0] + a[0][1] * v[1] + a[0][2] * v[2],
        a[1][0] * v[0] + a[1][1] * v[1] + a[1][2] * v[2],
        a[2][0] * v[0] + a[2][1] * v[1] + a[2][2] * v[2],
    ]


def _transform_pose_quest_to_robot(
    p_quest_m: list[float],
    q_quest: list[float],
    t_robot_from_quest: list[list[float]],
) -> tuple[list[float], list[float]]:
    r_map = [
        [t_robot_from_quest[0][0], t_robot_from_quest[0][1], t_robot_from_quest[0][2]],
        [t_robot_from_quest[1][0], t_robot_from_quest[1][1], t_robot_from_quest[1][2]],
        [t_robot_from_quest[2][0], t_robot_from_quest[2][1], t_robot_from_quest[2][2]],
    ]
    t_map = [
        t_robot_from_quest[0][3],
        t_robot_from_quest[1][3],
        t_robot_from_quest[2][3],
    ]

    p_robot = _mat3_vec_mul(r_map, p_quest_m)
    p_robot = [p_robot[0] + t_map[0], p_robot[1] + t_map[1], p_robot[2] + t_map[2]]

    r_quest = _quat_to_rot(q_quest)
    r_robot = _mat3_mul(r_map, r_quest)
    q_robot = _rot_to_quat(r_robot)

    return p_robot, q_robot


def load_config_from_file(path: str | None) -> dict[str, Any]:
    if not path:
        return {}

    p = Path(path)
    if not p.exists():
        raise FileNotFoundError(f"Config file not found: {path}")

    with p.open("r", encoding="utf-8") as f:
        return json.load(f)


def parse_args() -> BridgeConfig:
    parser = argparse.ArgumentParser(description="Quest to robot bridge")
    parser.add_argument("--server", default="http://127.0.0.1:5555")
    parser.add_argument("--robot-index", type=int, default=1)
    parser.add_argument("--hand", choices=["left", "right"], default="right")
    parser.add_argument("--poll-hz", type=float, default=20.0)
    parser.add_argument("--config", default=None, help="Optional JSON config file for calibration and limits")
    args = parser.parse_args()

    cfg_file = load_config_from_file(args.config)
    cfg = BridgeConfig(
        server_url=args.server,
        robot_index=args.robot_index,
        hand=args.hand,
        poll_hz=args.poll_hz,
    )

    for k, v in cfg_file.items():
        if hasattr(cfg, k):
            setattr(cfg, k, v)

    return cfg


if __name__ == "__main__":
    config = parse_args()
    QuestRobotBridge(config).run_forever()

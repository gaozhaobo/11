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
from dataclasses import dataclass
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


class QuestRobotBridge:
    def __init__(self, config: BridgeConfig) -> None:
        self.cfg = config
        self._last_filtered: dict[str, float] | None = None
        self._last_timestamp: int = 0

    def run_forever(self) -> None:
        period = 1.0 / max(self.cfg.poll_hz, 1.0)
        print(f"[Bridge] running at {self.cfg.poll_hz:.1f} Hz, source={self.cfg.hand}_hand")

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

        # Convert Quest meters to robot millimeters and apply simple clamp + smoothing.
        pose = {
            "x": self._clamp(palm.get("x", 0.0) * self.cfg.pos_scale, self.cfg.x_min, self.cfg.x_max),
            "y": self._clamp(palm.get("z", 0.0) * self.cfg.pos_scale, self.cfg.y_min, self.cfg.y_max),
            "z": self._clamp(palm.get("y", 0.0) * self.cfg.pos_scale, self.cfg.z_min, self.cfg.z_max),
            "qx": wrist_rot.get("x", 0.0),
            "qy": wrist_rot.get("y", 0.0),
            "qz": wrist_rot.get("z", 0.0),
            "qw": wrist_rot.get("w", 1.0),
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
                "note": "Use MATLAB IK DLL in Qt runtime to convert pose->joint targets",
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
        result = {}
        for key, value in pose.items():
            if key.startswith("q"):
                # normalize later
                result[key] = (1 - a) * self._last_filtered[key] + a * value
            else:
                result[key] = (1 - a) * self._last_filtered[key] + a * value

        norm = math.sqrt(result["qx"] ** 2 + result["qy"] ** 2 + result["qz"] ** 2 + result["qw"] ** 2)
        if norm > 1e-6:
            result["qx"] /= norm
            result["qy"] /= norm
            result["qz"] /= norm
            result["qw"] /= norm

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


def parse_args() -> BridgeConfig:
    parser = argparse.ArgumentParser(description="Quest to robot bridge")
    parser.add_argument("--server", default="http://127.0.0.1:5555")
    parser.add_argument("--robot-index", type=int, default=1)
    parser.add_argument("--hand", choices=["left", "right"], default="right")
    parser.add_argument("--poll-hz", type=float, default=20.0)
    args = parser.parse_args()

    return BridgeConfig(
        server_url=args.server,
        robot_index=args.robot_index,
        hand=args.hand,
        poll_hz=args.poll_hz,
    )


if __name__ == "__main__":
    cfg = parse_args()
    QuestRobotBridge(cfg).run_forever()

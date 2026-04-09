# XR Data Recorder Server

Flask server for receiving and serving hand/head tracking data from Quest 3.

## Features

- Real-time streaming data reception from Quest 3
- Event logging with timestamps
- CSV file upload and download
- Web dashboard for monitoring
- Streaming playback endpoint for PC visualization

## Setup

```bash
# Create virtual environment (recommended)
python3 -m venv venv
source venv/bin/activate  # macOS/Linux
# or: venv\Scripts\activate  # Windows

# Install dependencies
pip install -r requirements.txt

# Run server
python app.py
```

The server runs on `http://0.0.0.0:5555` by default.

## Web Dashboard

Open `http://localhost:5555` in your browser to access the web UI.

**Features:**
- Start/Stop recording sessions
- Set filename prefix for saved files
- View real-time event log
- Monitor connection status
- Download recorded CSV files

**Usage:**
1. Enter a filename prefix (e.g., "participant_01")
2. Click "Start Session"
3. Begin recording on Quest 3
4. Events and data will appear in real-time
5. Click "Stop Session" when done
6. Download files using the download buttons

## API Endpoints

### Session Management

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/start` | POST | Start recording session |
| `/api/stop` | POST | Stop recording session |
| `/api/data` | GET | Get session status and data |

### Event Logging

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/input` | POST | Log event with timestamp |

### Real-time Streaming (Quest → Server)

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/stream/head` | POST | Send head tracking data |
| `/api/stream/hand` | POST | Send hand tracking data |

### Real-time Streaming (Server → PC Playback)

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/stream/latest` | GET | Get latest frame data |
| `/api/stream/head/latest` | GET | Get latest head data |
| `/api/stream/hand/latest` | GET | Get latest hand data |

### File Management

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/upload` | POST | Upload CSV file |
| `/api/download?type=...` | GET | Download data files |

**Download Types:**
- `data` - Event log CSV
- `uploaded` - Uploaded files (requires `filename` param)
- `head_stream` - Head tracking CSV
- `left_hand_stream` - Left hand CSV
- `right_hand_stream` - Right hand CSV
- `all_streams` - List all available stream files

## Network Configuration

### Quest 3 Setup

1. Find your PC's IP address:
   ```bash
   # macOS
   ipconfig getifaddr en0
   
   # Windows
   ipconfig
   ```

2. Configure `StreamingDataSender` on Quest with the PC's IP address.

3. Ensure both devices are on the same network.

## Data Format

### Head Tracking

```json
{
  "timestamp": 1707612345678,
  "position": {"x": 0.0, "y": 1.6, "z": 0.0},
  "rotation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 1.0}
}
```

### Hand Tracking (26 joints)

```json
{
  "timestamp": 1707612345678,
  "hand": "left",
  "joints": [
    {
      "position": {"x": 0.0, "y": 0.0, "z": 0.0},
      "rotation": {"x": 0.0, "y": 0.0, "z": 0.0, "w": 1.0}
    }
    // ... 26 joints total
  ]
}
```

### Joint Order (HandJointId)

0. Palm
1. Wrist
2-5. Thumb (Metacarpal, Proximal, Distal, Tip)
6-10. Index (Metacarpal, Proximal, Intermediate, Distal, Tip)
11-15. Middle (same pattern)
16-20. Ring (same pattern)
21-25. Little/Pinky (same pattern)

## Output Files

When recording is active, the server saves:

- `data/{prefix}_{timestamp}.csv` - Event log
- `uploads/{prefix}_head_stream.csv` - Head tracking
- `uploads/{prefix}_left_hand_stream.csv` - Left hand tracking
- `uploads/{prefix}_right_hand_stream.csv` - Right hand tracking


## Quest ↔ Robot Bridge (new)

This repo now includes a bridge script for Quest-to-robot linkage:

```bash
python quest_robot_bridge.py --server http://127.0.0.1:5555 --robot-index 1 --hand right --poll-hz 20
```

Bridge behavior:
- Reads `/api/stream/latest` from Flask.
- Converts Quest hand pose (meters) to robot pose (millimeters).
- Applies simple workspace clamp + low-pass smoothing.
- Publishes normalized robot command to `/api/robot/command`.
- Qt/robot runtime can poll `/api/robot/latest` and pass pose into MATLAB IK DLL.

### Robot Bridge APIs

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/robot/command` | POST | Store latest robot command from bridge |
| `/api/robot/latest` | GET | Get latest robot command for Qt polling |

### Suggested deployment order

1. Start this Flask server (`python app.py`).
2. Start `quest_robot_bridge.py` on the robot control PC.
3. Run Quest app (`StreamingSender`) to send hand/head stream.
4. Qt side now has a polling client (`quest_robot_api_client.*`) and a wired handler (`MainWindow::onQuestRobotCommandReceived`) that converts pose quaternion to 4x4 `mwArray` and calls `myrobots.Robot_ikine(...)`.
5. Keep emergency stop and workspace limits enabled in Qt runtime.

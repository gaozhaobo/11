# Quest 3 XR Data Collection & Playback

A Unity project for recording, streaming, and visualizing hand and head tracking data from Meta Quest 3.

## Features

- **Real-time Streaming**: Stream hand/head tracking data from Quest 3 to PC for live visualization
- **CSV Recording**: Save tracking data locally on Quest and upload to server
- **Event Logging**: Send timestamped events/markers from Quest to server
- **Playback System**: Visualize recorded CSV files with synchronized timeline controls
- **Web Dashboard**: Monitor recording sessions and download data via browser

## Project Structure

```
Quest3DataCollectionDemo/
├── Assets/
│   ├── Scenes/
│   │   ├── FilePlayback.unity      # Playback from CSV files
│   │   ├── StreamingPlayback.unity # Real-time streaming receiver (PC)
│   │   └── StreamingSender.unity   # Recording & streaming sender (Quest)
│   └── Scripts/
│       ├── Playback/               # CSV playback components
│       ├── Streaming/              # Real-time streaming components
│       └── Editor/                 # Editor utilities
└── Server/                         # Flask data server (see Server/README.md)
```

## Scenes

### StreamingSender (Quest 3)
Records hand/head tracking data and streams it to the server in real-time.

**Components:**
- `StreamingDataSender` - Captures tracking data from OVRHands and streams to server
- `OVRCameraRig` - Quest camera rig with hand tracking

**Settings:**
| Setting | Description |
|---------|-------------|
| `serverIP` | IP address of the PC running the Flask server |
| `serverPort` | Server port (default: 5555) |
| `streamToServer` | Enable real-time streaming to server |
| `saveLocalCSV` | Save data locally on Quest (in addition to streaming) |
| `autoStartOnAwake` | Start recording automatically when app launches |
| `recordingInterval` | Time between samples (default: 0.1s = 10Hz) |

**Public Methods (for custom integration):**
```csharp
var sender = GetComponent<StreamingDataSender>();

// Recording control
sender.StartRecording();
sender.StopRecording();

// Send custom event/marker to server
sender.SendEvent("USER_ACTION: Button pressed");

// Upload locally saved CSV files to server (if saveLocalCSV was enabled)
sender.UploadCSVFiles();
```

### StreamingPlayback (PC)
Receives and visualizes real-time streaming data from Quest.

**Components:**
- `StreamingDataReceiver` - Polls server for latest tracking data
- `StreamingVisualizer` - Renders hands and head visualization

**Settings:**
- `serverIP` - Server address (use `localhost` if running on same PC)
- `pollingInterval` - How often to fetch new data (default: 0.08s)

### FilePlayback (PC)
Plays back recorded CSV files with timeline controls.

**Components:**
- `PlaybackController` - Timeline management (play, pause, seek, speed)
- `HandVisualPlayback` - Renders hand joints from CSV data
- `CameraSphereTracker` - Renders head position and gaze direction
- `PlaybackUI` - On-screen controls and keyboard shortcuts

**Keyboard Controls:**
| Key | Action |
|-----|--------|
| `Space` | Play/Pause |
| `S` | Stop |
| `R` | Restart |
| `←/→` | Skip backward/forward |
| `↑/↓` | Speed up/down |
| `L` | Toggle loop |
| `H` | Hide control panel |

## Server Setup

See [Server/README.md](Server/README.md) for detailed server documentation.

**Quick Start:**
```bash
cd Server
python3 -m venv venv
source venv/bin/activate  # Windows: venv\Scripts\activate
pip install -r requirements.txt
python app.py
```

Server runs at `http://0.0.0.0:5555` - Open in browser for web dashboard.

## Building for Quest 3

### Before Building and Running on Quest

1. Start the Flask server on your PC
2. Note your PC's local IP address (e.g., `192.168.x.x`)
3. Update `StreamingDataSender.serverIP` in the scene before building

### Build Scene
Build the **`StreamingSender`** scene for Quest 3.

### Build Steps (should all be preconfigured so jump to step 5)

1. **Open Build Settings**: File → Build Settings
2. **Add Scene**: 
   - Click "Add Open Scenes" or drag `Assets/Scenes/StreamingSender.unity`
   - Remove any other scenes from the build list
3. **Switch Platform**:
   - Select "Android" 
   - Click "Switch Platform"
4. **Configure Player Settings** (Edit → Project Settings → Player):
   - Under "Other Settings": 
     - Minimum API Level: Android 10.0 (API level 29)
     - Target API Level: Automatic (highest installed)
     - Scripting Backend: IL2CPP
     - Target Architectures: ARM64
6. **Build**:
   - Click "Build" or "Build and Run"
   - Save as `.apk` file
   - If "Build and Run", ensure Quest is connected via USB with developer mode enabled

## Quick Start

### Real-time Streaming

1. **Start the server** on your PC:
   ```bash
   cd Server && source venv/bin/activate && python app.py
   ```

2. **Note your PC's IP address** (e.g., `192.168.1.100`)

3. **Configure Quest scene**:
   - Open `StreamingSender` scene
   - Set `StreamingDataSender.serverIP` to your PC's IP
   - Build and deploy to Quest 3

4. **Configure PC playback**:
   - Open `StreamingPlayback` scene
   - Set `StreamingDataReceiver.serverIP` to `localhost` or your server's IP if you happen to run them seperately
   - Press Play in Unity Editor

5. **Run on Quest**: The app will auto-start streaming when launched

### CSV File Playback

1. Download CSV files from the server web dashboard
2. Place CSV files in `Assets/` or reference via TextAsset
3. Open `FilePlayback` scene
4. Assign CSV files to `HandVisualPlayback`:
   - `leftHandDataFile`
   - `rightHandDataFile`
5. Assign head CSV to `CameraSphereTracker`:
   - `headDataFile`
6. Press Play and use keyboard controls

## Data Formats

### Hand Data (26 joints per hand)
```csv
timestamp,joint_0_pos_x,joint_0_pos_y,joint_0_pos_z,joint_0_rot_x,joint_0_rot_y,joint_0_rot_z,joint_0_rot_w,...
```

Joint order follows `HandJointId` enum:
| Index | Joint |
|-------|-------|
| 0 | Palm |
| 1 | Wrist |
| 2-5 | Thumb (Metacarpal → Tip) |
| 6-10 | Index (Metacarpal → Tip) |
| 11-15 | Middle (Metacarpal → Tip) |
| 16-20 | Ring (Metacarpal → Tip) |
| 21-25 | Pinky (Metacarpal → Tip) |

### Head Data
```csv
timestamp,pos_x,pos_y,pos_z,rot_x,rot_y,rot_z,rot_w
```

### Events
```csv
timestamp,string
```

## Requirements

- **Unity**: Unity 6 (6000.x) or later
- **Meta XR SDK**: v78.0 (tested)
- **Quest**: Meta Quest 3
- **Python**: 3.8+
- **Flask**: See `Server/requirements.txt`

## License

MIT

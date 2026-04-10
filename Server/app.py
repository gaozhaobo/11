"""
XR Data Recorder Server
Flask server for receiving and serving hand/head tracking data from Quest 3.
"""

from flask import Flask, request, jsonify, send_from_directory, render_template
from werkzeug.utils import secure_filename
import os
import csv
import time
import threading
from typing import Optional, Dict, List, Any

# =============================================================================
# Configuration
# =============================================================================

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.join(BASE_DIR, 'data')
UPLOADS_DIR = os.path.join(BASE_DIR, 'uploads')
ALLOWED_EXTENSIONS = {'csv'}
MAX_RECENT_EVENTS = 100
DEFAULT_PORT = 5555

# =============================================================================
# Application Setup
# =============================================================================

app = Flask(__name__)

# Thread locks
_state_lock = threading.Lock()
_stream_lock = threading.Lock()

# Session state
_server_started = False
_current_filename: Optional[str] = None
_current_data: List[Dict[str, Any]] = []
_uploaded_files: List[str] = []
_filename_prefix = ''

# Real-time streaming state
_latest_head: Optional[Dict] = None
_latest_left_hand: Optional[Dict] = None
_latest_right_hand: Optional[Dict] = None
_latest_events: List[Dict] = []
_latest_robot_command: Optional[Dict] = None
_robot_accept_commands: bool = True


# =============================================================================
# Helper Functions
# =============================================================================

def allowed_file(filename: str) -> bool:
    """Check if file extension is allowed."""
    return '.' in filename and filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS


def ensure_dirs() -> None:
    """Create required directories if they don't exist."""
    for directory in [DATA_DIR, UPLOADS_DIR]:
        os.makedirs(directory, exist_ok=True)


def clean_dirs() -> None:
    """Clean all files from data directories."""
    for directory in [DATA_DIR, UPLOADS_DIR]:
        if os.path.exists(directory):
            for item in os.listdir(directory):
                item_path = os.path.join(directory, item)
                try:
                    if os.path.isfile(item_path):
                        os.unlink(item_path)
                except Exception as e:
                    print(f"Error deleting {item_path}: {e}")
        else:
            os.makedirs(directory)


def sanitize_filename(name: str) -> str:
    """Sanitize filename for safe storage."""
    return secure_filename(name)


# =============================================================================
# Session Management Endpoints
# =============================================================================

@app.route('/api/start', methods=['POST'])
def api_start():
    """Start a new recording session."""
    global _server_started, _current_filename, _current_data
    global _uploaded_files, _filename_prefix
    global _latest_head, _latest_left_hand, _latest_right_hand, _latest_events
    
    with _state_lock:
        if _server_started:
            return jsonify({'status': 'already_started'}), 200
        
        data = request.get_json() or {}
        prefix = sanitize_filename(data.get('filename_prefix', '').strip()) or 'file'
        timestamp = int(time.time())
        
        ensure_dirs()
        
        filename = f"{prefix}_{timestamp}.csv"
        _current_filename = filename
        _current_data = []
        _uploaded_files = []
        _filename_prefix = prefix
        
        # Reset streaming state
        with _stream_lock:
            _latest_head = None
            _latest_left_hand = None
            _latest_right_hand = None
            _latest_events = []
        
        # Create event file with header
        filepath = os.path.join(DATA_DIR, filename)
        with open(filepath, 'w', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow(['timestamp', 'string'])
        
        _server_started = True
        return jsonify({'status': 'started', 'filename': filename}), 200


@app.route('/api/stop', methods=['POST'])
def api_stop():
    """Stop the current recording session."""
    global _server_started, _current_filename, _current_data
    global _uploaded_files, _filename_prefix
    
    with _state_lock:
        if not _server_started:
            return jsonify({'status': 'already_stopped'}), 200
        
        _server_started = False
        _current_filename = None
        _current_data = []
        _uploaded_files = []
        _filename_prefix = ''
        clean_dirs()
        
        return jsonify({'status': 'stopped'}), 200


# =============================================================================
# Event Logging Endpoints
# =============================================================================

@app.route('/api/input', methods=['POST'])
def api_input():
    """Log an event with timestamp and string message."""
    global _current_data, _latest_events
    
    with _state_lock:
        if not _server_started or not _current_filename:
            return jsonify({'status': 'ignored'}), 200
        
        data = request.get_json()
        timestamp = data.get('timestamp')
        message = data.get('string')
        
        if not isinstance(timestamp, int) or not isinstance(message, str):
            return jsonify({'status': 'invalid'}), 400
        
        entry = {'timestamp': timestamp, 'string': message}
        _current_data.append(entry)
        
        # Append to CSV
        filepath = os.path.join(DATA_DIR, _current_filename)
        with open(filepath, 'a', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            writer.writerow([timestamp, message])
        
        # Add to streaming buffer
        with _stream_lock:
            _latest_events.append(entry)
            if len(_latest_events) > MAX_RECENT_EVENTS:
                _latest_events.pop(0)
        
        return jsonify({'status': 'ok'}), 200


# =============================================================================
# Real-time Streaming Input (from Quest)
# =============================================================================

@app.route('/api/stream/head', methods=['POST'])
def api_stream_head():
    """Receive real-time head tracking data from Quest."""
    global _latest_head
    
    data = request.get_json()
    timestamp = data.get('timestamp')
    position = data.get('position')
    rotation = data.get('rotation')
    
    if timestamp is None or position is None or rotation is None:
        return jsonify({'status': 'invalid'}), 400
    
    frame = {
        'timestamp': timestamp,
        'position': position,
        'rotation': rotation
    }
    
    with _stream_lock:
        _latest_head = frame
    
    # Save to CSV if recording
    _save_head_to_csv(timestamp, position, rotation)
    
    return jsonify({'status': 'ok'}), 200


@app.route('/api/stream/hand', methods=['POST'])
def api_stream_hand():
    """Receive real-time hand tracking data from Quest."""
    global _latest_left_hand, _latest_right_hand
    
    data = request.get_json()
    timestamp = data.get('timestamp')
    hand = data.get('hand')
    joints = data.get('joints')
    
    if timestamp is None or hand is None or joints is None:
        return jsonify({'status': 'invalid'}), 400
    
    frame = {
        'timestamp': timestamp,
        'hand': hand,
        'joints': joints
    }
    
    with _stream_lock:
        if hand == 'left':
            _latest_left_hand = frame
        else:
            _latest_right_hand = frame
    
    # Save to CSV if recording
    _save_hand_to_csv(timestamp, hand, joints)
    
    return jsonify({'status': 'ok'}), 200


def _save_head_to_csv(timestamp: int, position: Dict, rotation: Dict) -> None:
    """Save head data to CSV file."""
    with _state_lock:
        if not _server_started or not _filename_prefix:
            return
        
        filepath = os.path.join(UPLOADS_DIR, f"{_filename_prefix}_head_stream.csv")
        file_exists = os.path.exists(filepath)
        
        with open(filepath, 'a', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            if not file_exists:
                writer.writerow([
                    'timestamp', 'pos_x', 'pos_y', 'pos_z',
                    'rot_x', 'rot_y', 'rot_z', 'rot_w'
                ])
            writer.writerow([
                timestamp,
                position['x'], position['y'], position['z'],
                rotation['x'], rotation['y'], rotation['z'], rotation['w']
            ])


def _save_hand_to_csv(timestamp: int, hand: str, joints: List[Dict]) -> None:
    """Save hand data to CSV file."""
    with _state_lock:
        if not _server_started or not _filename_prefix:
            return
        
        filepath = os.path.join(UPLOADS_DIR, f"{_filename_prefix}_{hand}_hand_stream.csv")
        file_exists = os.path.exists(filepath)
        
        with open(filepath, 'a', newline='', encoding='utf-8') as f:
            writer = csv.writer(f)
            if not file_exists:
                header = ['timestamp']
                for i in range(len(joints)):
                    header.extend([
                        f'joint_{i}_pos_x', f'joint_{i}_pos_y', f'joint_{i}_pos_z',
                        f'joint_{i}_rot_x', f'joint_{i}_rot_y', f'joint_{i}_rot_z', f'joint_{i}_rot_w'
                    ])
                writer.writerow(header)
            
            row = [timestamp]
            for joint in joints:
                pos = joint.get('position', {})
                rot = joint.get('rotation', {})
                row.extend([
                    pos.get('x', 0), pos.get('y', 0), pos.get('z', 0),
                    rot.get('x', 0), rot.get('y', 0), rot.get('z', 0), rot.get('w', 1)
                ])
            writer.writerow(row)


# =============================================================================
# Real-time Streaming Output (to playback clients)
# =============================================================================

@app.route('/api/stream/latest', methods=['GET'])
def api_stream_latest():
    """Get latest frame data for real-time playback."""
    since = request.args.get('since', 0, type=int)
    
    with _stream_lock:
        result = {
            'server_started': _server_started,
            'head': _latest_head,
            'left_hand': _latest_left_hand,
            'right_hand': _latest_right_hand,
            'events': [e for e in _latest_events if e['timestamp'] > since]
        }
    
    return jsonify(result), 200


@app.route('/api/stream/head/latest', methods=['GET'])
def api_stream_head_latest():
    """Get just the latest head data."""
    with _stream_lock:
        return jsonify(_latest_head or {}), 200


@app.route('/api/stream/hand/latest', methods=['GET'])
def api_stream_hand_latest():
    """Get latest hand data."""
    hand = request.args.get('hand', 'both')
    
    with _stream_lock:
        if hand == 'left':
            return jsonify(_latest_left_hand or {}), 200
        elif hand == 'right':
            return jsonify(_latest_right_hand or {}), 200
        else:
            return jsonify({
                'left': _latest_left_hand,
                'right': _latest_right_hand
            }), 200




# =============================================================================
# Robot Control Bridge Endpoints
# =============================================================================

@app.route('/api/robot/command', methods=['POST'])
def api_robot_command():
    """Accept robot command produced by a bridge process."""
    global _latest_robot_command, _robot_accept_commands

    data = request.get_json() or {}
    timestamp = data.get('timestamp')
    if timestamp is None:
        timestamp = int(time.time() * 1000)

    command = {
        'timestamp': timestamp,
        'source': data.get('source', 'quest_bridge'),
        'mode': data.get('mode', 'ik_pose'),
        'robot_index': data.get('robot_index', 1),
        'target_pose': data.get('target_pose'),
        'target_joints': data.get('target_joints'),
        'meta': data.get('meta', {})
    }

    with _stream_lock:
        if not _robot_accept_commands:
            return jsonify({'status': 'ignored', 'reason': 'robot_control_disabled'}), 200
        _latest_robot_command = command

    return jsonify({'status': 'ok'}), 200


@app.route('/api/robot/latest', methods=['GET'])
def api_robot_latest():
    """Expose the most recent robot command for Qt/robot runtime polling."""
    with _stream_lock:
        return jsonify(_latest_robot_command or {}), 200


@app.route('/api/robot/control', methods=['GET', 'POST'])
def api_robot_control():
    """Get or set robot command forwarding controls."""
    global _robot_accept_commands, _latest_robot_command

    if request.method == 'GET':
        with _stream_lock:
            return jsonify({
                'enabled': _robot_accept_commands,
                'has_command': _latest_robot_command is not None
            }), 200

    data = request.get_json() or {}
    action = data.get('action')

    with _stream_lock:
        if action == 'enable':
            _robot_accept_commands = True
        elif action == 'disable':
            _robot_accept_commands = False
        elif action == 'clear_latest':
            _latest_robot_command = None
        elif action == 'disable_and_clear':
            _robot_accept_commands = False
            _latest_robot_command = None
        else:
            return jsonify({
                'status': 'invalid_action',
                'valid_actions': ['enable', 'disable', 'clear_latest', 'disable_and_clear']
            }), 400

        return jsonify({
            'status': 'ok',
            'enabled': _robot_accept_commands,
            'has_command': _latest_robot_command is not None
        }), 200


# =============================================================================
# Data & File Management
# =============================================================================

@app.route('/api/data', methods=['GET'])
def api_data():
    """Get current session data and status."""
    with _state_lock:
        return jsonify({
            'data': _current_data,
            'server_started': _server_started,
            'uploaded_files': _uploaded_files,
            'filename': _current_filename
        }), 200


@app.route('/api/upload', methods=['POST'])
def api_upload():
    """Upload a CSV file from Quest."""
    global _uploaded_files
    
    with _state_lock:
        if not _server_started:
            return jsonify({'status': 'ignored'}), 200
        
        if 'file' not in request.files:
            return jsonify({'status': 'no_file'}), 400
        
        file = request.files['file']
        if file.filename == '':
            return jsonify({'status': 'no_filename'}), 400
        
        if not allowed_file(file.filename):
            return jsonify({'status': 'not_csv'}), 400
        
        filename = sanitize_filename(file.filename)
        save_path = os.path.join(UPLOADS_DIR, filename)
        file.save(save_path)
        
        if filename not in _uploaded_files:
            _uploaded_files.append(filename)
        
        return jsonify({'status': 'uploaded', 'filename': filename}), 200


@app.route('/api/download', methods=['GET'])
def api_download():
    """Download recorded data files."""
    file_type = request.args.get('type')
    
    with _state_lock:
        # Event data
        if file_type == 'data':
            if not _server_started or not _current_filename:
                return jsonify({'status': 'not_running'}), 400
            
            prefix = _filename_prefix or 'file'
            timestamp = _current_filename.split('_')[-1].replace('.csv', '')
            download_name = f"{prefix}_event_{timestamp}.csv"
            return send_from_directory(
                DATA_DIR, _current_filename,
                as_attachment=True, download_name=download_name
            )
        
        # Uploaded files
        elif file_type == 'uploaded':
            filename = request.args.get('filename')
            if not filename or filename not in _uploaded_files:
                return jsonify({'status': 'not_found'}), 404
            
            prefix = _filename_prefix or 'file'
            download_name = f"{prefix}_{filename}"
            return send_from_directory(
                UPLOADS_DIR, filename,
                as_attachment=True, download_name=download_name
            )
        
        # Stream files
        elif file_type in ('head_stream', 'left_hand_stream', 'right_hand_stream'):
            if not _server_started or not _filename_prefix:
                return jsonify({'status': 'not_running'}), 400
            
            stream_file = f"{_filename_prefix}_{file_type}.csv"
            filepath = os.path.join(UPLOADS_DIR, stream_file)
            
            if not os.path.exists(filepath):
                return jsonify({
                    'status': 'no_data',
                    'message': f'No {file_type} data recorded yet'
                }), 404
            
            return send_from_directory(
                UPLOADS_DIR, stream_file,
                as_attachment=True, download_name=stream_file
            )
        
        # List all stream files
        elif file_type == 'all_streams':
            if not _server_started or not _filename_prefix:
                return jsonify({'status': 'not_running'}), 400
            
            files = {}
            for stream_type in ['head', 'left_hand', 'right_hand']:
                stream_file = f"{_filename_prefix}_{stream_type}_stream.csv"
                filepath = os.path.join(UPLOADS_DIR, stream_file)
                
                if os.path.exists(filepath):
                    files[stream_type] = {
                        'filename': stream_file,
                        'size': os.path.getsize(filepath),
                        'download_url': f'/api/download?type={stream_type}_stream'
                    }
            
            return jsonify({'status': 'ok', 'files': files}), 200
        
        else:
            return jsonify({
                'status': 'invalid_type',
                'valid_types': [
                    'data', 'uploaded', 'head_stream',
                    'left_hand_stream', 'right_hand_stream', 'all_streams'
                ]
            }), 400


# =============================================================================
# Web UI
# =============================================================================

@app.route('/', methods=['GET'])
def index():
    """Serve the web dashboard."""
    return render_template('index.html')


# =============================================================================
# Main Entry Point
# =============================================================================

if __name__ == '__main__':
    ensure_dirs()
    app.run(debug=True, host='0.0.0.0', port=DEFAULT_PORT)

using UnityEngine;
using System.Collections.Generic;

namespace PurdueXRLab.XRDataRecorder.Playback
{
    /// <summary>
    /// Centralized playback controller that synchronizes all visualization components
    /// using a shared global timeline based on actual timestamps.
    /// </summary>
    public class PlaybackController : MonoBehaviour
    {
        #region Inspector Fields
        
        [Header("Playback Settings")]
        [SerializeField] private bool autoPlay = true;
        [SerializeField] private bool loop = true;
        
        [Header("Speed Presets")]
        [SerializeField] private float[] speedPresets = { 0.25f, 0.5f, 1f, 2f, 4f, 8f };
        
        #endregion
        
        #region Private Fields
        
        private int _currentSpeedIndex = 2; // Default 1x
        private PlaybackUI _playbackUI;
        
        private bool _isPlaying;
        private float _playbackSpeed = 1f;
        private float _currentTime;
        private float _totalDuration;
        private long _globalStartTimestamp = long.MaxValue;
        private long _globalEndTimestamp = long.MinValue;
        
        private readonly List<IPlaybackListener> _listeners = new();
        
        #endregion
        
        #region Properties
        
        public static PlaybackController Instance { get; private set; }
        
        public float CurrentTime => _currentTime;
        public float TotalDuration => _totalDuration;
        public float PlaybackSpeed => _playbackSpeed;
        public bool IsPlaying => _isPlaying;
        public long GlobalStartTimestamp => _globalStartTimestamp;
        
        public bool Loop
        {
            get => loop;
            set => loop = value;
        }
        
        #endregion
        
        #region Unity Lifecycle
        
        private void Awake()
        {
            if (Instance == null)
            {
                Instance = this;
            }
            else
            {
                Debug.LogWarning("[PlaybackController] Duplicate instance found, destroying.");
                Destroy(gameObject);
            }
        }
        
        private void Start()
        {
            _playbackSpeed = speedPresets[_currentSpeedIndex];
            _playbackUI = GetComponent<PlaybackUI>();
        }
        
        private void Update()
        {
            HandleInput();
            UpdatePlayback();
        }
        
        private void OnDestroy()
        {
            if (Instance == this)
            {
                Instance = null;
            }
        }
        
        #endregion
        
        #region Input Handling
        
        private void HandleInput()
        {
            if (Input.GetKeyDown(KeyCode.Space))
            {
                if (_isPlaying) Pause(); else Play();
            }
            
            if (Input.GetKeyDown(KeyCode.S)) Stop();
            if (Input.GetKeyDown(KeyCode.R)) Restart();
            
            if (Input.GetKeyDown(KeyCode.RightArrow)) SkipForward(5f);
            if (Input.GetKeyDown(KeyCode.LeftArrow)) SkipBackward(5f);
            
            if (Input.GetKeyDown(KeyCode.UpArrow)) IncreaseSpeed();
            if (Input.GetKeyDown(KeyCode.DownArrow)) DecreaseSpeed();
            
            if (Input.GetKeyDown(KeyCode.L)) loop = !loop;
            
            if (Input.GetKeyDown(KeyCode.H))
            {
                _playbackUI?.ToggleShortcutPanel();
            }
        }
        
        #endregion
        
        #region Playback Logic
        
        private void UpdatePlayback()
        {
            if (!_isPlaying || _totalDuration <= 0) return;
            
            _currentTime += Time.deltaTime * _playbackSpeed;
            
            long currentTimestamp = _globalStartTimestamp + (long)(_currentTime * 1000f);
            NotifyListeners(currentTimestamp, _currentTime);
            
            // Handle end of playback
            if (_currentTime >= _totalDuration)
            {
                if (loop)
                {
                    _currentTime = 0f;
                    NotifyListeners(_globalStartTimestamp, 0f);
                }
                else
                {
                    _currentTime = _totalDuration;
                    Pause();
                }
            }
        }
        
        private void NotifyListeners(long timestamp, float playbackTime)
        {
            foreach (var listener in _listeners)
            {
                listener.OnPlaybackUpdate(timestamp, playbackTime);
            }
        }
        
        #endregion
        
        #region Public API - Registration
        
        /// <summary>
        /// Registers a timestamp range from a data source.
        /// Call when loading data to establish the global timeline.
        /// </summary>
        public void RegisterTimestampRange(long startTimestamp, long endTimestamp)
        {
            if (startTimestamp < _globalStartTimestamp)
                _globalStartTimestamp = startTimestamp;
            
            if (endTimestamp > _globalEndTimestamp)
                _globalEndTimestamp = endTimestamp;
            
            if (_globalStartTimestamp != long.MaxValue && _globalEndTimestamp != long.MinValue)
            {
                _totalDuration = (_globalEndTimestamp - _globalStartTimestamp) / 1000f;
                Debug.Log($"[PlaybackController] Timeline: {_totalDuration:F2}s");
            }
            
            if (autoPlay && _totalDuration > 0 && !_isPlaying)
            {
                Play();
            }
        }
        
        /// <summary>
        /// Registers a listener to receive playback updates.
        /// </summary>
        public void RegisterListener(IPlaybackListener listener)
        {
            if (!_listeners.Contains(listener))
            {
                _listeners.Add(listener);
            }
        }
        
        /// <summary>
        /// Unregisters a listener.
        /// </summary>
        public void UnregisterListener(IPlaybackListener listener)
        {
            _listeners.Remove(listener);
        }
        
        #endregion
        
        #region Public API - Playback Control
        
        public void Play() => _isPlaying = true;
        
        public void Pause() => _isPlaying = false;
        
        public void Stop()
        {
            _isPlaying = false;
            _currentTime = 0f;
            NotifyListeners(_globalStartTimestamp, 0f);
        }
        
        public void Restart()
        {
            _currentTime = 0f;
            _isPlaying = true;
            NotifyListeners(_globalStartTimestamp, 0f);
        }
        
        public void SkipForward(float seconds)
        {
            _currentTime = Mathf.Min(_currentTime + seconds, _totalDuration);
            NotifyAtCurrentTime();
        }
        
        public void SkipBackward(float seconds)
        {
            _currentTime = Mathf.Max(_currentTime - seconds, 0f);
            NotifyAtCurrentTime();
        }
        
        public void IncreaseSpeed()
        {
            if (_currentSpeedIndex < speedPresets.Length - 1)
            {
                _currentSpeedIndex++;
                _playbackSpeed = speedPresets[_currentSpeedIndex];
            }
        }
        
        public void DecreaseSpeed()
        {
            if (_currentSpeedIndex > 0)
            {
                _currentSpeedIndex--;
                _playbackSpeed = speedPresets[_currentSpeedIndex];
            }
        }
        
        public void SetSpeed(float speed)
        {
            _playbackSpeed = Mathf.Max(0.1f, speed);
            
            for (int i = 0; i < speedPresets.Length; i++)
            {
                if (Mathf.Approximately(speedPresets[i], speed))
                {
                    _currentSpeedIndex = i;
                    break;
                }
            }
        }
        
        public void SeekToTime(float time)
        {
            _currentTime = Mathf.Clamp(time, 0f, _totalDuration);
            NotifyAtCurrentTime();
        }
        
        public void SeekToNormalized(float normalized)
        {
            SeekToTime(normalized * _totalDuration);
        }
        
        private void NotifyAtCurrentTime()
        {
            long timestamp = _globalStartTimestamp + (long)(_currentTime * 1000f);
            NotifyListeners(timestamp, _currentTime);
        }
        
        #endregion
    }
}

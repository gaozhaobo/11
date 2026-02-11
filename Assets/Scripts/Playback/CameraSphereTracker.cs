using UnityEngine;
using System.Collections.Generic;
using System.Globalization;

namespace PurdueXRLab.XRDataRecorder.Playback
{
    /// <summary>
    /// Visualizes head/camera tracking data as a sphere with gaze direction ray.
    /// Uses PlaybackController for synchronized timeline playback.
    /// </summary>
    public class CameraSphereTracker : MonoBehaviour, IPlaybackListener
    {
        #region Inspector Fields
        
        [Header("Data File")]
        [SerializeField] private TextAsset cameraDataFile;
        
        [Header("Head Visualization")]
        [SerializeField] private float headSphereRadius = 0.08f;
        [SerializeField] private Color headColor = Color.cyan;
        [SerializeField] private Material headMaterial;
        
        [Header("Gaze Ray")]
        [SerializeField] private float rayLength = 0.5f;
        [SerializeField] private float rayWidth = 0.01f;
        [SerializeField] private Color rayColor = Color.yellow;
        
        #endregion
        
        #region Private Fields
        
        private List<CameraFrame> _cameraFrames = new();
        private Transform _headSphere;
        private LineRenderer _gazeRay;
        
        #endregion
        
        #region Data Structures
        
        private class CameraFrame
        {
            public long Timestamp;
            public Vector3 Position;
            public Quaternion Rotation;
        }
        
        #endregion
        
        #region Unity Lifecycle
        
        private void Start()
        {
            if (cameraDataFile == null) return;
            
            LoadCameraData();
            CreateHeadVisualization();
            CreateGazeRay();
            RegisterWithPlaybackController();
            
            if (_cameraFrames.Count > 0)
            {
                UpdateVisualization(_cameraFrames[0]);
            }
        }
        
        private void OnDestroy()
        {
            PlaybackController.Instance?.UnregisterListener(this);
        }
        
        #endregion
        
        #region Initialization
        
        private void LoadCameraData()
        {
            _cameraFrames.Clear();
            string[] lines = cameraDataFile.text.Split('\n');
            
            for (int i = 1; i < lines.Length; i++) // Skip header
            {
                string line = lines[i].Trim();
                if (string.IsNullOrEmpty(line)) continue;
                
                string[] values = line.Split(',');
                if (values.Length < 8) continue;
                
                try
                {
                    var frame = new CameraFrame
                    {
                        Timestamp = long.Parse(values[0]),
                        Position = new Vector3(
                            float.Parse(values[1], CultureInfo.InvariantCulture),
                            float.Parse(values[2], CultureInfo.InvariantCulture),
                            float.Parse(values[3], CultureInfo.InvariantCulture)
                        ),
                        Rotation = new Quaternion(
                            float.Parse(values[4], CultureInfo.InvariantCulture),
                            float.Parse(values[5], CultureInfo.InvariantCulture),
                            float.Parse(values[6], CultureInfo.InvariantCulture),
                            float.Parse(values[7], CultureInfo.InvariantCulture)
                        )
                    };
                    
                    _cameraFrames.Add(frame);
                }
                catch (System.Exception e)
                {
                    Debug.LogWarning($"[CameraSphereTracker] Failed to parse line {i}: {e.Message}");
                }
            }
            
            Debug.Log($"[CameraSphereTracker] Loaded {_cameraFrames.Count} frames");
        }
        
        private void CreateHeadVisualization()
        {
            var headObj = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            headObj.name = "HeadVisualization";
            headObj.transform.SetParent(transform);
            headObj.transform.localScale = Vector3.one * headSphereRadius * 2f;
            
            if (headObj.TryGetComponent<Renderer>(out var renderer))
            {
                if (headMaterial != null)
                {
                    renderer.material = headMaterial;
                }
                else
                {
                    renderer.material = CreateUnlitMaterial(headColor);
                }
            }
            
            if (headObj.TryGetComponent<Collider>(out var collider))
            {
                DestroyImmediate(collider);
            }
            
            _headSphere = headObj.transform;
        }
        
        private void CreateGazeRay()
        {
            var rayObj = new GameObject("GazeRayVisualization");
            rayObj.transform.SetParent(transform);
            
            _gazeRay = rayObj.AddComponent<LineRenderer>();
            _gazeRay.material = new Material(Shader.Find("Sprites/Default"));
            _gazeRay.startColor = rayColor;
            _gazeRay.endColor = rayColor;
            _gazeRay.startWidth = rayWidth;
            _gazeRay.endWidth = rayWidth * 0.5f;
            _gazeRay.positionCount = 2;
            _gazeRay.useWorldSpace = true;
        }
        
        private void RegisterWithPlaybackController()
        {
            if (PlaybackController.Instance == null)
            {
                Debug.LogWarning("[CameraSphereTracker] No PlaybackController found.");
                return;
            }
            
            PlaybackController.Instance.RegisterListener(this);
            
            if (_cameraFrames.Count > 0)
            {
                PlaybackController.Instance.RegisterTimestampRange(
                    _cameraFrames[0].Timestamp,
                    _cameraFrames[^1].Timestamp
                );
            }
        }
        
        private static Material CreateUnlitMaterial(Color color)
        {
            var shader = Shader.Find("Universal Render Pipeline/Unlit")
                         ?? Shader.Find("Unlit/Color")
                         ?? Shader.Find("Standard");
            
            var mat = new Material(shader) { color = color };
            if (mat.HasProperty("_BaseColor"))
                mat.SetColor("_BaseColor", color);
            
            return mat;
        }
        
        #endregion
        
        #region IPlaybackListener
        
        public void OnPlaybackUpdate(long timestamp, float playbackTime)
        {
            if (_cameraFrames.Count == 0) return;
            
            int frameIndex = FindFrameForTimestamp(timestamp);
            if (frameIndex >= 0)
            {
                UpdateVisualization(_cameraFrames[frameIndex]);
            }
        }
        
        #endregion
        
        #region Helpers
        
        /// <summary>
        /// Binary search for frame closest to (but not exceeding) timestamp.
        /// </summary>
        private int FindFrameForTimestamp(long timestamp)
        {
            if (_cameraFrames.Count == 0) return -1;
            
            if (timestamp <= _cameraFrames[0].Timestamp) return 0;
            if (timestamp >= _cameraFrames[^1].Timestamp) return _cameraFrames.Count - 1;
            
            int left = 0;
            int right = _cameraFrames.Count - 1;
            
            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (_cameraFrames[mid].Timestamp <= timestamp)
                    left = mid;
                else
                    right = mid - 1;
            }
            
            return left;
        }
        
        private void UpdateVisualization(CameraFrame frame)
        {
            if (_headSphere != null)
            {
                _headSphere.SetPositionAndRotation(frame.Position, frame.Rotation);
            }
            
            if (_gazeRay != null)
            {
                Vector3 rayEnd = frame.Position + frame.Rotation * Vector3.forward * rayLength;
                _gazeRay.SetPosition(0, frame.Position);
                _gazeRay.SetPosition(1, rayEnd);
            }
        }
        
        #endregion
    }
}

using UnityEngine;
using System.Collections.Generic;

namespace PurdueXRLab.XRDataRecorder.Streaming
{
    /// <summary>
    /// Visualizes real-time streaming data from StreamingDataReceiver.
    /// Supports both assigned hand joints (skinned mesh) and auto-created sphere visualization.
    /// </summary>
    public class StreamingVisualizer : MonoBehaviour
    {
        #region Constants
        
        private const int JointCount = 26;
        
        /// <summary>
        /// Hand joint connections for skeletal visualization (26-joint structure).
        /// </summary>
        private static readonly (int From, int To)[] JointConnections =
        {
            // Wrist
            (0, 1),   // Palm -> Wrist
            // Thumb
            (1, 2), (2, 3), (3, 4), (4, 5),
            // Index
            (1, 6), (6, 7), (7, 8), (8, 9), (9, 10),
            // Middle
            (1, 11), (11, 12), (12, 13), (13, 14), (14, 15),
            // Ring
            (1, 16), (16, 17), (17, 18), (18, 19), (19, 20),
            // Pinky
            (1, 21), (21, 22), (22, 23), (23, 24), (24, 25)
        };
        
        #endregion
        
        #region Inspector Fields
        
        [Header("Data Source")]
        [SerializeField] private StreamingDataReceiver dataReceiver;
        
        [Header("Head Visualization")]
        [SerializeField] private bool showHead = true;
        [SerializeField] private float headSphereRadius = 0.08f;
        [SerializeField] private Color headColor = Color.cyan;
        [SerializeField] private float gazeRayLength = 0.5f;
        
        [Header("Hand Joints")]
        [SerializeField, Tooltip("Assign 26 transforms in order: Palm, Wrist, Thumb(4), Index(5), Middle(5), Ring(5), Pinky(5)")]
        private List<Transform> leftHandJoints = new();
        [SerializeField]
        private List<Transform> rightHandJoints = new();
        
        [Header("Hand Renderers (Optional)")]
        [SerializeField] private SkinnedMeshRenderer leftHandRenderer;
        [SerializeField] private SkinnedMeshRenderer rightHandRenderer;
        
        [Header("Auto-Create Settings")]
        [SerializeField] private bool autoCreateIfEmpty = true;
        [SerializeField] private bool showSkeletons = true;
        [SerializeField] private float jointRadius = 0.005f;
        [SerializeField] private Color leftHandColor = new(0.2f, 0.6f, 1f);
        [SerializeField] private Color rightHandColor = new(1f, 0.6f, 0.2f);
        [SerializeField] private float connectionWidth = 0.003f;
        
        [Header("Status")]
        [SerializeField, Tooltip("Read-only")] private bool isActive;
        
        #endregion
        
        #region Private Fields
        
        private GameObject _headVisualization;
        private LineRenderer _gazeRay;
        private Transform _headTransform;
        
        private GameObject _leftHandRoot;
        private GameObject _rightHandRoot;
        private LineRenderer[] _leftHandConnections;
        private LineRenderer[] _rightHandConnections;
        private bool _usingAutoCreatedHands;
        
        private Material _leftHandMaterial;
        private Material _rightHandMaterial;
        
        #endregion
        
        #region Properties
        
        public List<Transform> LeftHandJoints => leftHandJoints;
        public List<Transform> RightHandJoints => rightHandJoints;
        
        #endregion
        
        #region Unity Lifecycle
        
        private void Start()
        {
            InitializeDataReceiver();
            InitializeSkinnedMeshBounds();
            CreateMaterials();
            
            if (showHead)
            {
                CreateHeadVisualization();
            }
            
            if (autoCreateIfEmpty)
            {
                if (leftHandJoints.Count == 0) CreateAutoHandVisualization(true);
                if (rightHandJoints.Count == 0) CreateAutoHandVisualization(false);
            }
            
            if (showSkeletons)
            {
                CreateSkeletonConnections();
            }
            
            SetVisualizationActive(false);
        }
        
        private void OnDestroy()
        {
            if (dataReceiver != null)
            {
                dataReceiver.OnHeadDataReceived -= OnHeadData;
                dataReceiver.OnLeftHandDataReceived -= OnLeftHandData;
                dataReceiver.OnRightHandDataReceived -= OnRightHandData;
                dataReceiver.OnConnectionChanged -= OnConnectionChanged;
            }
        }
        
        #endregion
        
        #region Initialization
        
        private void InitializeDataReceiver()
        {
            if (dataReceiver == null)
            {
                dataReceiver = FindFirstObjectByType<StreamingDataReceiver>();
            }
            
            if (dataReceiver != null)
            {
                dataReceiver.OnHeadDataReceived += OnHeadData;
                dataReceiver.OnLeftHandDataReceived += OnLeftHandData;
                dataReceiver.OnRightHandDataReceived += OnRightHandData;
                dataReceiver.OnConnectionChanged += OnConnectionChanged;
            }
        }
        
        private void InitializeSkinnedMeshBounds()
        {
            // Expand bounds to prevent culling
            if (leftHandRenderer != null)
                leftHandRenderer.localBounds = new Bounds(Vector3.zero, Vector3.one);
            if (rightHandRenderer != null)
                rightHandRenderer.localBounds = new Bounds(Vector3.zero, Vector3.one);
        }
        
        private void CreateMaterials()
        {
            Shader shader = FindShader();
            
            _leftHandMaterial = CreateMaterial(shader, leftHandColor);
            _rightHandMaterial = CreateMaterial(shader, rightHandColor);
        }
        
        private static Shader FindShader()
        {
            return Shader.Find("Universal Render Pipeline/Unlit")
                   ?? Shader.Find("Unlit/Color")
                   ?? Shader.Find("Standard");
        }
        
        private static Material CreateMaterial(Shader shader, Color color)
        {
            var mat = new Material(shader) { color = color };
            if (mat.HasProperty("_BaseColor"))
                mat.SetColor("_BaseColor", color);
            return mat;
        }
        
        private void CreateSkeletonConnections()
        {
            if (leftHandJoints.Count > 0 && _leftHandConnections == null)
                _leftHandConnections = CreateConnections(_leftHandMaterial, leftHandColor, "LeftHand");
            if (rightHandJoints.Count > 0 && _rightHandConnections == null)
                _rightHandConnections = CreateConnections(_rightHandMaterial, rightHandColor, "RightHand");
        }
        
        #endregion
        
        #region Head Visualization
        
        private void CreateHeadVisualization()
        {
            // Create head sphere
            _headVisualization = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            _headVisualization.name = "StreamingHead";
            _headVisualization.transform.SetParent(transform);
            _headVisualization.transform.localScale = Vector3.one * headSphereRadius * 2f;
            
            if (_headVisualization.TryGetComponent<Renderer>(out var renderer))
            {
                renderer.material = CreateMaterial(FindShader(), headColor);
            }
            
            if (_headVisualization.TryGetComponent<Collider>(out var collider))
            {
                DestroyImmediate(collider);
            }
            
            _headTransform = _headVisualization.transform;
            
            // Create gaze ray
            var rayObj = new GameObject("StreamingGazeRay");
            rayObj.transform.SetParent(transform);
            _gazeRay = rayObj.AddComponent<LineRenderer>();
            _gazeRay.material = new Material(Shader.Find("Sprites/Default"));
            _gazeRay.startColor = Color.yellow;
            _gazeRay.endColor = Color.yellow;
            _gazeRay.startWidth = 0.01f;
            _gazeRay.endWidth = 0.005f;
            _gazeRay.positionCount = 2;
            _gazeRay.useWorldSpace = true;
            
            _headVisualization.SetActive(false);
            rayObj.SetActive(false);
        }
        
        #endregion
        
        #region Hand Visualization
        
        private void CreateAutoHandVisualization(bool isLeft)
        {
            string handName = isLeft ? "StreamingLeftHand" : "StreamingRightHand";
            Material material = isLeft ? _leftHandMaterial : _rightHandMaterial;
            List<Transform> joints = isLeft ? leftHandJoints : rightHandJoints;
            
            var handRoot = new GameObject(handName);
            handRoot.transform.SetParent(transform);
            
            if (isLeft)
                _leftHandRoot = handRoot;
            else
                _rightHandRoot = handRoot;
            
            for (int i = 0; i < JointCount; i++)
            {
                var jointObj = GameObject.CreatePrimitive(PrimitiveType.Sphere);
                jointObj.name = $"Joint_{i}";
                jointObj.transform.SetParent(handRoot.transform);
                jointObj.transform.localScale = Vector3.one * jointRadius * 2f;
                
                if (jointObj.TryGetComponent<Renderer>(out var renderer))
                    renderer.material = material;
                
                if (jointObj.TryGetComponent<Collider>(out var collider))
                    DestroyImmediate(collider);
                
                joints.Add(jointObj.transform);
            }
            
            _usingAutoCreatedHands = true;
            handRoot.SetActive(false);
        }
        
        private LineRenderer[] CreateConnections(Material material, Color color, string prefix)
        {
            var connections = new List<LineRenderer>();
            var root = new GameObject($"{prefix}Connections");
            root.transform.SetParent(transform);
            
            foreach (var (from, to) in JointConnections)
            {
                if (from >= JointCount || to >= JointCount) continue;
                
                var lineObj = new GameObject($"Connection_{from}-{to}");
                lineObj.transform.SetParent(root.transform);
                
                var line = lineObj.AddComponent<LineRenderer>();
                line.material = new Material(material);
                line.startColor = color;
                line.endColor = color;
                line.startWidth = connectionWidth;
                line.endWidth = connectionWidth;
                line.positionCount = 2;
                line.useWorldSpace = true;
                
                connections.Add(line);
            }
            
            return connections.ToArray();
        }
        
        #endregion
        
        #region Event Handlers
        
        private void OnConnectionChanged(bool connected)
        {
            isActive = connected;
            
            if (_usingAutoCreatedHands)
            {
                SetVisualizationActive(connected);
            }
            
            Debug.Log($"[StreamingVisualizer] {(connected ? "Connected" : "Disconnected")}");
        }
        
        private void OnHeadData(StreamingDataReceiver.StreamHeadData data)
        {
            if (!showHead || _headTransform == null) return;
            
            _headTransform.SetPositionAndRotation(data.position, data.rotation);
            
            if (!_headTransform.gameObject.activeSelf)
                _headTransform.gameObject.SetActive(true);
            
            if (_gazeRay != null)
            {
                Vector3 rayEnd = data.position + data.rotation * Vector3.forward * gazeRayLength;
                _gazeRay.SetPosition(0, data.position);
                _gazeRay.SetPosition(1, rayEnd);
                
                if (!_gazeRay.gameObject.activeSelf)
                    _gazeRay.gameObject.SetActive(true);
            }
        }
        
        private void OnLeftHandData(StreamingDataReceiver.StreamHandData data)
        {
            UpdateHandJoints(leftHandJoints, data.joints);
            
            if (showSkeletons && _leftHandConnections != null)
                UpdateConnections(_leftHandConnections, leftHandJoints);
            
            if (_leftHandRoot != null && !_leftHandRoot.activeSelf)
                _leftHandRoot.SetActive(true);
        }
        
        private void OnRightHandData(StreamingDataReceiver.StreamHandData data)
        {
            UpdateHandJoints(rightHandJoints, data.joints);
            
            if (showSkeletons && _rightHandConnections != null)
                UpdateConnections(_rightHandConnections, rightHandJoints);
            
            if (_rightHandRoot != null && !_rightHandRoot.activeSelf)
                _rightHandRoot.SetActive(true);
        }
        
        private static void UpdateHandJoints(List<Transform> joints, List<StreamingDataReceiver.StreamJointData> jointData)
        {
            if (joints == null || jointData == null) return;
            
            int count = Mathf.Min(joints.Count, jointData.Count);
            for (int i = 0; i < count; i++)
            {
                if (joints[i] != null)
                {
                    joints[i].SetPositionAndRotation(jointData[i].position, jointData[i].rotation);
                }
            }
        }
        
        private void UpdateConnections(LineRenderer[] connections, List<Transform> joints)
        {
            if (connections == null || joints == null) return;
            
            int idx = 0;
            foreach (var (from, to) in JointConnections)
            {
                if (from < joints.Count && to < joints.Count && 
                    idx < connections.Length &&
                    joints[from] != null && joints[to] != null)
                {
                    connections[idx].SetPosition(0, joints[from].position);
                    connections[idx].SetPosition(1, joints[to].position);
                    idx++;
                }
            }
        }
        
        #endregion
        
        #region Public API
        
        /// <summary>
        /// Starts streaming visualization.
        /// </summary>
        public void StartStreaming()
        {
            dataReceiver?.StartReceiving();
        }
        
        /// <summary>
        /// Stops streaming visualization.
        /// </summary>
        public void StopStreaming()
        {
            dataReceiver?.StopReceiving();
        }
        
        #endregion
        
        #region Helpers
        
        private void SetVisualizationActive(bool active)
        {
            if (_headVisualization != null) _headVisualization.SetActive(active);
            if (_gazeRay != null) _gazeRay.gameObject.SetActive(active);
            if (_leftHandRoot != null) _leftHandRoot.SetActive(active);
            if (_rightHandRoot != null) _rightHandRoot.SetActive(active);
        }
        
        #endregion
    }
}

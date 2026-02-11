using UnityEngine;
using System.Collections.Generic;
using System.Globalization;

namespace PurdueXRLab.XRDataRecorder.Playback
{
    /// <summary>
    /// Visualizes hand tracking data from CSV files with skeletal connections.
    /// Uses PlaybackController for synchronized timeline playback.
    /// </summary>
    public class HandVisualPlayback : MonoBehaviour, IPlaybackListener
    {
        #region Constants
        
        private const int JointDataStride = 7; // pos(x,y,z) + rot(x,y,z,w)
        
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
        
        [Header("Data Files")]
        [SerializeField] private TextAsset leftHandDataFile;
        [SerializeField] private TextAsset rightHandDataFile;

        [Header("Visualization")]
        [SerializeField] private Material jointMaterial;
        [SerializeField] private float jointRadius = 0.005f;
        [SerializeField] private bool showSkeletons = true;

        [Header("Hand Joints")]
        [SerializeField] private List<Transform> leftHandJoints = new();
        [SerializeField] private SkinnedMeshRenderer leftHandRenderer;
        [SerializeField] private List<Transform> rightHandJoints = new();
        [SerializeField] private SkinnedMeshRenderer rightHandRenderer;
        
        #endregion
        
        #region Private Fields
        
        private List<FrameData> _leftHandFrames = new();
        private List<FrameData> _rightHandFrames = new();
        
        private LineRenderer[] _leftHandConnections;
        private LineRenderer[] _rightHandConnections;
        
        #endregion
        
        #region Properties
        
        public List<Transform> LeftHandJoints => leftHandJoints;
        public List<Transform> RightHandJoints => rightHandJoints;
        
        #endregion
        
        #region Data Structures
        
        private class FrameData
        {
            public long Timestamp;
            public List<(Vector3 Position, Quaternion Rotation)> Joints;
        }
        
        #endregion
        
        #region Unity Lifecycle
        
        private void Start()
        {
            LoadDataFiles();
            InitializeSkinnedMeshBounds();
            CreateHandVisuals();
            RegisterWithPlaybackController();
            UpdateToFirstFrame();
        }
        
        private void OnDestroy()
        {
            PlaybackController.Instance?.UnregisterListener(this);
        }
        
        #endregion
        
        #region Initialization
        
        private void LoadDataFiles()
        {
            if (leftHandDataFile != null)
            {
                _leftHandFrames = LoadHandData(leftHandDataFile);
                Debug.Log($"[HandVisualPlayback] Loaded {_leftHandFrames.Count} left hand frames");
            }
            
            if (rightHandDataFile != null)
            {
                _rightHandFrames = LoadHandData(rightHandDataFile);
                Debug.Log($"[HandVisualPlayback] Loaded {_rightHandFrames.Count} right hand frames");
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
        
        private void RegisterWithPlaybackController()
        {
            if (PlaybackController.Instance == null)
            {
                Debug.LogWarning("[HandVisualPlayback] No PlaybackController found.");
                return;
            }
            
            PlaybackController.Instance.RegisterListener(this);
            RegisterTimestampRange(_leftHandFrames);
            RegisterTimestampRange(_rightHandFrames);
        }
        
        private void RegisterTimestampRange(List<FrameData> frames)
        {
            if (frames.Count == 0 || PlaybackController.Instance == null) return;
            
            PlaybackController.Instance.RegisterTimestampRange(
                frames[0].Timestamp,
                frames[^1].Timestamp
            );
        }
        
        private void UpdateToFirstFrame()
        {
            if (_leftHandFrames.Count > 0 && leftHandJoints.Count > 0)
            {
                UpdateHandVisuals(leftHandJoints, _leftHandFrames[0].Joints);
                if (showSkeletons && _leftHandConnections != null)
                    UpdateConnections(_leftHandConnections, leftHandJoints);
            }
            
            if (_rightHandFrames.Count > 0 && rightHandJoints.Count > 0)
            {
                UpdateHandVisuals(rightHandJoints, _rightHandFrames[0].Joints);
                if (showSkeletons && _rightHandConnections != null)
                    UpdateConnections(_rightHandConnections, rightHandJoints);
            }
        }
        
        #endregion
        
        #region IPlaybackListener
        
        public void OnPlaybackUpdate(long timestamp, float playbackTime)
        {
            bool hasLeft = _leftHandFrames.Count > 0 && leftHandJoints.Count > 0;
            bool hasRight = _rightHandFrames.Count > 0 && rightHandJoints.Count > 0;

            if (!hasLeft && !hasRight) return;

            if (hasLeft)
            {
                int frameIndex = FindFrameForTimestamp(_leftHandFrames, timestamp);
                if (frameIndex >= 0)
                {
                    UpdateHandVisuals(leftHandJoints, _leftHandFrames[frameIndex].Joints);
                    if (showSkeletons && _leftHandConnections != null)
                        UpdateConnections(_leftHandConnections, leftHandJoints);
                }
            }
            
            if (hasRight)
            {
                int frameIndex = FindFrameForTimestamp(_rightHandFrames, timestamp);
                if (frameIndex >= 0)
                {
                    UpdateHandVisuals(rightHandJoints, _rightHandFrames[frameIndex].Joints);
                    if (showSkeletons && _rightHandConnections != null)
                        UpdateConnections(_rightHandConnections, rightHandJoints);
                }
            }
        }
        
        #endregion
        
        #region Data Loading
        
        private static List<FrameData> LoadHandData(TextAsset dataFile)
        {
            var frames = new List<FrameData>();
            string[] lines = dataFile.text.Split('\n');
            
            for (int i = 1; i < lines.Length; i++) // Skip header
            {
                string line = lines[i].Trim();
                if (string.IsNullOrEmpty(line)) continue;

                string[] values = line.Split(',');
                if (values.Length < 2) continue;

                if (!long.TryParse(values[0], out long timestamp)) continue;

                var frame = new FrameData
                {
                    Timestamp = timestamp,
                    Joints = new List<(Vector3, Quaternion)>()
                };

                // Parse joint data
                for (int j = 1; j + JointDataStride <= values.Length; j += JointDataStride)
                {
                    try
                    {
                        var position = new Vector3(
                            float.Parse(values[j], CultureInfo.InvariantCulture),
                            float.Parse(values[j + 1], CultureInfo.InvariantCulture),
                            float.Parse(values[j + 2], CultureInfo.InvariantCulture)
                        );

                        var rotation = new Quaternion(
                            float.Parse(values[j + 3], CultureInfo.InvariantCulture),
                            float.Parse(values[j + 4], CultureInfo.InvariantCulture),
                            float.Parse(values[j + 5], CultureInfo.InvariantCulture),
                            float.Parse(values[j + 6], CultureInfo.InvariantCulture)
                        );
                        
                        frame.Joints.Add((position, rotation));
                    }
                    catch (System.Exception)
                    {
                        // Skip malformed lines
                        goto nextLine;
                    }
                }

                frames.Add(frame);
                nextLine:;
            }

            return frames;
        }
        
        /// <summary>
        /// Binary search for the frame closest to (but not exceeding) the timestamp.
        /// </summary>
        private static int FindFrameForTimestamp(List<FrameData> frames, long timestamp)
        {
            if (frames.Count == 0) return -1;
            
            if (timestamp <= frames[0].Timestamp) return 0;
            if (timestamp >= frames[^1].Timestamp) return frames.Count - 1;
            
            int left = 0;
            int right = frames.Count - 1;
            
            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (frames[mid].Timestamp <= timestamp)
                    left = mid;
                else
                    right = mid - 1;
            }
            
            return left;
        }
        
        #endregion
        
        #region Visualization
        
        private void CreateHandVisuals()
        {
            if (!showSkeletons) return;
            
            var leftRoot = new GameObject("LeftHandVisual");
            leftRoot.transform.SetParent(transform);
            
            var rightRoot = new GameObject("RightHandVisual");
            rightRoot.transform.SetParent(transform);

            if (leftHandJoints.Count > 0)
                _leftHandConnections = CreateConnections(leftRoot.transform, leftHandJoints.Count);
            if (rightHandJoints.Count > 0)
                _rightHandConnections = CreateConnections(rightRoot.transform, rightHandJoints.Count);
        }

        private LineRenderer[] CreateConnections(Transform parent, int jointCount)
        {
            var connections = new List<LineRenderer>();
            
            foreach (var (from, to) in JointConnections)
            {
                if (from >= jointCount || to >= jointCount) continue;
                
                var lineObj = new GameObject($"Connection_{from}-{to}");
                lineObj.transform.SetParent(parent);
            
                var line = lineObj.AddComponent<LineRenderer>();
                line.material = new Material(jointMaterial);
                line.startWidth = line.endWidth = jointRadius * 0.5f;
                line.positionCount = 2;
                line.useWorldSpace = true;
            
                connections.Add(line);
            }

            return connections.ToArray();
        }

        private static void UpdateHandVisuals(List<Transform> joints, List<(Vector3 Position, Quaternion Rotation)> jointData)
        {
            int count = Mathf.Min(joints.Count, jointData.Count);
            for (int i = 0; i < count; i++)
            {
                joints[i].SetPositionAndRotation(jointData[i].Position, jointData[i].Rotation);
            }
        }

        private void UpdateConnections(LineRenderer[] connections, List<Transform> joints)
        {
            int idx = 0;
            foreach (var (from, to) in JointConnections)
            {
                if (from < joints.Count && to < joints.Count && idx < connections.Length)
                {
                    connections[idx].SetPosition(0, joints[from].position);
                    connections[idx].SetPosition(1, joints[to].position);
                    idx++;
                }
            }
        }
        
        #endregion
    }
}

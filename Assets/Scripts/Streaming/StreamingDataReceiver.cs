using UnityEngine;
using UnityEngine.Networking;
using System;
using System.Collections;
using System.Collections.Generic;

namespace PurdueXRLab.XRDataRecorder.Streaming
{
    /// <summary>
    /// Receives real-time streaming data from the Flask server via HTTP polling.
    /// </summary>
    public class StreamingDataReceiver : MonoBehaviour
    {
        #region Inspector Fields
        
        [Header("Server Settings")]
        [SerializeField] private string serverIP = "192.168.0.250";
        [SerializeField] private int serverPort = 5555;
        
        [Header("Auto Start")]
        [SerializeField] private bool autoStartOnAwake = true;
        
        [Header("Polling Settings")]
        [SerializeField, Tooltip("How often to poll the server (seconds). Should match or be slightly faster than sender's recording interval.")]
        private float pollingInterval = 0.08f;
        
        [Header("Status")]
        [SerializeField, Tooltip("Read-only")] private bool isConnected;
        [SerializeField, Tooltip("Read-only")] private bool isReceiving;
        
        #endregion
        
        #region Events
        
        public event Action<StreamHeadData> OnHeadDataReceived;
        public event Action<StreamHandData> OnLeftHandDataReceived;
        public event Action<StreamHandData> OnRightHandDataReceived;
        public event Action<StreamEventData> OnEventReceived;
        public event Action<bool> OnConnectionChanged;
        
        #endregion
        
        #region Private Fields
        
        private Coroutine _pollingCoroutine;
        private long _lastEventTimestamp;
        private WaitForSeconds _pollingWait;
        
        #endregion
        
        #region Properties
        
        public bool IsConnected => isConnected;
        public bool IsReceiving => isReceiving;
        public string ServerUrl => $"http://{serverIP}:{serverPort}";
        
        public string ServerIP
        {
            get => serverIP;
            set => serverIP = value;
        }
        
        public int ServerPort
        {
            get => serverPort;
            set => serverPort = value;
        }
        
        #endregion
        
        #region Unity Lifecycle
        
        private void Awake()
        {
            _pollingWait = new WaitForSeconds(pollingInterval);
        }
        
        private void Start()
        {
            if (autoStartOnAwake)
            {
                StartReceiving();
            }
        }
        
        private void OnDestroy()
        {
            StopReceiving();
        }
        
        #endregion
        
        #region Public API
        
        /// <summary>
        /// Starts receiving streaming data from the server.
        /// </summary>
        public void StartReceiving()
        {
            if (isReceiving) return;
            _pollingCoroutine = StartCoroutine(PollingCoroutine());
        }
        
        /// <summary>
        /// Stops receiving streaming data.
        /// </summary>
        public void StopReceiving()
        {
            if (_pollingCoroutine != null)
            {
                StopCoroutine(_pollingCoroutine);
                _pollingCoroutine = null;
            }
            
            isReceiving = false;
            isConnected = false;
            OnConnectionChanged?.Invoke(false);
        }
        
        /// <summary>
        /// Sets the server address.
        /// </summary>
        public void SetServer(string ip, int port)
        {
            serverIP = ip;
            serverPort = port;
        }
        
        #endregion
        
        #region Polling
        
        private IEnumerator PollingCoroutine()
        {
            isReceiving = true;
            
            // Test connection first
            using (var req = UnityWebRequest.Get($"{ServerUrl}/api/data"))
            {
                req.timeout = 5;
                yield return req.SendWebRequest();
                
                if (req.result != UnityWebRequest.Result.Success)
                {
                    Debug.LogError($"[StreamingDataReceiver] Cannot connect to {ServerUrl}: {req.error}");
                    isConnected = false;
                    isReceiving = false;
                    OnConnectionChanged?.Invoke(false);
                    yield break;
                }
            }
            
            isConnected = true;
            OnConnectionChanged?.Invoke(true);
            Debug.Log($"[StreamingDataReceiver] Connected to {ServerUrl}");
            
            while (isReceiving)
            {
                yield return FetchLatestData();
                yield return _pollingWait;
            }
        }
        
        private IEnumerator FetchLatestData()
        {
            string url = $"{ServerUrl}/api/stream/latest?since={_lastEventTimestamp}";
            
            using var req = UnityWebRequest.Get(url);
            req.timeout = 2;
            yield return req.SendWebRequest();
            
            if (req.result != UnityWebRequest.Result.Success)
            {
                if (isConnected)
                {
                    isConnected = false;
                    OnConnectionChanged?.Invoke(false);
                    Debug.LogWarning($"[StreamingDataReceiver] Connection lost: {req.error}");
                }
                yield break;
            }
            
            if (!isConnected)
            {
                isConnected = true;
                OnConnectionChanged?.Invoke(true);
            }
            
            try
            {
                ProcessResponse(req.downloadHandler.text);
            }
            catch (Exception e)
            {
                Debug.LogWarning($"[StreamingDataReceiver] Failed to parse response: {e.Message}");
            }
        }
        
        private void ProcessResponse(string json)
        {
            var response = JsonUtility.FromJson<LatestDataResponse>(json);
            
            // Process head data
            if (response.head != null && response.head.timestamp > 0)
            {
                OnHeadDataReceived?.Invoke(new StreamHeadData
                {
                    timestamp = response.head.timestamp,
                    position = response.head.position.ToVector3(),
                    rotation = response.head.rotation.ToQuaternion()
                });
            }
            
            // Process hand data
            if (response.left_hand != null && response.left_hand.timestamp > 0)
            {
                OnLeftHandDataReceived?.Invoke(ConvertHandData(response.left_hand));
            }
            
            if (response.right_hand != null && response.right_hand.timestamp > 0)
            {
                OnRightHandDataReceived?.Invoke(ConvertHandData(response.right_hand));
            }
            
            // Process events
            if (response.events != null)
            {
                foreach (var evt in response.events)
                {
                    OnEventReceived?.Invoke(new StreamEventData
                    {
                        timestamp = evt.timestamp,
                        message = evt.@string
                    });
                    
                    if (evt.timestamp > _lastEventTimestamp)
                    {
                        _lastEventTimestamp = evt.timestamp;
                    }
                }
            }
        }
        
        private static StreamHandData ConvertHandData(HandJson handJson)
        {
            var handData = new StreamHandData
            {
                timestamp = handJson.timestamp,
                hand = handJson.hand,
                joints = new List<StreamJointData>(handJson.joints?.Count ?? 0)
            };
            
            if (handJson.joints != null)
            {
                foreach (var joint in handJson.joints)
                {
                    handData.joints.Add(new StreamJointData
                    {
                        position = joint.position.ToVector3(),
                        rotation = joint.rotation.ToQuaternion()
                    });
                }
            }
            
            return handData;
        }
        
        #endregion
        
        #region Data Structures
        
        [Serializable]
        public class StreamHeadData
        {
            public long timestamp;
            public Vector3 position;
            public Quaternion rotation;
        }
        
        [Serializable]
        public class StreamHandData
        {
            public long timestamp;
            public string hand;
            public List<StreamJointData> joints;
        }
        
        [Serializable]
        public class StreamJointData
        {
            public Vector3 position;
            public Quaternion rotation;
        }
        
        [Serializable]
        public class StreamEventData
        {
            public long timestamp;
            public string message;
        }
        
        // JSON response classes (private)
        [Serializable]
        private class LatestDataResponse
        {
            public bool server_started;
            public HeadJson head;
            public HandJson left_hand;
            public HandJson right_hand;
            public List<EventJson> events;
        }
        
        [Serializable]
        private class HeadJson
        {
            public long timestamp;
            public PositionJson position;
            public RotationJson rotation;
        }
        
        [Serializable]
        private class HandJson
        {
            public long timestamp;
            public string hand;
            public List<JointJson> joints;
        }
        
        [Serializable]
        private class JointJson
        {
            public PositionJson position;
            public RotationJson rotation;
        }
        
        [Serializable]
        private class PositionJson
        {
            public float x, y, z;
            public Vector3 ToVector3() => new(x, y, z);
        }
        
        [Serializable]
        private class RotationJson
        {
            public float x, y, z, w;
            public Quaternion ToQuaternion() => new(x, y, z, w);
        }
        
        [Serializable]
        private class EventJson
        {
            public long timestamp;
            public string @string;
        }
        
        #endregion
    }
}

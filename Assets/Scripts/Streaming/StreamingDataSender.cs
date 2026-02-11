using UnityEngine;
using UnityEngine.Networking;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;
using Oculus.Interaction;

namespace PurdueXRLab.XRDataRecorder.Streaming
{
    /// <summary>
    /// Sends tracking data to the Flask server.
    /// Supports both real-time streaming and local CSV recording.
    /// Uses HandVisual from Oculus.Interaction for 26-joint hand tracking.
    /// </summary>
    public class StreamingDataSender : MonoBehaviour
    {
        #region Inspector Fields
        
        [Header("Server Settings")]
        [SerializeField] private string serverIP = "192.168.0.250";
        [SerializeField] private int serverPort = 5555;
        
        [Header("Auto Start")]
        [SerializeField] private bool autoStartOnAwake = true;
        
        [Header("Recording Mode")]
        [SerializeField] private bool streamToServer = true;
        [SerializeField] private bool saveLocalCSV = true;
        
        [Header("Recording Settings")]
        [SerializeField] private float recordingInterval = 0.1f;
        
        [Header("Tracking Sources")]
        [SerializeField] private Transform headTransform;
        [SerializeField] private HandVisual leftHandVisual;
        [SerializeField] private HandVisual rightHandVisual;
        
        [Header("Status")]
        [SerializeField] private bool isRecording;
        
        #endregion
        
        #region Private Fields
        
        private Coroutine _recordingCoroutine;
        private StreamWriter _headCsvWriter;
        private StreamWriter _leftHandCsvWriter;
        private StreamWriter _rightHandCsvWriter;
        private string _headCsvPath;
        private string _leftHandCsvPath;
        private string _rightHandCsvPath;
        
        // Cached wait to avoid GC allocation
        private WaitForSeconds _recordingWait;
        
        #endregion
        
        #region Properties
        
        public bool IsRecording => isRecording;
        public string ServerUrl => $"http://{serverIP}:{serverPort}";
        
        #endregion
        
        #region Unity Lifecycle
        
        private void Awake()
        {
            _recordingWait = new WaitForSeconds(recordingInterval);
        }
        
        private void Start()
        {
            if (autoStartOnAwake)
            {
                StartRecording();
            }
        }
        
        private void OnDestroy()
        {
            if (isRecording)
            {
                StopRecording();
            }
        }
        
        private void OnApplicationQuit()
        {
            if (isRecording)
            {
                StopRecording();
            }
        }
        
        #endregion
        
        #region Public API
        
        /// <summary>
        /// Starts recording tracking data.
        /// </summary>
        public void StartRecording()
        {
            if (isRecording) return;
            
            long timestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
            
            if (saveLocalCSV)
            {
                InitializeCSVFiles(timestamp);
            }
            
            isRecording = true;
            _recordingCoroutine = StartCoroutine(RecordingCoroutine());
            
            if (streamToServer)
            {
                SendEvent("SESSION_START: Recording started");
            }
            
            Debug.Log($"[StreamingDataSender] Recording started (Stream: {streamToServer}, CSV: {saveLocalCSV})");
        }
        
        /// <summary>
        /// Stops recording tracking data.
        /// </summary>
        public void StopRecording()
        {
            if (!isRecording) return;
            
            isRecording = false;
            
            if (_recordingCoroutine != null)
            {
                StopCoroutine(_recordingCoroutine);
                _recordingCoroutine = null;
            }
            
            if (streamToServer)
            {
                SendEvent("SESSION_END: Recording stopped");
            }
            
            CloseCSVFiles();
            
            Debug.Log("[StreamingDataSender] Recording stopped");
        }
        
        /// <summary>
        /// Sends a custom event/marker to the server.
        /// </summary>
        /// <param name="message">Event message to send.</param>
        public void SendEvent(string message)
        {
            if (streamToServer)
            {
                StartCoroutine(SendEventCoroutine(message));
            }
        }
        
        /// <summary>
        /// Uploads locally saved CSV files to the server.
        /// Call this after stopping recording if saveLocalCSV was enabled.
        /// </summary>
        public void UploadCSVFiles()
        {
            if (!string.IsNullOrEmpty(_headCsvPath) && File.Exists(_headCsvPath))
            {
                StartCoroutine(UploadFileCoroutine(_headCsvPath));
            }
            if (!string.IsNullOrEmpty(_leftHandCsvPath) && File.Exists(_leftHandCsvPath))
            {
                StartCoroutine(UploadFileCoroutine(_leftHandCsvPath));
            }
            if (!string.IsNullOrEmpty(_rightHandCsvPath) && File.Exists(_rightHandCsvPath))
            {
                StartCoroutine(UploadFileCoroutine(_rightHandCsvPath));
            }
        }
        
        #endregion
        
        #region CSV Recording
        
        private void InitializeCSVFiles(long timestamp)
        {
            string basePath = Application.persistentDataPath;
            
            // Head CSV
            _headCsvPath = Path.Combine(basePath, $"head_{timestamp}.csv");
            _headCsvWriter = new StreamWriter(_headCsvPath, false);
            _headCsvWriter.WriteLine("timestamp,pos_x,pos_y,pos_z,rot_x,rot_y,rot_z,rot_w");
            
            // Left hand CSV
            if (leftHandVisual != null)
            {
                int jointCount = leftHandVisual.Joints?.Count ?? 26;
                _leftHandCsvPath = Path.Combine(basePath, $"left_hand_joints_{timestamp}.csv");
                _leftHandCsvWriter = new StreamWriter(_leftHandCsvPath, false);
                WriteHandHeader(_leftHandCsvWriter, jointCount);
            }
            
            // Right hand CSV
            if (rightHandVisual != null)
            {
                int jointCount = rightHandVisual.Joints?.Count ?? 26;
                _rightHandCsvPath = Path.Combine(basePath, $"right_hand_joints_{timestamp}.csv");
                _rightHandCsvWriter = new StreamWriter(_rightHandCsvPath, false);
                WriteHandHeader(_rightHandCsvWriter, jointCount);
            }
        }
        
        private void WriteHandHeader(StreamWriter writer, int jointCount)
        {
            var sb = new StringBuilder("timestamp");
            for (int i = 0; i < jointCount; i++)
            {
                sb.Append($",joint_{i}_pos_x,joint_{i}_pos_y,joint_{i}_pos_z");
                sb.Append($",joint_{i}_rot_x,joint_{i}_rot_y,joint_{i}_rot_z,joint_{i}_rot_w");
            }
            writer.WriteLine(sb.ToString());
        }
        
        private void CloseCSVFiles()
        {
            CloseWriter(ref _headCsvWriter, _headCsvPath, "Head");
            CloseWriter(ref _leftHandCsvWriter, _leftHandCsvPath, "Left hand");
            CloseWriter(ref _rightHandCsvWriter, _rightHandCsvPath, "Right hand");
        }
        
        private void CloseWriter(ref StreamWriter writer, string path, string name)
        {
            if (writer == null) return;
            
            writer.Flush();
            writer.Close();
            writer = null;
            Debug.Log($"[StreamingDataSender] {name} CSV saved: {path}");
        }
        
        #endregion
        
        #region Recording Coroutine
        
        private IEnumerator RecordingCoroutine()
        {
            while (isRecording)
            {
                long timestamp = DateTimeOffset.UtcNow.ToUnixTimeMilliseconds();
                
                RecordHead(timestamp);
                RecordHands(timestamp);
                
                yield return _recordingWait;
            }
        }
        
        private void RecordHead(long timestamp)
        {
            if (headTransform == null) return;
            
            Vector3 pos = headTransform.position;
            Quaternion rot = headTransform.rotation;
            
            if (saveLocalCSV && _headCsvWriter != null)
            {
                _headCsvWriter.WriteLine(
                    $"{timestamp},{F(pos.x)},{F(pos.y)},{F(pos.z)},{F(rot.x)},{F(rot.y)},{F(rot.z)},{F(rot.w)}");
            }
            
            if (streamToServer)
            {
                StartCoroutine(SendHeadDataCoroutine(timestamp, pos, rot));
            }
        }
        
        private void RecordHands(long timestamp)
        {
            if (leftHandVisual != null && leftHandVisual.Joints != null)
            {
                RecordHand("left", leftHandVisual.Joints, _leftHandCsvWriter, timestamp);
            }
            
            if (rightHandVisual != null && rightHandVisual.Joints != null)
            {
                RecordHand("right", rightHandVisual.Joints, _rightHandCsvWriter, timestamp);
            }
        }
        
        private void RecordHand(string handName, IList<Transform> joints, StreamWriter writer, long timestamp)
        {
            var jointDataList = new List<JointData>(joints.Count);
            StringBuilder csvRow = saveLocalCSV ? new StringBuilder(timestamp.ToString()) : null;
            
            foreach (var joint in joints)
            {
                Vector3 pos = joint != null ? joint.position : Vector3.zero;
                Quaternion rot = joint != null ? joint.rotation : Quaternion.identity;
                
                jointDataList.Add(new JointData(pos, rot));
                csvRow?.Append($",{F(pos.x)},{F(pos.y)},{F(pos.z)},{F(rot.x)},{F(rot.y)},{F(rot.z)},{F(rot.w)}");
            }
            
            if (saveLocalCSV && writer != null)
            {
                writer.WriteLine(csvRow.ToString());
            }
            
            if (streamToServer)
            {
                StartCoroutine(SendHandDataCoroutine(timestamp, handName, jointDataList));
            }
        }
        
        #endregion
        
        #region Network
        
        private IEnumerator SendHeadDataCoroutine(long timestamp, Vector3 pos, Quaternion rot)
        {
            string json = $"{{\"timestamp\":{timestamp}," +
                          $"\"position\":{{\"x\":{F(pos.x)},\"y\":{F(pos.y)},\"z\":{F(pos.z)}}}," +
                          $"\"rotation\":{{\"x\":{F(rot.x)},\"y\":{F(rot.y)},\"z\":{F(rot.z)},\"w\":{F(rot.w)}}}}}";
            
            yield return SendJsonPost($"{ServerUrl}/api/stream/head", json);
        }
        
        private IEnumerator SendHandDataCoroutine(long timestamp, string hand, List<JointData> joints)
        {
            var sb = new StringBuilder();
            sb.Append($"{{\"timestamp\":{timestamp},\"hand\":\"{hand}\",\"joints\":[");
            
            for (int i = 0; i < joints.Count; i++)
            {
                if (i > 0) sb.Append(',');
                var j = joints[i];
                sb.Append($"{{\"position\":{{\"x\":{F(j.Position.x)},\"y\":{F(j.Position.y)},\"z\":{F(j.Position.z)}}}," +
                          $"\"rotation\":{{\"x\":{F(j.Rotation.x)},\"y\":{F(j.Rotation.y)},\"z\":{F(j.Rotation.z)},\"w\":{F(j.Rotation.w)}}}}}");
            }
            
            sb.Append("]}");
            yield return SendJsonPost($"{ServerUrl}/api/stream/hand", sb.ToString());
        }
        
        private IEnumerator SendEventCoroutine(string message)
        {
            long timestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
            string escapedMessage = message.Replace("\\", "\\\\").Replace("\"", "\\\"").Replace("\n", ": ");
            string json = $"{{\"timestamp\":{timestamp},\"string\":\"{escapedMessage}\"}}";
            
            yield return SendJsonPost($"{ServerUrl}/api/input", json);
        }
        
        private IEnumerator SendJsonPost(string url, string json)
        {
            byte[] bodyRaw = Encoding.UTF8.GetBytes(json);
            
            using var req = new UnityWebRequest(url, "POST");
            req.uploadHandler = new UploadHandlerRaw(bodyRaw);
            req.downloadHandler = new DownloadHandlerBuffer();
            req.SetRequestHeader("Content-Type", "application/json");
            req.timeout = 2;
            
            yield return req.SendWebRequest();
        }
        
        private IEnumerator UploadFileCoroutine(string filePath)
        {
            if (!File.Exists(filePath)) yield break;
            
            byte[] fileData = File.ReadAllBytes(filePath);
            string fileName = Path.GetFileName(filePath);
            
            var form = new WWWForm();
            form.AddBinaryData("file", fileData, fileName);
            
            using var req = UnityWebRequest.Post($"{ServerUrl}/api/upload", form);
            yield return req.SendWebRequest();
            
            if (req.result == UnityWebRequest.Result.Success)
            {
                Debug.Log($"[StreamingDataSender] Uploaded: {fileName}");
                File.Delete(filePath);
            }
            else
            {
                Debug.LogError($"[StreamingDataSender] Upload failed for {fileName}: {req.error}");
            }
        }
        
        #endregion
        
        #region Helpers
        
        private static string F(float value) => value.ToString(CultureInfo.InvariantCulture);
        
        private readonly struct JointData
        {
            public readonly Vector3 Position;
            public readonly Quaternion Rotation;
            
            public JointData(Vector3 position, Quaternion rotation)
            {
                Position = position;
                Rotation = rotation;
            }
        }
        
        #endregion
    }
}

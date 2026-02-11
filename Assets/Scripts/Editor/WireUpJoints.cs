using UnityEngine;
using UnityEditor;
using UnityEditor.SceneManagement;
using PurdueXRLab.XRDataRecorder.Streaming;

namespace PurdueXRLab.XRDataRecorder.Editor
{
    /// <summary>
    /// Editor tool to wire up hand joint transforms to StreamingVisualizer.
    /// </summary>
    public static class WireUpJoints
    {
        /// <summary>
        /// 26 joints in HandJointId order (XRHand_ prefix).
        /// </summary>
        private static readonly string[] JointNames =
        {
            "XRHand_Palm",
            "XRHand_Wrist",
            "XRHand_ThumbMetacarpal",
            "XRHand_ThumbProximal",
            "XRHand_ThumbDistal",
            "XRHand_ThumbTip",
            "XRHand_IndexMetacarpal",
            "XRHand_IndexProximal",
            "XRHand_IndexIntermediate",
            "XRHand_IndexDistal",
            "XRHand_IndexTip",
            "XRHand_MiddleMetacarpal",
            "XRHand_MiddleProximal",
            "XRHand_MiddleIntermediate",
            "XRHand_MiddleDistal",
            "XRHand_MiddleTip",
            "XRHand_RingMetacarpal",
            "XRHand_RingProximal",
            "XRHand_RingIntermediate",
            "XRHand_RingDistal",
            "XRHand_RingTip",
            "XRHand_LittleMetacarpal",
            "XRHand_LittleProximal",
            "XRHand_LittleIntermediate",
            "XRHand_LittleDistal",
            "XRHand_LittleTip"
        };

        [MenuItem("Tools/Wire Up StreamingVisualizer Joints")]
        public static void WireUp()
        {
            var visualizer = Object.FindFirstObjectByType<StreamingVisualizer>();
            if (visualizer == null)
            {
                Debug.LogError("[WireUpJoints] No StreamingVisualizer found in scene!");
                return;
            }

            var leftHand = GameObject.Find("OpenXRLeftHand");
            var rightHand = GameObject.Find("OpenXRRightHand");

            if (leftHand == null || rightHand == null)
            {
                Debug.LogError("[WireUpJoints] Could not find OpenXRLeftHand or OpenXRRightHand!");
                return;
            }

            var so = new SerializedObject(visualizer);
            var leftJoints = so.FindProperty("leftHandJoints");
            var rightJoints = so.FindProperty("rightHandJoints");
            
            leftJoints.ClearArray();
            rightJoints.ClearArray();

            int leftCount = 0, rightCount = 0;
            
            for (int i = 0; i < JointNames.Length; i++)
            {
                // Left hand
                var leftJoint = FindJoint(leftHand.transform, JointNames[i]);
                leftJoints.InsertArrayElementAtIndex(i);
                leftJoints.GetArrayElementAtIndex(i).objectReferenceValue = leftJoint;
                if (leftJoint != null) leftCount++;

                // Right hand
                var rightJoint = FindJoint(rightHand.transform, JointNames[i]);
                rightJoints.InsertArrayElementAtIndex(i);
                rightJoints.GetArrayElementAtIndex(i).objectReferenceValue = rightJoint;
                if (rightJoint != null) rightCount++;
            }

            // Disable auto-create since we have real joints
            so.FindProperty("autoCreateIfEmpty").boolValue = false;
            
            so.ApplyModifiedProperties();
            EditorUtility.SetDirty(visualizer);
            EditorSceneManager.MarkSceneDirty(EditorSceneManager.GetActiveScene());

            Debug.Log($"[WireUpJoints] Wired {leftCount}/26 left, {rightCount}/26 right joints");
            
            if (leftCount < 26 || rightCount < 26)
            {
                Debug.LogWarning("[WireUpJoints] Some joints not found! Check hierarchy.");
            }
        }

        private static Transform FindJoint(Transform parent, string name)
        {
            if (parent.name == name) return parent;
            
            foreach (Transform child in parent)
            {
                var result = FindJoint(child, name);
                if (result != null) return result;
            }
            
            return null;
        }
    }
}

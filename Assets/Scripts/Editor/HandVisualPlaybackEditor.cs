using UnityEditor;
using PurdueXRLab.XRDataRecorder.Playback;

namespace PurdueXRLab.XRDataRecorder.Editor
{
    /// <summary>
    /// Custom editor for HandVisualPlayback.
    /// </summary>
    [CustomEditor(typeof(HandVisualPlayback))]
    public class HandVisualPlaybackEditor : UnityEditor.Editor
    {
        public override void OnInspectorGUI()
        {
            DrawDefaultInspector();
            
            EditorGUILayout.Space();
            EditorGUILayout.HelpBox(
                "Visualizes hand tracking data from CSV files.\n" +
                "Assign 26 joint transforms in HandJointId order:\n" +
                "Palm, Wrist, Thumb(4), Index(5), Middle(5), Ring(5), Pinky(5)",
                MessageType.Info);
        }
    }
}

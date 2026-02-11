using UnityEditor;
using PurdueXRLab.XRDataRecorder.Playback;

namespace PurdueXRLab.XRDataRecorder.Editor
{
    /// <summary>
    /// Custom editor for CameraSphereTracker.
    /// </summary>
    [CustomEditor(typeof(CameraSphereTracker))]
    public class CameraSphereTrackerEditor : UnityEditor.Editor
    {
        public override void OnInspectorGUI()
        {
            DrawDefaultInspector();
            
            EditorGUILayout.Space();
            EditorGUILayout.HelpBox(
                "Visualizes head tracking data from CSV file.\n" +
                "Automatically registers with PlaybackController for synchronized playback.",
                MessageType.Info);
        }
    }
}

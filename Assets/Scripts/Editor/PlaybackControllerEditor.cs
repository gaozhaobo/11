using UnityEngine;
using UnityEditor;
using PurdueXRLab.XRDataRecorder.Playback;

namespace PurdueXRLab.XRDataRecorder.Editor
{
    /// <summary>
    /// Custom editor for PlaybackController showing keyboard shortcuts and runtime status.
    /// </summary>
    [CustomEditor(typeof(PlaybackController))]
    public class PlaybackControllerEditor : UnityEditor.Editor
    {
        public override void OnInspectorGUI()
        {
            DrawDefaultInspector();
            
            EditorGUILayout.Space();
            EditorGUILayout.LabelField("Keyboard Shortcuts", EditorStyles.boldLabel);
            EditorGUILayout.HelpBox(
                "Space     - Play/Pause\n" +
                "S         - Stop\n" +
                "R         - Restart\n" +
                "→         - Skip +5s\n" +
                "←         - Skip -5s\n" +
                "↑         - Speed Up\n" +
                "↓         - Speed Down\n" +
                "L         - Toggle Loop\n" +
                "H         - Hide/Show Panel",
                MessageType.None);
            
            if (!Application.isPlaying)
            {
                EditorGUILayout.Space();
                EditorGUILayout.HelpBox("Enter Play mode to use playback controls.", MessageType.Info);
                return;
            }
            
            DrawRuntimeStatus();
        }
        
        private void DrawRuntimeStatus()
        {
            var controller = (PlaybackController)target;
            
            EditorGUILayout.Space();
            EditorGUILayout.LabelField("Runtime Status", EditorStyles.boldLabel);
            EditorGUILayout.LabelField("Playing:", controller.IsPlaying ? "Yes" : "No");
            EditorGUILayout.LabelField("Current Time:", $"{controller.CurrentTime:F2}s");
            EditorGUILayout.LabelField("Total Duration:", $"{controller.TotalDuration:F2}s");
            EditorGUILayout.LabelField("Speed:", $"{controller.PlaybackSpeed:F2}x");
            EditorGUILayout.LabelField("Loop:", controller.Loop ? "Yes" : "No");
            
            EditorGUILayout.Space();
            EditorGUILayout.BeginHorizontal();
            
            if (GUILayout.Button(controller.IsPlaying ? "Pause" : "Play"))
            {
                if (controller.IsPlaying)
                    controller.Pause();
                else
                    controller.Play();
            }
            
            if (GUILayout.Button("Stop"))
                controller.Stop();
            
            if (GUILayout.Button("Restart"))
                controller.Restart();
            
            EditorGUILayout.EndHorizontal();
            
            Repaint();
        }
    }
}

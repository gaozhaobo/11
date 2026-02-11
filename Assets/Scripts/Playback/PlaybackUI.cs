using UnityEngine;
using UnityEngine.UI;

namespace PurdueXRLab.XRDataRecorder.Playback
{
    /// <summary>
    /// Simple playback UI with bottom status bar.
    /// All controls via keyboard shortcuts.
    /// </summary>
    [RequireComponent(typeof(PlaybackController))]
    public class PlaybackUI : MonoBehaviour
    {
        #region Constants
        
        private const int FontSize = 36;
        private static readonly Color PanelColor = new(0.1f, 0.1f, 0.12f, 0.9f);
        private static readonly Color AccentColor = new(0.3f, 0.8f, 1f);
        
        #endregion
        
        #region Private Fields
        
        private Canvas _canvas;
        private GameObject _shortcutPanel;
        private Text _statusText;
        private Text _timeText;
        private RectTransform _progressFill;
        private PlaybackController _playbackController;
        
        #endregion
        
        #region Unity Lifecycle
        
        private void Awake()
        {
            _playbackController = GetComponent<PlaybackController>();
            CreateUI();
        }
        
        private void Update()
        {
            UpdateUI();
        }
        
        #endregion
        
        #region UI Creation
        
        private void CreateUI()
        {
            CreateCanvas();
            CreateBottomBar();
            CreateShortcutPanel();
        }
        
        private void CreateCanvas()
        {
            var canvasObj = new GameObject("PlaybackCanvas");
            _canvas = canvasObj.AddComponent<Canvas>();
            _canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            _canvas.sortingOrder = 100;
            
            var scaler = canvasObj.AddComponent<CanvasScaler>();
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1920, 1080);
            scaler.matchWidthOrHeight = 0.5f;
            
            canvasObj.AddComponent<GraphicRaycaster>();
        }
        
        private void CreateBottomBar()
        {
            // Container
            var bottomBar = CreateUIObject("BottomBar", _canvas.transform);
            var barRect = bottomBar.GetComponent<RectTransform>();
            barRect.anchorMin = new Vector2(0, 0);
            barRect.anchorMax = new Vector2(1, 0);
            barRect.pivot = new Vector2(0.5f, 0);
            barRect.anchoredPosition = Vector2.zero;
            barRect.sizeDelta = new Vector2(0, 100);
            
            bottomBar.AddComponent<Image>().color = PanelColor;
            
            // Progress bar background
            var progressBg = CreateUIObject("ProgressBg", bottomBar.transform);
            var progressBgRect = progressBg.GetComponent<RectTransform>();
            progressBgRect.anchorMin = new Vector2(0, 1);
            progressBgRect.anchorMax = new Vector2(1, 1);
            progressBgRect.pivot = new Vector2(0.5f, 1);
            progressBgRect.anchoredPosition = Vector2.zero;
            progressBgRect.sizeDelta = new Vector2(0, 10);
            
            progressBg.AddComponent<Image>().color = new Color(0.3f, 0.3f, 0.3f, 1f);
            
            // Progress bar fill
            var progressFillObj = CreateUIObject("ProgressFill", progressBg.transform);
            _progressFill = progressFillObj.GetComponent<RectTransform>();
            _progressFill.anchorMin = new Vector2(0, 0);
            _progressFill.anchorMax = new Vector2(0, 1);
            _progressFill.pivot = new Vector2(0, 0.5f);
            _progressFill.anchoredPosition = Vector2.zero;
            _progressFill.sizeDelta = Vector2.zero;
            
            progressFillObj.AddComponent<Image>().color = AccentColor;
            
            // Status text (left)
            _statusText = CreateText("StatusText", bottomBar.transform,
                new Vector2(0, 0), new Vector2(0.5f, 1), new Vector2(0, 0.5f),
                new Vector2(30, -3), new Vector2(-60, -6),
                TextAnchor.MiddleLeft, "⏸ Paused | 1.00x");
            
            // Time text (right)
            _timeText = CreateText("TimeText", bottomBar.transform,
                new Vector2(0.5f, 0), new Vector2(1, 1), new Vector2(1, 0.5f),
                new Vector2(-30, -3), new Vector2(-60, -6),
                TextAnchor.MiddleRight, "00:00.00 / 00:00.00");
        }
        
        private void CreateShortcutPanel()
        {
            _shortcutPanel = CreateUIObject("ShortcutPanel", _canvas.transform);
            var panelRect = _shortcutPanel.GetComponent<RectTransform>();
            panelRect.anchorMin = new Vector2(1, 1);
            panelRect.anchorMax = new Vector2(1, 1);
            panelRect.pivot = new Vector2(1, 1);
            panelRect.anchoredPosition = new Vector2(-20, -20);
            panelRect.sizeDelta = new Vector2(450, 480);
            
            _shortcutPanel.AddComponent<Image>().color = PanelColor;
            
            var textObj = CreateUIObject("ShortcutText", _shortcutPanel.transform);
            var textRect = textObj.GetComponent<RectTransform>();
            textRect.anchorMin = Vector2.zero;
            textRect.anchorMax = Vector2.one;
            textRect.offsetMin = new Vector2(30, 25);
            textRect.offsetMax = new Vector2(-30, -25);
            
            var shortcutText = textObj.AddComponent<Text>();
            shortcutText.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            shortcutText.fontSize = FontSize - 8;
            shortcutText.color = Color.white;
            shortcutText.alignment = TextAnchor.UpperLeft;
            shortcutText.lineSpacing = 1.3f;
            shortcutText.supportRichText = true;
            shortcutText.text = 
                "<b>⌨ Keyboard Controls</b>\n\n" +
                "<color=#4CF>Space</color>          Play / Pause\n" +
                "<color=#4CF>S</color>                  Stop\n" +
                "<color=#4CF>R</color>                  Restart\n" +
                "<color=#4CF>→</color>                  Skip +5s\n" +
                "<color=#4CF>←</color>                  Skip -5s\n" +
                "<color=#4CF>↑</color>                  Speed Up\n" +
                "<color=#4CF>↓</color>                  Speed Down\n" +
                "<color=#4CF>L</color>                  Toggle Loop\n" +
                "<color=#4CF>H</color>                  Hide Panel";
        }
        
        #endregion
        
        #region UI Update
        
        private void UpdateUI()
        {
            if (_playbackController == null) return;
            
            if (_statusText != null)
            {
                string state = _playbackController.IsPlaying ? "▶ Playing" : "⏸ Paused";
                string loop = _playbackController.Loop ? " 🔁" : "";
                _statusText.text = $"{state} | {_playbackController.PlaybackSpeed:F2}x{loop}";
            }
            
            if (_timeText != null)
            {
                string current = FormatTime(_playbackController.CurrentTime);
                string total = FormatTime(_playbackController.TotalDuration);
                _timeText.text = $"{current} / {total}";
            }
            
            if (_progressFill != null && _playbackController.TotalDuration > 0)
            {
                float progress = _playbackController.CurrentTime / _playbackController.TotalDuration;
                _progressFill.anchorMax = new Vector2(progress, 1);
            }
        }
        
        #endregion
        
        #region Public API
        
        public void ToggleShortcutPanel()
        {
            if (_shortcutPanel != null)
            {
                _shortcutPanel.SetActive(!_shortcutPanel.activeSelf);
            }
        }
        
        #endregion
        
        #region Helpers
        
        private static GameObject CreateUIObject(string name, Transform parent)
        {
            var obj = new GameObject(name);
            obj.transform.SetParent(parent, false);
            obj.AddComponent<RectTransform>();
            return obj;
        }
        
        private static Text CreateText(string name, Transform parent,
            Vector2 anchorMin, Vector2 anchorMax, Vector2 pivot,
            Vector2 anchoredPos, Vector2 sizeDelta,
            TextAnchor alignment, string content)
        {
            var obj = CreateUIObject(name, parent);
            var rect = obj.GetComponent<RectTransform>();
            rect.anchorMin = anchorMin;
            rect.anchorMax = anchorMax;
            rect.pivot = pivot;
            rect.anchoredPosition = anchoredPos;
            rect.sizeDelta = sizeDelta;
            
            var text = obj.AddComponent<Text>();
            text.font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
            text.fontSize = FontSize;
            text.color = Color.white;
            text.alignment = alignment;
            text.text = content;
            
            return text;
        }
        
        private static string FormatTime(float seconds)
        {
            int mins = (int)(seconds / 60f);
            int secs = (int)(seconds % 60f);
            int ms = (int)((seconds % 1f) * 100f);
            return $"{mins:D2}:{secs:D2}.{ms:D2}";
        }
        
        #endregion
    }
}

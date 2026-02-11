namespace PurdueXRLab.XRDataRecorder.Playback
{
    /// <summary>
    /// Interface for components that receive synchronized playback updates.
    /// </summary>
    public interface IPlaybackListener
    {
        /// <summary>
        /// Called each frame during playback with the current global timestamp.
        /// </summary>
        /// <param name="timestamp">Current timestamp in milliseconds (matches original recording).</param>
        /// <param name="playbackTime">Time in seconds since playback start.</param>
        void OnPlaybackUpdate(long timestamp, float playbackTime);
    }
}

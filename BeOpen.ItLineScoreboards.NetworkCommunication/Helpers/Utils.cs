using System;
using System.Text;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Helpers
{
    internal static class Utils
    {
        public static DateTime ScoreboardTimeStampToDateTime(int timeStamp)
        {
            DateTime dt = new DateTime(2000, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc);
            dt = dt.AddSeconds(timeStamp).ToLocalTime();
            return dt;
        }

        public static int DateTimeToScoreboardTimeStamp(DateTime time)
        {
            var timeSpan = time - new DateTime(2000, 1, 1, 0, 0, 0);
            return (int) timeSpan.TotalSeconds;
        }

        public static string GetTextFromBytes(byte[] bytes)
        {
            var message = Encoding.GetEncoding(1251).GetString(bytes);
            message = message.Remove(message.IndexOf("\0", StringComparison.Ordinal));
            return message;
        }

        public static byte[] GetBytesFromString(string text, int arrayLength)
        {
            var textBytes = Encoding.GetEncoding(1251).GetBytes(text);
            byte[] buffer = new byte[arrayLength];
            if (textBytes.Length > arrayLength)
            {
                throw new ArgumentException($"{nameof(text)} too long for array");
            }
            textBytes.CopyTo(buffer, 0);
            return buffer;
        }
    }
}
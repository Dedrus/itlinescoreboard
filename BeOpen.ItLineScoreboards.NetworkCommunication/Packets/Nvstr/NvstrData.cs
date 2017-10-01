using System;
using System.Collections.Generic;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Helpers;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class NvstrData : Data
    {
        private const int StringLength = 1024;
        public const int DataLength = StringLength + 2;
        public readonly StringMessage NvstrMessage;

        public NvstrData([NotNull] StringMessage message)
        {
            if (message == null)
            {
                throw new ArgumentNullException(nameof(message));
            }
            NvstrMessage = message;
        }

        public NvstrData(byte[] bytes)
        {
            var nvstrIndex = bytes[0];
            var stringProfile = (StringProfile) bytes[1];
            var array = new SubArray<byte>(bytes, 2).ToArray();
            var message = Utils.GetTextFromBytes(array);
            NvstrMessage = new StringMessage(nvstrIndex, stringProfile, message);
        }

        public override byte[] ToByteArray()
        {
            List<byte> buffer = new List<byte>();
            buffer.Add(NvstrMessage.StringIndex);
            buffer.Add((byte) NvstrMessage.StringProfile);
            buffer.AddRange(Utils.GetBytesFromString(NvstrMessage.Value, StringLength));
            return buffer.ToArray();
        }
    }
}
using System.Collections.Generic;
using System.Linq;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Helpers;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class RstrData : Data
    {
        private const int StringLength = 128;
        internal const int DataLength = (128 + 1 + 1) * 8;
        public readonly IEnumerable<StringMessage> RstrMessages;

        internal RstrData([NotNull] IEnumerable<StringMessage> rstrMessages)
        {
            RstrMessages = rstrMessages;
        }

        public RstrData(byte[] rstrMessages)
        {
            SubArray<byte> indexes = new SubArray<byte>(rstrMessages, 0, 8);
            SubArray<byte> stringProfiles = new SubArray<byte>(rstrMessages, 8, 8);
            SubArray<byte> data = new SubArray<byte>(rstrMessages, 16);
            List<StringMessage> messages = new List<StringMessage>();
            for (int i = 0; i < indexes.Count; i++)
            {
                if (indexes[i] != 255)
                {
                    var stringBytes = new SubArray<byte>(data.ToArray(), StringLength * i, StringLength).ToArray();
                    var message = Utils.GetTextFromBytes(stringBytes);
                    messages.Add(new StringMessage(indexes[i], (StringProfile) stringProfiles[i], message));
                }
            }
            RstrMessages = messages;
        }

        public override byte[] ToByteArray()
        {
            List<byte> buffer = new List<byte>();
            foreach (var rstrMessage in RstrMessages)
                buffer.Add(rstrMessage.StringIndex);
            for (int i = 0; i < 8 - RstrMessages.Count(); i++)
                buffer.Add(0xff);


            foreach (var rstrMessage in RstrMessages)
                buffer.Add((byte) rstrMessage.StringProfile);
            for (int i = 0; i < 8 - RstrMessages.Count(); i++)
                buffer.Add(0x00);

            foreach (var rstrMessage in RstrMessages)
            {
                //List<byte> stringBuffer = new List<byte>(128);
                //var bytesString = Encoding.GetEncoding(1251).GetBytes(rstrMessage.Value);
                //stringBuffer.AddRange(bytesString);
                //for (int i = stringBuffer.Count; i < StringLength; i++)
                //    stringBuffer.Add(0);
                buffer.AddRange(Utils.GetBytesFromString(rstrMessage.Value, StringLength));
            }
            for (int i = buffer.Count; i < DataLength; i++)
                buffer.Add(0x00);
            return buffer.ToArray();
        }
    }
}
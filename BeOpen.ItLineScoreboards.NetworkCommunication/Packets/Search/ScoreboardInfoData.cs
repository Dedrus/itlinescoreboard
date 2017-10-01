using System;
using System.Net;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Helpers;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class ScoreboardInfoData : Data
    {
        public const int DataLength = 48;

        public ScoreboardInfoData(byte[] bytes)
        {
            SubArray<byte> name = new SubArray<byte>(bytes, 0, 32);
            Name = Utils.GetTextFromBytes(name.ToArray());

            SubArray<byte> ip = new SubArray<byte>(bytes, 32, 4);
            Ip = new IPAddress(ip.ToArray());

            SubArray<byte> mask = new SubArray<byte>(bytes, 36, 4);
            NetMask = new IPAddress(mask.ToArray());

            SubArray<byte> gateway = new SubArray<byte>(bytes, 40, 4);
            DefaultGateway = new IPAddress(gateway.ToArray());

            SubArray<byte> version = new SubArray<byte>(bytes, 44, 2);
            Version = BitConverter.ToInt16(bytes, version.Offset);

            SubArray<byte> date = new SubArray<byte>(bytes, 46);
            short timeStamp = BitConverter.ToInt16(bytes, date.Offset);
            Date = Utils.ScoreboardTimeStampToDateTime(timeStamp);
        }

        public string Name { get; set; }
        public IPAddress Ip { get; set; }
        public IPAddress NetMask { get; set; }
        public IPAddress DefaultGateway { get; set; }
        public int Version { get; set; }
        public DateTime Date { get; set; }

        public override byte[] ToByteArray()
        {
            throw new NotImplementedException();
        }
    }
}
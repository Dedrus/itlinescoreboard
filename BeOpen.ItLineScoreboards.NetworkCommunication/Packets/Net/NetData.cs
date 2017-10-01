using System.Collections.Generic;
using System.Net;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Helpers;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class NetData : Data
    {
        public const int DataLength = 44;

        internal NetData(byte[] bytes)
        {
            SubArray<byte> name = new SubArray<byte>(bytes, 0, 32);
            Name = Utils.GetTextFromBytes(name.ToArray());

            SubArray<byte> ip = new SubArray<byte>(bytes, 32, 4);
            Ip = new IPAddress(ip.ToArray());

            SubArray<byte> mask = new SubArray<byte>(bytes, 36, 4);
            NetMask = new IPAddress(mask.ToArray());

            SubArray<byte> gateway = new SubArray<byte>(bytes, 40, 4);
            DefaultGateway = new IPAddress(gateway.ToArray());
        }

        internal NetData(ScoreboardNetInfo s)
        {
            Name = s.Name;
            Ip = s.Ip;
            NetMask = s.NetMask;
            DefaultGateway = s.DefaultGateway;
        }

        public string Name { get; set; }
        public IPAddress Ip { get; set; }
        public IPAddress NetMask { get; set; }
        public IPAddress DefaultGateway { get; set; }

        public override byte[] ToByteArray()
        {
            List<byte> buffer = new List<byte>();
            buffer.AddRange(Utils.GetBytesFromString(Name, 32));
            buffer.AddRange(Ip.GetAddressBytes());
            buffer.AddRange(NetMask.GetAddressBytes());
            buffer.AddRange(DefaultGateway.GetAddressBytes());
            return buffer.ToArray();
        }
    }
}
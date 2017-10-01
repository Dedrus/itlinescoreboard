using System.Net;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data
{
    public class ScoreboardNetInfo
    {
        public ScoreboardNetInfo()
        {
        }

        internal ScoreboardNetInfo(NetData data)
        {
            Name = data.Name;
            Ip = data.Ip;
            NetMask = data.NetMask;
            DefaultGateway = data.DefaultGateway;
        }

        public string Name { get; set; }
        public IPAddress Ip { get; set; }
        public IPAddress NetMask { get; set; }
        public IPAddress DefaultGateway { get; set; }
    }
}
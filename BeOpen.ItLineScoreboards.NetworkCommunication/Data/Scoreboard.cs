using System;
using System.Net;
using System.Net.NetworkInformation;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data
{
    public class Scoreboard
    {
        internal Scoreboard([NotNull] AnswerSearchPacket packet)
        {
            if (packet == null) throw new ArgumentNullException(nameof(packet));
            var data = (ScoreboardInfoData) packet.Data;
            Name = data.Name;
            Mac = packet.Mac;
            IpAddress = data.Ip;
            NetMask = data.NetMask;
            DefaultGateway = data.DefaultGateway;
            Version = data.Version;
            Date = data.Date;
        }

        public string Name { get; internal set; }
        public PhysicalAddress Mac { get; internal set; }
        public IPAddress IpAddress { get; internal set; }
        public IPAddress NetMask { get; internal set; }
        public IPAddress DefaultGateway { get; internal set; }
        public int Version { get; internal set; }
        public DateTime Date { get; internal set; }

        public override string ToString()
        {
            return $"{Mac} - {IpAddress} ({Name}, {Version})";
        }
    }
}
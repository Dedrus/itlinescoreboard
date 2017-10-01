using System.Net.NetworkInformation;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal abstract class PacketBase
    {
        //6 bytes
        [NotNull]
        public abstract PhysicalAddress Mac { get; }

        //1 byte
        public abstract Command Command { get; }

        //1 byte
        public abstract byte ScoreboardType { get; }

        //4 bytes
        public abstract uint MessageId { get; }

        [CanBeNull]
        public abstract Data Data { get; }
    }
}
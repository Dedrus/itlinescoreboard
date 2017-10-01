using System.Net.NetworkInformation;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class SetNetPacket : SendPacketBase
    {
        public const int Length = 12 + NetData.DataLength;
        private readonly Command _command = Command.SetNet;
        [NotNull] private readonly NetData _data;

        [NotNull] private readonly PhysicalAddress _mac;

        private readonly uint _messageId;
        private readonly byte _scoreboardType;

        public SetNetPacket([NotNull] PhysicalAddress mac, byte scoreboardType, uint messageId,
            [NotNull] NetData data)
        {
            _mac = mac;
            _scoreboardType = scoreboardType;
            _messageId = messageId;
            _data = data;
        }

        public override PhysicalAddress Mac => _mac;

        public override Command Command => _command;

        public override byte ScoreboardType => _scoreboardType;

        public override uint MessageId => _messageId;

        [NotNull]
        public override Data Data => _data;
    }
}
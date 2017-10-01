using System.Net.NetworkInformation;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class SetNvPacket : SendPacketBase
    {
        public const int Length = 12 + NvData.DataLength;
        private readonly Command _command = Command.SetNv;

        [NotNull] private readonly NvData _data;

        [NotNull] private readonly PhysicalAddress _mac;

        private readonly uint _messageId;
        private readonly byte _scoreboardType;

        public SetNvPacket([NotNull] PhysicalAddress mac, byte scoreboardType, uint messageId,
            [NotNull] NvData data)
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

        public override Data Data => _data;
    }
}
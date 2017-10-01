using System.Net.NetworkInformation;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class GetRstrPacket : SendPacketBase
    {
        private readonly Command _command = Command.GetRstr;

        [NotNull] private readonly GetRstrData _data;

        [NotNull] private readonly PhysicalAddress _mac;

        private readonly uint _messageId;
        private readonly byte _scoreboardType;

        public GetRstrPacket([NotNull] PhysicalAddress mac, byte scoreboardType, uint messageId,
            [NotNull] GetRstrData data)
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
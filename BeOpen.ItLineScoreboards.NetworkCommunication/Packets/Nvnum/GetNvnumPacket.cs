using System.Net.NetworkInformation;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class GetNvnumPacket : SendPacketBase
    {
        public const int Length = 12 + GetNumData.DataLength;
        private readonly Command _command = Command.GetNvnum;

        [NotNull] private readonly GetNumData _data;

        [NotNull] private readonly PhysicalAddress _mac;

        private readonly uint _messageId;
        private readonly byte _scoreboardType;

        public GetNvnumPacket([NotNull] PhysicalAddress mac, byte scoreboardType, uint messageId,
            [NotNull] GetNumData data)
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
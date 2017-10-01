using System.Net.NetworkInformation;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class GetNvPacket : SendPacketBase
    {
        private readonly Command _command = Command.GetNv;


        [NotNull] private readonly PhysicalAddress _mac;

        private readonly uint _messageId;
        private readonly byte _scoreboardType;

        public GetNvPacket([NotNull] PhysicalAddress mac, byte scoreboardType, uint messageId)
        {
            _mac = mac;
            _scoreboardType = scoreboardType;
            _messageId = messageId;
        }

        public override PhysicalAddress Mac => _mac;

        public override Command Command => _command;

        public override byte ScoreboardType => _scoreboardType;

        public override uint MessageId => _messageId;

        public override Data Data => null;
    }
}
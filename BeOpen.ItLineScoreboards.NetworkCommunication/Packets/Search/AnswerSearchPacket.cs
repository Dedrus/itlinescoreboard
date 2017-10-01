using System;
using System.Net.NetworkInformation;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Helpers;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class AnswerSearchPacket : ReceivePacketBase
    {
        public const int Length = 60;
        private readonly Command _command = Command.AnsRstr;
        [NotNull] private readonly ScoreboardInfoData _data;

        [NotNull] private readonly PhysicalAddress _mac;

        private readonly uint _messageId;
        private readonly byte _scoreboardType;

        public AnswerSearchPacket(byte[] bytes)
        {
            SubArray<byte> mac = new SubArray<byte>(bytes, 0, 6);
            _mac = new PhysicalAddress(mac.ToArray());
            _scoreboardType = bytes[7];
            SubArray<byte> messageId = new SubArray<byte>(bytes, 8, 4);
            _messageId = BitConverter.ToUInt32(messageId.ToArray(), 0);
            SubArray<byte> data = new SubArray<byte>(bytes, 12);
            _data = new ScoreboardInfoData(data.ToArray());
        }


        public override PhysicalAddress Mac => _mac;

        public override Command Command => _command;

        public override byte ScoreboardType => _scoreboardType;

        public override uint MessageId => _messageId;

        [NotNull]
        public override Data Data => _data;
    }
}
using System;
using System.Collections.Generic;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal static class PacketFactory
    {
        private static readonly Dictionary<Command, Func<byte[], ReceivePacketBase>> AnswersMap =
            new Dictionary<Command, Func<byte[], ReceivePacketBase>>();

        static PacketFactory()
        {
            //register types here
            AnswersMap[Command.AnsRstr] = bytes => new AnsRstrPacket(bytes);
            AnswersMap[Command.AnsNvstr] = bytes => new AnsNvstrPacket(bytes);
            AnswersMap[Command.AnsInfo] = bytes => new AnswerSearchPacket(bytes);
            AnswersMap[Command.AnsNv] = bytes => new AnsNvPacket(bytes);
            AnswersMap[Command.AnsNet] = bytes => new AnsNetPacket(bytes);
            AnswersMap[Command.AnsRnum] = bytes => new AnsRnumPacket(bytes);
            AnswersMap[Command.AnsNvnum] = bytes => new AnsNvnumPacket(bytes);
        }

        internal static ReceivePacketBase FromByte([NotNull] byte[] data)
        {
            if (data == null)
            {
                throw new ArgumentNullException(nameof(data));
            }
            if (data.Length < 12)
            {
                throw new ArgumentException(
                    $"{nameof(data)} array does not contains elements for parsing(missing command byte)");
            }
            Command cmd = (Command) data[6];
            Func<byte[], ReceivePacketBase> importer;
            AnswersMap.TryGetValue(cmd, out importer);
            if (importer != null)
            {
                return importer(data);
            }
            throw new NotImplementedException($"{cmd} is currently not supported!");
        }
    }
}
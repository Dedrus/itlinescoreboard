using System;
using System.Collections.Generic;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal abstract class SendPacketBase : PacketBase
    {
        public byte[] ToDatagram()
        {
            List<byte> buffer = new List<byte>();
            buffer.AddRange(Mac.GetAddressBytes());
            buffer.Add((byte) Command);
            buffer.Add(ScoreboardType);
            buffer.AddRange(BitConverter.GetBytes(MessageId));
            if (Data != null) buffer.AddRange(Data.ToByteArray());
            return buffer.ToArray();
        }
    }
}
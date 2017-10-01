using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal abstract class Data
    {
        [NotNull]
        public abstract byte[] ToByteArray();
    }
}
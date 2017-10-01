namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class GetNvstrData : Data
    {
        public readonly byte NvstrIndex;

        internal GetNvstrData(byte nvstrIndex)
        {
            NvstrIndex = nvstrIndex;
        }

        public GetNvstrData(byte[] bytes)
        {
            NvstrIndex = bytes[0];
        }

        public override byte[] ToByteArray()
        {
            return new[] {NvstrIndex};
        }
    }
}
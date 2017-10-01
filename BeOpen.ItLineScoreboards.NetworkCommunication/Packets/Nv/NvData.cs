using System;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class NvData : Data
    {
        public const int DataLength = 4;
        private readonly int _brightness;

        public NvData(int brightness)
        {
            _brightness = brightness;
        }

        public NvData(byte[] bytes)
        {
            _brightness = BitConverter.ToInt32(bytes, 0);
        }

        internal int Brightness => _brightness;

        public override byte[] ToByteArray()
        {
            return BitConverter.GetBytes(_brightness);
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class GetNumData : Data
    {
        public const int DataLength = RnumSize * 2;
        private const int RnumSize = 128;
        private readonly ushort[] _indexes = new ushort[RnumSize];

        public GetNumData([NotNull] IEnumerable<ushort> indexes)
        {
            if (indexes == null)
            {
                throw new ArgumentNullException(nameof(indexes));
            }
            var enumerable = indexes.ToArray();
            if (enumerable.Length > RnumSize)
            {
                throw new ArgumentException($"{nameof(indexes)} count is greater than 8.");
            }
            enumerable.CopyTo(_indexes, 0);
            for (int index = enumerable.Length; index < RnumSize; index++)
            {
                _indexes[index] = ushort.MaxValue;
            }
        }

        public override byte[] ToByteArray()
        {
            List<byte> buffer = new List<byte>();
            foreach (var index in _indexes)
            {
                buffer.AddRange(BitConverter.GetBytes(index));
            }
            return buffer.ToArray();
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class GetRstrData : Data
    {
        private readonly byte[] _indexes = new byte[8];

        public GetRstrData([NotNull] IEnumerable<byte> indexes)
        {
            if (indexes == null)
            {
                throw new ArgumentNullException(nameof(indexes));
            }
            var enumerable = indexes as byte[] ?? indexes.ToArray();
            if (enumerable.Length > 8)
            {
                throw new ArgumentException($"{nameof(indexes)} count is greater than 8.");
            }
            enumerable.CopyTo(_indexes, 0);
            for (int index = enumerable.Length; index < 8; index++)
            {
                _indexes[index] = 255;
            }
        }

        public override byte[] ToByteArray()
        {
            return _indexes;
        }
    }
}
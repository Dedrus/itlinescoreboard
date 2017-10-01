using System;
using System.Collections.Generic;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal class NumData : Data
    {
        private const int RnumSize = 128;
        internal const int DataLength = RnumSize * 2 + RnumSize * 4;
        public readonly IDictionary<ushort, uint> NumDictionary;

        internal NumData([NotNull] IDictionary<ushort, uint> numDictionary)
        {
            if (numDictionary == null)
            {
                throw new ArgumentNullException(nameof(numDictionary));
            }
            if (numDictionary.Count > RnumSize)
            {
                throw new ArgumentException($"{nameof(numDictionary)} count of elements should be less than 256!");
            }
            NumDictionary = numDictionary;
        }

        public NumData(byte[] bytes)
        {
            NumDictionary = new Dictionary<ushort, uint>();
            for (int i = 0; i < RnumSize; i++)
            {
                var index = BitConverter.ToUInt16(bytes, i * 2);
                if (index == ushort.MaxValue)
                {
                    continue;
                }
                var value = BitConverter.ToUInt32(bytes, RnumSize * 2 + i * 4);
                NumDictionary.Add(index, value);
            }
        }

        public override byte[] ToByteArray()
        {
            List<byte> buffer = new List<byte>();
            foreach (var i in NumDictionary.Keys)
            {
                buffer.AddRange(BitConverter.GetBytes(i));
            }
            var ignoreBytes = BitConverter.GetBytes(short.MaxValue);
            for (int i = NumDictionary.Count; i < RnumSize; i++)
            {
                buffer.AddRange(ignoreBytes);
            }
            foreach (var i in NumDictionary.Values)
            {
                buffer.AddRange(BitConverter.GetBytes(i));
            }
            ignoreBytes = BitConverter.GetBytes(int.MaxValue);
            for (int i = NumDictionary.Count; i < RnumSize; i++)
            {
                buffer.AddRange(ignoreBytes);
            }
            return buffer.ToArray();
        }
    }
}
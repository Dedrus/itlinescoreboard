using System;
using System.Collections.Generic;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Helpers
{
    internal class SubArray<T>
    {
        private ArraySegment<T> _segment;

        public SubArray(T[] array, int offset, int count)
        {
            _segment = new ArraySegment<T>(array, offset, count);
        }

        public SubArray(T[] array, int offset)
        {
            _segment = new ArraySegment<T>(array, offset, array.Length - offset);
        }

        public int Count => _segment.Count;

        public int Offset => _segment.Offset;

        public T this[int index] => _segment.Array[_segment.Offset + index];

        public T[] ToArray()
        {
            T[] temp = new T[_segment.Count];
            Array.Copy(_segment.Array, _segment.Offset, temp, 0, _segment.Count);
            return temp;
        }

        public IEnumerator<T> GetEnumerator()
        {
            for (int i = _segment.Offset; i < _segment.Offset + _segment.Count; i++)
            {
                yield return _segment.Array[i];
            }
        }
    }
}
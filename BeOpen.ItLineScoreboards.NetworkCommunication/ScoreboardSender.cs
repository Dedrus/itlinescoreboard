using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using System.Threading;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data;
using BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets;
using JetBrains.Annotations;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication
{
    [UsedImplicitly]
    public class ScoreboardSender : IDisposable
    {
        private const int ScoreboardsPort = 5001;

        /// <summary>
        ///     Задержка для обработки пакетов устройствами.
        /// </summary>
        private const int SendDelay = 150;

        private static readonly PhysicalAddress BroadcastMac = PhysicalAddress.Parse("FF-FF-FF-FF-FF-FF");
        private readonly IPEndPoint _endPoint = new IPEndPoint(IPAddress.Broadcast, ScoreboardsPort);
        private readonly Socket _socket;
        public readonly int SocketPort;
        private uint _messageId;

        public ScoreboardSender(int socketPort)
        {
            _socket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            _socket.EnableBroadcast = true;
            SocketPort = socketPort;
            _socket.Bind(new IPEndPoint(IPAddress.Any, SocketPort));
        }

        public void Dispose()
        {
            _socket.Dispose();
        }

        /// <summary>
        ///     Ищет табло в сети
        /// </summary>
        /// <returns></returns>
        public IDictionary<PhysicalAddress, Scoreboard> FindScoreboards()
        {
            var target = BroadcastMac;
            var packetId = _messageId++;
            SearchPacket packet = new SearchPacket(target, 255, packetId);
            SendPacket(packet);
            var answer = ReceiveMultipleAnswers(AnswerSearchPacket.Length);
            return answer.ToDictionary(a => a.Key, a => new Scoreboard((AnswerSearchPacket) a.Value));
        }

        /// <summary>
        ///     Установка ячеек Rstr
        /// </summary>
        /// <param name="data"></param>
        /// <param name="target"></param>
        /// <param name="scoreboardType"></param>
        /// <returns></returns>
        public IEnumerable<StringMessage> SetRstrData([NotNull] IEnumerable<StringMessage> data,
            [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (data == null) throw new ArgumentNullException(nameof(data));
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            SetRstrPacket packet = new SetRstrPacket(target, scoreboardType, packetId, new RstrData(data));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsRstrPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((RstrData) answer.Data).RstrMessages;
            }
            return new List<StringMessage>();
        }

        public IEnumerable<StringMessage> GetRstrData([NotNull] byte[] indexes, [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (indexes == null) throw new ArgumentNullException(nameof(indexes));
            if (indexes.Length > 8)
            {
                throw new ArgumentException(nameof(indexes));
            }
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            GetRstrPacket packet = new GetRstrPacket(target, scoreboardType, packetId, new GetRstrData(indexes));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsRstrPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((RstrData) answer.Data).RstrMessages;
            }
            return new List<StringMessage>();
        }


        public IDictionary<ushort, uint> SetRnumData([NotNull] IDictionary<ushort, uint> data,
            [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (data == null) throw new ArgumentNullException(nameof(data));
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            SetRnumPacket packet = new SetRnumPacket(target, scoreboardType, packetId, new NumData(data));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsRnumPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NumData) answer.Data).NumDictionary;
            }
            return new Dictionary<ushort, uint>();
        }

        public IDictionary<ushort, uint> GetRnumData([NotNull] ushort[] indexes, [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (indexes == null) throw new ArgumentNullException(nameof(indexes));
            if (indexes.Length > 256)
            {
                throw new ArgumentException(nameof(indexes));
            }
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            GetRnumPacket packet = new GetRnumPacket(target, scoreboardType, packetId, new GetNumData(indexes));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsRnumPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NumData) answer.Data).NumDictionary;
            }
            return new Dictionary<ushort, uint>();
        }

        public IDictionary<ushort, uint> SetNvnumData([NotNull] IDictionary<ushort, uint> data,
            [CanBeNull] PhysicalAddress target, byte scoreboardType = 255)
        {
            if (data == null) throw new ArgumentNullException(nameof(data));
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            SetNvnumPacket packet = new SetNvnumPacket(target, scoreboardType, packetId, new NumData(data));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNvnumPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NumData) answer.Data).NumDictionary;
            }
            return new Dictionary<ushort, uint>();
        }

        public IDictionary<ushort, uint> GetNvnumData([NotNull] ushort[] indexes, [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (indexes == null) throw new ArgumentNullException(nameof(indexes));
            if (indexes.Length > 256)
            {
                throw new ArgumentException(nameof(indexes));
            }
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            GetNvnumPacket packet = new GetNvnumPacket(target, scoreboardType, packetId, new GetNumData(indexes));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNvnumPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NumData) answer.Data).NumDictionary;
            }
            return new Dictionary<ushort, uint>();
        }


        /// <summary>
        ///     Установка ячеек Nvstr
        /// </summary>
        /// <param name="data"></param>
        /// <param name="target"></param>
        /// <param name="scoreboardType"></param>
        /// <returns>null если не получен ответ</returns>
        [CanBeNull]
        public StringMessage SetNvstrData([NotNull] StringMessage data, [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (data == null) throw new ArgumentNullException(nameof(data));
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            SetNvstrPacket packet = new SetNvstrPacket(target, scoreboardType, packetId, new NvstrData(data));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNvstrPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NvstrData) answer.Data).NvstrMessage;
            }
            return null;
        }

        [CanBeNull]
        public ScoreboardNetInfo GetNetData([CanBeNull] PhysicalAddress target, byte scoreboardType = 255)
        {
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            GetNetPacket packet = new GetNetPacket(target, scoreboardType, packetId);
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNetPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                var data = (NetData) answer.Data;
                return new ScoreboardNetInfo(data);
            }
            return null;
        }

        [CanBeNull]
        public ScoreboardNetInfo SetNetData(ScoreboardNetInfo data, [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            SetNetPacket packet = new SetNetPacket(target, scoreboardType, packetId, new NetData(data));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNetPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                var answerData = (NetData) answer.Data;
                return new ScoreboardNetInfo(answerData);
            }
            return null;
        }

        [CanBeNull]
        public StringMessage GetNvstrData([CanBeNull] PhysicalAddress target, byte stringIndex,
            byte scoreboardType = 255)
        {
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            GetNvstrPacket packet = new GetNvstrPacket(target, scoreboardType, packetId, new GetNvstrData(stringIndex));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNvstrPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NvstrData) answer.Data).NvstrMessage;
            }
            return null;
        }

        public int SetBrightness(int brightness, [CanBeNull] PhysicalAddress target,
            byte scoreboardType = 255)
        {
            if (brightness < 0 || brightness > 100)
            {
                throw new ArgumentException($"{nameof(brightness)} must be greater than 0 or less than 100!");
            }
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            SetNvPacket packet = new SetNvPacket(target, scoreboardType, packetId, new NvData(brightness));
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNvPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NvData) answer.Data).Brightness;
            }
            return -1;
        }

        public int GetBrightness([CanBeNull] PhysicalAddress target, byte scoreboardType = 255)
        {
            if (target == null)
            {
                target = BroadcastMac;
            }
            var packetId = _messageId++;
            GetNvPacket packet = new GetNvPacket(target, scoreboardType, packetId);
            SendPacket(packet);
            var answer = ReceiveOneAnswer();
            if (answer != null && answer.MessageId == packetId)
            {
                answer = (AnsNvPacket) answer;
                // ReSharper disable once PossibleNullReferenceException there will be empty list if no messages will return;
                return ((NvData) answer.Data).Brightness;
            }
            return -1;
        }

        /// <summary>
        ///     Метод для отправки пакетов.
        /// </summary>
        /// <param name="packet"></param>
        private void SendPacket(SendPacketBase packet)
        {
            var dataGram = packet.ToDatagram();
            _socket.SendTo(dataGram, _endPoint);
            //todo вот это по идее должно быть async Task sendPacket и в теле метода должно быть await Task.Delay(senddelay). Но т.к. юзается .net 4.0. то так нельзя и я не знаю как правильно
            //Вообще тут по идее вся логика асинхронная должна быть, т.к. мы только отправляем через сокет пакеты, а вся обработка производится на других устройствах(чистая асинхронщина)
            Thread.Sleep(SendDelay);
        }

        [CanBeNull]
        private ReceivePacketBase ReceiveOneAnswer()
        {
            if (_socket.Available > 0)
            {
                var dataBuffer = new byte[_socket.Available];
                _socket.Receive(dataBuffer);
                ReceivePacketBase packet = PacketFactory.FromByte(dataBuffer);
                return packet;
            }
            return null;
        }

        private IDictionary<PhysicalAddress, ReceivePacketBase> ReceiveMultipleAnswers(int datagramLength)
        {
            Dictionary<PhysicalAddress, ReceivePacketBase> dict = new Dictionary<PhysicalAddress, ReceivePacketBase>();
            if (_socket.Available > 0)
            {
                for (int i = 0; i < _socket.Available / datagramLength; i++)
                {
                    var dataBuffer = new byte[datagramLength];
                    _socket.Receive(dataBuffer);
                    ReceivePacketBase packet = PacketFactory.FromByte(dataBuffer.ToArray());
                    dict.Add(packet.Mac, packet);
                }
            }
            return dict;
        }
    }
}
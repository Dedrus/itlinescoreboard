using System;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Packets
{
    internal enum Command : byte
    {
        /// <summary>
        ///     Команда поиска 1
        /// </summary>
        CmdSearch = 1,

        /// <summary>
        ///     Ответ на команду запроса информации о табло 2
        /// </summary>
        AnsInfo = 2, //!< Ответ на команду запроса информации о табло 

        /// <summary>
        ///     Запрос информации о табло 3
        /// </summary>
        GetInfo = 3,

        /// <summary>
        ///     Запрос сетевых настроек 4
        /// </summary>
        GetNet = 4,

        /// <summary>
        ///     Ответ на запрос сетевых настроек 5
        /// </summary>
        AnsNet = 5,

        /// Установка сетевых настроек 6
        SetNet = 6,

        /// <summary>
        ///     Запрос энергонезависимых данных 7
        /// </summary>
        GetNv = 7,

        /// <summary>
        ///     Ответ на запрос энергонезависимых данных 8
        /// </summary>
        AnsNv = 8,

        /// <summary>
        ///     Установка энергонезависимых данных 9
        /// </summary>
        SetNv = 9,

        /// <summary>
        ///     Запрос конфигурации табло 10
        /// </summary>
        GetConfig = 10,

        /// <summary>
        ///     Ответ на запрос конфигурации табло 11
        /// </summary>
        AnsConfig = 11,

        /// <summary>
        ///     Установка конфигурации табло 12
        /// </summary>
        SetConfig = 12,

        /// <summary>
        ///     Запрос текущего времени 13
        /// </summary>
        GetDatetime = 13,

        /// <summary>
        ///     Ответ на запрос текущего времени 14
        /// </summary>
        AnsDatetime = 14,

        /// <summary>
        ///     Установка текущего времени 15
        /// </summary>
        SetDatetime = 15,

        /// <summary>
        ///     Установка данных [не используется] 16
        /// </summary>
        [Obsolete] SetData = 16,

        /// <summary>
        ///     Ответ установки данных [не используется]
        /// </summary>
        [Obsolete] AnsData = 17,

        /// <summary>
        ///     Установка режима отладки 18
        /// </summary>
        UdpDebug = 18,

        /// <summary>
        ///     Запрос переменных NVSTR 20
        /// </summary>
        GetNvstr = 20,

        /// <summary>
        ///     Ответ на запрос переменных NVSTR 21
        /// </summary>
        AnsNvstr = 21,

        /// <summary>
        ///     Установка переменных NVSTR 22
        /// </summary>
        SetNvstr = 22,

        /// <summary>
        ///     Запрос переменных RSTR 23
        /// </summary>
        GetRstr = 23,

        /// <summary>
        ///     Ответ на запрос переменных RSTR 24
        /// </summary>
        AnsRstr = 24,

        /// <summary>
        ///     Установка переменных RSTR 25(0x19)
        /// </summary>
        SetRstr = 25,

        /// <summary>
        ///     Запрос переменных CSTR 26
        /// </summary>
        GetCstr = 26,

        /// <summary>
        ///     Ответ на запрос переменных CSTR 27
        /// </summary>
        AnsCstr = 27,

        /// <summary>
        ///     Запрос переменных NVNUM 28
        /// </summary>
        GetNvnum = 28,

        /// <summary>
        ///     Ответ на запрос переменных NVNUM 29
        /// </summary>
        AnsNvnum = 29,

        /// <summary>
        ///     Установка переменных NVNUM 30
        /// </summary>
        SetNvnum = 30,

        /// <summary>
        ///     Запрос переменных RNUM 31
        /// </summary>
        GetRnum = 31,

        /// <summary>
        ///     Ответ на запрос переменных RNUM 32
        /// </summary>
        AnsRnum = 32,

        /// <summary>
        ///     Установка переменных RNUM 33
        /// </summary>
        SetRnum = 33,

        /// <summary>
        ///     Запрос переменных CNUM 34
        /// </summary>
        GetCnum = 34,

        /// <summary>
        ///     Ответ на запрос переменных CNUM 35
        /// </summary>
        AnsCnum = 35,

        /// <summary>
        ///     Запрос переменных TIMER 36
        /// </summary>
        GetTimer = 36,

        /// <summary>
        ///     Ответ на запрос переменных TIMER 37
        /// </summary>
        AnsTimer = 37,

        /// <summary>
        ///     Установка переменных TIMER 38
        /// </summary>
        SetTimer = 38,

        /// <summary>
        ///     Запрос значений eeconst 39
        /// </summary>
        GetEeconst = 39,

        /// <summary>
        ///     Ответ на запрос значений eeconst 40
        /// </summary>
        AnsEeconst = 40,

        /// <summary>
        ///     Установка значений eeconst 41
        /// </summary>
        SetEeconst = 41,

        /// <summary>
        ///     Запрос значений fsmc 42
        /// </summary>
        GetFsmc = 42,

        /// <summary>
        ///     Ответ на запрос значений fsmc 43
        /// </summary>
        AnsFsmc = 43,

        /// <summary>
        ///     Установка значений fsmc 44
        /// </summary>
        SetFsmc = 44,

        /// <summary>
        ///     Запрос значений image 45
        /// </summary>
        GetImage = 45,

        /// <summary>
        ///     Ответ на запрос значений image 46
        /// </summary>
        AnsImage = 46,

        /// <summary>
        ///     Установка значений image 47
        /// </summary>
        SetImage = 47,

        /// <summary>
        ///     Запрос текущего режима 50
        /// </summary>
        GetMode = 50,

        /// <summary>
        ///     Ответ на запрос текущего режима 51
        /// </summary>
        AnsMode = 51,

        /// <summary>
        ///     Установка текущего режима 52
        /// </summary>
        SetMode = 52,

        /// <summary>
        ///     Команда обновления 100
        /// </summary>
        ProgCmd = 100,

        /// <summary>
        ///     Ответ на команду обновления 101
        /// </summary>
        ProgAns = 101,

        /// <summary>
        ///     Данные для обновления 102
        /// </summary>
        ProgData = 102
    }
}
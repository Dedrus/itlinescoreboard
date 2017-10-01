using System;

namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data
{
    public enum StringProfile : byte
    {
        /// <summary>
        ///     Профиль не определен (0) [из конфигурации]
        /// </summary>
        StrNone = 0,

        /// <summary>
        ///     Выравнивание по левому краю (1)
        /// </summary>
        StrLeft,

        /// <summary>
        ///     Выравнивание по центру (2)
        /// </summary>
        StrCenter,

        /// <summary>
        ///     Выравнивание по правому краю (3)
        /// </summary>
        StrRight,

        /// <summary>
        ///     Выравнивание по левому краю с горизонтальным скроллингом (4)
        /// </summary>
        StrLscroll,

        /// <summary>
        ///     Выравнивание по центру с горизонтальным скроллингом (5)
        /// </summary>
        StrCscroll,

        /// <summary>
        ///     Выравнивание по правому краю с горизонтальным скроллингом (6)
        /// </summary>
        StrRscroll,

        /// <summary>
        ///     Бегущая строка с низкой скоростью (7)
        /// </summary>
        StrLow,

        /// Бегущая строка со средней скоростью (8)
        StrMedium,

        /// <summary>
        ///     Бегущая строка с высокой скоростью (9)
        /// </summary>
        StrHigh,

        /// <summary>
        ///     Бегущая строка с заданной скоростью (10) [не используется]
        /// </summary>
        [Obsolete] StrSpeed
    }
}
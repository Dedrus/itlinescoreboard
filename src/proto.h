/**************************************************************************//**
 * \file		proto.h
 * \brief		Заголовочный файл для протокола обмена по Ethernet.
 * \author	Шанин А.М.
 * \author	email: adnega@mail.ru
 * \author	(C) Ярославль, 2015
 * \version	v0.1
 * \date		06.07.2015
 *****************************************************************************/
#ifndef __PROTO_H__
#define __PROTO_H__

/******************************************************************************
 * INCLUDE
 *****************************************************************************/
#include "type.h"
#include "config.h"

/******************************************************************************
 * DEFINE
 *****************************************************************************/
#define	ETH_TABLO_CONTROL_PORT		(5001)
#define	ETH_TABLO_DEBUG_PORT			(5010)

#define	ETH_TABLO_VERSION					((SW_TYPE << 8) | SW_MODEL)
#define	ETH_TABLO_DATE						(SW_DATE_DW / (24 * 60 * 60))

#define	ETH_TABLO_TYPE						(SW_TYPE)	//!< Тип табло (6)
#define	ETH_TABLO_TYPE_BR					(0xFF)		//!< Широковещательный тип табло (0xFF)

#define ETH_PROG_DATA_SIZE				(1024)		//!< Размер порции данных программирования (1024)


#define NVSTR_PROTO_NUM						(1)				//!< Число элементов NVSTR в пакете (1)
#define RSTR_PROTO_NUM						(8)				//!< Число элементов RSTR в пакете (8)
#define CSTR_PROTO_NUM						(8)				//!< Число элементов CSTR в пакете (8)

#define NVNUM_PROTO_NUM						(128)			//!< Число элементов NVNUM в пакете (128)
#define RNUM_PROTO_NUM						(128)			//!< Число элементов RNUM в пакете (128)
#define CNUM_PROTO_NUM						(128)			//!< Число элементов CNUM в пакете (128)

#define TIMER_PROTO_NUM						(64)			//!< Число элементов TIMER в пакете (64)

#define STR_SIZE									(1024)
//-----------------------------------------------------------------------------
//	ETH_CMD
//-----------------------------------------------------------------------------
#define ETH_CMD_NONE							(0)				//!< Нет команды [не используется]

#define ETH_CMD_SEARCH						(1)				//!< Команда поиска (1)
#define ETH_ANS_INFO							(2)				//!< Ответ на команду запроса информации о табло (2)
#define ETH_GET_INFO							(3)				//!< Запрос информации о табло (3)

#define ETH_GET_NET								(4)				//!< Запрос сетевых настроек (4)
#define ETH_ANS_NET								(5)				//!< Ответ на запрос сетевых настроек (5)
#define ETH_SET_NET								(6)				//!< Установка сетевых настроек (6)

#define ETH_GET_NV								(7)				//!< Запрос энергонезависимых данных (7)
#define ETH_ANS_NV								(8)				//!< Ответ на запрос энергонезависимых данных (8)
#define ETH_SET_NV								(9)				//!< Установка энергонезависимых данных (9)

#define ETH_GET_CONFIG						(10)			//!< Запрос конфигурации табло (10)
#define ETH_ANS_CONFIG						(11)			//!< Ответ на запрос конфигурации табло (11)
#define ETH_SET_CONFIG						(12)			//!< Установка конфигурации табло (12)

#ifdef PRESENT_RTC
#define ETH_GET_DATETIME					(13)			//!< Запрос текущего времени (13)
#define ETH_ANS_DATETIME					(14)			//!< Ответ на запрос текущего времени (14)
#define ETH_SET_DATETIME					(15)			//!< Установка текущего времени (15)
#endif // PRESENT_RTC

#define ETH_SET_DATA							(16)			//!< Установка данных [не используется]
#define ETH_ANS_DATA							(17)			//!< Ответ установки данных [не используется]

#define ETH_UDP_DEBUG							(18)			//!< Установка режима отладки (18)

#define ETH_GET_NVSTR							(20)			//!< Запрос переменных NVSTR (20)
#define ETH_ANS_NVSTR							(21)			//!< Ответ на запрос переменных NVSTR (21)
#define ETH_SET_NVSTR							(22)			//!< Установка переменных NVSTR (22)

#define ETH_GET_RSTR							(23)			//!< Запрос переменных RSTR (23)
#define ETH_ANS_RSTR							(24)			//!< Ответ на запрос переменных RSTR (24)
#define ETH_SET_RSTR							(25)			//!< Установка переменных RSTR (25)

#define ETH_GET_CSTR							(26)			//!< Запрос переменных CSTR (26)
#define ETH_ANS_CSTR							(27)			//!< Ответ на запрос переменных CSTR (27)

#define ETH_GET_NVNUM							(28)			//!< Запрос переменных NVNUM (28)
#define ETH_ANS_NVNUM							(29)			//!< Ответ на запрос переменных NVNUM (29)
#define ETH_SET_NVNUM							(30)			//!< Установка переменных NVNUM (30)

#define ETH_GET_RNUM							(31)			//!< Запрос переменных RNUM (31)
#define ETH_ANS_RNUM							(32)			//!< Ответ на запрос переменных RNUM (32)
#define ETH_SET_RNUM							(33)			//!< Установка переменных RNUM (33)

#define ETH_GET_CNUM							(34)			//!< Запрос переменных CNUM (34)
#define ETH_ANS_CNUM							(35)			//!< Ответ на запрос переменных CNUM (35)

#define ETH_GET_TIMER							(36)			//!< Запрос переменных TIMER (36)
#define ETH_ANS_TIMER							(37)			//!< Ответ на запрос переменных TIMER (37)
#define ETH_SET_TIMER							(38)			//!< Установка переменных TIMER (38)

#define ETH_GET_EECONST						(39)			//!< Запрос значений eeconst (39)
#define ETH_ANS_EECONST						(40)			//!< Ответ на запрос значений eeconst (40)
#define ETH_SET_EECONST						(41)			//!< Установка значений eeconst (41)

#define ETH_GET_FSMC							(42)			//!< Запрос значений fsmc (42)
#define ETH_ANS_FSMC							(43)			//!< Ответ на запрос значений fsmc (43)
#define ETH_SET_FSMC							(44)			//!< Установка значений fsmc (44)

#define ETH_GET_IMAGE							(45)			//!< Запрос значений image (45)
#define ETH_ANS_IMAGE							(46)			//!< Ответ на запрос значений image (46)
#define ETH_SET_IMAGE							(47)			//!< Установка значений image (47)

#define ETH_GET_MODE							(50)			//!< Запрос текущего режима (50)
#define ETH_ANS_MODE							(51)			//!< Ответ на запрос текущего режима (51)
#define ETH_SET_MODE							(52)			//!< Установка текущего режима (52)

#define ETH_PROG_CMD							(100)			//!< Команда обновления (100)
#define ETH_PROG_ANS							(101)			//!< Ответ на команду обновления (101)
#define ETH_PROG_DATA							(102)			//!< Данные для обновления (102)

//-----------------------------------------------------------------------------
//!	\enum ePROG_CMD
//! \brief Команды для обновления
//! \sa sPACKET_PROG_CMD
//-----------------------------------------------------------------------------
enum ePROG_CMD
{
	PROG_CMD_NONE = 0,						//!< Нет команды (0)
	PROG_CMD_ENTER,								//!< Начать обновление (1)
	PROG_CMD_ABORT,								//!< Прервать обновление (2)
	PROG_CMD_STATE,								//!< Получить состояние (3)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_STATE
//! \brief Состояние обновления
//! \sa sPACKET_PROG_ANS
//-----------------------------------------------------------------------------
enum ePROG_STATE
{
	PROG_STATE_IDLE = 0,					//!< Обновление не запущено (0)
	PROG_STATE_ENTER,							//!< Обновление подготавливается (1)
	PROG_STATE_READY,							//!< Готовность (2)
	PROG_STATE_WRITE,							//!< Запись порции данных (3)
	PROG_STATE_DONE,							//!< Получены все данные (4)
	PROG_STATE_RESULT,						//!< Состояние (5)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_TARGET
//! \brief Объект обновления
//! \sa sPACKET_PROG_CMD, sPACKET_PROG_ANS, sPACKET_PROG_DATA
//-----------------------------------------------------------------------------
enum ePROG_TARGET
{
	PROG_TARGET_IMAGE = 0,				//!< Обновление прошивки (0)
	PROG_TARGET_FONT,							//!< Обновление сборки шрифтов (1)
	PROG_TARGET_CONFIG,						//!< Обновление конфигурации (2)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_RESULT
//! \brief Результат обновления
//! \sa sPACKET_PROG_ANS
//-----------------------------------------------------------------------------
enum ePROG_RESULT
{
	PROG_RESULT_OK = 0,						//!< Успешно (0)
	PROG_RESULT_FAIL_CRC32,				//!< Ошибка CRC32 (1)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_ANS
//! \brief Ответ на команду обновления
//! \sa sPACKET_PROG_ANS, sPACKET_PROG_DATA
//-----------------------------------------------------------------------------
enum ePROG_ANS
{
	PROG_ANS_FAIL = 0,						//!< Ошибка (0)
	PROG_ANS_OK,									//!< Успешно (1)
};

//-----------------------------------------------------------------------------
//!	\enum eP_TIMER_FIELD
//! \brief Битовая маска активных полей:
//! \brief - 0 - игнорировать поле
//! \brief - 1 - поле актуально
//! \sa sP_TIMER
//-----------------------------------------------------------------------------
enum eP_TIMER_FIELD
{
	P_TIMER_FIELD_STATE = 0,			//!< Поле 'state' активно (0)
	P_TIMER_FIELD_CURRENT,				//!< Поле 'current' активно (1)
	P_TIMER_FIELD_FROM,						//!< Поле 'from' активно (2)
	P_TIMER_FIELD_TO,							//!< Поле 'to' активно (3)
	P_TIMER_FIELD_FLAGS,					//!< Поле 'flags' активно (4)
};

//-----------------------------------------------------------------------------
//!	\struct sP_TIMER
//! \brief Структура данных для TIMER
//! \sa sPACKET_ANS_TIMER, sPACKET_SET_TIMER
//-----------------------------------------------------------------------------
typedef struct sP_TIMER
{
	DWORD	current;								//!< Текущее значение таймера \ref sTIMER::current
	DWORD	from;										//!< Начальное значение таймера \ref sTIMER::from
	DWORD	to;											//!< Конечное значение таймера \ref sTIMER::to
	WORD	flags;									//!< Флаги таймера \ref sTIMER::flags
	BYTE	state;									//!< Состояние таймера \ref sTIMER::cur_state, \ref sTIMER::new_state
	BYTE	fields;									//!< Битовая маска активных полей #eP_TIMER_FIELD
} sP_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sCOMMAND
//! \brief Общий вид UDP-пакетов \ref PAGE_COMMAND.
//-----------------------------------------------------------------------------
typedef	struct sCOMMAND
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда/ответ
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE, #ETH_TABLO_TYPE_BR
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК, возвращается табло)

	BYTE				data;							//!< данные пакета
} sCOMMAND;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_CMD_SEARCH
//! \brief Команда поиска.
//!	Ответ на команду поиска передается в пакете sPACKET_ANS_INFO.
//-----------------------------------------------------------------------------
typedef	struct sPACKET_CMD_SEARCH
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера (FF:FF:FF:FF:FF:FF)
	BYTE				cmd;							//!< команда #ETH_CMD_SEARCH
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE, #ETH_TABLO_TYPE_BR
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК, возвращается табло)
} sPACKET_CMD_SEARCH;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_INFO
//! \brief Ответ на команду запроса информации о табло.
//-----------------------------------------------------------------------------
typedef	struct sPACKET_ANS_INFO
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_INFO
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	char				name[NAME_SIZE];	//!< имя контроллера
	sIP_ADR			ip;								//!< IP-адрес контроллера
	sIP_ADR			mask;							//!< маска подсети
	sIP_ADR			gw;								//!< шлюз по-умолчанию
	WORD				version;					//!< версия
	WORD				date;							//!< дата
} sPACKET_ANS_INFO;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_INFO
//! \brief Запрос информации о табло.
//!	Ответ на команду запроса информации о табло передается в пакете sPACKET_ANS_INFO.
//-----------------------------------------------------------------------------
typedef	struct sPACKET_GET_INFO
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_INFO
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_INFO;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NET
//! \brief Запрос сетевых настроек.
//!	Ответ на команду запроса сетевых настроек передается в пакете sPACKET_ANS_NET.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NET
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_NET
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_NET;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NET
//! \brief Ответ на запрос сетевых настроек.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NET
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_NET
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	char				name[NAME_SIZE];	//!< имя контроллера [#NAME_SIZE]
	sIP_ADR			ip;								//!< IP-адрес контроллера
	sIP_ADR			mask;							//!< маска подсети
	sIP_ADR			gw;								//!< шлюз по-умолчанию
} sPACKET_ANS_NET;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NET
//! \brief Установка сетевых настроек.
//!	Ответ на команду установки сетевых настроек передается в пакете sPACKET_ANS_NET.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NET
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_NET
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	char				name[NAME_SIZE];	//!< имя контроллера [#NAME_SIZE]
	sIP_ADR			ip;								//!< IP-адрес контроллера
	sIP_ADR			mask;							//!< маска подсети
	sIP_ADR			gw;								//!< шлюз по-умолчанию
} sPACKET_SET_NET;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NV
//! \brief Запрос энергонезависимых данных.
//!	Ответ на команду запроса энергонезависимых данных передается в пакете sPACKET_ANS_NV.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NV
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_NV
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_NV;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NV
//! \brief Ответ на запрос энергонезависимых данных.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NV
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_NV
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	int					bright;						//!< яркость \ref PAGE_BRIGHT
} sPACKET_ANS_NV;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NV
//! \brief Установка энергонезависимых данных.
//!	Ответ на команду установки энергонезависимых данных передается в пакете sPACKET_ANS_NV.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NV
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_NV
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	int					bright;						//!< яркость \ref PAGE_BRIGHT
} sPACKET_SET_NV;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_CONFIG
//! \brief Запрос конфигурации табло.
//!	Ответ на команду запроса конфигурации табло передается в пакете sPACKET_ANS_CONFIG.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_CONFIG
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_CONFIG
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_CONFIG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_CONFIG
//! \brief Ответ на запрос конфигурации табло.
//! Подробнее о параметрах \ref PAGE_CONFIG
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_CONFIG
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_CONFIG
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	int					safe;							//!< температурный монитор (0 - выключен)
	short				t_min;						//!< нижняя граница контроля в градусах Цельсия, 1/16 градуса
	short				t_max;						//!< верхняя граница контроля в градусах Цельсия, 1/16 градуса
	int					to_watchdog;			//!< сторожевой таймер в секундах (не менее 600 секунд)
	DWORD				autobright;				//!< автоматическое управление яркостью \ref eAUTOBRIGHT
	//DWORD				reserv;
} sPACKET_ANS_CONFIG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_CONFIG
//! \brief Установка конфигурации табло.
//!	Ответ на команду установки конфигурации табло передается в пакете sPACKET_ANS_CONFIG.
//! Подробнее о параметрах \ref PAGE_CONFIG
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_CONFIG
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_CONFIG
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	int					safe;							//!< температурный монитор (0 - выключен)
	short				t_min;						//!< нижняя граница контроля в градусах Цельсия, 1/16 градуса
	short				t_max;						//!< верхняя граница контроля в градусах Цельсия, 1/16 градуса
	int					to_watchdog;			//!< сторожевой таймер в секундах (не менее 600 секунд)
	DWORD				autobright;				//!< автоматическое управление яркостью \ref eAUTOBRIGHT
	//DWORD				reserv;
} sPACKET_SET_CONFIG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_DATETIME
//! \brief Запрос текущего времени.
//!	Ответ на запрос текущего времени передается в пакете sPACKET_ANS_DATETIME.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_DATETIME
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_DATETIME
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_DATETIME;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_DATETIME
//! \brief Ответ на запрос текущего времени.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_DATETIME
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_DATETIME
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	DWORD				datetime;					//!< текущие дата и время \ref PAGE_DATETIME
} sPACKET_ANS_DATETIME;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_DATETIME
//! \brief Установка текущего времени.
//!	Ответ на команду установки текущего времени передается в пакете sPACKET_ANS_DATETIME.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_DATETIME
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_DATETIME
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	DWORD				datetime;					//!< текущие дата и время \ref PAGE_DATETIME
} sPACKET_SET_DATETIME;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_DATA
//! \brief Установка данных [не используется].
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_DATA
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_DATA
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	DWORD				number;						//!< [не используется]
	DWORD				param;						//!< [не используется]
	BYTE				str[STR_SIZE];		//!< [не используется]
} sPACKET_SET_DATA;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_DATA
//! \brief Ответ установки данных [не используется].
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_DATA
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_DATA
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	DWORD				status;						//!< [не используется]
} sPACKET_ANS_DATA;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_UDP_DEBUG
//! \brief Установка режима отладки.
//-----------------------------------------------------------------------------
typedef struct sPACKET_UDP_DEBUG
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_UDP_DEBUG
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	DWORD				flags;						//!< флаги отладки \ref PAGE_DEBUG
} sPACKET_UDP_DEBUG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NVSTR
//! \brief Запрос переменных NVSTR.
//!	Ответ на команду запроса переменных NVSTR передается в пакете sPACKET_ANS_NVSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NVSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_NVSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы строк в пакете [#NVSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[NVSTR_PROTO_NUM];
} sPACKET_GET_NVSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NVSTR
//! \brief Ответ на запрос переменных NVSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NVSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_NVSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы строк в пакете [#NVSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[NVSTR_PROTO_NUM];
																//!  профили строк в пакете #eRPF_STR [#NVSTR_PROTO_NUM]
	BYTE				profile[NVSTR_PROTO_NUM];
																//!  данные строк в пакете [#NVSTR_PROTO_NUM][#NVSTR_LEN]
	BYTE				nvstr[NVSTR_PROTO_NUM][NVSTR_LEN];
} sPACKET_ANS_NVSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NVSTR
//! \brief Установка переменных NVSTR.
//!	Ответ на команду установки переменных NVSTR передается в пакете sPACKET_ANS_NVSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NVSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_NVSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы строк в пакете [#NVSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[NVSTR_PROTO_NUM];
																//!  профили строк в пакете #eRPF_STR [#NVSTR_PROTO_NUM]
	BYTE				profile[NVSTR_PROTO_NUM];
																//!  данные строк в пакете [#NVSTR_PROTO_NUM][#NVSTR_LEN]
	BYTE				nvstr[NVSTR_PROTO_NUM][NVSTR_LEN];
} sPACKET_SET_NVSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_RSTR
//! \brief Запрос переменных RSTR.
//!	Ответ на команду запроса переменных RSTR передается в пакете sPACKET_ANS_RSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_RSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_RSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы строк в пакете [#RSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[RSTR_PROTO_NUM];
} sPACKET_GET_RSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_RSTR
//! \brief Ответ на запрос переменных RSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_RSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_RSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы строк в пакете [#RSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[RSTR_PROTO_NUM];
																//!  профили строк в пакете #eRPF_STR [#RSTR_PROTO_NUM]
	BYTE				profile[RSTR_PROTO_NUM];
																//!  данные строк в пакете [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				rstr[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_ANS_RSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_RSTR
//! \brief Установка переменных RSTR.
//!	Ответ на команду установки переменных RSTR передается в пакете sPACKET_ANS_RSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_RSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_RSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы строк в пакете [#RSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[RSTR_PROTO_NUM];
																//!  профили строк в пакете #eRPF_STR [#RSTR_PROTO_NUM]
	BYTE				profile[RSTR_PROTO_NUM];
																//!  данные строк в пакете [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				rstr[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_SET_RSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_CSTR
//! \brief Запрос переменных CSTR.
//!	Ответ на команду запроса переменных CSTR передается в пакете sPACKET_ANS_CSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_CSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_CSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы строк в пакете [#CSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[CSTR_PROTO_NUM];
} sPACKET_GET_CSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_CSTR
//! \brief Ответ на запрос переменных CSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_CSTR
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_CSTR
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы строк в пакете [#CSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[CSTR_PROTO_NUM];
																//!  профили строк в пакете #eRPF_STR [#CSTR_PROTO_NUM]
	BYTE				profile[CSTR_PROTO_NUM];
																//!  данные строк в пакете [#CSTR_PROTO_NUM][#CSTR_LEN]
	BYTE				cstr[CSTR_PROTO_NUM][CSTR_LEN];
} sPACKET_ANS_CSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NVNUM
//! \brief Запрос переменных NVNUM.
//!	Ответ на команду запроса переменных NVNUM передается в пакете sPACKET_ANS_NVNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NVNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_NVNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы чисел в пакете [#NVNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[NVNUM_PROTO_NUM];
} sPACKET_GET_NVNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NVNUM
//! \brief Ответ на запрос переменных NVNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NVNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_NVNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы чисел в пакете [#NVNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[NVNUM_PROTO_NUM];
																//!  данные чисел в пакете [#NVNUM_PROTO_NUM]
	DWORD				nvnum[NVNUM_PROTO_NUM];
} sPACKET_ANS_NVNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NVNUM
//! \brief Установка переменных NVNUM.
//!	Ответ на команду установки переменных NVNUM передается в пакете sPACKET_ANS_NVNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NVNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_NVNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы чисел в пакете [#NVNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[NVNUM_PROTO_NUM];
																//!  данные чисел в пакете [#NVNUM_PROTO_NUM]
	DWORD				nvnum[NVNUM_PROTO_NUM];
} sPACKET_SET_NVNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_RNUM
//! \brief Запрос переменных RNUM.
//!	Ответ на команду запроса переменных RNUM передается в пакете sPACKET_ANS_RNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_RNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_RNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы чисел в пакете [#RNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[RNUM_PROTO_NUM];
} sPACKET_GET_RNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_RNUM
//! \brief Ответ на запрос переменных RNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_RNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_RNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы чисел в пакете [#RNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[RNUM_PROTO_NUM];
																//!  данные чисел в пакете [#RNUM_PROTO_NUM]
	DWORD				rnum[RNUM_PROTO_NUM];
} sPACKET_ANS_RNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_RNUM
//! \brief Установка переменных RNUM.
//!	Ответ на команду установки переменных RNUM передается в пакете sPACKET_ANS_RNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_RNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_RNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы чисел в пакете [#RNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[RNUM_PROTO_NUM];
																//!  данные чисел в пакете [#RNUM_PROTO_NUM]
	DWORD				rnum[RNUM_PROTO_NUM];
} sPACKET_SET_RNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_CNUM
//! \brief Запрос переменных CNUM.
//!	Ответ на команду запроса переменных CNUM передается в пакете sPACKET_ANS_CNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_CNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_CNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы чисел в пакете [#CNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[CNUM_PROTO_NUM];
} sPACKET_GET_CNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_CNUM
//! \brief Ответ на запрос переменных CNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_CNUM
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_CNUM
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы чисел в пакете [#CNUM_PROTO_NUM]. Если индекс равен \b 0xFFFF, то элемент игнорируется.
	WORD				index[CNUM_PROTO_NUM];
																//!  данные чисел в пакете [#CNUM_PROTO_NUM]
	DWORD				cnum[CNUM_PROTO_NUM];
} sPACKET_ANS_CNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_TIMER
//! \brief Запрос переменных TIMER.
//!	Ответ на команду запроса переменных TIMER передается в пакете sPACKET_ANS_TIMER.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_TIMER
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_TIMER
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы таймеров в пакете [#TIMER_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[TIMER_PROTO_NUM];
} sPACKET_GET_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_TIMER
//! \brief Ответ на запрос переменных TIMER.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_TIMER
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_TIMER
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы таймеров в пакете [#TIMER_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	WORD				index[TIMER_PROTO_NUM];
																//!  данные таймеров в пакете [#TIMER_PROTO_NUM]
	sP_TIMER		timer[TIMER_PROTO_NUM];
} sPACKET_ANS_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_TIMER
//! \brief Установка переменных TIMER.
//!	Ответ на команду установки переменных TIMER передается в пакете sPACKET_ANS_TIMER.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_TIMER
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_TIMER
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы таймеров в пакете [#TIMER_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	WORD				index[TIMER_PROTO_NUM];
																//!  данные таймеров в пакете [#TIMER_PROTO_NUM]
	sP_TIMER		timer[TIMER_PROTO_NUM];
} sPACKET_SET_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_MODE
//! \brief Запрос текущего режима.
//!	Ответ на команду запроса текущего режима передается в пакете sPACKET_ANS_MODE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_MODE
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_MODE
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_MODE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_MODE
//! \brief Ответ на запрос текущего режима.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_MODE
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_MODE
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	DWORD				new_mode;					//!< номер конфигурации для загрузки
	DWORD				cur_mode;					//!< номер конфигурации текущий
} sPACKET_ANS_MODE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_MODE
//! \brief Установка текущего режима.
//!	Ответ на команду установки текущего режима передается в пакете sPACKET_ANS_MODE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_MODE
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_MODE
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	DWORD				mode;							//!< номер конфигурации
} sPACKET_SET_MODE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_EECONST
//! \brief Запрос значений eeconst.
//!	Ответ на команду запроса значений eeconst передается в пакете sPACKET_ANS_EECONST.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_EECONST
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_EECONST
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_EECONST;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_EECONST
//! \brief Ответ на запрос значений eeconst.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_EECONST
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_EECONST
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	WORD				eeconst[EECONST_NUM];	//!< значения eeconst
} sPACKET_ANS_EECONST;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_EECONST
//! \brief Установка значений eeconst.
//!	Ответ на команду установки значений eeconst передается в пакете sPACKET_ANS_EECONST.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_EECONST
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_EECONST
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	WORD				eeconst[EECONST_NUM];	//!< значения eeconst
} sPACKET_SET_EECONST;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_FSMC
//! \brief Запрос значений fsmc.
//!	Ответ на команду запроса значений fsmc передается в пакете sPACKET_ANS_FSMC.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_FSMC
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_FSMC
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)
} sPACKET_GET_FSMC;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_FSMC
//! \brief Ответ на запрос значений fsmc.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_FSMC
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_FSMC
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

	sFSMC_TIMINGS	fsmc_timings[FSMC_TIMING_NUM];	//!< значения fsmc
} sPACKET_ANS_FSMC;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_FSMC
//! \brief Установка значений fsmc.
//!	Ответ на команду установки значений fsmc передается в пакете sPACKET_ANS_FSMC.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_FSMC
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_FSMC
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

	sFSMC_TIMINGS	fsmc_timings[FSMC_TIMING_NUM];	//!< значения fsmc
} sPACKET_SET_FSMC;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_IMAGE
//! \brief Запрос переменных IMAGE.
//!	Ответ на команду запроса переменных IMAGE передается в пакете sPACKET_ANS_IMAGE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_IMAGE
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_GET_IMAGE
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы строк в пакете [#RSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[RSTR_PROTO_NUM];
} sPACKET_GET_IMAGE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_IMAGE
//! \brief Ответ на запрос переменных IMAGE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_IMAGE
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< ответ #ETH_ANS_IMAGE
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (возвращается табло)

																//!  индексы строк в пакете [#RSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[RSTR_PROTO_NUM];
																//!  данные строк в пакете [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				image[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_ANS_IMAGE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_IMAGE
//! \brief Установка переменных IMAGE.
//!	Ответ на команду установки переменных IMAGE передается в пакете sPACKET_ANS_IMAGE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_IMAGE
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_SET_IMAGE
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE
	DWORD				p_id;							//!< идентификатор пакета (устанавливается ПК)

																//!  индексы строк в пакете [#RSTR_PROTO_NUM]. Если индекс равен \b 0xFF, то элемент игнорируется.
	BYTE				index[RSTR_PROTO_NUM];
																//!  данные строк в пакете [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				image[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_SET_IMAGE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_PROG_CMD
//! \brief Команда обновления.
//-----------------------------------------------------------------------------
typedef struct sPACKET_PROG_CMD
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_PROG_CMD
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE

	WORD				command;					//!< команда программирования #ePROG_CMD
	WORD				target;						//!< объект программирования #ePROG_TARGET
} sPACKET_PROG_CMD;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_PROG_ANS
//! \brief Ответ на команду обновления.
//-----------------------------------------------------------------------------
typedef struct sPACKET_PROG_ANS
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_PROG_ANS
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE

	WORD				ans;							//!< результат команды
	WORD				target;						//!< объект программирования
	DWORD				param;						//!< параметр программирования
} sPACKET_PROG_ANS;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_PROG_DATA
//! \brief Данные для обновления.
//-----------------------------------------------------------------------------
typedef struct sPACKET_PROG_DATA
{
	sMAC_ADR		mac;							//!< MAC-адрес контроллера
	BYTE				cmd;							//!< команда #ETH_PROG_DATA
	BYTE				type;							//!< тип устройства #ETH_TABLO_TYPE

	DWORD				addr;							//!< адрес программирования
	DWORD				target;						//!< объект программирования

																//!  данные программирования [#ETH_PROG_DATA_SIZE]
	BYTE				data[ETH_PROG_DATA_SIZE];
} sPACKET_PROG_DATA;

/******************************************************************************
 * FUNCTION
 *****************************************************************************/

/******************************************************************************
 * VARIABLE
 *****************************************************************************/

#endif // __PROTO_H__
/******************************************************************************
 * КОНЕЦ ФАЙЛА
 *****************************************************************************/

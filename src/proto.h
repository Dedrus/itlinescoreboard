/**************************************************************************//**
 * \file		proto.h
 * \brief		������������ ���� ��� ��������� ������ �� Ethernet.
 * \author	����� �.�.
 * \author	email: adnega@mail.ru
 * \author	(C) ���������, 2015
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

#define	ETH_TABLO_TYPE						(SW_TYPE)	//!< ��� ����� (6)
#define	ETH_TABLO_TYPE_BR					(0xFF)		//!< ����������������� ��� ����� (0xFF)

#define ETH_PROG_DATA_SIZE				(1024)		//!< ������ ������ ������ ���������������� (1024)


#define NVSTR_PROTO_NUM						(1)				//!< ����� ��������� NVSTR � ������ (1)
#define RSTR_PROTO_NUM						(8)				//!< ����� ��������� RSTR � ������ (8)
#define CSTR_PROTO_NUM						(8)				//!< ����� ��������� CSTR � ������ (8)

#define NVNUM_PROTO_NUM						(128)			//!< ����� ��������� NVNUM � ������ (128)
#define RNUM_PROTO_NUM						(128)			//!< ����� ��������� RNUM � ������ (128)
#define CNUM_PROTO_NUM						(128)			//!< ����� ��������� CNUM � ������ (128)

#define TIMER_PROTO_NUM						(64)			//!< ����� ��������� TIMER � ������ (64)

#define STR_SIZE									(1024)
//-----------------------------------------------------------------------------
//	ETH_CMD
//-----------------------------------------------------------------------------
#define ETH_CMD_NONE							(0)				//!< ��� ������� [�� ������������]

#define ETH_CMD_SEARCH						(1)				//!< ������� ������ (1)
#define ETH_ANS_INFO							(2)				//!< ����� �� ������� ������� ���������� � ����� (2)
#define ETH_GET_INFO							(3)				//!< ������ ���������� � ����� (3)

#define ETH_GET_NET								(4)				//!< ������ ������� �������� (4)
#define ETH_ANS_NET								(5)				//!< ����� �� ������ ������� �������� (5)
#define ETH_SET_NET								(6)				//!< ��������� ������� �������� (6)

#define ETH_GET_NV								(7)				//!< ������ ����������������� ������ (7)
#define ETH_ANS_NV								(8)				//!< ����� �� ������ ����������������� ������ (8)
#define ETH_SET_NV								(9)				//!< ��������� ����������������� ������ (9)

#define ETH_GET_CONFIG						(10)			//!< ������ ������������ ����� (10)
#define ETH_ANS_CONFIG						(11)			//!< ����� �� ������ ������������ ����� (11)
#define ETH_SET_CONFIG						(12)			//!< ��������� ������������ ����� (12)

#ifdef PRESENT_RTC
#define ETH_GET_DATETIME					(13)			//!< ������ �������� ������� (13)
#define ETH_ANS_DATETIME					(14)			//!< ����� �� ������ �������� ������� (14)
#define ETH_SET_DATETIME					(15)			//!< ��������� �������� ������� (15)
#endif // PRESENT_RTC

#define ETH_SET_DATA							(16)			//!< ��������� ������ [�� ������������]
#define ETH_ANS_DATA							(17)			//!< ����� ��������� ������ [�� ������������]

#define ETH_UDP_DEBUG							(18)			//!< ��������� ������ ������� (18)

#define ETH_GET_NVSTR							(20)			//!< ������ ���������� NVSTR (20)
#define ETH_ANS_NVSTR							(21)			//!< ����� �� ������ ���������� NVSTR (21)
#define ETH_SET_NVSTR							(22)			//!< ��������� ���������� NVSTR (22)

#define ETH_GET_RSTR							(23)			//!< ������ ���������� RSTR (23)
#define ETH_ANS_RSTR							(24)			//!< ����� �� ������ ���������� RSTR (24)
#define ETH_SET_RSTR							(25)			//!< ��������� ���������� RSTR (25)

#define ETH_GET_CSTR							(26)			//!< ������ ���������� CSTR (26)
#define ETH_ANS_CSTR							(27)			//!< ����� �� ������ ���������� CSTR (27)

#define ETH_GET_NVNUM							(28)			//!< ������ ���������� NVNUM (28)
#define ETH_ANS_NVNUM							(29)			//!< ����� �� ������ ���������� NVNUM (29)
#define ETH_SET_NVNUM							(30)			//!< ��������� ���������� NVNUM (30)

#define ETH_GET_RNUM							(31)			//!< ������ ���������� RNUM (31)
#define ETH_ANS_RNUM							(32)			//!< ����� �� ������ ���������� RNUM (32)
#define ETH_SET_RNUM							(33)			//!< ��������� ���������� RNUM (33)

#define ETH_GET_CNUM							(34)			//!< ������ ���������� CNUM (34)
#define ETH_ANS_CNUM							(35)			//!< ����� �� ������ ���������� CNUM (35)

#define ETH_GET_TIMER							(36)			//!< ������ ���������� TIMER (36)
#define ETH_ANS_TIMER							(37)			//!< ����� �� ������ ���������� TIMER (37)
#define ETH_SET_TIMER							(38)			//!< ��������� ���������� TIMER (38)

#define ETH_GET_EECONST						(39)			//!< ������ �������� eeconst (39)
#define ETH_ANS_EECONST						(40)			//!< ����� �� ������ �������� eeconst (40)
#define ETH_SET_EECONST						(41)			//!< ��������� �������� eeconst (41)

#define ETH_GET_FSMC							(42)			//!< ������ �������� fsmc (42)
#define ETH_ANS_FSMC							(43)			//!< ����� �� ������ �������� fsmc (43)
#define ETH_SET_FSMC							(44)			//!< ��������� �������� fsmc (44)

#define ETH_GET_IMAGE							(45)			//!< ������ �������� image (45)
#define ETH_ANS_IMAGE							(46)			//!< ����� �� ������ �������� image (46)
#define ETH_SET_IMAGE							(47)			//!< ��������� �������� image (47)

#define ETH_GET_MODE							(50)			//!< ������ �������� ������ (50)
#define ETH_ANS_MODE							(51)			//!< ����� �� ������ �������� ������ (51)
#define ETH_SET_MODE							(52)			//!< ��������� �������� ������ (52)

#define ETH_PROG_CMD							(100)			//!< ������� ���������� (100)
#define ETH_PROG_ANS							(101)			//!< ����� �� ������� ���������� (101)
#define ETH_PROG_DATA							(102)			//!< ������ ��� ���������� (102)

//-----------------------------------------------------------------------------
//!	\enum ePROG_CMD
//! \brief ������� ��� ����������
//! \sa sPACKET_PROG_CMD
//-----------------------------------------------------------------------------
enum ePROG_CMD
{
	PROG_CMD_NONE = 0,						//!< ��� ������� (0)
	PROG_CMD_ENTER,								//!< ������ ���������� (1)
	PROG_CMD_ABORT,								//!< �������� ���������� (2)
	PROG_CMD_STATE,								//!< �������� ��������� (3)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_STATE
//! \brief ��������� ����������
//! \sa sPACKET_PROG_ANS
//-----------------------------------------------------------------------------
enum ePROG_STATE
{
	PROG_STATE_IDLE = 0,					//!< ���������� �� �������� (0)
	PROG_STATE_ENTER,							//!< ���������� ���������������� (1)
	PROG_STATE_READY,							//!< ���������� (2)
	PROG_STATE_WRITE,							//!< ������ ������ ������ (3)
	PROG_STATE_DONE,							//!< �������� ��� ������ (4)
	PROG_STATE_RESULT,						//!< ��������� (5)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_TARGET
//! \brief ������ ����������
//! \sa sPACKET_PROG_CMD, sPACKET_PROG_ANS, sPACKET_PROG_DATA
//-----------------------------------------------------------------------------
enum ePROG_TARGET
{
	PROG_TARGET_IMAGE = 0,				//!< ���������� �������� (0)
	PROG_TARGET_FONT,							//!< ���������� ������ ������� (1)
	PROG_TARGET_CONFIG,						//!< ���������� ������������ (2)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_RESULT
//! \brief ��������� ����������
//! \sa sPACKET_PROG_ANS
//-----------------------------------------------------------------------------
enum ePROG_RESULT
{
	PROG_RESULT_OK = 0,						//!< ������� (0)
	PROG_RESULT_FAIL_CRC32,				//!< ������ CRC32 (1)
};

//-----------------------------------------------------------------------------
//!	\enum ePROG_ANS
//! \brief ����� �� ������� ����������
//! \sa sPACKET_PROG_ANS, sPACKET_PROG_DATA
//-----------------------------------------------------------------------------
enum ePROG_ANS
{
	PROG_ANS_FAIL = 0,						//!< ������ (0)
	PROG_ANS_OK,									//!< ������� (1)
};

//-----------------------------------------------------------------------------
//!	\enum eP_TIMER_FIELD
//! \brief ������� ����� �������� �����:
//! \brief - 0 - ������������ ����
//! \brief - 1 - ���� ���������
//! \sa sP_TIMER
//-----------------------------------------------------------------------------
enum eP_TIMER_FIELD
{
	P_TIMER_FIELD_STATE = 0,			//!< ���� 'state' ������� (0)
	P_TIMER_FIELD_CURRENT,				//!< ���� 'current' ������� (1)
	P_TIMER_FIELD_FROM,						//!< ���� 'from' ������� (2)
	P_TIMER_FIELD_TO,							//!< ���� 'to' ������� (3)
	P_TIMER_FIELD_FLAGS,					//!< ���� 'flags' ������� (4)
};

//-----------------------------------------------------------------------------
//!	\struct sP_TIMER
//! \brief ��������� ������ ��� TIMER
//! \sa sPACKET_ANS_TIMER, sPACKET_SET_TIMER
//-----------------------------------------------------------------------------
typedef struct sP_TIMER
{
	DWORD	current;								//!< ������� �������� ������� \ref sTIMER::current
	DWORD	from;										//!< ��������� �������� ������� \ref sTIMER::from
	DWORD	to;											//!< �������� �������� ������� \ref sTIMER::to
	WORD	flags;									//!< ����� ������� \ref sTIMER::flags
	BYTE	state;									//!< ��������� ������� \ref sTIMER::cur_state, \ref sTIMER::new_state
	BYTE	fields;									//!< ������� ����� �������� ����� #eP_TIMER_FIELD
} sP_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sCOMMAND
//! \brief ����� ��� UDP-������� \ref PAGE_COMMAND.
//-----------------------------------------------------------------------------
typedef	struct sCOMMAND
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< �������/�����
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE, #ETH_TABLO_TYPE_BR
	DWORD				p_id;							//!< ������������� ������ (��������������� ��, ������������ �����)

	BYTE				data;							//!< ������ ������
} sCOMMAND;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_CMD_SEARCH
//! \brief ������� ������.
//!	����� �� ������� ������ ���������� � ������ sPACKET_ANS_INFO.
//-----------------------------------------------------------------------------
typedef	struct sPACKET_CMD_SEARCH
{
	sMAC_ADR		mac;							//!< MAC-����� ����������� (FF:FF:FF:FF:FF:FF)
	BYTE				cmd;							//!< ������� #ETH_CMD_SEARCH
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE, #ETH_TABLO_TYPE_BR
	DWORD				p_id;							//!< ������������� ������ (��������������� ��, ������������ �����)
} sPACKET_CMD_SEARCH;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_INFO
//! \brief ����� �� ������� ������� ���������� � �����.
//-----------------------------------------------------------------------------
typedef	struct sPACKET_ANS_INFO
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_INFO
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	char				name[NAME_SIZE];	//!< ��� �����������
	sIP_ADR			ip;								//!< IP-����� �����������
	sIP_ADR			mask;							//!< ����� �������
	sIP_ADR			gw;								//!< ���� ��-���������
	WORD				version;					//!< ������
	WORD				date;							//!< ����
} sPACKET_ANS_INFO;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_INFO
//! \brief ������ ���������� � �����.
//!	����� �� ������� ������� ���������� � ����� ���������� � ������ sPACKET_ANS_INFO.
//-----------------------------------------------------------------------------
typedef	struct sPACKET_GET_INFO
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_INFO
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_INFO;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NET
//! \brief ������ ������� ��������.
//!	����� �� ������� ������� ������� �������� ���������� � ������ sPACKET_ANS_NET.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NET
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_NET
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_NET;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NET
//! \brief ����� �� ������ ������� ��������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NET
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_NET
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	char				name[NAME_SIZE];	//!< ��� ����������� [#NAME_SIZE]
	sIP_ADR			ip;								//!< IP-����� �����������
	sIP_ADR			mask;							//!< ����� �������
	sIP_ADR			gw;								//!< ���� ��-���������
} sPACKET_ANS_NET;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NET
//! \brief ��������� ������� ��������.
//!	����� �� ������� ��������� ������� �������� ���������� � ������ sPACKET_ANS_NET.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NET
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_NET
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	char				name[NAME_SIZE];	//!< ��� ����������� [#NAME_SIZE]
	sIP_ADR			ip;								//!< IP-����� �����������
	sIP_ADR			mask;							//!< ����� �������
	sIP_ADR			gw;								//!< ���� ��-���������
} sPACKET_SET_NET;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NV
//! \brief ������ ����������������� ������.
//!	����� �� ������� ������� ����������������� ������ ���������� � ������ sPACKET_ANS_NV.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NV
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_NV
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_NV;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NV
//! \brief ����� �� ������ ����������������� ������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NV
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_NV
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	int					bright;						//!< ������� \ref PAGE_BRIGHT
} sPACKET_ANS_NV;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NV
//! \brief ��������� ����������������� ������.
//!	����� �� ������� ��������� ����������������� ������ ���������� � ������ sPACKET_ANS_NV.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NV
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_NV
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	int					bright;						//!< ������� \ref PAGE_BRIGHT
} sPACKET_SET_NV;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_CONFIG
//! \brief ������ ������������ �����.
//!	����� �� ������� ������� ������������ ����� ���������� � ������ sPACKET_ANS_CONFIG.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_CONFIG
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_CONFIG
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_CONFIG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_CONFIG
//! \brief ����� �� ������ ������������ �����.
//! ��������� � ���������� \ref PAGE_CONFIG
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_CONFIG
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_CONFIG
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	int					safe;							//!< ������������� ������� (0 - ��������)
	short				t_min;						//!< ������ ������� �������� � �������� �������, 1/16 �������
	short				t_max;						//!< ������� ������� �������� � �������� �������, 1/16 �������
	int					to_watchdog;			//!< ���������� ������ � �������� (�� ����� 600 ������)
	DWORD				autobright;				//!< �������������� ���������� �������� \ref eAUTOBRIGHT
	//DWORD				reserv;
} sPACKET_ANS_CONFIG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_CONFIG
//! \brief ��������� ������������ �����.
//!	����� �� ������� ��������� ������������ ����� ���������� � ������ sPACKET_ANS_CONFIG.
//! ��������� � ���������� \ref PAGE_CONFIG
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_CONFIG
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_CONFIG
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	int					safe;							//!< ������������� ������� (0 - ��������)
	short				t_min;						//!< ������ ������� �������� � �������� �������, 1/16 �������
	short				t_max;						//!< ������� ������� �������� � �������� �������, 1/16 �������
	int					to_watchdog;			//!< ���������� ������ � �������� (�� ����� 600 ������)
	DWORD				autobright;				//!< �������������� ���������� �������� \ref eAUTOBRIGHT
	//DWORD				reserv;
} sPACKET_SET_CONFIG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_DATETIME
//! \brief ������ �������� �������.
//!	����� �� ������ �������� ������� ���������� � ������ sPACKET_ANS_DATETIME.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_DATETIME
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_DATETIME
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_DATETIME;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_DATETIME
//! \brief ����� �� ������ �������� �������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_DATETIME
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_DATETIME
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	DWORD				datetime;					//!< ������� ���� � ����� \ref PAGE_DATETIME
} sPACKET_ANS_DATETIME;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_DATETIME
//! \brief ��������� �������� �������.
//!	����� �� ������� ��������� �������� ������� ���������� � ������ sPACKET_ANS_DATETIME.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_DATETIME
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_DATETIME
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	DWORD				datetime;					//!< ������� ���� � ����� \ref PAGE_DATETIME
} sPACKET_SET_DATETIME;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_DATA
//! \brief ��������� ������ [�� ������������].
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_DATA
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_DATA
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	DWORD				number;						//!< [�� ������������]
	DWORD				param;						//!< [�� ������������]
	BYTE				str[STR_SIZE];		//!< [�� ������������]
} sPACKET_SET_DATA;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_DATA
//! \brief ����� ��������� ������ [�� ������������].
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_DATA
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_DATA
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	DWORD				status;						//!< [�� ������������]
} sPACKET_ANS_DATA;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_UDP_DEBUG
//! \brief ��������� ������ �������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_UDP_DEBUG
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_UDP_DEBUG
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	DWORD				flags;						//!< ����� ������� \ref PAGE_DEBUG
} sPACKET_UDP_DEBUG;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NVSTR
//! \brief ������ ���������� NVSTR.
//!	����� �� ������� ������� ���������� NVSTR ���������� � ������ sPACKET_ANS_NVSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NVSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_NVSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#NVSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[NVSTR_PROTO_NUM];
} sPACKET_GET_NVSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NVSTR
//! \brief ����� �� ������ ���������� NVSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NVSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_NVSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� ����� � ������ [#NVSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[NVSTR_PROTO_NUM];
																//!  ������� ����� � ������ #eRPF_STR [#NVSTR_PROTO_NUM]
	BYTE				profile[NVSTR_PROTO_NUM];
																//!  ������ ����� � ������ [#NVSTR_PROTO_NUM][#NVSTR_LEN]
	BYTE				nvstr[NVSTR_PROTO_NUM][NVSTR_LEN];
} sPACKET_ANS_NVSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NVSTR
//! \brief ��������� ���������� NVSTR.
//!	����� �� ������� ��������� ���������� NVSTR ���������� � ������ sPACKET_ANS_NVSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NVSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_NVSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#NVSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[NVSTR_PROTO_NUM];
																//!  ������� ����� � ������ #eRPF_STR [#NVSTR_PROTO_NUM]
	BYTE				profile[NVSTR_PROTO_NUM];
																//!  ������ ����� � ������ [#NVSTR_PROTO_NUM][#NVSTR_LEN]
	BYTE				nvstr[NVSTR_PROTO_NUM][NVSTR_LEN];
} sPACKET_SET_NVSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_RSTR
//! \brief ������ ���������� RSTR.
//!	����� �� ������� ������� ���������� RSTR ���������� � ������ sPACKET_ANS_RSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_RSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_RSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#RSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[RSTR_PROTO_NUM];
} sPACKET_GET_RSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_RSTR
//! \brief ����� �� ������ ���������� RSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_RSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_RSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� ����� � ������ [#RSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[RSTR_PROTO_NUM];
																//!  ������� ����� � ������ #eRPF_STR [#RSTR_PROTO_NUM]
	BYTE				profile[RSTR_PROTO_NUM];
																//!  ������ ����� � ������ [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				rstr[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_ANS_RSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_RSTR
//! \brief ��������� ���������� RSTR.
//!	����� �� ������� ��������� ���������� RSTR ���������� � ������ sPACKET_ANS_RSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_RSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_RSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#RSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[RSTR_PROTO_NUM];
																//!  ������� ����� � ������ #eRPF_STR [#RSTR_PROTO_NUM]
	BYTE				profile[RSTR_PROTO_NUM];
																//!  ������ ����� � ������ [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				rstr[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_SET_RSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_CSTR
//! \brief ������ ���������� CSTR.
//!	����� �� ������� ������� ���������� CSTR ���������� � ������ sPACKET_ANS_CSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_CSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_CSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#CSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[CSTR_PROTO_NUM];
} sPACKET_GET_CSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_CSTR
//! \brief ����� �� ������ ���������� CSTR.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_CSTR
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_CSTR
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� ����� � ������ [#CSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[CSTR_PROTO_NUM];
																//!  ������� ����� � ������ #eRPF_STR [#CSTR_PROTO_NUM]
	BYTE				profile[CSTR_PROTO_NUM];
																//!  ������ ����� � ������ [#CSTR_PROTO_NUM][#CSTR_LEN]
	BYTE				cstr[CSTR_PROTO_NUM][CSTR_LEN];
} sPACKET_ANS_CSTR;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_NVNUM
//! \brief ������ ���������� NVNUM.
//!	����� �� ������� ������� ���������� NVNUM ���������� � ������ sPACKET_ANS_NVNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_NVNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_NVNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#NVNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[NVNUM_PROTO_NUM];
} sPACKET_GET_NVNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_NVNUM
//! \brief ����� �� ������ ���������� NVNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_NVNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_NVNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� ����� � ������ [#NVNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[NVNUM_PROTO_NUM];
																//!  ������ ����� � ������ [#NVNUM_PROTO_NUM]
	DWORD				nvnum[NVNUM_PROTO_NUM];
} sPACKET_ANS_NVNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_NVNUM
//! \brief ��������� ���������� NVNUM.
//!	����� �� ������� ��������� ���������� NVNUM ���������� � ������ sPACKET_ANS_NVNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_NVNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_NVNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#NVNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[NVNUM_PROTO_NUM];
																//!  ������ ����� � ������ [#NVNUM_PROTO_NUM]
	DWORD				nvnum[NVNUM_PROTO_NUM];
} sPACKET_SET_NVNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_RNUM
//! \brief ������ ���������� RNUM.
//!	����� �� ������� ������� ���������� RNUM ���������� � ������ sPACKET_ANS_RNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_RNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_RNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#RNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[RNUM_PROTO_NUM];
} sPACKET_GET_RNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_RNUM
//! \brief ����� �� ������ ���������� RNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_RNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_RNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� ����� � ������ [#RNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[RNUM_PROTO_NUM];
																//!  ������ ����� � ������ [#RNUM_PROTO_NUM]
	DWORD				rnum[RNUM_PROTO_NUM];
} sPACKET_ANS_RNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_RNUM
//! \brief ��������� ���������� RNUM.
//!	����� �� ������� ��������� ���������� RNUM ���������� � ������ sPACKET_ANS_RNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_RNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_RNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#RNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[RNUM_PROTO_NUM];
																//!  ������ ����� � ������ [#RNUM_PROTO_NUM]
	DWORD				rnum[RNUM_PROTO_NUM];
} sPACKET_SET_RNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_CNUM
//! \brief ������ ���������� CNUM.
//!	����� �� ������� ������� ���������� CNUM ���������� � ������ sPACKET_ANS_CNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_CNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_CNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#CNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[CNUM_PROTO_NUM];
} sPACKET_GET_CNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_CNUM
//! \brief ����� �� ������ ���������� CNUM.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_CNUM
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_CNUM
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� ����� � ������ [#CNUM_PROTO_NUM]. ���� ������ ����� \b 0xFFFF, �� ������� ������������.
	WORD				index[CNUM_PROTO_NUM];
																//!  ������ ����� � ������ [#CNUM_PROTO_NUM]
	DWORD				cnum[CNUM_PROTO_NUM];
} sPACKET_ANS_CNUM;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_TIMER
//! \brief ������ ���������� TIMER.
//!	����� �� ������� ������� ���������� TIMER ���������� � ������ sPACKET_ANS_TIMER.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_TIMER
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_TIMER
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� �������� � ������ [#TIMER_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[TIMER_PROTO_NUM];
} sPACKET_GET_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_TIMER
//! \brief ����� �� ������ ���������� TIMER.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_TIMER
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_TIMER
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� �������� � ������ [#TIMER_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	WORD				index[TIMER_PROTO_NUM];
																//!  ������ �������� � ������ [#TIMER_PROTO_NUM]
	sP_TIMER		timer[TIMER_PROTO_NUM];
} sPACKET_ANS_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_TIMER
//! \brief ��������� ���������� TIMER.
//!	����� �� ������� ��������� ���������� TIMER ���������� � ������ sPACKET_ANS_TIMER.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_TIMER
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_TIMER
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� �������� � ������ [#TIMER_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	WORD				index[TIMER_PROTO_NUM];
																//!  ������ �������� � ������ [#TIMER_PROTO_NUM]
	sP_TIMER		timer[TIMER_PROTO_NUM];
} sPACKET_SET_TIMER;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_MODE
//! \brief ������ �������� ������.
//!	����� �� ������� ������� �������� ������ ���������� � ������ sPACKET_ANS_MODE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_MODE
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_MODE
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_MODE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_MODE
//! \brief ����� �� ������ �������� ������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_MODE
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_MODE
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	DWORD				new_mode;					//!< ����� ������������ ��� ��������
	DWORD				cur_mode;					//!< ����� ������������ �������
} sPACKET_ANS_MODE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_MODE
//! \brief ��������� �������� ������.
//!	����� �� ������� ��������� �������� ������ ���������� � ������ sPACKET_ANS_MODE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_MODE
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_MODE
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	DWORD				mode;							//!< ����� ������������
} sPACKET_SET_MODE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_EECONST
//! \brief ������ �������� eeconst.
//!	����� �� ������� ������� �������� eeconst ���������� � ������ sPACKET_ANS_EECONST.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_EECONST
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_EECONST
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_EECONST;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_EECONST
//! \brief ����� �� ������ �������� eeconst.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_EECONST
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_EECONST
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	WORD				eeconst[EECONST_NUM];	//!< �������� eeconst
} sPACKET_ANS_EECONST;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_EECONST
//! \brief ��������� �������� eeconst.
//!	����� �� ������� ��������� �������� eeconst ���������� � ������ sPACKET_ANS_EECONST.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_EECONST
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_EECONST
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	WORD				eeconst[EECONST_NUM];	//!< �������� eeconst
} sPACKET_SET_EECONST;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_FSMC
//! \brief ������ �������� fsmc.
//!	����� �� ������� ������� �������� fsmc ���������� � ������ sPACKET_ANS_FSMC.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_FSMC
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_FSMC
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)
} sPACKET_GET_FSMC;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_FSMC
//! \brief ����� �� ������ �������� fsmc.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_FSMC
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_FSMC
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

	sFSMC_TIMINGS	fsmc_timings[FSMC_TIMING_NUM];	//!< �������� fsmc
} sPACKET_ANS_FSMC;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_FSMC
//! \brief ��������� �������� fsmc.
//!	����� �� ������� ��������� �������� fsmc ���������� � ������ sPACKET_ANS_FSMC.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_FSMC
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_FSMC
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

	sFSMC_TIMINGS	fsmc_timings[FSMC_TIMING_NUM];	//!< �������� fsmc
} sPACKET_SET_FSMC;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_GET_IMAGE
//! \brief ������ ���������� IMAGE.
//!	����� �� ������� ������� ���������� IMAGE ���������� � ������ sPACKET_ANS_IMAGE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_GET_IMAGE
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_GET_IMAGE
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#RSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[RSTR_PROTO_NUM];
} sPACKET_GET_IMAGE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_ANS_IMAGE
//! \brief ����� �� ������ ���������� IMAGE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_ANS_IMAGE
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ����� #ETH_ANS_IMAGE
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (������������ �����)

																//!  ������� ����� � ������ [#RSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[RSTR_PROTO_NUM];
																//!  ������ ����� � ������ [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				image[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_ANS_IMAGE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_SET_IMAGE
//! \brief ��������� ���������� IMAGE.
//!	����� �� ������� ��������� ���������� IMAGE ���������� � ������ sPACKET_ANS_IMAGE.
//-----------------------------------------------------------------------------
typedef struct sPACKET_SET_IMAGE
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_SET_IMAGE
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE
	DWORD				p_id;							//!< ������������� ������ (��������������� ��)

																//!  ������� ����� � ������ [#RSTR_PROTO_NUM]. ���� ������ ����� \b 0xFF, �� ������� ������������.
	BYTE				index[RSTR_PROTO_NUM];
																//!  ������ ����� � ������ [#RSTR_PROTO_NUM][#RSTR_LEN]
	BYTE				image[RSTR_PROTO_NUM][RSTR_LEN];
} sPACKET_SET_IMAGE;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_PROG_CMD
//! \brief ������� ����������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_PROG_CMD
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_PROG_CMD
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE

	WORD				command;					//!< ������� ���������������� #ePROG_CMD
	WORD				target;						//!< ������ ���������������� #ePROG_TARGET
} sPACKET_PROG_CMD;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_PROG_ANS
//! \brief ����� �� ������� ����������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_PROG_ANS
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_PROG_ANS
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE

	WORD				ans;							//!< ��������� �������
	WORD				target;						//!< ������ ����������������
	DWORD				param;						//!< �������� ����������������
} sPACKET_PROG_ANS;

//-----------------------------------------------------------------------------
//!	\struct sPACKET_PROG_DATA
//! \brief ������ ��� ����������.
//-----------------------------------------------------------------------------
typedef struct sPACKET_PROG_DATA
{
	sMAC_ADR		mac;							//!< MAC-����� �����������
	BYTE				cmd;							//!< ������� #ETH_PROG_DATA
	BYTE				type;							//!< ��� ���������� #ETH_TABLO_TYPE

	DWORD				addr;							//!< ����� ����������������
	DWORD				target;						//!< ������ ����������������

																//!  ������ ���������������� [#ETH_PROG_DATA_SIZE]
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
 * ����� �����
 *****************************************************************************/

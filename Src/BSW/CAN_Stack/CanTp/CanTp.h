/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : CanTp                                                   */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CAN transport layer interface                           */
/*                                                                            */
/* !Module          : CanTp                                                   */
/* !Description     : CAN transport layer interface                           */
/*                                                                            */
/* !File            : CanTp.h                                                 */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : uPD70F3375                                              */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/CO$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanTp/CanTp.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:12   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:06   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/

#ifndef CANTP_H
#define CANTP_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Can_Type.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CANTP_u16BUFLEN_MAX             ((uint16)1024)
#define CANTP_u8FRAMETIME_MAX           ((uint8)10)
#define CANTP_u16TIMEOUT_FIRSTCF        ((uint16)50) /*1010*/
#define CANTP_u8FLOWSTATUS              ((uint8)0)
#define CANTP_u8BLOCKSIZE               ((uint8)8)
#define CANTP_u8STMIN                   ((uint8)20)
#define CANTP_u16TIMEOUT_RECVFC         ((uint16)50) /*1010*/




#define CANTP_u8ERR_NOERR               0u
#define CANTP_u8ERR_ERR                 1u
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

typedef enum
{
	CANTP_MRST_SENDFC = 0u,
	CANTP_MRST_CFTOCHK,
} CanTp_tenuMfRecvStepType;

typedef enum
{
	CANTP_MSST_RECVFC = 0u,
	CANTP_MSST_SENDCF,
} CanTp_tenuMfSendStepType;

typedef enum
{
    CANTP_TTT_PHYSICAL = 0u,
    CANTP_TTT_FUNCTIONAL = 1u
} CanTp_tenuTpTaType;

typedef enum
{
	CANTP_TST_IDLE = 0u,
	CANTP_TST_MF_SENDING,
	CANTP_TST_MF_RECVING	
} CanTp_tenuTpStatusType;


typedef struct
{
	uint32 u32CanId;
	uint16 u16DataLen;
	uint8 au8TpBuf[CANTP_u16BUFLEN_MAX];
} CanTp_tstrTpPduType;

typedef struct
{
	uint8 u8Err;  /*0-no err,>0-err*/
	uint16 u16DlcRecved;
	uint8 u8LastInd;
} CanTp_tstrMfRecvStatType;

typedef struct
{
	uint8 u8Err;/*0-no err,>0-err*/
	uint16 u16DlcSent;
	uint8 u8LastInd;
} CanTp_tstrMfSendStatType;

typedef struct
{
	uint8 u8FlowStatus;
	uint8 u8BlockSize;
	uint8 u8STMin;
}CanTp_tstrFlowControlType;
/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void CanTp_vidInit(void);
extern void CanTp_vidManage(void);
extern void CanTp_vidCanTpRxIndication(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa);
extern void CanTp_vidDataCopy(uint8* pu8Dest,uint8* pu8Src,uint16 u16Cnt);
extern void CanTp_vidDataSet(uint8* pu8Dest,uint8 u8Val,uint16 u16Cnt);
extern void CanTp_vidDiagResp(uint16 u16DataLen);
#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/

/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : CanDiag_Cfg                                             */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !Module          : CanDiag_Cfg                                             */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !File            : CanDiag_Cfg.h                                           */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanDiag/CanDiag_Cfg.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:08   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:04   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/

#ifndef CANDIAG_CFG_H
#define CANDIAG_CFG_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Platform_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CANDIAG_u8SERIDNUMS 					17u
#define CANDIAG_u8SESLMT_DEFAULT_MSK       			0x01u
#define CANDIAG_u8SESLMT_PROGRAMMING_MSK   			0x02u
#define CANDIAG_u8SESLMT_EXTENDED_MSK      			0x04u
#define CANDIAG_u8SECLMT_LVL0     				0x00u
#define CANDIAG_u8SECLMT_LVL1     				0x01u
#define CANDIAG_u8SECLMT_LVL2     				0x02u
#define CANDIAG_u8SECLMT_LVL3     				0x04u
#define CANDIAG_u8SECLMT_LVL4     				0x08u
#define CANDIAG_u8ADDRLMT_PHYSICAL     			0x01u
#define CANDIAG_u8ADDRLMT_FUNCTIONAL   			0x02u

#define CANDIAG_u16TIMEOUT_SESSION_MAX 			5000u /*5000ms*/
#define CANDIAG_u16TIMEOUT_P2SERVER_MAX			50u /*50ms*/
#define CANDIAG_u16TIMEOUT_P2SERVER1_MAX		5000u /*5000ms P2*SERVER*/
	
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef struct
{
	uint8 u8SID;
	uint8 u8SessionLimitMsk;
	uint8 u8SecurityLimit;
	uint8 u8AddressingModeLimit;
	boolean bSupport;
} CanDiag_tstrSerSupportType;

/* Context information of a request */
typedef struct
{
    uint8 reqType; /* 0=physical request; 1=functional request */
    uint8 suppressPosResponse;/* 0=no; 1=yes;*/
    uint8 cancelOperation;/* 0=no;1=cancel pending operation */
}CanDiag_tstrMsgAddInfoType;

typedef struct
{
  uint8*              reqData;
  uint16              reqDataLen;
  uint8*              resData;
  uint16              resDataLen;
  uint32              u32CanId;
  CanDiag_tstrMsgAddInfoType msgAddInfo;
}CanDiag_tstrMsgContextType;
/******************************************************************************/
/* DATA DECLARATION                                               */
/******************************************************************************/
extern const CanDiag_tstrSerSupportType CanDiag_kstrSerSupport[CANDIAG_u8SERIDNUMS];

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void AppDiag_vidECUResetPost(void);
extern uint8 AppDiag_u8ReadMemoryByAddress(CanDiag_tstrMsgContextType *pMsgContext);
extern uint8 AppDiag_u8WriteMemoryByAddress(CanDiag_tstrMsgContextType *pMsgContext);
extern uint8 AppDiag_u8ReadDataByIdentifier(CanDiag_tstrMsgContextType *pMsgContext);
extern uint8 AppDiag_u8WriteDataByIdentifier(CanDiag_tstrMsgContextType *pMsgContext);
extern uint8 AppDiag_u8InputOutputControlByIdentifier(CanDiag_tstrMsgContextType *pMsgContext);

extern uint8 AppDtc_u8ClearDiagnosticInformation(CanDiag_tstrMsgContextType *pMsgContext);
extern uint8 AppDtc_u8ReadDTCInfomation(CanDiag_tstrMsgContextType *pMsgContext);
extern uint8 AppDtc_u8ControlDTCSetting(CanDiag_tstrMsgContextType *pMsgContext);
#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/

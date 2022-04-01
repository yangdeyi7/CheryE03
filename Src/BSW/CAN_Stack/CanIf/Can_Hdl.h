/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : Can_Hdl                                                   */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !Module          : Can_Hdl                                                   */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !File            : Can_Hdl.h                                                 */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/Can/Can_Hdl.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:06   chunping.yan
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

#ifndef CAN_DHL_H
#define CAN_DHL_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Can_Type.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define Can_u8GetSendNOkCnt()			(Can_u8SendNOkCnt)
#define Can_u8GetSendOkCnt()			(Can_u8SendOkCnt)

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef void (*Can_tpfvidRxFuncCallback)(Can_tstrPduType strPdu);
typedef void (*Can_tpfvidTxFuncCallback)(Can_tstrPduType strPdu);

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/



/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void  Can_vidRxHandler(Can_tstrPduType strPdu);
extern void  Can_vidTxHandler(void);
extern void  Can_vidWakeupHandler(void);
extern void  Can_vidBusoffHandler(void);
extern void  Can_vidSetRxCallbackFunc(Can_tpfvidRxFuncCallback pfvidCallback);
extern void  Can_vidSetTxCallbackFunc(Can_tpfvidTxFuncCallback pfvidCallback);
extern void  Can_vidSetWakeUpCallbackFunc(Std_tpfvidFuncCbk_vid pfvidCallback);
extern void  Can_vidSetBusOffCallbackFunc(Std_tpfvidFuncCbk_u8 pfvidCallback);
extern void  Can_vidHdlInit(void);
extern uint8 Can_u8CanMsgSendIdDatDlc(uint8 u8BufNo, uint32 u32CanId, uint8* pu8Data, uint8 u8Dlc);


extern uint8 au8_00A_C_57900323_10_B0B1[2];
extern uint8 au8_00A_C_57900323_10_B2B3[2];
extern uint8 au8_00A_C_57900323_10_B4B5[2];
extern uint8 au8_00A_C_57900323_10_B6B7[2];

extern uint8 au8_00B_C_57900323_11_B0B1[2];
extern uint8 au8_00B_C_57900323_11_B2B3[2];
extern uint8 au8_00B_C_57900323_11_B4B5[2];
extern uint8 au8_00B_C_57900323_11_B6B7[2];

extern uint8 au8_00C_C_57900322_12_B0B1[2];
extern uint8 au8_00C_C_57900322_12_B2B3[2];
extern uint8 au8_00C_C_57900322_12_B4B5[2];
extern uint8 au8_00C_C_57900322_12_B6B7[2];

extern uint8 au8_00D_C_57900322_13_B0B1[2];
extern uint8 au8_00D_C_57900322_13_B2B3[2];
extern uint8 au8_00D_C_57900322_13_B4B5[2];
extern uint8 au8_00D_C_57900322_13_B6B7[2];

extern uint8 au8_00E_C_56704738_14_B0B1[2];
extern uint8 au8_00E_C_56704738_14_B2B3[2];
/*
extern uint8 au8_00E_C_56704738_14_B4B5[2];
extern uint8 au8_00E_C_56704738_14_B6B7[2];

extern uint8 au8_00F_C_56704738_15_B0B1[2];
extern uint8 au8_00F_C_56704738_15_B2B3[2];
extern uint8 au8_00F_C_56704738_15_B4B5[2];
extern uint8 au8_00F_C_56704738_15_B6B7[2];
*/

#endif  

/*-------------------------------- end of file -------------------------------*/

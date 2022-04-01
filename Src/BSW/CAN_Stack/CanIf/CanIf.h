/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !Module          : CanIf                                                   */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !File            : CanIf.h                                                 */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanIf/CanIf.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:10   chunping.yan
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

#ifndef CANIF_H
#define CANIF_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "CanIf_Cfg.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CanIf_u8DISABLEAPPCOMTX1_SET		0x01u
#define CanIf_u8DISABLEAPPCOMTX1_CLR		0xFEu
#define CanIf_u8DISABLEAPPCOMRX1_SET		0x02u
#define CanIf_u8DISABLEAPPCOMRX1_CLR		0xFDu

#define CanIf_u8DISABLEAPPCOMTX2_SET		0x10u
#define CanIf_u8DISABLEAPPCOMTX2_CLR		0xEFu
#define CanIf_u8DISABLEAPPCOMRX2_SET		0x20u
#define CanIf_u8DISABLEAPPCOMRX2_CLR		0xDFu

#define CanIf_u8DISABLEAPPCOMTX_SET			0x11u
#define CanIf_u8DISABLEAPPCOMTX_CLR			0xEEu
#define CanIf_u8DISABLEAPPCOMRX_SET			0x22u
#define CanIf_u8DISABLEAPPCOMRX_CLR			0xDDu

#define CanIf_vidDisableAppComRx1()		(CanIf_u8AppComDisable |= CanIf_u8DISABLEAPPCOMRX1_SET)
#define CanIf_vidDisableAppComTx1()		(CanIf_u8AppComDisable |= CanIf_u8DISABLEAPPCOMTX1_SET)
#define CanIf_vidEnableAppComRx1()		(CanIf_u8AppComDisable &= CanIf_u8DISABLEAPPCOMRX1_CLR)
#define CanIf_vidEnableAppComTx1()		(CanIf_u8AppComDisable &= CanIf_u8DISABLEAPPCOMTX1_CLR)
#define CanIf_vidDisableAppComRx2()		(CanIf_u8AppComDisable |= CanIf_u8DISABLEAPPCOMRX2_SET)
#define CanIf_vidDisableAppComTx2()		(CanIf_u8AppComDisable |= CanIf_u8DISABLEAPPCOMTX2_SET)
#define CanIf_vidEnableAppComRx2()		(CanIf_u8AppComDisable &= CanIf_u8DISABLEAPPCOMRX2_CLR)
#define CanIf_vidEnableAppComTx2()		(CanIf_u8AppComDisable &= CanIf_u8DISABLEAPPCOMTX2_CLR)
#define CanIf_vidDisableAppComRx()		(CanIf_u8AppComDisable |= CanIf_u8DISABLEAPPCOMRX_SET)
#define CanIf_vidDisableAppComTx()		(CanIf_u8AppComDisable |= CanIf_u8DISABLEAPPCOMTX_SET)
#define CanIf_vidEnableAppComRx()		(CanIf_u8AppComDisable &= CanIf_u8DISABLEAPPCOMRX_CLR)
#define CanIf_vidEnableAppComTx()		(CanIf_u8AppComDisable &= CanIf_u8DISABLEAPPCOMTX_CLR)


#define CanIf_vidSetAppComDisable(x)	(CanIf_u8AppComDisable = x)
#define CanIf_u8GetAppComDisable()		(CanIf_u8AppComDisable)
#define CanIf_bGetAppComDisableRx()		(((CanIf_u8AppComDisable & CanIf_u8DISABLEAPPCOMRX_SET) > 0u ) ? TRUE : FALSE)
#define CanIf_bGetAppComDisableTx()		(((CanIf_u8AppComDisable & CanIf_u8DISABLEAPPCOMTX_SET) > 0u ) ? TRUE : FALSE)


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
extern uint8 CanIf_u8AppComDisable;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void CanIf_vidInit(void);
extern void CanIf_vidRxTask(void);
extern void CanIf_vidTxTask(void);
/* extern void CanIf_vidSetAppTxDelay(void); */
extern void CanIf_vidSetAppCycMsgTxTrue(void);
extern void CanIf_vidSetAppCycMsgTxFalse(void);

#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/

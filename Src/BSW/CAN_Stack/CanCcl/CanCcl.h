/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : CanCcl                                                  */
/*                                                                            */
/* !Component       : CanCcl                                                  */
/* !Description     : CAN communication interface                             */
/*                                                                            */
/* !Module          : CanCcl                                                  */
/* !Description     : CAN communication interface                             */
/*                                                                            */
/* !File            : CanCcl.h                                                */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanCcl/CanCcl.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:08   chunping.yan
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

#ifndef CANCCL_H
#define CANCCL_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Can_Type.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CanCcl_vidComStart() (CanCcl_vidSetCanMode(CANCCL_CMT_START))
#define CanCcl_vidComStop()  (CanCcl_vidSetCanMode(CANCCL_CMT_STOP))
#define CanCcl_vidComSleep() (CanCcl_vidSetCanMode(CANCCL_CMT_SLEEP))


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
    CANCCL_CMT_START = 0u,
    CANCCL_CMT_WORK,
    CANCCL_CMT_SLEEP, 
    CANCCL_CMT_STOP	
} CanCcl_tenuCanModeType;

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void CanCcl_vidInit(void);
extern void CanCcl_vidMainTask(void);
extern void CanCcl_vidSetCanMode(CanCcl_tenuCanModeType enuCanMode);
extern void CanCcl_vidSetTxState(uint8 u8State);
extern void CanCcl_vidSetRxState(uint8 u8State);
#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/

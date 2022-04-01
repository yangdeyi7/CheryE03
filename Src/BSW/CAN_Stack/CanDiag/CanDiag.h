/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : CanDiag                                                 */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !Module          : CanDiag                                                 */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !File            : CanDiag.h                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanDiag/CanDiag.h-arc  $
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

#ifndef CANDIAG_H
#define CANDIAG_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Platform_Types.h"
#include "CanDiag_Cfg.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define CanDiag_u8GetForbPosRes()   CanDiag_u8ForbPosRes


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
#define ProtectedWriteReg(preg,reg,value)      \
{                                              \
    preg =  0x000000A5UL;                      \
    reg  =  value;                             \
    reg  = ~value;                             \
    reg  =  value;                             \
}

#define PROTCMD0         (*((volatile uint32          *)0xfff80000UL))
#define PROTS0           (*((volatile uint32          *)0xfff80004UL))
#define SWRESA           (*((volatile uint32          *)0xfff80a04UL))

#define SOFT_RESET_VALUE 1u
#define FBL_SOFT_RESET() ProtectedWriteReg(PROTCMD0, SWRESA, SOFT_RESET_VALUE)

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

extern uint8 CanDiag_u8ForbPosRes;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void CanDiag_vidInit(void);
extern void CanDiag_vidSetCanDiagMsg(CanDiag_tstrMsgContextType strDmc);
extern void CanDiag_vidManage(void);



#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/

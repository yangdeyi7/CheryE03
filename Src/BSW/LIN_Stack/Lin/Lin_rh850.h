/******************************************************************************/
/* PROJECT  :  XXX                                                            */
/******************************************************************************/
/* !Layer           : Lin                                                     */
/*                                                                            */
/* !Component       : Lin                                                     */
/* !Description     : Provides interface for LIN Driver                       */
/*                                                                            */
/* !Module          : Lin                                                     */
/* !Description     : Provides interface for LIN Driver                       */
/*                                                                            */
/* !File            : Lin.h                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/*!Target          : RH850F1K-S1                                              */
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
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Jun 30 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_LIN/LinDrv/LinDrv.h-arc  $
 * 
 *    Rev 1.1   Jun 30 2017 18:19:06   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/

#ifndef LIN_RH850_H
#define LIN_RH850_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Lin_Cfg.h"
#include "Lin_Type_rh850.h"
#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define LIN_SYN_BYTE                ((uint8)0x55u)
#define LIN_MAX_DATA_DLC            (8)

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* Registers of the RLin3n Module */
typedef struct 
{
  volatile uint8 Unused0;
  volatile uint8 u8LWBR;
  volatile uint8 u8LBRP0;
  volatile uint8 u8LBRP1;
  volatile uint8 u8LSTC;
  volatile uint8 Unused1[3];
  volatile uint8 u8LMD;
  volatile uint8 u8LBFC;
  volatile uint8 u8LSC;
  volatile uint8 u8LWUP;
  volatile uint8 u8LIE;
  volatile uint8 u8LEDE;
  volatile uint8 u8LCUC;
  volatile uint8 Unused2;
  volatile uint8 u8LTRC;
  volatile uint8 u8LMST;
  volatile uint8 u8LST;
  volatile uint8 u8LEST;
  volatile uint8 u8LDFC;
  volatile uint8 u8LIDB;
  volatile uint8 u8LCBR;
  volatile uint8 u8LUDB0;
  volatile uint8 u8LDBR[8];
  volatile uint8 u8LUOER;
  volatile uint8 u8LUOR1;
  volatile uint8 Unused[2];
  volatile uint8 u8LUTDRL;
  volatile uint8 u8LUTDRH;
  volatile uint8 u8LURDRL;
  volatile uint8 u8LURDRH;
  volatile uint8 u8LUWTDRL;
  volatile uint8 u8LUWTDRH;
}tstrRLin3n;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void Lin_vidInit(uint8 u8ChanNum);
extern Std_ReturnType Lin_udtGoToSleep(uint8 u8ChanNum);



#ifdef LIN_SLAVE
extern void Lin_vidSlaveStart(uint8 u8ChanNum);
extern void Lin_vidSlaveStop(uint8 u8ChanNum);
#else
extern void Lin_vidMasterSend(uint8 u8ChanNum, LIN_tstrPduType* pstrPdu);
#endif



extern LIN_tenuStatusType Lin_enuGetStatus(uint8 u8ChanNum);
extern void Lin_vidSetStatus(uint8 u8ChanNum, LIN_tenuStatusType enuLinStatus);

/******************************************************************************/

#endif/* LIN_H */

/*-------------------------------- end of file -------------------------------*/

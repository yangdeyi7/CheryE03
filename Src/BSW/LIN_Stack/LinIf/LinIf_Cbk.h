/******************************************************************************/
/* PROJECT  :  XXXX                                                           */
/******************************************************************************/
/*!Layer           : LINIF                                                    */
/*                                                                            */
/*!Component       : LINIF                                                    */
/*!Description     : Contains the interface of LIN                            */
/*                                                                            */
/*!Module          : LinIf                                                    */
/*!Description     : LinIf                                                    */
/*                                                                            */
/*!File            : LinIf_cbk.h                                              */
/*                                                                            */
/*!Scope           : Private                                                  */
/*                                                                            */
/*!Target          : RH850F1L                                                 */
/*                                                                            */
/*!Vendor          : VALEO Climate Control Shashi                             */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2016 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/A$*/
/* $Revision::   1.2     $$Author::   yunxin.liu      $$Date::   Feb 14 2017 $*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/AppESS.c-arc  $
 * 
                                                                              */
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */

/******************************************************************************/
#ifndef LINIF_CBK_H
#define LINIF_CBK_H

/*******************************************************************************
*   Includes 
*******************************************************************************/
#include "Lin_Type_rh850.h"

extern const LIN_tstrPduType* Linif_pstrRxHeadCb(uint8 u8ChanNum, uint8 u8Pid);
extern void Linif_vidRxErrorCb(uint8 u8ChanNum, uint8 u8ErrorCode);

#endif /* LINIF_CBK_H */


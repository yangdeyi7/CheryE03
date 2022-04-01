/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : CMB                                                     */
/*                                                                            */
/* !Component       : CMB                                                     */
/* !Description     : CMB Control                                             */
/*                                                                            */
/* !Module          : CMB                                                     */
/* !Description     : CMB Control                                             */
/*                                                                            */
/* !File            : CMB.h                                                   */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/EC$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/CMB.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:10   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
#ifndef CMB_H
#define CMB_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


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
    CMB_DEMAND_FORNT_DEF,
    CMB_DEMAND_INCAR_FAN,
    CMB_DEMAND_HEAT_WIND,
    SOV_RLY1,  
    SOV_RLY2,  
    BLW_RLY3, 
    FAN_RLY4,  
    SOTXV_RLY5,
} CMB_tenuId;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void CMB_vidInit(void);
extern void CMB_vidSetSignalState(CMB_tenuId enuId, uint8 u8State);
extern void CMB_vidManageSignals(void);
extern uint8 CMB_enuForntDefStatus(void);
extern uint8 CMB_enuIncarFanStatus(void);
extern uint8 CMB_enuHeatWindStatus(void);







#endif
/*-------------------------------- end of file -------------------------------*/

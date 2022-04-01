/******************************************************************************/
/* PROJECT  :    M01_RCP                                                      */
/******************************************************************************/
/* !Layer           : Wdog                                                    */
/*                                                                            */
/* !Component       : Wdog                                                    */
/* !Description     : Provides interface for refreshing the watchdog          */
/*                                                                            */
/* !Module          : Wdog                                                    */
/* !Description     : Provides interface for refreshing the watchdog          */
/*                                                                            */
/* !File            : Wdog.h                                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : R7F7010233AFP                                           */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Se$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Jun 30 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/Wdog.h-arc  $
 * 
 *    Rev 1.1   Jun 30 2017 18:19:16   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/

#ifndef WDOG_H
#define WDOG_H
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
/******************************************************************************/
/*! \Description manage monitor flag ID.
 ******************************************************************************/
typedef enum
{
  WDG_Task10,
  WDG_Task40,
  WDG_Task100
} WDG_tenuId;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
/******************************************************************************/
/*! \Description refresh watchdog state.
 ******************************************************************************/
extern void Wdog_vidRefresh(void);

/******************************************************************************/
/*! \Description initial watchdog.
 ******************************************************************************/
extern void Wdog_vidInit(void);

/******************************************************************************/
/*! \Description management the watchdog.
 ******************************************************************************/
extern void Wdog_vidManage(void) ;

/******************************************************************************/
/*! \Description finish task of watchdog.
 ******************************************************************************/
extern void Wdog_vidTaskFinish(WDG_tenuId enuId);

#endif

/*-------------------------------- end of file -------------------------------*/


/******************************************************************************/
/* PROJECT  :    PHEV                                                         */
/******************************************************************************/
/* !Layer           : Wdog                                                    */
/*                                                                            */
/* !Component       : Wdog                                                    */
/* !Description     : Provides interface for refreshing the watchdog          */
/*                                                                            */
/* !Module          : Wdog                                                    */
/* !Description     : Provides interface for refreshing the watchdog          */
/*                                                                            */
/* !File            : Wdog.c                                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : R7F7016843xAFP                                          */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Dio.h" 
#include "Wdog.h"
#include "DWdg.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define MONITOR_TASK_NUM   3u
#define MONITOR_INTERVAL   4u

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
/* DATA DEFINITION                                                            */
/******************************************************************************/
static boolean WDG_abTaskMonitor[MONITOR_TASK_NUM] ;


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function:   Wdog_vidRefresh                                                */
/*! \Description Refresh watchdog. \n
    \return      void.
    \Trace_To :  CDD-Wdog-0005(0) 
*******************************************************************************/

void Wdog_vidRefresh(void)
{
  //lsy
  DWdg_vidWdgRefresh();
  
 // static uint8 LOC_u8WdogValue = 0;
  
  /* Toggle the value */
 // LOC_u8WdogValue = !LOC_u8WdogValue;
  
  /* Write the value to watchdog pin */
 // Dio_vidWrite(DIO_u8OUT_WDG, LOC_u8WdogValue);
  
} /* End of Wdog_vidRefresh */ 

/******************************************************************************/
/*!Function:   Wdog_vidInit                                                   */
/*! \Description Initial watchdog. \n
    \return      void.
    \Trace_To :  CDD-Wdog-0004(0) 
*******************************************************************************/
void Wdog_vidInit(void)
{
 /* INITIAL TASK  MONITOR FLAGS */
  WDG_abTaskMonitor[WDG_Task10]  = FALSE ;
  WDG_abTaskMonitor[WDG_Task40] = FALSE ;
  WDG_abTaskMonitor[WDG_Task100] = FALSE ;
  //lsy
  DWdg_vidInit();
}  /* end of Wdog_vidInit()  */  

/******************************************************************************/
/*!Function:   Wdog_vidTaskFinish                                                */
/*! \Description finish task of watchdog. \n
    \return      void.
    \Trace_To :  CDD-Wdog-0007(0) 
*******************************************************************************/
void Wdog_vidTaskFinish(WDG_tenuId enuId)
{
 /* INITIAL TASK  MONITOR FLAGS */
  WDG_abTaskMonitor[enuId]  = TRUE ; 
}  /* end of  Wdog_vidTaskFinish()  */



/******************************************************************************/
/*!Function:   Wdog_vidManagement                                             */
/*! \Description Management watchdog. \n
    \return      void.
    \Trace_To :  CDD-Wdog-0006(0)
*******************************************************************************/
void Wdog_vidManage(void)
{
  static uint8 LOC_u8MontierInterval = 0 ;
  if(LOC_u8MontierInterval >= MONITOR_INTERVAL)
  {   
	  /* if Watchdog 10ms,60ms,100ms tasks are all done,then close the Monitor */
     if((WDG_abTaskMonitor[WDG_Task10] == TRUE) && 
        (WDG_abTaskMonitor[WDG_Task40] == TRUE) &&
        (WDG_abTaskMonitor[WDG_Task100] == TRUE) )
     {
       WDG_abTaskMonitor[WDG_Task10]  = FALSE;
       WDG_abTaskMonitor[WDG_Task40] = FALSE;
       WDG_abTaskMonitor[WDG_Task100] = FALSE;
     }
     else
     {
       /* reset mcu*/
       for(; ;)
       {
       }  
     }
     /*  Reset the  interval value for next circle */
     LOC_u8MontierInterval = 0;    
  }
  LOC_u8MontierInterval++;
}   /* end of  Wdog_vidTaskFinish() */ 



/*-------------------------------- end of file -------------------------------*/



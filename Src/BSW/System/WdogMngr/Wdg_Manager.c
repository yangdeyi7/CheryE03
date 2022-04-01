/******************************************************************************/
/* PROJECT          : HKMC NU2 BCC                                         */
/******************************************************************************/
/* !Layer           : ECUAL                                                   */
/*                                                                            */
/* !Component       : Wdg                                                     */
/* !Description     : Controling external Wdg chip.                           */
/*                                                                            */
/* !Module          : Wdg                                                     */
/* !Description     : Watch dog manager                                       */
/*                                                                            */
/* !File            : Wdg_Manager                                             */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* PROJECT          : HKMC NU2 BCC                                         */
/*                                                                            */
/* !Vendor          : VIAS ( VALEO INTERBRANCH AUTOMOTIVE SOFTWARE )          */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2016 VALEO                                                       */
/* all rights reserved                                                        */
/******************************************************************************/

/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:                                                                       $
 * 
 *    Rev 1.2   Sep 24 2017 09:34:10   selbiali
 * VNR and MISRA Fixation
 * 
 *    Rev 1.1   Feb 06 2017 20:45:52   amansour
 * SMF_0005: ECUAL MISRA, MCAL MISRA, Services MISRA
 * SMF_0006: Change Request (Power.c), SIQ #92 to #97
 * SMF_0007: Miscellaneous: removal of redundant multiple, inclusion prot-
 * ection and removal for 2 modules (sensor.c,.h), adding robustness agai-
 * nst infinite loop, Source code Indentation fixed.
 * 
 *    Rev 1.0   Jan 17 2017 12:27:16   amansour
 * Initial revision.
*******************************************************************************/

/*=============================================================================
                               INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
 =============================================================================*/

/*! \Trace_To  :
* HVAC_SCD_SYSTEM_0001#01
* HVAC_SCD_SYSTEM_0071#01
*/

#include "Std_Types.h"
#include "DWdg.h"
#include "WDG_Manager.h"

/*==============================================================================
*                           LOCAL MACROS, DEFINES
==============================================================================*/
/*!Description: Number of occurrence of smallest period tasks*/
/*! \Trace_To: HVAC_SCD_SYSTEM_0052#01    */
#define u8NB_OCCUR_SMALL_TASK                   ((uint8)24)
#define u8WD_JUDGE_GATE                         ((uint8)18)


/*==============================================================================
*               LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/


/*==============================================================================
*                             LOCAL VARIABLES
==============================================================================*/
/*! \Trace_To: HVAC_SCD_SYSTEM_0053#01  ,HVAC_SCD_SYSTEM_0054#01    */
/*Runtime error counter */
static uint8   Wdg_u8RunTimeCounter;
/*Flag to cover the margin between the slow and fast tasks */
static boolean Wdg_bFlagForFirstTime;

/*==============================================================================
*                            GLOBAL FUNCTIONS
==============================================================================*/

/*============================================================================*/


/******************************************************************************/
/* !Function    : Wdg_vidInitialize                                           */
/* !Description : Initialization routine for Watch Dog                        */
/*! \Trace_To   : HVAC_SCD_SYSTEM_0039#01,HVAC_SCD_SYSTEM_0040#01            */
/******************************************************************************/
extern void Wdg_vidInitialize( void )
{
    Wdg_u8RunTimeCounter  = u8NB_OCCUR_SMALL_TASK;

    Wdg_bFlagForFirstTime = FALSE;
}


/******************************************************************************/
/* !Function    : Wdg_vidManagSlow                                            */
/* !Description : Monitor of tasks of less periods                            */
/*! \Trace_To   : HVAC_SCD_SYSTEM_0041#01,HVAC_SCD_SYSTEM_0042#01            */
/******************************************************************************/
extern void Wdg_vidManagSlow( void )
{
    static uint8 LOC_u8Counter = (uint8)0;

    if(Wdg_bFlagForFirstTime == FALSE)
    {
        if(LOC_u8Counter < (uint8)1)
        {
          LOC_u8Counter ++;
        }
        else
        {
            /*Raise the flag that the first run happened*/
            Wdg_bFlagForFirstTime = TRUE;
            /*Reload the counter*/
            Wdg_u8RunTimeCounter  = u8NB_OCCUR_SMALL_TASK;
        }
    }
    /*Check if the whole Tasks of less period has been executed successfully*/
    else if(Wdg_u8RunTimeCounter <= u8WD_JUDGE_GATE)
    {
        /*Reload the counter*/
        Wdg_u8RunTimeCounter = u8NB_OCCUR_SMALL_TASK;
    }
    else
    {
        /*reseted by watch dog*/
        DWdg_vidWdgReset();
    }

}


/******************************************************************************/
/* !Function    : Wdg_vidManagFast                                            */
/* !Description : Monitor of tasks of less periods                            */
/*! \Trace_To   : HVAC_SCD_SYSTEM_0043#01,HVAC_SCD_SYSTEM_0044#01            */
/******************************************************************************/
extern void Wdg_vidManagFast( void )
{
    /*Check if the counter reloaded or not*/
    if((Wdg_u8RunTimeCounter == (uint8)0) && (Wdg_bFlagForFirstTime == TRUE ))
    {
        /*reseted by watch dog*/
        DWdg_vidWdgReset();
    }
    else
    {
        /*Decrement the counter*/
        Wdg_u8RunTimeCounter --;
        /*Refresh the watch dog*/
        DWdg_vidWdgRefresh();
    }

}


/******************************************************************************/
/* !Function    : Wdg_vidResetCounterForLowPowerWakeup                        */
/* !Description : Reset watchdog counter for lowpower wake up                */
/*! \Trace_To   : HVAC_SCD_SYSTEM_0043#01,HVAC_SCD_SYSTEM_0044#01            */
/******************************************************************************/
extern void Wdg_vidResetCounterForLowPowerWakeup( void )
{
    Wdg_u8RunTimeCounter = u8WD_JUDGE_GATE;
}

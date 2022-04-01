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
/* !File            : Wdg_Manager.h                                           */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : NXP FS32K144 HAT0VLLR                                   */
/*                                                                            */
/* !Vendor          : VIAS ( VALEO INTERBRANCH AUTOMOTIVE SOFTWARE )          */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2016 VALEO                                                       */
/* all rights reserved                                                        */
/******************************************************************************/



#ifndef WDG_MANAGER_H
#define WDG_MANAGER_H
/*==============================================================================
*                                       LOCAL MACROS, DEFINES
==============================================================================*/



/*==============================================================================
*                LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/


/*==============================================================================
*                           LOCAL VARIABLES
==============================================================================*/



/*==============================================================================
*                          GLOBAL FUNCTIONS
==============================================================================*/


/******************************************************************************/
/* !Function    : Wdg_vidInitialize                                           */
/* !Description : Initialization routine for Watch Dog                        */
/******************************************************************************/
extern void Wdg_vidInitialize( void );


/******************************************************************************/
/* !Function    : Wdg_vidManagSlow                                            */
/* !Description : Monitor of tasks of less periods                            */
/******************************************************************************/
extern void Wdg_vidManagSlow( void );

/******************************************************************************/
/* !Function    : Wdg_vidManagFast                                            */
/* !Description : Monitor of tasks of highest period                          */
/******************************************************************************/
extern void Wdg_vidManagFast( void );

/******************************************************************************/
/* !Function    : Wdg_vidResetCounterForLowPowerWakeup                        */
/* !Description : Reset watchdog counter for lowpower wake up                */
/*! \Trace_To   : HVAC_SCD_SYSTEM_0043#01,HVAC_SCD_SYSTEM_0044#01            */
/******************************************************************************/
extern void Wdg_vidResetCounterForLowPowerWakeup( void );


/*============================================================================*/

#endif


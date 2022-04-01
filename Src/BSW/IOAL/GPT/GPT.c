/******************************************************************************/
/* !Layer           : IOAL                                                    */
/*                                                                            */
/* !Component       : GPT                                                     */
/* !Description     : Interface for managing general purpose timer.           */
/*                                                                            */
/* !Module          : GPT                                                     */
/* !Description     : GPT (Implementation of general purpose timer)           */
/*                                                                            */
/* !File            : GPT.c                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : NXP FS32K144 HAT0VLLR                                   */
/*                                                                            */
/* !Vendor          : VIAS ( VALEO INTERBRANCH AUTOMOTIVE SOFTWARE )          */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2019 VALEO                                                       */
/* all rights reserved                                                        */
/******************************************************************************/

/*=============================================================================
                               INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
 =============================================================================*/

#include "s32k144_GPT.h"

/*==============================================================================
*                       LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/


/*==============================================================================
*                                  LOCAL MACROS
==============================================================================*/
#define GPT_SysticktimerReloadValue             ((uint32)80000)


/*==============================================================================
*                                 LOCAL CONSTANTS
==============================================================================*/


/*==============================================================================
*                                 LOCAL VARIABLES
==============================================================================*/

/*==============================================================================
*                                 LOCAL VARIABLES
==============================================================================*/

/*==============================================================================
*                                 GLOBAL CONSTANTS
==============================================================================*/


/*==============================================================================
*                                 GLOBAL VARIABLES
==============================================================================*/
/*! \Trace_To: HVAC_SCD_IOAL_0120#01                                          */
/** TRUE/FALSE if Timer M Initialized                                         */
static VAR(boolean, static)             GPT_bTimerIsInitialized=(boolean)FALSE;

/*! \Trace_To: HVAC_SCD_IOAL_0081#01                                          */
P2FUNC(void, AUTOMATIC, GPT_pfvideOSCallback)(void);
/*============================================================================*/

/*==============================================================================
*                              GLOBAL FUNCTIONS
==============================================================================*/

/*============================================================================*/

/*******************************************************************************
*
*  Initializes the GPT driver, GPT_tstrConfigType is a user defined type structure
*  has all needed configurations to Initialize the GPT Driver
*
*  pkstrConfigPtr  : Pointer to a selected const configuration structure.
*
*******************************************************************************/
/*! \Trace_To: HVAC_SCD_IOAL_0032#01,HVAC_SCD_IOAL_0097#01      */
extern FUNC (void,PUBLIC) GPT_vidInit(void)
{
    /*Set the timer reload value*/
    S32_SysTick->RVR = GPT_SysticktimerReloadValue;
    
    /*set the current value register*/
    S32_SysTick->CVR = (uint32)0;
    /*For the timer to always use the core clock*/
    S32_SysTick->CSR = S32_SysTick_CSR_CLKSOURCE(1u);

    /* To indicate that the timer is initialized  */
    GPT_bTimerIsInitialized = (boolean)TRUE;
}


/*******************************************************************************
*
*   This function is responsible to start the timer of scheduler.
*
*******************************************************************************/
/*! \Trace_To: HVAC_SCD_IOAL_0033#01,HVAC_SCD_IOAL_0078#01      */
extern FUNC (void,PUBLIC) GPT_vidStartSchedTimer(void)
{
    uint32 u32CSRLoc = S32_SysTick->CSR;

    if( GPT_bTimerIsInitialized == (boolean)FALSE)
    {
        /* The Timer is UnInitialized and can't start before calling
           of GPT_vidInit()                                                      */
    }
    else
    {
        /*Enable SysTick interrupt and start counting down*/
        S32_SysTick->CSR = (u32CSRLoc | S32_SysTick_CSR_TICKINT(1u) | S32_SysTick_CSR_ENABLE(1u));
    }
}

/*******************************************************************************
*
*   This function is responsible to stop the timer of scheduler.
*
*******************************************************************************/
extern FUNC (void,PUBLIC) GPT_vidDeInit(void)
{
    uint32 u32CSRLoc = S32_SysTick->CSR;
    
    S32_SysTick->CSR = u32CSRLoc & 0xFFFFFFFC;//(u32CSRLoc & (~S32_SysTick_CSR_TICKINT(1u)) & (~S32_SysTick_CSR_ENABLE(1u)));
}


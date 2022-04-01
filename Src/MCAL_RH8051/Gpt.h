/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Gpt                                                     */
/*                                                                            */
/* !Component       : Gpt                                                     */
/* !Description     : Interface for managing general purpose timer.           */
/*                                                                            */
/* !Module          : Gpt                                                     */
/* !Description     : Gpt                                                     */
/*                                                                            */
/* !File            : Gpt.h                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* all rights reserved                                                        */
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#ifndef GPT_H
#define GPT_H


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#include "Std_Types.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef void (*Gpt_tpfvidTimerCallback)(void);


typedef enum
{
    Gpt_OSTM_CH0 = 0u,
	Gpt_OSTM_CH1,
	Gpt_OSTM_CH2,
	Gpt_OSTM_CH3,
	Gpt_OSTM_CH4,
    MaxNumberofChannels
}Gpt_tenuChannelType;


typedef struct
{
	/* Number of GPT channels                                                 */
    uint8  u8ChannelNumber;
	
} Gpt_tstrConfigType;

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
extern void Gpt_vidInit(const Gpt_tstrConfigType*  pkstrConfigPtr);
/******************************************************************************/
/*! \Description   Start the timer and pass it the callback to call when the   
                   timer fires                                                */
/******************************************************************************/
extern void Gpt_vidStartTimer(Gpt_tenuChannelType      enuChannel,
		                      Gpt_tpfvidTimerCallback  pfvidTimerCallback);

extern void Gpt_vidStopTimer(Gpt_tenuChannelType enuChannel);

#endif /* GPT_H                                                               */

/*-------------------------------- end of file -------------------------------*/

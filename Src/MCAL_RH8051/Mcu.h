/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Mcu                                                     */
/*                                                                            */
/* !Component       : Mcu                                                     */
/* !Description     : Interface for managing common micro peripherals.        */
/*                                                                            */
/* !Module          : Mcu                                                     */
/* !Description     : Mcu                                                     */
/*                                                                            */
/* !File            : Mcu.h                                                   */
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
#ifndef MCU_H
#define MCU_H

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
/******************************************************************************/
/*! \Description : Initialization function                                    */
/******************************************************************************/
extern void Mcu_vidInit( void );
/******************************************************************************/
/*! \Description : Enable interrupts                                          */
/******************************************************************************/
extern void Mcu_vidEnableInterrupts( void );
/******************************************************************************/
/*! \Description : disable interrupts.                                        */
/******************************************************************************/
extern void Mcu_vidDisableInterrupts(void);

#endif /* MCU_H */

/*-------------------------------- end of file -------------------------------*/


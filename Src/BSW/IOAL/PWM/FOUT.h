#ifndef FOUT_H
#define FOUT_H

#include "Std_Types.h"
#include "flexTimer_pwm_PWM_BLW.h"
#include "flexTimer_pwm_PWMOUT1_2.h"
#include "ftm_pwm_driver.h"
/******************************************************************************/                                               
#define FOUT_u8PWM_BLW                  ((uint8)0)
#define FOUT_u8PWM_PWMOUT1              ((uint8)1)
#define FOUT_u8PWM_PWMOUT2              ((uint8)2)



/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* !Description : Initialization routine for FOUT                             */
/*! \Trace_To:    HVAC_SCD_IOAL_0037#01                                        */
/******************************************************************************/
extern void FOUT_vidInit(void);


/******************************************************************************/
/*!Comment: Function responsible for generating the required PWM for the      */
/*            required channel                                                  */
/*!Values:                                                                      */
/*!            u8FOUTInHzDc16Id: Predefined channels Identifiers.                */
/*!          u16FrequencyValue      : Required PWM frequency                  */
/*!          u16DutyCycleValue      : Required Duty Cycle (0..1000%)          */
/*! \Trace_To:    HVAC_SCD_IOAL_0038#02                                            */
/******************************************************************************/
extern void FOUT_vidDutyCycleInPer( uint8 u8FOUTInHzDc16Id,
                                    uint16 u16FrequencyValue,
                                    uint16 u16DutyCycleValue);

/******************************************************************************/
/* !Function    : FOUT_vidInit                                                */
/* !Description : Initialization routine for FOUT                             */
/*! \Trace_To    : HVAC_SCD_IOAL_0037#01,HVAC_SCD_IOAL_0094#01                 */
/******************************************************************************/
extern void FOUT_vidDeInit(void);

#endif /* FOUT_H */


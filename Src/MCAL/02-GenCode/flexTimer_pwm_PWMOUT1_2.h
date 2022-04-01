/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : flexTimer_pwm_PWMOUT1_2.h
**     Project     : S32K144_100PIN_MCAL_Prj
**     Processor   : S32K144_100
**     Component   : ftm_pwm
**     Version     : Component SDK_S32K1xx_15, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K1xx_15
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-12-14, 14:45, # CodeGen: 20
**     Contents    :
**         FTM_DRV_Init                            - status_t FTM_DRV_Init(uint32_t instance,const ftm_user_config_t * info,...
**         FTM_DRV_Deinit                          - status_t FTM_DRV_Deinit(uint32_t instance);
**         FTM_DRV_DeinitPwm                       - status_t FTM_DRV_DeinitPwm(uint32_t instance);
**         FTM_DRV_InitPwm                         - status_t FTM_DRV_InitPwm(uint32_t instance,const ftm_pwm_param_t * param);
**         FTM_DRV_UpdatePwmChannel                - status_t FTM_DRV_UpdatePwmChannel(uint32_t instance,uint8_t channel,...
**         FTM_DRV_FastUpdatePwmChannels           - status_t FTM_DRV_FastUpdatePwmChannels(uint32_t instance, uint8_t...
**         FTM_DRV_UpdatePwmPeriod                 - status_t FTM_DRV_UpdatePwmPeriod(uint32_t instance,uint8_t channel,...
**         FTM_DRV_UpdatePwmPeriodDither           - status_t FTM_DRV_UpdatePwmPeriodDither(uint32_t instance, uint8_t...
**         FTM_DRV_UpdatePwmEdgeChannelDither      - status_t FTM_DRV_UpdatePwmEdgeChannelDither(uint32_t instance, uint8_t...
**         FTM_PWM_DRV_IrqHandler                  - void FTM_PWM_DRV_IrqHandler(uint32_t instance, uint32_t chnOutCtrlVal);
**         FTM_DRV_MaskOutputChannels              - status_t FTM_DRV_MaskOutputChannels(uint32_t instance, uint32_t channelsMask,...
**         FTM_DRV_SetInitialCounterValue          - status_t FTM_DRV_SetInitialCounterValue(uint32_t instance, uint16_t...
**         FTM_DRV_SetHalfCycleReloadPoint         - status_t FTM_DRV_SetHalfCycleReloadPoint(uint32_t instance, uint16_t...
**         FTM_DRV_SetSoftOutChnValue              - status_t FTM_DRV_SetSoftOutChnValue(uint32_t instance, uint8_t...
**         FTM_DRV_SetSoftwareOutputChannelControl - status_t FTM_DRV_SetSoftwareOutputChannelControl(uint32_t instance, uint8_t...
**         FTM_DRV_SetAllChnSoftwareOutputControl  - status_t FTM_DRV_SetAllChnSoftwareOutputControl(uint32_t instance, uint8_t...
**         FTM_DRV_SetInvertingControl             - status_t FTM_DRV_SetInvertingControl(uint32_t instance, uint8_t...
**         FTM_DRV_SetModuloCounterValue           - status_t FTM_DRV_SetModuloCounterValue(uint32_t instance, uint16_t...
**         FTM_DRV_SetSync                         - status_t FTM_DRV_SetSync(uint32_t instance, const ftm_pwm_sync_t *param);
**         FTM_DRV_GetFrequency                    - uint32_t FTM_DRV_GetFrequency(uint32_t instance);
**         FTM_DRV_ConvertFreqToPeriodTicks        - uint16_t FTM_DRV_ConvertFreqToPeriodTicks(uint32_t instance,uint32_t...
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc. 
**     Copyright 2016-2017 NXP 
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file flexTimer_pwm_PWMOUT1_2.h
** @version 01.00
*/         
/*!
**  @addtogroup flexTimer_pwm_PWMOUT1_2_module flexTimer_pwm_PWMOUT1_2 module documentation
**  @{
*/         
#ifndef flexTimer_pwm_PWMOUT1_2_H
#define flexTimer_pwm_PWMOUT1_2_H

/* MODULE flexTimer_pwm_PWMOUT1_2.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The global macro will be used in function call of the module.
 */

/* Include inherited beans */
#include "clockMan1.h"
#include "Cpu.h"
/*! @brief Device instance number */
#define INST_FLEXTIMER_PWM_PWMOUT1_2 2U


/*fault configuration structure for FTM2*/
extern  ftm_pwm_fault_param_t flexTimer_pwm_PWMOUT1_2_FaultConfig;

/* Channels configuration structure for flexTimer_pwm_PWMOUT1_2* independent channels */
extern ftm_independent_ch_param_t flexTimer_pwm_PWMOUT1_2_IndependentChannelsConfig[2];


/* PWM configuration for flexTimer_pwm_PWMOUT1_2 */
extern ftm_pwm_param_t flexTimer_pwm_PWMOUT1_2_PwmConfig;

/* Global configuration of flexTimer_pwm_PWMOUT1_2 */
extern ftm_user_config_t  flexTimer_pwm_PWMOUT1_2_InitConfig;

#endif
/* ifndef flexTimer_pwm_PWMOUT1_2_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/

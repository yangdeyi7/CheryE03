#ifndef MCU_MANAGER_H
#define MCU_MANAGER_H

/*! \Trace_To: HVAC_SCD_SYSTEM_0001#01,HVAC_SCD_SYSTEM_0003#02    */
#include "Std_Types.h"
#include "interrupt_manager.h"

/*****************************************************************************/
/* !Function     : MCU_vidInit                                               */
/* !Description  : Initialize all interrupts with its priority level and     */
/*                    enable used interrupts                                     */
/* !Trace_To     :                                                           */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern FUNC (void,AUTOMATIC) MCU_vidInit(void);

/*****************************************************************************/
/* !Function     : MCU_vidDeInit                                               */
/* !Description  : Deinitialize all interrupts with its priority level and     */
/*                    enable used interrupts                                     */
/* !Trace_To     :                                                           */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0020#01 ,HVAC_SCD_SYSTEM_0021#02  */
/*****************************************************************************/
FUNC (void,AUTOMATIC) MCU_vidDeInit(void);

/*****************************************************************************/
/* !Function     : MCU_vidDisableInterrupts                                  */
/* !Description  : Disables the Global interrupt of the Microcontroller      */
/* !Trace_To     : HVAC_SCD_SYSTEM_0022#01                                   */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern FUNC (void,AUTOMATIC) MCU_vidDisableInterrupts(void);


/*****************************************************************************/
/* !Function     : MCU_vidEnableInterrupts                                   */
/* !Description  : Enables the Global interrupt of the Microcontroller       */
/* !Trace_To     : HVAC_SCD_SYSTEM_0023#01                                      */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern FUNC (void,AUTOMATIC) MCU_vidEnableInterrupts( void );

/*****************************************************************************/
/* !Function     : HardFaultISR                                                 */
/* !Description  : Interrupt Service Routine of Hard fault interrupt         */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void HardFaultISR(void);

/*****************************************************************************/
/* !Function     : SysTickISR                                                 */
/* !Description  : Interrupt Service Routine of the systick timeout          */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void SysTickISR(void);

/*****************************************************************************/
/* !Function     : SpiDstmISR                                                 */
/* !Description  : Interrupt Service Routine of the LPSPI0 master transfer   */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void SpiDstmISR(void);


/*****************************************************************************/
/* !Function     : Adc0CoversionISR                                             */
/* !Description  : Interrupt Service Routine of ADC0 complete conversion     */
/*                    interrupt                                                 */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void Adc0CoversionISR(void);

/*****************************************************************************/
/* !Function     : Adc1CoversionISR                                             */
/* !Description  : Interrupt Service Routine of ADC0 complete conversion     */
/*                    interrupt                                                 */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void Adc1CoversionISR(void);

/*****************************************************************************/
/* !Function     : CanBusOffISR                                                 */
/* !Description  : Interrupt Service Routine of CAN bus off                  */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void CanBusOffISR(void);

/*****************************************************************************/
/* !Function     : CanMailBoxes0ISR                                             */
/* !Description  : Interrupt Service Routine of RX CAN mailboxes             */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void CanMailBoxes0ISR(void);


/*****************************************************************************/
/* !Function     : CanMailBoxes1ISR                                             */
/* !Description  : Interrupt Service Routine of RX CAN mailboxes             */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void CanMailBoxes1ISR(void);


/*****************************************************************************/
/* !Function     : FTM1Timeout_ISR                                             */
/* !Description  : Interrupt Service Routine of LIN mailboxes             */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void FTM1Timeout_ISR(void);

#endif /* MCU_MANAGER_H*/


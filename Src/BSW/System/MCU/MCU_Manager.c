/*=============================================================================
                               INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
 =============================================================================*/
#include "MCU_Manager.h"
#include "s32k144_GPT.h"
#include "DLIN.h"
#include "lptmr_driver.h"


/*==============================================================================
*                 LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/


/*==============================================================================
*                             LOCAL MACROS
==============================================================================*/


/*==============================================================================
*                            LOCAL CONSTANTS
==============================================================================*/


/*==============================================================================
*                            LOCAL VARIABLES
==============================================================================*/


/*==============================================================================
*                            LOCAL FUNCTIONS
==============================================================================*/
void LPSPI2_IRQHandler(void);
void Reset_Handler(void);
void ADC0_IRQHandler(void);
void ADC1_IRQHandler(void);
void CAN0_ORed_IRQHandler(void);
void CAN0_ORed_0_15_MB_IRQHandler(void);
void CAN0_ORed_16_31_MB_IRQHandler(void);
void vidFTM1Isr(void);
/*==============================================================================
*                            GLOBAL CONSTANTS
==============================================================================*/


/*==============================================================================
*                            GLOBAL VARIABLES
==============================================================================*/


/*==============================================================================
*                            GLOBAL FUNCTIONS
==============================================================================*/



/*****************************************************************************/
/* !Function     : MCU_vidInit                                               */
/* !Description  : Initialize all interrupts with its priority level and     */
/*                    enable used interrupts                                 */
/* !Trace_To     :                                                           */
/* !Parameter[in]: void                                                      */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0020#01 ,HVAC_SCD_SYSTEM_0021#02  */
/*****************************************************************************/
FUNC (void,AUTOMATIC) MCU_vidInit(void)
{
    uint8 u8InterruptID;
    
    /*Install new handler for the systick interrupt and enable it */
    INT_SYS_InstallHandler(SysTick_IRQn, &SysTickISR,NULL_PTR);
    INT_SYS_SetPriority(SysTick_IRQn, 0u);

    for(u8InterruptID = 0u; u8InterruptID <= (uint8)FTM3_Ovf_Reload_IRQn; u8InterruptID++)
    {
        switch (u8InterruptID) 
        {
        case (uint8)LPSPI2_IRQn:
            /* Install new handler for the LPSPI0 interrupt and enable it */
            INT_SYS_InstallHandler(LPSPI2_IRQn, &SpiDstmISR, NULL_PTR);
            INT_SYS_SetPriority(LPSPI2_IRQn, 1u);
            INT_SYS_EnableIRQ(LPSPI2_IRQn);
            break;

        case (uint8)ADC0_IRQn:
            /* Install new handler for the ADC0 interrupt and enable it */
            INT_SYS_InstallHandler(ADC0_IRQn, &Adc0CoversionISR, NULL_PTR);
            INT_SYS_SetPriority(ADC0_IRQn, 2u);
            INT_SYS_EnableIRQ(ADC0_IRQn);
            break;
            
        case (uint8)ADC1_IRQn:
            /* Install new handler for the ADC0 interrupt and enable it */
            INT_SYS_InstallHandler(ADC1_IRQn, &Adc1CoversionISR, NULL_PTR);
            INT_SYS_SetPriority(ADC1_IRQn, 2u);
            INT_SYS_EnableIRQ(ADC1_IRQn);
            break;
            
        case (uint8)CAN0_ORed_IRQn:
            /* Install new handler for the CAN Bus-Off interrupt and enable it */
            INT_SYS_InstallHandler(CAN0_ORed_IRQn, &CanBusOffISR, NULL_PTR);
            INT_SYS_SetPriority(CAN0_ORed_IRQn, 2u);
            INT_SYS_EnableIRQ(CAN0_ORed_IRQn);
            break;

        case (uint8)CAN0_ORed_0_15_MB_IRQn:
            /* Install new handler for the CAN mailboxes (0..15) interrupt and enable it */
            INT_SYS_InstallHandler(CAN0_ORed_0_15_MB_IRQn, &CanMailBoxes0ISR,NULL_PTR);
            INT_SYS_SetPriority(CAN0_ORed_0_15_MB_IRQn, 2u);
            INT_SYS_EnableIRQ(CAN0_ORed_0_15_MB_IRQn);
            break;

        case (uint8)CAN0_ORed_16_31_MB_IRQn:
            /* Install new handler for the CAN mailboxes (16..31) interrupt and enable it */
            INT_SYS_InstallHandler(CAN0_ORed_16_31_MB_IRQn, &CanMailBoxes1ISR,NULL_PTR);
            INT_SYS_SetPriority(CAN0_ORed_16_31_MB_IRQn, 2u);
            INT_SYS_EnableIRQ(CAN0_ORed_16_31_MB_IRQn);
            break;
                        
        case (uint8)LPUART2_RxTx_IRQn:
            /*LIN handler has been installed in l_ifc_init()*/
            break;

        case (uint8) FTM1_Ovf_Reload_IRQn:
            /*Install new handler for the FTM1 time out interrupt set priority to 2 and enable it*/
            INT_SYS_InstallHandler(FTM1_Ovf_Reload_IRQn, &FTM1Timeout_ISR,NULL_PTR);
            INT_SYS_EnableIRQ(FTM1_Ovf_Reload_IRQn);
            /* Setup the counter to trigger an interrupt every 500 us */
            FTM_DRV_InitCounter(INST_FLEXTIMER_MCLIN, &flexTimer_mclin_TimerConfig);
            FTM_DRV_CounterStart(INST_FLEXTIMER_MCLIN);
        break;
        
        default:
            /* set default priority to 3 (highest priority used) and disable all unused interrupts */
            INT_SYS_SetPriority((IRQn_Type)u8InterruptID,3u);
            INT_SYS_DisableIRQ((IRQn_Type)u8InterruptID);
            break;
        }
    }
    /* Install new handler for the Hard fault interrupt */
    INT_SYS_InstallHandler(HardFault_IRQn, &HardFaultISR, NULL_PTR);
}


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
FUNC (void,AUTOMATIC) MCU_vidDeInit(void)
{
    INT_SYS_DisableIRQ(LPSPI0_IRQn);
    INT_SYS_DisableIRQ(ADC0_IRQn);         
    INT_SYS_DisableIRQ(ADC1_IRQn);  
    INT_SYS_DisableIRQ(CAN0_ORed_IRQn);
    INT_SYS_DisableIRQ(CAN0_ORed_0_15_MB_IRQn); 
    INT_SYS_DisableIRQ(CAN0_ORed_16_31_MB_IRQn); 
    INT_SYS_DisableIRQ(FTM1_Ovf_Reload_IRQn);
}



/*****************************************************************************/
/* !Function     : MCU_vidDisableInterrupts                                  */
/* !Description  : Disables the Global interrupt of the Microcontroller      */
/* !Trace_To     :                                                           */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0022#01*/
/*****************************************************************************/
FUNC (void,AUTOMATIC) MCU_vidDisableInterrupts(void)
{
    INT_SYS_DisableIRQGlobal();
}

/*****************************************************************************/
/* !Function     : MCU_vidDisableInterrupts                                  */
/* !Description  : Enables the Global interrupt of the Microcontroller       */
/* !Trace_To     :                                                           */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To    :HVAC_SCD_SYSTEM_0023#01                                    */
/*****************************************************************************/
FUNC (void,AUTOMATIC) MCU_vidEnableInterrupts( void )
{
    INT_SYS_EnableIRQGlobal();
}

/****************************************************************************/
/*    Interrupt Service Routine of the FTM0 counter overflow                */
/*! \Trace_To: HVAC_SCD_SYSTEM_0024#01,HVAC_SCD_SYSTEM_0025#01  */
/****************************************************************************/
extern void SysTickISR(void)
{
    /* Call of the Callback function */
    if(GPT_pfvideOSCallback!=NULL)
    {
       GPT_pfvideOSCallback();
    }
    else
    {

    }
    
}

/***************************************************************************/
/*    Interrupt Service Routine of the LPSPI0 master transfer              */
/*! \Trace_To: HVAC_SCD_SYSTEM_0026#01,HVAC_SCD_SYSTEM_0027#01  */
/***************************************************************************/
extern void SpiDstmISR(void)
{
    INT_SYS_DisableIRQGlobal();
    LPSPI2_IRQHandler();
    INT_SYS_EnableIRQGlobal();
}

/*****************************************************************************/
/* !Function     : HardFaultISR                                                 */
/* !Description  : Interrupt Service Routine of Hard fault interrupt         */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0028#01,HVAC_SCD_SYSTEM_0029#01  */
/*****************************************************************************/
extern void HardFaultISR(void)
{
    INT_SYS_DisableIRQGlobal();
    Reset_Handler();
    INT_SYS_EnableIRQGlobal();
}


/*****************************************************************************/
/* !Function     : AdcCoversionISR                                             */
/* !Description  : Interrupt Service Routine of ADC0 complete conversion     */
/*                    interrupt                                                 */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0032#01,HVAC_SCD_SYSTEM_0033#01  */
/*****************************************************************************/
extern void Adc0CoversionISR(void)
{
    INT_SYS_DisableIRQGlobal();
    ADC0_IRQHandler();
    INT_SYS_EnableIRQGlobal();
}

/*****************************************************************************/
/* !Function     : AdcCoversionISR                                             */
/* !Description  : Interrupt Service Routine of ADC0 complete conversion     */
/*                    interrupt                                                 */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0032#01,HVAC_SCD_SYSTEM_0033#01  */
/*****************************************************************************/
extern void Adc1CoversionISR(void)
{
    INT_SYS_DisableIRQGlobal();
    ADC1_IRQHandler();
    INT_SYS_EnableIRQGlobal();
}


/*****************************************************************************/
/* !Function     : CanBusOffISR                                                 */
/* !Description  : Interrupt Service Routine of CAN bus off                  */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0035#01,HVAC_SCD_SYSTEM_0036#01  */
/*****************************************************************************/
extern void CanBusOffISR(void)
{
    INT_SYS_DisableIRQGlobal();
    CAN0_ORed_IRQHandler();
    INT_SYS_EnableIRQGlobal();
}

/*****************************************************************************/
/* !Function     : CanMailBoxesISR                                             */
/* !Description  : Interrupt Service Routine of RX CAN mailboxes             */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0037#01,HVAC_SCD_SYSTEM_0038#01  */
/*****************************************************************************/
extern void CanMailBoxes0ISR(void)
{
    INT_SYS_DisableIRQGlobal();
    CAN0_ORed_0_15_MB_IRQHandler();
    INT_SYS_EnableIRQGlobal();
}

/*****************************************************************************/
/* !Function     : CanMailBoxesISR                                             */
/* !Description  : Interrupt Service Routine of RX CAN mailboxes             */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_0037#01,HVAC_SCD_SYSTEM_0038#01  */
/*****************************************************************************/
extern void CanMailBoxes1ISR(void)
{
    INT_SYS_DisableIRQGlobal();
    CAN0_ORed_16_31_MB_IRQHandler();
    INT_SYS_EnableIRQGlobal();
}

/*****************************************************************************/
/* !Function     : FTM3_ISR                                                     */
/* !Description  : Interrupt Service Routine of RX              */
/* !Trace_To     :                                                             */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_SYSTEM_1037#01,HVAC_SCD_SYSTEM_1038#01               */
/*****************************************************************************/
extern void FTM1Timeout_ISR(void)
{
    INT_SYS_DisableIRQGlobal();
    vidFTM1Isr();
    INT_SYS_EnableIRQGlobal();
}



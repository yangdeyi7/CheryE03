#include "DLin.h"
#include "Std_Types.h"
#include "lin_driver.h"
#include "pins_driver.h"
#include "lin_cfg.h"
#include "lin_common_api.h"
#include "interrupt_manager.h"
#include "flexTimer_mclin.h"
#include "ftm_mc_driver.h"
#include "ftm_hw_access.h"
#include "ftm_common.h"
#include "s32k144_dio.h"

/* (CLK (MHz)* timer period (us) / Prescaler) */
#define TIMER_COMPARE_VAL             (uint16)(2000U)
#define TIMER_TICKS_1US               (uint16)(4U)

uint16 timerOverflowInterruptCount = 0U;
volatile bool linEnabled = false;
volatile uint16 capturedValue = 0U;

static void vidFTM1Init(void);


/*!
 * @brief LPTMR Interrupt Service Routine
 * The ISR will call LIN timeout service every 500us
 */
extern void vidFTM1Isr(void)
{
    /* Static variable, used to count if the timeout has passed to
     * provide the LIN scheme tick.
     */
    static uint32_t interruptCount = 0UL;
    /* Timer Interrupt Handler */
    lin_lld_timeout_service(LI0);

    /* If 5 ms have passed, provide the required tick */
    if(++interruptCount == 10UL)
    {
        l_sch_tick(LI0);
        interruptCount = 0UL;
    }

    /* Increment overflow count */
    timerOverflowInterruptCount++;
    /* Clear compare flag */
    FTM_DRV_ClearStatusFlags(INST_FLEXTIMER_MCLIN,FTM_TIME_OVER_FLOW_FLAG);

}


/*!
 * @brief Callback function to get time interval in nano seconds
 * @param[out] ns - number of nanoseconds passed since the last call of the function
 * @return dummy value
 */
uint32_t lin1TimerGetTimeIntervalCallback0(uint32_t *ns)
{
    static uint32_t previousCountValue = 0U;
    uint32_t counterValue;
    
    counterValue = FTM_DRV_CounterRead(INST_FLEXTIMER_MCLIN);
    *ns = (uint32_t)(((counterValue + ((uint32_t)timerOverflowInterruptCount * (uint32_t)TIMER_COMPARE_VAL)) - previousCountValue) * 1000U) / (uint32_t)TIMER_TICKS_1US;
    timerOverflowInterruptCount = 0U;
    previousCountValue = counterValue;
    return 0U;
}



static void vidFTM1Init(void)
{
    static ftm_state_t ftmStateStruct;

    /* Initialize FlexTimer instance as LIN timer */
    (void) FTM_DRV_Init(INST_FLEXTIMER_MCLIN, &flexTimer_mclin_InitConfig, &ftmStateStruct);
    
}


/******************************************************************************/
/* !Description : lin component init                         */
/*                                                                            */
/* !Parameters: void                                                          */
/*                                                                            */
/* !Returns: - LBTY_OK : Initialization success                               */
/*           - LBTY_NOK: Initialization end with error                        */
/*                                                                            */
/* !Trace_To :                                                                */
/******************************************************************************/

void LIN_vidInit(void)
{
    vidFTM1Init();

    /*LIN Master init*/
#ifdef LIN_MASTER    
    l_sys_init();
    
    l_ifc_init(LI0);
     /* Set Schedule table to Normal */
    l_sch_set(LI0, LI0_Sch_Normal, 0u);
#else
    /*LIN slave init*/
    (void)l_ifc_init(LI0);
#endif
    DIO_vidWrite(DIO_u8DO_LIN1_EN, 1u);
}

/******************************************************************************/
/* !Description : lin component init                         */
/*                                                                            */
/* !Parameters: void                                                          */
/*                                                                            */
/* !Returns: - LBTY_OK : Initialization success                               */
/*           - LBTY_NOK: Initialization end with error                        */
/*                                                                            */
/* !Trace_To :                                                                */
/******************************************************************************/
void LIN_vidDeInit(void)
{
    lin_lld_deinit(LI0);
    FTM_DRV_Deinit(INST_FLEXTIMER_MCLIN);
}


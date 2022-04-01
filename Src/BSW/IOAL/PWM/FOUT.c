/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "FOUT.h"


/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/


/*!Comment: Total number of Timer modules output used                         */
#define u8NB_FOUT_HZ_DC_16BITS                                        ((uint8)3)


/*!Comment : Min /MAX Frequency output                                        */
#define u16BLW_PWM_MIN_FREQ_HZ                                     ((uint16)400)
#define u16BLW_PWM_MAX_FREQ_HZ                                     ((uint16)400)


/*!Comment : Min /MAX Frequency output                                        */
#define u16PWMOUT1_PWM_MIN_FREQ_HZ                                 ((uint16)500)
#define u16PWMOUT1_PWM_MAX_FREQ_HZ                                 ((uint16)500)


/*!Comment : Min /MAX Frequency output                                        */
#define u16PWMOUT2_PWM_MIN_FREQ_HZ                                 ((uint16)500)
#define u16PWMOUT2_PWM_MAX_FREQ_HZ                                 ((uint16)500)


/*!Comment : Initial output duty cycle value                                  */
#define u16INIT_DUTY_CYCLE                                      ((uint16)0x0000)



#define u8BLW_PWM_FTM_CHANNEL                                         ((uint8)1)
#define u8PWMOUT1_PWM_FTM_CHANNEL                                     ((uint8)3)
#define u8PWMOUT2_PWM_FTM_CHANNEL                                     ((uint8)1)




/******************************************************************************/
/* !Comment : Configuration of the PWM Generators for FOUT pins               */
/******************************************************************************/

/* !Comment : Number of count cycles of the Timer to produce 400 Hz frequency */
/* !Comment : Frequency is fixed for all frequency outputs                    */
/* !Comment : = Frequency of Timer's input clock  / Frequency of PWM signal   */
/* !Comment : = 16 MHz / 400 Hz                                               */
#define u16FREQUENCY_CNT_VALUE                                 ((uint16)0x8000U) //0x3900U)//0x1300)


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/



/*! \Trace_To:HVAC_SCD_IOAL_0124#01 */
/* !Comment : Structure that contains the Min and Max frequency for each FOUT */
typedef struct
{
    uint16  u16MinFreq;
    uint16  u16MaxFreq;
}tstrMinMaxFreq;


/******************************************************************************/
/* static VARIABLES                                                           */
/******************************************************************************/



/******************************************************************************/
/* !Comment : Min and Max frequencies for each FOUT ID                        */
/* !Comment : Array index = HWI Id , Array value = Min and Max frequency      */
/* !Comment : of the ID                                                       */
/******************************************************************************/
/* MISRA_Justification: for readability of configuration array  */
/* PRQA S 3218 2                                                */

/*! \Trace_To:HVAC_SCD_IOAL_0135#01 */
static const tstrMinMaxFreq akstrUdtMinMaxFreq[(uint8)u8NB_FOUT_HZ_DC_16BITS ] =
{
        /*!Comment: u16PWM_BLW                                                */
        {
                u16BLW_PWM_MIN_FREQ_HZ,
                u16BLW_PWM_MAX_FREQ_HZ
        },
        /*!Comment: u16PWMOUT1                                                */
        {
                u16PWMOUT1_PWM_MIN_FREQ_HZ,
                u16PWMOUT1_PWM_MAX_FREQ_HZ
        },
        /*!Comment: u16PWMOUT2                                               */
        {
                u16PWMOUT2_PWM_MIN_FREQ_HZ,
                u16PWMOUT2_PWM_MAX_FREQ_HZ
        },
		
};

/*! \Trace_To:HVAC_SCD_IOAL_0136#01 */
/*!Comment : Number of frequency outputs used                                 */
static uint8 FOUT_u8NumberOfOutputs = (uint8)0x00;

/******************************************************************************/
/* static FUNCTIONS PROTOTYPES                                                */
/******************************************************************************/

/******************************************************************************/
/* !Description : Output the PWM signal on the required pin with the required */
/* !Description : duty-cycle                                                  */
/******************************************************************************/
static void vidOutputPinPWM
(
        /*!Comment: Pin index in the DIN pins configuration array             */
        /*!Range: 0..u8NB_FOUT_HZ_DC_16BITS-1                                 */
        uint8 u8PinIndex,

        /*!Comment: Duty-Cycle of the required PWM signal                     */
        /*!Range: 0..1000                                                     */
        uint16 u16DutyCycle
);

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/* !Function    : FOUT_vidInit                                                */
/* !Description : Initialization routine for FOUT                             */
/*! \Trace_To    : HVAC_SCD_IOAL_0037#01,HVAC_SCD_IOAL_0094#01                 */
/******************************************************************************/
extern void FOUT_vidInit(void)
{
    static ftm_state_t ftmStateStruct;
    uint16 u16DutyCycle;

    FOUT_u8NumberOfOutputs = (uint8)u8NB_FOUT_HZ_DC_16BITS;

    /****************************************************************************/
    /* !Pseudo: Start timers                                                    */
    /****************************************************************************/
	/* Initialize FTM2	*/
	(void)FTM_DRV_Init(INST_FLEXTIMER_PWM_PWMOUT1_2, &flexTimer_pwm_PWMOUT1_2_InitConfig, &ftmStateStruct);
	(void)FTM_DRV_InitPwm(INST_FLEXTIMER_PWM_PWMOUT1_2, &flexTimer_pwm_PWMOUT1_2_PwmConfig);

    /* Initialize FTM3  */
    (void)FTM_DRV_Init(INST_FLEXTIMER_PWM_PWM_BLW, &flexTimer_pwm_PWM_BLW_InitConfig, &ftmStateStruct);
    (void)FTM_DRV_InitPwm(INST_FLEXTIMER_PWM_PWM_BLW, &flexTimer_pwm_PWM_BLW_PwmConfig);

    /****************************************************************************/
    /* !Pseudo: Set initial frequency and duty-cycle                            */
    /****************************************************************************/
    u16DutyCycle = 0u;
    (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWM_BLW, u8BLW_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16DutyCycle, 0u, true);
	(void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT1_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16DutyCycle, 0u, true);
	(void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT2_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16DutyCycle, 0u, true);
}


/******************************************************************************/
/* !Function    : FOUT_vidInit                                                */
/* !Description : Initialization routine for FOUT                             */
/*! \Trace_To    : HVAC_SCD_IOAL_0037#01,HVAC_SCD_IOAL_0094#01                 */
/******************************************************************************/
extern void FOUT_vidDeInit(void)
{
    FOUT_u8NumberOfOutputs = (uint8)u8NB_FOUT_HZ_DC_16BITS;
    /****************************************************************************/
    /* !Pseudo: Set initial frequency and duty-cycle                            */
    /****************************************************************************/
	/* DeInitialize FTM3  */    
    FTM_DRV_DeinitPwm(INST_FLEXTIMER_PWM_PWM_BLW);    
    FTM_DRV_Deinit(INST_FLEXTIMER_PWM_PWM_BLW);

    /* DeInitialize FTM2  */    
    FTM_DRV_DeinitPwm(INST_FLEXTIMER_PWM_PWMOUT1_2);
    FTM_DRV_Deinit(INST_FLEXTIMER_PWM_PWMOUT1_2);
}

/******************************************************************************/
/* !Function    : FOUT_vidDutyCycleInPer                                      */
/* !Description : Write the value of the frequency output in Hertz            */
/* !Description : and duty cycle 8 bits                                       */
/* Trace_To     : HVAC_SCD_IOAL_0095#03                                       */
/******************************************************************************/
extern void FOUT_vidDutyCycleInPer
(
        /*!Comment: FOUT_HZ_DC_16BITS identifier                              */
        /*!Range: 0..u8NB_FOUT_HZ_DC_16BITS-1                                 */
        uint8                             u8FOUTInHzDc16Id,
        /*!Comment: Frequency value                                           */
        /*!Range: Min_limit..Max_limit                                        */
        /*!Unit: Hertz                                                        */
        uint16                            u16FrequencyValue,
        /*!Comment: Duty cycle value                                          */
        /*!Range: 0..1000                                                     */
        uint16                            u16DutyCycleValue
)
{
    uint16 u16MinFrequency;
    uint16 u16MaxFrequency;
    /* array to save current duty to be compared with requested duty */
    static uint16 u16PrevDuty[u8NB_FOUT_HZ_DC_16BITS] = {(uint16)0};

    /*!Pseudo : Check if Req. ID is valid and new duty cycle is requested */
    if ((u8FOUTInHzDc16Id < (uint8)FOUT_u8NumberOfOutputs) &&
            (u16DutyCycleValue != u16PrevDuty[u8FOUTInHzDc16Id]))
    {
        /* read the min and max frequency for the PWM channel */
        u16MinFrequency = akstrUdtMinMaxFreq[u8FOUTInHzDc16Id].u16MinFreq;
        u16MaxFrequency = akstrUdtMinMaxFreq[u8FOUTInHzDc16Id].u16MaxFreq;

        /*!Pseudo   : if Duty cycle is equal 0                                   */
        if (u16DutyCycleValue == u16INIT_DUTY_CYCLE)
        {
            /*!pseudo   : set output to 0                                        */
            vidOutputPinPWM(u8FOUTInHzDc16Id, (uint16)0);
        }
        /*!Pseudo   : if DutyCycle equals 100%                                   */
        else if (u16DutyCycleValue >= (uint16)1000)
        {
            /*!pseudo   : set output to 1                                        */
            vidOutputPinPWM(u8FOUTInHzDc16Id, (uint16)1000);
        }
        else
        {
            /*!Pseudo : If frequency is in the allowed range                     */
            if ( (u16FrequencyValue >= u16MinFrequency)
                    && (u16FrequencyValue <= u16MaxFrequency) )
            {
                /*!Pseudo : Set the frequency and duty cycle                     */
                vidOutputPinPWM(u8FOUTInHzDc16Id, u16DutyCycleValue);
            }
            /*!Pseudo : If frequency is NOT in the allowed range                 */
            else
            {
                /* !Pseudo: Report Error using error module if it is configured  */

            }
        }

        /* save current duty cycle */
        u16PrevDuty[u8FOUTInHzDc16Id] = u16DutyCycleValue;
    }
    else
    {
        /* !Pseudo: Report Error using error module if it is configured          */
    }
}




/******************************************************************************/
/* static FUNCTIONS                                                           */
/******************************************************************************/

/******************************************************************************/
/* !Function    : vidOutputPinPWM                                             */
/* !Description : Output the PWM signal on the required pin with the required */
/* !Description : duty-cycle                                                  */
/* !Trace_To    : HVAC_SCD_IOAL_0121#02                                       */
/******************************************************************************/
static void vidOutputPinPWM
(
        /*!Comment: Pin index in the DIN pins configuration array             */
        /*!Range: 0..u8NB_FOUT_HZ_DC_16BITS-1                                 */
        uint8 u8PinIndex,

        /*!Comment: Duty-Cycle of the required PWM signal                     */
        /*!Range: 0..1000                                                     */
        uint16 u16DutyCycle
)
{
    uint32  u32CmpRegValue;
    uint16  u16Temp;
    uint32  u32Temp;

    /*!Pseudo: Set the value of the frequency counter                            */
    /*!Comment: Frequency Counter reload value = NB of cycles - 1 as the counter */
    /*!Comment: starts from 0                                                    */

    /*!Pseudo: If required duty-cycle is 0 then set the duty-cycle counter to 0  */
    if (u16DutyCycle == (uint16)0)
    {
        if(u8PinIndex == FOUT_u8PWM_BLW)
        {
            (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWM_BLW, u8BLW_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16DutyCycle, 0u, true);
        }
        else if (u8PinIndex == FOUT_u8PWM_PWMOUT1)
        {
             (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT1_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16DutyCycle, 0u, true);       
        }
        else if(u8PinIndex == FOUT_u8PWM_PWMOUT2)
        {
             (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT2_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16DutyCycle, 0u, true);      
        }
        else
        {
            /* Do nothing */
        }
    }
    /*!Pseudo: If required duty-cycle is 100 then set the duty-cycle counter to */
    /*!Pseudo: value of the frequency counter + 1                               */
    /*!Comment: ( u16FREQUENCY_CNT_VALUE + 1 ) - 1                              */
    else if (u16DutyCycle == (uint16)1000)
    {
        u16Temp = u16FREQUENCY_CNT_VALUE;

        if(u8PinIndex == FOUT_u8PWM_BLW)
        {
            (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWM_BLW, u8BLW_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16Temp, 0u, true);
        }
        else if (u8PinIndex == FOUT_u8PWM_PWMOUT1)
        {
             (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT1_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16Temp, 0u, true);       
        }
        else if(u8PinIndex == FOUT_u8PWM_PWMOUT2)
        {
             (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT2_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, u16Temp, 0u, true);      
        }
    }
    /*!Pseudo: else calculate the duty-cycle counter value                      */
    /*!Comment: Duty-cycle counter = Duty-cycle * Frequency Counter value       */
    /*!Comment:                      ------------------------------------       */
    /*!Comment:                                   0xFFFF                        */
    else
    {
        u32Temp =  (uint32)u16DutyCycle * (uint32)u16FREQUENCY_CNT_VALUE ;
        /*!Comment: + (0xFFFF/2) for rounding up in devision                        */
        u32CmpRegValue = u32Temp /(uint32)1000;

        if (u32CmpRegValue >= (uint32)u16FREQUENCY_CNT_VALUE)
        {
            /* !Comment: Report Error using error module if it is configured        */
        }
        else
        {
          if(u8PinIndex == FOUT_u8PWM_BLW)
          {
               (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWM_BLW, u8BLW_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, (uint16)u32CmpRegValue, 0u, true);
          }
          else if (u8PinIndex == FOUT_u8PWM_PWMOUT1)
          {
               (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT1_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, (uint16)u32CmpRegValue, 0u, true);       
          }
          else if(u8PinIndex == FOUT_u8PWM_PWMOUT2)
          {
               (void)FTM_DRV_UpdatePwmChannel(INST_FLEXTIMER_PWM_PWMOUT1_2, u8PWMOUT2_PWM_FTM_CHANNEL, FTM_PWM_UPDATE_IN_DUTY_CYCLE, (uint16)u32CmpRegValue, 0u, true);      
          }
        }
    }
}



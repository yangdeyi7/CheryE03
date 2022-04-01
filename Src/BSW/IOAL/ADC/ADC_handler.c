/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "ADC_handler.h"
#include "adc_pal1.h"
#include "adc_pal2.h"

/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/

#ifndef NULL_PTR
#define NULL_PTR  ((void *)0)
#endif
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/



/******************************************************************************/
/* static FUNCTIONS PROTOTYPES                                                */
/******************************************************************************/

/******************************************************************************/
/* static VARIABLES                                                           */
/******************************************************************************/


static ADC_tstrDynamicADCInfos ADC_astrADCDynInfos[ADC_u8NUM_CHNL];

/* Flag used to store if an ADC0 PAL conversion group0 has finished executing */
static boolean ADC0_bGroup1ConvDone = FALSE;

/* Flag used to store if an ADC1 PAL conversion group0 has finished executing */
//static boolean ADC1_bGroup0ConvDone = FALSE;

/* Flag used to store if an ADC1 PAL conversion group1 has finished executing */
static boolean ADC1_bGroup1ConvDone = FALSE;


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/*! \Trace_To:    HVAC_SCD_IOAL_0112#01                                        */
/* CallBack function from the MCAL layer used to set the conversion flag when Conversion finishes  */
void adc_pal1_callback00(const adc_callback_info_t * const callbackInfo, void * userData)
{
    ADC_StartGroupConversion(&adc_pal1_instance, (uint32_t)1);
}


/* CallBack function from the MCAL layer used to set the conversion flag when Conversion finishes  */
void adc_pal1_callback01(const adc_callback_info_t * const callbackInfo, void * userData)
{
    ADC0_bGroup1ConvDone = TRUE;
}


/* CallBack function from the MCAL layer used to set the conversion flag when Conversion finishes  */
void adc_pal2_callback00(const adc_callback_info_t * const callbackInfo, void * userData)
{
    ADC_StartGroupConversion(&adc_pal2_instance, (uint32_t)1);
}

/* CallBack function from the MCAL layer used to set the conversion flag when Conversion finishes  */
void adc_pal2_callback03(const adc_callback_info_t * const callbackInfo, void * userData)
{
    ADC1_bGroup1ConvDone = TRUE;
}

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/* !Function    : ADC_vidInit                                                 */
/* !Description : Initialize ADC port for asynchronous conversion with 10     */
/* !Description : bits resolution                                             */
/*! \Trace_To:    HVAC_SCD_IOAL_0013#02                                        */
/******************************************************************************/
extern void ADC_vidInit ( void )
{

    uint8 u8Index = (uint8)0;
    /* for loop to initialize the dynamic array sample index and first time average  */
    for (u8Index = (uint8)0; u8Index < ADC_u8NUM_CHNL; u8Index++)
    {
        ADC_astrADCDynInfos[u8Index].u8SampleCounter=(uint8)0;
        ADC_astrADCDynInfos[u8Index].ADC_bEmptyArrayAvg=TRUE;
    }


    /* Initialize the ADC0 pal and start the first conversion  */
    (void)ADC_Init(&adc_pal1_instance,&adc_pal1_InitConfig0);
    (void)ADC_StartGroupConversion (&adc_pal1_instance, (uint32_t)0);
    
    /* Initialize the ADC1 pal and start the first conversion  */
    (void)ADC_Init(&adc_pal2_instance,&adc_pal2_InitConfig0);
    (void)ADC_StartGroupConversion (&adc_pal2_instance, (uint32_t)0);

    

}

/******************************************************************************/
/* !Function    : ADC_vidDeInit                                                 */
/* !Description : Deinitialize ADC port for asynchronous conversion with 10     */
/* !Description : bits resolution                                             */
/*! \Trace_To:    HVAC_SCD_IOAL_0013#02                                        */
/******************************************************************************/
extern void ADC_vidDeInit(void)
{
    ADC_Deinit(&adc_pal1_instance);
    ADC_Deinit(&adc_pal2_instance);
}

/******************************************************************************/
/* !Function    : ADC_vidManage                                               */
/* !Description : Entry point for adc management                              */
/* !Description : stores the measured values and then restarts the            */
/* !Description : acquisition process                                         */
/*! \Trace_To:    HVAC_SCD_IOAL_0015#01                                        */
/******************************************************************************/
extern void ADC_vidManage ( void )
{
    uint8 u8SelectedGroupIndex;
    /* counter for the for loop  */
    uint8 u8Index = (uint8)0;

    /* Check if the group 0 and group 1 ADC0 finished conversion  */
    if(ADC1_bGroup1ConvDone == TRUE)
    {
        /* for loop to check on each channel of group0 */
        for (u8Index = (uint8)ADC1_u8GRUOP0_FIRST_CHNL; u8Index <= ADC1_u8GRUOP0_END_CHNL; u8Index++)
        {
            /* condition to allocate variables inside the ADC raw values array
             * it checks if the sample counter divided by the ADC sampling time is equal to zero */
            if( (ADC_astrADCDynInfos[u8Index].u8SampleCounter%
                    ADC_akstreData[u8Index].ADC_u8ADCSampleTime)==(uint8)0 )
            {
                ADC_akstreData[u8Index].ADC_u16ADCRawArray
                [ADC_astrADCDynInfos[u8Index].u8SampleCounter
                 /ADC_akstreData[u8Index].ADC_u8ADCSampleTime] = adc_pal2_Results00[ADC_akstreData[u8Index].ADC_u8ADCChannel];
            }
            else
            {
                /* Do Nothing */
            }

            /* increment sample index */
            ADC_astrADCDynInfos[u8Index].u8SampleCounter++;

            /* if the sample index is equal to the sample number multiplied by sample time
             * example if an ADC has 20 milliseconds sample time and 8 samples
             *  the index needs to be 16 before it resets and set the empty buffer flag to true */
            if( ADC_astrADCDynInfos[u8Index].u8SampleCounter
                    >= (ADC_akstreData[u8Index].ADC_u8ADCSampleNumber *
                            ADC_akstreData[u8Index].ADC_u8ADCSampleTime) )
            {
                ADC_astrADCDynInfos[u8Index].u8SampleCounter = (uint8)0;
                ADC_astrADCDynInfos[u8Index].ADC_bEmptyArrayAvg= FALSE;
            }
            else
            {
                /* Do Nothing */
            }

        }

        /* for loop to check on each channel of group1 */
        for (u8Index = (uint8)ADC1_u8GRUOP1_FIRST_CHNL; u8Index <= ADC1_u8GRUOP1_END_CHNL; u8Index++)
        {
            /* condition to allocate variables inside the ADC raw values array
             * it checks if the sample counter divided by the ADC sampling time is equal to zero */
            if( (ADC_astrADCDynInfos[u8Index].u8SampleCounter%
                    ADC_akstreData[u8Index].ADC_u8ADCSampleTime)==(uint8)0 )
            {
                ADC_akstreData[u8Index].ADC_u16ADCRawArray
                [ADC_astrADCDynInfos[u8Index].u8SampleCounter
                 /ADC_akstreData[u8Index].ADC_u8ADCSampleTime]=adc_pal2_Results03[ADC_akstreData[u8Index].ADC_u8ADCChannel];
            }
            else
            {
                /* Do Nothing */
            }

            /* increment sample index */
            ADC_astrADCDynInfos[u8Index].u8SampleCounter++;

            /* if the sample index is equal to the sample number multiplied by sample time
             * example if an ADC has 20 milliseconds sample time and 8 samples
             *  the index needs to be 16 before it resets and set the empty buffer flag to true */
            if( ADC_astrADCDynInfos[u8Index].u8SampleCounter
                    >= (ADC_akstreData[u8Index].ADC_u8ADCSampleNumber *
                            ADC_akstreData[u8Index].ADC_u8ADCSampleTime) )
            {
                ADC_astrADCDynInfos[u8Index].u8SampleCounter = (uint8)0;
                ADC_astrADCDynInfos[u8Index].ADC_bEmptyArrayAvg= FALSE;
            }
            else
            {
                /* Do Nothing */
            }

        }
        
        u8SelectedGroupIndex = 0u;

        /* reset the flag  */
        ADC1_bGroup1ConvDone = FALSE;
        /* Start the selected SW triggered group1 of conversions */
        (void)ADC_StartGroupConversion(&adc_pal2_instance, (uint32_t)u8SelectedGroupIndex);
    }
    else
    {
        /* Do Nothing */
    }

    /* Check if the group 0 and group 1 ADC0 finished conversion  */
    if(ADC0_bGroup1ConvDone == TRUE)
    {
        /* for loop to check on each channel of group0 */
        for (u8Index = (uint8)ADC0_u8GRUOP0_FIRST_CHNL; u8Index <= ADC0_u8GRUOP0_END_CHNL; u8Index++)
        {
            /* condition to allocate variables inside the ADC raw values array
             * it checks if the sample counter divided by the ADC sampling time is equal to zero */
            if( (ADC_astrADCDynInfos[u8Index].u8SampleCounter%
                    ADC_akstreData[u8Index].ADC_u8ADCSampleTime)==(uint8)0 )
            {
                ADC_akstreData[u8Index].ADC_u16ADCRawArray
                [ADC_astrADCDynInfos[u8Index].u8SampleCounter
                 /ADC_akstreData[u8Index].ADC_u8ADCSampleTime] = adc_pal1_Results00[ADC_akstreData[u8Index].ADC_u8ADCChannel];
            }
            else
            {
                /* Do Nothing */
            }

            /* increment sample index */
            ADC_astrADCDynInfos[u8Index].u8SampleCounter++;

            /* if the sample index is equal to the sample number multiplied by sample time
             * example if an ADC has 20 milliseconds sample time and 8 samples
             *  the index needs to be 16 before it resets and set the empty buffer flag to true */
            if( ADC_astrADCDynInfos[u8Index].u8SampleCounter
                    >= (ADC_akstreData[u8Index].ADC_u8ADCSampleNumber *
                            ADC_akstreData[u8Index].ADC_u8ADCSampleTime) )
            {
                ADC_astrADCDynInfos[u8Index].u8SampleCounter = (uint8)0;
                ADC_astrADCDynInfos[u8Index].ADC_bEmptyArrayAvg= FALSE;
            }
            else
            {
                /* Do Nothing */
            }

        }

        /* for loop to check on each channel of group1 */
        for (u8Index = (uint8)ADC0_u8GRUOP1_FIRST_CHNL; u8Index <= ADC0_u8GRUOP1_END_CHNL; u8Index++)
        {
            /* condition to allocate variables inside the ADC raw values array
             * it checks if the sample counter divided by the ADC sampling time is equal to zero */
            if( (ADC_astrADCDynInfos[u8Index].u8SampleCounter%
                    ADC_akstreData[u8Index].ADC_u8ADCSampleTime)==(uint8)0 )
            {
                ADC_akstreData[u8Index].ADC_u16ADCRawArray
                [ADC_astrADCDynInfos[u8Index].u8SampleCounter
                 /ADC_akstreData[u8Index].ADC_u8ADCSampleTime]=adc_pal1_Results01[ADC_akstreData[u8Index].ADC_u8ADCChannel];
            }
            else
            {
                /* Do Nothing */
            }

            /* increment sample index */
            ADC_astrADCDynInfos[u8Index].u8SampleCounter++;

            /* if the sample index is equal to the sample number multiplied by sample time
             * example if an ADC has 20 milliseconds sample time and 8 samples
             *  the index needs to be 16 before it resets and set the empty buffer flag to true */
            if( ADC_astrADCDynInfos[u8Index].u8SampleCounter
                    >= (ADC_akstreData[u8Index].ADC_u8ADCSampleNumber *
                            ADC_akstreData[u8Index].ADC_u8ADCSampleTime) )
            {
                ADC_astrADCDynInfos[u8Index].u8SampleCounter = (uint8)0;
                ADC_astrADCDynInfos[u8Index].ADC_bEmptyArrayAvg= FALSE;
            }
            else
            {
                /* Do Nothing */
            }

        }
        
        u8SelectedGroupIndex = 0u;

        /* reset the flag  */
        ADC0_bGroup1ConvDone = FALSE;
        /* Start the selected SW triggered group1 of conversions */
        (void)ADC_StartGroupConversion(&adc_pal1_instance, (uint32_t)u8SelectedGroupIndex);
    }
    else
    {
        /* Do Nothing */
    }
}



/******************************************************************************/
/* !Function    : ADC_bAsyncRead                                              */
/* !Description : Read the value of the ADC asynchronously and                */
/* !Description : returns it in 16 bits                                       */
/*! \Trace_To:    HVAC_SCD_IOAL_0017#02                                       */
/******************************************************************************/
/* !Comment: Value of the ADC                                                 */
/* !Range  : 0..1023                                                          */
/******************************************************************************/
extern boolean ADC_bAsyncRead
(
        /*!Comment: ADC16A identifier                                         */
        /*!Range: 0..MCAL_u8NB_ADC_16BITS_ASYNC-1                             */
        ADC_tenuChannelsId enuAdc16bitsAsyncId, uint16*  pu16DataRead
)
{
    uint8  u8Index;
    uint32 u32TempValue = (uint32)0;
    boolean bReadFinishFlag = FALSE;
    uint8 u8SampleIndex =0;
    /*!Pseudo : Check if the identifier is correct                            */

    /*!Pseudo : Get the moving average condition in normal conditions         */
    if ((pu16DataRead != NULL_PTR) && (enuAdc16bitsAsyncId < ADC_MAX_ENUM))
    {
        /*condition to calculate the moving average when the array is still not full */
        if (ADC_astrADCDynInfos[enuAdc16bitsAsyncId].ADC_bEmptyArrayAvg == TRUE)
        {
            if (ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleTime <= 1u)
            {
                u8SampleIndex = ADC_astrADCDynInfos[enuAdc16bitsAsyncId].u8SampleCounter
                    / ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleTime;
            }
			else
            {
                u8SampleIndex = ADC_astrADCDynInfos[enuAdc16bitsAsyncId].u8SampleCounter
                    / ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleTime+1u;
            }
            
            /*for loop on sample counter divided by sample time          */
            for (u8Index=(uint8)0; u8Index < u8SampleIndex
            /*(ADC_astrADCDynInfos[enuAdc16bitsAsyncId].u8SampleCounter
                    / ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleTime)*/
                    ; u8Index++)
            {
                /* add the values in the array inside the Temp variables  */
                u32TempValue +=(uint32) ADC_akstreData[enuAdc16bitsAsyncId].ADC_u16ADCRawArray[u8Index];
            }
            /* condition to ensure that there is no division by zero  */
            if ((ADC_astrADCDynInfos[enuAdc16bitsAsyncId].u8SampleCounter
                    /ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleTime ) > (uint8)0)
            {
                u32TempValue = (uint32) (u32TempValue /(uint32)u8SampleIndex
                        /*(((uint32)ADC_astrADCDynInfos[enuAdc16bitsAsyncId].u8SampleCounter
                        /(uint32)ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleTime)+1u)*/) ;
                /* condition to ensure that there is no division by zero  */
                *pu16DataRead  = (uint16)u32TempValue;
                bReadFinishFlag=(boolean)TRUE;
            }
            else
            {
                *pu16DataRead  = ADC_akstreData[enuAdc16bitsAsyncId].ADC_u16ADCRawArray[0];
                bReadFinishFlag=(boolean)TRUE;
            }

        }
        /* if not the first time calculate the moving average normally */
        else
        {
            /* for loop to add all the values inside the raw variable array   */
            for (u8Index=(uint8)0; (u8Index < ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleNumber) ; u8Index++)
            {
                u32TempValue += (uint32) ADC_akstreData[enuAdc16bitsAsyncId].ADC_u16ADCRawArray[u8Index];
            }

            u32TempValue = u32TempValue / (uint32)ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCSampleNumber;
            *pu16DataRead  = (uint16)u32TempValue;
            bReadFinishFlag=TRUE;
        }
    }
    else
    {
        /* Do Nothing */
    }

    return (bReadFinishFlag);
}


/*!Comment: This function is provided here to get the value in uint16 format */
/*! \Trace_To:    HVAC_SCD_IOAL_0019#01                                        */

extern uint16 ADC_u16Read(
        /*!Comment: ADC16A identifier                                               */
        /*!Range: 0..MCAL_u8NB_ADC_16BITS_ASYNC-1                                    */
        ADC_tenuChannelsId enuAdc16bitsAsyncId
)
{
    uint16  u16DataRead=0u;
    /*!Check if the input ID is valid*/
    if(enuAdc16bitsAsyncId<ADC_MAX_ENUM )
    {
        (void)ADC_bAsyncRead(enuAdc16bitsAsyncId,&u16DataRead);
    }
    else{
        /*!Do Nothing*/
    }
    return(u16DataRead);
}


/*!Comment: This function is provided to the sensors with the current pressure value*/
/*! \Trace_To:    HVAC_SCD_IOAL_0021#02                                        */

extern uint16 ADC_u16CurrentADCReading(ADC_tenuChannelsId enuAdc16bitsAsyncId)
{
    uint16  u16DataRead=0u;
    /*!Check if the input ID is valid*/
    if(enuAdc16bitsAsyncId<=ADC0_u8GRUOP0_END_CHNL )
    {
        /*!Comment: get the current pressure value by dividing the sample counter by sample time*/
        u16DataRead = adc_pal1_Results00
               [ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCChannel];
    }
    else if(enuAdc16bitsAsyncId<=ADC0_u8GRUOP1_END_CHNL)
    {
        /*!Comment: get the current pressure value by dividing the sample counter by sample time*/
        u16DataRead = adc_pal1_Results01
               [ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCChannel];
    }else if(enuAdc16bitsAsyncId <= ADC1_u8GRUOP0_END_CHNL)
    {
        /*!Comment: get the current pressure value by dividing the sample counter by sample time*/
        u16DataRead = adc_pal2_Results00
               [ADC_akstreData[enuAdc16bitsAsyncId].ADC_u8ADCChannel];
    }else
    {
        /*!Do Nothing*/
    }
    return(u16DataRead);

}

/******************************************************************************/
/* !Function    : ADC_vidClearBuffer                                              */
/* !Description : allow buffer to be cleared                */
/* !Description : void                                      */
/*! \Trace_To:    HVAC_SCD_IOAL_0221#01                                          */
/******************************************************************************/
extern void ADC_vidClearBuffer(ADC_tenuChannelsId enuAdc16bitsAsyncId)
{
    /*!Check if the input is valid */
    if(enuAdc16bitsAsyncId < ADC_MAX_ENUM )
    {
        /*!Reset the flag and sample counter */
        ADC_astrADCDynInfos[enuAdc16bitsAsyncId].ADC_bEmptyArrayAvg = TRUE;
        ADC_astrADCDynInfos[enuAdc16bitsAsyncId].u8SampleCounter = 0u;
    }
    else
    {
        /*!Do Nothing*/
    }

}

/******************************************************************************/
/* !Function    : ADC_SetConverFinishFlg                                       */
/* !Description : set the adc conversion finish flag, used by other file       */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern void ADC_SetADC0ConverFinishFlg(boolean set)
{
    ADC0_bGroup1ConvDone = set;
}


/******************************************************************************/
/* !Function    : ADC_GetConverFinishFlg                                       */
/* !Description : Get the adc conversion finish flag, used by other file        */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern boolean ADC_GetADC0ConverFinishFlg(void)
{
    return ADC0_bGroup1ConvDone;
}


/******************************************************************************/
/* !Function    : ADC_SetConverFinishFlg                                       */
/* !Description : set the adc conversion finish flag, used by other file       */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern void ADC_SetADC1ConverFinishFlg(boolean set)
{
    ADC1_bGroup1ConvDone = set;
}


/******************************************************************************/
/* !Function    : ADC_GetConverFinishFlg                                       */
/* !Description : Get the adc conversion finish flag, used by other file        */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern boolean ADC_GetADC1ConverFinishFlg(void)
{
    return ADC1_bGroup1ConvDone;
}


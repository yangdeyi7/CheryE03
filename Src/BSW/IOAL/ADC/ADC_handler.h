/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/

#ifndef ADC_HANDLER_H
#define ADC_HANDLER_H


/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

#include "ADC_cnfg.h"

/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/* Dynamic structure to hold the current counter for each ADC channel and the empty buffer flag*/
typedef struct
{
      uint8     u8SampleCounter;
      boolean   ADC_bEmptyArrayAvg;
}ADC_tstrDynamicADCInfos;


/******************************************************************************/
/* GLOBAL FUNCTIONS                                                           */
/******************************************************************************/

/******************************************************************************/
/* !Function    : ADC_vidInit                                                 */
/* !Description : Initialize ADC port for asynchronous conversion with 10     */
/* !Description : bits resolution                                             */
/*! \Trace_To:    HVAC_SCD_IOAL_0012#01                                        */
/******************************************************************************/
extern void ADC_vidInit ( void );

/******************************************************************************/
/* !Function    : ADC_vidDeInit                                                 */
/* !Description : Deinitialize ADC port for asynchronous conversion with 10     */
/* !Description : bits resolution                                             */
/*! \Trace_To:    HVAC_SCD_IOAL_0013#02                                        */
/******************************************************************************/
extern void ADC_vidDeInit(void);


/******************************************************************************/
/* !Function    : ADC_vidManage                                               */
/* !Description : Entry point for ADC management                              */
/* !Description : stores the measured values and then restarts the            */
/* !Description : acquisition process                                         */
/*! \Trace_To:    HVAC_SCD_IOAL_0014#01                                        */
/******************************************************************************/
extern void ADC_vidManage ( void );


/******************************************************************************/
/* !Function    : ADC_bAsyncRead                                              */
/* !Description : Read the value of the ADC asynchronously and                */
/* !Description : returns it in 10 bits                                       */
/*! \Trace_To:    HVAC_SCD_IOAL_0016#01                                        */
/******************************************************************************/
/* !Comment: Value of the ADC channel ID                                      */
/* !Range  : 0..6                                                             */
/******************************************************************************/
extern boolean ADC_bAsyncRead(ADC_tenuChannelsId enuAdc16bitsAsyncId,uint16*  pu16DataRead);


/******************************************************************************/
/* !Function    : ADC_u16CurrentAdcReading                                    */
/* !Description : Read the current ADC value                                  */
/* !Description : returns it in 10 bits                                       */
/*! \Trace_To:    HVAC_SCD_IOAL_0018#01                                        */
/******************************************************************************/
extern uint16 ADC_u16CurrentADCReading(ADC_tenuChannelsId enuAdc16bitsAsyncId);



/*!Comment: This function is provided here to interface with the COTS         */
/*! \Trace_To:    HVAC_SCD_IOAL_0020#01                                        */

extern uint16 ADC_u16Read(/*!Comment: ADC16A identifier                       */
  /*!Range: 0..MCAL_u8NB_ADC_16BITS_ASYNC-1                                    */
  ADC_tenuChannelsId enuAdc16bitsAsyncId
  );

/******************************************************************************/
/* !Function    : ADC_vidClearBuffer                                          */
/* !Description : Clear the ADC buffer                                        */
/* !Description : returns it in 10 bits                                       */
/*! \Trace_To:      HVAC_SCD_IOAL_0220#01                                        */
/******************************************************************************/
extern void ADC_vidClearBuffer(ADC_tenuChannelsId enuAdc16bitsAsyncId);

/******************************************************************************/
/* !Function    : ADC_SetConverFinishFlg                                       */
/* !Description : set the adc conversion finish flag, used by other file       */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern void ADC_SetADC0ConverFinishFlg(boolean set);

/******************************************************************************/
/* !Function    : ADC_GetConverFinishFlg                                       */
/* !Description : Get the adc conversion finish flag, used by other file        */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern boolean ADC_GetADC0ConverFinishFlg(void);

/******************************************************************************/
/* !Function    : ADC_SetConverFinishFlg                                       */
/* !Description : set the adc conversion finish flag, used by other file       */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern void ADC_SetADC1ConverFinishFlg(boolean set);

/******************************************************************************/
/* !Function    : ADC_GetConverFinishFlg                                       */
/* !Description : Get the adc conversion finish flag, used by other file        */
/* !Description : void                                      */
/*! \Trace_To:                                            */
/******************************************************************************/
extern boolean ADC_GetADC1ConverFinishFlg(void);


#endif /* ADC_H */


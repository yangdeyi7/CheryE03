/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "s32k144_DIO.h"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/*! \Trace_To: HVAC_SCD_IOAL_0113#01 */
/*!Comment: Din pin descriptor                                                */
typedef struct
{
  /*!Comment: Pin index in the DIN pins configuration array                   */
      GPIO_Type * ptru32DINPortAdd;
  /*!Comment: Pin index in the DOUT pins configuration array                  */
  /*!Range: 0..DIO_u8NUM_OF_OUTPUTS-1                                         */
      uint8 u8PinIndex;
} tstrDIOPortPin;

/*! \Trace_To: HVAC_SCD_IOAL_0114#01 */
typedef struct
{
  /* !Comment: Pointer to a PMC register of the pin                           */
  volatile uint8* const kpvu8PortModeCtrlReg;
  /* !Comment: Pointer to a PM register of the pin                            */
  volatile uint8* const kpvu8PortModeReg;
  /* !Comment: Pointer to a P register of the pin                             */
  volatile uint8* const kpvu8PortDataReg;
  /* !Comment: Mask for the pin position in the configuration registers       */
  const uint8 ku8PinIndex;
  /* !Comment: The default value of the pin                                   */
  const uint8 ku8DefaultValue;
} tstrDOUTData;

/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/


/******************************************************************************/
/* static VARIABLES                                                           */
/******************************************************************************/


/*!Comment: Digital input pins configuration structure */
/*! \Trace_To: HVAC_SCD_IOAL_0116#01 */
static const tstrDIOPortPin akstrDinData[DIO_u8NB_DIN] =
{
    /*!Comment:   DIO_u8CAN1_ERROR                          */
    {PTE,11u},
	/*!Comment:   DIO_u8IN1                                 */
	{PTD,7u},
	/*!Comment:   DIO_u8IN2                                 */
	{PTD,6u},
    /*!Comment:   DIO_u8IN3                                 */
	{PTB,4u},
};


/*!Comment: Digital output pins configuration structure                       */
/*! \Trace_To: HVAC_SCD_IOAL_0133#01 */
static const tstrDIOPortPin akstrDoutData[DIO_u8NUM_OF_OUTPUTS] =
{
    /*!Comment: DIO_u8WDG                                 */
    {PTE,8u},
    /*!Comment: DIO_SPI_CS1                                 */
    {PTD,1u},
    /*!Comment: DIO_SPI_CS2                                  */
    {PTD,0u},
    /*!Comment: DIO_u8DO_CAN1_STB                              */
    {PTE,10u},
    /*!Comment: DIO_u8DO_CAN2_STB                              */
    {PTA,14u},
    /*!Comment: DIO_u8DO_CAN1_EN                               */
    {PTE,13u},
    /*!Comment: DIO_u8DO_LIN1_EN                               */
    {PTD,16u},
    /*!Comment: DIO_u8DO_LIN2_EN                               */
    {PTE,9u},
    /*!Comment: DIO_u8DO_LIN3_EN                               */
    {PTC,11u},
};
/*! \Trace_To: HVAC_SCD_IOAL_0115#01 */
/*!Comment : Number of digital input used                  */
/*static uint8 DIO_u8NumberOfInputs = (uint8)DIO_u8NB_DIN;*/

/******************************************************************************/
/* static FUNCTIONS PROTOTYPES                                                */
/******************************************************************************/

/******************************************************************************/
/* !Description : Read the current level of the required digital input pin    */
/******************************************************************************/
/*! \Trace_To: HVAC_SCD_IOAL_0131#01 */
static uint8 u8ReadInputPin
(
  /*!Comment: Pin index in the DIN pins configuration array                   */
  const GPIO_Type * ptru32DINPortAdd,

  /*!Comment: Pin index in the DIN pins configuration array                   */
  /*!Range: 0..MCAL_u8NB_DIN-1                                                */
  uint8 u8PinIndex
);


/******************************************************************************/
/* !Description : Write the the required value on the digital output pin      */
/******************************************************************************/
/*! \Trace_To: HVAC_SCD_IOAL_0132#01 */
static void vidWriteOnOutputPin
(
  /*!Comment: Pin index in the DIN pins configuration array                   */
  GPIO_Type * ptru32DINPortAdd,

  /*!Comment: Pin index in the DOUT pins configuration array                  */
  /*!Range: 0..DIO_u8NUM_OF_OUTPUTS-1                                         */
  uint32 u32PinIndex,

  /*!Comment: value to output on the pin                                      */
  /*!Range: 0..1                                                              */
  uint8 u8Value
);


/******************************************************************************/
/* EXPORTED FUNCTIONS                                                         */
/******************************************************************************/

/******************************************************************************/
/* !Function      : DIO_vidInit                                               */
/* !Description   : Initialization routine for HWI DIO                        */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    void                                                   */
/* !Comment       :                                                           */
/* !Range         :                                                           */
/* !Return        : void                                                       */
/* !Range         :                                                           */
/*!Trace_To       : HVAC_SCD_IOAL_0023#01,HVAC_SCD_IOAL_0064#01 */
/******************************************************************************/
extern void DIO_vidInit
(
    /*!Comment: Detected PCB variant                                          */
    /*!Range  : 0..1                                                          */

    void
)
{
    /* Initialize pins
     *  -   See PinSettings component for more info
     */
    (void) PINS_DRV_Init((uint32_t)NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
    DIO_vidWrite(DIO_u8DO_LIN1_EN, 1u);
    
}


/******************************************************************************/
/* !Function      : DIO_vidRefreshPorts                                       */
/* !Description   : Refresh I/O ports initialization and initialize           */
/*                    unused pins    as input                                 */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    void                                                   */
/* !Comment       :                                                           */
/* !Range         :                                                           */
/* !Return        : void                                                      */
/* !Range         :                                                           */
/*!Trace_To       : HVAC_SCD_IOAL_0065#01,HVAC_SCD_IOAL_0066#01 */
/******************************************************************************/
extern void DIO_vidRefreshPorts(void)
{
    /* refresh configuration of all used pins and configure
     * unused pins as input */
#if 0
    /* refresh PORT A */
    PINS_DRV_SetPinsDirection(PTA, (pins_channel_type_t)DIO_PORTA_PINS_DIRECTION_MASK);

    /* refresh PORT B */
    PINS_DRV_SetPinsDirection(PTB, (pins_channel_type_t)DIO_PORTB_PINS_DIRECTION_MASK);

    /* refresh PORT C */
    PINS_DRV_SetPinsDirection(PTC, (pins_channel_type_t)DIO_PORTC_PINS_DIRECTION_MASK);

    /* refresh PORT D */
    PINS_DRV_SetPinsDirection(PTD, (pins_channel_type_t)DIO_PORTD_PINS_DIRECTION_MASK);

    /* refresh PORT E */
    PINS_DRV_SetPinsDirection(PTE, (pins_channel_type_t)DIO_PORTE_PINS_DIRECTION_MASK);
#endif
}/* End of DIO_vidUnusedIOInit(void) */

/******************************************************************************/
/* !Function      : DIO_u8DinRead                                             */
/* !Description   : Read a value of a digital input                           */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    u8DOUTIdentifier                                          */
/* !Comment       : Value of the DIN                                          */
/* !Range         : 0..DIO_u8NB_DIN-1                                         */
/* !Return        : void                                                       */
/* !Range         :                                                           */
/*!Trace_To       : HVAC_SCD_IOAL_0024#01,HVAC_SCD_IOAL_0067#01 */
/******************************************************************************/
extern uint8 DIO_u8DinRead
(
    /*!Comment: Pin index in the DIN pins configuration array                 */
    uint8 u8DINIdentifier
)
{
  uint8 u8Result = (uint8)0;

  /* Determine the level of PUSH_RECI by reading and ORing the values on
           pins P55 and P54 ( if P55 or P54 is pressed, then the PUSH_RECI is
           considered pressed                                                 */
  if(u8DINIdentifier < DIO_u8NB_DIN)
  {

      u8Result = (uint8)u8ReadInputPin(
              akstrDinData[u8DINIdentifier].ptru32DINPortAdd,
              akstrDinData[u8DINIdentifier].u8PinIndex);
  }
  /* !Pseudo: The result is an error value                                    */
  return u8Result;
}


/******************************************************************************/
/* !Function      : DIO_vidWrite                                              */
/* !Description   : Write a value of a logical output                         */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    u8DOUTIdentifier                                          */
/* !Comment       : Pin index in the DIN pins configuration array             */
/* !Range         : 0..DIO_u8NUM_OF_OUTPUTS (14)                              */
/* !Parameters[in]:    u8Value                                                   */
/* !Comment       : value to output on the pin                                */
/* !Range         : 0..1                                                      */
/* !Return        : void                                                       */
/* !Range         :                                                           */
/*!Trace_To       : HVAC_SCD_IOAL_0025#01,HVAC_SCD_IOAL_0070#01 */
/******************************************************************************/
extern void DIO_vidWrite
(
    /*!Comment: Pin index in the DIN pins configuration array                 */
    uint8 u8DOUTIdentifier,
    /*!Comment: value to output on the pin                                    */
    /*!Range: 0..1                                                            */
    uint8 u8Value
)
{
    if(u8DOUTIdentifier < DIO_u8NUM_OF_OUTPUTS)
    {
        /*!Pseudo: Check if output value is 0 or 1                            */
        if (u8Value <= (uint8)1)
        {
            /*!Pseudo: Write the output value on the pin                      */
            vidWriteOnOutputPin(akstrDoutData[u8DOUTIdentifier].ptru32DINPortAdd,
                                akstrDoutData[u8DOUTIdentifier].u8PinIndex,
                                u8Value);
        }
        else
        {
            /* !Pseudo: Report Error using error module if it is configured   */
        }
    }
}

/******************************************************************************/
/* !Function      : u8ReadInputPin                                            */
/* !Description   : Read the current level of the required digital input pin  */
/* !Trace_To      :                                                           */
/* !Parameters[in]:                                                              */
/* !Comment       : Value of the required digital input pin                   */
/* !Range         : 0..1                                                      */
/* !Return        : void                                                       */
/* !Range         :                                                           */
/******************************************************************************/
/* !Trace_To: HVAC_SCD_IOAL_0131#01 */
static uint8  u8ReadInputPin
(
 /*!Comment: Pin index in the DIN pins configuration array                    */
  const GPIO_Type * ptru32DINPortAdd,
  /*!Comment: Pin index in the DIN pins configuration array                   */
  /*!Range: 0..MCAL_u8NB_DIN-1                                                */
  uint8 u8PinIndex
)
{
    uint8 u8Result;
    uint32 u32Temp;
    /*!Pseudo: Read the Port Data register (Pn) of the pin to determine
               it level                                                       */
    u32Temp = (uint32)PINS_DRV_ReadPins(ptru32DINPortAdd);
    u8Result= (uint8)((u32Temp >> (uint32)u8PinIndex ) & 1u);
    /*!Pseudo: Return the current level of the pin                            */
    return u8Result;
}

/******************************************************************************/
/* !Function      : vidWriteOnOutputPin                                       */
/* !Description   : Write the the required value on the digital output pin    */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    ptru32DINPortAdd                                          */
/* !Comment       : port ID address                                           */
/* !Range         : PTA, PTB, PTC, PTD, PTE                                   */
/* !Parameters[in]:    u32PinIndex                                                  */
/* !Comment       : Pin index in the DOUT pins configuration array            */
/* !Range         : 0..DIO_u8NUM_OF_OUTPUTS-1                                 */
/* !Parameters[in]:    u8Value                                                    */
/* !Comment       : value to output on the pin                                */
/* !Range         : 0..1                                                      */
/* !Return        : void                                                       */
/* !Range         :                                                           */
/* !Trace_To: HVAC_SCD_IOAL_0132#01 */
/******************************************************************************/
static void vidWriteOnOutputPin
(
  /*!Comment: Pin index in the DIN pins configuration array                   */
  GPIO_Type * ptru32DINPortAdd,
  /*!Comment: Pin index in the DOUT pins configuration array                  */
  /*!Range: 0..DIO_u8NUM_OF_OUTPUTS-1                                         */
  uint32 u32PinIndex,
  /*!Comment: value to output on the pin                                      */
  /*!Range: 0..1                                                              */
  uint8 u8Value
)
{
    /*!Pseudo: Write the required value in Port Data register (Pn) of the pin */
    PINS_DRV_WritePin(ptru32DINPortAdd,
             (uint32_t)u32PinIndex,
                      u8Value);
}


/******************************************************************************/
/* !Function      : DIO_vidDeInit                                               */
/* !Description   : DeInitialization routine for HWI DIO                        */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    void                                                        */
/* !Comment       :                                                           */
/* !Range         :                                                           */
/* !Return        : void                                                       */
/* !Range         :                                                           */
/*!Trace_To       : HVAC_SCD_IOAL_0023#01,HVAC_SCD_IOAL_0064#01 */
/******************************************************************************/
extern void DIO_vidDeInit(void)
{

}


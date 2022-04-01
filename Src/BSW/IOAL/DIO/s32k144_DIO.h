#ifndef S32k144_DIO_H
#define S32k144_DIO_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "pin_mux.h"

/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/
/*! \Trace_To: HVAC_SCD_IOAL_0022#01 */
/*!Description: Number of input pins                                           */
#define DIO_u8NB_DIN                        ((uint8)4)

/*!Description: Number of used pins                                            */
//#define DIO_u8NU_USED_PINS                ((uint8)9)

/*!Description: Number of output pins                                          */
#define DIO_u8NUM_OF_OUTPUTS                ((uint8)9)

/*!Description  Set output Direction                                           */
#define DIO_u8DDR_OUT                       ((uint8)0)

/*!Description  Set input Direction                                            */
#define DIO_u8DDR_IN                        ((uint8)1)

/*!Description  Set input disable                                              */
#define DIO_u8IN_DISABLE                    ((uint8)0)

/*!Description  Set input enable                                               */
#define DIO_u8IN_ENABLE                     ((uint8)1)


/******************************* Digital Input ID *****************************/
#define DIO_u8CAN1_ERROR                    0u
#define DIO_u8IN1                           1u
#define DIO_u8IN2                           2u
#define DIO_u8IN3                           3u

/**************************** Digital Output ID *******************************/                            
#define DIO_u8WDG                           0u
#define DIO_SPI_CS1                         1u
#define DIO_SPI_CS2                         2u
#define DIO_u8DO_CAN1_STB                   3u
#define DIO_u8DO_CAN2_STB                   4u
#define DIO_u8DO_CAN1_EN                    5u
#define DIO_u8DO_LIN1_EN                    6u
#define DIO_u8DO_LIN2_EN                    7u
#define DIO_u8DO_LIN3_EN                    8u

/**************************** Ports direction masks ***************************/
/* !PORTA pins direction mask                                                   */
#define DIO_PORTA_PINS_DIRECTION_MASK        //((uint32_t)0x00000300)

/* !PORTB pins direction mask                                                   */
#define DIO_PORTB_PINS_DIRECTION_MASK        //((uint32_t)0x00000021)

/* !PORTC pins direction mask                                                   */
#define DIO_PORTC_PINS_DIRECTION_MASK        //((uint32_t)0x00000008)

/* !PORTD pins direction mask                                                   */
#define DIO_PORTD_PINS_DIRECTION_MASK        //((uint32_t)0x00000023)

/* !PORTE pins direction mask                                                   */
#define DIO_PORTE_PINS_DIRECTION_MASK        //((uint32_t)0x0000A300)


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* !Function      : DIO_vidInit                                               */
/* !Description   : Initialization routine for HWI DIO                        */
/* !Trace_To      : HVAC_SCD_IOAL_0023#01                                     */
/* !Parameters[in]:    void                                                    */
/* !Comment       :                                                           */
/* !Range         :                                                           */
/* !Return        : void                                                       */
/* !Range         :                                                           */
/******************************************************************************/
extern void DIO_vidInit( void );



/******************************************************************************/
/* !Function      : DIO_vidRefreshPorts                                       */
/* !Description   : Initialization routine for Unused Pins                    */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    void                                                   */
/* !Comment       :                                                           */
/* !Range         :                                                           */
/* !Return        : void                                                      */
/* !Range         :                                                           */
/******************************************************************************/
extern void DIO_vidRefreshPorts( void );

/******************************************************************************/
/* !Function      : DIO_u8DinRead                                             */
/* !Description   : Read a value of a digital input                           */
/* !Trace_To      : HVAC_SCD_IOAL_0024#01                                     */
/* !Parameters[in]:    u8DOUTIdentifier                                       */
/* !Comment       : Value of the DIN                                          */
/* !Range         : 0..DIO_u8NB_DIN-1                                         */
/* !Return        : void                                                      */
/* !Range         :                                                           */
/******************************************************************************/
extern uint8 DIO_u8DinRead (uint8 u8DINIdentifier);

/******************************************************************************/
/* !Function      : DIO_vidWrite                                              */
/* !Description   : Write a value of a logical output                         */
/* !Trace_To      : HVAC_SCD_IOAL_0025#01                                     */
/* !Parameters[in]:    u8DOUTIdentifier                                       */
/* !Comment       : Pin index in the DIN pins configuration array             */
/* !Range         : 0..DIO_u8NUM_OF_OUTPUTS (14)                              */
/* !Parameters[in]:    u8Value                                                */
/* !Comment       : value to output on the pin                                */
/* !Range         : 0..1                                                      */
/* !Return        : void                                                      */
/* !Range         :                                                           */
/******************************************************************************/
extern void DIO_vidWrite (uint8 u8DOUTIdentifier, uint8 u8DOUTValue);

/******************************************************************************/
/* !Function      : DIO_vidDeInit                                             */
/* !Description   : DeInitialization routine for HWI DIO                      */
/* !Trace_To      :                                                           */
/* !Parameters[in]:    void                                                   */
/* !Comment       :                                                           */
/* !Range         :                                                           */
/* !Return        : void                                                      */
/* !Range         :                                                           */
/*!Trace_To       : HVAC_SCD_IOAL_0023#01,HVAC_SCD_IOAL_0064#01 */
/******************************************************************************/
extern void DIO_vidDeInit(void);

#endif

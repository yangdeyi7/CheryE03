/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "CanTrcv.h"
#include "s32k144_Dio.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

extern void CanTrcv_vidTrcvInitFct(void)
{
    /* set the enable port to low */
    DIO_vidWrite(DIO_u8DO_CAN1_EN, STD_LOW);
    /* set the standby port to low */
    DIO_vidWrite(DIO_u8DO_CAN1_STB, STD_LOW);
    /* Switch the transceiver to NORMAL mode */
    /* wait the specific time for a stable wake port level */
    NOP();
    /* set the enable port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_EN, STD_HIGH);
    /* set the standby port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_STB, STD_HIGH);
}

extern void CanTrcv_vidWakeUpTrcvFct(void)
{
    /* set the enable port to low */
    DIO_vidWrite(DIO_u8DO_CAN1_EN, STD_LOW);
    /* set the standby port to low */
    DIO_vidWrite(DIO_u8DO_CAN1_STB, STD_LOW);
    /* Switch the transceiver to NORMAL mode */
    /* wait the specific time for a stable wake port level */
    NOP();
    /* set the enable port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_EN, STD_HIGH);
    /* set the standby port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_STB, STD_HIGH);

}

extern void CanTrcv_vidSleepTrcvFct(void)
{
    /* set the enable port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_EN, STD_HIGH);
    /* set the standby port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_STB, STD_HIGH);
    /* wait the specific time for a stable wake port level */
    NOP();
    /* set the enable port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_EN, STD_HIGH);
    /* set the standby port to high */
    DIO_vidWrite(DIO_u8DO_CAN1_STB, STD_LOW);
}

extern void CanTrcv_vidStdByTrcvFct(void)
{
    /* Switch the transceiver to STANDBY mode */
    /* set the standby port to low */
    DIO_vidWrite(DIO_u8DO_CAN1_STB, STD_LOW);
}

/*-------------------------------- end of file -------------------------------*/

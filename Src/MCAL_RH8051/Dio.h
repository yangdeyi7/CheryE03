/******************************************************************************/
/* PROJECT  :    CHJ_D01                                                      */
/******************************************************************************/
/* !Layer           : Dio                                                     */
/*                                                                            */
/* !Component       : Dio                                                     */
/* !Description     : Managing digital inputs and outputs peripherals         */
/*                                                                            */
/* !Module          : Dio                                                     */
/* !Description     : Dio                                                     */
/*                                                                            */
/* !File            : Dio.h                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/******************************************************************************/
#ifndef DIO_H
#define DIO_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Port.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/*output*/
#define    DIO_u8OUT_WDG            0u
#define    DIO_u8OUT_EEP_CS         1u
#define    DIO_u8OUT_EEP_WP         2u
#define    DIO_u8OUT_E910_DR1_EN    3u
#define    DIO_u8OUT_E910_DR2_EN    4u
#define    DIO_u8OUT_E910_DR3_EN    5u
#define    DIO_u8OUT_E910_DR4_EN    6u
#define    DIO_u8OUT_E910_RST       7u
#define    DIO_u8OUT_LIN_EN         8u
#define    DIO_u8OUT_LIN2_EN        9u
#define    DIO_u8OUT_CAN_EN         10u
#define    DIO_u8OUT_CAN_STB        11u
#define    DIO_u8OUT_CAN_WAKEUP     12u
#define    DIO_u8OUT_CAN2_STB       13u
#define    DIO_u8OUT_L9997_EN       14u
#define    DIO_u8OUT_L9997_IN1      15u
#define    DIO_u8OUT_L9997_IN2      16u
#define    DIO_u8OUT_VALVE1_DRIV    17u
#define    DIO_u8OUT_VALVE2_DRIV    18u
#define    DIO_u8OUT_VALVE3_DRIV    19u
#define    DIO_u8OUT_VALVE4_DRIV    20u
#define    DIO_u8OUT_COLD_FAN_PWR   21u
#define    DIO_u8OUT_SPI1_CS1       22u
#define    DIO_u8OUT_SPI1_CS2       23u
#define    DIO_u8OUT_PIN_MAX        23u
/*input*/
#define    DIO_u8IN_DEF_SW          24u
#define    DIO_u8IN_VALVE1_DIR      25u
#define    DIO_u8IN_VALVE2_DIR      26u
#define    DIO_u8IN_VALVE3_DIR      27u
#define    DIO_u8IN_VALVE4_DIR      28u
#define    DIO_u8IN_CAN_ERR         29u
/*unused pin*/
#define    DIO_u8UNUSED_P0_0        30u

#define    DIO_u8OUTSIG_NUM         24u
#define    DIO_u8INSIG_NUM          6u
#define    DIO_u8UNUSED_NUM         1u
/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/*! \Description Initialize Dio                                               */
/******************************************************************************/
extern void  Dio_vidInit(void);
/******************************************************************************/
/*! \Description : Output a certain level from output pin                      /
*******************************************************************************/
extern void  Dio_vidWrite(uint8 u8DioId, uint8 u8Value);
/******************************************************************************/
/*! \Description : Read input I/O level                                        /
*******************************************************************************/
extern uint8 Dio_u8Read(uint8 u8DioId);



#endif

/** \} */ /* end of Dio module group */
/** \} */ /* end of MCAL Dio Component */

/*-------------------------------- end of file -------------------------------*/

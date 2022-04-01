/******************************************************************************/
/* PROJECT  :    CHJ_D01                                                       */
/******************************************************************************/
/* !Layer           : Dio                                                     */
/*                                                                            */
/* !Component       : Dio                                                     */
/* !Description     : Managing digital inputs and outputs peripherals         */
/*                                                                            */
/* !Module          : Dio                                                     */
/* !Description     : Dio                                                     */
/*                                                                            */
/* !File            : Dio.c                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "s32k144_DIO.h"
//#include "Dio_Cfg.h"
#include "Port.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

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
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/
//static void vidOutputSignalsInit(uint8 u8DioId);
//static void vidInputSignalsInit(uint8 u8DioId);
/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/*!Function : vidOutputSignalsInit                                           */
/*! \Description Initialize output DIO.
    \param[in]   ID of DATA 
    \Range       0...
    \return      void
    \Trace_To   
  *****************************************************************************/
//static void vidOutputSignalsInit(uint8 u8DioId)
//{
//   //Port_vidSetGpioOutput(Dio_akstrSigCfg[u8DioId].strPortCfgType);
//}

/******************************************************************************/
/*!Function : vidInputSignalsInit                                           */
/*! \Description Initialize input DIO.
    \param[in]   ID of DATA 
    \Range       0...
    \return      void
    \Trace_To   
  *****************************************************************************/
//static void vidInputSignalsInit(uint8 u8DioId)
//{
//   //Port_vidSetGpioInput(Dio_akstrSigCfg[u8DioId].strPortCfgType);
//}


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function : Dio_vidInit                                                     */
/*! \Description Initialize Dio.
    \return      void
	\Trace_To   
  *****************************************************************************/
void Dio_vidInit(void)
{
    DIO_vidInit();
}

/******************************************************************************/
/*!Function : Dio_vidWrite                                                    */
/*! \Description Write to a digital output.
  \param[in]   ID of DATA .
  \Range       0...
  \param[in]   Value  to write
  \Range       0,1 
  \Trace_To     
//  ******************************************************************************/
//#define DIO_u8WDG                           0u
//#define DIO_SPI_CS0                         1u
//#define DIO_SPI_CS1                         2u
//#define DIO_u8DO_CAN1_STB                   3u
//#define DIO_u8DO_CAN2_STB                   4u
//#define DIO_u8DO_CAN1_EN                    5u
//#define DIO_u8DO_LIN1_EN                    6u
//#define DIO_u8DO_LIN2_EN                    7u
//#define DIO_u8DO_LIN3_EN                    8u
//
///*output*/
//#define    DIO_u8OUT_WDG            0u
//#define    DIO_u8OUT_EEP_CS         1u
//#define    DIO_u8OUT_EEP_WP         2u
//#define    DIO_u8OUT_E910_DR1_EN    3u
//#define    DIO_u8OUT_E910_DR2_EN    4u
//#define    DIO_u8OUT_E910_DR3_EN    5u
//#define    DIO_u8OUT_E910_DR4_EN    6u
//#define    DIO_u8OUT_E910_RST       7u
//#define    DIO_u8OUT_LIN_EN         8u
//#define    DIO_u8OUT_LIN2_EN        9u
//#define    DIO_u8OUT_CAN_EN         10u
//#define    DIO_u8OUT_CAN_STB        11u
//#define    DIO_u8OUT_CAN_WAKEUP     12u
//#define    DIO_u8OUT_CAN2_STB       13u
//#define    DIO_u8OUT_L9997_EN       14u
//#define    DIO_u8OUT_L9997_IN1      15u
//#define    DIO_u8OUT_L9997_IN2      16u
//#define    DIO_u8OUT_VALVE1_DRIV    17u
//#define    DIO_u8OUT_VALVE2_DRIV    18u
//#define    DIO_u8OUT_VALVE3_DRIV    19u
//#define    DIO_u8OUT_VALVE4_DRIV    20u
//#define    DIO_u8OUT_COLD_FAN_PWR   21u
//#define    DIO_u8OUT_SPI1_CS1       22u
//#define    DIO_u8OUT_SPI1_CS2       23u
//#define    DIO_u8OUT_PIN_MAX        23u
//static uint8 s32k144_outpin_id_map[]={DIO_u8OUT_WDG,DIO_u8OUT_SPI1_CS1,DIO_u8OUT_SPI1_CS2,}
void Dio_vidWrite(uint8 u8DioId, uint8 u8Value)
{
  uint8 s32k144_outpin_id_map=0xFF;
  if     (u8DioId==DIO_u8OUT_WDG)      s32k144_outpin_id_map=DIO_u8WDG;
  else if(u8DioId==DIO_u8OUT_SPI1_CS1) s32k144_outpin_id_map=DIO_SPI_CS1;
  else if(u8DioId==DIO_u8OUT_SPI1_CS2) s32k144_outpin_id_map=DIO_SPI_CS2;
  if(s32k144_outpin_id_map!=0xFF)
  {
    DIO_vidWrite(s32k144_outpin_id_map,u8Value);
  }
}

/*******************************************************************************/
/*!Function : Dio_u8Read                                                      */
/*! \Description Read from a digital input.
    \param[in]  ID of DATA .
    \Range      0...
    \return     0,1
    \Trace_To   
 ******************************************************************************/
uint8 Dio_u8Read(uint8 u8DioId)
{
    uint8 u8Result;
    //u8Result = DIO_u8DinRead(u8DioId);
    u8Result=0;
    return u8Result;	
}


/** \} */ /* end of Dio module group */
/** \} */ /* end of MCAL Dio Component */

/*-------------------------------- end of file -------------------------------*/









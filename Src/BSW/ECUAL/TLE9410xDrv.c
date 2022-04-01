/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Spi.h"
#include "Dio.h"
#include "S32k144_Dio.h"
#include "TLE9410xDrv.h"
#include "s32k144_SPI.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define u8NUM_OF_SIG                 ((uint8)6)
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
//static uint8 TLE9410xDrv_au8WrData[u8NUM_OF_SIG];
static uint32 motor_chip1_data=0;
static uint32 motor_chip2_data=0;
/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/


void TLE9410xDrv_vidInit(void)
{
//    TLE9410xDrv_au8WrData[TLE9410XDRV_MIXL_OUT12] = 0u;
//	TLE9410xDrv_au8WrData[TLE9410XDRV_MIXR_OUT34] = 0u;
//	TLE9410xDrv_au8WrData[TLE9410XDRV_MODEL_OUT56] = 0u;
//	TLE9410xDrv_au8WrData[TLE9410XDRV_MODER_OUT12] = 0u;
//	TLE9410xDrv_au8WrData[TLE9410XDRV_DEFROST_OUT34] = 0u;
//	TLE9410xDrv_au8WrData[TLE9410XDRV_RECY_OUT56] = 0u;
  motor_chip1_data=0;
  motor_chip2_data=0;
  Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
  Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
}

static void delay()
{//tCSNH least 5us
    uint32 i=320;
    while(i) i--;
}

void TLE9410xDrv_vidManage(void)
{
	static  uint8  LOC_u8CtrlStep = 0u;
	uint8          u8Addr = 0u;
	uint8          u8Data = 0u;
	uint16         u16AddrAndData = 0u;
	switch(LOC_u8CtrlStep)
	{
		case 0u://chip1 ctl
			Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            u8Addr         = u8ADDR_HB_ACT_1_CTRL;
			u8Data         = (uint8)((motor_chip1_data>>0)&0xFF);
			u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
			Spi_udtWriteReadTle9410x(&u16AddrAndData);
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            delay();
            
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            u8Addr         = u8ADDR_HB_ACT_2_CTRL;
			u8Data         = (uint8)((motor_chip1_data>>8)&0xFF);
			u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
			Spi_udtWriteReadTle9410x(&u16AddrAndData);
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            delay();
            
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            u8Addr         = u8ADDR_HB_ACT_3_CTRL;
			u8Data         = (uint8)((motor_chip1_data>>16)&0xFF);
			u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
			Spi_udtWriteReadTle9410x(&u16AddrAndData);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            delay();
			LOC_u8CtrlStep = 1u;
			break;

		case 1u://chip2 ctl
			Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 0u);
			u8Addr         = u8ADDR_HB_ACT_1_CTRL;
			u8Data         = (uint8)((motor_chip2_data>>0)&0xFF);
			u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
			Spi_udtWriteReadTle9410x(&u16AddrAndData);
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            delay();
            
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 0u);
            u8Addr         = u8ADDR_HB_ACT_2_CTRL;
			u8Data         = (uint8)((motor_chip2_data>>8)&0xFF);
			u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
			Spi_udtWriteReadTle9410x(&u16AddrAndData);
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            delay();
            
            Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 0u);
            u8Addr         = u8ADDR_HB_ACT_3_CTRL;
			u8Data         = (uint8)((motor_chip2_data>>16)&0xFF);
			u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
			Spi_udtWriteReadTle9410x(&u16AddrAndData);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
			Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
            delay();
			LOC_u8CtrlStep = 0u;
			break;
		default:
			break;
	}

}



void TLE9410xDrv_vidDcMotorCtrl(TLE9410xDRV_tenuId enuMotorId,uint8 u8HighOutValue,uint8 u8LowOutValue)
{
   uint32 temp_value=0;
   uint8  high_out,low_out;
   switch(enuMotorId)
   {
   case TLE9410XDRV_MIXL://_3_8:
         high_out=8;
         low_out =3;
         temp_value =(0x01<<u8HighOutValue)<<(2*high_out-2);//对应位置1
         motor_chip1_data&=~(0x03<<(2*high_out-2));//对应位清0
         motor_chip1_data|=temp_value;//更新新值
         temp_value=(0x01<<u8LowOutValue) <<(2*low_out-2);
         motor_chip1_data&=~(0x03<<(2*low_out-2));
         motor_chip1_data|=temp_value;
	   break;
   case TLE9410XDRV_MIXR://_2_10:
         high_out=2;
         low_out =10;
         temp_value =(0x01<<u8HighOutValue)<<(2*high_out-2);//对应位置1
         motor_chip1_data&=~(0x03<<(2*high_out-2));//对应位清0
         motor_chip1_data|=temp_value;//更新新值
         temp_value=(0x01<<u8LowOutValue) <<(2*low_out-2);
         motor_chip1_data&=~(0x03<<(2*low_out-2));
         motor_chip1_data|=temp_value;
	   break;
       
   case TLE9410XDRV_MODEL://_5_9:
         high_out=5;
         low_out =9;
         temp_value =(0x01<<u8HighOutValue)<<(2*high_out-2);//对应位置1
         motor_chip1_data&=~(0x03<<(2*high_out-2));//对应位清0
         motor_chip1_data|=temp_value;//更新新值
         temp_value=(0x01<<u8LowOutValue) <<(2*low_out-2);
         motor_chip1_data&=~(0x03<<(2*low_out-2));
         motor_chip1_data|=temp_value;
	   break;

   case TLE9410XDRV_MODER://_1_7:
         high_out=1;
         low_out =7;
         temp_value =(0x01<<u8HighOutValue)<<(2*high_out-2);//对应位置1
         motor_chip1_data&=~(0x03<<(2*high_out-2));//对应位清0
         motor_chip1_data|=temp_value;//更新新值
         temp_value=(0x01<<u8LowOutValue) <<(2*low_out-2);
         motor_chip1_data&=~(0x03<<(2*low_out-2));
         motor_chip1_data|=temp_value;
	   break;

   case TLE9410XDRV_RECY://_4_6:
	     high_out=6;
         low_out =4;
         temp_value =(0x01<<u8HighOutValue)<<(2*high_out-2);//对应位置1
         motor_chip1_data&=~(0x03<<(2*high_out-2));//对应位清0
         motor_chip1_data|=temp_value;//更新新值
         temp_value=(0x01<<u8LowOutValue) <<(2*low_out-2);
         motor_chip1_data&=~(0x03<<(2*low_out-2));
         motor_chip1_data|=temp_value;
	   break;
   case TLE9410XDRV_DEFROST://_4_6:
         high_out=6;
         low_out =4;
         temp_value =(0x01<<u8HighOutValue)<<(2*high_out-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*high_out-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
         temp_value=(0x01<<u8LowOutValue) <<(2*low_out-2);
         motor_chip2_data&=~(0x03<<(2*low_out-2));
         motor_chip2_data|=temp_value;
	   break;
       
       default:
	   break;
   }
}

void TLE9410xDrv_vidRelayCtrl(TLE9410xDRV_tenuId enuRelayId,uint8 u8OutValue)
{
   uint32 temp_value=0;
   uint8  outx;
   switch(enuRelayId)
   {
	   case TLE9410XDRV_SOV_RLY1:
	     outx=1;
         temp_value =(0x01<<u8OutValue)<<(2*outx-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*outx-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
	   break;

	   case TLE9410XDRV_SOV_RLY2:
	     outx=10;
         temp_value =(0x01<<u8OutValue)<<(2*outx-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*outx-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
	   break;

	   case TLE9410XDRV_BLW_RLY3:
	     outx=11;
         temp_value =(0x01<<u8OutValue)<<(2*outx-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*outx-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
	   break;

	   case TLE9410XDRV_FAN_RLY4:
	     outx=12;
         temp_value =(0x01<<u8OutValue)<<(2*outx-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*outx-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
	   break;
       case TLE9410XDRV_SOTXV_RLY5:
	     outx=9;
         temp_value =(0x01<<u8OutValue)<<(2*outx-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*outx-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
	   break;   
        case TLE9410XDRV_FAN_RLY11:
	     outx=8;
         temp_value =(0x01<<u8OutValue)<<(2*outx-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*outx-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
	   break; 
       /*case 0xFE:
	     outx=2;
         temp_value =(0x01<<u8OutValue)<<(2*outx-2);//对应位置1
         motor_chip2_data&=~(0x03<<(2*outx-2));//对应位清0
         motor_chip2_data|=temp_value;//更新新值
	   break; */
	   default:
	   break;
   }

}

static uint8 TLE9410xDrv_au8AddrDataBuffer[2];
void tle9410Drv_test()
{
    uint8          u8Addr = 0u;
	uint8          u8Data = 0u;
	uint16         u16AddrAndData = 0u;
    
    
    
    TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXL,0,1);
    TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXR,0,1);
    TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODEL,0,1);
    TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODER,0,1);
    TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_RECY,0,1);
    TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_DEFROST,0,1);
    while(1)
    {
       TLE9410xDrv_vidManage();
 //   TLE9410xDrv_vidManage();
    }
 //  TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOV_RLY1,0);
//    TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOV_RLY2,0);
//    TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_BLW_RLY3,0);
//    TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_FAN_RLY4,0);
//    TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOTXV_RLY5,0);
//    
//    TLE9410xDrv_vidManage();
 //   TLE9410xDrv_vidManage();
 //   return;
//    
//    return;
//    //SEGGER_RTT_printf(0, "tle9410Drv_test\r\n");
//    TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_RLY1_OUT12,1);
//    return;
//    DIO_vidWrite(DIO_SPI_CS1,1);
//    DIO_vidWrite(DIO_SPI_CS2,0);
//			
//    
//    u8Addr         = u8ADDR_HB_ACT_1_CTRL;
//    u8Data         = (uint8)((0x01>>0)&0xFF);
//    u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
//
//    TLE9410xDrv_au8AddrDataBuffer[0] = 0x83;
//    TLE9410xDrv_au8AddrDataBuffer[1] = 0x09;
//    SPI_bWriteData(SPI_u8CH1_TLE9410X,TLE9410xDrv_au8AddrDataBuffer,1,SPI_u8MODE_READ_WRITE);
//     DIO_vidWrite(DIO_SPI_CS1,1);
//    DIO_vidWrite(DIO_SPI_CS2,1);
    
//    Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
//	Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);   
//    u8Addr         = u8ADDR_HB_ACT_1_CTRL;
//    u8Data         = 0x09;//(uint8)((motor_chip1_data>>0)&0xFF);
//    u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
//    Spi_udtWriteReadTle9410x(&u16AddrAndData);
////    u8Addr         = u8ADDR_HB_ACT_2_CTRL;
////    u8Data         = (uint8)((motor_chip1_data>>8)&0xFF);
////    u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
////    Spi_udtWriteReadTle9410x(&u16AddrAndData);
////    u8Addr         = u8ADDR_HB_ACT_3_CTRL;
////    u8Data         = (uint8)((motor_chip1_data>>16)&0xFF);
////    u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
////    Spi_udtWriteReadTle9410x(&u16AddrAndData);
//    
//    Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
//    Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
    
//    
        Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 0u);  
        uint32 temp_value=0;
        uint8  high_out,low_out;//_4_6:
        uint8 u8HighOutValue=1;
        uint8 u8LowOutValue=1;
        high_out=4;
        low_out =6;
        temp_value =(0x01<<u8HighOutValue)<<(2*high_out-2);//对应位置1
        motor_chip1_data=0xFFFFFFFF;
        SEGGER_RTT_printf(0, "tle9410Drv_test0:0x%x,0x%x\r\n",temp_value,motor_chip1_data);
        motor_chip1_data&=~(0x03<<(2*high_out-2));//对应位清0
        motor_chip1_data|=temp_value;//更新新值
        SEGGER_RTT_printf(0, "tle9410Drv_test2:0x%x,0x%x\r\n",temp_value,motor_chip1_data);
        temp_value=(0x01<<u8LowOutValue) <<(2*low_out-2);
        motor_chip1_data&=~(0x03<<(2*low_out-2));
        motor_chip1_data|=temp_value;
        SEGGER_RTT_printf(0, "tle9410Drv_test3:0x%x,0x%x\r\n",temp_value,motor_chip1_data);
        
        u8Addr         = u8ADDR_HB_ACT_1_CTRL;
        u8Data         = (uint8)((motor_chip1_data>>0)&0xFF);
        u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
        Spi_udtWriteReadTle9410x(&u16AddrAndData);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);  
    
        Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);  
        u8Addr         = u8ADDR_HB_ACT_2_CTRL;
        u8Data         = (uint8)((motor_chip1_data>>8)&0xFF);
        u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
        Spi_udtWriteReadTle9410x(&u16AddrAndData);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u); 
        
        Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);  
        u8Addr         = u8ADDR_HB_ACT_3_CTRL;
        u8Data         = (uint8)((motor_chip1_data>>16)&0xFF);
        u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
        Spi_udtWriteReadTle9410x(&u16AddrAndData);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
        Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);  
    
 //     DIO_vidWrite(DIO_SPI_CS1,1);
 //   DIO_vidWrite(DIO_SPI_CS2,0);
			
    
//    u8Addr         = u8ADDR_HB_ACT_1_CTRL;
//    u8Data         = (uint8)((0x01>>0)&0xFF);
//    u16AddrAndData = (uint16)(u8Addr) | (uint16)(u8Data << 8u);
//
//    TLE9410xDrv_au8AddrDataBuffer[0] = 0x83;
//    TLE9410xDrv_au8AddrDataBuffer[1] = 0x00;
//    SPI_bWriteData(SPI_u8CH1_TLE9410X,TLE9410xDrv_au8AddrDataBuffer,1,SPI_u8MODE_READ_WRITE);
//     DIO_vidWrite(DIO_SPI_CS1,1);
//    DIO_vidWrite(DIO_SPI_CS2,1);
//     Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
//    Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
//     TLE9410xDrv_au8AddrDataBuffer[0] = 0x83;
//     TLE9410xDrv_au8AddrDataBuffer[1] = 0xAA;
//      SPI_bWriteData(SPI_u8CH0_TLE94108,TLE9410xDrv_au8AddrDataBuffer,1,SPI_u8MODE_READ_WRITE);  
//      Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
//	Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
//    Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 0u);
//    Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
//     TLE9410xDrv_au8AddrDataBuffer[0] = 0x83;
//     TLE9410xDrv_au8AddrDataBuffer[1] = 0xFF;
//     SPI_bWriteData(SPI_u8CH0_TLE94108,TLE9410xDrv_au8AddrDataBuffer,1,SPI_u8MODE_READ_WRITE); 
//    Dio_vidWrite(DIO_u8OUT_SPI1_CS1 , 1u);
//	Dio_vidWrite(DIO_u8OUT_SPI1_CS2 , 1u);
}







/*-------------------------------- end of file -------------------------------*/

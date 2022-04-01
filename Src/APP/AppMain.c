/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : App                                                     */
/*                                                                            */
/* !Component       : AppMain                                                 */
/* !Description     : App main function                                       */
/*                                                                            */
/* !Module          : AppMain                                                 */
/* !Description     : App main function                                       */
/*                                                                            */
/* !File            : AppMain.c                                               */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : uPD70F3375                                              */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/AP$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/APP/AppMain.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:06   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:04   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "AppMain.h"
#include "CanCcl.h"
#include "Power.h"
#include "Stepper.h"
#include "Eeprom.h"
#include "Cmb.h"
#include "Blower.h"
#include "AppDiag.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "CRC8.h"
#include "StdLibSS.h"
#include "ExvDrv.h"
#include "EcvDrv.h"
#include "SovDrv.h"
#include "AppMbdInterface.h"
#include "Uart.h"
#include "Can.h"
#include "Can_Hdl.h"
#include "Eeprom.h"
#include "Adc.h"
#include "Pwm.h"
#include "Sensor.h"
#include "Actuator.h"
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
static uint8   AppMain_u8AppVolOnOffStatus;


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
extern void AppMain_vidInit(void)
{
    AppDiag_vidInit();
    AppMbdInterface_vidInit();
    AppMain_u8AppVolOnOffStatus = STD_OFF;
    CanCcl_vidSetCanMode(CANCCL_CMT_START);
}

extern void AppMain_vidManage(void)
{
    return;
    if (AppMain_u8AppVolOnOffStatus == STD_ON)
    {
				static uint8 LOC_u8Cnt = 0u;
				static uint8 LOC_u8EcvCtrlStep = 0u;
				switch(LOC_u8EcvCtrlStep)
				{
					case 0:
                        Actuator_vidSetPosition(u8ACT_RECY,20);
						LOC_u8EcvCtrlStep = 1u;
						break;

					case 1:
                    //if ((Actuator_u8GetPosition(u8ACT_RECY) <= 22) && (Actuator_u8GetPosition(u8ACT_RECY) >= 18))
                    {
                    	if(LOC_u8Cnt  < (25 * 3))
						{
							LOC_u8Cnt++;
						}
						else
						{
							LOC_u8Cnt = 0u;
							LOC_u8EcvCtrlStep = 2u;
						}
                    }
                    break;
                    
                    
                    case 2:
                        Actuator_vidSetPosition(u8ACT_RECY,90);
						LOC_u8EcvCtrlStep = 3u;
						break;

					case 3:
                    //if ((Actuator_u8GetPosition(u8ACT_RECY) <= 92) && (Actuator_u8GetPosition(u8ACT_RECY) >= 88))
                    {
                    	if(LOC_u8Cnt  < (25 * 3))
						{
							LOC_u8Cnt++;
						}
						else
						{
							LOC_u8Cnt = 0u;
							LOC_u8EcvCtrlStep = 0u;
						}
                    }
                    break;

			   }
		    }

}


extern void AppMain_vidFastManage(void)
{
    /*! Get the current Power level. */
    Power_tenuPowerLevel enuPowerLevelCur;
    enuPowerLevelCur = Power_enuGetPowerLevel();
    if (enuPowerLevelCur == Power_LEVEL_B)
    {
		AppMain_u8AppVolOnOffStatus = STD_ON;	
    }
    else if (enuPowerLevelCur == Power_LEVEL_C)
    {
		AppMain_u8AppVolOnOffStatus = STD_ON;		
    }
    else if (enuPowerLevelCur == Power_LEVEL_A)
    {
		AppMain_u8AppVolOnOffStatus = STD_OFF;	
    }
    else if (enuPowerLevelCur == Power_LEVEL_D)
    {
		AppMain_u8AppVolOnOffStatus = STD_OFF;	
    }	
    else if (enuPowerLevelCur == Power_LEVEL_LV)
    {
		AppMain_u8AppVolOnOffStatus = STD_OFF;	
    }	
    else if (enuPowerLevelCur == Power_LEVEL_HV)
    {
		AppMain_u8AppVolOnOffStatus = STD_OFF;	
    }
    else
    {
		AppMain_u8AppVolOnOffStatus = STD_OFF;		
    }
}
#if 0
uint8 u8UartSendHead[3] = {0xAA,0xBB,0XCC};
uint8 u8UartBuffer[sizeof(AppDiag_tstrSendToPcDisplayData) + sizeof(u8UartSendHead)/sizeof(u8UartSendHead[0])];//!!!!!Must been defined as Global Variable
#endif
#if 0
uint8 u8CanSendHead[8] = {0x04,0x22,0X21,0XFF,0X88,0xAA,0XBB,0XCC};
uint8 u8CanBuffer[sizeof(AppDiag_tstrSendToPcDisplayData) + sizeof(u8CanSendHead)/sizeof(u8CanSendHead[0])];//!!!!!Must been defined as Global Variable
#endif
extern void AppMain_vidSlowManage(void)
{
#if 1
    AppMbdInterface_vidManage();
#else
	{
        static uint8 LOC_u8Step = 0u;
		static uint8 LOC_u8StepCnt = 0u;
		switch(LOC_u8Step)
		{
          case 0:
			LOC_u8Step = 1u;
			StdLibSS_vidDataSetU8(AppDiag_uniSendToPcDisplayData.u8DataAll,0X01,sizeof(AppDiag_tstrSendToPcDisplayData));
		  break;

		  case 1:
		  if(LOC_u8StepCnt < 10)
		  {
			  LOC_u8StepCnt++;
		  }
		  else
		  {
			 LOC_u8StepCnt = 0u;
			 LOC_u8Step = 2u;
		  }
		  break;

		  case 2:
		    StdLibSS_vidDataSetU8(AppDiag_uniSendToPcDisplayData.u8DataAll,0X02,sizeof(AppDiag_tstrSendToPcDisplayData));
		    LOC_u8Step = 3u;
		  break;

	      case 3:
		  if(LOC_u8StepCnt < 10)
		  {
			  LOC_u8StepCnt++;
		  }
		  else
		  {
			 LOC_u8StepCnt = 0u;
			 LOC_u8Step = 0u;
		  }
		  break;	  
		}


	}
#endif
	
#if 0
    /*Uart Send Data To PC Display*/
    {
         uint8 u8Index;
	 for(u8Index = 0u; u8Index < sizeof(u8UartBuffer)/sizeof(u8UartBuffer[0]); u8Index++)
	 {
	     if(u8Index < sizeof(u8UartSendHead)/sizeof(u8UartSendHead[0]))
	     {
                u8UartBuffer[u8Index] = u8UartSendHead[u8Index];
	     }
	     else
	     {
                u8UartBuffer[u8Index] = AppDiag_uniSendToPcDisplayData.u8DataAll[u8Index - sizeof(u8UartSendHead)/sizeof(u8UartSendHead[0])];
	     }
	 }
	 {
	     static uint8 LOC_u8UartSentCnt = 0u;
	     if(LOC_u8UartSentCnt < 10)
	     {
		 LOC_u8UartSentCnt++;
	     }
	     else
	     {
		 UART_vidWriteBuffer(u8UartBuffer, sizeof(u8UartBuffer)/sizeof(u8UartBuffer[0]));
	     }
	 }
    }
#endif
#if 0
    /*CAN APP Frame Send Data To PC Display*/
    {
		uint8 u8Index;
		for(u8Index = 0u; u8Index < sizeof(u8CanBuffer)/sizeof(u8CanBuffer[0]); u8Index++)
		{
			if(u8Index < sizeof(u8CanSendHead)/sizeof(u8CanSendHead[0]))
			{
                u8CanBuffer[u8Index] = u8CanSendHead[u8Index];
			}
			else
			{
                u8CanBuffer[u8Index] = AppDiag_uniSendToPcDisplayData.u8DataAll[u8Index - sizeof(u8CanSendHead)/sizeof(u8CanSendHead[0])];
			}
		}
		{
			static uint8 LOC_u8CanSendCnt = 0u;
			if(LOC_u8CanSendCnt < 10)
			{
				LOC_u8CanSendCnt++;
			}
			else
			{
				Can_vidSendBuffer(u8CanBuffer, sizeof(u8CanBuffer)/sizeof(u8CanBuffer[0]));
			}
		} 
    }
#endif
}


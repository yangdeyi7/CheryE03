/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : Can_Hdl                                                 */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !Module          : Can_Hdl                                                 */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !File            : Can_Hdl.c                                               */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/CO$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/Can/Can_Hdl.c-arc  $
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
#include "Can_Type.h"
#include "Can_Hdl.h"
#include "Can.h"
#include "CanTrcv.h"
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
static Can_tpfvidRxFuncCallback   Can_pfvidRxCallback;
static Can_tpfvidTxFuncCallback   Can_pfvidTxCallback;
static Std_tpfvidFuncCbk_vid      Can_pfvidWakeUpCallback;
static Std_tpfvidFuncCbk_u8       Can_pfvidBusOffCallback;
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void Can_vidHdlInit(void)
{
	Can_pfvidRxCallback = (Can_tpfvidRxFuncCallback)0;
}

void Can_vidRxHandler(Can_tstrPduType strPdu)
{
    if(Can_pfvidRxCallback != NULL_PTR)
    {
        if((strPdu.u32CanId & 0x80000000)==0)
        {
            /*std ID*/
            strPdu.u32CanId >>= 18;
            strPdu.u32CanId &= 0x000007FF;
        }
        else
        {
            /*ext ID*/
            strPdu.u32CanId &= 0x1FFFFFFF;
        }
        Can_pfvidRxCallback(strPdu);
    }
}

void Can_vidTxHandler(void)
{
	Can_tstrPduType strPdu;
    strPdu.u8Dlc = 0u;
	if (Can_pfvidTxCallback != NULL_PTR ) 
	{ 
		Can_pfvidTxCallback(strPdu);
	}		
}

extern void Can_vidWakeupHandler(void)
{
	if (Can_pfvidWakeUpCallback != NULL_PTR ) 
	{ 
		Can_pfvidWakeUpCallback();
	}	
}

extern void Can_vidBusoffHandler(void)
{
    uint8 u8State = 0u;
	if (Can_pfvidBusOffCallback != NULL_PTR ) 
	{ 
		Can_pfvidBusOffCallback(u8State);
	}	
}

void Can_vidSetRxCallbackFunc(Can_tpfvidRxFuncCallback pfvidCallback)
{
	Can_pfvidRxCallback = pfvidCallback;
}

void Can_vidSetTxCallbackFunc(Can_tpfvidTxFuncCallback pfvidCallback)
{
	Can_pfvidTxCallback = pfvidCallback;
}

void Can_vidSetWakeUpCallbackFunc(Std_tpfvidFuncCbk_vid pfvidCallback)
{
	Can_pfvidWakeUpCallback = pfvidCallback;
}

void Can_vidSetBusOffCallbackFunc(Std_tpfvidFuncCbk_u8 pfvidCallback)
{
	Can_pfvidBusOffCallback = pfvidCallback;	
}


uint8 Can_u8CanMsgSendIdDatDlc(uint8 u8BufNo, uint32 u32CanId, uint8* pu8Data, uint8 u8Dlc)
{
	boolean bRtn = FALSE;
    Can_tstrPduType strPduType;
	uint8 u8FilledCounter;
	/* to consider place in diag part*/
	for(u8FilledCounter = 0u;u8FilledCounter < 8u;u8FilledCounter++)
	{
		if(u8FilledCounter < u8Dlc)
		{
			/*do nothing*/
		}
		else
		{
			pu8Data[u8FilledCounter] = 0x55u;
		}
	}
    
    strPduType.u32CanId = u32CanId;
    strPduType.u8Dlc = u8Dlc;
	strPduType.pu8Data = pu8Data;
    
    Can_tstrFrame pdu;
    pdu.u32Id=u32CanId;
    pdu.u8DLC=u8Dlc;
    for(u8FilledCounter=0;u8FilledCounter<8;u8FilledCounter++)
    {
        pdu.au8Data[u8FilledCounter]=pu8Data[u8FilledCounter];
    }
    SEGGER_RTT_printf(0, "Can_u8CanMsgSendIdDatDlc:id=0x%04x\r\n",pdu.u32Id);
	bRtn = Can_u32TrasnimitMsg((uint32)u8BufNo,&pdu);
	return (uint8)bRtn;
}


static uint8  u8MixLPerPosi    = 0xffu;
static uint8  u8MixRPerPosi    = 0xffu;
static uint8  u8ModeLStsPosi   = 0xffu;
static uint8  u8ModeRStsPosi   = 0xffu;
static uint8  u8DefrostPerPosi = 0xffu;
static uint8  u8RecyPerPosi    = 0xffu;

uint8 au8_00A_C_57900323_10_B0B1[2] = {0,0};
uint8 au8_00A_C_57900323_10_B2B3[2] = {0,0};
uint8 au8_00A_C_57900323_10_B4B5[2] = {0,0};
uint8 au8_00A_C_57900323_10_B6B7[2] = {0,0};

uint8 au8_00B_C_57900323_11_B0B1[2] = {0,0};
uint8 au8_00B_C_57900323_11_B2B3[2] = {0,0};
uint8 au8_00B_C_57900323_11_B4B5[2] = {0,0};
uint8 au8_00B_C_57900323_11_B6B7[2] = {0,0};

uint8 au8_00C_C_57900322_12_B0B1[2] = {0,0};
uint8 au8_00C_C_57900322_12_B2B3[2] = {0,0};
uint8 au8_00C_C_57900322_12_B4B5[2] = {0,0};
uint8 au8_00C_C_57900322_12_B6B7[2] = {0,0};

uint8 au8_00D_C_57900322_13_B0B1[2] = {0,0};
uint8 au8_00D_C_57900322_13_B2B3[2] = {0,0};
uint8 au8_00D_C_57900322_13_B4B5[2] = {0,0};
uint8 au8_00D_C_57900322_13_B6B7[2] = {0,0};

uint8 au8_00E_C_56704738_14_B0B1[2] = {0,0};
uint8 au8_00E_C_56704738_14_B2B3[2] = {0,0};
/*
uint8 au8_00E_C_56704738_14_B4B5[2] = {0,0};
uint8 au8_00E_C_56704738_14_B6B7[2] = {0,0};

uint8 au8_00F_C_56704738_15_B0B1[2] = {0,0};
uint8 au8_00F_C_56704738_15_B2B3[2] = {0,0};
uint8 au8_00F_C_56704738_15_B4B5[2] = {0,0};
uint8 au8_00F_C_56704738_15_B6B7[2] = {0,0};
*/
/*****************Get CAN MSG From Dc Motor Contrl PCBA to Get Flap Motor Actual Posi*****************/
#define   s8Act_ABS_DIFF(x ,y)  ( ((x) > (y)) ? ((x) - (y)) : ((y) - (x)) )

extern uint8  u8GetMixLPerPosi(void)
{
   return u8MixLPerPosi;
}
extern uint8  u8GetMixRPerPosi(void)
{
   return u8MixRPerPosi;
}
extern uint8  u8GetModeLStsPosi(void)
{
   uint8 u8Rtn = 0xffu;
   if(s8Act_ABS_DIFF(u8ModeLStsPosi,0) <= 2)
   {
       u8Rtn = 1u;
   }
   else if(s8Act_ABS_DIFF(u8ModeLStsPosi,49) <= 2)
   {
	   u8Rtn = 3u;
   }
   else if(s8Act_ABS_DIFF(u8ModeLStsPosi,1000) <= 2)
   {
       u8Rtn = 5u;
   }
   else
   {

   }
   return u8Rtn;
}
extern uint8  u8GetModeRStsPosi(void)
{
   return u8ModeRStsPosi;
}
extern uint8  u8GetDefrostPerPosi(void)
{
   return u8DefrostPerPosi;
}
extern uint8  u8GetRecyPerPosi(void)
{
   return u8RecyPerPosi;
}
/*-------------------------------- end of file -------------------------------*/

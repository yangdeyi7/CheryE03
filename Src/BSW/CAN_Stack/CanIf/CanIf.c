/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : CanIf                                                   */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !Module          : CanIf                                                   */
/* !Description     : Can communication interface                             */
/*                                                                            */
/* !File            : CanIf.c                                                 */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanIf/CanIf.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:10   chunping.yan
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
#include "Can_Type.h"
#include "Can_Hdl.h"
#include "CanIf.h"
#include "CanIf_Cfg.h"
#include "CanTp.h"
#include "CanCcl.h"
#include "Can.h"
#include "mcu.h"
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
uint8 CanIf_u8AppComDisable;


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidCanComRxIndication(uint8 u8Ind,Can_tstrPduType strPdu);
static void vidCanTpRxIndication(Can_tstrPduType strPdu,
	CanTp_tenuTpTaType enuTpTa);
static void vidCanIfRxIndication(Can_tstrPduType strPdu);
static void vidCanIfTxIndication(Can_tstrPduType strPdu);
static uint8 u8SendMsg(uint8 u8MsgBufInd, Can_tstrPduType strPdu);
static void vidInitCtrl(void);


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
static uint8 u8SendMsg(uint8 u8MsgBufInd, Can_tstrPduType strPdu)
{
    /*maybe change : send by different msg buffer vs can ID*/
    uint8 u8Rtn = 0u;
#if 0
	if ((CanIf_u8AppComDisable & CanIf_u8DISABLEAPPCOMTX_SET) == CanIf_u8DISABLEAPPCOMTX_SET)
	{
		/*disable TX*/
	}
	else
	{
		/*enable TX*/
		u8Rtn = Can_u8CanMsgSendIdDatDlc(u8MsgBufInd, 
			strPdu.u32CanId, strPdu.pu8Data, strPdu.u8Dlc);
	}
#endif
    return u8Rtn;	
}


static void vidInitCtrl(void)
{
	uint8 u8Index;
	for (u8Index = 0u ; u8Index < COM_RXPDUNUM ; u8Index++)
	{
        /* timeout timer reset */
        CanIf_strRxCtrl[u8Index].u16RxToTimer = 0u;
	}
	
	for (u8Index = 0u ; u8Index < COM_TXPDUNUM ; u8Index++)
	{
        /* timeout timer reset */
        CanIf_strTxCtrl[u8Index].bSend = FALSE;
        CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt = 0u;	
        CanIf_strTxCtrl[u8Index].u16MsgCycleTimeFastCnt = 0u;			
		CanIf_strTxCtrl[u8Index].u8MsgNbOfRepetitionCnt = 0u;
	}	
}

static void vidCanComRxIndication(uint8 u8Ind, Can_tstrPduType strPdu)
{
    uint8 u8Index;
	if ((CanIf_u8AppComDisable & CanIf_u8DISABLEAPPCOMRX_SET) == CanIf_u8DISABLEAPPCOMRX_SET)
	{
		/*disable RX*/
	}
	else
	{
		/*enable RX*/	
      
        SEGGER_RTT_printf(0, "vidCanComRxIndication:id=0x%04x\r\n",strPdu.u32CanId);
		/*receive data*/
		for (u8Index = 0u; u8Index < strPdu.u8Dlc; u8Index++)
		{
			CanIf_kstrRxPduBuf[u8Ind].pu8Data[u8Index] = strPdu.pu8Data[u8Index];        
		}
		/*call Rx indication function*/
		CanIf_kstrRxMsgInfo[u8Ind].vidRxIndication();
		/*time out cnt to be cleared*/
		if (CanIf_kstrRxMsgInfo[u8Ind].bTOMonitored == TRUE)
		{
			CanIf_strRxCtrl[u8Ind].u16RxToTimer = 0u;
		}
	}
}


static void vidCanTpRxIndication(Can_tstrPduType strPdu,
	CanTp_tenuTpTaType enuTpTa)
{
	CanTp_vidCanTpRxIndication(strPdu, enuTpTa);	
}

static void vidCanIfRxIndication(Can_tstrPduType strPdu)
{
	uint8 u8Index;
	boolean bFound = FALSE;

	/*app message*/
	if (CanIf_bGetAppComDisableRx() == FALSE)
	{
		for (u8Index = 0u ; u8Index < COM_RXPDUNUM ; u8Index++)
		{
			if (strPdu.u32CanId == CanIf_kstrRxMsgInfo[u8Index].strPdu.u32CanId)
			{
              //SEGGER_RTT_printf(0, "vidCanIfRxIndication:id=0x%04x\r\n");
				vidCanComRxIndication(u8Index, strPdu);
				bFound = TRUE;
				break;
			}
		}		
	}
	
	/*TP message*/
 	if (bFound == FALSE)
	{
        SEGGER_RTT_printf(0, "vidCanTpRxIndication:id=0x%04x\r\n",strPdu.u32CanId);
		for (u8Index = 0u ; u8Index < TP_RXPDUNUM ; u8Index++)
		{
			if (strPdu.u32CanId == CanIf_ku32TpRxMsgId[u8Index])
			{
				vidCanTpRxIndication(strPdu , CanIf_kenuTpTa[u8Index]);
				bFound=TRUE;
				break;
			}
		}		
	} 	
}

static void vidCanIfTxIndication(Can_tstrPduType strPdu)
{
	
}

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

void CanIf_vidInit(void)
{
	uint8 u8Index;
	uint8 u8DataIndex;
	CanIf_u8AppComDisable = 0x00u; /*enable TX and RX*/
	/*init tx and rx data buffer*/
	for (u8Index = 0u ; u8Index < COM_RXPDUNUM ; u8Index++)
	{
        /* timeout timer reset */
		for (u8DataIndex=0u;
			u8DataIndex < CanIf_kstrRxMsgInfo[u8Index].strPdu.u8Dlc ; 
			u8DataIndex++)
		{
			CanIf_kstrRxPduBuf[u8Index].pu8Data[u8DataIndex] = 
				CanIf_kstrRxMsgInfo[u8Index].strPdu.pu8Data[u8DataIndex];        
		}
	}
	
	for (u8Index = 0; u8Index < COM_TXPDUNUM; u8Index++)
	{
        /* timeout timer reset */
		for (u8DataIndex = 0u;
			u8DataIndex < CanIf_kstrTxMsgInfo[u8Index].strPdu.u8Dlc;
			u8DataIndex++)
		{
			CanIf_kstrTxPduBuf[u8Index].pu8Data[u8DataIndex] = 
				CanIf_kstrTxMsgInfo[u8Index].strPdu.pu8Data[u8DataIndex];        
		}
	}	
	/*init ctrl info*/
	vidInitCtrl();
	/*set call back*/
	Can_vidSetRxCallbackFunc(&vidCanIfRxIndication);
	Can_vidSetTxCallbackFunc(&vidCanIfTxIndication);	
        
}

void CanIf_vidRxTask(void)
{
	uint8 u8Index;
	/*check if enable RX*/
	if (CanIf_bGetAppComDisableRx() == FALSE)
	{
		Mcu_vidDisableInterrupts();
		for (u8Index = 0u; u8Index < COM_RXPDUNUM; u8Index++)
		{
			/*timeout handling*/
			if (CanIf_kstrRxMsgInfo[u8Index].bTOMonitored == TRUE)
			{
				if (CanIf_strRxCtrl[u8Index].u16RxToTimer < 
					CanIf_kstrRxMsgInfo[u8Index].u16RxTimeout)
				{
					CanIf_strRxCtrl[u8Index].u16RxToTimer += 10u;
				}
				else
				{
					if (CanIf_strRxCtrl[u8Index].u16RxToTimer != 0xffffu)
					{
						CanIf_kstrRxMsgInfo[u8Index].vidTOIndication();
						CanIf_strRxCtrl[u8Index].u16RxToTimer = 0xffffu; 
						/*^avoid 2nd trig*/
					}
				}
			}
		}
		Mcu_vidEnableInterrupts();
	}
}

void CanIf_vidTxTask(void)
{

	uint8 u8Index;
	Can_tstrPduType strPdu;
	
	if (CanIf_bGetAppComDisableTx() == FALSE)
	{	
		/*Mcu_vidDisableInterrupts();*/
		for (u8Index = 0u; u8Index < COM_TXPDUNUM; u8Index++)
		{
			/*if some where have requested send*/
			if (CanIf_strTxCtrl[u8Index].bSend == TRUE)
			{
				if (CanIf_kstrTxMsgInfo[u8Index].u8MsgNbOfRepetition > 0u)	
				{
					CanIf_strTxCtrl[u8Index].u8MsgNbOfRepetitionCnt = 
						CanIf_kstrTxMsgInfo[u8Index].u8MsgNbOfRepetition;
				}		
			}
			/*repetition msg handling*/
			if (CanIf_strTxCtrl[u8Index].u8MsgNbOfRepetitionCnt > 0u)
			{
				if (CanIf_strTxCtrl[u8Index].u16MsgCycleTimeFastCnt < 
					CanIf_kstrTxMsgInfo[u8Index].u16MsgCycleTimeFast)
				{
					CanIf_strTxCtrl[u8Index].u16MsgCycleTimeFastCnt	+= 10u;
				}
				if (CanIf_strTxCtrl[u8Index].u16MsgCycleTimeFastCnt >= 
					CanIf_kstrTxMsgInfo[u8Index].u16MsgCycleTimeFast)
				{
					CanIf_strTxCtrl[u8Index].u16MsgCycleTimeFastCnt = 0u;
					CanIf_strTxCtrl[u8Index].bSend = TRUE;
					CanIf_strTxCtrl[u8Index].u8MsgNbOfRepetitionCnt --;			
				}


				CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt = 0u;			
			}
			else
			{
				/*periodic msg handling*/
				if (CanIf_kstrTxMsgInfo[u8Index].enuMsgSendType == MST_Cycle)
				{
					if (CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt < 
						CanIf_kstrTxMsgInfo[u8Index].u16MsgCycleTime)
					{
						CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt	+= 10u;
					}
					if (CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt >= 
						CanIf_kstrTxMsgInfo[u8Index].u16MsgCycleTime)
					{
						CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt = 0u;
						CanIf_strTxCtrl[u8Index].bSend = TRUE;
					}
					
				}
			}
		
			
			/*send handling*/
			if (CanIf_strTxCtrl[u8Index].bSend == TRUE)
			{
				/*call send indication*/
				CanIf_kstrTxMsgInfo[u8Index].vidTxIndication(CanIf_kstrTxPduBuf[u8Index].pu8Data);
				/*call send function*/
				strPdu.u32CanId = CanIf_kstrTxMsgInfo[u8Index].strPdu.u32CanId;
				strPdu.u8Dlc = CanIf_kstrTxMsgInfo[u8Index].strPdu.u8Dlc;
				strPdu.pu8Data = CanIf_kstrTxPduBuf[u8Index].pu8Data;
				
				u8SendMsg(CanIf_kstrTxMsgInfo[u8Index].u8MsgBufInd,strPdu);
				/*init parameters after sending*/
				CanIf_strTxCtrl[u8Index].bSend = FALSE;
				
				/*break; send only one time*/
			}
			
		}
		/*Mcu_vidEnableInterrupts();*/
	}

}

#if 0u
void CanIf_vidSetAppTxDelay(void)
{
	uint8 u8Index;
	uint8 u8Tmp = 0u;
	uint16 u16Tmp;
	/*Mcu_vidDisableInterrupts();*/
	for (u8Index = 0u; u8Index < COM_TXPDUNUM; u8Index++)
	{
		/*periodic msg handling*/
		if (CanIf_kstrTxMsgInfo[u8Index].enuMsgSendType == MST_Cycle)
		{
			u8Tmp ++;
			u16Tmp = u8Tmp * 10;
			if (u16Tmp < CanIf_kstrTxMsgInfo[u8Index].u16MsgCycleTime)
			{
				CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt = 
					CanIf_kstrTxMsgInfo[u8Index].u16MsgCycleTime - u16Tmp;
			}
			
		}
	}			
}
#endif


void CanIf_vidSetAppCycMsgTxTrue(void)
{
	uint8 u8Index;
	/*Mcu_vidDisableInterrupts();*/
	for (u8Index = 0u; u8Index < COM_TXPDUNUM; u8Index++)
	{
		/*periodic msg handling*/
		if (CanIf_kstrTxMsgInfo[u8Index].enuMsgSendType == MST_Cycle)
		{
			CanIf_strTxCtrl[u8Index].u16MsgCycleTimeCnt = 0u;
			CanIf_strTxCtrl[u8Index].bSend = TRUE;			
		}
	}	
}

void CanIf_vidSetAppCycMsgTxFalse(void)
{
	uint8 u8Index;
	/*Mcu_vidDisableInterrupts();*/
	for (u8Index = 0u; u8Index < COM_TXPDUNUM; u8Index++)
	{
		/*periodic msg handling*/
		if (CanIf_kstrTxMsgInfo[u8Index].enuMsgSendType == MST_Cycle)
		{
			CanIf_strTxCtrl[u8Index].bSend = FALSE;			
		}
	}	
}



/*-------------------------------- end of file -------------------------------*/

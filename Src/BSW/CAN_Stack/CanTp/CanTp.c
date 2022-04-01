/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : CanTp                                                   */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : Can transport layer interface                           */
/*                                                                            */
/* !Module          : CanTp                                                   */
/* !Description     : Can transport layer interface                           */
/*                                                                            */
/* !File            : CanTp.c                                                 */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanTp/CanTp.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:12   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:06   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
/*to be tested : modified 20180719 by YCP*/
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Platform_Types.h"
#include "CanTp.h"
#include "CanDiag.h"
#include "CanIf.h"
#include "Can_Hdl.h"
#include "MCU_Manager.h"
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
static CanTp_tstrTpPduType CanTp_strTpPdu;
static CanTp_tenuTpStatusType CanTp_enuTpStatus;

static boolean CanTp_bFlagTpRecvPduCF;
static boolean CanTp_bFlagTpRecvPduFC;
static CanTp_tstrMfRecvStatType CanTp_strMfRecvStat;
static CanTp_tstrMfSendStatType CanTp_strMfSendStat;

static CanTp_tstrFlowControlType CanTp_strFlowControlGot;
static uint8 CanTp_u8FramesRecvFc;

static CanTp_tenuMfRecvStepType CanTp_enuMfRecvStep;
static CanTp_tenuMfSendStepType CanTp_enuMfSendStep;
static uint16 CanTp_u16TimeCnt;
static uint8 CanTp_u8FramesSent;
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidTpRecvPduSF(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa);
static void vidTpRecvPduFF(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa);
static void vidTpRecvPduCF(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa);
static void vidTpRecvPduFC(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa);
static void vidTpSendPduResp(void);
static void vidTpSendPduFC(void);
static void vidTpSendPduCF(void);
static void vidTpHandleReset(void);
/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
static void vidTpSendPduResp(void)
{
	uint8 au8MsgBuf[8];
	uint8 u8Ind;
	if (CanTp_strTpPdu.u16DataLen <= 7u)
	{
		/*single frame send*/
		au8MsgBuf[0] =  (uint8)(CanTp_strTpPdu.u16DataLen);
		for (u8Ind = 0u; u8Ind < CanTp_strTpPdu.u16DataLen; u8Ind++)
		{
			au8MsgBuf[u8Ind + 1u] = CanTp_strTpPdu.au8TpBuf[u8Ind];
		}
		/*other data filled with 0*/
		for (u8Ind = CanTp_strTpPdu.u16DataLen; u8Ind < 7u; u8Ind++)
		{
			au8MsgBuf[u8Ind + 1u] = 0x55u;
		}	
		if(CanDiag_u8GetForbPosRes() == 0x0u)
		{
			Can_u8CanMsgSendIdDatDlc(TP_MSG_TX_BUFFER_ID, 
			TP_MSG_TX_ID, au8MsgBuf, 8u/* CanTp_strTpPdu.u16DataLen + 1u */);
		}
        CanTp_vidInit();
	}
	else
	{
		/*multi frame send*/
		if(CanTp_enuTpStatus == CANTP_TST_IDLE)
		{
			/*first frame send*/
			au8MsgBuf[0] = 0x10u + 
				(uint8)((CanTp_strTpPdu.u16DataLen >> 8) & 0x000fu);
			au8MsgBuf[1] = (uint8)(CanTp_strTpPdu.u16DataLen & 0x00ffu);				
			for (u8Ind = 0u; u8Ind < 6u; u8Ind ++)
			{
				au8MsgBuf[u8Ind + 2u] = CanTp_strTpPdu.au8TpBuf[u8Ind];
			}
			if (CanTp_strTpPdu.u16DataLen <= CANTP_u16BUFLEN_MAX)
			{			
				if(CanDiag_u8GetForbPosRes() == 0x0u)
				{
					Can_u8CanMsgSendIdDatDlc(TP_MSG_TX_BUFFER_ID, 
					TP_MSG_TX_ID, au8MsgBuf, 8u);
				}
					
				CanTp_strMfSendStat.u8Err = CANTP_u8ERR_NOERR;
				CanTp_strMfSendStat.u16DlcSent = (uint16)6;
				CanTp_strMfSendStat.u8LastInd = 0u;
					
				CanTp_enuTpStatus = CANTP_TST_MF_SENDING;
			}
			else
			{
				/*len > 1024 : don't send*/
                CanTp_vidInit();
			}
		}
	}
}

static void vidTpSendPduFC(void)
{
	uint8 au8MsgBuf[8];

	au8MsgBuf[0] = 0x30u + CANTP_u8FLOWSTATUS; /*(0 = Clear To Send, 1 = Wait, 2 = Overflow/abort)*/
	au8MsgBuf[1] = CANTP_u8BLOCKSIZE; /*Maximum number of CF without FC,0 means no ctrl*/
	au8MsgBuf[2] = CANTP_u8STMIN; /*STmin:0~127ms*/
	/* if(CanDiag_u8GetForbPosRes() == 0x0u) */
	{
		Can_u8CanMsgSendIdDatDlc(TP_MSG_TX_BUFFER_ID, 
		TP_MSG_TX_ID, au8MsgBuf, 3u);
	}
	
	
}

static void vidTpSendPduCF(void)
{
	uint8 au8MsgBuf[8];
	uint8 u8Ind;
	boolean bFinished = FALSE;
	

	if (CanTp_strMfSendStat.u8LastInd == 0u)
	{
		CanTp_strMfSendStat.u8LastInd = 0x21u;
	}
	else
	{
		CanTp_strMfSendStat.u8LastInd ++;
		if (CanTp_strMfSendStat.u8LastInd > 0x2f)
		{
			CanTp_strMfSendStat.u8LastInd = 0x20u;
		}
	}
	au8MsgBuf[0] = CanTp_strMfSendStat.u8LastInd;

	for (u8Ind = 0u; u8Ind < 7u; u8Ind ++)
	{
		au8MsgBuf[u8Ind + 1] = 
			CanTp_strTpPdu.au8TpBuf[CanTp_strMfSendStat.u16DlcSent];
		CanTp_strMfSendStat.u16DlcSent ++;
		if (CanTp_strMfSendStat.u16DlcSent >= CanTp_strTpPdu.u16DataLen)
		{
			bFinished = TRUE;
			break;
		}
	}
	/*fill with other data with 0*/
	u8Ind++;
	if (bFinished == TRUE)
	{
		while (u8Ind < 7u)
		{
			au8MsgBuf[u8Ind + 1] = 0u;
			u8Ind ++;
		}
	}
	/* if(CanDiag_u8GetForbPosRes() == 0x0u) */
	{
		Can_u8CanMsgSendIdDatDlc(TP_MSG_TX_BUFFER_ID, 
			TP_MSG_TX_ID, au8MsgBuf,	8u);
	}
	

	if (bFinished == TRUE)
	{
		/*sent finished*/
		CanTp_vidInit();
	}
	
}

static void vidTpRecvPduSF(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa)
{
	uint8 u8Ind;
	uint16 u16Len;
	CanDiag_tstrMsgContextType strDmc;
	u16Len = (strPdu.pu8Data[0] & 0x0fu);
	CanTp_strTpPdu.u32CanId = strPdu.u32CanId;
	CanTp_strTpPdu.u16DataLen = u16Len;	

	if (u16Len <= 7u)
	{
		for (u8Ind=0u; u8Ind < ((uint8)u16Len); u8Ind++)
		{
			CanTp_strTpPdu.au8TpBuf[u8Ind] =
                            strPdu.pu8Data[u8Ind + 1];
		}
		strDmc.msgAddInfo.suppressPosResponse = 0u;
	}
	else
	{
		/*expect negative response*/
		strDmc.msgAddInfo.suppressPosResponse = 1u;		
	}
	strDmc.msgAddInfo.reqType = (uint8)enuTpTa;
	strDmc.msgAddInfo.cancelOperation = 0u;	
	strDmc.reqData = CanTp_strTpPdu.au8TpBuf;
        strDmc.resData = CanTp_strTpPdu.au8TpBuf;       
	strDmc.reqDataLen = CanTp_strTpPdu.u16DataLen;

	strDmc.u32CanId = CanTp_strTpPdu.u32CanId;	
	
	/*call CanDiag functions*/
/* 	CanDiag_vidCanDiagHandle(&strDmc);
	CanTp_strTpPdu.u16DataLen = strDmc.resDataLen;	 */
	if ((u16Len <= 7u) && (strPdu.u8Dlc > u16Len))
	{
		CanDiag_vidSetCanDiagMsg(strDmc);
	}
	
	CanTp_enuTpStatus = CANTP_TST_IDLE;/*to be tested : modified 20180719 by YCP*/
	/*send resp data on CAN */
	/* vidTpSendPduResp(); */
	
}

static void vidTpRecvPduFF(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa)
{
	uint16 u16Tmp;
	
	/*don't handle function addr*/
	if (enuTpTa == CANTP_TTT_FUNCTIONAL)
	{
		/*do nothing*/
	}
	else
	{
		u16Tmp = (((uint16)(strPdu.pu8Data[0] & 0x0fu)) << 8) + strPdu.pu8Data[1];
		if ((u16Tmp >= 8u) && (u16Tmp <= CANTP_u16BUFLEN_MAX))
		{
			CanTp_strTpPdu.u32CanId = strPdu.u32CanId;
			CanTp_strTpPdu.u16DataLen = u16Tmp;	
			
			for (u16Tmp = 0u; u16Tmp < 6u; u16Tmp++)
			{
				CanTp_strTpPdu.au8TpBuf[u16Tmp] = strPdu.pu8Data[2u+u16Tmp];
			}
			CanTp_strMfRecvStat.u16DlcRecved = 6u;
			CanTp_strMfRecvStat.u8LastInd = 0x20u;
			/*inform main task to handle recv procedure*/
			CanTp_enuTpStatus = CANTP_TST_MF_RECVING;	
			CanTp_u8FramesRecvFc = 0u;
		}
		else
		{
			CanTp_vidInit();
		}
	}
}

static void vidTpRecvPduCF(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa)
{
	uint8 u8Tmp;
	boolean bFinished = FALSE;
	
	/*check if no timeout*/
	if (CanTp_strTpPdu.u32CanId != strPdu.u32CanId)
	{
		CanTp_strMfRecvStat.u8Err = CANTP_u8ERR_ERR;
	}
	
	if ((CanTp_strMfRecvStat.u8LastInd + 1u) != strPdu.pu8Data[0])
	{
		CanTp_strMfRecvStat.u8Err = CANTP_u8ERR_ERR;
	}
	
	if (CanTp_strMfRecvStat.u8Err == CANTP_u8ERR_NOERR)
	{
		CanTp_bFlagTpRecvPduCF = TRUE;
		
		/*recv 1~n frame*/
		for (u8Tmp = 0u; u8Tmp < 7u; u8Tmp++)
		{
				CanTp_strTpPdu.au8TpBuf[CanTp_strMfRecvStat.u16DlcRecved] = strPdu.pu8Data[1u+u8Tmp];
			CanTp_strMfRecvStat.u16DlcRecved ++;
			if (CanTp_strMfRecvStat.u16DlcRecved >=	CanTp_strTpPdu.u16DataLen)
			{
				bFinished = TRUE;
				break;
			}
		}
		/*set last recv index*/
		CanTp_strMfRecvStat.u8LastInd = strPdu.pu8Data[0];
		if (CanTp_strMfRecvStat.u8LastInd == 0x2Fu)
		{
			CanTp_strMfRecvStat.u8LastInd = 0x1Fu;
		}
		/*recv finished check*/
		if (bFinished == TRUE)
		{
			CanDiag_tstrMsgContextType strDmc;

			strDmc.msgAddInfo.suppressPosResponse = 0u;
			strDmc.msgAddInfo.reqType = (uint8)enuTpTa;
			strDmc.msgAddInfo.cancelOperation = 0u;	
			strDmc.reqData = CanTp_strTpPdu.au8TpBuf;
                        strDmc.resData = CanTp_strTpPdu.au8TpBuf;
			strDmc.reqDataLen = CanTp_strTpPdu.u16DataLen;
			strDmc.u32CanId = CanTp_strTpPdu.u32CanId;	

            CanTp_enuTpStatus = CANTP_TST_IDLE; /*send finished,need to call resp*/
			/*call CanDiag functions*/
/* 			CanDiag_vidCanDiagHandle(&strDmc);
			CanTp_strTpPdu.u16DataLen = strDmc.resDataLen; */
			/*send resp data on CAN */
/* 			vidTpSendPduResp();	 */
			if ((u8Tmp + 2u) <= strPdu.u8Dlc) /*check if dlc is correct*/
			{
				CanDiag_vidSetCanDiagMsg(strDmc);
			}

			
		}
		else
		{
			CanTp_u8FramesRecvFc ++;
		}
	}
	else
	{
		/*if possible need to handle the err*/
		
		/*init*/
		CanTp_vidInit();
	}
}

static void vidTpRecvPduFC(Can_tstrPduType strPdu, CanTp_tenuTpTaType enuTpTa)
{
	
	if (strPdu.u8Dlc < 3u)
	{
		CanTp_bFlagTpRecvPduFC = FALSE;
	}
	else
	{
		CanTp_strFlowControlGot.u8FlowStatus = strPdu.pu8Data[0] - 0x30u;
		CanTp_strFlowControlGot.u8BlockSize = strPdu.pu8Data[1];	
		CanTp_strFlowControlGot.u8STMin = strPdu.pu8Data[2];		

		
		if (CanTp_strFlowControlGot.u8FlowStatus >= 2u)
		{
			/*mistake handling*/
			CanTp_bFlagTpRecvPduFC = FALSE;
			vidTpHandleReset();		
			CanTp_strFlowControlGot.u8FlowStatus = 0u;
		}
		else if (CanTp_strFlowControlGot.u8FlowStatus == 1u) /*wait*/
		{
			CanTp_bFlagTpRecvPduFC = FALSE;
		}
		else
		{
			CanTp_bFlagTpRecvPduFC = TRUE;
		}

		if (enuTpTa == CANTP_TTT_FUNCTIONAL)
		{
			CanTp_bFlagTpRecvPduFC = FALSE;
			vidTpHandleReset();		
			CanTp_strFlowControlGot.u8FlowStatus = 0u;
		}	
		
		if (CanTp_strFlowControlGot.u8STMin > 127u)
		{
			CanTp_strFlowControlGot.u8STMin = 127u;
		}	
	}

}

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void CanTp_vidInit(void)
{
	uint16 u16Ind;
	for (u16Ind=0u; u16Ind < CANTP_u16BUFLEN_MAX; u16Ind++)
	{
		CanTp_strTpPdu.au8TpBuf[u16Ind]=0u;
	}
	CanTp_strTpPdu.u32CanId = 0u;
	CanTp_strTpPdu.u16DataLen = 0u;
	CanTp_enuTpStatus = CANTP_TST_IDLE;

	CanTp_bFlagTpRecvPduCF = FALSE;
	CanTp_bFlagTpRecvPduFC = FALSE;
	CanTp_strMfRecvStat.u8Err = CANTP_u8ERR_NOERR;
	CanTp_strMfRecvStat.u16DlcRecved = (uint16)0;
	CanTp_strMfRecvStat.u8LastInd = 0u;
	
	CanTp_strMfSendStat.u8Err = CANTP_u8ERR_NOERR;
	CanTp_strMfSendStat.u16DlcSent = (uint16)0;
	CanTp_strMfSendStat.u8LastInd = 0u;
	CanTp_strFlowControlGot.u8FlowStatus = 0u;
	CanTp_strFlowControlGot.u8BlockSize = 0u;	
	CanTp_strFlowControlGot.u8STMin = 0u;
	CanTp_u8FramesRecvFc = 0u;
	vidTpHandleReset();
	CanTp_enuMfRecvStep = CANTP_MRST_SENDFC;
	CanTp_enuMfSendStep = CANTP_MSST_RECVFC;
	CanTp_u16TimeCnt = 0u;
	CanTp_u8FramesSent = 0u;	
}

void CanTp_vidManage(void)
{
	if (CanTp_enuTpStatus == CANTP_TST_IDLE)
	{
		vidTpHandleReset();
	}
	else if (CanTp_enuTpStatus == CANTP_TST_MF_RECVING)
	{
		switch (CanTp_enuMfRecvStep)
		{
			case CANTP_MRST_SENDFC :
				/*send FC*/
				vidTpSendPduFC();	/*if need delay ,call after a delay*/
				CanTp_u16TimeCnt = 0u;
				CanTp_enuMfRecvStep = CANTP_MRST_CFTOCHK;
				break;
			case CANTP_MRST_CFTOCHK :
				/*check if received CF frame*/
				MCU_vidDisableInterrupts();
				if (CanTp_bFlagTpRecvPduCF == TRUE)
				{
					CanTp_u16TimeCnt = 0u;
					CanTp_bFlagTpRecvPduCF = FALSE;
					if (CANTP_u8BLOCKSIZE > 0u) /*ycp : 20180322 don't do ctrl if bs=0*/
					{
						if (CanTp_u8FramesRecvFc >= CANTP_u8BLOCKSIZE)
						{
							CanTp_enuMfRecvStep = CANTP_MRST_SENDFC;
							CanTp_u8FramesRecvFc = 0u;
						}
					}
				}
				MCU_vidEnableInterrupts();
				if (CanTp_u16TimeCnt < CANTP_u16TIMEOUT_FIRSTCF)
				{
					CanTp_u16TimeCnt += 10u;
				}
				else
				{
					/*time out*/
					MCU_vidDisableInterrupts();					
					CanTp_strMfRecvStat.u8Err = CANTP_u8ERR_ERR;
					MCU_vidEnableInterrupts();					
				}
				break;
			
			default :
			
				break;
			
		}
		MCU_vidDisableInterrupts();
		if (CanTp_strMfRecvStat.u8Err == CANTP_u8ERR_ERR)
		{
			/*if possible need to handle the err*/
		
			/*init*/
			CanTp_vidInit();
		}
		MCU_vidEnableInterrupts();
		
	}
	else if (CanTp_enuTpStatus == CANTP_TST_MF_SENDING)
	{
		/*check timeout of FC recv*/
		switch (CanTp_enuMfSendStep)
		{
			case CANTP_MSST_RECVFC :
				MCU_vidDisableInterrupts();
				if (CanTp_bFlagTpRecvPduFC == TRUE)
				{
					CanTp_u16TimeCnt = 0u;
					CanTp_enuMfSendStep = CANTP_MSST_SENDCF;
					CanTp_bFlagTpRecvPduFC = FALSE;
				}
				MCU_vidEnableInterrupts();
				if (CanTp_u16TimeCnt < CANTP_u16TIMEOUT_RECVFC)
				{
					CanTp_u16TimeCnt += 10u;
				}
				else
				{
					/*time out*/
					MCU_vidDisableInterrupts();					
					CanTp_strMfSendStat.u8Err = CANTP_u8ERR_ERR;
					MCU_vidEnableInterrupts();					
				}			
				break;
			case CANTP_MSST_SENDCF :
				if (CanTp_u16TimeCnt < CanTp_strFlowControlGot.u8STMin)
				{
					CanTp_u16TimeCnt += 10u;
				}
				else
				{
					/*time to send CF*/
					vidTpSendPduCF();
					if (CanTp_strFlowControlGot.u8BlockSize > 0u) /*ycp : 20180322 don't do ctrl if bs=0*/
					{
						CanTp_u8FramesSent ++;
						if (CanTp_u8FramesSent >= CanTp_strFlowControlGot.u8BlockSize)
						{
							/*need next frame control*/
							CanTp_enuMfSendStep = CANTP_MSST_RECVFC;
							CanTp_u8FramesSent = 0u;
						}
					}
					CanTp_u16TimeCnt = 0u;
				}
				break;
			default :
			
				break;
		}
		MCU_vidDisableInterrupts();
		if (CanTp_strMfSendStat.u8Err == CANTP_u8ERR_ERR)
		{
			/*if possible need to handle the err*/
		
			/*init*/
			CanTp_vidInit();
		}
		MCU_vidEnableInterrupts();		
		
		
	}

}

void CanTp_vidCanTpRxIndication(Can_tstrPduType strPdu, 
	CanTp_tenuTpTaType enuTpTa)
{
/*	static uint32 LOC_u32CanIdLast = 0u;*/
	uint8 u8Tmp;
	u8Tmp = ((strPdu.pu8Data[0] & 0xF0u) >> 4u);
	switch (u8Tmp)
	{
		case 0u:
			/*if in multi frame tx or rx status : disable the recv*/
/* 			if (CanTp_enuTpStatus == CANTP_TST_IDLE)
			{ */
			if ((CanTp_enuMfSendStep == CANTP_MSST_SENDCF) || 
				(CanTp_bFlagTpRecvPduFC == TRUE))
			{
				
			}
			else
			{
				vidTpHandleReset();
				vidTpRecvPduSF(strPdu, enuTpTa);
/*				LOC_u32CanIdLast = strPdu.u32CanId;*/
			}
/* 			} */
			break;
		case 1u:
/* 			if (CanTp_enuTpStatus == CANTP_TST_IDLE)
			{ */	
			if ((CanTp_enuMfSendStep == CANTP_MSST_SENDCF) || 
				(CanTp_bFlagTpRecvPduFC == TRUE))
			{
				
			}
			else
			{				
				vidTpHandleReset();		
				vidTpRecvPduFF(strPdu, enuTpTa);
/*				LOC_u32CanIdLast = strPdu.u32CanId;*/
			}
/* 			} */
			break;		
		case 2u:
			if (CanTp_enuTpStatus == CANTP_TST_MF_RECVING)
			{
				vidTpRecvPduCF(strPdu, enuTpTa);
			}
			break;
		case 3u:
			if ((CanTp_enuTpStatus == CANTP_TST_MF_SENDING) &&
				(CanTp_enuMfSendStep != CANTP_MSST_SENDCF))
			{
/* 				if (LOC_u32CanIdLast == strPdu.u32CanId)
				{ */
					vidTpRecvPduFC(strPdu, enuTpTa);
/* 				}
				else
				{
					vidTpHandleReset();
				} */
			}
			break;
		default :
			/*cancel the recv and send*/

			break;
	}
}

void vidTpHandleReset(void)
{
	CanTp_u16TimeCnt = 0u;		
	CanTp_enuMfRecvStep = CANTP_MRST_SENDFC;
	CanTp_enuMfSendStep = CANTP_MSST_RECVFC;
	CanTp_u8FramesSent = 0u;
	CanTp_bFlagTpRecvPduCF = FALSE;
	CanTp_bFlagTpRecvPduFC = FALSE;		
		
}

void CanTp_vidDataCopy(uint8* pu8Dest,uint8* pu8Src,uint16 u16Cnt)
{
    uint16 i = 0u;
    for(i = 0u;i < u16Cnt;i++)
    {
        *(pu8Dest + i) = *(pu8Src + i);
    }
}

void CanTp_vidDataSet(uint8* pu8Dest,uint8 u8Val,uint16 u16Cnt)
{
    uint16 i = 0u;
    for(i = 0u;i < u16Cnt;i++)
    {
        *(pu8Dest + i) = u8Val;
    }	
}

void CanTp_vidDiagResp(uint16 u16DataLen)
{
	CanTp_strTpPdu.u16DataLen = u16DataLen;
	vidTpSendPduResp();
}

/*-------------------------------- end of file -------------------------------*/

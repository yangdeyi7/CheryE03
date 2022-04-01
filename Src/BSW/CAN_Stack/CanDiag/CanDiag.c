/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : CanDiag                                                 */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !Module          : CanDiag                                                 */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !File            : CanDiag.c                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanDiag/CanDiag.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:08   chunping.yan
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
#include "CanDiag.h"
#include "CanDiag_Cfg.h"
#include "mcu.h"
#include "CanTp.h"
#include "AppDiag.h"
#include "CanIf.h"
#include "Eeprom.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define u16RUNTIMER_MAX 				10000u  /*100s unit:10ms*/
#define u16SECTIME_DELAY 				1000u  	/*10s unit:10ms*/
#define u16NEXSECACCTIMER_MAX 			1000u  /*10s unit:10ms*/


#define u32ENCRYPTCONSTANT				0x30001101u
#define u32ENCRYPTMASK					0x30001101u
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef enum
{
	CANDIAG_SART_RECVSEED,
	CANDIAG_SART_RECVKEY	
} CanDiag_tenuSecAccRecvType;

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
static uint8 CanDiag_u8SessionMsk;
static uint8 CanDiag_u8SecLvl;
static uint16 CanDiag_u16SesToTimer;
static boolean CanDiag_bECUReset;
static uint16 CanDiag_u16RunTimer;
static CanDiag_tenuSecAccRecvType CanDiag_enuSecAccRecv;
static uint8 CanDiag_u8SecAccErrCnt;
static uint16 CanDiag_u16NextSecAccTimer;

static CanDiag_tstrMsgContextType CanDiag_strDmc;
static boolean CanDiag_bMsgRecved;
static uint8 CanDiag_u8SeedsCounter;
//static boolean CanDiag_bRoutineStarted;
uint8 CanDiag_u8ForbPosRes;
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static uint8 u8CheckServiceSupport(CanDiag_tstrMsgContextType *pMsgContext);
static uint8 u8TesterPresent(CanDiag_tstrMsgContextType *pMsgContext);

static uint8 u8DiagnosticSessionControl(CanDiag_tstrMsgContextType *pMsgContext);
static uint8 u8ECUReset(CanDiag_tstrMsgContextType *pMsgContext);
static uint8 u8SecurityAccess(CanDiag_tstrMsgContextType *pMsgContext);
static uint8 u8CommunicationControl(CanDiag_tstrMsgContextType *pMsgContext);
static uint8 u8RoutineControl(CanDiag_tstrMsgContextType *pMsgContext);

static void vidSessionManage(void);
static void vidECUResetManage(void);
static void vidSecurityManage(void);

static void vidDefaultSessionInit(void);
static void vidSetSeeds(uint8* pau8Data);
static void vidSendNegResp(CanDiag_tstrMsgContextType *pMsgContext, 
	uint8 u8NRC);
static void vidCanDiagPhyHandle(void);
static void vidCanDiagFuncHandle(void);



static uint8 AppDtc_u8ControlDTCSetting(CanDiag_tstrMsgContextType *pMsgContext);


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
static void vidCanDiagFuncHandle()
{
	uint8 u8NRC = 0u;
	uint8 u8ForbPosReq = 0u;
	uint8 u8DID;
	CanDiag_tstrMsgContextType *pMsgContext = &CanDiag_strDmc;
	u8DID = pMsgContext->reqData[0];
	CanDiag_u16SesToTimer = 0u;
	if (pMsgContext->reqDataLen == 0u)
	{
		pMsgContext->resDataLen = 0u;
		/*do nothing : no response*/
	}
	else
	{
		/*20180712  forbidden posetive bit*/
		if((u8DID == 0x10u)||
			(u8DID == 0x28u)||
			(u8DID == 0x3eu)||
			(u8DID == 0x85u))
			{
				if((pMsgContext->reqData[1] & 0x80) == 0x80)
				{
					u8ForbPosReq = 1u;
				}
				pMsgContext->reqData[1] = pMsgContext->reqData[1] & 0x7f;
			}

		/*check if session support*/
		u8NRC = u8CheckServiceSupport(pMsgContext);
		if (u8NRC == 0x00u)
		{
		
			switch (pMsgContext->reqData[0]) /*SER ID*/
			{
				case 0x10u: /*DiagnosticSessionControl*/
					u8NRC = u8DiagnosticSessionControl(pMsgContext);
					/*lock ECU*/
					CanDiag_u8SecLvl = CANDIAG_u8SECLMT_LVL0;
					break;
				case 0x11u: /*ECUReset*/
					u8NRC = u8ECUReset(pMsgContext);
                    /*lock ECU*/
                    CanDiag_u8SecLvl = CANDIAG_u8SECLMT_LVL0; 					
					break;
				case 0x14u: /*ClearDiagnosticInformation*/
					//u8NRC = AppDtc_u8ClearDiagnosticInformation(pMsgContext);
					break;
				case 0x19u: /*ReadDTCInfomation*/
					//u8NRC = AppDtc_u8ReadDTCInfomation(pMsgContext);
					break;
				case 0x22u: /*ReadDataByIdentifier*/
					u8NRC = AppDiag_u8ReadDataByIdentifier(pMsgContext);
					break;
				case 0x23u: /*ReadMemoryByAddress*/
					u8NRC = AppDiag_u8ReadMemoryByAddress(pMsgContext);
					break;
				case 0x27u: /*SecurityAccess*/
					u8NRC = u8SecurityAccess(pMsgContext);
					break;
				case 0x28u: /*CommunicationControl*/
					u8NRC = u8CommunicationControl(pMsgContext);
					break;
				case 0x2Au: /*ReadDataByPeriodicIdentifier*/
					u8NRC = 0x11u;
					break;
				case 0x2Cu: /*DynamicallyDefinitionDataIdentifier*/
					u8NRC = 0x11u;
					break;
				case 0x2Eu: /*WriteDataByIdentifier*/
					u8NRC = AppDiag_u8WriteDataByIdentifier(pMsgContext);
					break;
				case 0x2Fu: /*InputOutputControlByIdentifier*/
					u8NRC = AppDiag_u8InputOutputControlByIdentifier(pMsgContext);
					break;
				case 0x31u: /*RoutineControl*/
					u8NRC = u8RoutineControl(pMsgContext);
					break;
				case 0x34u: /*RequestDownload*/
					u8NRC = 0x11u;
					break;
				case 0x36: /*TransferData*/
					u8NRC = 0x11u;
					break;
				case 0x37u: /*RequestTransferExit*/
					u8NRC = 0x11u;
					break;
				case 0x3Du: /*WriteMemoryByAddress*/
					u8NRC = AppDiag_u8WriteMemoryByAddress(pMsgContext);
					break;
				case 0x3Eu: /*TesterPresent*/
					u8NRC = u8TesterPresent(pMsgContext);
					break;
				case 0x85u: /*ControlDTCSetting*/
					u8NRC = AppDtc_u8ControlDTCSetting(pMsgContext);
					break;
				default:
					/*NRC = 0x11 : service not support*/
					u8NRC = 0x11u;
					break;
			}
		}
		
		if((u8DID == 0x22u)||
			(u8DID == 0x2eu)||
			(u8DID == 0x14u)||
			(u8DID == 0x2fu)||
			(u8DID == 0x34u)||
			(u8DID == 0x36u)||
			(u8DID == 0x37u))/*not support subfunction*/
			{
				if((u8NRC == 0x11u) || (u8NRC == 0x31u)||(u8NRC == 0x7fu)||(u8NRC == 0x7eu))
				{
					CanDiag_u8ForbPosRes = 0x1u;
				}
				else
				{
					CanDiag_u8ForbPosRes = 0x0u;
				}
			}
			else if((u8DID == 0x10u)||
				(u8DID == 0x28u)||
				(u8DID == 0x3eu)||
				(u8DID == 0x85u))  /*support sufuction but support forbidden*/
				{
					if (u8NRC > 0u)
					{
						if((u8NRC == 0x11u) || (u8NRC == 0x12u)||(u8NRC == 0x7fu)||(u8NRC == 0x7eu))
						{
							CanDiag_u8ForbPosRes = 0x1u;
						}
						else
						{
							vidSendNegResp(pMsgContext, u8NRC);
							CanDiag_u8ForbPosRes = 0x0u;
						}
					}
					else if(u8ForbPosReq == 1u)
					{
						CanDiag_u8ForbPosRes = 0x1u;
					}
					else
					{
						CanDiag_u8ForbPosRes = 0x0u;
					}
				}
				else
				{
					if (u8NRC > 0u)
					{
						if((u8NRC == 0x11u) || (u8NRC == 0x12u)||(u8NRC == 0x7fu)||(u8NRC == 0x7eu))
						{
							CanDiag_u8ForbPosRes = 0x1u;
						}
						else
						{
							vidSendNegResp(pMsgContext, u8NRC);
							CanDiag_u8ForbPosRes = 0x0u;
						}
					}
					else
					{
						CanDiag_u8ForbPosRes = 0x0u;
					}
				}
	}
}


static void vidCanDiagPhyHandle()
{
	uint8 u8NRC = 0u;
	uint8 u8ForbPosReq = 0u;
	uint8 u8DID;
	CanDiag_tstrMsgContextType *pMsgContext = &CanDiag_strDmc;
	u8DID = pMsgContext->reqData[0];
	CanDiag_u16SesToTimer = 0u;
	if (pMsgContext->reqDataLen == 0u)
	{
		pMsgContext->resDataLen = 0u;
		/*do nothing : no response*/
	}
	else
	{
		/*20180712  forbidden posetive bit*/
		if((u8DID == 0x10u)||
			(u8DID == 0x28u)||
			(u8DID == 0x3eu)||
			(u8DID == 0x85u))
			{
				if((pMsgContext->reqData[1] & 0x80) == 0x80)
				{
					u8ForbPosReq = 1u;
				}
				pMsgContext->reqData[1] = pMsgContext->reqData[1] & 0x7f;
			}

		/*check if session support*/
		u8NRC = u8CheckServiceSupport(pMsgContext);
		if (u8NRC == 0x00u)
		{
		
			switch (pMsgContext->reqData[0]) /*SER ID*/
			{
				case 0x10u: /*DiagnosticSessionControl*/
					u8NRC = u8DiagnosticSessionControl(pMsgContext);
					/*lock ECU*/
					CanDiag_u8SecLvl = CANDIAG_u8SECLMT_LVL0;
					break;
				case 0x11u: /*ECUReset*/
					u8NRC = u8ECUReset(pMsgContext);
                    /*lock ECU*/
                    CanDiag_u8SecLvl = CANDIAG_u8SECLMT_LVL0; 					
					break;
				case 0x14u: /*ClearDiagnosticInformation*/
					//u8NRC = AppDtc_u8ClearDiagnosticInformation(pMsgContext);
					break;
				case 0x19u: /*ReadDTCInfomation*/
					//u8NRC = AppDtc_u8ReadDTCInfomation(pMsgContext);
					break;
				case 0x22u: /*ReadDataByIdentifier*/
					u8NRC = AppDiag_u8ReadDataByIdentifier(pMsgContext);
					break;
				case 0x23u: /*ReadMemoryByAddress*/
					u8NRC = AppDiag_u8ReadMemoryByAddress(pMsgContext);
					break;
				case 0x27u: /*SecurityAccess*/
					u8NRC = u8SecurityAccess(pMsgContext);
					break;
				case 0x28u: /*CommunicationControl*/
					u8NRC = u8CommunicationControl(pMsgContext);
					break;
				case 0x2Au: /*ReadDataByPeriodicIdentifier*/
					u8NRC = 0x11u;
					break;
				case 0x2Cu: /*DynamicallyDefinitionDataIdentifier*/
					u8NRC = 0x11u;
					break;
				case 0x2Eu: /*WriteDataByIdentifier*/
					u8NRC = AppDiag_u8WriteDataByIdentifier(pMsgContext);
					break;
				case 0x2Fu: /*InputOutputControlByIdentifier*/
					u8NRC = AppDiag_u8InputOutputControlByIdentifier(pMsgContext);
					break;
				case 0x31u: /*RoutineControl*/
					u8NRC = u8RoutineControl(pMsgContext);
					break;
				case 0x34u: /*RequestDownload*/
					u8NRC = 0x11u;
					break;
				case 0x36: /*TransferData*/
					u8NRC = 0x11u;
					break;
				case 0x37u: /*RequestTransferExit*/
					u8NRC = 0x11u;
					break;
				case 0x3Du: /*WriteMemoryByAddress*/
					u8NRC = AppDiag_u8WriteMemoryByAddress(pMsgContext);
					break;
				case 0x3Eu: /*TesterPresent*/
					u8NRC = u8TesterPresent(pMsgContext);
					break;
				case 0x85u: /*ControlDTCSetting*/
					u8NRC = AppDtc_u8ControlDTCSetting(pMsgContext);
					break;
				default:
					/*NRC = 0x11 : service not support*/
					u8NRC = 0x11u;
					break;
			}
		}
		
		if((u8DID == 0x10u)||
			(u8DID == 0x28u)||
			(u8DID == 0x3eu)||
			(u8DID == 0x85u))
			{
				if (u8NRC > 0u)
				{
					vidSendNegResp(pMsgContext, u8NRC);
					CanDiag_u8ForbPosRes = 0x0u;
				}
				else if(u8ForbPosReq == 1u)
				{
					CanDiag_u8ForbPosRes = 0x1u;
				}
				else
				{
					CanDiag_u8ForbPosRes = 0x0u;
				}
			}
			else
			{
				if (u8NRC > 0u)
				{
					vidSendNegResp(pMsgContext, u8NRC);
				}
				CanDiag_u8ForbPosRes = 0x0u;
			}
	}
}



static void vidDefaultSessionInit(void)
{
	/*security level return back to 0*/
	CanDiag_u8SecLvl = CANDIAG_u8SECLMT_LVL0;
	/*2F service init*/
	AppDiag_vidClearIoCtrlFlag();
	/*85 service init*/
	//AppDtc_vidEnableDetect(TRUE);
	/*other service init*/	
	
	/*28 service init*/
	/*CanIf_vidSetAppComDisable(0x00u);	*/
	CanIf_vidEnableAppComRx1();
	CanIf_vidEnableAppComTx1();
}

static void vidSetSeeds(uint8* pau8Data)
{
	pau8Data[0] = CanDiag_u8SeedsCounter;
	pau8Data[1] = CanDiag_u8SeedsCounter * 3;	
	pau8Data[2] = CanDiag_u8SeedsCounter * 5;
	pau8Data[3] = CanDiag_u8SeedsCounter * 7;	
}

static void vidECUResetManage(void)
{
	static uint8 LOC_u8Timer = 0u;
	if (CanDiag_bECUReset == TRUE)
	{
		if (LOC_u8Timer < 50u)
		{
			/*wait 200ms to reset*/
			LOC_u8Timer ++;
		}
		else
		{
			/*call appdiag to reset*/
			AppDiag_vidECUResetPost();
			LOC_u8Timer = 0u;
		}
	}
}

static void vidSecurityManage(void)
{
	Mcu_vidDisableInterrupts();
	if (CanDiag_u8SecAccErrCnt >= 3u)
	{
		if (CanDiag_u16NextSecAccTimer < u16NEXSECACCTIMER_MAX)
		{
			CanDiag_u16NextSecAccTimer ++;
		}
		else
		{
			CanDiag_u8SecAccErrCnt --;
			CanDiag_u16NextSecAccTimer = 0u;
		}
	}

	Mcu_vidEnableInterrupts();
	CanDiag_u8SeedsCounter ++;
}

static void vidSessionManage(void)
{
	Mcu_vidDisableInterrupts();
	if (CanDiag_u8SessionMsk != CANDIAG_u8SESLMT_DEFAULT_MSK)
	{
		if (CanDiag_u16SesToTimer < CANDIAG_u16TIMEOUT_SESSION_MAX)
		{
			CanDiag_u16SesToTimer += 10u;
		}
		else
		{
			CanDiag_u8SessionMsk = CANDIAG_u8SESLMT_DEFAULT_MSK;
			vidDefaultSessionInit();
		}
	}
	Mcu_vidEnableInterrupts();
}


static uint8 AppDtc_u8ControlDTCSetting(CanDiag_tstrMsgContextType *pMsgContext)
{
    uint8 u8NRC = 0u;
    if (u8NRC == 0x00u)
    {
		/*2st step : positive response*/
		pMsgContext->resData[0] = 0xc5u;
		pMsgContext->resData[1] = 0x02u;//pMsgContext->reqData[1];
		pMsgContext->resDataLen = 2u;		
    }
    return u8NRC;

}

/*sid=0x27:security access*/
static uint8 u8SecurityAccess(CanDiag_tstrMsgContextType *pMsgContext)
{	
	uint8 u8NRC = 0u;
	static uint8 LOC_au8Seeds[4];
	static uint8 LOC_u8SecLvlReq = CANDIAG_u8SECLMT_LVL0;
	uint8 u8Tmp;
	
	if ((pMsgContext->reqData[1] == 0x09u) && 
		(CanDiag_u8SessionMsk != CANDIAG_u8SESLMT_PROGRAMMING_MSK))
	{
		u8NRC = 0x7Eu; /*subFunctionNotSupportedInActiveSession*/		
	}

	/*it will not be availabe within 10s*/
	/*TBD:if programming procudure , ignore the 10s delay check*/
	if (CanDiag_u8SecAccErrCnt >= 3u)
	{
		u8NRC = 0x37u; /*delay time not arrive*/
	}
#if 0	/*cancel this in customer new UDS spec*/
	if (CanDiag_u16RunTimer < u16SECTIME_DELAY)
	{
		u8NRC = 0x22u; /*condition is not satisfied*/
	}
#endif
	if ((pMsgContext->reqData[1] == 0x01u) ||
	(pMsgContext->reqData[1] == 0x09u))
	{
		if(pMsgContext->reqDataLen == 2u)
		{
			/*do nothing*/
		}
		else
		{
			u8NRC = 0x13u; /*Length wrong*/
		}
	}
	else if ((pMsgContext->reqData[1] == 0x02u) ||
		(pMsgContext->reqData[1] == 0x0Au))
	{
		if(pMsgContext->reqDataLen == 6u)
		{
			/*do nothing*/
		}
		else
		{
			u8NRC = 0x13u; /*Length wrong*/
		}
	}
	else
	{
		u8NRC = 0x12u; /*sub function not support*/
	}
	

	
	
	if (u8NRC == 0u)
	{

		if ((pMsgContext->reqData[1] == 0x01u) ||
			(pMsgContext->reqData[1] == 0x09u))
		{	
		
			if (pMsgContext->reqData[1] == 0x01u)
			{
				LOC_u8SecLvlReq = CANDIAG_u8SECLMT_LVL1;
			}
			else if (pMsgContext->reqData[1] == 0x09u)
			{
				LOC_u8SecLvlReq = CANDIAG_u8SECLMT_LVL2;
			}
			if (CanDiag_u8SecLvl == LOC_u8SecLvlReq)
			{
				for (u8Tmp = 0u; u8Tmp < 4u; u8Tmp ++)
				{
					LOC_au8Seeds[u8Tmp] = 0u;
				}
			}
			else
			{
				/*set seed*/
				vidSetSeeds(LOC_au8Seeds);
				if (LOC_u8SecLvlReq == CANDIAG_u8SECLMT_LVL2)
				{
					if ((LOC_au8Seeds[0] == 0u) &&
						(LOC_au8Seeds[1] == 0u))
					{
						LOC_au8Seeds[0] += 1u;
					}
				}
			}
			
			if ((CanDiag_u8SecLvl == CANDIAG_u8SECLMT_LVL1) ||
				(CanDiag_u8SecLvl == CANDIAG_u8SECLMT_LVL2))
			{
				/*already unlocked*/	
					/*1st step : do something*/
					
					/*2st step : positive response*/
					pMsgContext->resData[0] = 0x67u;
					/*pMsgContext->resData[1] = pMsgContext->reqData[1];*/
					/*use default seeds*/
					CanTp_vidDataSet(&(pMsgContext->resData[2]), 0u, 4u);
					
					pMsgContext->resDataLen = 6u;				
			}
			else
			{
				if (u8NRC == 0u)
				{
					/*1st step : do something*/
					CanDiag_enuSecAccRecv = CANDIAG_SART_RECVKEY;
					/*2st step : positive response*/
					pMsgContext->resData[0] = 0x67u;
					/*pMsgContext->resData[1] = pMsgContext->reqData[1];*/
					CanTp_vidDataCopy(&(pMsgContext->resData[2]), LOC_au8Seeds, 4u);
					
					pMsgContext->resDataLen = 6u;				
					
				}
			}
		}
		else if ((pMsgContext->reqData[1] == 0x02u) ||
				(pMsgContext->reqData[1] == 0x0Au))
		{
			if (CanDiag_enuSecAccRecv != CANDIAG_SART_RECVKEY)
			{
				u8NRC = 0x24u; /*req sequence error*/	
			}
			if (CanDiag_u8SecLvl == LOC_u8SecLvlReq)
			{
				u8NRC = 0x24u; /*req sequence error*/
			}
			/*check key*/
			if (u8NRC == 0u)
			{
				u8Tmp = (uint8)AppDiag_bCheckKey(LOC_u8SecLvlReq, LOC_au8Seeds, 
					&(pMsgContext->reqData[2]));
				if (u8Tmp == (uint8)FALSE)
				{
					u8NRC = 0x35u;
					if (CanDiag_u8SecAccErrCnt < 3u)
					{
						CanDiag_u8SecAccErrCnt ++;
						CanDiag_u16NextSecAccTimer = 0u;
					}
				}
				else
				{
					/*1st step : do something*/
					CanDiag_u8SecAccErrCnt = 0u;
					CanDiag_u16NextSecAccTimer = 0u;
					CanDiag_u8SecLvl = LOC_u8SecLvlReq;
					/*2st step : positive response*/
					pMsgContext->resData[0] = 0x67u;
					/*pMsgContext->resData[1] = pMsgContext->reqData[1];*/
					pMsgContext->resDataLen = 2u;					
				}
			}
			
			CanDiag_enuSecAccRecv = CANDIAG_SART_RECVSEED;
		}
		else
		{
			u8NRC = 0x12u; /*sub function not support*/
			CanDiag_enuSecAccRecv = CANDIAG_SART_RECVSEED;
		}



	}
	
	return u8NRC;
}


/*sid=0x28:CommunicationControl*/
static uint8 u8CommunicationControl(CanDiag_tstrMsgContextType *pMsgContext)
{	
	uint8 u8NRC = 0x00u;
	uint8 u8Tmp;
#if 0
	

	if ((pMsgContext->reqData[2] < 0x01u) || (pMsgContext->reqData[2] > 0x03u))
	{
		/*com type out of range*/
		u8NRC = 0x31u;		
	}
	/*precondition check*/
	if (AppDiag_bPreConditionCheck(0x28u) == FALSE)
	{
		u8NRC = 0x22u; /*condition not satisfy*/
	}
	
	if(pMsgContext->reqDataLen == 3u)
	{
		/*do nothing*/
	}
	else
	{
		u8NRC = 0x13u; /*Length wrong*/
	}
	
	if ((pMsgContext->reqData[1] <= 0x01u) || (pMsgContext->reqData[1] == 0x03u))
	{
		/*do nothing*/
	}
	else
	{
		/*sub function not support*/
		u8NRC = 0x12u;
	}
#endif
	if (u8NRC == 0x00u)
	{
		/*1st step : do something*/
		u8Tmp = CanIf_u8GetAppComDisable();
		u8Tmp &= (~0x03);
		switch (pMsgContext->reqData[2])
		{
			case 0x01u:
				/*app com*/
				CanIf_vidSetAppComDisable(u8Tmp | (pMsgContext->reqData[1] & 0x03));
				break;
			case 0x02u:
				/*NM com*/
				//CanNm_vidSetComState(pMsgContext->reqData[1]);
				break;
			case 0x03u:
				/*NM and app com*/
				//CanIf_vidSetAppComDisable(u8Tmp | (pMsgContext->reqData[1] & 0x03));	
				//CanNm_vidSetComState(pMsgContext->reqData[1]);				
				break;
			default:
			
				break;
		}
		/*2st step : positive response*/
		pMsgContext->resData[0] = 0x68u;
		pMsgContext->resData[1] = 0x03u;//pMsgContext->reqData[1];
		pMsgContext->resDataLen = 2u;		
	}
	return u8NRC;
}


/*sid=0x31:RoutineControl*/
static uint8 u8RoutineControl(CanDiag_tstrMsgContextType *pMsgContext)
{	
	uint8 u8NRC = 0x00u;
#if 0
	uint16 u16RoutineId;
	if ((pMsgContext->reqData[1] < 0x01u) || (pMsgContext->reqData[1] > 0x03u))
	{
		/*sub function not support*/
		u8NRC = 0x12u;
	}
	else if (pMsgContext->reqData[1] > 0x01u)
	{
		if(pMsgContext->reqDataLen >= 4u)
		{
			/*routine code series check*/
			if (CanDiag_bRoutineStarted != TRUE)
			{
				/*routine code series error*/
				u8NRC = 0x24u;
			}	
		}
		else
		{
			u8NRC = 0x13u; /*Length wrong*/
		}

	}
	/*precondition check*/
	if (AppDiag_bPreConditionCheck(0x31u) == FALSE)
	{
		u8NRC = 0x22u; /*condition not satisfy*/
	}
	
	if (u8NRC == 0x00u)
	{
		/*1st step : do something*/
		u16RoutineId = ((pMsgContext->reqData[2] << 8) + pMsgContext->reqData[3]);
		switch (u16RoutineId )
		{
			case 0xFF02u:
				if (pMsgContext->reqData[1] == 0x01u) /*start routine*/
				{
					CanDiag_bRoutineStarted = TRUE;
				}
				else if (pMsgContext->reqData[1] == 0x02u) /*stop routine*/
				{
					CanDiag_bRoutineStarted = FALSE;
				}
				else if (pMsgContext->reqData[1] == 0x03u) /*req routine result*/
				{
	
				}
				if(pMsgContext->reqDataLen == 4u)/*ff02 must be 4 byte*/
				{
					
				}
				else
				{
					//u8NRC = 0x13u;/*length wrong*/
				}
				break;
			default:
				u8NRC = 0x31u; /*RID not support*/
				break;
		}
#endif
		/*2st step : positive response*/
		if (u8NRC == 0x00u)
		{
			pMsgContext->resData[0] = 0x71u;
			pMsgContext->resData[1] = 0x01;//pMsgContext->reqData[1];
			pMsgContext->resData[2] = 0xff;//pMsgContext->reqData[2];			
			pMsgContext->resData[3] = 0x02;//pMsgContext->reqData[3];
			pMsgContext->resData[4] = 0x00u;
			pMsgContext->resDataLen = 5u;
		}			
	return u8NRC;
}

/*SID=0x10 : session control*/
static uint8 u8DiagnosticSessionControl(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint8 u8NRC = 0u;
	uint8 u8SubFunc;
	u8SubFunc = pMsgContext->reqData[1];/* & (~0x80u);*/
	if ((u8SubFunc >= 1u) && (u8SubFunc <= 3u))
	{
		if(pMsgContext->reqDataLen == 2u)
		{
						/*1st step : do something*/
			switch (pMsgContext->reqData[1])
			{
				case 1u: /*default session*/
					CanDiag_u8SessionMsk = CANDIAG_u8SESLMT_DEFAULT_MSK;
					vidDefaultSessionInit();
					break;
				case 2u: /*programming session*/
					#if 0
					if (CanDiag_u8SessionMsk == CANDIAG_u8SESLMT_DEFAULT_MSK)
					{
						u8NRC = 0x7fu; /*0x22u*/
					}
					else
                                        #endif
					{
						CanDiag_u8SessionMsk = CANDIAG_u8SESLMT_PROGRAMMING_MSK;
						CanDiag_u16SesToTimer = 0u;
						
						/*save EEP*/
						EEP_u8WriteOneByte(EEP_ADDR_FBL, 0x5Au);
						
						/*  reset  */
						(*((void(*)(void))0x00))();


					}
					break;
				case 3u: /*extend session*/
					if (CanDiag_u8SessionMsk == CANDIAG_u8SESLMT_PROGRAMMING_MSK)
					{
						u8NRC = 0x22u;
					}
					else
					{
						CanDiag_u8SessionMsk = CANDIAG_u8SESLMT_EXTENDED_MSK;
						CanDiag_u16SesToTimer = 0u;		
					}				
					break;
			}
			
			/*2st step : positive response*/
			if (u8NRC == 0x00u)
			{
				if ((pMsgContext->reqData[1] & 0x80) > 0u)
				{
					pMsgContext->resDataLen = 0u; /*dont response*/
				}
				else
				{
					pMsgContext->resDataLen = 6u; 
				}
				pMsgContext->resData[0] = 0x50u;
				pMsgContext->resData[1] = pMsgContext->reqData[1]; /*sub function*/
				pMsgContext->resData[2] = (CANDIAG_u16TIMEOUT_P2SERVER_MAX / 256u);
				pMsgContext->resData[3] = (CANDIAG_u16TIMEOUT_P2SERVER_MAX % 256u);
				pMsgContext->resData[4] = ((CANDIAG_u16TIMEOUT_P2SERVER1_MAX / 10u) / 256u);
				pMsgContext->resData[5] = ((CANDIAG_u16TIMEOUT_P2SERVER1_MAX / 10u) % 256u);		
				
			}			
		}
		else
		{
			u8NRC = 0x13u; /*Length wrong*/
		}

	}
	else
	{
		u8NRC = 0x12u; /*sub function not support*/
	}
	return u8NRC;
}


static uint8 u8ECUReset(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint8 u8NRC = 0u;	
	if (pMsgContext->reqData[1] == 1u)
	{
		if(pMsgContext->reqDataLen == 2u)
		{
			/*1st step : do something*/
			CanDiag_bECUReset = TRUE;
			/*2st step : positive response*/
			pMsgContext->resData[0] = 0x51u;
			pMsgContext->resData[1] = pMsgContext->reqData[1];
			pMsgContext->resDataLen = 2u;
		}
		else
		{
			u8NRC = 0x13u; /*Length wrong*/
		}
		
	}
	else
	{
		u8NRC = 0x12u; /*sub function not support*/
	}	
	return u8NRC;
}

/*SID=0x3e : tester present*/
static uint8 u8TesterPresent(CanDiag_tstrMsgContextType *pMsgContext)
{
	/*session timer reset*/
	uint8 u8NRC = 0u;
	uint8 u8SubFunc;
	u8SubFunc = pMsgContext->reqData[1] & (~0x80u);
	if (u8SubFunc == 0u)
	{
		if(pMsgContext->reqDataLen == 2u)
		{
			if ((pMsgContext->reqData[1] & 0x80) > 0u)
			{
				pMsgContext->resDataLen = 0u; /*dont response*/
			}
			else
			{
				pMsgContext->resDataLen = 2u; 
			}		
			/*1st step : do something*/
			CanDiag_u16SesToTimer = 0u;
			/*2st step : positive response*/
			pMsgContext->resData[0] = 0x7eu;
			pMsgContext->resData[1] = pMsgContext->reqData[1];
		}
		else
		{
			u8NRC = 0x13u; /*Length wrong*/
		}
		

	}
	else
	{
		u8NRC = 0x12u; /*sub function not support*/
	}
	return u8NRC;	
	
}

static uint8 u8CheckServiceSupport(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint8 u8Tmp;
	uint8 u8NRC = 0x00u;
	uint8 u8ServiceID;
	uint8 reqType;
	u8ServiceID = pMsgContext->reqData[0];
	reqType = pMsgContext->msgAddInfo.reqType;
	for (u8Tmp = 0u; u8Tmp < CANDIAG_u8SERIDNUMS; u8Tmp ++)
	{
		if (CanDiag_kstrSerSupport[u8Tmp].u8SID == u8ServiceID)
		{
			break;
		}
	}
	if(pMsgContext->reqDataLen == 1u )
	{
		u8NRC = 0x13u;
	}
	if (u8Tmp >= CANDIAG_u8SERIDNUMS)
	{
		/*NRC = 0x11 : service not support*/
		u8NRC = 0x11u;
	}
	else
	{
		/*session check*/
		if ((CanDiag_kstrSerSupport[u8Tmp].u8SessionLimitMsk & CanDiag_u8SessionMsk) 
			== 0u)
		{
			if (u8NRC == 0x00u)
			{
				u8NRC = 0x7Fu; /*session not support*/
			}
		}
		/*security check*/
		if (CanDiag_kstrSerSupport[u8Tmp].u8SecurityLimit > 0u)
		{
			if ((CanDiag_kstrSerSupport[u8Tmp].u8SecurityLimit & CanDiag_u8SecLvl) 
				== 0u)
			{
				if (u8NRC == 0x00u)
				{
					u8NRC = 0x33u; /*ECU locked*/
					if((pMsgContext->reqData[0] == 0x31u)&&
					(pMsgContext->reqData[1] == 0x01u)&&
					(pMsgContext->reqData[2] == 0xffu)&&
					(pMsgContext->reqData[3] == 0x02u))
					{
						u8NRC = 0x00u;
					}
				}
			}
		}
		else
		{
			/*no security limit*/
		}
		/*u8AddressingModeLimit check*/
		if ((CanDiag_kstrSerSupport[u8Tmp].u8AddressingModeLimit & (1u << reqType)) 
			== 0u)
		{
			if (u8NRC == 0x00u)
			{
				u8NRC = 0x11u; /*Service not support*/
			}
		}
	}

	return u8NRC;
}

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void CanDiag_vidInit(void)
{
	CanDiag_u8SessionMsk = CANDIAG_u8SESLMT_DEFAULT_MSK;
	CanDiag_u8SecLvl = CANDIAG_u8SECLMT_LVL0;
	CanDiag_u16SesToTimer = 0u;
	CanDiag_bECUReset = FALSE;
	CanDiag_u16RunTimer = 0u;
	CanDiag_enuSecAccRecv = CANDIAG_SART_RECVSEED;
	CanDiag_u8SecAccErrCnt = 0u;
	CanDiag_u16NextSecAccTimer = 0u;
	CanDiag_bMsgRecved = FALSE;
	CanDiag_u8SeedsCounter = 0u;
	//CanDiag_bRoutineStarted = FALSE;
}

void CanDiag_vidSetCanDiagMsg(CanDiag_tstrMsgContextType strDmc)
{
	CanDiag_bMsgRecved = TRUE;
	CanDiag_strDmc.msgAddInfo.reqType = strDmc.msgAddInfo.reqType;
	CanDiag_strDmc.msgAddInfo.cancelOperation = strDmc.msgAddInfo.cancelOperation;	
	CanDiag_strDmc.reqData = strDmc.reqData;
        CanDiag_strDmc.resData = strDmc.resData;       
	CanDiag_strDmc.reqDataLen = strDmc.reqDataLen;
	CanDiag_strDmc.u32CanId = strDmc.u32CanId;	
}



void CanDiag_vidManage(void)
{
	if (CanDiag_bMsgRecved == TRUE)
	{
		Mcu_vidDisableInterrupts();
		if(CanDiag_strDmc.msgAddInfo.reqType == CANTP_TTT_PHYSICAL)
		{
			vidCanDiagPhyHandle();
			if (CanDiag_strDmc.resDataLen > 0u)
			{
				CanTp_vidDiagResp(CanDiag_strDmc.resDataLen);
			}
			CanDiag_bMsgRecved = FALSE;
		}
		else if(CanDiag_strDmc.msgAddInfo.reqType == CANTP_TTT_FUNCTIONAL)
		{
			vidCanDiagFuncHandle();
			if (CanDiag_strDmc.resDataLen > 0u)
			{
				CanTp_vidDiagResp(CanDiag_strDmc.resDataLen);
			}
			CanDiag_bMsgRecved = FALSE;
		}
		else
		{
			/*do nothing*/
		}
		Mcu_vidEnableInterrupts();
	}
	
	if (CanDiag_u16RunTimer < u16RUNTIMER_MAX)
	{
		CanDiag_u16RunTimer ++;
	}
	/*session management*/
	vidSessionManage();
	/*security management*/
	vidSecurityManage();
	/*ECUReset management*/
	vidECUResetManage();
	
}

void vidSendNegResp(CanDiag_tstrMsgContextType *pMsgContext, 
	uint8 u8NRC)
{
	/*resData and reqData address is same =>to avoid recover*/
	pMsgContext->resData[1] = pMsgContext->reqData[0]; /*data 1 = data 0*/
	pMsgContext->resData[0] = 0x7Fu; /*data 0 = 0x7Fu*/
	pMsgContext->resData[2] = u8NRC; 
	pMsgContext->resDataLen = 0x03u;
	pMsgContext->resData[3] = 0x55u;
	pMsgContext->resData[4] = 0x55u;
	pMsgContext->resData[5] = 0x55u;
	pMsgContext->resData[6] = 0x55u;
}


/*-------------------------------- end of file -------------------------------*/

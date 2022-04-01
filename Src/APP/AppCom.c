/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : App                                                     */
/*                                                                            */
/* !Component       : AppCom                                                  */
/* !Description     : App com interface                                       */
/*                                                                            */
/* !Module          : AppCom                                                  */
/* !Description     : App com interface                                       */
/*                                                                            */
/* !File            : AppCom.c                                                */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/APP/AppCom.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:04   chunping.yan
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
#include "CanIf.h"
#include "Crc8.h"
#include "Lin.h"
#include "LinIf.h"
#include "Lin_Cfg.h"
#include "LinIf_Cfg.h"

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
/*D01*/
boolean  AppCom_bLostACUFlag = FALSE;
boolean  AppCom_bLostHU_AC_RegFlag = FALSE;
boolean  AppCom_bLostHU_LightandSRCtrlReqFlag = FALSE;
boolean  AppCom_bLostVCU_PT_ACPwrSpdFlag = FALSE;
boolean  AppCom_bLostBMS_TempIsoFlag = FALSE;
boolean  AppCom_bLostVCU_PT_HVCmdandPwrAllotFlag = FALSE;
boolean  AppCom_bLostESP_GeneralStatusFlag = FALSE;
boolean  AppCom_bLostBMS_RESSPTCandCmpsReqFlag = FALSE;
boolean  AppCom_bLostHU_DriveCtrlReqFlag = FALSE;
boolean  AppCom_bLostIPC_DisplayInfoFlag = FALSE;
boolean  AppCom_bLostBMS_RESSTempInfoFlag = FALSE;


/*M01*/
boolean  AppCom_bLostEMSFlag = FALSE;
boolean  AppCom_bLostRSCMFlag = FALSE;
boolean  AppCom_bLostVCUFlag = FALSE;
boolean  AppCom_bLostESPFlag = FALSE;
boolean  AppCom_bLostIPCFlag = FALSE;
boolean  AppCom_bLostGWFlag = FALSE;

boolean  AppCom_bFptCommErrFlag = FALSE;
boolean  AppCom_bRptCommErrFlag = FALSE;
boolean  AppCom_bAcTpvrCommErrFlag = FALSE;

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/*Rx indication function definition                                           */
/******************************************************************************/
extern void AppCom_vidRxInd_GW_BD_ACU_DirverInfo(void)
{
	AppCom_bLostACUFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_HU_ACCtrlReq(void)
{
	AppCom_bLostHU_AC_RegFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_HU_LightandSRCtrlReq(void)
{
	AppCom_bLostHU_LightandSRCtrlReqFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_VCU_PT_ACPwrSpd(void)
{
	AppCom_bLostVCU_PT_ACPwrSpdFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_BMS_TempIso(void)
{
	AppCom_bLostBMS_TempIsoFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_VCU_PT_HVCmdandPwrAllot(void)
{
	AppCom_bLostVCU_PT_HVCmdandPwrAllotFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_ESP_GeneralStatus(void)
{
	AppCom_bLostESP_GeneralStatusFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_BMS_RESSPTCandCmpsReq(void)
{
	AppCom_bLostBMS_RESSPTCandCmpsReqFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_HU_DriveCtrlReq(void)
{
	AppCom_bLostHU_DriveCtrlReqFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_IPC_DisplayInfo(void)
{
	 AppCom_bLostIPC_DisplayInfoFlag = FALSE;
}

extern void AppCom_vidRxInd_GW_BD_BMS_RESSTempInfo(void)
{
	AppCom_bLostBMS_RESSTempInfoFlag = FALSE;
}


/******************************************************************************/   
/*rx Ipdu timeout indication function definition                              */
/******************************************************************************/   
extern void AppCom_vidToInd_GW_BD_ACU_DirverInfo(void)
{
	AppCom_bLostACUFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_HU_ACCtrlReq(void)
{
	AppCom_bLostHU_AC_RegFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_HU_LightandSRCtrlReq(void)
{
	AppCom_bLostHU_LightandSRCtrlReqFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_VCU_PT_ACPwrSpd(void)
{
	AppCom_bLostVCU_PT_ACPwrSpdFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_BMS_TempIso(void)
{
	AppCom_bLostBMS_TempIsoFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_VCU_PT_HVCmdandPwrAllot(void)
{
	AppCom_bLostVCU_PT_HVCmdandPwrAllotFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_ESP_GeneralStatus(void)
{
	AppCom_bLostESP_GeneralStatusFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_BMS_RESSPTCandCmpsReq(void)
{
	AppCom_bLostBMS_RESSPTCandCmpsReqFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_HU_DriveCtrlReq(void)
{
	AppCom_bLostHU_DriveCtrlReqFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_IPC_DisplayInfo(void)
{
	AppCom_bLostIPC_DisplayInfoFlag = TRUE;
}

extern void AppCom_vidToInd_GW_BD_BMS_RESSTempInfo(void)
{
	AppCom_bLostBMS_RESSTempInfoFlag = TRUE;
}


/******************************************************************************/   
/*tx Ipdu indication function definition                                      */
/******************************************************************************/   
extern void AppCom_vidTxInd_AC_PwrAlloted(uint8 *pu8Data)
{
	static uint8 LOC_u8Cnt = 0u;
	uint8 u8Tmp;
	
	/*set counter*/
	SetSig_AC_PwrAlloted_AC_PwrAlloted_RollingCounter(LOC_u8Cnt);
	/*set crc*/
	u8Tmp = Crc8_u8Calculate(pu8Data, 7u);
	SetSig_AC_PwrAlloted_AC_PwrAlloted_Checksum(u8Tmp);
	
	if (LOC_u8Cnt < 0x0F)
	{
		LOC_u8Cnt++;
	}
	else
	{
		LOC_u8Cnt = 0u;
	}	
}

extern void AppCom_vidTxInd_AC_ACCtrlFeedback(uint8 *pu8Data)
{
	static uint8 LOC_u8Cnt = 0u;
	uint8 u8Tmp;
	
	/*set counter*/
	SetSig_AC_ACCtrlFeedback_AC_ACCtrlFeedback_RollingCounter(LOC_u8Cnt);
	/*set crc*/
	u8Tmp = Crc8_u8Calculate(pu8Data, 7u);
	SetSig_AC_ACCtrlFeedback_AC_ACCtrlFeedback_Checksum(u8Tmp);
	
	if (LOC_u8Cnt < 0x0F)
	{
		LOC_u8Cnt++;
	}
	else
	{
		LOC_u8Cnt = 0u;
	}	
}

extern void AppCom_vidTxInd_AC_TempInfo(uint8 *pu8Data)
{
	static uint8 LOC_u8Cnt = 0u;
	uint8 u8Tmp;
	
	/*set counter*/
	SetSig_AC_TempInfo_AC_TempInfo_RollingCounter(LOC_u8Cnt);
	/*set crc*/
	u8Tmp = Crc8_u8Calculate(pu8Data, 7u);
	SetSig_AC_TempInfo_AC_TempInfo_Checksum(u8Tmp);
	
	if (LOC_u8Cnt < 0x0F)
	{
		LOC_u8Cnt++;
	}
	else
	{
		LOC_u8Cnt = 0u;
	}	
}

extern void AppCom_vidTxInd_AC_PwrInfo(uint8 *pu8Data)
{

}

void AppCom_vidTxInd_AC_SHMNumber(uint8 *pu8Data)
{
	
}

extern void AppCom_vidTxInd_AC_LightAndTemp(uint8 *pu8Data)
{

}


extern void AppCom_vidTxInd_AC_Diagnosis1(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_AC_Diagnosis2(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_AC_Diagnosis3(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_AC_Diagnosis4(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_AC_Diagnosis5(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_AC_Diagnosis6(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_CLM_1(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_CLM_11(uint8 *pu8Data)
{

}
extern void AppCom_vidTxInd_CLM_2(uint8 *pu8Data)
{

}

extern void AppCom_vidRxInd_ABS_ESP_G()
{

}
extern void AppCom_vidToInd_ABS_ESP_G()
{

}
extern void AppCom_vidRxInd_ADCC_4()
{

}
extern void AppCom_vidToInd_ADCC_4()
{

}
extern void AppCom_vidRxInd_AIPM_1()
{

}
extern void AppCom_vidToInd_AIPM_1()
{

}
extern void AppCom_vidRxInd_AIPM_2()
{

}
extern void AppCom_vidToInd_AIPM_2()
{

}
extern void AppCom_vidRxInd_BCM_11()
{

}
extern void AppCom_vidToInd_BCM_11()
{

}
extern void AppCom_vidRxInd_BMS_2()
{

}
extern void AppCom_vidToInd_BMS_2()
{

}
extern void AppCom_vidRxInd_BMS_4()
{

}
extern void AppCom_vidToInd_BMS_4()
{

}
extern void AppCom_vidRxInd_BMS_5()
{

}
extern void AppCom_vidToInd_BMS_5()
{

}
extern void AppCom_vidRxInd_BMS_7()
{

}
extern void AppCom_vidToInd_BMS_7()
{

}extern void AppCom_vidRxInd_DCDC_1()
{

}
extern void AppCom_vidToInd_DCDC_1()
{

}
extern void AppCom_vidRxInd_OBC_3()
{

}
extern void AppCom_vidToInd_OBC_3()
{

}
extern void AppCom_vidToInd_OBC_4()
{

}
extern void AppCom_vidRxInd_OBC_4()
{

}
extern void AppCom_vidToInd_TIHU_IHU_4()
{

}
extern void AppCom_vidRxInd_TIHU_IHU_4()
{

}
extern void AppCom_vidToInd_TMF_4()
{

}
extern void AppCom_vidRxInd_TMF_4()
{

}
extern void AppCom_vidToInd_TMR_4()
{

}
extern void AppCom_vidRxInd_TMR_4()
{

}
extern void AppCom_vidToInd_VCC_7()
{

}
extern void AppCom_vidRxInd_VCC_7()
{

}
extern void AppCom_vidRxInd_TMF_2()
{

}
extern void AppCom_vidToInd_TMF_2()
{

}
extern void AppCom_vidRxInd_TMR_2()
{

}
extern void AppCom_vidToInd_TMR_2()
{

}
/*-------------------------------- end of file -------------------------------*/

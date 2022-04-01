#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Can_Type.h"
#include "CanTp.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define COM_RXPDUNUM  				(18u) 						/*receive normal msg num*/
#define COM_TXPDUNUM  				(9u)  						/*send normal msg num*/



#define TP_RXPDUNUM   				(2u)						/*receive diag msg num*/
#define TP_MSG_TX_ID    			(0x7ABu) 					/*send diag msg id*/
#define TP_MSG_TX_BUFFER_ID 		(COM_TXPDUNUM) 	            /*for send diag msg tx buffer id*/

/**********************Can Send Message****************************************/
/*0-0x398 D01*/
#define SetSig_AC_PwrAlloted_Unused0(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused0 = x)
#define SetSig_AC_PwrAlloted_Unused1(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused1 = x)
#define SetSig_AC_PwrAlloted_Unused2(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused2 = x)
#define SetSig_AC_PwrAlloted_Unused3(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused3 = x)
#define SetSig_AC_PwrAlloted_Unused4(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused4 = x)
#define SetSig_AC_PwrAlloted_Unused5(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused5 = x)
#define SetSig_AC_PwrAlloted_Unused6(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused6 = x)
#define SetSig_AC_PwrAlloted_AC_CabinDemistReq(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.AC_CabinDemistReq = x)
#define SetSig_AC_PwrAlloted_AC_DefrostModeStatus(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.AC_DefrostModeStatus = x)
#define SetSig_AC_PwrAlloted_Unused7(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.Unused7 = x)
#define SetSig_AC_PwrAlloted_AC_PwrAlloted_RollingCounter(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.AC_PwrAlloted_RollingCounter = x)
#define SetSig_AC_PwrAlloted_AC_PwrAlloted_Checksum(x) (CanIf_uniTxMsgType_AC_PwrAlloted.Ipdu.AC_PwrAlloted_Checksum = x)

/*1-0x3E8 D01*/
#define SetSig_AC_ACCtrlFeedback_AC_MaxColdStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_MaxColdStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_OFFStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_OFFStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_FrontBlowModeStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_FrontBlowModeStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_FrontBlowSpeedCtrlFeedback(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_FrontBlowSpeedCtrlFeedback = x)
#define SetSig_AC_ACCtrlFeedback_AC_FrontAutoACStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_FrontAutoACStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_FrontACStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_FrontACStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_FTempStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_FTempStatus = x)
#define SetSig_AC_ACCtrlFeedback_Unused0(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.Unused0 = x)
#define SetSig_AC_ACCtrlFeedback_AC_SyncStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_SyncStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_RearAutoACStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_RearAutoACStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_MaxHotStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_MaxHotStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_RearTempStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_RearTempStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_RearOFFStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_RearOFFStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_RearBlowSpeedCtrlStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_RearBlowSpeedCtrlStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_RearBlowModeStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_RearBlowModeStatus = x)
#define SetSig_AC_ACCtrlFeedback_Unused1(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.Unused1 = x)
#define SetSig_AC_ACCtrlFeedback_Unused2(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.Unused2 = x)
#define SetSig_AC_ACCtrlFeedback_AC_RecyModeStatus(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_RecyModeStatus = x)
#define SetSig_AC_ACCtrlFeedback_AC_ACCtrlFeedback_RollingCounter(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_ACCtrlFeedback_RollingCounter = x)
#define SetSig_AC_ACCtrlFeedback_AC_ACCtrlFeedback_Checksum(x) (CanIf_uniTxMsgType_AC_ACCtrlFeedback.Ipdu.AC_ACCtrlFeedback_Checksum = x)

/*2-0x538 D01*/
#define SetSig_AC_TempInfo_AC_OutsideAirTemp(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_OutsideAirTemp = x)
#define SetSig_AC_TempInfo_AC_OutsideAirTempValid(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_OutsideAirTempValid = x)
#define SetSig_AC_TempInfo_Unused0(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.Unused0 = x)
#define SetSig_AC_TempInfo_AC_RESSHeatPauseReq(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_RESSHeatPauseReq = x)
#define SetSig_AC_TempInfo_Unused1(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.Unused1 = x)
#define SetSig_AC_TempInfo_AC_MILLamp(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_MILLamp = x)
#define SetSig_AC_TempInfo_Unused2(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.Unused2 = x)
#define SetSig_AC_TempInfo_AC_FrontEvapTemp(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_FrontEvapTemp = x)
#define SetSig_AC_TempInfo_Unused3(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.Unused3 = x)
#define SetSig_AC_TempInfo_AC_CmpsHiSidFldPress(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_CmpsHiSidFldPress = x)
#define SetSig_AC_TempInfo_Unused4(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.Unused4 = x)
#define SetSig_AC_TempInfo_AC_TempInfo_RollingCounter(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_TempInfo_RollingCounter = x)
#define SetSig_AC_TempInfo_AC_TempInfo_Checksum(x) (CanIf_uniTxMsgType_AC_TempInfo.Ipdu.AC_TempInfo_Checksum = x)

/*3-0x558 D01*/
#define SetSig_AC_PwrInfo_AC_ACPwrReq(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_ACPwrReq = x)
#define SetSig_AC_PwrInfo_AC_ACPwrReqValid(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_ACPwrReqValid = x)
#define SetSig_AC_PwrInfo_AC_CabinWaterPTCPwr(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CabinWaterPTCPwr = x)
#define SetSig_AC_PwrInfo_AC_CabinWaterPTCPwrValid(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CabinWaterPTCPwrValid = x)
#define SetSig_AC_PwrInfo_AC_CabinAirPTCPwr(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CabinAirPTCPwr = x)
#define SetSig_AC_PwrInfo_AC_CabinAirPTCPwrValid(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CabinAirPTCPwrValid = x)
#define SetSig_AC_PwrInfo_AC_CmpPwr(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CmpPwr = x)
#define SetSig_AC_PwrInfo_AC_CmpPwrValid(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CmpPwrValid = x)
#define SetSig_AC_PwrInfo_AC_CmpsSpeed(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CmpsSpeed = x)
#define SetSig_AC_PwrInfo_AC_CmpsSpeedValid(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_CmpsSpeedValid = x)
#define SetSig_AC_PwrInfo_AC_ElecFanCtrl_ReservedRequest(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_ElecFanCtrl_ReservedRequest = x)
#define SetSig_AC_PwrInfo_Unused0(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.Unused0 = x)
#define SetSig_AC_PwrInfo_AC_ElecFanPWMCtrl_Reserved(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_ElecFanPWMCtrl_Reserved = x)
#define SetSig_AC_PwrInfo_AC_ElecFanPWMCtrl_ReservedValid(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.AC_ElecFanPWMCtrl_ReservedValid = x)
#define SetSig_AC_PwrInfo_Unused1(x) (CanIf_uniTxMsgType_AC_PwrInfo.Ipdu.Unused1 = x)

/*4-0x609 D01*/
#define SetSig_AC_SHMNumber_Unused0(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.Unused0 = x)
#define SetSig_AC_SHMNumber_AC_SWNumberHI(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.AC_SWNumberHI = x)
#define SetSig_AC_SHMNumber_AC_SWNumberLO(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.AC_SWNumberLO = x)
#define SetSig_AC_SHMNumber_AC_HWNumberHI(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.AC_HWNumberHI = x)
#define SetSig_AC_SHMNumber_AC_HWNumberLO(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.AC_HWNumberLO = x)
#define SetSig_AC_SHMNumber_AC_MXNumberHI(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.AC_MXNumberHI = x)
#define SetSig_AC_SHMNumber_AC_MXNumberLO(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.AC_MXNumberLO = x)
#define SetSig_AC_SHMNumber_Unused1(x) (CanIf_uniTxMsgType_AC_SHMNumber.Ipdu.Unused1 = x)

/*5-0x508 D01*/
#define SetSig_AC_LightAndTemp_AC_InsideAirTemp(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.AC_InsideAirTemp = x)
#define SetSig_AC_LightAndTemp_Unused0(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.Unused0 = x)
#define SetSig_AC_LightAndTemp_AC_SunLightHI(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.AC_SunLightHI = x)
#define SetSig_AC_LightAndTemp_AC_SunLightLO(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.AC_SunLightLO = x)
#define SetSig_AC_LightAndTemp_Unused1(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.Unused1 = x)
#define SetSig_AC_LightAndTemp_Unused2(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.Unused2 = x)
#define SetSig_AC_LightAndTemp_Unused3(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.Unused3 = x)
#define SetSig_AC_LightAndTemp_Unused4(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.Unused4 = x)
#define SetSig_AC_LightAndTemp_Unused5(x) (CanIf_uniTxMsgType_AC_LightAndTemp.Ipdu.Unused5 = x)


/**********************Can Receive Message*************************************/
/*0-0x95 D01*/
#define GetSig_GW_BD_ACU_DirverInfo_Unused0() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.Unused0)
#define GetSig_GW_BD_ACU_DirverInfo_Unused1() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.Unused1)
#define GetSig_GW_BD_ACU_DirverInfo_Unused2() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.Unused2)
#define GetSig_GW_BD_ACU_DirverInfo_ACU_CrashOutputStatus() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.ACU_CrashOutputStatus)
#define GetSig_GW_BD_ACU_DirverInfo_Unused3() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.Unused3)
#define GetSig_GW_BD_ACU_DirverInfo_Unused4() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.Unused4)
#define GetSig_GW_BD_ACU_DirverInfo_Unused5() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.Unused5)
#define GetSig_GW_BD_ACU_DirverInfo_ACU_DirverInfo_RollingCounter() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.ACU_DirverInfo_RollingCounter)
#define GetSig_GW_BD_ACU_DirverInfo_ACU_DirverInfo_Checksum() (CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo.Ipdu.ACU_DirverInfo_Checksum)

/*1-0X3DB D01*/
#define GetSig_GW_BD_HU_ACCtrlReq_HU_OFFSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_OFFSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_ACSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_ACSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_FTempSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_FTempSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_RearTempSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_RearTempSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_FrontBlowSpdCtrlSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_FrontBlowSpdCtrlSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_RearBlowSpdCtrlSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_RearBlowSpdCtrlSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_FrontBlowModeSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_FrontBlowModeSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_RearBlowModeSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_RearBlowModeSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_RearAutoACSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_RearAutoACSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_RearOFFSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_RearOFFSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_DefrostModeSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_DefrostModeSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_FrontAutoACSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_FrontAutoACSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_RecyModeSwitchReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_RecyModeSwitchReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_SyncSwtichReq() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_SyncSwtichReq)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_ACCtrlReq_RollingCounter() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_ACCtrlReq_RollingCounter)
#define GetSig_GW_BD_HU_ACCtrlReq_HU_ACCtrlReq_Checksum() (CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq.Ipdu.HU_ACCtrlReq_Checksum)

/*2-0x51C D01*/
#define GetSig_GW_BD_HU_LightandSRCtrlReq_Unused0() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.Unused0)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_Unused1() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.Unused1)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_Unused2() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.Unused2)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_Unused3() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.Unused3)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_Unused4() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.Unused4)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_Unused5() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.Unused5)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_Unused6() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.Unused6)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_HU_LightandSRCtrlReq_RollingCounter() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.HU_LightandSRCtrlReq_RollingCounter)
#define GetSig_GW_BD_HU_LightandSRCtrlReq_HU_LightandSRCtrlReq_Checksum() (CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq.Ipdu.HU_LightandSRCtrlReq_Checksum)

/*3-0X530 D01*/
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_VCU_PT_ACAlotdPwr() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.VCU_PT_ACAlotdPwr)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused0() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused0)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_VCU_PT_ElecFanWindSpeed() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.VCU_PT_ElecFanWindSpeed)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused1() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused1)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused2() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused2)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused3() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused3)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused4() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused4)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused5() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused5)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused6() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused6)
#define GetSig_GW_BD_VCU_PT_ACPwrSpd_Unused7() (CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd.Ipdu.Unused7)

/*4-0X560 D01*/
#define GetSig_GW_BD_BMS_TempIso_Unused0() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.Unused0)
#define GetSig_GW_BD_BMS_TempIso_Unused1() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.Unused1)
#define GetSig_GW_BD_BMS_TempIso_Unused2() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.Unused2)
#define GetSig_GW_BD_BMS_TempIso_BMS_InletTemp() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.BMS_InletTemp)
#define GetSig_GW_BD_BMS_TempIso_Unused3() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.Unused3)
#define GetSig_GW_BD_BMS_TempIso_BMS_InletTargetTemp() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.BMS_InletTargetTemp)
#define GetSig_GW_BD_BMS_TempIso_Unused4() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.Unused4)
#define GetSig_GW_BD_BMS_TempIso_Unused5() (CanIf_uniRxMsgType_GW_BD_BMS_TempIso.Ipdu.Unused5)

/*5-0X390 D01*/
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_Unused0() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.Unused0)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_Unused1() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.Unused1)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_Unused2() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.Unused2)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_Unused3() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.Unused3)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_Unused4() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.Unused4)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_Unused5() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.Unused5)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_Unused6() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.Unused6)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_VCU_PT_HVCmdandPwrAllot_RollingCounter() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.VCU_PT_HVCmdandPwrAllot_RollingCounter)
#define GetSig_GW_BD_VCU_PT_HVCmdandPwrAllot_VCU_PT_HVCmdandPwrAllot_Checksum() (CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot.Ipdu.VCU_PT_HVCmdandPwrAllot_Checksum)

/*6-0X295 D01*/
#define GetSig_GW_BD_ESP_GeneralStatus_Unused0() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.Unused0)
#define GetSig_GW_BD_ESP_GeneralStatus_ESP_VehicleSpeedValid() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.ESP_VehicleSpeedValid)
#define GetSig_GW_BD_ESP_GeneralStatus_ESP_VehicleSpeedHI() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.ESP_VehicleSpeedHI)
#define GetSig_GW_BD_ESP_GeneralStatus_ESP_VehicleSpeedLO() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.ESP_VehicleSpeedLO)
#define GetSig_GW_BD_ESP_GeneralStatus_Unused1() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.Unused1)
#define GetSig_GW_BD_ESP_GeneralStatus_Unused2() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.Unused2)
#define GetSig_GW_BD_ESP_GeneralStatus_Unused3() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.Unused3)
#define GetSig_GW_BD_ESP_GeneralStatus_Unused4() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.Unused4)
#define GetSig_GW_BD_ESP_GeneralStatus_Unused5() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.Unused5)
#define GetSig_GW_BD_ESP_GeneralStatus_ESP_GeneralStatus_RollingCounter() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.ESP_GeneralStatus_RollingCounter)
#define GetSig_GW_BD_ESP_GeneralStatus_ESP_GeneralStatus_Checksum() (CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus.Ipdu.ESP_GeneralStatus_Checksum)

/*7-0X3A0*/
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_Unused0() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.Unused0)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_Unused1() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.Unused1)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_BMS_PumpSpeed() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.BMS_PumpSpeed)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_Unused2() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.Unused2)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_BMS_RESSCoolReq() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.BMS_RESSCoolReq)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_Unused3() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.Unused3)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_Unused4() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.Unused4)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_Unused5() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.Unused5)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_BMS_RESSPumpStatus() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.BMS_RESSPumpStatus)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_Unused6() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.Unused6)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_BMS_RESSPTCandCmpsReq_RollCnt() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.BMS_RESSPTCandCmpsReq_RollCnt)
#define GetSig_GW_BD_BMS_RESSPTCandCmpsReq_BMS_RESSPTCandCmpsReq_ChkSum() (CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq.Ipdu.BMS_RESSPTCandCmpsReq_ChkSum)

/*8-0X3BC*/
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused0() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused0)
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused1() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused1)
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused2() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused2)
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused3() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused3)
#define GetSig_GW_BD_HU_DriveCtrlReq_HU_AirCleanModeReq() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.HU_AirCleanModeReq)
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused4() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused4)
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused5() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused5)
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused6() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused6)
#define GetSig_GW_BD_HU_DriveCtrlReq_Unused7() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.Unused7)
#define GetSig_GW_BD_HU_DriveCtrlReq_HU_DriveCtrlReq_RollingCounter() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.HU_DriveCtrlReq_RollingCounter)
#define GetSig_GW_BD_HU_DriveCtrlReq_HU_DriveCtrlReq_Checksum() (CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq.Ipdu.HU_DriveCtrlReq_Checksum)

/*9-0X3CC*/
#define GetSig_GW_BD_IPC_DisplayInfo_Unused0() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.Unused0)
#define GetSig_GW_BD_IPC_DisplayInfo_Unused1() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.Unused1)
#define GetSig_GW_BD_IPC_DisplayInfo_IPC_TotalOdometerHI() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.IPC_TotalOdometerHI)
#define GetSig_GW_BD_IPC_DisplayInfo_IPC_TotalOdometerMI() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.IPC_TotalOdometerMI)
#define GetSig_GW_BD_IPC_DisplayInfo_IPC_TotalOdometerLO() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.IPC_TotalOdometerLO)
#define GetSig_GW_BD_IPC_DisplayInfo_Unused2() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.Unused2)
#define GetSig_GW_BD_IPC_DisplayInfo_Unused3() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.Unused3)
#define GetSig_GW_BD_IPC_DisplayInfo_IPC_DisplayInfo_RollingCounter() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.IPC_DisplayInfo_RollingCounter)
#define GetSig_GW_BD_IPC_DisplayInfo_IPC_DisplayInfo_Checksum() (CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo.Ipdu.IPC_DisplayInfo_Checksum)

/*10-0X620*/
#define GetSig_GW_BD_BMS_RESSTempInfo_Unused0() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.Unused0)
#define GetSig_GW_BD_BMS_RESSTempInfo_BMS_RESSMaxTemp() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.BMS_RESSMaxTemp)
#define GetSig_GW_BD_BMS_RESSTempInfo_Unused1() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.Unused1)
#define GetSig_GW_BD_BMS_RESSTempInfo_Unused2() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.Unused2)
#define GetSig_GW_BD_BMS_RESSTempInfo_Unused3() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.Unused3)
#define GetSig_GW_BD_BMS_RESSTempInfo_Unused4() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.Unused4)
#define GetSig_GW_BD_BMS_RESSTempInfo_Unused5() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.Unused5)
#define GetSig_GW_BD_BMS_RESSTempInfo_Unused6() (CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo.Ipdu.Unused6)

typedef struct
{
	uint8* pu8Data;
} CanIf_tstrDataAddrType;

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


	
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef void (*Com_RxIndicationType)(void);
typedef void (*Com_TOIndicationType)(void);
typedef void (*Com_TxIndicationType)(uint8 *pu8Data);

typedef enum
{
	MST_Cycle,
	MST_NoSendType,
	MST_IfActive
} CanIf_tenuMsgSendType;

/*send msg type*/
typedef struct
{
	Can_tstrPduType strPdu;
	uint16 u16MsgCycleTime;
	uint16 u16MsgCycleTimeFast;
	uint8 u8MsgNbOfRepetition;
    CanIf_tenuMsgSendType enuMsgSendType;
	Com_TxIndicationType vidTxIndication;
	uint8 u8MsgBufInd;
} CanIf_tstrTxMsgInfoType;

/*receive msg type*/
typedef struct
{
	Can_tstrPduType strPdu;
    boolean bTOMonitored;
    uint16  u16RxTimeout;  
	Com_RxIndicationType vidRxIndication;
	Com_TOIndicationType vidTOIndication;
} CanIf_tstrRxMsgInfoType;

typedef struct
{
	boolean bSend;
	uint16 u16MsgCycleTimeCnt;
	uint16 u16MsgCycleTimeFastCnt;
	uint8 u8MsgNbOfRepetitionCnt;
}CanIf_tstrTxCtrlType;

typedef struct
{
	uint16 u16RxToTimer;

} CanIf_tstrRxCtrlType;

/******************************************************************************/   
/* Send Signal structures                                                     */ 
/******************************************************************************/  
typedef struct 
{	 
	 uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 1;	
	 uint8 AC_CabinDemistReq : 1;	
	 uint8 AC_DefrostModeStatus : 1;	
	 uint8 Unused7 : 1;	
	 uint8 AC_PwrAlloted_RollingCounter : 4;	
	 uint8 AC_PwrAlloted_Checksum : 8;	 
} CanIf_tstrTxMsgType_AC_PwrAlloted; /*0-0x398 D01*/




typedef struct {	 uint8 AC_MaxColdStatus : 1;	
	 uint8 AC_OFFStatus : 1;	
	 uint8 AC_FrontBlowModeStatus : 3;	
	 uint8 AC_FrontBlowSpeedCtrlFeedback : 3;	
	 uint8 AC_FrontAutoACStatus : 1;	
	 uint8 AC_FrontACStatus : 1;	
	 uint8 AC_FTempStatus : 6;	
	 uint8 Unused0 : 7;	
	 uint8 AC_SyncStatus : 1;	
	 uint8 AC_RearAutoACStatus : 1;	
	 uint8 AC_MaxHotStatus : 1;	
	 uint8 AC_RearTempStatus : 6;	
	 uint8 AC_RearOFFStatus : 1;	
	 uint8 AC_RearBlowSpeedCtrlStatus : 3;	
	 uint8 AC_RearBlowModeStatus : 3;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 3;	
	 uint8 AC_RecyModeStatus : 2;	
	 uint8 AC_ACCtrlFeedback_RollingCounter : 4;	
	 uint8 AC_ACCtrlFeedback_Checksum : 8;	 
} CanIf_tstrTxMsgType_AC_ACCtrlFeedback;   /*1-0x3E8 D01*/

typedef struct 
{	  
		  uint8 AC_OutsideAirTemp : 8;	 
		  uint8 AC_OutsideAirTempValid : 1;  
		  uint8 Unused0 : 7; 
		  uint8 AC_RESSHeatPauseReq : 1; 
		  uint8 Unused1 : 1; 
		  uint8 AC_MILLamp : 1;  
		  uint8 Unused2 : 5; 
		  uint8 AC_FrontEvapTemp : 8;	 
		  uint8 Unused3 : 8; 
		  uint8 AC_CmpsHiSidFldPress : 8;	 
		  uint8 AC_CmpsHiSidFldPressValid : 1;	 
		  uint8 AC_CabinAirVlvStatus : 2;	 
		  uint8 Unused4 : 1; 
		  uint8 AC_TempInfo_RollingCounter : 4;  
		  uint8 AC_TempInfo_Checksum : 8;	 
} CanIf_tstrTxMsgType_AC_TempInfo; /*2-0x538 D01*/

typedef struct {	 uint8 AC_ACPwrReq : 7;	
	 uint8 AC_CabinWaterPTCPwrValid : 1;	
	 uint8 AC_CabinAirPTCPwr : 7;	
	 uint8 AC_CabinAirPTCPwrValid : 1;	
	 uint8 AC_CmpPwr : 7;	
	 uint8 AC_CmpPwrValid : 1;	
	 uint8 AC_CmpsSpeed : 8;	
	 uint8 AC_CmpsSpeedValid : 1;	
	 uint8 AC_ElecFanCtrl_ReservedRequest : 2;	
	 uint8 Unused0 : 5;	
	 uint8 AC_ElecFanPWMCtrl_Reserved : 7;	
	 uint8 AC_ElecFanPWMCtrl_ReservedValid : 1;	
	 uint8 Unused1 : 8;	 } CanIf_tstrTxMsgType_AC_PwrInfo;  /*3-0x558 D01*/

typedef struct {	 uint8 Unused0 : 8;	
	 uint8 AC_SWNumberHI : 8;	
	 uint8 AC_SWNumberLO : 8;	
	 uint8 AC_HWNumberHI : 8;	
	 uint8 AC_HWNumberLO : 8;	
	 uint8 AC_MXNumberHI : 8;	
	 uint8 AC_MXNumberLO : 8;	
	 uint8 Unused1 : 8;	 } CanIf_tstrTxMsgType_AC_SHMNumber; /*4-0x609 D01*/

typedef struct {	 uint8 AC_InsideAirTemp : 8;	
	 uint8 Unused0 : 8;	
	 uint8 AC_SunLightHI : 8;	
	 uint8 AC_SunLightLO : 4;	
	 uint8 Unused1 : 4;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	 } CanIf_tstrTxMsgType_AC_LightAndTemp;  /*5-0x508 D01*/

/******************************************************************************/   
/* Receive Signal structures                                                  */ 
/******************************************************************************/  
typedef struct {	 uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 ACU_CrashOutputStatus : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 4;	
	 uint8 ACU_DirverInfo_RollingCounter : 4;	
	 uint8 ACU_DirverInfo_Checksum : 8;	 } CanIf_tstrRxMsgType_GW_BD_ACU_DirverInfo;  /*0-0x95 D01*/
	 
typedef struct {	 uint8 HU_OFFSwitchReq : 1;	
	 uint8 HU_ACSwitchReq : 1;	
	 uint8 HU_FTempSwitchReq : 6;	
	 uint8 HU_RearTempSwitchReq : 6;	
	 uint8 HU_FrontBlowSpdCtrlSwitchReq : 4;	
	 uint8 HU_RearBlowSpdCtrlSwitchReq : 4;	
	 uint8 HU_FrontBlowModeSwitchReq : 3;	
	 uint8 HU_RearBlowModeSwitchReq : 2;	
	 uint8 HU_RearAutoACSwitchReq : 1;	
	 uint8 HU_RearOFFSwitchReq : 1;	
	 uint8 HU_DefrostModeSwitchReq : 1;	
	 uint8 HU_FrontAutoACSwitchReq : 1;	
	 uint8 HU_RecyModeSwitchReq : 1;	
	 uint8 HU_SyncSwtichReq : 1;	
	 uint8 HU_ACCtrlReq_RollingCounter : 4;	
	 uint8 HU_ACCtrlReq_Checksum : 8;	 } CanIf_tstrRxMsgType_GW_BD_HU_ACCtrlReq;  /*1-0X3DB D01*/

typedef struct {	 uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 4;	
	 uint8 HU_LightandSRCtrlReq_RollingCounter : 4;	
	 uint8 HU_LightandSRCtrlReq_Checksum : 8;	 } CanIf_tstrRxMsgType_GW_BD_HU_LightandSRCtrlReq;  /*2-0X51C D01*/

typedef struct {	 uint8 VCU_PT_ACAlotdPwr : 7;	
	 uint8 Unused0 : 1;	
	 uint8 VCU_PT_ElecFanWindSpeed : 7;	
	 uint8 Unused1 : 1;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 8;	 } CanIf_tstrRxMsgType_GW_BD_VCU_PT_ACPwrSpd;   /*3-0X530 D01*/

typedef struct {	 uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 BMS_InletTemp : 8;	
	 uint8 Unused3 : 8;	
	 uint8 BMS_InletTargetTemp : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	 } CanIf_tstrRxMsgType_GW_BD_BMS_TempIso; /*4-0X560 D01*/

typedef struct 
{	 uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 4;	
	 uint8 VCU_PT_HVCmdandPwrAllot_RollingCounter : 4;	
	 uint8 VCU_PT_HVCmdandPwrAllot_Checksum : 8;	 
} CanIf_tstrRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot; /*5-0X390 D01*/

typedef struct 
{	 uint8 Unused0 : 7;	
	 uint8 ESP_VehicleSpeedValid : 1;	
	 uint8 ESP_VehicleSpeedHI : 8;	
	 uint8 ESP_VehicleSpeedLO : 5;	
	 uint8 Unused1 : 3;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 4;	
	 uint8 ESP_GeneralStatus_RollingCounter : 4;	
	 uint8 ESP_GeneralStatus_Checksum : 8;	 
} CanIf_tstrRxMsgType_GW_BD_ESP_GeneralStatus;  /*6-0X295 D01*/

typedef struct 
{	 uint8 Unused0 : 8;	
	 uint8 Unused1 : 1;	
	 uint8 BMS_PumpSpeed : 7;	
	 uint8 Unused2 : 8;	
	 uint8 BMS_RESSCoolReq : 2;	
	 uint8 Unused3 : 6;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 BMS_RESSPumpStatus : 2;	
	 uint8 Unused6 : 2;	
	 uint8 BMS_RESSPTCandCmpsReq_RollCnt : 4;	
	 uint8 BMS_RESSPTCandCmpsReq_ChkSum : 8;	 
} CanIf_tstrRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq; /*7-0X3A0 D01*/

typedef struct {	 uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 5;	
	 uint8 HU_AirCleanModeReq : 1;	
	 uint8 Unused4 : 2;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 4;	
	 uint8 HU_DriveCtrlReq_RollingCounter : 4;	
	 uint8 HU_DriveCtrlReq_Checksum : 8;	 } CanIf_tstrRxMsgType_GW_BD_HU_DriveCtrlReq;   /*8-0X3BC D01*/

typedef struct {	  uint8 Unused0 : 8; 
		  uint8 Unused1 : 8; 
		  uint8 IPC_TotalOdometerHI : 8; 
		  uint8 IPC_TotalOdometerMI : 8; 
		  uint8 IPC_TotalOdometerLO : 8; 
		  uint8 Unused2 : 8; 
		  uint8 Unused3 : 4;
		  uint8 IPC_DisplayInfo_RollingCounter : 4;  
		  uint8 IPC_DisplayInfo_Checksum : 8;	  } CanIf_tstrRxMsgType_GW_BD_IPC_DisplayInfo;  /*9-0X3CC D01*/

typedef struct {	 uint8 Unused0 : 8;	
	 uint8 BMS_RESSMaxTemp : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	 } CanIf_tstrRxMsgType_GW_BD_BMS_RESSTempInfo; /*10-0x620 D01*/

/********************************************************************************/   
/* Send Message unions 															*/
/********************************************************************************/ 
typedef union 
{
	CanIf_tstrTxMsgType_AC_PwrAlloted Ipdu;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_PwrAlloted; /*0-0x398 D01*/


typedef union
{ 
	CanIf_tstrTxMsgType_AC_ACCtrlFeedback Ipdu; 
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_ACCtrlFeedback; /*1-0x3E8 D01*/


typedef union 
{
	CanIf_tstrTxMsgType_AC_TempInfo Ipdu;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_TempInfo; /*2-0x538 D01*/

typedef union
{ 
	CanIf_tstrTxMsgType_AC_PwrInfo Ipdu; 
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_PwrInfo; /*3-0x558 D01*/

typedef union
{ 
	CanIf_tstrTxMsgType_AC_SHMNumber Ipdu; 
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_SHMNumber; /*4-0x609 D01*/

typedef union 
{ 
	CanIf_tstrTxMsgType_AC_LightAndTemp Ipdu; 
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_LightAndTemp;   /*5-0x508 D01*/

/********************************************************************************/   
/* Receive Message unions */
/********************************************************************************/ 
typedef union 
{
	CanIf_tstrRxMsgType_GW_BD_ACU_DirverInfo Ipdu;
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_ACU_DirverInfo; /*0-0x95 D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_HU_ACCtrlReq Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_HU_ACCtrlReq; /*1-0x3DB D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_HU_LightandSRCtrlReq Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_HU_LightandSRCtrlReq;  /*2-0X51C D01*/ 

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_VCU_PT_ACPwrSpd Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_VCU_PT_ACPwrSpd; /*3-0X530 D01*/ 

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_BMS_TempIso Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_BMS_TempIso;  /*4-0X560 D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot;  /*5-0X390 D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_ESP_GeneralStatus Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_ESP_GeneralStatus; /*6-0X295 D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq;  /*7-0X3A0 D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_HU_DriveCtrlReq Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_HU_DriveCtrlReq; /*8-0X3BC D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_IPC_DisplayInfo Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_IPC_DisplayInfo;  /*9-0X3CC D01*/

typedef union 
{ 
	CanIf_tstrRxMsgType_GW_BD_BMS_RESSTempInfo Ipdu; 
	uint8 _c[8];
} CanIf_tuniRxMsgType_GW_BD_BMS_RESSTempInfo;  /*10-0X620 D01*/ 


typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
     uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_Diagnosis1;  /*0X5A6*/

typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
     uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_Diagnosis2;  /*0X5A7*/

typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
     uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_Diagnosis3;  /*0X5A4*/

typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
     uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_Diagnosis4;  /*0X5A5*/

typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_Diagnosis5;  /*0X5A1*/

typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_AC_Diagnosis6;  /*0X5A2*/

typedef union 
{ 
	struct {	 
     uint8 ExternalTemperature_F : 8;	
     
	 uint8 ExternalTemperature_C : 8;
     
	 uint8 BlowSpeedLevelDisplaySts : 3;	
	 uint8 ACRequestDisplaySts : 1;	
	 uint8 AutoDisplaySts : 1;	
	 uint8 ACRequestCommand : 1;	
	 uint8 Reserved_AC_MaxSts : 1;
     uint8 ExternalTemperatureFailSts : 1;
     
     uint8 ISSInhibitACSts : 1;	
	 uint8 WorkingSts : 1;	
	 uint8 PM2_5Sts : 1;	
	 uint8 SelfTestActive : 1;
     uint8 ModeAdjustDisplaySts : 3;
     uint8 FrontDeforest_MaxDisplaySts : 1;	
     
	 uint8 DisplayActive : 1;	
	 uint8 BlowAdvanceOnSts : 1;	
	 uint8 BlowDelayOffSts : 1;
     uint8 SetTemperature_L_C:5;
     
     uint8 TemperatureUnit : 1;	
	 uint8 ZoneSelectionDisplaySts : 1;	
	 uint8 CirculationModeDisplaySts : 1;
     uint8 SetTemperature_R_C:5;
       
     uint8 SetTemperature_L_F_lbit3 : 3;	
	 uint8 SelfTestResult : 5;	
     
	 uint8 Reserved_ANION_request : 1;
     uint8 SetTemperature_R_F:5 ;  
     uint8 SetTemperature_L_F_hbit2 : 3;  
     
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_CLM_1;  /*0X51A*/

typedef union 
{ 
	struct {	 
     uint8 EAC_iHvAcnCpr : 8;	
     
	 uint8 HVH_DC_curr : 8;	
     
	 uint8 EAC_uHvAcnCpr_lbit8 : 8;	
     
	 uint8 CLM_TMRCoolantFlow :  6;	
	 uint8 EAC_uHvAcnCpr_hbit2 : 2;	
     
	 uint8 HVH_HV_voltage_lbit8 : 8;	
     
	 uint8 CLM_TMFCoolantFlow : 6;
     uint8 HVH_HV_voltage_hbit2 : 2;
     
     uint8 unused0 : 1;
     uint8 CLM_TMRHeatReq:1;
     uint8 HVH_Sts :3;
     uint8 EAC_Sts :3;
     
     uint8 TMR_InletWaterTemp :8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_CLM_11;  /*0X3F6*/

typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
     
	 uint8 CLM2_ExternalTempFailSts : 1;	
     uint8 Unused2 : 7;	
     
	 uint8 CLM2_ExternalTemperature_C : 8;	
     
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniTxMsgType_CLM_2;  /*0X535*/

/////rx
typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
     
	 uint8 VehicleSpeedVSOSig_lbit5 : 5;
     uint8 Unused1 : 3;
     
	 uint8 VehicleSpeedVSOSig_hbit8 : 8;
     
     uint8 Unused2 : 7;	
	 uint8 VehicleSpeedVSOSigValidData : 1;	
     
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_ABS_ESP_G;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 ADCC_CoolantFlowReq : 6;	
	 uint8 ADCC_DelayReq : 1;
     uint8 Unused1 : 1;	
     
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     
     uint8 ADCC_4_Message_Counter : 4;
     uint8 Unused7 : 4;
     
     uint8 ADCC_4_CRC : 8;
     
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_ADCC_4;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
     
	 uint8 Unused1 : 8;	
     
	 uint8 Unused2 : 2;	
	 uint8 LeftTempPlusMinusSts : 2;	
	 uint8 RightTempPlusMinusSts : 2;	
     uint8 Key15Sts: 1;
     uint8 Unused3 : 1;
     
	 uint8 Knob2Sts : 5;	
	 uint8 Key7Sts : 1;
     uint8 Key8Sts : 1;
     uint8 Key9Sts :1;
     
    uint8 Knob3Sts:5;
    uint8 SelfTestActiveKeySts:1;
    uint8 TemperatureUnitKeySts:1;
    uint8 Key10Sts:1;
    
    uint8 unused4:2;
    uint8 Key13Sts:1;  
    uint8 Key16Sts:1;
    uint8 BlowerSlidPlusMinusSts:2;
    uint8 Key14Sts:1;
    uint8 unused5:1;
    
    uint8 unused6:1;
    uint8 BlowLevelPlusMinusSts:2;
    uint8 unused7:5;
    
    uint8 unused8:2;
    uint8 Key17Sts:1;
    uint8 Key18Sts:1;
    uint8 Key19Sts:1;
    uint8 BlowerSilderSts:3;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_AIPM_1;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 SolarSenRaw_lbit8 : 8;	
     
	 uint8 OnBoardTempRaw_C_lbit6 : 6;	
     uint8 SolarSenRaw_hbit2:2;
     
	 uint8 SurfaceTempRaw_C_lbit4 : 4;	
     uint8 OnBoardTempRaw_C_hbit4:4;
    
     uint8 PM_2_5KeyPresent:2;
     uint8 SurfaceTempRaw_C_hbit6:6;
    
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_AIPM_2;  /*0X535*/
typedef union 
{ 
		struct {	 
     uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
     
	 uint8 RLS_TempSensorValue : 8;	
     
	 uint8 Unused3 : 8;
     
	 uint8 RLS_HumidSensorValue : 8;
     
	 uint8 RLS_TempDewPoint_lbit3 : 3;	
     uint8 RLS_Humid_Temp_Error:1;
     uint8 Unused4 : 4;
     
	 uint8 RLS_TempDewPoint_hbit8 : 8;
     
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_BCM_11;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
     
     uint8 Unused4 : 4;	
     uint8 BMS_Chg_Sts:4;
       
     uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 8;  
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_BMS_2;  /*0X535*/
typedef union 
{ 
    struct {	 
     uint8 BMS_WaterTemp_Inlet : 8;	
	 uint8 BMS_WaterTemp_Outlet : 8;	
	 uint8 BMS_WaterTemp_InletTarget : 8;	
	 uint8 BMS_Request_FlowRate : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_BMS_4;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 BMS_Request_Mode : 4;	
     uint8 Unused0 : 4;	
     
     uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;
     uint8 Unused4 : 8;
     
	 uint8 BMS_HeatRequest_Mode : 3;	
	 uint8 Unused5 : 5;	
     
	 uint8 Unused6 : 8;	
	 uint8 Unused7 : 8;	
	
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_BMS_5;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 BMS_HighestBattTemp : 8;	
	 uint8 BMS_LowestBattTemp : 8;	
	 uint8 BMS_AverageBattTemp : 8;	
     
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_BMS_7;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
     
	 uint8 DCDC_Temp : 8;	
     
	 uint8 Unused3 : 8;	
     
	 uint8 Unused4 : 2;	
     uint8 DCDC_CoolingReq:1;
     uint8 Unused5:5;
    
     uint8 Unused6 : 2;	
     uint8 DCDC_OverTemp:1;
     uint8 Unused7:5;
       
	 uint8 Unused8 : 8;
     uint8 Unused9 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_DCDC_1;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
	 uint8 OBC_ChargerTemp : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_OBC_3;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 Unused0 : 8;	
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
     
	 uint8 Unused6 : 6;
     uint8 OBC_CoolingReq : 1;
     uint8 Unused7 : 6;
     
     uint8 Unused8 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_OBC_4;  /*0X535*/
typedef union 
{ 
	struct {	 
    uint8 Unused0 : 3;	
    uint8 HU_BlowSpeedLevelKeySts:3;
    uint8 HU_SetMaxFrontDeforestSts:2;
    
    uint8 HU_SetTemperature_L_C_lbit4:4;
    uint8 Unused1:1;
    uint8 HU_ModeAdjustKeySts:3;
    
    uint8 Unused2 : 2;
    uint8 HU_SetTemperature_R_C:5;
    uint8 HU_SetTemperature_L_C_hbit1:1;
    
   
	uint8 Unused3 : 8;	
	uint8 Unused4 : 8;	
     
     
	uint8 HU_SetCLMOn : 2;	
    uint8 HU_SetACRequestKeySts:2;
    uint8 Unused5 : 4;	
      
	uint8 Unused6 : 2;	
    uint8 HU_SetCirculationModeKeySts:2;
    uint8 HU_ZoneSelectionKeySts:2;
    uint8 Unused7 : 2;
     
	uint8 Unused8 : 6;	
    uint8 HU_SetAutoKeySts:2;
    
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_TIHU_IHU_4;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 TMF_InvTemp : 8;	
     
	 uint8 Unused1 : 8;	
	 uint8 Unused2 : 8;	
     
	 uint8 TMF_StatTemp_lbit1 : 1;
     uint8 Unused4 : 7;
     
	 uint8 TMF_StatTemp_hbit8 : 8;	
     
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_TMF_4;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 TMR_InverterTemperature : 8;
     
	 uint8 Unused1 : 8;	
     
	 uint8 TMR_StatorTemperature_lbit7 : 7;	
	 uint8 Unused3 : 1;	
     
	 uint8 Unused4 : 6;	
     uint8 TMR_StatorTemperature_hbit2 : 2;
     
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
     uint8 Unused8 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_TMR_4;  /*0X535*/
typedef union 
{ 
	struct {	 
     uint8 VCC_EDUSystemPowerLimit_lbit8 : 8;
     
	 uint8 VCC_MotorHeatPwrAct_lbit6 : 6;	
     uint8 VCC_EDUSystemPowerLimit_hbit2:2;
    
     uint8 Unused2 : 2;	
     uint8 VCC_EACAllow:1;
     uint8 VCC_HVHAllow:1;
     uint8 VCC_HVReady:1;
     uint8 VCC_MotorHeatPwrAct_hbit3:3;
    
	 uint8 Unused3 : 8;	
	 uint8 Unused4 : 8;	
	 uint8 Unused5 : 8;	
	 uint8 Unused6 : 8;
     uint8 Unused7 : 8;
    }packet;
	uint8 _c[8];
} CanIf_tuniRxMsgType_VCC_7;  /*0X535*/
/******************************************************************************/
/* VARIABLE DECLARATION                                                       */
/******************************************************************************/

/******************************************************************************/   
/* Databuffer for send  objects                                               */ 
/******************************************************************************/  
extern CanIf_tuniTxMsgType_AC_PwrAlloted CanIf_uniTxMsgType_AC_PwrAlloted;   /*0X398 D01*/
extern CanIf_tuniTxMsgType_AC_ACCtrlFeedback CanIf_uniTxMsgType_AC_ACCtrlFeedback; /*0X3E8 D01*/
extern CanIf_tuniTxMsgType_AC_TempInfo CanIf_uniTxMsgType_AC_TempInfo; /*0X538*/
extern CanIf_tuniTxMsgType_AC_PwrInfo CanIf_uniTxMsgType_AC_PwrInfo; /*0x558*/
extern CanIf_tuniTxMsgType_AC_SHMNumber CanIf_uniTxMsgType_AC_SHMNumber; /*0x609*/
extern CanIf_tuniTxMsgType_AC_LightAndTemp CanIf_uniTxMsgType_AC_LightAndTemp; /*0x508*/

extern CanIf_tuniTxMsgType_AC_Diagnosis1 CanIf_uniTxMsgType_AC_Diagnosis1;   /*0X5A6*/
extern CanIf_tuniTxMsgType_AC_Diagnosis2 CanIf_uniTxMsgType_AC_Diagnosis2; /*0X5A7*/
extern CanIf_tuniTxMsgType_AC_Diagnosis3 CanIf_uniTxMsgType_AC_Diagnosis3; /*0X5A4*/
extern CanIf_tuniTxMsgType_AC_Diagnosis4 CanIf_uniTxMsgType_AC_Diagnosis4; /*0X5A5*/
extern CanIf_tuniTxMsgType_AC_Diagnosis5 CanIf_uniTxMsgType_AC_Diagnosis5; /*0x5A1*/
extern CanIf_tuniTxMsgType_AC_Diagnosis6 CanIf_uniTxMsgType_AC_Diagnosis6; /*0x5A2*/
extern CanIf_tuniTxMsgType_CLM_1  CanIf_uniTxMsgType_CLM_1; /*0X51A*/
extern CanIf_tuniTxMsgType_CLM_11 CanIf_uniTxMsgType_CLM_11; /*0x3F6*/
extern CanIf_tuniTxMsgType_CLM_2  CanIf_uniTxMsgType_CLM_2; /*0x535*/


/******************************************************************************/   
/* Databuffer for receive objects                                             */ 
/******************************************************************************/   
extern CanIf_tuniRxMsgType_GW_BD_ACU_DirverInfo CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo;
extern CanIf_tuniRxMsgType_GW_BD_HU_ACCtrlReq CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq;
extern CanIf_tuniRxMsgType_GW_BD_HU_LightandSRCtrlReq CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq;
extern CanIf_tuniRxMsgType_GW_BD_VCU_PT_ACPwrSpd CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd;
extern CanIf_tuniRxMsgType_GW_BD_BMS_TempIso CanIf_uniRxMsgType_GW_BD_BMS_TempIso;
extern CanIf_tuniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot;
extern CanIf_tuniRxMsgType_GW_BD_ESP_GeneralStatus CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus;
extern CanIf_tuniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq;
extern CanIf_tuniRxMsgType_GW_BD_HU_DriveCtrlReq CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq;
extern CanIf_tuniRxMsgType_GW_BD_IPC_DisplayInfo CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo;
extern CanIf_tuniRxMsgType_GW_BD_BMS_RESSTempInfo CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo;
//demo car
extern CanIf_tuniRxMsgType_ABS_ESP_G     CanIf_uniRxMsgType_ABS_ESP_G;   /*0X502*/
extern CanIf_tuniRxMsgType_ADCC_4 CanIf_uniRxMsgType_ADCC_4; /*0X16B*/
extern CanIf_tuniRxMsgType_AIPM_1 CanIf_uniRxMsgType_AIPM_1; /*0X4F1*/
extern CanIf_tuniRxMsgType_AIPM_2 CanIf_uniRxMsgType_AIPM_2; /*0X4F3*/
extern CanIf_tuniRxMsgType_BCM_11 CanIf_uniRxMsgType_BCM_11; /*0x427*/
extern CanIf_tuniRxMsgType_BMS_2 CanIf_uniRxMsgType_BMS_2; /*0x208*/
extern CanIf_tuniRxMsgType_BMS_4  CanIf_uniRxMsgType_BMS_4; /*0X41F*/
extern CanIf_tuniRxMsgType_BMS_5 CanIf_uniRxMsgType_BMS_5; /*0x41B*/
extern CanIf_tuniRxMsgType_BMS_7  CanIf_uniRxMsgType_BMS_7; /*0x426*/
extern CanIf_tuniRxMsgType_DCDC_1  CanIf_uniRxMsgType_DCDC_1; /*0x418*/
extern CanIf_tuniRxMsgType_OBC_3  CanIf_uniRxMsgType_OBC_3; /*0X42B*/
extern CanIf_tuniRxMsgType_OBC_4 CanIf_uniRxMsgType_OBC_4; /*0x43C*/
extern CanIf_tuniRxMsgType_TIHU_IHU_4  CanIf_uniRxMsgType_TIHU_IHU_4; /*0x519*/
extern CanIf_tuniRxMsgType_TMF_4  CanIf_uniRxMsgType_TMF_4; /*0x45B*/
extern CanIf_tuniRxMsgType_TMR_4 CanIf_uniRxMsgType_TMR_4; /*0x48B*/
extern CanIf_tuniRxMsgType_VCC_7  CanIf_uniRxMsgType_VCC_7; /*0x3FE*/

/*control variabiles*/
extern const CanIf_tstrTxMsgInfoType CanIf_kstrTxMsgInfo[COM_TXPDUNUM]; 
extern CanIf_tstrDataAddrType CanIf_kstrTxPduBuf[COM_TXPDUNUM];
extern CanIf_tstrTxCtrlType CanIf_strTxCtrl[COM_TXPDUNUM];

extern const CanIf_tstrRxMsgInfoType CanIf_kstrRxMsgInfo[COM_RXPDUNUM];
extern CanIf_tstrDataAddrType CanIf_kstrRxPduBuf[COM_RXPDUNUM];
extern CanIf_tstrRxCtrlType CanIf_strRxCtrl[COM_RXPDUNUM];

extern const uint32 CanIf_ku32TpRxMsgId[TP_RXPDUNUM];
extern const CanTp_tenuTpTaType CanIf_kenuTpTa[TP_RXPDUNUM];
/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
/******************************************************************************/   
/*Rx indication function definition                                           */
/******************************************************************************/
extern void AppCom_vidRxInd_GW_BD_ACU_DirverInfo(void); 
extern void AppCom_vidRxInd_GW_BD_HU_ACCtrlReq(void);
extern void AppCom_vidRxInd_GW_BD_HU_LightandSRCtrlReq(void);
extern void AppCom_vidRxInd_GW_BD_VCU_PT_ACPwrSpd(void);
extern void AppCom_vidRxInd_GW_BD_BMS_TempIso(void);
extern void AppCom_vidRxInd_GW_BD_VCU_PT_HVCmdandPwrAllot(void);
extern void AppCom_vidRxInd_GW_BD_ESP_GeneralStatus(void);
extern void AppCom_vidRxInd_GW_BD_BMS_RESSPTCandCmpsReq(void);
extern void AppCom_vidRxInd_GW_BD_HU_DriveCtrlReq(void);
extern void AppCom_vidRxInd_GW_BD_IPC_DisplayInfo(void);
extern void AppCom_vidRxInd_GW_BD_BMS_RESSTempInfo(void);

/******************************************************************************/   
/*rx Ipdu timeout indication function definition                              */
/******************************************************************************/ 
extern void AppCom_vidToInd_GW_BD_ACU_DirverInfo(void);
extern void AppCom_vidToInd_GW_BD_HU_ACCtrlReq(void);
extern void AppCom_vidToInd_GW_BD_HU_LightandSRCtrlReq(void);
extern void AppCom_vidToInd_GW_BD_VCU_PT_ACPwrSpd(void);
extern void AppCom_vidToInd_GW_BD_BMS_TempIso(void);
extern void AppCom_vidToInd_GW_BD_VCU_PT_HVCmdandPwrAllot(void);
extern void AppCom_vidToInd_GW_BD_ESP_GeneralStatus(void);
extern void AppCom_vidToInd_GW_BD_BMS_RESSPTCandCmpsReq(void);
extern void AppCom_vidToInd_GW_BD_HU_DriveCtrlReq(void);
extern void AppCom_vidToInd_GW_BD_IPC_DisplayInfo(void);
extern void AppCom_vidToInd_GW_BD_BMS_RESSTempInfo(void);

extern void AppCom_vidRxInd_ABS_ESP_G();
extern void AppCom_vidToInd_ABS_ESP_G();
extern void AppCom_vidRxInd_ADCC_4();
extern void AppCom_vidToInd_ADCC_4();
extern void AppCom_vidRxInd_AIPM_1();
extern void AppCom_vidToInd_AIPM_1();
extern void AppCom_vidRxInd_AIPM_2();
extern void AppCom_vidToInd_AIPM_2();
extern void AppCom_vidRxInd_BCM_11();
extern void AppCom_vidToInd_BCM_11();
extern void AppCom_vidRxInd_BMS_2();
extern void AppCom_vidToInd_BMS_2();
extern void AppCom_vidRxInd_BMS_4();
extern void AppCom_vidToInd_BMS_4();
extern void AppCom_vidRxInd_BMS_5();
extern void AppCom_vidToInd_BMS_5();
extern void AppCom_vidRxInd_BMS_7();
extern void AppCom_vidToInd_BMS_7();
extern void AppCom_vidRxInd_DCDC_1();
extern void AppCom_vidToInd_DCDC_1();
extern void AppCom_vidRxInd_OBC_3();
extern void AppCom_vidToInd_OBC_3();
extern void AppCom_vidToInd_OBC_4();
extern void AppCom_vidRxInd_OBC_4();
extern void AppCom_vidToInd_TIHU_IHU_4();
extern void AppCom_vidRxInd_TIHU_IHU_4();
extern void AppCom_vidToInd_TMF_4();
extern void AppCom_vidRxInd_TMF_4();
extern void AppCom_vidToInd_TMR_4();
extern void AppCom_vidRxInd_TMR_4();
extern void AppCom_vidToInd_VCC_7();
extern void AppCom_vidRxInd_VCC_7();
extern void AppCom_vidToInd_TMF_2();
extern void AppCom_vidRxInd_TMF_2();
extern void AppCom_vidToInd_TMR_2();
extern void AppCom_vidRxInd_TMR_2();
/******************************************************************************/   
/*tx Ipdu indication function definition                                      */
/******************************************************************************/   
extern void AppCom_vidTxInd_AC_PwrAlloted(uint8 *pu8Data); /*0X398 D01*/
extern void AppCom_vidTxInd_AC_ACCtrlFeedback(uint8 *pu8Data);  /*0X3E8 D01*/
extern void AppCom_vidTxInd_AC_TempInfo(uint8 *pu8Data); /*0X538 D01*/
extern void AppCom_vidTxInd_AC_PwrInfo(uint8 *pu8Data); /*0x558 D01*/
extern void AppCom_vidTxInd_AC_SHMNumber(uint8 *pu8Data); /*0X609 D01*/
extern void AppCom_vidTxInd_AC_LightAndTemp(uint8 *pu8Data);  /*0X508 D01*/

extern void AppCom_vidTxInd_AC_Diagnosis1(uint8 *pu8Data);
extern void AppCom_vidTxInd_AC_Diagnosis2(uint8 *pu8Data);
extern void AppCom_vidTxInd_AC_Diagnosis3(uint8 *pu8Data);
extern void AppCom_vidTxInd_AC_Diagnosis4(uint8 *pu8Data);
extern void AppCom_vidTxInd_AC_Diagnosis5(uint8 *pu8Data);
extern void AppCom_vidTxInd_AC_Diagnosis6(uint8 *pu8Data);
extern void AppCom_vidTxInd_CLM_1(uint8 *pu8Data);
extern void AppCom_vidTxInd_CLM_11(uint8 *pu8Data);
extern void AppCom_vidTxInd_CLM_2(uint8 *pu8Data);

#endif  /* XXX_H */ 

/*-------------------------------- end of file ----------------------------*/

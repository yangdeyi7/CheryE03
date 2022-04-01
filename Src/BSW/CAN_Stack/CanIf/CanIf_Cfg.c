/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "CanIf_Cfg.h"
#include "CanIf.h"

#include "dbc2struct.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


const static uint8  CanIf_au8DefaultValue_FF[8]=
{
  0x0u, 0x0u, 0x0u, 0x0u, 0x0u, 0x0u, 0x0u, 0x0u
};

/*********send msg info**********/
const CanIf_tstrTxMsgInfoType CanIf_kstrTxMsgInfo[COM_TXPDUNUM] = 
{ 
	/*msg0*/
	{
		{0x5A6u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		}, 
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_IfActive, /*Msg type*/
		&AppCom_vidTxInd_AC_Diagnosis1, /*call back func*/
		0u	/*msg buf number*/
	},
	/*msg1*/
	{
		{0x5A7u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_AC_Diagnosis2, /*call back func*/
		1u	/*msg buf number*/
	},
	/*msg2*/
	{
		{0x5A4u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_AC_Diagnosis3, /*call back func*/
		2u	/*msg buf number*/
	},
	/*msg3*/
	{
		{0x5A5u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_AC_Diagnosis4, /*call back func*/
		3u	/*msg buf number*/
	},
	/*msg4*/
	{
		{0x5A1u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		5000u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_AC_Diagnosis5, /*call back func*/
		4u	/*msg buf number*/
	},
	/*msg5*/
	{
		{0x5A2u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_AC_Diagnosis6, /*call back func*/
		5u	/*msg buf number*/
	},
	/*msg6*/
	{
		{0x51Au, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_CLM_1, /*call back func*/
		6u	/*msg buf number*/
	},
    /*msg7*/
	{
		{0x3F6u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_CLM_11, /*call back func*/
		7u	/*msg buf number*/
	},
	 /*msg8*/
	{
		{0x535u, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		100u, /*cycle time*/
		0u,  /*cycle time fast*/
		0u,   /*NbOfRepetition*/
		MST_Cycle, /*Msg type*/
		&AppCom_vidTxInd_CLM_2, /*call back func*/
		8u	/*msg buf number*/
	},
};

/**********receive msg info********/
const CanIf_tstrRxMsgInfoType CanIf_kstrRxMsgInfo[COM_RXPDUNUM] = 
{ 
	/*msg0*/
	{
		{0X502, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_ABS_ESP_G, /*RxIndication*/
		&AppCom_vidToInd_ABS_ESP_G /*TOIndication*/
	},
	/*msg1*/
	{
		{0X16B, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/
			
		&AppCom_vidRxInd_ADCC_4, /*RxIndication*/
		&AppCom_vidToInd_ADCC_4 /*TOIndication*/
	},
	/*msg2*/
	{
		{0X4F1, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_AIPM_1, /*RxIndication*/
		&AppCom_vidToInd_AIPM_1 /*TOIndication*/
	},
	/*msg3*/
	{
		{0X4F3, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_AIPM_2, /*RxIndication*/
		&AppCom_vidToInd_AIPM_2 /*TOIndication*/
	},
	/*msg4*/
	{
		{0x427, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_BCM_11, /*RxIndication*/
		&AppCom_vidToInd_BCM_11 /*TOIndication*/
	},
	/*msg5*/
	{
		{0x208, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_BMS_2, /*RxIndication*/
		&AppCom_vidToInd_BMS_2 /*TOIndication*/
	},	
	/*msg6*/
	{
		{0X41F, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_BMS_4, /*RxIndication*/
		&AppCom_vidToInd_BMS_4 /*TOIndication*/
	},		
	/*msg7*/
	{
		{0x41B, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_BMS_5, /*RxIndication*/
		&AppCom_vidToInd_BMS_5 /*TOIndication*/
	},
	/*msg8*/
	{
		{0x426, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_BMS_7, /*RxIndication*/
		&AppCom_vidToInd_BMS_7 /*TOIndication*/
	},
	/*msg9*/
	{
		{0x418, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_DCDC_1, /*RxIndication*/
		&AppCom_vidToInd_DCDC_1 /*TOIndication*/
	},
	/*msg10*/
	{
		{0X42B, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_OBC_3, /*RxIndication*/
		&AppCom_vidToInd_OBC_3 /*TOIndication*/
	},
    /*msg11*/
	{
		{0x43C, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_OBC_4, /*RxIndication*/
		&AppCom_vidToInd_OBC_4 /*TOIndication*/
	},
    /*msg12*/
	{
		{0x519, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_TIHU_IHU_4, /*RxIndication*/
		&AppCom_vidToInd_TIHU_IHU_4 /*TOIndication*/
	},
    /*msg13*/
	{
		{0x45B, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_TMF_4, /*RxIndication*/
		&AppCom_vidToInd_TMF_4 /*TOIndication*/
	},
    /*msg14*/
	{
		{0x48B, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_TMR_4, /*RxIndication*/
		&AppCom_vidToInd_TMR_4 /*TOIndication*/
	},
    /*msg15*/
	{
		{0x3FE, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_VCC_7, /*RxIndication*/
		&AppCom_vidToInd_VCC_7 /*TOIndication*/
	},
    /*msg16*/
	{
		{0x315, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_TMF_2, /*RxIndication*/
		&AppCom_vidToInd_TMF_2 /*TOIndication*/
	},
    /*msg17*/
	{
		{0x31E, /*ID*/
		8u, /*dlc*/
		(uint8 *)CanIf_au8DefaultValue_FF	/*data buffer addr*/
		},
		TRUE, /*TOMonitored*/
		2000u, /*RxTimeout*/

		&AppCom_vidRxInd_TMR_2, /*RxIndication*/
		&AppCom_vidToInd_TMR_2 /*TOIndication*/
	}
};   


const uint32 CanIf_ku32TpRxMsgId[TP_RXPDUNUM]=
{
    0x7A3u,
    0x7DFu
};	

const CanTp_tenuTpTaType CanIf_kenuTpTa[TP_RXPDUNUM]=
{
    CANTP_TTT_PHYSICAL,
    CANTP_TTT_FUNCTIONAL
};

CanIf_tstrDataAddrType CanIf_kstrRxPduBuf[COM_RXPDUNUM]=
{
#if 1
    canFrames[CanFrameIndex_ABS_ESP_G].canbuffer,
    canFrames[CanFrameIndex_ADCC_4].canbuffer,
    canFrames[CanFrameIndex_AIPM_1].canbuffer,
    canFrames[CanFrameIndex_AIPM_2].canbuffer,
    canFrames[CanFrameIndex_BCM_11].canbuffer,
    canFrames[CanFrameIndex_BMS_2].canbuffer,
    canFrames[CanFrameIndex_BMS_4].canbuffer,
    canFrames[CanFrameIndex_BMS_5].canbuffer,
    canFrames[CanFrameIndex_BMS_7].canbuffer,
    canFrames[CanFrameIndex_DCDC_1].canbuffer,
    canFrames[CanFrameIndex_OBC_3].canbuffer,
    canFrames[CanFrameIndex_OBC_4].canbuffer,
    canFrames[CanFrameIndex_TIHU_IHU_4].canbuffer,
    canFrames[CanFrameIndex_TMF_4].canbuffer,
    canFrames[CanFrameIndex_TMR_4].canbuffer,
    canFrames[CanFrameIndex_VCC_7].canbuffer,
    canFrames[CanFrameIndex_TMF_2].canbuffer,
    canFrames[CanFrameIndex_TMR_2].canbuffer,
#else
    CanIf_uniRxMsgType_ABS_ESP_G._c, /*0-0X502 */
    CanIf_uniRxMsgType_ADCC_4._c,  /*0X16B */
    CanIf_uniRxMsgType_AIPM_1._c,  /*0x4f1 */
    CanIf_uniRxMsgType_AIPM_2._c,  /*0X4f3 */
    CanIf_uniRxMsgType_BCM_11._c,  /*0X427 */
    CanIf_uniRxMsgType_BMS_2._c, /*0X208 */
    CanIf_uniRxMsgType_BMS_4._c,  /*0X41f */
    CanIf_uniRxMsgType_BMS_5._c, /*0X41b */
    CanIf_uniRxMsgType_BMS_7._c,  /*0X426 */
    CanIf_uniRxMsgType_DCDC_1._c,  /*0X418 */
    CanIf_uniRxMsgType_OBC_3._c,  /*0X42b */
    CanIf_uniRxMsgType_OBC_4._c, /*0X43c */
    CanIf_uniRxMsgType_TIHU_IHU_4._c,  /*0X519 */
    CanIf_uniRxMsgType_TMF_4._c,  /*0X45b*/
    CanIf_uniRxMsgType_TMR_4._c,  /*0X48b */
    CanIf_uniRxMsgType_VCC_7._c,  /*0X3Fe */
#endif
};

CanIf_tstrDataAddrType CanIf_kstrTxPduBuf[COM_TXPDUNUM]=
{
#if 1
    canFrames[CanFrameIndex_AC_Diagnosis1].canbuffer,
    canFrames[CanFrameIndex_AC_Diagnosis2].canbuffer,
    canFrames[CanFrameIndex_AC_Diagnosis3].canbuffer,
    canFrames[CanFrameIndex_AC_Diagnosis4].canbuffer,
    canFrames[CanFrameIndex_AC_Diagnosis5].canbuffer,
    canFrames[CanFrameIndex_AC_Diagnosis6].canbuffer,
    canFrames[CanFrameIndex_CLM_1].canbuffer,
    canFrames[CanFrameIndex_CLM_11].canbuffer,
    canFrames[CanFrameIndex_CLM_2].canbuffer,
#else
	CanIf_uniTxMsgType_AC_Diagnosis1._c, /*0x5A6*/
	CanIf_uniTxMsgType_AC_Diagnosis2._c, /*0X5A7*/
	CanIf_uniTxMsgType_AC_Diagnosis3._c, /*0X5A4*/
	CanIf_uniTxMsgType_AC_Diagnosis4._c,  /*0X5A5*/
	CanIf_uniTxMsgType_AC_Diagnosis5._c, /*0X5A1*/
	CanIf_uniTxMsgType_AC_Diagnosis6._c, /*0X5A2*/
    CanIf_uniTxMsgType_CLM_1._c,  /*0X5A5*/
	CanIf_uniTxMsgType_CLM_11._c, /*0X5A1*/
	CanIf_uniTxMsgType_CLM_2._c   /*0X5A2*/      
#endif
};

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/******************************************************************************/   
/* Databuffer for receive objects                                             */ 
/******************************************************************************/ 
CanIf_tuniRxMsgType_GW_BD_ACU_DirverInfo CanIf_uniRxMsgType_GW_BD_ACU_DirverInfo;
CanIf_tuniRxMsgType_GW_BD_HU_ACCtrlReq CanIf_uniRxMsgType_GW_BD_HU_ACCtrlReq;
CanIf_tuniRxMsgType_GW_BD_HU_LightandSRCtrlReq CanIf_uniRxMsgType_GW_BD_HU_LightandSRCtrlReq;
CanIf_tuniRxMsgType_GW_BD_VCU_PT_ACPwrSpd CanIf_uniRxMsgType_GW_BD_VCU_PT_ACPwrSpd;
CanIf_tuniRxMsgType_GW_BD_BMS_TempIso CanIf_uniRxMsgType_GW_BD_BMS_TempIso;
CanIf_tuniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot CanIf_uniRxMsgType_GW_BD_VCU_PT_HVCmdandPwrAllot;
CanIf_tuniRxMsgType_GW_BD_ESP_GeneralStatus CanIf_uniRxMsgType_GW_BD_ESP_GeneralStatus;
CanIf_tuniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq CanIf_uniRxMsgType_GW_BD_BMS_RESSPTCandCmpsReq;
CanIf_tuniRxMsgType_GW_BD_HU_DriveCtrlReq CanIf_uniRxMsgType_GW_BD_HU_DriveCtrlReq;
CanIf_tuniRxMsgType_GW_BD_IPC_DisplayInfo CanIf_uniRxMsgType_GW_BD_IPC_DisplayInfo;
CanIf_tuniRxMsgType_GW_BD_BMS_RESSTempInfo CanIf_uniRxMsgType_GW_BD_BMS_RESSTempInfo;
//demo car
CanIf_tuniRxMsgType_ABS_ESP_G  CanIf_uniRxMsgType_ABS_ESP_G;   /*0X502*/
CanIf_tuniRxMsgType_ADCC_4 CanIf_uniRxMsgType_ADCC_4; /*0X16B*/
CanIf_tuniRxMsgType_AIPM_1 CanIf_uniRxMsgType_AIPM_1; /*0X4F1*/
CanIf_tuniRxMsgType_AIPM_2 CanIf_uniRxMsgType_AIPM_2; /*0X4F3*/
CanIf_tuniRxMsgType_BCM_11 CanIf_uniRxMsgType_BCM_11; /*0x427*/
CanIf_tuniRxMsgType_BMS_2 CanIf_uniRxMsgType_BMS_2; /*0x208*/
CanIf_tuniRxMsgType_BMS_4  CanIf_uniRxMsgType_BMS_4; /*0X41F*/
CanIf_tuniRxMsgType_BMS_5 CanIf_uniRxMsgType_BMS_5; /*0x41B*/
CanIf_tuniRxMsgType_BMS_7  CanIf_uniRxMsgType_BMS_7; /*0x426*/
CanIf_tuniRxMsgType_DCDC_1  CanIf_uniRxMsgType_DCDC_1; /*0x418*/
CanIf_tuniRxMsgType_OBC_3  CanIf_uniRxMsgType_OBC_3; /*0X42B*/
CanIf_tuniRxMsgType_OBC_4 CanIf_uniRxMsgType_OBC_4; /*0x43C*/
CanIf_tuniRxMsgType_TIHU_IHU_4  CanIf_uniRxMsgType_TIHU_IHU_4; /*0x519*/
CanIf_tuniRxMsgType_TMF_4  CanIf_uniRxMsgType_TMF_4; /*0x45B*/
CanIf_tuniRxMsgType_TMR_4 CanIf_uniRxMsgType_TMR_4; /*0x48B*/
CanIf_tuniRxMsgType_VCC_7  CanIf_uniRxMsgType_VCC_7; /*0x3FE*/
/******************************************************************************/   
/* Databuffer for send    objects                                             */ 
/******************************************************************************/  
CanIf_tuniTxMsgType_AC_PwrAlloted CanIf_uniTxMsgType_AC_PwrAlloted; 
CanIf_tuniTxMsgType_AC_ACCtrlFeedback CanIf_uniTxMsgType_AC_ACCtrlFeedback; 
CanIf_tuniTxMsgType_AC_TempInfo CanIf_uniTxMsgType_AC_TempInfo; 
CanIf_tuniTxMsgType_AC_PwrInfo CanIf_uniTxMsgType_AC_PwrInfo;
CanIf_tuniTxMsgType_AC_SHMNumber CanIf_uniTxMsgType_AC_SHMNumber;
CanIf_tuniTxMsgType_AC_LightAndTemp CanIf_uniTxMsgType_AC_LightAndTemp;

CanIf_tuniTxMsgType_AC_Diagnosis1 CanIf_uniTxMsgType_AC_Diagnosis1;   /*0X5A6*/
CanIf_tuniTxMsgType_AC_Diagnosis2 CanIf_uniTxMsgType_AC_Diagnosis2; /*0X5A7*/
CanIf_tuniTxMsgType_AC_Diagnosis3 CanIf_uniTxMsgType_AC_Diagnosis3; /*0X5A4*/
CanIf_tuniTxMsgType_AC_Diagnosis4 CanIf_uniTxMsgType_AC_Diagnosis4; /*0X5A5*/
CanIf_tuniTxMsgType_AC_Diagnosis5 CanIf_uniTxMsgType_AC_Diagnosis5; /*0x5A1*/
CanIf_tuniTxMsgType_AC_Diagnosis6 CanIf_uniTxMsgType_AC_Diagnosis6; /*0x5A2*/
CanIf_tuniTxMsgType_CLM_1  CanIf_uniTxMsgType_CLM_1; /*0X51A*/
CanIf_tuniTxMsgType_CLM_11 CanIf_uniTxMsgType_CLM_11; /*0x3F6*/
CanIf_tuniTxMsgType_CLM_2  CanIf_uniTxMsgType_CLM_2; /*0x535*/

/*control variable*/
CanIf_tstrRxCtrlType CanIf_strRxCtrl[COM_RXPDUNUM];

CanIf_tstrTxCtrlType CanIf_strTxCtrl[COM_TXPDUNUM];
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/


/*-------------------------------- end of file -------------------------------*/

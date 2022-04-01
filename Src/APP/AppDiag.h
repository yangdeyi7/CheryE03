/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : App                                                     */
/*                                                                            */
/* !Component       : AppDiag                                                 */
/* !Description     : App diag   interface                                    */
/*                                                                            */
/* !Module          : AppDiag                                                 */
/* !Description     : App diag   interface                                    */
/*                                                                            */
/* !File            : AppDiag.h                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/APP/AppDiag.h-arc  $
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

#ifndef APPDIAG_H
#define APPDIAG_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "CanDiag.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#pragma pack(1)
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef struct
{
/************************Auto/Manual Contrl************************************/
    uint16      Diag_u8manualCtrlMode;
/************************Model Input*******************************************/
    uint16     THM_In_u16P_Ref_CondOut_A10;
    uint16     THM_In_u16P_Ref_EvaOut_A10;
    uint16     THM_In_u16P_Ref_CHILOut_A10;
    sint16     THM_In_s16T_Ref_CHILOut_A10;
    sint16     THM_In_s16T_Ref_EDCIn_A10;
    sint16     THM_In_s16Teva_Front_A10;
    sint16     THM_In_s16Teva_Rear_A10;
    sint16     THM_In_s16TevaSet_Req_A10;
    boolean    THM_In_bAcSts;
    sint16     THM_In_s16Tamb_A10;
    sint16     THM_In_s16Tincar_Front_A10;
    sint16     THM_In_s16Tincar_Rear_A10;
    uint8      THM_In_u8VehSpd;
    uint8      THM_In_u8PWM_FrontFAN;
    boolean    THM_In_bAGS_Status;
    uint8      THM_In_u8AGS_Position;
    uint8      THM_In_u8VehicleType;
    uint16     THM_In_u16PowerComp;
    uint16     THM_In_u16Ncomp;
    uint16     THM_In_u16Power_Max;
    uint16     THM_In_u16Ncomp_Max;
    boolean    THM_In_bSOV_Eva;
    boolean    THM_In_bSOV_OutEva;
    boolean    THM_In_bSOV_TXVOutEva;
    uint16     THM_In_u16EXV_Eva_Pos;
    uint16     THM_In_u16EXV_Chil_Pos;
    sint16     THM_In_s16Tincar_Setting_Req_A10;
    uint8      THM_In_u8BlwVol_Real_A10;
    uint8      THM_In_u8ModeStatus_Real;
    uint8      THM_In_u8IntakePerc_Real;
    uint8      THM_In_u8Mix_Flap_Position_L;
    uint8      THM_In_u8Mix_Flap_Position_R;
    sint16     THM_In_u16Tset_Left_A10;
    sint16     THM_In_u16Tset_Right_A10;
    sint16     THM_In_s16Tasd_Left_Req_A10;
    sint16     THM_In_s16Tasd_Right_Req_A10;
    sint16     THM_In_s16TDuct_Left_Out_A10;
    sint16     THM_In_s16TDuct_Right_Out_A10;
    boolean    THM_In_bEco_Model_Set;
    uint8      THM_In_u8HVACSts;
    boolean    THM_In_bFlag_HeatShort_Blw_Req;
    uint16     THM_In_u16Rainfall;
    uint16     THM_In_u16Solar;
    sint16     THM_In_s16T_Wat_BatIn_A10;
    sint16     THM_In_s16T_Wat_HVCHOut_A10;
    sint16     THM_In_s16T_Wat_LTROut_A10;
    sint16     THM_In_s16T_Wat_MotorIn_A10;
    sint16     THM_In_s16T_Wat_MotorOut_A10;
    sint16     THM_In_s16TbatMax_A10;
    sint16     THM_In_s16TbatAvr_A10;
    sint16     THM_In_s16TbatMin_A10;
    uint8      THM_In_u8BAT_CoolHeatLv;
    sint16     THM_In_s16T_BAT_Wat_Set_A10;
    uint8      THM_In_u8Mot_CoolLv;
    uint8      THM_In_u8TWValve_HC_Position;
    uint8      THM_In_u8TWValve_LTR_Position;
    uint8      THM_In_u8TWValve_BAT_Position;
    uint8      THM_In_u8HVCH_Status;
    uint16     THM_In_u16Pump_HVCH;
    uint16     THM_In_u16Pump_Motor;
    uint16     THM_In_u16Pump_Bat;
    uint8      THM_In_u8IgnSts;
    uint16     THM_In_u16PowerHVCH;
    boolean    THM_In_bDTC_P_Ref_CondOut;
    boolean    THM_In_bDTC_P_Ref_EvaOut;
    boolean    THM_In_bDTC_P_Ref_CHILOut;
    boolean    THM_In_bDTC_T_Ref_CHILOut;
    boolean    THM_In_bDTC_T_Ref_EDCIn;
    boolean    THM_In_bDTC_Teva_Front;
    boolean    THM_In_bDTC_Tamb;
    boolean    THM_In_bDTC_SOV_Eva;
    boolean    THM_In_bDTC_SOV_OutEva;
    boolean    THM_In_bDTC_SOV_TXVOutEva;
    boolean    THM_In_bDTC_EXV_Eva_Pos;
    boolean    THM_In_bDTC_EXV_Chil_Pos;
    boolean    THM_In_bDTC_BLW_Front;
    boolean    THM_In_bDTC_EDC_Front;
    boolean    THM_In_bDTC_TWValve_HC;
    boolean    THM_In_bDTC_TWValve_LTR;
    boolean    THM_In_bDTC_TWValve_BAT;
    boolean    THM_In_bDTC_HVCH;
    boolean    THM_In_bDTC_Pump_HVCH;
    boolean    THM_In_bDTC_Pump_Motor;
    boolean    THM_In_bDTC_Pump_Bat;
    sint16     THM_In_s16T_Ref_EDCOut_A10;
/************************Model output*******************************************/
    uint16     THM_Out_u16Ncomp_Rpm_Req;
    boolean    THM_Out_bSOV_Eva_Req;
    boolean    THM_Out_bSOV_OutEva_Req;
    boolean    THM_Out_bSOV_TXVOutEva_Req;
    uint16     THM_Out_u16EXV_Eva_Pos_Req;
    uint16     THM_Out_u16EXV_Chil_Pos_Req;
    uint8      THM_Out_u8HpWorkMode_Req;
    uint8      THM_Out_u8AGS_Position_Req;
    uint8      THM_Out_u8FRFAN_PWM_Req;
    uint8      THM_Out_u8Mix_Left_Req;
    uint8      THM_Out_u8Mix_Right_Req;
    uint8      THM_Out_u8DTC_Ref_System;
    uint8      THM_Out_u8DTC_Ref_Component;
    boolean    THM_Out_bDTC_EvaFreeze;
    boolean    THM_Out_bDTC_OutEvaFreeze;
    uint8      THM_Out_u8TWValve_HC_Req;
    uint8      THM_Out_u8TWValve_LTR_Req;
    uint8      THM_Out_u8TWValve_BAT_Req;
    uint8      THM_Out_u8HVCH_Req;
    uint16     THM_Out_u16Pump_HVCH_Req;
    uint16     THM_Out_u16Pump_Motor_Req;
    uint16     THM_Out_u16Pump_Bat_Req;
}AppDiag_tstrSendToPcDisplayData;
#pragma pack()

typedef union
{
  AppDiag_tstrSendToPcDisplayData  strSendToPcDisplayData;
  uint8                            u8DataAll[sizeof(AppDiag_tstrSendToPcDisplayData)];
}AppDiag_tuniSendToPcDisplayData;

extern AppDiag_tuniSendToPcDisplayData  AppDiag_uniSendToPcDisplayData;
/**********************************************************************************/
#pragma pack(1)
typedef struct
{
/************************Auto/Manual Contrl************************************/
    uint8      Diag_u8manualCtrlMode;
/************************uppc set data to MBD input value**********************/
/************************Manual Contrl by upper pc*****************************/
    sint16     THM_In_s16TevaSet_Req_A10;
    boolean    THM_In_bAcSts;
    sint16     THM_In_s16Tamb_A10;
    sint16     THM_In_s16Tincar_Front_A10;
    uint8      THM_In_u8VehSpd;
    sint16     THM_In_s16Tincar_Setting_Req_A10;
    sint16     THM_In_s16Tset_Left_A10;
    sint16     THM_In_s16Tset_Right_A10;
    sint16     THM_In_s16Tasd_Left_Req_A10;
    sint16     THM_In_s16Tasd_Right_Req_A10;
    boolean    THM_In_bEco_Model_Set;
    uint8      THM_In_u8HVACSts;
    boolean    THM_In_bFlag_HeatShort_Blw_Req;
    sint16     THM_In_s16TbatMax_A10;
    sint16     THM_In_s16TbatAvr_A10;
    sint16     THM_In_s16TbatMin_A10;
    uint8      THM_In_u8BAT_CoolHeatLv;
    sint16     THM_In_s16T_BAT_Wat_Set_A10;
    uint8      THM_In_u8Mot_CoolLv;
    uint8      THM_In_u8IgnSts;
    uint16     THM_Out_u16Ncomp_Rpm_Req;
    boolean    THM_Out_bSOV_Eva_Req;
    boolean    THM_Out_bSOV_OutEva_Req;
    boolean    THM_Out_bSOV_TXVOutEva_Req;
    uint16     THM_Out_u16EXV_Eva_Pos_Req;
    uint16     THM_Out_u16EXV_Chil_Pos_Req;
    uint8      THM_Out_u8HpWorkMode_Req;
    uint8      THM_Out_u8FRFAN_PWM_Req;
    uint8      THM_Out_u8Mix_Left_Req;
    uint8      THM_Out_u8Mix_Right_Req;
    uint8      THM_Out_u8TWValve_HC_Req;
    uint8      THM_Out_u8TWValve_LTR_Req;
    uint8      THM_Out_u8TWValve_BAT_Req;
    uint8      THM_Out_u8HVCH_Req;
    uint16     THM_Out_u16Pump_HVCH_Req;
    uint16     THM_Out_u16Pump_Motor_Req;
    uint16     THM_Out_u16Pump_Bat_Req;
    uint16     CmfO_u16Blw_Rpm_Req;
    uint8      CmfO_u8Rec_Req;
    uint8      CmfO_u8Mode_Left_Req;
    uint8      CmfO_u8Mode_Right_Req;
    uint8      CmfO_u8Defrost_Req;

}AppDiag_tstrRecvFormPcData;
#pragma pack()

typedef union
{
  AppDiag_tstrRecvFormPcData        strRecvFormPcData;
  uint8                             u8DataAll[sizeof(AppDiag_tstrRecvFormPcData)];
}AppDiag_tuniRecvFormPcData;

extern AppDiag_tuniRecvFormPcData   AppDiag_uniRecvFormPcData;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void AppDiag_vidInit(void);
extern uint8 AppDiag_u8GetIoCtrlFlag(void);
extern void AppDiag_vidClearIoCtrlFlag(void);
extern boolean AppDiag_bCheckKey(uint8 u8Lvl, uint8* pau8Seeds, uint8* pau8Key);
extern boolean AppDiag_bPreConditionCheck(uint8 u8SerId);
#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/

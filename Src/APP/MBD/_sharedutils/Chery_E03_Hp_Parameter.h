/*
 * File: Chery_E03_Hp_Parameter.h
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#ifndef RTW_HEADER_Chery_E03_Hp_Parameter_h_
#define RTW_HEADER_Chery_E03_Hp_Parameter_h_
#include "rtwtypes.h"

typedef struct {
  int16_T Hp_s16Tdelta_HC_Evap_u1[5];
  uint16_T Hp_u16Ki_Mix_Normal_y[5];
} Hp_u16Ki_Mix_Normal_Tab;

typedef struct {
  int16_T Hp_s16Tdelta_HC_Evap_u1[5];
  uint16_T Hp_u16Kp_Mix_Normal_y[5];
} Hp_u16Kp_Mix_Normal_Tab;

typedef struct {
  int16_T s16POMI_Mix_Vent[11];
  uint8_T u8Pos_MixStepper_Pomi_y[11];
} u8Pos_MixStepper_Pomi_Tab;

typedef struct {
  int16_T s16POMI_Mix_VF[12];
  uint8_T u8Pos_MixStepper_Pomi_95_y[12];
} u8Pos_MixStepper_Pomi_95_Tab;

typedef struct {
  uint8_T HP_u8_Pratio_u1[4];
  uint16_T HP_u16_Pratio_Delay_Time_y[4];
} HP_u16_Pratio_Delay_Tab;

typedef struct {
  int16_T HP_s16Tamb_AC_u1[8];
  int16_T HP_s16Twater_Req_Cmf_u2[10];
  uint8_T HP_u8TWV_HVCH_AC_y[80];
} HP_u8TWV_HVCH_AC_Tab;

typedef struct {
  int16_T HP_s16Tamb_AC_u1[8];
  int16_T HP_s16TDelta_Wat_Amb_u2[6];
  uint16_T HP_u16Pump_HVCH_AC_y[48];
} HP_u16Pump_HVCH_AC_Tab;

typedef struct {
  int16_T s16Teva_load_u1[7];
  uint8_T u8HVAC_BlwVol_u2[7];
  uint16_T u16Ncomp_AC_Est_y[49];
} u16Ncomp_AC_Est_Tab;

typedef struct {
  int16_T s16Teva_CtrlDelta_u1[8];
  uint16_T u16KpRatio_CompAC_y[8];
} u16KpRatio_CompAC_Tab;

typedef struct {
  uint16_T u16Postion_ChillerEXV_u1[8];
  uint16_T u16Ncomp_EXVEst_y[8];
} u16Ncomp_EXVEst_Tab;

typedef struct {
  int16_T s16TEMP_Text_u1[7];
  uint8_T u8HVAC_BlwVol_u2[7];
  uint16_T u16Kp_EDC_ACChil_y[49];
} u16Kp_EDC_ACChil_Tab;

typedef struct {
  int16_T AC_s16Teva_CtrlDelta[8];
  int16_T AC_s16Teva_CtrlTi_y[8];
} AC_s16Teva_CtrlTi_Tab;

typedef struct {
  int16_T s16TambEdcRamp_u1[6];
  uint16_T u16Prco_ACMode_u2[6];
  uint16_T u16ACMode_EdcRamp_y[36];
} u16ACMode_EdcRamp_Tab;

typedef struct {
  int16_T s16EdcTout_Risk_u1[8];
  uint16_T u16Edc_ToutReduce_y[8];
} u16Edc_ToutReduce_Tab;

typedef struct {
  uint16_T u16ACPrco_risk_u1[8];
  uint16_T u16ACNcomp_PrcoRisk_y[8];
} u16ACNcomp_PrcoRisk_Tab;

typedef struct {
  int16_T s16Power_Comp_gap_u1[8];
  uint16_T u16Ncomp_PowRisk_y[8];
} u16Ncomp_PowRisk_Tab;

typedef struct {
  int16_T s16Teva_risk_u1[8];
  uint16_T u16Ncomp_EvaRisk_y[8];
} u16Ncomp_EvaRisk_Tab;

typedef struct {
  int16_T AC_s16TBat_In_delta_Lv1_u1[8];
  int16_T AC_s16ExvStepsOpen_Lv1_y[8];
} AC_s16ExvStepsOpen_Lv1_Tab;

typedef struct {
  int16_T AC_s16TEva_delta_Lv1_u1[8];
  int16_T AC_s16ExvStepsClose_Lv1_y[8];
} AC_s16ExvStepsClose_Lv1_Tab;

typedef struct {
  int16_T AC_s16TBat_In_delta_Lv2_u1[8];
  int16_T AC_s16ExvStepsOpen_Lv2_y[8];
} AC_s16ExvStepsOpen_Lv2_Tab;

typedef struct {
  int16_T AC_s16TEva_delta_Lv2_u1[8];
  int16_T AC_s16ExvStepsClose_Lv2_y[8];
} AC_s16ExvStepsClose_Lv2_Tab;

typedef struct {
  int16_T AC_s16TBatIn_Delta_Lv3_u1[10];
  int16_T AC_s16ExvCtrl_Ki_Lv3_y[10];
} AC_s16ExvCtrl_Ki_Lv3_Tab;

typedef struct {
  int16_T AC_s16TBatIn_Delta_Lv3_u1[10];
  int16_T AC_s16ExvCtrl_Kp_Lv3_y[10];
} AC_s16ExvCtrl_Kp_Lv3_Tab;

typedef struct {
  int16_T s16Tamb_Common2_u1[10];
  uint16_T u16Ncomp_RPM_u2[7];
  uint16_T u16EXV_Eva_Pos_AC_Est_y[70];
} u16EXV_Eva_Pos_AC_Est_Tab;

typedef struct {
  int16_T s16Chil_Exv_SH_delta[8];
  uint16_T u16Chil_EXV_Kp_y[8];
} u16Chil_EXV_Kp_Tab;

typedef struct {
  int16_T s16Chil_Exv_SH_delta[8];
  int16_T s16Chil_EXV_Ki_y[8];
} s16Chil_EXV_Ki_Tab;

typedef struct {
  uint16_T AC_u16Vspd_FAN_u1[7];
  uint16_T AC_u16Prco_FAN_u2[7];
  uint16_T AC_u16PWM_FAN_AC_y[49];
} AC_u16PWM_FAN_AC_Tab;

typedef struct {
  uint16_T u16Prco_risk_u1[8];
  uint16_T u16Ncomp_PrcoRisk_y[8];
} u16Ncomp_PrcoRisk_Tab;

typedef struct {
  uint16_T AC_u16Vspd_FAN_u1[7];
  int16_T AC_s16T_DeltaExtSat_HP[7];
  uint16_T AC_u16PWM_FAN_HP_y[49];
} AC_u16PWM_FAN_HP_Tab;

typedef struct {
  int16_T HP_s16Twat_HVCH_u1[5];
  uint16_T HP_u16Pump_HC_Twat_y[5];
} HP_u16Pump_HC_Twat_Tab;

typedef struct {
  int16_T s16Tamb_Common2_u1[10];
  int16_T s16Tasd_TotalDehum_u2[7];
  uint16_T u16Ncomp_HP_Est_y[70];
} u16Ncomp_HP_Est_Tab;

typedef struct {
  int16_T s16Tamb_HP_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  uint16_T u16Percent_EDCEst_HP_y[49];
} u16Percent_EDCEst_HP_Tab;

typedef struct {
  int16_T s16Tamb_HP_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  uint16_T u16Ki_EDC_HP_y[49];
} u16Ki_EDC_HP_Tab;

typedef struct {
  int16_T s16Tamb_HP_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  uint16_T u16Kp_EDC_HP_y[49];
} u16Kp_EDC_HP_Tab;

typedef struct {
  int16_T s16Tamb_TotalDehum_u1[10];
  uint16_T u16_QBlower_HVAC_u2[7];
  uint16_T u16Ki_EDC_TotalDehum_y[70];
} u16Ki_EDC_TotalDehum_Tab;

typedef struct {
  int16_T s16Tamb_Common2_u1[10];
  uint16_T u16PRCI_Ncomp_Rampup_Ctrl_u2[9];
  uint16_T u16Ncomp_HP_RampSpd_y[90];
} u16Ncomp_HP_RampSpd_Tab;

typedef struct {
  uint16_T u16Prci_risk_HP_u1[8];
  uint16_T u16Ncomp_PrciRisk_HP_y[8];
} u16Ncomp_PrciRisk_HP_Tab;

typedef struct {
  uint16_T AC_u16Prco_risk_ValeoEDC_u1[8];
  uint16_T AC_u16Ncomp_PrcoRisk_ValeoEDC_y[8];
} AC_u16Ncomp_PrcoRisk_ValeoEDC_Tab;

typedef struct {
  uint16_T u16PresRatio_Risk[8];
  uint16_T u16Ncomp_PresRatio_Risk_y[8];
} u16Ncomp_PresRatio_Risk_Tab;

typedef struct {
  int16_T s16Teva_risk_u1[8];
  uint16_T u16Ncomp_EvaRisk_TotalDehum_y[8];
} u16Ncomp_EvaRisk_TotalDehum_Tab;

typedef struct {
  int16_T HP_s16SH_delta_u1[8];
  int16_T HP_s16TWater_Chil_u2[9];
  int16_T HP_s16Ki_EXV_Chil_HPChil_y[72];
} HP_s16Ki_EXV_Chil_HPChil_Tab;

typedef struct {
  int16_T HP_s16SH_delta_u1[8];
  int16_T HP_s16TWater_Chil_u2[9];
  int16_T HP_s16Kp_EXV_Chil_HPChil_y[72];
} HP_s16Kp_EXV_Chil_HPChil_Tab;

typedef struct {
  int16_T HP_s16TWater_HPChil_u1[7];
  uint16_T HP_u16_QBlower_HVAC_u2[7];
  uint16_T HP_u16SH_Set_HPCHIL_y[49];
} HP_u16SH_Set_HPCHIL_Tab;

typedef struct {
  uint16_T HP_u16EXV_EvaCDS_Est_u1[10];
  uint16_T HP_u16_EXV_EvaCDS_HP_Max_y[10];
} HP_u16_EXV_EvaCDS_HP_Max_Tab;

typedef struct {
  uint16_T HP_u16EXV_EvaCDS_Est_u1[10];
  uint16_T HP_u16_EXV_EvaCDS_HP_Min_y[10];
} HP_u16_EXV_EvaCDS_HP_Min_Tab;

typedef struct {
  int16_T s16Tamb_Common2_u1[10];
  uint16_T u16Ncomp_RPM_u2[10];
  uint16_T u16EXV_EvaCDS_Pos_HP_Est_y[100];
} u16EXV_EvaCDS_Min_2D_Tab;

typedef struct {
  int16_T s16Tamb_Common2_u1[10];
  uint16_T u16Ncomp_RPM_u2[7];
  uint16_T u16EXV_EvaCDS_Pos_HP_Est_y[70];
} u16EXV_EvaCDS_Pos_HP_Est_Tab;

typedef struct {
  int16_T s16SH_delta_u1[8];
  int16_T HP_s16Tamb_u2[9];
  int16_T s16Ki_EXV_EvaCDS_HP_y[72];
} s16Ki_EXV_EvaCDS_HP_Tab;

typedef struct {
  int16_T HP_s16SH_delta_u1[8];
  int16_T HP_s16Tamb_u2[9];
  int16_T HP_s16Kp_EXV_EvaCDS_HP_y[72];
} HP_s16Kp_EXV_EvaCDS_HP_Tab;

typedef struct {
  int16_T s16Tamb_HP_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  uint16_T u16SH_Target_HP_y[49];
} u16SH_Target_HP_Tab;

typedef struct {
  int16_T ACPre_s16TSet_Cmf_u1[10];
  int16_T ACPre_s16Tamb_U2[11];
  int16_T ACPre_s16LVL_HeatCool_y[110];
} ACPre_s16LVL_HeatCool_Tab;

typedef struct {
  int16_T Flap_s16TCtrlDelta_Coolant_u1[8];
  uint16_T Flap_u16_Qblower_HVCHCtrl_u2[7];
  uint16_T Flap_u16Ki_HVCH_A10000_y[56];
} Flap_u16Ki_HVCH_A10000_Tab;

typedef struct {
  int16_T Flap_s16TCtrlDelta_Coolant_u1[8];
  uint16_T Flap_u16_Qblower_HVCHCtrl_u2[7];
  uint16_T Flap_u16Kp_HVCH_A10000_y[56];
} Flap_u16Kp_HVCH_A10000_Tab;

typedef struct {
  uint16_T AC_u16Vspd_FAN_u1[7];
  int16_T AC_s16T_DeltaExtWater_u2[8];
  uint16_T AC_u16PWM_FAN_StopMode_y[56];
} AC_u16PWM_FAN_StopMode_Tab;

typedef struct {
  int16_T s16Tamb_TotalDehum_u1[10];
  int16_T s16Tasd_TotalDehum_u2[7];
  uint16_T u16Ncomp_TotalDehum_Est_y[70];
} u16Ncomp_TotalDehum_Est_Tab;

typedef struct {
  int16_T s16Tamb_TotalDehum_u1[10];
  uint16_T u16_QBlower_HVAC_u2[7];
  uint16_T u16Kp_EDC_TotalDehum_y[70];
} u16Kp_EDC_TotalDehum_Tab;

typedef struct {
  uint16_T u16Prci_risk_TotalDehum_u1[8];
  uint16_T u16Ncomp_PrciRisk_TotalDehum_y[8];
} u16Ncomp_PrciRisk_TotalDehum_Tab;

typedef struct {
  int16_T AC_s16TBatIn_Delta_Lv3_u1[10];
  int16_T AC_s16TBatIn_Delta_Lv3_u1_y[10];
} AC_s16TBatIn_Delta_Lv3_u1_Tab;

typedef struct {
  int16_T s16Tamb_TotalDehum_u1[10];
  uint16_T u16Ncomp_RPM_EXV[11];
  uint16_T u16EXV_EvaCDS_Est_TDEDC_y[110];
} u16EXV_EvaCDS_Est_TDEDC_Tab;

typedef struct {
  int16_T s16Tamb_TotalDehum_u1[10];
  uint16_T u16Ncomp_RPM_EXV[11];
  uint16_T u16EXV_EvaCDS_Min_TotalDehum_y[110];
} u16EXV_EvaCDS_Min_TotalDehum_Tab;

typedef struct {
  int16_T s16Tamb_TotalDehum_u1[10];
  uint16_T u16Ncomp_RPM_EXV[11];
  uint16_T u16EXV_EvaCDS_Max_TotalDehum_y[110];
} u16EXV_EvaCDS_Max_TotalDehum_Tab;

typedef struct {
  int16_T s16Tamb_TotalDehum_u1[10];
  uint16_T u16_QBlower_HVAC_u2[7];
  uint16_T u16SH_Target_TotalDehum_y[70];
} u16SH_Target_TotalDehum_Tab;

typedef struct {
  int16_T ACPre_s16Teva_u1[9];
  int16_T ACPre_s16_Tasd_Max_u2[12];
  int16_T ACPre_s16TWat_CmfReq_y[108];
} ACPre_s16TWat_CmfReq_Tab;

typedef struct {
  uint8_T u8Mode_HVAC_u1[7];
  uint8_T u8HVAC_BlwVol_HVPTC_u2[7];
  uint16_T u16QAir_Estimation_HVPTC_FullHot_y[49];
} u16QAir_Estimation_HVPTC_FullHot_Tab;

typedef struct {
  uint16_T AC_u16PWM_FrontFAN_u1[7];
  uint16_T AC_u16Vspd_u2[7];
  uint16_T AC_u16Vair_Front_y[49];
} AC_u16Vair_Front_Tab;

typedef struct {
  uint8_T ACPre_u8AGS_Position_u1[5];
  uint16_T AC_u16Vspd_u2[7];
  uint8_T ACPre_u8AGSFactor_y[35];
} ACPre_u8AGSFactor_Tab;

typedef struct {
  int16_T s16Tamb_ACDehum_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  int16_T s16Twater_Max_ACDehum_y[49];
} s16Twater_Max_ACDehum_Tab;

typedef struct {
  int16_T s16Tamb_ACDehum_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  int16_T s16Twater_Min_TotalDehum_y[49];
} s16Twater_Min_TotalDehum_Tab;

typedef struct {
  int16_T s16Tamb_HP_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  int16_T s16Twater_Max_HP_y[49];
} s16Twater_Max_HP_Tab;

typedef struct {
  int16_T s16Tamb_ACDehum_u1[7];
  uint16_T u16_QBlower_HVAC_u2[7];
  int16_T s16Twater_Max_TotalDehum_y[49];
} s16Twater_Max_TotalDehum_Tab;

typedef struct {
  int16_T s16Tamb_Common2_u1[10];
  uint16_T u16_QBlower_HVAC_u2[7];
  int16_T s16Twater_Min_HP_y[70];
} s16Twater_Min_HP_Tab;

#endif                                 /* RTW_HEADER_Chery_E03_Hp_Parameter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

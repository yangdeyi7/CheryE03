/*
 * File: Sokon_X01_Cmf_Parameter.h
 *
 * Code generated for Simulink model 'Sokon_X01_Thm'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:36 2022
 */

#ifndef RTW_HEADER_Sokon_X01_Cmf_Parameter_h_
#define RTW_HEADER_Sokon_X01_Cmf_Parameter_h_
#include "rtwtypes.h"

typedef struct {
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Tasd_Def_Cmp_y[11];
} Thm_s16Tasd_Def_Cmp_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Mode_Auto_y[110];
} Thm_s16Mode_Auto_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Tsys_y[110];
} Thm_s16Tsys_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[13];
  int16_T Thm_s16Tast_y[130];
} Thm_s16Tast_Tab;

typedef struct {
  int8_T Thm_s8LVL_CabHeat_X[8];
  int16_T Thm_s16Tasd_Eco_Offset_y[8];
} Thm_s16Tasd_Eco_Offset_Tab;

typedef struct {
  uint16_T Thm_u16Solar[10];
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Tasd_Solar_Cmp_Coefficient_y[110];
} Thm_s16Tasd_Solar_Cmp_Coefficient_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Tasd_SolarCmp_y[110];
} Thm_s16Tasd_SolarCmp_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Tast_TsetDown_Cmp_y[110];
} Thm_s16Tast_TsetDown_Cmp_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Tast_TsetFilFactor_Inc_Cmp_y[110];
} Thm_s16Tast_TsetFilFactor_Inc_Cmp_Tab;

typedef struct {
  int16_T Thm_s16TDiff_SysINCar[11];
  int16_T Thm_s16Tamb[11];
  int16_T Thm_s16Tasd_Dyn_y[121];
} Thm_s16Tasd_Dyn_Tab;

typedef struct {
  uint16_T Thm_u16Solar[10];
  int16_T Thm_s16Tuct_A10[11];
  int8_T Thm_s16Blower_SolarCmp_y[110];
} Thm_s16Blower_SolarCmp_Tab;

typedef struct {
  int16_T CMF_s16T_WAT_ICDS_U1[10];
  int16_T CMF_s16Tasd_U2[11];
  uint8_T CMF_u8Blw_LImitation_y[110];
} CMF_u8Blw_LImitation_Tab;

typedef struct {
  int16_T CMF_s16Tamb_u1[10];
  int16_T CMF_s16TDiff_SysINCar_u2[11];
  int8_T CMF_s8Blw_Dyn_y[110];
} CMF_s8Blw_Dyn_Tab;

typedef struct {
  uint8_T CMF_u8VSPD_U1[10];
  uint8_T CMF_u8INTAK_PERCENT_U2[6];
  int8_T CMF_s8Blw_VSP_Comp_y[60];
} CMF_s8Blw_VSP_Comp_Tab;

typedef struct {
  int8_T CMF_s8Mode_NumForCalc[4];
  uint8_T CMF_u8ModeReqFromModeCalc_y[4];
} CMF_u8ModeReqFromModeCalc_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[11];
  uint8_T Thm_u8VBLW_Static_y[110];
} Thm_u8VBLW_Static_Tab;

typedef struct {
  uint16_T Thm_u16Tset[10];
  int16_T Thm_s16Tamb[11];
  int8_T Thm_s8LVL_CabHeat_y[110];
} Thm_s8LVL_CabHeat_Tab;

typedef struct {
  int16_T Thm_s16TWAT_ICDS_X[8];
  int16_T Thm_s16Toffset_EVA_SET_y[8];
} Thm_s16Toffset_EVA_SET_Tab;

typedef struct {
  int16_T Thm_s16Tamb_A10[11];
  int16_T Thm_s16HVCH_OutTw_Cmp_A10[11];
} Thm_s16HVCH_OutTw_Cmp_Tab;

#endif                                 /* RTW_HEADER_Sokon_X01_Cmf_Parameter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

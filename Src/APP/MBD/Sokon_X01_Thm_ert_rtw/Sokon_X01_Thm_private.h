/*
 * File: Sokon_X01_Thm_private.h
 *
 * Code generated for Simulink model 'Sokon_X01_Thm'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Sokon_X01_Thm_private_h_
#define RTW_HEADER_Sokon_X01_Thm_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Sokon_X01_Thm.h"

extern boolean_T Sokon_X01_Thm_DataTypeConv_b_(boolean_T rtu_In1);
extern int16_T Sokon_X01_Thm_DataTypeConv_s16_(uint16_T rtu_In1);
extern int16_T Sokon_X01_Thm_DataTypeConv_s16__f(uint8_T rtu_In1);
extern int16_T Sokon_X01_Thm_DataTypeConv_s16__h(int16_T rtu_In1);
extern void Sokon_X01_Thm_IfThenElse(boolean_T rtu_bIf, int64m_T rtu_Then,
  int64m_T rtu_Else, int64m_T *rty_Out);
extern void Sokon_X01_Thm_Divide_Safe(int64m_T rtu_x, int64m_T rtu_y, int64m_T
  *rty_out, const ConstB_Divide_Safe_Sokon_X01_Thm_T *localC);
extern uint16_T Sokon_X01_Thm_IfThenElse_j(boolean_T rtu_bIf, uint16_T rtu_Then,
  uint16_T rtu_Else);
extern void Sokon_X01_Thm_Divide_Safe1(int64m_T rtu_x, uint16_T rtu_y, int64m_T *
  rty_out, const ConstB_Divide_Safe_Sokon_X01_Thm_j_T *localC);
extern int16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp(int16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, uint8_T rtu_FilterFactor_INC, uint8_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_T *localDW);
extern int16_T Sokon_X01_Thm_FirOrderLinear_Filter(int16_T rtu_DataIn, boolean_T
  rtu_bFlagInit, uint8_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Thm_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Thm_T *localDW, uint16_T rtp_AmpNumVal);
extern uint16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp_i(uint16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, uint8_T rtu_FilterFactor_INC, uint8_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_l_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_l_T *localDW);
extern uint16_T Sokon_X01_Thm_FirOrderLinear_Filter2(uint16_T rtu_DataIn,
  boolean_T rtu_bFlagInit, uint8_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Thm_n_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Thm_o_T *localDW, uint16_T rtp_AmpNumVal);
extern uint16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp_c(uint16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, uint16_T rtu_FilterFactor_INC, uint16_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_h_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_e_T *localDW);
extern uint16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor(uint16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, uint16_T rtu_FilterFactor_INC, uint16_T
  rtu_FilterFactor_DEC, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Sokon_X01_Thm_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Sokon_X01_Thm_T *localDW, uint16_T
  rtp_AmpNumVal);

#endif                                 /* RTW_HEADER_Sokon_X01_Thm_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

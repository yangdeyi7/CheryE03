/*
 * File: Sokon_X01_Cmf_private.h
 *
 * Code generated for Simulink model 'Sokon_X01_Cmf'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:07 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Sokon_X01_Cmf_private_h_
#define RTW_HEADER_Sokon_X01_Cmf_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S94>/Hyster_Judge'
   *   '<S94>/Hyster_Judge1'
   *   '<S95>/Hyster_Judge1'
   *   '<S95>/Hyster_Judge2'
   *   '<S95>/Hyster_Judge4'
   *   '<S164>/Hyster_Judge1'
   *   '<S126>/Hyster_Judge'
   */
  boolean_T pooled3;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S94>/Hyster_Judge'
   *   '<S94>/Hyster_Judge1'
   *   '<S95>/Hyster_Judge1'
   *   '<S95>/Hyster_Judge2'
   *   '<S95>/Hyster_Judge4'
   *   '<S164>/Hyster_Judge1'
   *   '<S126>/CntModule_Cfg'
   *   '<S126>/FlagHoldModule'
   *   '<S126>/Hyster_Judge'
   *   '<S167>/Hyster'
   *   '<S167>/Hyster1'
   *   '<S167>/Hyster2'
   */
  boolean_T pooled4;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S76>/UnitDelay1'
   *   '<S80>/Constant'
   *   '<S265>/UnitDelay1'
   *   '<S269>/Constant'
   */
  int64m_T pooled9;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S21>/CMF_u8Blw_LImitation_Table'
   *   '<S22>/Blower_SolarCmp'
   *   '<S22>/CMF_s8Blw_Dyn_Y_Table'
   *   '<S163>/Thm_s16Mode'
   *   '<S215>/Thm_s16TSYS_Table'
   *   '<S215>/Thm_u8VBLW_STATIC_Table'
   *   '<S226>/Cmf_s8LVL_CabHeatCoolingTab'
   *   '<S237>/TasdL_SolarCmp_Coefficient'
   *   '<S237>/Tasd_SolarCmp'
   *   '<S237>/Tasd_SolarCmp1'
   *   '<S237>/Tasd_SolarCmp_Coefficient1'
   *   '<S238>/Thm_s16Tast_TsetDown_Cmp'
   *   '<S238>/Thm_s16Tast_TsetFilFactor_Inc_Cmp'
   */
  uint32_T pooled10[2];

  /* Computed Parameter: CMF_s8Blw_VSP_Comp_Table_maxIndex
   * Referenced by: '<S22>/CMF_s8Blw_VSP_Comp_Table'
   */
  uint32_T CMF_s8Blw_VSP_Comp_Table_maxIndex[2];

  /* Computed Parameter: CMF_s16Tasd_Solar_CMP_Table_maxIndex
   * Referenced by: '<S231>/CMF_s16Tasd_Solar_CMP_Table'
   */
  uint32_T CMF_s16Tasd_Solar_CMP_Table_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S215>/Thm_s16Tast_L_Table'
   *   '<S215>/Thm_s16Tast_R_Table'
   */
  uint32_T pooled14[2];

  /* Computed Parameter: R134A_P_a100_T_a10_Table_tableData
   * Referenced by: '<S214>/R134A_P_a100_T_a10_Table'
   */
  int16_T R134A_P_a100_T_a10_Table_tableData[29];

  /* Computed Parameter: TevaSetCompensationByTamb_tableData
   * Referenced by: '<S19>/TevaSetCompensationByTamb'
   */
  int16_T TevaSetCompensationByTamb_tableData[4];

  /* Computed Parameter: TevaSetCompensationByTamb_bp01Data
   * Referenced by: '<S19>/TevaSetCompensationByTamb'
   */
  int16_T TevaSetCompensationByTamb_bp01Data[4];

  /* Computed Parameter: R134A_P_a100_T_a10_Table_bp01Data
   * Referenced by: '<S214>/R134A_P_a100_T_a10_Table'
   */
  uint16_T R134A_P_a100_T_a10_Table_bp01Data[29];
} ConstP_Sokon_X01_Cmf_T;

/* Constant parameters (default storage) */
extern const ConstP_Sokon_X01_Cmf_T Sokon_X01_Cmf_ConstP;
extern const ConstB_Sokon_X01_Cmf_h_T Sokon_X01_Cmf_ConstB;

#endif                                 /* RTW_HEADER_Sokon_X01_Cmf_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

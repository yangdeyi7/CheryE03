/*
 * File: Chery_E03_Hp_private.h
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Chery_E03_Hp_private_h_
#define RTW_HEADER_Chery_E03_Hp_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S243>/Hyster_Judge'
   *   '<S1254>/Hyster_Judge1'
   *   '<S1259>/Hyster_Judge'
   *   '<S1259>/Hyster_Judge1'
   *   '<S1259>/Hyster_Judge2'
   *   '<S1259>/Hyster_Judge3'
   *   '<S1259>/Hyster_Judge4'
   *   '<S1259>/Hyster_Judge5'
   *   '<S1259>/Hyster_Judge6'
   *   '<S1259>/Hyster_Judge7'
   *   '<S1261>/Hyster_Judge'
   *   '<S89>/Hyster_And_Delay_Judge'
   *   '<S1224>/Hyster_Judge'
   *   '<S1225>/Hyster_Judge'
   *   '<S1226>/Hyster_Judge'
   *   '<S1227>/Hyster_Judge'
   *   '<S1228>/Hyster_Judge'
   *   '<S1229>/Hyster_Judge'
   *   '<S1264>/Hyster_Judge'
   *   '<S1265>/Hyster_Judge1'
   *   '<S1289>/Hyster_Judge'
   *   '<S1289>/Hyster_Judge1'
   *   '<S1289>/Hyster_Judge2'
   *   '<S1291>/Hyster_Judge'
   *   '<S1291>/Hyster_Judge1'
   *   '<S1292>/Hyster_Judge'
   *   '<S1337>/Hyster_Judge'
   *   '<S1337>/Hyster_Judge1'
   *   '<S1337>/Hyster_Judge2'
   *   '<S1339>/Hyster_Judge'
   *   '<S1339>/Hyster_Judge1'
   *   '<S1340>/Hyster_Judge'
   *   '<S1384>/Hyster_Judge'
   *   '<S1384>/Hyster_Judge1'
   *   '<S1385>/Hyster_Judge'
   *   '<S1423>/Hyster_Judge'
   *   '<S1423>/Hyster_Judge1'
   *   '<S1423>/Hyster_Judge2'
   *   '<S1424>/Hyster_Judge'
   *   '<S1425>/Hyster_Judge1'
   *   '<S1425>/Hyster_Judge2'
   *   '<S1426>/Hyster_Judge'
   *   '<S654>/Hyster'
   *   '<S654>/Hyster1'
   *   '<S654>/Hyster_Judge1'
   *   '<S655>/Hyster_Judge'
   *   '<S817>/Hyster_Judge'
   *   '<S1018>/Hyster_And_Delay_Judge'
   *   '<S1019>/Hyster_And_Delay_Judge'
   */
  boolean_T pooled3;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S243>/Hyster_Judge'
   *   '<S1254>/Hyster_Judge1'
   *   '<S1259>/Hyster_Judge'
   *   '<S1259>/Hyster_Judge1'
   *   '<S1259>/Hyster_Judge2'
   *   '<S1259>/Hyster_Judge3'
   *   '<S1259>/Hyster_Judge4'
   *   '<S1259>/Hyster_Judge5'
   *   '<S1259>/Hyster_Judge6'
   *   '<S1259>/Hyster_Judge7'
   *   '<S1261>/Hyster_Judge'
   *   '<S89>/Hyster_And_Delay_Judge'
   *   '<S1224>/Hyster_Judge'
   *   '<S1225>/Hyster_Judge'
   *   '<S1226>/Hyster_Judge'
   *   '<S1227>/Hyster_Judge'
   *   '<S1228>/Hyster_Judge'
   *   '<S1229>/Hyster_Judge'
   *   '<S1264>/Hyster_Judge'
   *   '<S1265>/Hyster_Judge1'
   *   '<S1289>/Hyster_Judge'
   *   '<S1289>/Hyster_Judge1'
   *   '<S1289>/Hyster_Judge2'
   *   '<S1291>/Hyster_Judge'
   *   '<S1291>/Hyster_Judge1'
   *   '<S1292>/Hyster_Judge'
   *   '<S1337>/Hyster_Judge'
   *   '<S1337>/Hyster_Judge1'
   *   '<S1337>/Hyster_Judge2'
   *   '<S1339>/Hyster_Judge'
   *   '<S1339>/Hyster_Judge1'
   *   '<S1340>/Hyster_Judge'
   *   '<S1384>/Hyster_Judge'
   *   '<S1384>/Hyster_Judge1'
   *   '<S1385>/Hyster_Judge'
   *   '<S1423>/Hyster_Judge'
   *   '<S1423>/Hyster_Judge1'
   *   '<S1423>/Hyster_Judge2'
   *   '<S1424>/Hyster_Judge'
   *   '<S1425>/Hyster_Judge1'
   *   '<S1425>/Hyster_Judge2'
   *   '<S1426>/Hyster_Judge'
   *   '<S655>/Hyster_Judge'
   *   '<S817>/Hyster_Judge'
   *   '<S1018>/Hyster_And_Delay_Judge'
   *   '<S1019>/Hyster_And_Delay_Judge'
   */
  boolean_T pooled4;

  /* Pooled Parameter (Expression: 0)
   * Referenced by:
   *   '<S709>/Unit Delay'
   *   '<S721>/Unit Delay'
   */
  int64m_T pooled7;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1192>/UnitDelay1'
   *   '<S1196>/Constant'
   */
  int64m_T pooled8;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S1046>/Twater_Max_ACDehum_Y'
   *   '<S1046>/Twater_Min_TotalDehum_Y'
   *   '<S1046>/s16Twater_Max_HP'
   *   '<S1046>/s16Twater_Max_TotalDehum'
   *   '<S347>/FAN_PWM_Calculatoin_AC'
   *   '<S447>/FAN_PWM_Calculatoin_AC'
   *   '<S503>/FAN_PWM_Calculatoin_HPMode'
   *   '<S906>/FAN_PWM_Calculatoin_HPMode'
   *   '<S1163>/Air_Flow_Rate_Estimation_Fullhot'
   *   '<S1168>/2-D Lookup Table'
   *   '<S633>/SH_Target_Setting'
   *   '<S648>/SH_Target_Setting_HP'
   *   '<S378>/Ncomp_AC_Est'
   *   '<S382>/Kp_EDC_Calculation'
   *   '<S575>/Ratio_AirFlowRate'
   *   '<S578>/Ki_EDC_Calculation'
   *   '<S578>/Kp_EDC_Calculation'
   *   '<S942>/Ratio_AirFlowRate'
   */
  uint32_T pooled15[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S372>/2-D Lookup Table'
   *   '<S474>/2-D Lookup Table'
   */
  uint32_T pooled16[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S1046>/s16Twater_Min_HP'
   *   '<S441>/EXV_Eva_Estimation'
   *   '<S647>/EXV_Eva_Estimation'
   *   '<S1010>/EXV_Eva_max3'
   *   '<S575>/Ncomp_TotalDehum_Est'
   *   '<S942>/Ncomp_TotalDehum_Est'
   *   '<S945>/Ki_EDC_Calculation1'
   *   '<S945>/Kp_EDC_Calculation'
   */
  uint32_T pooled17[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S343>/HVCH_3Way_Valve'
   *   '<S443>/HVCH_3Way_Valve'
   *   '<S842>/HVCH_3Way_Valve'
   */
  uint32_T pooled18[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S343>/Pump_HVCH_Req'
   *   '<S443>/Pump_HVCH_Req'
   *   '<S838>/Pump_HVCH_Req'
   */
  uint32_T pooled19[2];

  /* Computed Parameter: EDC_Ramp_Up_Speed_maxIndex
   * Referenced by: '<S569>/EDC_Ramp_Up_Speed'
   */
  uint32_T EDC_Ramp_Up_Speed_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S633>/Ki_Calculation'
   *   '<S633>/Kp_Calculation'
   *   '<S648>/EXV_Ki'
   *   '<S648>/EXV_Kp'
   */
  uint32_T pooled20[2];

  /* Computed Parameter: EXV_EvaCDS_Min_2D_maxIndex
   * Referenced by: '<S647>/EXV_EvaCDS_Min_2D'
   */
  uint32_T EXV_EvaCDS_Min_2D_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S654>/2-D Lookup Table1'
   *   '<S1009>/EXV_Eva_Estimation'
   */
  uint32_T pooled23[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S818>/Kp_Table1'
   *   '<S818>/Kp_Table_A10000'
   *   '<S697>/Ki_Table_A10000'
   *   '<S697>/Kp_Table_A10000'
   */
  uint32_T pooled24[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S773>/FAN_PWM_Calculatoin_AC'
   *   '<S835>/FAN_PWM_Calculatoin_AC'
   */
  uint32_T pooled25[2];

  /* Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S1168>/2-D Lookup Table1'
   */
  uint32_T uDLookupTable1_maxIndex[2];

  /* Computed Parameter: Twat_Cmf_Req_Calculation_maxIndex
   * Referenced by: '<S1162>/Twat_Cmf_Req_Calculation'
   */
  uint32_T Twat_Cmf_Req_Calculation_maxIndex[2];

  /* Pooled Parameter (Expression: [-100,-10,0,10,20,50,100,150,200])
   * Referenced by:
   *   '<S476>/chil_Ki'
   *   '<S866>/chil_Ki'
   */
  int16_T pooled36[9];

  /* Pooled Parameter (Expression: [-100,-50,-10,0,10,25,50,100,150,200])
   * Referenced by:
   *   '<S476>/chillercomp_kp'
   *   '<S866>/chillercomp_kp'
   */
  int16_T pooled37[10];

  /* Computed Parameter: EXV_Min_According_EDC_bp01Data
   * Referenced by: '<S501>/EXV_Min_According_EDC'
   */
  int16_T EXV_Min_According_EDC_bp01Data[11];

  /* Pooled Parameter (Expression: [-312,-264,-205,-156,-101,-65,-3,33,82,118,157,199,237,277,318,360,402,441,480,520,563,602,640,679,721,760,801,841,881])
   * Referenced by:
   *   '<S1212>/R134A_P_a10_T_a10_Table'
   *   '<S1213>/R134A_P_a10_T_a10_Table'
   *   '<S1214>/R134A_P_a10_T_a10_Table'
   *   '<S1216>/R134A_P_a10_T_a10_Table'
   *   '<S1218>/R134A_P_a10_T_a10_Table'
   */
  int16_T pooled49[29];

  /* Pooled Parameter (Expression: [6,2,1,1,1,2,3,4,5])
   * Referenced by:
   *   '<S476>/chil_Ki'
   *   '<S866>/chil_Ki'
   */
  uint16_T pooled71[9];

  /* Pooled Parameter (Expression: [150,100,30,10,20,60,100,120,180,200])
   * Referenced by:
   *   '<S476>/chillercomp_kp'
   *   '<S866>/chillercomp_kp'
   */
  uint16_T pooled72[10];

  /* Pooled Parameter (Expression: [50,80,100,120,140,160,170,180,190])
   * Referenced by:
   *   '<S499>/1-D Lookup Table'
   *   '<S634>/1-D Lookup Table'
   */
  uint16_T pooled73[9];

  /* Pooled Parameter (Expression: [0,960,1500,2000,3000,4000,5000,6000,7000])
   * Referenced by:
   *   '<S499>/1-D Lookup Table'
   *   '<S634>/1-D Lookup Table'
   */
  uint16_T pooled74[9];

  /* Computed Parameter: EXV_Min_According_EDC_tableData
   * Referenced by: '<S501>/EXV_Min_According_EDC'
   */
  uint16_T EXV_Min_According_EDC_tableData[11];

  /* Pooled Parameter (Expression: [8,10,13,16,20,23,29,33,39,44,50,57,64,72,81,91,102,113,125,138,153,168,183,200,219,238,259,281,304])
   * Referenced by:
   *   '<S1212>/R134A_P_a10_T_a10_Table'
   *   '<S1213>/R134A_P_a10_T_a10_Table'
   *   '<S1214>/R134A_P_a10_T_a10_Table'
   *   '<S1216>/R134A_P_a10_T_a10_Table'
   *   '<S1218>/R134A_P_a10_T_a10_Table'
   */
  uint16_T pooled80[29];
} ConstP_Chery_E03_Hp_T;

/* Constant parameters (default storage) */
extern const ConstP_Chery_E03_Hp_T Chery_E03_Hp_ConstP;
extern const ConstB_Chery_E03_Hp_h_T Chery_E03_Hp_ConstB;

#endif                                 /* RTW_HEADER_Chery_E03_Hp_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

/*
 * File: Chery_E03_Hp_data.c
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

#include "Chery_E03_Hp.h"
#include "Chery_E03_Hp_private.h"

/* Constant parameters (default storage) */
const ConstP_Chery_E03_Hp_T Chery_E03_Hp_ConstP = {
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
  0,

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
  1,

  /* Pooled Parameter (Expression: 0)
   * Referenced by:
   *   '<S709>/Unit Delay'
   *   '<S721>/Unit Delay'
   */
  { { 0UL, 0UL } },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1192>/UnitDelay1'
   *   '<S1196>/Constant'
   */
  { { 0UL, 0UL } },

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
  { 6U, 6U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S372>/2-D Lookup Table'
   *   '<S474>/2-D Lookup Table'
   */
  { 5U, 5U },

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
  { 9U, 6U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S343>/HVCH_3Way_Valve'
   *   '<S443>/HVCH_3Way_Valve'
   *   '<S842>/HVCH_3Way_Valve'
   */
  { 7U, 9U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S343>/Pump_HVCH_Req'
   *   '<S443>/Pump_HVCH_Req'
   *   '<S838>/Pump_HVCH_Req'
   */
  { 7U, 5U },

  /* Computed Parameter: EDC_Ramp_Up_Speed_maxIndex
   * Referenced by: '<S569>/EDC_Ramp_Up_Speed'
   */
  { 9U, 8U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S633>/Ki_Calculation'
   *   '<S633>/Kp_Calculation'
   *   '<S648>/EXV_Ki'
   *   '<S648>/EXV_Kp'
   */
  { 7U, 8U },

  /* Computed Parameter: EXV_EvaCDS_Min_2D_maxIndex
   * Referenced by: '<S647>/EXV_EvaCDS_Min_2D'
   */
  { 9U, 9U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S654>/2-D Lookup Table1'
   *   '<S1009>/EXV_Eva_Estimation'
   */
  { 9U, 10U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S818>/Kp_Table1'
   *   '<S818>/Kp_Table_A10000'
   *   '<S697>/Ki_Table_A10000'
   *   '<S697>/Kp_Table_A10000'
   */
  { 7U, 6U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S773>/FAN_PWM_Calculatoin_AC'
   *   '<S835>/FAN_PWM_Calculatoin_AC'
   */
  { 6U, 7U },

  /* Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S1168>/2-D Lookup Table1'
   */
  { 4U, 6U },

  /* Computed Parameter: Twat_Cmf_Req_Calculation_maxIndex
   * Referenced by: '<S1162>/Twat_Cmf_Req_Calculation'
   */
  { 8U, 11U },

  /* Pooled Parameter (Expression: [-100,-10,0,10,20,50,100,150,200])
   * Referenced by:
   *   '<S476>/chil_Ki'
   *   '<S866>/chil_Ki'
   */
  { -100, -10, 0, 10, 20, 50, 100, 150, 200 },

  /* Pooled Parameter (Expression: [-100,-50,-10,0,10,25,50,100,150,200])
   * Referenced by:
   *   '<S476>/chillercomp_kp'
   *   '<S866>/chillercomp_kp'
   */
  { -100, -50, -10, 0, 10, 25, 50, 100, 150, 200 },

  /* Computed Parameter: EXV_Min_According_EDC_bp01Data
   * Referenced by: '<S501>/EXV_Min_According_EDC'
   */
  { 0, 700, 960, 1500, 2000, 2500, 3500, 4500, 5500, 6500, 7000 },

  /* Pooled Parameter (Expression: [-312,-264,-205,-156,-101,-65,-3,33,82,118,157,199,237,277,318,360,402,441,480,520,563,602,640,679,721,760,801,841,881])
   * Referenced by:
   *   '<S1212>/R134A_P_a10_T_a10_Table'
   *   '<S1213>/R134A_P_a10_T_a10_Table'
   *   '<S1214>/R134A_P_a10_T_a10_Table'
   *   '<S1216>/R134A_P_a10_T_a10_Table'
   *   '<S1218>/R134A_P_a10_T_a10_Table'
   */
  { -312, -264, -205, -156, -101, -65, -3, 33, 82, 118, 157, 199, 237, 277, 318,
    360, 402, 441, 480, 520, 563, 602, 640, 679, 721, 760, 801, 841, 881 },

  /* Pooled Parameter (Expression: [6,2,1,1,1,2,3,4,5])
   * Referenced by:
   *   '<S476>/chil_Ki'
   *   '<S866>/chil_Ki'
   */
  { 6U, 2U, 1U, 1U, 1U, 2U, 3U, 4U, 5U },

  /* Pooled Parameter (Expression: [150,100,30,10,20,60,100,120,180,200])
   * Referenced by:
   *   '<S476>/chillercomp_kp'
   *   '<S866>/chillercomp_kp'
   */
  { 150U, 100U, 30U, 10U, 20U, 60U, 100U, 120U, 180U, 200U },

  /* Pooled Parameter (Expression: [50,80,100,120,140,160,170,180,190])
   * Referenced by:
   *   '<S499>/1-D Lookup Table'
   *   '<S634>/1-D Lookup Table'
   */
  { 50U, 80U, 100U, 120U, 140U, 160U, 170U, 180U, 190U },

  /* Pooled Parameter (Expression: [0,960,1500,2000,3000,4000,5000,6000,7000])
   * Referenced by:
   *   '<S499>/1-D Lookup Table'
   *   '<S634>/1-D Lookup Table'
   */
  { 0U, 960U, 1500U, 2000U, 3000U, 4000U, 5000U, 6000U, 7000U },

  /* Computed Parameter: EXV_Min_According_EDC_tableData
   * Referenced by: '<S501>/EXV_Min_According_EDC'
   */
  { 50U, 60U, 65U, 70U, 75U, 80U, 85U, 90U, 95U, 100U, 105U },

  /* Pooled Parameter (Expression: [8,10,13,16,20,23,29,33,39,44,50,57,64,72,81,91,102,113,125,138,153,168,183,200,219,238,259,281,304])
   * Referenced by:
   *   '<S1212>/R134A_P_a10_T_a10_Table'
   *   '<S1213>/R134A_P_a10_T_a10_Table'
   *   '<S1214>/R134A_P_a10_T_a10_Table'
   *   '<S1216>/R134A_P_a10_T_a10_Table'
   *   '<S1218>/R134A_P_a10_T_a10_Table'
   */
  { 8U, 10U, 13U, 16U, 20U, 23U, 29U, 33U, 39U, 44U, 50U, 57U, 64U, 72U, 81U,
    91U, 102U, 113U, 125U, 138U, 153U, 168U, 183U, 200U, 219U, 238U, 259U, 281U,
    304U }
};

/* Invariant block signals (default storage) */
const ConstB_Chery_E03_Hp_h_T Chery_E03_Hp_ConstB = {
  0U,                                  /* '<S603>/Comp_Speed_Keep' */
  0U,                                  /* '<S597>/Constant1' */
  0U,                                  /* '<S574>/Constant1' */
  0U,                                  /* '<S961>/Constant1' */
  0U,                                  /* '<S941>/Constant1' */
  0U,                                  /* '<S394>/Constant1' */
  0U,                                  /* '<S379>/Constant1' */

  /* Start of '<S1162>/FirOrderLinear_Filter5' */
  {
    20U,                               /* synthesized block */

    /* Start of '<S1177>/FirOrderLinear_Filter_DoubleFactor_Amp' */
    {
      /* Start of '<S1192>/Divide_Safe1' */
      {
        1U,                            /* '<S1201>/Conversion' */
        1U                             /* '<S1195>/Divide1' */
      }
      ,

      /* End of '<S1192>/Divide_Safe1' */

      /* Start of '<S1192>/Divide_Safe' */
      {
        { { 0x1UL, 0UL } },            /* '<S1197>/Conversion' */
        1U                             /* '<S1194>/Divide1' */
      }
      /* End of '<S1192>/Divide_Safe' */
    }
    /* End of '<S1177>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  }
  ,

  /* End of '<S1162>/FirOrderLinear_Filter5' */

  /* Start of '<S1176>/DelayJudge2' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      3U                               /* '<S1189>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1176>/DelayJudge2' */

  /* Start of '<S1176>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      3U                               /* '<S1186>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1176>/DelayJudge1' */

  /* Start of '<S1145>/DelayJudge2' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      3U                               /* '<S1158>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1145>/DelayJudge2' */

  /* Start of '<S1145>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      3U                               /* '<S1155>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1145>/DelayJudge1' */

  /* Start of '<S1130>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S1140>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1130>/DelayJudge1' */

  /* Start of '<S1130>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      12U                              /* '<S1137>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1130>/DelayJudge' */

  /* Start of '<S1115>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S1125>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1115>/DelayJudge1' */

  /* Start of '<S1115>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      12U                              /* '<S1122>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1115>/DelayJudge' */

  /* Start of '<S1100>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S1110>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1100>/DelayJudge1' */

  /* Start of '<S1100>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      12U                              /* '<S1107>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1100>/DelayJudge' */

  /* Start of '<S1085>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S1095>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1085>/DelayJudge1' */

  /* Start of '<S1085>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      12U                              /* '<S1092>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1085>/DelayJudge' */

  /* Start of '<S1070>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S1080>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1070>/DelayJudge1' */

  /* Start of '<S1070>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      12U                              /* '<S1077>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1070>/DelayJudge' */

  /* Start of '<S1055>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S1065>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1055>/DelayJudge1' */

  /* Start of '<S1055>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      12U                              /* '<S1062>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S1055>/DelayJudge' */

  /* Start of '<S660>/Delay_Any' */
  {
    0,                                 /* '<S742>/Compare' */

    /* Start of '<S735>/DataTypeConv_u16_' */
    {
      2U                               /* '<S744>/Saturation' */
    }
    /* End of '<S735>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S660>/Delay_Any' */

  /* Start of '<S660>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      20U                              /* '<S739>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S660>/DelayJudge' */

  /* Start of '<S659>/Divide' */
  {
    1U,                                /* '<S730>/Conversion' */
    1U                                 /* '<S728>/Divide1' */
  }
  ,

  /* End of '<S659>/Divide' */

  /* Start of '<S658>/PIModule' */
  {
    0U,                                /* '<S721>/Divide3' */
    0                                  /* '<S721>/Divide4' */
  }
  ,

  /* End of '<S658>/PIModule' */

  /* Start of '<S657>/PIModule' */
  {
    0U,                                /* '<S709>/Divide3' */
    0                                  /* '<S709>/Divide4' */
  }
  ,

  /* End of '<S657>/PIModule' */

  /* Start of '<S656>/PIModule' */
  {
    0U,                                /* '<S700>/Divide3' */
    0                                  /* '<S700>/Divide4' */
  }
  ,

  /* End of '<S656>/PIModule' */

  /* Start of '<S654>/Hyster1' */
  {
    -1000,                             /* '<S683>/Conversion' */
    -500                               /* '<S684>/Conversion' */
  }
  ,

  /* End of '<S654>/Hyster1' */

  /* Start of '<S654>/Hyster' */
  {
    1500,                              /* '<S678>/Conversion' */
    500                                /* '<S679>/Conversion' */
  }
  ,

  /* End of '<S654>/Hyster' */

  /* Start of '<S654>/DelayJudge2' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      300U                             /* '<S674>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S654>/DelayJudge2' */

  /* Start of '<S654>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      100U                             /* '<S671>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S654>/DelayJudge1' */

  /* Start of '<S600>/Hyster1' */
  {
    190U,                              /* '<S618>/Conversion' */
    240U                               /* '<S619>/Conversion' */
  }
  ,

  /* End of '<S600>/Hyster1' */

  /* Start of '<S1019>/Hyster_And_Delay_Judge' */
  {
    /* Start of '<S1032>/DelayJudge1' */
    {
      /* Start of '<S97>/DataTypeConv_u16_' */
      {
        20U                            /* '<S1040>/Saturation' */
      }
      /* End of '<S97>/DataTypeConv_u16_' */
    }
    ,

    /* End of '<S1032>/DelayJudge1' */

    /* Start of '<S1032>/DelayJudge' */
    {
      /* Start of '<S97>/DataTypeConv_u16_' */
      {
        20U                            /* '<S1037>/Saturation' */
      }
      /* End of '<S97>/DataTypeConv_u16_' */
    }
    /* End of '<S1032>/DelayJudge' */
  }
  ,

  /* End of '<S1019>/Hyster_And_Delay_Judge' */

  /* Start of '<S1018>/Hyster_And_Delay_Judge' */
  {
    /* Start of '<S1021>/DelayJudge1' */
    {
      /* Start of '<S97>/DataTypeConv_u16_' */
      {
        30U                            /* '<S1029>/Saturation' */
      }
      /* End of '<S97>/DataTypeConv_u16_' */
    }
    ,

    /* End of '<S1021>/DelayJudge1' */

    /* Start of '<S1021>/DelayJudge' */
    {
      /* Start of '<S97>/DataTypeConv_u16_' */
      {
        30U                            /* '<S1026>/Saturation' */
      }
      /* End of '<S97>/DataTypeConv_u16_' */
    }
    /* End of '<S1021>/DelayJudge' */
  }
  ,

  /* End of '<S1018>/Hyster_And_Delay_Judge' */

  /* Start of '<S986>/Delay_5s' */
  {
    /* Start of '<S431>/DelayJudge' */
    {
      0U                               /* '<S1005>/DataTypeConv_u16_' */
    }
    /* End of '<S431>/DelayJudge' */
  }
  ,

  /* End of '<S986>/Delay_5s' */

  /* Start of '<S986>/Delay_15s' */
  {
    /* Start of '<S431>/DelayJudge' */
    {
      0U                               /* '<S1001>/DataTypeConv_u16_' */
    }
    /* End of '<S431>/DelayJudge' */
  }
  ,

  /* End of '<S986>/Delay_15s' */

  /* Start of '<S416>/Delay_5s' */
  {
    /* Start of '<S431>/DelayJudge' */
    {
      0U                               /* '<S437>/DataTypeConv_u16_' */
    }
    /* End of '<S431>/DelayJudge' */
  }
  ,

  /* End of '<S416>/Delay_5s' */

  /* Start of '<S416>/Delay_2s_L1_Increase' */
  {
    /* Start of '<S431>/DelayJudge' */
    {
      0U                               /* '<S433>/DataTypeConv_u16_' */
    }
    /* End of '<S431>/DelayJudge' */
  }
  ,

  /* End of '<S416>/Delay_2s_L1_Increase' */

  /* Start of '<S322>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S332>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S322>/DelayJudge1' */

  /* Start of '<S322>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      12U                              /* '<S329>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S322>/DelayJudge' */

  /* Start of '<S246>/Hyster1' */
  {
    200U,                              /* '<S314>/Conversion' */
    260U                               /* '<S315>/Conversion' */
  }
  ,

  /* End of '<S246>/Hyster1' */

  /* Start of '<S274>/DelayJudge1' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      5U                               /* '<S288>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S274>/DelayJudge1' */

  /* Start of '<S274>/DelayJudge' */
  {
    /* Start of '<S97>/DataTypeConv_u16_' */
    {
      20U                              /* '<S285>/Saturation' */
    }
    /* End of '<S97>/DataTypeConv_u16_' */
  }
  ,

  /* End of '<S274>/DelayJudge' */

  /* Start of '<S89>/Hyster_And_Delay_Judge' */
  {
    /* Start of '<S94>/DelayJudge1' */
    {
      /* Start of '<S97>/DataTypeConv_u16_' */
      {
        100U                           /* '<S102>/Saturation' */
      }
      /* End of '<S97>/DataTypeConv_u16_' */
    }
    ,

    /* End of '<S94>/DelayJudge1' */

    /* Start of '<S94>/DelayJudge' */
    {
      /* Start of '<S97>/DataTypeConv_u16_' */
      {
        100U                           /* '<S99>/Saturation' */
      }
      /* End of '<S97>/DataTypeConv_u16_' */
    }
    /* End of '<S94>/DelayJudge' */
  }
  /* End of '<S89>/Hyster_And_Delay_Judge' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

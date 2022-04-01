/*
 * File: Sokon_X01_Cmf_data.c
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

#include "Sokon_X01_Cmf.h"
#include "Sokon_X01_Cmf_private.h"

/* Constant parameters (default storage) */
const ConstP_Sokon_X01_Cmf_T Sokon_X01_Cmf_ConstP = {
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
  1,

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
  0,

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S76>/UnitDelay1'
   *   '<S80>/Constant'
   *   '<S265>/UnitDelay1'
   *   '<S269>/Constant'
   */
  { { 0UL, 0UL } },

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
  { 9U, 10U },

  /* Computed Parameter: CMF_s8Blw_VSP_Comp_Table_maxIndex
   * Referenced by: '<S22>/CMF_s8Blw_VSP_Comp_Table'
   */
  { 9U, 5U },

  /* Computed Parameter: CMF_s16Tasd_Solar_CMP_Table_maxIndex
   * Referenced by: '<S231>/CMF_s16Tasd_Solar_CMP_Table'
   */
  { 10U, 10U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S215>/Thm_s16Tast_L_Table'
   *   '<S215>/Thm_s16Tast_R_Table'
   */
  { 9U, 12U },

  /* Computed Parameter: R134A_P_a100_T_a10_Table_tableData
   * Referenced by: '<S214>/R134A_P_a100_T_a10_Table'
   */
  { -312, -264, -205, -156, -101, -65, -3, 33, 82, 118, 157, 199, 237, 277, 318,
    360, 402, 441, 480, 520, 563, 602, 640, 679, 721, 760, 801, 841, 881 },

  /* Computed Parameter: TevaSetCompensationByTamb_tableData
   * Referenced by: '<S19>/TevaSetCompensationByTamb'
   */
  { 0, 0, 5, 15 },

  /* Computed Parameter: TevaSetCompensationByTamb_bp01Data
   * Referenced by: '<S19>/TevaSetCompensationByTamb'
   */
  { 0, 250, 300, 400 },

  /* Computed Parameter: R134A_P_a100_T_a10_Table_bp01Data
   * Referenced by: '<S214>/R134A_P_a100_T_a10_Table'
   */
  { 80U, 100U, 130U, 160U, 200U, 230U, 290U, 330U, 390U, 440U, 500U, 570U, 640U,
    720U, 810U, 910U, 1020U, 1130U, 1250U, 1380U, 1530U, 1680U, 1830U, 2000U,
    2190U, 2380U, 2590U, 2810U, 3040U }
};

/* Invariant block signals (default storage) */
const ConstB_Sokon_X01_Cmf_h_T Sokon_X01_Cmf_ConstB = {
  0U,                                  /* '<Root>/Saturation73' */
  0U,                                  /* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<Root>/Saturation55' */
  0,                                   /* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<Root>/Saturation66' */
  0U,                                  /* '<Root>/Saturation68' */
  0U,                                  /* '<Root>/Saturation71' */
  0U,                                  /* '<Root>/Saturation72' */
  0U,                                  /* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0U,                                  /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<Root>/Saturation67' */
  0,                                   /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  0,                                   /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */

  /* Start of '<S238>/FirOrderLinear_Filter' */
  {
    /* Start of '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
    {
      /* Start of '<S265>/Divide_Safe1' */
      {
        1U,                            /* '<S274>/Conversion' */
        1U                             /* '<S268>/Divide1' */
      }
      ,

      /* End of '<S265>/Divide_Safe1' */

      /* Start of '<S265>/Divide_Safe' */
      {
        { { 0x1UL, 0UL } },            /* '<S270>/Conversion' */
        1U                             /* '<S267>/Divide1' */
      }
      /* End of '<S265>/Divide_Safe' */
    }
    /* End of '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  }
  ,

  /* End of '<S238>/FirOrderLinear_Filter' */

  /* Start of '<S237>/DataTypeConv_s16_1' */
  {
    100                                /* '<S247>/Saturation' */
  }
  ,

  /* End of '<S237>/DataTypeConv_s16_1' */

  /* Start of '<S237>/DataTypeConv_s16_' */
  {
    100                                /* '<S246>/Saturation' */
  }
  ,

  /* End of '<S237>/DataTypeConv_s16_' */

  /* Start of '<S164>/Data Type Conversion3' */
  {
    11                                 /* '<S187>/Saturation' */
  }
  ,

  /* End of '<S164>/Data Type Conversion3' */

  /* Start of '<S164>/Data Type Conversion2' */
  {
    14                                 /* '<S186>/Saturation' */
  }
  ,

  /* End of '<S164>/Data Type Conversion2' */

  /* Start of '<S126>/DataTypeConv_u16_1' */
  {
    900U                               /* '<S137>/Saturation' */
  }
  ,

  /* End of '<S126>/DataTypeConv_u16_1' */

  /* Start of '<S126>/Data Type Conversion1' */
  {
    2000U                              /* '<S136>/Saturation' */
  }
  ,

  /* End of '<S126>/Data Type Conversion1' */

  /* Start of '<S126>/Data Type Conversion' */
  {
    2500U                              /* '<S135>/Saturation' */
  }
  ,

  /* End of '<S126>/Data Type Conversion' */

  /* Start of '<S126>/CntModule_Cfg' */
  {
    /* Start of '<S128>/DataTypeConv_u32_2' */
    {
      900U                             /* '<S144>/Saturation' */
    }
    ,

    /* End of '<S128>/DataTypeConv_u32_2' */

    /* Start of '<S128>/DataTypeConv_u32_1' */
    {
      900U                             /* '<S143>/Saturation' */
    }
    /* End of '<S128>/DataTypeConv_u32_1' */
  }
  ,

  /* End of '<S126>/CntModule_Cfg' */

  /* Start of '<S95>/DataTypeConv_u8_5' */
  {
    2U                                 /* '<S115>/Saturation' */
  }
  ,

  /* End of '<S95>/DataTypeConv_u8_5' */

  /* Start of '<S95>/DataTypeConv_u8_4' */
  {
    5U                                 /* '<S114>/Saturation' */
  }
  ,

  /* End of '<S95>/DataTypeConv_u8_4' */

  /* Start of '<S95>/DataTypeConv_u8_1' */
  {
    12U                                /* '<S113>/Saturation' */
  }
  ,

  /* End of '<S95>/DataTypeConv_u8_1' */

  /* Start of '<S95>/DataTypeConv_u8_' */
  {
    15U                                /* '<S112>/Saturation' */
  }
  ,

  /* End of '<S95>/DataTypeConv_u8_' */

  /* Start of '<S95>/DataTypeConv_s16_1' */
  {
    5                                  /* '<S111>/Saturation' */
  }
  ,

  /* End of '<S95>/DataTypeConv_s16_1' */

  /* Start of '<S95>/DataTypeConv_s16_' */
  {
    0                                  /* '<S110>/Saturation' */
  }
  ,

  /* End of '<S95>/DataTypeConv_s16_' */

  /* Start of '<S94>/Data Type Conversion3' */
  {
    -3                                 /* '<S103>/Saturation' */
  }
  ,

  /* End of '<S94>/Data Type Conversion3' */

  /* Start of '<S94>/Data Type Conversion2' */
  {
    3                                  /* '<S102>/Saturation' */
  }
  ,

  /* End of '<S94>/Data Type Conversion2' */

  /* Start of '<S94>/Data Type Conversion1' */
  {
    -3                                 /* '<S101>/Saturation' */
  }
  ,

  /* End of '<S94>/Data Type Conversion1' */

  /* Start of '<S94>/Data Type Conversion' */
  {
    3                                  /* '<S100>/Saturation' */
  }
  ,

  /* End of '<S94>/Data Type Conversion' */

  /* Start of '<S13>/Data Type Conversion4' */
  {
    0U                                 /* '<S93>/Saturation' */
  }
  ,

  /* End of '<S13>/Data Type Conversion4' */

  /* Start of '<S13>/Data Type Conversion3' */
  {
    0U                                 /* '<S92>/Saturation' */
  }
  ,

  /* End of '<S13>/Data Type Conversion3' */

  /* Start of '<S13>/Data Type Conversion2' */
  {
    0U                                 /* '<S91>/Saturation' */
  }
  ,

  /* End of '<S13>/Data Type Conversion2' */

  /* Start of '<S13>/Data Type Conversion1' */
  {
    0                                  /* '<S90>/Saturation' */
  }
  ,

  /* End of '<S13>/Data Type Conversion1' */

  /* Start of '<S12>/FirOrderLinear_Filter10' */
  {
    /* Start of '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
    {
      /* Start of '<S76>/Divide_Safe1' */
      {
        1U,                            /* '<S85>/Conversion' */
        1U                             /* '<S79>/Divide1' */
      }
      ,

      /* End of '<S76>/Divide_Safe1' */

      /* Start of '<S76>/Divide_Safe' */
      {
        { { 0x1UL, 0UL } },            /* '<S81>/Conversion' */
        1U                             /* '<S78>/Divide1' */
      }
      /* End of '<S76>/Divide_Safe' */
    }
    /* End of '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  }
  ,

  /* End of '<S12>/FirOrderLinear_Filter10' */

  /* Start of '<S11>/Data Type Conversion9' */
  {
    0                                  /* '<S71>/Compare' */
  }
  ,

  /* End of '<S11>/Data Type Conversion9' */

  /* Start of '<S11>/Data Type Conversion8' */
  {
    0                                  /* '<S69>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion8' */

  /* Start of '<S11>/Data Type Conversion7' */
  {
    0U                                 /* '<S68>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion7' */

  /* Start of '<S11>/Data Type Conversion6' */
  {
    0                                  /* '<S67>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion6' */

  /* Start of '<S11>/Data Type Conversion5' */
  {
    0                                  /* '<S66>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion5' */

  /* Start of '<S11>/Data Type Conversion4' */
  {
    0                                  /* '<S65>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion4' */

  /* Start of '<S11>/Data Type Conversion30' */
  {
    0                                  /* '<S64>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion30' */

  /* Start of '<S11>/Data Type Conversion3' */
  {
    0                                  /* '<S63>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion3' */

  /* Start of '<S11>/Data Type Conversion29' */
  {
    0U                                 /* '<S62>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion29' */

  /* Start of '<S11>/Data Type Conversion28' */
  {
    0U                                 /* '<S61>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion28' */

  /* Start of '<S11>/Data Type Conversion27' */
  {
    0U                                 /* '<S60>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion27' */

  /* Start of '<S11>/Data Type Conversion26' */
  {
    0U                                 /* '<S59>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion26' */

  /* Start of '<S11>/Data Type Conversion25' */
  {
    0                                  /* '<S58>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion25' */

  /* Start of '<S11>/Data Type Conversion24' */
  {
    0U                                 /* '<S57>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion24' */

  /* Start of '<S11>/Data Type Conversion23' */
  {
    0U                                 /* '<S56>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion23' */

  /* Start of '<S11>/Data Type Conversion22' */
  {
    0U                                 /* '<S55>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion22' */

  /* Start of '<S11>/Data Type Conversion21' */
  {
    0                                  /* '<S54>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion21' */

  /* Start of '<S11>/Data Type Conversion20' */
  {
    0U                                 /* '<S53>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion20' */

  /* Start of '<S11>/Data Type Conversion2' */
  {
    0U                                 /* '<S52>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion2' */

  /* Start of '<S11>/Data Type Conversion19' */
  {
    0                                  /* '<S51>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion19' */

  /* Start of '<S11>/Data Type Conversion18' */
  {
    0                                  /* '<S50>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion18' */

  /* Start of '<S11>/Data Type Conversion17' */
  {
    0                                  /* '<S49>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion17' */

  /* Start of '<S11>/Data Type Conversion16' */
  {
    0U                                 /* '<S48>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion16' */

  /* Start of '<S11>/Data Type Conversion15' */
  {
    0                                  /* '<S47>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion15' */

  /* Start of '<S11>/Data Type Conversion14' */
  {
    0                                  /* '<S46>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion14' */

  /* Start of '<S11>/Data Type Conversion13' */
  {
    0                                  /* '<S45>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion13' */

  /* Start of '<S11>/Data Type Conversion12' */
  {
    0                                  /* '<S44>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion12' */

  /* Start of '<S11>/Data Type Conversion11' */
  {
    0U                                 /* '<S43>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion11' */

  /* Start of '<S11>/Data Type Conversion10' */
  {
    0U                                 /* '<S42>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion10' */

  /* Start of '<S11>/Data Type Conversion1' */
  {
    0U                                 /* '<S41>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion1' */

  /* Start of '<S11>/Data Type Conversion' */
  {
    0U                                 /* '<S40>/Saturation' */
  }
  ,

  /* End of '<S11>/Data Type Conversion' */

  /* Start of '<S20>/Data Type Conversion' */
  {
    0U                                 /* '<S24>/Saturation' */
  }
  ,

  /* End of '<S20>/Data Type Conversion' */

  /* Start of '<S23>/Data Type Conversion' */
  {
    97U                                /* '<S27>/Saturation' */
  }
  /* End of '<S23>/Data Type Conversion' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

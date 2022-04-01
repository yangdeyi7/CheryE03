/*
 * File: Sokon_X01_Cmf.h
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

#ifndef RTW_HEADER_Sokon_X01_Cmf_h_
#define RTW_HEADER_Sokon_X01_Cmf_h_
#include <string.h>
#ifndef Sokon_X01_Cmf_COMMON_INCLUDES_
# define Sokon_X01_Cmf_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Sokon_X01_Cmf_COMMON_INCLUDES_ */

#include "Sokon_X01_Cmf_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Includes for objects with custom storage classes. */
#include "CMF_Parameter.h"

/* Block states (default storage) for system '<S21>/DelayJudge' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  uint16_T u16Count_Delay;             /* '<S34>/JudgeTime' */
} DW_DelayJudge_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  int64m_T UnitDelay1_DSTATE;          /* '<S76>/UnitDelay1' */
  uint8_T UnitDelay2_DSTATE;           /* '<S76>/UnitDelay2' */
} DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S12>/FirOrderLinear_Filter10' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T
    FirOrderLinear_Filter_DoubleFactor_Amp;/* '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
} DW_FirOrderLinear_Filter_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S94>/Hyster_Judge' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S104>/Unit Delay' */
} DW_Hyster_Judge_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S95>/Hyster_Judge1' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S116>/Unit Delay' */
} DW_Hyster_Judge_Sokon_X01_Cmf_p_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S95>/Hyster_Judge2' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S117>/Unit Delay' */
} DW_Hyster_Judge_Sokon_X01_Cmf_po_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S128>/FirstRun' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  uint16_T u16COUNT;                   /* '<S146>/FlagFirstRunJudge' */
} DW_FirstRun_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S126>/CntModule_Cfg' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  uint32_T Loc_i_DSTATE;               /* '<S128>/Loc_i' */
  DW_FirstRun_Sokon_X01_Cmf_T FirstRun;/* '<S128>/FirstRun' */
} DW_CntModule_Cfg_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S126>/FlagHoldModule' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S138>/Unit Delay' */
} DW_FlagHoldModule_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S126>/Hyster_Judge' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S141>/Unit Delay' */
} DW_Hyster_Judge_Sokon_X01_Cmf_e_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S167>/Hyster' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T UnitDelay_DSTATE;          /* '<S168>/Unit Delay' */
  DW_FirstRun_Sokon_X01_Cmf_T Subsystem;/* '<S168>/Subsystem' */
} DW_Hyster_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  int64m_T UnitDelay1_DSTATE;          /* '<S265>/UnitDelay1' */
  int16_T UnitDelay2_DSTATE;           /* '<S265>/UnitDelay2' */
} DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_m_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for system '<S238>/FirOrderLinear_Filter' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_m_T
    FirOrderLinear_Filter_DoubleFactor_Amp;/* '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
} DW_FirOrderLinear_Filter_Sokon_X01_Cmf_m_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'Sokon_X01_Cmf' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  int16_T UnitDelay1_DSTATE;           /* '<S238>/Unit Delay1' */
  uint16_T UnitDelay_DSTATE;           /* '<S238>/Unit Delay' */
  uint16_T u16COUNT_Sensor_Delay;      /* '<S75>/Sensor_Prepare_Delay' */
  uint8_T UnitDelay_DSTATE_j;          /* '<S199>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S126>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_h2;       /* '<S74>/Unit Delay' */
  boolean_T IC_FirstOutputTime;        /* '<Root>/IC' */
  boolean_T IC10_FirstOutputTime;      /* '<Root>/IC10' */
  boolean_T IC20_FirstOutputTime;      /* '<Root>/IC20' */
  boolean_T IC1_FirstOutputTime;       /* '<Root>/IC1' */
  boolean_T IC21_FirstOutputTime;      /* '<Root>/IC21' */
  boolean_T IC14_FirstOutputTime;      /* '<Root>/IC14' */
  boolean_T IC17_FirstOutputTime;      /* '<Root>/IC17' */
  boolean_T IC44_FirstOutputTime;      /* '<Root>/IC44' */
  boolean_T IC45_FirstOutputTime;      /* '<Root>/IC45' */
  boolean_T IC42_FirstOutputTime;      /* '<Root>/IC42' */
  boolean_T IC18_FirstOutputTime;      /* '<Root>/IC18' */
  boolean_T IC19_FirstOutputTime;      /* '<Root>/IC19' */
  boolean_T IC35_FirstOutputTime;      /* '<Root>/IC35' */
  boolean_T IC5_FirstOutputTime;       /* '<Root>/IC5' */
  boolean_T IC40_FirstOutputTime;      /* '<Root>/IC40' */
  boolean_T IC41_FirstOutputTime;      /* '<Root>/IC41' */
  boolean_T IC46_FirstOutputTime;      /* '<Root>/IC46' */
  boolean_T IC47_FirstOutputTime;      /* '<Root>/IC47' */
  boolean_T IC48_FirstOutputTime;      /* '<Root>/IC48' */
  boolean_T IC24_FirstOutputTime;      /* '<Root>/IC24' */
  boolean_T IC25_FirstOutputTime;      /* '<Root>/IC25' */
  boolean_T IC26_FirstOutputTime;      /* '<Root>/IC26' */
  boolean_T IC39_FirstOutputTime;      /* '<Root>/IC39' */
  boolean_T IC78_FirstOutputTime;      /* '<Root>/IC78' */
  boolean_T IC58_FirstOutputTime;      /* '<Root>/IC58' */
  boolean_T IC49_FirstOutputTime;      /* '<Root>/IC49' */
  boolean_T IC50_FirstOutputTime;      /* '<Root>/IC50' */
  boolean_T IC51_FirstOutputTime;      /* '<Root>/IC51' */
  boolean_T IC52_FirstOutputTime;      /* '<Root>/IC52' */
  boolean_T IC53_FirstOutputTime;      /* '<Root>/IC53' */
  boolean_T IC54_FirstOutputTime;      /* '<Root>/IC54' */
  boolean_T IC55_FirstOutputTime;      /* '<Root>/IC55' */
  boolean_T IC56_FirstOutputTime;      /* '<Root>/IC56' */
  boolean_T IC57_FirstOutputTime;      /* '<Root>/IC57' */
  boolean_T IC59_FirstOutputTime;      /* '<Root>/IC59' */
  boolean_T IC60_FirstOutputTime;      /* '<Root>/IC60' */
  boolean_T IC61_FirstOutputTime;      /* '<Root>/IC61' */
  boolean_T IC62_FirstOutputTime;      /* '<Root>/IC62' */
  boolean_T IC63_FirstOutputTime;      /* '<Root>/IC63' */
  boolean_T IC64_FirstOutputTime;      /* '<Root>/IC64' */
  boolean_T IC65_FirstOutputTime;      /* '<Root>/IC65' */
  boolean_T IC66_FirstOutputTime;      /* '<Root>/IC66' */
  boolean_T IC67_FirstOutputTime;      /* '<Root>/IC67' */
  boolean_T IC68_FirstOutputTime;      /* '<Root>/IC68' */
  boolean_T IC69_FirstOutputTime;      /* '<Root>/IC69' */
  boolean_T IC70_FirstOutputTime;      /* '<Root>/IC70' */
  boolean_T IC71_FirstOutputTime;      /* '<Root>/IC71' */
  boolean_T IC72_FirstOutputTime;      /* '<Root>/IC72' */
  boolean_T IC73_FirstOutputTime;      /* '<Root>/IC73' */
  boolean_T IC74_FirstOutputTime;      /* '<Root>/IC74' */
  boolean_T IC75_FirstOutputTime;      /* '<Root>/IC75' */
  boolean_T IC76_FirstOutputTime;      /* '<Root>/IC76' */
  boolean_T IC77_FirstOutputTime;      /* '<Root>/IC77' */
  boolean_T IC4_FirstOutputTime;       /* '<Root>/IC4' */
  boolean_T Loc_bFeatEndFlag;          /* '<S188>/HeatingStartupWhenLowTwater' */
  DW_FirOrderLinear_Filter_Sokon_X01_Cmf_m_T FirOrderLinear_Filter;/* '<S238>/FirOrderLinear_Filter' */
  DW_Hyster_Judge_Sokon_X01_Cmf_T Hyster_Judge1_h;/* '<S164>/Hyster_Judge1' */
  DW_Hyster_Sokon_X01_Cmf_T Hyster2;   /* '<S167>/Hyster2' */
  DW_Hyster_Sokon_X01_Cmf_T Hyster1;   /* '<S167>/Hyster1' */
  DW_Hyster_Sokon_X01_Cmf_T Hyster;    /* '<S167>/Hyster' */
  DW_Hyster_Judge_Sokon_X01_Cmf_e_T Hyster_Judge_l;/* '<S126>/Hyster_Judge' */
  DW_FlagHoldModule_Sokon_X01_Cmf_T FlagHoldModule;/* '<S126>/FlagHoldModule' */
  DW_CntModule_Cfg_Sokon_X01_Cmf_T CntModule_Cfg;/* '<S126>/CntModule_Cfg' */
  DW_Hyster_Judge_Sokon_X01_Cmf_po_T Hyster_Judge4;/* '<S95>/Hyster_Judge4' */
  DW_Hyster_Judge_Sokon_X01_Cmf_po_T Hyster_Judge2;/* '<S95>/Hyster_Judge2' */
  DW_Hyster_Judge_Sokon_X01_Cmf_p_T Hyster_Judge1_b;/* '<S95>/Hyster_Judge1' */
  DW_Hyster_Judge_Sokon_X01_Cmf_T Hyster_Judge1;/* '<S94>/Hyster_Judge1' */
  DW_Hyster_Judge_Sokon_X01_Cmf_T Hyster_Judge;/* '<S94>/Hyster_Judge' */
  DW_FirOrderLinear_Filter_Sokon_X01_Cmf_T FirOrderLinear_Filter10;/* '<S12>/FirOrderLinear_Filter10' */
  DW_DelayJudge_Sokon_X01_Cmf_T DelayJudge;/* '<S21>/DelayJudge' */
} DW_Sokon_X01_Cmf_f_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S23>/Data Type Conversion' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint8_T Saturation;            /* '<S27>/Saturation' */
} ConstB_DataTypeConv_u8__Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S11>/Data Type Conversion' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint8_T Saturation;            /* '<S40>/Saturation' */
} ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S11>/Data Type Conversion10' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint16_T Saturation;           /* '<S42>/Saturation' */
} ConstB_DataTypeConv_u16__Sokon_X01_Cmf_o_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S11>/Data Type Conversion12' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const int16_T Saturation;            /* '<S44>/Saturation' */
} ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S11>/Data Type Conversion17' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const int8_T Saturation;             /* '<S49>/Saturation' */
} ConstB_DataTypeConv_s8__Sokon_X01_Cmf_e_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S11>/Data Type Conversion9' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const boolean_T Compare;             /* '<S71>/Compare' */
} ConstB_DataTypeConv_b__Sokon_X01_Cmf_l_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S76>/Divide_Safe' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const int64m_T Conversion;           /* '<S81>/Conversion' */
  const uint16_T Divide1;              /* '<S78>/Divide1' */
} ConstB_Divide_Safe_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S76>/Divide_Safe1' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint16_T Conversion;           /* '<S85>/Conversion' */
  const uint16_T Divide1;              /* '<S79>/Divide1' */
} ConstB_Divide_Safe_Sokon_X01_Cmf_f_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  ConstB_Divide_Safe_Sokon_X01_Cmf_f_T Divide_Safe1;/* '<S76>/Divide_Safe1' */
  ConstB_Divide_Safe_Sokon_X01_Cmf_T Divide_Safe;/* '<S76>/Divide_Safe' */
} ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S12>/FirOrderLinear_Filter10' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T
    FirOrderLinear_Filter_DoubleFactor_Amp;/* '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
} ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S13>/Data Type Conversion1' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const int8_T Saturation;             /* '<S90>/Saturation' */
} ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S95>/DataTypeConv_s16_' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const int16_T Saturation;            /* '<S110>/Saturation' */
} ConstB_DataTypeConv_s16__Sokon_X01_Cmf_d_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S95>/DataTypeConv_u8_' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint8_T Saturation;            /* '<S112>/Saturation' */
} ConstB_DataTypeConv_u8__Sokon_X01_Cmf_e_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S128>/DataTypeConv_u32_1' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint32_T Saturation;           /* '<S143>/Saturation' */
} ConstB_DataTypeConv_u32__Sokon_X01_Cmf_m_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S126>/CntModule_Cfg' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  ConstB_DataTypeConv_u32__Sokon_X01_Cmf_m_T DataTypeConv_u32_2;/* '<S128>/DataTypeConv_u32_2' */
  ConstB_DataTypeConv_u32__Sokon_X01_Cmf_m_T DataTypeConv_u32_1;/* '<S128>/DataTypeConv_u32_1' */
} ConstB_CntModule_Cfg_Sokon_X01_Cmf_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S126>/Data Type Conversion' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint16_T Saturation;           /* '<S135>/Saturation' */
} ConstB_DataTypeConv_u16__Sokon_X01_Cmf_p_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  ConstB_Divide_Safe_Sokon_X01_Cmf_f_T Divide_Safe1;/* '<S265>/Divide_Safe1' */
  ConstB_Divide_Safe_Sokon_X01_Cmf_T Divide_Safe;/* '<S265>/Divide_Safe' */
} ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_l_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for system '<S238>/FirOrderLinear_Filter' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_l_T
    FirOrderLinear_Filter_DoubleFactor_Amp;/* '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
} ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_g_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'Sokon_X01_Cmf' */
#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

typedef struct {
  const uint16_T Saturation73;         /* '<Root>/Saturation73' */
  const uint16_T CmfO_u16Tw_PTCOut_Set_A10;/* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint16_T CmfO_u16Tw_PTCOut_Set_A10_n;/* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint16_T CmfO_u16Tw_PTCOut_Set_A10_nv;/* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint16_T CmfO_u16Tw_PTCOut_Set_A10_nvh;/* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint16_T CmfO_u16Tw_PTCOut_Set_A10_nvhn;/* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint16_T CmfO_u16Tw_PTCOut_Set_A10_nvhnw;/* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int16_T Saturation55;          /* '<Root>/Saturation55' */
  const int16_T CmfO_s16Tincar_Setting_Req_A10;/* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int16_T CmfO_s16Tincar_Setting_Req_A10_d;/* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int16_T CmfO_s16Tincar_Setting_Req_A10_dv;/* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int16_T CmfO_s16Tincar_Setting_Req_A10_dvl;/* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int16_T CmfO_s16Tincar_Setting_Req_A10_dvlo;/* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int16_T CmfO_s16Tincar_Setting_Req_A10_dvlof;/* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T Saturation66;          /* '<Root>/Saturation66' */
  const uint8_T Saturation68;          /* '<Root>/Saturation68' */
  const uint8_T Saturation71;          /* '<Root>/Saturation71' */
  const uint8_T Saturation72;          /* '<Root>/Saturation72' */
  const uint8_T CmfO_u8CabinCoolPrioReq;/* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinHeatPrioReq;/* '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinCoolPrioReq_g;/* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinHeatPrioReq_m;/* '<S18>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8Debug_IntkStatic;/* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8Debug_ModePerStatic;/* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinCoolPrioReq_gw;/* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinHeatPrioReq_mu;/* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinCoolPrioReq_gwd;/* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinHeatPrioReq_muz;/* '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8Debug_ModePerStatic_n;/* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinCoolPrioReq_gwdg;/* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinHeatPrioReq_muzz;/* '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8Debug_IntkStatic_k;/* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8Debug_ModePerStatic_ng;/* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinCoolPrioReq_gwdge;/* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const uint8_T CmfO_u8CabinHeatPrioReq_muzzk;/* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int8_T Saturation67;           /* '<Root>/Saturation67' */
  const int8_T CmfO_s8Debug_IntkDyn;   /* '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  const int8_T CmfO_s8Debug_IntkDyn_l; /* '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_g_T FirOrderLinear_Filter;/* '<S238>/FirOrderLinear_Filter' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_d_T DataTypeConv_s16_1_i;/* '<S237>/DataTypeConv_s16_1' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_d_T DataTypeConv_s16__j;/* '<S237>/DataTypeConv_s16_' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T DataTypeConversion3_g;/* '<S164>/Data Type Conversion3' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T DataTypeConversion2_dw;/* '<S164>/Data Type Conversion2' */
  ConstB_DataTypeConv_u16__Sokon_X01_Cmf_p_T DataTypeConv_u16_1;/* '<S126>/DataTypeConv_u16_1' */
  ConstB_DataTypeConv_u16__Sokon_X01_Cmf_p_T DataTypeConversion1_n;/* '<S126>/Data Type Conversion1' */
  ConstB_DataTypeConv_u16__Sokon_X01_Cmf_p_T DataTypeConversion_l;/* '<S126>/Data Type Conversion' */
  ConstB_CntModule_Cfg_Sokon_X01_Cmf_T CntModule_Cfg;/* '<S126>/CntModule_Cfg' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_e_T DataTypeConv_u8_5;/* '<S95>/DataTypeConv_u8_5' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_e_T DataTypeConv_u8_4;/* '<S95>/DataTypeConv_u8_4' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_e_T DataTypeConv_u8_1;/* '<S95>/DataTypeConv_u8_1' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_e_T DataTypeConv_u8__c;/* '<S95>/DataTypeConv_u8_' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_d_T DataTypeConv_s16_1_n;/* '<S95>/DataTypeConv_s16_1' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_d_T DataTypeConv_s16_;/* '<S95>/DataTypeConv_s16_' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T DataTypeConversion3_l;/* '<S94>/Data Type Conversion3' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T DataTypeConversion2_d;/* '<S94>/Data Type Conversion2' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T DataTypeConversion1_in;/* '<S94>/Data Type Conversion1' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T DataTypeConversion_a;/* '<S94>/Data Type Conversion' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_T DataTypeConversion4_o;/* '<S13>/Data Type Conversion4' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_T DataTypeConversion3_b;/* '<S13>/Data Type Conversion3' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_T DataTypeConversion2_e;/* '<S13>/Data Type Conversion2' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_d_T DataTypeConversion1_i;/* '<S13>/Data Type Conversion1' */
  ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_T FirOrderLinear_Filter10;/* '<S12>/FirOrderLinear_Filter10' */
  ConstB_DataTypeConv_b__Sokon_X01_Cmf_l_T DataTypeConversion9;/* '<S11>/Data Type Conversion9' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion8;/* '<S11>/Data Type Conversion8' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion7;/* '<S11>/Data Type Conversion7' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion6;/* '<S11>/Data Type Conversion6' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion5;/* '<S11>/Data Type Conversion5' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion4;/* '<S11>/Data Type Conversion4' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion30;/* '<S11>/Data Type Conversion30' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion3;/* '<S11>/Data Type Conversion3' */
  ConstB_DataTypeConv_u16__Sokon_X01_Cmf_o_T DataTypeConversion29;/* '<S11>/Data Type Conversion29' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion28;/* '<S11>/Data Type Conversion28' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion27;/* '<S11>/Data Type Conversion27' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion26;/* '<S11>/Data Type Conversion26' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_e_T DataTypeConversion25;/* '<S11>/Data Type Conversion25' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion24;/* '<S11>/Data Type Conversion24' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion23;/* '<S11>/Data Type Conversion23' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion22;/* '<S11>/Data Type Conversion22' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_e_T DataTypeConversion21;/* '<S11>/Data Type Conversion21' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion20;/* '<S11>/Data Type Conversion20' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion2;/* '<S11>/Data Type Conversion2' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_e_T DataTypeConversion19;/* '<S11>/Data Type Conversion19' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_e_T DataTypeConversion18;/* '<S11>/Data Type Conversion18' */
  ConstB_DataTypeConv_s8__Sokon_X01_Cmf_e_T DataTypeConversion17;/* '<S11>/Data Type Conversion17' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion16;/* '<S11>/Data Type Conversion16' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion15;/* '<S11>/Data Type Conversion15' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion14;/* '<S11>/Data Type Conversion14' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion13;/* '<S11>/Data Type Conversion13' */
  ConstB_DataTypeConv_s16__Sokon_X01_Cmf_o_T DataTypeConversion12;/* '<S11>/Data Type Conversion12' */
  ConstB_DataTypeConv_u16__Sokon_X01_Cmf_o_T DataTypeConversion11;/* '<S11>/Data Type Conversion11' */
  ConstB_DataTypeConv_u16__Sokon_X01_Cmf_o_T DataTypeConversion10;/* '<S11>/Data Type Conversion10' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion1;/* '<S11>/Data Type Conversion1' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_m_T DataTypeConversion;/* '<S11>/Data Type Conversion' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_T DataTypeConversion_k;/* '<S20>/Data Type Conversion' */
  ConstB_DataTypeConv_u8__Sokon_X01_Cmf_T DataTypeConversion_h;/* '<S23>/Data Type Conversion' */
} ConstB_Sokon_X01_Cmf_h_T;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

extern void Sokon_X01_Cmf_Init(void);
extern void Sokon_X01_Cmf_Start(uint8_T *rty_CmfO_u8HVACMode_Req, uint8_T
  *rty_CmfO_u8HVACIntake_Req, uint8_T *rty_CmfO_u8HVACBlwVol_Req_A10, int16_T
  *rty_CmfO_s16Tasd_Left_Req_A10, int16_T *rty_CmfO_s16Tasd_Right_Req_A10,
  int16_T *rty_CmfO_s16TDuct_Left_Out_A10, int16_T
  *rty_CmfO_s16TDuct_Right_Out_A10, uint8_T *rty_CmfO_u8TevaSet_Req_A10, int16_T
  *rty_CmfO_s16Tincar_Setting_Req_A10, boolean_T
  *rty_CmfO_bFlag_HeatShort_Blw_Req, uint16_T *rty_CmfO_u16Debug_TasdLStatic_A10,
  uint16_T *rty_CmfO_u16Debug_TasdRStatic_A10, int16_T
  *rty_CmfO_s16Debug_TasdLSolarCmp_A10, int16_T
  *rty_CmfO_s16Debug_TasdDefCmp_A10, int16_T *rty_CmfO_s16Debug_TasdEcoCmp_A10,
  int16_T *rty_CmfO_s16Debug_TasdDyn_A10, uint8_T
  *rty_CmfO_u8Debug_BlwStatic_A10, int8_T *rty_CmfO_s8Debug_BlwVspCmp_A10,
  int8_T *rty_CmfO_s8Debug_BlwSolarCmp_A10, int8_T *rty_CmfO_s8Debug_BlwDyn_A10,
  uint8_T *rty_CmfO_u8Debug_IntkStatic, int8_T *rty_CmfO_s8Debug_IntkDyn,
  uint8_T *rty_CmfO_u8Debug_ModePerStatic, int8_T
  *rty_CmfO_s8Debug_LvlCabHeatCool, uint8_T *rty_CmfO_u8WindExitmodeDisp,
  uint8_T *rty_CmfO_u8CabinCoolPrioReq, uint8_T *rty_CmfO_u8CabinHeatPrioReq,
  uint16_T *rty_CmfO_u16Tw_PTCOut_Set_Pre_A10, int16_T
  *rty_CmfO_s16Debug_TasdRSolarCmp_A10);
extern void Sokon_X01_Cmf(const uint16_T *rtu_CmfI_u16Tset_Left_A10, const
  uint16_T *rtu_CmfI_u16Tset_Right_A10, const boolean_T *rtu_CmfI_bAcSts, const
  uint8_T *rtu_CmfI_u8BlwMASts, const uint8_T *rtu_CmfI_u8ModeMASts, const
  uint8_T *rtu_CmfI_u8IntakeMASts, const uint16_T *rtu_CmfI_u16P_Ref_CondOut_A10,
  const uint16_T *rtu_CmfI_u16Sun_L, const uint16_T *rtu_CmfI_u16Sun_R, const
  int16_T *rtu_CmfI_s16Tamb_A10, const int16_T *rtu_CmfI_s16Tincar_Front_A10,
  const int16_T *rtu_CmfI_s16TDuct_LV_A10, const int16_T
  *rtu_CmfI_s16TDuct_LF_A10, const int16_T *rtu_CmfI_s16TDuct_RV_A10, const
  uint8_T *rtu_CmfI_u8ModeStatus_Real, const uint8_T *rtu_CmfI_u8IntakePerc_Real,
  const uint8_T *rtu_CmfI_u8HVACSts, const uint8_T *rtu_CmfI_u8VehSpd, const
  boolean_T *rtu_CmfI_bEco_Model_Set, const uint8_T *rtu_CmfI_u8IgnSts, const
  int16_T *rtu_CmfI_s16T_Wat_HVCHOut_A10, const uint8_T *rtu_CmfI_u8BAT_CoolLv,
  const uint16_T *rtu_CmfI_u16Ncomp, const uint8_T
  *rtu_CmfI_u8Mix_Flap_Position_L, const uint8_T *rtu_CmfI_u8HpWorkMode, uint8_T
  *rty_CmfO_u8HVACMode_Req, uint8_T *rty_CmfO_u8HVACIntake_Req, uint8_T
  *rty_CmfO_u8HVACBlwVol_Req_A10, int16_T *rty_CmfO_s16Tasd_Left_Req_A10,
  int16_T *rty_CmfO_s16Tasd_Right_Req_A10, int16_T
  *rty_CmfO_s16TDuct_Left_Out_A10, int16_T *rty_CmfO_s16TDuct_Right_Out_A10,
  uint8_T *rty_CmfO_u8TevaSet_Req_A10, int16_T
  *rty_CmfO_s16Tincar_Setting_Req_A10, boolean_T
  *rty_CmfO_bFlag_HeatShort_Blw_Req, uint16_T *rty_CmfO_u16Debug_TasdLStatic_A10,
  uint16_T *rty_CmfO_u16Debug_TasdRStatic_A10, int16_T
  *rty_CmfO_s16Debug_TasdLSolarCmp_A10, int16_T
  *rty_CmfO_s16Debug_TasdDefCmp_A10, int16_T *rty_CmfO_s16Debug_TasdEcoCmp_A10,
  int16_T *rty_CmfO_s16Debug_TasdDyn_A10, uint8_T
  *rty_CmfO_u8Debug_BlwStatic_A10, int8_T *rty_CmfO_s8Debug_BlwVspCmp_A10,
  int8_T *rty_CmfO_s8Debug_BlwSolarCmp_A10, int8_T *rty_CmfO_s8Debug_BlwDyn_A10,
  uint8_T *rty_CmfO_u8Debug_IntkStatic, int8_T *rty_CmfO_s8Debug_IntkDyn,
  uint8_T *rty_CmfO_u8Debug_ModePerStatic, int8_T
  *rty_CmfO_s8Debug_LvlCabHeatCool, uint8_T *rty_CmfO_u8WindExitmodeDisp,
  uint8_T *rty_CmfO_u8CabinCoolPrioReq, uint8_T *rty_CmfO_u8CabinHeatPrioReq,
  uint16_T *rty_CmfO_u16Tw_PTCOut_Set_Pre_A10, int16_T
  *rty_CmfO_s16Debug_TasdRSolarCmp_A10);

/* Model reference registration function */
extern void Sokon_X01_Cmf_initialize(void);

#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

extern boolean_T Sokon_X01_Cmf_DataTypeConv_b_(boolean_T rtu_In1);
extern uint8_T Sokon_X01_Cmf_IfThenElse(boolean_T rtu_bIf, uint8_T rtu_Then,
  uint8_T rtu_Else);
extern uint16_T Sokon_X01_Cmf_DataTypeConv_u16_(uint16_T rtu_In1);
extern void Sokon_X01_Cmf_DelayJudge_Init(DW_DelayJudge_Sokon_X01_Cmf_T *localDW);
extern boolean_T Sokon_X01_Cmf_DelayJudge(boolean_T rtu_bJudge, uint16_T
  rtu_DelayTime, DW_DelayJudge_Sokon_X01_Cmf_T *localDW);
extern int16_T Sokon_X01_Cmf_DataTypeConv_s16_(int16_T rtu_In1);
extern int8_T Sokon_X01_Cmf_DataTypeConv_s8_(int8_T rtu_In1);
extern void Sokon_X01_Cmf_IfThenElse_p(boolean_T rtu_bIf, int64m_T rtu_Then,
  int64m_T rtu_Else, int64m_T *rty_Out);
extern void Sokon_X01_Cmf_Divide_Safe(int64m_T rtu_x, int64m_T rtu_y, int64m_T
  *rty_out, const ConstB_Divide_Safe_Sokon_X01_Cmf_T *localC);
extern uint16_T Sokon_X01_Cmf_IfThenElse_k(boolean_T rtu_bIf, uint16_T rtu_Then,
  uint16_T rtu_Else);
extern void Sokon_X01_Cmf_Divide_Safe1(int64m_T rtu_x, uint16_T rtu_y, int64m_T *
  rty_out, const ConstB_Divide_Safe_Sokon_X01_Cmf_f_T *localC);
extern uint8_T Sokon_X01_Cmf_FirOrderLinear_Filter_DoubleFactor_Amp(uint8_T
  rtu_DataIn, boolean_T rtu_bFlagInit, uint16_T rtu_FilterFactor_INC, uint16_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T *localDW);
extern uint8_T Sokon_X01_Cmf_FirOrderLinear_Filter(uint8_T rtu_DataIn, boolean_T
  rtu_bFlagInit, uint16_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Cmf_T *localDW, uint16_T rtp_AmpNumVal);
extern void Sokon_X01_Cmf_Hyster_Judge_Init(DW_Hyster_Judge_Sokon_X01_Cmf_T
  *localDW, boolean_T rtp_bParaInit);
extern boolean_T Sokon_X01_Cmf_Hyster_Judge(int8_T rtu_ParaJudgeUp, int8_T
  rtu_HyJudgeIn, int8_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp);
extern void Sokon_X01_Cmf_Hyster_Judge1_Init(DW_Hyster_Judge_Sokon_X01_Cmf_p_T
  *localDW, boolean_T rtp_bParaInit);
extern boolean_T Sokon_X01_Cmf_Hyster_Judge1(int16_T rtu_ParaJudgeUp, int16_T
  rtu_HyJudgeIn, int16_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_p_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp);
extern void Sokon_X01_Cmf_Hyster_Judge2_Init(DW_Hyster_Judge_Sokon_X01_Cmf_po_T *
  localDW, boolean_T rtp_bParaInit);
extern boolean_T Sokon_X01_Cmf_Hyster_Judge2(uint8_T rtu_ParaJudgeUp, uint8_T
  rtu_HyJudgeIn, uint8_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_po_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp);
extern uint32_T Sokon_X01_Cmf_DataTypeConv_u32_(uint32_T rtu_In1);
extern void Sokon_X01_Cmf_FirstRun_Init(boolean_T *rty_bFirstRun,
  DW_FirstRun_Sokon_X01_Cmf_T *localDW);
extern boolean_T Sokon_X01_Cmf_FirstRun(DW_FirstRun_Sokon_X01_Cmf_T *localDW,
  uint16_T rtp_u16DelayTime);
extern uint32_T Sokon_X01_Cmf_IfThenElse1(boolean_T rtu_bIf, uint32_T rtu_Then,
  uint32_T rtu_Else);
extern void Sokon_X01_Cmf_CntModule_Cfg_Init(DW_CntModule_Cfg_Sokon_X01_Cmf_T
  *localDW, uint32_T rtp_InitVal_i);
extern void Sokon_X01_Cmf_CntModule_Cfg(boolean_T rtu_bEnable, boolean_T
  rtu_bReset, boolean_T *rty_bCntReachMax, uint32_T *rty_Cnt_i, const
  ConstB_CntModule_Cfg_Sokon_X01_Cmf_T *localC, DW_CntModule_Cfg_Sokon_X01_Cmf_T
  *localDW, boolean_T rtp_bInitOutput, uint32_T rtp_InitVal_i);
extern boolean_T Sokon_X01_Cmf_IfThenElse1_h(boolean_T rtu_bIf, boolean_T
  rtu_Then, boolean_T rtu_Else);
extern void Sokon_X01_Cmf_FlagHoldModule_Init(DW_FlagHoldModule_Sokon_X01_Cmf_T *
  localDW, boolean_T rtp_bInitValue);
extern boolean_T Sokon_X01_Cmf_FlagHoldModule(boolean_T rtu_bTriggerFlag,
  boolean_T rtu_bResetFlag, DW_FlagHoldModule_Sokon_X01_Cmf_T *localDW);
extern void Sokon_X01_Cmf_Hyster_Judge_d_Init(DW_Hyster_Judge_Sokon_X01_Cmf_e_T *
  localDW, boolean_T rtp_bParaInit);
extern boolean_T Sokon_X01_Cmf_Hyster_Judge_l(uint16_T rtu_ParaJudgeUp, uint16_T
  rtu_HyJudgeIn, uint16_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_e_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp);
extern int8_T Sokon_X01_Cmf_DataTypeConv_s8__n(uint8_T rtu_In1);
extern void Sokon_X01_Cmf_Hyster_Init(DW_Hyster_Sokon_X01_Cmf_T *localDW);
extern boolean_T Sokon_X01_Cmf_Hyster(int16_T rtu_DataIn, int16_T
  rtu_ParaJudgeUp, int16_T rtu_ParaJudgeDown, boolean_T rtu_OutputWhenUp,
  boolean_T rtu_OutputWhenDown, DW_Hyster_Sokon_X01_Cmf_T *localDW, boolean_T
  rtp_bParaInitUseUp);
extern uint8_T Sokon_X01_Cmf_DataTypeConv_u8__d(uint8_T rtu_In1);
extern int16_T Sokon_X01_Cmf_R134a_SatTempCal_P_A100_(uint16_T rtu_u16P_A100);
extern uint8_T Sokon_X01_Cmf_DataTypeConv_u8__g(uint16_T rtu_In1);
extern uint16_T Sokon_X01_Cmf_DataTypeConversion_p(int16_T rtu_In1);
extern int16_T Sokon_X01_Cmf_DataTypeConv_s16__l(uint16_T rtu_In1);
extern int16_T Sokon_X01_Cmf_DataTypeConv_s16_2(int32_T rtu_In1);
extern int16_T Sokon_X01_Cmf_IfThenElse_f(boolean_T rtu_bIf, int16_T rtu_Then,
  int32_T rtu_Else);
extern int16_T Sokon_X01_Cmf_Cal_Divide_10_(int16_T rtu_dataIn);
extern int16_T Sokon_X01_Cmf_FirOrderLinear_Filter_DoubleFactor_Amp_e(int16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, int16_T rtu_FilterFactor_INC, int16_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_l_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_m_T *localDW);
extern int16_T Sokon_X01_Cmf_FirOrderLinear_Filter_m(int16_T rtu_DataIn,
  boolean_T rtu_bFlagInit, int16_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_g_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Cmf_m_T *localDW, uint16_T rtp_AmpNumVal);
extern int16_T Sokon_X01_Cmf_IfThenElse_h(boolean_T rtu_bIf, int16_T rtu_Then,
  int16_T rtu_Else);
extern uint8_T Sokon_X01_Cmf_DataTypeConversion_c(int16_T rtu_In1);

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

#ifndef Sokon_X01_Cmf_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_Sokon_X01_Cmf_f_T Sokon_X01_Cmf_DW;

#endif                                 /*Sokon_X01_Cmf_MDLREF_HIDE_CHILD_*/

/* Exported data declaration */

/* Volatile memory section */
/* Declaration for custom storage class: Volatile */
extern volatile CMF_s8Blw_Dyn_Tab CMF_s8Blw_Dyn;
extern volatile CMF_s8Blw_VSP_Comp_Tab CMF_s8Blw_VSP_Comp;
extern volatile CMF_u8Blw_LImitation_Tab CMF_u8Blw_LImitation;
extern volatile Thm_s16Blower_SolarCmp_Tab Thm_s16Blower_SolarCmp;
extern volatile Thm_s16Mode_Auto_Tab Thm_s16Mode_Auto;
extern volatile Thm_s16Tasd_Def_Cmp_Tab Thm_s16Tasd_Def_Cmp;
extern volatile Thm_s16Tasd_Dyn_Tab Thm_s16Tasd_Dyn;
extern volatile Thm_s16Tasd_Eco_Offset_Tab Thm_s16Tasd_Eco_Offset;
extern volatile Thm_s16Tasd_SolarCmp_Tab Thm_s16Tasd_SolarCmp;
extern volatile Thm_s16Tasd_Solar_Cmp_Coefficient_Tab
  Thm_s16Tasd_Solar_Cmp_Coefficient;
extern volatile Thm_s16Tast_Tab Thm_s16Tast;
extern volatile Thm_s16Tast_TsetDown_Cmp_Tab Thm_s16Tast_TsetDown_Cmp;
extern volatile Thm_s16Tast_TsetFilFactor_Inc_Cmp_Tab
  Thm_s16Tast_TsetFilFactor_Inc_Cmp;
extern volatile Thm_s16Toffset_EVA_SET_Tab Thm_s16Toffset_EVA_SET;
extern volatile Thm_s16Tsys_Tab Thm_s16Tsys;
extern volatile Thm_s8LVL_CabHeat_Tab Thm_s8LVL_CabHeat;
extern volatile Thm_u8VBLW_Static_Tab Thm_u8VBLW_Static;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S119>/Data Type Duplicate' : Unused code path elimination
 * Block '<S120>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S122>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S124>/Data Type Duplicate' : Unused code path elimination
 * Block '<S152>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Signal Copy3' : Unused code path elimination
 * Block '<S13>/Signal Copy4' : Unused code path elimination
 * Block '<S171>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
 * Block '<S178>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S163>/Mode_Mapping' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Max1' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate' : Unused code path elimination
 * Block '<S253>/Data Type Duplicate' : Unused code path elimination
 * Block '<S266>/Data Type Duplicate' : Unused code path elimination
 * Block '<S270>/Data Type Duplicate' : Unused code path elimination
 * Block '<S272>/Data Type Duplicate' : Unused code path elimination
 * Block '<S274>/Data Type Duplicate' : Unused code path elimination
 * Block '<S276>/Data Type Duplicate' : Unused code path elimination
 * Block '<S277>/Data Type Duplicate' : Unused code path elimination
 * Block '<S278>/Data Type Duplicate' : Unused code path elimination
 * Block '<S279>/Data Type Duplicate' : Unused code path elimination
 * Block '<S282>/Compare' : Unused code path elimination
 * Block '<S282>/Constant' : Unused code path elimination
 * Block '<S287>/Data Type Duplicate' : Unused code path elimination
 * Block '<S287>/Data Type Propagation' : Unused code path elimination
 * Block '<Root>/IC11' : Unused code path elimination
 * Block '<Root>/IC12' : Unused code path elimination
 * Block '<Root>/IC13' : Unused code path elimination
 * Block '<Root>/IC15' : Unused code path elimination
 * Block '<Root>/IC16' : Unused code path elimination
 * Block '<Root>/IC2' : Unused code path elimination
 * Block '<Root>/IC22' : Unused code path elimination
 * Block '<Root>/IC23' : Unused code path elimination
 * Block '<Root>/IC27' : Unused code path elimination
 * Block '<Root>/IC28' : Unused code path elimination
 * Block '<Root>/IC29' : Unused code path elimination
 * Block '<Root>/IC3' : Unused code path elimination
 * Block '<Root>/IC30' : Unused code path elimination
 * Block '<Root>/IC31' : Unused code path elimination
 * Block '<Root>/IC32' : Unused code path elimination
 * Block '<Root>/IC33' : Unused code path elimination
 * Block '<Root>/IC34' : Unused code path elimination
 * Block '<Root>/IC36' : Unused code path elimination
 * Block '<Root>/IC37' : Unused code path elimination
 * Block '<Root>/IC38' : Unused code path elimination
 * Block '<Root>/IC43' : Unused code path elimination
 * Block '<Root>/IC6' : Unused code path elimination
 * Block '<Root>/IC7' : Unused code path elimination
 * Block '<Root>/IC8' : Unused code path elimination
 * Block '<Root>/IC9' : Unused code path elimination
 * Block '<Root>/Saturation10' : Unused code path elimination
 * Block '<Root>/Saturation11' : Unused code path elimination
 * Block '<Root>/Saturation12' : Unused code path elimination
 * Block '<Root>/Saturation14' : Unused code path elimination
 * Block '<Root>/Saturation15' : Unused code path elimination
 * Block '<Root>/Saturation2' : Unused code path elimination
 * Block '<Root>/Saturation21' : Unused code path elimination
 * Block '<Root>/Saturation22' : Unused code path elimination
 * Block '<Root>/Saturation26' : Unused code path elimination
 * Block '<Root>/Saturation27' : Unused code path elimination
 * Block '<Root>/Saturation28' : Unused code path elimination
 * Block '<Root>/Saturation29' : Unused code path elimination
 * Block '<Root>/Saturation3' : Unused code path elimination
 * Block '<Root>/Saturation30' : Unused code path elimination
 * Block '<Root>/Saturation31' : Unused code path elimination
 * Block '<Root>/Saturation32' : Unused code path elimination
 * Block '<Root>/Saturation33' : Unused code path elimination
 * Block '<Root>/Saturation35' : Unused code path elimination
 * Block '<Root>/Saturation36' : Unused code path elimination
 * Block '<Root>/Saturation37' : Unused code path elimination
 * Block '<Root>/Saturation41' : Unused code path elimination
 * Block '<Root>/Saturation5' : Unused code path elimination
 * Block '<Root>/Saturation6' : Unused code path elimination
 * Block '<Root>/Saturation7' : Unused code path elimination
 * Block '<Root>/Saturation8' : Unused code path elimination
 * Block '<S20>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S9>/Signal Copy8' : Eliminate redundant signal conversion block
 * Block '<S106>/Conversion' : Eliminate redundant data type conversion
 * Block '<S107>/Conversion' : Eliminate redundant data type conversion
 * Block '<S108>/Conversion' : Eliminate redundant data type conversion
 * Block '<S109>/Conversion' : Eliminate redundant data type conversion
 * Block '<S119>/Conversion' : Eliminate redundant data type conversion
 * Block '<S120>/Conversion' : Eliminate redundant data type conversion
 * Block '<S121>/Conversion' : Eliminate redundant data type conversion
 * Block '<S122>/Conversion' : Eliminate redundant data type conversion
 * Block '<S123>/Conversion' : Eliminate redundant data type conversion
 * Block '<S124>/Conversion' : Eliminate redundant data type conversion
 * Block '<S160>/Conversion' : Eliminate redundant data type conversion
 * Block '<S161>/Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S13>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S13>/Signal Copy8' : Eliminate redundant signal conversion block
 * Block '<S172>/Conversion' : Eliminate redundant data type conversion
 * Block '<S173>/Conversion' : Eliminate redundant data type conversion
 * Block '<S177>/Conversion' : Eliminate redundant data type conversion
 * Block '<S178>/Conversion' : Eliminate redundant data type conversion
 * Block '<S182>/Conversion' : Eliminate redundant data type conversion
 * Block '<S183>/Conversion' : Eliminate redundant data type conversion
 * Block '<S191>/Conversion' : Eliminate redundant data type conversion
 * Block '<S192>/Conversion' : Eliminate redundant data type conversion
 * Block '<S165>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S14>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S14>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S14>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S14>/Signal Copy8' : Eliminate redundant signal conversion block
 * Block '<S15>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S15>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy13' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy14' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy15' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy16' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy17' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy18' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy19' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy20' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy21' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy22' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy25' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy26' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy27' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy28' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy29' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy30' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy31' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy32' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy39' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy7' : Eliminate redundant signal conversion block
 * Block '<S16>/Signal Copy8' : Eliminate redundant signal conversion block
 * Block '<S203>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S216>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy4' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy5' : Eliminate redundant signal conversion block
 * Block '<S18>/Signal Copy6' : Eliminate redundant signal conversion block
 * Block '<S19>/Signal Copy8' : Eliminate redundant signal conversion block
 * Block '<Root>/Saturation38' : Eliminated Saturate block
 * Block '<Root>/Saturation39' : Eliminated Saturate block
 * Block '<Root>/Saturation48' : Eliminated Saturate block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Sokon_X01_Cmf'
 * '<S1>'   : 'Sokon_X01_Cmf/DataTypeConv_b_'
 * '<S2>'   : 'Sokon_X01_Cmf/DataTypeConv_b_1'
 * '<S3>'   : 'Sokon_X01_Cmf/DataTypeConv_b_2'
 * '<S4>'   : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main'
 * '<S5>'   : 'Sokon_X01_Cmf/Model Info1'
 * '<S6>'   : 'Sokon_X01_Cmf/DataTypeConv_b_/Compare To Constant'
 * '<S7>'   : 'Sokon_X01_Cmf/DataTypeConv_b_1/Compare To Constant'
 * '<S8>'   : 'Sokon_X01_Cmf/DataTypeConv_b_2/Compare To Constant'
 * '<S9>'   : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal'
 * '<S10>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusInner'
 * '<S11>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit'
 * '<S12>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake'
 * '<S13>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal'
 * '<S14>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal'
 * '<S15>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/OtherRequirmentCal'
 * '<S16>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/OutputUnpack'
 * '<S17>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal'
 * '<S18>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal'
 * '<S19>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal'
 * '<S20>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management'
 * '<S21>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Auto_Cal'
 * '<S22>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Compensation'
 * '<S23>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management/BlowerFeatureManagement'
 * '<S24>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management/Data Type Conversion'
 * '<S25>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management/HVAC_Status_Off'
 * '<S26>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management/BlowerFeatureManagement/Compare To Constant1'
 * '<S27>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management/BlowerFeatureManagement/Data Type Conversion'
 * '<S28>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management/BlowerFeatureManagement/IfThenElse1'
 * '<S29>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/Blower_Auto_Manual_Management/BlowerFeatureManagement/IfThenElse1/Data Type Conversion Inherited'
 * '<S30>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Auto_Cal/Blower_in_AutoMode'
 * '<S31>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Auto_Cal/Compare To Constant1'
 * '<S32>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Auto_Cal/DelayJudge'
 * '<S33>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Auto_Cal/DelayJudge/DataTypeConv_u16_'
 * '<S34>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Auto_Cal/DelayJudge/Judge'
 * '<S35>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Auto_Cal/DelayJudge/Judge/JudgeTime'
 * '<S36>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Compensation/DataTypeConv_s16_1'
 * '<S37>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Compensation/DataTypeConv_s8_'
 * '<S38>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BlowerCal/CMF_Blower_Compensation/DataTypeConv_u16_'
 * '<S39>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusInner/LastOutputBus'
 * '<S40>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion'
 * '<S41>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion1'
 * '<S42>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion10'
 * '<S43>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion11'
 * '<S44>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion12'
 * '<S45>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion13'
 * '<S46>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion14'
 * '<S47>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion15'
 * '<S48>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion16'
 * '<S49>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion17'
 * '<S50>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion18'
 * '<S51>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion19'
 * '<S52>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion2'
 * '<S53>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion20'
 * '<S54>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion21'
 * '<S55>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion22'
 * '<S56>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion23'
 * '<S57>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion24'
 * '<S58>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion25'
 * '<S59>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion26'
 * '<S60>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion27'
 * '<S61>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion28'
 * '<S62>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion29'
 * '<S63>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion3'
 * '<S64>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion30'
 * '<S65>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion4'
 * '<S66>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion5'
 * '<S67>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion6'
 * '<S68>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion7'
 * '<S69>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion8'
 * '<S70>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion9'
 * '<S71>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/BusOutputInit/Data Type Conversion9/Compare To Constant'
 * '<S72>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/Compare To Constant'
 * '<S73>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10'
 * '<S74>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/JudgeFirstIGN'
 * '<S75>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/JudgeFlag_Sensor_Ready'
 * '<S76>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp'
 * '<S77>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Data Type Conversion Inherited'
 * '<S78>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe'
 * '<S79>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1'
 * '<S80>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/Compare To Constant'
 * '<S81>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/Data Type Conversion Inherited'
 * '<S82>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/IfThenElse'
 * '<S83>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/IfThenElse/Data Type Conversion Inherited'
 * '<S84>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/Compare To Constant'
 * '<S85>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/Data Type Conversion Inherited'
 * '<S86>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/IfThenElse'
 * '<S87>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/FirOrderLinear_Filter10/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/IfThenElse/Data Type Conversion Inherited'
 * '<S88>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/JudgeFirstIGN/JudgeSWFirstRun'
 * '<S89>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/InputPake/JudgeFlag_Sensor_Ready/Sensor_Prepare_Delay'
 * '<S90>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Data Type Conversion1'
 * '<S91>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Data Type Conversion2'
 * '<S92>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Data Type Conversion3'
 * '<S93>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Data Type Conversion4'
 * '<S94>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation'
 * '<S95>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature'
 * '<S96>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management'
 * '<S97>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Manual_Calculation'
 * '<S98>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Compare To Constant1'
 * '<S99>'  : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Compare To Constant11'
 * '<S100>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Data Type Conversion'
 * '<S101>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Data Type Conversion1'
 * '<S102>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Data Type Conversion2'
 * '<S103>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Data Type Conversion3'
 * '<S104>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Hyster_Judge'
 * '<S105>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Hyster_Judge1'
 * '<S106>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Hyster_Judge/Data Type Conversion Inherited'
 * '<S107>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Hyster_Judge/Data Type Conversion Inherited1'
 * '<S108>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Hyster_Judge1/Data Type Conversion Inherited'
 * '<S109>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation/Hyster_Judge1/Data Type Conversion Inherited1'
 * '<S110>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/DataTypeConv_s16_'
 * '<S111>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/DataTypeConv_s16_1'
 * '<S112>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/DataTypeConv_u8_'
 * '<S113>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/DataTypeConv_u8_1'
 * '<S114>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/DataTypeConv_u8_4'
 * '<S115>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/DataTypeConv_u8_5'
 * '<S116>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge1'
 * '<S117>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge2'
 * '<S118>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge4'
 * '<S119>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge1/Data Type Conversion Inherited'
 * '<S120>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge1/Data Type Conversion Inherited1'
 * '<S121>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge2/Data Type Conversion Inherited'
 * '<S122>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge2/Data Type Conversion Inherited1'
 * '<S123>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge4/Data Type Conversion Inherited'
 * '<S124>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Calculation_For_Sokon_X1_Feature/Hyster_Judge4/Data Type Conversion Inherited1'
 * '<S125>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/Fresh_Recycle_in_ManualMode1'
 * '<S126>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement'
 * '<S127>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/ '
 * '<S128>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg'
 * '<S129>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Compare To Constant3'
 * '<S130>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Compressor open'
 * '<S131>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Compressor open2'
 * '<S132>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Compressor open3'
 * '<S133>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Compressor open4'
 * '<S134>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Compressor open5'
 * '<S135>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Data Type Conversion'
 * '<S136>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Data Type Conversion1'
 * '<S137>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/DataTypeConv_u16_1'
 * '<S138>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/FlagHoldModule'
 * '<S139>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/HVAC_Status_Defrost1'
 * '<S140>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/HVAC_Status_Defrost2'
 * '<S141>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Hyster_Judge'
 * '<S142>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/DataTypeConv_u32_'
 * '<S143>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/DataTypeConv_u32_1'
 * '<S144>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/DataTypeConv_u32_2'
 * '<S145>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/DataTypeConv_u32_3'
 * '<S146>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/FirstRun'
 * '<S147>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse1'
 * '<S148>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse2'
 * '<S149>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse3'
 * '<S150>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse4'
 * '<S151>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/FirstRun/FlagFirstRunJudge'
 * '<S152>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse1/Data Type Conversion Inherited'
 * '<S153>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse2/Data Type Conversion Inherited'
 * '<S154>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse3/Data Type Conversion Inherited'
 * '<S155>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/CntModule_Cfg/IfThenElse4/Data Type Conversion Inherited'
 * '<S156>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/FlagHoldModule/IfThenElse1'
 * '<S157>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/FlagHoldModule/IfThenElse2'
 * '<S158>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/FlagHoldModule/IfThenElse1/Data Type Conversion Inherited'
 * '<S159>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/FlagHoldModule/IfThenElse2/Data Type Conversion Inherited'
 * '<S160>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Hyster_Judge/Data Type Conversion Inherited'
 * '<S161>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Auto_Manual_Management/IntakeFeatureManagement/Hyster_Judge/Data Type Conversion Inherited1'
 * '<S162>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/IntakeCal/Intake_Manual_Calculation/Fresh_Recycle_in_ManualMode1'
 * '<S163>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd'
 * '<S164>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement'
 * '<S165>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/Mode_Auto_Manual_Management'
 * '<S166>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/DataTypeConv_s8_'
 * '<S167>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control'
 * '<S168>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster'
 * '<S169>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster1'
 * '<S170>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster2'
 * '<S171>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster/Data Type Conversion Inherited'
 * '<S172>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster/Data Type Conversion Inherited1'
 * '<S173>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster/Data Type Conversion Inherited2'
 * '<S174>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster/Subsystem'
 * '<S175>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster/Subsystem/FlagFirstRunJudge'
 * '<S176>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster1/Data Type Conversion Inherited'
 * '<S177>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster1/Data Type Conversion Inherited1'
 * '<S178>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster1/Data Type Conversion Inherited2'
 * '<S179>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster1/Subsystem'
 * '<S180>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster1/Subsystem/FlagFirstRunJudge'
 * '<S181>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster2/Data Type Conversion Inherited'
 * '<S182>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster2/Data Type Conversion Inherited1'
 * '<S183>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster2/Data Type Conversion Inherited2'
 * '<S184>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster2/Subsystem'
 * '<S185>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeAutoCalctByTasd/Mode_Hysterris_Control/Hyster2/Subsystem/FlagFirstRunJudge'
 * '<S186>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement/Data Type Conversion2'
 * '<S187>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement/Data Type Conversion3'
 * '<S188>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement/HeatingStartupWhenLowTwater'
 * '<S189>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement/Hyster_Judge1'
 * '<S190>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement/HeatingStartupWhenLowTwater/HeatingStartupWhenLowTwater'
 * '<S191>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement/Hyster_Judge1/Data Type Conversion Inherited'
 * '<S192>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/ModeFeatureManagement/Hyster_Judge1/Data Type Conversion Inherited1'
 * '<S193>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/Mode_Auto_Manual_Management/DataTypeConv_u8_'
 * '<S194>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/ModeCal/Mode_Auto_Manual_Management/Mode_Status_Auto_7'
 * '<S195>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/App_Pre_Cal'
 * '<S196>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal'
 * '<S197>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal'
 * '<S198>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/UserSet_Pre_Cal'
 * '<S199>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/App_Pre_Cal/FirstIgnOnJudge'
 * '<S200>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/App_Pre_Cal/FirstIgnOnJudge/Compare To Constant'
 * '<S201>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/App_Pre_Cal/FirstIgnOnJudge/Compare To Constant1'
 * '<S202>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation'
 * '<S203>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/T_HeatSourceCalc'
 * '<S204>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/T_SatHPCal'
 * '<S205>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant'
 * '<S206>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant1'
 * '<S207>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant2'
 * '<S208>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant3'
 * '<S209>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant4'
 * '<S210>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant5'
 * '<S211>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant7'
 * '<S212>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant8'
 * '<S213>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/TDuct_Calculation/Compare To Constant9'
 * '<S214>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/Sen_Pre_Cal/T_SatHPCal/R134a_SatTempCal_P_A100_'
 * '<S215>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal'
 * '<S216>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature'
 * '<S217>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Tset_Ave_Cal'
 * '<S218>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/Compare To Constant'
 * '<S219>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/Compare To Constant1'
 * '<S220>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/Compare To Constant2'
 * '<S221>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/Compare To Constant3'
 * '<S222>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/Compare To Constant4'
 * '<S223>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/DataTypeConv_u8_'
 * '<S224>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/IfThenElse'
 * '<S225>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/StaticTable_Cal/CmfGetStaticTableCal/Amp_BlwVol_Judgement_Feature/IfThenElse/Data Type Conversion Inherited'
 * '<S226>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/UserSet_Pre_Cal/LVL_CabHeatCoolingCal'
 * '<S227>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/PerData_Cal/UserSet_Pre_Cal/Tset_Ave_Cal'
 * '<S228>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Data Type Conversion'
 * '<S229>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Data Type Conversion1'
 * '<S230>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation'
 * '<S231>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Dynamic'
 * '<S232>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Limitation_Output'
 * '<S233>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Static_Calculation'
 * '<S234>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Compensation_Eco_Mode'
 * '<S235>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_DefComp'
 * '<S236>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_DiffComp'
 * '<S237>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp'
 * '<S238>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp'
 * '<S239>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Compensation_Eco_Mode/Compare To Constant1'
 * '<S240>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_DefComp/Compare To Constant3'
 * '<S241>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_DiffComp/DataTypeConv_s16_'
 * '<S242>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_DiffComp/DataTypeConv_s16_1'
 * '<S243>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_DiffComp/DataTypeConv_s16_2'
 * '<S244>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/Compare To Constant'
 * '<S245>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/Compare To Constant1'
 * '<S246>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/DataTypeConv_s16_'
 * '<S247>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/DataTypeConv_s16_1'
 * '<S248>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/DataTypeConv_s16_2'
 * '<S249>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/DataTypeConv_s16_3'
 * '<S250>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/IfThenElse'
 * '<S251>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/IfThenElse1'
 * '<S252>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/IfThenElse/Data Type Conversion Inherited'
 * '<S253>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_SolarComp/IfThenElse1/Data Type Conversion Inherited'
 * '<S254>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/Cal_Divide_10_'
 * '<S255>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/Compare To Constant'
 * '<S256>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/Compare To Constant1'
 * '<S257>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/Compare To Constant2'
 * '<S258>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/Compare To Constant3'
 * '<S259>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/DataTypeConv_s16_'
 * '<S260>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/DataTypeConv_s16_1'
 * '<S261>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter'
 * '<S262>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/IfThenElse'
 * '<S263>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/IfThenElse1'
 * '<S264>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/IfThenElse2'
 * '<S265>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp'
 * '<S266>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Data Type Conversion Inherited'
 * '<S267>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe'
 * '<S268>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1'
 * '<S269>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/Compare To Constant'
 * '<S270>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/Data Type Conversion Inherited'
 * '<S271>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/IfThenElse'
 * '<S272>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe/IfThenElse/Data Type Conversion Inherited'
 * '<S273>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/Compare To Constant'
 * '<S274>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/Data Type Conversion Inherited'
 * '<S275>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/IfThenElse'
 * '<S276>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/FirOrderLinear_Filter/FirOrderLinear_Filter_DoubleFactor_Amp/Divide_Safe1/IfThenElse/Data Type Conversion Inherited'
 * '<S277>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/IfThenElse/Data Type Conversion Inherited'
 * '<S278>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/IfThenElse1/Data Type Conversion Inherited'
 * '<S279>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TasdCal/Tasd_Cmp_Calculation/Tasd_Tset_Cmp/IfThenElse2/Data Type Conversion Inherited'
 * '<S280>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Compare To Constant11'
 * '<S281>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Compare To Constant3'
 * '<S282>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Compare To Constant6'
 * '<S283>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Compare To Constant7'
 * '<S284>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Compare To Constant8'
 * '<S285>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Compare To Constant9'
 * '<S286>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Data Type Conversion'
 * '<S287>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/Saturation Dynamic1'
 * '<S288>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/TevaSetMinFeatures'
 * '<S289>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/TevaSetMinFeatures/Compare To Constant1'
 * '<S290>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/TevaSetMinFeatures/Compare To Constant11'
 * '<S291>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/TevaSetMinFeatures/Compare To Constant2'
 * '<S292>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/TevaSetMinFeatures/Compare To Constant3'
 * '<S293>' : 'Sokon_X01_Cmf/GAC_A02_Cmf_Main/TevaSetCal/TevaSetMinFeatures/Compare To Constant4'
 */

/*-
 * Requirements for '<Root>': Sokon_X01_Cmf
 */
#endif                                 /* RTW_HEADER_Sokon_X01_Cmf_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

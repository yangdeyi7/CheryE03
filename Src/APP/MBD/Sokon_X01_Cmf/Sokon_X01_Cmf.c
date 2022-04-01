/*
 * File: Sokon_X01_Cmf.c
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
#include "MultiWordAdd.h"
#include "MultiWordSub.h"
#include "asr_s32.h"
#include "div_nde_s32_floor.h"
#include "div_nzp_s32_near.h"
#include "look1_is16lu32n16Ds32_binlcs.h"
#include "look1_is8lu32n16ts16Ds32_binlcs.h"
#include "look1_iu16lu32n16ts16Ds32_binlcn.h"
#include "look2_is16lu16n8ts8Ds16ds16_binlcs.h"
#include "look2_is16lu16n8tu8_binlcse.h"
#include "look2_is16lu32n16Ds32ds32_binlcs.h"
#include "look2_iu16s16lu16n16ts16Ds32ds32_binlcas.h"
#include "look2_iu16s16lu16n8ts8Ds16ds16_binlcn.h"
#include "look2_iu16s16lu16n8tu8_binlcne.h"
#include "look2_iu16s16lu32n16ts16Ds32ds32_binlcn.h"
#include "look2_iu16s16lu32n16ts16Ds32ds32_binlcs.h"
#include "look2_iu8lu32n24ts8Ds16ds16_binlcs.h"
#include "sLong2MultiWord.h"
#include "sMultiWord2MultiWord.h"
#include "sMultiWord2sLongSat.h"
#include "sMultiWord2uLongSat.h"
#include "sMultiWordDivNear.h"
#include "sMultiWordNe.h"
#include "sMultiWordShl.h"
#include "sMultiWordShrNear.h"
#include "uLong2MultiWord.h"
#include "uMultiWord2MultiWord.h"
#include "uMultiWordShl.h"

/* Block states (default storage) */
DW_Sokon_X01_Cmf_f_T Sokon_X01_Cmf_DW;

/*
 * Output and update for atomic system:
 *    '<Root>/DataTypeConv_b_'
 *    '<Root>/DataTypeConv_b_1'
 *    '<Root>/DataTypeConv_b_2'
 */
boolean_T Sokon_X01_Cmf_DataTypeConv_b_(boolean_T rtu_In1)
{
  /* RelationalOperator: '<S6>/Compare' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S23>/IfThenElse1'
 *    '<S216>/IfThenElse'
 */
uint8_T Sokon_X01_Cmf_IfThenElse(boolean_T rtu_bIf, uint8_T rtu_Then, uint8_T
  rtu_Else)
{
  uint8_T rty_Out_0;

  /* Switch: '<S28>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S29>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S29>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S28>/Switch' */
  return rty_Out_0;
}

/*
 * Output and update for atomic system:
 *    '<S32>/DataTypeConv_u16_'
 *    '<S22>/DataTypeConv_u16_'
 */
uint16_T Sokon_X01_Cmf_DataTypeConv_u16_(uint16_T rtu_In1)
{
  /* Saturate: '<S33>/Saturation' */
  return rtu_In1;
}

/* System initialize for atomic system: '<S21>/DelayJudge' */
void Sokon_X01_Cmf_DelayJudge_Init(DW_DelayJudge_Sokon_X01_Cmf_T *localDW)
{
  /* SystemInitialize for Chart: '<S34>/JudgeTime' */
  localDW->u16Count_Delay = 0U;
}

/* Output and update for atomic system: '<S21>/DelayJudge' */
boolean_T Sokon_X01_Cmf_DelayJudge(boolean_T rtu_bJudge, uint16_T rtu_DelayTime,
  DW_DelayJudge_Sokon_X01_Cmf_T *localDW)
{
  boolean_T rty_bDelayJudge_0;
  uint16_T rtb_Saturation_b;
  int32_T tmp;

  /* Outputs for Atomic SubSystem: '<S32>/DataTypeConv_u16_' */
  rtb_Saturation_b = (uint16_T) Sokon_X01_Cmf_DataTypeConv_u16_(rtu_DelayTime);

  /* End of Outputs for SubSystem: '<S32>/DataTypeConv_u16_' */

  /* Chart: '<S34>/JudgeTime' */
  if (rtu_bJudge) {
    if (localDW->u16Count_Delay >= rtb_Saturation_b) {
      /* SignalConversion: '<S32>/Signal Copy' */
      rty_bDelayJudge_0 = true;
    } else {
      /* SignalConversion: '<S32>/Signal Copy' */
      rty_bDelayJudge_0 = false;
      tmp = ((int32_T)localDW->u16Count_Delay) + 1;
      if (tmp > 65535) {
        tmp = 65535;
      }

      localDW->u16Count_Delay = (uint16_T)tmp;
    }
  } else {
    localDW->u16Count_Delay = 0U;

    /* SignalConversion: '<S32>/Signal Copy' */
    rty_bDelayJudge_0 = false;
  }

  /* End of Chart: '<S34>/JudgeTime' */
  return rty_bDelayJudge_0;
}

/*
 * Output and update for atomic system:
 *    '<S22>/DataTypeConv_s16_1'
 *    '<S237>/DataTypeConv_s16_2'
 *    '<S237>/DataTypeConv_s16_3'
 */
int16_T Sokon_X01_Cmf_DataTypeConv_s16_(int16_T rtu_In1)
{
  /* Saturate: '<S36>/Saturation' */
  return rtu_In1;
}

/* Output and update for atomic system: '<S22>/DataTypeConv_s8_' */
int8_T Sokon_X01_Cmf_DataTypeConv_s8_(int8_T rtu_In1)
{
  /* Saturate: '<S37>/Saturation' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S78>/IfThenElse'
 *    '<S267>/IfThenElse'
 */
void Sokon_X01_Cmf_IfThenElse_p(boolean_T rtu_bIf, int64m_T rtu_Then, int64m_T
  rtu_Else, int64m_T *rty_Out)
{
  /* Switch: '<S82>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S83>/Conversion' */
    *rty_Out = rtu_Then;
  } else {
    /* DataTypeConversion: '<S83>/Conversion' */
    *rty_Out = rtu_Else;
  }

  /* End of Switch: '<S82>/Switch' */
}

/*
 * Output and update for atomic system:
 *    '<S76>/Divide_Safe'
 *    '<S265>/Divide_Safe'
 */
void Sokon_X01_Cmf_Divide_Safe(int64m_T rtu_x, int64m_T rtu_y, int64m_T *rty_out,
  const ConstB_Divide_Safe_Sokon_X01_Cmf_T *localC)
{
  int64m_T rtb_Conversion_p;
  int96m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;

  /* Outputs for Atomic SubSystem: '<S78>/IfThenElse' */

  /* RelationalOperator: '<S80>/Compare' incorporates:
   *  Constant: '<S80>/Constant'
   */
  Sokon_X01_Cmf_IfThenElse_p(sMultiWordNe(&rtu_y.chunks[0U],
    &Sokon_X01_Cmf_ConstP.pooled9.chunks[0], 2), rtu_y, localC->Conversion,
    &rtb_Conversion_p);

  /* End of Outputs for SubSystem: '<S78>/IfThenElse' */

  /* Product: '<S78>/Divide' */
  tmp_0 = rtu_x;
  sMultiWordDivNear(&tmp_0.chunks[0U], 2, &rtb_Conversion_p.chunks[0U], 2,
                    &tmp.chunks[0U], 3, &tmp_1.chunks[0U], 2, &tmp_2.chunks[0U],
                    2, &tmp_3.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp.chunks[0U], 3, &tmp_0.chunks[0U], 2);
  *rty_out = tmp_0;
}

/*
 * Output and update for atomic system:
 *    '<S79>/IfThenElse'
 *    '<S268>/IfThenElse'
 */
uint16_T Sokon_X01_Cmf_IfThenElse_k(boolean_T rtu_bIf, uint16_T rtu_Then,
  uint16_T rtu_Else)
{
  uint16_T rty_Out_0;

  /* Switch: '<S86>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S87>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S87>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S86>/Switch' */
  return rty_Out_0;
}

/*
 * Output and update for atomic system:
 *    '<S76>/Divide_Safe1'
 *    '<S265>/Divide_Safe1'
 */
void Sokon_X01_Cmf_Divide_Safe1(int64m_T rtu_x, uint16_T rtu_y, int64m_T
  *rty_out, const ConstB_Divide_Safe_Sokon_X01_Cmf_f_T *localC)
{
  uint16_T rtb_Conversion_m2;
  int96m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  int64m_T tmp_4;

  /* Outputs for Atomic SubSystem: '<S79>/IfThenElse' */

  /* RelationalOperator: '<S84>/Compare' incorporates:
   *  Constant: '<S84>/Constant'
   */
  rtb_Conversion_m2 = (uint16_T) Sokon_X01_Cmf_IfThenElse_k(((int32_T)rtu_y) !=
    0, rtu_y, localC->Conversion);

  /* End of Outputs for SubSystem: '<S79>/IfThenElse' */

  /* Product: '<S79>/Divide' */
  tmp_0 = rtu_x;
  uLong2MultiWord((uint32_T)rtb_Conversion_m2, &tmp_1.chunks[0U], 2);
  sMultiWordDivNear(&tmp_0.chunks[0U], 2, &tmp_1.chunks[0U], 2, &tmp.chunks[0U],
                    3, &tmp_2.chunks[0U], 2, &tmp_3.chunks[0U], 2,
                    &tmp_4.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp.chunks[0U], 3, &tmp_0.chunks[0U], 2);
  *rty_out = tmp_0;
}

/* Output and update for atomic system: '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
uint8_T Sokon_X01_Cmf_FirOrderLinear_Filter_DoubleFactor_Amp(uint8_T rtu_DataIn,
  boolean_T rtu_bFlagInit, uint16_T rtu_FilterFactor_INC, uint16_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_T *localDW)
{
  uint8_T rty_FilterOut_0;
  int64m_T rtb_Product_e;
  int64m_T rtb_Divide_gi;
  int64m_T rtb_Switch1_i;
  int64m_T rtb_Divide_lk;
  uint32_T tmp;
  uint64m_T tmp_0;
  uint64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  int96m_T tmp_4;
  int96m_T tmp_5;

  /* Product: '<S76>/Product' */
  uLong2MultiWord(((uint32_T)rtu_DataIn) * ((uint32_T)rtu_u16AmpNumVal),
                  &tmp_1.chunks[0U], 2);
  uMultiWordShl(&tmp_1.chunks[0U], 2, 16U, &tmp_0.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_0.chunks[0U], 2, &rtb_Product_e.chunks[0U], 2);

  /* UnitDelay: '<S76>/UnitDelay1' */
  rtb_Divide_gi = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S76>/Switch1' incorporates:
   *  RelationalOperator: '<S76>/Relational Operator'
   *  UnitDelay: '<S76>/UnitDelay2'
   */
  if (rtu_DataIn > localDW->UnitDelay2_DSTATE) {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_INC) << 16,
                    &rtb_Switch1_i.chunks[0U], 2);
  } else {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_DEC) << 16,
                    &rtb_Switch1_i.chunks[0U], 2);
  }

  /* End of Switch: '<S76>/Switch1' */

  /* Sum: '<S76>/Subtract1' incorporates:
   *  UnitDelay: '<S76>/UnitDelay1'
   */
  tmp_2 = localDW->UnitDelay1_DSTATE;
  MultiWordSub(&rtb_Product_e.chunks[0U], &tmp_2.chunks[0U], &tmp_3.chunks[0U],
               2);

  /* Outputs for Atomic SubSystem: '<S76>/Divide_Safe' */
  Sokon_X01_Cmf_Divide_Safe(tmp_3, rtb_Switch1_i, &rtb_Divide_lk,
    &localC->Divide_Safe);

  /* End of Outputs for SubSystem: '<S76>/Divide_Safe' */

  /* Switch: '<S76>/Switch' incorporates:
   *  UnitDelay: '<S76>/UnitDelay1'
   */
  if (rtu_bFlagInit) {
    localDW->UnitDelay1_DSTATE = rtb_Product_e;
  } else {
    /* Sum: '<S76>/Add1' incorporates:
     *  UnitDelay: '<S76>/UnitDelay1'
     */
    sMultiWord2MultiWord(&rtb_Divide_lk.chunks[0U], 2, &tmp_5.chunks[0U], 3);
    sMultiWordShl(&tmp_5.chunks[0U], 3, 16U, &tmp_4.chunks[0U], 3);
    sMultiWord2MultiWord(&tmp_4.chunks[0U], 3, &tmp_2.chunks[0U], 2);
    MultiWordAdd(&tmp_2.chunks[0U], &rtb_Divide_gi.chunks[0U],
                 &localDW->UnitDelay1_DSTATE.chunks[0U], 2);
  }

  /* End of Switch: '<S76>/Switch' */

  /* Outputs for Atomic SubSystem: '<S76>/Divide_Safe1' */
  /* UnitDelay: '<S76>/UnitDelay1' */
  Sokon_X01_Cmf_Divide_Safe1(localDW->UnitDelay1_DSTATE, rtu_u16AmpNumVal,
    &rtb_Divide_gi, &localC->Divide_Safe1);

  /* End of Outputs for SubSystem: '<S76>/Divide_Safe1' */

  /* DataTypeConversion: '<S77>/Conversion' */
  sMultiWordShrNear(&rtb_Divide_gi.chunks[0U], 2, 16U, &tmp_2.chunks[0U], 2);
  tmp = sMultiWord2uLongSat(&tmp_2.chunks[0U], 2);
  if (tmp > 255U) {
    tmp = 255U;
  }

  rty_FilterOut_0 = (uint8_T)tmp;

  /* Update for UnitDelay: '<S76>/UnitDelay2' incorporates:
   *  DataTypeConversion: '<S77>/Conversion'
   */
  localDW->UnitDelay2_DSTATE = (uint8_T)tmp;
  return rty_FilterOut_0;
}

/* Output and update for atomic system: '<S12>/FirOrderLinear_Filter10' */
uint8_T Sokon_X01_Cmf_FirOrderLinear_Filter(uint8_T rtu_DataIn, boolean_T
  rtu_bFlagInit, uint16_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Cmf_T *localDW, uint16_T rtp_AmpNumVal)
{
  uint8_T rty_FilterOut_0;

  /* Outputs for Atomic SubSystem: '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */

  /* SignalConversion: '<S73>/TmpSignal ConversionAtFirOrderLinear_Filter_DoubleFactor_AmpInport3' incorporates:
   *  Constant: '<S73>/Constant1'
   */
  rty_FilterOut_0 = (uint8_T)
    Sokon_X01_Cmf_FirOrderLinear_Filter_DoubleFactor_Amp(rtu_DataIn,
    rtu_bFlagInit, rtu_FilterFactor, rtu_FilterFactor, rtp_AmpNumVal,
    &localC->FirOrderLinear_Filter_DoubleFactor_Amp,
    &localDW->FirOrderLinear_Filter_DoubleFactor_Amp);

  /* End of Outputs for SubSystem: '<S73>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  return rty_FilterOut_0;
}

/*
 * System initialize for atomic system:
 *    '<S94>/Hyster_Judge'
 *    '<S94>/Hyster_Judge1'
 *    '<S164>/Hyster_Judge1'
 */
void Sokon_X01_Cmf_Hyster_Judge_Init(DW_Hyster_Judge_Sokon_X01_Cmf_T *localDW,
  boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S104>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;
}

/*
 * Output and update for atomic system:
 *    '<S94>/Hyster_Judge'
 *    '<S94>/Hyster_Judge1'
 *    '<S164>/Hyster_Judge1'
 */
boolean_T Sokon_X01_Cmf_Hyster_Judge(int8_T rtu_ParaJudgeUp, int8_T
  rtu_HyJudgeIn, int8_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;

  /* Switch: '<S104>/Switch4' incorporates:
   *  Constant: '<S104>/JudgeYes'
   *  Logic: '<S104>/NOT'
   *  RelationalOperator: '<S104>/RelationalOperator1'
   *  UnitDelay: '<S104>/Unit Delay'
   */
  if (rtu_HyJudgeIn <= rtu_ParaJudgeDown) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S104>/Switch4' */

  /* Switch: '<S104>/Switch2' incorporates:
   *  Constant: '<S104>/JudgeYes'
   *  RelationalOperator: '<S104>/RelationalOperator3'
   *  UnitDelay: '<S104>/Unit Delay'
   */
  if (rtu_HyJudgeIn >= rtu_ParaJudgeUp) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S104>/Switch2' */

  /* Update for UnitDelay: '<S104>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/* System initialize for atomic system: '<S95>/Hyster_Judge1' */
void Sokon_X01_Cmf_Hyster_Judge1_Init(DW_Hyster_Judge_Sokon_X01_Cmf_p_T *localDW,
  boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S116>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;
}

/* Output and update for atomic system: '<S95>/Hyster_Judge1' */
boolean_T Sokon_X01_Cmf_Hyster_Judge1(int16_T rtu_ParaJudgeUp, int16_T
  rtu_HyJudgeIn, int16_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_p_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;

  /* Switch: '<S116>/Switch4' incorporates:
   *  Constant: '<S116>/JudgeYes'
   *  Logic: '<S116>/NOT'
   *  RelationalOperator: '<S116>/RelationalOperator1'
   *  UnitDelay: '<S116>/Unit Delay'
   */
  if (rtu_HyJudgeIn <= rtu_ParaJudgeDown) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S116>/Switch4' */

  /* Switch: '<S116>/Switch2' incorporates:
   *  Constant: '<S116>/JudgeYes'
   *  RelationalOperator: '<S116>/RelationalOperator3'
   *  UnitDelay: '<S116>/Unit Delay'
   */
  if (rtu_HyJudgeIn >= rtu_ParaJudgeUp) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S116>/Switch2' */

  /* Update for UnitDelay: '<S116>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/*
 * System initialize for atomic system:
 *    '<S95>/Hyster_Judge2'
 *    '<S95>/Hyster_Judge4'
 */
void Sokon_X01_Cmf_Hyster_Judge2_Init(DW_Hyster_Judge_Sokon_X01_Cmf_po_T
  *localDW, boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S117>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;
}

/*
 * Output and update for atomic system:
 *    '<S95>/Hyster_Judge2'
 *    '<S95>/Hyster_Judge4'
 */
boolean_T Sokon_X01_Cmf_Hyster_Judge2(uint8_T rtu_ParaJudgeUp, uint8_T
  rtu_HyJudgeIn, uint8_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_po_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;

  /* Switch: '<S117>/Switch4' incorporates:
   *  Constant: '<S117>/JudgeYes'
   *  Logic: '<S117>/NOT'
   *  RelationalOperator: '<S117>/RelationalOperator1'
   *  UnitDelay: '<S117>/Unit Delay'
   */
  if (rtu_HyJudgeIn <= rtu_ParaJudgeDown) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S117>/Switch4' */

  /* Switch: '<S117>/Switch2' incorporates:
   *  Constant: '<S117>/JudgeYes'
   *  RelationalOperator: '<S117>/RelationalOperator3'
   *  UnitDelay: '<S117>/Unit Delay'
   */
  if (rtu_HyJudgeIn >= rtu_ParaJudgeUp) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S117>/Switch2' */

  /* Update for UnitDelay: '<S117>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/*
 * Output and update for atomic system:
 *    '<S128>/DataTypeConv_u32_'
 *    '<S128>/DataTypeConv_u32_3'
 */
uint32_T Sokon_X01_Cmf_DataTypeConv_u32_(uint32_T rtu_In1)
{
  /* Saturate: '<S142>/Saturation' */
  return rtu_In1;
}

/*
 * System initialize for atomic system:
 *    '<S128>/FirstRun'
 *    '<S168>/Subsystem'
 *    '<S169>/Subsystem'
 *    '<S170>/Subsystem'
 */
void Sokon_X01_Cmf_FirstRun_Init(boolean_T *rty_bFirstRun,
  DW_FirstRun_Sokon_X01_Cmf_T *localDW)
{
  /* SystemInitialize for Chart: '<S146>/FlagFirstRunJudge' */
  localDW->u16COUNT = 0U;
  *rty_bFirstRun = false;
}

/*
 * Output and update for atomic system:
 *    '<S128>/FirstRun'
 *    '<S168>/Subsystem'
 *    '<S169>/Subsystem'
 *    '<S170>/Subsystem'
 */
boolean_T Sokon_X01_Cmf_FirstRun(DW_FirstRun_Sokon_X01_Cmf_T *localDW, uint16_T
  rtp_u16DelayTime)
{
  boolean_T rty_bFirstRun_0;
  int32_T tmp;

  /* Chart: '<S146>/FlagFirstRunJudge' */
  if (localDW->u16COUNT < rtp_u16DelayTime) {
    rty_bFirstRun_0 = true;
    tmp = ((int32_T)localDW->u16COUNT) + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    localDW->u16COUNT = (uint16_T)tmp;
  } else {
    rty_bFirstRun_0 = false;
  }

  /* End of Chart: '<S146>/FlagFirstRunJudge' */
  return rty_bFirstRun_0;
}

/*
 * Output and update for atomic system:
 *    '<S128>/IfThenElse1'
 *    '<S128>/IfThenElse2'
 *    '<S128>/IfThenElse3'
 *    '<S128>/IfThenElse4'
 */
uint32_T Sokon_X01_Cmf_IfThenElse1(boolean_T rtu_bIf, uint32_T rtu_Then,
  uint32_T rtu_Else)
{
  uint32_T rty_Out_0;

  /* Switch: '<S147>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S152>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S152>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S147>/Switch' */
  return rty_Out_0;
}

/* System initialize for atomic system: '<S126>/CntModule_Cfg' */
void Sokon_X01_Cmf_CntModule_Cfg_Init(DW_CntModule_Cfg_Sokon_X01_Cmf_T *localDW,
  uint32_T rtp_InitVal_i)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun;

  /* InitializeConditions for UnitDelay: '<S128>/Loc_i' */
  localDW->Loc_i_DSTATE = rtp_InitVal_i;

  /* SystemInitialize for Atomic SubSystem: '<S128>/FirstRun' */
  Sokon_X01_Cmf_FirstRun_Init(&rtb_bFirstRun, &localDW->FirstRun);

  /* End of SystemInitialize for SubSystem: '<S128>/FirstRun' */
}

/* Output and update for atomic system: '<S126>/CntModule_Cfg' */
void Sokon_X01_Cmf_CntModule_Cfg(boolean_T rtu_bEnable, boolean_T rtu_bReset,
  boolean_T *rty_bCntReachMax, uint32_T *rty_Cnt_i, const
  ConstB_CntModule_Cfg_Sokon_X01_Cmf_T *localC, DW_CntModule_Cfg_Sokon_X01_Cmf_T
  *localDW, boolean_T rtp_bInitOutput, uint32_T rtp_InitVal_i)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun;
  boolean_T rtb_AND_j;
  uint32_T rtb_Conversion_m;
  uint32_T rtb_Conversion_mi;

  /* Logic: '<S128>/AND' incorporates:
   *  Logic: '<S128>/NOT'
   */
  rtb_AND_j = (rtu_bEnable && (!rtu_bReset));

  /* Outputs for Atomic SubSystem: '<S128>/FirstRun' */
  rtb_bFirstRun = ( Sokon_X01_Cmf_FirstRun(&localDW->FirstRun, 1) != false);

  /* End of Outputs for SubSystem: '<S128>/FirstRun' */

  /* Outputs for Atomic SubSystem: '<S128>/IfThenElse4' */

  /* Constant: '<S128>/Constant2' incorporates:
   *  Constant: '<S128>/Constant1'
   */
  rtb_Conversion_m = (uint32_T) Sokon_X01_Cmf_IfThenElse1(rtp_bInitOutput,
    localC->DataTypeConv_u32_1.Saturation, rtp_InitVal_i);

  /* End of Outputs for SubSystem: '<S128>/IfThenElse4' */

  /* Outputs for Atomic SubSystem: '<S128>/IfThenElse3' */

  /* UnitDelay: '<S128>/Loc_i' incorporates:
   *  Constant: '<S128>/Constant1'
   */
  rtb_Conversion_mi = (uint32_T) Sokon_X01_Cmf_IfThenElse1(rtb_AND_j,
    localDW->Loc_i_DSTATE, rtp_InitVal_i);

  /* End of Outputs for SubSystem: '<S128>/IfThenElse3' */

  /* Outputs for Atomic SubSystem: '<S128>/IfThenElse2' */

  /* Logic: '<S128>/AND1' */
  *rty_Cnt_i = (uint32_T) Sokon_X01_Cmf_IfThenElse1(rtb_bFirstRun && rtb_AND_j,
    rtb_Conversion_m, rtb_Conversion_mi);

  /* End of Outputs for SubSystem: '<S128>/IfThenElse2' */

  /* Outputs for Atomic SubSystem: '<S128>/DataTypeConv_u32_3' */

  /* Bias: '<S128>/Add Constant' */
  rtb_Conversion_mi = (uint32_T) Sokon_X01_Cmf_DataTypeConv_u32_((*rty_Cnt_i) +
    1U);

  /* End of Outputs for SubSystem: '<S128>/DataTypeConv_u32_3' */

  /* RelationalOperator: '<S128>/NotEqual1' */
  *rty_bCntReachMax = ((*rty_Cnt_i) > localC->DataTypeConv_u32_2.Saturation);

  /* Outputs for Atomic SubSystem: '<S128>/IfThenElse1' */
  rtb_Conversion_mi = (uint32_T) Sokon_X01_Cmf_IfThenElse1(*rty_bCntReachMax,
    *rty_Cnt_i, rtb_Conversion_mi);

  /* End of Outputs for SubSystem: '<S128>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S128>/DataTypeConv_u32_' */

  /* UnitDelay: '<S128>/Loc_i' */
  localDW->Loc_i_DSTATE = (uint32_T) Sokon_X01_Cmf_DataTypeConv_u32_
    (rtb_Conversion_mi);

  /* End of Outputs for SubSystem: '<S128>/DataTypeConv_u32_' */
}

/*
 * Output and update for atomic system:
 *    '<S138>/IfThenElse1'
 *    '<S138>/IfThenElse2'
 */
boolean_T Sokon_X01_Cmf_IfThenElse1_h(boolean_T rtu_bIf, boolean_T rtu_Then,
  boolean_T rtu_Else)
{
  boolean_T rty_Out_0;

  /* Switch: '<S156>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S158>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S158>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S156>/Switch' */
  return rty_Out_0;
}

/* System initialize for atomic system: '<S126>/FlagHoldModule' */
void Sokon_X01_Cmf_FlagHoldModule_Init(DW_FlagHoldModule_Sokon_X01_Cmf_T
  *localDW, boolean_T rtp_bInitValue)
{
  /* InitializeConditions for UnitDelay: '<S138>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bInitValue;
}

/* Output and update for atomic system: '<S126>/FlagHoldModule' */
boolean_T Sokon_X01_Cmf_FlagHoldModule(boolean_T rtu_bTriggerFlag, boolean_T
  rtu_bResetFlag, DW_FlagHoldModule_Sokon_X01_Cmf_T *localDW)
{
  boolean_T rty_bFlagHold_0;
  boolean_T rtb_Conversion_o;

  /* Outputs for Atomic SubSystem: '<S138>/IfThenElse2' */

  /* Constant: '<S138>/Constant3' incorporates:
   *  UnitDelay: '<S138>/Unit Delay'
   */
  rtb_Conversion_o = ( Sokon_X01_Cmf_IfThenElse1_h(rtu_bResetFlag, false,
    localDW->UnitDelay_DSTATE) != false);

  /* End of Outputs for SubSystem: '<S138>/IfThenElse2' */

  /* Outputs for Atomic SubSystem: '<S138>/IfThenElse1' */

  /* Constant: '<S138>/Constant1' */
  rty_bFlagHold_0 = ( Sokon_X01_Cmf_IfThenElse1_h(rtu_bTriggerFlag, true,
    rtb_Conversion_o) != false);

  /* End of Outputs for SubSystem: '<S138>/IfThenElse1' */

  /* Update for UnitDelay: '<S138>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bFlagHold_0;
  return rty_bFlagHold_0;
}

/* System initialize for atomic system: '<S126>/Hyster_Judge' */
void Sokon_X01_Cmf_Hyster_Judge_d_Init(DW_Hyster_Judge_Sokon_X01_Cmf_e_T
  *localDW, boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S141>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;
}

/* Output and update for atomic system: '<S126>/Hyster_Judge' */
boolean_T Sokon_X01_Cmf_Hyster_Judge_l(uint16_T rtu_ParaJudgeUp, uint16_T
  rtu_HyJudgeIn, uint16_T rtu_ParaJudgeDown, DW_Hyster_Judge_Sokon_X01_Cmf_e_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;

  /* Switch: '<S141>/Switch4' incorporates:
   *  Constant: '<S141>/JudgeYes'
   *  Logic: '<S141>/NOT'
   *  RelationalOperator: '<S141>/RelationalOperator1'
   *  UnitDelay: '<S141>/Unit Delay'
   */
  if (rtu_HyJudgeIn <= rtu_ParaJudgeDown) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S141>/Switch4' */

  /* Switch: '<S141>/Switch2' incorporates:
   *  Constant: '<S141>/JudgeYes'
   *  RelationalOperator: '<S141>/RelationalOperator3'
   *  UnitDelay: '<S141>/Unit Delay'
   */
  if (rtu_HyJudgeIn >= rtu_ParaJudgeUp) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S141>/Switch2' */

  /* Update for UnitDelay: '<S141>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/* Output and update for atomic system: '<S163>/DataTypeConv_s8_' */
int8_T Sokon_X01_Cmf_DataTypeConv_s8__n(uint8_T rtu_In1)
{
  int8_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S166>/Saturation' */
  if (((int32_T)rtu_In1) < 127) {
    y = (int32_T)rtu_In1;
  } else {
    y = 127;
  }

  rty_Out1_0 = (int8_T)y;

  /* End of Saturate: '<S166>/Saturation' */
  return rty_Out1_0;
}

/*
 * System initialize for atomic system:
 *    '<S167>/Hyster'
 *    '<S167>/Hyster1'
 *    '<S167>/Hyster2'
 */
void Sokon_X01_Cmf_Hyster_Init(DW_Hyster_Sokon_X01_Cmf_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_i;

  /* SystemInitialize for Atomic SubSystem: '<S168>/Subsystem' */
  Sokon_X01_Cmf_FirstRun_Init(&rtb_bFirstRun_i, &localDW->Subsystem);

  /* End of SystemInitialize for SubSystem: '<S168>/Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S167>/Hyster'
 *    '<S167>/Hyster1'
 *    '<S167>/Hyster2'
 */
boolean_T Sokon_X01_Cmf_Hyster(int16_T rtu_DataIn, int16_T rtu_ParaJudgeUp,
  int16_T rtu_ParaJudgeDown, boolean_T rtu_OutputWhenUp, boolean_T
  rtu_OutputWhenDown, DW_Hyster_Sokon_X01_Cmf_T *localDW, boolean_T
  rtp_bParaInitUseUp)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_i;
  boolean_T rty_HyDataOut_0;

  /* Switch: '<S168>/Switch3' incorporates:
   *  Constant: '<S168>/Constant'
   */
  if (rtp_bParaInitUseUp) {
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  } else {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S168>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S168>/Subsystem' */
  rtb_bFirstRun_i = ( Sokon_X01_Cmf_FirstRun(&localDW->Subsystem, 1) != false);

  /* End of Outputs for SubSystem: '<S168>/Subsystem' */

  /* Switch: '<S168>/Switch1' incorporates:
   *  UnitDelay: '<S168>/Unit Delay'
   */
  if (!rtb_bFirstRun_i) {
    rty_HyDataOut_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S168>/Switch1' */

  /* Switch: '<S168>/Switch4' incorporates:
   *  RelationalOperator: '<S168>/RelationalOperator1'
   */
  if (rtu_DataIn <= rtu_ParaJudgeDown) {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S168>/Switch4' */

  /* Switch: '<S168>/Switch2' incorporates:
   *  RelationalOperator: '<S168>/RelationalOperator3'
   */
  if (rtu_DataIn >= rtu_ParaJudgeUp) {
    /* DataTypeConversion: '<S171>/Conversion' */
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  }

  /* End of Switch: '<S168>/Switch2' */

  /* Update for UnitDelay: '<S168>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_HyDataOut_0;
  return rty_HyDataOut_0;
}

/* Output and update for atomic system: '<S165>/DataTypeConv_u8_' */
uint8_T Sokon_X01_Cmf_DataTypeConv_u8__d(uint8_T rtu_In1)
{
  /* Saturate: '<S193>/Saturation' */
  return rtu_In1;
}

/* Output and update for atomic system: '<S204>/R134a_SatTempCal_P_A100_' */
int16_T Sokon_X01_Cmf_R134a_SatTempCal_P_A100_(uint16_T rtu_u16P_A100)
{
  /* Lookup_n-D: '<S214>/R134A_P_a100_T_a10_Table' */
  return look1_iu16lu32n16ts16Ds32_binlcn(rtu_u16P_A100,
    Sokon_X01_Cmf_ConstP.R134A_P_a100_T_a10_Table_bp01Data,
    Sokon_X01_Cmf_ConstP.R134A_P_a100_T_a10_Table_tableData, 28U);
}

/* Output and update for atomic system: '<S216>/DataTypeConv_u8_' */
uint8_T Sokon_X01_Cmf_DataTypeConv_u8__g(uint16_T rtu_In1)
{
  uint8_T rty_Out1_0;
  uint32_T y;

  /* Saturate: '<S223>/Saturation' */
  if (((uint32_T)rtu_In1) < 255U) {
    y = (uint32_T)rtu_In1;
  } else {
    y = 255U;
  }

  rty_Out1_0 = (uint8_T)y;

  /* End of Saturate: '<S223>/Saturation' */
  return rty_Out1_0;
}

/*
 * Output and update for atomic system:
 *    '<S18>/Data Type Conversion'
 *    '<S18>/Data Type Conversion1'
 */
uint16_T Sokon_X01_Cmf_DataTypeConversion_p(int16_T rtu_In1)
{
  uint16_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S228>/Saturation' */
  if (rtu_In1 > 0) {
    y = (int32_T)rtu_In1;
  } else {
    y = 0;
  }

  rty_Out1_0 = (uint16_T)y;

  /* End of Saturate: '<S228>/Saturation' */
  return rty_Out1_0;
}

/*
 * Output and update for atomic system:
 *    '<S236>/DataTypeConv_s16_'
 *    '<S236>/DataTypeConv_s16_1'
 *    '<S238>/DataTypeConv_s16_'
 *    '<S238>/DataTypeConv_s16_1'
 */
int16_T Sokon_X01_Cmf_DataTypeConv_s16__l(uint16_T rtu_In1)
{
  int16_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S241>/Saturation' */
  if (((int32_T)rtu_In1) < 32767) {
    y = (int32_T)rtu_In1;
  } else {
    y = 32767;
  }

  rty_Out1_0 = (int16_T)y;

  /* End of Saturate: '<S241>/Saturation' */
  return rty_Out1_0;
}

/* Output and update for atomic system: '<S236>/DataTypeConv_s16_2' */
int16_T Sokon_X01_Cmf_DataTypeConv_s16_2(int32_T rtu_In1)
{
  int16_T rty_Out1_0;

  /* Saturate: '<S243>/Saturation' */
  if (rtu_In1 >= 1073709056) {
    rty_Out1_0 = MAX_int16_T;
  } else if (rtu_In1 <= -1073741824) {
    rty_Out1_0 = MIN_int16_T;
  } else {
    rty_Out1_0 = (int16_T)asr_s32(rtu_In1, 15U);
  }

  /* End of Saturate: '<S243>/Saturation' */
  return rty_Out1_0;
}

/*
 * Output and update for atomic system:
 *    '<S237>/IfThenElse'
 *    '<S237>/IfThenElse1'
 */
int16_T Sokon_X01_Cmf_IfThenElse_f(boolean_T rtu_bIf, int16_T rtu_Then, int32_T
  rtu_Else)
{
  int16_T rty_Out_0;
  int32_T rtb_Switch_hv;

  /* Switch: '<S250>/Switch' */
  if (rtu_bIf) {
    rtb_Switch_hv = (int32_T)rtu_Then;
  } else {
    rtb_Switch_hv = rtu_Else;
  }

  /* End of Switch: '<S250>/Switch' */

  /* DataTypeConversion: '<S252>/Conversion' */
  if (rtb_Switch_hv > 32767) {
    rtb_Switch_hv = 32767;
  } else {
    if (rtb_Switch_hv < -32768) {
      rtb_Switch_hv = -32768;
    }
  }

  rty_Out_0 = (int16_T)rtb_Switch_hv;

  /* End of DataTypeConversion: '<S252>/Conversion' */
  return rty_Out_0;
}

/* Output and update for atomic system: '<S238>/Cal_Divide_10_' */
int16_T Sokon_X01_Cmf_Cal_Divide_10_(int16_T rtu_dataIn)
{
  /* Product: '<S254>/Divide' */
  return (int16_T)div_nzp_s32_near((int32_T)rtu_dataIn, 10);
}

/* Output and update for atomic system: '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
int16_T Sokon_X01_Cmf_FirOrderLinear_Filter_DoubleFactor_Amp_e(int16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, int16_T rtu_FilterFactor_INC, int16_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_l_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Cmf_m_T *localDW)
{
  int16_T rty_FilterOut_0;
  int64m_T rtb_Product_e;
  int64m_T rtb_Divide_o;
  int64m_T rtb_Switch1_c;
  int64m_T rtb_Divide_m;
  int32_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int96m_T tmp_2;
  int96m_T tmp_3;

  /* Product: '<S265>/Product' */
  sLong2MultiWord(((int32_T)rtu_DataIn) * ((int32_T)rtu_u16AmpNumVal),
                  &tmp_0.chunks[0U], 2);
  sMultiWordShl(&tmp_0.chunks[0U], 2, 16U, &rtb_Product_e.chunks[0U], 2);

  /* UnitDelay: '<S265>/UnitDelay1' */
  rtb_Divide_o = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S265>/Switch1' incorporates:
   *  RelationalOperator: '<S265>/Relational Operator'
   *  UnitDelay: '<S265>/UnitDelay2'
   */
  if (rtu_DataIn > localDW->UnitDelay2_DSTATE) {
    sLong2MultiWord(((int32_T)rtu_FilterFactor_INC) * 65536,
                    &rtb_Switch1_c.chunks[0U], 2);
  } else {
    sLong2MultiWord(((int32_T)rtu_FilterFactor_DEC) * 65536,
                    &rtb_Switch1_c.chunks[0U], 2);
  }

  /* End of Switch: '<S265>/Switch1' */

  /* Sum: '<S265>/Subtract1' incorporates:
   *  UnitDelay: '<S265>/UnitDelay1'
   */
  tmp_0 = localDW->UnitDelay1_DSTATE;
  MultiWordSub(&rtb_Product_e.chunks[0U], &tmp_0.chunks[0U], &tmp_1.chunks[0U],
               2);

  /* Outputs for Atomic SubSystem: '<S265>/Divide_Safe' */
  Sokon_X01_Cmf_Divide_Safe(tmp_1, rtb_Switch1_c, &rtb_Divide_m,
    &localC->Divide_Safe);

  /* End of Outputs for SubSystem: '<S265>/Divide_Safe' */

  /* Switch: '<S265>/Switch' incorporates:
   *  UnitDelay: '<S265>/UnitDelay1'
   */
  if (rtu_bFlagInit) {
    localDW->UnitDelay1_DSTATE = rtb_Product_e;
  } else {
    /* Sum: '<S265>/Add1' incorporates:
     *  UnitDelay: '<S265>/UnitDelay1'
     */
    sMultiWord2MultiWord(&rtb_Divide_m.chunks[0U], 2, &tmp_3.chunks[0U], 3);
    sMultiWordShl(&tmp_3.chunks[0U], 3, 16U, &tmp_2.chunks[0U], 3);
    sMultiWord2MultiWord(&tmp_2.chunks[0U], 3, &tmp_0.chunks[0U], 2);
    MultiWordAdd(&tmp_0.chunks[0U], &rtb_Divide_o.chunks[0U],
                 &localDW->UnitDelay1_DSTATE.chunks[0U], 2);
  }

  /* End of Switch: '<S265>/Switch' */

  /* Outputs for Atomic SubSystem: '<S265>/Divide_Safe1' */
  /* UnitDelay: '<S265>/UnitDelay1' */
  Sokon_X01_Cmf_Divide_Safe1(localDW->UnitDelay1_DSTATE, rtu_u16AmpNumVal,
    &rtb_Divide_o, &localC->Divide_Safe1);

  /* End of Outputs for SubSystem: '<S265>/Divide_Safe1' */

  /* DataTypeConversion: '<S266>/Conversion' */
  sMultiWordShrNear(&rtb_Divide_o.chunks[0U], 2, 16U, &tmp_0.chunks[0U], 2);
  tmp = sMultiWord2sLongSat(&tmp_0.chunks[0U], 2);
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  rty_FilterOut_0 = (int16_T)tmp;

  /* Update for UnitDelay: '<S265>/UnitDelay2' incorporates:
   *  DataTypeConversion: '<S266>/Conversion'
   */
  localDW->UnitDelay2_DSTATE = (int16_T)tmp;
  return rty_FilterOut_0;
}

/* Output and update for atomic system: '<S238>/FirOrderLinear_Filter' */
int16_T Sokon_X01_Cmf_FirOrderLinear_Filter_m(int16_T rtu_DataIn, boolean_T
  rtu_bFlagInit, int16_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Cmf_g_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Cmf_m_T *localDW, uint16_T rtp_AmpNumVal)
{
  int16_T rty_FilterOut_0;

  /* Outputs for Atomic SubSystem: '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */

  /* SignalConversion: '<S261>/TmpSignal ConversionAtFirOrderLinear_Filter_DoubleFactor_AmpInport3' incorporates:
   *  Constant: '<S261>/Constant1'
   */
  rty_FilterOut_0 = (int16_T)
    Sokon_X01_Cmf_FirOrderLinear_Filter_DoubleFactor_Amp_e(rtu_DataIn,
    rtu_bFlagInit, rtu_FilterFactor, rtu_FilterFactor, rtp_AmpNumVal,
    &localC->FirOrderLinear_Filter_DoubleFactor_Amp,
    &localDW->FirOrderLinear_Filter_DoubleFactor_Amp);

  /* End of Outputs for SubSystem: '<S261>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  return rty_FilterOut_0;
}

/*
 * Output and update for atomic system:
 *    '<S238>/IfThenElse'
 *    '<S238>/IfThenElse1'
 *    '<S238>/IfThenElse2'
 */
int16_T Sokon_X01_Cmf_IfThenElse_h(boolean_T rtu_bIf, int16_T rtu_Then, int16_T
  rtu_Else)
{
  int16_T rty_Out_0;

  /* Switch: '<S262>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S277>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S277>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S262>/Switch' */
  return rty_Out_0;
}

/* Output and update for atomic system: '<S19>/Data Type Conversion' */
uint8_T Sokon_X01_Cmf_DataTypeConversion_c(int16_T rtu_In1)
{
  uint8_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S286>/Saturation' */
  if (rtu_In1 > 255) {
    y = 255;
  } else if (rtu_In1 < 0) {
    y = 0;
  } else {
    y = (int32_T)rtu_In1;
  }

  rty_Out1_0 = (uint8_T)y;

  /* End of Saturate: '<S286>/Saturation' */
  return rty_Out1_0;
}

/* System initialize for referenced model: 'Sokon_X01_Cmf' */
void Sokon_X01_Cmf_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S4>/ModeCal' */
  /* SystemInitialize for Atomic SubSystem: '<S167>/Hyster' */
  Sokon_X01_Cmf_Hyster_Init(&Sokon_X01_Cmf_DW.Hyster);

  /* End of SystemInitialize for SubSystem: '<S167>/Hyster' */

  /* SystemInitialize for Atomic SubSystem: '<S167>/Hyster1' */
  Sokon_X01_Cmf_Hyster_Init(&Sokon_X01_Cmf_DW.Hyster1);

  /* End of SystemInitialize for SubSystem: '<S167>/Hyster1' */

  /* SystemInitialize for Atomic SubSystem: '<S167>/Hyster2' */
  Sokon_X01_Cmf_Hyster_Init(&Sokon_X01_Cmf_DW.Hyster2);

  /* End of SystemInitialize for SubSystem: '<S167>/Hyster2' */

  /* SystemInitialize for Atomic SubSystem: '<S164>/Hyster_Judge1' */
  Sokon_X01_Cmf_Hyster_Judge_Init(&Sokon_X01_Cmf_DW.Hyster_Judge1_h,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S164>/Hyster_Judge1' */

  /* SystemInitialize for Chart: '<S188>/HeatingStartupWhenLowTwater' */
  Sokon_X01_Cmf_DW.Loc_bFeatEndFlag = false;

  /* End of SystemInitialize for SubSystem: '<S4>/ModeCal' */

  /* SystemInitialize for Atomic SubSystem: '<S12>/JudgeFlag_Sensor_Ready' */
  /* SystemInitialize for Chart: '<S75>/Sensor_Prepare_Delay' */
  Sokon_X01_Cmf_DW.u16COUNT_Sensor_Delay = 0U;

  /* End of SystemInitialize for SubSystem: '<S12>/JudgeFlag_Sensor_Ready' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/IntakeCal' */
  /* SystemInitialize for Atomic SubSystem: '<S13>/Intake_Auto_Calculation' */
  /* SystemInitialize for Atomic SubSystem: '<S94>/Hyster_Judge' */
  Sokon_X01_Cmf_Hyster_Judge_Init(&Sokon_X01_Cmf_DW.Hyster_Judge,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S94>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S94>/Hyster_Judge1' */
  Sokon_X01_Cmf_Hyster_Judge_Init(&Sokon_X01_Cmf_DW.Hyster_Judge1,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S94>/Hyster_Judge1' */
  /* End of SystemInitialize for SubSystem: '<S13>/Intake_Auto_Calculation' */

  /* SystemInitialize for Atomic SubSystem: '<S13>/Intake_Auto_Calculation_For_Sokon_X1_Feature' */
  /* SystemInitialize for Atomic SubSystem: '<S95>/Hyster_Judge2' */
  Sokon_X01_Cmf_Hyster_Judge2_Init(&Sokon_X01_Cmf_DW.Hyster_Judge2,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S95>/Hyster_Judge2' */

  /* SystemInitialize for Atomic SubSystem: '<S95>/Hyster_Judge4' */
  Sokon_X01_Cmf_Hyster_Judge2_Init(&Sokon_X01_Cmf_DW.Hyster_Judge4,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S95>/Hyster_Judge4' */

  /* SystemInitialize for Atomic SubSystem: '<S95>/Hyster_Judge1' */
  Sokon_X01_Cmf_Hyster_Judge1_Init(&Sokon_X01_Cmf_DW.Hyster_Judge1_b,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S95>/Hyster_Judge1' */
  /* End of SystemInitialize for SubSystem: '<S13>/Intake_Auto_Calculation_For_Sokon_X1_Feature' */

  /* SystemInitialize for Atomic SubSystem: '<S13>/Intake_Auto_Manual_Management' */
  /* SystemInitialize for Atomic SubSystem: '<S126>/FlagHoldModule' */
  Sokon_X01_Cmf_FlagHoldModule_Init(&Sokon_X01_Cmf_DW.FlagHoldModule,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S126>/FlagHoldModule' */

  /* SystemInitialize for Atomic SubSystem: '<S126>/Hyster_Judge' */
  Sokon_X01_Cmf_Hyster_Judge_d_Init(&Sokon_X01_Cmf_DW.Hyster_Judge_l,
    Sokon_X01_Cmf_ConstP.pooled4);

  /* End of SystemInitialize for SubSystem: '<S126>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S126>/CntModule_Cfg' */
  Sokon_X01_Cmf_CntModule_Cfg_Init(&Sokon_X01_Cmf_DW.CntModule_Cfg, 1U);

  /* End of SystemInitialize for SubSystem: '<S126>/CntModule_Cfg' */
  /* End of SystemInitialize for SubSystem: '<S13>/Intake_Auto_Manual_Management' */
  /* End of SystemInitialize for SubSystem: '<S4>/IntakeCal' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/BlowerCal' */
  /* SystemInitialize for Atomic SubSystem: '<S9>/CMF_Blower_Auto_Cal' */
  /* SystemInitialize for Atomic SubSystem: '<S21>/DelayJudge' */
  Sokon_X01_Cmf_DelayJudge_Init(&Sokon_X01_Cmf_DW.DelayJudge);

  /* End of SystemInitialize for SubSystem: '<S21>/DelayJudge' */
  /* End of SystemInitialize for SubSystem: '<S9>/CMF_Blower_Auto_Cal' */
  /* End of SystemInitialize for SubSystem: '<S4>/BlowerCal' */
}

/* Start for referenced model: 'Sokon_X01_Cmf' */
void Sokon_X01_Cmf_Start(uint8_T *rty_CmfO_u8HVACMode_Req, uint8_T
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
  *rty_CmfO_s16Debug_TasdRSolarCmp_A10)
{
  /* Start for InitialCondition: '<Root>/IC' */
  Sokon_X01_Cmf_DW.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC10' */
  Sokon_X01_Cmf_DW.IC10_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC20' */
  Sokon_X01_Cmf_DW.IC20_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC1' */
  Sokon_X01_Cmf_DW.IC1_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC21' */
  Sokon_X01_Cmf_DW.IC21_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC14' */
  Sokon_X01_Cmf_DW.IC14_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC17' */
  Sokon_X01_Cmf_DW.IC17_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC44' */
  Sokon_X01_Cmf_DW.IC44_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC45' */
  Sokon_X01_Cmf_DW.IC45_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC42' */
  Sokon_X01_Cmf_DW.IC42_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC18' */
  Sokon_X01_Cmf_DW.IC18_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC19' */
  Sokon_X01_Cmf_DW.IC19_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC35' */
  Sokon_X01_Cmf_DW.IC35_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC5' */
  Sokon_X01_Cmf_DW.IC5_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC40' */
  Sokon_X01_Cmf_DW.IC40_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC41' */
  Sokon_X01_Cmf_DW.IC41_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC46' */
  Sokon_X01_Cmf_DW.IC46_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC47' */
  Sokon_X01_Cmf_DW.IC47_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC48' */
  Sokon_X01_Cmf_DW.IC48_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC24' */
  Sokon_X01_Cmf_DW.IC24_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC25' */
  Sokon_X01_Cmf_DW.IC25_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC26' */
  Sokon_X01_Cmf_DW.IC26_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC39' */
  Sokon_X01_Cmf_DW.IC39_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC78' */
  Sokon_X01_Cmf_DW.IC78_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC58' */
  *rty_CmfO_bFlag_HeatShort_Blw_Req = false;
  Sokon_X01_Cmf_DW.IC58_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC49' */
  *rty_CmfO_u8HVACMode_Req = 0U;
  Sokon_X01_Cmf_DW.IC49_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC50' */
  *rty_CmfO_u8HVACIntake_Req = 100U;
  Sokon_X01_Cmf_DW.IC50_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC51' */
  *rty_CmfO_u8HVACBlwVol_Req_A10 = 0U;
  Sokon_X01_Cmf_DW.IC51_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC52' */
  *rty_CmfO_s16Tasd_Left_Req_A10 = 200;
  Sokon_X01_Cmf_DW.IC52_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC53' */
  *rty_CmfO_s16Tasd_Right_Req_A10 = 200;
  Sokon_X01_Cmf_DW.IC53_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC54' */
  *rty_CmfO_s16TDuct_Left_Out_A10 = 200;
  Sokon_X01_Cmf_DW.IC54_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC55' */
  *rty_CmfO_s16TDuct_Right_Out_A10 = 200;
  Sokon_X01_Cmf_DW.IC55_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC56' */
  *rty_CmfO_u8TevaSet_Req_A10 = 200U;
  Sokon_X01_Cmf_DW.IC56_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC57' */
  *rty_CmfO_s16Tincar_Setting_Req_A10 = 240;
  Sokon_X01_Cmf_DW.IC57_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC59' */
  *rty_CmfO_u16Debug_TasdLStatic_A10 = 0U;
  Sokon_X01_Cmf_DW.IC59_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC60' */
  *rty_CmfO_u16Debug_TasdRStatic_A10 = 0U;
  Sokon_X01_Cmf_DW.IC60_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC61' */
  *rty_CmfO_s16Debug_TasdLSolarCmp_A10 = 0;
  Sokon_X01_Cmf_DW.IC61_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC62' */
  *rty_CmfO_s16Debug_TasdDefCmp_A10 = 0;
  Sokon_X01_Cmf_DW.IC62_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC63' */
  *rty_CmfO_s16Debug_TasdEcoCmp_A10 = 0;
  Sokon_X01_Cmf_DW.IC63_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC64' */
  *rty_CmfO_s16Debug_TasdDyn_A10 = 0;
  Sokon_X01_Cmf_DW.IC64_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC65' */
  *rty_CmfO_u8Debug_BlwStatic_A10 = 0U;
  Sokon_X01_Cmf_DW.IC65_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC66' */
  *rty_CmfO_s8Debug_BlwVspCmp_A10 = 0;
  Sokon_X01_Cmf_DW.IC66_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC67' */
  *rty_CmfO_s8Debug_BlwSolarCmp_A10 = 0;
  Sokon_X01_Cmf_DW.IC67_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC68' */
  *rty_CmfO_s8Debug_BlwDyn_A10 = 0;
  Sokon_X01_Cmf_DW.IC68_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC69' */
  *rty_CmfO_u8Debug_IntkStatic = 0U;
  Sokon_X01_Cmf_DW.IC69_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC70' */
  *rty_CmfO_s8Debug_IntkDyn = 0;
  Sokon_X01_Cmf_DW.IC70_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC71' */
  *rty_CmfO_u8Debug_ModePerStatic = 0U;
  Sokon_X01_Cmf_DW.IC71_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC72' */
  *rty_CmfO_s8Debug_LvlCabHeatCool = 0;
  Sokon_X01_Cmf_DW.IC72_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC73' */
  *rty_CmfO_u8WindExitmodeDisp = 0U;
  Sokon_X01_Cmf_DW.IC73_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC74' */
  *rty_CmfO_u8CabinCoolPrioReq = 0U;
  Sokon_X01_Cmf_DW.IC74_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC75' */
  *rty_CmfO_u8CabinHeatPrioReq = 0U;
  Sokon_X01_Cmf_DW.IC75_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC76' */
  *rty_CmfO_u16Tw_PTCOut_Set_Pre_A10 = 0U;
  Sokon_X01_Cmf_DW.IC76_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC77' */
  *rty_CmfO_s16Debug_TasdRSolarCmp_A10 = 0;
  Sokon_X01_Cmf_DW.IC77_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC4' */
  Sokon_X01_Cmf_DW.IC4_FirstOutputTime = true;
}

/* Output and update for referenced model: 'Sokon_X01_Cmf' */
void Sokon_X01_Cmf(const uint16_T *rtu_CmfI_u16Tset_Left_A10, const uint16_T
                   *rtu_CmfI_u16Tset_Right_A10, const boolean_T *rtu_CmfI_bAcSts,
                   const uint8_T *rtu_CmfI_u8BlwMASts, const uint8_T
                   *rtu_CmfI_u8ModeMASts, const uint8_T *rtu_CmfI_u8IntakeMASts,
                   const uint16_T *rtu_CmfI_u16P_Ref_CondOut_A10, const uint16_T
                   *rtu_CmfI_u16Sun_L, const uint16_T *rtu_CmfI_u16Sun_R, const
                   int16_T *rtu_CmfI_s16Tamb_A10, const int16_T
                   *rtu_CmfI_s16Tincar_Front_A10, const int16_T
                   *rtu_CmfI_s16TDuct_LV_A10, const int16_T
                   *rtu_CmfI_s16TDuct_LF_A10, const int16_T
                   *rtu_CmfI_s16TDuct_RV_A10, const uint8_T
                   *rtu_CmfI_u8ModeStatus_Real, const uint8_T
                   *rtu_CmfI_u8IntakePerc_Real, const uint8_T
                   *rtu_CmfI_u8HVACSts, const uint8_T *rtu_CmfI_u8VehSpd, const
                   boolean_T *rtu_CmfI_bEco_Model_Set, const uint8_T
                   *rtu_CmfI_u8IgnSts, const int16_T
                   *rtu_CmfI_s16T_Wat_HVCHOut_A10, const uint8_T
                   *rtu_CmfI_u8BAT_CoolLv, const uint16_T *rtu_CmfI_u16Ncomp,
                   const uint8_T *rtu_CmfI_u8Mix_Flap_Position_L, const uint8_T *
                   rtu_CmfI_u8HpWorkMode, uint8_T *rty_CmfO_u8HVACMode_Req,
                   uint8_T *rty_CmfO_u8HVACIntake_Req, uint8_T
                   *rty_CmfO_u8HVACBlwVol_Req_A10, int16_T
                   *rty_CmfO_s16Tasd_Left_Req_A10, int16_T
                   *rty_CmfO_s16Tasd_Right_Req_A10, int16_T
                   *rty_CmfO_s16TDuct_Left_Out_A10, int16_T
                   *rty_CmfO_s16TDuct_Right_Out_A10, uint8_T
                   *rty_CmfO_u8TevaSet_Req_A10, int16_T
                   *rty_CmfO_s16Tincar_Setting_Req_A10, boolean_T
                   *rty_CmfO_bFlag_HeatShort_Blw_Req, uint16_T
                   *rty_CmfO_u16Debug_TasdLStatic_A10, uint16_T
                   *rty_CmfO_u16Debug_TasdRStatic_A10, int16_T
                   *rty_CmfO_s16Debug_TasdLSolarCmp_A10, int16_T
                   *rty_CmfO_s16Debug_TasdDefCmp_A10, int16_T
                   *rty_CmfO_s16Debug_TasdEcoCmp_A10, int16_T
                   *rty_CmfO_s16Debug_TasdDyn_A10, uint8_T
                   *rty_CmfO_u8Debug_BlwStatic_A10, int8_T
                   *rty_CmfO_s8Debug_BlwVspCmp_A10, int8_T
                   *rty_CmfO_s8Debug_BlwSolarCmp_A10, int8_T
                   *rty_CmfO_s8Debug_BlwDyn_A10, uint8_T
                   *rty_CmfO_u8Debug_IntkStatic, int8_T
                   *rty_CmfO_s8Debug_IntkDyn, uint8_T
                   *rty_CmfO_u8Debug_ModePerStatic, int8_T
                   *rty_CmfO_s8Debug_LvlCabHeatCool, uint8_T
                   *rty_CmfO_u8WindExitmodeDisp, uint8_T
                   *rty_CmfO_u8CabinCoolPrioReq, uint8_T
                   *rty_CmfO_u8CabinHeatPrioReq, uint16_T
                   *rty_CmfO_u16Tw_PTCOut_Set_Pre_A10, int16_T
                   *rty_CmfO_s16Debug_TasdRSolarCmp_A10)
{
  uint16_T rtb_CmfI_u16Tset_Ave_A10;
  uint16_T rtb_CmfI_u16Tset_Left_A10;
  uint8_T rtb_Switch_i;
  uint8_T rtb_CmfI_u8ModeMASts;
  int16_T rtb_CmfI_s16TDuct_LV_A10;
  int16_T rtb_CmfI_s16Tamb_A10;
  uint16_T rtb_CmfI_u16Tset_Right_A10;
  uint16_T rtb_Saturation57;
  int16_T rtb_CmfI_s16Tincar_Front_A10;
  uint8_T rtb_CmfI_u8IntakeMASts;
  uint16_T rtb_CmfI_u16P_Ref_CondOut_A10;
  uint8_T rtb_CmfI_u8IgnSts;
  int16_T rtb_CmfI_s16T_Wat_HVCHOut_A10;
  boolean_T rtb_IC42;
  uint16_T rtb_CmfI_u16Sun_L;
  uint16_T rtb_CmfI_u16Sun_R;
  uint8_T rtb_CmfI_u8ModeStatus_Real;
  uint8_T rtb_CmfI_u8BlwMASts;
  uint8_T rtb_IC40;
  uint8_T rtb_CmfI_u8BAT_CoolLv;
  uint16_T rtb_CmfI_u16Ncomp;
  uint8_T rtb_CmfI_u8Mix_Flap_Position_L;
  int16_T rtb_Switch1;
  int16_T rtb_Switch3;
  int16_T rtb_Saturation74;
  uint8_T rtb_Saturation70;
  boolean_T rtb_Compare_iy;
  int8_T rtb_Saturation69;
  boolean_T rtb_Compare_ez;
  boolean_T rtb_LogicalOperator1_i;
  int16_T rtb_Cmf_s16TasdLStatic;
  int16_T rtb_Switch_cvp;
  int16_T rtb_Switch;
  int16_T rtb_CMF_s16Tasd_Solar_CMP_Table;
  int16_T rtb_Cmf_s16TasdRStatic;
  int16_T rtb_CmfO_s16Tasd_Right_Req_A10_d;
  uint16_T rtb_Saturation;
  uint8_T rtb_CmfO_u8TevaSet_Req_A10_f;
  int8_T rtb_Cmf_s8LVL_CabHeatCooling;
  uint8_T rtb_Switch2;
  uint16_T rtb_CmfO_u16Debug_TasdLStatic_A10_k;
  int16_T rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k;
  boolean_T rtb_SignalCopy;
  int8_T rtb_CMF_s8Blw_VSP_Comp_Table;
  int8_T rtb_CMF_s8Blw_Dyn_Y_Table;
  boolean_T rtb_Conversion_n;
  boolean_T rtb_Conversion_p;
  boolean_T rtb_Conversion_g;
  uint8_T rtb_Switch_g;
  boolean_T rtb_Switch2_py;
  boolean_T rtb_Conversion_ah;
  uint8_T rtb_Conversion_m;
  boolean_T rtb_Switch2_h;
  boolean_T rtb_Switch2_c1;
  boolean_T rtb_Switch2_i;
  boolean_T rtb_Switch2_n;
  boolean_T rtb_Switch2_c;
  boolean_T rtb_Switch2_mv;
  uint8_T rtb_Switch5;
  int16_T rtb_Cmf_s16T_SysIncar_Delta;
  uint8_T rtb_Conversion_ch;
  uint32_T rtb_Conversion;
  int16_T rtb_R134A_P_a100_T_a10_Table;
  boolean_T rtb_Compare_nq;
  int32_T u0;

  /* InitialCondition: '<Root>/IC' */
  if (Sokon_X01_Cmf_DW.IC_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC_FirstOutputTime = false;
    rtb_CmfI_u16Tset_Ave_A10 = 240U;
  } else {
    rtb_CmfI_u16Tset_Ave_A10 = *rtu_CmfI_u16Tset_Left_A10;
  }

  /* End of InitialCondition: '<Root>/IC' */

  /* Saturate: '<Root>/Saturation' */
  if (((int32_T)rtb_CmfI_u16Tset_Ave_A10) > 330) {
    rtb_CmfI_u16Tset_Left_A10 = 330U;
  } else if (((int32_T)rtb_CmfI_u16Tset_Ave_A10) < 180) {
    rtb_CmfI_u16Tset_Left_A10 = 180U;
  } else {
    rtb_CmfI_u16Tset_Left_A10 = rtb_CmfI_u16Tset_Ave_A10;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* InitialCondition: '<Root>/IC10' */
  if (Sokon_X01_Cmf_DW.IC10_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC10_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8ModeMASts;
  }

  /* End of InitialCondition: '<Root>/IC10' */

  /* Saturate: '<Root>/Saturation9' */
  if (((int32_T)rtb_Switch_i) < 7) {
    rtb_CmfI_u8ModeMASts = rtb_Switch_i;
  } else {
    rtb_CmfI_u8ModeMASts = 7U;
  }

  /* End of Saturate: '<Root>/Saturation9' */

  /* InitialCondition: '<Root>/IC20' */
  if (Sokon_X01_Cmf_DW.IC20_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC20_FirstOutputTime = false;
    rtb_CmfI_s16TDuct_LV_A10 = 200;
  } else {
    rtb_CmfI_s16TDuct_LV_A10 = *rtu_CmfI_s16Tamb_A10;
  }

  /* End of InitialCondition: '<Root>/IC20' */

  /* Saturate: '<Root>/Saturation19' */
  rtb_CmfI_s16Tamb_A10 = rtb_CmfI_s16TDuct_LV_A10;
  if (rtb_CmfI_s16Tamb_A10 > 1500) {
    rtb_CmfI_s16Tamb_A10 = 1500;
  } else {
    if (rtb_CmfI_s16Tamb_A10 < -500) {
      rtb_CmfI_s16Tamb_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation19' */

  /* InitialCondition: '<Root>/IC1' */
  if (Sokon_X01_Cmf_DW.IC1_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC1_FirstOutputTime = false;
    rtb_CmfI_u16Tset_Ave_A10 = 240U;
  } else {
    rtb_CmfI_u16Tset_Ave_A10 = *rtu_CmfI_u16Tset_Right_A10;
  }

  /* End of InitialCondition: '<Root>/IC1' */

  /* Saturate: '<Root>/Saturation1' */
  if (((int32_T)rtb_CmfI_u16Tset_Ave_A10) > 330) {
    rtb_CmfI_u16Tset_Right_A10 = 330U;
  } else if (((int32_T)rtb_CmfI_u16Tset_Ave_A10) < 180) {
    rtb_CmfI_u16Tset_Right_A10 = 180U;
  } else {
    rtb_CmfI_u16Tset_Right_A10 = rtb_CmfI_u16Tset_Ave_A10;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Sum: '<S227>/Sum' incorporates:
   *  Sum: '<S217>/Sum'
   */
  rtb_Conversion = ((uint32_T)rtb_CmfI_u16Tset_Left_A10) + ((uint32_T)
    rtb_CmfI_u16Tset_Right_A10);

  /* Lookup_n-D: '<S226>/Cmf_s8LVL_CabHeatCoolingTab' incorporates:
   *  Constant: '<S227>/Average_Cal'
   *  Product: '<S227>/Product'
   *  Sum: '<S227>/Sum'
   */
  rtb_Cmf_s8LVL_CabHeatCooling = look2_iu16s16lu16n8ts8Ds16ds16_binlcn((uint16_T)
    (rtb_Conversion / ((uint32_T)THM_u8CONST_2)), rtb_CmfI_s16Tamb_A10,
    ((uint16_T *)&(Thm_s8LVL_CabHeat.Thm_u16Tset[0])), ((int16_T *)
    &(Thm_s8LVL_CabHeat.Thm_s16Tamb[0])), ((int8_T *)
    &(Thm_s8LVL_CabHeat.Thm_s8LVL_CabHeat_y[0])), Sokon_X01_Cmf_ConstP.pooled10,
    10U);

  /* InitialCondition: '<Root>/IC21' */
  if (Sokon_X01_Cmf_DW.IC21_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC21_FirstOutputTime = false;
    rtb_CmfI_s16TDuct_LV_A10 = 200;
  } else {
    rtb_CmfI_s16TDuct_LV_A10 = *rtu_CmfI_s16Tincar_Front_A10;
  }

  /* End of InitialCondition: '<Root>/IC21' */

  /* Saturate: '<Root>/Saturation20' */
  rtb_CmfI_s16Tincar_Front_A10 = rtb_CmfI_s16TDuct_LV_A10;
  if (rtb_CmfI_s16Tincar_Front_A10 > 1500) {
    rtb_CmfI_s16Tincar_Front_A10 = 1500;
  } else {
    if (rtb_CmfI_s16Tincar_Front_A10 < -500) {
      rtb_CmfI_s16Tincar_Front_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation20' */

  /* InitialCondition: '<Root>/IC14' */
  if (Sokon_X01_Cmf_DW.IC14_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC14_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8IntakeMASts;
  }

  /* End of InitialCondition: '<Root>/IC14' */

  /* Saturate: '<Root>/Saturation13' */
  if (((int32_T)rtb_Switch_i) < 3) {
    rtb_CmfI_u8IntakeMASts = rtb_Switch_i;
  } else {
    rtb_CmfI_u8IntakeMASts = 3U;
  }

  /* End of Saturate: '<Root>/Saturation13' */

  /* InitialCondition: '<Root>/IC17' */
  if (Sokon_X01_Cmf_DW.IC17_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC17_FirstOutputTime = false;
    rtb_Saturation57 = 150U;
  } else {
    rtb_Saturation57 = *rtu_CmfI_u16P_Ref_CondOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC17' */

  /* Saturate: '<Root>/Saturation16' */
  rtb_CmfI_u16P_Ref_CondOut_A10 = rtb_Saturation57;
  if (((int32_T)rtb_CmfI_u16P_Ref_CondOut_A10) >= 400) {
    rtb_CmfI_u16P_Ref_CondOut_A10 = 400U;
  }

  /* End of Saturate: '<Root>/Saturation16' */

  /* InitialCondition: '<Root>/IC44' */
  if (Sokon_X01_Cmf_DW.IC44_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC44_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8IgnSts;
  }

  /* End of InitialCondition: '<Root>/IC44' */

  /* Saturate: '<Root>/Saturation42' */
  if (((int32_T)rtb_Switch_i) < 7) {
    rtb_CmfI_u8IgnSts = rtb_Switch_i;
  } else {
    rtb_CmfI_u8IgnSts = 7U;
  }

  /* End of Saturate: '<Root>/Saturation42' */

  /* InitialCondition: '<Root>/IC45' */
  if (Sokon_X01_Cmf_DW.IC45_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC45_FirstOutputTime = false;
    rtb_CmfI_s16TDuct_LV_A10 = 200;
  } else {
    rtb_CmfI_s16TDuct_LV_A10 = *rtu_CmfI_s16T_Wat_HVCHOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC45' */

  /* Saturate: '<Root>/Saturation43' */
  rtb_CmfI_s16T_Wat_HVCHOut_A10 = rtb_CmfI_s16TDuct_LV_A10;
  if (rtb_CmfI_s16T_Wat_HVCHOut_A10 > 1500) {
    rtb_CmfI_s16T_Wat_HVCHOut_A10 = 1500;
  } else {
    if (rtb_CmfI_s16T_Wat_HVCHOut_A10 < -500) {
      rtb_CmfI_s16T_Wat_HVCHOut_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation43' */

  /* InitialCondition: '<Root>/IC42' */
  if (Sokon_X01_Cmf_DW.IC42_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC42_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = *rtu_CmfI_bEco_Model_Set;
  }

  /* End of InitialCondition: '<Root>/IC42' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_1' */
  rtb_Compare_ez = ( Sokon_X01_Cmf_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_1' */

  /* InitialCondition: '<Root>/IC18' */
  if (Sokon_X01_Cmf_DW.IC18_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC18_FirstOutputTime = false;
    rtb_Saturation57 = 0U;
  } else {
    rtb_Saturation57 = *rtu_CmfI_u16Sun_L;
  }

  /* End of InitialCondition: '<Root>/IC18' */

  /* Saturate: '<Root>/Saturation17' */
  rtb_CmfI_u16Sun_L = rtb_Saturation57;
  if (((int32_T)rtb_CmfI_u16Sun_L) >= 1275) {
    rtb_CmfI_u16Sun_L = 1275U;
  }

  /* End of Saturate: '<Root>/Saturation17' */

  /* InitialCondition: '<Root>/IC19' */
  if (Sokon_X01_Cmf_DW.IC19_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC19_FirstOutputTime = false;
    rtb_Saturation57 = 0U;
  } else {
    rtb_Saturation57 = *rtu_CmfI_u16Sun_R;
  }

  /* End of InitialCondition: '<Root>/IC19' */

  /* Saturate: '<Root>/Saturation18' */
  rtb_CmfI_u16Sun_R = rtb_Saturation57;
  if (((int32_T)rtb_CmfI_u16Sun_R) >= 1275) {
    rtb_CmfI_u16Sun_R = 1275U;
  }

  /* End of Saturate: '<Root>/Saturation18' */

  /* InitialCondition: '<Root>/IC35' */
  if (Sokon_X01_Cmf_DW.IC35_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC35_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8ModeStatus_Real;
  }

  /* End of InitialCondition: '<Root>/IC35' */

  /* Saturate: '<Root>/Saturation34' */
  if (((int32_T)rtb_Switch_i) < 7) {
    rtb_CmfI_u8ModeStatus_Real = rtb_Switch_i;
  } else {
    rtb_CmfI_u8ModeStatus_Real = 7U;
  }

  /* End of Saturate: '<Root>/Saturation34' */

  /* Lookup_n-D: '<S215>/Thm_s16Tast_L_Table' */
  rtb_Cmf_s16TasdLStatic = look2_iu16s16lu32n16ts16Ds32ds32_binlcn
    (rtb_CmfI_u16Tset_Left_A10, rtb_CmfI_s16Tamb_A10, ((uint16_T *)
      &(Thm_s16Tast.Thm_u16Tset[0])), ((int16_T *)&(Thm_s16Tast.Thm_s16Tamb[0])),
     ((int16_T *)&(Thm_s16Tast.Thm_s16Tast_y[0])), Sokon_X01_Cmf_ConstP.pooled14,
     10U);

  /* Lookup_n-D: '<S215>/Thm_s16Tast_R_Table' */
  rtb_Cmf_s16TasdRStatic = look2_iu16s16lu32n16ts16Ds32ds32_binlcn
    (rtb_CmfI_u16Tset_Right_A10, rtb_CmfI_s16Tamb_A10, ((uint16_T *)
      &(Thm_s16Tast.Thm_u16Tset[0])), ((int16_T *)&(Thm_s16Tast.Thm_s16Tamb[0])),
     ((int16_T *)&(Thm_s16Tast.Thm_s16Tast_y[0])), Sokon_X01_Cmf_ConstP.pooled14,
     10U);

  /* Sum: '<S217>/Sum' */
  rtb_Saturation57 = (uint16_T)rtb_Conversion;

  /* Product: '<S217>/Product' incorporates:
   *  Constant: '<S217>/Average_Cal'
   */
  rtb_CmfI_u16Tset_Ave_A10 = (uint16_T)(((uint32_T)rtb_Saturation57) /
    ((uint32_T)THM_u8CONST_2));

  /* Lookup_n-D: '<S215>/Thm_s16TSYS_Table' */
  rtb_CmfI_s16TDuct_LV_A10 = look2_iu16s16lu32n16ts16Ds32ds32_binlcn
    (rtb_CmfI_u16Tset_Ave_A10, rtb_CmfI_s16Tamb_A10, ((uint16_T *)
      &(Thm_s16Tsys.Thm_u16Tset[0])), ((int16_T *)&(Thm_s16Tsys.Thm_s16Tamb[0])),
     ((int16_T *)&(Thm_s16Tsys.Thm_s16Tsys_y[0])), Sokon_X01_Cmf_ConstP.pooled10,
     10U);

  /* Sum: '<S215>/Sum1' */
  rtb_Cmf_s16T_SysIncar_Delta = (int16_T)(rtb_CmfI_s16TDuct_LV_A10 -
    rtb_CmfI_s16Tincar_Front_A10);

  /* Outputs for Atomic SubSystem: '<S4>/TasdCal' */
  /* Outputs for Atomic SubSystem: '<S18>/Data Type Conversion' */
  /* Outputs for Atomic SubSystem: '<S4>/IntakeCal' */
  /* SignalConversion: '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  rtb_CmfO_u16Debug_TasdLStatic_A10_k = (uint16_T)
    Sokon_X01_Cmf_DataTypeConversion_p(rtb_Cmf_s16TasdLStatic);

  /* End of Outputs for SubSystem: '<S4>/IntakeCal' */
  /* End of Outputs for SubSystem: '<S18>/Data Type Conversion' */

  /* Outputs for Atomic SubSystem: '<S18>/Data Type Conversion1' */
  rtb_Saturation57 = (uint16_T) Sokon_X01_Cmf_DataTypeConversion_p
    (rtb_Cmf_s16TasdRStatic);

  /* End of Outputs for SubSystem: '<S18>/Data Type Conversion1' */

  /* Lookup_n-D: '<S234>/CMF_s16Tasd_Eco_Comp' */
  rtb_Saturation74 = look1_is8lu32n16ts16Ds32_binlcs
    (rtb_Cmf_s8LVL_CabHeatCooling, ((int8_T *)
      &(Thm_s16Tasd_Eco_Offset.Thm_s8LVL_CabHeat_X[0])), ((int16_T *)
      &(Thm_s16Tasd_Eco_Offset.Thm_s16Tasd_Eco_Offset_y[0])), 7U);

  /* Switch: '<S234>/Switch' incorporates:
   *  Constant: '<S234>/Constant'
   *  RelationalOperator: '<S239>/Compare'
   */
  if (!rtb_Compare_ez) {
    rtb_Switch = THM_s16TASD_NoCompDyn_0;
  } else {
    rtb_Switch = rtb_Saturation74;
  }

  /* End of Switch: '<S234>/Switch' */

  /* Lookup_n-D: '<S235>/TadComp' */
  rtb_Saturation74 = look1_is16lu32n16Ds32_binlcs(rtb_CmfI_s16Tamb_A10,
    ((int16_T *)&(Thm_s16Tasd_Def_Cmp.Thm_s16Tamb[0])), ((int16_T *)
    &(Thm_s16Tasd_Def_Cmp.Thm_s16Tasd_Def_Cmp_y[0])), 10U);

  /* Switch: '<S235>/Switch' incorporates:
   *  Constant: '<S235>/Constant'
   *  Constant: '<S240>/Constant'
   *  RelationalOperator: '<S240>/Compare'
   */
  if (rtb_CmfI_u8ModeMASts == CAL_u8DIS_MODE_DEF) {
    rtb_Switch_cvp = rtb_Saturation74;
  } else {
    rtb_Switch_cvp = THM_s16TASD_NoCompDyn_0;
  }

  /* End of Switch: '<S235>/Switch' */

  /* Outputs for Atomic SubSystem: '<S236>/DataTypeConv_s16_' */
  rtb_Switch3 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16__l
    (rtb_CmfI_u16Tset_Left_A10);

  /* End of Outputs for SubSystem: '<S236>/DataTypeConv_s16_' */

  /* Outputs for Atomic SubSystem: '<S236>/DataTypeConv_s16_1' */
  rtb_Saturation74 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16__l
    (rtb_CmfI_u16Tset_Right_A10);

  /* End of Outputs for SubSystem: '<S236>/DataTypeConv_s16_1' */

  /* Sum: '<S236>/Subtract' */
  rtb_Saturation74 = (int16_T)(rtb_Switch3 - rtb_Saturation74);

  /* Product: '<S236>/Divide' */
  rtb_Switch3 = (int16_T)asr_s32((int32_T)rtb_Saturation74, 2U);

  /* Logic: '<S237>/Logical Operator' incorporates:
   *  Constant: '<S244>/Constant'
   *  Constant: '<S245>/Constant'
   *  RelationalOperator: '<S244>/Compare'
   *  RelationalOperator: '<S245>/Compare'
   */
  rtb_IC42 = ((rtb_CmfI_u8ModeStatus_Real == CAL_u8DIS_MODE_FEET) ||
              (rtb_CmfI_u8ModeStatus_Real == CAL_u8DIS_MODE_FD));

  /* Lookup_n-D: '<S237>/Tasd_SolarCmp' */
  rtb_Saturation74 = look2_iu16s16lu32n16ts16Ds32ds32_binlcn
    (rtb_CmfI_u16Tset_Left_A10, rtb_CmfI_s16Tamb_A10, ((uint16_T *)
      &(Thm_s16Tasd_SolarCmp.Thm_u16Tset[0])), ((int16_T *)
      &(Thm_s16Tasd_SolarCmp.Thm_s16Tamb[0])), ((int16_T *)
      &(Thm_s16Tasd_SolarCmp.Thm_s16Tasd_SolarCmp_y[0])),
     Sokon_X01_Cmf_ConstP.pooled10, 10U);

  /* Lookup_n-D: '<S237>/TasdL_SolarCmp_Coefficient' */
  rtb_Switch1 = look2_iu16s16lu32n16ts16Ds32ds32_binlcs(rtb_CmfI_u16Sun_L,
    rtb_CmfI_s16Tamb_A10, ((uint16_T *)
    &(Thm_s16Tasd_Solar_Cmp_Coefficient.Thm_u16Solar[0])), ((int16_T *)
    &(Thm_s16Tasd_Solar_Cmp_Coefficient.Thm_s16Tamb[0])), ((int16_T *)
    &(Thm_s16Tasd_Solar_Cmp_Coefficient.Thm_s16Tasd_Solar_Cmp_Coefficient_y[0])),
    Sokon_X01_Cmf_ConstP.pooled10, 10U);

  /* Outputs for Atomic SubSystem: '<S237>/IfThenElse' */
  /* Constant: '<S237>/Constant5' incorporates:
   *  Product: '<S237>/Divide'
   *  Product: '<S237>/Multiply'
   */
  rtb_Saturation74 = (int16_T) Sokon_X01_Cmf_IfThenElse_f(rtb_IC42, 0,
    div_nde_s32_floor(((int32_T)rtb_Saturation74) * ((int32_T)rtb_Switch1),
                      (int32_T)
                      Sokon_X01_Cmf_ConstB.DataTypeConv_s16__j.Saturation));

  /* End of Outputs for SubSystem: '<S237>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S237>/DataTypeConv_s16_2' */
  rtb_CmfI_s16TDuct_LV_A10 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16_
    (rtb_Saturation74);

  /* End of Outputs for SubSystem: '<S237>/DataTypeConv_s16_2' */

  /* Outputs for Atomic SubSystem: '<S238>/DataTypeConv_s16_' */
  rtb_Switch1 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16__l
    (rtb_CmfI_u16Tset_Left_A10);

  /* End of Outputs for SubSystem: '<S238>/DataTypeConv_s16_' */

  /* Outputs for Atomic SubSystem: '<S238>/DataTypeConv_s16_1' */
  /* UnitDelay: '<S238>/Unit Delay' */
  rtb_Saturation74 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16__l
    (Sokon_X01_Cmf_DW.UnitDelay_DSTATE);

  /* End of Outputs for SubSystem: '<S238>/DataTypeConv_s16_1' */

  /* Sum: '<S238>/Add' */
  rtb_Saturation74 = (int16_T)(rtb_Switch1 - rtb_Saturation74);

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  Constant: '<S256>/Constant'
   *  Constant: '<S257>/Constant'
   *  Constant: '<S258>/Constant'
   *  Logic: '<S238>/Logical Operator'
   *  RelationalOperator: '<S256>/Compare'
   *  RelationalOperator: '<S257>/Compare'
   *  RelationalOperator: '<S258>/Compare'
   */
  rtb_LogicalOperator1_i = ((rtb_Saturation74 != 0) &&
    ((rtb_CmfI_u8ModeStatus_Real == CAL_u8DIS_MODE_FD) ||
     (rtb_CmfI_u8ModeStatus_Real == CAL_u8DIS_MODE_FEET)));

  /* Outputs for Atomic SubSystem: '<S238>/IfThenElse' */
  /* RelationalOperator: '<S255>/Compare' incorporates:
   *  Constant: '<S238>/Constant3'
   *  Constant: '<S255>/Constant'
   *  Lookup_n-D: '<S238>/Thm_s16Tast_TsetDown_Cmp'
   */
  rtb_Switch1 = (int16_T) Sokon_X01_Cmf_IfThenElse_h(rtb_Saturation74 < 0,
    look2_iu16s16lu16n16ts16Ds32ds32_binlcas(rtb_CmfI_u16Tset_Left_A10,
    rtb_CmfI_s16Tamb_A10, ((uint16_T *)&(Thm_s16Tast_TsetDown_Cmp.Thm_u16Tset[0])),
    ((int16_T *)&(Thm_s16Tast_TsetDown_Cmp.Thm_s16Tamb[0])), ((int16_T *)
    &(Thm_s16Tast_TsetDown_Cmp.Thm_s16Tast_TsetDown_Cmp_y[0])),
    Sokon_X01_Cmf_ConstP.pooled10, 10U), 0);

  /* End of Outputs for SubSystem: '<S238>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S238>/Cal_Divide_10_' */
  /* Product: '<S238>/Divide' */
  rtb_Switch1 = (int16_T) Sokon_X01_Cmf_Cal_Divide_10_((int16_T)
    (rtb_Saturation74 * rtb_Switch1));

  /* End of Outputs for SubSystem: '<S238>/Cal_Divide_10_' */

  /* UnitDelay: '<S238>/Unit Delay1' */
  rtb_Saturation74 = Sokon_X01_Cmf_DW.UnitDelay1_DSTATE;

  /* Outputs for Atomic SubSystem: '<S238>/IfThenElse1' */
  /* Logic: '<S199>/Logical Operator' incorporates:
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S238>/Constant'
   *  RelationalOperator: '<S200>/Compare'
   *  RelationalOperator: '<S201>/Compare'
   *  Sum: '<S238>/Add1'
   *  UnitDelay: '<S199>/Unit Delay'
   */
  rtb_Saturation74 = (int16_T) Sokon_X01_Cmf_IfThenElse_h((((int32_T)
    rtb_CmfI_u8IgnSts) != 0) && (((int32_T)Sokon_X01_Cmf_DW.UnitDelay_DSTATE_j) ==
    0), 0, (int16_T)(rtb_Switch1 + rtb_Saturation74));

  /* End of Outputs for SubSystem: '<S238>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S238>/IfThenElse2' */
  /* Constant: '<S238>/Constant1' */
  rtb_Saturation74 = (int16_T) Sokon_X01_Cmf_IfThenElse_h(rtb_LogicalOperator1_i,
    rtb_Saturation74, 0);

  /* End of Outputs for SubSystem: '<S238>/IfThenElse2' */

  /* Outputs for Atomic SubSystem: '<S238>/FirOrderLinear_Filter' */
  /* UnitDelay: '<S238>/Unit Delay1' incorporates:
   *  Lookup_n-D: '<S238>/Thm_s16Tast_TsetFilFactor_Inc_Cmp'
   */
  Sokon_X01_Cmf_DW.UnitDelay1_DSTATE = (int16_T)
    Sokon_X01_Cmf_FirOrderLinear_Filter_m(rtb_Saturation74,
    rtb_LogicalOperator1_i, look2_iu16s16lu16n16ts16Ds32ds32_binlcas
    (rtb_CmfI_u16Tset_Left_A10, rtb_CmfI_s16Tamb_A10, ((uint16_T *)
    &(Thm_s16Tast_TsetFilFactor_Inc_Cmp.Thm_u16Tset[0])), ((int16_T *)
    &(Thm_s16Tast_TsetFilFactor_Inc_Cmp.Thm_s16Tamb[0])), ((int16_T *)
    &(Thm_s16Tast_TsetFilFactor_Inc_Cmp.Thm_s16Tast_TsetFilFactor_Inc_Cmp_y[0])),
     Sokon_X01_Cmf_ConstP.pooled10, 10U),
    &Sokon_X01_Cmf_ConstB.FirOrderLinear_Filter,
    &Sokon_X01_Cmf_DW.FirOrderLinear_Filter, 100);

  /* End of Outputs for SubSystem: '<S238>/FirOrderLinear_Filter' */

  /* Lookup_n-D: '<S231>/CMF_s16Tasd_Solar_CMP_Table' */
  rtb_CMF_s16Tasd_Solar_CMP_Table = look2_is16lu32n16Ds32ds32_binlcs
    (rtb_Cmf_s16T_SysIncar_Delta, rtb_CmfI_s16Tamb_A10, ((int16_T *)
      &(Thm_s16Tasd_Dyn.Thm_s16TDiff_SysINCar[0])), ((int16_T *)
      &(Thm_s16Tasd_Dyn.Thm_s16Tamb[0])), ((int16_T *)
      &(Thm_s16Tasd_Dyn.Thm_s16Tasd_Dyn_y[0])),
     Sokon_X01_Cmf_ConstP.CMF_s16Tasd_Solar_CMP_Table_maxIndex, 11U);

  /* Sum: '<S232>/Sum' incorporates:
   *  UnitDelay: '<S238>/Unit Delay1'
   */
  rtb_Saturation74 = (int16_T)(((int16_T)(((int16_T)(((int16_T)(((int16_T)
    (((int16_T)(rtb_Cmf_s16TasdLStatic + rtb_CmfI_s16TDuct_LV_A10)) +
     rtb_Switch_cvp)) + rtb_Switch)) + rtb_Switch3)) +
    rtb_CMF_s16Tasd_Solar_CMP_Table)) + Sokon_X01_Cmf_DW.UnitDelay1_DSTATE);

  /* Saturate: '<S232>/Saturation' */
  rtb_Cmf_s16TasdLStatic = rtb_Saturation74;
  if (rtb_Cmf_s16TasdLStatic > THM_s16TASD_UPLIM) {
    rtb_Cmf_s16TasdLStatic = THM_s16TASD_UPLIM;
  } else {
    if (rtb_Cmf_s16TasdLStatic < 0) {
      rtb_Cmf_s16TasdLStatic = 0;
    }
  }

  /* End of Saturate: '<S232>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S236>/DataTypeConv_s16_2' */
  /* Gain: '<S236>/Gain' */
  rtb_Switch1 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16_2(-32768 * rtb_Switch3);

  /* End of Outputs for SubSystem: '<S236>/DataTypeConv_s16_2' */

  /* Lookup_n-D: '<S237>/Tasd_SolarCmp1' */
  rtb_Saturation74 = look2_iu16s16lu32n16ts16Ds32ds32_binlcn
    (rtb_CmfI_u16Tset_Right_A10, rtb_CmfI_s16Tamb_A10, ((uint16_T *)
      &(Thm_s16Tasd_SolarCmp.Thm_u16Tset[0])), ((int16_T *)
      &(Thm_s16Tasd_SolarCmp.Thm_s16Tamb[0])), ((int16_T *)
      &(Thm_s16Tasd_SolarCmp.Thm_s16Tasd_SolarCmp_y[0])),
     Sokon_X01_Cmf_ConstP.pooled10, 10U);

  /* Lookup_n-D: '<S237>/Tasd_SolarCmp_Coefficient1' */
  rtb_Switch3 = look2_iu16s16lu32n16ts16Ds32ds32_binlcs(rtb_CmfI_u16Sun_R,
    rtb_CmfI_s16Tamb_A10, ((uint16_T *)
    &(Thm_s16Tasd_Solar_Cmp_Coefficient.Thm_u16Solar[0])), ((int16_T *)
    &(Thm_s16Tasd_Solar_Cmp_Coefficient.Thm_s16Tamb[0])), ((int16_T *)
    &(Thm_s16Tasd_Solar_Cmp_Coefficient.Thm_s16Tasd_Solar_Cmp_Coefficient_y[0])),
    Sokon_X01_Cmf_ConstP.pooled10, 10U);

  /* Outputs for Atomic SubSystem: '<S237>/IfThenElse1' */
  /* Constant: '<S237>/Constant2' incorporates:
   *  Product: '<S237>/Divide1'
   *  Product: '<S237>/Multiply1'
   */
  rtb_Saturation74 = (int16_T) Sokon_X01_Cmf_IfThenElse_f(rtb_IC42, 0,
    div_nde_s32_floor(((int32_T)rtb_Saturation74) * ((int32_T)rtb_Switch3),
                      (int32_T)
                      Sokon_X01_Cmf_ConstB.DataTypeConv_s16_1_i.Saturation));

  /* End of Outputs for SubSystem: '<S237>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S237>/DataTypeConv_s16_3' */
  rtb_Switch3 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16_(rtb_Saturation74);

  /* End of Outputs for SubSystem: '<S237>/DataTypeConv_s16_3' */

  /* Sum: '<S232>/Sum1' incorporates:
   *  UnitDelay: '<S238>/Unit Delay1'
   */
  rtb_Saturation74 = (int16_T)(((int16_T)(((int16_T)(((int16_T)(((int16_T)
    (((int16_T)(rtb_Cmf_s16TasdRStatic + rtb_Switch3)) + rtb_Switch_cvp)) +
    rtb_Switch)) + rtb_Switch1)) + rtb_CMF_s16Tasd_Solar_CMP_Table)) +
    Sokon_X01_Cmf_DW.UnitDelay1_DSTATE);

  /* Saturate: '<S232>/Saturation1' */
  rtb_CmfO_s16Tasd_Right_Req_A10_d = rtb_Saturation74;
  if (rtb_CmfO_s16Tasd_Right_Req_A10_d > THM_s16TASD_UPLIM) {
    rtb_CmfO_s16Tasd_Right_Req_A10_d = THM_s16TASD_UPLIM;
  } else {
    if (rtb_CmfO_s16Tasd_Right_Req_A10_d < 0) {
      rtb_CmfO_s16Tasd_Right_Req_A10_d = 0;
    }
  }

  /* End of Saturate: '<S232>/Saturation1' */

  /* Update for UnitDelay: '<S238>/Unit Delay' */
  Sokon_X01_Cmf_DW.UnitDelay_DSTATE = rtb_CmfI_u16Tset_Left_A10;

  /* End of Outputs for SubSystem: '<S4>/TasdCal' */

  /* InitialCondition: '<Root>/IC5' */
  if (Sokon_X01_Cmf_DW.IC5_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC5_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8BlwMASts;
  }

  /* End of InitialCondition: '<Root>/IC5' */

  /* Saturate: '<Root>/Saturation4' */
  if (((int32_T)rtb_Switch_i) < 15) {
    rtb_CmfI_u8BlwMASts = rtb_Switch_i;
  } else {
    rtb_CmfI_u8BlwMASts = 15U;
  }

  /* End of Saturate: '<Root>/Saturation4' */

  /* InitialCondition: '<Root>/IC40' */
  if (Sokon_X01_Cmf_DW.IC40_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC40_FirstOutputTime = false;
    rtb_IC40 = 0U;
  } else {
    rtb_IC40 = *rtu_CmfI_u8HVACSts;
  }

  /* End of InitialCondition: '<Root>/IC40' */

  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* Lookup_n-D: '<S19>/Heat_Pickup_Table' */
  rtb_Saturation74 = look1_is16lu32n16Ds32_binlcs(rtb_CmfI_s16T_Wat_HVCHOut_A10,
    ((int16_T *)&(Thm_s16Toffset_EVA_SET.Thm_s16TWAT_ICDS_X[0])), ((int16_T *)
    &(Thm_s16Toffset_EVA_SET.Thm_s16Toffset_EVA_SET_y[0])), 7U);

  /* MinMax: '<S19>/Max' */
  if (rtb_Cmf_s16TasdLStatic < rtb_CmfO_s16Tasd_Right_Req_A10_d) {
    rtb_Cmf_s16TasdRStatic = rtb_Cmf_s16TasdLStatic;
  } else {
    rtb_Cmf_s16TasdRStatic = rtb_CmfO_s16Tasd_Right_Req_A10_d;
  }

  /* End of MinMax: '<S19>/Max' */

  /* Sum: '<S19>/Sum' incorporates:
   *  Lookup_n-D: '<S19>/TevaSetCompensationByTamb'
   */
  rtb_Saturation74 = (int16_T)(((int16_T)(rtb_Cmf_s16TasdRStatic -
    rtb_Saturation74)) - look1_is16lu32n16Ds32_binlcs(rtb_CmfI_s16Tamb_A10,
    Sokon_X01_Cmf_ConstP.TevaSetCompensationByTamb_bp01Data,
    Sokon_X01_Cmf_ConstP.TevaSetCompensationByTamb_tableData, 3U));

  /* MinMax: '<S19>/Max2' incorporates:
   *  Constant: '<S19>/Teva_Setting_Offset_From_Tamb'
   *  Sum: '<S19>/Sum1'
   */
  rtb_Cmf_s16TasdRStatic = rtb_Saturation74;
  rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k = (int16_T)(rtb_CmfI_s16Tamb_A10 - 50);
  if (rtb_Cmf_s16TasdRStatic < rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k) {
    rtb_Saturation74 = rtb_Cmf_s16TasdRStatic;
  } else {
    rtb_Saturation74 = rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k;
  }

  /* End of MinMax: '<S19>/Max2' */

  /* RelationalOperator: '<S287>/LowerRelop1' incorporates:
   *  Constant: '<S19>/Constant2'
   */
  rtb_IC42 = (rtb_Saturation74 > THM_s16TEVA_SET_MAX);

  /* Switch: '<S287>/Switch' incorporates:
   *  Constant: '<S19>/Constant4'
   *  RelationalOperator: '<S287>/UpperRelop'
   */
  if (rtb_Saturation74 < THM_s16TEVA_SET_MIN) {
    rtb_Saturation74 = THM_s16TEVA_SET_MIN;
  }

  /* End of Switch: '<S287>/Switch' */

  /* Switch: '<S287>/Switch2' incorporates:
   *  Constant: '<S19>/Constant2'
   */
  if (rtb_IC42) {
    rtb_Saturation74 = THM_s16TEVA_SET_MAX;
  }

  /* End of Switch: '<S287>/Switch2' */

  /* Switch: '<S19>/Switch2' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S289>/Constant'
   *  Constant: '<S290>/Constant'
   *  Constant: '<S291>/Constant'
   *  Constant: '<S292>/Constant'
   *  Logic: '<S288>/Logical Operator'
   *  Logic: '<S288>/Logical Operator1'
   *  Logic: '<S288>/Logical Operator2'
   *  RelationalOperator: '<S289>/Compare'
   *  RelationalOperator: '<S290>/Compare'
   *  RelationalOperator: '<S291>/Compare'
   *  RelationalOperator: '<S292>/Compare'
   *  RelationalOperator: '<S293>/Compare'
   */
  if ((rtb_CmfI_u8ModeMASts == CAL_u8DIS_MODE_DEF) || (((!rtb_Compare_ez) &&
        (((int32_T)rtb_CmfI_u8BlwMASts) == 7)) && ((rtb_CmfI_u16Tset_Left_A10 ==
         THM_u16TSET_LOW) || (rtb_CmfI_u16Tset_Right_A10 == THM_u16TSET_LOW))))
  {
    rtb_Saturation74 = THM_s16TEVA_SET_MIN;
  }

  /* End of Switch: '<S19>/Switch2' */

  /* Switch: '<S19>/Switch5' incorporates:
   *  Constant: '<S19>/Constant7'
   *  Constant: '<S280>/Constant'
   *  Constant: '<S281>/Constant'
   *  Constant: '<S283>/Constant'
   *  Constant: '<S284>/Constant'
   *  Constant: '<S285>/Constant'
   *  Logic: '<S19>/OR1'
   *  Logic: '<S19>/OR2'
   *  Logic: '<S19>/OR3'
   *  RelationalOperator: '<S280>/Compare'
   *  RelationalOperator: '<S281>/Compare'
   *  RelationalOperator: '<S283>/Compare'
   *  RelationalOperator: '<S284>/Compare'
   *  RelationalOperator: '<S285>/Compare'
   */
  if ((((rtb_IC40 == THM_u8HVAC_STS_OFF) || (rtb_IC40 ==
         THM_u8HVAC_STS_VENTILATE)) || (rtb_IC40 == THM_u8HVAC_STS_OTA)) ||
      ((rtb_CmfI_u8ModeMASts != CAL_u8DIS_MODE_DEF) &&
       (rtb_CmfI_u16Tset_Left_A10 >= THM_u16TSET_HI))) {
    rtb_Cmf_s16TasdRStatic = THM_s16TEVA_SET_STOP;
  } else {
    rtb_Cmf_s16TasdRStatic = rtb_Saturation74;
  }

  /* End of Switch: '<S19>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S19>/Data Type Conversion' */
  /* Outputs for Atomic SubSystem: '<S4>/ModeCal' */
  /* SignalConversion: '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  rtb_CmfO_u8TevaSet_Req_A10_f = (uint8_T) Sokon_X01_Cmf_DataTypeConversion_c
    (rtb_Cmf_s16TasdRStatic);

  /* End of Outputs for SubSystem: '<S19>/Data Type Conversion' */

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  rtb_CmfI_u16Tset_Right_A10 = rtb_Saturation57;

  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* Lookup_n-D: '<S163>/Thm_s16Mode' */
  rtb_Cmf_s16TasdRStatic = look2_iu16s16lu32n16ts16Ds32ds32_binlcn
    (rtb_CmfI_u16Tset_Left_A10, rtb_CmfI_s16Tamb_A10, ((uint16_T *)
      &(Thm_s16Mode_Auto.Thm_u16Tset[0])), ((int16_T *)
      &(Thm_s16Mode_Auto.Thm_s16Tamb[0])), ((int16_T *)
      &(Thm_s16Mode_Auto.Thm_s16Mode_Auto_y[0])), Sokon_X01_Cmf_ConstP.pooled10,
     10U);

  /* Outputs for Atomic SubSystem: '<S167>/Hyster' */
  /* Constant: '<S167>/Constant' incorporates:
   *  Constant: '<S167>/Constant1'
   *  Constant: '<S167>/Constant2'
   *  Constant: '<S167>/Constant3'
   */
  rtb_Conversion_g = ( Sokon_X01_Cmf_Hyster(rtb_Cmf_s16TasdRStatic, 27, 24,
    CmfThm_bConst_1, CmfThm_bConst_0, &Sokon_X01_Cmf_DW.Hyster,
    Sokon_X01_Cmf_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S167>/Hyster' */

  /* Outputs for Atomic SubSystem: '<S167>/Hyster1' */
  /* Constant: '<S167>/Constant5' incorporates:
   *  Constant: '<S167>/Constant6'
   *  Constant: '<S167>/Constant7'
   *  Constant: '<S167>/Constant8'
   */
  rtb_Conversion_p = ( Sokon_X01_Cmf_Hyster(rtb_Cmf_s16TasdRStatic, 17, 14,
    CmfThm_bConst_1, CmfThm_bConst_0, &Sokon_X01_Cmf_DW.Hyster1,
    Sokon_X01_Cmf_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S167>/Hyster1' */

  /* Outputs for Atomic SubSystem: '<S167>/Hyster2' */
  /* Constant: '<S167>/Constant10' incorporates:
   *  Constant: '<S167>/Constant11'
   *  Constant: '<S167>/Constant12'
   *  Constant: '<S167>/Constant13'
   */
  rtb_Conversion_n = ( Sokon_X01_Cmf_Hyster(rtb_Cmf_s16TasdRStatic, 7, 4,
    CmfThm_bConst_1, CmfThm_bConst_0, &Sokon_X01_Cmf_DW.Hyster2,
    Sokon_X01_Cmf_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S167>/Hyster2' */

  /* Switch: '<S167>/Switch2' incorporates:
   *  Constant: '<S167>/Constant14'
   *  Constant: '<S167>/Constant15'
   */
  if (rtb_Conversion_n) {
    rtb_Saturation70 = CAL_u8DIS_MODE_VF;
  } else {
    rtb_Saturation70 = CAL_u8DIS_MODE_VENT;
  }

  /* End of Switch: '<S167>/Switch2' */

  /* Switch: '<S167>/Switch1' incorporates:
   *  Constant: '<S167>/Constant9'
   */
  if (rtb_Conversion_p) {
    rtb_Saturation70 = CAL_u8DIS_MODE_FEET;
  }

  /* End of Switch: '<S167>/Switch1' */

  /* Switch: '<S167>/Switch' incorporates:
   *  Constant: '<S167>/Constant4'
   */
  if (rtb_Conversion_g) {
    rtb_Switch_g = CAL_u8DIS_MODE_FD;
  } else {
    rtb_Switch_g = rtb_Saturation70;
  }

  /* End of Switch: '<S167>/Switch' */

  /* Outputs for Atomic SubSystem: '<S163>/DataTypeConv_s8_' */
  rtb_Saturation69 = (int8_T) Sokon_X01_Cmf_DataTypeConv_s8__n(rtb_Switch_g);

  /* End of Outputs for SubSystem: '<S163>/DataTypeConv_s8_' */

  /* Outputs for Atomic SubSystem: '<S14>/Mode_Auto_Manual_Management' */
  /* Switch: '<S165>/Switch1' incorporates:
   *  Constant: '<S194>/Constant'
   *  RelationalOperator: '<S194>/Compare'
   */
  if (rtb_CmfI_u8ModeMASts != CAL_u8MODE_AUTO_6) {
    rtb_Switch_g = rtb_CmfI_u8ModeMASts;
  } else {
    rtb_Switch_g = (uint8_T)rtb_Saturation69;
  }

  /* End of Switch: '<S165>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S165>/DataTypeConv_u8_' */
  rtb_Saturation70 = (uint8_T) Sokon_X01_Cmf_DataTypeConv_u8__d(rtb_Switch_g);

  /* End of Outputs for SubSystem: '<S165>/DataTypeConv_u8_' */
  /* End of Outputs for SubSystem: '<S14>/Mode_Auto_Manual_Management' */

  /* Outputs for Atomic SubSystem: '<S164>/Hyster_Judge1' */
  rtb_Switch2_h = ( Sokon_X01_Cmf_Hyster_Judge
                   (Sokon_X01_Cmf_ConstB.DataTypeConversion2_dw.Saturation,
                    rtb_Cmf_s8LVL_CabHeatCooling,
                    Sokon_X01_Cmf_ConstB.DataTypeConversion3_g.Saturation,
                    &Sokon_X01_Cmf_DW.Hyster_Judge1_h,
                    Sokon_X01_Cmf_ConstP.pooled3) != false);

  /* End of Outputs for SubSystem: '<S164>/Hyster_Judge1' */

  /* Chart: '<S188>/HeatingStartupWhenLowTwater' */
  if (((int32_T)rtb_CmfI_u8IgnSts) != 0) {
    /*  用户模式为非Standby */
    if ((rtb_CmfI_s16T_Wat_HVCHOut_A10 < 400) &&
        (!Sokon_X01_Cmf_DW.Loc_bFeatEndFlag)) {
      /*  水温如果小于40℃，且此功能在此上电周期内没有结束 */
      if (rtb_Switch2_h) {
        /*  有制热请求 */
        rtb_IC42 = true;

        /* Switch: '<S164>/Switch2' incorporates:
         *  Constant: '<S164>/Constant'
         */
        /*  低热源Mode DEF控制成立 */
        rtb_Switch2 = CAL_u8DIS_MODE_DEF;
      } else {
        rtb_IC42 = false;

        /*  低热源Mode DEF控制释放 */
        /* Switch: '<S164>/Switch2' */
        rtb_Switch2 = rtb_Saturation70;
      }
    } else {
      rtb_IC42 = false;
      Sokon_X01_Cmf_DW.Loc_bFeatEndFlag = true;

      /*  如果水温大于40℃，功能在非Standby周期内上锁，不会二次满足 */
      /* Switch: '<S164>/Switch2' */
      rtb_Switch2 = rtb_Saturation70;
    }
  } else {
    rtb_IC42 = false;
    Sokon_X01_Cmf_DW.Loc_bFeatEndFlag = false;

    /* Standby时，功能锁定解除 */
    /* Switch: '<S164>/Switch2' */
    rtb_Switch2 = rtb_Saturation70;
  }

  /* End of Chart: '<S188>/HeatingStartupWhenLowTwater' */
  /* End of Outputs for SubSystem: '<S4>/ModeCal' */

  /* Outputs for Atomic SubSystem: '<S12>/JudgeFlag_Sensor_Ready' */
  /* Chart: '<S75>/Sensor_Prepare_Delay' */
  if (((int32_T)Sokon_X01_Cmf_DW.u16COUNT_Sensor_Delay) >= 30) {
    rtb_LogicalOperator1_i = true;
  } else {
    rtb_LogicalOperator1_i = false;
    u0 = ((int32_T)Sokon_X01_Cmf_DW.u16COUNT_Sensor_Delay) + 1;
    if (u0 > 65535) {
      u0 = 65535;
    }

    Sokon_X01_Cmf_DW.u16COUNT_Sensor_Delay = (uint16_T)u0;
  }

  /* End of Chart: '<S75>/Sensor_Prepare_Delay' */
  /* End of Outputs for SubSystem: '<S12>/JudgeFlag_Sensor_Ready' */

  /* Outputs for Atomic SubSystem: '<S12>/JudgeFirstIGN' */
  /* Chart: '<S74>/JudgeSWFirstRun' incorporates:
   *  UnitDelay: '<S74>/Unit Delay'
   *
   * Block description for '<S74>/JudgeSWFirstRun':
   *  Judge_first_GetVol
   */
  /* get first IGN ON */
  if (rtb_LogicalOperator1_i) {
    /* SW after 3s */
    if (!Sokon_X01_Cmf_DW.UnitDelay_DSTATE_h2) {
      rtb_Switch_g = SEN_u8CMFSW_FIRST_2;

      /* SW check first, status is 2 */
    } else {
      rtb_Switch_g = SEN_u8CMFSW_READY_1;

      /* SW check ok, status is 1 */
    }
  } else {
    rtb_Switch_g = SEN_u8CMFSW_INIT_0;

    /* SW check inital,status is 0 */
  }

  /* End of Chart: '<S74>/JudgeSWFirstRun' */

  /* Update for UnitDelay: '<S74>/Unit Delay' */
  Sokon_X01_Cmf_DW.UnitDelay_DSTATE_h2 = rtb_LogicalOperator1_i;

  /* End of Outputs for SubSystem: '<S12>/JudgeFirstIGN' */

  /* InitialCondition: '<Root>/IC41' */
  if (Sokon_X01_Cmf_DW.IC41_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC41_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8VehSpd;
  }

  /* End of InitialCondition: '<Root>/IC41' */

  /* Saturate: '<Root>/Saturation40' */
  if (((int32_T)rtb_Switch_i) >= 240) {
    rtb_Switch_i = 240U;
  }

  /* End of Saturate: '<Root>/Saturation40' */

  /* Outputs for Atomic SubSystem: '<S12>/FirOrderLinear_Filter10' */
  /* RelationalOperator: '<S72>/Compare' incorporates:
   *  Constant: '<S12>/Constant15'
   *  Constant: '<S72>/Constant'
   */
  rtb_Conversion_ch = (uint8_T) Sokon_X01_Cmf_FirOrderLinear_Filter(rtb_Switch_i,
    ((int32_T)rtb_Switch_g) == 0, CmfThm_u16Filter_60s,
    &Sokon_X01_Cmf_ConstB.FirOrderLinear_Filter10,
    &Sokon_X01_Cmf_DW.FirOrderLinear_Filter10, 100);

  /* End of Outputs for SubSystem: '<S12>/FirOrderLinear_Filter10' */

  /* InitialCondition: '<Root>/IC46' */
  if (Sokon_X01_Cmf_DW.IC46_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC46_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8BAT_CoolLv;
  }

  /* End of InitialCondition: '<Root>/IC46' */

  /* Saturate: '<Root>/Saturation44' */
  if (((int32_T)rtb_Switch_i) < 15) {
    rtb_CmfI_u8BAT_CoolLv = rtb_Switch_i;
  } else {
    rtb_CmfI_u8BAT_CoolLv = 15U;
  }

  /* End of Saturate: '<Root>/Saturation44' */

  /* InitialCondition: '<Root>/IC47' */
  if (Sokon_X01_Cmf_DW.IC47_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC47_FirstOutputTime = false;
    rtb_Saturation57 = 0U;
  } else {
    rtb_Saturation57 = *rtu_CmfI_u16Ncomp;
  }

  /* End of InitialCondition: '<Root>/IC47' */

  /* Saturate: '<Root>/Saturation45' */
  rtb_CmfI_u16Ncomp = rtb_Saturation57;
  if (((int32_T)rtb_CmfI_u16Ncomp) >= 12700) {
    rtb_CmfI_u16Ncomp = 12700U;
  }

  /* End of Saturate: '<Root>/Saturation45' */

  /* InitialCondition: '<Root>/IC48' */
  if (Sokon_X01_Cmf_DW.IC48_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC48_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8Mix_Flap_Position_L;
  }

  /* End of InitialCondition: '<Root>/IC48' */

  /* Saturate: '<Root>/Saturation46' */
  if (((int32_T)rtb_Switch_i) < 100) {
    rtb_CmfI_u8Mix_Flap_Position_L = rtb_Switch_i;
  } else {
    rtb_CmfI_u8Mix_Flap_Position_L = 100U;
  }

  /* End of Saturate: '<Root>/Saturation46' */

  /* Outputs for Atomic SubSystem: '<S4>/IntakeCal' */
  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* SignalConversion: '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k = rtb_CmfI_s16TDuct_LV_A10;

  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* SignalConversion: '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  rtb_Switch_g = rtb_Saturation70;

  /* Outputs for Atomic SubSystem: '<S13>/Intake_Auto_Calculation' */
  /* Outputs for Atomic SubSystem: '<S94>/Hyster_Judge' */
  rtb_Switch2_c1 = ( Sokon_X01_Cmf_Hyster_Judge
                    (Sokon_X01_Cmf_ConstB.DataTypeConversion_a.Saturation,
                     rtb_Cmf_s8LVL_CabHeatCooling,
                     Sokon_X01_Cmf_ConstB.DataTypeConversion1_in.Saturation,
                     &Sokon_X01_Cmf_DW.Hyster_Judge,
                     Sokon_X01_Cmf_ConstP.pooled3) != false);

  /* End of Outputs for SubSystem: '<S94>/Hyster_Judge' */

  /* Switch: '<S94>/Switch2' incorporates:
   *  Constant: '<S94>/Constant2'
   *  Constant: '<S94>/Constant5'
   */
  if (rtb_Switch2_c1) {
    rtb_Saturation70 = CMF_u8FLAP_INTAK_FRE;
  } else {
    rtb_Saturation70 = CMF_u8FLAP_INTAK_RECY;
  }

  /* End of Switch: '<S94>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S94>/Hyster_Judge1' */
  rtb_Switch2_i = ( Sokon_X01_Cmf_Hyster_Judge
                   (Sokon_X01_Cmf_ConstB.DataTypeConversion2_d.Saturation,
                    rtb_Cmf_s8LVL_CabHeatCooling,
                    Sokon_X01_Cmf_ConstB.DataTypeConversion3_l.Saturation,
                    &Sokon_X01_Cmf_DW.Hyster_Judge1,
                    Sokon_X01_Cmf_ConstP.pooled3) != false);

  /* End of Outputs for SubSystem: '<S94>/Hyster_Judge1' */

  /* Switch: '<S94>/Switch3' incorporates:
   *  Constant: '<S94>/Constant8'
   *  Constant: '<S94>/Constant9'
   */
  if (rtb_Switch2_i) {
    rtb_Switch_i = CMF_u8FLAP_INTAK_TwoLayer;
  } else {
    rtb_Switch_i = CMF_u8FLAP_INTAK_RECY;
  }

  /* End of Switch: '<S94>/Switch3' */

  /* Switch: '<S94>/Switch1' incorporates:
   *  Constant: '<S98>/Constant'
   *  RelationalOperator: '<S98>/Compare'
   */
  if (rtb_CmfI_u16Tset_Left_A10 != THM_u16TSET_LOW) {
    rtb_Saturation70 = rtb_Switch_i;
  }

  /* End of Switch: '<S94>/Switch1' */

  /* Switch: '<S94>/Switch5' incorporates:
   *  Constant: '<S94>/Constant6'
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S99>/Compare'
   */
  if (rtb_CmfI_u16Tset_Left_A10 == THM_u16TSET_HI) {
    rtb_Switch_i = CMF_u8FLAP_INTAK_TwoLayer;
  } else {
    rtb_Switch_i = rtb_Saturation70;
  }

  /* End of Switch: '<S94>/Switch5' */
  /* End of Outputs for SubSystem: '<S13>/Intake_Auto_Calculation' */

  /* Outputs for Atomic SubSystem: '<S13>/Intake_Auto_Calculation_For_Sokon_X1_Feature' */
  /* Outputs for Atomic SubSystem: '<S95>/Hyster_Judge2' */
  rtb_Switch2_n = ( Sokon_X01_Cmf_Hyster_Judge2
                   (Sokon_X01_Cmf_ConstB.DataTypeConv_u8__c.Saturation,
                    rtb_Conversion_ch,
                    Sokon_X01_Cmf_ConstB.DataTypeConv_u8_1.Saturation,
                    &Sokon_X01_Cmf_DW.Hyster_Judge2,
                    Sokon_X01_Cmf_ConstP.pooled3) != false);

  /* End of Outputs for SubSystem: '<S95>/Hyster_Judge2' */

  /* Switch: '<S95>/Switch1' incorporates:
   *  Constant: '<S95>/Constant3'
   *  Constant: '<S95>/Constant8'
   */
  if (rtb_Switch2_n) {
    rtb_Saturation70 = CMF_u8FLAP_INTAK_FRE;
  } else {
    rtb_Saturation70 = 80U;
  }

  /* End of Switch: '<S95>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S95>/Hyster_Judge4' */
  rtb_Switch2_c = ( Sokon_X01_Cmf_Hyster_Judge2
                   (Sokon_X01_Cmf_ConstB.DataTypeConv_u8_4.Saturation,
                    rtb_Conversion_ch,
                    Sokon_X01_Cmf_ConstB.DataTypeConv_u8_5.Saturation,
                    &Sokon_X01_Cmf_DW.Hyster_Judge4,
                    Sokon_X01_Cmf_ConstP.pooled3) != false);

  /* End of Outputs for SubSystem: '<S95>/Hyster_Judge4' */

  /* Switch: '<S95>/Switch3' incorporates:
   *  Constant: '<S95>/Constant6'
   */
  if (!rtb_Switch2_c) {
    rtb_Saturation70 = 60U;
  }

  /* End of Switch: '<S95>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S95>/Hyster_Judge1' */
  rtb_Switch2_mv = ( Sokon_X01_Cmf_Hyster_Judge1
                    (Sokon_X01_Cmf_ConstB.DataTypeConv_s16_1_n.Saturation,
                     rtb_CmfI_s16Tamb_A10,
                     Sokon_X01_Cmf_ConstB.DataTypeConv_s16_.Saturation,
                     &Sokon_X01_Cmf_DW.Hyster_Judge1_b,
                     Sokon_X01_Cmf_ConstP.pooled3) != false);

  /* End of Outputs for SubSystem: '<S95>/Hyster_Judge1' */

  /* Switch: '<S95>/Switch4' */
  if (!rtb_Switch2_mv) {
    rtb_Switch_i = rtb_Saturation70;
  }

  /* End of Switch: '<S95>/Switch4' */
  /* End of Outputs for SubSystem: '<S13>/Intake_Auto_Calculation_For_Sokon_X1_Feature' */

  /* Outputs for Atomic SubSystem: '<S13>/Intake_Manual_Calculation' */
  /* Switch: '<S97>/Switch5' incorporates:
   *  Constant: '<S162>/Constant'
   *  Constant: '<S97>/Constant4'
   *  Constant: '<S97>/Constant5'
   *  RelationalOperator: '<S162>/Compare'
   */
  if (rtb_CmfI_u8IntakeMASts == CAL_u8INTAK_ManualREC_1) {
    rtb_Switch5 = CMF_u8FLAP_INTAK_RECY;
  } else {
    rtb_Switch5 = CMF_u8FLAP_INTAK_FRE;
  }

  /* End of Switch: '<S97>/Switch5' */
  /* End of Outputs for SubSystem: '<S13>/Intake_Manual_Calculation' */

  /* Outputs for Atomic SubSystem: '<S13>/Intake_Auto_Manual_Management' */
  /* Switch: '<S96>/Switch5' incorporates:
   *  Constant: '<S125>/Constant'
   *  RelationalOperator: '<S125>/Compare'
   */
  if (rtb_CmfI_u8IntakeMASts == CAL_u8INTAK_AUTO_3) {
    rtb_Saturation70 = rtb_Switch_i;
  } else {
    rtb_Saturation70 = rtb_Switch5;
  }

  /* End of Switch: '<S96>/Switch5' */

  /* Logic: '<S126>/AND' incorporates:
   *  Constant: '<S131>/Constant'
   *  Constant: '<S132>/Constant'
   *  Constant: '<S133>/Constant'
   *  Constant: '<S134>/Constant'
   *  RelationalOperator: '<S131>/Compare'
   *  RelationalOperator: '<S132>/Compare'
   *  RelationalOperator: '<S133>/Compare'
   *  RelationalOperator: '<S134>/Compare'
   */
  rtb_LogicalOperator1_i = ((((((int32_T)rtb_CmfI_u8Mix_Flap_Position_L) <= 10) &&
    (rtb_CmfI_s16Tincar_Front_A10 > 500)) && (rtb_CmfI_u16Tset_Left_A10 ==
    THM_u16TSET_LOW)) && (((int32_T)rtb_CmfI_u16Ncomp) > 0));

  /* UnitDelay: '<S126>/Unit Delay' */
  rtb_SignalCopy = Sokon_X01_Cmf_DW.UnitDelay_DSTATE_h;

  /* Outputs for Atomic SubSystem: '<S126>/FlagHoldModule' */
  /* Logic: '<S126>/AND1' incorporates:
   *  Logic: '<S126>/NOT'
   *  UnitDelay: '<S126>/Unit Delay'
   */
  rtb_Conversion_ah = ( Sokon_X01_Cmf_FlagHoldModule(rtb_LogicalOperator1_i,
    (!rtb_LogicalOperator1_i) && (Sokon_X01_Cmf_DW.UnitDelay_DSTATE_h),
    &Sokon_X01_Cmf_DW.FlagHoldModule) != false);

  /* End of Outputs for SubSystem: '<S126>/FlagHoldModule' */

  /* Switch: '<S126>/Switch3' incorporates:
   *  Constant: '<S126>/Constant3'
   */
  if (rtb_Conversion_ah) {
    rtb_Saturation70 = CMF_u8FLAP_INTAK_FRE;
  }

  /* End of Switch: '<S126>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S126>/Hyster_Judge' */
  rtb_Switch2_py = ( Sokon_X01_Cmf_Hyster_Judge_l
                    (Sokon_X01_Cmf_ConstB.DataTypeConversion_l.Saturation,
                     rtb_CmfI_u16P_Ref_CondOut_A10,
                     Sokon_X01_Cmf_ConstB.DataTypeConversion1_n.Saturation,
                     &Sokon_X01_Cmf_DW.Hyster_Judge_l,
                     Sokon_X01_Cmf_ConstP.pooled3) != false);

  /* End of Outputs for SubSystem: '<S126>/Hyster_Judge' */

  /* Switch: '<S126>/Switch1' incorporates:
   *  Constant: '<S126>/Constant5'
   *  Constant: '<S130>/Constant'
   *  Constant: '<S139>/Constant'
   *  Constant: '<S140>/Constant'
   *  Logic: '<S126>/Logical Operator'
   *  Logic: '<S126>/Logical Operator1'
   *  Logic: '<S126>/Logical Operator4'
   *  RelationalOperator: '<S130>/Compare'
   *  RelationalOperator: '<S139>/Compare'
   *  RelationalOperator: '<S140>/Compare'
   */
  if (((((int32_T)rtb_CmfI_u16Ncomp) > 0) && rtb_Switch2_py) || ((((int32_T)
         rtb_CmfI_u8BAT_CoolLv) == 2) || (((int32_T)rtb_CmfI_u8BAT_CoolLv) == 3)))
  {
    rtb_Saturation70 = CMF_u8FLAP_INTAK_RECY;
  }

  /* End of Switch: '<S126>/Switch1' */

  /* Switch: '<S126>/Switch2' incorporates:
   *  Constant: '<S126>/Constant2'
   *  Constant: '<S127>/Constant'
   *  Constant: '<S129>/Constant'
   *  Logic: '<S126>/Logical Operator2'
   *  RelationalOperator: '<S127>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   */
  if ((rtb_CmfI_u8ModeMASts == CAL_u8DIS_MODE_DEF) && (rtb_CmfI_u8IntakeMASts ==
       CAL_u8INTAK_ManualFRE_2)) {
    *rty_CmfO_u8HVACIntake_Req = CMF_u8FLAP_INTAK_FRE;
  } else {
    *rty_CmfO_u8HVACIntake_Req = rtb_Saturation70;
  }

  /* End of Switch: '<S126>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S126>/CntModule_Cfg' */
  /* Logic: '<S126>/NOT1' incorporates:
   *  UnitDelay: '<S126>/Unit Delay'
   */
  Sokon_X01_Cmf_CntModule_Cfg(rtb_Conversion_ah, !rtb_Conversion_ah,
    &Sokon_X01_Cmf_DW.UnitDelay_DSTATE_h, &rtb_Conversion,
    &Sokon_X01_Cmf_ConstB.CntModule_Cfg, &Sokon_X01_Cmf_DW.CntModule_Cfg,
    Sokon_X01_Cmf_ConstP.pooled4, 1U);

  /* End of Outputs for SubSystem: '<S126>/CntModule_Cfg' */
  /* End of Outputs for SubSystem: '<S13>/Intake_Auto_Manual_Management' */
  /* End of Outputs for SubSystem: '<S4>/IntakeCal' */

  /* InitialCondition: '<Root>/IC24' */
  if (Sokon_X01_Cmf_DW.IC24_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC24_FirstOutputTime = false;
    rtb_CmfI_s16TDuct_LV_A10 = 200;
  } else {
    rtb_CmfI_s16TDuct_LV_A10 = *rtu_CmfI_s16TDuct_LV_A10;
  }

  /* End of InitialCondition: '<Root>/IC24' */

  /* Saturate: '<Root>/Saturation23' */
  rtb_Cmf_s16TasdRStatic = rtb_CmfI_s16TDuct_LV_A10;
  if (rtb_Cmf_s16TasdRStatic > 1500) {
    rtb_CmfI_s16TDuct_LV_A10 = 1500;
  } else if (rtb_Cmf_s16TasdRStatic < -500) {
    rtb_CmfI_s16TDuct_LV_A10 = -500;
  } else {
    rtb_CmfI_s16TDuct_LV_A10 = rtb_Cmf_s16TasdRStatic;
  }

  /* End of Saturate: '<Root>/Saturation23' */

  /* InitialCondition: '<Root>/IC25' */
  if (Sokon_X01_Cmf_DW.IC25_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC25_FirstOutputTime = false;
    rtb_Switch1 = 200;
  } else {
    rtb_Switch1 = *rtu_CmfI_s16TDuct_LF_A10;
  }

  /* End of InitialCondition: '<Root>/IC25' */

  /* Saturate: '<Root>/Saturation24' */
  rtb_Cmf_s16TasdRStatic = rtb_Switch1;
  if (rtb_Cmf_s16TasdRStatic > 1500) {
    rtb_Switch1 = 1500;
  } else if (rtb_Cmf_s16TasdRStatic < -500) {
    rtb_Switch1 = -500;
  } else {
    rtb_Switch1 = rtb_Cmf_s16TasdRStatic;
  }

  /* End of Saturate: '<Root>/Saturation24' */

  /* Product: '<S202>/Product' incorporates:
   *  Constant: '<S202>/Constant'
   *  Sum: '<S202>/Sum'
   */
  rtb_Saturation74 = (int16_T)div_nde_s32_floor(((int32_T)
    rtb_CmfI_s16TDuct_LV_A10) + ((int32_T)rtb_Switch1), (int32_T)THM_u8CONST_2);

  /* Switch: '<S202>/Switch1' incorporates:
   *  Constant: '<S208>/Constant'
   *  Constant: '<S209>/Constant'
   *  Logic: '<S202>/OR1'
   *  RelationalOperator: '<S208>/Compare'
   *  RelationalOperator: '<S209>/Compare'
   */
  if ((rtb_CmfI_u8ModeStatus_Real != CAL_u8DIS_MODE_FEET) &&
      (rtb_CmfI_u8ModeStatus_Real != CAL_u8DIS_MODE_FD)) {
    rtb_Switch1 = rtb_Saturation74;
  }

  /* End of Switch: '<S202>/Switch1' */

  /* Switch: '<S202>/Switch' incorporates:
   *  Constant: '<S205>/Constant'
   *  Constant: '<S207>/Constant'
   *  Logic: '<S202>/OR'
   *  RelationalOperator: '<S205>/Compare'
   *  RelationalOperator: '<S207>/Compare'
   */
  if ((rtb_CmfI_u8ModeStatus_Real == CAL_u8DIS_MODE_VENT) ||
      (rtb_CmfI_u8ModeStatus_Real == CAL_u8DIS_MODE_DEF)) {
    rtb_CmfI_s16Tincar_Front_A10 = rtb_CmfI_s16TDuct_LV_A10;
  } else {
    rtb_CmfI_s16Tincar_Front_A10 = rtb_Switch1;
  }

  /* End of Switch: '<S202>/Switch' */

  /* InitialCondition: '<Root>/IC26' */
  if (Sokon_X01_Cmf_DW.IC26_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC26_FirstOutputTime = false;
    rtb_Saturation74 = 200;
  } else {
    rtb_Saturation74 = *rtu_CmfI_s16TDuct_RV_A10;
  }

  /* End of InitialCondition: '<Root>/IC26' */

  /* Saturate: '<Root>/Saturation25' */
  rtb_Cmf_s16TasdRStatic = rtb_Saturation74;
  if (rtb_Cmf_s16TasdRStatic > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_Cmf_s16TasdRStatic < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_Cmf_s16TasdRStatic;
  }

  /* End of Saturate: '<Root>/Saturation25' */

  /* Switch: '<S202>/Switch2' */
  rtb_Cmf_s16TasdRStatic = rtb_Saturation74;

  /* InitialCondition: '<Root>/IC39' */
  if (Sokon_X01_Cmf_DW.IC39_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC39_FirstOutputTime = false;
    rtb_Switch_i = 0U;
  } else {
    rtb_Switch_i = *rtu_CmfI_u8IntakePerc_Real;
  }

  /* End of InitialCondition: '<Root>/IC39' */

  /* InitialCondition: '<Root>/IC78' */
  if (Sokon_X01_Cmf_DW.IC78_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC78_FirstOutputTime = false;
    rtb_Saturation70 = 0U;
  } else {
    rtb_Saturation70 = *rtu_CmfI_u8HpWorkMode;
  }

  /* End of InitialCondition: '<Root>/IC78' */

  /* Saturate: '<Root>/Saturation75' */
  rtb_CmfI_u8IntakeMASts = rtb_Saturation70;
  if (((int32_T)rtb_CmfI_u8IntakeMASts) < 128) {
    rtb_Saturation70 = rtb_CmfI_u8IntakeMASts;
  } else {
    rtb_Saturation70 = 128U;
  }

  /* End of Saturate: '<Root>/Saturation75' */

  /* Outputs for Atomic SubSystem: '<S216>/IfThenElse' */
  /* Logic: '<S216>/Logical Operator1' incorporates:
   *  Constant: '<S216>/Constant2'
   *  Constant: '<S216>/Constant3'
   *  Constant: '<S218>/Constant'
   *  Constant: '<S219>/Constant'
   *  Constant: '<S220>/Constant'
   *  Constant: '<S221>/Constant'
   *  Constant: '<S222>/Constant'
   *  RelationalOperator: '<S218>/Compare'
   *  RelationalOperator: '<S219>/Compare'
   *  RelationalOperator: '<S220>/Compare'
   *  RelationalOperator: '<S221>/Compare'
   *  RelationalOperator: '<S222>/Compare'
   */
  rtb_Saturation70 = (uint8_T) Sokon_X01_Cmf_IfThenElse(((((rtb_Saturation70 ==
    CMF_u8MODE_HP_7) || (rtb_Saturation70 == CMF_u8MODE_HP_BatHeat_10)) ||
    (rtb_Saturation70 == CMF_u8MODE_HP_CHILMDCHIL_12)) || (rtb_Saturation70 ==
    CMF_u8MODE_HP_CHIL_8)) || (rtb_Saturation70 == CMF_u8MODE_HP_MDCHIL_9), 11,
    10);

  /* End of Outputs for SubSystem: '<S216>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S216>/DataTypeConv_u8_' */
  /* Product: '<S216>/Divide' incorporates:
   *  Lookup_n-D: '<S215>/Thm_u8VBLW_STATIC_Table'
   *  Product: '<S216>/Multiply'
   */
  rtb_Saturation70 = (uint8_T) Sokon_X01_Cmf_DataTypeConv_u8__g((uint16_T)
    ((((uint32_T)look2_iu16s16lu16n8tu8_binlcne(rtb_CmfI_u16Tset_Ave_A10,
    rtb_CmfI_s16Tamb_A10, ((uint16_T *)&(Thm_u8VBLW_Static.Thm_u16Tset[0])),
    ((int16_T *)&(Thm_u8VBLW_Static.Thm_s16Tamb[0])), ((uint8_T *)
    &(Thm_u8VBLW_Static.Thm_u8VBLW_Static_y[0])), Sokon_X01_Cmf_ConstP.pooled10,
    10U)) * ((uint32_T)rtb_Saturation70)) / 10U));

  /* End of Outputs for SubSystem: '<S216>/DataTypeConv_u8_' */

  /* Saturate: '<S216>/Saturation32' */
  rtb_CmfI_u8ModeStatus_Real = rtb_Saturation70;
  if (((int32_T)rtb_CmfI_u8ModeStatus_Real) >= 70) {
    rtb_CmfI_u8ModeStatus_Real = 70U;
  }

  /* End of Saturate: '<S216>/Saturation32' */

  /* Outputs for Atomic SubSystem: '<S4>/BlowerCal' */
  /* Outputs for Atomic SubSystem: '<S9>/CMF_Blower_Compensation' */
  /* Sum: '<S22>/Sum1' */
  rtb_Saturation = (uint16_T)(((uint32_T)rtb_CmfI_u16Sun_L) + ((uint32_T)
    rtb_CmfI_u16Sun_R));

  /* Outputs for Atomic SubSystem: '<S22>/DataTypeConv_u16_' */
  /* Product: '<S22>/Product1' incorporates:
   *  Constant: '<S22>/Constant1'
   */
  rtb_Saturation = (uint16_T) Sokon_X01_Cmf_DataTypeConv_u16_((uint16_T)
    (((uint32_T)rtb_Saturation) / ((uint32_T)THM_u8CONST_2)));

  /* End of Outputs for SubSystem: '<S22>/DataTypeConv_u16_' */

  /* Sum: '<S22>/Sum' incorporates:
   *  Switch: '<S202>/Switch2'
   */
  rtb_Saturation74 += rtb_CmfI_s16Tincar_Front_A10;

  /* Outputs for Atomic SubSystem: '<S22>/DataTypeConv_s16_1' */
  /* Product: '<S22>/Product' incorporates:
   *  Constant: '<S22>/Constant'
   */
  rtb_Saturation74 = (int16_T) Sokon_X01_Cmf_DataTypeConv_s16_((int16_T)
    div_nde_s32_floor((int32_T)rtb_Saturation74, (int32_T)THM_u8CONST_2));

  /* End of Outputs for SubSystem: '<S22>/DataTypeConv_s16_1' */

  /* Outputs for Atomic SubSystem: '<S22>/DataTypeConv_s8_' */
  /* Lookup_n-D: '<S22>/Blower_SolarCmp' */
  rtb_Saturation69 = (int8_T) Sokon_X01_Cmf_DataTypeConv_s8_
    (look2_iu16s16lu16n8ts8Ds16ds16_binlcn(rtb_Saturation, rtb_Saturation74,
      ((uint16_T *)&(Thm_s16Blower_SolarCmp.Thm_u16Solar[0])), ((int16_T *)
       &(Thm_s16Blower_SolarCmp.Thm_s16Tuct_A10[0])), ((int8_T *)
       &(Thm_s16Blower_SolarCmp.Thm_s16Blower_SolarCmp_y[0])),
      Sokon_X01_Cmf_ConstP.pooled10, 10U));

  /* End of Outputs for SubSystem: '<S22>/DataTypeConv_s8_' */

  /* Lookup_n-D: '<S22>/CMF_s8Blw_Dyn_Y_Table' */
  rtb_CMF_s8Blw_Dyn_Y_Table = look2_is16lu16n8ts8Ds16ds16_binlcs
    (rtb_CmfI_s16Tamb_A10, rtb_Cmf_s16T_SysIncar_Delta, ((int16_T *)
      &(CMF_s8Blw_Dyn.CMF_s16Tamb_u1[0])), ((int16_T *)
      &(CMF_s8Blw_Dyn.CMF_s16TDiff_SysINCar_u2[0])), ((int8_T *)
      &(CMF_s8Blw_Dyn.CMF_s8Blw_Dyn_y[0])), Sokon_X01_Cmf_ConstP.pooled10, 10U);

  /* Lookup_n-D: '<S22>/CMF_s8Blw_VSP_Comp_Table' */
  rtb_CMF_s8Blw_VSP_Comp_Table = look2_iu8lu32n24ts8Ds16ds16_binlcs
    (rtb_Conversion_ch, rtb_Switch_i, ((uint8_T *)
      &(CMF_s8Blw_VSP_Comp.CMF_u8VSPD_U1[0])), ((uint8_T *)
      &(CMF_s8Blw_VSP_Comp.CMF_u8INTAK_PERCENT_U2[0])), ((int8_T *)
      &(CMF_s8Blw_VSP_Comp.CMF_s8Blw_VSP_Comp_y[0])),
     Sokon_X01_Cmf_ConstP.CMF_s8Blw_VSP_Comp_Table_maxIndex, 10U);

  /* End of Outputs for SubSystem: '<S9>/CMF_Blower_Compensation' */

  /* Outputs for Atomic SubSystem: '<S9>/CMF_Blower_Auto_Cal' */
  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* MinMax: '<S21>/Max1' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusInnerOut_at_inport_0'
   */
  if (rtb_Cmf_s16TasdLStatic > rtb_CmfO_s16Tasd_Right_Req_A10_d) {
    rtb_Saturation74 = rtb_Cmf_s16TasdLStatic;
  } else {
    rtb_Saturation74 = rtb_CmfO_s16Tasd_Right_Req_A10_d;
  }

  /* End of MinMax: '<S21>/Max1' */
  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* Lookup_n-D: '<S21>/CMF_u8Blw_LImitation_Table' */
  rtb_Switch_i = look2_is16lu16n8tu8_binlcse(rtb_CmfI_s16T_Wat_HVCHOut_A10,
    rtb_Saturation74, ((int16_T *)&(CMF_u8Blw_LImitation.CMF_s16T_WAT_ICDS_U1[0])),
    ((int16_T *)&(CMF_u8Blw_LImitation.CMF_s16Tasd_U2[0])), ((uint8_T *)
    &(CMF_u8Blw_LImitation.CMF_u8Blw_LImitation_y[0])),
    Sokon_X01_Cmf_ConstP.pooled10, 10U);

  /* Outputs for Atomic SubSystem: '<S4>/IntakeCal' */
  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   *  SignalConversion: '<S13>/BusConversion_InsertedFor_BusInnerOut_at_inport_0'
   */
  if (!rtb_IC42) {
    rtb_Switch_i = CMF_u8BLW_MAX;
  }

  /* End of Switch: '<S21>/Switch' */
  /* End of Outputs for SubSystem: '<S4>/IntakeCal' */

  /* Sum: '<S21>/Sum' */
  rtb_Saturation74 = (int16_T)(((((int32_T)rtb_CmfI_u8ModeStatus_Real) +
    ((int32_T)rtb_CMF_s8Blw_VSP_Comp_Table)) + ((int32_T)rtb_Saturation69)) +
    ((int32_T)rtb_CMF_s8Blw_Dyn_Y_Table));

  /* Saturate: '<S21>/Saturation' */
  u0 = (int32_T)rtb_Saturation74;
  if (u0 > ((int32_T)CMF_u8BLW_MAX)) {
    u0 = (int32_T)CMF_u8BLW_MAX;
  } else {
    if (u0 < ((int32_T)CMF_u8BLW_MIN)) {
      u0 = (int32_T)CMF_u8BLW_MIN;
    }
  }

  rtb_Conversion_m = (uint8_T)u0;

  /* End of Saturate: '<S21>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S21>/DelayJudge' */
  /* Logic: '<S21>/OR' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S31>/Constant'
   *  RelationalOperator: '<S30>/Compare'
   *  RelationalOperator: '<S31>/Compare'
   *  Sum: '<S21>/Sum1'
   */
  rtb_SignalCopy = ( Sokon_X01_Cmf_DelayJudge(((((int32_T)rtb_Switch_i) -
    ((int32_T)rtb_Conversion_m)) <= 5) && (rtb_CmfI_u8BlwMASts ==
    CAL_u8BLW_AUTO_8), CMF_u16TIMER_10S, &Sokon_X01_Cmf_DW.DelayJudge) != false);

  /* End of Outputs for SubSystem: '<S21>/DelayJudge' */

  /* MinMax: '<S21>/Min' */
  rtb_CmfI_u8BlwMASts = rtb_Conversion_m;
  if (rtb_Switch_i < rtb_CmfI_u8BlwMASts) {
    rtb_CmfI_u8BlwMASts = rtb_Switch_i;
  }

  /* End of MinMax: '<S21>/Min' */
  /* End of Outputs for SubSystem: '<S9>/CMF_Blower_Auto_Cal' */

  /* Outputs for Atomic SubSystem: '<S9>/Blower_Auto_Manual_Management' */
  /* MinMax: '<S23>/Max' */
  if (Sokon_X01_Cmf_ConstB.DataTypeConversion_h.Saturation > rtb_CmfI_u8BlwMASts)
  {
    rtb_CmfI_u8IntakeMASts =
      Sokon_X01_Cmf_ConstB.DataTypeConversion_h.Saturation;
  } else {
    rtb_CmfI_u8IntakeMASts = rtb_CmfI_u8BlwMASts;
  }

  /* End of MinMax: '<S23>/Max' */

  /* Outputs for Atomic SubSystem: '<S23>/IfThenElse1' */
  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   */
  rtb_Conversion_m = (uint8_T) Sokon_X01_Cmf_IfThenElse(rtb_CmfI_u8ModeMASts ==
    CAL_u8DIS_MODE_DEF, rtb_CmfI_u8IntakeMASts, rtb_CmfI_u8BlwMASts);

  /* End of Outputs for SubSystem: '<S23>/IfThenElse1' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S25>/Compare'
   */
  if (rtb_IC40 == THM_u8HVAC_STS_OFF) {
    rtb_CmfI_u8ModeMASts = Sokon_X01_Cmf_ConstB.DataTypeConversion_k.Saturation;
  } else {
    rtb_CmfI_u8ModeMASts = rtb_Conversion_m;
  }

  /* End of Switch: '<S20>/Switch' */
  /* End of Outputs for SubSystem: '<S9>/Blower_Auto_Manual_Management' */
  /* End of Outputs for SubSystem: '<S4>/BlowerCal' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_2' */
  /* Outputs for Atomic SubSystem: '<S4>/OtherRequirmentCal' */
  /* SignalConversion: '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  rtb_Compare_iy = ( Sokon_X01_Cmf_DataTypeConv_b_(rtb_SignalCopy) != false);

  /* End of Outputs for SubSystem: '<S4>/OtherRequirmentCal' */
  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_2' */

  /* InitialCondition: '<Root>/IC58' */
  if (Sokon_X01_Cmf_DW.IC58_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC58_FirstOutputTime = false;
    *rty_CmfO_bFlag_HeatShort_Blw_Req = false;
  } else {
    *rty_CmfO_bFlag_HeatShort_Blw_Req = rtb_Compare_iy;
  }

  /* End of InitialCondition: '<Root>/IC58' */

  /* Outputs for Atomic SubSystem: '<S4>/IntakeCal' */
  /* Saturate: '<Root>/Saturation47' incorporates:
   *  SignalConversion: '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (((int32_T)rtb_Switch2) < 7) {
    rtb_Saturation70 = rtb_Switch2;
  } else {
    rtb_Saturation70 = 7U;
  }

  /* End of Saturate: '<Root>/Saturation47' */
  /* End of Outputs for SubSystem: '<S4>/IntakeCal' */

  /* InitialCondition: '<Root>/IC49' */
  if (Sokon_X01_Cmf_DW.IC49_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC49_FirstOutputTime = false;
    *rty_CmfO_u8HVACMode_Req = 0U;
  } else {
    *rty_CmfO_u8HVACMode_Req = rtb_Saturation70;
  }

  /* End of InitialCondition: '<Root>/IC49' */

  /* InitialCondition: '<Root>/IC50' */
  if (Sokon_X01_Cmf_DW.IC50_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC50_FirstOutputTime = false;
    *rty_CmfO_u8HVACIntake_Req = 100U;
  }

  /* End of InitialCondition: '<Root>/IC50' */

  /* Outputs for Atomic SubSystem: '<S4>/OtherRequirmentCal' */
  /* Saturate: '<Root>/Saturation49' incorporates:
   *  SignalConversion: '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (((int32_T)rtb_CmfI_u8ModeMASts) < 120) {
    rtb_Saturation70 = rtb_CmfI_u8ModeMASts;
  } else {
    rtb_Saturation70 = 120U;
  }

  /* End of Saturate: '<Root>/Saturation49' */
  /* End of Outputs for SubSystem: '<S4>/OtherRequirmentCal' */

  /* InitialCondition: '<Root>/IC51' */
  if (Sokon_X01_Cmf_DW.IC51_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC51_FirstOutputTime = false;
    *rty_CmfO_u8HVACBlwVol_Req_A10 = 0U;
  } else {
    *rty_CmfO_u8HVACBlwVol_Req_A10 = rtb_Saturation70;
  }

  /* End of InitialCondition: '<Root>/IC51' */

  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* Saturate: '<Root>/Saturation50' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (rtb_Cmf_s16TasdLStatic > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_Cmf_s16TasdLStatic < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_Cmf_s16TasdLStatic;
  }

  /* End of Saturate: '<Root>/Saturation50' */
  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* InitialCondition: '<Root>/IC52' */
  if (Sokon_X01_Cmf_DW.IC52_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC52_FirstOutputTime = false;
    *rty_CmfO_s16Tasd_Left_Req_A10 = 200;
  } else {
    *rty_CmfO_s16Tasd_Left_Req_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC52' */

  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* Saturate: '<Root>/Saturation51' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (rtb_CmfO_s16Tasd_Right_Req_A10_d > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_CmfO_s16Tasd_Right_Req_A10_d < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_CmfO_s16Tasd_Right_Req_A10_d;
  }

  /* End of Saturate: '<Root>/Saturation51' */
  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* InitialCondition: '<Root>/IC53' */
  if (Sokon_X01_Cmf_DW.IC53_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC53_FirstOutputTime = false;
    *rty_CmfO_s16Tasd_Right_Req_A10 = 200;
  } else {
    *rty_CmfO_s16Tasd_Right_Req_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC53' */

  /* Outputs for Atomic SubSystem: '<S4>/OtherRequirmentCal' */
  /* Saturate: '<Root>/Saturation52' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtSignal Copy3Inport1'
   */
  if (rtb_CmfI_s16Tincar_Front_A10 > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_CmfI_s16Tincar_Front_A10 < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_CmfI_s16Tincar_Front_A10;
  }

  /* End of Saturate: '<Root>/Saturation52' */
  /* End of Outputs for SubSystem: '<S4>/OtherRequirmentCal' */

  /* InitialCondition: '<Root>/IC54' */
  if (Sokon_X01_Cmf_DW.IC54_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC54_FirstOutputTime = false;
    *rty_CmfO_s16TDuct_Left_Out_A10 = 200;
  } else {
    *rty_CmfO_s16TDuct_Left_Out_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC54' */

  /* Outputs for Atomic SubSystem: '<S4>/OtherRequirmentCal' */
  /* Saturate: '<Root>/Saturation53' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtSignal Copy4Inport1'
   */
  rtb_Saturation74 = rtb_Cmf_s16TasdRStatic;

  /* End of Outputs for SubSystem: '<S4>/OtherRequirmentCal' */

  /* InitialCondition: '<Root>/IC55' */
  if (Sokon_X01_Cmf_DW.IC55_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC55_FirstOutputTime = false;
    *rty_CmfO_s16TDuct_Right_Out_A10 = 200;
  } else {
    *rty_CmfO_s16TDuct_Right_Out_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC55' */

  /* Outputs for Atomic SubSystem: '<S4>/IntakeCal' */
  /* SignalConversion: '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  rtb_CmfI_u8IntakeMASts = rtb_CmfO_u8TevaSet_Req_A10_f;

  /* End of Outputs for SubSystem: '<S4>/IntakeCal' */

  /* Saturate: '<Root>/Saturation54' */
  if (((int32_T)rtb_CmfI_u8IntakeMASts) < 200) {
    rtb_Saturation70 = rtb_CmfI_u8IntakeMASts;
  } else {
    rtb_Saturation70 = 200U;
  }

  /* End of Saturate: '<Root>/Saturation54' */

  /* InitialCondition: '<Root>/IC56' */
  if (Sokon_X01_Cmf_DW.IC56_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC56_FirstOutputTime = false;
    *rty_CmfO_u8TevaSet_Req_A10 = 200U;
  } else {
    *rty_CmfO_u8TevaSet_Req_A10 = rtb_Saturation70;
  }

  /* End of InitialCondition: '<Root>/IC56' */

  /* InitialCondition: '<Root>/IC57' */
  if (Sokon_X01_Cmf_DW.IC57_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC57_FirstOutputTime = false;
    *rty_CmfO_s16Tincar_Setting_Req_A10 = 240;
  } else {
    *rty_CmfO_s16Tincar_Setting_Req_A10 = Sokon_X01_Cmf_ConstB.Saturation55;
  }

  /* End of InitialCondition: '<Root>/IC57' */

  /* InitialCondition: '<Root>/IC59' */
  if (Sokon_X01_Cmf_DW.IC59_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC59_FirstOutputTime = false;
    *rty_CmfO_u16Debug_TasdLStatic_A10 = 0U;
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/BlowerCal' */
    /* SignalConversion: '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
    rtb_CmfI_u16Tset_Ave_A10 = rtb_CmfO_u16Debug_TasdLStatic_A10_k;

    /* End of Outputs for SubSystem: '<S4>/BlowerCal' */

    /* Saturate: '<Root>/Saturation56' */
    if (((int32_T)rtb_CmfI_u16Tset_Ave_A10) < 800) {
      *rty_CmfO_u16Debug_TasdLStatic_A10 = rtb_CmfI_u16Tset_Ave_A10;
    } else {
      *rty_CmfO_u16Debug_TasdLStatic_A10 = 800U;
    }

    /* End of Saturate: '<Root>/Saturation56' */
  }

  /* End of InitialCondition: '<Root>/IC59' */

  /* InitialCondition: '<Root>/IC60' incorporates:
   *  Saturate: '<Root>/Saturation57'
   *  SignalConversion: '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (Sokon_X01_Cmf_DW.IC60_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC60_FirstOutputTime = false;
    *rty_CmfO_u16Debug_TasdRStatic_A10 = 0U;
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/IntakeCal' */
    if (((int32_T)rtb_CmfI_u16Tset_Right_A10) < 800) {
      /* Saturate: '<Root>/Saturation57' incorporates:
       *  SignalConversion: '<S13>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
       */
      *rty_CmfO_u16Debug_TasdRStatic_A10 = rtb_CmfI_u16Tset_Right_A10;
    } else {
      /* Saturate: '<Root>/Saturation57' */
      *rty_CmfO_u16Debug_TasdRStatic_A10 = 800U;
    }

    /* End of Outputs for SubSystem: '<S4>/IntakeCal' */
  }

  /* End of InitialCondition: '<Root>/IC60' */

  /* Outputs for Atomic SubSystem: '<S4>/BlowerCal' */
  /* Saturate: '<Root>/Saturation58' incorporates:
   *  SignalConversion: '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_CmfO_s16Debug_TasdLSolarCmp_A10_k;
  }

  /* End of Saturate: '<Root>/Saturation58' */
  /* End of Outputs for SubSystem: '<S4>/BlowerCal' */

  /* InitialCondition: '<Root>/IC61' */
  if (Sokon_X01_Cmf_DW.IC61_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC61_FirstOutputTime = false;
    *rty_CmfO_s16Debug_TasdLSolarCmp_A10 = 0;
  } else {
    *rty_CmfO_s16Debug_TasdLSolarCmp_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC61' */

  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* Saturate: '<Root>/Saturation59' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (rtb_Switch_cvp > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_Switch_cvp < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_Switch_cvp;
  }

  /* End of Saturate: '<Root>/Saturation59' */
  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* InitialCondition: '<Root>/IC62' */
  if (Sokon_X01_Cmf_DW.IC62_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC62_FirstOutputTime = false;
    *rty_CmfO_s16Debug_TasdDefCmp_A10 = 0;
  } else {
    *rty_CmfO_s16Debug_TasdDefCmp_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC62' */

  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* Saturate: '<Root>/Saturation60' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (rtb_Switch > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_Switch < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_Switch;
  }

  /* End of Saturate: '<Root>/Saturation60' */
  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* InitialCondition: '<Root>/IC63' */
  if (Sokon_X01_Cmf_DW.IC63_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC63_FirstOutputTime = false;
    *rty_CmfO_s16Debug_TasdEcoCmp_A10 = 0;
  } else {
    *rty_CmfO_s16Debug_TasdEcoCmp_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC63' */

  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* Saturate: '<Root>/Saturation61' incorporates:
   *  SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (rtb_CMF_s16Tasd_Solar_CMP_Table > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_CMF_s16Tasd_Solar_CMP_Table < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_CMF_s16Tasd_Solar_CMP_Table;
  }

  /* End of Saturate: '<Root>/Saturation61' */
  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* InitialCondition: '<Root>/IC64' */
  if (Sokon_X01_Cmf_DW.IC64_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC64_FirstOutputTime = false;
    *rty_CmfO_s16Debug_TasdDyn_A10 = 0;
  } else {
    *rty_CmfO_s16Debug_TasdDyn_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC64' */

  /* Outputs for Atomic SubSystem: '<S4>/BlowerCal' */
  /* Saturate: '<Root>/Saturation62' incorporates:
   *  SignalConversion: '<S9>/TmpSignal ConversionAtSignal Copy2Inport1'
   */
  rtb_Saturation70 = rtb_CmfI_u8ModeStatus_Real;

  /* End of Outputs for SubSystem: '<S4>/BlowerCal' */

  /* InitialCondition: '<Root>/IC65' */
  if (Sokon_X01_Cmf_DW.IC65_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC65_FirstOutputTime = false;
    *rty_CmfO_u8Debug_BlwStatic_A10 = 0U;
  } else {
    *rty_CmfO_u8Debug_BlwStatic_A10 = rtb_Saturation70;
  }

  /* End of InitialCondition: '<Root>/IC65' */

  /* InitialCondition: '<Root>/IC66' incorporates:
   *  Saturate: '<Root>/Saturation63'
   *  SignalConversion: '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (Sokon_X01_Cmf_DW.IC66_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC66_FirstOutputTime = false;
    *rty_CmfO_s8Debug_BlwVspCmp_A10 = 0;
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/OtherRequirmentCal' */
    if (rtb_CMF_s8Blw_VSP_Comp_Table > 80) {
      /* Saturate: '<Root>/Saturation63' */
      *rty_CmfO_s8Debug_BlwVspCmp_A10 = 80;
    } else if (rtb_CMF_s8Blw_VSP_Comp_Table < -80) {
      /* Saturate: '<Root>/Saturation63' */
      *rty_CmfO_s8Debug_BlwVspCmp_A10 = -80;
    } else {
      /* Saturate: '<Root>/Saturation63' incorporates:
       *  SignalConversion: '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
       */
      *rty_CmfO_s8Debug_BlwVspCmp_A10 = rtb_CMF_s8Blw_VSP_Comp_Table;
    }

    /* End of Outputs for SubSystem: '<S4>/OtherRequirmentCal' */
  }

  /* End of InitialCondition: '<Root>/IC66' */

  /* InitialCondition: '<Root>/IC67' */
  if (Sokon_X01_Cmf_DW.IC67_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC67_FirstOutputTime = false;
    *rty_CmfO_s8Debug_BlwSolarCmp_A10 = 0;
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/OtherRequirmentCal' */
    /* SignalConversion: '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
    rtb_CMF_s8Blw_VSP_Comp_Table = rtb_Saturation69;

    /* End of Outputs for SubSystem: '<S4>/OtherRequirmentCal' */

    /* Saturate: '<Root>/Saturation64' */
    if (rtb_CMF_s8Blw_VSP_Comp_Table > 80) {
      *rty_CmfO_s8Debug_BlwSolarCmp_A10 = 80;
    } else if (rtb_CMF_s8Blw_VSP_Comp_Table < -80) {
      *rty_CmfO_s8Debug_BlwSolarCmp_A10 = -80;
    } else {
      *rty_CmfO_s8Debug_BlwSolarCmp_A10 = rtb_CMF_s8Blw_VSP_Comp_Table;
    }

    /* End of Saturate: '<Root>/Saturation64' */
  }

  /* End of InitialCondition: '<Root>/IC67' */

  /* InitialCondition: '<Root>/IC68' incorporates:
   *  Saturate: '<Root>/Saturation65'
   *  SignalConversion: '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (Sokon_X01_Cmf_DW.IC68_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC68_FirstOutputTime = false;
    *rty_CmfO_s8Debug_BlwDyn_A10 = 0;
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/OtherRequirmentCal' */
    if (rtb_CMF_s8Blw_Dyn_Y_Table > 80) {
      /* Saturate: '<Root>/Saturation65' */
      *rty_CmfO_s8Debug_BlwDyn_A10 = 80;
    } else if (rtb_CMF_s8Blw_Dyn_Y_Table < -80) {
      /* Saturate: '<Root>/Saturation65' */
      *rty_CmfO_s8Debug_BlwDyn_A10 = -80;
    } else {
      /* Saturate: '<Root>/Saturation65' incorporates:
       *  SignalConversion: '<S15>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
       */
      *rty_CmfO_s8Debug_BlwDyn_A10 = rtb_CMF_s8Blw_Dyn_Y_Table;
    }

    /* End of Outputs for SubSystem: '<S4>/OtherRequirmentCal' */
  }

  /* End of InitialCondition: '<Root>/IC68' */

  /* InitialCondition: '<Root>/IC69' */
  if (Sokon_X01_Cmf_DW.IC69_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC69_FirstOutputTime = false;
    *rty_CmfO_u8Debug_IntkStatic = 0U;
  } else {
    *rty_CmfO_u8Debug_IntkStatic = Sokon_X01_Cmf_ConstB.Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC69' */

  /* InitialCondition: '<Root>/IC70' */
  if (Sokon_X01_Cmf_DW.IC70_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC70_FirstOutputTime = false;
    *rty_CmfO_s8Debug_IntkDyn = 0;
  } else {
    *rty_CmfO_s8Debug_IntkDyn = Sokon_X01_Cmf_ConstB.Saturation67;
  }

  /* End of InitialCondition: '<Root>/IC70' */

  /* InitialCondition: '<Root>/IC71' */
  if (Sokon_X01_Cmf_DW.IC71_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC71_FirstOutputTime = false;
    *rty_CmfO_u8Debug_ModePerStatic = 0U;
  } else {
    *rty_CmfO_u8Debug_ModePerStatic = Sokon_X01_Cmf_ConstB.Saturation68;
  }

  /* End of InitialCondition: '<Root>/IC71' */

  /* InitialCondition: '<Root>/IC72' incorporates:
   *  Saturate: '<Root>/Saturation69'
   *  SignalConversion: '<S14>/TmpSignal ConversionAtSignal Copy2Inport1'
   */
  if (Sokon_X01_Cmf_DW.IC72_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC72_FirstOutputTime = false;
    *rty_CmfO_s8Debug_LvlCabHeatCool = 0;
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/ModeCal' */
    if (rtb_Cmf_s8LVL_CabHeatCooling > 50) {
      /* Saturate: '<Root>/Saturation69' */
      *rty_CmfO_s8Debug_LvlCabHeatCool = 50;
    } else if (rtb_Cmf_s8LVL_CabHeatCooling < -50) {
      /* Saturate: '<Root>/Saturation69' */
      *rty_CmfO_s8Debug_LvlCabHeatCool = -50;
    } else {
      /* Saturate: '<Root>/Saturation69' incorporates:
       *  SignalConversion: '<S14>/TmpSignal ConversionAtSignal Copy2Inport1'
       */
      *rty_CmfO_s8Debug_LvlCabHeatCool = rtb_Cmf_s8LVL_CabHeatCooling;
    }

    /* End of Outputs for SubSystem: '<S4>/ModeCal' */
  }

  /* End of InitialCondition: '<Root>/IC72' */

  /* Outputs for Atomic SubSystem: '<S4>/BlowerCal' */
  /* Saturate: '<Root>/Saturation70' incorporates:
   *  SignalConversion: '<S9>/BusConversion_InsertedFor_BusOutputOut_at_inport_0'
   */
  if (((int32_T)rtb_Switch_g) < 7) {
    rtb_Saturation70 = rtb_Switch_g;
  } else {
    rtb_Saturation70 = 7U;
  }

  /* End of Saturate: '<Root>/Saturation70' */
  /* End of Outputs for SubSystem: '<S4>/BlowerCal' */

  /* InitialCondition: '<Root>/IC73' */
  if (Sokon_X01_Cmf_DW.IC73_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC73_FirstOutputTime = false;
    *rty_CmfO_u8WindExitmodeDisp = 0U;
  } else {
    *rty_CmfO_u8WindExitmodeDisp = rtb_Saturation70;
  }

  /* End of InitialCondition: '<Root>/IC73' */

  /* InitialCondition: '<Root>/IC74' */
  if (Sokon_X01_Cmf_DW.IC74_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC74_FirstOutputTime = false;
    *rty_CmfO_u8CabinCoolPrioReq = 0U;
  } else {
    *rty_CmfO_u8CabinCoolPrioReq = Sokon_X01_Cmf_ConstB.Saturation71;
  }

  /* End of InitialCondition: '<Root>/IC74' */

  /* InitialCondition: '<Root>/IC75' */
  if (Sokon_X01_Cmf_DW.IC75_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC75_FirstOutputTime = false;
    *rty_CmfO_u8CabinHeatPrioReq = 0U;
  } else {
    *rty_CmfO_u8CabinHeatPrioReq = Sokon_X01_Cmf_ConstB.Saturation72;
  }

  /* End of InitialCondition: '<Root>/IC75' */

  /* InitialCondition: '<Root>/IC76' */
  if (Sokon_X01_Cmf_DW.IC76_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC76_FirstOutputTime = false;
    *rty_CmfO_u16Tw_PTCOut_Set_Pre_A10 = 0U;
  } else {
    *rty_CmfO_u16Tw_PTCOut_Set_Pre_A10 = Sokon_X01_Cmf_ConstB.Saturation73;
  }

  /* End of InitialCondition: '<Root>/IC76' */

  /* Outputs for Atomic SubSystem: '<S4>/TevaSetCal' */
  /* SignalConversion: '<S19>/BusConversion_InsertedFor_BusOutputOut_at_inport_0' */
  rtb_Cmf_s16TasdRStatic = rtb_Switch3;

  /* End of Outputs for SubSystem: '<S4>/TevaSetCal' */

  /* Saturate: '<Root>/Saturation74' */
  if (rtb_Cmf_s16TasdRStatic > 1500) {
    rtb_Saturation74 = 1500;
  } else if (rtb_Cmf_s16TasdRStatic < -500) {
    rtb_Saturation74 = -500;
  } else {
    rtb_Saturation74 = rtb_Cmf_s16TasdRStatic;
  }

  /* End of Saturate: '<Root>/Saturation74' */

  /* InitialCondition: '<Root>/IC77' */
  if (Sokon_X01_Cmf_DW.IC77_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC77_FirstOutputTime = false;
    *rty_CmfO_s16Debug_TasdRSolarCmp_A10 = 0;
  } else {
    *rty_CmfO_s16Debug_TasdRSolarCmp_A10 = rtb_Saturation74;
  }

  /* End of InitialCondition: '<Root>/IC77' */

  /* Outputs for Atomic SubSystem: '<S204>/R134a_SatTempCal_P_A100_' */
  /* Gain: '<S204>/Gain' */
  rtb_R134A_P_a100_T_a10_Table = (int16_T)
    Sokon_X01_Cmf_R134a_SatTempCal_P_A100_((uint16_T)(10U * ((uint32_T)
    rtb_CmfI_u16P_Ref_CondOut_A10)));

  /* End of Outputs for SubSystem: '<S204>/R134a_SatTempCal_P_A100_' */

  /* InitialCondition: '<Root>/IC4' */
  if (Sokon_X01_Cmf_DW.IC4_FirstOutputTime) {
    Sokon_X01_Cmf_DW.IC4_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = *rtu_CmfI_bAcSts;
  }

  /* End of InitialCondition: '<Root>/IC4' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_' */
  rtb_Compare_nq = ( Sokon_X01_Cmf_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_' */

  /* Update for UnitDelay: '<S199>/Unit Delay' */
  Sokon_X01_Cmf_DW.UnitDelay_DSTATE_j = rtb_CmfI_u8IgnSts;
}

/* Model initialize function */
void Sokon_X01_Cmf_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&Sokon_X01_Cmf_DW, 0,
                sizeof(DW_Sokon_X01_Cmf_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

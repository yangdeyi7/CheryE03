/*
 * File: Chery_E03_Hp.c
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
#include "Double2MultiWord.h"
#include "MultiWord2sLong.h"
#include "MultiWordAdd.h"
#include "MultiWordSignedWrap.h"
#include "MultiWordSub.h"
#include "asr_s32.h"
#include "div_nde_s32_floor.h"
#include "div_nzp_s32_near.h"
#include "div_nzp_u32_near.h"
#include "look1_is16lu16n8tu8_binlcse.h"
#include "look1_is16lu32n16Ds32_binlcs.h"
#include "look1_is16lu32n16tu16_binlcse.h"
#include "look1_iu16bs16lu32n16_binlcse.h"
#include "look1_iu16lu32n16_binlcse.h"
#include "look1_iu16lu32n16ts16Ds32_binlcn.h"
#include "look1_iu8lu32n24tu16Ds32Iu8_binlcs.h"
#include "look2_is16lu16n8tu8_binlcse.h"
#include "look2_is16lu32n16Ds32ds32_binlcs.h"
#include "look2_is16lu32n16tu16_binlcse.h"
#include "look2_is16u16lu32n16ts16Ds32ds32_binlcs.h"
#include "look2_is16u16lu32n16tu16_binlcse.h"
#include "look2_is16u8lu32n16tu16_binlcse.h"
#include "look2_iu16lu32n16_binlcse.h"
#include "look2_iu16s16lu32n16tu16_binlcse.h"
#include "look2_iu8lu32n16tu16_binlcse.h"
#include "look2_iu8u16lu32n16tu8_binlcse.h"
#include "sLong2MultiWord.h"
#include "sMultiWord2MultiWord.h"
#include "sMultiWord2sLongSat.h"
#include "sMultiWordDivNear.h"
#include "sMultiWordGe.h"
#include "sMultiWordLe.h"
#include "sMultiWordNe.h"
#include "sMultiWordShl.h"
#include "sMultiWordShrNear.h"
#include "ssuMultiWordMul.h"
#include "uLong2MultiWord.h"

/* Named constants for Chart: '<S976>/Eva_Freeze_Status_Check' */
#define Chery_E03_Hp_IN_Eva_Freeze_EDC_Yes ((uint8_T)1U)
#define Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon ((uint8_T)2U)
#define Chery_E03_Hp_IN_Goto_Eva_FreezeEDC_Check ((uint8_T)3U)
#define Chery_E03_Hp_IN_NO_ACTIVE_CHILD_b ((uint8_T)0U)

/* Named constants for Chart: '<S88>/Eva_Cond_Calculation' */
#define Chery_E03_Hp_IN_Condensate_Generate ((uint8_T)1U)
#define Chery_E03_Hp_IN_Condensate_Remove ((uint8_T)2U)
#define Chery_E03_Hp_IN_NO_ACTIVE_CHILD_j ((uint8_T)0U)

/* Named constants for Chart: '<S116>/Sys_Working_Mode_selection' */
#define Chery_E03_Hp_IN_Mode_Chiller   ((uint8_T)1U)
#define Chery_E03_Hp_IN_Mode_Ref_Work  ((uint8_T)2U)
#define Chery_E03_Hp_IN_Mode_Stop      ((uint8_T)3U)

/* Named constants for Chart: '<S375>/Eva_Freeze_Status_Check' */
#define Chery_E03_Hp_IN_EDC_RPM_Maintain ((uint8_T)1U)
#define Chery_E03_Hp_IN_Eva_Freeze_EDC_Yes_m ((uint8_T)2U)
#define Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon_p ((uint8_T)3U)
#define Chery_E03_Hp_IN_Goto_Eva_FreezeEDC_Check_g ((uint8_T)4U)

/* Block signals (default storage) */
B_Chery_E03_Hp_c_T Chery_E03_Hp_B;

/* Block states (default storage) */
DW_Chery_E03_Hp_f_T Chery_E03_Hp_DW;

/* Forward declaration for local functions */
static boolean_T Chery_E03_Hp_Ref_Work(void);

/*
 * Output and update for atomic system:
 *    '<S43>/MixFlapReqCal'
 *    '<S44>/MixFlapReqCal'
 */
void Chery_E03_Hp_MixFlapReqCal(boolean_T rtu_bFlag_Heating_Stop, int16_T
  rtu_s16TSet, boolean_T rtu_bFlag_Full_Hot, uint8_T rtu_u8MixPerReq, boolean_T *
  rty_bSysHeatingStop, uint8_T *rty_u8MixStepper_Req)
{
  /* Logic: '<S45>/OR' incorporates:
   *  Constant: '<S50>/Constant'
   *  RelationalOperator: '<S50>/Compare'
   */
  *rty_bSysHeatingStop = (rtu_bFlag_Heating_Stop || (rtu_s16TSet == s16TSET_LOW));

  /* Switch: '<S45>/Switch4' incorporates:
   *  Constant: '<S45>/Constant10'
   *  Constant: '<S51>/Constant'
   *  RelationalOperator: '<S51>/Compare'
   */
  if (rtu_bFlag_Full_Hot == bFLAG_YES) {
    *rty_u8MixStepper_Req = u8FLAP_POS_100;
  } else {
    *rty_u8MixStepper_Req = rtu_u8MixPerReq;
  }

  /* End of Switch: '<S45>/Switch4' */

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Constant8'
   */
  if (*rty_bSysHeatingStop) {
    *rty_u8MixStepper_Req = u8FLAP_POS_0;
  }

  /* End of Switch: '<S45>/Switch' */
}

/*
 * Output and update for atomic system:
 *    '<S49>/IfThenElse'
 *    '<S578>/IfThenElse'
 *    '<S633>/IfThenElse1'
 *    '<S1162>/IfThenElse'
 *    '<S1164>/IfThenElse'
 *    '<S1259>/IfThenElse'
 *    '<S1259>/IfThenElse1'
 *    '<S1259>/IfThenElse2'
 *    '<S1259>/IfThenElse3'
 *    '<S1259>/IfThenElse4'
 *    ...
 */
int16_T Chery_E03_Hp_IfThenElse(boolean_T rtu_bIf, int16_T rtu_Then, int16_T
  rtu_Else)
{
  int16_T rty_Out_0;

  /* Switch: '<S61>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S62>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S62>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S61>/Switch' */
  return rty_Out_0;
}

/*
 * System initialize for atomic system:
 *    '<S100>/JudgeTime'
 *    '<S103>/JudgeTime'
 *    '<S286>/JudgeTime'
 *    '<S289>/JudgeTime'
 *    '<S320>/JudgeTime'
 *    '<S330>/JudgeTime'
 *    '<S333>/JudgeTime'
 *    '<S435>/JudgeTime'
 *    '<S439>/JudgeTime'
 *    '<S1003>/JudgeTime'
 *    ...
 */
void Chery_E03_Hp_JudgeTime_Init(boolean_T *rty_bDelayJudge,
  DW_JudgeTime_Chery_E03_Hp_T *localDW)
{
  localDW->u16Count_Delay = 0U;
  *rty_bDelayJudge = false;
}

/*
 * System reset for atomic system:
 *    '<S100>/JudgeTime'
 *    '<S103>/JudgeTime'
 *    '<S286>/JudgeTime'
 *    '<S289>/JudgeTime'
 *    '<S320>/JudgeTime'
 *    '<S330>/JudgeTime'
 *    '<S333>/JudgeTime'
 *    '<S435>/JudgeTime'
 *    '<S439>/JudgeTime'
 *    '<S1003>/JudgeTime'
 *    ...
 */
void Chery_E03_Hp_JudgeTime_Reset(boolean_T *rty_bDelayJudge,
  DW_JudgeTime_Chery_E03_Hp_T *localDW)
{
  localDW->u16Count_Delay = 0U;
  *rty_bDelayJudge = false;
}

/*
 * Output and update for atomic system:
 *    '<S100>/JudgeTime'
 *    '<S103>/JudgeTime'
 *    '<S286>/JudgeTime'
 *    '<S289>/JudgeTime'
 *    '<S320>/JudgeTime'
 *    '<S330>/JudgeTime'
 *    '<S333>/JudgeTime'
 *    '<S435>/JudgeTime'
 *    '<S439>/JudgeTime'
 *    '<S1003>/JudgeTime'
 *    ...
 */
void Chery_E03_Hp_JudgeTime(boolean_T rtu_bJudge, uint16_T rtu_u16DelayTime,
  boolean_T *rty_bDelayJudge, DW_JudgeTime_Chery_E03_Hp_T *localDW)
{
  int32_T tmp;

  /* Chart: '<S100>/JudgeTime' */
  if (rtu_bJudge) {
    if (localDW->u16Count_Delay >= rtu_u16DelayTime) {
      *rty_bDelayJudge = true;
    } else {
      *rty_bDelayJudge = false;
      tmp = ((int32_T)localDW->u16Count_Delay) + 1;
      if (tmp > 65535) {
        tmp = 65535;
      }

      localDW->u16Count_Delay = (uint16_T)tmp;
    }
  } else {
    localDW->u16Count_Delay = 0U;
    *rty_bDelayJudge = false;
  }

  /* End of Chart: '<S100>/JudgeTime' */
}

/*
 * System initialize for atomic system:
 *    '<S94>/DelayJudge'
 *    '<S94>/DelayJudge1'
 *    '<S274>/DelayJudge'
 *    '<S274>/DelayJudge1'
 *    '<S322>/DelayJudge'
 *    '<S322>/DelayJudge1'
 *    '<S1021>/DelayJudge'
 *    '<S1021>/DelayJudge1'
 *    '<S1032>/DelayJudge'
 *    '<S1032>/DelayJudge1'
 *    ...
 */
void Chery_E03_Hp_DelayJudge_Init(DW_DelayJudge_Chery_E03_Hp_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge_f;

  /* SystemInitialize for Chart: '<S100>/JudgeTime' */
  Chery_E03_Hp_JudgeTime_Init(&rtb_bDelayJudge_f, &localDW->sf_JudgeTime);
}

/*
 * System reset for atomic system:
 *    '<S94>/DelayJudge'
 *    '<S94>/DelayJudge1'
 *    '<S274>/DelayJudge'
 *    '<S274>/DelayJudge1'
 *    '<S322>/DelayJudge'
 *    '<S322>/DelayJudge1'
 *    '<S1021>/DelayJudge'
 *    '<S1021>/DelayJudge1'
 *    '<S1032>/DelayJudge'
 *    '<S1032>/DelayJudge1'
 *    ...
 */
void Chery_E03_Hp_DelayJudge_Reset(DW_DelayJudge_Chery_E03_Hp_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge_f;

  /* SystemReset for Chart: '<S100>/JudgeTime' */
  Chery_E03_Hp_JudgeTime_Reset(&rtb_bDelayJudge_f, &localDW->sf_JudgeTime);
}

/*
 * Output and update for atomic system:
 *    '<S94>/DelayJudge'
 *    '<S94>/DelayJudge1'
 *    '<S274>/DelayJudge'
 *    '<S274>/DelayJudge1'
 *    '<S322>/DelayJudge'
 *    '<S322>/DelayJudge1'
 *    '<S1021>/DelayJudge'
 *    '<S1021>/DelayJudge1'
 *    '<S1032>/DelayJudge'
 *    '<S1032>/DelayJudge1'
 *    ...
 */
boolean_T Chery_E03_Hp_DelayJudge(boolean_T rtu_bJudge, const
  ConstB_DelayJudge_Chery_E03_Hp_T *localC, DW_DelayJudge_Chery_E03_Hp_T
  *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge_f;
  boolean_T rty_bDelayJudge_0;

  /* Chart: '<S100>/JudgeTime' */
  Chery_E03_Hp_JudgeTime(rtu_bJudge, localC->DataTypeConv_u16_.Saturation,
    &rtb_bDelayJudge_f, &localDW->sf_JudgeTime);

  /* SignalConversion: '<S97>/Signal Copy' */
  rty_bDelayJudge_0 = rtb_bDelayJudge_f;
  return rty_bDelayJudge_0;
}

/* System initialize for atomic system: '<S89>/Hyster_And_Delay_Judge' */
void Chery_E03_Hp_Hyster_And_Delay_Judge_Init
  (DW_Hyster_And_Delay_Judge_Chery_E03_Hp_T *localDW, boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S94>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;

  /* SystemInitialize for Atomic SubSystem: '<S94>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&localDW->DelayJudge);

  /* End of SystemInitialize for SubSystem: '<S94>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S94>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&localDW->DelayJudge1);

  /* End of SystemInitialize for SubSystem: '<S94>/DelayJudge1' */
}

/* Output and update for atomic system: '<S89>/Hyster_And_Delay_Judge' */
boolean_T Chery_E03_Hp_Hyster_And_Delay_Judge(int32_T rtu_ParaJudgeUp, int32_T
  rtu_HyJudgeIn, int32_T rtu_ParaJudgeDown, const
  ConstB_Hyster_And_Delay_Judge_Chery_E03_Hp_T *localC,
  DW_Hyster_And_Delay_Judge_Chery_E03_Hp_T *localDW, boolean_T
  rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;
  boolean_T rtb_SignalCopy_dn;
  boolean_T rtb_SignalCopy_d4v;

  /* Outputs for Atomic SubSystem: '<S94>/DelayJudge' */
  /* RelationalOperator: '<S94>/RelationalOperator3' */
  rtb_SignalCopy_d4v = ( Chery_E03_Hp_DelayJudge(rtu_HyJudgeIn >=
    rtu_ParaJudgeUp, &localC->DelayJudge, &localDW->DelayJudge) != false);

  /* End of Outputs for SubSystem: '<S94>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S94>/DelayJudge1' */
  /* RelationalOperator: '<S94>/RelationalOperator1' */
  rtb_SignalCopy_dn = ( Chery_E03_Hp_DelayJudge(rtu_HyJudgeIn <=
    rtu_ParaJudgeDown, &localC->DelayJudge1, &localDW->DelayJudge1) != false);

  /* End of Outputs for SubSystem: '<S94>/DelayJudge1' */

  /* Switch: '<S94>/Switch4' incorporates:
   *  Constant: '<S94>/JudgeYes'
   *  Logic: '<S94>/NOT'
   *  UnitDelay: '<S94>/Unit Delay'
   */
  if (rtb_SignalCopy_dn) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S94>/Switch4' */

  /* Switch: '<S94>/Switch2' incorporates:
   *  Constant: '<S94>/JudgeYes'
   *  UnitDelay: '<S94>/Unit Delay'
   */
  if (rtb_SignalCopy_d4v) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S94>/Switch2' */

  /* Update for UnitDelay: '<S94>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/*
 * Output and update for atomic system:
 *    '<S90>/IfThenElse'
 *    '<S119>/IfThenElse1'
 *    '<S118>/IfThenElse2'
 *    '<S118>/IfThenElse3'
 *    '<S118>/IfThenElse4'
 *    '<S118>/IfThenElse5'
 *    '<S120>/IfThenElse1'
 *    '<S129>/IfThenElse1'
 *    '<S128>/IfThenElse2'
 *    '<S128>/IfThenElse3'
 *    ...
 */
uint8_T Chery_E03_Hp_IfThenElse_a(boolean_T rtu_bIf, uint8_T rtu_Then, uint8_T
  rtu_Else)
{
  uint8_T rty_Out_0;

  /* Switch: '<S106>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S107>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S107>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S106>/Switch' */
  return rty_Out_0;
}

/* Function for Chart: '<S116>/Sys_Working_Mode_selection' */
static boolean_T Chery_E03_Hp_Ref_Work(void)
{
  /* UnitDelay: '<S87>/Unit Delay' */
  return ((((Chery_E03_Hp_DW.UnitDelay_DSTATE_i != u8MODE_STOP_0) &&
            (Chery_E03_Hp_DW.UnitDelay_DSTATE_i != u8MODE_FAILURE_4)) &&
           (Chery_E03_Hp_DW.UnitDelay_DSTATE_i != u8MODE_HVCH_CMF_20)) &&
          (Chery_E03_Hp_DW.UnitDelay_DSTATE_i != u8MODE_HVCH_BAT_21)) &&
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_i != u8MODE_HVCH_CMF_BAT_22);
}

/* System initialize for atomic system: '<S1>/Mode_Selection' */
void Chery_E03_Hp_Mode_Selection_Init(void)
{
  /* local block i/o variables */
  boolean_T rtb_bFlag_Mode_SwithConfirm;

  /* SystemInitialize for Chart: '<S88>/Eva_Cond_Calculation' */
  Chery_E03_Hp_DW.is_active_c106_Chery_E03_Hp = 0U;
  Chery_E03_Hp_DW.is_c106_Chery_E03_Hp = Chery_E03_Hp_IN_NO_ACTIVE_CHILD_j;
  Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt = 0;

  /* SystemInitialize for Atomic SubSystem: '<S89>/Hyster_And_Delay_Judge' */
  Chery_E03_Hp_Hyster_And_Delay_Judge_Init
    (&Chery_E03_Hp_DW.Hyster_And_Delay_Judge, Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S89>/Hyster_And_Delay_Judge' */

  /* SystemInitialize for Chart: '<S208>/Chart' */
  rtb_bFlag_Mode_SwithConfirm = false;

  /* SystemInitialize for Chart: '<S116>/Sys_Working_Mode_selection' */
  Chery_E03_Hp_DW.is_active_c107_Chery_E03_Hp = 0U;
  Chery_E03_Hp_DW.is_c107_Chery_E03_Hp = Chery_E03_Hp_IN_NO_ACTIVE_CHILD_j;
  Chery_E03_Hp_B.AC_u8SysMode_Select = 0U;
}

/*
 * Output and update for atomic system: '<S1>/Mode_Selection'
 * Block description for: '<S1>/Mode_Selection'
 *   ModeSelection
 *   Decide the real work mode according the Mode request and the DTC
 */
void Chery_E03_Hp_Mode_Selection(void)
{
  /* local block i/o variables */
  boolean_T rtb_bFlag_Mode_SwithConfirm;
  uint8_T rtb_Merge;
  uint8_T rtb_Switch;
  uint16_T rtb_Abs;
  boolean_T rtb_Switch2;
  uint8_T rtb_Conversion_gly;
  uint8_T rtb_UnitDelay;
  uint8_T rtb_UnitDelay1;
  uint8_T rtb_UnitDelay2;
  int32_T rtb_Sum;
  uint8_T rtb_Conversion_g4;
  uint8_T rtb_Conversion_ak;
  uint8_T rtb_Conversion_hy;
  uint8_T rtb_Conversion_mn;
  uint8_T rtb_Conversion_gk;
  uint8_T rtb_Conversion_d;
  uint8_T rtb_Conversion_bz;
  uint8_T rtb_Conversion_i;
  uint8_T rtb_Conversion_g;
  uint8_T rtb_Conversion_ej;
  uint8_T rtb_Conversion_g0;
  uint8_T rtb_Conversion_fz;
  uint8_T rtb_Conversion_bi;
  uint8_T rtb_Conversion;
  uint8_T rtb_Conversion_d4;
  boolean_T bPressBalance;

  /* SwitchCase: '<S85>/Switch Case' incorporates:
   *  Constant: '<S118>/Constant2'
   *  Constant: '<S118>/Constant3'
   *  Constant: '<S118>/Constant4'
   *  Constant: '<S118>/Constant5'
   *  Constant: '<S121>/Constant'
   *  Constant: '<S121>/Constant1'
   *  Constant: '<S122>/Constant'
   *  Constant: '<S122>/Constant1'
   *  Constant: '<S124>/Constant'
   *  Constant: '<S124>/Constant1'
   *  Constant: '<S124>/Constant2'
   *  Constant: '<S128>/Constant2'
   *  Constant: '<S128>/Constant3'
   *  Constant: '<S128>/Constant4'
   *  Constant: '<S128>/Constant5'
   *  Constant: '<S148>/Constant'
   *  Constant: '<S156>/Constant'
   *  Constant: '<S168>/Constant'
   *  Constant: '<S169>/Constant'
   *  Inport: '<S127>/u8Mode_Req_Pre'
   *  RelationalOperator: '<S148>/Compare'
   *  RelationalOperator: '<S156>/Compare'
   *  RelationalOperator: '<S168>/Compare'
   *  RelationalOperator: '<S169>/Compare'
   *  UnitDelay: '<S1055>/Unit Delay'
   *  UnitDelay: '<S1070>/Unit Delay'
   *  UnitDelay: '<S1085>/Unit Delay'
   *  UnitDelay: '<S1115>/Unit Delay'
   */
  switch (Chery_E03_Hp_B.Merge) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S85>/Stop_Mode' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    rtb_Merge = Chery_E03_Hp_B.Merge;

    /* End of Outputs for SubSystem: '<S85>/Stop_Mode' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S85>/AC_Mode' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S119>/IfThenElse1' */
    /* SignalConversion: '<S119>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S119>/Constant'
     *  Constant: '<S138>/Constant'
     *  Constant: '<S139>/Constant'
     *  Logic: '<S119>/OR'
     *  RelationalOperator: '<S138>/Compare'
     *  RelationalOperator: '<S139>/Compare'
     *  UnitDelay: '<S1085>/Unit Delay'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_p0 == bFAILRISK_NO_0) &&
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh == bFAILRISK_NO_0),
       Chery_E03_Hp_B.Merge, u8MODE_FAILURE_4);

    /* End of Outputs for SubSystem: '<S119>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/AC_Mode' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S85>/AC_Chiller_Mode' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S118>/IfThenElse4' */
    rtb_Conversion_g4 = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_eb, u8MODE_FAILURE_4, u8MODE_CHILLER_3);

    /* End of Outputs for SubSystem: '<S118>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S118>/IfThenElse5' */
    rtb_Conversion_hy = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_eb, u8MODE_AC_1, u8MODE_ACCHILLER_2);

    /* End of Outputs for SubSystem: '<S118>/IfThenElse5' */

    /* Outputs for Atomic SubSystem: '<S118>/IfThenElse3' */
    rtb_Conversion_gk = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_p0, rtb_Conversion_g4, rtb_Conversion_hy);

    /* End of Outputs for SubSystem: '<S118>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S118>/IfThenElse2' */
    /* SignalConversion: '<S118>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S118>/Constant1'
     *  Constant: '<S118>/Constant2'
     *  Constant: '<S118>/Constant3'
     *  Constant: '<S118>/Constant4'
     *  Constant: '<S118>/Constant5'
     *  UnitDelay: '<S1055>/Unit Delay'
     *  UnitDelay: '<S1085>/Unit Delay'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh, u8MODE_FAILURE_4, rtb_Conversion_gk);

    /* End of Outputs for SubSystem: '<S118>/IfThenElse2' */
    /* End of Outputs for SubSystem: '<S85>/AC_Chiller_Mode' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S85>/Chiller_Mode' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S120>/IfThenElse1' */
    /* SignalConversion: '<S120>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S120>/Constant'
     *  Constant: '<S142>/Constant'
     *  Constant: '<S143>/Constant'
     *  Logic: '<S120>/OR'
     *  RelationalOperator: '<S142>/Compare'
     *  RelationalOperator: '<S143>/Compare'
     *  UnitDelay: '<S1055>/Unit Delay'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_eb == bFAILRISK_NO_0) &&
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh == bFAILRISK_NO_0),
       Chery_E03_Hp_B.Merge, u8MODE_FAILURE_4);

    /* End of Outputs for SubSystem: '<S120>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/Chiller_Mode' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S85>/Total_Dehum_Mode' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S129>/IfThenElse1' */
    /* SignalConversion: '<S129>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S129>/Constant'
     *  Constant: '<S188>/Constant'
     *  Constant: '<S189>/Constant'
     *  Logic: '<S129>/OR'
     *  RelationalOperator: '<S188>/Compare'
     *  RelationalOperator: '<S189>/Compare'
     *  UnitDelay: '<S1130>/Unit Delay'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_c4 == bFAILRISK_NO_0) &&
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh == bFAILRISK_NO_0),
       Chery_E03_Hp_B.Merge, u8MODE_FAILURE_4);

    /* End of Outputs for SubSystem: '<S129>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/Total_Dehum_Mode' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S85>/TotalDehum_Chiller_Mode' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S128>/IfThenElse4' */
    rtb_Conversion_ak = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_eb, u8MODE_FAILURE_4, u8MODE_CHILLER_3);

    /* End of Outputs for SubSystem: '<S128>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S128>/IfThenElse5' */
    rtb_Conversion_mn = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_eb, u8MODE_AC_1,
       u8MODE_TotalDehum_CHIL_6);

    /* End of Outputs for SubSystem: '<S128>/IfThenElse5' */

    /* Outputs for Atomic SubSystem: '<S128>/IfThenElse3' */
    rtb_Conversion_d = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_p0, rtb_Conversion_ak, rtb_Conversion_mn);

    /* End of Outputs for SubSystem: '<S128>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S128>/IfThenElse2' */
    /* SignalConversion: '<S128>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S128>/Constant1'
     *  Constant: '<S128>/Constant2'
     *  Constant: '<S128>/Constant3'
     *  Constant: '<S128>/Constant4'
     *  Constant: '<S128>/Constant5'
     *  UnitDelay: '<S1055>/Unit Delay'
     *  UnitDelay: '<S1085>/Unit Delay'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh, u8MODE_FAILURE_4, rtb_Conversion_d);

    /* End of Outputs for SubSystem: '<S128>/IfThenElse2' */
    /* End of Outputs for SubSystem: '<S85>/TotalDehum_Chiller_Mode' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S85>/HP_Mode' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S122>/IfThenElse2' */
    rtb_Conversion_bz = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_op == bFAILRISK_NO_0, u8MODE_HVCH_CMF_20,
       u8MODE_FAILURE_4);

    /* End of Outputs for SubSystem: '<S122>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S122>/IfThenElse1' */
    /* SignalConversion: '<S122>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S122>/Constant'
     *  Constant: '<S122>/Constant1'
     *  Constant: '<S154>/Constant'
     *  Constant: '<S155>/Constant'
     *  Constant: '<S156>/Constant'
     *  Logic: '<S122>/OR'
     *  RelationalOperator: '<S154>/Compare'
     *  RelationalOperator: '<S155>/Compare'
     *  RelationalOperator: '<S156>/Compare'
     *  UnitDelay: '<S1100>/Unit Delay'
     *  UnitDelay: '<S1115>/Unit Delay'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_my == bFAILRISK_NO_0) &&
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh == bFAILRISK_NO_0),
       Chery_E03_Hp_B.Merge, rtb_Conversion_bz);

    /* End of Outputs for SubSystem: '<S122>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/HP_Mode' */
    break;

   case 8:
   case 9:
   case 10:
   case 12:
    /* Outputs for IfAction SubSystem: '<S85>/HP_Chiller_HP_MDChil_Mode' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S121>/IfThenElse2' */
    rtb_Conversion_g = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_op == bFAILRISK_NO_0, u8MODE_HVCH_CMF_20,
       u8MODE_FAILURE_4);

    /* End of Outputs for SubSystem: '<S121>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S121>/IfThenElse1' */
    /* SignalConversion: '<S121>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S121>/Constant1'
     *  Constant: '<S146>/Constant'
     *  Constant: '<S147>/Constant'
     *  Constant: '<S148>/Constant'
     *  Constant: '<S149>/Constant'
     *  Logic: '<S121>/OR'
     *  RelationalOperator: '<S146>/Compare'
     *  RelationalOperator: '<S147>/Compare'
     *  RelationalOperator: '<S148>/Compare'
     *  RelationalOperator: '<S149>/Compare'
     *  UnitDelay: '<S1055>/Unit Delay'
     *  UnitDelay: '<S1100>/Unit Delay'
     *  UnitDelay: '<S1115>/Unit Delay'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((Chery_E03_Hp_DW.UnitDelay_DSTATE_my == bFAILRISK_NO_0) &&
        (Chery_E03_Hp_DW.UnitDelay_DSTATE_eb == bFAILRISK_NO_0)) &&
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh == bFAILRISK_NO_0),
       Chery_E03_Hp_B.Merge, rtb_Conversion_g);

    /* End of Outputs for SubSystem: '<S121>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/HP_Chiller_HP_MDChil_Mode' */
    break;

   case 20:
    /* Outputs for IfAction SubSystem: '<S85>/HVCH_CMF_Mode' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S125>/IfThenElse1' */
    /* SignalConversion: '<S125>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S125>/Constant'
     *  Constant: '<S176>/Constant'
     *  RelationalOperator: '<S176>/Compare'
     *  UnitDelay: '<S1115>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_op == bFAILRISK_NO_0,
       Chery_E03_Hp_B.Merge, u8MODE_FAILURE_31);

    /* End of Outputs for SubSystem: '<S125>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/HVCH_CMF_Mode' */
    break;

   case 21:
    /* Outputs for IfAction SubSystem: '<S85>/HVCH_CMFBat_Mode' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S124>/IfThenElse3' */
    rtb_Conversion_i = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_e == bFAILRISK_NO_0, u8MODE_HVCH_BAT_21,
       u8MODE_FAILURE_31);

    /* End of Outputs for SubSystem: '<S124>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S124>/IfThenElse2' */
    rtb_Conversion_ej = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_op == bFAILRISK_NO_0, u8MODE_HVCH_CMF_20,
       rtb_Conversion_i);

    /* End of Outputs for SubSystem: '<S124>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S124>/IfThenElse1' */
    /* SignalConversion: '<S124>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S124>/Constant'
     *  Constant: '<S124>/Constant1'
     *  Constant: '<S124>/Constant2'
     *  Constant: '<S165>/Constant'
     *  Constant: '<S167>/Constant'
     *  Constant: '<S168>/Constant'
     *  Constant: '<S169>/Constant'
     *  Logic: '<S124>/OR'
     *  RelationalOperator: '<S165>/Compare'
     *  RelationalOperator: '<S167>/Compare'
     *  RelationalOperator: '<S168>/Compare'
     *  RelationalOperator: '<S169>/Compare'
     *  UnitDelay: '<S1070>/Unit Delay'
     *  UnitDelay: '<S1115>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_op == bFAILRISK_NO_0) &&
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_e == bFAILRISK_NO_0),
       Chery_E03_Hp_B.Merge, rtb_Conversion_ej);

    /* End of Outputs for SubSystem: '<S124>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/HVCH_CMFBat_Mode' */
    break;

   case 22:
    /* Outputs for IfAction SubSystem: '<S85>/HVCH_Bat_Mode' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S123>/IfThenElse1' */
    /* SignalConversion: '<S123>/OutportBufferForu8Mode_Select_Pre' incorporates:
     *  Constant: '<S123>/Constant'
     *  Constant: '<S161>/Constant'
     *  RelationalOperator: '<S161>/Compare'
     *  UnitDelay: '<S1070>/Unit Delay'
     */
    rtb_Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_e == bFAILRISK_NO_0,
       Chery_E03_Hp_B.Merge, u8MODE_FAILURE_31);

    /* End of Outputs for SubSystem: '<S123>/IfThenElse1' */
    /* End of Outputs for SubSystem: '<S85>/HVCH_Bat_Mode' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S85>/Other_Default_Mode' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    /* SignalConversion: '<S126>/OutportBuffer_InsertedFor_u8Mode_Select_Pre_at_inport_0' incorporates:
     *  Constant: '<S126>/Constant'
     */
    rtb_Merge = u8MODE_STOP_0;

    /* End of Outputs for SubSystem: '<S85>/Other_Default_Mode' */
    break;
  }

  /* End of SwitchCase: '<S85>/Switch Case' */

  /* Outputs for Atomic SubSystem: '<S86>/IfThenElse3' */
  /* RelationalOperator: '<S196>/Compare' incorporates:
   *  Constant: '<S196>/Constant'
   *  Constant: '<S86>/Constant3'
   */
  rtb_Conversion_g0 = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Merge ==
    u8MODE_HVCH_CMF_BAT_22, u8MODE_HVCH_CMF_20, rtb_Merge);

  /* End of Outputs for SubSystem: '<S86>/IfThenElse3' */

  /* Outputs for Atomic SubSystem: '<S86>/IfThenElse2' */
  /* RelationalOperator: '<S195>/Compare' incorporates:
   *  Constant: '<S195>/Constant'
   *  Constant: '<S86>/Constant2'
   */
  rtb_Conversion_fz = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Merge ==
    u8MODE_HVCH_BAT_21, u8MODE_STOP_0, rtb_Conversion_g0);

  /* End of Outputs for SubSystem: '<S86>/IfThenElse2' */

  /* Outputs for Atomic SubSystem: '<S86>/IfThenElse1' */
  /* RelationalOperator: '<S194>/Compare' incorporates:
   *  Constant: '<S194>/Constant'
   *  Constant: '<S86>/Constant1'
   */
  rtb_Conversion_bi = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Merge ==
    u8MODE_HP_CHILMDCHIL_12, u8MODE_HP_CHIL_8, rtb_Conversion_fz);

  /* End of Outputs for SubSystem: '<S86>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S86>/IfThenElse' */
  /* Logic: '<S86>/Logical Operator' incorporates:
   *  Constant: '<S192>/Constant'
   *  Constant: '<S193>/Constant'
   *  Constant: '<S86>/Constant'
   *  RelationalOperator: '<S192>/Compare'
   *  RelationalOperator: '<S193>/Compare'
   */
  rtb_Conversion_gly = (uint8_T) Chery_E03_Hp_IfThenElse_a((rtb_Merge ==
    u8MODE_HP_MDCHIL_9) || (rtb_Merge == u8MODE_HP_BatHeat_10), u8MODE_HP_7,
    rtb_Conversion_bi);

  /* End of Outputs for SubSystem: '<S86>/IfThenElse' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S82>/Constant'
   *  RelationalOperator: '<S82>/Compare'
   */
  if (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1) {
    rtb_Switch = rtb_Conversion_gly;
  } else {
    rtb_Switch = rtb_Merge;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Chart: '<S88>/Eva_Cond_Calculation' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S109>/Constant'
   *  Constant: '<S110>/Constant'
   *  Constant: '<S111>/Constant'
   *  Constant: '<S112>/Constant'
   *  Constant: '<S114>/Constant'
   *  Constant: '<S88>/30_Min'
   *  Logic: '<S91>/Logical Operator'
   *  RelationalOperator: '<S108>/Compare'
   *  RelationalOperator: '<S109>/Compare'
   *  RelationalOperator: '<S110>/Compare'
   *  RelationalOperator: '<S111>/Compare'
   *  RelationalOperator: '<S112>/Compare'
   *  RelationalOperator: '<S114>/Compare'
   */
  if (((uint32_T)Chery_E03_Hp_DW.is_active_c106_Chery_E03_Hp) == 0U) {
    Chery_E03_Hp_DW.is_active_c106_Chery_E03_Hp = 1U;
    Chery_E03_Hp_DW.is_c106_Chery_E03_Hp = Chery_E03_Hp_IN_Condensate_Generate;
  } else if (((uint32_T)Chery_E03_Hp_DW.is_c106_Chery_E03_Hp) ==
             Chery_E03_Hp_IN_Condensate_Generate) {
    if (((((Chery_E03_Hp_B.UnitDelay != u8MODE_AC_1) &&
           (Chery_E03_Hp_B.UnitDelay != u8MODE_ACCHILLER_2)) &&
          (Chery_E03_Hp_B.UnitDelay != u8MODE_TotalDehum_5)) &&
         (Chery_E03_Hp_B.UnitDelay != u8MODE_TotalDehum_CHIL_6)) &&
        (Chery_E03_Hp_B.UnitDelay != u8MODE_TotalDehum_18)) {
      Chery_E03_Hp_DW.is_c106_Chery_E03_Hp = Chery_E03_Hp_IN_Condensate_Remove;
    } else {
      if (Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt < 18000) {
        if (Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt > 2147483646) {
          Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt = MAX_int32_T;
        } else {
          Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt++;
        }
      }

      Chery_E03_Hp_B.Out_s32Cond_Water = Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt;
    }
  } else if (((((Chery_E03_Hp_B.UnitDelay == u8MODE_AC_1) ||
                (Chery_E03_Hp_B.UnitDelay == u8MODE_ACCHILLER_2)) ||
               (Chery_E03_Hp_B.UnitDelay == u8MODE_TotalDehum_5)) ||
              (Chery_E03_Hp_B.UnitDelay == u8MODE_TotalDehum_CHIL_6)) ||
             (Chery_E03_Hp_B.UnitDelay == u8MODE_TotalDehum_18)) {
    Chery_E03_Hp_DW.is_c106_Chery_E03_Hp = Chery_E03_Hp_IN_Condensate_Generate;
  } else {
    if (Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt > 0) {
      if (((int32_T)Chery_E03_Hp_B.CMF_u16_QBlower_HVAC) >= 50) {
        if (Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt < -2147483645) {
          Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt = MIN_int32_T;
        } else {
          Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt -= 3;
        }
      } else if (Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt < -2147483647) {
        Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt = MIN_int32_T;
      } else {
        Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt--;
      }
    }

    Chery_E03_Hp_B.Out_s32Cond_Water = Chery_E03_Hp_DW.Loc_s32Cond_Water_Cnt;
  }

  /* End of Chart: '<S88>/Eva_Cond_Calculation' */

  /* Outputs for Atomic SubSystem: '<S89>/Hyster_And_Delay_Judge' */
  /* Constant: '<S89>/Constant' incorporates:
   *  Constant: '<S89>/Constant1'
   */
  rtb_Switch2 = ( Chery_E03_Hp_Hyster_And_Delay_Judge(3000,
    Chery_E03_Hp_B.Out_s32Cond_Water, 1800,
    &Chery_E03_Hp_ConstB.Hyster_And_Delay_Judge,
    &Chery_E03_Hp_DW.Hyster_And_Delay_Judge, Chery_E03_Hp_ConstP.pooled4) !=
                 false);

  /* End of Outputs for SubSystem: '<S89>/Hyster_And_Delay_Judge' */

  /* UnitDelay: '<S208>/Unit Delay' */
  rtb_UnitDelay = Chery_E03_Hp_DW.UnitDelay_DSTATE_f;

  /* UnitDelay: '<S208>/Unit Delay1' */
  rtb_UnitDelay1 = Chery_E03_Hp_DW.UnitDelay1_DSTATE_b;

  /* UnitDelay: '<S208>/Unit Delay2' */
  rtb_UnitDelay2 = Chery_E03_Hp_DW.UnitDelay2_DSTATE_d;

  /* Chart: '<S208>/Chart' incorporates:
   *  UnitDelay: '<S208>/Unit Delay'
   *  UnitDelay: '<S208>/Unit Delay1'
   *  UnitDelay: '<S208>/Unit Delay2'
   *  UnitDelay: '<S208>/Unit Delay3'
   */
  rtb_bFlag_Mode_SwithConfirm = ((rtb_Switch ==
    Chery_E03_Hp_DW.UnitDelay_DSTATE_f) && ((Chery_E03_Hp_DW.UnitDelay_DSTATE_f ==
    Chery_E03_Hp_DW.UnitDelay1_DSTATE_b) &&
    ((Chery_E03_Hp_DW.UnitDelay1_DSTATE_b == Chery_E03_Hp_DW.UnitDelay2_DSTATE_d)
     && (Chery_E03_Hp_DW.UnitDelay2_DSTATE_d ==
         Chery_E03_Hp_DW.UnitDelay3_DSTATE_h))));

  /* Outputs for Atomic SubSystem: '<S87>/IfThenElse1' */
  /* UnitDelay: '<S87>/Unit Delay' incorporates:
   *  Constant: '<S205>/Constant'
   *  Constant: '<S87>/Constant'
   *  RelationalOperator: '<S205>/Compare'
   */
  rtb_Conversion = (uint8_T) Chery_E03_Hp_IfThenElse_a
    (rtb_bFlag_Mode_SwithConfirm, rtb_Switch, Chery_E03_Hp_DW.UnitDelay_DSTATE_i);

  /* End of Outputs for SubSystem: '<S87>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S87>/IfThenElse' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_i = (uint8_T) Chery_E03_Hp_IfThenElse_a
    (rtb_Switch == u8MODE_FAILURE_4, u8MODE_FAILURE_4, rtb_Conversion);

  /* End of Outputs for SubSystem: '<S87>/IfThenElse' */

  /* Sum: '<S115>/Sum' */
  rtb_Sum = ((int32_T)Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10) - ((int32_T)
    Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10);

  /* Abs: '<S115>/Abs' */
  if (rtb_Sum < 0) {
    rtb_Abs = (uint16_T)((int32_T)(-rtb_Sum));
  } else {
    rtb_Abs = (uint16_T)rtb_Sum;
  }

  /* End of Abs: '<S115>/Abs' */

  /* Switch: '<S115>/Switch' incorporates:
   *  Constant: '<S115>/Constant'
   *  Constant: '<S115>/Pressure_Balance_Yes'
   *  Constant: '<S115>/bLogic_Const_0'
   *  RelationalOperator: '<S115>/Relational Operator'
   */
  if (rtb_Abs <= u16PBALANCE) {
    bPressBalance = bCONST_1;
  } else {
    bPressBalance = bCONST_0;
  }

  /* End of Switch: '<S115>/Switch' */

  /* Chart: '<S116>/Sys_Working_Mode_selection' incorporates:
   *  UnitDelay: '<S87>/Unit Delay'
   */
  /* None */
  if (((uint32_T)Chery_E03_Hp_DW.is_active_c107_Chery_E03_Hp) == 0U) {
    Chery_E03_Hp_DW.is_active_c107_Chery_E03_Hp = 1U;
    Chery_E03_Hp_DW.is_c107_Chery_E03_Hp = Chery_E03_Hp_IN_Mode_Stop;
  } else {
    switch (Chery_E03_Hp_DW.is_c107_Chery_E03_Hp) {
     case Chery_E03_Hp_IN_Mode_Chiller:
      if (Chery_E03_Hp_DW.UnitDelay_DSTATE_i != u8MODE_CHILLER_3) {
        Chery_E03_Hp_DW.is_c107_Chery_E03_Hp = Chery_E03_Hp_IN_Mode_Stop;
      } else {
        Chery_E03_Hp_B.AC_u8SysMode_Select = Chery_E03_Hp_DW.UnitDelay_DSTATE_i;

        /* exit: */
      }
      break;

     case Chery_E03_Hp_IN_Mode_Ref_Work:
      if (!Chery_E03_Hp_Ref_Work()) {
        Chery_E03_Hp_DW.is_c107_Chery_E03_Hp = Chery_E03_Hp_IN_Mode_Stop;
      } else {
        Chery_E03_Hp_B.AC_u8SysMode_Select = Chery_E03_Hp_DW.UnitDelay_DSTATE_i;

        /* exit: */
      }
      break;

     default:
      if ((Chery_E03_Hp_Ref_Work()) && bPressBalance) {
        Chery_E03_Hp_DW.is_c107_Chery_E03_Hp = Chery_E03_Hp_IN_Mode_Ref_Work;
        Chery_E03_Hp_B.AC_u8SysMode_Select = Chery_E03_Hp_DW.UnitDelay_DSTATE_i;
      } else if ((Chery_E03_Hp_DW.UnitDelay_DSTATE_i == u8MODE_CHILLER_3) &&
                 bPressBalance) {
        Chery_E03_Hp_DW.is_c107_Chery_E03_Hp = Chery_E03_Hp_IN_Mode_Chiller;
        Chery_E03_Hp_B.AC_u8SysMode_Select = Chery_E03_Hp_DW.UnitDelay_DSTATE_i;
      } else if (!Chery_E03_Hp_Ref_Work()) {
        Chery_E03_Hp_B.AC_u8SysMode_Select = Chery_E03_Hp_DW.UnitDelay_DSTATE_i;
      } else {
        Chery_E03_Hp_B.AC_u8SysMode_Select = u8MODE_STOP_0;
      }
      break;
    }
  }

  /* End of Chart: '<S116>/Sys_Working_Mode_selection' */

  /* SignalConversion: '<S37>/Signal Copy' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 = Chery_E03_Hp_B.AC_u8SysMode_Select;

  /* Outputs for Atomic SubSystem: '<S90>/IfThenElse' */
  /* Logic: '<S90>/Logical Operator' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S90>/Constant'
   *  RelationalOperator: '<S105>/Compare'
   */
  rtb_Conversion_d4 = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2 &&
    (rtb_Merge == u8MODE_HP_7), u8MODE_HVCH_CMF_20, rtb_Merge);

  /* End of Outputs for SubSystem: '<S90>/IfThenElse' */

  /* Update for UnitDelay: '<S208>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_f = rtb_Switch;

  /* Update for UnitDelay: '<S208>/Unit Delay1' */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_b = rtb_UnitDelay;

  /* Update for UnitDelay: '<S208>/Unit Delay2' */
  Chery_E03_Hp_DW.UnitDelay2_DSTATE_d = rtb_UnitDelay1;

  /* Update for UnitDelay: '<S208>/Unit Delay3' */
  Chery_E03_Hp_DW.UnitDelay3_DSTATE_h = rtb_UnitDelay2;
}

/*
 * Output and update for atomic system:
 *    '<S38>/Data Type Conversion'
 *    '<S38>/Data Type Conversion19'
 *    '<S38>/Data Type Conversion21'
 *    '<S38>/Data Type Conversion4'
 *    '<S38>/Data Type Conversion5'
 *    '<S433>/DataTypeConv_u16_'
 *    '<S437>/DataTypeConv_u16_'
 *    '<S1001>/DataTypeConv_u16_'
 *    '<S1005>/DataTypeConv_u16_'
 *    '<S1168>/Data Type Conversion'
 */
uint16_T Chery_E03_Hp_DataTypeConversion(uint16_T rtu_In1)
{
  /* Saturate: '<S212>/Saturation' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S38>/Data Type Conversion1'
 *    '<S38>/Data Type Conversion2'
 *    '<S38>/Data Type Conversion3'
 */
boolean_T Chery_E03_Hp_DataTypeConv_b_(uint8_T rtu_In1)
{
  /* RelationalOperator: '<S236>/Compare' incorporates:
   *  Constant: '<S236>/Constant'
   */
  return ((int32_T)rtu_In1) != 0;
}

/*
 * Output and update for atomic system:
 *    '<S38>/Data Type Conversion10'
 *    '<S38>/Data Type Conversion11'
 *    '<S38>/Data Type Conversion12'
 *    '<S38>/Data Type Conversion15'
 *    '<S38>/Data Type Conversion16'
 *    '<S38>/Data Type Conversion17'
 *    '<S38>/Data Type Conversion18'
 *    '<S38>/Data Type Conversion6'
 *    '<S38>/Data Type Conversion7'
 *    '<S38>/Data Type Conversion8'
 *    '<S38>/Data Type Conversion9'
 */
uint8_T Chery_E03_Hp_DataTypeConv_u8_(uint8_T rtu_In1)
{
  /* Saturate: '<S214>/Saturation' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S38>/Data Type Conversion13'
 *    '<S38>/Data Type Conversion14'
 *    '<Root>/DataTypeConv_b_'
 *    '<Root>/DataTypeConv_b_1'
 *    '<Root>/DataTypeConv_b_10'
 *    '<Root>/DataTypeConv_b_11'
 *    '<Root>/DataTypeConv_b_12'
 *    '<Root>/DataTypeConv_b_13'
 *    '<Root>/DataTypeConv_b_14'
 *    '<Root>/DataTypeConv_b_15'
 *    ...
 */
boolean_T Chery_E03_Hp_DataTypeConversion13(boolean_T rtu_In1)
{
  /* RelationalOperator: '<S237>/Compare' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S38>/Data Type Conversion20'
 *    '<S318>/DataTypeConv_u16_'
 *    '<S1045>/Data Type Conversion'
 *    '<S1045>/Data Type Conversion1'
 */
uint16_T Chery_E03_Hp_DataTypeConversion20(uint8_T rtu_In1)
{
  /* Saturate: '<S225>/Saturation' */
  return (uint16_T)rtu_In1;
}

/* Output and update for atomic system: '<S235>/DataTypeConv_u8_' */
uint8_T Chery_E03_Hp_DataTypeConv_u8__a(int16_T rtu_In1)
{
  uint8_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S242>/Saturation' */
  if (rtu_In1 > 255) {
    y = 255;
  } else if (rtu_In1 < 0) {
    y = 0;
  } else {
    y = (int32_T)rtu_In1;
  }

  rty_Out1_0 = (uint8_T)y;

  /* End of Saturate: '<S242>/Saturation' */
  return rty_Out1_0;
}

/*
 * System initialize for atomic system:
 *    '<S243>/Hyster_Judge'
 *    '<S1224>/Hyster_Judge'
 *    '<S1225>/Hyster_Judge'
 *    '<S1226>/Hyster_Judge'
 *    '<S1227>/Hyster_Judge'
 *    '<S1228>/Hyster_Judge'
 *    '<S1229>/Hyster_Judge'
 *    '<S1261>/Hyster_Judge'
 */
void Chery_E03_Hp_Hyster_Judge_Init(DW_Hyster_Judge_Chery_E03_Hp_T *localDW,
  boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S249>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;
}

/*
 * Output and update for atomic system:
 *    '<S243>/Hyster_Judge'
 *    '<S1224>/Hyster_Judge'
 *    '<S1225>/Hyster_Judge'
 *    '<S1226>/Hyster_Judge'
 *    '<S1227>/Hyster_Judge'
 *    '<S1228>/Hyster_Judge'
 *    '<S1229>/Hyster_Judge'
 *    '<S1261>/Hyster_Judge'
 */
boolean_T Chery_E03_Hp_Hyster_Judge(int16_T rtu_ParaJudgeUp, int16_T
  rtu_HyJudgeIn, int16_T rtu_ParaJudgeDown, DW_Hyster_Judge_Chery_E03_Hp_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;

  /* Switch: '<S249>/Switch4' incorporates:
   *  Constant: '<S249>/JudgeYes'
   *  Logic: '<S249>/NOT'
   *  RelationalOperator: '<S249>/RelationalOperator1'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  if (rtu_HyJudgeIn <= rtu_ParaJudgeDown) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S249>/Switch4' */

  /* Switch: '<S249>/Switch2' incorporates:
   *  Constant: '<S249>/JudgeYes'
   *  RelationalOperator: '<S249>/RelationalOperator3'
   *  UnitDelay: '<S249>/Unit Delay'
   */
  if (rtu_HyJudgeIn >= rtu_ParaJudgeUp) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S249>/Switch2' */

  /* Update for UnitDelay: '<S249>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/*
 * Output and update for atomic system:
 *    '<S243>/IfThenElse'
 *    '<S244>/IfThenElse'
 *    '<S245>/IfThenElse1'
 *    '<S322>/IfThenElse'
 *    '<S322>/IfThenElse1'
 *    '<S654>/IfThenElse1'
 *    '<S654>/IfThenElse2'
 *    '<S656>/IfThenElse2'
 *    '<S1055>/IfThenElse'
 *    '<S1055>/IfThenElse1'
 *    ...
 */
void Chery_E03_Hp_IfThenElse_c(boolean_T rtu_bIf, boolean_T rtu_Then, boolean_T
  rtu_Else, boolean_T *rty_Out)
{
  /* Switch: '<S250>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S253>/Conversion' */
    *rty_Out = rtu_Then;
  } else {
    /* DataTypeConversion: '<S253>/Conversion' */
    *rty_Out = rtu_Else;
  }

  /* End of Switch: '<S250>/Switch' */
}

/* System initialize for atomic system: '<S39>/Correctchargedetection' */
void Chery_E03_Hp_Correctchargedetection_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S243>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S243>/Hyster_Judge' */
}

/*
 * Output and update for atomic system: '<S39>/Correctchargedetection'
 * Block description for: '<S39>/Correctchargedetection'
 *   Correct charege detection module is used for the system charge detection.
 *   If the system charge detection <25(2.5bar) in the temperature >50(5 degree)celsius
 *   it means the system have the refrigerant leakage and can't work.
 */
void Chery_E03_Hp_Correctchargedetection(void)
{
  boolean_T rtb_Switch4;
  boolean_T rtb_Switch2;

  /* Switch: '<S243>/Switch4' incorporates:
   *  Constant: '<S243>/AC_On_Authority_No1'
   *  Constant: '<S243>/AC_On_Authority_Yes'
   *  Constant: '<S243>/PRCO_ac_charge_limit_test1'
   *  RelationalOperator: '<S243>/RelationalOperator3'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 > u16PCHARGE_FAIL) {
    rtb_Switch4 = bFAIL_RISK_No;
  } else {
    rtb_Switch4 = bFAIL_RISK_YES;
  }

  /* End of Switch: '<S243>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S243>/Hyster_Judge' */
  /* Constant: '<S243>/Text_Uplimit_acmode_set' incorporates:
   *  Constant: '<S243>/Text_downlumt_acmode_set'
   */
  rtb_Switch2 = ( Chery_E03_Hp_Hyster_Judge(s16TAD_UP_50,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, s16TAD_LOW_30, &Chery_E03_Hp_DW.Hyster_Judge,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S243>/Hyster_Judge' */

  /* Outputs for Atomic SubSystem: '<S243>/IfThenElse' */
  /* Constant: '<S243>/AC_On_Authority_No2' */
  Chery_E03_Hp_IfThenElse_c(rtb_Switch2, rtb_Switch4, bFAIL_RISK_No,
    &Chery_E03_Hp_B.Conversion_mh);

  /* End of Outputs for SubSystem: '<S243>/IfThenElse' */
}

/*
 * System initialize for atomic system:
 *    '<S258>/Subsystem'
 *    '<S275>/Subsystem'
 *    '<S276>/Subsystem'
 *    '<S306>/Subsystem'
 *    '<S307>/Subsystem'
 *    '<S610>/Subsystem'
 *    '<S611>/Subsystem'
 *    '<S666>/Subsystem'
 *    '<S667>/Subsystem'
 *    '<S656>/FirstRun'
 *    ...
 */
void Chery_E03_Hp_FirstRun_Init(boolean_T *rty_bFirstRun,
  DW_FirstRun_Chery_E03_Hp_T *localDW)
{
  /* SystemInitialize for Chart: '<S263>/FlagFirstRunJudge' */
  localDW->u16COUNT = 0U;
  *rty_bFirstRun = false;
}

/*
 * System reset for atomic system:
 *    '<S258>/Subsystem'
 *    '<S275>/Subsystem'
 *    '<S276>/Subsystem'
 *    '<S306>/Subsystem'
 *    '<S307>/Subsystem'
 *    '<S610>/Subsystem'
 *    '<S611>/Subsystem'
 *    '<S666>/Subsystem'
 *    '<S667>/Subsystem'
 *    '<S656>/FirstRun'
 *    ...
 */
void Chery_E03_Hp_FirstRun_Reset(boolean_T *rty_bFirstRun,
  DW_FirstRun_Chery_E03_Hp_T *localDW)
{
  /* SystemReset for Chart: '<S263>/FlagFirstRunJudge' */
  localDW->u16COUNT = 0U;
  *rty_bFirstRun = false;
}

/*
 * Output and update for atomic system:
 *    '<S258>/Subsystem'
 *    '<S275>/Subsystem'
 *    '<S276>/Subsystem'
 *    '<S306>/Subsystem'
 *    '<S307>/Subsystem'
 *    '<S610>/Subsystem'
 *    '<S611>/Subsystem'
 *    '<S666>/Subsystem'
 *    '<S667>/Subsystem'
 *    '<S656>/FirstRun'
 *    ...
 */
boolean_T Chery_E03_Hp_FirstRun(DW_FirstRun_Chery_E03_Hp_T *localDW, uint16_T
  rtp_u16DelayTime)
{
  boolean_T rty_bFirstRun_0;
  int32_T tmp;

  /* Chart: '<S263>/FlagFirstRunJudge' */
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

  /* End of Chart: '<S263>/FlagFirstRunJudge' */
  return rty_bFirstRun_0;
}

/* System initialize for atomic system: '<S244>/Hyster' */
void Chery_E03_Hp_Hyster_Init(DW_Hyster_Chery_E03_Hp_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_b;

  /* SystemInitialize for Atomic SubSystem: '<S258>/Subsystem' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_b, &localDW->Subsystem);

  /* End of SystemInitialize for SubSystem: '<S258>/Subsystem' */
}

/* Output and update for atomic system: '<S244>/Hyster' */
boolean_T Chery_E03_Hp_Hyster(int16_T rtu_DataIn, int16_T rtu_ParaJudgeUp,
  int16_T rtu_ParaJudgeDown, boolean_T rtu_OutputWhenUp, boolean_T
  rtu_OutputWhenDown, DW_Hyster_Chery_E03_Hp_T *localDW, real_T
  rtp_bParaInitUseUp)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_b;
  boolean_T rty_HyDataOut_0;

  /* Switch: '<S258>/Switch3' incorporates:
   *  Constant: '<S258>/Constant'
   */
  if (rtp_bParaInitUseUp != 0.0) {
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  } else {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S258>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S258>/Subsystem' */
  rtb_bFirstRun_b = ( Chery_E03_Hp_FirstRun(&localDW->Subsystem, 1) != false);

  /* End of Outputs for SubSystem: '<S258>/Subsystem' */

  /* Switch: '<S258>/Switch1' incorporates:
   *  UnitDelay: '<S258>/Unit Delay'
   */
  if (!rtb_bFirstRun_b) {
    rty_HyDataOut_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S258>/Switch1' */

  /* Switch: '<S258>/Switch4' incorporates:
   *  RelationalOperator: '<S258>/RelationalOperator1'
   */
  if (rtu_DataIn <= rtu_ParaJudgeDown) {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S258>/Switch4' */

  /* Switch: '<S258>/Switch2' incorporates:
   *  RelationalOperator: '<S258>/RelationalOperator3'
   */
  if (rtu_DataIn >= rtu_ParaJudgeUp) {
    /* DataTypeConversion: '<S260>/Conversion' */
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  }

  /* End of Switch: '<S258>/Switch2' */

  /* Update for UnitDelay: '<S258>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_HyDataOut_0;
  return rty_HyDataOut_0;
}

/* System initialize for atomic system: '<S39>/EVAFreezeDetection' */
void Chery_E03_Hp_EVAFreezeDetection_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S244>/Hyster' */
  Chery_E03_Hp_Hyster_Init(&Chery_E03_Hp_DW.Hyster);

  /* End of SystemInitialize for SubSystem: '<S244>/Hyster' */
}

/*
 * Output and update for atomic system: '<S39>/EVAFreezeDetection'
 * Block description for: '<S39>/EVAFreezeDetection'
 *   Eva Freeze detection
 *   -3 degree to 1 degree
 */
void Chery_E03_Hp_EVAFreezeDetection(void)
{
  boolean_T rtb_Conversion;

  /* Outputs for Atomic SubSystem: '<S244>/Hyster' */

  /* Constant: '<S244>/Def_Freezing_No_Limit' incorporates:
   *  Constant: '<S244>/Def_Freezing_Yes_Limit'
   *  Constant: '<S244>/Def_Freezing_no1'
   *  Constant: '<S244>/Def_Freezing_yes'
   */
  rtb_Conversion = ( Chery_E03_Hp_Hyster(Chery_E03_Hp_B.HpI_s16Teva_Front_A10,
    s16TEVA_NOR, s16TEVA_FAIL, bCONST_0, bCONST_1, &Chery_E03_Hp_DW.Hyster, 0.0)
                    != false);

  /* End of Outputs for SubSystem: '<S244>/Hyster' */

  /* Outputs for Atomic SubSystem: '<S244>/IfThenElse' */

  /* Logic: '<S244>/AND' incorporates:
   *  Constant: '<S244>/Def_Freezing_no'
   *  Constant: '<S254>/Constant'
   *  Constant: '<S255>/Constant'
   *  Constant: '<S256>/Constant'
   *  Constant: '<S257>/Constant'
   *  RelationalOperator: '<S254>/Compare'
   *  RelationalOperator: '<S255>/Compare'
   *  RelationalOperator: '<S256>/Compare'
   *  RelationalOperator: '<S257>/Compare'
   */
  Chery_E03_Hp_IfThenElse_c((((Chery_E03_Hp_B.Merge == u8MODE_AC_1) ||
    (Chery_E03_Hp_B.Merge == u8MODE_ACCHILLER_2)) || (Chery_E03_Hp_B.Merge ==
    u8MODE_TotalDehum_5)) || (Chery_E03_Hp_B.Merge == u8MODE_TotalDehum_CHIL_6),
    rtb_Conversion, bCONST_0, &Chery_E03_Hp_B.Conversion_p1);

  /* End of Outputs for SubSystem: '<S244>/IfThenElse' */
}

/*
 * Output and update for atomic system:
 *    '<S274>/IfThenElse'
 *    '<S274>/IfThenElse1'
 */
real_T Chery_E03_Hp_IfThenElse_m(boolean_T rtu_bIf, real_T rtu_Then, real_T
  rtu_Else)
{
  real_T rty_Out_0;

  /* Switch: '<S283>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S291>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S291>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S283>/Switch' */
  return rty_Out_0;
}

/*
 * System initialize for atomic system:
 *    '<S245>/Hyster'
 *    '<S245>/Hyster1'
 *    '<S246>/Hyster'
 *    '<S600>/Hyster'
 */
void Chery_E03_Hp_Hyster_f_Init(DW_Hyster_Chery_E03_Hp_n_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_m;

  /* InitializeConditions for UnitDelay: '<S275>/Unit Delay' */
  localDW->UnitDelay_DSTATE = false;

  /* SystemInitialize for Atomic SubSystem: '<S275>/Subsystem' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_m, &localDW->Subsystem);

  /* End of SystemInitialize for SubSystem: '<S275>/Subsystem' */
}

/*
 * System reset for atomic system:
 *    '<S245>/Hyster'
 *    '<S245>/Hyster1'
 *    '<S246>/Hyster'
 *    '<S600>/Hyster'
 */
void Chery_E03_Hp_Hyster_m_Reset(DW_Hyster_Chery_E03_Hp_n_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_m;

  /* InitializeConditions for UnitDelay: '<S275>/Unit Delay' */
  localDW->UnitDelay_DSTATE = false;

  /* SystemReset for Atomic SubSystem: '<S275>/Subsystem' */
  Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun_m, &localDW->Subsystem);

  /* End of SystemReset for SubSystem: '<S275>/Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S245>/Hyster'
 *    '<S245>/Hyster1'
 *    '<S246>/Hyster'
 *    '<S600>/Hyster'
 */
boolean_T Chery_E03_Hp_Hyster_n(uint16_T rtu_DataIn, uint16_T rtu_ParaJudgeUp,
  uint16_T rtu_ParaJudgeDown, boolean_T rtu_OutputWhenUp, boolean_T
  rtu_OutputWhenDown, DW_Hyster_Chery_E03_Hp_n_T *localDW, real_T
  rtp_bParaInitUseUp)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_m;
  boolean_T rty_HyDataOut_0;

  /* Switch: '<S275>/Switch3' incorporates:
   *  Constant: '<S275>/Constant'
   */
  if (rtp_bParaInitUseUp != 0.0) {
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  } else {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S275>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsystem' */
  rtb_bFirstRun_m = ( Chery_E03_Hp_FirstRun(&localDW->Subsystem, 1) != false);

  /* End of Outputs for SubSystem: '<S275>/Subsystem' */

  /* Switch: '<S275>/Switch1' incorporates:
   *  UnitDelay: '<S275>/Unit Delay'
   */
  if (!rtb_bFirstRun_m) {
    rty_HyDataOut_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S275>/Switch1' */

  /* Switch: '<S275>/Switch4' incorporates:
   *  RelationalOperator: '<S275>/RelationalOperator1'
   */
  if (rtu_DataIn <= rtu_ParaJudgeDown) {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S275>/Switch4' */

  /* Switch: '<S275>/Switch2' incorporates:
   *  RelationalOperator: '<S275>/RelationalOperator3'
   */
  if (rtu_DataIn >= rtu_ParaJudgeUp) {
    /* DataTypeConversion: '<S293>/Conversion' */
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  }

  /* End of Switch: '<S275>/Switch2' */

  /* Update for UnitDelay: '<S275>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_HyDataOut_0;
  return rty_HyDataOut_0;
}

/* Output and update for atomic system: '<S245>/IfThenElse' */
void Chery_E03_Hp_IfThenElse_e(boolean_T rtu_bIf, boolean_T rtu_Then, real_T
  rtu_Else, boolean_T *rty_Out)
{
  real_T rtb_Switch_ei;

  /* Switch: '<S277>/Switch' */
  if (rtu_bIf) {
    rtb_Switch_ei = rtu_Then ? 1.0 : 0.0;
  } else {
    rtb_Switch_ei = rtu_Else;
  }

  /* End of Switch: '<S277>/Switch' */

  /* DataTypeConversion: '<S303>/Conversion' */
  *rty_Out = (rtb_Switch_ei != 0.0);
}

/* System initialize for atomic system: '<S39>/LPfailuredetection' */
void Chery_E03_Hp_LPfailuredetection_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S245>/Hyster' */
  Chery_E03_Hp_Hyster_f_Init(&Chery_E03_Hp_DW.Hyster_n);

  /* End of SystemInitialize for SubSystem: '<S245>/Hyster' */

  /* SystemInitialize for Atomic SubSystem: '<S274>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_i);

  /* End of SystemInitialize for SubSystem: '<S274>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S274>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_i);

  /* End of SystemInitialize for SubSystem: '<S274>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S245>/Hyster1' */
  Chery_E03_Hp_Hyster_f_Init(&Chery_E03_Hp_DW.Hyster1);

  /* End of SystemInitialize for SubSystem: '<S245>/Hyster1' */
}

/*
 * Output and update for atomic system: '<S39>/LPfailuredetection'
 * Block description for: '<S39>/LPfailuredetection'
 *   Low pressure side protection
 *   LP side the pressure too low, means risk of icing and High pressure ratio.
 *   1.5~2bar
 */
void Chery_E03_Hp_LPfailuredetection(void)
{
  boolean_T rtb_Conversion;
  boolean_T rtb_SignalCopy_nd;
  boolean_T rtb_SignalCopy;

  /* Outputs for Atomic SubSystem: '<S245>/Hyster' */

  /* Constant: '<S245>/Def_Freezing_No_Limit1' incorporates:
   *  Constant: '<S245>/Def_Freezing_Yes_Limit1'
   *  Constant: '<S245>/PRCI_Failure_No_HP'
   *  Constant: '<S245>/PRCI_Failure_Yes_HP'
   */
  rtb_Conversion = ( Chery_E03_Hp_Hyster_n
                    (Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10, u16PRCI_NORFAIL_HP,
                     u16PRCI_FAIL_HP, bCONST_0, bCONST_1,
                     &Chery_E03_Hp_DW.Hyster_n, 0.0) != false);

  /* End of Outputs for SubSystem: '<S245>/Hyster' */

  /* Outputs for Atomic SubSystem: '<S245>/IfThenElse1' */

  /* Logic: '<S245>/AND1' incorporates:
   *  Constant: '<S245>/Def_Freezing_no2'
   *  Constant: '<S266>/Constant'
   *  Constant: '<S267>/Constant'
   *  Constant: '<S273>/Constant'
   *  RelationalOperator: '<S266>/Compare'
   *  RelationalOperator: '<S267>/Compare'
   *  RelationalOperator: '<S273>/Compare'
   */
  Chery_E03_Hp_IfThenElse_c(((Chery_E03_Hp_B.Merge == u8MODE_HP_7) ||
    (Chery_E03_Hp_B.Merge == u8MODE_HP_CHIL_8)) || (Chery_E03_Hp_B.Merge ==
    u8MODE_HP_MDCHIL_9), rtb_Conversion, bCONST_0, &rtb_Conversion);

  /* End of Outputs for SubSystem: '<S245>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S274>/DelayJudge' */

  /* RelationalOperator: '<S279>/Compare' incorporates:
   *  Constant: '<S279>/Constant'
   */
  rtb_SignalCopy_nd = ( Chery_E03_Hp_DelayJudge(rtb_Conversion ==
    bFAILRISK_YES_1, &Chery_E03_Hp_ConstB.DelayJudge_i,
    &Chery_E03_Hp_DW.DelayJudge_i) != false);

  /* End of Outputs for SubSystem: '<S274>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S274>/DelayJudge1' */

  /* RelationalOperator: '<S280>/Compare' incorporates:
   *  Constant: '<S280>/Constant'
   */
  rtb_SignalCopy = ( Chery_E03_Hp_DelayJudge(rtb_Conversion == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1_i, &Chery_E03_Hp_DW.DelayJudge1_i) != false);

  /* End of Outputs for SubSystem: '<S274>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S245>/Hyster1' */

  /* Constant: '<S245>/Def_Freezing_No_Limit' incorporates:
   *  Constant: '<S245>/Def_Freezing_Yes_Limit'
   *  Constant: '<S245>/Def_Freezing_no1'
   *  Constant: '<S245>/Def_Prco_overpressure_yes'
   */
  rtb_Conversion = ( Chery_E03_Hp_Hyster_n
                    (Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10, u16PRCI_NOR,
                     u16PRCI_FAIL, bCONST_0, bCONST_1, &Chery_E03_Hp_DW.Hyster1,
                     0.0) != false);

  /* End of Outputs for SubSystem: '<S245>/Hyster1' */

  /* Outputs for Atomic SubSystem: '<S274>/IfThenElse1' */

  /* UnitDelay: '<S274>/Unit Delay' incorporates:
   *  Constant: '<S274>/Constant'
   *  Constant: '<S274>/Constant1'
   */
  Chery_E03_Hp_DW.UnitDelay_DSTATE = (real_T) Chery_E03_Hp_IfThenElse_m
    (rtb_SignalCopy, (real_T)(bFAILRISK_NO_0 ? 1.0 : 0.0),
     Chery_E03_Hp_DW.UnitDelay_DSTATE);

  /* End of Outputs for SubSystem: '<S274>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S274>/IfThenElse' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE = (real_T) Chery_E03_Hp_IfThenElse_m
    (rtb_SignalCopy_nd, (real_T)(bFAILRISK_YES_1 ? 1.0 : 0.0),
     Chery_E03_Hp_DW.UnitDelay_DSTATE);

  /* End of Outputs for SubSystem: '<S274>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S245>/IfThenElse' */

  /* Logic: '<S245>/AND2' incorporates:
   *  Constant: '<S268>/Constant'
   *  Constant: '<S269>/Constant'
   *  Constant: '<S270>/Constant'
   *  Constant: '<S271>/Constant'
   *  Constant: '<S272>/Constant'
   *  RelationalOperator: '<S268>/Compare'
   *  RelationalOperator: '<S269>/Compare'
   *  RelationalOperator: '<S270>/Compare'
   *  RelationalOperator: '<S271>/Compare'
   *  RelationalOperator: '<S272>/Compare'
   *  UnitDelay: '<S274>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_e(((((Chery_E03_Hp_B.Merge == u8MODE_AC_1) ||
    (Chery_E03_Hp_B.Merge == u8MODE_ACCHILLER_2)) || (Chery_E03_Hp_B.Merge ==
    u8MODE_CHILLER_3)) || (Chery_E03_Hp_B.Merge == u8MODE_TotalDehum_5)) ||
    (Chery_E03_Hp_B.Merge == u8MODE_TotalDehum_CHIL_6), rtb_Conversion,
    Chery_E03_Hp_DW.UnitDelay_DSTATE, &Chery_E03_Hp_B.Conversion_a);

  /* End of Outputs for SubSystem: '<S245>/IfThenElse' */
}

/*
 * System initialize for atomic system:
 *    '<S246>/Hyster1'
 *    '<S600>/Hyster1'
 */
void Chery_E03_Hp_Hyster1_Init(DW_Hyster_Chery_E03_Hp_g_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_p;

  /* InitializeConditions for UnitDelay: '<S307>/Unit Delay' */
  localDW->UnitDelay_DSTATE = false;

  /* SystemInitialize for Atomic SubSystem: '<S307>/Subsystem' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_p, &localDW->Subsystem);

  /* End of SystemInitialize for SubSystem: '<S307>/Subsystem' */
}

/*
 * System reset for atomic system:
 *    '<S246>/Hyster1'
 *    '<S600>/Hyster1'
 */
void Chery_E03_Hp_Hyster1_Reset(DW_Hyster_Chery_E03_Hp_g_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_p;

  /* InitializeConditions for UnitDelay: '<S307>/Unit Delay' */
  localDW->UnitDelay_DSTATE = false;

  /* SystemReset for Atomic SubSystem: '<S307>/Subsystem' */
  Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun_p, &localDW->Subsystem);

  /* End of SystemReset for SubSystem: '<S307>/Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S246>/Hyster1'
 *    '<S600>/Hyster1'
 */
boolean_T Chery_E03_Hp_Hyster1(uint16_T rtu_DataIn, boolean_T rtu_OutputWhenUp,
  boolean_T rtu_OutputWhenDown, const ConstB_Hyster_Chery_E03_Hp_c_T *localC,
  DW_Hyster_Chery_E03_Hp_g_T *localDW, real_T rtp_bParaInitUseUp)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_p;
  boolean_T rty_HyDataOut_0;

  /* Switch: '<S307>/Switch3' incorporates:
   *  Constant: '<S307>/Constant'
   */
  if (rtp_bParaInitUseUp != 0.0) {
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  } else {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S307>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsystem' */
  rtb_bFirstRun_p = ( Chery_E03_Hp_FirstRun(&localDW->Subsystem, 1) != false);

  /* End of Outputs for SubSystem: '<S307>/Subsystem' */

  /* Switch: '<S307>/Switch1' incorporates:
   *  UnitDelay: '<S307>/Unit Delay'
   */
  if (!rtb_bFirstRun_p) {
    rty_HyDataOut_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S307>/Switch1' */

  /* Switch: '<S307>/Switch4' incorporates:
   *  RelationalOperator: '<S307>/RelationalOperator1'
   */
  if (rtu_DataIn <= localC->Conversion) {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S307>/Switch4' */

  /* Switch: '<S307>/Switch2' incorporates:
   *  RelationalOperator: '<S307>/RelationalOperator3'
   */
  if (rtu_DataIn >= localC->Conversion_p) {
    /* DataTypeConversion: '<S313>/Conversion' */
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  }

  /* End of Switch: '<S307>/Switch2' */

  /* Update for UnitDelay: '<S307>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_HyDataOut_0;
  return rty_HyDataOut_0;
}

/* System initialize for atomic system: '<S39>/PRCOfaidetection' */
void Chery_E03_Hp_PRCOfaidetection_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S246>/Hyster' */
  Chery_E03_Hp_Hyster_f_Init(&Chery_E03_Hp_DW.Hyster_b);

  /* End of SystemInitialize for SubSystem: '<S246>/Hyster' */

  /* SystemInitialize for Atomic SubSystem: '<S246>/Hyster1' */
  Chery_E03_Hp_Hyster1_Init(&Chery_E03_Hp_DW.Hyster1_e);

  /* End of SystemInitialize for SubSystem: '<S246>/Hyster1' */
}

/*
 * Output and update for atomic system: '<S39>/PRCOfaidetection'
 * Block description for: '<S39>/PRCOfaidetection'
 *   High pressure over presure detection
 *   24bar ~ 30bar
 */
void Chery_E03_Hp_PRCOfaidetection(void)
{
  boolean_T rtb_Conversion;
  boolean_T rtb_Conversion_k;

  /* Outputs for Atomic SubSystem: '<S246>/Hyster' */
  /* Constant: '<S246>/Def_Prco_Yes_Limit' incorporates:
   *  Constant: '<S246>/Def_Prco_No_Limit'
   *  Constant: '<S246>/Prco_no'
   *  Constant: '<S246>/Prco_yes'
   */
  rtb_Conversion_k = ( Chery_E03_Hp_Hyster_n
                      (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, u16PRCO_FAIL,
                       u16PRCO_NOR, bCONST_1, bCONST_0,
                       &Chery_E03_Hp_DW.Hyster_b, 0.0) != false);

  /* End of Outputs for SubSystem: '<S246>/Hyster' */

  /* Outputs for Atomic SubSystem: '<S246>/Hyster1' */
  /* Constant: '<S246>/Prco_yes1' incorporates:
   *  Constant: '<S246>/Prco_no1'
   */
  rtb_Conversion = ( Chery_E03_Hp_Hyster1
                    (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, bCONST_1, bCONST_0,
                     &Chery_E03_Hp_ConstB.Hyster1_e, &Chery_E03_Hp_DW.Hyster1_e,
                     0.0) != false);

  /* End of Outputs for SubSystem: '<S246>/Hyster1' */

  /* Switch: '<S246>/Switch' incorporates:
   *  Constant: '<S305>/Constant'
   *  Constant: '<S41>/Constant'
   *  RelationalOperator: '<S305>/Compare'
   */
  if (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1) {
    Chery_E03_Hp_B.bDTC_Sysmtem_Prco = rtb_Conversion;
  } else {
    Chery_E03_Hp_B.bDTC_Sysmtem_Prco = rtb_Conversion_k;
  }

  /* End of Switch: '<S246>/Switch' */
}

/* System initialize for atomic system: '<S247>/DelayJudge1' */
void Chery_E03_Hp_DelayJudge1_Init(DW_DelayJudge_Chery_E03_Hp_l_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge;

  /* SystemInitialize for Chart: '<S320>/JudgeTime' */
  Chery_E03_Hp_JudgeTime_Init(&rtb_bDelayJudge, &localDW->sf_JudgeTime);
}

/* Output and update for atomic system: '<S247>/DelayJudge1' */
boolean_T Chery_E03_Hp_DelayJudge1(boolean_T rtu_bJudge, uint8_T rtu_DelayTime,
  DW_DelayJudge_Chery_E03_Hp_l_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge;
  boolean_T rty_bDelayJudge_0;
  uint16_T rtb_Saturation_m;

  /* Outputs for Atomic SubSystem: '<S318>/DataTypeConv_u16_' */
  rtb_Saturation_m = (uint16_T) Chery_E03_Hp_DataTypeConversion20(rtu_DelayTime);

  /* End of Outputs for SubSystem: '<S318>/DataTypeConv_u16_' */

  /* Chart: '<S320>/JudgeTime' */
  Chery_E03_Hp_JudgeTime(rtu_bJudge, rtb_Saturation_m, &rtb_bDelayJudge,
    &localDW->sf_JudgeTime);

  /* SignalConversion: '<S318>/Signal Copy' */
  rty_bDelayJudge_0 = rtb_bDelayJudge;
  return rty_bDelayJudge_0;
}

/* System initialize for atomic system: '<S39>/Pressure_ratiofailuredetection' */
void Chery_E03_Hp_Pressure_ratiofailuredetection_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S247>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge1_Init(&Chery_E03_Hp_DW.DelayJudge1_a);

  /* End of SystemInitialize for SubSystem: '<S247>/DelayJudge1' */
}

/*
 * Output and update for atomic system: '<S39>/Pressure_ratiofailuredetection'
 * Block description for: '<S39>/Pressure_ratiofailuredetection'
 *   Pressure_ratio failure detection is used to protect the pressure ration
 *   ratio of pressure is 9~12
 */
void Chery_E03_Hp_Pressure_ratiofailuredetection(void)
{
  uint8_T rtb_Divide;
  boolean_T rtb_SignalCopy;

  /* Product: '<S247>/Divide' */
  rtb_Divide = (uint8_T)div_nzp_u32_near((uint32_T)
    Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, (uint32_T)
    Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10);

  /* Outputs for Atomic SubSystem: '<S247>/DelayJudge1' */
  /* RelationalOperator: '<S247>/RelationalOperator' incorporates:
   *  Constant: '<S247>/Pratio_Limit'
   *  Lookup_n-D: '<S247>/1-D Lookup Table'
   */
  rtb_SignalCopy = ( Chery_E03_Hp_DelayJudge1(((int32_T)rtb_Divide) >= 18,
    look1_iu8lu32n24tu16Ds32Iu8_binlcs(rtb_Divide, ((uint8_T *)
    &(HP_u16_Pratio_Delay.HP_u8_Pratio_u1[0])), ((uint16_T *)
    &(HP_u16_Pratio_Delay.HP_u16_Pratio_Delay_Time_y[0])), 3U),
    &Chery_E03_Hp_DW.DelayJudge1_a) != false);

  /* End of Outputs for SubSystem: '<S247>/DelayJudge1' */

  /* Switch: '<S247>/Switch5' incorporates:
   *  Constant: '<S247>/Def_Freezing_no1'
   *  Constant: '<S247>/Press_Ratio_Low'
   *  Product: '<S247>/Product1'
   *  RelationalOperator: '<S247>/RelationalOperator4'
   *  UnitDelay: '<S247>/UnitDelay1'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 <= ((uint16_T)
       (Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10 * ((uint16_T)u8RATIO_PRE_NOR))))
  {
    Chery_E03_Hp_DW.UnitDelay1_DSTATE_e = bCONST_0;
  }

  /* End of Switch: '<S247>/Switch5' */

  /* Switch: '<S247>/Switch4' incorporates:
   *  Constant: '<S247>/Def_Prco_overpressure_yes'
   *  UnitDelay: '<S247>/UnitDelay1'
   */
  if (rtb_SignalCopy) {
    Chery_E03_Hp_DW.UnitDelay1_DSTATE_e = bCONST_1;
  }

  /* End of Switch: '<S247>/Switch4' */
}

/* System initialize for atomic system: '<S1>/SystemFailureDetection' */
void Chery_E03_Hp_SystemFailureDetection_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S39>/Correctchargedetection'
   *
   * Block description for '<S39>/Correctchargedetection':
   *  Correct charege detection module is used for the system charge detection.
   *  If the system charge detection <25(2.5bar) in the temperature >50(5 degree)celsius
   *  it means the system have the refrigerant leakage and can't work.
   */
  Chery_E03_Hp_Correctchargedetection_Init();

  /* End of SystemInitialize for SubSystem: '<S39>/Correctchargedetection' */

  /* SystemInitialize for Atomic SubSystem: '<S39>/EVAFreezeDetection'
   *
   * Block description for '<S39>/EVAFreezeDetection':
   *  Eva Freeze detection
   *  -3 degree to 1 degree
   */
  Chery_E03_Hp_EVAFreezeDetection_Init();

  /* End of SystemInitialize for SubSystem: '<S39>/EVAFreezeDetection' */

  /* SystemInitialize for Atomic SubSystem: '<S39>/LPfailuredetection'
   *
   * Block description for '<S39>/LPfailuredetection':
   *  Low pressure side protection
   *  LP side the pressure too low, means risk of icing and High pressure ratio.
   *  1.5~2bar
   */
  Chery_E03_Hp_LPfailuredetection_Init();

  /* End of SystemInitialize for SubSystem: '<S39>/LPfailuredetection' */

  /* SystemInitialize for Atomic SubSystem: '<S39>/PRCOfaidetection'
   *
   * Block description for '<S39>/PRCOfaidetection':
   *  High pressure over presure detection
   *  24bar ~ 30bar
   */
  Chery_E03_Hp_PRCOfaidetection_Init();

  /* End of SystemInitialize for SubSystem: '<S39>/PRCOfaidetection' */

  /* SystemInitialize for Atomic SubSystem: '<S39>/Pressure_ratiofailuredetection'
   *
   * Block description for '<S39>/Pressure_ratiofailuredetection':
   *  Pressure_ratio failure detection is used to protect the pressure ration
   *  ratio of pressure is 9~12
   */
  Chery_E03_Hp_Pressure_ratiofailuredetection_Init();

  /* End of SystemInitialize for SubSystem: '<S39>/Pressure_ratiofailuredetection' */

  /* SystemInitialize for Atomic SubSystem: '<S322>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge);

  /* End of SystemInitialize for SubSystem: '<S322>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S322>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1);

  /* End of SystemInitialize for SubSystem: '<S322>/DelayJudge1' */
}

/*
 * Output and update for atomic system: '<S1>/SystemFailureDetection'
 * Block description for: '<S1>/SystemFailureDetection'
 *   System DTC detection
 */
void Chery_E03_Hp_SystemFailureDetection(void)
{
  boolean_T rtb_Conversion;
  boolean_T rtb_SignalCopy;
  boolean_T rtb_SignalCopy_m;

  /* Outputs for Atomic SubSystem: '<S39>/Correctchargedetection'
   *
   * Block description for '<S39>/Correctchargedetection':
   *  Correct charege detection module is used for the system charge detection.
   *  If the system charge detection <25(2.5bar) in the temperature >50(5 degree)celsius
   *  it means the system have the refrigerant leakage and can't work.
   */
  Chery_E03_Hp_Correctchargedetection();

  /* End of Outputs for SubSystem: '<S39>/Correctchargedetection' */

  /* Outputs for Atomic SubSystem: '<S39>/EVAFreezeDetection'
   *
   * Block description for '<S39>/EVAFreezeDetection':
   *  Eva Freeze detection
   *  -3 degree to 1 degree
   */
  Chery_E03_Hp_EVAFreezeDetection();

  /* End of Outputs for SubSystem: '<S39>/EVAFreezeDetection' */

  /* Outputs for Atomic SubSystem: '<S39>/LPfailuredetection'
   *
   * Block description for '<S39>/LPfailuredetection':
   *  Low pressure side protection
   *  LP side the pressure too low, means risk of icing and High pressure ratio.
   *  1.5~2bar
   */
  Chery_E03_Hp_LPfailuredetection();

  /* End of Outputs for SubSystem: '<S39>/LPfailuredetection' */

  /* Outputs for Atomic SubSystem: '<S39>/PRCOfaidetection'
   *
   * Block description for '<S39>/PRCOfaidetection':
   *  High pressure over presure detection
   *  24bar ~ 30bar
   */
  Chery_E03_Hp_PRCOfaidetection();

  /* End of Outputs for SubSystem: '<S39>/PRCOfaidetection' */

  /* Outputs for Atomic SubSystem: '<S39>/Pressure_ratiofailuredetection'
   *
   * Block description for '<S39>/Pressure_ratiofailuredetection':
   *  Pressure_ratio failure detection is used to protect the pressure ration
   *  ratio of pressure is 9~12
   */
  Chery_E03_Hp_Pressure_ratiofailuredetection();

  /* End of Outputs for SubSystem: '<S39>/Pressure_ratiofailuredetection' */

  /* Logic: '<S248>/LogicalOperator' incorporates:
   *  UnitDelay: '<S247>/UnitDelay1'
   */
  rtb_Conversion = (((((Chery_E03_Hp_B.Conversion_p1) ||
                       (Chery_E03_Hp_B.bDTC_Sysmtem_Prco)) ||
                      (Chery_E03_Hp_B.Conversion_mh)) ||
                     (Chery_E03_Hp_DW.UnitDelay1_DSTATE_e)) ||
                    (Chery_E03_Hp_B.Conversion_a));

  /* Outputs for Atomic SubSystem: '<S322>/DelayJudge' */

  /* RelationalOperator: '<S323>/Compare' incorporates:
   *  Constant: '<S323>/Constant'
   */
  rtb_SignalCopy = ( Chery_E03_Hp_DelayJudge(rtb_Conversion == bFAILRISK_YES_1,
    &Chery_E03_Hp_ConstB.DelayJudge, &Chery_E03_Hp_DW.DelayJudge) != false);

  /* End of Outputs for SubSystem: '<S322>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S322>/DelayJudge1' */

  /* RelationalOperator: '<S324>/Compare' incorporates:
   *  Constant: '<S324>/Constant'
   */
  rtb_SignalCopy_m = ( Chery_E03_Hp_DelayJudge(rtb_Conversion == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1, &Chery_E03_Hp_DW.DelayJudge1) != false);

  /* End of Outputs for SubSystem: '<S322>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S322>/IfThenElse1' */

  /* Constant: '<S322>/Constant1' incorporates:
   *  UnitDelay: '<S322>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_m, bFAILRISK_NO_0,
    Chery_E03_Hp_DW.UnitDelay_DSTATE_gh, &rtb_Conversion);

  /* End of Outputs for SubSystem: '<S322>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S322>/IfThenElse' */

  /* Constant: '<S322>/Constant' incorporates:
   *  UnitDelay: '<S322>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy, bFAILRISK_YES_1, rtb_Conversion,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_gh);

  /* End of Outputs for SubSystem: '<S322>/IfThenElse' */
}

/*
 * Output and update for atomic system:
 *    '<S837>/IfThenElse2'
 *    '<S837>/IfThenElse3'
 *    '<S837>/IfThenElse4'
 *    '<S356>/IfThenElse2'
 *    '<S356>/IfThenElse3'
 *    '<S356>/IfThenElse4'
 *    '<S456>/IfThenElse2'
 *    '<S456>/IfThenElse3'
 *    '<S456>/IfThenElse4'
 *    '<S920>/IfThenElse2'
 *    ...
 */
uint16_T Chery_E03_Hp_IfThenElse2(boolean_T rtu_bIf, uint16_T rtu_Then, uint16_T
  rtu_Else)
{
  uint16_T rty_Out_0;

  /* Switch: '<S848>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S851>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S851>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S848>/Switch' */
  return rty_Out_0;
}

/*
 * System initialize for atomic system:
 *    '<S860>/Chiller_edc_management'
 *    '<S470>/Chiller_edc_management'
 */
void Chery_E03_Hp_Chiller_edc_management_Init(int32_T *rty_s32NcompChil_Ctrl_Rpm,
  DW_Chiller_edc_management_Chery_E03_Hp_T *localDW)
{
  localDW->s32NCOMP_DOWN_LIMIT_p = 0;
  *rty_s32NcompChil_Ctrl_Rpm = 0;
}

/*
 * System reset for atomic system:
 *    '<S860>/Chiller_edc_management'
 *    '<S470>/Chiller_edc_management'
 */
void Chery_E03_Hp_Chiller_edc_management_Reset(int32_T
  *rty_s32NcompChil_Ctrl_Rpm, DW_Chiller_edc_management_Chery_E03_Hp_T *localDW)
{
  localDW->s32NCOMP_DOWN_LIMIT_p = 0;
  *rty_s32NcompChil_Ctrl_Rpm = 0;
}

/*
 * Output and update for atomic system:
 *    '<S860>/Chiller_edc_management'
 *    '<S470>/Chiller_edc_management'
 */
void Chery_E03_Hp_Chiller_edc_management(boolean_T rtu_bChil_EDC_Config, int32_T
  rtu_s32NcompChil_AfRisk_A10, int32_T *rty_s32NcompChil_Ctrl_Rpm,
  DW_Chiller_edc_management_Chery_E03_Hp_T *localDW)
{
  /* Chart: '<S860>/Chiller_edc_management' */
  /* None */
  if (rtu_bChil_EDC_Config) {
    if (rtu_s32NcompChil_AfRisk_A10 != s32NCOMP_STOP_0) {
      if (rtu_s32NcompChil_AfRisk_A10 >= localDW->s32NCOMP_DOWN_LIMIT_p) {
        *rty_s32NcompChil_Ctrl_Rpm = rtu_s32NcompChil_AfRisk_A10;
      } else {
        *rty_s32NcompChil_Ctrl_Rpm = localDW->s32NCOMP_DOWN_LIMIT_p;
      }
    } else {
      *rty_s32NcompChil_Ctrl_Rpm = s32NCOMP_STOP_0;
    }
  } else {
    *rty_s32NcompChil_Ctrl_Rpm = s32NCOMP_STOP_0;
  }

  /* End of Chart: '<S860>/Chiller_edc_management' */
}

/*
 * Output and update for atomic system: '<S861>/ChilPIparameters'
 * Block description for: '<S861>/ChilPIparameters'
 *   get chiller Kp ki and delt_T
 */
void Chery_E03_Hp_ChilPIparameters(void)
{
  /* Sum: '<S866>/Sum' */
  Chery_E03_Hp_B.s16Twat_Ctrl_delt_e = (int16_T)
    (Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 -
     Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10);

  /* Lookup_n-D: '<S866>/chil_Ki' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_m = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.s16Twat_Ctrl_delt_e, Chery_E03_Hp_ConstP.pooled36,
     Chery_E03_Hp_ConstP.pooled71, 8U);

  /* Lookup_n-D: '<S866>/chillercomp_kp' */
  Chery_E03_Hp_B.u16Ncomp_PrcoRisk_eb = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.s16Twat_Ctrl_delt_e, Chery_E03_Hp_ConstP.pooled37,
     Chery_E03_Hp_ConstP.pooled72, 9U);
}

/* System initialize for atomic system: '<S869>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S871>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_dy = false;
}

/* System reset for atomic system: '<S869>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S871>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_dy = false;
}

/* Output and update for atomic system: '<S869>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk(void)
{
  /* Switch: '<S871>/Switch3' incorporates:
   *  Constant: '<S871>/Pressure_Ratio_Risk_N'
   *  Constant: '<S876>/Constant'
   *  RelationalOperator: '<S876>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 <= 1150) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_dy = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S871>/Switch3' */

  /* Switch: '<S871>/Switch2' incorporates:
   *  Constant: '<S871>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S875>/Constant'
   *  RelationalOperator: '<S875>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 >= 1200) {
    Chery_E03_Hp_B.bRisk_EdcTout_p = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_EdcTout_p = Chery_E03_Hp_DW.UnitDelay_DSTATE_dy;
  }

  /* End of Switch: '<S871>/Switch2' */

  /* Lookup_n-D: '<S871>/EdcTout_Risk_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_m = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10, ((int16_T *)
      &(u16Edc_ToutReduce.s16EdcTout_Risk_u1[0])), ((uint16_T *)
      &(u16Edc_ToutReduce.u16Edc_ToutReduce_y[0])), 7U);

  /* Update for UnitDelay: '<S871>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_dy = Chery_E03_Hp_B.bRisk_EdcTout_p;
}

/* System initialize for atomic system: '<S869>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S872>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ff = false;
}

/* System reset for atomic system: '<S869>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S872>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ff = false;
}

/* Output and update for atomic system: '<S869>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection(void)
{
  /* Switch: '<S872>/Switch3' incorporates:
   *  Constant: '<S872>/Def_PRCOrisk_no'
   *  Constant: '<S878>/Constant'
   *  RelationalOperator: '<S878>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 <= u16PRCO_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_ff = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S872>/Switch3' */

  /* Switch: '<S872>/Switch2' incorporates:
   *  Constant: '<S872>/Def_PRCOrisk_yes'
   *  Constant: '<S877>/Constant'
   *  RelationalOperator: '<S877>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 > u16PRCO_RISK) {
    Chery_E03_Hp_B.bRisk_PRCO_n = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PRCO_n = Chery_E03_Hp_DW.UnitDelay_DSTATE_ff;
  }

  /* End of Switch: '<S872>/Switch2' */

  /* Lookup_n-D: '<S872>/Prco_offset Table1' */
  Chery_E03_Hp_B.u16Ncomp_PrcoRisk_eb = look1_iu16lu32n16_binlcse
    (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((uint16_T *)
      &(u16Ncomp_PrcoRisk.u16Prco_risk_u1[0])), ((uint16_T *)
      &(u16Ncomp_PrcoRisk.u16Ncomp_PrcoRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S872>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ff = Chery_E03_Hp_B.bRisk_PRCO_n;
}

/* Output and update for atomic system: '<S873>/DataTypeConv_s16_' */
int16_T Chery_E03_Hp_DataTypeConv_s16_(int32_T rtu_In1)
{
  int16_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S881>/Saturation' */
  if (rtu_In1 > 32767) {
    y = 32767;
  } else if (rtu_In1 < -32768) {
    y = -32768;
  } else {
    y = rtu_In1;
  }

  rty_Out1_0 = (int16_T)y;

  /* End of Saturate: '<S881>/Saturation' */
  return rty_Out1_0;
}

/* System initialize for atomic system: '<S869>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S873>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_oy = false;
}

/* System reset for atomic system: '<S869>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S873>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_oy = false;
}

/* Output and update for atomic system: '<S869>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction(void)
{
  int32_T rtb_Sum;
  int16_T rtb_Saturation;

  /* Sum: '<S873>/Sum' */
  rtb_Sum = ((int32_T)Chery_E03_Hp_B.HpI_u16Power_Max) - ((int32_T)
    Chery_E03_Hp_B.HpI_u16PowerComp);

  /* Switch: '<S873>/Switch2' incorporates:
   *  Constant: '<S873>/Def_Pcomprisk_No'
   *  Constant: '<S880>/Constant'
   *  RelationalOperator: '<S880>/Compare'
   */
  if (rtb_Sum >= ((int32_T)s16POWER_GAP_NORISK)) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_oy = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S873>/Switch2' */

  /* Switch: '<S873>/Switch1' incorporates:
   *  Constant: '<S873>/Def_Pcomprisk_yes_set'
   *  Constant: '<S879>/Constant'
   *  RelationalOperator: '<S879>/Compare'
   */
  if (rtb_Sum <= ((int32_T)s16POWER_GAP_RISK)) {
    Chery_E03_Hp_B.bRisk_PowerLimitation_d = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PowerLimitation_d = Chery_E03_Hp_DW.UnitDelay_DSTATE_oy;
  }

  /* End of Switch: '<S873>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S873>/DataTypeConv_s16_' */
  rtb_Saturation = (int16_T) Chery_E03_Hp_DataTypeConv_s16_(rtb_Sum);

  /* End of Outputs for SubSystem: '<S873>/DataTypeConv_s16_' */

  /* Lookup_n-D: '<S873>/Power_cpr_diff' */
  Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk_j = look1_is16lu32n16tu16_binlcse
    (rtb_Saturation, ((int16_T *)&(u16Ncomp_PowRisk.s16Power_Comp_gap_u1[0])),
     ((uint16_T *)&(u16Ncomp_PowRisk.u16Ncomp_PowRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S873>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_oy = Chery_E03_Hp_B.bRisk_PowerLimitation_d;
}

/* System initialize for atomic system: '<S862>/Chiller_Risk_corrector' */
void Chery_E03_Hp_Chiller_Risk_corrector_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S869>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_Init();

  /* End of SystemInitialize for SubSystem: '<S869>/EdcToutRisk' */

  /* SystemInitialize for Atomic SubSystem: '<S869>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_Init();

  /* End of SystemInitialize for SubSystem: '<S869>/PRCO_riskcorrection' */

  /* SystemInitialize for Atomic SubSystem: '<S869>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_Init();

  /* End of SystemInitialize for SubSystem: '<S869>/Pcomp_correction' */
}

/* System reset for atomic system: '<S862>/Chiller_Risk_corrector' */
void Chery_E03_Hp_Chiller_Risk_corrector_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S869>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_Reset();

  /* End of SystemReset for SubSystem: '<S869>/EdcToutRisk' */

  /* SystemReset for Atomic SubSystem: '<S869>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_Reset();

  /* End of SystemReset for SubSystem: '<S869>/PRCO_riskcorrection' */

  /* SystemReset for Atomic SubSystem: '<S869>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_Reset();

  /* End of SystemReset for SubSystem: '<S869>/Pcomp_correction' */
}

/*
 * Output and update for atomic system: '<S862>/Chiller_Risk_corrector'
 * Block description for: '<S862>/Chiller_Risk_corrector'
 *   chiller mode risk value for EDC rpm compensation
 */
void Chery_E03_Hp_Chiller_Risk_corrector(void)
{
  /* Outputs for Atomic SubSystem: '<S869>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk();

  /* End of Outputs for SubSystem: '<S869>/EdcToutRisk' */

  /* Outputs for Atomic SubSystem: '<S869>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection();

  /* End of Outputs for SubSystem: '<S869>/PRCO_riskcorrection' */

  /* Outputs for Atomic SubSystem: '<S869>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction();

  /* End of Outputs for SubSystem: '<S869>/Pcomp_correction' */

  /* Logic: '<S874>/OR' */
  Chery_E03_Hp_B.bChilRisk_Comp_e = (((Chery_E03_Hp_B.bRisk_PRCO_n) ||
    (Chery_E03_Hp_B.bRisk_PowerLimitation_d)) || (Chery_E03_Hp_B.bRisk_EdcTout_p));

  /* MinMax: '<S874>/Max' */
  if (Chery_E03_Hp_B.u16Ncomp_PrcoRisk_eb >
      Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk_j) {
    Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk_j =
      Chery_E03_Hp_B.u16Ncomp_PrcoRisk_eb;
  }

  if (Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk_j <=
      Chery_E03_Hp_B.u16Ncomp_Tout_Risk_m) {
    Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk_j =
      Chery_E03_Hp_B.u16Ncomp_Tout_Risk_m;
  }

  /* End of MinMax: '<S874>/Max' */
}

/*
 * System initialize for atomic system:
 *    '<S883>/bEDC_Start_Config_Decision'
 *    '<S492>/bEDC_Start_Config_Decision'
 */
void Chery_E03_Hp_bEDC_Start_Config_Decision_Init(boolean_T
  *rty_bChil_EDC_Config, DW_bEDC_Start_Config_Decision_Chery_E03_Hp_T *localDW)
{
  localDW->u16Count_EDC_Config = 0U;
  *rty_bChil_EDC_Config = false;
}

/*
 * System reset for atomic system:
 *    '<S883>/bEDC_Start_Config_Decision'
 *    '<S492>/bEDC_Start_Config_Decision'
 */
void Chery_E03_Hp_bEDC_Start_Config_Decision_Reset(boolean_T
  *rty_bChil_EDC_Config, DW_bEDC_Start_Config_Decision_Chery_E03_Hp_T *localDW)
{
  localDW->u16Count_EDC_Config = 0U;
  *rty_bChil_EDC_Config = false;
}

/*
 * Output and update for atomic system:
 *    '<S883>/bEDC_Start_Config_Decision'
 *    '<S492>/bEDC_Start_Config_Decision'
 */
void Chery_E03_Hp_bEDC_Start_Config_Decision(boolean_T
  rtu_bChiller_EDC_Start_Config, boolean_T *rty_bChil_EDC_Config,
  DW_bEDC_Start_Config_Decision_Chery_E03_Hp_T *localDW)
{
  /* Chart: '<S883>/bEDC_Start_Config_Decision' */
  /* None */
  if (rtu_bChiller_EDC_Start_Config) {
    if (localDW->u16Count_EDC_Config == u16TIMT_EDC_CONF_5) {
      *rty_bChil_EDC_Config = true;
    } else {
      localDW->u16Count_EDC_Config += u16COUNT_1;
      *rty_bChil_EDC_Config = false;
    }
  } else {
    localDW->u16Count_EDC_Config = u16COUNT_0;
    *rty_bChil_EDC_Config = false;
  }

  /* End of Chart: '<S883>/bEDC_Start_Config_Decision' */
}

/* System initialize for atomic system: '<S832>/Chiller_EDC_Start_Configulation' */
void Chery_E03_Hp_Chiller_EDC_Start_Configulation_Init(void)
{
  /* SystemInitialize for Chart: '<S883>/bEDC_Start_Config_Decision' */
  Chery_E03_Hp_bEDC_Start_Config_Decision_Init
    (&Chery_E03_Hp_B.bChil_EDC_Config_l,
     &Chery_E03_Hp_DW.sf_bEDC_Start_Config_Decision);
}

/* System reset for atomic system: '<S832>/Chiller_EDC_Start_Configulation' */
void Chery_E03_Hp_Chiller_EDC_Start_Configulation_Reset(void)
{
  /* SystemReset for Chart: '<S883>/bEDC_Start_Config_Decision' */
  Chery_E03_Hp_bEDC_Start_Config_Decision_Reset
    (&Chery_E03_Hp_B.bChil_EDC_Config_l,
     &Chery_E03_Hp_DW.sf_bEDC_Start_Config_Decision);
}

/*
 * Output and update for atomic system: '<S832>/Chiller_EDC_Start_Configulation'
 * Block description for: '<S832>/Chiller_EDC_Start_Configulation'
 *   edc startup condition judge
 */
void Chery_E03_Hp_Chiller_EDC_Start_Configulation(void)
{
  /* Chart: '<S883>/bEDC_Start_Config_Decision' incorporates:
   *  Constant: '<S882>/Position_shutoff Valeo Open'
   *  Constant: '<S882>/V_Air_condensor_lowlimit'
   *  Constant: '<S882>/V_Air_condensor_lowlimit1'
   *  Constant: '<S882>/V_Air_condensor_lowlimit2'
   *  Constant: '<S884>/Constant'
   *  Logic: '<S882>/LogicalOperator'
   *  RelationalOperator: '<S882>/Comparison10'
   *  RelationalOperator: '<S882>/Comparison2'
   *  RelationalOperator: '<S882>/Comparison3'
   *  RelationalOperator: '<S882>/Comparison4'
   *  RelationalOperator: '<S884>/Compare'
   */
  Chery_E03_Hp_bEDC_Start_Config_Decision
    (((((Chery_E03_Hp_B.AC_u16Vair_Condensor_E >= u16VAIR_CONDMIN) &&
        (Chery_E03_Hp_B.HpI_u16EXV_Chil_Pos >= u16CHIL_EXV_MIN_START)) &&
       (Chery_E03_Hp_B.HpI_u16Power_Max >= u16EDC_POWERMIN)) &&
      (Chery_E03_Hp_B.HpI_u16Ncomp_Max >= u16EDC_RPMMIN)) && (((int32_T)
       Chery_E03_Hp_B.HpI_u16Pump_Bat) > 30), &Chery_E03_Hp_B.bChil_EDC_Config_l,
     &Chery_E03_Hp_DW.sf_bEDC_Start_Config_Decision);
}

/* System initialize for atomic system: '<S371>/EDC_Estimation_AC' */
void Chery_E03_Hp_EDC_Estimation_AC_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S383>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_hb = 0U;
}

/* System reset for atomic system: '<S371>/EDC_Estimation_AC' */
void Chery_E03_Hp_EDC_Estimation_AC_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S383>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_hb = 0U;
}

/*
 * Output and update for atomic system: '<S371>/EDC_Estimation_AC'
 * Block description for: '<S371>/EDC_Estimation_AC'
 *   edc forward rpm estimation
 */
void Chery_E03_Hp_EDC_Estimation_AC(void)
{
  int32_T u0;

  /* Product: '<S383>/Multiply1' incorporates:
   *  Product: '<S383>/Multiply'
   *  Sum: '<S383>/Sum'
   *  UnitDelay: '<S383>/Unit Delay'
   */
  u0 = asr_s32(((int32_T)((uint32_T)(((uint32_T)
    Chery_E03_Hp_DW.UnitDelay_DSTATE_hb) * 3U))) + ((int32_T)
    Chery_E03_Hp_B.HpI_u8BlwVol_Real_A10), 2U);

  /* Saturate: '<S383>/Saturation' incorporates:
   *  UnitDelay: '<S383>/Unit Delay'
   */
  if (u0 > 150) {
    u0 = 150;
  }

  Chery_E03_Hp_DW.UnitDelay_DSTATE_hb = (uint8_T)u0;

  /* End of Saturate: '<S383>/Saturation' */

  /* Lookup_n-D: '<S378>/Ncomp_AC_Est' incorporates:
   *  Sum: '<S378>/Subtract'
   *  UnitDelay: '<S383>/Unit Delay'
   */
  Chery_E03_Hp_B.u16Ncomp_PrcoRisk_l = look2_is16u8lu32n16tu16_binlcse((int16_T)
    (Chery_E03_Hp_B.AC_s16Tairevaup_E - Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10),
    Chery_E03_Hp_DW.UnitDelay_DSTATE_hb, ((int16_T *)
    &(u16Ncomp_AC_Est.s16Teva_load_u1[0])), ((uint8_T *)
    &(u16Ncomp_AC_Est.u8HVAC_BlwVol_u2[0])), ((uint16_T *)
    &(u16Ncomp_AC_Est.u16Ncomp_AC_Est_y[0])), Chery_E03_Hp_ConstP.pooled15, 7U);
}

/*
 * Output and update for atomic system: '<S371>/Ncomp_Estimation_Chiller'
 * Block description for: '<S371>/Ncomp_Estimation_Chiller'
 *   edc for ac_chiller mode compensation for chiller
 */
void Chery_E03_Hp_Ncomp_Estimation_Chiller(void)
{
  /* Switch: '<S381>/Switch' incorporates:
   *  Constant: '<S381>/Constant1'
   *  Constant: '<S384>/Constant'
   *  Lookup_n-D: '<S381>/Ncomp_exv_estimation'
   *  RelationalOperator: '<S384>/Compare'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  if (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_ACCHILLER_2) {
    Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l = look1_iu16lu32n16_binlcse
      (Chery_E03_Hp_B.HpI_u16EXV_Chil_Pos, ((uint16_T *)
        &(u16Ncomp_EXVEst.u16Postion_ChillerEXV_u1[0])), ((uint16_T *)
        &(u16Ncomp_EXVEst.u16Ncomp_EXVEst_y[0])), 7U);
  } else {
    Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l = u16NCOMP_STOP_0;
  }

  /* End of Switch: '<S381>/Switch' */
}

/*
 * Output and update for atomic system: '<S371>/PIparameters'
 * Block description for: '<S371>/PIparameters'
 *   AC_EDC_PI parameter
 */
void Chery_E03_Hp_PIparameters(void)
{
  /* Lookup_n-D: '<S382>/Kp_EDC_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l = look2_is16u8lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.HpI_u8BlwVol_Real_A10,
     ((int16_T *)&(u16Kp_EDC_ACChil.s16TEMP_Text_u1[0])), ((uint8_T *)
      &(u16Kp_EDC_ACChil.u8HVAC_BlwVol_u2[0])), ((uint16_T *)
      &(u16Kp_EDC_ACChil.u16Kp_EDC_ACChil_y[0])), Chery_E03_Hp_ConstP.pooled15,
     7U);

  /* Sum: '<S382>/Sum' */
  Chery_E03_Hp_B.s16Teva_Ctrl_Delta = (int16_T)
    (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 -
     Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10);

  /* Lookup_n-D: '<S382>/Time Constant for the Teva_EDC Control' */
  Chery_E03_Hp_B.s16Ti_Comp_AC = look1_is16lu32n16Ds32_binlcs
    (Chery_E03_Hp_B.s16Teva_Ctrl_Delta, ((int16_T *)
      &(AC_s16Teva_CtrlTi.AC_s16Teva_CtrlDelta[0])), ((int16_T *)
      &(AC_s16Teva_CtrlTi.AC_s16Teva_CtrlTi_y[0])), 7U);
}

/*
 * Output and update for atomic system: '<S391>/EDC_Rpm_risk'
 * Block description for: '<S391>/EDC_Rpm_risk'
 *   This module for edc rpm calulation
 */
void Chery_E03_Hp_EDC_Rpm_risk(void)
{
  /* Constant: '<S394>/Def_Pcomprisk_yes_set1' */
  Chery_E03_Hp_B.bRisk_Comp_e = bFAIL_NO_RISK_0;
}

/* System initialize for atomic system: '<S391>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_h_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S395>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_d2 = false;
}

/* System reset for atomic system: '<S391>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_m_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S395>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_d2 = false;
}

/* Output and update for atomic system: '<S391>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_b(void)
{
  /* Switch: '<S395>/Switch3' incorporates:
   *  Constant: '<S395>/Pressure_Ratio_Risk_N'
   *  Constant: '<S400>/Constant'
   *  RelationalOperator: '<S400>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 <= 1150) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_d2 = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S395>/Switch3' */

  /* Switch: '<S395>/Switch2' incorporates:
   *  Constant: '<S395>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S399>/Constant'
   *  RelationalOperator: '<S399>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 >= 1200) {
    Chery_E03_Hp_B.bRisk_EdcTout_n = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_EdcTout_n = Chery_E03_Hp_DW.UnitDelay_DSTATE_d2;
  }

  /* End of Switch: '<S395>/Switch2' */

  /* Lookup_n-D: '<S395>/EdcTout_Risk_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10, ((int16_T *)
      &(u16Edc_ToutReduce.s16EdcTout_Risk_u1[0])), ((uint16_T *)
      &(u16Edc_ToutReduce.u16Edc_ToutReduce_y[0])), 7U);

  /* Update for UnitDelay: '<S395>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_d2 = Chery_E03_Hp_B.bRisk_EdcTout_n;
}

/* System initialize for atomic system: '<S391>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_m_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S396>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_cp = false;
}

/* System reset for atomic system: '<S391>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_i_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S396>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_cp = false;
}

/* Output and update for atomic system: '<S391>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_i(void)
{
  /* Switch: '<S396>/Switch3' incorporates:
   *  Constant: '<S396>/Def_PRCOrisk_no'
   *  Constant: '<S402>/Constant'
   *  RelationalOperator: '<S402>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 <= u16PRCO_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_cp = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S396>/Switch3' */

  /* Switch: '<S396>/Switch2' incorporates:
   *  Constant: '<S396>/Def_PRCOrisk_yes'
   *  Constant: '<S401>/Constant'
   *  RelationalOperator: '<S401>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 > u16PRCO_RISK) {
    Chery_E03_Hp_B.bRisk_PRCO_o = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PRCO_o = Chery_E03_Hp_DW.UnitDelay_DSTATE_cp;
  }

  /* End of Switch: '<S396>/Switch2' */

  /* Lookup_n-D: '<S396>/Prco_offset' */
  Chery_E03_Hp_B.u16Ncomp_PrcoRisk_l = look1_iu16lu32n16_binlcse
    (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((uint16_T *)
      &(u16ACNcomp_PrcoRisk.u16ACPrco_risk_u1[0])), ((uint16_T *)
      &(u16ACNcomp_PrcoRisk.u16ACNcomp_PrcoRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S396>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_cp = Chery_E03_Hp_B.bRisk_PRCO_o;
}

/* System initialize for atomic system: '<S391>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_a_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S397>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ih = false;
}

/* System reset for atomic system: '<S391>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_p_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S397>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ih = false;
}

/* Output and update for atomic system: '<S391>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_d(void)
{
  int16_T rtb_Sum;

  /* Sum: '<S397>/Sum' */
  rtb_Sum = (int16_T)(((int16_T)Chery_E03_Hp_B.HpI_u16Power_Max) - ((int16_T)
    Chery_E03_Hp_B.HpI_u16PowerComp));

  /* Switch: '<S397>/Switch2' incorporates:
   *  Constant: '<S397>/Def_Pcomprisk_No'
   *  Constant: '<S404>/Constant'
   *  RelationalOperator: '<S404>/Compare'
   */
  if (rtb_Sum >= s16POWER_GAP_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_ih = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S397>/Switch2' */

  /* Switch: '<S397>/Switch1' incorporates:
   *  Constant: '<S397>/Def_Pcomprisk_yes_set'
   *  Constant: '<S403>/Constant'
   *  RelationalOperator: '<S403>/Compare'
   */
  if (rtb_Sum <= s16POWER_GAP_RISK) {
    Chery_E03_Hp_B.bRisk_PowerLimitation_o = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PowerLimitation_o = Chery_E03_Hp_DW.UnitDelay_DSTATE_ih;
  }

  /* End of Switch: '<S397>/Switch1' */

  /* Lookup_n-D: '<S397>/Power_cpr_diff' */
  Chery_E03_Hp_B.u16Ncomp_PowRisk_e = look1_is16lu32n16tu16_binlcse(rtb_Sum,
    ((int16_T *)&(u16Ncomp_PowRisk.s16Power_Comp_gap_u1[0])), ((uint16_T *)
    &(u16Ncomp_PowRisk.u16Ncomp_PowRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S397>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ih = Chery_E03_Hp_B.bRisk_PowerLimitation_o;
}

/* System initialize for atomic system: '<S391>/T_eva_freezing_risk' */
void Chery_E03_Hp_T_eva_freezing_risk_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S398>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ds = false;
}

/* System reset for atomic system: '<S391>/T_eva_freezing_risk' */
void Chery_E03_Hp_T_eva_freezing_risk_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S398>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ds = false;
}

/* Output and update for atomic system: '<S391>/T_eva_freezing_risk' */
void Chery_E03_Hp_T_eva_freezing_risk(void)
{
  /* Switch: '<S398>/Switch3' incorporates:
   *  Constant: '<S398>/Def_PRCOrisk_no'
   *  Constant: '<S406>/Constant'
   *  RelationalOperator: '<S406>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 >= 30) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_ds = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S398>/Switch3' */

  /* Switch: '<S398>/Switch2' incorporates:
   *  Constant: '<S398>/Def_PRCOrisk_yes'
   *  Constant: '<S405>/Constant'
   *  RelationalOperator: '<S405>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 <= 20) {
    Chery_E03_Hp_B.bRisk_Teva_Freeze = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_Teva_Freeze = Chery_E03_Hp_DW.UnitDelay_DSTATE_ds;
  }

  /* End of Switch: '<S398>/Switch2' */

  /* Lookup_n-D: '<S398>/Teva_offset' */
  Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16Teva_Front_A10, ((int16_T *)
      &(u16Ncomp_EvaRisk.s16Teva_risk_u1[0])), ((uint16_T *)
      &(u16Ncomp_EvaRisk.u16Ncomp_EvaRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S398>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ds = Chery_E03_Hp_B.bRisk_Teva_Freeze;
}

/* System initialize for atomic system: '<S373>/Risk_corrector' */
void Chery_E03_Hp_Risk_corrector_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S391>/T_eva_freezing_risk' */
  Chery_E03_Hp_T_eva_freezing_risk_Init();

  /* End of SystemInitialize for SubSystem: '<S391>/T_eva_freezing_risk' */

  /* SystemInitialize for Atomic SubSystem: '<S391>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_m_Init();

  /* End of SystemInitialize for SubSystem: '<S391>/PRCO_riskcorrection' */

  /* SystemInitialize for Atomic SubSystem: '<S391>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_a_Init();

  /* End of SystemInitialize for SubSystem: '<S391>/Pcomp_correction' */

  /* SystemInitialize for Atomic SubSystem: '<S391>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_h_Init();

  /* End of SystemInitialize for SubSystem: '<S391>/EdcToutRisk' */
}

/* System reset for atomic system: '<S373>/Risk_corrector' */
void Chery_E03_Hp_Risk_corrector_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S391>/T_eva_freezing_risk' */
  Chery_E03_Hp_T_eva_freezing_risk_Reset();

  /* End of SystemReset for SubSystem: '<S391>/T_eva_freezing_risk' */

  /* SystemReset for Atomic SubSystem: '<S391>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_i_Reset();

  /* End of SystemReset for SubSystem: '<S391>/PRCO_riskcorrection' */

  /* SystemReset for Atomic SubSystem: '<S391>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_p_Reset();

  /* End of SystemReset for SubSystem: '<S391>/Pcomp_correction' */

  /* SystemReset for Atomic SubSystem: '<S391>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_m_Reset();

  /* End of SystemReset for SubSystem: '<S391>/EdcToutRisk' */
}

/*
 * Outputs for atomic system: '<S373>/Risk_corrector'
 * Block description for: '<S373>/Risk_corrector'
 *   risk value for EDC rpm compensation
 */
void Chery_E03_Hp_Risk_corrector(void)
{
  /* Outputs for Atomic SubSystem: '<S391>/T_eva_freezing_risk' */
  Chery_E03_Hp_T_eva_freezing_risk();

  /* End of Outputs for SubSystem: '<S391>/T_eva_freezing_risk' */

  /* Outputs for Atomic SubSystem: '<S391>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_i();

  /* End of Outputs for SubSystem: '<S391>/PRCO_riskcorrection' */

  /* Outputs for Atomic SubSystem: '<S391>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_d();

  /* End of Outputs for SubSystem: '<S391>/Pcomp_correction' */

  /* Outputs for Atomic SubSystem: '<S391>/EDC_Rpm_risk'
   *
   * Block description for '<S391>/EDC_Rpm_risk':
   *  This module for edc rpm calulation
   */
  Chery_E03_Hp_EDC_Rpm_risk();

  /* End of Outputs for SubSystem: '<S391>/EDC_Rpm_risk' */

  /* Outputs for Atomic SubSystem: '<S391>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_b();

  /* End of Outputs for SubSystem: '<S391>/EdcToutRisk' */

  /* Logic: '<S393>/OR' */
  Chery_E03_Hp_B.bRisk_Comp_e = (((((Chery_E03_Hp_B.bRisk_PRCO_o) ||
    (Chery_E03_Hp_B.bRisk_PowerLimitation_o)) || (Chery_E03_Hp_B.bRisk_Comp_e)) ||
    (Chery_E03_Hp_B.bRisk_Teva_Freeze)) || (Chery_E03_Hp_B.bRisk_EdcTout_n));

  /* MinMax: '<S393>/Max' */
  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC <= Chery_E03_Hp_B.u16Ncomp_PrcoRisk_l) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC = Chery_E03_Hp_B.u16Ncomp_PrcoRisk_l;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC <= Chery_E03_Hp_B.u16Ncomp_PowRisk_e) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC = Chery_E03_Hp_B.u16Ncomp_PowRisk_e;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC <=
      Chery_E03_Hp_ConstB.u16Ncomp_RpmRisk_d) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC = Chery_E03_Hp_ConstB.u16Ncomp_RpmRisk_d;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC <= Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l)
  {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC = Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l;
  }

  /* End of MinMax: '<S393>/Max' */
}

/* System initialize for atomic system: '<S344>/EDC_Start_Configulation' */
void Chery_E03_Hp_EDC_Start_Configulation_Init(void)
{
  /* SystemInitialize for Chart: '<S408>/bEDC_Start_Config_Decision' */
  Chery_E03_Hp_DW.u16Count_EDC_Config = 0U;
}

/* System reset for atomic system: '<S344>/EDC_Start_Configulation' */
void Chery_E03_Hp_EDC_Start_Configulation_Reset(void)
{
  /* SystemReset for Chart: '<S408>/bEDC_Start_Config_Decision' */
  Chery_E03_Hp_DW.u16Count_EDC_Config = 0U;
}

/*
 * Output and update for atomic system: '<S344>/EDC_Start_Configulation'
 * Block description for: '<S344>/EDC_Start_Configulation'
 *   edc startup condition judge
 */
void Chery_E03_Hp_EDC_Start_Configulation(void)
{
  /* Logic: '<S407>/LogicalOperator' incorporates:
   *  Constant: '<S407>/Q_HVAC_Blower_lowlimit'
   *  Constant: '<S407>/V_Air_condensor_lowlimit'
   *  Constant: '<S407>/V_Air_condensor_lowlimit1'
   *  Constant: '<S407>/V_Air_condensor_lowlimit2'
   *  RelationalOperator: '<S407>/Comparison1'
   *  RelationalOperator: '<S407>/Comparison10'
   *  RelationalOperator: '<S407>/Comparison3'
   *  RelationalOperator: '<S407>/Comparison4'
   */
  Chery_E03_Hp_B.bEDC_Start_Config_pre =
    ((((Chery_E03_Hp_B.AC_u16Vair_Condensor_E >= u16VAIR_CONDMIN) &&
       (Chery_E03_Hp_B.HpI_u8BlwVol_Real_A10 >= u8BLW_VOL_MIN)) &&
      (Chery_E03_Hp_B.HpI_u16Power_Max >= u16EDC_POWERMIN)) &&
     (Chery_E03_Hp_B.HpI_u16Ncomp_Max >= u16EDC_RPMMIN));

  /* Chart: '<S408>/bEDC_Start_Config_Decision' */
  /* None */
  if (Chery_E03_Hp_B.bEDC_Start_Config_pre) {
    if (Chery_E03_Hp_DW.u16Count_EDC_Config != u16TIMT_EDC_CONF_5) {
      Chery_E03_Hp_DW.u16Count_EDC_Config += u16COUNT_1;
    }
  } else {
    Chery_E03_Hp_DW.u16Count_EDC_Config = u16COUNT_0;
  }

  /* End of Chart: '<S408>/bEDC_Start_Config_Decision' */
}

/* System initialize for atomic system: '<S337>/EDC_ACChiller_Control' */
void Chery_E03_Hp_EDC_ACChiller_Control_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S372>/Unit Delay3' */
  Chery_E03_Hp_DW.UnitDelay3_DSTATE_g = 0;

  /* InitializeConditions for UnitDelay: '<S372>/Unit Delay1' */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_l = 0;

  /* SystemInitialize for Atomic SubSystem: '<S344>/EDC_Start_Configulation'
   *
   * Block description for '<S344>/EDC_Start_Configulation':
   *  edc startup condition judge
   */
  Chery_E03_Hp_EDC_Start_Configulation_Init();

  /* End of SystemInitialize for SubSystem: '<S344>/EDC_Start_Configulation' */

  /* SystemInitialize for Chart: '<S375>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_DW.is_active_c87_Chery_E03_Hp = 0U;
  Chery_E03_Hp_DW.is_c87_Chery_E03_Hp = 0;
  Chery_E03_Hp_DW.u16Count_Eva_FreezeCheck = 0U;
  Chery_E03_Hp_DW.u16Count_Eva_Freezerelease = 0U;
  Chery_E03_Hp_DW.u16Comp_count = 0U;
  Chery_E03_Hp_B.bEvafreRelease_switch_on = false;

  /* SystemInitialize for Chart: '<S376>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_DW.u16Count_Initial_Finish = u16CONST_0;

  /* SystemInitialize for Atomic SubSystem: '<S371>/EDC_Estimation_AC'
   *
   * Block description for '<S371>/EDC_Estimation_AC':
   *  edc forward rpm estimation
   */
  Chery_E03_Hp_EDC_Estimation_AC_Init();

  /* End of SystemInitialize for SubSystem: '<S371>/EDC_Estimation_AC' */

  /* SystemInitialize for Atomic SubSystem: '<S373>/Risk_corrector'
   *
   * Block description for '<S373>/Risk_corrector':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_Init();

  /* End of SystemInitialize for SubSystem: '<S373>/Risk_corrector' */
}

/* System reset for atomic system: '<S337>/EDC_ACChiller_Control' */
void Chery_E03_Hp_EDC_ACChiller_Control_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S372>/Unit Delay3' */
  Chery_E03_Hp_DW.UnitDelay3_DSTATE_g = 0;

  /* InitializeConditions for UnitDelay: '<S372>/Unit Delay1' */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_l = 0;

  /* SystemReset for Atomic SubSystem: '<S344>/EDC_Start_Configulation'
   *
   * Block description for '<S344>/EDC_Start_Configulation':
   *  edc startup condition judge
   */
  Chery_E03_Hp_EDC_Start_Configulation_Reset();

  /* End of SystemReset for SubSystem: '<S344>/EDC_Start_Configulation' */

  /* SystemReset for Chart: '<S375>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_DW.is_active_c87_Chery_E03_Hp = 0U;
  Chery_E03_Hp_DW.is_c87_Chery_E03_Hp = 0;
  Chery_E03_Hp_DW.u16Count_Eva_FreezeCheck = 0U;
  Chery_E03_Hp_DW.u16Count_Eva_Freezerelease = 0U;
  Chery_E03_Hp_DW.u16Comp_count = 0U;
  Chery_E03_Hp_B.bEvafreRelease_switch_on = false;

  /* SystemReset for Chart: '<S376>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_DW.u16Count_Initial_Finish = u16CONST_0;

  /* SystemReset for Atomic SubSystem: '<S371>/EDC_Estimation_AC'
   *
   * Block description for '<S371>/EDC_Estimation_AC':
   *  edc forward rpm estimation
   */
  Chery_E03_Hp_EDC_Estimation_AC_Reset();

  /* End of SystemReset for SubSystem: '<S371>/EDC_Estimation_AC' */

  /* SystemReset for Atomic SubSystem: '<S373>/Risk_corrector'
   *
   * Block description for '<S373>/Risk_corrector':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_Reset();

  /* End of SystemReset for SubSystem: '<S373>/Risk_corrector' */
}

/*
 * Output and update for atomic system: '<S337>/EDC_ACChiller_Control'
 * Block description for: '<S337>/EDC_ACChiller_Control'
 *   ACChiller Mode_ EDC Control
 */
void Chery_E03_Hp_EDC_ACChiller_Control(void)
{
  int32_T rtb_Switch;
  int16_T rtb_Saturation1;
  int32_T rtb_Switch2;
  int32_T rtb_Subtract;
  boolean_T rtb_bEvafreeze_EDCoff;
  boolean_T rtb_bMode_Initialize_Flag_No;

  /* Outputs for Atomic SubSystem: '<S344>/EDC_Start_Configulation'
   *
   * Block description for '<S344>/EDC_Start_Configulation':
   *  edc startup condition judge
   */
  Chery_E03_Hp_EDC_Start_Configulation();

  /* End of Outputs for SubSystem: '<S344>/EDC_Start_Configulation' */

  /* Chart: '<S375>/Eva_Freeze_Status_Check' */
  /* None */
  if (((uint32_T)Chery_E03_Hp_DW.is_active_c87_Chery_E03_Hp) == 0U) {
    Chery_E03_Hp_DW.is_active_c87_Chery_E03_Hp = 1U;
    Chery_E03_Hp_DW.is_c87_Chery_E03_Hp = Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon_p;
    rtb_bEvafreeze_EDCoff = false;
  } else {
    switch (Chery_E03_Hp_DW.is_c87_Chery_E03_Hp) {
     case Chery_E03_Hp_IN_EDC_RPM_Maintain:
      if (Chery_E03_Hp_DW.u16Comp_count >= u16TIME_EVAFRE_RELEASE) {
        Chery_E03_Hp_DW.is_c87_Chery_E03_Hp =
          Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon_p;
        rtb_bEvafreeze_EDCoff = false;
      } else if (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 < s16TEVA_FREZEE) {
        Chery_E03_Hp_DW.is_c87_Chery_E03_Hp =
          Chery_E03_Hp_IN_Goto_Eva_FreezeEDC_Check_g;
        rtb_bEvafreeze_EDCoff = false;
        Chery_E03_Hp_DW.u16Count_Eva_FreezeCheck = u16COUNT_0;
      } else {
        rtb_bEvafreeze_EDCoff = false;
        Chery_E03_Hp_B.bEvafreRelease_switch_on = true;
        Chery_E03_Hp_DW.u16Comp_count += u16COUNT_1;
      }
      break;

     case Chery_E03_Hp_IN_Eva_Freeze_EDC_Yes_m:
      if ((Chery_E03_Hp_DW.u16Count_Eva_Freezerelease >= u16TIME_EVAFRE_RELEASE)
          && (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 >= s16TEVA_NOR_RESTART)) {
        Chery_E03_Hp_DW.is_c87_Chery_E03_Hp = Chery_E03_Hp_IN_EDC_RPM_Maintain;
        rtb_bEvafreeze_EDCoff = false;
        Chery_E03_Hp_B.bEvafreRelease_switch_on = true;
        Chery_E03_Hp_DW.u16Comp_count = u16COUNT_0;
      } else {
        rtb_bEvafreeze_EDCoff = true;
        Chery_E03_Hp_DW.u16Count_Eva_Freezerelease += u16COUNT_1;
      }
      break;

     case Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon_p:
      if (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 < s16TEVA_FREZEE) {
        /* Teva_freeze set point is 0 degree */
        Chery_E03_Hp_DW.is_c87_Chery_E03_Hp =
          Chery_E03_Hp_IN_Goto_Eva_FreezeEDC_Check_g;
        rtb_bEvafreeze_EDCoff = false;
        Chery_E03_Hp_DW.u16Count_Eva_FreezeCheck = u16COUNT_0;
      } else {
        rtb_bEvafreeze_EDCoff = false;
        Chery_E03_Hp_B.bEvafreRelease_switch_on = false;

        /* exit: */
      }
      break;

     default:
      if (Chery_E03_Hp_DW.u16Count_Eva_FreezeCheck >= u16TIME_EVAFRE) {
        Chery_E03_Hp_DW.is_c87_Chery_E03_Hp =
          Chery_E03_Hp_IN_Eva_Freeze_EDC_Yes_m;
        rtb_bEvafreeze_EDCoff = true;
        Chery_E03_Hp_DW.u16Count_Eva_Freezerelease = u16COUNT_0;
      } else if (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 > s16TEVA_FREEZE_NOR) {
        Chery_E03_Hp_DW.is_c87_Chery_E03_Hp =
          Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon_p;
        rtb_bEvafreeze_EDCoff = false;
      } else {
        rtb_bEvafreeze_EDCoff = false;
        Chery_E03_Hp_DW.u16Count_Eva_FreezeCheck += u16COUNT_1;

        /* exit: */
      }
      break;
    }
  }

  /* End of Chart: '<S375>/Eva_Freeze_Status_Check' */

  /* Chart: '<S376>/Mode_Initialization_Flag_Decision' */
  if (((int32_T)Chery_E03_Hp_DW.u16Count_Initial_Finish) < 50) {
    rtb_Switch = ((int32_T)Chery_E03_Hp_DW.u16Count_Initial_Finish) + 1;
    if (rtb_Switch > 65535) {
      rtb_Switch = 65535;
    }

    Chery_E03_Hp_DW.u16Count_Initial_Finish = (uint16_T)rtb_Switch;
    rtb_bMode_Initialize_Flag_No = false;
  } else {
    Chery_E03_Hp_DW.u16Count_Initial_Finish = 50U;
    rtb_bMode_Initialize_Flag_No = true;
  }

  /* End of Chart: '<S376>/Mode_Initialization_Flag_Decision' */

  /* Outputs for Atomic SubSystem: '<S371>/EDC_Estimation_AC'
   *
   * Block description for '<S371>/EDC_Estimation_AC':
   *  edc forward rpm estimation
   */
  Chery_E03_Hp_EDC_Estimation_AC();

  /* End of Outputs for SubSystem: '<S371>/EDC_Estimation_AC' */

  /* Outputs for Atomic SubSystem: '<S371>/Ncomp_Estimation_Chiller'
   *
   * Block description for '<S371>/Ncomp_Estimation_Chiller':
   *  edc for ac_chiller mode compensation for chiller
   */
  Chery_E03_Hp_Ncomp_Estimation_Chiller();

  /* End of Outputs for SubSystem: '<S371>/Ncomp_Estimation_Chiller' */

  /* Product: '<S380>/Product3' incorporates:
   *  Constant: '<S380>/AMP_10_1'
   *  Sum: '<S380>/Sum4'
   */
  rtb_Switch = (int32_T)((uint32_T)(((uint32_T)((uint16_T)((int32_T)(((int32_T)
    ((int16_T)(((int16_T)Chery_E03_Hp_B.u16Ncomp_PrcoRisk_l) + ((int16_T)
    Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l)))) + ((int32_T)((int16_T)
    Chery_E03_Hp_ConstB.u16Ncomp_AC_RearEva_Est_a)))))) * ((uint32_T)u8AMP_10)));

  /* Saturate: '<S380>/Saturation' */
  if (rtb_Switch > s32NCOMP_FOR_ACCHIL) {
    rtb_Switch = s32NCOMP_FOR_ACCHIL;
  } else {
    if (rtb_Switch < s32NCOMP_STOP_0) {
      rtb_Switch = s32NCOMP_STOP_0;
    }
  }

  /* End of Saturate: '<S380>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S371>/PIparameters'
   *
   * Block description for '<S371>/PIparameters':
   *  AC_EDC_PI parameter
   */
  Chery_E03_Hp_PIparameters();

  /* End of Outputs for SubSystem: '<S371>/PIparameters' */

  /* Saturate: '<S380>/Saturation1' */
  if (Chery_E03_Hp_B.s16Teva_Ctrl_Delta > s16TEVA_CTRL_UP) {
    rtb_Saturation1 = s16TEVA_CTRL_UP;
  } else if (Chery_E03_Hp_B.s16Teva_Ctrl_Delta < s16TEVA_CTRL_DOWN) {
    rtb_Saturation1 = s16TEVA_CTRL_DOWN;
  } else {
    rtb_Saturation1 = Chery_E03_Hp_B.s16Teva_Ctrl_Delta;
  }

  /* End of Saturate: '<S380>/Saturation1' */

  /* Product: '<S380>/Product1' incorporates:
   *  Product: '<S380>/Product2'
   */
  rtb_Subtract = ((int32_T)rtb_Saturation1) * ((int32_T)
    Chery_E03_Hp_B.u16Ncomp_Tout_Risk_l);

  /* Sum: '<S380>/Sum1' incorporates:
   *  Product: '<S380>/Product1'
   */
  rtb_Switch += rtb_Subtract;

  /* Sum: '<S380>/Sum3' incorporates:
   *  Constant: '<S380>/Sample_Time_0.1s'
   *  Product: '<S380>/Divide1'
   *  Product: '<S380>/Divide2'
   *  UnitDelay: '<S372>/Unit Delay3'
   */
  rtb_Subtract = (rtb_Switch + ((rtb_Subtract / ((int32_T)u8SAMPLE_TIME_10)) /
    ((int32_T)Chery_E03_Hp_B.s16Ti_Comp_AC))) +
    Chery_E03_Hp_DW.UnitDelay3_DSTATE_g;

  /* Outputs for Atomic SubSystem: '<S373>/Risk_corrector'
   *
   * Block description for '<S373>/Risk_corrector':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector();

  /* End of Outputs for SubSystem: '<S373>/Risk_corrector' */

  /* Product: '<S390>/Product' incorporates:
   *  Constant: '<S390>/Amplificate rate 10 for the Kp_rate'
   */
  rtb_Switch2 = (int32_T)((uint32_T)(((uint32_T)
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC) * ((uint32_T)u8AMP_10)));

  /* Switch: '<S390>/Switch' incorporates:
   *  Constant: '<S392>/Constant'
   *  MinMax: '<S390>/Max'
   *  RelationalOperator: '<S392>/Compare'
   *  Sum: '<S390>/Sum'
   *  Sum: '<S390>/Sum1'
   *  UnitDelay: '<S372>/Unit Delay1'
   */
  if (Chery_E03_Hp_B.bRisk_Comp_e == bFAIL_NO_RISK_0) {
    rtb_Subtract -= rtb_Switch2;
  } else {
    if (rtb_Subtract >= Chery_E03_Hp_DW.UnitDelay1_DSTATE_l) {
      /* MinMax: '<S390>/Max' incorporates:
       *  UnitDelay: '<S372>/Unit Delay1'
       */
      rtb_Subtract = Chery_E03_Hp_DW.UnitDelay1_DSTATE_l;
    }

    rtb_Subtract -= rtb_Switch2;
  }

  /* End of Switch: '<S390>/Switch' */

  /* Chart: '<S370>/EDC_output_Management_Pre' */
  /* None */
  if (Chery_E03_Hp_B.bEDC_Start_Config_pre) {
    if (!rtb_bEvafreeze_EDCoff) {
      if ((!Chery_E03_Hp_B.bEvafreRelease_switch_on) &&
          rtb_bMode_Initialize_Flag_No) {
        /* Saturate: '<S390>/AfRisk_Pre_Satuation' */
        if (rtb_Subtract > s32NCOMP_UP_LIMIT) {
          rtb_Switch2 = s32NCOMP_UP_LIMIT;
        } else if (rtb_Subtract < s32NCOMP_STOP_0) {
          rtb_Switch2 = s32NCOMP_STOP_0;
        } else {
          rtb_Switch2 = rtb_Subtract;
        }

        /* End of Saturate: '<S390>/AfRisk_Pre_Satuation' */
      } else {
        rtb_Switch2 = s32NCOMP_DOWN_LIMIT;
      }
    } else {
      rtb_Switch2 = s32NCOMP_STOP_0;
    }
  } else {
    rtb_Switch2 = s32NCOMP_STOP_0;
  }

  /* Switch: '<S372>/Switch1' incorporates:
   *  Chart: '<S370>/EDC_output_Management_Pre'
   *  Constant: '<S372>/Constant2'
   *  Constant: '<S385>/Constant'
   *  Constant: '<S386>/Constant'
   *  Logic: '<S372>/AND'
   *  RelationalOperator: '<S385>/Compare'
   *  RelationalOperator: '<S386>/Compare'
   */
  if ((rtb_Switch2 < s32NCOMP_DOWN_LIMIT) && (rtb_Switch2 > s32NCOMP_DOWN_0)) {
    rtb_Subtract = s32NCOMP_DOWN_LIMIT;
  } else {
    rtb_Subtract = rtb_Switch2;
  }

  /* End of Switch: '<S372>/Switch1' */

  /* Switch: '<S372>/Switch2' incorporates:
   *  Chart: '<S370>/EDC_output_Management_Pre'
   *  Constant: '<S372>/Constant5'
   *  Constant: '<S387>/Constant'
   *  RelationalOperator: '<S387>/Compare'
   */
  if (rtb_Switch2 == s32NCOMP_DOWN_0) {
    rtb_Subtract = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S372>/Switch2' */

  /* Gain: '<S372>/Gain1' */
  rtb_Switch2 = (int32_T)((uint32_T)(10U * ((uint32_T)
    Chery_E03_Hp_B.HpI_u16Ncomp_Max)));

  /* MinMax: '<S372>/Min2' incorporates:
   *  Constant: '<S372>/Constant7'
   */
  if (rtb_Switch2 >= s32NCOMP_UP_LIMIT) {
    rtb_Switch2 = s32NCOMP_UP_LIMIT;
  }

  /* End of MinMax: '<S372>/Min2' */

  /* RelationalOperator: '<S389>/LowerRelop1' */
  rtb_bEvafreeze_EDCoff = (rtb_Subtract > rtb_Switch2);

  /* Switch: '<S389>/Switch' incorporates:
   *  Constant: '<S372>/Constant8'
   *  RelationalOperator: '<S389>/UpperRelop'
   */
  if (rtb_Subtract < s32NCOMP_DOWN_0) {
    rtb_Subtract = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S389>/Switch' */

  /* Switch: '<S389>/Switch2' */
  if (!rtb_bEvafreeze_EDCoff) {
    rtb_Switch2 = rtb_Subtract;
  }

  /* End of Switch: '<S389>/Switch2' */

  /* Sum: '<S372>/Sum3' */
  rtb_Switch = rtb_Switch2 - rtb_Switch;

  /* RelationalOperator: '<S388>/LowerRelop1' incorporates:
   *  Constant: '<S372>/Constant3'
   */
  rtb_bEvafreeze_EDCoff = (rtb_Switch > s32NCOMP_ICAL_UP);

  /* Switch: '<S388>/Switch' incorporates:
   *  Constant: '<S372>/Constant6'
   *  RelationalOperator: '<S388>/UpperRelop'
   */
  if (rtb_Switch < s32NCOMP_DOWN_0) {
    rtb_Switch = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S388>/Switch' */

  /* Switch: '<S388>/Switch2' incorporates:
   *  Constant: '<S372>/Constant3'
   *  UnitDelay: '<S372>/Unit Delay3'
   */
  if (rtb_bEvafreeze_EDCoff) {
    Chery_E03_Hp_DW.UnitDelay3_DSTATE_g = s32NCOMP_ICAL_UP;
  } else {
    Chery_E03_Hp_DW.UnitDelay3_DSTATE_g = rtb_Switch;
  }

  /* End of Switch: '<S388>/Switch2' */

  /* Sum: '<S372>/Subtract' incorporates:
   *  Lookup_n-D: '<S372>/2-D Lookup Table'
   *  UnitDelay: '<S372>/Unit Delay1'
   */
  rtb_Subtract = Chery_E03_Hp_DW.UnitDelay1_DSTATE_l + ((int32_T)
    look2_is16u16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
    Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((int16_T *)
    &(u16ACMode_EdcRamp.s16TambEdcRamp_u1[0])), ((uint16_T *)
    &(u16ACMode_EdcRamp.u16Prco_ACMode_u2[0])), ((uint16_T *)
    &(u16ACMode_EdcRamp.u16ACMode_EdcRamp_y[0])), Chery_E03_Hp_ConstP.pooled16,
    6U));

  /* MinMax: '<S372>/Min3' */
  if (rtb_Switch2 < rtb_Subtract) {
    Chery_E03_Hp_DW.UnitDelay1_DSTATE_l = rtb_Switch2;
  } else {
    Chery_E03_Hp_DW.UnitDelay1_DSTATE_l = rtb_Subtract;
  }

  /* End of MinMax: '<S372>/Min3' */

  /* Product: '<S372>/Product' incorporates:
   *  Constant: '<S372>/Constant1'
   *  UnitDelay: '<S372>/Unit Delay1'
   */
  Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC = (uint16_T)((int32_T)
    (Chery_E03_Hp_DW.UnitDelay1_DSTATE_l / ((int32_T)u8AMP_10)));
}

/*
 * System initialize for atomic system:
 *    '<S431>/DelayJudge'
 *    '<S432>/DelayJudge'
 *    '<S999>/DelayJudge'
 *    '<S1000>/DelayJudge'
 */
void Chery_E03_Hp_DelayJudge_d_Init(DW_DelayJudge_Chery_E03_Hp_n_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge_o;

  /* SystemInitialize for Chart: '<S435>/JudgeTime' */
  Chery_E03_Hp_JudgeTime_Init(&rtb_bDelayJudge_o, &localDW->sf_JudgeTime);
}

/*
 * System reset for atomic system:
 *    '<S431>/DelayJudge'
 *    '<S432>/DelayJudge'
 *    '<S999>/DelayJudge'
 *    '<S1000>/DelayJudge'
 */
void Chery_E03_Hp_DelayJudge_b_Reset(DW_DelayJudge_Chery_E03_Hp_n_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge_o;

  /* SystemReset for Chart: '<S435>/JudgeTime' */
  Chery_E03_Hp_JudgeTime_Reset(&rtb_bDelayJudge_o, &localDW->sf_JudgeTime);
}

/*
 * Output and update for atomic system:
 *    '<S431>/DelayJudge'
 *    '<S432>/DelayJudge'
 *    '<S999>/DelayJudge'
 *    '<S1000>/DelayJudge'
 */
boolean_T Chery_E03_Hp_DelayJudge_f(boolean_T rtu_bJudge, uint16_T rtu_DelayTime,
  const ConstB_DelayJudge_Chery_E03_Hp_o_T *localC,
  DW_DelayJudge_Chery_E03_Hp_n_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bDelayJudge_o;
  boolean_T rty_bDelayJudge_0;
  uint16_T rtb_Saturation_gt;

  /* Outputs for Atomic SubSystem: '<S433>/DataTypeConv_u16_' */
  rtb_Saturation_gt = (uint16_T) Chery_E03_Hp_DataTypeConversion(rtu_DelayTime);

  /* End of Outputs for SubSystem: '<S433>/DataTypeConv_u16_' */

  /* Chart: '<S435>/JudgeTime' */
  Chery_E03_Hp_JudgeTime(rtu_bJudge,
    localC->TmpSignalConversionAtDataTypeConv_u16_Outport1, &rtb_bDelayJudge_o,
    &localDW->sf_JudgeTime);

  /* SignalConversion: '<S433>/Signal Copy' */
  rty_bDelayJudge_0 = rtb_bDelayJudge_o;
  return rty_bDelayJudge_0;
}

/*
 * System initialize for atomic system:
 *    '<S416>/Delay_2s_L1_Increase'
 *    '<S416>/Delay_5s'
 *    '<S986>/Delay_15s'
 *    '<S986>/Delay_5s'
 */
void Chery_E03_Hp_DelayJudge_Cfg_Init(DW_DelayJudge_Cfg_Chery_E03_Hp_T *localDW)
{
  /* SystemInitialize for Atomic SubSystem: '<S431>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_d_Init(&localDW->DelayJudge);

  /* End of SystemInitialize for SubSystem: '<S431>/DelayJudge' */
}

/*
 * System reset for atomic system:
 *    '<S416>/Delay_2s_L1_Increase'
 *    '<S416>/Delay_5s'
 *    '<S986>/Delay_15s'
 *    '<S986>/Delay_5s'
 */
void Chery_E03_Hp_DelayJudge_Cfg_Reset(DW_DelayJudge_Cfg_Chery_E03_Hp_T *localDW)
{
  /* SystemReset for Atomic SubSystem: '<S431>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_b_Reset(&localDW->DelayJudge);

  /* End of SystemReset for SubSystem: '<S431>/DelayJudge' */
}

/*
 * Output and update for atomic system:
 *    '<S416>/Delay_2s_L1_Increase'
 *    '<S416>/Delay_5s'
 *    '<S986>/Delay_15s'
 *    '<S986>/Delay_5s'
 */
boolean_T Chery_E03_Hp_DelayJudge_Cfg(boolean_T rtu_bJudge, const
  ConstB_DelayJudge_Cfg_Chery_E03_Hp_T *localC, DW_DelayJudge_Cfg_Chery_E03_Hp_T
  *localDW, uint16_T rtp_u16ParaTime)
{
  boolean_T rty_bDelayJudge_0;

  /* Outputs for Atomic SubSystem: '<S431>/DelayJudge' */

  /* Constant: '<S431>/Constant' */
  rty_bDelayJudge_0 = ( Chery_E03_Hp_DelayJudge_f(rtu_bJudge, rtp_u16ParaTime,
    &localC->DelayJudge, &localDW->DelayJudge) != false);

  /* End of Outputs for SubSystem: '<S431>/DelayJudge' */
  return rty_bDelayJudge_0;
}

/*
 * Output and update for atomic system: '<S471>/ChilPIparameters'
 * Block description for: '<S471>/ChilPIparameters'
 *   get chiller Kp ki and delt_T
 */
void Chery_E03_Hp_ChilPIparameters_p(void)
{
  /* Sum: '<S476>/Sum' */
  Chery_E03_Hp_B.s16Twat_Ctrl_delt = (int16_T)
    (Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 -
     Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10);

  /* Lookup_n-D: '<S476>/chil_Ki' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.s16Twat_Ctrl_delt, Chery_E03_Hp_ConstP.pooled36,
     Chery_E03_Hp_ConstP.pooled71, 8U);

  /* Lookup_n-D: '<S476>/chillercomp_kp' */
  Chery_E03_Hp_B.u16Ncomp_PrcoRisk_e = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.s16Twat_Ctrl_delt, Chery_E03_Hp_ConstP.pooled37,
     Chery_E03_Hp_ConstP.pooled72, 9U);
}

/* System initialize for atomic system: '<S479>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_g_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S481>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_k4 = false;
}

/* System reset for atomic system: '<S479>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_h_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S481>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_k4 = false;
}

/* Output and update for atomic system: '<S479>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_j(void)
{
  /* Switch: '<S481>/Switch3' incorporates:
   *  Constant: '<S481>/Pressure_Ratio_Risk_N'
   *  Constant: '<S486>/Constant'
   *  RelationalOperator: '<S486>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 <= 1150) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_k4 = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S481>/Switch3' */

  /* Switch: '<S481>/Switch2' incorporates:
   *  Constant: '<S481>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S485>/Constant'
   *  RelationalOperator: '<S485>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 >= 1200) {
    Chery_E03_Hp_B.bRisk_EdcTout_m = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_EdcTout_m = Chery_E03_Hp_DW.UnitDelay_DSTATE_k4;
  }

  /* End of Switch: '<S481>/Switch2' */

  /* Lookup_n-D: '<S481>/EdcTout_Risk_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10, ((int16_T *)
      &(u16Edc_ToutReduce.s16EdcTout_Risk_u1[0])), ((uint16_T *)
      &(u16Edc_ToutReduce.u16Edc_ToutReduce_y[0])), 7U);

  /* Update for UnitDelay: '<S481>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_k4 = Chery_E03_Hp_B.bRisk_EdcTout_m;
}

/* System initialize for atomic system: '<S479>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_p_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S482>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_b1 = false;
}

/* System reset for atomic system: '<S479>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_c_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S482>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_b1 = false;
}

/* Output and update for atomic system: '<S479>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_o(void)
{
  /* Switch: '<S482>/Switch3' incorporates:
   *  Constant: '<S482>/Def_PRCOrisk_no'
   *  Constant: '<S488>/Constant'
   *  RelationalOperator: '<S488>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 <= u16PRCO_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_b1 = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S482>/Switch3' */

  /* Switch: '<S482>/Switch2' incorporates:
   *  Constant: '<S482>/Def_PRCOrisk_yes'
   *  Constant: '<S487>/Constant'
   *  RelationalOperator: '<S487>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 > u16PRCO_RISK) {
    Chery_E03_Hp_B.bRisk_PRCO_h = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PRCO_h = Chery_E03_Hp_DW.UnitDelay_DSTATE_b1;
  }

  /* End of Switch: '<S482>/Switch2' */

  /* Lookup_n-D: '<S482>/Prco_offset Table1' */
  Chery_E03_Hp_B.u16Ncomp_PrcoRisk_e = look1_iu16lu32n16_binlcse
    (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((uint16_T *)
      &(u16Ncomp_PrcoRisk.u16Prco_risk_u1[0])), ((uint16_T *)
      &(u16Ncomp_PrcoRisk.u16Ncomp_PrcoRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S482>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_b1 = Chery_E03_Hp_B.bRisk_PRCO_h;
}

/* System initialize for atomic system: '<S479>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_d_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S483>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_pr = false;
}

/* System reset for atomic system: '<S479>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_e_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S483>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_pr = false;
}

/* Output and update for atomic system: '<S479>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_e(void)
{
  int16_T rtb_Sum;

  /* Sum: '<S483>/Sum' */
  rtb_Sum = (int16_T)(((int16_T)Chery_E03_Hp_B.HpI_u16Power_Max) - ((int16_T)
    Chery_E03_Hp_B.HpI_u16PowerComp));

  /* Switch: '<S483>/Switch2' incorporates:
   *  Constant: '<S483>/Def_Pcomprisk_No'
   *  Constant: '<S490>/Constant'
   *  RelationalOperator: '<S490>/Compare'
   */
  if (rtb_Sum >= s16POWER_GAP_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_pr = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S483>/Switch2' */

  /* Switch: '<S483>/Switch1' incorporates:
   *  Constant: '<S483>/Def_Pcomprisk_yes_set'
   *  Constant: '<S489>/Constant'
   *  RelationalOperator: '<S489>/Compare'
   */
  if (rtb_Sum <= s16POWER_GAP_RISK) {
    Chery_E03_Hp_B.bRisk_PowerLimitation_e = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PowerLimitation_e = Chery_E03_Hp_DW.UnitDelay_DSTATE_pr;
  }

  /* End of Switch: '<S483>/Switch1' */

  /* Lookup_n-D: '<S483>/Power_cpr_diff' */
  Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk = look1_is16lu32n16tu16_binlcse
    (rtb_Sum, ((int16_T *)&(u16Ncomp_PowRisk.s16Power_Comp_gap_u1[0])),
     ((uint16_T *)&(u16Ncomp_PowRisk.u16Ncomp_PowRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S483>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_pr = Chery_E03_Hp_B.bRisk_PowerLimitation_e;
}

/* System initialize for atomic system: '<S472>/Chiller_Risk_corrector' */
void Chery_E03_Hp_Chiller_Risk_corrector_k_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S479>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_g_Init();

  /* End of SystemInitialize for SubSystem: '<S479>/EdcToutRisk' */

  /* SystemInitialize for Atomic SubSystem: '<S479>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_p_Init();

  /* End of SystemInitialize for SubSystem: '<S479>/PRCO_riskcorrection' */

  /* SystemInitialize for Atomic SubSystem: '<S479>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_d_Init();

  /* End of SystemInitialize for SubSystem: '<S479>/Pcomp_correction' */
}

/* System reset for atomic system: '<S472>/Chiller_Risk_corrector' */
void Chery_E03_Hp_Chiller_Risk_corrector_o_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S479>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_h_Reset();

  /* End of SystemReset for SubSystem: '<S479>/EdcToutRisk' */

  /* SystemReset for Atomic SubSystem: '<S479>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_c_Reset();

  /* End of SystemReset for SubSystem: '<S479>/PRCO_riskcorrection' */

  /* SystemReset for Atomic SubSystem: '<S479>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_e_Reset();

  /* End of SystemReset for SubSystem: '<S479>/Pcomp_correction' */
}

/*
 * Output and update for atomic system: '<S472>/Chiller_Risk_corrector'
 * Block description for: '<S472>/Chiller_Risk_corrector'
 *   chiller mode risk value for EDC rpm compensation
 */
void Chery_E03_Hp_Chiller_Risk_corrector_g(void)
{
  /* Outputs for Atomic SubSystem: '<S479>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_j();

  /* End of Outputs for SubSystem: '<S479>/EdcToutRisk' */

  /* Outputs for Atomic SubSystem: '<S479>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_o();

  /* End of Outputs for SubSystem: '<S479>/PRCO_riskcorrection' */

  /* Outputs for Atomic SubSystem: '<S479>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_e();

  /* End of Outputs for SubSystem: '<S479>/Pcomp_correction' */

  /* Logic: '<S484>/OR' */
  Chery_E03_Hp_B.bChilRisk_Comp = (((Chery_E03_Hp_B.bRisk_PRCO_h) ||
    (Chery_E03_Hp_B.bRisk_PowerLimitation_e)) || (Chery_E03_Hp_B.bRisk_EdcTout_m));

  /* MinMax: '<S484>/Max' */
  if (Chery_E03_Hp_B.u16Ncomp_PrcoRisk_e >
      Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk) {
    Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk = Chery_E03_Hp_B.u16Ncomp_PrcoRisk_e;
  }

  if (Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk <=
      Chery_E03_Hp_B.u16Ncomp_Tout_Risk) {
    Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk = Chery_E03_Hp_B.u16Ncomp_Tout_Risk;
  }

  /* End of MinMax: '<S484>/Max' */
}

/* System initialize for atomic system: '<S444>/Chiller_EDC_Start_Configulation' */
void Chery_E03_Hp_Chiller_EDC_Start_Configulation_d_Init(void)
{
  /* SystemInitialize for Chart: '<S492>/bEDC_Start_Config_Decision' */
  Chery_E03_Hp_bEDC_Start_Config_Decision_Init(&Chery_E03_Hp_B.bChil_EDC_Config,
    &Chery_E03_Hp_DW.sf_bEDC_Start_Config_Decision_d);
}

/* System reset for atomic system: '<S444>/Chiller_EDC_Start_Configulation' */
void Chery_E03_Hp_Chiller_EDC_Start_Configulation_k_Reset(void)
{
  /* SystemReset for Chart: '<S492>/bEDC_Start_Config_Decision' */
  Chery_E03_Hp_bEDC_Start_Config_Decision_Reset(&Chery_E03_Hp_B.bChil_EDC_Config,
    &Chery_E03_Hp_DW.sf_bEDC_Start_Config_Decision_d);
}

/*
 * Output and update for atomic system: '<S444>/Chiller_EDC_Start_Configulation'
 * Block description for: '<S444>/Chiller_EDC_Start_Configulation'
 *   edc startup condition judge
 */
void Chery_E03_Hp_Chiller_EDC_Start_Configulation_b(void)
{
  /* Chart: '<S492>/bEDC_Start_Config_Decision' incorporates:
   *  Constant: '<S491>/Position_shutoff Valeo Open'
   *  Constant: '<S491>/V_Air_condensor_lowlimit'
   *  Constant: '<S491>/V_Air_condensor_lowlimit1'
   *  Constant: '<S491>/V_Air_condensor_lowlimit2'
   *  Constant: '<S493>/Constant'
   *  Logic: '<S491>/LogicalOperator'
   *  RelationalOperator: '<S491>/Comparison10'
   *  RelationalOperator: '<S491>/Comparison2'
   *  RelationalOperator: '<S491>/Comparison3'
   *  RelationalOperator: '<S491>/Comparison4'
   *  RelationalOperator: '<S493>/Compare'
   */
  Chery_E03_Hp_bEDC_Start_Config_Decision
    (((((Chery_E03_Hp_B.AC_u16Vair_Condensor_E >= u16VAIR_CONDMIN) &&
        (Chery_E03_Hp_B.HpI_u16EXV_Chil_Pos >= u16CHIL_EXV_MIN_START)) &&
       (Chery_E03_Hp_B.HpI_u16Power_Max >= u16EDC_POWERMIN)) &&
      (Chery_E03_Hp_B.HpI_u16Ncomp_Max >= u16EDC_RPMMIN)) && (((int32_T)
       Chery_E03_Hp_B.HpI_u16Pump_Bat) > 30), &Chery_E03_Hp_B.bChil_EDC_Config,
     &Chery_E03_Hp_DW.sf_bEDC_Start_Config_Decision_d);
}

/*
 * Output and update for atomic system: '<S935>/EDC_Estimation_TotalDehum'
 * Block description for: '<S935>/EDC_Estimation_TotalDehum'
 *   edc forward rpm estimation
 */
void Chery_E03_Hp_EDC_Estimation_TotalDehum(void)
{
  uint32_T u0;

  /* Product: '<S942>/Product' incorporates:
   *  Constant: '<S942>/Constant'
   *  Lookup_n-D: '<S942>/Ncomp_TotalDehum_Est'
   *  Lookup_n-D: '<S942>/Ratio_AirFlowRate'
   */
  u0 = (((uint32_T)look2_is16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
          Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req, ((int16_T *)
           &(u16Ncomp_TotalDehum_Est.s16Tamb_TotalDehum_u1[0])), ((int16_T *)
           &(u16Ncomp_TotalDehum_Est.s16Tasd_TotalDehum_u2[0])), ((uint16_T *)
           &(u16Ncomp_TotalDehum_Est.u16Ncomp_TotalDehum_Est_y[0])),
          Chery_E03_Hp_ConstP.pooled17, 10U)) * ((uint32_T)
         look2_is16u16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
          Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
           &(u16Percent_EDCEst_HP.s16Tamb_HP_u1[0])), ((uint16_T *)
           &(u16Percent_EDCEst_HP.u16_QBlower_HVAC_u2[0])), ((uint16_T *)
           &(u16Percent_EDCEst_HP.u16Percent_EDCEst_HP_y[0])),
          Chery_E03_Hp_ConstP.pooled15, 7U))) / ((uint32_T)u16AMP_100);

  /* Saturate: '<S942>/Saturation' */
  if (u0 >= 7000U) {
    u0 = 7000U;
  }

  Chery_E03_Hp_B.u16Ncomp_Prci_Risk_b = (uint16_T)u0;

  /* End of Saturate: '<S942>/Saturation' */
}

/*
 * Output and update for atomic system: '<S935>/Ncomp_Estimation_Chiller'
 * Block description for: '<S935>/Ncomp_Estimation_Chiller'
 *   edc for ac_chiller mode compensation for chiller
 */
void Chery_E03_Hp_Ncomp_Estimation_Chiller_h(void)
{
  /* Constant: '<S944>/Constant2' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_j = u16NCOMP_STOP_0;
}

/*
 * Output and update for atomic system: '<S935>/PIparameters'
 * Block description for: '<S935>/PIparameters'
 *   AC_EDC_PI parameter
 */
void Chery_E03_Hp_PIparameters_b(void)
{
  /* Lookup_n-D: '<S945>/Ki_EDC_Calculation1' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_j = look2_is16u16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC,
     ((int16_T *)&(u16Ki_EDC_TotalDehum.s16Tamb_TotalDehum_u1[0])), ((uint16_T *)
      &(u16Ki_EDC_TotalDehum.u16_QBlower_HVAC_u2[0])), ((uint16_T *)
      &(u16Ki_EDC_TotalDehum.u16Ki_EDC_TotalDehum_y[0])),
     Chery_E03_Hp_ConstP.pooled17, 10U);

  /* Lookup_n-D: '<S945>/Kp_EDC_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Prci_Risk_b = look2_is16u16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC,
     ((int16_T *)&(u16Kp_EDC_TotalDehum.s16Tamb_TotalDehum_u1[0])), ((uint16_T *)
      &(u16Kp_EDC_TotalDehum.u16_QBlower_HVAC_u2[0])), ((uint16_T *)
      &(u16Kp_EDC_TotalDehum.u16Kp_EDC_TotalDehum_y[0])),
     Chery_E03_Hp_ConstP.pooled17, 10U);

  /* Sum: '<S945>/Sum' */
  Chery_E03_Hp_B.s16T_Water_Ctrl_Delta_g = (int16_T)
    (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
     Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10);
}

/*
 * Output and update for atomic system: '<S958>/EDC_Rpm_risk'
 * Block description for: '<S958>/EDC_Rpm_risk'
 *   This module for edc rpm calulation
 */
void Chery_E03_Hp_EDC_Rpm_risk_e(void)
{
  /* Constant: '<S961>/Def_Pcomprisk_yes_set1' */
  Chery_E03_Hp_B.bEDC_Start_Config_pre_l = bFAIL_NO_RISK_0;
}

/* System initialize for atomic system: '<S958>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_l_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S962>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_kh = false;
}

/* System reset for atomic system: '<S958>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_m3_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S962>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_kh = false;
}

/* Output and update for atomic system: '<S958>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_h(void)
{
  /* Switch: '<S962>/Switch3' incorporates:
   *  Constant: '<S962>/Pressure_Ratio_Risk_N'
   *  Constant: '<S968>/Constant'
   *  RelationalOperator: '<S968>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 <= 1150) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_kh = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S962>/Switch3' */

  /* Switch: '<S962>/Switch2' incorporates:
   *  Constant: '<S962>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S967>/Constant'
   *  RelationalOperator: '<S967>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 >= 1200) {
    Chery_E03_Hp_B.bRisk_EdcTout_e = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_EdcTout_e = Chery_E03_Hp_DW.UnitDelay_DSTATE_kh;
  }

  /* End of Switch: '<S962>/Switch2' */

  /* Lookup_n-D: '<S962>/EdcTout_Risk_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_j = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10, ((int16_T *)
      &(u16Edc_ToutReduce.s16EdcTout_Risk_u1[0])), ((uint16_T *)
      &(u16Edc_ToutReduce.u16Edc_ToutReduce_y[0])), 7U);

  /* Update for UnitDelay: '<S962>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_kh = Chery_E03_Hp_B.bRisk_EdcTout_e;
}

/* System initialize for atomic system: '<S958>/PRCI_Risk' */
void Chery_E03_Hp_PRCI_Risk_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S963>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ib = false;
}

/* System reset for atomic system: '<S958>/PRCI_Risk' */
void Chery_E03_Hp_PRCI_Risk_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S963>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ib = false;
}

/* Output and update for atomic system: '<S958>/PRCI_Risk' */
void Chery_E03_Hp_PRCI_Risk(void)
{
  /* Switch: '<S963>/Switch3' incorporates:
   *  Constant: '<S963>/Pressure_Ratio_Risk_N'
   *  Constant: '<S970>/Constant'
   *  RelationalOperator: '<S970>/Compare'
   */
  if (((int32_T)Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10) >= 28) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_ib = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S963>/Switch3' */

  /* Switch: '<S963>/Switch2' incorporates:
   *  Constant: '<S963>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S969>/Constant'
   *  RelationalOperator: '<S969>/Compare'
   */
  if (((int32_T)Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10) <= 24) {
    Chery_E03_Hp_B.bRisk_PRCI_HP_f = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PRCI_HP_f = Chery_E03_Hp_DW.UnitDelay_DSTATE_ib;
  }

  /* End of Switch: '<S963>/Switch2' */

  /* Lookup_n-D: '<S963>/Prco_Risk_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Prci_Risk_b = look1_iu16lu32n16_binlcse
    (Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10, ((uint16_T *)
      &(u16Ncomp_PrciRisk_TotalDehum.u16Prci_risk_TotalDehum_u1[0])), ((uint16_T
       *)&(u16Ncomp_PrciRisk_TotalDehum.u16Ncomp_PrciRisk_TotalDehum_y[0])), 7U);

  /* Update for UnitDelay: '<S963>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ib = Chery_E03_Hp_B.bRisk_PRCI_HP_f;
}

/* System initialize for atomic system: '<S958>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_h_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S964>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_dr = false;
}

/* System reset for atomic system: '<S958>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_iq_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S964>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_dr = false;
}

/* Output and update for atomic system: '<S958>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_m(void)
{
  /* Switch: '<S964>/Switch3' incorporates:
   *  Constant: '<S964>/Def_PRCOrisk_no'
   *  Constant: '<S972>/Constant'
   *  RelationalOperator: '<S972>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 <= u16PRCO_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_dr = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S964>/Switch3' */

  /* Switch: '<S964>/Switch2' incorporates:
   *  Constant: '<S964>/Def_PRCOrisk_yes'
   *  Constant: '<S971>/Constant'
   *  RelationalOperator: '<S971>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 > u16PRCO_RISK) {
    Chery_E03_Hp_B.bRisk_PRCO = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PRCO = Chery_E03_Hp_DW.UnitDelay_DSTATE_dr;
  }

  /* End of Switch: '<S964>/Switch2' */

  /* Lookup_n-D: '<S964>/Prco_offset' */
  Chery_E03_Hp_B.u16Ncomp_PrcoRisk_f = look1_iu16lu32n16_binlcse
    (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((uint16_T *)
      &(u16Ncomp_PrcoRisk.u16Prco_risk_u1[0])), ((uint16_T *)
      &(u16Ncomp_PrcoRisk.u16Ncomp_PrcoRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S964>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_dr = Chery_E03_Hp_B.bRisk_PRCO;
}

/* System initialize for atomic system: '<S958>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_i_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S965>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_hm = false;
}

/* System reset for atomic system: '<S958>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_k_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S965>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_hm = false;
}

/* Output and update for atomic system: '<S958>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_a(void)
{
  int16_T rtb_Sum;

  /* Sum: '<S965>/Sum' */
  rtb_Sum = (int16_T)(((int16_T)Chery_E03_Hp_B.HpI_u16Power_Max) - ((int16_T)
    Chery_E03_Hp_B.HpI_u16PowerComp));

  /* Switch: '<S965>/Switch2' incorporates:
   *  Constant: '<S965>/Def_Pcomprisk_No'
   *  Constant: '<S974>/Constant'
   *  RelationalOperator: '<S974>/Compare'
   */
  if (rtb_Sum >= s16POWER_GAP_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_hm = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S965>/Switch2' */

  /* Switch: '<S965>/Switch1' incorporates:
   *  Constant: '<S965>/Def_Pcomprisk_yes_set'
   *  Constant: '<S973>/Constant'
   *  RelationalOperator: '<S973>/Compare'
   */
  if (rtb_Sum <= s16POWER_GAP_RISK) {
    Chery_E03_Hp_B.bRisk_PowerLimitation_f = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PowerLimitation_f = Chery_E03_Hp_DW.UnitDelay_DSTATE_hm;
  }

  /* End of Switch: '<S965>/Switch1' */

  /* Lookup_n-D: '<S965>/Power_cpr_diff' */
  Chery_E03_Hp_B.u16Ncomp_PowRisk_c = look1_is16lu32n16tu16_binlcse(rtb_Sum,
    ((int16_T *)&(u16Ncomp_PowRisk.s16Power_Comp_gap_u1[0])), ((uint16_T *)
    &(u16Ncomp_PowRisk.u16Ncomp_PowRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S965>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_hm = Chery_E03_Hp_B.bRisk_PowerLimitation_f;
}

/* System initialize for atomic system: '<S958>/T_eva_freezing_risk' */
void Chery_E03_Hp_T_eva_freezing_risk_m_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S966>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ag = false;
}

/* System reset for atomic system: '<S958>/T_eva_freezing_risk' */
void Chery_E03_Hp_T_eva_freezing_risk_f_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S966>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ag = false;
}

/* Output and update for atomic system: '<S958>/T_eva_freezing_risk' */
void Chery_E03_Hp_T_eva_freezing_risk_b(void)
{
  /* Switch: '<S966>/Switch2' incorporates:
   *  Constant: '<S966>/Def_Freezing_No_Limit'
   *  Constant: '<S966>/Def_Freezing_no1'
   *  RelationalOperator: '<S966>/RelationalOperator1'
   */
  if (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 >= 20) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_ag = bCONST_0;
  }

  /* End of Switch: '<S966>/Switch2' */

  /* Switch: '<S966>/Switch1' incorporates:
   *  Constant: '<S966>/Def_Freezing_Yes_Limit'
   *  Constant: '<S966>/Def_Freezing_yes'
   *  RelationalOperator: '<S966>/RelationalOperator'
   */
  if (Chery_E03_Hp_B.HpI_s16Teva_Front_A10 <= -10) {
    Chery_E03_Hp_B.bRisk_EvaFreeze = bCONST_1;
  } else {
    Chery_E03_Hp_B.bRisk_EvaFreeze = Chery_E03_Hp_DW.UnitDelay_DSTATE_ag;
  }

  /* End of Switch: '<S966>/Switch1' */

  /* Lookup_n-D: '<S966>/Teva_offset' */
  Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16Teva_Front_A10, ((int16_T *)
      &(u16Ncomp_EvaRisk_TotalDehum.s16Teva_risk_u1[0])), ((uint16_T *)
      &(u16Ncomp_EvaRisk_TotalDehum.u16Ncomp_EvaRisk_TotalDehum_y[0])), 7U);

  /* Update for UnitDelay: '<S966>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ag = Chery_E03_Hp_B.bRisk_EvaFreeze;
}

/* System initialize for atomic system: '<S937>/Risk_corrector' */
void Chery_E03_Hp_Risk_corrector_n_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S958>/T_eva_freezing_risk' */
  Chery_E03_Hp_T_eva_freezing_risk_m_Init();

  /* End of SystemInitialize for SubSystem: '<S958>/T_eva_freezing_risk' */

  /* SystemInitialize for Atomic SubSystem: '<S958>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_h_Init();

  /* End of SystemInitialize for SubSystem: '<S958>/PRCO_riskcorrection' */

  /* SystemInitialize for Atomic SubSystem: '<S958>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_i_Init();

  /* End of SystemInitialize for SubSystem: '<S958>/Pcomp_correction' */

  /* SystemInitialize for Atomic SubSystem: '<S958>/PRCI_Risk' */
  Chery_E03_Hp_PRCI_Risk_Init();

  /* End of SystemInitialize for SubSystem: '<S958>/PRCI_Risk' */

  /* SystemInitialize for Atomic SubSystem: '<S958>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_l_Init();

  /* End of SystemInitialize for SubSystem: '<S958>/EdcToutRisk' */
}

/* System reset for atomic system: '<S937>/Risk_corrector' */
void Chery_E03_Hp_Risk_corrector_f_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S958>/T_eva_freezing_risk' */
  Chery_E03_Hp_T_eva_freezing_risk_f_Reset();

  /* End of SystemReset for SubSystem: '<S958>/T_eva_freezing_risk' */

  /* SystemReset for Atomic SubSystem: '<S958>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_iq_Reset();

  /* End of SystemReset for SubSystem: '<S958>/PRCO_riskcorrection' */

  /* SystemReset for Atomic SubSystem: '<S958>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_k_Reset();

  /* End of SystemReset for SubSystem: '<S958>/Pcomp_correction' */

  /* SystemReset for Atomic SubSystem: '<S958>/PRCI_Risk' */
  Chery_E03_Hp_PRCI_Risk_Reset();

  /* End of SystemReset for SubSystem: '<S958>/PRCI_Risk' */

  /* SystemReset for Atomic SubSystem: '<S958>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_m3_Reset();

  /* End of SystemReset for SubSystem: '<S958>/EdcToutRisk' */
}

/*
 * Output and update for atomic system: '<S937>/Risk_corrector'
 * Block description for: '<S937>/Risk_corrector'
 *   risk value for EDC rpm compensation
 */
void Chery_E03_Hp_Risk_corrector_j(void)
{
  /* Outputs for Atomic SubSystem: '<S958>/T_eva_freezing_risk' */
  Chery_E03_Hp_T_eva_freezing_risk_b();

  /* End of Outputs for SubSystem: '<S958>/T_eva_freezing_risk' */

  /* Outputs for Atomic SubSystem: '<S958>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_m();

  /* End of Outputs for SubSystem: '<S958>/PRCO_riskcorrection' */

  /* Outputs for Atomic SubSystem: '<S958>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_a();

  /* End of Outputs for SubSystem: '<S958>/Pcomp_correction' */

  /* Outputs for Atomic SubSystem: '<S958>/EDC_Rpm_risk'
   *
   * Block description for '<S958>/EDC_Rpm_risk':
   *  This module for edc rpm calulation
   */
  Chery_E03_Hp_EDC_Rpm_risk_e();

  /* End of Outputs for SubSystem: '<S958>/EDC_Rpm_risk' */

  /* Outputs for Atomic SubSystem: '<S958>/PRCI_Risk' */
  Chery_E03_Hp_PRCI_Risk();

  /* End of Outputs for SubSystem: '<S958>/PRCI_Risk' */

  /* Outputs for Atomic SubSystem: '<S958>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_h();

  /* End of Outputs for SubSystem: '<S958>/EdcToutRisk' */

  /* Logic: '<S960>/OR' */
  Chery_E03_Hp_B.bEDC_Start_Config_pre_l = ((((((Chery_E03_Hp_B.bRisk_PRCO) ||
    (Chery_E03_Hp_B.bRisk_PowerLimitation_f)) ||
    (Chery_E03_Hp_B.bEDC_Start_Config_pre_l)) || (Chery_E03_Hp_B.bRisk_EvaFreeze))
    || (Chery_E03_Hp_B.bRisk_PRCI_HP_f)) || (Chery_E03_Hp_B.bRisk_EdcTout_e));

  /* MinMax: '<S960>/Max' */
  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum <=
      Chery_E03_Hp_B.u16Ncomp_PrcoRisk_f) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum =
      Chery_E03_Hp_B.u16Ncomp_PrcoRisk_f;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum <=
      Chery_E03_Hp_B.u16Ncomp_PowRisk_c) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum =
      Chery_E03_Hp_B.u16Ncomp_PowRisk_c;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum <=
      Chery_E03_Hp_ConstB.u16Ncomp_RpmRisk_j) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum =
      Chery_E03_Hp_ConstB.u16Ncomp_RpmRisk_j;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum <=
      Chery_E03_Hp_B.u16Ncomp_Prci_Risk_b) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum =
      Chery_E03_Hp_B.u16Ncomp_Prci_Risk_b;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum <=
      Chery_E03_Hp_B.u16Ncomp_Tout_Risk_j) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum =
      Chery_E03_Hp_B.u16Ncomp_Tout_Risk_j;
  }

  /* End of MinMax: '<S960>/Max' */
}

/*
 * Output and update for atomic system: '<S908>/EDC_Start_Configulation'
 * Block description for: '<S908>/EDC_Start_Configulation'
 *   edc startup condition judge
 */
void Chery_E03_Hp_EDC_Start_Configulation_b(void)
{
  /* Logic: '<S975>/LogicalOperator' incorporates:
   *  Constant: '<S975>/Q_HVAC_Blower_lowlimit'
   *  Constant: '<S975>/V_Air_condensor_lowlimit1'
   *  Constant: '<S975>/V_Air_condensor_lowlimit2'
   *  RelationalOperator: '<S975>/Comparison1'
   *  RelationalOperator: '<S975>/Comparison3'
   *  RelationalOperator: '<S975>/Comparison4'
   */
  Chery_E03_Hp_B.bEDC_Start_Config_pre_l =
    (((Chery_E03_Hp_B.HpI_u8BlwVol_Real_A10 >= u8BLW_VOL_MIN) &&
      (Chery_E03_Hp_B.HpI_u16Power_Max >= u16EDC_POWERMIN)) &&
     (Chery_E03_Hp_B.HpI_u16Ncomp_Max >= u16EDC_RPMMIN));
}

/*
 * System initialize for atomic system:
 *    '<S976>/Eva_Freeze_Status_Check'
 *    '<S627>/Eva_Freeze_Status_Check'
 */
void Chery_E03_Hp_Eva_Freeze_Status_Check_Init(boolean_T *rty_bEvafreeze_EDCoff,
  DW_Eva_Freeze_Status_Check_Chery_E03_Hp_T *localDW)
{
  localDW->is_active_c94_Chery_E03_Hp = 0U;
  localDW->is_c94_Chery_E03_Hp = Chery_E03_Hp_IN_NO_ACTIVE_CHILD_b;
  localDW->u16Count_Eva_FreezeCheck = 0U;
  localDW->u16Count_Eva_Freezerelease = 0U;
  *rty_bEvafreeze_EDCoff = false;
}

/*
 * System reset for atomic system:
 *    '<S976>/Eva_Freeze_Status_Check'
 *    '<S627>/Eva_Freeze_Status_Check'
 */
void Chery_E03_Hp_Eva_Freeze_Status_Check_Reset(boolean_T *rty_bEvafreeze_EDCoff,
  DW_Eva_Freeze_Status_Check_Chery_E03_Hp_T *localDW)
{
  localDW->is_active_c94_Chery_E03_Hp = 0U;
  localDW->is_c94_Chery_E03_Hp = Chery_E03_Hp_IN_NO_ACTIVE_CHILD_b;
  localDW->u16Count_Eva_FreezeCheck = 0U;
  localDW->u16Count_Eva_Freezerelease = 0U;
  *rty_bEvafreeze_EDCoff = false;
}

/*
 * Output and update for atomic system:
 *    '<S976>/Eva_Freeze_Status_Check'
 *    '<S627>/Eva_Freeze_Status_Check'
 */
void Chery_E03_Hp_Eva_Freeze_Status_Check(int16_T rtu_AC_s16Teva, boolean_T
  *rty_bEvafreeze_EDCoff, DW_Eva_Freeze_Status_Check_Chery_E03_Hp_T *localDW)
{
  /* Chart: '<S976>/Eva_Freeze_Status_Check' */
  /* None */
  if (((uint32_T)localDW->is_active_c94_Chery_E03_Hp) == 0U) {
    localDW->is_active_c94_Chery_E03_Hp = 1U;
    localDW->is_c94_Chery_E03_Hp = Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon;
    *rty_bEvafreeze_EDCoff = false;
  } else {
    switch (localDW->is_c94_Chery_E03_Hp) {
     case Chery_E03_Hp_IN_Eva_Freeze_EDC_Yes:
      if ((((int32_T)localDW->u16Count_Eva_Freezerelease) >= 400) &&
          (rtu_AC_s16Teva >= s16TEVA_NOR_RESTART)) {
        localDW->is_c94_Chery_E03_Hp = Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon;
        *rty_bEvafreeze_EDCoff = false;
      } else {
        *rty_bEvafreeze_EDCoff = true;
        localDW->u16Count_Eva_Freezerelease += u16COUNT_1;
      }
      break;

     case Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon:
      if (rtu_AC_s16Teva < s16TEVA_FREZEE) {
        /* Teva_freeze set point is 0 degree */
        localDW->is_c94_Chery_E03_Hp = Chery_E03_Hp_IN_Goto_Eva_FreezeEDC_Check;
        *rty_bEvafreeze_EDCoff = false;
        localDW->u16Count_Eva_FreezeCheck = u16COUNT_0;
      } else {
        *rty_bEvafreeze_EDCoff = false;

        /* exit: */
      }
      break;

     default:
      if (((int32_T)localDW->u16Count_Eva_FreezeCheck) >= 20) {
        /*  After 2S, the Eva_Freeze Confirm */
        localDW->is_c94_Chery_E03_Hp = Chery_E03_Hp_IN_Eva_Freeze_EDC_Yes;
        *rty_bEvafreeze_EDCoff = true;
        localDW->u16Count_Eva_Freezerelease = u16COUNT_0;
      } else if (rtu_AC_s16Teva > s16TEVA_FREEZE_NOR) {
        localDW->is_c94_Chery_E03_Hp = Chery_E03_Hp_IN_Eva_Not_Freeze_EDCon;
        *rty_bEvafreeze_EDCoff = false;
      } else {
        *rty_bEvafreeze_EDCoff = false;
        localDW->u16Count_Eva_FreezeCheck += u16COUNT_1;

        /* exit: */
      }
      break;
    }
  }

  /* End of Chart: '<S976>/Eva_Freeze_Status_Check' */
}

/*
 * System initialize for atomic system:
 *    '<S940>/Mode_Initialization_Flag_Decision'
 *    '<S573>/Mode_Initialization_Flag_Decision'
 */
void Chery_E03_Hp_Mode_Initialization_Flag_Decision_Init(boolean_T
  *rty_bMode_Initialize_Flag_No,
  DW_Mode_Initialization_Flag_Decision_Chery_E03_Hp_T *localDW)
{
  localDW->u16Count_Initial_Finish = u16CONST_0;
  *rty_bMode_Initialize_Flag_No = false;
}

/*
 * System reset for atomic system:
 *    '<S940>/Mode_Initialization_Flag_Decision'
 *    '<S573>/Mode_Initialization_Flag_Decision'
 */
void Chery_E03_Hp_Mode_Initialization_Flag_Decision_Reset(boolean_T
  *rty_bMode_Initialize_Flag_No,
  DW_Mode_Initialization_Flag_Decision_Chery_E03_Hp_T *localDW)
{
  localDW->u16Count_Initial_Finish = u16CONST_0;
  *rty_bMode_Initialize_Flag_No = false;
}

/*
 * Output and update for atomic system:
 *    '<S940>/Mode_Initialization_Flag_Decision'
 *    '<S573>/Mode_Initialization_Flag_Decision'
 */
void Chery_E03_Hp_Mode_Initialization_Flag_Decision(boolean_T
  *rty_bMode_Initialize_Flag_No,
  DW_Mode_Initialization_Flag_Decision_Chery_E03_Hp_T *localDW)
{
  int32_T tmp;

  /* Chart: '<S940>/Mode_Initialization_Flag_Decision' */
  if (((int32_T)localDW->u16Count_Initial_Finish) < 100) {
    tmp = ((int32_T)localDW->u16Count_Initial_Finish) + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    localDW->u16Count_Initial_Finish = (uint16_T)tmp;
    *rty_bMode_Initialize_Flag_No = false;
  } else {
    localDW->u16Count_Initial_Finish = 100U;
    *rty_bMode_Initialize_Flag_No = true;
  }

  /* End of Chart: '<S940>/Mode_Initialization_Flag_Decision' */
}

/* System initialize for atomic system: '<S342>/EDC_TotalDehum_Control' */
void Chery_E03_Hp_EDC_TotalDehum_Control_Init(void)
{
  /* local block i/o variables */
  boolean_T rtb_bMode_Initialize_Flag_No_b;
  boolean_T rtb_bEvafreeze_EDCoff_g;

  /* InitializeConditions for UnitDelay: '<S936>/Unit Delay3' */
  Chery_E03_Hp_DW.UnitDelay3_DSTATE_e = 0;

  /* InitializeConditions for MinMax: '<S957>/Max1' incorporates:
   *  UnitDelay: '<S936>/Unit Delay1'
   */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_j = 0;

  /* SystemInitialize for Atomic SubSystem: '<S937>/Risk_corrector'
   *
   * Block description for '<S937>/Risk_corrector':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_n_Init();

  /* End of SystemInitialize for SubSystem: '<S937>/Risk_corrector' */

  /* SystemInitialize for Chart: '<S940>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_Mode_Initialization_Flag_Decision_Init
    (&rtb_bMode_Initialize_Flag_No_b,
     &Chery_E03_Hp_DW.sf_Mode_Initialization_Flag_Decision_f);

  /* SystemInitialize for Chart: '<S976>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_Eva_Freeze_Status_Check_Init(&rtb_bEvafreeze_EDCoff_g,
    &Chery_E03_Hp_DW.sf_Eva_Freeze_Status_Check_k);
}

/* System reset for atomic system: '<S342>/EDC_TotalDehum_Control' */
void Chery_E03_Hp_EDC_TotalDehum_Control_Reset(void)
{
  /* local block i/o variables */
  boolean_T rtb_bMode_Initialize_Flag_No_b;
  boolean_T rtb_bEvafreeze_EDCoff_g;

  /* InitializeConditions for UnitDelay: '<S936>/Unit Delay3' */
  Chery_E03_Hp_DW.UnitDelay3_DSTATE_e = 0;

  /* InitializeConditions for MinMax: '<S957>/Max1' incorporates:
   *  UnitDelay: '<S936>/Unit Delay1'
   */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_j = 0;

  /* SystemReset for Atomic SubSystem: '<S937>/Risk_corrector'
   *
   * Block description for '<S937>/Risk_corrector':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_f_Reset();

  /* End of SystemReset for SubSystem: '<S937>/Risk_corrector' */

  /* SystemReset for Chart: '<S940>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_Mode_Initialization_Flag_Decision_Reset
    (&rtb_bMode_Initialize_Flag_No_b,
     &Chery_E03_Hp_DW.sf_Mode_Initialization_Flag_Decision_f);

  /* SystemReset for Chart: '<S976>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_Eva_Freeze_Status_Check_Reset(&rtb_bEvafreeze_EDCoff_g,
    &Chery_E03_Hp_DW.sf_Eva_Freeze_Status_Check_k);
}

/*
 * Output and update for atomic system: '<S342>/EDC_TotalDehum_Control'
 * Block description for: '<S342>/EDC_TotalDehum_Control'
 *   ACChiller Mode_ EDC Control
 */
void Chery_E03_Hp_EDC_TotalDehum_Control(void)
{
  /* local block i/o variables */
  boolean_T rtb_bMode_Initialize_Flag_No_b;
  boolean_T rtb_bEvafreeze_EDCoff_g;
  int32_T rtb_Switch;
  int16_T rtb_Saturation1;
  int32_T rtb_Switch_hw;
  boolean_T rtb_LowerRelop1_k;

  /* Outputs for Atomic SubSystem: '<S935>/EDC_Estimation_TotalDehum'
   *
   * Block description for '<S935>/EDC_Estimation_TotalDehum':
   *  edc forward rpm estimation
   */
  Chery_E03_Hp_EDC_Estimation_TotalDehum();

  /* End of Outputs for SubSystem: '<S935>/EDC_Estimation_TotalDehum' */

  /* Outputs for Atomic SubSystem: '<S935>/Ncomp_Estimation_Chiller'
   *
   * Block description for '<S935>/Ncomp_Estimation_Chiller':
   *  edc for ac_chiller mode compensation for chiller
   */
  Chery_E03_Hp_Ncomp_Estimation_Chiller_h();

  /* End of Outputs for SubSystem: '<S935>/Ncomp_Estimation_Chiller' */

  /* Product: '<S943>/Product3' incorporates:
   *  Constant: '<S943>/AMP_10_1'
   *  Sum: '<S943>/Sum4'
   */
  rtb_Switch = (int32_T)((uint32_T)(((uint32_T)((uint16_T)((int32_T)(((int32_T)
    ((int16_T)(((int16_T)Chery_E03_Hp_B.u16Ncomp_Prci_Risk_b) + ((int16_T)
    Chery_E03_Hp_B.u16Ncomp_Tout_Risk_j)))) + ((int32_T)((int16_T)
    Chery_E03_Hp_ConstB.u16Ncomp_AC_RearEva_Est_e)))))) * ((uint32_T)u8AMP_10)));

  /* Saturate: '<S943>/Saturation' */
  if (rtb_Switch > s32NCOMP_FOR_ACCHIL) {
    rtb_Switch = s32NCOMP_FOR_ACCHIL;
  } else {
    if (rtb_Switch < s32NCOMP_STOP_0) {
      rtb_Switch = s32NCOMP_STOP_0;
    }
  }

  /* End of Saturate: '<S943>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S935>/PIparameters'
   *
   * Block description for '<S935>/PIparameters':
   *  AC_EDC_PI parameter
   */
  Chery_E03_Hp_PIparameters_b();

  /* End of Outputs for SubSystem: '<S935>/PIparameters' */

  /* Saturate: '<S943>/Saturation1' */
  if (Chery_E03_Hp_B.s16T_Water_Ctrl_Delta_g > 250) {
    rtb_Saturation1 = 250;
  } else if (Chery_E03_Hp_B.s16T_Water_Ctrl_Delta_g < -250) {
    rtb_Saturation1 = -250;
  } else {
    rtb_Saturation1 = Chery_E03_Hp_B.s16T_Water_Ctrl_Delta_g;
  }

  /* End of Saturate: '<S943>/Saturation1' */

  /* Sum: '<S943>/Sum1' incorporates:
   *  Product: '<S943>/Product1'
   */
  rtb_Switch += ((int32_T)rtb_Saturation1) * ((int32_T)
    Chery_E03_Hp_B.u16Ncomp_Prci_Risk_b);

  /* Sum: '<S943>/Sum3' incorporates:
   *  Constant: '<S943>/AMP_10_2'
   *  Constant: '<S943>/AMP_10_3'
   *  Constant: '<S946>/Constant'
   *  Product: '<S943>/Product2'
   *  Product: '<S943>/Product4'
   *  Product: '<S943>/Product5'
   *  UnitDelay: '<S936>/Unit Delay3'
   */
  rtb_Switch_hw = ((div_nde_s32_floor(((int32_T)rtb_Saturation1) * ((int32_T)
    Chery_E03_Hp_B.u16Ncomp_Tout_Risk_j), (int32_T)u8AMP_100) + rtb_Switch) +
                   Chery_E03_Hp_DW.UnitDelay3_DSTATE_e) - ((int32_T)((uint32_T)
    (((uint32_T)u16CONST_0) * ((uint32_T)u8AMP_10))));

  /* Outputs for Atomic SubSystem: '<S937>/Risk_corrector'
   *
   * Block description for '<S937>/Risk_corrector':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_j();

  /* End of Outputs for SubSystem: '<S937>/Risk_corrector' */

  /* Switch: '<S957>/Switch' incorporates:
   *  Constant: '<S957>/Amplificate rate 10 for the Kp_rate'
   *  Constant: '<S959>/Constant'
   *  Product: '<S957>/Product'
   *  RelationalOperator: '<S959>/Compare'
   *  Sum: '<S957>/Sum'
   */
  if (Chery_E03_Hp_B.bEDC_Start_Config_pre_l != bFAIL_NO_RISK_0) {
    /* MinMax: '<S957>/Max1' incorporates:
     *  UnitDelay: '<S936>/Unit Delay1'
     */
    if (rtb_Switch_hw < Chery_E03_Hp_DW.UnitDelay1_DSTATE_j) {
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_j = rtb_Switch_hw;
    }

    rtb_Switch_hw = Chery_E03_Hp_DW.UnitDelay1_DSTATE_j - ((int32_T)((uint32_T)
      (((uint32_T)Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum) * ((uint32_T)
      u8AMP_10))));
  }

  /* End of Switch: '<S957>/Switch' */

  /* Saturate: '<S957>/AfRisk_Pre_Satuation' */
  if (rtb_Switch_hw > s32NCOMP_UP_LIMIT) {
    rtb_Switch_hw = s32NCOMP_UP_LIMIT;
  } else {
    if (rtb_Switch_hw < s32NCOMP_STOP_0) {
      rtb_Switch_hw = s32NCOMP_STOP_0;
    }
  }

  /* End of Saturate: '<S957>/AfRisk_Pre_Satuation' */

  /* Switch: '<S936>/Switch1' incorporates:
   *  Constant: '<S936>/Constant2'
   *  Constant: '<S953>/Constant'
   *  Constant: '<S954>/Constant'
   *  Logic: '<S936>/AND'
   *  RelationalOperator: '<S953>/Compare'
   *  RelationalOperator: '<S954>/Compare'
   */
  if ((rtb_Switch_hw < s32NCOMP_DOWN_LIMIT) && (rtb_Switch_hw > s32NCOMP_DOWN_0))
  {
    rtb_Switch_hw = s32NCOMP_DOWN_LIMIT;
  }

  /* End of Switch: '<S936>/Switch1' */

  /* Chart: '<S940>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_Mode_Initialization_Flag_Decision(&rtb_bMode_Initialize_Flag_No_b,
    &Chery_E03_Hp_DW.sf_Mode_Initialization_Flag_Decision_f);

  /* Switch: '<S936>/Switch2' incorporates:
   *  Constant: '<S936>/Constant4'
   */
  if (!rtb_bMode_Initialize_Flag_No_b) {
    rtb_Switch_hw = s32NCOMP_DOWN_LIMIT;
  }

  /* End of Switch: '<S936>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S908>/EDC_Start_Configulation'
   *
   * Block description for '<S908>/EDC_Start_Configulation':
   *  edc startup condition judge
   */
  Chery_E03_Hp_EDC_Start_Configulation_b();

  /* End of Outputs for SubSystem: '<S908>/EDC_Start_Configulation' */

  /* Switch: '<S936>/Switch3' incorporates:
   *  Constant: '<S936>/Constant5'
   */
  if (!Chery_E03_Hp_B.bEDC_Start_Config_pre_l) {
    rtb_Switch_hw = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S936>/Switch3' */

  /* MinMax: '<S957>/Max1' incorporates:
   *  Gain: '<S936>/Gain1'
   */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_j = (int32_T)((uint32_T)(10U * ((uint32_T)
    Chery_E03_Hp_B.HpI_u16Ncomp_Max)));

  /* MinMax: '<S936>/Min2' incorporates:
   *  Constant: '<S936>/Constant7'
   */
  if (Chery_E03_Hp_DW.UnitDelay1_DSTATE_j >= s32NCOMP_UP_LIMIT) {
    /* MinMax: '<S957>/Max1' */
    Chery_E03_Hp_DW.UnitDelay1_DSTATE_j = s32NCOMP_UP_LIMIT;
  }

  /* End of MinMax: '<S936>/Min2' */

  /* RelationalOperator: '<S956>/LowerRelop1' */
  rtb_LowerRelop1_k = (rtb_Switch_hw > Chery_E03_Hp_DW.UnitDelay1_DSTATE_j);

  /* Switch: '<S956>/Switch' incorporates:
   *  Constant: '<S936>/Constant8'
   *  RelationalOperator: '<S956>/UpperRelop'
   */
  if (rtb_Switch_hw < s32NCOMP_DOWN_0) {
    rtb_Switch_hw = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S956>/Switch' */

  /* Switch: '<S956>/Switch2' */
  if (!rtb_LowerRelop1_k) {
    /* MinMax: '<S957>/Max1' incorporates:
     *  UnitDelay: '<S936>/Unit Delay1'
     */
    Chery_E03_Hp_DW.UnitDelay1_DSTATE_j = rtb_Switch_hw;
  }

  /* End of Switch: '<S956>/Switch2' */

  /* Product: '<S936>/Product' incorporates:
   *  Constant: '<S936>/Constant1'
   *  UnitDelay: '<S936>/Unit Delay1'
   */
  Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum = (uint16_T)((int32_T)
    (Chery_E03_Hp_DW.UnitDelay1_DSTATE_j / ((int32_T)u8AMP_10)));

  /* Sum: '<S936>/Sum3' incorporates:
   *  UnitDelay: '<S936>/Unit Delay1'
   */
  rtb_Switch = Chery_E03_Hp_DW.UnitDelay1_DSTATE_j - rtb_Switch;

  /* RelationalOperator: '<S955>/LowerRelop1' incorporates:
   *  Constant: '<S936>/Constant3'
   */
  rtb_LowerRelop1_k = (rtb_Switch > s32NCOMP_ICAL_UP);

  /* Switch: '<S955>/Switch' incorporates:
   *  Constant: '<S936>/Constant6'
   *  RelationalOperator: '<S955>/UpperRelop'
   */
  if (rtb_Switch < s32NCOMP_DOWN_0) {
    rtb_Switch = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S955>/Switch' */

  /* Switch: '<S955>/Switch2' incorporates:
   *  Constant: '<S936>/Constant3'
   *  UnitDelay: '<S936>/Unit Delay3'
   */
  if (rtb_LowerRelop1_k) {
    Chery_E03_Hp_DW.UnitDelay3_DSTATE_e = s32NCOMP_ICAL_UP;
  } else {
    Chery_E03_Hp_DW.UnitDelay3_DSTATE_e = rtb_Switch;
  }

  /* End of Switch: '<S955>/Switch2' */

  /* Chart: '<S976>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_Eva_Freeze_Status_Check(Chery_E03_Hp_B.HpI_s16Teva_Front_A10,
    &rtb_bEvafreeze_EDCoff_g, &Chery_E03_Hp_DW.sf_Eva_Freeze_Status_Check_k);
}

/* System initialize for atomic system: '<S1018>/Hyster_And_Delay_Judge' */
void Chery_E03_Hp_Hyster_And_Delay_Judge_i_Init
  (DW_Hyster_And_Delay_Judge_Chery_E03_Hp_o_T *localDW, boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S1021>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;

  /* SystemInitialize for Atomic SubSystem: '<S1021>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&localDW->DelayJudge);

  /* End of SystemInitialize for SubSystem: '<S1021>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1021>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&localDW->DelayJudge1);

  /* End of SystemInitialize for SubSystem: '<S1021>/DelayJudge1' */
}

/* System reset for atomic system: '<S1018>/Hyster_And_Delay_Judge' */
void Chery_E03_Hp_Hyster_And_Delay_Judge_o_Reset
  (DW_Hyster_And_Delay_Judge_Chery_E03_Hp_o_T *localDW, boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S1021>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;

  /* SystemReset for Atomic SubSystem: '<S1021>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Reset(&localDW->DelayJudge);

  /* End of SystemReset for SubSystem: '<S1021>/DelayJudge' */

  /* SystemReset for Atomic SubSystem: '<S1021>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Reset(&localDW->DelayJudge1);

  /* End of SystemReset for SubSystem: '<S1021>/DelayJudge1' */
}

/* Output and update for atomic system: '<S1018>/Hyster_And_Delay_Judge' */
boolean_T Chery_E03_Hp_Hyster_And_Delay_Judge_m(uint16_T rtu_ParaJudgeUp,
  uint16_T rtu_HyJudgeIn, uint16_T rtu_ParaJudgeDown, const
  ConstB_Hyster_And_Delay_Judge_Chery_E03_Hp_c_T *localC,
  DW_Hyster_And_Delay_Judge_Chery_E03_Hp_o_T *localDW, boolean_T
  rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;
  boolean_T rtb_SignalCopy_hm;
  boolean_T rtb_SignalCopy_bs;

  /* Outputs for Atomic SubSystem: '<S1021>/DelayJudge' */
  /* RelationalOperator: '<S1021>/RelationalOperator3' */
  rtb_SignalCopy_bs = ( Chery_E03_Hp_DelayJudge(rtu_HyJudgeIn >= rtu_ParaJudgeUp,
    &localC->DelayJudge, &localDW->DelayJudge) != false);

  /* End of Outputs for SubSystem: '<S1021>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1021>/DelayJudge1' */
  /* RelationalOperator: '<S1021>/RelationalOperator1' */
  rtb_SignalCopy_hm = ( Chery_E03_Hp_DelayJudge(rtu_HyJudgeIn <=
    rtu_ParaJudgeDown, &localC->DelayJudge1, &localDW->DelayJudge1) != false);

  /* End of Outputs for SubSystem: '<S1021>/DelayJudge1' */

  /* Switch: '<S1021>/Switch4' incorporates:
   *  Constant: '<S1021>/JudgeYes'
   *  Logic: '<S1021>/NOT'
   */
  if (rtb_SignalCopy_hm) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S1021>/Switch4' */

  /* Switch: '<S1021>/Switch2' incorporates:
   *  Constant: '<S1021>/JudgeYes'
   */
  if (rtb_SignalCopy_bs) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S1021>/Switch2' */

  /* Update for UnitDelay: '<S1021>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/* System initialize for atomic system: '<S1019>/Hyster_And_Delay_Judge' */
void Chery_E03_Hp_Hyster_And_Delay_Judge_m_Init
  (DW_Hyster_And_Delay_Judge_Chery_E03_Hp_b_T *localDW, boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S1032>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;

  /* SystemInitialize for Atomic SubSystem: '<S1032>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&localDW->DelayJudge);

  /* End of SystemInitialize for SubSystem: '<S1032>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1032>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&localDW->DelayJudge1);

  /* End of SystemInitialize for SubSystem: '<S1032>/DelayJudge1' */
}

/* System reset for atomic system: '<S1019>/Hyster_And_Delay_Judge' */
void Chery_E03_Hp_Hyster_And_Delay_Judge_d_Reset
  (DW_Hyster_And_Delay_Judge_Chery_E03_Hp_b_T *localDW, boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S1032>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;

  /* SystemReset for Atomic SubSystem: '<S1032>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Reset(&localDW->DelayJudge);

  /* End of SystemReset for SubSystem: '<S1032>/DelayJudge' */

  /* SystemReset for Atomic SubSystem: '<S1032>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Reset(&localDW->DelayJudge1);

  /* End of SystemReset for SubSystem: '<S1032>/DelayJudge1' */
}

/* Output and update for atomic system: '<S1019>/Hyster_And_Delay_Judge' */
boolean_T Chery_E03_Hp_Hyster_And_Delay_Judge_h(int16_T rtu_ParaJudgeUp, int16_T
  rtu_HyJudgeIn, int16_T rtu_ParaJudgeDown, const
  ConstB_Hyster_And_Delay_Judge_Chery_E03_Hp_d_T *localC,
  DW_Hyster_And_Delay_Judge_Chery_E03_Hp_b_T *localDW, boolean_T
  rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;
  boolean_T rtb_SignalCopy_ja;
  boolean_T rtb_SignalCopy_ol;

  /* Outputs for Atomic SubSystem: '<S1032>/DelayJudge' */
  /* RelationalOperator: '<S1032>/RelationalOperator3' */
  rtb_SignalCopy_ol = ( Chery_E03_Hp_DelayJudge(rtu_HyJudgeIn >= rtu_ParaJudgeUp,
    &localC->DelayJudge, &localDW->DelayJudge) != false);

  /* End of Outputs for SubSystem: '<S1032>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1032>/DelayJudge1' */
  /* RelationalOperator: '<S1032>/RelationalOperator1' */
  rtb_SignalCopy_ja = ( Chery_E03_Hp_DelayJudge(rtu_HyJudgeIn <=
    rtu_ParaJudgeDown, &localC->DelayJudge1, &localDW->DelayJudge1) != false);

  /* End of Outputs for SubSystem: '<S1032>/DelayJudge1' */

  /* Switch: '<S1032>/Switch4' incorporates:
   *  Constant: '<S1032>/JudgeYes'
   *  Logic: '<S1032>/NOT'
   */
  if (rtb_SignalCopy_ja) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S1032>/Switch4' */

  /* Switch: '<S1032>/Switch2' incorporates:
   *  Constant: '<S1032>/JudgeYes'
   */
  if (rtb_SignalCopy_ol) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S1032>/Switch2' */

  /* Update for UnitDelay: '<S1032>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/* Output and update for atomic system: '<S505>/IfThenElse1' */
uint16_T Chery_E03_Hp_IfThenElse1(boolean_T rtu_bIf, uint16_T rtu_Then, uint8_T
  rtu_Else)
{
  uint16_T rty_Out_0;

  /* Switch: '<S563>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S566>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S566>/Conversion' */
    rty_Out_0 = (uint16_T)rtu_Else;
  }

  /* End of Switch: '<S563>/Switch' */
  return rty_Out_0;
}

/*
 * Output and update for atomic system: '<S568>/EDC_Estimation_TotalDehum'
 * Block description for: '<S568>/EDC_Estimation_TotalDehum'
 *   edc forward rpm estimation
 */
void Chery_E03_Hp_EDC_Estimation_TotalDehum_k(void)
{
  uint32_T u0;

  /* Product: '<S575>/Product' incorporates:
   *  Constant: '<S575>/Constant'
   *  Lookup_n-D: '<S575>/Ncomp_TotalDehum_Est'
   *  Lookup_n-D: '<S575>/Ratio_AirFlowRate'
   */
  u0 = (((uint32_T)look2_is16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
          Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req, ((int16_T *)
           &(u16Ncomp_HP_Est.s16Tamb_Common2_u1[0])), ((int16_T *)
           &(u16Ncomp_HP_Est.s16Tasd_TotalDehum_u2[0])), ((uint16_T *)
           &(u16Ncomp_HP_Est.u16Ncomp_HP_Est_y[0])),
          Chery_E03_Hp_ConstP.pooled17, 10U)) * ((uint32_T)
         look2_is16u16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
          Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
           &(u16Percent_EDCEst_HP.s16Tamb_HP_u1[0])), ((uint16_T *)
           &(u16Percent_EDCEst_HP.u16_QBlower_HVAC_u2[0])), ((uint16_T *)
           &(u16Percent_EDCEst_HP.u16Percent_EDCEst_HP_y[0])),
          Chery_E03_Hp_ConstP.pooled15, 7U))) / ((uint32_T)u16AMP_100);

  /* Saturate: '<S575>/Saturation' */
  if (u0 >= 7000U) {
    u0 = 7000U;
  }

  Chery_E03_Hp_B.u16Ncomp_Prci_Risk = (uint16_T)u0;

  /* End of Saturate: '<S575>/Saturation' */
}

/*
 * Output and update for atomic system: '<S568>/Ncomp_Estimation_Chiller'
 * Block description for: '<S568>/Ncomp_Estimation_Chiller'
 *   edc for ac_chiller mode compensation for chiller
 */
void Chery_E03_Hp_Ncomp_Estimation_Chiller_b(void)
{
  /* Constant: '<S577>/Constant2' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_a = u16NCOMP_STOP_0;
}

/*
 * Output and update for atomic system: '<S568>/PIparameters'
 * Block description for: '<S568>/PIparameters'
 *   AC_EDC_PI parameter
 */
void Chery_E03_Hp_PIparameters_o(void)
{
  int16_T rtb_Conversion;
  int16_T y;

  /* MinMax: '<S578>/Max' */
  if (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req >
      Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10) {
    y = Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req;
  } else {
    y = Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10;
  }

  /* End of MinMax: '<S578>/Max' */

  /* Outputs for Atomic SubSystem: '<S578>/IfThenElse' */
  /* RelationalOperator: '<S584>/Compare' incorporates:
   *  Constant: '<S584>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Conversion = (int16_T) Chery_E03_Hp_IfThenElse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_BatHeat_10, y,
     Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req);

  /* End of Outputs for SubSystem: '<S578>/IfThenElse' */

  /* Sum: '<S578>/Sum' */
  Chery_E03_Hp_B.s16T_Water_Ctrl_Delta = (int16_T)(rtb_Conversion -
    Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10);

  /* Lookup_n-D: '<S578>/Ki_EDC_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_a = look2_is16u16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC,
     ((int16_T *)&(u16Ki_EDC_HP.s16Tamb_HP_u1[0])), ((uint16_T *)
      &(u16Ki_EDC_HP.u16_QBlower_HVAC_u2[0])), ((uint16_T *)
      &(u16Ki_EDC_HP.u16Ki_EDC_HP_y[0])), Chery_E03_Hp_ConstP.pooled15, 7U);

  /* Lookup_n-D: '<S578>/Kp_EDC_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Prci_Risk = look2_is16u16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC,
     ((int16_T *)&(u16Kp_EDC_HP.s16Tamb_HP_u1[0])), ((uint16_T *)
      &(u16Kp_EDC_HP.u16_QBlower_HVAC_u2[0])), ((uint16_T *)
      &(u16Kp_EDC_HP.u16Kp_EDC_HP_y[0])), Chery_E03_Hp_ConstP.pooled15, 7U);
}

/*
 * Output and update for atomic system: '<S594>/EDC_Rpm_risk'
 * Block description for: '<S594>/EDC_Rpm_risk'
 *   This module for edc rpm calulation
 */
void Chery_E03_Hp_EDC_Rpm_risk_p(void)
{
  /* Constant: '<S597>/Def_Pcomprisk_yes_set1' */
  Chery_E03_Hp_B.Def_Pcomprisk_yes_set1 = bFAIL_NO_RISK_0;
}

/* System initialize for atomic system: '<S594>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_gu_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S598>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_k2 = false;
}

/* System reset for atomic system: '<S594>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_k_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S598>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_k2 = false;
}

/* Output and update for atomic system: '<S594>/EdcToutRisk' */
void Chery_E03_Hp_EdcToutRisk_d(void)
{
  /* Switch: '<S598>/Switch3' incorporates:
   *  Constant: '<S598>/Pressure_Ratio_Risk_N'
   *  Constant: '<S605>/Constant'
   *  RelationalOperator: '<S605>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 <= 1150) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_k2 = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S598>/Switch3' */

  /* Switch: '<S598>/Switch2' incorporates:
   *  Constant: '<S598>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S604>/Constant'
   *  RelationalOperator: '<S604>/Compare'
   */
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 >= 1200) {
    Chery_E03_Hp_B.bRisk_EdcTout = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_EdcTout = Chery_E03_Hp_DW.UnitDelay_DSTATE_k2;
  }

  /* End of Switch: '<S598>/Switch2' */

  /* Lookup_n-D: '<S598>/EdcTout_Risk_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Tout_Risk_a = look1_is16lu32n16tu16_binlcse
    (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10, ((int16_T *)
      &(u16Edc_ToutReduce.s16EdcTout_Risk_u1[0])), ((uint16_T *)
      &(u16Edc_ToutReduce.u16Edc_ToutReduce_y[0])), 7U);

  /* Update for UnitDelay: '<S598>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_k2 = Chery_E03_Hp_B.bRisk_EdcTout;
}

/* System initialize for atomic system: '<S594>/PRCI_Risk' */
void Chery_E03_Hp_PRCI_Risk_m_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S599>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_nb = false;
}

/* System reset for atomic system: '<S594>/PRCI_Risk' */
void Chery_E03_Hp_PRCI_Risk_a_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S599>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_nb = false;
}

/* Output and update for atomic system: '<S594>/PRCI_Risk' */
void Chery_E03_Hp_PRCI_Risk_n(void)
{
  /* Switch: '<S599>/Switch3' incorporates:
   *  Constant: '<S599>/Pressure_Ratio_Risk_N'
   *  Constant: '<S607>/Constant'
   *  RelationalOperator: '<S607>/Compare'
   */
  if (((int32_T)Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10) >= 13) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_nb = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S599>/Switch3' */

  /* Switch: '<S599>/Switch2' incorporates:
   *  Constant: '<S599>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S606>/Constant'
   *  RelationalOperator: '<S606>/Compare'
   */
  if (((int32_T)Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10) <= 11) {
    Chery_E03_Hp_B.bRisk_PRCI_HP = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PRCI_HP = Chery_E03_Hp_DW.UnitDelay_DSTATE_nb;
  }

  /* End of Switch: '<S599>/Switch2' */

  /* Lookup_n-D: '<S599>/Prci_Risk_Calculation' */
  Chery_E03_Hp_B.u16Ncomp_Prci_Risk = look1_iu16lu32n16_binlcse
    (Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10, ((uint16_T *)
      &(u16Ncomp_PrciRisk_HP.u16Prci_risk_HP_u1[0])), ((uint16_T *)
      &(u16Ncomp_PrciRisk_HP.u16Ncomp_PrciRisk_HP_y[0])), 7U);

  /* Update for UnitDelay: '<S599>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_nb = Chery_E03_Hp_B.bRisk_PRCI_HP;
}

/* System initialize for atomic system: '<S594>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_hk_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S600>/Hyster' */
  Chery_E03_Hp_Hyster_f_Init(&Chery_E03_Hp_DW.Hyster_i);

  /* End of SystemInitialize for SubSystem: '<S600>/Hyster' */

  /* SystemInitialize for Atomic SubSystem: '<S600>/Hyster1' */
  Chery_E03_Hp_Hyster1_Init(&Chery_E03_Hp_DW.Hyster1_h);

  /* End of SystemInitialize for SubSystem: '<S600>/Hyster1' */
}

/* System reset for atomic system: '<S594>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_ii_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S600>/Hyster' */
  Chery_E03_Hp_Hyster_m_Reset(&Chery_E03_Hp_DW.Hyster_i);

  /* End of SystemReset for SubSystem: '<S600>/Hyster' */

  /* SystemReset for Atomic SubSystem: '<S600>/Hyster1' */
  Chery_E03_Hp_Hyster1_Reset(&Chery_E03_Hp_DW.Hyster1_h);

  /* End of SystemReset for SubSystem: '<S600>/Hyster1' */
}

/* Output and update for atomic system: '<S594>/PRCO_riskcorrection' */
void Chery_E03_Hp_PRCO_riskcorrection_k(void)
{
  boolean_T rtb_Conversion;
  boolean_T rtb_Conversion_g;

  /* Outputs for Atomic SubSystem: '<S600>/Hyster' */
  /* Constant: '<S600>/Def_Prco_Yes_Limit' incorporates:
   *  Constant: '<S600>/Def_Prco_No_Limit'
   *  Constant: '<S600>/Prco_no'
   *  Constant: '<S600>/Prco_yes'
   */
  rtb_Conversion_g = ( Chery_E03_Hp_Hyster_n
                      (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, u16PRCO_RISK,
                       u16PRCO_NORISK, bCONST_1, bCONST_0,
                       &Chery_E03_Hp_DW.Hyster_i, 0.0) != false);

  /* End of Outputs for SubSystem: '<S600>/Hyster' */

  /* Outputs for Atomic SubSystem: '<S600>/Hyster1' */
  /* Constant: '<S600>/Prco_yes1' incorporates:
   *  Constant: '<S600>/Prco_no1'
   */
  rtb_Conversion = ( Chery_E03_Hp_Hyster1
                    (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, bCONST_1, bCONST_0,
                     &Chery_E03_Hp_ConstB.Hyster1_h, &Chery_E03_Hp_DW.Hyster1_h,
                     0.0) != false);

  /* End of Outputs for SubSystem: '<S600>/Hyster1' */

  /* Switch: '<S600>/Switch' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S608>/Constant'
   *  Lookup_n-D: '<S600>/Prco_offset'
   *  Lookup_n-D: '<S600>/Prco_offset1'
   *  RelationalOperator: '<S608>/Compare'
   *  Switch: '<S600>/Switch1'
   */
  if (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1) {
    Chery_E03_Hp_B.bEDC_Start_Config_pre_m = rtb_Conversion;
    Chery_E03_Hp_B.u16Ncomp_PrcoRisk_d = look1_iu16lu32n16_binlcse
      (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((uint16_T *)
        &(AC_u16Ncomp_PrcoRisk_ValeoEDC.AC_u16Prco_risk_ValeoEDC_u1[0])),
       ((uint16_T *)
        &(AC_u16Ncomp_PrcoRisk_ValeoEDC.AC_u16Ncomp_PrcoRisk_ValeoEDC_y[0])), 7U);
  } else {
    Chery_E03_Hp_B.bEDC_Start_Config_pre_m = rtb_Conversion_g;
    Chery_E03_Hp_B.u16Ncomp_PrcoRisk_d = look1_iu16lu32n16_binlcse
      (Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((uint16_T *)
        &(u16Ncomp_PrcoRisk.u16Prco_risk_u1[0])), ((uint16_T *)
        &(u16Ncomp_PrcoRisk.u16Ncomp_PrcoRisk_y[0])), 7U);
  }

  /* End of Switch: '<S600>/Switch' */
}

/* System initialize for atomic system: '<S594>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_k_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S601>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_h4 = false;
}

/* System reset for atomic system: '<S594>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_f_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S601>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_h4 = false;
}

/* Output and update for atomic system: '<S594>/Pcomp_correction' */
void Chery_E03_Hp_Pcomp_correction_m(void)
{
  int16_T rtb_u16Ncomp_PowRisk;

  /* Sum: '<S601>/Sum' */
  rtb_u16Ncomp_PowRisk = (int16_T)(((int16_T)Chery_E03_Hp_B.HpI_u16Power_Max) -
    ((int16_T)Chery_E03_Hp_B.HpI_u16PowerComp));

  /* Switch: '<S601>/Switch2' incorporates:
   *  Constant: '<S601>/Def_Pcomprisk_No'
   *  Constant: '<S623>/Constant'
   *  RelationalOperator: '<S623>/Compare'
   */
  if (rtb_u16Ncomp_PowRisk >= s16POWER_GAP_NORISK) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_h4 = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S601>/Switch2' */

  /* Switch: '<S601>/Switch1' incorporates:
   *  Constant: '<S601>/Def_Pcomprisk_yes_set'
   *  Constant: '<S622>/Constant'
   *  RelationalOperator: '<S622>/Compare'
   */
  if (rtb_u16Ncomp_PowRisk <= s16POWER_GAP_RISK) {
    Chery_E03_Hp_B.bRisk_PowerLimitation = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_PowerLimitation = Chery_E03_Hp_DW.UnitDelay_DSTATE_h4;
  }

  /* End of Switch: '<S601>/Switch1' */

  /* Lookup_n-D: '<S601>/Power_cpr_diff' */
  Chery_E03_Hp_B.u16Ncomp_PowRisk_h = look1_is16lu32n16tu16_binlcse
    (rtb_u16Ncomp_PowRisk, ((int16_T *)&(u16Ncomp_PowRisk.s16Power_Comp_gap_u1[0])),
     ((uint16_T *)&(u16Ncomp_PowRisk.u16Ncomp_PowRisk_y[0])), 7U);

  /* Update for UnitDelay: '<S601>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_h4 = Chery_E03_Hp_B.bRisk_PowerLimitation;
}

/* System initialize for atomic system: '<S594>/Pressure_Ratio_Risk' */
void Chery_E03_Hp_Pressure_Ratio_Risk_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S602>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_a = false;
}

/* System reset for atomic system: '<S594>/Pressure_Ratio_Risk' */
void Chery_E03_Hp_Pressure_Ratio_Risk_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S602>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_a = false;
}

/* Output and update for atomic system: '<S594>/Pressure_Ratio_Risk' */
void Chery_E03_Hp_Pressure_Ratio_Risk(void)
{
  uint16_T rtb_Product_e;

  /* Product: '<S602>/Product' */
  rtb_Product_e = (uint16_T)(((uint32_T)Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10)
    / ((uint32_T)Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10));

  /* Switch: '<S602>/Switch3' incorporates:
   *  Constant: '<S602>/Pressure_Ratio_Risk_N'
   *  Constant: '<S625>/Constant'
   *  RelationalOperator: '<S625>/Compare'
   */
  if (((int32_T)rtb_Product_e) <= 12) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_a = bFAIL_NO_RISK_0;
  }

  /* End of Switch: '<S602>/Switch3' */

  /* Switch: '<S602>/Switch2' incorporates:
   *  Constant: '<S602>/Pressure_Ratio_Risk_Y'
   *  Constant: '<S624>/Constant'
   *  RelationalOperator: '<S624>/Compare'
   */
  if (((int32_T)rtb_Product_e) > 16) {
    Chery_E03_Hp_B.bRisk_Pressure_Ratio = bFAIL_RISK_Y_1;
  } else {
    Chery_E03_Hp_B.bRisk_Pressure_Ratio = Chery_E03_Hp_DW.UnitDelay_DSTATE_a;
  }

  /* End of Switch: '<S602>/Switch2' */

  /* Lookup_n-D: '<S602>/Prco_Risk_Calculation' */
  Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP = look1_iu16lu32n16_binlcse(rtb_Product_e,
    ((uint16_T *)&(u16Ncomp_PresRatio_Risk.u16PresRatio_Risk[0])), ((uint16_T *)
    &(u16Ncomp_PresRatio_Risk.u16Ncomp_PresRatio_Risk_y[0])), 7U);

  /* Update for UnitDelay: '<S602>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_a = Chery_E03_Hp_B.bRisk_Pressure_Ratio;
}

/* Output and update for atomic system: '<S594>/T_eva_freezing_risk' */
void Chery_E03_Hp_T_eva_freezing_risk_e(void)
{
  /* Constant: '<S603>/Def_Freezing_no2' */
  Chery_E03_Hp_B.bRisk_Comp = bCONST_0;
}

/* System initialize for atomic system: '<S570>/Risk_corrector_HP' */
void Chery_E03_Hp_Risk_corrector_HP_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S594>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_hk_Init();

  /* End of SystemInitialize for SubSystem: '<S594>/PRCO_riskcorrection' */

  /* SystemInitialize for Atomic SubSystem: '<S594>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_k_Init();

  /* End of SystemInitialize for SubSystem: '<S594>/Pcomp_correction' */

  /* SystemInitialize for Atomic SubSystem: '<S594>/Pressure_Ratio_Risk' */
  Chery_E03_Hp_Pressure_Ratio_Risk_Init();

  /* End of SystemInitialize for SubSystem: '<S594>/Pressure_Ratio_Risk' */

  /* SystemInitialize for Atomic SubSystem: '<S594>/PRCI_Risk' */
  Chery_E03_Hp_PRCI_Risk_m_Init();

  /* End of SystemInitialize for SubSystem: '<S594>/PRCI_Risk' */

  /* SystemInitialize for Atomic SubSystem: '<S594>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_gu_Init();

  /* End of SystemInitialize for SubSystem: '<S594>/EdcToutRisk' */
}

/* System reset for atomic system: '<S570>/Risk_corrector_HP' */
void Chery_E03_Hp_Risk_corrector_HP_Reset(void)
{
  /* SystemReset for Atomic SubSystem: '<S594>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_ii_Reset();

  /* End of SystemReset for SubSystem: '<S594>/PRCO_riskcorrection' */

  /* SystemReset for Atomic SubSystem: '<S594>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_f_Reset();

  /* End of SystemReset for SubSystem: '<S594>/Pcomp_correction' */

  /* SystemReset for Atomic SubSystem: '<S594>/Pressure_Ratio_Risk' */
  Chery_E03_Hp_Pressure_Ratio_Risk_Reset();

  /* End of SystemReset for SubSystem: '<S594>/Pressure_Ratio_Risk' */

  /* SystemReset for Atomic SubSystem: '<S594>/PRCI_Risk' */
  Chery_E03_Hp_PRCI_Risk_a_Reset();

  /* End of SystemReset for SubSystem: '<S594>/PRCI_Risk' */

  /* SystemReset for Atomic SubSystem: '<S594>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_k_Reset();

  /* End of SystemReset for SubSystem: '<S594>/EdcToutRisk' */
}

/*
 * Output and update for atomic system: '<S570>/Risk_corrector_HP'
 * Block description for: '<S570>/Risk_corrector_HP'
 *   risk value for EDC rpm compensation
 */
void Chery_E03_Hp_Risk_corrector_HP(void)
{
  uint16_T u0;

  /* Outputs for Atomic SubSystem: '<S594>/T_eva_freezing_risk' */
  Chery_E03_Hp_T_eva_freezing_risk_e();

  /* End of Outputs for SubSystem: '<S594>/T_eva_freezing_risk' */

  /* Outputs for Atomic SubSystem: '<S594>/PRCO_riskcorrection' */
  Chery_E03_Hp_PRCO_riskcorrection_k();

  /* End of Outputs for SubSystem: '<S594>/PRCO_riskcorrection' */

  /* Outputs for Atomic SubSystem: '<S594>/Pcomp_correction' */
  Chery_E03_Hp_Pcomp_correction_m();

  /* End of Outputs for SubSystem: '<S594>/Pcomp_correction' */

  /* Outputs for Atomic SubSystem: '<S594>/EDC_Rpm_risk'
   *
   * Block description for '<S594>/EDC_Rpm_risk':
   *  This module for edc rpm calulation
   */
  Chery_E03_Hp_EDC_Rpm_risk_p();

  /* End of Outputs for SubSystem: '<S594>/EDC_Rpm_risk' */

  /* Outputs for Atomic SubSystem: '<S594>/Pressure_Ratio_Risk' */
  Chery_E03_Hp_Pressure_Ratio_Risk();

  /* End of Outputs for SubSystem: '<S594>/Pressure_Ratio_Risk' */

  /* Outputs for Atomic SubSystem: '<S594>/PRCI_Risk' */
  Chery_E03_Hp_PRCI_Risk_n();

  /* End of Outputs for SubSystem: '<S594>/PRCI_Risk' */

  /* Outputs for Atomic SubSystem: '<S594>/EdcToutRisk' */
  Chery_E03_Hp_EdcToutRisk_d();

  /* End of Outputs for SubSystem: '<S594>/EdcToutRisk' */

  /* Logic: '<S596>/OR' */
  Chery_E03_Hp_B.bRisk_Comp = (((((((Chery_E03_Hp_B.bEDC_Start_Config_pre_m) ||
    (Chery_E03_Hp_B.bRisk_PowerLimitation)) ||
    (Chery_E03_Hp_B.Def_Pcomprisk_yes_set1)) || (Chery_E03_Hp_B.bRisk_Comp)) ||
    (Chery_E03_Hp_B.bRisk_Pressure_Ratio)) || (Chery_E03_Hp_B.bRisk_PRCI_HP)) ||
    (Chery_E03_Hp_B.bRisk_EdcTout));

  /* MinMax: '<S596>/Max' */
  if (Chery_E03_Hp_ConstB.Comp_Speed_Keep > Chery_E03_Hp_B.u16Ncomp_PrcoRisk_d)
  {
    u0 = Chery_E03_Hp_ConstB.Comp_Speed_Keep;
  } else {
    u0 = Chery_E03_Hp_B.u16Ncomp_PrcoRisk_d;
  }

  if (u0 <= Chery_E03_Hp_B.u16Ncomp_PowRisk_h) {
    u0 = Chery_E03_Hp_B.u16Ncomp_PowRisk_h;
  }

  if (u0 <= Chery_E03_Hp_ConstB.u16Ncomp_RpmRisk) {
    u0 = Chery_E03_Hp_ConstB.u16Ncomp_RpmRisk;
  }

  if (u0 > Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP = u0;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP <= Chery_E03_Hp_B.u16Ncomp_Prci_Risk) {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP = Chery_E03_Hp_B.u16Ncomp_Prci_Risk;
  }

  if (Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP <= Chery_E03_Hp_B.u16Ncomp_Tout_Risk_a)
  {
    Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP = Chery_E03_Hp_B.u16Ncomp_Tout_Risk_a;
  }

  /* End of MinMax: '<S596>/Max' */
}

/*
 * Output and update for atomic system: '<S506>/EDC_Start_Configulation'
 * Block description for: '<S506>/EDC_Start_Configulation'
 *   edc startup condition judge
 */
void Chery_E03_Hp_EDC_Start_Configulation_c(void)
{
  /* Logic: '<S626>/LogicalOperator' incorporates:
   *  Constant: '<S626>/Q_HVAC_Blower_lowlimit'
   *  Constant: '<S626>/V_Air_condensor_lowlimit1'
   *  Constant: '<S626>/V_Air_condensor_lowlimit2'
   *  RelationalOperator: '<S626>/Comparison1'
   *  RelationalOperator: '<S626>/Comparison3'
   *  RelationalOperator: '<S626>/Comparison4'
   */
  Chery_E03_Hp_B.bEDC_Start_Config_pre_m =
    (((Chery_E03_Hp_B.HpI_u8BlwVol_Real_A10 >= u8BLW_VOL_MIN) &&
      (Chery_E03_Hp_B.HpI_u16Power_Max >= u16EDC_POWERMIN)) &&
     (Chery_E03_Hp_B.HpI_u16Ncomp_Max >= u16EDC_RPMMIN));
}

/* System initialize for atomic system: '<S339>/EDC_Control_HP' */
void Chery_E03_Hp_EDC_Control_HP_Init(void)
{
  /* local block i/o variables */
  boolean_T rtb_bMode_Initialize_Flag_No_j;
  boolean_T rtb_bEvafreeze_EDCoff_b;

  /* InitializeConditions for UnitDelay: '<S569>/Unit Delay3' */
  Chery_E03_Hp_DW.UnitDelay3_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S569>/Unit Delay1' */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE = 0;

  /* SystemInitialize for Atomic SubSystem: '<S570>/Risk_corrector_HP'
   *
   * Block description for '<S570>/Risk_corrector_HP':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_HP_Init();

  /* End of SystemInitialize for SubSystem: '<S570>/Risk_corrector_HP' */

  /* SystemInitialize for Chart: '<S573>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_Mode_Initialization_Flag_Decision_Init
    (&rtb_bMode_Initialize_Flag_No_j,
     &Chery_E03_Hp_DW.sf_Mode_Initialization_Flag_Decision_n);

  /* SystemInitialize for Chart: '<S627>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_Eva_Freeze_Status_Check_Init(&rtb_bEvafreeze_EDCoff_b,
    &Chery_E03_Hp_DW.sf_Eva_Freeze_Status_Check_b);
}

/* System reset for atomic system: '<S339>/EDC_Control_HP' */
void Chery_E03_Hp_EDC_Control_HP_Reset(void)
{
  /* local block i/o variables */
  boolean_T rtb_bMode_Initialize_Flag_No_j;
  boolean_T rtb_bEvafreeze_EDCoff_b;

  /* InitializeConditions for UnitDelay: '<S569>/Unit Delay3' */
  Chery_E03_Hp_DW.UnitDelay3_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S569>/Unit Delay1' */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE = 0;

  /* SystemReset for Atomic SubSystem: '<S570>/Risk_corrector_HP'
   *
   * Block description for '<S570>/Risk_corrector_HP':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_HP_Reset();

  /* End of SystemReset for SubSystem: '<S570>/Risk_corrector_HP' */

  /* SystemReset for Chart: '<S573>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_Mode_Initialization_Flag_Decision_Reset
    (&rtb_bMode_Initialize_Flag_No_j,
     &Chery_E03_Hp_DW.sf_Mode_Initialization_Flag_Decision_n);

  /* SystemReset for Chart: '<S627>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_Eva_Freeze_Status_Check_Reset(&rtb_bEvafreeze_EDCoff_b,
    &Chery_E03_Hp_DW.sf_Eva_Freeze_Status_Check_b);
}

/*
 * Output and update for atomic system: '<S339>/EDC_Control_HP'
 * Block description for: '<S339>/EDC_Control_HP'
 *   ACChiller Mode_ EDC Control
 */
void Chery_E03_Hp_EDC_Control_HP(void)
{
  /* local block i/o variables */
  boolean_T rtb_bMode_Initialize_Flag_No_j;
  boolean_T rtb_bEvafreeze_EDCoff_b;
  int32_T rtb_Switch;
  int16_T rtb_Saturation1;
  int32_T rtb_Sum1_g;
  int32_T rtb_Switch2;
  boolean_T rtb_LowerRelop1_jw;

  /* Outputs for Atomic SubSystem: '<S568>/EDC_Estimation_TotalDehum'
   *
   * Block description for '<S568>/EDC_Estimation_TotalDehum':
   *  edc forward rpm estimation
   */
  Chery_E03_Hp_EDC_Estimation_TotalDehum_k();

  /* End of Outputs for SubSystem: '<S568>/EDC_Estimation_TotalDehum' */

  /* Outputs for Atomic SubSystem: '<S568>/Ncomp_Estimation_Chiller'
   *
   * Block description for '<S568>/Ncomp_Estimation_Chiller':
   *  edc for ac_chiller mode compensation for chiller
   */
  Chery_E03_Hp_Ncomp_Estimation_Chiller_b();

  /* End of Outputs for SubSystem: '<S568>/Ncomp_Estimation_Chiller' */

  /* Product: '<S576>/Product3' incorporates:
   *  Constant: '<S576>/AMP_10_1'
   *  Sum: '<S576>/Sum4'
   */
  rtb_Switch = (int32_T)((uint32_T)(((uint32_T)((uint16_T)((int32_T)(((int32_T)
    ((int16_T)(((int16_T)Chery_E03_Hp_B.u16Ncomp_Prci_Risk) + ((int16_T)
    Chery_E03_Hp_B.u16Ncomp_Tout_Risk_a)))) + ((int32_T)((int16_T)
    Chery_E03_Hp_ConstB.u16Ncomp_AC_RearEva_Est)))))) * ((uint32_T)u8AMP_10)));

  /* Saturate: '<S576>/Saturation' */
  if (rtb_Switch > s32NCOMP_FOR_ACCHIL) {
    rtb_Switch = s32NCOMP_FOR_ACCHIL;
  } else {
    if (rtb_Switch < s32NCOMP_STOP_0) {
      rtb_Switch = s32NCOMP_STOP_0;
    }
  }

  /* End of Saturate: '<S576>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S568>/PIparameters'
   *
   * Block description for '<S568>/PIparameters':
   *  AC_EDC_PI parameter
   */
  Chery_E03_Hp_PIparameters_o();

  /* End of Outputs for SubSystem: '<S568>/PIparameters' */

  /* Saturate: '<S576>/Saturation1' */
  if (Chery_E03_Hp_B.s16T_Water_Ctrl_Delta > 250) {
    rtb_Saturation1 = 250;
  } else if (Chery_E03_Hp_B.s16T_Water_Ctrl_Delta < -250) {
    rtb_Saturation1 = -250;
  } else {
    rtb_Saturation1 = Chery_E03_Hp_B.s16T_Water_Ctrl_Delta;
  }

  /* End of Saturate: '<S576>/Saturation1' */

  /* Sum: '<S576>/Sum1' incorporates:
   *  Product: '<S576>/Product1'
   */
  rtb_Switch += ((int32_T)rtb_Saturation1) * ((int32_T)
    Chery_E03_Hp_B.u16Ncomp_Prci_Risk);

  /* Sum: '<S576>/Sum3' incorporates:
   *  Constant: '<S576>/AMP_10_2'
   *  Constant: '<S576>/AMP_10_3'
   *  Constant: '<S579>/Constant'
   *  Product: '<S576>/Product2'
   *  Product: '<S576>/Product4'
   *  Product: '<S576>/Product5'
   *  UnitDelay: '<S569>/Unit Delay3'
   */
  rtb_Sum1_g = ((rtb_Switch + div_nde_s32_floor(((int32_T)rtb_Saturation1) *
    ((int32_T)Chery_E03_Hp_B.u16Ncomp_Tout_Risk_a), (int32_T)u8AMP_100)) +
                Chery_E03_Hp_DW.UnitDelay3_DSTATE) - ((int32_T)((uint32_T)
    (((uint32_T)u16CONST_0) * ((uint32_T)u8AMP_10))));

  /* Outputs for Atomic SubSystem: '<S570>/Risk_corrector_HP'
   *
   * Block description for '<S570>/Risk_corrector_HP':
   *  risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Risk_corrector_HP();

  /* End of Outputs for SubSystem: '<S570>/Risk_corrector_HP' */

  /* Switch: '<S593>/Switch' incorporates:
   *  Constant: '<S593>/Amplificate rate 10 for the Kp_rate'
   *  Constant: '<S595>/Constant'
   *  Product: '<S593>/Product'
   *  RelationalOperator: '<S595>/Compare'
   *  Sum: '<S593>/Sum'
   */
  if (Chery_E03_Hp_B.bRisk_Comp != bFAIL_NO_RISK_0) {
    /* MinMax: '<S593>/Max1' incorporates:
     *  UnitDelay: '<S569>/Unit Delay1'
     */
    if (rtb_Sum1_g >= Chery_E03_Hp_DW.UnitDelay1_DSTATE) {
      rtb_Sum1_g = Chery_E03_Hp_DW.UnitDelay1_DSTATE;
    }

    /* End of MinMax: '<S593>/Max1' */
    rtb_Sum1_g -= (int32_T)((uint32_T)(((uint32_T)
      Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP) * ((uint32_T)u8AMP_10)));
  }

  /* End of Switch: '<S593>/Switch' */

  /* Saturate: '<S593>/AfRisk_Pre_Satuation' */
  if (rtb_Sum1_g > s32NCOMP_UP_LIMIT) {
    rtb_Sum1_g = s32NCOMP_UP_LIMIT;
  } else {
    if (rtb_Sum1_g < s32NCOMP_STOP_0) {
      rtb_Sum1_g = s32NCOMP_STOP_0;
    }
  }

  /* End of Saturate: '<S593>/AfRisk_Pre_Satuation' */

  /* Switch: '<S569>/Switch1' incorporates:
   *  Constant: '<S569>/Constant2'
   *  Constant: '<S589>/Constant'
   *  Constant: '<S590>/Constant'
   *  Logic: '<S569>/AND'
   *  RelationalOperator: '<S589>/Compare'
   *  RelationalOperator: '<S590>/Compare'
   */
  if ((rtb_Sum1_g < s32NCOMP_DOWN_LIMIT) && (rtb_Sum1_g > s32NCOMP_DOWN_0)) {
    rtb_Sum1_g = s32NCOMP_DOWN_LIMIT;
  }

  /* End of Switch: '<S569>/Switch1' */

  /* Chart: '<S573>/Mode_Initialization_Flag_Decision' */
  Chery_E03_Hp_Mode_Initialization_Flag_Decision(&rtb_bMode_Initialize_Flag_No_j,
    &Chery_E03_Hp_DW.sf_Mode_Initialization_Flag_Decision_n);

  /* Switch: '<S569>/Switch2' incorporates:
   *  Constant: '<S569>/Constant4'
   */
  if (!rtb_bMode_Initialize_Flag_No_j) {
    rtb_Sum1_g = s32NCOMP_DOWN_LIMIT;
  }

  /* End of Switch: '<S569>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S506>/EDC_Start_Configulation'
   *
   * Block description for '<S506>/EDC_Start_Configulation':
   *  edc startup condition judge
   */
  Chery_E03_Hp_EDC_Start_Configulation_c();

  /* End of Outputs for SubSystem: '<S506>/EDC_Start_Configulation' */

  /* Switch: '<S569>/Switch3' incorporates:
   *  Constant: '<S569>/Constant5'
   */
  if (!Chery_E03_Hp_B.bEDC_Start_Config_pre_m) {
    rtb_Sum1_g = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S569>/Switch3' */

  /* Gain: '<S569>/Gain1' */
  rtb_Switch2 = (int32_T)((uint32_T)(10U * ((uint32_T)
    Chery_E03_Hp_B.HpI_u16Ncomp_Max)));

  /* MinMax: '<S569>/Min2' incorporates:
   *  Constant: '<S569>/Constant7'
   */
  if (rtb_Switch2 >= s32NCOMP_UP_LIMIT) {
    rtb_Switch2 = s32NCOMP_UP_LIMIT;
  }

  /* End of MinMax: '<S569>/Min2' */

  /* RelationalOperator: '<S592>/LowerRelop1' */
  rtb_LowerRelop1_jw = (rtb_Sum1_g > rtb_Switch2);

  /* Switch: '<S592>/Switch' incorporates:
   *  Constant: '<S569>/Constant8'
   *  RelationalOperator: '<S592>/UpperRelop'
   */
  if (rtb_Sum1_g < s32NCOMP_DOWN_0) {
    rtb_Sum1_g = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S592>/Switch' */

  /* Switch: '<S592>/Switch2' */
  if (!rtb_LowerRelop1_jw) {
    rtb_Switch2 = rtb_Sum1_g;
  }

  /* End of Switch: '<S592>/Switch2' */

  /* Sum: '<S569>/Sum3' */
  rtb_Switch = rtb_Switch2 - rtb_Switch;

  /* RelationalOperator: '<S591>/LowerRelop1' incorporates:
   *  Constant: '<S569>/Constant3'
   */
  rtb_LowerRelop1_jw = (rtb_Switch > s32NCOMP_ICAL_UP);

  /* Switch: '<S591>/Switch' incorporates:
   *  Constant: '<S569>/Constant6'
   *  RelationalOperator: '<S591>/UpperRelop'
   */
  if (rtb_Switch < s32NCOMP_DOWN_0) {
    rtb_Switch = s32NCOMP_DOWN_0;
  }

  /* End of Switch: '<S591>/Switch' */

  /* Switch: '<S591>/Switch2' incorporates:
   *  Constant: '<S569>/Constant3'
   *  UnitDelay: '<S569>/Unit Delay3'
   */
  if (rtb_LowerRelop1_jw) {
    Chery_E03_Hp_DW.UnitDelay3_DSTATE = s32NCOMP_ICAL_UP;
  } else {
    Chery_E03_Hp_DW.UnitDelay3_DSTATE = rtb_Switch;
  }

  /* End of Switch: '<S591>/Switch2' */

  /* Sum: '<S569>/Sum1' incorporates:
   *  Lookup_n-D: '<S569>/EDC_Ramp_Up_Speed'
   *  UnitDelay: '<S569>/Unit Delay1'
   */
  rtb_Sum1_g = Chery_E03_Hp_DW.UnitDelay1_DSTATE + ((int32_T)
    look2_is16u16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
    Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10, ((int16_T *)
    &(u16Ncomp_HP_RampSpd.s16Tamb_Common2_u1[0])), ((uint16_T *)
    &(u16Ncomp_HP_RampSpd.u16PRCI_Ncomp_Rampup_Ctrl_u2[0])), ((uint16_T *)
    &(u16Ncomp_HP_RampSpd.u16Ncomp_HP_RampSpd_y[0])),
    Chery_E03_Hp_ConstP.EDC_Ramp_Up_Speed_maxIndex, 10U));

  /* MinMax: '<S569>/Min' */
  if (rtb_Switch2 < rtb_Sum1_g) {
    Chery_E03_Hp_DW.UnitDelay1_DSTATE = rtb_Switch2;
  } else {
    Chery_E03_Hp_DW.UnitDelay1_DSTATE = rtb_Sum1_g;
  }

  /* End of MinMax: '<S569>/Min' */

  /* Product: '<S569>/Product' incorporates:
   *  Constant: '<S569>/Constant1'
   *  UnitDelay: '<S569>/Unit Delay1'
   */
  Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP = (uint16_T)((int32_T)
    (Chery_E03_Hp_DW.UnitDelay1_DSTATE / ((int32_T)u8AMP_10)));

  /* Chart: '<S627>/Eva_Freeze_Status_Check' */
  Chery_E03_Hp_Eva_Freeze_Status_Check(Chery_E03_Hp_B.HpI_s16Teva_Front_A10,
    &rtb_bEvafreeze_EDCoff_b, &Chery_E03_Hp_DW.sf_Eva_Freeze_Status_Check_b);
}

/*
 * Output and update for atomic system:
 *    '<S633>/IfThenElse'
 *    '<S648>/IfThenElse'
 *    '<S656>/IfThenElse1'
 *    '<S710>/IfThenElse2'
 *    '<S658>/IfThenElse'
 *    '<S736>/IfThenElse'
 *    '<S736>/IfThenElse1'
 *    '<S736>/IfThenElse2'
 *    '<S736>/IfThenElse3'
 */
int32_T Chery_E03_Hp_IfThenElse_cv(boolean_T rtu_bIf, int32_T rtu_Then, int32_T
  rtu_Else)
{
  int32_T rty_Out_0;

  /* Switch: '<S642>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S645>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S645>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S642>/Switch' */
  return rty_Out_0;
}

/* Output and update for atomic system: '<S648>/DataTypeConv_u16_' */
uint16_T Chery_E03_Hp_DataTypeConv_u16__h(int32_T rtu_In1)
{
  uint16_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S650>/Saturation' */
  if (rtu_In1 > 65535) {
    y = 65535;
  } else if (rtu_In1 < 0) {
    y = 0;
  } else {
    y = rtu_In1;
  }

  rty_Out1_0 = (uint16_T)y;

  /* End of Saturate: '<S650>/Saturation' */
  return rty_Out1_0;
}

/* Output and update for atomic system: '<S654>/DataTypeConv_s16_' */
int16_T Chery_E03_Hp_DataTypeConv_s16__d(int16_T rtu_In1)
{
  /* Saturate: '<S663>/Saturation' */
  return rtu_In1;
}

/*
 * System initialize for atomic system:
 *    '<S654>/Hyster'
 *    '<S654>/Hyster1'
 */
void Chery_E03_Hp_Hyster_e_Init(DW_Hyster_Chery_E03_Hp_j_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_h;

  /* InitializeConditions for UnitDelay: '<S666>/Unit Delay' */
  localDW->UnitDelay_DSTATE = false;

  /* SystemInitialize for Atomic SubSystem: '<S666>/Subsystem' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_h, &localDW->Subsystem);

  /* End of SystemInitialize for SubSystem: '<S666>/Subsystem' */
}

/*
 * System reset for atomic system:
 *    '<S654>/Hyster'
 *    '<S654>/Hyster1'
 */
void Chery_E03_Hp_Hyster_b_Reset(DW_Hyster_Chery_E03_Hp_j_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_h;

  /* InitializeConditions for UnitDelay: '<S666>/Unit Delay' */
  localDW->UnitDelay_DSTATE = false;

  /* SystemReset for Atomic SubSystem: '<S666>/Subsystem' */
  Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun_h, &localDW->Subsystem);

  /* End of SystemReset for SubSystem: '<S666>/Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S654>/Hyster'
 *    '<S654>/Hyster1'
 */
boolean_T Chery_E03_Hp_Hyster_p(int32_T rtu_DataIn, boolean_T rtu_OutputWhenUp,
  boolean_T rtu_OutputWhenDown, const ConstB_Hyster_Chery_E03_Hp_i_T *localC,
  DW_Hyster_Chery_E03_Hp_j_T *localDW, boolean_T rtp_bParaInitUseUp)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_h;
  boolean_T rty_HyDataOut_0;

  /* Switch: '<S666>/Switch3' incorporates:
   *  Constant: '<S666>/Constant'
   */
  if (rtp_bParaInitUseUp) {
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  } else {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S666>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S666>/Subsystem' */
  rtb_bFirstRun_h = ( Chery_E03_Hp_FirstRun(&localDW->Subsystem, 1) != false);

  /* End of Outputs for SubSystem: '<S666>/Subsystem' */

  /* Switch: '<S666>/Switch1' incorporates:
   *  UnitDelay: '<S666>/Unit Delay'
   */
  if (!rtb_bFirstRun_h) {
    rty_HyDataOut_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S666>/Switch1' */

  /* Switch: '<S666>/Switch4' incorporates:
   *  RelationalOperator: '<S666>/RelationalOperator1'
   */
  if (rtu_DataIn <= localC->Conversion) {
    rty_HyDataOut_0 = rtu_OutputWhenDown;
  }

  /* End of Switch: '<S666>/Switch4' */

  /* Switch: '<S666>/Switch2' incorporates:
   *  RelationalOperator: '<S666>/RelationalOperator3'
   */
  if (rtu_DataIn >= localC->Conversion_n) {
    /* DataTypeConversion: '<S677>/Conversion' */
    rty_HyDataOut_0 = rtu_OutputWhenUp;
  }

  /* End of Switch: '<S666>/Switch2' */

  /* Update for UnitDelay: '<S666>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_HyDataOut_0;
  return rty_HyDataOut_0;
}

/*
 * System initialize for atomic system:
 *    '<S654>/Hyster_Judge1'
 *    '<S655>/Hyster_Judge'
 *    '<S817>/Hyster_Judge'
 *    '<S1254>/Hyster_Judge1'
 *    '<S1384>/Hyster_Judge'
 *    '<S1384>/Hyster_Judge1'
 *    '<S1385>/Hyster_Judge'
 *    '<S1337>/Hyster_Judge'
 *    '<S1337>/Hyster_Judge1'
 *    '<S1337>/Hyster_Judge2'
 *    ...
 */
void Chery_E03_Hp_Hyster_Judge1_Init(DW_Hyster_Judge_Chery_E03_Hp_b_T *localDW,
  boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S668>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;
}

/*
 * System reset for atomic system:
 *    '<S654>/Hyster_Judge1'
 *    '<S655>/Hyster_Judge'
 *    '<S817>/Hyster_Judge'
 *    '<S1254>/Hyster_Judge1'
 *    '<S1384>/Hyster_Judge'
 *    '<S1384>/Hyster_Judge1'
 *    '<S1385>/Hyster_Judge'
 *    '<S1337>/Hyster_Judge'
 *    '<S1337>/Hyster_Judge1'
 *    '<S1337>/Hyster_Judge2'
 *    ...
 */
void Chery_E03_Hp_Hyster_Judge1_Reset(DW_Hyster_Judge_Chery_E03_Hp_b_T *localDW,
  boolean_T rtp_bParaInit)
{
  /* InitializeConditions for UnitDelay: '<S668>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtp_bParaInit;
}

/*
 * Output and update for atomic system:
 *    '<S654>/Hyster_Judge1'
 *    '<S655>/Hyster_Judge'
 *    '<S817>/Hyster_Judge'
 *    '<S1254>/Hyster_Judge1'
 *    '<S1384>/Hyster_Judge'
 *    '<S1384>/Hyster_Judge1'
 *    '<S1385>/Hyster_Judge'
 *    '<S1337>/Hyster_Judge'
 *    '<S1337>/Hyster_Judge1'
 *    '<S1337>/Hyster_Judge2'
 *    ...
 */
boolean_T Chery_E03_Hp_Hyster_Judge1(int16_T rtu_ParaJudgeUp, int16_T
  rtu_HyJudgeIn, int16_T rtu_ParaJudgeDown, DW_Hyster_Judge_Chery_E03_Hp_b_T
  *localDW, boolean_T rtp_bOutputValueWhenJudgeUp)
{
  boolean_T rty_bHyJudge_0;

  /* Switch: '<S668>/Switch4' incorporates:
   *  Constant: '<S668>/JudgeYes'
   *  Logic: '<S668>/NOT'
   *  RelationalOperator: '<S668>/RelationalOperator1'
   */
  if (rtu_HyJudgeIn <= rtu_ParaJudgeDown) {
    localDW->UnitDelay_DSTATE = !rtp_bOutputValueWhenJudgeUp;
  }

  /* End of Switch: '<S668>/Switch4' */

  /* Switch: '<S668>/Switch2' incorporates:
   *  Constant: '<S668>/JudgeYes'
   *  RelationalOperator: '<S668>/RelationalOperator3'
   */
  if (rtu_HyJudgeIn >= rtu_ParaJudgeUp) {
    rty_bHyJudge_0 = rtp_bOutputValueWhenJudgeUp;
  } else {
    rty_bHyJudge_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S668>/Switch2' */

  /* Update for UnitDelay: '<S668>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rty_bHyJudge_0;
  return rty_bHyJudge_0;
}

/*
 * Output and update for atomic system:
 *    '<S700>/DataTypeConv_s32_'
 *    '<S709>/DataTypeConv_s32_'
 *    '<S721>/DataTypeConv_s32_'
 */
int32_T Chery_E03_Hp_DataTypeConv_s32_(int32_T rtu_In1)
{
  /* Saturate: '<S705>/Saturation' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S700>/DataTypeConv_s32_1'
 *    '<S709>/DataTypeConv_s32_1'
 *    '<S721>/DataTypeConv_s32_1'
 */
int32_T Chery_E03_Hp_DataTypeConv_s32_1(int64m_T rtu_In1)
{
  int32_T rty_Out1_0;
  int64m_T tmp;
  static int64m_T tmp_0 = { { 2147483647U, 0U }/* chunks */
  };

  static int64m_T tmp_1 = { { 2147483648U, MAX_uint32_T }/* chunks */
  };

  /* Saturate: '<S706>/Saturation' */
  tmp = tmp_0;
  if (sMultiWordGe(&rtu_In1.chunks[0U], &tmp.chunks[0U], 2)) {
    rty_Out1_0 = MAX_int32_T;
  } else {
    tmp = tmp_1;
    if (sMultiWordLe(&rtu_In1.chunks[0U], &tmp.chunks[0U], 2)) {
      rty_Out1_0 = MIN_int32_T;
    } else {
      tmp = rtu_In1;
      rty_Out1_0 = MultiWord2sLong(&tmp.chunks[0U]);
    }
  }

  /* End of Saturate: '<S706>/Saturation' */
  return rty_Out1_0;
}

/* System initialize for atomic system: '<S656>/PIModule' */
void Chery_E03_Hp_PIModule_Init(DW_PIModule_Chery_E03_Hp_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S700>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S700>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;
}

/* System reset for atomic system: '<S656>/PIModule' */
void Chery_E03_Hp_PIModule_Reset(DW_PIModule_Chery_E03_Hp_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S700>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S700>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;
}

/* Output and update for atomic system: '<S656>/PIModule' */
void Chery_E03_Hp_PIModule(real_T rtu_KP_a100, real_T rtu_KI_a1000, int16_T
  rtu_Ctrl_Delta_a10, boolean_T rtu_bClearIcal, boolean_T
  rtu_bOutput_With_ActValLast, int32_T rtu_s32ActuatorValLast_a10000, int32_T
  *rty_DebugBus_Outport_1, int32_T *rty_DebugBus_Outport_1_n, int32_T
  *rty_DebugBus_Outport_1_ni, int32_T *rty_DebugBus_Outport_1_g, int32_T
  *rty_DebugBus_Outport_1_nj, int32_T *rty_DebugBus_Outport_1_k, int32_T
  *rty_DebugBus_Outport_1_b, int32_T *rty_s32ActuatorValue_a10000, const
  ConstB_PIModule_Chery_E03_Hp_T *localC, DW_PIModule_Chery_E03_Hp_T *localDW)
{
  int32_T rtb_Switch2_od;
  real_T rtb_IcalPart_a10000;
  real_T rtb_Ical_a10000;
  real_T rtb_Pcal_a1000;
  real_T rtb_Switch_fg;
  int64m_T tmp;
  int64m_T tmp_0;
  real_T u;
  real_T v;

  /* Outputs for Atomic SubSystem: '<S700>/DataTypeConv_s32_' */
  rtb_Switch2_od = Chery_E03_Hp_DataTypeConv_s32_(rtu_s32ActuatorValLast_a10000);

  /* End of Outputs for SubSystem: '<S700>/DataTypeConv_s32_' */

  /* Switch: '<S700>/Switch1' incorporates:
   *  Constant: '<S700>/Constant7'
   *  Sum: '<S700>/Add4'
   *  UnitDelay: '<S700>/Unit Delay'
   */
  if (rtu_bClearIcal) {
    rtb_IcalPart_a10000 = 0.0;
  } else {
    rtb_IcalPart_a10000 = ((real_T)rtb_Switch2_od) - localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S700>/Switch1' */

  /* Product: '<S700>/Divide1' */
  rtb_Ical_a10000 = rtu_KI_a1000 * ((real_T)rtu_Ctrl_Delta_a10);

  /* Sum: '<S700>/Add6' */
  rtb_IcalPart_a10000 += rtb_Ical_a10000;

  /* Product: '<S700>/Divide' */
  rtb_Pcal_a1000 = rtu_KP_a100 * ((real_T)rtu_Ctrl_Delta_a10);

  /* Sum: '<S700>/Add3' incorporates:
   *  Product: '<S700>/Divide6'
   *  UnitDelay: '<S700>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = ((real_T)localC->Forward_a10000) + (rtb_Pcal_a1000
    * 10.0);

  /* Switch: '<S700>/Switch' incorporates:
   *  Sum: '<S700>/Add5'
   *  UnitDelay: '<S700>/Unit Delay'
   */
  if (rtu_bOutput_With_ActValLast) {
    rtb_Switch_fg = (real_T)rtb_Switch2_od;
  } else {
    rtb_Switch_fg = rtb_IcalPart_a10000 + localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S700>/Switch' */

  /* Product: '<S700>/Divide11' incorporates:
   *  Sum: '<S700>/Add'
   */
  u = (rtb_Switch_fg - ((real_T)rtb_Switch2_od)) / 10000.0;
  v = fabs(u);
  if (v < 4.503599627370496E+15) {
    if (v >= 0.5) {
      u = floor(u + 0.5);
    } else {
      u = 0.0;
    }
  }

  *rty_DebugBus_Outport_1_b = (int32_T)u;

  /* End of Product: '<S700>/Divide11' */

  /* Saturate: '<S700>/Saturation' */
  if (rtb_Switch_fg > 2.147483647E+9) {
    rtb_Switch_fg = 2.147483647E+9;
  } else {
    if (rtb_Switch_fg < -2.147483648E+9) {
      rtb_Switch_fg = -2.147483648E+9;
    }
  }

  v = fabs(rtb_Switch_fg);
  if (v < 4.503599627370496E+15) {
    if (v >= 0.5) {
      rtb_Switch_fg = floor(rtb_Switch_fg + 0.5);
    } else {
      rtb_Switch_fg = 0.0;
    }
  }

  *rty_s32ActuatorValue_a10000 = (int32_T)rtb_Switch_fg;

  /* End of Saturate: '<S700>/Saturation' */

  /* Product: '<S700>/Divide5' */
  *rty_DebugBus_Outport_1_ni = div_nzp_s32_near(*rty_s32ActuatorValue_a10000,
    10000);

  /* Product: '<S700>/Divide2' */
  u = rtb_Pcal_a1000 / 1000.0;
  v = fabs(u);
  if (v < 4.503599627370496E+15) {
    if (v >= 0.5) {
      u = floor(u + 0.5);
    } else {
      u = 0.0;
    }
  }

  *rty_DebugBus_Outport_1 = (int32_T)u;

  /* End of Product: '<S700>/Divide2' */

  /* UnitDelay: '<S700>/Unit Delay1' */
  rtb_Switch2_od = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S700>/Switch2' incorporates:
   *  Constant: '<S700>/Constant8'
   */
  if (rtu_bClearIcal) {
    rtb_Switch2_od = 0;
  }

  /* End of Switch: '<S700>/Switch2' */

  /* Sum: '<S700>/Add1' */
  Double2MultiWord(floor(rtb_Ical_a10000 + ((real_T)rtb_Switch2_od)),
                   &tmp.chunks[0U], 2);
  MultiWordSignedWrap(&tmp.chunks[0U], 2, 16U, &tmp_0.chunks[0U]);

  /* Outputs for Atomic SubSystem: '<S700>/DataTypeConv_s32_1' */
  /* UnitDelay: '<S700>/Unit Delay1' incorporates:
   *  Sum: '<S700>/Add1'
   */
  localDW->UnitDelay1_DSTATE = Chery_E03_Hp_DataTypeConv_s32_1(tmp_0);

  /* End of Outputs for SubSystem: '<S700>/DataTypeConv_s32_1' */

  /* Product: '<S700>/Divide10' incorporates:
   *  Sum: '<S700>/Add2'
   *  UnitDelay: '<S700>/Unit Delay1'
   */
  u = (rtb_IcalPart_a10000 - ((real_T)localDW->UnitDelay1_DSTATE)) / 10000.0;
  v = fabs(u);
  if (v < 4.503599627370496E+15) {
    if (v >= 0.5) {
      u = floor(u + 0.5);
    } else {
      u = 0.0;
    }
  }

  *rty_DebugBus_Outport_1_k = (int32_T)u;

  /* End of Product: '<S700>/Divide10' */

  /* Product: '<S700>/Divide8' incorporates:
   *  UnitDelay: '<S700>/Unit Delay1'
   */
  *rty_DebugBus_Outport_1_nj = div_nzp_s32_near(localDW->UnitDelay1_DSTATE,
    10000);

  /* Product: '<S700>/Divide7' */
  u = rtb_IcalPart_a10000 / 10000.0;
  v = fabs(u);
  if (v < 4.503599627370496E+15) {
    if (v >= 0.5) {
      u = floor(u + 0.5);
    } else {
      u = 0.0;
    }
  }

  *rty_DebugBus_Outport_1_n = (int32_T)u;

  /* End of Product: '<S700>/Divide7' */

  /* Product: '<S700>/Divide9' */
  u = rtb_Ical_a10000 / 10000.0;
  v = fabs(u);
  if (v < 4.503599627370496E+15) {
    if (v >= 0.5) {
      u = floor(u + 0.5);
    } else {
      u = 0.0;
    }
  }

  *rty_DebugBus_Outport_1_g = (int32_T)u;

  /* End of Product: '<S700>/Divide9' */
}

/*
 * System initialize for atomic system:
 *    '<S657>/PIModule'
 *    '<S658>/PIModule'
 */
void Chery_E03_Hp_PIModule_j_Init(DW_PIModule_Chery_E03_Hp_i_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S709>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Chery_E03_Hp_ConstP.pooled7;

  /* InitializeConditions for UnitDelay: '<S709>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;
}

/*
 * System reset for atomic system:
 *    '<S657>/PIModule'
 *    '<S658>/PIModule'
 */
void Chery_E03_Hp_PIModule_c_Reset(DW_PIModule_Chery_E03_Hp_i_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S709>/Unit Delay' */
  localDW->UnitDelay_DSTATE = Chery_E03_Hp_ConstP.pooled7;

  /* InitializeConditions for UnitDelay: '<S709>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0;
}

/*
 * Output and update for atomic system:
 *    '<S657>/PIModule'
 *    '<S658>/PIModule'
 */
void Chery_E03_Hp_PIModule_p(uint8_T rtu_KP_a100, uint8_T rtu_KI_a1000, int16_T
  rtu_Ctrl_Delta_a10, boolean_T rtu_bClearIcal, boolean_T
  rtu_bOutput_With_ActValLast, int32_T rtu_s32ActuatorValLast_a10000, int32_T
  *rty_DebugBus_Outport_1, int32_T *rty_DebugBus_Outport_1_b, int32_T
  *rty_DebugBus_Outport_1_k, int32_T *rty_DebugBus_Outport_1_m, int32_T
  *rty_DebugBus_Outport_1_kq, int32_T *rty_DebugBus_Outport_1_i, int32_T
  *rty_DebugBus_Outport_1_o, int32_T *rty_s32ActuatorValue_a10000, const
  ConstB_PIModule_Chery_E03_Hp_o_T *localC, DW_PIModule_Chery_E03_Hp_i_T
  *localDW)
{
  int32_T rtb_Saturation_f;
  int32_T rtb_Ical_a10000;
  int32_T rtb_Switch2_ht;
  int64m_T rtb_Switch_cb;
  int64m_T rtb_IcalPart_a10000;
  int64m_T tmp;
  int64m_T tmp_0;
  uint32_T tmp_1;
  uint32_T tmp_2;
  int96m_T tmp_3;
  int64m_T tmp_4;
  int64m_T tmp_5;
  int64m_T tmp_6;
  int64m_T tmp_7;
  int96m_T tmp_8;
  int64m_T tmp_9;
  int64m_T tmp_a;
  int96m_T tmp_b;
  static int64m_T tmp_c = { { 2147483647U, 0U }/* chunks */
  };

  static int64m_T tmp_d = { { 2147483648U, MAX_uint32_T }/* chunks */
  };

  static int64m_T tmp_e = { { 0U, 0U } /* chunks */
  };

  /* Outputs for Atomic SubSystem: '<S709>/DataTypeConv_s32_' */
  rtb_Saturation_f = Chery_E03_Hp_DataTypeConv_s32_
    (rtu_s32ActuatorValLast_a10000);

  /* End of Outputs for SubSystem: '<S709>/DataTypeConv_s32_' */

  /* Switch: '<S709>/Switch1' incorporates:
   *  Constant: '<S709>/Constant7'
   */
  if (rtu_bClearIcal) {
    rtb_Switch_cb = tmp_e;
  } else {
    /* Sum: '<S709>/Add4' incorporates:
     *  UnitDelay: '<S709>/Unit Delay'
     */
    sLong2MultiWord(rtb_Saturation_f, &tmp.chunks[0U], 2);
    tmp_0 = localDW->UnitDelay_DSTATE;
    MultiWordSub(&tmp.chunks[0U], &tmp_0.chunks[0U], &rtb_Switch_cb.chunks[0U],
                 2);
  }

  /* End of Switch: '<S709>/Switch1' */

  /* Product: '<S709>/Divide1' */
  rtb_Ical_a10000 = ((int32_T)rtu_KI_a1000) * ((int32_T)rtu_Ctrl_Delta_a10);

  /* Sum: '<S709>/Add6' */
  sLong2MultiWord(rtb_Ical_a10000, &tmp.chunks[0U], 2);
  MultiWordAdd(&tmp.chunks[0U], &rtb_Switch_cb.chunks[0U],
               &rtb_IcalPart_a10000.chunks[0U], 2);

  /* Product: '<S709>/Divide' */
  rtb_Switch2_ht = ((int32_T)rtu_KP_a100) * ((int32_T)rtu_Ctrl_Delta_a10);

  /* Sum: '<S709>/Add3' */
  uLong2MultiWord(localC->Forward_a10000, &tmp.chunks[0U], 2);

  /* Product: '<S709>/Divide6' */
  tmp_1 = (uint32_T)rtb_Switch2_ht;
  tmp_2 = 10U;
  ssuMultiWordMul(&tmp_1, 1, &tmp_2, 1, &tmp_0.chunks[0U], 2);

  /* Sum: '<S709>/Add3' incorporates:
   *  UnitDelay: '<S709>/Unit Delay'
   */
  MultiWordAdd(&tmp.chunks[0U], &tmp_0.chunks[0U],
               &localDW->UnitDelay_DSTATE.chunks[0U], 2);

  /* Switch: '<S709>/Switch' */
  if (rtu_bOutput_With_ActValLast) {
    sLong2MultiWord(rtb_Saturation_f, &rtb_Switch_cb.chunks[0U], 2);
  } else {
    /* Sum: '<S709>/Add5' incorporates:
     *  UnitDelay: '<S709>/Unit Delay'
     */
    tmp = localDW->UnitDelay_DSTATE;
    MultiWordAdd(&rtb_IcalPart_a10000.chunks[0U], &tmp.chunks[0U],
                 &rtb_Switch_cb.chunks[0U], 2);
  }

  /* End of Switch: '<S709>/Switch' */

  /* Sum: '<S709>/Add' */
  sLong2MultiWord(rtb_Saturation_f, &tmp_0.chunks[0U], 2);
  MultiWordSub(&rtb_Switch_cb.chunks[0U], &tmp_0.chunks[0U], &tmp.chunks[0U], 2);

  /* Product: '<S709>/Divide11' */
  uLong2MultiWord(10000U, &tmp_0.chunks[0U], 2);
  sMultiWordDivNear(&tmp.chunks[0U], 2, &tmp_0.chunks[0U], 2, &tmp_3.chunks[0U],
                    3, &tmp_4.chunks[0U], 2, &tmp_5.chunks[0U], 2,
                    &tmp_6.chunks[0U], 2);
  *rty_DebugBus_Outport_1_o = MultiWord2sLong(&tmp_3.chunks[0U]);

  /* Saturate: '<S709>/Saturation' */
  tmp = tmp_c;
  if (sMultiWordGe(&rtb_Switch_cb.chunks[0U], &tmp.chunks[0U], 2)) {
    *rty_s32ActuatorValue_a10000 = MAX_int32_T;
  } else {
    tmp_0 = tmp_d;
    if (sMultiWordLe(&rtb_Switch_cb.chunks[0U], &tmp_0.chunks[0U], 2)) {
      *rty_s32ActuatorValue_a10000 = MIN_int32_T;
    } else {
      *rty_s32ActuatorValue_a10000 = MultiWord2sLong(&rtb_Switch_cb.chunks[0U]);
    }
  }

  /* End of Saturate: '<S709>/Saturation' */

  /* Product: '<S709>/Divide5' */
  *rty_DebugBus_Outport_1_k = div_nzp_s32_near(*rty_s32ActuatorValue_a10000,
    10000);

  /* Product: '<S709>/Divide2' */
  *rty_DebugBus_Outport_1 = div_nzp_s32_near(rtb_Switch2_ht, 1000);

  /* UnitDelay: '<S709>/Unit Delay1' */
  rtb_Switch2_ht = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S709>/Switch2' incorporates:
   *  Constant: '<S709>/Constant8'
   */
  if (rtu_bClearIcal) {
    rtb_Switch2_ht = 0;
  }

  /* End of Switch: '<S709>/Switch2' */

  /* Sum: '<S709>/Add1' */
  sLong2MultiWord(rtb_Ical_a10000, &tmp_6.chunks[0U], 2);
  MultiWordSignedWrap(&tmp_6.chunks[0U], 2, 16U, &tmp_5.chunks[0U]);
  sLong2MultiWord(rtb_Switch2_ht, &tmp_7.chunks[0U], 2);
  MultiWordSignedWrap(&tmp_7.chunks[0U], 2, 16U, &tmp_6.chunks[0U]);
  MultiWordAdd(&tmp_5.chunks[0U], &tmp_6.chunks[0U], &tmp_4.chunks[0U], 2);
  MultiWordSignedWrap(&tmp_4.chunks[0U], 2, 16U, &tmp_5.chunks[0U]);

  /* Outputs for Atomic SubSystem: '<S709>/DataTypeConv_s32_1' */
  /* UnitDelay: '<S709>/Unit Delay1' incorporates:
   *  Product: '<S709>/Divide11'
   *  Sum: '<S709>/Add1'
   */
  localDW->UnitDelay1_DSTATE = Chery_E03_Hp_DataTypeConv_s32_1(tmp_5);

  /* End of Outputs for SubSystem: '<S709>/DataTypeConv_s32_1' */

  /* Sum: '<S709>/Add2' incorporates:
   *  UnitDelay: '<S709>/Unit Delay1'
   */
  sLong2MultiWord(localDW->UnitDelay1_DSTATE, &tmp_6.chunks[0U], 2);
  MultiWordSub(&rtb_IcalPart_a10000.chunks[0U], &tmp_6.chunks[0U],
               &tmp_4.chunks[0U], 2);

  /* Product: '<S709>/Divide10' */
  uLong2MultiWord(10000U, &tmp_6.chunks[0U], 2);
  sMultiWordDivNear(&tmp_4.chunks[0U], 2, &tmp_6.chunks[0U], 2, &tmp_8.chunks[0U],
                    3, &tmp_7.chunks[0U], 2, &tmp_9.chunks[0U], 2,
                    &tmp_a.chunks[0U], 2);
  *rty_DebugBus_Outport_1_i = MultiWord2sLong(&tmp_8.chunks[0U]);

  /* Product: '<S709>/Divide8' incorporates:
   *  UnitDelay: '<S709>/Unit Delay1'
   */
  *rty_DebugBus_Outport_1_kq = div_nzp_s32_near(localDW->UnitDelay1_DSTATE,
    10000);

  /* Product: '<S709>/Divide7' */
  uLong2MultiWord(10000U, &tmp_4.chunks[0U], 2);
  sMultiWordDivNear(&rtb_IcalPart_a10000.chunks[0U], 2, &tmp_4.chunks[0U], 2,
                    &tmp_b.chunks[0U], 3, &tmp_6.chunks[0U], 2, &tmp_7.chunks[0U],
                    2, &tmp_9.chunks[0U], 2);
  *rty_DebugBus_Outport_1_b = MultiWord2sLong(&tmp_b.chunks[0U]);

  /* Product: '<S709>/Divide9' */
  *rty_DebugBus_Outport_1_m = div_nzp_s32_near(rtb_Ical_a10000, 10000);
}

/* Output and update for atomic system: '<S659>/DataTypeConv_u8_' */
uint8_T Chery_E03_Hp_DataTypeConv_u8__p(int32_T rtu_In1)
{
  uint8_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S727>/Saturation' */
  if (rtu_In1 > 255) {
    y = 255;
  } else if (rtu_In1 < 0) {
    y = 0;
  } else {
    y = rtu_In1;
  }

  rty_Out1_0 = (uint8_T)y;

  /* End of Saturate: '<S727>/Saturation' */
  return rty_Out1_0;
}

/* Output and update for atomic system: '<S659>/Divide' */
int32_T Chery_E03_Hp_Divide_Safe(int32_T rtu_x, uint16_T rtu_y, const
  ConstB_Divide_Safe_Chery_E03_Hp_T *localC)
{
  int32_T rty_out_0;
  uint16_T rtb_Conversion_jh;

  /* Outputs for Atomic SubSystem: '<S728>/IfThenElse' */

  /* RelationalOperator: '<S729>/Compare' incorporates:
   *  Constant: '<S729>/Constant'
   */
  rtb_Conversion_jh = (uint16_T) Chery_E03_Hp_IfThenElse2(((int32_T)rtu_y) != 0,
    rtu_y, localC->Conversion);

  /* End of Outputs for SubSystem: '<S728>/IfThenElse' */

  /* Product: '<S728>/Divide' */
  rty_out_0 = div_nzp_s32_near(rtu_x, (int32_T)rtb_Conversion_jh);
  return rty_out_0;
}

/* System initialize for atomic system: '<S660>/Delay_Any' */
void Chery_E03_Hp_Delay_Any_Init(DW_Delay_Any_Chery_E03_Hp_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_hj;

  /* InitializeConditions for UnitDelay: '<S735>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S735>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0U;

  /* SystemInitialize for Atomic SubSystem: '<S735>/FirstRun' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_hj, &localDW->FirstRun);

  /* End of SystemInitialize for SubSystem: '<S735>/FirstRun' */

  /* SystemInitialize for Chart: '<S746>/JudgeTime' */
  localDW->u16Count_Delay = 0U;
}

/* System reset for atomic system: '<S660>/Delay_Any' */
void Chery_E03_Hp_Delay_Any_Reset(DW_Delay_Any_Chery_E03_Hp_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_hj;

  /* InitializeConditions for UnitDelay: '<S735>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0U;

  /* InitializeConditions for UnitDelay: '<S735>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = 0U;

  /* SystemReset for Atomic SubSystem: '<S735>/FirstRun' */
  Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun_hj, &localDW->FirstRun);

  /* End of SystemReset for SubSystem: '<S735>/FirstRun' */

  /* SystemReset for Chart: '<S746>/JudgeTime' */
  localDW->u16Count_Delay = 0U;
}

/* Output and update for atomic system: '<S660>/Delay_Any' */
uint8_T Chery_E03_Hp_Delay_Any(uint8_T rtu_input, const
  ConstB_Delay_Any_Chery_E03_Hp_T *localC, DW_Delay_Any_Chery_E03_Hp_T *localDW)
{
  /* local block i/o variables */
  boolean_T rtb_bFirstRun_hj;
  uint8_T rty_DelayOut_0;
  boolean_T rtb_bDelayJudge_k;
  int32_T tmp;

  /* Outputs for Atomic SubSystem: '<S735>/FirstRun' */
  rtb_bFirstRun_hj = ( Chery_E03_Hp_FirstRun(&localDW->FirstRun, 1) != false);

  /* End of Outputs for SubSystem: '<S735>/FirstRun' */

  /* Chart: '<S746>/JudgeTime' incorporates:
   *  RelationalOperator: '<S735>/Relational Operator'
   *  UnitDelay: '<S735>/Unit Delay'
   */
  if (localDW->u16Count_Delay >= localC->DataTypeConv_u16_.Saturation) {
    rtb_bDelayJudge_k = true;
  } else {
    rtb_bDelayJudge_k = false;
    tmp = ((int32_T)localDW->u16Count_Delay) + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    localDW->u16Count_Delay = (uint16_T)tmp;
  }

  if (localDW->UnitDelay_DSTATE != rtu_input) {
    localDW->u16Count_Delay = 1U;
  }

  /* End of Chart: '<S746>/JudgeTime' */

  /* Switch: '<S735>/Switch1' incorporates:
   *  UnitDelay: '<S735>/Unit Delay1'
   */
  if (!rtb_bDelayJudge_k) {
    localDW->UnitDelay_DSTATE = localDW->UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S735>/Switch1' */

  /* Switch: '<S735>/Switch' incorporates:
   *  Logic: '<S735>/OR'
   */
  if (rtb_bFirstRun_hj || (localC->Compare)) {
    /* DataTypeConversion: '<S743>/Conversion' */
    rty_DelayOut_0 = rtu_input;
  } else {
    /* DataTypeConversion: '<S743>/Conversion' */
    rty_DelayOut_0 = localDW->UnitDelay_DSTATE;
  }

  /* End of Switch: '<S735>/Switch' */

  /* Update for UnitDelay: '<S735>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtu_input;

  /* Update for UnitDelay: '<S735>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = rty_DelayOut_0;
  return rty_DelayOut_0;
}

/* Output and update for atomic system: '<S660>/IfThenElse' */
uint8_T Chery_E03_Hp_IfThenElse_b(boolean_T rtu_bIf, uint8_T rtu_Then, int32_T
  rtu_Else)
{
  uint8_T rty_Out_0;
  int32_T rtb_Switch_l;

  /* Switch: '<S738>/Switch' */
  if (rtu_bIf) {
    rtb_Switch_l = (int32_T)rtu_Then;
  } else {
    rtb_Switch_l = rtu_Else;
  }

  /* End of Switch: '<S738>/Switch' */

  /* DataTypeConversion: '<S759>/Conversion' */
  if (rtb_Switch_l < 0) {
    rtb_Switch_l = 0;
  } else {
    if (rtb_Switch_l > 255) {
      rtb_Switch_l = 255;
    }
  }

  rty_Out_0 = (uint8_T)rtb_Switch_l;

  /* End of DataTypeConversion: '<S759>/Conversion' */
  return rty_Out_0;
}

/* System initialize for atomic system: '<S1>/System_Control' */
void Chery_E03_Hp_System_Control_Init(void)
{
  /* local block i/o variables */
  int32_T rtb_s32NcompChil_Ctrl_Rpm;
  int32_T rtb_s32NcompChil_Ctrl_Rpm_a;
  boolean_T rtb_bFirstRun;
  boolean_T rtb_bFirstRun_d;
  boolean_T rtb_bFirstRun_dy;
  boolean_T rtb_bFirstRun_e;

  /* SystemInitialize for IfAction SubSystem: '<S40>/Stop Mode Ctrl'
   *
   * Block description for '<S40>/Stop Mode Ctrl':
   *  chiller mode control
   */
  /* SystemInitialize for Atomic SubSystem: '<S341>/EDC_Ctrl_Stop_Mode'
   *
   * Block description for '<S341>/EDC_Ctrl_Stop_Mode':
   *  chiller mode edc rpm control
   */
  /* InitializeConditions for UnitDelay: '<S864>/Unit Delay1' */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_d = 0;

  /* InitializeConditions for UnitDelay: '<S864>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_pv = 0U;

  /* InitializeConditions for Product: '<S864>/Product1' incorporates:
   *  UnitDelay: '<S864>/Unit Delay2'
   */
  Chery_E03_Hp_DW.UnitDelay2_DSTATE_o = 0;

  /* SystemInitialize for Atomic SubSystem: '<S832>/Chiller_EDC_Start_Configulation'
   *
   * Block description for '<S832>/Chiller_EDC_Start_Configulation':
   *  edc startup condition judge
   */
  Chery_E03_Hp_Chiller_EDC_Start_Configulation_Init();

  /* End of SystemInitialize for SubSystem: '<S832>/Chiller_EDC_Start_Configulation' */

  /* SystemInitialize for Atomic SubSystem: '<S862>/Chiller_Risk_corrector'
   *
   * Block description for '<S862>/Chiller_Risk_corrector':
   *  chiller mode risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Chiller_Risk_corrector_Init();

  /* End of SystemInitialize for SubSystem: '<S862>/Chiller_Risk_corrector' */

  /* SystemInitialize for Chart: '<S860>/Chiller_edc_management' */
  Chery_E03_Hp_Chiller_edc_management_Init(&rtb_s32NcompChil_Ctrl_Rpm_a,
    &Chery_E03_Hp_DW.sf_Chiller_edc_management);

  /* End of SystemInitialize for SubSystem: '<S341>/EDC_Ctrl_Stop_Mode' */
  /* End of SystemInitialize for SubSystem: '<S40>/Stop Mode Ctrl' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/ACChiller_mode'
   *
   * Block description for '<S40>/ACChiller_mode':
   *  AC / AC Chiller mode control
   */
  /* SystemInitialize for Atomic SubSystem: '<S337>/EDC_ACChiller_Control'
   *
   * Block description for '<S337>/EDC_ACChiller_Control':
   *  ACChiller Mode_ EDC Control
   */
  Chery_E03_Hp_EDC_ACChiller_Control_Init();

  /* End of SystemInitialize for SubSystem: '<S337>/EDC_ACChiller_Control' */

  /* SystemInitialize for Atomic SubSystem: '<S337>/EXV_Chiller_Ctrl_ACChiller1'
   *
   * Block description for '<S337>/EXV_Chiller_Ctrl_ACChiller1':
   *  Chiller exv step control
   */
  /* InitializeConditions for UnitDelay: '<S413>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_j5 = 0U;

  /* InitializeConditions for UnitDelay: '<S414>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_m = 0U;

  /* InitializeConditions for UnitDelay: '<S415>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_ks = 0;

  /* SystemInitialize for Atomic SubSystem: '<S416>/Delay_2s_L1_Increase' */
  Chery_E03_Hp_DelayJudge_Cfg_Init(&Chery_E03_Hp_DW.Delay_2s_L1_Increase);

  /* End of SystemInitialize for SubSystem: '<S416>/Delay_2s_L1_Increase' */

  /* SystemInitialize for Atomic SubSystem: '<S416>/Delay_5s' */
  Chery_E03_Hp_DelayJudge_Cfg_Init(&Chery_E03_Hp_DW.Delay_5s);

  /* End of SystemInitialize for SubSystem: '<S416>/Delay_5s' */

  /* SystemInitialize for Atomic SubSystem: '<S345>/Chiller EXV Output Management' */
  /* InitializeConditions for Saturate: '<S412>/Saturation' incorporates:
   *  UnitDelay: '<S412>/Unit Delay'
   */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_o = 0U;

  /* End of SystemInitialize for SubSystem: '<S345>/Chiller EXV Output Management' */
  /* End of SystemInitialize for SubSystem: '<S337>/EXV_Chiller_Ctrl_ACChiller1' */

  /* SystemInitialize for Atomic SubSystem: '<S337>/EXV_Eva_Ctrl'
   *
   * Block description for '<S337>/EXV_Eva_Ctrl':
   *  Chiller exv step control
   */
  /* SystemInitialize for Atomic SubSystem: '<S346>/AC_Mode_Exv_PI'
   *
   * Block description for '<S346>/AC_Mode_Exv_PI':
   *  Chiller mode exv position PI
   */
  /* InitializeConditions for UnitDelay: '<S442>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_h = 0;

  /* End of SystemInitialize for SubSystem: '<S346>/AC_Mode_Exv_PI' */
  /* End of SystemInitialize for SubSystem: '<S337>/EXV_Eva_Ctrl' */
  /* End of SystemInitialize for SubSystem: '<S40>/ACChiller_mode' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/Chiller_Mode'
   *
   * Block description for '<S40>/Chiller_Mode':
   *  chiller mode control
   */
  /* SystemInitialize for Atomic SubSystem: '<S338>/EDC_Rpm_CHil_Ctrl'
   *
   * Block description for '<S338>/EDC_Rpm_CHil_Ctrl':
   *  chiller mode edc rpm control
   */
  /* InitializeConditions for UnitDelay: '<S474>/Unit Delay1' */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_c = 0;

  /* InitializeConditions for UnitDelay: '<S474>/Unit Delay2' */
  Chery_E03_Hp_DW.UnitDelay2_DSTATE = 0;

  /* SystemInitialize for Atomic SubSystem: '<S444>/Chiller_EDC_Start_Configulation'
   *
   * Block description for '<S444>/Chiller_EDC_Start_Configulation':
   *  edc startup condition judge
   */
  Chery_E03_Hp_Chiller_EDC_Start_Configulation_d_Init();

  /* End of SystemInitialize for SubSystem: '<S444>/Chiller_EDC_Start_Configulation' */

  /* SystemInitialize for Atomic SubSystem: '<S472>/Chiller_Risk_corrector'
   *
   * Block description for '<S472>/Chiller_Risk_corrector':
   *  chiller mode risk value for EDC rpm compensation
   */
  Chery_E03_Hp_Chiller_Risk_corrector_k_Init();

  /* End of SystemInitialize for SubSystem: '<S472>/Chiller_Risk_corrector' */

  /* SystemInitialize for Chart: '<S470>/Chiller_edc_management' */
  Chery_E03_Hp_Chiller_edc_management_Init(&rtb_s32NcompChil_Ctrl_Rpm,
    &Chery_E03_Hp_DW.sf_Chiller_edc_management_d);

  /* End of SystemInitialize for SubSystem: '<S338>/EDC_Rpm_CHil_Ctrl' */

  /* SystemInitialize for Atomic SubSystem: '<S338>/EXV_Step_Chiller_Ctrl'
   *
   * Block description for '<S338>/EXV_Step_Chiller_Ctrl':
   *  chiller mode exv step control
   */
  /* SystemInitialize for Atomic SubSystem: '<S446>/Chiller_Exv_PI'
   *
   * Block description for '<S446>/Chiller_Exv_PI':
   *  Chiller mode exv position PI
   */
  /* SystemInitialize for Atomic SubSystem: '<S500>/ChilExvPICal1' */
  /* InitializeConditions for UnitDelay: '<S501>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_k = 0;

  /* End of SystemInitialize for SubSystem: '<S500>/ChilExvPICal1' */
  /* End of SystemInitialize for SubSystem: '<S446>/Chiller_Exv_PI' */
  /* End of SystemInitialize for SubSystem: '<S338>/EXV_Step_Chiller_Ctrl' */
  /* End of SystemInitialize for SubSystem: '<S40>/Chiller_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/Total_Dehum_Mode'
   *
   * Block description for '<S40>/Total_Dehum_Mode':
   *  AC / AC Chiller mode control
   */
  /* SystemInitialize for Atomic SubSystem: '<S342>/EDC_TotalDehum_Control'
   *
   * Block description for '<S342>/EDC_TotalDehum_Control':
   *  ACChiller Mode_ EDC Control
   */
  Chery_E03_Hp_EDC_TotalDehum_Control_Init();

  /* End of SystemInitialize for SubSystem: '<S342>/EDC_TotalDehum_Control' */

  /* SystemInitialize for Atomic SubSystem: '<S1018>/Hyster_And_Delay_Judge' */
  Chery_E03_Hp_Hyster_And_Delay_Judge_i_Init
    (&Chery_E03_Hp_DW.Hyster_And_Delay_Judge_m, Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1018>/Hyster_And_Delay_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1019>/Hyster_And_Delay_Judge' */
  Chery_E03_Hp_Hyster_And_Delay_Judge_m_Init
    (&Chery_E03_Hp_DW.Hyster_And_Delay_Judge_h, Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1019>/Hyster_And_Delay_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S342>/EXV_Eva_TotalDehum_Ctrl'
   *
   * Block description for '<S342>/EXV_Eva_TotalDehum_Ctrl':
   *  Chiller exv step control
   */
  /* SystemInitialize for Atomic SubSystem: '<S910>/Total_DehumMode_EXV'
   *
   * Block description for '<S910>/Total_DehumMode_EXV':
   *  Chiller mode exv position PI
   */
  /* InitializeConditions for Saturate: '<S1010>/Saturation2' incorporates:
   *  UnitDelay: '<S1010>/Unit Delay'
   */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_p = 0;

  /* End of SystemInitialize for SubSystem: '<S910>/Total_DehumMode_EXV' */
  /* End of SystemInitialize for SubSystem: '<S342>/EXV_Eva_TotalDehum_Ctrl' */

  /* SystemInitialize for Atomic SubSystem: '<S342>/EXV_Chiller_Ctrl_TotalDehum'
   *
   * Block description for '<S342>/EXV_Chiller_Ctrl_TotalDehum':
   *  Chiller exv step control
   */
  /* InitializeConditions for UnitDelay: '<S985>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_b = 0;

  /* SystemInitialize for Atomic SubSystem: '<S986>/Delay_15s' */
  Chery_E03_Hp_DelayJudge_Cfg_Init(&Chery_E03_Hp_DW.Delay_15s);

  /* End of SystemInitialize for SubSystem: '<S986>/Delay_15s' */

  /* SystemInitialize for Atomic SubSystem: '<S986>/Delay_5s' */
  Chery_E03_Hp_DelayJudge_Cfg_Init(&Chery_E03_Hp_DW.Delay_5s_b);

  /* End of SystemInitialize for SubSystem: '<S986>/Delay_5s' */
  /* End of SystemInitialize for SubSystem: '<S342>/EXV_Chiller_Ctrl_TotalDehum' */
  /* End of SystemInitialize for SubSystem: '<S40>/Total_Dehum_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/HP_Mode'
   *
   * Block description for '<S40>/HP_Mode':
   *  AC / AC Chiller mode control
   */
  /* InitializeConditions for MinMax: '<S710>/Min' incorporates:
   *  UnitDelay: '<S659>/Unit Delay'
   */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_c = 0;

  /* InitializeConditions for UnitDelay: '<S654>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_n = false;

  /* SystemInitialize for Atomic SubSystem: '<S339>/EDC_Control_HP'
   *
   * Block description for '<S339>/EDC_Control_HP':
   *  ACChiller Mode_ EDC Control
   */
  Chery_E03_Hp_EDC_Control_HP_Init();

  /* End of SystemInitialize for SubSystem: '<S339>/EDC_Control_HP' */

  /* SystemInitialize for Atomic SubSystem: '<S660>/FirstRun2' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun, &Chery_E03_Hp_DW.FirstRun2);

  /* End of SystemInitialize for SubSystem: '<S660>/FirstRun2' */

  /* SystemInitialize for Atomic SubSystem: '<S656>/FirstRun' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_e, &Chery_E03_Hp_DW.FirstRun);

  /* End of SystemInitialize for SubSystem: '<S656>/FirstRun' */

  /* SystemInitialize for Atomic SubSystem: '<S654>/Hyster' */
  Chery_E03_Hp_Hyster_e_Init(&Chery_E03_Hp_DW.Hyster_p);

  /* End of SystemInitialize for SubSystem: '<S654>/Hyster' */

  /* SystemInitialize for Atomic SubSystem: '<S654>/Hyster1' */
  Chery_E03_Hp_Hyster_e_Init(&Chery_E03_Hp_DW.Hyster1_a);

  /* End of SystemInitialize for SubSystem: '<S654>/Hyster1' */

  /* SystemInitialize for Atomic SubSystem: '<S654>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S654>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S654>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_k);

  /* End of SystemInitialize for SubSystem: '<S654>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S654>/DelayJudge2' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge2);

  /* End of SystemInitialize for SubSystem: '<S654>/DelayJudge2' */

  /* SystemInitialize for Atomic SubSystem: '<S657>/FirstRun' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_dy, &Chery_E03_Hp_DW.FirstRun_n);

  /* End of SystemInitialize for SubSystem: '<S657>/FirstRun' */

  /* SystemInitialize for Atomic SubSystem: '<S657>/PIModule' */
  Chery_E03_Hp_PIModule_j_Init(&Chery_E03_Hp_DW.PIModule_p);

  /* End of SystemInitialize for SubSystem: '<S657>/PIModule' */

  /* SystemInitialize for Atomic SubSystem: '<S656>/PIModule' */
  Chery_E03_Hp_PIModule_Init(&Chery_E03_Hp_DW.PIModule);

  /* End of SystemInitialize for SubSystem: '<S656>/PIModule' */

  /* SystemInitialize for Atomic SubSystem: '<S658>/FirstRun' */
  Chery_E03_Hp_FirstRun_Init(&rtb_bFirstRun_d, &Chery_E03_Hp_DW.FirstRun_c);

  /* End of SystemInitialize for SubSystem: '<S658>/FirstRun' */

  /* SystemInitialize for Atomic SubSystem: '<S658>/PIModule' */
  Chery_E03_Hp_PIModule_j_Init(&Chery_E03_Hp_DW.PIModule_e);

  /* End of SystemInitialize for SubSystem: '<S658>/PIModule' */

  /* SystemInitialize for Iterator SubSystem: '<S660>/FindMinVal' */
  /* InitializeConditions for UnitDelay: '<S736>/TempMinVal' */
  Chery_E03_Hp_DW.TempMinVal_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S736>/TempIndexOfMinVal' */
  Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE = 0;

  /* End of SystemInitialize for SubSystem: '<S660>/FindMinVal' */

  /* SystemInitialize for Atomic SubSystem: '<S660>/Delay_Any' */
  Chery_E03_Hp_Delay_Any_Init(&Chery_E03_Hp_DW.Delay_Any);

  /* End of SystemInitialize for SubSystem: '<S660>/Delay_Any' */

  /* SystemInitialize for Atomic SubSystem: '<S339>/EXV_Eva_Ctrl_HPMode'
   *
   * Block description for '<S339>/EXV_Eva_Ctrl_HPMode':
   *  Chiller exv step control
   */
  /* SystemInitialize for Atomic SubSystem: '<S508>/EXV_HP_Mode'
   *
   * Block description for '<S508>/EXV_HP_Mode':
   *  Chiller mode exv position PI
   */
  /* InitializeConditions for UnitDelay: '<S648>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_g = 380000;

  /* End of SystemInitialize for SubSystem: '<S508>/EXV_HP_Mode' */
  /* End of SystemInitialize for SubSystem: '<S339>/EXV_Eva_Ctrl_HPMode' */

  /* SystemInitialize for Atomic SubSystem: '<S339>/EXV_Chiller_Ctrl_HP'
   *
   * Block description for '<S339>/EXV_Chiller_Ctrl_HP':
   *  Chiller exv step control
   */
  /* SystemInitialize for Atomic SubSystem: '<S507>/Chil_EXV_Calculation' */
  /* InitializeConditions for UnitDelay: '<S633>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_d = 0;

  /* End of SystemInitialize for SubSystem: '<S507>/Chil_EXV_Calculation' */
  /* End of SystemInitialize for SubSystem: '<S339>/EXV_Chiller_Ctrl_HP' */

  /* SystemInitialize for Atomic SubSystem: '<S660>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_l);

  /* End of SystemInitialize for SubSystem: '<S660>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S655>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_g,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S655>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S40>/HP_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/HVCH Mode Ctrl'
   *
   * Block description for '<S40>/HVCH Mode Ctrl':
   *  chiller mode control
   */
  /* InitializeConditions for UnitDelay: '<S818>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_l = 0;

  /* SystemInitialize for Atomic SubSystem: '<S817>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_o,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S817>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S40>/HVCH Mode Ctrl' */

  /* SystemInitialize for Merge: '<S40>/Merge' */
  Chery_E03_Hp_B.u16Ncomp_Rpm_Req = 0U;
  Chery_E03_Hp_B.u8TWValve_LTR_Req = 0U;
  Chery_E03_Hp_B.u8TWValve_BAT_Req = 0U;
  Chery_E03_Hp_B.u8HVCH_Req = 0U;
  Chery_E03_Hp_B.u16Pump_HVCH_Req = 0U;
  Chery_E03_Hp_B.u16Pump_Bat_Req = 0U;
  Chery_E03_Hp_B.u16Pump_Motor_Req = 0U;
  Chery_E03_Hp_B.bSOV_Eva_Req = 0U;
  Chery_E03_Hp_B.bSOV_OutEva_Req = 0U;
  Chery_E03_Hp_B.bSOV_TXVOutEva_Req = 0U;
  Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = 0U;
  Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = 0U;
  Chery_E03_Hp_B.u8AGS_Position_Req = 0U;
  Chery_E03_Hp_B.u8FRFAN_PWM_Req = 0U;
  Chery_E03_Hp_B.u8TWValve_HC_Req = 0U;
}

/* Disable for atomic system: '<S1>/System_Control' */
void Chery_E03_Hp_System_Control_Disable(void)
{
  /* Disable for SwitchCase: '<S40>/Switch Case' */
  Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = -1;
}

/* Start for atomic system: '<S1>/System_Control' */
void Chery_E03_Hp_System_Control_Start(void)
{
  /* Start for SwitchCase: '<S40>/Switch Case' */
  Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = -1;
}

/*
 * Output and update for atomic system: '<S1>/System_Control'
 * Block description for: '<S1>/System_Control'
 *   control
 */
void Chery_E03_Hp_System_Control(void)
{
  /* local block i/o variables */
  int32_T rtb_s32NcompChil_Ctrl_Rpm;
  int32_T rtb_s32NcompChil_Ctrl_Rpm_a;
  boolean_T rtb_bFirstRun;
  boolean_T rtb_bFirstRun_d;
  boolean_T rtb_bFirstRun_dy;
  boolean_T rtb_bFirstRun_e;
  int8_T rtPrevAction;
  uint16_T rtb_FAN_PWM_Calculatoin_AC;
  uint16_T rtb_FAN_PWM_Calculatoin_AC_f;
  uint16_T rtb_Switch;
  uint16_T rtb_FAN_PWM_Calculatoin_AC_p;
  uint16_T rtb_Conversion;
  boolean_T rtb_LowerRelop1_bs;
  boolean_T rtb_UpperRelop_d;
  int16_T rtb_Sum;
  boolean_T rtb_Switch2;
  boolean_T rtb_Conversion_dx;
  boolean_T rtb_Conversion_n;
  boolean_T rtb_Conversion_bb;
  uint16_T rtb_Conversion_d;
  int32_T rtb_Add1_kc;
  int32_T rtb_Switch_n;
  int32_T rtb_Conversion_d04l;
  uint8_T rtb_Conversion_g;
  int32_T rtb_BusArr[3];
  uint8_T rtb_TmpBufferAtOutEva_SOV_Close1Outport1;
  uint16_T rtb_Kp_Table_A10000;
  uint8_T rtb_bSOV_TXVOutEva_Req_f;
  boolean_T rtb_LowerRelop1_j;
  int16_T rtb_Sum_i;
  int32_T rtb_Sum2;
  int32_T rtb_Switch_oe;
  boolean_T rtb_LowerRelop1_a;
  int16_T rtb_Add1_j;
  int16_T rtb_Saturation;
  int32_T rtb_Divide;
  boolean_T rtb_SignalCopy;
  boolean_T rtb_SignalCopy_o3;
  int16_T rtb_Conversion_e;
  uint8_T rtb_Conversion_dq;
  uint8_T rtb_Conversion_k;
  uint8_T rtb_Conversion_dk;
  uint8_T rtb_Conversion_a;
  boolean_T rtb_SignalCopy_b;
  boolean_T rtb_SignalCopy_o;
  int32_T rtb_Divide5_n;
  int32_T rtb_Divide9_a;
  int32_T rtb_Divide8_n;
  int32_T rtb_Divide10_h;
  int32_T rtb_Divide11_p;
  uint8_T rtb_Conversion_h;
  boolean_T rtb_SignalCopy_e;
  uint8_T rtb_Conversion_np5;
  boolean_T rtb_SignalCopy_p;
  uint8_T rtb_Conversion_l;
  uint8_T rtb_Conversion_fe;
  int32_T rtb_Conversion_gw;
  boolean_T rtb_Switch2_m5;
  boolean_T rtb_SignalCopy_n;
  uint8_T rtb_Conversion_i;
  uint8_T rtb_Conversion_ea;
  uint8_T rtb_Conversion_nmc;
  uint8_T rtb_Conversion_i0;
  uint8_T rtb_Conversion_hy;
  uint8_T rtb_Conversion_iok;
  uint8_T rtb_Conversion_m;
  uint8_T rtb_Conversion_b;
  uint8_T rtb_Conversion_pz;
  uint8_T rtb_Conversion_hl;
  uint8_T rtb_Conversion_kz;
  uint8_T rtb_Conversion_fxj;

  /* SwitchCase: '<S40>/Switch Case' incorporates:
   *  Constant: '<S1018>/EDC_RPM_Offset'
   *  Constant: '<S1018>/EDC_RPM_Offset1'
   *  Constant: '<S1019>/Constant'
   *  Constant: '<S1019>/Constant1'
   *  Constant: '<S343>/Constant'
   *  Constant: '<S343>/Constant1'
   *  Constant: '<S343>/Constant2'
   *  Constant: '<S343>/Constant3'
   *  Constant: '<S349>/Constant'
   *  Constant: '<S350>/Constant'
   *  Constant: '<S351>/Constant'
   *  Constant: '<S356>/Pump_0%'
   *  Constant: '<S356>/Pump_100%'
   *  Constant: '<S356>/Pump_50%'
   *  Constant: '<S356>/Pump_80%'
   *  Constant: '<S360>/Constant'
   *  Constant: '<S361>/Constant'
   *  Constant: '<S362>/Constant'
   *  Constant: '<S363>/Constant'
   *  Constant: '<S429>/Constant'
   *  Constant: '<S430>/Constant'
   *  Constant: '<S443>/Constant'
   *  Constant: '<S443>/Constant1'
   *  Constant: '<S443>/Constant2'
   *  Constant: '<S443>/Constant3'
   *  Constant: '<S449>/Constant'
   *  Constant: '<S450>/Constant'
   *  Constant: '<S451>/Constant'
   *  Constant: '<S456>/Pump_0%'
   *  Constant: '<S456>/Pump_100%'
   *  Constant: '<S456>/Pump_50%'
   *  Constant: '<S456>/Pump_80%'
   *  Constant: '<S460>/Constant'
   *  Constant: '<S461>/Constant'
   *  Constant: '<S462>/Constant'
   *  Constant: '<S463>/Constant'
   *  Constant: '<S505>/Constant1'
   *  Constant: '<S505>/Constant2'
   *  Constant: '<S510>/Eva_SOV_Close'
   *  Constant: '<S510>/Eva_SOV_Open'
   *  Constant: '<S510>/OutEva_SOV_Close'
   *  Constant: '<S510>/OutEva_SOV_Open'
   *  Constant: '<S519>/Constant11'
   *  Constant: '<S519>/Constant12'
   *  Constant: '<S519>/Constant13'
   *  Constant: '<S519>/Constant14'
   *  Constant: '<S519>/Constant15'
   *  Constant: '<S519>/Constant2'
   *  Constant: '<S519>/Constant3'
   *  Constant: '<S519>/Constant6'
   *  Constant: '<S521>/Constant1'
   *  Constant: '<S521>/Constant10'
   *  Constant: '<S521>/Constant7'
   *  Constant: '<S521>/Constant8'
   *  Constant: '<S521>/Constant9'
   *  Constant: '<S523>/Constant'
   *  Constant: '<S524>/Constant'
   *  Constant: '<S525>/Constant'
   *  Constant: '<S526>/Constant'
   *  Constant: '<S527>/Constant'
   *  Constant: '<S546>/Constant'
   *  Constant: '<S548>/Constant'
   *  Constant: '<S549>/Constant'
   *  Constant: '<S550>/Constant'
   *  Constant: '<S551>/Constant'
   *  Constant: '<S633>/Constant2'
   *  Constant: '<S633>/Constant4'
   *  Constant: '<S637>/Constant'
   *  Constant: '<S638>/Constant'
   *  Constant: '<S640>/Constant'
   *  Constant: '<S641>/Constant'
   *  Constant: '<S648>/Constant1'
   *  Constant: '<S648>/Constant2'
   *  Constant: '<S649>/Constant'
   *  Constant: '<S654>/Constant4'
   *  Constant: '<S654>/Constant5'
   *  Constant: '<S654>/Constant6'
   *  Constant: '<S654>/Constant7'
   *  Constant: '<S654>/Constant8'
   *  Constant: '<S654>/Constant9'
   *  Constant: '<S654>/HVCH_Authority_Yes'
   *  Constant: '<S654>/HVCH_Authority_Yes1'
   *  Constant: '<S655>/Constant'
   *  Constant: '<S655>/Constant1'
   *  Constant: '<S656>/Constant1'
   *  Constant: '<S656>/Constant2'
   *  Constant: '<S656>/Constant3'
   *  Constant: '<S657>/Constant'
   *  Constant: '<S657>/Constant1'
   *  Constant: '<S657>/Constant2'
   *  Constant: '<S658>/Constant'
   *  Constant: '<S658>/Constant1'
   *  Constant: '<S658>/Constant2'
   *  Constant: '<S658>/Constant6'
   *  Constant: '<S658>/Constant7'
   *  Constant: '<S659>/Amp_2'
   *  Constant: '<S660>/PIMode_Normal_0'
   *  Constant: '<S697>/Constant'
   *  Constant: '<S697>/Constant1'
   *  Constant: '<S715>/Constant'
   *  Constant: '<S718>/Constant'
   *  Constant: '<S733>/Constant'
   *  Constant: '<S760>/Constant'
   *  Constant: '<S761>/Constant'
   *  Constant: '<S773>/AGS_0%_Close1'
   *  Constant: '<S773>/AGS_0%_Close3'
   *  Constant: '<S773>/AGS_100%_Open'
   *  Constant: '<S776>/Pump_0%'
   *  Constant: '<S776>/Pump_100%'
   *  Constant: '<S776>/Pump_50%'
   *  Constant: '<S776>/Pump_80%'
   *  Constant: '<S782>/Constant'
   *  Constant: '<S783>/Constant'
   *  Constant: '<S784>/Constant'
   *  Constant: '<S785>/Constant'
   *  Constant: '<S805>/Constant'
   *  Constant: '<S807>/Constant'
   *  Constant: '<S817>/Constant'
   *  Constant: '<S817>/Constant1'
   *  Constant: '<S835>/AGS_0%_Close1'
   *  Constant: '<S835>/AGS_0%_Close3'
   *  Constant: '<S835>/AGS_100%_Open'
   *  Constant: '<S837>/Pump_0%'
   *  Constant: '<S837>/Pump_100%'
   *  Constant: '<S837>/Pump_50%'
   *  Constant: '<S837>/Pump_80%'
   *  Constant: '<S844>/Constant'
   *  Constant: '<S845>/Constant'
   *  Constant: '<S846>/Constant'
   *  Constant: '<S847>/Constant'
   *  Constant: '<S895>/Constant'
   *  Constant: '<S897>/Constant'
   *  Constant: '<S920>/Pump_0%'
   *  Constant: '<S920>/Pump_100%'
   *  Constant: '<S920>/Pump_50%'
   *  Constant: '<S920>/Pump_80%'
   *  Constant: '<S924>/Constant'
   *  Constant: '<S925>/Constant'
   *  Constant: '<S926>/Constant'
   *  Constant: '<S927>/Constant'
   *  Constant: '<S997>/Constant'
   *  Constant: '<S998>/Constant'
   *  DataTypeConversion: '<S773>/Data Type Conversion'
   *  DataTypeConversion: '<S773>/Data Type Conversion1'
   *  DataTypeConversion: '<S835>/Data Type Conversion'
   *  DataTypeConversion: '<S835>/Data Type Conversion1'
   *  Logic: '<S343>/OR'
   *  Logic: '<S343>/OR1'
   *  Logic: '<S356>/OR2'
   *  Logic: '<S443>/OR'
   *  Logic: '<S443>/OR1'
   *  Logic: '<S456>/OR2'
   *  Logic: '<S505>/OR'
   *  Logic: '<S519>/OR'
   *  Logic: '<S519>/OR3'
   *  Logic: '<S521>/OR1'
   *  Logic: '<S521>/OR2'
   *  Logic: '<S633>/OR1'
   *  Logic: '<S654>/NOT'
   *  Logic: '<S773>/OR1'
   *  Logic: '<S773>/OR3'
   *  Logic: '<S776>/OR2'
   *  Logic: '<S835>/OR1'
   *  Logic: '<S835>/OR3'
   *  Logic: '<S837>/OR2'
   *  Logic: '<S920>/OR2'
   *  Lookup_n-D: '<S697>/Ki_Table_A10000'
   *  Lookup_n-D: '<S697>/Kp_Table_A10000'
   *  Lookup_n-D: '<S773>/FAN_PWM_Calculatoin_AC'
   *  Lookup_n-D: '<S835>/FAN_PWM_Calculatoin_AC'
   *  MultiPortSwitch: '<S736>/Index Vector1'
   *  Product: '<S633>/Divide'
   *  Product: '<S648>/Divide'
   *  Product: '<S697>/Divide'
   *  Product: '<S697>/Product4'
   *  RelationalOperator: '<S349>/Compare'
   *  RelationalOperator: '<S350>/Compare'
   *  RelationalOperator: '<S351>/Compare'
   *  RelationalOperator: '<S360>/Compare'
   *  RelationalOperator: '<S361>/Compare'
   *  RelationalOperator: '<S362>/Compare'
   *  RelationalOperator: '<S363>/Compare'
   *  RelationalOperator: '<S429>/Compare'
   *  RelationalOperator: '<S430>/Compare'
   *  RelationalOperator: '<S449>/Compare'
   *  RelationalOperator: '<S450>/Compare'
   *  RelationalOperator: '<S451>/Compare'
   *  RelationalOperator: '<S460>/Compare'
   *  RelationalOperator: '<S461>/Compare'
   *  RelationalOperator: '<S462>/Compare'
   *  RelationalOperator: '<S463>/Compare'
   *  RelationalOperator: '<S519>/Relational Operator'
   *  RelationalOperator: '<S523>/Compare'
   *  RelationalOperator: '<S524>/Compare'
   *  RelationalOperator: '<S525>/Compare'
   *  RelationalOperator: '<S526>/Compare'
   *  RelationalOperator: '<S527>/Compare'
   *  RelationalOperator: '<S546>/Compare'
   *  RelationalOperator: '<S548>/Compare'
   *  RelationalOperator: '<S549>/Compare'
   *  RelationalOperator: '<S550>/Compare'
   *  RelationalOperator: '<S551>/Compare'
   *  RelationalOperator: '<S637>/Compare'
   *  RelationalOperator: '<S638>/Compare'
   *  RelationalOperator: '<S640>/Compare'
   *  RelationalOperator: '<S641>/Compare'
   *  RelationalOperator: '<S649>/Compare'
   *  RelationalOperator: '<S658>/Relational Operator'
   *  RelationalOperator: '<S715>/Compare'
   *  RelationalOperator: '<S733>/Compare'
   *  RelationalOperator: '<S760>/Compare'
   *  RelationalOperator: '<S761>/Compare'
   *  RelationalOperator: '<S782>/Compare'
   *  RelationalOperator: '<S783>/Compare'
   *  RelationalOperator: '<S784>/Compare'
   *  RelationalOperator: '<S785>/Compare'
   *  RelationalOperator: '<S805>/Compare'
   *  RelationalOperator: '<S807>/Compare'
   *  RelationalOperator: '<S844>/Compare'
   *  RelationalOperator: '<S845>/Compare'
   *  RelationalOperator: '<S846>/Compare'
   *  RelationalOperator: '<S847>/Compare'
   *  RelationalOperator: '<S895>/Compare'
   *  RelationalOperator: '<S897>/Compare'
   *  RelationalOperator: '<S924>/Compare'
   *  RelationalOperator: '<S925>/Compare'
   *  RelationalOperator: '<S926>/Compare'
   *  RelationalOperator: '<S927>/Compare'
   *  RelationalOperator: '<S997>/Compare'
   *  RelationalOperator: '<S998>/Compare'
   *  Sum: '<S1018>/Sum'
   *  Sum: '<S1018>/Sum1'
   *  Sum: '<S1019>/Sum'
   *  Sum: '<S416>/Add2'
   *  Sum: '<S654>/Sum1'
   *  Sum: '<S654>/Sum2'
   *  Sum: '<S654>/Sum3'
   *  Sum: '<S655>/Sum'
   *  Sum: '<S718>/Sum2'
   *  Sum: '<S773>/Sum'
   *  Sum: '<S817>/Sum'
   *  Sum: '<S835>/Sum'
   *  Sum: '<S986>/Add2'
   *  UnitDelay: '<S1>/Unit Delay'
   *  UnitDelay: '<S648>/Unit Delay'
   *  UnitDelay: '<S654>/Unit Delay'
   *  UnitDelay: '<S659>/Unit Delay'
   *  UnitDelay: '<S736>/TempIndexOfMinVal'
   *  UnitDelay: '<S736>/TempMinVal'
   */
  rtPrevAction = Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem;
  switch (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1) {
   case 0:
   case 4:
    Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case 1:
   case 2:
    Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   case 3:
    Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = 2;
    break;

   case 5:
   case 6:
    Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = 3;
    break;

   case 7:
   case 8:
   case 9:
   case 10:
   case 12:
    Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = 4;
    break;

   default:
    Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem = 5;
    break;
  }

  switch (Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    if (Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S40>/Stop Mode Ctrl' incorporates:
       *  ActionPort: '<S341>/Action Port'
       *
       * Block description for '<S40>/Stop Mode Ctrl':
       *  chiller mode control
       */
      /* SystemReset for Atomic SubSystem: '<S341>/EDC_Ctrl_Stop_Mode'
       *
       * Block description for '<S341>/EDC_Ctrl_Stop_Mode':
       *  chiller mode edc rpm control
       */
      /* SystemReset for SwitchCase: '<S40>/Switch Case' incorporates:
       *  Chart: '<S860>/Chiller_edc_management'
       *  Product: '<S864>/Product1'
       *  UnitDelay: '<S864>/Unit Delay'
       *  UnitDelay: '<S864>/Unit Delay1'
       *  UnitDelay: '<S864>/Unit Delay2'
       */
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_d = 0;
      Chery_E03_Hp_DW.UnitDelay_DSTATE_pv = 0U;
      Chery_E03_Hp_DW.UnitDelay2_DSTATE_o = 0;

      /* SystemReset for Atomic SubSystem: '<S832>/Chiller_EDC_Start_Configulation'
       *
       * Block description for '<S832>/Chiller_EDC_Start_Configulation':
       *  edc startup condition judge
       */
      Chery_E03_Hp_Chiller_EDC_Start_Configulation_Reset();

      /* End of SystemReset for SubSystem: '<S832>/Chiller_EDC_Start_Configulation' */

      /* SystemReset for Atomic SubSystem: '<S862>/Chiller_Risk_corrector'
       *
       * Block description for '<S862>/Chiller_Risk_corrector':
       *  chiller mode risk value for EDC rpm compensation
       */
      Chery_E03_Hp_Chiller_Risk_corrector_Reset();

      /* End of SystemReset for SubSystem: '<S862>/Chiller_Risk_corrector' */
      Chery_E03_Hp_Chiller_edc_management_Reset(&rtb_s32NcompChil_Ctrl_Rpm_a,
        &Chery_E03_Hp_DW.sf_Chiller_edc_management);

      /* End of SystemReset for SubSystem: '<S341>/EDC_Ctrl_Stop_Mode' */
      /* End of SystemReset for SubSystem: '<S40>/Stop Mode Ctrl' */
    }

    /* Outputs for IfAction SubSystem: '<S40>/Stop Mode Ctrl' incorporates:
     *  ActionPort: '<S341>/Action Port'
     *
     * Block description for '<S40>/Stop Mode Ctrl':
     *  chiller mode control
     */
    /* Outputs for Atomic SubSystem: '<S837>/IfThenElse4' */
    rtb_FAN_PWM_Calculatoin_AC = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_3, 80, 0);

    /* End of Outputs for SubSystem: '<S837>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S837>/IfThenElse3' */
    rtb_FAN_PWM_Calculatoin_AC = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2, 60,
       rtb_FAN_PWM_Calculatoin_AC);

    /* End of Outputs for SubSystem: '<S837>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S837>/IfThenElse2' */
    rtb_FAN_PWM_Calculatoin_AC = (uint16_T) Chery_E03_Hp_IfThenElse2
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTM_CycleL11) ||
       (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1), 40,
       rtb_FAN_PWM_Calculatoin_AC);

    /* End of Outputs for SubSystem: '<S837>/IfThenElse2' */

    /* SignalConversion: '<S341>/Signal Copy9' incorporates:
     *  Constant: '<S837>/Pump_0%'
     *  Constant: '<S837>/Pump_100%'
     *  Constant: '<S837>/Pump_50%'
     *  Constant: '<S837>/Pump_80%'
     *  Constant: '<S844>/Constant'
     *  Constant: '<S845>/Constant'
     *  Constant: '<S846>/Constant'
     *  Constant: '<S847>/Constant'
     *  Logic: '<S837>/OR2'
     *  RelationalOperator: '<S844>/Compare'
     *  RelationalOperator: '<S845>/Compare'
     *  RelationalOperator: '<S846>/Compare'
     *  RelationalOperator: '<S847>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Bat_Req = rtb_FAN_PWM_Calculatoin_AC;

    /* SignalConversion: '<S341>/Signal Copy8' incorporates:
     *  Lookup_n-D: '<S838>/Pump_HVCH_Req'
     *  Sum: '<S838>/Sum'
     */
    Chery_E03_Hp_B.u16Pump_HVCH_Req = look2_is16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, (int16_T)
       (Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 - Chery_E03_Hp_B.HpI_s16Tamb_A10),
       ((int16_T *)&(HP_u16Pump_HVCH_AC.HP_s16Tamb_AC_u1[0])), ((int16_T *)
        &(HP_u16Pump_HVCH_AC.HP_s16TDelta_Wat_Amb_u2[0])), ((uint16_T *)
        &(HP_u16Pump_HVCH_AC.HP_u16Pump_HVCH_AC_y[0])),
       Chery_E03_Hp_ConstP.pooled19, 8U);

    /* Outputs for Atomic SubSystem: '<S839>/IfThenElse2' */
    /* SignalConversion: '<S341>/Signal Copy10' incorporates:
     *  Constant: '<S839>/Constant4'
     *  Constant: '<S839>/Constant5'
     *  Constant: '<S854>/Constant'
     *  RelationalOperator: '<S854>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Motor_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((int32_T)Chery_E03_Hp_B.HpI_u8Mot_CoolLv) == 1, 70, 0);

    /* End of Outputs for SubSystem: '<S839>/IfThenElse2' */

    /* SignalConversion: '<S341>/Signal Copy5' incorporates:
     *  Lookup_n-D: '<S842>/HVCH_3Way_Valve'
     */
    Chery_E03_Hp_B.u8TWValve_HC_Req = look2_is16lu16n8tu8_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req,
       ((int16_T *)&(HP_u8TWV_HVCH_AC.HP_s16Tamb_AC_u1[0])), ((int16_T *)
        &(HP_u8TWV_HVCH_AC.HP_s16Twater_Req_Cmf_u2[0])), ((uint8_T *)
        &(HP_u8TWV_HVCH_AC.HP_u8TWV_HVCH_AC_y[0])), Chery_E03_Hp_ConstP.pooled18,
       8U);

    /* Outputs for Atomic SubSystem: '<S843>/IfThenElse1' */
    /* SignalConversion: '<S341>/Signal Copy6' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S843>/Constant2'
     *  Constant: '<S843>/Constant3'
     *  Constant: '<S857>/Constant'
     *  RelationalOperator: '<S857>/Compare'
     */
    Chery_E03_Hp_B.u8TWValve_LTR_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1, 50, 0);

    /* End of Outputs for SubSystem: '<S843>/IfThenElse1' */

    /* SignalConversion: '<S341>/Signal Copy7' incorporates:
     *  Constant: '<S841>/Constant6'
     */
    Chery_E03_Hp_B.u8TWValve_BAT_Req = 100U;

    /* SignalConversion: '<S341>/Signal Copy11' incorporates:
     *  Constant: '<S840>/Constant7'
     */
    Chery_E03_Hp_B.u8HVCH_Req = 0U;

    /* Outputs for Atomic SubSystem: '<S341>/EDC_Ctrl_Stop_Mode'
     *
     * Block description for '<S341>/EDC_Ctrl_Stop_Mode':
     *  chiller mode edc rpm control
     */
    /* Outputs for Atomic SubSystem: '<S832>/Chiller_EDC_Start_Configulation'
     *
     * Block description for '<S832>/Chiller_EDC_Start_Configulation':
     *  edc startup condition judge
     */
    Chery_E03_Hp_Chiller_EDC_Start_Configulation();

    /* End of Outputs for SubSystem: '<S832>/Chiller_EDC_Start_Configulation' */

    /* Outputs for Atomic SubSystem: '<S861>/ChilPIparameters'
     *
     * Block description for '<S861>/ChilPIparameters':
     *  get chiller Kp ki and delt_T
     */
    Chery_E03_Hp_ChilPIparameters();

    /* End of Outputs for SubSystem: '<S861>/ChilPIparameters' */

    /* Saturate: '<S867>/Saturation1' */
    if (Chery_E03_Hp_B.s16Twat_Ctrl_delt_e > 200) {
      rtb_Sum_i = 200;
    } else if (Chery_E03_Hp_B.s16Twat_Ctrl_delt_e < -200) {
      rtb_Sum_i = -200;
    } else {
      rtb_Sum_i = Chery_E03_Hp_B.s16Twat_Ctrl_delt_e;
    }

    /* End of Saturate: '<S867>/Saturation1' */

    /* Product: '<S867>/Product1' */
    rtb_Sum2 = ((int32_T)rtb_Sum_i) * ((int32_T)
      Chery_E03_Hp_B.u16Ncomp_PrcoRisk_eb);

    /* Sum: '<S867>/Add' incorporates:
     *  Product: '<S867>/Product2'
     *  UnitDelay: '<S864>/Unit Delay1'
     */
    rtb_Switch_oe = ((((int32_T)rtb_Sum_i) * ((int32_T)
      Chery_E03_Hp_B.u16Ncomp_Tout_Risk_m)) + rtb_Sum2) +
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_d;

    /* Outputs for Atomic SubSystem: '<S862>/Chiller_Risk_corrector'
     *
     * Block description for '<S862>/Chiller_Risk_corrector':
     *  chiller mode risk value for EDC rpm compensation
     */
    Chery_E03_Hp_Chiller_Risk_corrector();

    /* End of Outputs for SubSystem: '<S862>/Chiller_Risk_corrector' */

    /* Switch: '<S868>/Switch' incorporates:
     *  Constant: '<S870>/Constant'
     *  RelationalOperator: '<S870>/Compare'
     *  Sum: '<S868>/Subtract1'
     */
    if (Chery_E03_Hp_B.bChilRisk_Comp_e != bFAIL_NO_RISK_0) {
      /* MinMax: '<S868>/Max' incorporates:
       *  UnitDelay: '<S864>/Unit Delay'
       */
      if (rtb_Switch_oe >= ((int32_T)Chery_E03_Hp_DW.UnitDelay_DSTATE_pv)) {
        rtb_Switch_oe = (int32_T)Chery_E03_Hp_DW.UnitDelay_DSTATE_pv;
      }

      /* End of MinMax: '<S868>/Max' */
      rtb_Switch_oe -= (int32_T)Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk_j;
    }

    /* End of Switch: '<S868>/Switch' */

    /* Chart: '<S860>/Chiller_edc_management' */
    Chery_E03_Hp_Chiller_edc_management(Chery_E03_Hp_B.bChil_EDC_Config_l,
      rtb_Switch_oe, &rtb_s32NcompChil_Ctrl_Rpm_a,
      &Chery_E03_Hp_DW.sf_Chiller_edc_management);

    /* Sum: '<S864>/Sum1' incorporates:
     *  Constant: '<S864>/Constant'
     *  UnitDelay: '<S864>/Unit Delay2'
     */
    rtb_Switch_oe = Chery_E03_Hp_DW.UnitDelay2_DSTATE_o + s32NCOMP_UP_SPD;

    /* Switch: '<S864>/Switch1' incorporates:
     *  Constant: '<S864>/Constant2'
     *  Constant: '<S886>/Constant'
     *  Constant: '<S887>/Constant'
     *  Logic: '<S864>/AND'
     *  MinMax: '<S864>/Min'
     *  RelationalOperator: '<S886>/Compare'
     *  RelationalOperator: '<S887>/Compare'
     */
    if ((rtb_s32NcompChil_Ctrl_Rpm_a < s32NCOMP_DOWN_LIMIT) &&
        (rtb_s32NcompChil_Ctrl_Rpm_a > s32NCOMP_DOWN_0)) {
      rtb_Switch_oe = s32NCOMP_DOWN_LIMIT;
    } else {
      if (rtb_s32NcompChil_Ctrl_Rpm_a < rtb_Switch_oe) {
        /* MinMax: '<S864>/Min' */
        rtb_Switch_oe = rtb_s32NcompChil_Ctrl_Rpm_a;
      }
    }

    /* End of Switch: '<S864>/Switch1' */

    /* Switch: '<S864>/Switch2' incorporates:
     *  Constant: '<S864>/Constant3'
     *  Constant: '<S888>/Constant'
     *  RelationalOperator: '<S888>/Compare'
     */
    if (rtb_s32NcompChil_Ctrl_Rpm_a == s32NCOMP_DOWN_0) {
      rtb_Switch_oe = s32NCOMP_DOWN_0;
    }

    /* End of Switch: '<S864>/Switch2' */

    /* Product: '<S864>/Product1' incorporates:
     *  Constant: '<S864>/Constant4'
     */
    Chery_E03_Hp_DW.UnitDelay2_DSTATE_o = (int32_T)((uint32_T)(((uint32_T)
      Chery_E03_Hp_B.HpI_u16Ncomp_Max) * ((uint32_T)u8AMP_10)));

    /* RelationalOperator: '<S889>/LowerRelop1' incorporates:
     *  Product: '<S864>/Product1'
     */
    rtb_LowerRelop1_a = (rtb_Switch_oe > Chery_E03_Hp_DW.UnitDelay2_DSTATE_o);

    /* Switch: '<S889>/Switch' incorporates:
     *  Constant: '<S864>/Constant8'
     *  RelationalOperator: '<S889>/UpperRelop'
     */
    if (rtb_Switch_oe < s32NCOMP_DOWN_0) {
      rtb_Switch_oe = s32NCOMP_DOWN_0;
    }

    /* End of Switch: '<S889>/Switch' */

    /* Switch: '<S889>/Switch2' */
    if (!rtb_LowerRelop1_a) {
      /* Product: '<S864>/Product1' incorporates:
       *  UnitDelay: '<S864>/Unit Delay2'
       */
      Chery_E03_Hp_DW.UnitDelay2_DSTATE_o = rtb_Switch_oe;
    }

    /* End of Switch: '<S889>/Switch2' */

    /* Product: '<S864>/Product' incorporates:
     *  Constant: '<S864>/Constant1'
     *  UnitDelay: '<S864>/Unit Delay'
     *  UnitDelay: '<S864>/Unit Delay2'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_pv = (uint16_T)((int32_T)
      (Chery_E03_Hp_DW.UnitDelay2_DSTATE_o / ((int32_T)u8AMP_10)));

    /* Sum: '<S864>/Sum2' incorporates:
     *  UnitDelay: '<S864>/Unit Delay2'
     */
    rtb_Sum2 = Chery_E03_Hp_DW.UnitDelay2_DSTATE_o - rtb_Sum2;

    /* Saturate: '<S864>/Saturation1' */
    if (rtb_Sum2 > 50000) {
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_d = 50000;
    } else if (rtb_Sum2 < 0) {
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_d = 0;
    } else {
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_d = rtb_Sum2;
    }

    /* End of Saturate: '<S864>/Saturation1' */
    /* End of Outputs for SubSystem: '<S341>/EDC_Ctrl_Stop_Mode' */

    /* SignalConversion: '<S341>/Signal Copy2' incorporates:
     *  Constant: '<S833>/Constant'
     */
    Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = 576U;

    /* SignalConversion: '<S341>/Signal Copy' incorporates:
     *  Constant: '<S832>/Constant'
     */
    Chery_E03_Hp_B.u16Ncomp_Rpm_Req = u16NCOMP_STOP_0;

    /* SignalConversion: '<S341>/Signal Copy1' incorporates:
     *  Constant: '<S834>/Constant'
     */
    Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = 576U;

    /* Outputs for Atomic SubSystem: '<S835>/IfThenElse1' */
    rtb_Conversion_l = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_CoolReq_Yes) || (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 100, 0);

    /* End of Outputs for SubSystem: '<S835>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S835>/IfThenElse' */
    /* SignalConversion: '<S341>/Signal Copy3' incorporates:
     *  Constant: '<S835>/AGS_0%_Close'
     *  Constant: '<S835>/AGS_0%_Close1'
     *  Constant: '<S835>/AGS_100%_Open'
     *  Constant: '<S894>/Constant'
     *  Constant: '<S895>/Constant'
     *  Logic: '<S835>/OR'
     *  Logic: '<S835>/OR1'
     *  RelationalOperator: '<S894>/Compare'
     *  RelationalOperator: '<S895>/Compare'
     */
    Chery_E03_Hp_B.u8AGS_Position_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_HeatReq_Yes) && (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 0, rtb_Conversion_l);

    /* End of Outputs for SubSystem: '<S835>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S835>/IfThenElse3' */
    rtb_Conversion_fe = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_CoolReq_Yes) || (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), (uint8_T)look2_iu16s16lu32n16tu16_binlcse
       ((uint16_T)Chery_E03_Hp_B.HpI_u8VehSpd, (int16_T)
        (Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 - Chery_E03_Hp_B.HpI_s16Tamb_A10),
        ((uint16_T *)&(AC_u16PWM_FAN_StopMode.AC_u16Vspd_FAN_u1[0])), ((int16_T *)
         &(AC_u16PWM_FAN_StopMode.AC_s16T_DeltaExtWater_u2[0])), ((uint16_T *)
         &(AC_u16PWM_FAN_StopMode.AC_u16PWM_FAN_StopMode_y[0])),
        Chery_E03_Hp_ConstP.pooled25, 7U), 0);

    /* End of Outputs for SubSystem: '<S835>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S835>/IfThenElse2' */
    /* SignalConversion: '<S341>/Signal Copy4' incorporates:
     *  Constant: '<S835>/AGS_0%_Close3'
     *  Constant: '<S835>/Front_FAN_Close'
     *  Constant: '<S896>/Constant'
     *  Constant: '<S897>/Constant'
     *  DataTypeConversion: '<S835>/Data Type Conversion'
     *  DataTypeConversion: '<S835>/Data Type Conversion1'
     *  Logic: '<S835>/OR2'
     *  Logic: '<S835>/OR3'
     *  Lookup_n-D: '<S835>/FAN_PWM_Calculatoin_AC'
     *  RelationalOperator: '<S896>/Compare'
     *  RelationalOperator: '<S897>/Compare'
     *  Sum: '<S835>/Sum'
     */
    Chery_E03_Hp_B.u8FRFAN_PWM_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_HeatReq_Yes) && (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 0, rtb_Conversion_fe);

    /* End of Outputs for SubSystem: '<S835>/IfThenElse2' */

    /* SignalConversion: '<S341>/Signal Copy12' incorporates:
     *  Constant: '<S836>/SOV_Eva_Close'
     */
    Chery_E03_Hp_B.bSOV_Eva_Req = bSOV_Close_0 ? 1U : 0U;

    /* SignalConversion: '<S341>/Signal Copy13' incorporates:
     *  Constant: '<S836>/SOV_Open'
     */
    Chery_E03_Hp_B.bSOV_OutEva_Req = bSOV_OPEN_1 ? 1U : 0U;

    /* SignalConversion: '<S341>/Signal Copy14' incorporates:
     *  Constant: '<S836>/SOV_TXV_Close'
     */
    Chery_E03_Hp_B.bSOV_TXVOutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* End of Outputs for SubSystem: '<S40>/Stop Mode Ctrl' */
    break;

   case 1:
    if (Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S40>/ACChiller_mode' incorporates:
       *  ActionPort: '<S337>/Action Port'
       *
       * Block description for '<S40>/ACChiller_mode':
       *  AC / AC Chiller mode control
       */
      /* SystemReset for Atomic SubSystem: '<S337>/EDC_ACChiller_Control'
       *
       * Block description for '<S337>/EDC_ACChiller_Control':
       *  ACChiller Mode_ EDC Control
       */
      /* SystemReset for SwitchCase: '<S40>/Switch Case' incorporates:
       *  Saturate: '<S412>/Saturation'
       *  UnitDelay: '<S412>/Unit Delay'
       *  UnitDelay: '<S413>/Unit Delay'
       *  UnitDelay: '<S414>/Unit Delay'
       *  UnitDelay: '<S415>/Unit Delay'
       *  UnitDelay: '<S442>/Unit Delay'
       */
      Chery_E03_Hp_EDC_ACChiller_Control_Reset();

      /* End of SystemReset for SubSystem: '<S337>/EDC_ACChiller_Control' */

      /* SystemReset for Atomic SubSystem: '<S337>/EXV_Chiller_Ctrl_ACChiller1'
       *
       * Block description for '<S337>/EXV_Chiller_Ctrl_ACChiller1':
       *  Chiller exv step control
       */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_j5 = 0U;
      Chery_E03_Hp_DW.UnitDelay_DSTATE_m = 0U;
      Chery_E03_Hp_DW.UnitDelay_DSTATE_ks = 0;

      /* SystemReset for Atomic SubSystem: '<S416>/Delay_2s_L1_Increase' */
      Chery_E03_Hp_DelayJudge_Cfg_Reset(&Chery_E03_Hp_DW.Delay_2s_L1_Increase);

      /* End of SystemReset for SubSystem: '<S416>/Delay_2s_L1_Increase' */

      /* SystemReset for Atomic SubSystem: '<S416>/Delay_5s' */
      Chery_E03_Hp_DelayJudge_Cfg_Reset(&Chery_E03_Hp_DW.Delay_5s);

      /* End of SystemReset for SubSystem: '<S416>/Delay_5s' */

      /* SystemReset for Atomic SubSystem: '<S345>/Chiller EXV Output Management' */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_o = 0U;

      /* End of SystemReset for SubSystem: '<S345>/Chiller EXV Output Management' */
      /* End of SystemReset for SubSystem: '<S337>/EXV_Chiller_Ctrl_ACChiller1' */

      /* SystemReset for Atomic SubSystem: '<S337>/EXV_Eva_Ctrl'
       *
       * Block description for '<S337>/EXV_Eva_Ctrl':
       *  Chiller exv step control
       */
      /* SystemReset for Atomic SubSystem: '<S346>/AC_Mode_Exv_PI'
       *
       * Block description for '<S346>/AC_Mode_Exv_PI':
       *  Chiller mode exv position PI
       */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_h = 0;

      /* End of SystemReset for SubSystem: '<S346>/AC_Mode_Exv_PI' */
      /* End of SystemReset for SubSystem: '<S337>/EXV_Eva_Ctrl' */
      /* End of SystemReset for SubSystem: '<S40>/ACChiller_mode' */
    }

    /* Outputs for IfAction SubSystem: '<S40>/ACChiller_mode' incorporates:
     *  ActionPort: '<S337>/Action Port'
     *
     * Block description for '<S40>/ACChiller_mode':
     *  AC / AC Chiller mode control
     */
    /* Outputs for Atomic SubSystem: '<S343>/IfThenElse' */
    rtb_Conversion_dq = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTM_CycleL11) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_ACCHILLER_2), 0, 100);

    /* End of Outputs for SubSystem: '<S343>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S343>/IfThenElse1' */
    rtb_Conversion_dk = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.Conversion_p <= 200) && (Chery_E03_Hp_B.bBTM_CoolReq_Yes),
       50, 0);

    /* End of Outputs for SubSystem: '<S343>/IfThenElse1' */

    /* SignalConversion: '<S337>/Signal Copy6' incorporates:
     *  Constant: '<S343>/Constant'
     *  Constant: '<S343>/Constant1'
     *  Constant: '<S343>/Constant2'
     *  Constant: '<S343>/Constant3'
     *  Constant: '<S349>/Constant'
     *  Constant: '<S350>/Constant'
     *  Constant: '<S351>/Constant'
     *  Logic: '<S343>/OR'
     *  Logic: '<S343>/OR1'
     *  RelationalOperator: '<S349>/Compare'
     *  RelationalOperator: '<S350>/Compare'
     *  RelationalOperator: '<S351>/Compare'
     */
    Chery_E03_Hp_B.u8TWValve_LTR_Req = 0U;

    /* Outputs for Atomic SubSystem: '<S343>/IfThenElse2' */
    /* SignalConversion: '<S337>/Signal Copy10' incorporates:
     *  Constant: '<S343>/Constant4'
     *  Constant: '<S343>/Constant5'
     *  Constant: '<S352>/Constant'
     *  RelationalOperator: '<S352>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Motor_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((int32_T)Chery_E03_Hp_B.HpI_u8Mot_CoolLv) == 1, 100, 0);

    /* End of Outputs for SubSystem: '<S343>/IfThenElse2' */

    /* SignalConversion: '<S337>/Signal Copy5' incorporates:
     *  Lookup_n-D: '<S343>/HVCH_3Way_Valve'
     */
    Chery_E03_Hp_B.u8TWValve_HC_Req = look2_is16lu16n8tu8_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req,
       ((int16_T *)&(HP_u8TWV_HVCH_AC.HP_s16Tamb_AC_u1[0])), ((int16_T *)
        &(HP_u8TWV_HVCH_AC.HP_s16Twater_Req_Cmf_u2[0])), ((uint8_T *)
        &(HP_u8TWV_HVCH_AC.HP_u8TWV_HVCH_AC_y[0])), Chery_E03_Hp_ConstP.pooled18,
       8U);

    /* SignalConversion: '<S337>/Signal Copy8' incorporates:
     *  Lookup_n-D: '<S343>/Pump_HVCH_Req'
     *  Sum: '<S343>/Sum'
     */
    Chery_E03_Hp_B.u16Pump_HVCH_Req = look2_is16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, (int16_T)
       (Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 - Chery_E03_Hp_B.HpI_s16Tamb_A10),
       ((int16_T *)&(HP_u16Pump_HVCH_AC.HP_s16Tamb_AC_u1[0])), ((int16_T *)
        &(HP_u16Pump_HVCH_AC.HP_s16TDelta_Wat_Amb_u2[0])), ((uint16_T *)
        &(HP_u16Pump_HVCH_AC.HP_u16Pump_HVCH_AC_y[0])),
       Chery_E03_Hp_ConstP.pooled19, 8U);

    /* Outputs for Atomic SubSystem: '<S356>/IfThenElse4' */
    rtb_Switch = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_3, 60, 0);

    /* End of Outputs for SubSystem: '<S356>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S356>/IfThenElse3' */
    rtb_Switch = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2, 50, rtb_Switch);

    /* End of Outputs for SubSystem: '<S356>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S356>/IfThenElse2' */
    rtb_Switch = (uint16_T) Chery_E03_Hp_IfThenElse2
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTM_CycleL11) ||
       (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1), 30, rtb_Switch);

    /* End of Outputs for SubSystem: '<S356>/IfThenElse2' */

    /* SignalConversion: '<S337>/Signal Copy9' incorporates:
     *  Constant: '<S356>/Pump_0%'
     *  Constant: '<S356>/Pump_100%'
     *  Constant: '<S356>/Pump_50%'
     *  Constant: '<S356>/Pump_80%'
     *  Constant: '<S360>/Constant'
     *  Constant: '<S361>/Constant'
     *  Constant: '<S362>/Constant'
     *  Constant: '<S363>/Constant'
     *  Logic: '<S356>/OR2'
     *  RelationalOperator: '<S360>/Compare'
     *  RelationalOperator: '<S361>/Compare'
     *  RelationalOperator: '<S362>/Compare'
     *  RelationalOperator: '<S363>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Bat_Req = rtb_Switch;

    /* SignalConversion: '<S337>/Signal Copy7' incorporates:
     *  Constant: '<S343>/Constant6'
     */
    Chery_E03_Hp_B.u8TWValve_BAT_Req = 100U;

    /* SignalConversion: '<S337>/Signal Copy11' incorporates:
     *  Constant: '<S343>/Constant7'
     */
    Chery_E03_Hp_B.u8HVCH_Req = 0U;

    /* Outputs for Atomic SubSystem: '<S337>/EDC_ACChiller_Control'
     *
     * Block description for '<S337>/EDC_ACChiller_Control':
     *  ACChiller Mode_ EDC Control
     */
    Chery_E03_Hp_EDC_ACChiller_Control();

    /* End of Outputs for SubSystem: '<S337>/EDC_ACChiller_Control' */

    /* Outputs for Atomic SubSystem: '<S337>/EXV_Chiller_Ctrl_ACChiller1'
     *
     * Block description for '<S337>/EXV_Chiller_Ctrl_ACChiller1':
     *  Chiller exv step control
     */
    /* Sum: '<S416>/Subtract' */
    rtb_Sum_i = (int16_T)(Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 -
                          Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10);

    /* Lookup_n-D: '<S413>/1-D Lookup Table' */
    rtb_Saturation = look1_is16lu32n16Ds32_binlcs(rtb_Sum_i, ((int16_T *)
      &(AC_s16ExvStepsOpen_Lv1.AC_s16TBat_In_delta_Lv1_u1[0])), ((int16_T *)
      &(AC_s16ExvStepsOpen_Lv1.AC_s16ExvStepsOpen_Lv1_y[0])), 7U);

    /* Sum: '<S416>/Add2' */
    rtb_Add1_j = (int16_T)(Chery_E03_Hp_B.HpI_s16Teva_Front_A10 -
      Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10);

    /* Outputs for Atomic SubSystem: '<S416>/Delay_2s_L1_Increase' */
    rtb_SignalCopy = ( Chery_E03_Hp_DelayJudge_Cfg(rtb_Add1_j <= 20,
      &Chery_E03_Hp_ConstB.Delay_2s_L1_Increase,
      &Chery_E03_Hp_DW.Delay_2s_L1_Increase, 20) != false);

    /* End of Outputs for SubSystem: '<S416>/Delay_2s_L1_Increase' */

    /* Switch: '<S413>/Switch' incorporates:
     *  Constant: '<S429>/Constant'
     *  Lookup_n-D: '<S413>/1-D Lookup Table1'
     *  RelationalOperator: '<S429>/Compare'
     *  Sum: '<S416>/Add2'
     */
    if (!rtb_SignalCopy) {
      rtb_Saturation = look1_is16lu32n16Ds32_binlcs(rtb_Add1_j, ((int16_T *)
        &(AC_s16ExvStepsClose_Lv1.AC_s16TEva_delta_Lv1_u1[0])), ((int16_T *)
        &(AC_s16ExvStepsClose_Lv1.AC_s16ExvStepsClose_Lv1_y[0])), 7U);
    }

    /* End of Switch: '<S413>/Switch' */

    /* UnitDelay: '<S413>/Unit Delay' */
    rtb_FAN_PWM_Calculatoin_AC_f = Chery_E03_Hp_DW.UnitDelay_DSTATE_j5;

    /* Switch: '<S413>/Switch1' incorporates:
     *  Constant: '<S413>/Constant2'
     *  Constant: '<S423>/Constant'
     *  RelationalOperator: '<S423>/Compare'
     */
    if (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv != u8BTMCOOL_1) {
      rtb_FAN_PWM_Calculatoin_AC_f = u16EXV_CHIL_MIN_0;
    }

    /* End of Switch: '<S413>/Switch1' */

    /* Sum: '<S413>/Add' */
    rtb_Saturation = (int16_T)asr_s32(((int32_T)rtb_Saturation) + ((int32_T)
      rtb_FAN_PWM_Calculatoin_AC_f), 1U);

    /* Switch: '<S424>/Switch' incorporates:
     *  Constant: '<S413>/Constant1'
     *  RelationalOperator: '<S424>/UpperRelop'
     */
    if (rtb_Saturation < 0) {
      rtb_FAN_PWM_Calculatoin_AC_f = 0U;
    } else {
      rtb_FAN_PWM_Calculatoin_AC_f = (uint16_T)((int32_T)(((int32_T)
        rtb_Saturation) * 2));
    }

    /* End of Switch: '<S424>/Switch' */

    /* Switch: '<S424>/Switch2' incorporates:
     *  Constant: '<S413>/L1_Max_Open_Rate'
     *  RelationalOperator: '<S424>/LowerRelop1'
     *  UnitDelay: '<S413>/Unit Delay'
     */
    if (rtb_Saturation > 1250) {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_j5 = 2500U;
    } else {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_j5 = rtb_FAN_PWM_Calculatoin_AC_f;
    }

    /* End of Switch: '<S424>/Switch2' */

    /* Outputs for Atomic SubSystem: '<S416>/Delay_5s' */
    rtb_SignalCopy_o3 = ( Chery_E03_Hp_DelayJudge_Cfg(rtb_Add1_j <= 45,
      &Chery_E03_Hp_ConstB.Delay_5s, &Chery_E03_Hp_DW.Delay_5s, 150) != false);

    /* End of Outputs for SubSystem: '<S416>/Delay_5s' */

    /* Lookup_n-D: '<S414>/1-D Lookup Table' incorporates:
     *  Constant: '<S430>/Constant'
     *  RelationalOperator: '<S430>/Compare'
     *  Sum: '<S416>/Add2'
     */
    rtb_Saturation = look1_is16lu32n16Ds32_binlcs(rtb_Sum_i, ((int16_T *)
      &(AC_s16ExvStepsOpen_Lv2.AC_s16TBat_In_delta_Lv2_u1[0])), ((int16_T *)
      &(AC_s16ExvStepsOpen_Lv2.AC_s16ExvStepsOpen_Lv2_y[0])), 7U);

    /* Switch: '<S414>/Switch1' incorporates:
     *  Lookup_n-D: '<S414>/1-D Lookup Table1'
     *  Sum: '<S416>/Add2'
     */
    if (!rtb_SignalCopy_o3) {
      rtb_Saturation = look1_is16lu32n16Ds32_binlcs(rtb_Add1_j, ((int16_T *)
        &(AC_s16ExvStepsClose_Lv2.AC_s16TEva_delta_Lv2_u1[0])), ((int16_T *)
        &(AC_s16ExvStepsClose_Lv2.AC_s16ExvStepsClose_Lv2_y[0])), 7U);
    }

    /* End of Switch: '<S414>/Switch1' */

    /* UnitDelay: '<S414>/Unit Delay' */
    rtb_FAN_PWM_Calculatoin_AC_f = Chery_E03_Hp_DW.UnitDelay_DSTATE_m;

    /* Switch: '<S414>/Switch2' incorporates:
     *  Constant: '<S414>/Constant2'
     *  Constant: '<S425>/Constant'
     *  RelationalOperator: '<S425>/Compare'
     */
    if (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv != u8BTMCOOL_2) {
      rtb_FAN_PWM_Calculatoin_AC_f = 0U;
    }

    /* End of Switch: '<S414>/Switch2' */

    /* Sum: '<S414>/Add' */
    rtb_Add1_j = (int16_T)(rtb_Saturation + ((int16_T)
      rtb_FAN_PWM_Calculatoin_AC_f));

    /* Switch: '<S426>/Switch' incorporates:
     *  Constant: '<S414>/Constant1'
     *  RelationalOperator: '<S426>/UpperRelop'
     */
    if (rtb_Add1_j < 0) {
      rtb_FAN_PWM_Calculatoin_AC_f = 0U;
    } else {
      rtb_FAN_PWM_Calculatoin_AC_f = (uint16_T)rtb_Add1_j;
    }

    /* End of Switch: '<S426>/Switch' */

    /* Switch: '<S426>/Switch2' incorporates:
     *  Constant: '<S414>/Constant'
     *  RelationalOperator: '<S426>/LowerRelop1'
     *  UnitDelay: '<S414>/Unit Delay'
     */
    if (rtb_Add1_j > 2800) {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_m = 2800U;
    } else {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_m = rtb_FAN_PWM_Calculatoin_AC_f;
    }

    /* End of Switch: '<S426>/Switch2' */

    /* Product: '<S415>/Divide1' incorporates:
     *  Constant: '<S415>/Constant3'
     */
    rtb_Sum2 = 3800 * ((int32_T)u16AMP_100);

    /* Saturate: '<S415>/Saturation' */
    if (rtb_Sum_i > 200) {
      rtb_Saturation = 200;
    } else if (rtb_Sum_i < -150) {
      rtb_Saturation = -150;
    } else {
      rtb_Saturation = rtb_Sum_i;
    }

    /* End of Saturate: '<S415>/Saturation' */

    /* Product: '<S415>/Product' incorporates:
     *  Lookup_n-D: '<S415>/ExvLv3Kp'
     */
    rtb_Switch_oe = ((int32_T)rtb_Saturation) * ((int32_T)
      look1_is16lu32n16Ds32_binlcs(rtb_Sum_i, ((int16_T *)
      &(AC_s16ExvCtrl_Kp_Lv3.AC_s16TBatIn_Delta_Lv3_u1[0])), ((int16_T *)
      &(AC_s16ExvCtrl_Kp_Lv3.AC_s16ExvCtrl_Kp_Lv3_y[0])), 9U));

    /* Switch: '<S415>/Switch' incorporates:
     *  Constant: '<S415>/Constant'
     *  Constant: '<S427>/Constant'
     *  RelationalOperator: '<S427>/Compare'
     */
    if (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv != u8BTMCOOL_3) {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_ks = 0;
    }

    /* End of Switch: '<S415>/Switch' */

    /* Sum: '<S415>/Add' incorporates:
     *  Lookup_n-D: '<S415>/ExvL3Ki'
     *  Product: '<S415>/Product1'
     *  Sum: '<S415>/Add1'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_ks += (((int32_T)
      look1_is16lu32n16Ds32_binlcs(rtb_Sum_i, ((int16_T *)
      &(AC_s16ExvCtrl_Ki_Lv3.AC_s16TBatIn_Delta_Lv3_u1[0])), ((int16_T *)
      &(AC_s16ExvCtrl_Ki_Lv3.AC_s16ExvCtrl_Ki_Lv3_y[0])), 9U)) * ((int32_T)
      rtb_Sum_i)) + rtb_Switch_oe;

    /* Switch: '<S428>/Switch' incorporates:
     *  RelationalOperator: '<S428>/UpperRelop'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_ks < 0) {
      rtb_Divide = 0;
    } else {
      rtb_Divide = Chery_E03_Hp_DW.UnitDelay_DSTATE_ks;
    }

    /* End of Switch: '<S428>/Switch' */

    /* Switch: '<S428>/Switch2' incorporates:
     *  RelationalOperator: '<S428>/LowerRelop1'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_ks <= rtb_Sum2) {
      rtb_Sum2 = rtb_Divide;
    }

    /* End of Switch: '<S428>/Switch2' */

    /* Product: '<S415>/Divide' incorporates:
     *  Constant: '<S415>/Constant2'
     */
    rtb_Divide = div_nde_s32_floor(rtb_Sum2, (int32_T)u16AMP_100);

    /* Outputs for Atomic SubSystem: '<S345>/Chiller EXV Output Management' */
    /* Sum: '<S412>/Add' incorporates:
     *  Constant: '<S412>/Constant'
     *  UnitDelay: '<S412>/Unit Delay'
     */
    rtb_Saturation = (int16_T)asr_s32(((int32_T)
      Chery_E03_Hp_DW.UnitDelay_DSTATE_o) + 5, 1U);

    /* Switch: '<S412>/Switch3' incorporates:
     *  Constant: '<S412>/Constant5'
     *  Constant: '<S418>/Constant'
     *  RelationalOperator: '<S418>/Compare'
     *  UnitDelay: '<S414>/Unit Delay'
     */
    if (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2) {
      rtb_Switch = Chery_E03_Hp_DW.UnitDelay_DSTATE_m;
    } else {
      rtb_Switch = u16EXV_CHIL_MIN_0;
    }

    /* End of Switch: '<S412>/Switch3' */

    /* Switch: '<S412>/Switch2' incorporates:
     *  Constant: '<S417>/Constant'
     *  RelationalOperator: '<S417>/Compare'
     *  UnitDelay: '<S413>/Unit Delay'
     */
    if (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1) {
      rtb_Switch = Chery_E03_Hp_DW.UnitDelay_DSTATE_j5;
    }

    /* End of Switch: '<S412>/Switch2' */

    /* Switch: '<S412>/Switch1' incorporates:
     *  Constant: '<S412>/Constant4'
     *  Constant: '<S419>/Constant'
     *  Constant: '<S421>/Constant'
     *  Logic: '<S412>/OR'
     *  RelationalOperator: '<S419>/Compare'
     *  RelationalOperator: '<S421>/Compare'
     */
    if ((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_AC_1) ||
        (Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 < 50)) {
      rtb_Switch = u16EXV_CHIL_MIN_0;
    }

    /* End of Switch: '<S412>/Switch1' */

    /* Sum: '<S412>/Add1' incorporates:
     *  Constant: '<S412>/Constant1'
     *  UnitDelay: '<S412>/Unit Delay'
     */
    rtb_Add1_j = (int16_T)asr_s32(((int32_T)Chery_E03_Hp_DW.UnitDelay_DSTATE_o)
      - 3, 1U);

    /* Switch: '<S422>/Switch' incorporates:
     *  RelationalOperator: '<S422>/UpperRelop'
     */
    if (((int32_T)rtb_Switch) < (((int32_T)rtb_Add1_j) * 2)) {
      rtb_Sum_i = (int16_T)(rtb_Add1_j * 2);
    } else {
      rtb_Sum_i = (int16_T)rtb_Switch;
    }

    /* End of Switch: '<S422>/Switch' */

    /* Switch: '<S422>/Switch2' incorporates:
     *  RelationalOperator: '<S422>/LowerRelop1'
     */
    if (((int32_T)rtb_Switch) > (((int32_T)rtb_Saturation) * 2)) {
      rtb_Sum_i = (int16_T)(rtb_Saturation * 2);
    }

    /* End of Switch: '<S422>/Switch2' */

    /* Switch: '<S412>/Switch' incorporates:
     *  Constant: '<S420>/Constant'
     *  RelationalOperator: '<S420>/Compare'
     *  Saturate: '<S415>/Saturation2'
     */
    if (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv != u8BTMCOOL_3) {
      rtb_Switch = (uint16_T)rtb_Sum_i;
    } else {
      if (rtb_Divide > 3800) {
        /* Saturate: '<S415>/Saturation2' */
        rtb_Divide = 3800;
      } else {
        if (rtb_Divide < 0) {
          /* Saturate: '<S415>/Saturation2' */
          rtb_Divide = 0;
        }
      }

      rtb_Switch = (uint16_T)rtb_Divide;
    }

    /* End of Switch: '<S412>/Switch' */

    /* Saturate: '<S412>/Saturation' */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_o = rtb_Switch;
    if (((int32_T)Chery_E03_Hp_DW.UnitDelay_DSTATE_o) >= 5760) {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_o = 5760U;
    }

    /* End of Saturate: '<S412>/Saturation' */
    /* End of Outputs for SubSystem: '<S345>/Chiller EXV Output Management' */

    /* Sum: '<S415>/Add2' incorporates:
     *  UnitDelay: '<S415>/Unit Delay'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_ks = rtb_Sum2 - rtb_Switch_oe;

    /* Outputs for Atomic SubSystem: '<S345>/Chiller EXV Output Management' */
    /* SignalConversion: '<S337>/Signal Copy2' incorporates:
     *  Constant: '<S412>/Constant2'
     *  Product: '<S412>/Product'
     *  UnitDelay: '<S412>/Unit Delay'
     */
    Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = (uint16_T)(((uint32_T)
      Chery_E03_Hp_DW.UnitDelay_DSTATE_o) / ((uint32_T)u8AMP_10));

    /* End of Outputs for SubSystem: '<S345>/Chiller EXV Output Management' */
    /* End of Outputs for SubSystem: '<S337>/EXV_Chiller_Ctrl_ACChiller1' */

    /* SignalConversion: '<S337>/Signal Copy' */
    Chery_E03_Hp_B.u16Ncomp_Rpm_Req = Chery_E03_Hp_B.AC_u16Ncomp_Rpm_AC;

    /* Outputs for Atomic SubSystem: '<S337>/EXV_Eva_Ctrl'
     *
     * Block description for '<S337>/EXV_Eva_Ctrl':
     *  Chiller exv step control
     */
    /* Outputs for Atomic SubSystem: '<S346>/AC_Mode_Exv_PI'
     *
     * Block description for '<S346>/AC_Mode_Exv_PI':
     *  Chiller mode exv position PI
     */
    /* Sum: '<S442>/Subtract' incorporates:
     *  Constant: '<S442>/Constant1'
     */
    rtb_Saturation = (int16_T)(((int16_T)Chery_E03_Hp_B.Hp_u16SH_CompInlet) - 50);

    /* Saturate: '<S442>/Saturation' */
    if (rtb_Saturation > 150) {
      rtb_Saturation = 150;
    } else {
      if (rtb_Saturation < -150) {
        rtb_Saturation = -150;
      }
    }

    /* End of Saturate: '<S442>/Saturation' */

    /* Outputs for Atomic SubSystem: '<S346>/AC_EXV_Forward'
     *
     * Block description for '<S346>/AC_EXV_Forward':
     *  chiller edc rpm forward
     */
    /* Sum: '<S442>/Add3' incorporates:
     *  Constant: '<S442>/Constant'
     *  Lookup_n-D: '<S441>/EXV_Eva_Estimation'
     *  Lookup_n-D: '<S442>/SH_KP1'
     *  Product: '<S442>/Product'
     *  Product: '<S442>/Product1'
     */
    rtb_Switch_oe = ((int32_T)((uint32_T)(((uint32_T)
      look2_is16u16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
      Chery_E03_Hp_B.HpI_u16Ncomp, ((int16_T *)
      &(u16EXV_Eva_Pos_AC_Est.s16Tamb_Common2_u1[0])), ((uint16_T *)
      &(u16EXV_Eva_Pos_AC_Est.u16Ncomp_RPM_u2[0])), ((uint16_T *)
      &(u16EXV_Eva_Pos_AC_Est.u16EXV_Eva_Pos_AC_Est_y[0])),
      Chery_E03_Hp_ConstP.pooled17, 10U)) * ((uint32_T)u16AMP_10000)))) +
      (((int32_T)look1_is16lu32n16tu16_binlcse(rtb_Saturation, ((int16_T *)
          &(u16Chil_EXV_Kp.s16Chil_Exv_SH_delta[0])), ((uint16_T *)
          &(u16Chil_EXV_Kp.u16Chil_EXV_Kp_y[0])), 7U)) * ((int32_T)
        rtb_Saturation));

    /* End of Outputs for SubSystem: '<S346>/AC_EXV_Forward' */

    /* UnitDelay: '<S442>/Unit Delay' */
    rtb_Sum2 = Chery_E03_Hp_DW.UnitDelay_DSTATE_h;

    /* Saturate: '<S442>/Saturation2' incorporates:
     *  UnitDelay: '<S442>/Unit Delay'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_h > 4000000) {
      rtb_Sum2 = 4000000;
    } else {
      if (Chery_E03_Hp_DW.UnitDelay_DSTATE_h < -1200000) {
        rtb_Sum2 = -1200000;
      }
    }

    /* End of Saturate: '<S442>/Saturation2' */

    /* Sum: '<S442>/Add1' incorporates:
     *  Lookup_n-D: '<S442>/SH_Ki'
     *  Product: '<S442>/Product2'
     *  Sum: '<S442>/Add2'
     */
    rtb_Sum2 += (((int32_T)look1_is16lu32n16Ds32_binlcs(rtb_Saturation,
      ((int16_T *)&(s16Chil_EXV_Ki.s16Chil_Exv_SH_delta[0])), ((int16_T *)
      &(s16Chil_EXV_Ki.s16Chil_EXV_Ki_y[0])), 7U)) * ((int32_T)rtb_Saturation))
      + rtb_Switch_oe;

    /* Sum: '<S442>/Add4' incorporates:
     *  UnitDelay: '<S442>/Unit Delay'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_h = rtb_Sum2 - rtb_Switch_oe;

    /* Product: '<S442>/Divide' incorporates:
     *  Constant: '<S442>/Constant2'
     */
    rtb_Switch_oe = div_nde_s32_floor(rtb_Sum2, (int32_T)u16AMP_10000);

    /* Saturate: '<S442>/Saturation1' */
    if (rtb_Switch_oe > 576) {
      rtb_Switch_oe = 576;
    } else {
      if (rtb_Switch_oe < 0) {
        rtb_Switch_oe = 0;
      }
    }

    /* End of Saturate: '<S442>/Saturation1' */
    /* End of Outputs for SubSystem: '<S346>/AC_Mode_Exv_PI' */
    /* End of Outputs for SubSystem: '<S337>/EXV_Eva_Ctrl' */

    /* SignalConversion: '<S337>/Signal Copy1' */
    Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = (uint16_T)rtb_Switch_oe;

    /* SignalConversion: '<S337>/Signal Copy3' incorporates:
     *  Constant: '<S347>/AGS_100_Open'
     */
    Chery_E03_Hp_B.u8AGS_Position_Req = 100U;

    /* SignalConversion: '<S337>/Signal Copy4' incorporates:
     *  DataTypeConversion: '<S347>/Data Type Conversion'
     *  DataTypeConversion: '<S347>/Data Type Conversion1'
     *  Lookup_n-D: '<S347>/FAN_PWM_Calculatoin_AC'
     */
    Chery_E03_Hp_B.u8FRFAN_PWM_Req = (uint8_T)look2_iu16lu32n16_binlcse
      ((uint16_T)Chery_E03_Hp_B.HpI_u8VehSpd,
       Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10, ((uint16_T *)
        &(AC_u16PWM_FAN_AC.AC_u16Vspd_FAN_u1[0])), ((uint16_T *)
        &(AC_u16PWM_FAN_AC.AC_u16Prco_FAN_u2[0])), ((uint16_T *)
        &(AC_u16PWM_FAN_AC.AC_u16PWM_FAN_AC_y[0])), Chery_E03_Hp_ConstP.pooled15,
       7U);

    /* SignalConversion: '<S337>/Signal Copy12' incorporates:
     *  Constant: '<S348>/SOV_Open'
     */
    Chery_E03_Hp_B.bSOV_Eva_Req = bSOV_OPEN_1 ? 1U : 0U;

    /* SignalConversion: '<S337>/Signal Copy13' incorporates:
     *  Constant: '<S348>/SOV_Close'
     */
    Chery_E03_Hp_B.bSOV_OutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* SignalConversion: '<S337>/Signal Copy14' incorporates:
     *  Constant: '<S348>/SOV_Close_1'
     */
    Chery_E03_Hp_B.bSOV_TXVOutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* End of Outputs for SubSystem: '<S40>/ACChiller_mode' */
    break;

   case 2:
    if (Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S40>/Chiller_Mode' incorporates:
       *  ActionPort: '<S338>/Action Port'
       *
       * Block description for '<S40>/Chiller_Mode':
       *  chiller mode control
       */
      /* SystemReset for Atomic SubSystem: '<S338>/EDC_Rpm_CHil_Ctrl'
       *
       * Block description for '<S338>/EDC_Rpm_CHil_Ctrl':
       *  chiller mode edc rpm control
       */
      /* SystemReset for SwitchCase: '<S40>/Switch Case' incorporates:
       *  Chart: '<S470>/Chiller_edc_management'
       *  UnitDelay: '<S474>/Unit Delay1'
       *  UnitDelay: '<S474>/Unit Delay2'
       *  UnitDelay: '<S501>/Unit Delay'
       */
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_c = 0;
      Chery_E03_Hp_DW.UnitDelay2_DSTATE = 0;

      /* SystemReset for Atomic SubSystem: '<S444>/Chiller_EDC_Start_Configulation'
       *
       * Block description for '<S444>/Chiller_EDC_Start_Configulation':
       *  edc startup condition judge
       */
      Chery_E03_Hp_Chiller_EDC_Start_Configulation_k_Reset();

      /* End of SystemReset for SubSystem: '<S444>/Chiller_EDC_Start_Configulation' */

      /* SystemReset for Atomic SubSystem: '<S472>/Chiller_Risk_corrector'
       *
       * Block description for '<S472>/Chiller_Risk_corrector':
       *  chiller mode risk value for EDC rpm compensation
       */
      Chery_E03_Hp_Chiller_Risk_corrector_o_Reset();

      /* End of SystemReset for SubSystem: '<S472>/Chiller_Risk_corrector' */
      Chery_E03_Hp_Chiller_edc_management_Reset(&rtb_s32NcompChil_Ctrl_Rpm,
        &Chery_E03_Hp_DW.sf_Chiller_edc_management_d);

      /* End of SystemReset for SubSystem: '<S338>/EDC_Rpm_CHil_Ctrl' */

      /* SystemReset for Atomic SubSystem: '<S338>/EXV_Step_Chiller_Ctrl'
       *
       * Block description for '<S338>/EXV_Step_Chiller_Ctrl':
       *  chiller mode exv step control
       */
      /* SystemReset for Atomic SubSystem: '<S446>/Chiller_Exv_PI'
       *
       * Block description for '<S446>/Chiller_Exv_PI':
       *  Chiller mode exv position PI
       */
      /* SystemReset for Atomic SubSystem: '<S500>/ChilExvPICal1' */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_k = 0;

      /* End of SystemReset for SubSystem: '<S500>/ChilExvPICal1' */
      /* End of SystemReset for SubSystem: '<S446>/Chiller_Exv_PI' */
      /* End of SystemReset for SubSystem: '<S338>/EXV_Step_Chiller_Ctrl' */
      /* End of SystemReset for SubSystem: '<S40>/Chiller_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S40>/Chiller_Mode' incorporates:
     *  ActionPort: '<S338>/Action Port'
     *
     * Block description for '<S40>/Chiller_Mode':
     *  chiller mode control
     */
    /* Outputs for Atomic SubSystem: '<S443>/IfThenElse' */
    rtb_Conversion_k = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTM_CycleL11) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_ACCHILLER_2), 0, 100);

    /* End of Outputs for SubSystem: '<S443>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S443>/IfThenElse1' */
    rtb_Conversion_a = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.Conversion_p <= 200) && (Chery_E03_Hp_B.bBTM_CoolReq_Yes),
       50, 0);

    /* End of Outputs for SubSystem: '<S443>/IfThenElse1' */

    /* SignalConversion: '<S338>/Signal Copy6' incorporates:
     *  Constant: '<S443>/Constant'
     *  Constant: '<S443>/Constant1'
     *  Constant: '<S443>/Constant2'
     *  Constant: '<S443>/Constant3'
     *  Constant: '<S449>/Constant'
     *  Constant: '<S450>/Constant'
     *  Constant: '<S451>/Constant'
     *  Logic: '<S443>/OR'
     *  Logic: '<S443>/OR1'
     *  RelationalOperator: '<S449>/Compare'
     *  RelationalOperator: '<S450>/Compare'
     *  RelationalOperator: '<S451>/Compare'
     */
    Chery_E03_Hp_B.u8TWValve_LTR_Req = 0U;

    /* Outputs for Atomic SubSystem: '<S443>/IfThenElse2' */
    /* SignalConversion: '<S338>/Signal Copy10' incorporates:
     *  Constant: '<S443>/Constant4'
     *  Constant: '<S443>/Constant5'
     *  Constant: '<S452>/Constant'
     *  RelationalOperator: '<S452>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Motor_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((int32_T)Chery_E03_Hp_B.HpI_u8Mot_CoolLv) == 1, 100, 0);

    /* End of Outputs for SubSystem: '<S443>/IfThenElse2' */

    /* SignalConversion: '<S338>/Signal Copy5' incorporates:
     *  Lookup_n-D: '<S443>/HVCH_3Way_Valve'
     */
    Chery_E03_Hp_B.u8TWValve_HC_Req = look2_is16lu16n8tu8_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req,
       ((int16_T *)&(HP_u8TWV_HVCH_AC.HP_s16Tamb_AC_u1[0])), ((int16_T *)
        &(HP_u8TWV_HVCH_AC.HP_s16Twater_Req_Cmf_u2[0])), ((uint8_T *)
        &(HP_u8TWV_HVCH_AC.HP_u8TWV_HVCH_AC_y[0])), Chery_E03_Hp_ConstP.pooled18,
       8U);

    /* Lookup_n-D: '<S443>/Pump_HVCH_Req' incorporates:
     *  Sum: '<S443>/Sum'
     */
    rtb_FAN_PWM_Calculatoin_AC_p = look2_is16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, (int16_T)
       (Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 - Chery_E03_Hp_B.HpI_s16Tamb_A10),
       ((int16_T *)&(HP_u16Pump_HVCH_AC.HP_s16Tamb_AC_u1[0])), ((int16_T *)
        &(HP_u16Pump_HVCH_AC.HP_s16TDelta_Wat_Amb_u2[0])), ((uint16_T *)
        &(HP_u16Pump_HVCH_AC.HP_u16Pump_HVCH_AC_y[0])),
       Chery_E03_Hp_ConstP.pooled19, 8U);

    /* SignalConversion: '<S338>/Signal Copy8' */
    Chery_E03_Hp_B.u16Pump_HVCH_Req = rtb_FAN_PWM_Calculatoin_AC_p;

    /* Outputs for Atomic SubSystem: '<S456>/IfThenElse4' */
    rtb_FAN_PWM_Calculatoin_AC_p = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_3, 70, 0);

    /* End of Outputs for SubSystem: '<S456>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S456>/IfThenElse3' */
    rtb_FAN_PWM_Calculatoin_AC_p = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2, 60,
       rtb_FAN_PWM_Calculatoin_AC_p);

    /* End of Outputs for SubSystem: '<S456>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S456>/IfThenElse2' */
    rtb_FAN_PWM_Calculatoin_AC_p = (uint16_T) Chery_E03_Hp_IfThenElse2
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTM_CycleL11) ||
       (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1), 50,
       rtb_FAN_PWM_Calculatoin_AC_p);

    /* End of Outputs for SubSystem: '<S456>/IfThenElse2' */

    /* SignalConversion: '<S338>/Signal Copy9' incorporates:
     *  Constant: '<S456>/Pump_0%'
     *  Constant: '<S456>/Pump_100%'
     *  Constant: '<S456>/Pump_50%'
     *  Constant: '<S456>/Pump_80%'
     *  Constant: '<S460>/Constant'
     *  Constant: '<S461>/Constant'
     *  Constant: '<S462>/Constant'
     *  Constant: '<S463>/Constant'
     *  Logic: '<S456>/OR2'
     *  RelationalOperator: '<S460>/Compare'
     *  RelationalOperator: '<S461>/Compare'
     *  RelationalOperator: '<S462>/Compare'
     *  RelationalOperator: '<S463>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Bat_Req = rtb_FAN_PWM_Calculatoin_AC_p;

    /* SignalConversion: '<S338>/Signal Copy7' incorporates:
     *  Constant: '<S443>/Constant6'
     */
    Chery_E03_Hp_B.u8TWValve_BAT_Req = 100U;

    /* SignalConversion: '<S338>/Signal Copy11' incorporates:
     *  Constant: '<S443>/Constant7'
     */
    Chery_E03_Hp_B.u8HVCH_Req = 0U;

    /* Outputs for Atomic SubSystem: '<S338>/EDC_Rpm_CHil_Ctrl'
     *
     * Block description for '<S338>/EDC_Rpm_CHil_Ctrl':
     *  chiller mode edc rpm control
     */
    /* Outputs for Atomic SubSystem: '<S444>/Chiller_EDC_Start_Configulation'
     *
     * Block description for '<S444>/Chiller_EDC_Start_Configulation':
     *  edc startup condition judge
     */
    Chery_E03_Hp_Chiller_EDC_Start_Configulation_b();

    /* End of Outputs for SubSystem: '<S444>/Chiller_EDC_Start_Configulation' */

    /* Outputs for Atomic SubSystem: '<S471>/ChilPIparameters'
     *
     * Block description for '<S471>/ChilPIparameters':
     *  get chiller Kp ki and delt_T
     */
    Chery_E03_Hp_ChilPIparameters_p();

    /* End of Outputs for SubSystem: '<S471>/ChilPIparameters' */

    /* Saturate: '<S477>/Saturation1' */
    if (Chery_E03_Hp_B.s16Twat_Ctrl_delt > 200) {
      rtb_Sum_i = 200;
    } else if (Chery_E03_Hp_B.s16Twat_Ctrl_delt < -200) {
      rtb_Sum_i = -200;
    } else {
      rtb_Sum_i = Chery_E03_Hp_B.s16Twat_Ctrl_delt;
    }

    /* End of Saturate: '<S477>/Saturation1' */

    /* Product: '<S477>/Product1' */
    rtb_Sum2 = ((int32_T)rtb_Sum_i) * ((int32_T)
      Chery_E03_Hp_B.u16Ncomp_PrcoRisk_e);

    /* Sum: '<S477>/Add' incorporates:
     *  Product: '<S477>/Product2'
     *  UnitDelay: '<S474>/Unit Delay1'
     */
    rtb_Switch_oe = (rtb_Sum2 + (((int32_T)rtb_Sum_i) * ((int32_T)
      Chery_E03_Hp_B.u16Ncomp_Tout_Risk))) + Chery_E03_Hp_DW.UnitDelay1_DSTATE_c;

    /* Outputs for Atomic SubSystem: '<S472>/Chiller_Risk_corrector'
     *
     * Block description for '<S472>/Chiller_Risk_corrector':
     *  chiller mode risk value for EDC rpm compensation
     */
    Chery_E03_Hp_Chiller_Risk_corrector_g();

    /* End of Outputs for SubSystem: '<S472>/Chiller_Risk_corrector' */

    /* Switch: '<S478>/Switch' incorporates:
     *  Constant: '<S478>/Constant'
     *  Constant: '<S480>/Constant'
     *  Product: '<S478>/Multiply'
     *  RelationalOperator: '<S480>/Compare'
     *  Sum: '<S478>/Subtract1'
     */
    if (Chery_E03_Hp_B.bChilRisk_Comp != bFAIL_NO_RISK_0) {
      /* MinMax: '<S478>/Max' incorporates:
       *  UnitDelay: '<S474>/Unit Delay2'
       */
      if (rtb_Switch_oe >= Chery_E03_Hp_DW.UnitDelay2_DSTATE) {
        rtb_Switch_oe = Chery_E03_Hp_DW.UnitDelay2_DSTATE;
      }

      /* End of MinMax: '<S478>/Max' */
      rtb_Switch_oe -= (int32_T)((uint32_T)(((uint32_T)
        Chery_E03_Hp_B.u16Ncompchil_Reduce_Risk) * ((uint32_T)u16AMP_10)));
    }

    /* End of Switch: '<S478>/Switch' */

    /* Chart: '<S470>/Chiller_edc_management' */
    Chery_E03_Hp_Chiller_edc_management(Chery_E03_Hp_B.bChil_EDC_Config,
      rtb_Switch_oe, &rtb_s32NcompChil_Ctrl_Rpm,
      &Chery_E03_Hp_DW.sf_Chiller_edc_management_d);

    /* Sum: '<S474>/Sum1' incorporates:
     *  Constant: '<S474>/Constant'
     *  UnitDelay: '<S474>/Unit Delay2'
     */
    rtb_Divide = Chery_E03_Hp_DW.UnitDelay2_DSTATE + s32NCOMP_UP_SPD;

    /* Switch: '<S474>/Switch1' incorporates:
     *  Constant: '<S474>/Constant2'
     *  Constant: '<S495>/Constant'
     *  Constant: '<S496>/Constant'
     *  Logic: '<S474>/AND'
     *  MinMax: '<S474>/Min'
     *  RelationalOperator: '<S495>/Compare'
     *  RelationalOperator: '<S496>/Compare'
     */
    if ((rtb_s32NcompChil_Ctrl_Rpm < s32NCOMP_DOWN_LIMIT) &&
        (rtb_s32NcompChil_Ctrl_Rpm > s32NCOMP_DOWN_0)) {
      rtb_Divide = s32NCOMP_DOWN_LIMIT;
    } else {
      if (rtb_s32NcompChil_Ctrl_Rpm < rtb_Divide) {
        /* MinMax: '<S474>/Min' */
        rtb_Divide = rtb_s32NcompChil_Ctrl_Rpm;
      }
    }

    /* End of Switch: '<S474>/Switch1' */

    /* Switch: '<S474>/Switch2' incorporates:
     *  Constant: '<S474>/Constant3'
     *  Constant: '<S497>/Constant'
     *  RelationalOperator: '<S497>/Compare'
     */
    if (rtb_s32NcompChil_Ctrl_Rpm == s32NCOMP_DOWN_0) {
      rtb_Divide = s32NCOMP_DOWN_0;
    }

    /* End of Switch: '<S474>/Switch2' */

    /* Product: '<S474>/Product1' incorporates:
     *  Constant: '<S474>/Constant4'
     */
    rtb_Switch_oe = (int32_T)((uint32_T)(((uint32_T)
      Chery_E03_Hp_B.HpI_u16Ncomp_Max) * ((uint32_T)u8AMP_10)));

    /* RelationalOperator: '<S498>/LowerRelop1' incorporates:
     *  Product: '<S474>/Product1'
     */
    rtb_LowerRelop1_a = (rtb_Divide > rtb_Switch_oe);

    /* Switch: '<S498>/Switch' incorporates:
     *  Constant: '<S474>/Constant8'
     *  RelationalOperator: '<S498>/UpperRelop'
     */
    if (rtb_Divide < s32NCOMP_DOWN_0) {
      rtb_Divide = s32NCOMP_DOWN_0;
    }

    /* End of Switch: '<S498>/Switch' */

    /* Switch: '<S498>/Switch2' */
    if (!rtb_LowerRelop1_a) {
      rtb_Switch_oe = rtb_Divide;
    }

    /* End of Switch: '<S498>/Switch2' */

    /* Sum: '<S474>/Sum2' */
    rtb_Sum2 = rtb_Switch_oe - rtb_Sum2;

    /* Saturate: '<S474>/Saturation1' */
    if (rtb_Sum2 > 50000) {
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_c = 50000;
    } else if (rtb_Sum2 < 0) {
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_c = 0;
    } else {
      Chery_E03_Hp_DW.UnitDelay1_DSTATE_c = rtb_Sum2;
    }

    /* End of Saturate: '<S474>/Saturation1' */

    /* Lookup_n-D: '<S474>/2-D Lookup Table' */
    rtb_FAN_PWM_Calculatoin_AC_p = look2_is16u16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10,
       ((int16_T *)&(u16ACMode_EdcRamp.s16TambEdcRamp_u1[0])), ((uint16_T *)
        &(u16ACMode_EdcRamp.u16Prco_ACMode_u2[0])), ((uint16_T *)
        &(u16ACMode_EdcRamp.u16ACMode_EdcRamp_y[0])),
       Chery_E03_Hp_ConstP.pooled16, 6U);

    /* Sum: '<S474>/Subtract' incorporates:
     *  UnitDelay: '<S474>/Unit Delay2'
     */
    rtb_Divide = Chery_E03_Hp_DW.UnitDelay2_DSTATE + ((int32_T)
      rtb_FAN_PWM_Calculatoin_AC_p);

    /* MinMax: '<S474>/Min3' */
    if (rtb_Switch_oe < rtb_Divide) {
      Chery_E03_Hp_DW.UnitDelay2_DSTATE = rtb_Switch_oe;
    } else {
      Chery_E03_Hp_DW.UnitDelay2_DSTATE = rtb_Divide;
    }

    /* End of MinMax: '<S474>/Min3' */

    /* Product: '<S474>/Product' incorporates:
     *  Constant: '<S474>/Constant1'
     *  UnitDelay: '<S474>/Unit Delay2'
     */
    Chery_E03_Hp_B.u16Ncomp_Rpm_Req = (uint16_T)((int32_T)
      (Chery_E03_Hp_DW.UnitDelay2_DSTATE / ((int32_T)u8AMP_10)));

    /* End of Outputs for SubSystem: '<S338>/EDC_Rpm_CHil_Ctrl' */

    /* Outputs for Atomic SubSystem: '<S338>/EXV_Step_Chiller_Ctrl'
     *
     * Block description for '<S338>/EXV_Step_Chiller_Ctrl':
     *  chiller mode exv step control
     */
    /* Outputs for Atomic SubSystem: '<S446>/Chiller_Exv_PI'
     *
     * Block description for '<S446>/Chiller_Exv_PI':
     *  Chiller mode exv position PI
     */
    /* Outputs for Atomic SubSystem: '<S500>/ChilExvPICal1' */
    /* Sum: '<S501>/Subtract' incorporates:
     *  Constant: '<S501>/Constant1'
     */
    rtb_Sum_i = (int16_T)(((int16_T)Chery_E03_Hp_B.Hp_u16SH_ChilOut) - 80);

    /* Saturate: '<S501>/Saturation' */
    if (rtb_Sum_i > 150) {
      rtb_Sum_i = 150;
    } else {
      if (rtb_Sum_i < -150) {
        rtb_Sum_i = -150;
      }
    }

    /* End of Saturate: '<S501>/Saturation' */

    /* Lookup_n-D: '<S501>/SH_KP1' */
    rtb_FAN_PWM_Calculatoin_AC_p = look1_is16lu32n16tu16_binlcse(rtb_Sum_i,
      ((int16_T *)&(u16Chil_EXV_Kp.s16Chil_Exv_SH_delta[0])), ((uint16_T *)
      &(u16Chil_EXV_Kp.u16Chil_EXV_Kp_y[0])), 7U);

    /* Product: '<S501>/Product1' */
    rtb_Switch_oe = ((int32_T)rtb_FAN_PWM_Calculatoin_AC_p) * ((int32_T)
      rtb_Sum_i);

    /* Outputs for Atomic SubSystem: '<S446>/Chil_exv_forward'
     *
     * Block description for '<S446>/Chil_exv_forward':
     *  chiller edc rpm forward
     */
    /* Sum: '<S501>/Add3' incorporates:
     *  Constant: '<S501>/Constant'
     *  Lookup_n-D: '<S499>/1-D Lookup Table'
     *  Product: '<S501>/Product'
     */
    rtb_Divide = ((int32_T)((uint32_T)(((uint32_T)look1_iu16lu32n16_binlcse
      (Chery_E03_Hp_B.u16Ncomp_Rpm_Req, Chery_E03_Hp_ConstP.pooled74,
       Chery_E03_Hp_ConstP.pooled73, 8U)) * ((uint32_T)u16AMP_10000)))) +
      rtb_Switch_oe;

    /* End of Outputs for SubSystem: '<S446>/Chil_exv_forward' */

    /* UnitDelay: '<S501>/Unit Delay' */
    rtb_Switch_oe = Chery_E03_Hp_DW.UnitDelay_DSTATE_k;

    /* Saturate: '<S501>/Saturation2' incorporates:
     *  UnitDelay: '<S501>/Unit Delay'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_k > 4000000) {
      rtb_Switch_oe = 4000000;
    } else {
      if (Chery_E03_Hp_DW.UnitDelay_DSTATE_k < -1200000) {
        rtb_Switch_oe = -1200000;
      }
    }

    /* End of Saturate: '<S501>/Saturation2' */

    /* Sum: '<S501>/Add1' incorporates:
     *  Lookup_n-D: '<S501>/SH_Ki'
     *  Product: '<S501>/Product2'
     *  Sum: '<S501>/Add2'
     */
    rtb_Switch_oe += (((int32_T)look1_is16lu32n16Ds32_binlcs(rtb_Sum_i,
      ((int16_T *)&(s16Chil_EXV_Ki.s16Chil_Exv_SH_delta[0])), ((int16_T *)
      &(s16Chil_EXV_Ki.s16Chil_EXV_Ki_y[0])), 7U)) * ((int32_T)rtb_Sum_i)) +
      rtb_Divide;

    /* Product: '<S501>/Divide' incorporates:
     *  Constant: '<S501>/Constant2'
     */
    rtb_Sum2 = div_nde_s32_floor(rtb_Switch_oe, (int32_T)u16AMP_10000);

    /* Lookup_n-D: '<S501>/EXV_Min_According_EDC' */
    rtb_FAN_PWM_Calculatoin_AC_p = look1_iu16bs16lu32n16_binlcse
      (Chery_E03_Hp_B.u16Ncomp_Rpm_Req,
       Chery_E03_Hp_ConstP.EXV_Min_According_EDC_bp01Data,
       Chery_E03_Hp_ConstP.EXV_Min_According_EDC_tableData, 10U);

    /* Switch: '<S502>/Switch' incorporates:
     *  RelationalOperator: '<S502>/UpperRelop'
     */
    if (rtb_Sum2 >= ((int32_T)rtb_FAN_PWM_Calculatoin_AC_p)) {
      rtb_FAN_PWM_Calculatoin_AC_p = (uint16_T)rtb_Sum2;
    }

    /* End of Switch: '<S502>/Switch' */

    /* Switch: '<S502>/Switch2' incorporates:
     *  Constant: '<S501>/Constant3'
     *  RelationalOperator: '<S502>/LowerRelop1'
     */
    if (rtb_Sum2 > 380) {
      Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = 380U;
    } else {
      Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = rtb_FAN_PWM_Calculatoin_AC_p;
    }

    /* End of Switch: '<S502>/Switch2' */

    /* Sum: '<S501>/Add4' incorporates:
     *  Constant: '<S501>/Constant4'
     *  Product: '<S501>/Product3'
     *  UnitDelay: '<S501>/Unit Delay'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_k = ((int32_T)((uint32_T)(((uint32_T)
      Chery_E03_Hp_B.u16EXV_Chil_Pos_Req) * ((uint32_T)u16AMP_10000)))) -
      rtb_Divide;

    /* End of Outputs for SubSystem: '<S500>/ChilExvPICal1' */
    /* End of Outputs for SubSystem: '<S446>/Chiller_Exv_PI' */
    /* End of Outputs for SubSystem: '<S338>/EXV_Step_Chiller_Ctrl' */

    /* SignalConversion: '<S338>/Signal Copy1' incorporates:
     *  Constant: '<S445>/Constant'
     */
    Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = 0U;

    /* SignalConversion: '<S338>/Signal Copy3' incorporates:
     *  Constant: '<S447>/AGS_100_Open'
     */
    Chery_E03_Hp_B.u8AGS_Position_Req = 100U;

    /* DataTypeConversion: '<S447>/Data Type Conversion1' */
    rtb_FAN_PWM_Calculatoin_AC_p = (uint16_T)Chery_E03_Hp_B.HpI_u8VehSpd;

    /* Lookup_n-D: '<S447>/FAN_PWM_Calculatoin_AC' */
    rtb_FAN_PWM_Calculatoin_AC_p = look2_iu16lu32n16_binlcse
      (rtb_FAN_PWM_Calculatoin_AC_p, Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10,
       ((uint16_T *)&(AC_u16PWM_FAN_AC.AC_u16Vspd_FAN_u1[0])), ((uint16_T *)
        &(AC_u16PWM_FAN_AC.AC_u16Prco_FAN_u2[0])), ((uint16_T *)
        &(AC_u16PWM_FAN_AC.AC_u16PWM_FAN_AC_y[0])), Chery_E03_Hp_ConstP.pooled15,
       7U);

    /* SignalConversion: '<S338>/Signal Copy4' incorporates:
     *  DataTypeConversion: '<S447>/Data Type Conversion'
     */
    Chery_E03_Hp_B.u8FRFAN_PWM_Req = (uint8_T)rtb_FAN_PWM_Calculatoin_AC_p;

    /* SignalConversion: '<S338>/Signal Copy12' incorporates:
     *  Constant: '<S448>/SOV_Open'
     */
    Chery_E03_Hp_B.bSOV_Eva_Req = bSOV_OPEN_1 ? 1U : 0U;

    /* SignalConversion: '<S338>/Signal Copy13' incorporates:
     *  Constant: '<S448>/SOV_Close'
     */
    Chery_E03_Hp_B.bSOV_OutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* SignalConversion: '<S338>/Signal Copy14' incorporates:
     *  Constant: '<S448>/SOV_Close_1'
     */
    Chery_E03_Hp_B.bSOV_TXVOutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* End of Outputs for SubSystem: '<S40>/Chiller_Mode' */
    break;

   case 3:
    if (Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* SystemReset for IfAction SubSystem: '<S40>/Total_Dehum_Mode' incorporates:
       *  ActionPort: '<S342>/Action Port'
       *
       * Block description for '<S40>/Total_Dehum_Mode':
       *  AC / AC Chiller mode control
       */
      /* SystemReset for Atomic SubSystem: '<S342>/EDC_TotalDehum_Control'
       *
       * Block description for '<S342>/EDC_TotalDehum_Control':
       *  ACChiller Mode_ EDC Control
       */
      /* SystemReset for SwitchCase: '<S40>/Switch Case' incorporates:
       *  Saturate: '<S1010>/Saturation2'
       *  UnitDelay: '<S1010>/Unit Delay'
       *  UnitDelay: '<S985>/Unit Delay'
       */
      Chery_E03_Hp_EDC_TotalDehum_Control_Reset();

      /* End of SystemReset for SubSystem: '<S342>/EDC_TotalDehum_Control' */

      /* SystemReset for Atomic SubSystem: '<S1018>/Hyster_And_Delay_Judge' */
      Chery_E03_Hp_Hyster_And_Delay_Judge_o_Reset
        (&Chery_E03_Hp_DW.Hyster_And_Delay_Judge_m, Chery_E03_Hp_ConstP.pooled3);

      /* End of SystemReset for SubSystem: '<S1018>/Hyster_And_Delay_Judge' */

      /* SystemReset for Atomic SubSystem: '<S1019>/Hyster_And_Delay_Judge' */
      Chery_E03_Hp_Hyster_And_Delay_Judge_d_Reset
        (&Chery_E03_Hp_DW.Hyster_And_Delay_Judge_h, Chery_E03_Hp_ConstP.pooled3);

      /* End of SystemReset for SubSystem: '<S1019>/Hyster_And_Delay_Judge' */

      /* SystemReset for Atomic SubSystem: '<S342>/EXV_Eva_TotalDehum_Ctrl'
       *
       * Block description for '<S342>/EXV_Eva_TotalDehum_Ctrl':
       *  Chiller exv step control
       */
      /* SystemReset for Atomic SubSystem: '<S910>/Total_DehumMode_EXV'
       *
       * Block description for '<S910>/Total_DehumMode_EXV':
       *  Chiller mode exv position PI
       */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_p = 0;

      /* End of SystemReset for SubSystem: '<S910>/Total_DehumMode_EXV' */
      /* End of SystemReset for SubSystem: '<S342>/EXV_Eva_TotalDehum_Ctrl' */

      /* SystemReset for Atomic SubSystem: '<S342>/EXV_Chiller_Ctrl_TotalDehum'
       *
       * Block description for '<S342>/EXV_Chiller_Ctrl_TotalDehum':
       *  Chiller exv step control
       */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_b = 0;

      /* SystemReset for Atomic SubSystem: '<S986>/Delay_15s' */
      Chery_E03_Hp_DelayJudge_Cfg_Reset(&Chery_E03_Hp_DW.Delay_15s);

      /* End of SystemReset for SubSystem: '<S986>/Delay_15s' */

      /* SystemReset for Atomic SubSystem: '<S986>/Delay_5s' */
      Chery_E03_Hp_DelayJudge_Cfg_Reset(&Chery_E03_Hp_DW.Delay_5s_b);

      /* End of SystemReset for SubSystem: '<S986>/Delay_5s' */
      /* End of SystemReset for SubSystem: '<S342>/EXV_Chiller_Ctrl_TotalDehum' */
      /* End of SystemReset for SubSystem: '<S40>/Total_Dehum_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S40>/Total_Dehum_Mode' incorporates:
     *  ActionPort: '<S342>/Action Port'
     *
     * Block description for '<S40>/Total_Dehum_Mode':
     *  AC / AC Chiller mode control
     */
    /* Outputs for Atomic SubSystem: '<S906>/IfThenElse1' */
    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S906>/AGS_0_Close'
     *  Constant: '<S906>/AGS_100_Open'
     *  Constant: '<S912>/Constant'
     *  RelationalOperator: '<S912>/Compare'
     */
    Chery_E03_Hp_B.u8AGS_Position_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 != u8MODE_TotalDehum_CHIL_6, 100, 0);

    /* End of Outputs for SubSystem: '<S906>/IfThenElse1' */

    /* DataTypeConversion: '<S906>/Data Type Conversion1' */
    rtb_Conversion = (uint16_T)Chery_E03_Hp_B.HpI_u8VehSpd;

    /* Lookup_n-D: '<S906>/FAN_PWM_Calculatoin_HPMode' incorporates:
     *  Sum: '<S906>/Sum'
     */
    rtb_Conversion = look2_iu16s16lu32n16tu16_binlcse(rtb_Conversion, (int16_T)
      (Chery_E03_Hp_B.HpI_s16Tamb_A10 - Chery_E03_Hp_B.R134A_P_a10_T_a10_Table),
      ((uint16_T *)&(AC_u16PWM_FAN_HP.AC_u16Vspd_FAN_u1[0])), ((int16_T *)
      &(AC_u16PWM_FAN_HP.AC_s16T_DeltaExtSat_HP[0])), ((uint16_T *)
      &(AC_u16PWM_FAN_HP.AC_u16PWM_FAN_HP_y[0])), Chery_E03_Hp_ConstP.pooled15,
      7U);

    /* Outputs for Atomic SubSystem: '<S906>/IfThenElse2' */
    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S906>/Front_FAN_Close'
     *  Constant: '<S913>/Constant'
     *  DataTypeConversion: '<S906>/Data Type Conversion'
     *  RelationalOperator: '<S913>/Compare'
     */
    Chery_E03_Hp_B.u8FRFAN_PWM_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 != u8MODE_TotalDehum_CHIL_6, (uint8_T)
       rtb_Conversion, 0);

    /* End of Outputs for SubSystem: '<S906>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S342>/EDC_TotalDehum_Control'
     *
     * Block description for '<S342>/EDC_TotalDehum_Control':
     *  ACChiller Mode_ EDC Control
     */
    Chery_E03_Hp_EDC_TotalDehum_Control();

    /* End of Outputs for SubSystem: '<S342>/EDC_TotalDehum_Control' */

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' */
    Chery_E03_Hp_B.u16Ncomp_Rpm_Req = Chery_E03_Hp_B.AC_u16Ncomp_Rpm_TotalDehum;

    /* Product: '<S1018>/Multiply' incorporates:
     *  Constant: '<S1018>/Constant'
     *  Constant: '<S1018>/Constant1'
     */
    rtb_Switch_oe = div_nde_s32_floor(s32NCOMP_DOWN_LIMIT, (int32_T)u16AMP_10);

    /* Outputs for Atomic SubSystem: '<S1018>/Hyster_And_Delay_Judge' */
    rtb_LowerRelop1_bs = ( Chery_E03_Hp_Hyster_And_Delay_Judge_m((uint16_T)
      ((int32_T)(rtb_Switch_oe + 200)), Chery_E03_Hp_B.HpI_u16Ncomp, (uint16_T)
      ((int32_T)(rtb_Switch_oe + 100)),
      &Chery_E03_Hp_ConstB.Hyster_And_Delay_Judge_m,
      &Chery_E03_Hp_DW.Hyster_And_Delay_Judge_m, Chery_E03_Hp_ConstP.pooled4) !=
                          false);

    /* End of Outputs for SubSystem: '<S1018>/Hyster_And_Delay_Judge' */

    /* Outputs for Atomic SubSystem: '<S1019>/Hyster_And_Delay_Judge' */
    rtb_UpperRelop_d = ( Chery_E03_Hp_Hyster_And_Delay_Judge_h(40, (int16_T)
      (Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10 -
       Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req), 10,
      &Chery_E03_Hp_ConstB.Hyster_And_Delay_Judge_h,
      &Chery_E03_Hp_DW.Hyster_And_Delay_Judge_h, Chery_E03_Hp_ConstP.pooled4) !=
                        false);

    /* End of Outputs for SubSystem: '<S1019>/Hyster_And_Delay_Judge' */

    /* Outputs for Atomic SubSystem: '<S1014>/IfThenElse' */
    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S1014>/Eva_SOV_Close'
     *  Constant: '<S1014>/Eva_SOV_Open'
     *  Constant: '<S1016>/Constant'
     *  Constant: '<S1018>/EDC_RPM_Offset'
     *  Constant: '<S1018>/EDC_RPM_Offset1'
     *  Constant: '<S1019>/Constant'
     *  Constant: '<S1019>/Constant1'
     *  Logic: '<S1014>/OR'
     *  Logic: '<S1014>/OR1'
     *  Logic: '<S1018>/NOT'
     *  RelationalOperator: '<S1016>/Compare'
     *  Sum: '<S1018>/Sum'
     *  Sum: '<S1018>/Sum1'
     *  Sum: '<S1019>/Sum'
     */
    Chery_E03_Hp_B.bSOV_Eva_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((!rtb_LowerRelop1_bs) && rtb_UpperRelop_d) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_TotalDehum_CHIL_6),
       (uint8_T)(bSOV_OPEN_1 ? 1U : 0U), (uint8_T)(bSOV_Close_0 ? 1U : 0U));

    /* End of Outputs for SubSystem: '<S1014>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S342>/EXV_Eva_TotalDehum_Ctrl'
     *
     * Block description for '<S342>/EXV_Eva_TotalDehum_Ctrl':
     *  Chiller exv step control
     */
    /* Outputs for Atomic SubSystem: '<S910>/Total_DehumMode_EXV'
     *
     * Block description for '<S910>/Total_DehumMode_EXV':
     *  Chiller mode exv position PI
     */
    /* Lookup_n-D: '<S1010>/EXV_Eva_max3' */
    rtb_Conversion = look2_is16u16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC,
       ((int16_T *)&(u16SH_Target_TotalDehum.s16Tamb_TotalDehum_u1[0])),
       ((uint16_T *)&(u16SH_Target_TotalDehum.u16_QBlower_HVAC_u2[0])),
       ((uint16_T *)&(u16SH_Target_TotalDehum.u16SH_Target_TotalDehum_y[0])),
       Chery_E03_Hp_ConstP.pooled17, 10U);

    /* Sum: '<S1010>/Subtract' */
    rtb_Sum_i = (int16_T)(((int16_T)Chery_E03_Hp_B.Hp_u16SH_CompInlet) -
                          ((int16_T)rtb_Conversion));

    /* Saturate: '<S1010>/Saturation' */
    if (rtb_Sum_i > 150) {
      rtb_Sum_i = 150;
    } else {
      if (rtb_Sum_i < -150) {
        rtb_Sum_i = -150;
      }
    }

    /* End of Saturate: '<S1010>/Saturation' */

    /* Lookup_n-D: '<S1010>/SH_KP1' */
    rtb_Conversion = look1_is16lu32n16tu16_binlcse(rtb_Sum_i, ((int16_T *)
      &(u16Chil_EXV_Kp.s16Chil_Exv_SH_delta[0])), ((uint16_T *)
      &(u16Chil_EXV_Kp.u16Chil_EXV_Kp_y[0])), 7U);

    /* Outputs for Atomic SubSystem: '<S910>/EXV_Forward_TotalDehum'
     *
     * Block description for '<S910>/EXV_Forward_TotalDehum':
     *  chiller edc rpm forward
     */
    /* Sum: '<S1010>/Add3' incorporates:
     *  Constant: '<S1010>/Constant'
     *  Lookup_n-D: '<S1009>/EXV_Eva_Estimation'
     *  Product: '<S1010>/Product'
     *  Product: '<S1010>/Product1'
     */
    rtb_Switch_oe = ((int32_T)((uint32_T)(((uint32_T)
      look2_is16u16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
      Chery_E03_Hp_B.HpI_u16Ncomp, ((int16_T *)
      &(u16EXV_EvaCDS_Est_TDEDC.s16Tamb_TotalDehum_u1[0])), ((uint16_T *)
      &(u16EXV_EvaCDS_Est_TDEDC.u16Ncomp_RPM_EXV[0])), ((uint16_T *)
      &(u16EXV_EvaCDS_Est_TDEDC.u16EXV_EvaCDS_Est_TDEDC_y[0])),
      Chery_E03_Hp_ConstP.pooled23, 10U)) * ((uint32_T)u16AMP_10000)))) +
      (((int32_T)rtb_Conversion) * ((int32_T)rtb_Sum_i));

    /* End of Outputs for SubSystem: '<S910>/EXV_Forward_TotalDehum' */

    /* Saturate: '<S1010>/Saturation2' incorporates:
     *  UnitDelay: '<S1010>/Unit Delay'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_p > 4000000) {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_p = 4000000;
    } else {
      if (Chery_E03_Hp_DW.UnitDelay_DSTATE_p < -1200000) {
        Chery_E03_Hp_DW.UnitDelay_DSTATE_p = -1200000;
      }
    }

    /* Sum: '<S1010>/Add1' incorporates:
     *  Lookup_n-D: '<S1010>/SH_Ki'
     *  Product: '<S1010>/Product2'
     */
    rtb_Sum2 = ((((int32_T)look1_is16lu32n16Ds32_binlcs(rtb_Sum_i, ((int16_T *)
      &(s16Chil_EXV_Ki.s16Chil_Exv_SH_delta[0])), ((int16_T *)
      &(s16Chil_EXV_Ki.s16Chil_EXV_Ki_y[0])), 7U)) * ((int32_T)rtb_Sum_i)) +
                rtb_Switch_oe) + Chery_E03_Hp_DW.UnitDelay_DSTATE_p;

    /* Saturate: '<S1010>/Saturation2' incorporates:
     *  Sum: '<S1010>/Add4'
     *  UnitDelay: '<S1010>/Unit Delay'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_p = rtb_Sum2 - rtb_Switch_oe;

    /* Product: '<S1010>/Divide' incorporates:
     *  Constant: '<S1010>/Constant2'
     */
    rtb_Switch_oe = div_nde_s32_floor(rtb_Sum2, (int32_T)u16AMP_10000);

    /* Switch: '<S1011>/Switch' incorporates:
     *  Constant: '<S1010>/Constant3'
     *  RelationalOperator: '<S1011>/UpperRelop'
     */
    if (rtb_Switch_oe < 0) {
      rtb_Conversion = 0U;
    } else {
      rtb_Conversion = (uint16_T)rtb_Switch_oe;
    }

    /* End of Switch: '<S1011>/Switch' */

    /* Switch: '<S1011>/Switch2' incorporates:
     *  RelationalOperator: '<S1011>/LowerRelop1'
     */
    if (rtb_Switch_oe > 576) {
      /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
       *  Constant: '<S1010>/Constant1'
       */
      Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = 576U;
    } else {
      /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' */
      Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = rtb_Conversion;
    }

    /* End of Switch: '<S1011>/Switch2' */
    /* End of Outputs for SubSystem: '<S910>/Total_DehumMode_EXV' */
    /* End of Outputs for SubSystem: '<S342>/EXV_Eva_TotalDehum_Ctrl' */

    /* Outputs for Atomic SubSystem: '<S342>/EXV_Chiller_Ctrl_TotalDehum'
     *
     * Block description for '<S342>/EXV_Chiller_Ctrl_TotalDehum':
     *  Chiller exv step control
     */
    /* Sum: '<S986>/Add2' */
    rtb_Add1_j = (int16_T)(Chery_E03_Hp_B.HpI_s16Teva_Front_A10 -
      Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10);

    /* Outputs for Atomic SubSystem: '<S986>/Delay_15s' */
    rtb_SignalCopy_e = ( Chery_E03_Hp_DelayJudge_Cfg(rtb_Add1_j <= 20,
      &Chery_E03_Hp_ConstB.Delay_15s, &Chery_E03_Hp_DW.Delay_15s, 150) != false);

    /* End of Outputs for SubSystem: '<S986>/Delay_15s' */

    /* Outputs for Atomic SubSystem: '<S986>/Delay_5s' */
    rtb_SignalCopy_p = ( Chery_E03_Hp_DelayJudge_Cfg(rtb_Add1_j <= 40,
      &Chery_E03_Hp_ConstB.Delay_5s_b, &Chery_E03_Hp_DW.Delay_5s_b, 150) !=
                        false);

    /* End of Outputs for SubSystem: '<S986>/Delay_5s' */

    /* Sum: '<S986>/Subtract' incorporates:
     *  Constant: '<S997>/Constant'
     *  Constant: '<S998>/Constant'
     *  RelationalOperator: '<S997>/Compare'
     *  RelationalOperator: '<S998>/Compare'
     *  Sum: '<S986>/Add2'
     */
    rtb_Add1_j = (int16_T)(Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10 -
      Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10);

    /* Saturate: '<S985>/Saturation' */
    if (rtb_Add1_j > 200) {
      rtb_Sum_i = 200;
    } else if (rtb_Add1_j < -150) {
      rtb_Sum_i = -150;
    } else {
      rtb_Sum_i = rtb_Add1_j;
    }

    /* End of Saturate: '<S985>/Saturation' */

    /* Product: '<S985>/Product' incorporates:
     *  Lookup_n-D: '<S985>/ExvLv3Kp'
     */
    rtb_Sum2 = ((int32_T)rtb_Sum_i) * ((int32_T)look1_is16lu32n16Ds32_binlcs
      (rtb_Add1_j, ((int16_T *)
                    &(AC_s16TBatIn_Delta_Lv3_u1.AC_s16TBatIn_Delta_Lv3_u1[0])),
       ((int16_T *)&(AC_s16TBatIn_Delta_Lv3_u1.AC_s16TBatIn_Delta_Lv3_u1_y[0])),
       9U));

    /* Product: '<S985>/Divide' incorporates:
     *  Constant: '<S985>/Constant1'
     *  Lookup_n-D: '<S985>/ExvL3Ki'
     *  Product: '<S985>/Product1'
     *  Sum: '<S985>/Add'
     *  UnitDelay: '<S985>/Unit Delay'
     */
    rtb_Switch_oe = div_nde_s32_floor(((((int32_T)look1_is16lu32n16Ds32_binlcs
      (rtb_Add1_j, ((int16_T *)&(AC_s16ExvCtrl_Ki_Lv3.AC_s16TBatIn_Delta_Lv3_u1
      [0])), ((int16_T *)&(AC_s16ExvCtrl_Ki_Lv3.AC_s16ExvCtrl_Ki_Lv3_y[0])), 9U))
      * ((int32_T)rtb_Add1_j)) + rtb_Sum2) + Chery_E03_Hp_DW.UnitDelay_DSTATE_b,
      (int32_T)u16AMP_1000);

    /* Saturate: '<S985>/Saturation2' */
    if (rtb_Switch_oe > 3800) {
      rtb_Switch_oe = 3800;
    } else {
      if (rtb_Switch_oe < 0) {
        rtb_Switch_oe = 0;
      }
    }

    rtb_Conversion = (uint16_T)rtb_Switch_oe;

    /* End of Saturate: '<S985>/Saturation2' */

    /* Sum: '<S985>/Add2' incorporates:
     *  Constant: '<S985>/Constant2'
     *  Product: '<S985>/Product2'
     *  UnitDelay: '<S985>/Unit Delay'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_b = ((int32_T)((uint32_T)(((uint32_T)
      rtb_Conversion) * ((uint32_T)u16AMP_1000)))) - rtb_Sum2;

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S985>/Constant3'
     *  Product: '<S985>/Product3'
     */
    Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = (uint16_T)(((uint32_T)rtb_Conversion) /
      ((uint32_T)u8AMP_10));

    /* End of Outputs for SubSystem: '<S342>/EXV_Chiller_Ctrl_TotalDehum' */

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S907>/Constant6'
     */
    Chery_E03_Hp_B.u8TWValve_BAT_Req = 100U;

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S907>/Constant7'
     */
    Chery_E03_Hp_B.u8HVCH_Req = 0U;

    /* Lookup_n-D: '<S921>/Table_HVCH_Pump1' */
    rtb_Conversion = look1_is16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10, ((int16_T *)
        &(HP_u16Pump_HC_Twat.HP_s16Twat_HVCH_u1[0])), ((uint16_T *)
        &(HP_u16Pump_HC_Twat.HP_u16Pump_HC_Twat_y[0])), 4U);

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' */
    Chery_E03_Hp_B.u16Pump_HVCH_Req = rtb_Conversion;

    /* Outputs for Atomic SubSystem: '<S920>/IfThenElse4' */
    rtb_Conversion = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_3, 80, 0);

    /* End of Outputs for SubSystem: '<S920>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S920>/IfThenElse3' */
    rtb_Conversion = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2, 60, rtb_Conversion);

    /* End of Outputs for SubSystem: '<S920>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S920>/IfThenElse2' */
    rtb_Conversion = (uint16_T) Chery_E03_Hp_IfThenElse2
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTM_CycleL11) ||
       (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1), 50, rtb_Conversion);

    /* End of Outputs for SubSystem: '<S920>/IfThenElse2' */

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S920>/Pump_0%'
     *  Constant: '<S920>/Pump_100%'
     *  Constant: '<S920>/Pump_50%'
     *  Constant: '<S920>/Pump_80%'
     *  Constant: '<S924>/Constant'
     *  Constant: '<S925>/Constant'
     *  Constant: '<S926>/Constant'
     *  Constant: '<S927>/Constant'
     *  Logic: '<S920>/OR2'
     *  RelationalOperator: '<S924>/Compare'
     *  RelationalOperator: '<S925>/Compare'
     *  RelationalOperator: '<S926>/Compare'
     *  RelationalOperator: '<S927>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Bat_Req = rtb_Conversion;

    /* Outputs for Atomic SubSystem: '<S907>/IfThenElse2' */
    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S907>/Constant4'
     *  Constant: '<S907>/Constant5'
     *  Constant: '<S918>/Constant'
     *  RelationalOperator: '<S918>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Motor_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((int32_T)Chery_E03_Hp_B.HpI_u8Mot_CoolLv) == 1, 100, 0);

    /* End of Outputs for SubSystem: '<S907>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S911>/IfThenElse1' */
    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S1012>/Constant'
     *  Constant: '<S911>/OutEva_SOV_Close'
     *  Constant: '<S911>/OutEva_SOV_Open'
     *  RelationalOperator: '<S1012>/Compare'
     */
    Chery_E03_Hp_B.bSOV_OutEva_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 != u8MODE_TotalDehum_CHIL_6, (uint8_T)
       (bSOV_OPEN_1 ? 1U : 0U), (uint8_T)(bSOV_Close_0 ? 1U : 0U));

    /* End of Outputs for SubSystem: '<S911>/IfThenElse1' */

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S911>/TXVOutEva_SOV_Close'
     */
    Chery_E03_Hp_B.bSOV_TXVOutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S907>/Constant8'
     */
    Chery_E03_Hp_B.u8TWValve_HC_Req = 100U;

    /* Switch: '<S922>/Switch' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S934>/Constant'
     *  RelationalOperator: '<S934>/Compare'
     */
    if (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1) {
      /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
       *  Constant: '<S922>/Constant1'
       */
      Chery_E03_Hp_B.u8TWValve_LTR_Req = 100U;
    } else {
      /* SignalConversion: '<S342>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
       *  Constant: '<S922>/Constant3'
       */
      Chery_E03_Hp_B.u8TWValve_LTR_Req = 0U;
    }

    /* End of Switch: '<S922>/Switch' */
    /* End of Outputs for SubSystem: '<S40>/Total_Dehum_Mode' */
    break;

   case 4:
    if (Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S40>/HP_Mode' incorporates:
       *  ActionPort: '<S339>/Action Port'
       *
       * Block description for '<S40>/HP_Mode':
       *  AC / AC Chiller mode control
       */
      /* InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
       *  MinMax: '<S710>/Min'
       *  UnitDelay: '<S654>/Unit Delay'
       *  UnitDelay: '<S659>/Unit Delay'
       */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_c = 0;
      Chery_E03_Hp_DW.UnitDelay_DSTATE_n = false;

      /* End of InitializeConditions for SubSystem: '<S40>/HP_Mode' */

      /* SystemReset for IfAction SubSystem: '<S40>/HP_Mode' incorporates:
       *  ActionPort: '<S339>/Action Port'
       *
       * Block description for '<S40>/HP_Mode':
       *  AC / AC Chiller mode control
       */
      /* SystemReset for Atomic SubSystem: '<S339>/EDC_Control_HP'
       *
       * Block description for '<S339>/EDC_Control_HP':
       *  ACChiller Mode_ EDC Control
       */
      /* SystemReset for SwitchCase: '<S40>/Switch Case' incorporates:
       *  UnitDelay: '<S633>/Unit Delay'
       *  UnitDelay: '<S648>/Unit Delay'
       */
      Chery_E03_Hp_EDC_Control_HP_Reset();

      /* End of SystemReset for SubSystem: '<S339>/EDC_Control_HP' */

      /* SystemReset for Atomic SubSystem: '<S660>/FirstRun2' */
      Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun, &Chery_E03_Hp_DW.FirstRun2);

      /* End of SystemReset for SubSystem: '<S660>/FirstRun2' */

      /* SystemReset for Atomic SubSystem: '<S656>/FirstRun' */
      Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun_e, &Chery_E03_Hp_DW.FirstRun);

      /* End of SystemReset for SubSystem: '<S656>/FirstRun' */

      /* SystemReset for Atomic SubSystem: '<S654>/Hyster' */
      Chery_E03_Hp_Hyster_b_Reset(&Chery_E03_Hp_DW.Hyster_p);

      /* End of SystemReset for SubSystem: '<S654>/Hyster' */

      /* SystemReset for Atomic SubSystem: '<S654>/Hyster1' */
      Chery_E03_Hp_Hyster_b_Reset(&Chery_E03_Hp_DW.Hyster1_a);

      /* End of SystemReset for SubSystem: '<S654>/Hyster1' */

      /* SystemReset for Atomic SubSystem: '<S654>/Hyster_Judge1' */
      Chery_E03_Hp_Hyster_Judge1_Reset(&Chery_E03_Hp_DW.Hyster_Judge1,
        Chery_E03_Hp_ConstP.pooled3);

      /* End of SystemReset for SubSystem: '<S654>/Hyster_Judge1' */

      /* SystemReset for Atomic SubSystem: '<S654>/DelayJudge1' */
      Chery_E03_Hp_DelayJudge_Reset(&Chery_E03_Hp_DW.DelayJudge1_k);

      /* End of SystemReset for SubSystem: '<S654>/DelayJudge1' */

      /* SystemReset for Atomic SubSystem: '<S654>/DelayJudge2' */
      Chery_E03_Hp_DelayJudge_Reset(&Chery_E03_Hp_DW.DelayJudge2);

      /* End of SystemReset for SubSystem: '<S654>/DelayJudge2' */

      /* SystemReset for Atomic SubSystem: '<S657>/FirstRun' */
      Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun_dy, &Chery_E03_Hp_DW.FirstRun_n);

      /* End of SystemReset for SubSystem: '<S657>/FirstRun' */

      /* SystemReset for Atomic SubSystem: '<S657>/PIModule' */
      Chery_E03_Hp_PIModule_c_Reset(&Chery_E03_Hp_DW.PIModule_p);

      /* End of SystemReset for SubSystem: '<S657>/PIModule' */

      /* SystemReset for Atomic SubSystem: '<S656>/PIModule' */
      Chery_E03_Hp_PIModule_Reset(&Chery_E03_Hp_DW.PIModule);

      /* End of SystemReset for SubSystem: '<S656>/PIModule' */

      /* SystemReset for Atomic SubSystem: '<S658>/FirstRun' */
      Chery_E03_Hp_FirstRun_Reset(&rtb_bFirstRun_d, &Chery_E03_Hp_DW.FirstRun_c);

      /* End of SystemReset for SubSystem: '<S658>/FirstRun' */

      /* SystemReset for Atomic SubSystem: '<S658>/PIModule' */
      Chery_E03_Hp_PIModule_c_Reset(&Chery_E03_Hp_DW.PIModule_e);

      /* End of SystemReset for SubSystem: '<S658>/PIModule' */

      /* SystemReset for Atomic SubSystem: '<S660>/Delay_Any' */
      Chery_E03_Hp_Delay_Any_Reset(&Chery_E03_Hp_DW.Delay_Any);

      /* End of SystemReset for SubSystem: '<S660>/Delay_Any' */

      /* SystemReset for Atomic SubSystem: '<S339>/EXV_Eva_Ctrl_HPMode'
       *
       * Block description for '<S339>/EXV_Eva_Ctrl_HPMode':
       *  Chiller exv step control
       */
      /* SystemReset for Atomic SubSystem: '<S508>/EXV_HP_Mode'
       *
       * Block description for '<S508>/EXV_HP_Mode':
       *  Chiller mode exv position PI
       */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_g = 380000;

      /* End of SystemReset for SubSystem: '<S508>/EXV_HP_Mode' */
      /* End of SystemReset for SubSystem: '<S339>/EXV_Eva_Ctrl_HPMode' */

      /* SystemReset for Atomic SubSystem: '<S339>/EXV_Chiller_Ctrl_HP'
       *
       * Block description for '<S339>/EXV_Chiller_Ctrl_HP':
       *  Chiller exv step control
       */
      /* SystemReset for Atomic SubSystem: '<S507>/Chil_EXV_Calculation' */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_d = 0;

      /* End of SystemReset for SubSystem: '<S507>/Chil_EXV_Calculation' */
      /* End of SystemReset for SubSystem: '<S339>/EXV_Chiller_Ctrl_HP' */

      /* SystemReset for Atomic SubSystem: '<S660>/DelayJudge' */
      Chery_E03_Hp_DelayJudge_Reset(&Chery_E03_Hp_DW.DelayJudge_l);

      /* End of SystemReset for SubSystem: '<S660>/DelayJudge' */

      /* SystemReset for Atomic SubSystem: '<S655>/Hyster_Judge' */
      Chery_E03_Hp_Hyster_Judge1_Reset(&Chery_E03_Hp_DW.Hyster_Judge_g,
        Chery_E03_Hp_ConstP.pooled3);

      /* End of SystemReset for SubSystem: '<S655>/Hyster_Judge' */
      /* End of SystemReset for SubSystem: '<S40>/HP_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S40>/HP_Mode' incorporates:
     *  ActionPort: '<S339>/Action Port'
     *
     * Block description for '<S40>/HP_Mode':
     *  AC / AC Chiller mode control
     */
    /* Sum: '<S707>/Sum3' incorporates:
     *  Sum: '<S707>/Sum2'
     */
    rtb_Add1_j = (int16_T)(((int16_T)(((int16_T)Chery_E03_Hp_B.HpI_u16Power_Max)
      - ((int16_T)Chery_E03_Hp_B.HpI_u16PowerComp))) - ((int16_T)
      Chery_E03_Hp_B.HpI_u16PowerHVCH));

    /* Outputs for Atomic SubSystem: '<S339>/EDC_Control_HP'
     *
     * Block description for '<S339>/EDC_Control_HP':
     *  ACChiller Mode_ EDC Control
     */
    Chery_E03_Hp_EDC_Control_HP();

    /* End of Outputs for SubSystem: '<S339>/EDC_Control_HP' */

    /* Outputs for Atomic SubSystem: '<S660>/FirstRun2' */
    rtb_bFirstRun = ( Chery_E03_Hp_FirstRun(&Chery_E03_Hp_DW.FirstRun2, 1) !=
                     false);

    /* End of Outputs for SubSystem: '<S660>/FirstRun2' */

    /* Outputs for Atomic SubSystem: '<S656>/FirstRun' */
    rtb_bFirstRun_e = ( Chery_E03_Hp_FirstRun(&Chery_E03_Hp_DW.FirstRun, 1) !=
                       false);

    /* End of Outputs for SubSystem: '<S656>/FirstRun' */

    /* Outputs for Atomic SubSystem: '<S654>/Hyster' */
    rtb_Conversion_n = ( Chery_E03_Hp_Hyster_p(Chery_E03_Hp_B.HpI_u16Ncomp -
      Chery_E03_Hp_B.HpI_u16Ncomp_Max, bCONST_1, bCONST_0,
      &Chery_E03_Hp_ConstB.Hyster_p, &Chery_E03_Hp_DW.Hyster_p,
      Chery_E03_Hp_ConstP.pooled3) != false);

    /* End of Outputs for SubSystem: '<S654>/Hyster' */

    /* Outputs for Atomic SubSystem: '<S654>/Hyster1' */
    rtb_Conversion_bb = ( Chery_E03_Hp_Hyster_p(Chery_E03_Hp_B.HpI_u16PowerComp
      - Chery_E03_Hp_B.HpI_u16Power_Max, bCONST_1, bCONST_0,
      &Chery_E03_Hp_ConstB.Hyster1_a, &Chery_E03_Hp_DW.Hyster1_a,
      Chery_E03_Hp_ConstP.pooled3) != false);

    /* End of Outputs for SubSystem: '<S654>/Hyster1' */

    /* MinMax: '<S654>/Max2' incorporates:
     *  Constant: '<S654>/Constant6'
     *  Constant: '<S654>/Constant7'
     *  Constant: '<S654>/Constant8'
     *  Constant: '<S654>/Constant9'
     *  Sum: '<S654>/Sum1'
     *  Sum: '<S654>/Sum3'
     */
    if (Chery_E03_Hp_B.HpI_s16Tset_Left_A10 >
        Chery_E03_Hp_B.HpI_s16Tset_Right_A10) {
      rtb_Sum_i = Chery_E03_Hp_B.HpI_s16Tset_Left_A10;
    } else {
      rtb_Sum_i = Chery_E03_Hp_B.HpI_s16Tset_Right_A10;
    }

    /* End of MinMax: '<S654>/Max2' */

    /* Outputs for Atomic SubSystem: '<S654>/DataTypeConv_s16_' */
    rtb_Sum = (int16_T) Chery_E03_Hp_DataTypeConv_s16__d(rtb_Sum_i);

    /* End of Outputs for SubSystem: '<S654>/DataTypeConv_s16_' */

    /* Lookup_n-D: '<S654>/2-D Lookup Table1' */
    rtb_Sum = look2_is16lu32n16Ds32ds32_binlcs(rtb_Sum,
      Chery_E03_Hp_B.HpI_s16Tamb_A10, ((int16_T *)
      &(ACPre_s16LVL_HeatCool.ACPre_s16TSet_Cmf_u1[0])), ((int16_T *)
      &(ACPre_s16LVL_HeatCool.ACPre_s16Tamb_U2[0])), ((int16_T *)
      &(ACPre_s16LVL_HeatCool.ACPre_s16LVL_HeatCool_y[0])),
      Chery_E03_Hp_ConstP.pooled23, 10U);

    /* RelationalOperator: '<S662>/Compare' incorporates:
     *  Constant: '<S662>/Constant'
     */
    rtb_Switch2 = (rtb_Sum >= 3);

    /* Switch: '<S654>/Switch' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S661>/Constant'
     *  Logic: '<S654>/Logical Operator'
     *  RelationalOperator: '<S661>/Compare'
     */
    if (ACPre_u8Project_CheryE03 != ACPre_u8Project_SokonX1) {
      rtb_Switch2 = (rtb_Switch2 || (Chery_E03_Hp_B.bBTM_HeatReq_Yes));
    }

    /* End of Switch: '<S654>/Switch' */

    /* Outputs for Atomic SubSystem: '<S654>/Hyster_Judge1' */
    rtb_Conversion_dx = ( Chery_E03_Hp_Hyster_Judge1(140, (int16_T)
      (Chery_E03_Hp_B.s16Twater_Max_HP_Y - Chery_E03_Hp_B.Switch), 80,
      &Chery_E03_Hp_DW.Hyster_Judge1, Chery_E03_Hp_ConstP.pooled3) != false);

    /* End of Outputs for SubSystem: '<S654>/Hyster_Judge1' */

    /* Logic: '<S654>/OR1' incorporates:
     *  Constant: '<S654>/Constant4'
     *  Constant: '<S654>/Constant5'
     *  Logic: '<S654>/OR2'
     *  Sum: '<S654>/Sum2'
     */
    rtb_LowerRelop1_a = ((((rtb_Switch2 && rtb_Conversion_dx) ||
      rtb_Conversion_n) || rtb_Conversion_bb) || (Chery_E03_Hp_B.bRisk_Comp));

    /* Outputs for Atomic SubSystem: '<S654>/DelayJudge1' */
    rtb_SignalCopy_b = ( Chery_E03_Hp_DelayJudge(rtb_LowerRelop1_a,
      &Chery_E03_Hp_ConstB.DelayJudge1_k, &Chery_E03_Hp_DW.DelayJudge1_k) !=
                        false);

    /* End of Outputs for SubSystem: '<S654>/DelayJudge1' */

    /* Outputs for Atomic SubSystem: '<S654>/DelayJudge2' */
    rtb_SignalCopy_o = ( Chery_E03_Hp_DelayJudge(!rtb_LowerRelop1_a,
      &Chery_E03_Hp_ConstB.DelayJudge2, &Chery_E03_Hp_DW.DelayJudge2) != false);

    /* End of Outputs for SubSystem: '<S654>/DelayJudge2' */

    /* Outputs for Atomic SubSystem: '<S657>/FirstRun' */
    rtb_bFirstRun_dy = ( Chery_E03_Hp_FirstRun(&Chery_E03_Hp_DW.FirstRun_n, 1)
                        != false);

    /* End of Outputs for SubSystem: '<S657>/FirstRun' */

    /* Outputs for Atomic SubSystem: '<S657>/PIModule' */
    Chery_E03_Hp_PIModule_p(5, 30, rtb_Add1_j, rtb_bFirstRun_dy, bCONST_0,
      Chery_E03_Hp_DW.UnitDelay_DSTATE_c, &rtb_Switch_oe, &rtb_Divide,
      &rtb_Divide5_n, &rtb_Divide9_a, &rtb_Divide8_n, &rtb_Divide10_h,
      &rtb_Divide11_p, &rtb_Sum2, &Chery_E03_Hp_ConstB.PIModule_p,
      &Chery_E03_Hp_DW.PIModule_p);

    /* End of Outputs for SubSystem: '<S657>/PIModule' */

    /* Sum: '<S695>/Sum4' incorporates:
     *  Constant: '<S657>/Constant'
     *  Constant: '<S657>/Constant1'
     *  Constant: '<S657>/Constant2'
     *  Constant: '<S695>/Delta_HP_HVCH'
     *  Logic: '<S654>/NOT'
     *  Sum: '<S695>/Sum5'
     *  UnitDelay: '<S659>/Unit Delay'
     */
    rtb_Sum_i = (int16_T)(((int16_T)(Chery_E03_Hp_B.Switch -
      Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10)) - 30);

    /* Saturate: '<S695>/Saturation1' */
    if (rtb_Sum_i > 300) {
      rtb_Sum_i = 300;
    } else {
      if (rtb_Sum_i < -600) {
        rtb_Sum_i = -600;
      }
    }

    /* End of Saturate: '<S695>/Saturation1' */

    /* Outputs for Atomic SubSystem: '<S654>/IfThenElse2' */
    Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_o, bCONST_0,
      Chery_E03_Hp_DW.UnitDelay_DSTATE_n, &rtb_Switch2);

    /* End of Outputs for SubSystem: '<S654>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S654>/IfThenElse1' */
    Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_b, bCONST_1, rtb_Switch2,
      &rtb_Conversion_dx);

    /* End of Outputs for SubSystem: '<S654>/IfThenElse1' */

    /* Logic: '<S656>/Logical Operator1' incorporates:
     *  Constant: '<S654>/HVCH_Authority_Yes'
     *  Constant: '<S654>/HVCH_Authority_Yes1'
     *  UnitDelay: '<S654>/Unit Delay'
     */
    rtb_LowerRelop1_a = !rtb_Conversion_dx;

    /* Outputs for Atomic SubSystem: '<S656>/IfThenElse2' */
    Chery_E03_Hp_IfThenElse_c(rtb_LowerRelop1_a, bCONST_1, bCONST_0,
      &rtb_Switch2);

    /* End of Outputs for SubSystem: '<S656>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S656>/IfThenElse1' */
    rtb_Conversion_d04l = Chery_E03_Hp_IfThenElse_cv(rtb_LowerRelop1_a, 0,
      Chery_E03_Hp_DW.UnitDelay_DSTATE_c);

    /* End of Outputs for SubSystem: '<S656>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S656>/PIModule' */
    Chery_E03_Hp_PIModule(((real_T)((int32_T)(((int32_T)
      look2_is16u16lu32n16tu16_binlcse(rtb_Sum_i,
      Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
      &(Flap_u16Kp_HVCH_A10000.Flap_s16TCtrlDelta_Coolant_u1[0])), ((uint16_T *)
      &(Flap_u16Kp_HVCH_A10000.Flap_u16_Qblower_HVCHCtrl_u2[0])), ((uint16_T *)
      &(Flap_u16Kp_HVCH_A10000.Flap_u16Kp_HVCH_A10000_y[0])),
      Chery_E03_Hp_ConstP.pooled24, 8U)) * 3))) / 10.0, (real_T)
                          look2_is16u16lu32n16tu16_binlcse(rtb_Sum_i,
      Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
      &(Flap_u16Ki_HVCH_A10000.Flap_s16TCtrlDelta_Coolant_u1[0])), ((uint16_T *)
      &(Flap_u16Ki_HVCH_A10000.Flap_u16_Qblower_HVCHCtrl_u2[0])), ((uint16_T *)
      &(Flap_u16Ki_HVCH_A10000.Flap_u16Ki_HVCH_A10000_y[0])),
      Chery_E03_Hp_ConstP.pooled24, 8U), rtb_Sum_i, rtb_bFirstRun_e, rtb_Switch2,
                          rtb_Conversion_d04l, &rtb_Switch_oe, &rtb_Divide,
                          &rtb_Divide5_n, &rtb_Divide9_a, &rtb_Divide8_n,
                          &rtb_Divide10_h, &rtb_Divide11_p, &rtb_Conversion_d04l,
                          &Chery_E03_Hp_ConstB.PIModule,
                          &Chery_E03_Hp_DW.PIModule);

    /* End of Outputs for SubSystem: '<S656>/PIModule' */

    /* Outputs for Atomic SubSystem: '<S658>/FirstRun' */
    rtb_bFirstRun_d = ( Chery_E03_Hp_FirstRun(&Chery_E03_Hp_DW.FirstRun_c, 1) !=
                       false);

    /* End of Outputs for SubSystem: '<S658>/FirstRun' */

    /* Outputs for Atomic SubSystem: '<S658>/PIModule' */
    Chery_E03_Hp_PIModule_p(50, 10, (int16_T)(s16Tw_HVCH_UpLimit -
      Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10), rtb_bFirstRun_d, bCONST_0,
      Chery_E03_Hp_DW.UnitDelay_DSTATE_c, &rtb_Switch_oe, &rtb_Divide,
      &rtb_Divide5_n, &rtb_Divide9_a, &rtb_Divide8_n, &rtb_Divide10_h,
      &rtb_Divide11_p, &rtb_Add1_kc, &Chery_E03_Hp_ConstB.PIModule_e,
      &Chery_E03_Hp_DW.PIModule_e);

    /* End of Outputs for SubSystem: '<S658>/PIModule' */

    /* Product: '<S658>/Product3' incorporates:
     *  Constant: '<S656>/Constant1'
     *  Constant: '<S656>/Constant2'
     *  Constant: '<S656>/Constant3'
     *  Constant: '<S658>/Amp_Rate1'
     *  Constant: '<S658>/Constant'
     *  Constant: '<S658>/Constant1'
     *  Constant: '<S658>/Constant2'
     *  Constant: '<S658>/Constant5'
     *  Constant: '<S697>/Constant'
     *  Constant: '<S697>/Constant1'
     *  Constant: '<S718>/Constant'
     *  Lookup_n-D: '<S697>/Ki_Table_A10000'
     *  Lookup_n-D: '<S697>/Kp_Table_A10000'
     *  Product: '<S656>/Product6'
     *  Product: '<S657>/Product3'
     *  Product: '<S697>/Divide'
     *  Product: '<S697>/Product4'
     *  Sum: '<S718>/Sum2'
     *  UnitDelay: '<S659>/Unit Delay'
     */
    rtb_Switch_oe = 100 * ((int32_T)u16AMP_10000);

    /* Switch: '<S722>/Switch' incorporates:
     *  RelationalOperator: '<S722>/UpperRelop'
     */
    if (rtb_Add1_kc < 0) {
      rtb_Switch_n = 0;
    } else {
      rtb_Switch_n = rtb_Add1_kc;
    }

    /* End of Switch: '<S722>/Switch' */

    /* Switch: '<S722>/Switch2' incorporates:
     *  Product: '<S658>/Product3'
     *  RelationalOperator: '<S722>/LowerRelop1'
     */
    if (rtb_Add1_kc > rtb_Switch_oe) {
      rtb_Divide = rtb_Switch_oe;
    } else {
      rtb_Divide = rtb_Switch_n;
    }

    /* End of Switch: '<S722>/Switch2' */

    /* Outputs for Atomic SubSystem: '<S658>/IfThenElse' */
    rtb_BusArr[2] = Chery_E03_Hp_IfThenElse_cv(s16Tw_HVCH_UpLimitMax >=
      Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10, rtb_Divide, 0);

    /* End of Outputs for SubSystem: '<S658>/IfThenElse' */

    /* Product: '<S656>/Product6' incorporates:
     *  Constant: '<S658>/Constant6'
     *  Constant: '<S658>/Constant7'
     *  RelationalOperator: '<S658>/Relational Operator'
     */
    rtb_Switch_n = rtb_Switch_oe;

    /* Switch: '<S701>/Switch' incorporates:
     *  RelationalOperator: '<S701>/UpperRelop'
     */
    if (rtb_Conversion_d04l < 0) {
      rtb_Divide = 0;
    } else {
      rtb_Divide = rtb_Conversion_d04l;
    }

    /* End of Switch: '<S701>/Switch' */

    /* Switch: '<S701>/Switch2' incorporates:
     *  RelationalOperator: '<S701>/LowerRelop1'
     */
    if (rtb_Conversion_d04l > rtb_Switch_n) {
      rtb_BusArr[0] = rtb_Switch_n;
    } else {
      rtb_BusArr[0] = rtb_Divide;
    }

    /* End of Switch: '<S701>/Switch2' */

    /* Product: '<S657>/Product3' */
    rtb_Switch_n = rtb_Switch_oe;

    /* Switch: '<S711>/Switch' incorporates:
     *  RelationalOperator: '<S711>/UpperRelop'
     */
    if (rtb_Sum2 < 0) {
      rtb_Divide = 0;
    } else {
      rtb_Divide = rtb_Sum2;
    }

    /* End of Switch: '<S711>/Switch' */

    /* Switch: '<S711>/Switch2' incorporates:
     *  RelationalOperator: '<S711>/LowerRelop1'
     */
    if (rtb_Sum2 > rtb_Switch_n) {
      rtb_Divide = rtb_Switch_n;
    }

    /* End of Switch: '<S711>/Switch2' */

    /* MinMax: '<S710>/Min' incorporates:
     *  UnitDelay: '<S659>/Unit Delay'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_c >= rtb_Divide) {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_c = rtb_Divide;
    }

    /* Outputs for Atomic SubSystem: '<S710>/IfThenElse2' */
    rtb_BusArr[1] = Chery_E03_Hp_IfThenElse_cv(rtb_Add1_j < 0,
      Chery_E03_Hp_DW.UnitDelay_DSTATE_c, rtb_Divide);

    /* End of Outputs for SubSystem: '<S710>/IfThenElse2' */

    /* Outputs for Iterator SubSystem: '<S660>/FindMinVal' incorporates:
     *  ForIterator: '<S736>/For Iterator'
     */
    if (((int32_T)Chery_E03_Hp_DW.ForIterator_IterationMarker) != 0) {
      /* InitializeConditions for UnitDelay: '<S736>/TempMinVal' */
      Chery_E03_Hp_DW.TempMinVal_DSTATE = 0;

      /* InitializeConditions for UnitDelay: '<S736>/TempIndexOfMinVal' */
      Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE = 0;
    }

    Chery_E03_Hp_DW.ForIterator_IterationMarker = 1U;

    /* RelationalOperator: '<S736>/Less Than' incorporates:
     *  Constant: '<S715>/Constant'
     *  MultiPortSwitch: '<S736>/Index Vector1'
     *  RelationalOperator: '<S715>/Compare'
     *  UnitDelay: '<S736>/TempMinVal'
     */
    rtb_LowerRelop1_a = (rtb_BusArr[0] < Chery_E03_Hp_DW.TempMinVal_DSTATE);

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse1' */
    rtb_Conversion_gw = Chery_E03_Hp_IfThenElse_cv(rtb_LowerRelop1_a,
      rtb_BusArr[0], Chery_E03_Hp_DW.TempMinVal_DSTATE);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse' */
    Chery_E03_Hp_DW.TempMinVal_DSTATE = Chery_E03_Hp_IfThenElse_cv(true,
      rtb_BusArr[0], rtb_Conversion_gw);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse3' */
    rtb_Conversion_gw = Chery_E03_Hp_IfThenElse_cv(rtb_LowerRelop1_a, 0,
      Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse2' */
    Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE = Chery_E03_Hp_IfThenElse_cv(true,
      0, rtb_Conversion_gw);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse2' */

    /* RelationalOperator: '<S736>/Less Than' incorporates:
     *  MultiPortSwitch: '<S736>/Index Vector1'
     *  UnitDelay: '<S736>/TempIndexOfMinVal'
     *  UnitDelay: '<S736>/TempMinVal'
     */
    rtb_LowerRelop1_a = (rtb_BusArr[1] < Chery_E03_Hp_DW.TempMinVal_DSTATE);

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse1' */
    rtb_Conversion_gw = Chery_E03_Hp_IfThenElse_cv(rtb_LowerRelop1_a,
      rtb_BusArr[1], Chery_E03_Hp_DW.TempMinVal_DSTATE);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse' */
    Chery_E03_Hp_DW.TempMinVal_DSTATE = Chery_E03_Hp_IfThenElse_cv(false,
      rtb_BusArr[1], rtb_Conversion_gw);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse3' */
    rtb_Conversion_gw = Chery_E03_Hp_IfThenElse_cv(rtb_LowerRelop1_a, 1,
      Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse2' */
    Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE = Chery_E03_Hp_IfThenElse_cv(false,
      1, rtb_Conversion_gw);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse2' */

    /* RelationalOperator: '<S736>/Less Than' incorporates:
     *  MultiPortSwitch: '<S736>/Index Vector1'
     *  UnitDelay: '<S736>/TempIndexOfMinVal'
     *  UnitDelay: '<S736>/TempMinVal'
     */
    rtb_LowerRelop1_a = (rtb_BusArr[2] < Chery_E03_Hp_DW.TempMinVal_DSTATE);

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse1' */
    rtb_Conversion_gw = Chery_E03_Hp_IfThenElse_cv(rtb_LowerRelop1_a,
      rtb_BusArr[2], Chery_E03_Hp_DW.TempMinVal_DSTATE);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse' */
    Chery_E03_Hp_DW.TempMinVal_DSTATE = Chery_E03_Hp_IfThenElse_cv(false,
      rtb_BusArr[2], rtb_Conversion_gw);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse3' */
    rtb_Conversion_gw = Chery_E03_Hp_IfThenElse_cv(rtb_LowerRelop1_a, 2,
      Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S736>/IfThenElse2' */
    Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE = Chery_E03_Hp_IfThenElse_cv(false,
      2, rtb_Conversion_gw);

    /* End of Outputs for SubSystem: '<S736>/IfThenElse2' */
    /* End of Outputs for SubSystem: '<S660>/FindMinVal' */

    /* Outputs for Atomic SubSystem: '<S660>/IfThenElse' */
    rtb_TmpBufferAtOutEva_SOV_Close1Outport1 = (uint8_T)
      Chery_E03_Hp_IfThenElse_b(rtb_bFirstRun, 0,
      Chery_E03_Hp_DW.TempIndexOfMinVal_DSTATE);

    /* End of Outputs for SubSystem: '<S660>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S660>/Delay_Any' */
    rtb_Conversion_g = (uint8_T) Chery_E03_Hp_Delay_Any
      (rtb_TmpBufferAtOutEva_SOV_Close1Outport1, &Chery_E03_Hp_ConstB.Delay_Any,
       &Chery_E03_Hp_DW.Delay_Any);

    /* End of Outputs for SubSystem: '<S660>/Delay_Any' */

    /* MinMax: '<S710>/Min' incorporates:
     *  Constant: '<S660>/PIMode_Normal_0'
     *  MultiPortSwitch: '<S660>/Index Vector'
     *  MultiPortSwitch: '<S736>/Index Vector1'
     *  UnitDelay: '<S659>/Unit Delay'
     *  UnitDelay: '<S736>/TempIndexOfMinVal'
     *  UnitDelay: '<S736>/TempMinVal'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_c = rtb_BusArr[rtb_Conversion_g];

    /* Outputs for Atomic SubSystem: '<S659>/Divide' */
    rtb_Switch_n = Chery_E03_Hp_Divide_Safe(Chery_E03_Hp_DW.UnitDelay_DSTATE_c,
      u16AMP_10000, &Chery_E03_Hp_ConstB.Divide);

    /* End of Outputs for SubSystem: '<S659>/Divide' */

    /* Outputs for Atomic SubSystem: '<S659>/DataTypeConv_u8_' */
    rtb_TmpBufferAtOutEva_SOV_Close1Outport1 = (uint8_T)
      Chery_E03_Hp_DataTypeConv_u8__p(rtb_Switch_n);

    /* End of Outputs for SubSystem: '<S659>/DataTypeConv_u8_' */

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S659>/Amp_2'
     *  UnitDelay: '<S659>/Unit Delay'
     */
    Chery_E03_Hp_B.u8HVCH_Req = rtb_TmpBufferAtOutEva_SOV_Close1Outport1;

    /* Outputs for Atomic SubSystem: '<S339>/EXV_Eva_Ctrl_HPMode'
     *
     * Block description for '<S339>/EXV_Eva_Ctrl_HPMode':
     *  Chiller exv step control
     */
    /* Outputs for Atomic SubSystem: '<S508>/EXV_Forward_HP'
     *
     * Block description for '<S508>/EXV_Forward_HP':
     *  chiller edc rpm forward
     */
    /* Lookup_n-D: '<S647>/EXV_Eva_Estimation' */
    rtb_FAN_PWM_Calculatoin_AC_f = look2_is16u16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.HpI_u16Ncomp, ((int16_T *)
        &(u16EXV_EvaCDS_Pos_HP_Est.s16Tamb_Common2_u1[0])), ((uint16_T *)
        &(u16EXV_EvaCDS_Pos_HP_Est.u16Ncomp_RPM_u2[0])), ((uint16_T *)
        &(u16EXV_EvaCDS_Pos_HP_Est.u16EXV_EvaCDS_Pos_HP_Est_y[0])),
       Chery_E03_Hp_ConstP.pooled17, 10U);

    /* End of Outputs for SubSystem: '<S508>/EXV_Forward_HP' */

    /* Outputs for Atomic SubSystem: '<S508>/EXV_HP_Mode'
     *
     * Block description for '<S508>/EXV_HP_Mode':
     *  Chiller mode exv position PI
     */
    /* Lookup_n-D: '<S648>/SH_Target_Setting_HP' */
    rtb_Conversion_d = look2_is16u16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC,
       ((int16_T *)&(u16SH_Target_HP.s16Tamb_HP_u1[0])), ((uint16_T *)
        &(u16SH_Target_HP.u16_QBlower_HVAC_u2[0])), ((uint16_T *)
        &(u16SH_Target_HP.u16SH_Target_HP_y[0])), Chery_E03_Hp_ConstP.pooled15,
       7U);

    /* Sum: '<S648>/Subtract' */
    rtb_Sum_i = (int16_T)(((int16_T)Chery_E03_Hp_B.Hp_u16SH_CompInlet) -
                          ((int16_T)rtb_Conversion_d));

    /* Saturate: '<S648>/Saturation' */
    if (rtb_Sum_i > 150) {
      rtb_Sum = 150;
    } else if (rtb_Sum_i < -150) {
      rtb_Sum = -150;
    } else {
      rtb_Sum = rtb_Sum_i;
    }

    /* End of Saturate: '<S648>/Saturation' */

    /* Sum: '<S648>/Add3' incorporates:
     *  Constant: '<S648>/Constant'
     *  Lookup_n-D: '<S648>/EXV_Kp'
     *  Product: '<S648>/Product'
     *  Product: '<S648>/Product1'
     */
    rtb_Conversion_d04l = ((int32_T)((uint32_T)(((uint32_T)
      rtb_FAN_PWM_Calculatoin_AC_f) * ((uint32_T)u16AMP_10000)))) + (((int32_T)
      look2_is16lu32n16Ds32ds32_binlcs(rtb_Sum, Chery_E03_Hp_B.HpI_s16Tamb_A10,
      ((int16_T *)&(HP_s16Kp_EXV_EvaCDS_HP.HP_s16SH_delta_u1[0])), ((int16_T *)
      &(HP_s16Kp_EXV_EvaCDS_HP.HP_s16Tamb_u2[0])), ((int16_T *)
      &(HP_s16Kp_EXV_EvaCDS_HP.HP_s16Kp_EXV_EvaCDS_HP_y[0])),
      Chery_E03_Hp_ConstP.pooled20, 8U)) * ((int32_T)rtb_Sum));

    /* Outputs for Atomic SubSystem: '<S508>/EXV_Forward_HP'
     *
     * Block description for '<S508>/EXV_Forward_HP':
     *  chiller edc rpm forward
     */
    /* Product: '<S648>/Product3' incorporates:
     *  Constant: '<S648>/Constant3'
     *  Lookup_n-D: '<S647>/EXV_EvaCDS_Max'
     */
    rtb_Sum2 = (int32_T)((uint32_T)(((uint32_T)look1_iu16lu32n16_binlcse
      (rtb_FAN_PWM_Calculatoin_AC_f, ((uint16_T *)
      &(HP_u16_EXV_EvaCDS_HP_Max.HP_u16EXV_EvaCDS_Est_u1[0])), ((uint16_T *)
      &(HP_u16_EXV_EvaCDS_HP_Max.HP_u16_EXV_EvaCDS_HP_Max_y[0])), 9U)) *
      ((uint32_T)u16AMP_10000)));

    /* End of Outputs for SubSystem: '<S508>/EXV_Forward_HP' */

    /* Outputs for Atomic SubSystem: '<S648>/IfThenElse' */
    rtb_Add1_kc = Chery_E03_Hp_IfThenElse_cv(Chery_E03_Hp_DW.UnitDelay_DSTATE_h1
      == u8MODE_HP_7, Chery_E03_Hp_DW.UnitDelay_DSTATE_g, 0);

    /* End of Outputs for SubSystem: '<S648>/IfThenElse' */

    /* Sum: '<S648>/Add1' incorporates:
     *  Constant: '<S648>/Constant1'
     *  Constant: '<S649>/Constant'
     *  Lookup_n-D: '<S648>/EXV_Ki'
     *  Product: '<S648>/Product2'
     *  RelationalOperator: '<S649>/Compare'
     *  Sum: '<S648>/Add2'
     *  UnitDelay: '<S648>/Unit Delay'
     */
    rtb_Add1_kc += (((int32_T)look2_is16lu32n16Ds32ds32_binlcs(rtb_Sum,
      Chery_E03_Hp_B.HpI_s16Tamb_A10, ((int16_T *)
      &(s16Ki_EXV_EvaCDS_HP.s16SH_delta_u1[0])), ((int16_T *)
      &(s16Ki_EXV_EvaCDS_HP.HP_s16Tamb_u2[0])), ((int16_T *)
      &(s16Ki_EXV_EvaCDS_HP.s16Ki_EXV_EvaCDS_HP_y[0])),
      Chery_E03_Hp_ConstP.pooled20, 8U)) * ((int32_T)rtb_Sum)) +
      rtb_Conversion_d04l;

    /* Outputs for Atomic SubSystem: '<S508>/EXV_Forward_HP'
     *
     * Block description for '<S508>/EXV_Forward_HP':
     *  chiller edc rpm forward
     */
    /* Product: '<S648>/Product4' incorporates:
     *  Constant: '<S648>/Constant4'
     *  Lookup_n-D: '<S647>/EXV_EvaCDS_Min_2D'
     */
    rtb_Switch_n = (int32_T)((uint32_T)(((uint32_T)
      look2_is16u16lu32n16tu16_binlcse(Chery_E03_Hp_B.HpI_s16Tamb_A10,
      rtb_FAN_PWM_Calculatoin_AC_f, ((int16_T *)
      &(u16EXV_EvaCDS_Min_2D.s16Tamb_Common2_u1[0])), ((uint16_T *)
      &(u16EXV_EvaCDS_Min_2D.u16Ncomp_RPM_u2[0])), ((uint16_T *)
      &(u16EXV_EvaCDS_Min_2D.u16EXV_EvaCDS_Pos_HP_Est_y[0])),
      Chery_E03_Hp_ConstP.EXV_EvaCDS_Min_2D_maxIndex, 10U)) * ((uint32_T)
      u16AMP_10000)));

    /* End of Outputs for SubSystem: '<S508>/EXV_Forward_HP' */

    /* Switch: '<S652>/Switch' incorporates:
     *  RelationalOperator: '<S652>/UpperRelop'
     */
    if (rtb_Add1_kc >= rtb_Switch_n) {
      rtb_Switch_n = rtb_Add1_kc;
    }

    /* End of Switch: '<S652>/Switch' */

    /* Switch: '<S652>/Switch2' incorporates:
     *  RelationalOperator: '<S652>/LowerRelop1'
     */
    if (rtb_Add1_kc <= rtb_Sum2) {
      rtb_Sum2 = rtb_Switch_n;
    }

    /* End of Switch: '<S652>/Switch2' */

    /* Sum: '<S648>/Add4' incorporates:
     *  UnitDelay: '<S648>/Unit Delay'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_g = rtb_Sum2 - rtb_Conversion_d04l;

    /* Outputs for Atomic SubSystem: '<S648>/DataTypeConv_u16_' */
    rtb_Conversion_d = (uint16_T) Chery_E03_Hp_DataTypeConv_u16__h
      (div_nde_s32_floor(rtb_Sum2, (int32_T)u16AMP_10000));

    /* End of Outputs for SubSystem: '<S648>/DataTypeConv_u16_' */
    /* End of Outputs for SubSystem: '<S508>/EXV_HP_Mode' */
    /* End of Outputs for SubSystem: '<S339>/EXV_Eva_Ctrl_HPMode' */

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S648>/Constant2'
     *  Product: '<S648>/Divide'
     */
    Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = rtb_Conversion_d;

    /* Outputs for Atomic SubSystem: '<S339>/EXV_Chiller_Ctrl_HP'
     *
     * Block description for '<S339>/EXV_Chiller_Ctrl_HP':
     *  Chiller exv step control
     */
    /* Outputs for Atomic SubSystem: '<S507>/HP_exv_forward'
     *
     * Block description for '<S507>/HP_exv_forward':
     *  chiller edc rpm forward
     */
    /* Lookup_n-D: '<S634>/1-D Lookup Table' */
    rtb_FAN_PWM_Calculatoin_AC_f = look1_iu16lu32n16_binlcse
      (Chery_E03_Hp_B.HpI_u16Ncomp, Chery_E03_Hp_ConstP.pooled74,
       Chery_E03_Hp_ConstP.pooled73, 8U);

    /* End of Outputs for SubSystem: '<S507>/HP_exv_forward' */

    /* Outputs for Atomic SubSystem: '<S507>/Chil_EXV_Calculation' */
    /* Outputs for Atomic SubSystem: '<S633>/IfThenElse1' */
    rtb_Conversion_e = (int16_T) Chery_E03_Hp_IfThenElse
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHIL_8,
       Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10,
       Chery_E03_Hp_B.HpI_s16T_Wat_MotorOut_A10);

    /* End of Outputs for SubSystem: '<S633>/IfThenElse1' */

    /* Sum: '<S633>/Subtract' incorporates:
     *  Constant: '<S637>/Constant'
     *  Lookup_n-D: '<S633>/SH_Target_Setting'
     *  RelationalOperator: '<S637>/Compare'
     */
    rtb_Sum_i = (int16_T)(((int16_T)Chery_E03_Hp_B.Hp_u16SH_ChilOut) - ((int16_T)
      look2_is16u16lu32n16tu16_binlcse(rtb_Conversion_e,
      Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
      &(HP_u16SH_Set_HPCHIL.HP_s16TWater_HPChil_u1[0])), ((uint16_T *)
      &(HP_u16SH_Set_HPCHIL.HP_u16_QBlower_HVAC_u2[0])), ((uint16_T *)
      &(HP_u16SH_Set_HPCHIL.HP_u16SH_Set_HPCHIL_y[0])),
      Chery_E03_Hp_ConstP.pooled15, 7U)));

    /* Saturate: '<S633>/Saturation' */
    if (rtb_Sum_i > 150) {
      rtb_Sum_i = 150;
    } else {
      if (rtb_Sum_i < -150) {
        rtb_Sum_i = -150;
      }
    }

    /* End of Saturate: '<S633>/Saturation' */

    /* Sum: '<S633>/Add3' incorporates:
     *  Constant: '<S633>/Constant'
     *  Lookup_n-D: '<S633>/Kp_Calculation'
     *  Product: '<S633>/Product'
     *  Product: '<S633>/Product1'
     */
    rtb_Conversion_d04l = ((int32_T)((uint32_T)(((uint32_T)
      rtb_FAN_PWM_Calculatoin_AC_f) * ((uint32_T)u16AMP_10000)))) + (((int32_T)
      look2_is16lu32n16Ds32ds32_binlcs(rtb_Sum_i, rtb_Conversion_e, ((int16_T *)
      &(HP_s16Kp_EXV_Chil_HPChil.HP_s16SH_delta_u1[0])), ((int16_T *)
      &(HP_s16Kp_EXV_Chil_HPChil.HP_s16TWater_Chil_u2[0])), ((int16_T *)
      &(HP_s16Kp_EXV_Chil_HPChil.HP_s16Kp_EXV_Chil_HPChil_y[0])),
      Chery_E03_Hp_ConstP.pooled20, 8U)) * ((int32_T)rtb_Sum_i));

    /* Outputs for Atomic SubSystem: '<S507>/HP_exv_forward'
     *
     * Block description for '<S507>/HP_exv_forward':
     *  chiller edc rpm forward
     */
    /* Product: '<S633>/Product3' incorporates:
     *  Constant: '<S633>/Constant5'
     *  Lookup_n-D: '<S634>/EXV_Max'
     */
    rtb_Sum2 = (int32_T)((uint32_T)(((uint32_T)look1_iu16lu32n16_binlcse
      (rtb_FAN_PWM_Calculatoin_AC_f, ((uint16_T *)
      &(HP_u16_EXV_EvaCDS_HP_Max.HP_u16EXV_EvaCDS_Est_u1[0])), ((uint16_T *)
      &(HP_u16_EXV_EvaCDS_HP_Max.HP_u16_EXV_EvaCDS_HP_Max_y[0])), 9U)) *
      ((uint32_T)u16AMP_10000)));

    /* End of Outputs for SubSystem: '<S507>/HP_exv_forward' */

    /* Sum: '<S633>/Add1' incorporates:
     *  Lookup_n-D: '<S633>/Ki_Calculation'
     *  Product: '<S633>/Product2'
     *  UnitDelay: '<S633>/Unit Delay'
     */
    rtb_Add1_kc = ((((int32_T)look2_is16lu32n16Ds32ds32_binlcs(rtb_Sum_i,
      rtb_Conversion_e, ((int16_T *)
                         &(HP_s16Ki_EXV_Chil_HPChil.HP_s16SH_delta_u1[0])),
      ((int16_T *)&(HP_s16Ki_EXV_Chil_HPChil.HP_s16TWater_Chil_u2[0])),
      ((int16_T *)&(HP_s16Ki_EXV_Chil_HPChil.HP_s16Ki_EXV_Chil_HPChil_y[0])),
      Chery_E03_Hp_ConstP.pooled20, 8U)) * ((int32_T)rtb_Sum_i)) +
                   rtb_Conversion_d04l) + Chery_E03_Hp_DW.UnitDelay_DSTATE_d;

    /* Outputs for Atomic SubSystem: '<S507>/HP_exv_forward'
     *
     * Block description for '<S507>/HP_exv_forward':
     *  chiller edc rpm forward
     */
    /* Product: '<S633>/Product4' incorporates:
     *  Constant: '<S633>/Constant6'
     *  Lookup_n-D: '<S634>/EXV_Min'
     */
    rtb_Switch_n = (int32_T)((uint32_T)(((uint32_T)look1_iu16lu32n16_binlcse
      (rtb_FAN_PWM_Calculatoin_AC_f, ((uint16_T *)
      &(HP_u16_EXV_EvaCDS_HP_Min.HP_u16EXV_EvaCDS_Est_u1[0])), ((uint16_T *)
      &(HP_u16_EXV_EvaCDS_HP_Min.HP_u16_EXV_EvaCDS_HP_Min_y[0])), 9U)) *
      ((uint32_T)u16AMP_10000)));

    /* End of Outputs for SubSystem: '<S507>/HP_exv_forward' */

    /* Switch: '<S644>/Switch' incorporates:
     *  RelationalOperator: '<S644>/UpperRelop'
     */
    if (rtb_Add1_kc >= rtb_Switch_n) {
      rtb_Switch_n = rtb_Add1_kc;
    }

    /* End of Switch: '<S644>/Switch' */

    /* Switch: '<S644>/Switch2' incorporates:
     *  RelationalOperator: '<S644>/LowerRelop1'
     */
    if (rtb_Add1_kc <= rtb_Sum2) {
      rtb_Sum2 = rtb_Switch_n;
    }

    /* End of Switch: '<S644>/Switch2' */

    /* Sum: '<S633>/Add4' */
    rtb_Conversion_d04l = rtb_Sum2 - rtb_Conversion_d04l;

    /* Saturate: '<S633>/Saturation2' */
    rtb_Switch_oe = rtb_Conversion_d04l;
    if (rtb_Switch_oe > 4000000) {
      rtb_Conversion_d04l = 4000000;
    } else if (rtb_Switch_oe < -1200000) {
      rtb_Conversion_d04l = -1200000;
    } else {
      rtb_Conversion_d04l = rtb_Switch_oe;
    }

    /* End of Saturate: '<S633>/Saturation2' */

    /* Switch: '<S633>/Switch' incorporates:
     *  Constant: '<S633>/Constant3'
     *  Constant: '<S635>/Constant'
     *  Constant: '<S636>/Constant'
     *  Constant: '<S639>/Constant'
     *  Logic: '<S633>/OR2'
     *  RelationalOperator: '<S635>/Compare'
     *  RelationalOperator: '<S636>/Compare'
     *  RelationalOperator: '<S639>/Compare'
     *  UnitDelay: '<S633>/Unit Delay'
     */
    if (((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHIL_8) ||
         (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_MDCHIL_9)) ||
        (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHILMDCHIL_12)) {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_d = 0;
    } else {
      Chery_E03_Hp_DW.UnitDelay_DSTATE_d = rtb_Conversion_d04l;
    }

    /* End of Switch: '<S633>/Switch' */

    /* Outputs for Atomic SubSystem: '<S633>/IfThenElse' */
    rtb_Conversion_d04l = Chery_E03_Hp_IfThenElse_cv
      (((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHIL_8) ||
        (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_MDCHIL_9)) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHILMDCHIL_12),
       div_nde_s32_floor(rtb_Sum2, (int32_T)u16AMP_10000), 0);

    /* End of Outputs for SubSystem: '<S633>/IfThenElse' */

    /* Saturate: '<S633>/Saturation1' incorporates:
     *  Constant: '<S633>/Constant2'
     *  Constant: '<S633>/Constant4'
     *  Constant: '<S638>/Constant'
     *  Constant: '<S640>/Constant'
     *  Constant: '<S641>/Constant'
     *  Logic: '<S633>/OR1'
     *  Product: '<S633>/Divide'
     *  RelationalOperator: '<S638>/Compare'
     *  RelationalOperator: '<S640>/Compare'
     *  RelationalOperator: '<S641>/Compare'
     */
    rtb_Switch_oe = rtb_Conversion_d04l;
    if (rtb_Switch_oe > 300) {
      rtb_Switch_oe = 300;
    } else {
      if (rtb_Switch_oe < 0) {
        rtb_Switch_oe = 0;
      }
    }

    /* End of Saturate: '<S633>/Saturation1' */
    /* End of Outputs for SubSystem: '<S507>/Chil_EXV_Calculation' */
    /* End of Outputs for SubSystem: '<S339>/EXV_Chiller_Ctrl_HP' */

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' */
    Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = (uint16_T)rtb_Switch_oe;

    /* Outputs for Atomic SubSystem: '<S660>/DelayJudge' */
    rtb_SignalCopy_n = ( Chery_E03_Hp_DelayJudge(((int32_T)rtb_Conversion_g) !=
      0, &Chery_E03_Hp_ConstB.DelayJudge_l, &Chery_E03_Hp_DW.DelayJudge_l) !=
                        false);

    /* End of Outputs for SubSystem: '<S660>/DelayJudge' */

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S733>/Constant'
     *  RelationalOperator: '<S733>/Compare'
     */
    Chery_E03_Hp_B.u16Ncomp_Rpm_Req = Chery_E03_Hp_B.AC_u16Ncomp_Rpm_HP;

    /* Outputs for Atomic SubSystem: '<S503>/IfThenElse1' */
    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S503>/AGS_0_Close'
     *  Constant: '<S503>/AGS_100_Open'
     *  Constant: '<S511>/Constant'
     *  Constant: '<S513>/Constant'
     *  Logic: '<S503>/OR'
     *  RelationalOperator: '<S511>/Compare'
     *  RelationalOperator: '<S513>/Compare'
     */
    Chery_E03_Hp_B.u8AGS_Position_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_7) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_BatHeat_10), 100, 0);

    /* End of Outputs for SubSystem: '<S503>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S503>/IfThenElse2' */
    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S503>/Front_FAN_Close'
     *  Constant: '<S512>/Constant'
     *  Constant: '<S514>/Constant'
     *  DataTypeConversion: '<S503>/Data Type Conversion'
     *  DataTypeConversion: '<S503>/Data Type Conversion1'
     *  Logic: '<S503>/OR1'
     *  Lookup_n-D: '<S503>/FAN_PWM_Calculatoin_HPMode'
     *  RelationalOperator: '<S512>/Compare'
     *  RelationalOperator: '<S514>/Compare'
     *  Sum: '<S503>/Sum'
     */
    Chery_E03_Hp_B.u8FRFAN_PWM_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_7) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_BatHeat_10), (uint8_T)
       look2_iu16s16lu32n16tu16_binlcse((uint16_T)Chery_E03_Hp_B.HpI_u8VehSpd,
        (int16_T)(Chery_E03_Hp_B.HpI_s16Tamb_A10 -
                  Chery_E03_Hp_B.R134A_P_a10_T_a10_Table), ((uint16_T *)
         &(AC_u16PWM_FAN_HP.AC_u16Vspd_FAN_u1[0])), ((int16_T *)
         &(AC_u16PWM_FAN_HP.AC_s16T_DeltaExtSat_HP[0])), ((uint16_T *)
         &(AC_u16PWM_FAN_HP.AC_u16PWM_FAN_HP_y[0])),
        Chery_E03_Hp_ConstP.pooled15, 7U), 0);

    /* End of Outputs for SubSystem: '<S503>/IfThenElse2' */

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S510>/Eva_SOV_Close1'
     */
    Chery_E03_Hp_B.bSOV_Eva_Req = bSOV_Close_0 ? 1U : 0U;

    /* Outputs for Atomic SubSystem: '<S519>/IfThenElse8' */
    rtb_Conversion_i = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_CoolReq_Yes, 100, 0);

    /* End of Outputs for SubSystem: '<S519>/IfThenElse8' */

    /* Outputs for Atomic SubSystem: '<S519>/IfThenElse7' */
    rtb_Conversion_ea = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_HeatReq_Yes) && (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 100, rtb_Conversion_i);

    /* End of Outputs for SubSystem: '<S519>/IfThenElse7' */

    /* Outputs for Atomic SubSystem: '<S519>/IfThenElse12' */
    rtb_Conversion_nmc = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10 >=
       Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10, 50, 100);

    /* End of Outputs for SubSystem: '<S519>/IfThenElse12' */

    /* Outputs for Atomic SubSystem: '<S519>/IfThenElse11' */
    rtb_Conversion_i0 = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_BatHeat_10,
       rtb_Conversion_nmc, 0);

    /* End of Outputs for SubSystem: '<S519>/IfThenElse11' */

    /* Outputs for Atomic SubSystem: '<S519>/IfThenElse10' */
    rtb_Conversion_hy = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_MDCHIL_9) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHILMDCHIL_12), 50,
       rtb_Conversion_i0);

    /* End of Outputs for SubSystem: '<S519>/IfThenElse10' */

    /* Outputs for Atomic SubSystem: '<S519>/IfThenElse9' */
    rtb_Conversion_iok = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHIL_8, 0,
       rtb_Conversion_hy);

    /* End of Outputs for SubSystem: '<S519>/IfThenElse9' */

    /* Outputs for Atomic SubSystem: '<S519>/IfThenElse1' */
    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S519>/Constant11'
     *  Constant: '<S519>/Constant12'
     *  Constant: '<S519>/Constant13'
     *  Constant: '<S519>/Constant14'
     *  Constant: '<S519>/Constant15'
     *  Constant: '<S519>/Constant2'
     *  Constant: '<S519>/Constant3'
     *  Constant: '<S519>/Constant6'
     *  Constant: '<S522>/Constant'
     *  Constant: '<S523>/Constant'
     *  Constant: '<S524>/Constant'
     *  Constant: '<S525>/Constant'
     *  Constant: '<S526>/Constant'
     *  Constant: '<S527>/Constant'
     *  Logic: '<S519>/OR'
     *  Logic: '<S519>/OR3'
     *  RelationalOperator: '<S519>/Relational Operator'
     *  RelationalOperator: '<S522>/Compare'
     *  RelationalOperator: '<S523>/Compare'
     *  RelationalOperator: '<S524>/Compare'
     *  RelationalOperator: '<S525>/Compare'
     *  RelationalOperator: '<S526>/Compare'
     *  RelationalOperator: '<S527>/Compare'
     */
    Chery_E03_Hp_B.u8TWValve_BAT_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_7, rtb_Conversion_ea,
       rtb_Conversion_iok);

    /* End of Outputs for SubSystem: '<S519>/IfThenElse1' */

    /* Lookup_n-D: '<S565>/Table_HVCH_Pump1' */
    rtb_Conversion_d = look1_is16lu32n16tu16_binlcse
      (Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10, ((int16_T *)
        &(HP_u16Pump_HC_Twat.HP_s16Twat_HVCH_u1[0])), ((uint16_T *)
        &(HP_u16Pump_HC_Twat.HP_u16Pump_HC_Twat_y[0])), 4U);

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' */
    Chery_E03_Hp_B.u16Pump_HVCH_Req = rtb_Conversion_d;

    /* Outputs for Atomic SubSystem: '<S505>/IfThenElse1' */
    rtb_Conversion_d = (uint16_T) Chery_E03_Hp_IfThenElse1
      ((Chery_E03_Hp_B.bBTM_CoolReq_Yes) || (Chery_E03_Hp_B.bBTM_HeatReq_Yes),
       70, 0);

    /* End of Outputs for SubSystem: '<S505>/IfThenElse1' */

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S505>/Constant1'
     *  Constant: '<S505>/Constant2'
     *  Logic: '<S505>/OR'
     */
    Chery_E03_Hp_B.u16Pump_Bat_Req = rtb_Conversion_d;

    /* Outputs for Atomic SubSystem: '<S505>/IfThenElse2' */
    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S505>/Constant4'
     *  Constant: '<S505>/Constant5'
     *  Constant: '<S562>/Constant'
     *  RelationalOperator: '<S562>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Motor_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((int32_T)Chery_E03_Hp_B.HpI_u8Mot_CoolLv) == 1, 100, 0);

    /* End of Outputs for SubSystem: '<S505>/IfThenElse2' */

    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S510>/OutEva_SOV_Close1'
     */
    Chery_E03_Hp_B.bSOV_OutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* Outputs for Atomic SubSystem: '<S510>/IfThenElse2' */
    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S510>/OutEva_SOV_Close2'
     *  Constant: '<S510>/OutEva_SOV_Open1'
     *  Constant: '<S762>/Constant'
     *  RelationalOperator: '<S762>/Compare'
     */
    Chery_E03_Hp_B.bSOV_TXVOutEva_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_7, (uint8_T)(bSOV_OPEN_1
        ? 1U : 0U), (uint8_T)(bSOV_Close_0 ? 1U : 0U));

    /* End of Outputs for SubSystem: '<S510>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S520>/IfThenElse2' */
    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S520>/Constant4'
     *  Constant: '<S520>/Constant5'
     *  Constant: '<S543>/Constant'
     *  RelationalOperator: '<S543>/Compare'
     */
    Chery_E03_Hp_B.u8TWValve_HC_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_BatHeat_10, 50, 100);

    /* End of Outputs for SubSystem: '<S520>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S521>/IfThenElse6' */
    rtb_Conversion_m = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_CoolReq_Yes, 50, 100);

    /* End of Outputs for SubSystem: '<S521>/IfThenElse6' */

    /* Outputs for Atomic SubSystem: '<S521>/IfThenElse5' */
    rtb_Conversion_b = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_HeatReq_Yes) && (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 0, rtb_Conversion_m);

    /* End of Outputs for SubSystem: '<S521>/IfThenElse5' */

    /* Outputs for Atomic SubSystem: '<S521>/IfThenElse4' */
    rtb_Conversion_pz = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHIL_8, 100,
       rtb_Conversion_b);

    /* End of Outputs for SubSystem: '<S521>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S521>/IfThenElse3' */
    rtb_Conversion_hl = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_BatHeat_10) ||
        (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_MDCHIL_9)) ||
       (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHILMDCHIL_12), 0,
       rtb_Conversion_pz);

    /* End of Outputs for SubSystem: '<S521>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S521>/IfThenElse1' */
    /* SignalConversion: '<S339>/BusConversion_InsertedFor_Bus_Ctrl_Req_Outport_1_at_inport_0' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S521>/Constant1'
     *  Constant: '<S521>/Constant10'
     *  Constant: '<S521>/Constant2'
     *  Constant: '<S521>/Constant7'
     *  Constant: '<S521>/Constant8'
     *  Constant: '<S521>/Constant9'
     *  Constant: '<S546>/Constant'
     *  Constant: '<S547>/Constant'
     *  Constant: '<S548>/Constant'
     *  Constant: '<S549>/Constant'
     *  Constant: '<S550>/Constant'
     *  Constant: '<S551>/Constant'
     *  Logic: '<S521>/OR1'
     *  Logic: '<S521>/OR2'
     *  RelationalOperator: '<S546>/Compare'
     *  RelationalOperator: '<S547>/Compare'
     *  RelationalOperator: '<S548>/Compare'
     *  RelationalOperator: '<S549>/Compare'
     *  RelationalOperator: '<S550>/Compare'
     *  RelationalOperator: '<S551>/Compare'
     */
    Chery_E03_Hp_B.u8TWValve_LTR_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1, 0, rtb_Conversion_hl);

    /* End of Outputs for SubSystem: '<S521>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S655>/Hyster_Judge' */
    rtb_Switch2 = ( Chery_E03_Hp_Hyster_Judge1(200, (int16_T)
      (Chery_E03_Hp_B.s16Twater_Max_HP_Y - Chery_E03_Hp_B.Switch), 120,
      &Chery_E03_Hp_DW.Hyster_Judge_g, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S655>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S510>/IfThenElse' */
    rtb_Conversion_kz = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_7, (uint8_T)
       (bSOV_Close_0 ? 1U : 0U), (uint8_T)(bSOV_OPEN_1 ? 1U : 0U));

    /* End of Outputs for SubSystem: '<S510>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S510>/IfThenElse1' */
    rtb_Conversion_fxj = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HP_CHIL_8, (uint8_T)
       (bSOV_OPEN_1 ? 1U : 0U), (uint8_T)(bSOV_Close_0 ? 1U : 0U));

    /* End of Outputs for SubSystem: '<S510>/IfThenElse1' */

    /* Update for UnitDelay: '<S654>/Unit Delay' incorporates:
     *  Constant: '<S510>/Eva_SOV_Close'
     *  Constant: '<S510>/Eva_SOV_Open'
     *  Constant: '<S510>/OutEva_SOV_Close'
     *  Constant: '<S510>/OutEva_SOV_Open'
     *  Constant: '<S655>/Constant'
     *  Constant: '<S655>/Constant1'
     *  Constant: '<S760>/Constant'
     *  Constant: '<S761>/Constant'
     *  RelationalOperator: '<S760>/Compare'
     *  RelationalOperator: '<S761>/Compare'
     *  Sum: '<S655>/Sum'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_n = rtb_Conversion_dx;

    /* End of Outputs for SubSystem: '<S40>/HP_Mode' */
    break;

   case 5:
    if (Chery_E03_Hp_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S40>/HVCH Mode Ctrl' incorporates:
       *  ActionPort: '<S340>/Action Port'
       *
       * Block description for '<S40>/HVCH Mode Ctrl':
       *  chiller mode control
       */
      /* InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
       *  UnitDelay: '<S818>/Unit Delay'
       */
      Chery_E03_Hp_DW.UnitDelay_DSTATE_l = 0;

      /* End of InitializeConditions for SubSystem: '<S40>/HVCH Mode Ctrl' */

      /* SystemReset for IfAction SubSystem: '<S40>/HVCH Mode Ctrl' incorporates:
       *  ActionPort: '<S340>/Action Port'
       *
       * Block description for '<S40>/HVCH Mode Ctrl':
       *  chiller mode control
       */
      /* SystemReset for Atomic SubSystem: '<S817>/Hyster_Judge' */
      /* SystemReset for SwitchCase: '<S40>/Switch Case' */
      Chery_E03_Hp_Hyster_Judge1_Reset(&Chery_E03_Hp_DW.Hyster_Judge_o,
        Chery_E03_Hp_ConstP.pooled3);

      /* End of SystemReset for SubSystem: '<S817>/Hyster_Judge' */
      /* End of SystemReset for SubSystem: '<S40>/HVCH Mode Ctrl' */
    }

    /* Outputs for IfAction SubSystem: '<S40>/HVCH Mode Ctrl' incorporates:
     *  ActionPort: '<S340>/Action Port'
     *
     * Block description for '<S40>/HVCH Mode Ctrl':
     *  chiller mode control
     */
    /* Outputs for Atomic SubSystem: '<S776>/IfThenElse4' */
    rtb_Kp_Table_A10000 = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_3, 70, 0);

    /* End of Outputs for SubSystem: '<S776>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S776>/IfThenElse3' */
    rtb_Kp_Table_A10000 = (uint16_T) Chery_E03_Hp_IfThenElse2
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2, 60,
       rtb_Kp_Table_A10000);

    /* End of Outputs for SubSystem: '<S776>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S776>/IfThenElse2' */
    rtb_Kp_Table_A10000 = (uint16_T) Chery_E03_Hp_IfThenElse2
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTM_CycleL11) ||
       (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1), 50,
       rtb_Kp_Table_A10000);

    /* End of Outputs for SubSystem: '<S776>/IfThenElse2' */

    /* SignalConversion: '<S340>/Signal Copy9' incorporates:
     *  Constant: '<S776>/Pump_0%'
     *  Constant: '<S776>/Pump_100%'
     *  Constant: '<S776>/Pump_50%'
     *  Constant: '<S776>/Pump_80%'
     *  Constant: '<S782>/Constant'
     *  Constant: '<S783>/Constant'
     *  Constant: '<S784>/Constant'
     *  Constant: '<S785>/Constant'
     *  Logic: '<S776>/OR2'
     *  RelationalOperator: '<S782>/Compare'
     *  RelationalOperator: '<S783>/Compare'
     *  RelationalOperator: '<S784>/Compare'
     *  RelationalOperator: '<S785>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Bat_Req = rtb_Kp_Table_A10000;

    /* Switch: '<S777>/Switch' incorporates:
     *  Constant: '<S792>/Constant'
     *  Constant: '<S793>/Constant'
     *  Constant: '<S794>/Constant'
     *  Logic: '<S777>/Logical Operator'
     *  RelationalOperator: '<S792>/Compare'
     *  RelationalOperator: '<S793>/Compare'
     *  RelationalOperator: '<S794>/Compare'
     */
    if (((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_CMF_20) ||
         (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_CMF_BAT_22)) ||
        (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_BAT_21)) {
      /* SignalConversion: '<S340>/Signal Copy8' incorporates:
       *  Lookup_n-D: '<S777>/Table_HVCH_Pump'
       */
      Chery_E03_Hp_B.u16Pump_HVCH_Req = look1_is16lu32n16tu16_binlcse
        (Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10, ((int16_T *)
          &(HP_u16Pump_HC_Twat.HP_s16Twat_HVCH_u1[0])), ((uint16_T *)
          &(HP_u16Pump_HC_Twat.HP_u16Pump_HC_Twat_y[0])), 4U);
    } else {
      /* SignalConversion: '<S340>/Signal Copy8' incorporates:
       *  Constant: '<S777>/Constant1'
       */
      Chery_E03_Hp_B.u16Pump_HVCH_Req = 0U;
    }

    /* End of Switch: '<S777>/Switch' */

    /* Outputs for Atomic SubSystem: '<S778>/IfThenElse2' */
    /* SignalConversion: '<S340>/Signal Copy10' incorporates:
     *  Constant: '<S778>/Constant4'
     *  Constant: '<S778>/Constant5'
     *  Constant: '<S795>/Constant'
     *  RelationalOperator: '<S795>/Compare'
     */
    Chery_E03_Hp_B.u16Pump_Motor_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (((int32_T)Chery_E03_Hp_B.HpI_u8Mot_CoolLv) == 1, 100, 0);

    /* End of Outputs for SubSystem: '<S778>/IfThenElse2' */

    /* Switch: '<S780>/Switch2' incorporates:
     *  Constant: '<S780>/Constant2'
     *  Constant: '<S780>/Constant3'
     *  Constant: '<S800>/Constant'
     *  RelationalOperator: '<S800>/Compare'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_CMF_BAT_22) {
      rtb_bSOV_TXVOutEva_Req_f = Hp_u8TWV_HC_MiddlePos_Sokon;
    } else {
      rtb_bSOV_TXVOutEva_Req_f = Hp_u8TWV_HC_FullHot_Sokon;
    }

    /* End of Switch: '<S780>/Switch2' */

    /* Switch: '<S780>/Switch1' incorporates:
     *  Constant: '<S780>/Constant1'
     *  Constant: '<S799>/Constant'
     *  RelationalOperator: '<S799>/Compare'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_BAT_21) {
      rtb_bSOV_TXVOutEva_Req_f = Hp_u8TWV_HC_FullCool_Sokon;
    }

    /* End of Switch: '<S780>/Switch1' */

    /* Switch: '<S780>/Switch' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S798>/Constant'
     *  RelationalOperator: '<S798>/Compare'
     */
    if (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1) {
      /* SignalConversion: '<S340>/Signal Copy5' incorporates:
       *  Constant: '<S780>/Constant'
       */
      Chery_E03_Hp_B.u8TWValve_HC_Req = Hp_u8TWV_HC_FullHot_Sokon;
    } else {
      /* SignalConversion: '<S340>/Signal Copy5' */
      Chery_E03_Hp_B.u8TWValve_HC_Req = rtb_bSOV_TXVOutEva_Req_f;
    }

    /* End of Switch: '<S780>/Switch' */

    /* Outputs for Atomic SubSystem: '<S781>/IfThenElse1' */
    /* SignalConversion: '<S340>/Signal Copy6' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S781>/Constant2'
     *  Constant: '<S781>/Constant3'
     *  Constant: '<S801>/Constant'
     *  RelationalOperator: '<S801>/Compare'
     */
    Chery_E03_Hp_B.u8TWValve_LTR_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1, 100, 0);

    /* End of Outputs for SubSystem: '<S781>/IfThenElse1' */

    /* SignalConversion: '<S340>/Signal Copy7' incorporates:
     *  Constant: '<S779>/Constant6'
     */
    Chery_E03_Hp_B.u8TWValve_BAT_Req = 100U;

    /* SignalConversion: '<S340>/Signal Copy' incorporates:
     *  Constant: '<S770>/Constant'
     */
    Chery_E03_Hp_B.u16Ncomp_Rpm_Req = u16NCOMP_STOP_0;

    /* SignalConversion: '<S340>/Signal Copy2' incorporates:
     *  Constant: '<S771>/Constant'
     */
    Chery_E03_Hp_B.u16EXV_Chil_Pos_Req = 576U;

    /* SignalConversion: '<S340>/Signal Copy1' incorporates:
     *  Constant: '<S772>/Constant'
     */
    Chery_E03_Hp_B.u16EXV_Eva_Pos_Req = 576U;

    /* Outputs for Atomic SubSystem: '<S773>/IfThenElse1' */
    rtb_Conversion_h = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_CoolReq_Yes) || (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 100, 0);

    /* End of Outputs for SubSystem: '<S773>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S773>/IfThenElse' */
    /* SignalConversion: '<S340>/Signal Copy3' incorporates:
     *  Constant: '<S773>/AGS_0%_Close'
     *  Constant: '<S773>/AGS_0%_Close1'
     *  Constant: '<S773>/AGS_100%_Open'
     *  Constant: '<S804>/Constant'
     *  Constant: '<S805>/Constant'
     *  Logic: '<S773>/OR'
     *  Logic: '<S773>/OR1'
     *  RelationalOperator: '<S804>/Compare'
     *  RelationalOperator: '<S805>/Compare'
     */
    Chery_E03_Hp_B.u8AGS_Position_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_HeatReq_Yes) && (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 0, rtb_Conversion_h);

    /* End of Outputs for SubSystem: '<S773>/IfThenElse' */

    /* Outputs for Atomic SubSystem: '<S773>/IfThenElse3' */
    rtb_Conversion_np5 = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_CoolReq_Yes) || (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), (uint8_T)look2_iu16s16lu32n16tu16_binlcse
       ((uint16_T)Chery_E03_Hp_B.HpI_u8VehSpd, (int16_T)
        (Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 - Chery_E03_Hp_B.HpI_s16Tamb_A10),
        ((uint16_T *)&(AC_u16PWM_FAN_StopMode.AC_u16Vspd_FAN_u1[0])), ((int16_T *)
         &(AC_u16PWM_FAN_StopMode.AC_s16T_DeltaExtWater_u2[0])), ((uint16_T *)
         &(AC_u16PWM_FAN_StopMode.AC_u16PWM_FAN_StopMode_y[0])),
        Chery_E03_Hp_ConstP.pooled25, 7U), 0);

    /* End of Outputs for SubSystem: '<S773>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S773>/IfThenElse2' */
    /* SignalConversion: '<S340>/Signal Copy4' incorporates:
     *  Constant: '<S773>/AGS_0%_Close3'
     *  Constant: '<S773>/Front_FAN_Close'
     *  Constant: '<S806>/Constant'
     *  Constant: '<S807>/Constant'
     *  DataTypeConversion: '<S773>/Data Type Conversion'
     *  DataTypeConversion: '<S773>/Data Type Conversion1'
     *  Logic: '<S773>/OR2'
     *  Logic: '<S773>/OR3'
     *  Lookup_n-D: '<S773>/FAN_PWM_Calculatoin_AC'
     *  RelationalOperator: '<S806>/Compare'
     *  RelationalOperator: '<S807>/Compare'
     *  Sum: '<S773>/Sum'
     */
    Chery_E03_Hp_B.u8FRFAN_PWM_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.bBTM_HeatReq_Yes) && (Chery_E03_Hp_B.HpI_u8Mot_CoolLv ==
        ACPre_u8MotorCoolReq_Yes), 0, rtb_Conversion_np5);

    /* End of Outputs for SubSystem: '<S773>/IfThenElse2' */

    /* Switch: '<S816>/Switch1' incorporates:
     *  Constant: '<S816>/HVCH_Authority_No'
     *  Constant: '<S816>/HVCH_Authority_Yes'
     *  Constant: '<S819>/Constant'
     *  Constant: '<S820>/Constant'
     *  Constant: '<S821>/Constant'
     *  Logic: '<S816>/Logical Operator1'
     *  RelationalOperator: '<S819>/Compare'
     *  RelationalOperator: '<S820>/Compare'
     *  RelationalOperator: '<S821>/Compare'
     */
    if (((Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_CMF_20) ||
         (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_BAT_21)) ||
        (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_CMF_BAT_22)) {
      rtb_LowerRelop1_a = bCONST_1;
    } else {
      rtb_LowerRelop1_a = bCONST_0;
    }

    /* End of Switch: '<S816>/Switch1' */

    /* Product: '<S818>/Product3' incorporates:
     *  Constant: '<S818>/Amp_Rate1'
     */
    rtb_Sum2 = (int32_T)((uint32_T)(100U * ((uint32_T)u16AMP_10000)));

    /* Sum: '<S818>/Sum4' */
    rtb_Sum_i = (int16_T)(Chery_E03_Hp_B.Switch -
                          Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10);

    /* Saturate: '<S818>/Saturation1' incorporates:
     *  Sum: '<S818>/Sum4'
     */
    if (rtb_Sum_i > 300) {
      rtb_Sum_i = 300;
    } else {
      if (rtb_Sum_i < -500) {
        rtb_Sum_i = -500;
      }
    }

    /* End of Saturate: '<S818>/Saturation1' */

    /* Switch: '<S818>/Switch' incorporates:
     *  Constant: '<S818>/Constant'
     *  Constant: '<S826>/Constant'
     *  RelationalOperator: '<S826>/Compare'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1 == u8MODE_HVCH_BAT_21) {
      rtb_FAN_PWM_Calculatoin_AC_f = 300U;
    } else {
      rtb_FAN_PWM_Calculatoin_AC_f = Chery_E03_Hp_B.CMF_u16_QBlower_HVAC;
    }

    /* End of Switch: '<S818>/Switch' */

    /* Product: '<S818>/Product' incorporates:
     *  Lookup_n-D: '<S818>/Kp_Table_A10000'
     */
    rtb_Switch_oe = ((int32_T)look2_is16u16lu32n16tu16_binlcse(rtb_Sum_i,
      rtb_FAN_PWM_Calculatoin_AC_f, ((int16_T *)
      &(Flap_u16Kp_HVCH_A10000.Flap_s16TCtrlDelta_Coolant_u1[0])), ((uint16_T *)
      &(Flap_u16Kp_HVCH_A10000.Flap_u16_Qblower_HVCHCtrl_u2[0])), ((uint16_T *)
      &(Flap_u16Kp_HVCH_A10000.Flap_u16Kp_HVCH_A10000_y[0])),
      Chery_E03_Hp_ConstP.pooled24, 8U)) * ((int32_T)rtb_Sum_i);

    /* RelationalOperator: '<S829>/LowerRelop1' */
    rtb_LowerRelop1_j = (rtb_Switch_oe > rtb_Sum2);

    /* Switch: '<S829>/Switch' incorporates:
     *  Constant: '<S818>/0%_Percent'
     *  RelationalOperator: '<S829>/UpperRelop'
     */
    if (rtb_Switch_oe < 0) {
      rtb_Switch_oe = 0;
    }

    /* End of Switch: '<S829>/Switch' */

    /* Switch: '<S829>/Switch2' */
    if (rtb_LowerRelop1_j) {
      rtb_Switch_oe = rtb_Sum2;
    }

    /* End of Switch: '<S829>/Switch2' */

    /* Sum: '<S818>/Sum3' */
    rtb_Sum2 -= rtb_Switch_oe;

    /* UnitDelay: '<S818>/Unit Delay' */
    rtb_Divide = Chery_E03_Hp_DW.UnitDelay_DSTATE_l;

    /* Switch: '<S828>/Switch' incorporates:
     *  Constant: '<S818>/Constant2'
     *  RelationalOperator: '<S828>/UpperRelop'
     *  UnitDelay: '<S818>/Unit Delay'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_l < 0) {
      rtb_Divide = 0;
    }

    /* End of Switch: '<S828>/Switch' */

    /* Switch: '<S828>/Switch2' incorporates:
     *  RelationalOperator: '<S828>/LowerRelop1'
     *  UnitDelay: '<S818>/Unit Delay'
     */
    if (Chery_E03_Hp_DW.UnitDelay_DSTATE_l <= rtb_Sum2) {
      rtb_Sum2 = rtb_Divide;
    }

    /* End of Switch: '<S828>/Switch2' */

    /* Switch: '<S818>/Switch2' incorporates:
     *  Constant: '<S818>/Constant3'
     */
    if (!rtb_LowerRelop1_a) {
      rtb_Sum2 = 0;
    }

    /* End of Switch: '<S818>/Switch2' */

    /* Lookup_n-D: '<S818>/Kp_Table1' */
    rtb_FAN_PWM_Calculatoin_AC_f = look2_is16u16lu32n16tu16_binlcse(rtb_Sum_i,
      rtb_FAN_PWM_Calculatoin_AC_f, ((int16_T *)
      &(Flap_u16Ki_HVCH_A10000.Flap_s16TCtrlDelta_Coolant_u1[0])), ((uint16_T *)
      &(Flap_u16Ki_HVCH_A10000.Flap_u16_Qblower_HVCHCtrl_u2[0])), ((uint16_T *)
      &(Flap_u16Ki_HVCH_A10000.Flap_u16Ki_HVCH_A10000_y[0])),
      Chery_E03_Hp_ConstP.pooled24, 8U);

    /* Sum: '<S818>/Sum1' incorporates:
     *  Product: '<S818>/Product1'
     *  UnitDelay: '<S818>/Unit Delay'
     */
    Chery_E03_Hp_DW.UnitDelay_DSTATE_l = (((int32_T)rtb_FAN_PWM_Calculatoin_AC_f)
      * ((int32_T)rtb_Sum_i)) + rtb_Sum2;

    /* Sum: '<S818>/Sum2' incorporates:
     *  UnitDelay: '<S818>/Unit Delay'
     */
    rtb_Switch_oe += Chery_E03_Hp_DW.UnitDelay_DSTATE_l;

    /* Product: '<S818>/Product2' incorporates:
     *  Constant: '<S818>/Amp_Rate'
     */
    rtb_Divide = div_nde_s32_floor(rtb_Switch_oe, (int32_T)u16AMP_10000);

    /* Saturate: '<S818>/Saturation' */
    if (rtb_Divide > 100) {
      rtb_Divide = 100;
    } else {
      if (rtb_Divide < 0) {
        rtb_Divide = 0;
      }
    }

    /* End of Saturate: '<S818>/Saturation' */

    /* Outputs for Atomic SubSystem: '<S818>/IfThenElse1' */
    /* SignalConversion: '<S340>/Signal Copy11' incorporates:
     *  Constant: '<S818>/Constant4'
     */
    Chery_E03_Hp_B.u8HVCH_Req = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (rtb_LowerRelop1_a, (uint8_T)rtb_Divide, 0);

    /* End of Outputs for SubSystem: '<S818>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S817>/Hyster_Judge' */
    rtb_Switch2_m5 = ( Chery_E03_Hp_Hyster_Judge1(200, (int16_T)
      (Chery_E03_Hp_B.s16Twater_Max_HP_Y - Chery_E03_Hp_B.Switch), 120,
      &Chery_E03_Hp_DW.Hyster_Judge_o, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S817>/Hyster_Judge' */

    /* SignalConversion: '<S340>/Signal Copy12' incorporates:
     *  Constant: '<S775>/SOV_Eva_Close'
     *  Constant: '<S817>/Constant'
     *  Constant: '<S817>/Constant1'
     *  Sum: '<S817>/Sum'
     */
    Chery_E03_Hp_B.bSOV_Eva_Req = bSOV_Close_0 ? 1U : 0U;

    /* SignalConversion: '<S340>/Signal Copy13' incorporates:
     *  Constant: '<S775>/SOV_Open'
     */
    Chery_E03_Hp_B.bSOV_OutEva_Req = bSOV_OPEN_1 ? 1U : 0U;

    /* SignalConversion: '<S340>/Signal Copy14' incorporates:
     *  Constant: '<S775>/SOV_TXV_Close'
     */
    Chery_E03_Hp_B.bSOV_TXVOutEva_Req = bSOV_Close_0 ? 1U : 0U;

    /* End of Outputs for SubSystem: '<S40>/HVCH Mode Ctrl' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S40>/Switch Case' */
}

/* Output and update for atomic system: '<S1194>/IfThenElse' */
void Chery_E03_Hp_IfThenElse_j(boolean_T rtu_bIf, int64m_T rtu_Then, int64m_T
  rtu_Else, int64m_T *rty_Out)
{
  /* Switch: '<S1198>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S1199>/Conversion' */
    *rty_Out = rtu_Then;
  } else {
    /* DataTypeConversion: '<S1199>/Conversion' */
    *rty_Out = rtu_Else;
  }

  /* End of Switch: '<S1198>/Switch' */
}

/* Output and update for atomic system: '<S1192>/Divide_Safe' */
void Chery_E03_Hp_Divide_Safe_k(int64m_T rtu_x, int64m_T rtu_y, int64m_T
  *rty_out, const ConstB_Divide_Safe_Chery_E03_Hp_o_T *localC)
{
  int64m_T rtb_Conversion_aa;
  int96m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;

  /* Outputs for Atomic SubSystem: '<S1194>/IfThenElse' */

  /* RelationalOperator: '<S1196>/Compare' incorporates:
   *  Constant: '<S1196>/Constant'
   */
  Chery_E03_Hp_IfThenElse_j(sMultiWordNe(&rtu_y.chunks[0U],
    &Chery_E03_Hp_ConstP.pooled8.chunks[0], 2), rtu_y, localC->Conversion,
    &rtb_Conversion_aa);

  /* End of Outputs for SubSystem: '<S1194>/IfThenElse' */

  /* Product: '<S1194>/Divide' */
  tmp_0 = rtu_x;
  sMultiWordDivNear(&tmp_0.chunks[0U], 2, &rtb_Conversion_aa.chunks[0U], 2,
                    &tmp.chunks[0U], 3, &tmp_1.chunks[0U], 2, &tmp_2.chunks[0U],
                    2, &tmp_3.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp.chunks[0U], 3, &tmp_0.chunks[0U], 2);
  *rty_out = tmp_0;
}

/* Output and update for atomic system: '<S1192>/Divide_Safe1' */
void Chery_E03_Hp_Divide_Safe1(int64m_T rtu_x, uint16_T rtu_y, int64m_T *rty_out,
  const ConstB_Divide_Safe_Chery_E03_Hp_o3_T *localC)
{
  uint16_T rtb_Conversion_e1;
  int96m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  int64m_T tmp_4;

  /* Outputs for Atomic SubSystem: '<S1195>/IfThenElse' */

  /* RelationalOperator: '<S1200>/Compare' incorporates:
   *  Constant: '<S1200>/Constant'
   */
  rtb_Conversion_e1 = (uint16_T) Chery_E03_Hp_IfThenElse2(((int32_T)rtu_y) != 0,
    rtu_y, localC->Conversion);

  /* End of Outputs for SubSystem: '<S1195>/IfThenElse' */

  /* Product: '<S1195>/Divide' */
  tmp_0 = rtu_x;
  uLong2MultiWord((uint32_T)rtb_Conversion_e1, &tmp_1.chunks[0U], 2);
  sMultiWordDivNear(&tmp_0.chunks[0U], 2, &tmp_1.chunks[0U], 2, &tmp.chunks[0U],
                    3, &tmp_2.chunks[0U], 2, &tmp_3.chunks[0U], 2,
                    &tmp_4.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp.chunks[0U], 3, &tmp_0.chunks[0U], 2);
  *rty_out = tmp_0;
}

/* Output and update for atomic system: '<S1177>/FirOrderLinear_Filter_DoubleFactor_Amp' */
int16_T Chery_E03_Hp_FirOrderLinear_Filter_DoubleFactor_Amp(int16_T rtu_DataIn,
  boolean_T rtu_bFlagInit, uint8_T rtu_FilterFactor_INC, uint8_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Chery_E03_Hp_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Chery_E03_Hp_T *localDW)
{
  int16_T rty_FilterOut_0;
  int64m_T rtb_Product_n;
  int64m_T rtb_Divide_k;
  int64m_T rtb_Switch1_a;
  int64m_T rtb_Divide_d;
  int32_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int96m_T tmp_2;
  int96m_T tmp_3;

  /* Product: '<S1192>/Product' */
  sLong2MultiWord(((int32_T)rtu_DataIn) * ((int32_T)rtu_u16AmpNumVal),
                  &tmp_0.chunks[0U], 2);
  sMultiWordShl(&tmp_0.chunks[0U], 2, 16U, &rtb_Product_n.chunks[0U], 2);

  /* UnitDelay: '<S1192>/UnitDelay1' */
  rtb_Divide_k = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S1192>/Switch1' incorporates:
   *  RelationalOperator: '<S1192>/Relational Operator'
   *  UnitDelay: '<S1192>/UnitDelay2'
   */
  if (rtu_DataIn > localDW->UnitDelay2_DSTATE) {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_INC) << 16,
                    &rtb_Switch1_a.chunks[0U], 2);
  } else {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_DEC) << 16,
                    &rtb_Switch1_a.chunks[0U], 2);
  }

  /* End of Switch: '<S1192>/Switch1' */

  /* Sum: '<S1192>/Subtract1' incorporates:
   *  UnitDelay: '<S1192>/UnitDelay1'
   */
  tmp_0 = localDW->UnitDelay1_DSTATE;
  MultiWordSub(&rtb_Product_n.chunks[0U], &tmp_0.chunks[0U], &tmp_1.chunks[0U],
               2);

  /* Outputs for Atomic SubSystem: '<S1192>/Divide_Safe' */
  Chery_E03_Hp_Divide_Safe_k(tmp_1, rtb_Switch1_a, &rtb_Divide_d,
    &localC->Divide_Safe);

  /* End of Outputs for SubSystem: '<S1192>/Divide_Safe' */

  /* Switch: '<S1192>/Switch' incorporates:
   *  UnitDelay: '<S1192>/UnitDelay1'
   */
  if (rtu_bFlagInit) {
    localDW->UnitDelay1_DSTATE = rtb_Product_n;
  } else {
    /* Sum: '<S1192>/Add1' incorporates:
     *  UnitDelay: '<S1192>/UnitDelay1'
     */
    sMultiWord2MultiWord(&rtb_Divide_d.chunks[0U], 2, &tmp_3.chunks[0U], 3);
    sMultiWordShl(&tmp_3.chunks[0U], 3, 16U, &tmp_2.chunks[0U], 3);
    sMultiWord2MultiWord(&tmp_2.chunks[0U], 3, &tmp_0.chunks[0U], 2);
    MultiWordAdd(&tmp_0.chunks[0U], &rtb_Divide_k.chunks[0U],
                 &localDW->UnitDelay1_DSTATE.chunks[0U], 2);
  }

  /* End of Switch: '<S1192>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1192>/Divide_Safe1' */
  /* UnitDelay: '<S1192>/UnitDelay1' */
  Chery_E03_Hp_Divide_Safe1(localDW->UnitDelay1_DSTATE, rtu_u16AmpNumVal,
    &rtb_Divide_k, &localC->Divide_Safe1);

  /* End of Outputs for SubSystem: '<S1192>/Divide_Safe1' */

  /* DataTypeConversion: '<S1193>/Conversion' */
  sMultiWordShrNear(&rtb_Divide_k.chunks[0U], 2, 16U, &tmp_0.chunks[0U], 2);
  tmp = sMultiWord2sLongSat(&tmp_0.chunks[0U], 2);
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  rty_FilterOut_0 = (int16_T)tmp;

  /* Update for UnitDelay: '<S1192>/UnitDelay2' incorporates:
   *  DataTypeConversion: '<S1193>/Conversion'
   */
  localDW->UnitDelay2_DSTATE = (int16_T)tmp;
  return rty_FilterOut_0;
}

/* Output and update for atomic system: '<S1162>/FirOrderLinear_Filter5' */
int16_T Chery_E03_Hp_FirOrderLinear_Filter(int16_T rtu_DataIn, boolean_T
  rtu_bFlagInit, uint8_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Chery_E03_Hp_T *localC,
  DW_FirOrderLinear_Filter_Chery_E03_Hp_T *localDW, uint16_T rtp_AmpNumVal)
{
  int16_T rty_FilterOut_0;

  /* Outputs for Atomic SubSystem: '<S1177>/FirOrderLinear_Filter_DoubleFactor_Amp' */

  /* Constant: '<S1177>/Constant1' */
  rty_FilterOut_0 = (int16_T)
    Chery_E03_Hp_FirOrderLinear_Filter_DoubleFactor_Amp(rtu_DataIn,
    rtu_bFlagInit,
    localC->TmpSignalConversionAtFirOrderLinear_Filter_DoubleFactor_Amp,
    rtu_FilterFactor, rtp_AmpNumVal,
    &localC->FirOrderLinear_Filter_DoubleFactor_Amp,
    &localDW->FirOrderLinear_Filter_DoubleFactor_Amp);

  /* End of Outputs for SubSystem: '<S1177>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  return rty_FilterOut_0;
}

/*
 * Output and update for atomic system:
 *    '<S1169>/R134a_SatTempCal_P_A10'
 *    '<S1170>/R134a_SatTempCal_P_A10'
 *    '<S1171>/R134a_SatTempCal_P_A10'
 *    '<S1215>/R134a_SatTempCal_P_A10'
 *    '<S1217>/R134a_SatTempCal_P_A10'
 */
int16_T Chery_E03_Hp_R134a_SatTempCal_P_A10_(uint16_T rtu_u16P_A10)
{
  /* Lookup_n-D: '<S1212>/R134A_P_a10_T_a10_Table' */
  return look1_iu16lu32n16ts16Ds32_binlcn(rtu_u16P_A10,
    Chery_E03_Hp_ConstP.pooled80, Chery_E03_Hp_ConstP.pooled49, 28U);
}

/*
 * Output and update for atomic system: '<S1045>/SH_Chil_Outlet_Calculation'
 * Block description for: '<S1045>/SH_Chil_Outlet_Calculation'
 *   Super heating of the evaporator outlet/EDC Inlet calculation
 *   For the EXV calculation
 */
void Chery_E03_Hp_SH_Chil_Outlet_Calculation(void)
{
  int16_T rtb_R134A_P_a10_T_a10_Table;
  int32_T u0;

  /* Outputs for Atomic SubSystem: '<S1215>/R134a_SatTempCal_P_A10' */
  rtb_R134A_P_a10_T_a10_Table = (int16_T) Chery_E03_Hp_R134a_SatTempCal_P_A10_
    (Chery_E03_Hp_B.Hp_u16SH_CompInlet);

  /* End of Outputs for SubSystem: '<S1215>/R134a_SatTempCal_P_A10' */

  /* Saturate: '<S1215>/Saturation' incorporates:
   *  Sum: '<S1215>/Sub'
   */
  u0 = (int32_T)((int16_T)(Chery_E03_Hp_B.AC_s16Tairevaup_E -
    rtb_R134A_P_a10_T_a10_Table));
  if (u0 > ((int32_T)u16SH_UP_LIMIT)) {
    u0 = (int32_T)u16SH_UP_LIMIT;
  } else {
    if (u0 < ((int32_T)u16SH_LOW_LIMIT)) {
      u0 = (int32_T)u16SH_LOW_LIMIT;
    }
  }

  /* End of Saturate: '<S1215>/Saturation' */

  /* Gain: '<S1172>/Gain' */
  Chery_E03_Hp_B.Hp_u16SH_ChilOut = (uint16_T)u0;
}

/*
 * Output and update for atomic system: '<S1045>/SH_Comp_Inlet_Calculation'
 * Block description for: '<S1045>/SH_Comp_Inlet_Calculation'
 *   Super heating of the evaporator outlet/EDC Inlet calculation
 *   For the EXV calculation
 */
void Chery_E03_Hp_SH_Comp_Inlet_Calculation(void)
{
  int16_T rtb_R134A_P_a10_T_a10_Table;
  int32_T u0;

  /* Outputs for Atomic SubSystem: '<S1217>/R134a_SatTempCal_P_A10' */
  rtb_R134A_P_a10_T_a10_Table = (int16_T) Chery_E03_Hp_R134a_SatTempCal_P_A10_
    (Chery_E03_Hp_B.Hp_u16SH_CompInlet);

  /* End of Outputs for SubSystem: '<S1217>/R134a_SatTempCal_P_A10' */

  /* Saturate: '<S1217>/Saturation' incorporates:
   *  Sum: '<S1217>/Sub'
   */
  u0 = (int32_T)((int16_T)(Chery_E03_Hp_B.Conversion_p -
    rtb_R134A_P_a10_T_a10_Table));
  if (u0 > ((int32_T)u16SH_UP_LIMIT)) {
    u0 = (int32_T)u16SH_UP_LIMIT;
  } else {
    if (u0 < ((int32_T)u16SH_LOW_LIMIT)) {
      u0 = (int32_T)u16SH_LOW_LIMIT;
    }
  }

  /* End of Saturate: '<S1217>/Saturation' */

  /* Gain: '<S1173>/Gain' */
  Chery_E03_Hp_B.Hp_u16SH_CompInlet = (uint16_T)u0;
}

/* System initialize for atomic system: '<S1>/WorkingModeRequest' */
void Chery_E03_Hp_WorkingModeRequest_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_m,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_d,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge3' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge3,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge3' */

  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge2' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge2,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge2' */

  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge4' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge4,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge4' */

  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge5' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge5,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge5' */

  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge6' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge6,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge6' */

  /* SystemInitialize for Atomic SubSystem: '<S1259>/Hyster_Judge7' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge7,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1259>/Hyster_Judge7' */

  /* SystemInitialize for Atomic SubSystem: '<S42>/bAC_Cooling_Requirement_Check' */
  /* SystemInitialize for Atomic SubSystem: '<S1261>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge_i5,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1261>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S42>/bAC_Cooling_Requirement_Check' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Tamb_30_Mode_Req' */
  /* SystemInitialize for Atomic SubSystem: '<S1254>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_p,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1254>/Hyster_Judge1' */
  /* End of SystemInitialize for SubSystem: '<S42>/Tamb_30_Mode_Req' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Tamb_20_Mode_Req' */
  /* SystemInitialize for Atomic SubSystem: '<S1384>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_f,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1384>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1384>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_h,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1384>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1385>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_je,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1385>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S42>/Tamb_20_Mode_Req' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Tamb_15_Mode_Req' */
  /* SystemInitialize for Atomic SubSystem: '<S1339>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_hm,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1339>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1339>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_g,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1339>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1340>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_k,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1340>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1337>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_d3,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1337>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1337>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_i,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1337>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1337>/Hyster_Judge2' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge2_k,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1337>/Hyster_Judge2' */
  /* End of SystemInitialize for SubSystem: '<S42>/Tamb_15_Mode_Req' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Tamb_10_Mode_Req' */
  /* SystemInitialize for Atomic SubSystem: '<S1291>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_g5,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1291>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1291>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_e,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1291>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1292>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_c,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1292>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1289>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_o,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1289>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1289>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_mb,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1289>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1289>/Hyster_Judge2' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge2_g,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1289>/Hyster_Judge2' */
  /* End of SystemInitialize for SubSystem: '<S42>/Tamb_10_Mode_Req' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Tamb_5_Mode_Req' */
  /* SystemInitialize for Atomic SubSystem: '<S1425>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_go,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1425>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1425>/Hyster_Judge2' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge2_c,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1425>/Hyster_Judge2' */

  /* SystemInitialize for Atomic SubSystem: '<S1426>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_n,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1426>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1423>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_h0,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1423>/Hyster_Judge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1423>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_hw,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1423>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1423>/Hyster_Judge2' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge2_m,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1423>/Hyster_Judge2' */

  /* SystemInitialize for Atomic SubSystem: '<S1424>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_e,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1424>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S42>/Tamb_5_Mode_Req' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Tamb_0_Mode_Req' */
  /* SystemInitialize for Atomic SubSystem: '<S1264>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge_ie,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1264>/Hyster_Judge' */

  /* SystemInitialize for Atomic SubSystem: '<S1265>/Hyster_Judge1' */
  Chery_E03_Hp_Hyster_Judge1_Init(&Chery_E03_Hp_DW.Hyster_Judge1_ht,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1265>/Hyster_Judge1' */
  /* End of SystemInitialize for SubSystem: '<S42>/Tamb_0_Mode_Req' */

  /* SystemInitialize for Merge: '<S42>/Merge' */
  Chery_E03_Hp_B.Merge = 0U;
}

/*
 * Output and update for atomic system: '<S1>/WorkingModeRequest'
 * Block description for: '<S1>/WorkingModeRequest'
 *   Working Mode Request
 *   Working mode request according the AC Request and the Chiller request.
 */
void Chery_E03_Hp_WorkingModeRequest(void)
{
  boolean_T rtb_Switch2;
  boolean_T rtb_bAC_Cooling_Req;
  uint8_T rtb_Switch;
  uint8_T rtb_Conversion;
  boolean_T rtb_Switch2_ho;
  boolean_T rtb_Switch2_h3;
  boolean_T rtb_Switch2_fa;
  boolean_T rtb_Switch2_d4;
  boolean_T rtb_Switch2_e;
  boolean_T rtb_Switch2_ka0;
  boolean_T rtb_Switch2_fk;
  int16_T rtb_Conversion_j;
  boolean_T rtb_Switch2_ps;
  boolean_T rtb_Switch2_pa;
  uint8_T rtb_Conversion_m;
  uint8_T rtb_Conversion_mu5;
  uint8_T rtb_Conversion_l;
  uint8_T rtb_Conversion_lm;
  boolean_T rtb_Switch2_iyb;
  boolean_T rtb_Switch2_p;
  boolean_T rtb_Switch2_km;
  boolean_T rtb_Switch2_h;
  uint8_T rtb_Conversion_nv;
  uint8_T rtb_Conversion_ozy;
  uint8_T rtb_Conversion_hf;
  uint8_T rtb_Conversion_dxk;
  uint8_T rtb_Conversion_ej;
  uint8_T rtb_Conversion_d;
  boolean_T rtb_Switch2_owj;
  boolean_T rtb_Switch2_lg;
  boolean_T rtb_Switch2_mc;
  boolean_T rtb_Switch2_hb;
  uint8_T rtb_Conversion_h;
  uint8_T rtb_Conversion_k;
  uint8_T rtb_Conversion_ja;
  uint8_T rtb_Conversion_g4;
  uint8_T rtb_Conversion_f23;
  uint8_T rtb_Conversion_a;
  uint8_T rtb_Conversion_b;
  uint8_T rtb_Conversion_jf;
  uint8_T rtb_Conversion_g;
  uint8_T rtb_Conversion_cn;
  uint8_T rtb_Conversion_e;
  uint8_T rtb_Conversion_ci;
  uint8_T rtb_Conversion_hh;
  uint8_T rtb_Conversion_cx;
  uint8_T rtb_Conversion_n;
  uint8_T rtb_Conversion_krr;
  uint8_T rtb_Conversion_gs;
  uint8_T rtb_Conversion_nyz;
  uint8_T rtb_Conversion_pq;
  uint8_T rtb_Conversion_pc;
  uint8_T rtb_Conversion_kn;
  uint8_T rtb_Conversion_dyf;
  uint8_T rtb_Conversion_go;
  uint8_T rtb_Conversion_b4;
  uint8_T rtb_Conversion_jc;
  uint8_T rtb_Conversion_ml;
  uint8_T rtb_Conversion_gf;
  uint8_T rtb_Conversion_nl;
  uint8_T rtb_Conversion_mb;
  uint8_T rtb_Conversion_f5;
  uint8_T rtb_Conversion_h5f;
  uint8_T rtb_Conversion_pz;
  uint8_T rtb_Conversion_eq;
  uint8_T rtb_Conversion_hw;
  uint8_T rtb_Conversion_lu;
  uint8_T rtb_Conversion_by;
  uint8_T rtb_Conversion_eh;
  uint8_T rtb_Conversion_ir;
  uint8_T rtb_Conversion_er;
  uint8_T rtb_Conversion_kq;
  uint8_T rtb_Conversion_ppe;
  uint8_T rtb_Conversion_ni;
  uint8_T rtb_Conversion_pib;
  uint8_T rtb_Conversion_nc;
  uint8_T rtb_Conversion_kl;
  uint8_T rtb_Conversion_oi;
  uint8_T rtb_Conversion_gz;
  uint8_T rtb_Conversion_a3;
  uint8_T rtb_Conversion_fo;
  uint8_T rtb_Conversion_eg;
  uint8_T rtb_Conversion_bb;
  uint8_T rtb_Conversion_lg;
  uint8_T rtb_Conversion_au;
  uint8_T rtb_Conversion_dx;
  uint8_T rtb_Conversion_ge;
  uint8_T rtb_Conversion_in;
  uint8_T rtb_Conversion_kz;
  uint8_T rtb_Conversion_ny;
  uint8_T rtb_Conversion_e3;
  uint8_T rtb_Conversion_as;
  uint8_T rtb_Conversion_pd;
  uint8_T rtb_Conversion_ku;
  uint8_T rtb_Conversion_ft;
  uint8_T rtb_Conversion_j2s;
  uint8_T rtb_Conversion_md;
  uint8_T rtb_Conversion_ip;

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge' */
  /* Constant: '<S1259>/Constant' incorporates:
   *  Constant: '<S1259>/Constant1'
   */
  rtb_Switch2_ho = ( Chery_E03_Hp_Hyster_Judge1(300,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, 280, &Chery_E03_Hp_DW.Hyster_Judge_m,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge' */

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge1' */
  /* Constant: '<S1259>/Constant2' incorporates:
   *  Constant: '<S1259>/Constant3'
   */
  rtb_Switch2_h3 = ( Chery_E03_Hp_Hyster_Judge1(200,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, 180, &Chery_E03_Hp_DW.Hyster_Judge1_d,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge1' */

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge3' */
  /* Constant: '<S1259>/Constant6' incorporates:
   *  Constant: '<S1259>/Constant7'
   */
  rtb_Switch2_fa = ( Chery_E03_Hp_Hyster_Judge1(150,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, 130, &Chery_E03_Hp_DW.Hyster_Judge3,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge3' */

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge2' */
  /* Constant: '<S1259>/Constant4' incorporates:
   *  Constant: '<S1259>/Constant5'
   */
  rtb_Switch2_d4 = ( Chery_E03_Hp_Hyster_Judge1(100,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, 80, &Chery_E03_Hp_DW.Hyster_Judge2,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge2' */

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge4' */
  /* Constant: '<S1259>/Constant8' incorporates:
   *  Constant: '<S1259>/Constant9'
   */
  rtb_Switch2_e = ( Chery_E03_Hp_Hyster_Judge1(50,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, 30, &Chery_E03_Hp_DW.Hyster_Judge4,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge4' */

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge5' */
  /* Constant: '<S1259>/Constant10' incorporates:
   *  Constant: '<S1259>/Constant11'
   */
  rtb_Switch2_ka0 = ( Chery_E03_Hp_Hyster_Judge1(0,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, -20, &Chery_E03_Hp_DW.Hyster_Judge5,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge5' */

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge6' */
  /* Constant: '<S1259>/Constant12' incorporates:
   *  Constant: '<S1259>/Constant13'
   */
  rtb_Switch2_fk = ( Chery_E03_Hp_Hyster_Judge1(-80,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, -100, &Chery_E03_Hp_DW.Hyster_Judge6,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge6' */

  /* Outputs for Atomic SubSystem: '<S1259>/Hyster_Judge7' */
  /* Constant: '<S1259>/Constant14' incorporates:
   *  Constant: '<S1259>/Constant15'
   */
  rtb_Switch2 = ( Chery_E03_Hp_Hyster_Judge1(-160,
    Chery_E03_Hp_B.HpI_s16Tamb_A10, -180, &Chery_E03_Hp_DW.Hyster_Judge7,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1259>/Hyster_Judge7' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse7' */
  /* Constant: '<S1259>/Constant23' incorporates:
   *  Constant: '<S1259>/Constant24'
   */
  rtb_Conversion_j = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2, -180, -200);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse7' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse6' */
  /* Constant: '<S1259>/Constant22' */
  rtb_Conversion_j = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2_fk, -80,
    rtb_Conversion_j);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse6' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse5' */
  /* Constant: '<S1259>/Constant21' */
  rtb_Conversion_j = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2_ka0, 0,
    rtb_Conversion_j);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse5' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse4' */
  /* Constant: '<S1259>/Constant20' */
  rtb_Conversion_j = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2_e, 50,
    rtb_Conversion_j);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse4' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse3' */
  /* Constant: '<S1259>/Constant19' */
  rtb_Conversion_j = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2_d4, 100,
    rtb_Conversion_j);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse3' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse2' */
  /* Constant: '<S1259>/Constant18' */
  rtb_Conversion_j = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2_fa, 150,
    rtb_Conversion_j);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse2' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse1' */
  /* Constant: '<S1259>/Constant17' */
  rtb_Conversion_j = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2_h3, 200,
    rtb_Conversion_j);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S1259>/IfThenElse' */
  /* Constant: '<S1259>/Constant16' */
  Chery_E03_Hp_B.Conversion_p = (int16_T) Chery_E03_Hp_IfThenElse(rtb_Switch2_ho,
    300, rtb_Conversion_j);

  /* End of Outputs for SubSystem: '<S1259>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S42>/bAC_Cooling_Requirement_Check' */
  /* Outputs for Atomic SubSystem: '<S1261>/Hyster_Judge' */
  /* Constant: '<S1261>/Text_Uplimit_acmode_set' incorporates:
   *  Constant: '<S1261>/Text_downlumt_acmode_set'
   */
  rtb_Switch2 = ( Chery_E03_Hp_Hyster_Judge(70, Chery_E03_Hp_B.HpI_s16Tamb_A10,
    50, &Chery_E03_Hp_DW.Hyster_Judge_i5, Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1261>/Hyster_Judge' */

  /* Logic: '<S1261>/AND' incorporates:
   *  Constant: '<S1261>/Teva_set_uplimit'
   *  RelationalOperator: '<S1261>/RelationalOperator4'
   */
  rtb_bAC_Cooling_Req = ((rtb_Switch2 && (Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10 <=
    s16TEVA_UP_150)) && (Chery_E03_Hp_B.Conversion_a));

  /* End of Outputs for SubSystem: '<S42>/bAC_Cooling_Requirement_Check' */

  /* SwitchCase: '<S42>/Switch Case' incorporates:
   *  Constant: '<S1253>/Constant2'
   *  Constant: '<S1253>/Constant3'
   *  Constant: '<S1254>/Constant'
   *  Constant: '<S1254>/Constant2'
   *  Constant: '<S1254>/Constant3'
   *  Constant: '<S1254>/Constant4'
   *  Constant: '<S1254>/Constant5'
   *  Constant: '<S1254>/Constant6'
   *  Constant: '<S1254>/Constant7'
   *  Constant: '<S1264>/Constant'
   *  Constant: '<S1264>/Constant1'
   *  Constant: '<S1264>/Constant4'
   *  Constant: '<S1264>/Constant5'
   *  Constant: '<S1265>/Constant'
   *  Constant: '<S1265>/Constant1'
   *  Constant: '<S1265>/Constant2'
   *  Constant: '<S1265>/Constant3'
   *  Constant: '<S1265>/Constant4'
   *  Constant: '<S1265>/Constant9'
   *  Constant: '<S1272>/Constant'
   *  Constant: '<S1284>/Constant'
   *  Constant: '<S1285>/Constant'
   *  Constant: '<S1289>/Constant1'
   *  Constant: '<S1289>/Constant10'
   *  Constant: '<S1289>/Constant11'
   *  Constant: '<S1289>/Constant2'
   *  Constant: '<S1289>/Constant3'
   *  Constant: '<S1289>/Constant4'
   *  Constant: '<S1289>/Constant5'
   *  Constant: '<S1289>/Constant6'
   *  Constant: '<S1289>/Constant7'
   *  Constant: '<S1289>/Constant8'
   *  Constant: '<S1289>/Constant9'
   *  Constant: '<S1290>/Constant6'
   *  Constant: '<S1290>/Constant8'
   *  Constant: '<S1291>/Constant'
   *  Constant: '<S1291>/Constant1'
   *  Constant: '<S1291>/Constant2'
   *  Constant: '<S1291>/Constant3'
   *  Constant: '<S1291>/Constant4'
   *  Constant: '<S1291>/Constant5'
   *  Constant: '<S1291>/Constant6'
   *  Constant: '<S1292>/Constant1'
   *  Constant: '<S1292>/Constant2'
   *  Constant: '<S1292>/Constant5'
   *  Constant: '<S1292>/Constant6'
   *  Constant: '<S1333>/Constant'
   *  Constant: '<S1337>/Constant1'
   *  Constant: '<S1337>/Constant11'
   *  Constant: '<S1337>/Constant12'
   *  Constant: '<S1337>/Constant2'
   *  Constant: '<S1337>/Constant3'
   *  Constant: '<S1337>/Constant4'
   *  Constant: '<S1337>/Constant5'
   *  Constant: '<S1337>/Constant6'
   *  Constant: '<S1337>/Constant7'
   *  Constant: '<S1337>/Constant8'
   *  Constant: '<S1337>/Constant9'
   *  Constant: '<S1338>/Constant6'
   *  Constant: '<S1338>/Constant8'
   *  Constant: '<S1339>/Constant'
   *  Constant: '<S1339>/Constant1'
   *  Constant: '<S1339>/Constant2'
   *  Constant: '<S1339>/Constant3'
   *  Constant: '<S1339>/Constant4'
   *  Constant: '<S1339>/Constant5'
   *  Constant: '<S1339>/Constant6'
   *  Constant: '<S1340>/Constant1'
   *  Constant: '<S1340>/Constant2'
   *  Constant: '<S1340>/Constant5'
   *  Constant: '<S1340>/Constant6'
   *  Constant: '<S1384>/Constant'
   *  Constant: '<S1384>/Constant1'
   *  Constant: '<S1384>/Constant2'
   *  Constant: '<S1384>/Constant3'
   *  Constant: '<S1384>/Constant4'
   *  Constant: '<S1384>/Constant5'
   *  Constant: '<S1384>/Constant6'
   *  Constant: '<S1385>/Constant'
   *  Constant: '<S1385>/Constant4'
   *  Constant: '<S1385>/Constant5'
   *  Constant: '<S1385>/Constant6'
   *  Constant: '<S1418>/Constant'
   *  Constant: '<S1419>/Constant'
   *  Constant: '<S1423>/Constant'
   *  Constant: '<S1423>/Constant1'
   *  Constant: '<S1423>/Constant10'
   *  Constant: '<S1423>/Constant2'
   *  Constant: '<S1423>/Constant3'
   *  Constant: '<S1423>/Constant4'
   *  Constant: '<S1423>/Constant5'
   *  Constant: '<S1423>/Constant6'
   *  Constant: '<S1423>/Constant7'
   *  Constant: '<S1423>/Constant8'
   *  Constant: '<S1423>/Constant9'
   *  Constant: '<S1424>/Constant'
   *  Constant: '<S1424>/Constant1'
   *  Constant: '<S1424>/Constant4'
   *  Constant: '<S1424>/Constant5'
   *  Constant: '<S1424>/Constant8'
   *  Constant: '<S1425>/Constant1'
   *  Constant: '<S1425>/Constant2'
   *  Constant: '<S1425>/Constant3'
   *  Constant: '<S1425>/Constant4'
   *  Constant: '<S1425>/Constant7'
   *  Constant: '<S1425>/Constant8'
   *  Constant: '<S1425>/Constant9'
   *  Constant: '<S1426>/Constant'
   *  Constant: '<S1426>/Constant4'
   *  Constant: '<S1426>/Constant5'
   *  Constant: '<S1426>/Constant6'
   *  Constant: '<S1472>/Constant2'
   *  Constant: '<S1472>/Constant3'
   *  Constant: '<S1472>/Constant4'
   *  Constant: '<S1472>/Constant5'
   *  Constant: '<S1473>/Constant1'
   *  Constant: '<S1473>/Constant2'
   *  Constant: '<S1473>/Constant3'
   *  Constant: '<S1473>/Constant4'
   *  Constant: '<S1473>/Constant5'
   *  Constant: '<S1473>/Constant6'
   *  Constant: '<S1474>/Constant2'
   *  Constant: '<S1474>/Constant3'
   *  Constant: '<S1474>/Constant4'
   *  Constant: '<S1474>/Constant5'
   *  Constant: '<S1477>/Constant'
   *  Constant: '<S1487>/Constant'
   *  Constant: '<S1489>/Constant'
   *  Constant: '<S1490>/Constant'
   *  Constant: '<S1501>/Constant'
   *  Constant: '<S1511>/Constant2'
   *  Constant: '<S1511>/Constant3'
   *  Constant: '<S1511>/Constant4'
   *  Constant: '<S1511>/Constant5'
   *  Constant: '<S1512>/Constant1'
   *  Constant: '<S1512>/Constant2'
   *  Constant: '<S1512>/Constant3'
   *  Constant: '<S1512>/Constant4'
   *  Constant: '<S1512>/Constant5'
   *  Constant: '<S1512>/Constant6'
   *  Constant: '<S1513>/Constant2'
   *  Constant: '<S1513>/Constant3'
   *  Constant: '<S1513>/Constant4'
   *  Constant: '<S1513>/Constant5'
   *  Constant: '<S1516>/Constant'
   *  Constant: '<S1524>/Constant'
   *  Constant: '<S1526>/Constant'
   *  Constant: '<S1527>/Constant'
   *  Constant: '<S1538>/Constant'
   *  Constant: '<S1548>/Constant2'
   *  Constant: '<S1548>/Constant3'
   *  Constant: '<S1548>/Constant4'
   *  Constant: '<S1548>/Constant5'
   *  Constant: '<S1549>/Constant1'
   *  Constant: '<S1549>/Constant4'
   *  Constant: '<S1549>/Constant5'
   *  Constant: '<S1549>/Constant6'
   *  Constant: '<S1550>/Constant2'
   *  Constant: '<S1550>/Constant3'
   *  Constant: '<S1550>/Constant4'
   *  Constant: '<S1550>/Constant5'
   *  Constant: '<S1553>/Constant'
   *  Constant: '<S1561>/Constant'
   *  Constant: '<S1562>/Constant'
   *  Constant: '<S1569>/Constant'
   *  Logic: '<S1251>/OR'
   *  Logic: '<S1255>/OR'
   *  RelationalOperator: '<S1272>/Compare'
   *  RelationalOperator: '<S1283>/Compare'
   *  RelationalOperator: '<S1284>/Compare'
   *  RelationalOperator: '<S1285>/Compare'
   *  RelationalOperator: '<S1296>/Compare'
   *  RelationalOperator: '<S1332>/Compare'
   *  RelationalOperator: '<S1333>/Compare'
   *  RelationalOperator: '<S1344>/Compare'
   *  RelationalOperator: '<S1380>/Compare'
   *  RelationalOperator: '<S1417>/Compare'
   *  RelationalOperator: '<S1418>/Compare'
   *  RelationalOperator: '<S1419>/Compare'
   *  RelationalOperator: '<S1430>/Compare'
   *  RelationalOperator: '<S1477>/Compare'
   *  RelationalOperator: '<S1478>/Compare'
   *  RelationalOperator: '<S1487>/Compare'
   *  RelationalOperator: '<S1488>/Compare'
   *  RelationalOperator: '<S1489>/Compare'
   *  RelationalOperator: '<S1490>/Compare'
   *  RelationalOperator: '<S1501>/Compare'
   *  RelationalOperator: '<S1502>/Compare'
   *  RelationalOperator: '<S1516>/Compare'
   *  RelationalOperator: '<S1517>/Compare'
   *  RelationalOperator: '<S1524>/Compare'
   *  RelationalOperator: '<S1525>/Compare'
   *  RelationalOperator: '<S1526>/Compare'
   *  RelationalOperator: '<S1527>/Compare'
   *  RelationalOperator: '<S1538>/Compare'
   *  RelationalOperator: '<S1539>/Compare'
   *  RelationalOperator: '<S1553>/Compare'
   *  RelationalOperator: '<S1554>/Compare'
   *  RelationalOperator: '<S1561>/Compare'
   *  RelationalOperator: '<S1562>/Compare'
   *  RelationalOperator: '<S1569>/Compare'
   *  RelationalOperator: '<S1570>/Compare'
   *  Sum: '<S1254>/Sum1'
   *  Sum: '<S1264>/Sum'
   *  Sum: '<S1265>/Sum1'
   *  Sum: '<S1289>/Sum'
   *  Sum: '<S1289>/Sum1'
   *  Sum: '<S1289>/Sum2'
   *  Sum: '<S1291>/Sum'
   *  Sum: '<S1291>/Sum1'
   *  Sum: '<S1292>/Sum'
   *  Sum: '<S1337>/Sum'
   *  Sum: '<S1337>/Sum1'
   *  Sum: '<S1337>/Sum2'
   *  Sum: '<S1339>/Sum'
   *  Sum: '<S1339>/Sum1'
   *  Sum: '<S1340>/Sum'
   *  Sum: '<S1384>/Sum'
   *  Sum: '<S1384>/Sum1'
   *  Sum: '<S1385>/Sum'
   *  Sum: '<S1423>/Sum'
   *  Sum: '<S1423>/Sum1'
   *  Sum: '<S1423>/Sum2'
   *  Sum: '<S1424>/Sum'
   *  Sum: '<S1425>/Sum1'
   *  Sum: '<S1425>/Sum2'
   *  Sum: '<S1426>/Sum'
   */
  switch (Chery_E03_Hp_B.Conversion_p) {
   case 300:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_30_Mode_Req' incorporates:
     *  ActionPort: '<S1254>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1254>/Hyster_Judge1' */
    rtb_Switch2_pa = ( Chery_E03_Hp_Hyster_Judge1(50, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10), 0,
      &Chery_E03_Hp_DW.Hyster_Judge1_p, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1254>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1254>/IfThenElse3' */
    rtb_Conversion_lm = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_pa,
      u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1254>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1254>/IfThenElse1' */
    rtb_Conversion_hf = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_bAC_Cooling_Req,
      u8MODE_AC_1, rtb_Conversion_lm);

    /* End of Outputs for SubSystem: '<S1254>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1254>/IfThenElse2' */
    rtb_Conversion_d = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_bAC_Cooling_Req,
      u8MODE_ACCHILLER_2, u8MODE_CHILLER_3);

    /* End of Outputs for SubSystem: '<S1254>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1254>/IfThenElse' */
    /* SignalConversion: '<S1254>/OutportBufferForu8Mode_Req_Pre_Tamb30' incorporates:
     *  Constant: '<S1254>/Constant'
     *  Constant: '<S1254>/Constant2'
     *  Constant: '<S1254>/Constant3'
     *  Constant: '<S1254>/Constant4'
     *  Constant: '<S1254>/Constant5'
     *  Constant: '<S1254>/Constant6'
     *  Constant: '<S1254>/Constant7'
     *  RelationalOperator: '<S1404>/Compare'
     *  Sum: '<S1254>/Sum1'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_hf, rtb_Conversion_d);

    /* End of Outputs for SubSystem: '<S1254>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_30_Mode_Req' */
    break;

   case 200:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_20_Mode_Req' incorporates:
     *  ActionPort: '<S1253>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1384>/Hyster_Judge' */
    rtb_Switch2_iyb = ( Chery_E03_Hp_Hyster_Judge1(50, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), 0,
      &Chery_E03_Hp_DW.Hyster_Judge_f, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1384>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1384>/Hyster_Judge1' */
    rtb_Switch2_owj = ( Chery_E03_Hp_Hyster_Judge1(50, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10), 0,
      &Chery_E03_Hp_DW.Hyster_Judge1_h, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1384>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1384>/IfThenElse1' */
    rtb_Conversion_h = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_owj,
      u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1384>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1384>/IfThenElse3' */
    rtb_Conversion_jf = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_iyb,
      u8MODE_TotalDehum_5, rtb_Conversion_h);

    /* End of Outputs for SubSystem: '<S1384>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1385>/Hyster_Judge' */
    rtb_Switch2_owj = ( Chery_E03_Hp_Hyster_Judge1(50, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), 0,
      &Chery_E03_Hp_DW.Hyster_Judge_je, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1385>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1385>/IfThenElse3' */
    rtb_Conversion_pq = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_owj,
      u8MODE_TotalDehum_5, u8MODE_AC_1);

    /* End of Outputs for SubSystem: '<S1385>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1253>/IfThenElse1' */
    rtb_Conversion_go = (uint8_T) Chery_E03_Hp_IfThenElse_a(!rtb_bAC_Cooling_Req,
      rtb_Conversion_jf, rtb_Conversion_pq);

    /* End of Outputs for SubSystem: '<S1253>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1253>/IfThenElse2' */
    rtb_Conversion_nl = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_bAC_Cooling_Req,
      u8MODE_ACCHILLER_2, u8MODE_CHILLER_3);

    /* End of Outputs for SubSystem: '<S1253>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1253>/IfThenElse' */
    /* SignalConversion: '<S1253>/OutportBufferForu8Mode_Req_Pre_Tamb20' incorporates:
     *  Constant: '<S1253>/Constant2'
     *  Constant: '<S1253>/Constant3'
     *  Constant: '<S1384>/Constant'
     *  Constant: '<S1384>/Constant1'
     *  Constant: '<S1384>/Constant2'
     *  Constant: '<S1384>/Constant3'
     *  Constant: '<S1384>/Constant4'
     *  Constant: '<S1384>/Constant5'
     *  Constant: '<S1384>/Constant6'
     *  Constant: '<S1385>/Constant'
     *  Constant: '<S1385>/Constant4'
     *  Constant: '<S1385>/Constant5'
     *  Constant: '<S1385>/Constant6'
     *  RelationalOperator: '<S1379>/Compare'
     *  RelationalOperator: '<S1380>/Compare'
     *  Sum: '<S1384>/Sum'
     *  Sum: '<S1384>/Sum1'
     *  Sum: '<S1385>/Sum'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_go, rtb_Conversion_nl);

    /* End of Outputs for SubSystem: '<S1253>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_20_Mode_Req' */
    break;

   case 150:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_15_Mode_Req' incorporates:
     *  ActionPort: '<S1252>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1339>/Hyster_Judge' */
    rtb_Switch2_p = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge_hm, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1339>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1339>/Hyster_Judge1' */
    rtb_Switch2_lg = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge1_g,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1339>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1339>/IfThenElse1' */
    rtb_Conversion_k = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_lg,
      u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1339>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1339>/IfThenElse3' */
    rtb_Conversion_g = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_p,
      u8MODE_TotalDehum_5, rtb_Conversion_k);

    /* End of Outputs for SubSystem: '<S1339>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1340>/Hyster_Judge' */
    rtb_Switch2_lg = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge_k, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1340>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1340>/IfThenElse3' */
    rtb_Conversion_pc = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_lg,
      u8MODE_TotalDehum_5, u8MODE_AC_1);

    /* End of Outputs for SubSystem: '<S1340>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1252>/IfThenElse1' */
    rtb_Conversion_b4 = (uint8_T) Chery_E03_Hp_IfThenElse_a(!rtb_bAC_Cooling_Req,
      rtb_Conversion_g, rtb_Conversion_pc);

    /* End of Outputs for SubSystem: '<S1252>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1337>/Hyster_Judge1' */
    rtb_Switch2_p = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.s16Twater_Min_HP_Y),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge1_d3,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1337>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1337>/Hyster_Judge' */
    rtb_Switch2_lg = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge_i,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1337>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1337>/IfThenElse3' */
    rtb_Conversion_er = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_lg,
      u8MODE_CHILLER_3, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1337>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1337>/IfThenElse2' */
    rtb_Conversion_ni = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_p,
      u8MODE_HP_CHIL_8, rtb_Conversion_er);

    /* End of Outputs for SubSystem: '<S1337>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1337>/Hyster_Judge2' */
    rtb_Switch2_p = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge2_k, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1337>/Hyster_Judge2' */

    /* Outputs for Atomic SubSystem: '<S1337>/IfThenElse4' */
    rtb_Conversion_eg = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_p,
      u8MODE_TotalDehum_CHIL_6, u8MODE_ACCHILLER_2);

    /* End of Outputs for SubSystem: '<S1337>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1337>/IfThenElse1' */
    rtb_Conversion_bb = (uint8_T) Chery_E03_Hp_IfThenElse_a(!rtb_bAC_Cooling_Req,
      rtb_Conversion_ni, rtb_Conversion_eg);

    /* End of Outputs for SubSystem: '<S1337>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1338>/IfThenElse1' */
    rtb_Conversion_au = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_bAC_Cooling_Req,
      u8MODE_ACCHILLER_2, u8MODE_CHILLER_3);

    /* End of Outputs for SubSystem: '<S1338>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1252>/IfThenElse2' */
    rtb_Conversion_kz = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1, rtb_Conversion_bb,
       rtb_Conversion_au);

    /* End of Outputs for SubSystem: '<S1252>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1252>/IfThenElse' */
    /* SignalConversion: '<S1252>/OutportBufferForu8Mode_Req_Pre_Tamb15' incorporates:
     *  Constant: '<S1333>/Constant'
     *  Constant: '<S1337>/Constant1'
     *  Constant: '<S1337>/Constant11'
     *  Constant: '<S1337>/Constant12'
     *  Constant: '<S1337>/Constant2'
     *  Constant: '<S1337>/Constant3'
     *  Constant: '<S1337>/Constant4'
     *  Constant: '<S1337>/Constant5'
     *  Constant: '<S1337>/Constant6'
     *  Constant: '<S1337>/Constant7'
     *  Constant: '<S1337>/Constant8'
     *  Constant: '<S1337>/Constant9'
     *  Constant: '<S1338>/Constant6'
     *  Constant: '<S1338>/Constant8'
     *  Constant: '<S1339>/Constant'
     *  Constant: '<S1339>/Constant1'
     *  Constant: '<S1339>/Constant2'
     *  Constant: '<S1339>/Constant3'
     *  Constant: '<S1339>/Constant4'
     *  Constant: '<S1339>/Constant5'
     *  Constant: '<S1339>/Constant6'
     *  Constant: '<S1340>/Constant1'
     *  Constant: '<S1340>/Constant2'
     *  Constant: '<S1340>/Constant5'
     *  Constant: '<S1340>/Constant6'
     *  RelationalOperator: '<S1331>/Compare'
     *  RelationalOperator: '<S1332>/Compare'
     *  RelationalOperator: '<S1333>/Compare'
     *  RelationalOperator: '<S1344>/Compare'
     *  Sum: '<S1337>/Sum'
     *  Sum: '<S1337>/Sum1'
     *  Sum: '<S1337>/Sum2'
     *  Sum: '<S1339>/Sum'
     *  Sum: '<S1339>/Sum1'
     *  Sum: '<S1340>/Sum'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_b4, rtb_Conversion_kz);

    /* End of Outputs for SubSystem: '<S1252>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_15_Mode_Req' */
    break;

   case 100:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_10_Mode_Req' incorporates:
     *  ActionPort: '<S1251>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1291>/Hyster_Judge' */
    rtb_Switch2_km = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge_g5, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1291>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1291>/Hyster_Judge1' */
    rtb_Switch2_mc = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge1_e,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1291>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1291>/IfThenElse1' */
    rtb_Conversion_ja = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_mc,
      u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1291>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1291>/IfThenElse3' */
    rtb_Conversion_cn = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_km,
      u8MODE_TotalDehum_5, rtb_Conversion_ja);

    /* End of Outputs for SubSystem: '<S1291>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1292>/Hyster_Judge' */
    rtb_Switch2_mc = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge_c, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1292>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1292>/IfThenElse3' */
    rtb_Conversion_kn = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_mc,
      u8MODE_TotalDehum_5, u8MODE_AC_1);

    /* End of Outputs for SubSystem: '<S1292>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1251>/IfThenElse1' */
    rtb_Conversion_jc = (uint8_T) Chery_E03_Hp_IfThenElse_a(!rtb_bAC_Cooling_Req,
      rtb_Conversion_cn, rtb_Conversion_kn);

    /* End of Outputs for SubSystem: '<S1251>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1289>/Hyster_Judge1' */
    rtb_Switch2_km = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.s16Twater_Min_HP_Y),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge1_o,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1289>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1289>/Hyster_Judge' */
    rtb_Switch2_mc = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge_mb,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1289>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1289>/IfThenElse3' */
    rtb_Conversion_kl = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_mc,
      u8MODE_CHILLER_3, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1289>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1289>/IfThenElse2' */
    rtb_Conversion_a3 = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_km,
      u8MODE_HP_CHIL_8, rtb_Conversion_kl);

    /* End of Outputs for SubSystem: '<S1289>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1289>/Hyster_Judge2' */
    rtb_Switch2_km = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge2_g, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1289>/Hyster_Judge2' */

    /* Outputs for Atomic SubSystem: '<S1289>/IfThenElse4' */
    rtb_Conversion_dx = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_km,
      u8MODE_TotalDehum_CHIL_6, u8MODE_ACCHILLER_2);

    /* End of Outputs for SubSystem: '<S1289>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1289>/IfThenElse1' */
    rtb_Conversion_ny = (uint8_T) Chery_E03_Hp_IfThenElse_a(!rtb_bAC_Cooling_Req,
      rtb_Conversion_a3, rtb_Conversion_dx);

    /* End of Outputs for SubSystem: '<S1289>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1290>/IfThenElse1' */
    rtb_Conversion_pd = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_bAC_Cooling_Req,
      u8MODE_ACCHILLER_2, u8MODE_CHILLER_3);

    /* End of Outputs for SubSystem: '<S1290>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1251>/IfThenElse2' */
    rtb_Conversion_ft = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2) ||
       (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1), rtb_Conversion_ny,
       rtb_Conversion_pd);

    /* End of Outputs for SubSystem: '<S1251>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1251>/IfThenElse' */
    /* SignalConversion: '<S1251>/OutportBufferForu8Mode_Req_Pre_Tamb10' incorporates:
     *  Constant: '<S1284>/Constant'
     *  Constant: '<S1285>/Constant'
     *  Constant: '<S1289>/Constant1'
     *  Constant: '<S1289>/Constant10'
     *  Constant: '<S1289>/Constant11'
     *  Constant: '<S1289>/Constant2'
     *  Constant: '<S1289>/Constant3'
     *  Constant: '<S1289>/Constant4'
     *  Constant: '<S1289>/Constant5'
     *  Constant: '<S1289>/Constant6'
     *  Constant: '<S1289>/Constant7'
     *  Constant: '<S1289>/Constant8'
     *  Constant: '<S1289>/Constant9'
     *  Constant: '<S1290>/Constant6'
     *  Constant: '<S1290>/Constant8'
     *  Constant: '<S1291>/Constant'
     *  Constant: '<S1291>/Constant1'
     *  Constant: '<S1291>/Constant2'
     *  Constant: '<S1291>/Constant3'
     *  Constant: '<S1291>/Constant4'
     *  Constant: '<S1291>/Constant5'
     *  Constant: '<S1291>/Constant6'
     *  Constant: '<S1292>/Constant1'
     *  Constant: '<S1292>/Constant2'
     *  Constant: '<S1292>/Constant5'
     *  Constant: '<S1292>/Constant6'
     *  Logic: '<S1251>/OR'
     *  RelationalOperator: '<S1282>/Compare'
     *  RelationalOperator: '<S1283>/Compare'
     *  RelationalOperator: '<S1284>/Compare'
     *  RelationalOperator: '<S1285>/Compare'
     *  RelationalOperator: '<S1296>/Compare'
     *  Sum: '<S1289>/Sum'
     *  Sum: '<S1289>/Sum1'
     *  Sum: '<S1289>/Sum2'
     *  Sum: '<S1291>/Sum'
     *  Sum: '<S1291>/Sum1'
     *  Sum: '<S1292>/Sum'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_jc, rtb_Conversion_ft);

    /* End of Outputs for SubSystem: '<S1251>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_10_Mode_Req' */
    break;

   case 50:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_5_Mode_Req' incorporates:
     *  ActionPort: '<S1255>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1425>/Hyster_Judge1' */
    rtb_Switch2_h = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.s16Twater_Min_HP_Y),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge1_go,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1425>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1425>/Hyster_Judge2' */
    rtb_Switch2_hb = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge2_c,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1425>/Hyster_Judge2' */

    /* Outputs for Atomic SubSystem: '<S1425>/IfThenElse1' */
    rtb_Conversion_g4 = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_hb,
      u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1425>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1425>/IfThenElse4' */
    rtb_Conversion_e = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_h,
      u8MODE_HP_7, rtb_Conversion_g4);

    /* End of Outputs for SubSystem: '<S1425>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1426>/Hyster_Judge' */
    rtb_Switch2_hb = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge_n, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1426>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1426>/IfThenElse3' */
    rtb_Conversion_dyf = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_hb,
      u8MODE_TotalDehum_5, u8MODE_AC_1);

    /* End of Outputs for SubSystem: '<S1426>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1255>/IfThenElse1' */
    rtb_Conversion_ml = (uint8_T) Chery_E03_Hp_IfThenElse_a(!rtb_bAC_Cooling_Req,
      rtb_Conversion_e, rtb_Conversion_dyf);

    /* End of Outputs for SubSystem: '<S1255>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1423>/Hyster_Judge1' */
    rtb_Switch2_h = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.s16Twater_Min_HP_Y),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge1_h0,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1423>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1423>/Hyster_Judge' */
    rtb_Switch2_hb = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge_hw,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1423>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1423>/IfThenElse3' */
    rtb_Conversion_oi = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_hb,
      u8MODE_CHILLER_3, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1423>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1423>/IfThenElse2' */
    rtb_Conversion_fo = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_h,
      u8MODE_HP_CHIL_8, rtb_Conversion_oi);

    /* End of Outputs for SubSystem: '<S1423>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1423>/Hyster_Judge2' */
    rtb_Switch2_h = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
       Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y), ACPre_s16Temp_Hys_Down,
      &Chery_E03_Hp_DW.Hyster_Judge2_m, Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1423>/Hyster_Judge2' */

    /* Outputs for Atomic SubSystem: '<S1423>/IfThenElse4' */
    rtb_Conversion_ge = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_h,
      u8MODE_TotalDehum_CHIL_6, u8MODE_ACCHILLER_2);

    /* End of Outputs for SubSystem: '<S1423>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1423>/IfThenElse1' */
    rtb_Conversion_e3 = (uint8_T) Chery_E03_Hp_IfThenElse_a(!rtb_bAC_Cooling_Req,
      rtb_Conversion_fo, rtb_Conversion_ge);

    /* End of Outputs for SubSystem: '<S1423>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1424>/Hyster_Judge' */
    rtb_Switch2_h = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge_e,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1424>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1424>/IfThenElse3' */
    rtb_Conversion_j2s = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_h,
      u8MODE_CHILLER_3, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1424>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1424>/IfThenElse1' */
    rtb_Conversion_md = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_bAC_Cooling_Req,
      u8MODE_ACCHILLER_2, rtb_Conversion_j2s);

    /* End of Outputs for SubSystem: '<S1424>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1255>/IfThenElse2' */
    rtb_Conversion_ip = (uint8_T) Chery_E03_Hp_IfThenElse_a
      ((Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2) ||
       (Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1), rtb_Conversion_e3,
       rtb_Conversion_md);

    /* End of Outputs for SubSystem: '<S1255>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1255>/IfThenElse' */
    /* SignalConversion: '<S1255>/OutportBufferForu8Mode_Req_Pre_Tamb5' incorporates:
     *  Constant: '<S1418>/Constant'
     *  Constant: '<S1419>/Constant'
     *  Constant: '<S1423>/Constant'
     *  Constant: '<S1423>/Constant1'
     *  Constant: '<S1423>/Constant10'
     *  Constant: '<S1423>/Constant2'
     *  Constant: '<S1423>/Constant3'
     *  Constant: '<S1423>/Constant4'
     *  Constant: '<S1423>/Constant5'
     *  Constant: '<S1423>/Constant6'
     *  Constant: '<S1423>/Constant7'
     *  Constant: '<S1423>/Constant8'
     *  Constant: '<S1423>/Constant9'
     *  Constant: '<S1424>/Constant'
     *  Constant: '<S1424>/Constant1'
     *  Constant: '<S1424>/Constant4'
     *  Constant: '<S1424>/Constant5'
     *  Constant: '<S1424>/Constant8'
     *  Constant: '<S1425>/Constant1'
     *  Constant: '<S1425>/Constant2'
     *  Constant: '<S1425>/Constant3'
     *  Constant: '<S1425>/Constant4'
     *  Constant: '<S1425>/Constant7'
     *  Constant: '<S1425>/Constant8'
     *  Constant: '<S1425>/Constant9'
     *  Constant: '<S1426>/Constant'
     *  Constant: '<S1426>/Constant4'
     *  Constant: '<S1426>/Constant5'
     *  Constant: '<S1426>/Constant6'
     *  Logic: '<S1255>/OR'
     *  RelationalOperator: '<S1416>/Compare'
     *  RelationalOperator: '<S1417>/Compare'
     *  RelationalOperator: '<S1418>/Compare'
     *  RelationalOperator: '<S1419>/Compare'
     *  RelationalOperator: '<S1430>/Compare'
     *  Sum: '<S1423>/Sum'
     *  Sum: '<S1423>/Sum1'
     *  Sum: '<S1423>/Sum2'
     *  Sum: '<S1424>/Sum'
     *  Sum: '<S1425>/Sum1'
     *  Sum: '<S1425>/Sum2'
     *  Sum: '<S1426>/Sum'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_ml, rtb_Conversion_ip);

    /* End of Outputs for SubSystem: '<S1255>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_5_Mode_Req' */
    break;

   case 0:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_0_Mode_Req' incorporates:
     *  ActionPort: '<S1250>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1264>/Hyster_Judge' */
    rtb_Switch2_ps = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.HpI_s16Tamb_A10),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge_ie,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1264>/Hyster_Judge' */

    /* Outputs for Atomic SubSystem: '<S1264>/IfThenElse3' */
    rtb_Conversion_m = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_ps,
      u8MODE_HP_7, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1264>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1265>/Hyster_Judge1' */
    rtb_Switch2_ps = ( Chery_E03_Hp_Hyster_Judge1(ACPre_s16Temp_Hys_Up, (int16_T)
      (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.s16Twater_Min_HP_Y),
      ACPre_s16Temp_Hys_Down, &Chery_E03_Hp_DW.Hyster_Judge1_ht,
      Chery_E03_Hp_ConstP.pooled4) != false);

    /* End of Outputs for SubSystem: '<S1265>/Hyster_Judge1' */

    /* Outputs for Atomic SubSystem: '<S1265>/IfThenElse1' */
    rtb_Conversion_f23 = (uint8_T) Chery_E03_Hp_IfThenElse_a(((int32_T)
      Chery_E03_Hp_B.HpI_u8Mot_CoolLv) == 1, u8MODE_HP_MDCHIL_9, u8MODE_HP_7);

    /* End of Outputs for SubSystem: '<S1265>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1265>/IfThenElse2' */
    rtb_Conversion_ci = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1265>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1265>/IfThenElse4' */
    rtb_Conversion_n = (uint8_T) Chery_E03_Hp_IfThenElse_a(rtb_Switch2_ps,
      rtb_Conversion_f23, rtb_Conversion_ci);

    /* End of Outputs for SubSystem: '<S1265>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1250>/IfThenElse' */
    /* SignalConversion: '<S1250>/OutportBufferForu8Mode_Req_Pre_Tamb0' incorporates:
     *  Constant: '<S1264>/Constant'
     *  Constant: '<S1264>/Constant1'
     *  Constant: '<S1264>/Constant4'
     *  Constant: '<S1264>/Constant5'
     *  Constant: '<S1265>/Constant'
     *  Constant: '<S1265>/Constant1'
     *  Constant: '<S1265>/Constant2'
     *  Constant: '<S1265>/Constant3'
     *  Constant: '<S1265>/Constant4'
     *  Constant: '<S1265>/Constant9'
     *  Constant: '<S1272>/Constant'
     *  RelationalOperator: '<S1272>/Compare'
     *  Sum: '<S1264>/Sum'
     *  Sum: '<S1265>/Sum1'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_m, rtb_Conversion_n);

    /* End of Outputs for SubSystem: '<S1250>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_0_Mode_Req' */
    break;

   case -80:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_M10_Mode_Req' incorporates:
     *  ActionPort: '<S1256>/Action Port'
     */
    /* Switch: '<S1483>/Switch' incorporates:
     *  Constant: '<S1483>/Constant1'
     *  Constant: '<S1483>/Constant4'
     */
    if (Chery_E03_Hp_B.bFlag_Cmf_NoHeatingReq) {
      rtb_Switch = u8MODE_CHILLER_3;
    } else {
      rtb_Switch = u8MODE_HP_CHIL_8;
    }

    /* End of Switch: '<S1483>/Switch' */

    /* Outputs for Atomic SubSystem: '<S1472>/IfThenElse1' */
    rtb_Conversion_a = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HP_CHILMDCHIL_12, u8MODE_HP_CHIL_8);

    /* End of Outputs for SubSystem: '<S1472>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1472>/IfThenElse2' */
    rtb_Conversion_hh = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1472>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1472>/IfThenElse3' */
    rtb_Conversion = (uint8_T) Chery_E03_Hp_IfThenElse_a(!Chery_E03_Hp_B.Switch2,
      rtb_Conversion_a, rtb_Conversion_hh);

    /* End of Outputs for SubSystem: '<S1472>/IfThenElse3' */

    /* Switch: '<S1472>/Switch' incorporates:
     *  Constant: '<S1472>/Constant2'
     *  Constant: '<S1472>/Constant3'
     *  Constant: '<S1472>/Constant4'
     *  Constant: '<S1472>/Constant5'
     *  Constant: '<S1477>/Constant'
     *  Constant: '<S1479>/Constant'
     *  Constant: '<S41>/Constant'
     *  RelationalOperator: '<S1477>/Compare'
     *  RelationalOperator: '<S1478>/Compare'
     *  RelationalOperator: '<S1479>/Compare'
     */
    if (ACPre_u8Project_CheryE03 != ACPre_u8Project_SokonX1) {
      rtb_Switch = rtb_Conversion;
    }

    /* End of Switch: '<S1472>/Switch' */

    /* Outputs for Atomic SubSystem: '<S1473>/IfThenElse1' */
    rtb_Conversion_eq = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes, u8MODE_HP_7,
       u8MODE_HP_BatHeat_10);

    /* End of Outputs for SubSystem: '<S1473>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1473>/IfThenElse4' */
    rtb_Conversion_by = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HVCH_CMF_20, u8MODE_HVCH_CMF_BAT_22);

    /* End of Outputs for SubSystem: '<S1473>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1473>/IfThenElse5' */
    rtb_Conversion_kq = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_STOP_0, u8MODE_HVCH_BAT_21);

    /* End of Outputs for SubSystem: '<S1473>/IfThenElse5' */

    /* Outputs for Atomic SubSystem: '<S1473>/IfThenElse2' */
    rtb_Conversion_pib = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, rtb_Conversion_by, rtb_Conversion_kq);

    /* End of Outputs for SubSystem: '<S1473>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1473>/IfThenElse3' */
    rtb_Conversion_gz = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.Switch2, rtb_Conversion_eq, rtb_Conversion_pib);

    /* End of Outputs for SubSystem: '<S1473>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1474>/IfThenElse1' */
    rtb_Conversion_lg = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HP_MDCHIL_9, u8MODE_HP_7);

    /* End of Outputs for SubSystem: '<S1474>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1474>/IfThenElse2' */
    rtb_Conversion_in = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1474>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1474>/IfThenElse3' */
    rtb_Conversion_as = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.Switch2, rtb_Conversion_lg, rtb_Conversion_in);

    /* End of Outputs for SubSystem: '<S1474>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1256>/IfThenElse1' */
    rtb_Conversion_ku = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_HeatReq_Yes, rtb_Conversion_gz, rtb_Conversion_as);

    /* End of Outputs for SubSystem: '<S1256>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1256>/IfThenElse' */
    /* SignalConversion: '<S1256>/OutportBufferForu8Mode_Req_Pre_TambM10' incorporates:
     *  Constant: '<S1473>/Constant1'
     *  Constant: '<S1473>/Constant2'
     *  Constant: '<S1473>/Constant3'
     *  Constant: '<S1473>/Constant4'
     *  Constant: '<S1473>/Constant5'
     *  Constant: '<S1473>/Constant6'
     *  Constant: '<S1474>/Constant2'
     *  Constant: '<S1474>/Constant3'
     *  Constant: '<S1474>/Constant4'
     *  Constant: '<S1474>/Constant5'
     *  Constant: '<S1487>/Constant'
     *  Constant: '<S1489>/Constant'
     *  Constant: '<S1490>/Constant'
     *  Constant: '<S1501>/Constant'
     *  RelationalOperator: '<S1487>/Compare'
     *  RelationalOperator: '<S1488>/Compare'
     *  RelationalOperator: '<S1489>/Compare'
     *  RelationalOperator: '<S1490>/Compare'
     *  RelationalOperator: '<S1501>/Compare'
     *  RelationalOperator: '<S1502>/Compare'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Switch, rtb_Conversion_ku);

    /* End of Outputs for SubSystem: '<S1256>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_M10_Mode_Req' */
    break;

   case -180:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_M18_Mode_Req' incorporates:
     *  ActionPort: '<S1257>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1511>/IfThenElse1' */
    rtb_Conversion_mu5 = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HP_CHILMDCHIL_12, u8MODE_HP_CHIL_8);

    /* End of Outputs for SubSystem: '<S1511>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1511>/IfThenElse2' */
    rtb_Conversion_nv = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1511>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1511>/IfThenElse3' */
    rtb_Conversion_dxk = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.Switch2, rtb_Conversion_mu5, rtb_Conversion_nv);

    /* End of Outputs for SubSystem: '<S1511>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1512>/IfThenElse1' */
    rtb_Conversion_cx = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes, u8MODE_HP_7,
       u8MODE_HP_BatHeat_10);

    /* End of Outputs for SubSystem: '<S1512>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1512>/IfThenElse4' */
    rtb_Conversion_gs = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HVCH_CMF_20, u8MODE_HVCH_CMF_BAT_22);

    /* End of Outputs for SubSystem: '<S1512>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1512>/IfThenElse5' */
    rtb_Conversion_gf = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_STOP_0, u8MODE_HVCH_BAT_21);

    /* End of Outputs for SubSystem: '<S1512>/IfThenElse5' */

    /* Outputs for Atomic SubSystem: '<S1512>/IfThenElse2' */
    rtb_Conversion_mb = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, rtb_Conversion_gs, rtb_Conversion_gf);

    /* End of Outputs for SubSystem: '<S1512>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1512>/IfThenElse3' */
    rtb_Conversion_h5f = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.Switch2, rtb_Conversion_cx, rtb_Conversion_mb);

    /* End of Outputs for SubSystem: '<S1512>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1513>/IfThenElse1' */
    rtb_Conversion_eh = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HP_MDCHIL_9, u8MODE_HP_7);

    /* End of Outputs for SubSystem: '<S1513>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1513>/IfThenElse2' */
    rtb_Conversion_ir = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1513>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1513>/IfThenElse3' */
    rtb_Conversion_ppe = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.Switch2, rtb_Conversion_eh, rtb_Conversion_ir);

    /* End of Outputs for SubSystem: '<S1513>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1257>/IfThenElse1' */
    rtb_Conversion_nc = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_HeatReq_Yes, rtb_Conversion_h5f, rtb_Conversion_ppe);

    /* End of Outputs for SubSystem: '<S1257>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1257>/IfThenElse' */
    /* SignalConversion: '<S1257>/OutportBufferForu8Mode_Req_Pre_TambM18' incorporates:
     *  Constant: '<S1511>/Constant2'
     *  Constant: '<S1511>/Constant3'
     *  Constant: '<S1511>/Constant4'
     *  Constant: '<S1511>/Constant5'
     *  Constant: '<S1512>/Constant1'
     *  Constant: '<S1512>/Constant2'
     *  Constant: '<S1512>/Constant3'
     *  Constant: '<S1512>/Constant4'
     *  Constant: '<S1512>/Constant5'
     *  Constant: '<S1512>/Constant6'
     *  Constant: '<S1513>/Constant2'
     *  Constant: '<S1513>/Constant3'
     *  Constant: '<S1513>/Constant4'
     *  Constant: '<S1513>/Constant5'
     *  Constant: '<S1516>/Constant'
     *  Constant: '<S1524>/Constant'
     *  Constant: '<S1526>/Constant'
     *  Constant: '<S1527>/Constant'
     *  Constant: '<S1538>/Constant'
     *  RelationalOperator: '<S1516>/Compare'
     *  RelationalOperator: '<S1517>/Compare'
     *  RelationalOperator: '<S1524>/Compare'
     *  RelationalOperator: '<S1525>/Compare'
     *  RelationalOperator: '<S1526>/Compare'
     *  RelationalOperator: '<S1527>/Compare'
     *  RelationalOperator: '<S1538>/Compare'
     *  RelationalOperator: '<S1539>/Compare'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_dxk, rtb_Conversion_nc);

    /* End of Outputs for SubSystem: '<S1257>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_M18_Mode_Req' */
    break;

   case -200:
    /* Outputs for IfAction SubSystem: '<S42>/Tamb_M25_Mode_Req' incorporates:
     *  ActionPort: '<S1258>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S1548>/IfThenElse1' */
    rtb_Conversion_l = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HP_CHILMDCHIL_12, u8MODE_HP_CHIL_8);

    /* End of Outputs for SubSystem: '<S1548>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1548>/IfThenElse2' */
    rtb_Conversion_ozy = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1548>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1548>/IfThenElse3' */
    rtb_Conversion_ej = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.Switch2, rtb_Conversion_l, rtb_Conversion_ozy);

    /* End of Outputs for SubSystem: '<S1548>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1549>/IfThenElse4' */
    rtb_Conversion_b = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HVCH_CMF_20, u8MODE_HVCH_CMF_BAT_22);

    /* End of Outputs for SubSystem: '<S1549>/IfThenElse4' */

    /* Outputs for Atomic SubSystem: '<S1549>/IfThenElse5' */
    rtb_Conversion_krr = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_STOP_0, u8MODE_HVCH_BAT_21);

    /* End of Outputs for SubSystem: '<S1549>/IfThenElse5' */

    /* Outputs for Atomic SubSystem: '<S1549>/IfThenElse2' */
    rtb_Conversion_nyz = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, rtb_Conversion_b, rtb_Conversion_krr);

    /* End of Outputs for SubSystem: '<S1549>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1550>/IfThenElse1' */
    rtb_Conversion_f5 = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.HpI_u8Mot_CoolLv == ACPre_u8MotorCoolReq_Yes,
       u8MODE_HP_MDCHIL_9, u8MODE_HVCH_CMF_20);

    /* End of Outputs for SubSystem: '<S1550>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1550>/IfThenElse2' */
    rtb_Conversion_pz = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bDTC_Sysmtem_Prco, u8MODE_HVCH_CMF_20, u8MODE_STOP_0);

    /* End of Outputs for SubSystem: '<S1550>/IfThenElse2' */

    /* Outputs for Atomic SubSystem: '<S1550>/IfThenElse3' */
    rtb_Conversion_hw = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (!Chery_E03_Hp_B.Switch2, rtb_Conversion_f5, rtb_Conversion_pz);

    /* End of Outputs for SubSystem: '<S1550>/IfThenElse3' */

    /* Outputs for Atomic SubSystem: '<S1258>/IfThenElse1' */
    rtb_Conversion_lu = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_HeatReq_Yes, rtb_Conversion_nyz, rtb_Conversion_hw);

    /* End of Outputs for SubSystem: '<S1258>/IfThenElse1' */

    /* Outputs for Atomic SubSystem: '<S1258>/IfThenElse' */
    /* SignalConversion: '<S1258>/OutportBufferForu8Mode_Req_Pre_TambM25' incorporates:
     *  Constant: '<S1548>/Constant2'
     *  Constant: '<S1548>/Constant3'
     *  Constant: '<S1548>/Constant4'
     *  Constant: '<S1548>/Constant5'
     *  Constant: '<S1549>/Constant1'
     *  Constant: '<S1549>/Constant4'
     *  Constant: '<S1549>/Constant5'
     *  Constant: '<S1549>/Constant6'
     *  Constant: '<S1550>/Constant2'
     *  Constant: '<S1550>/Constant3'
     *  Constant: '<S1550>/Constant4'
     *  Constant: '<S1550>/Constant5'
     *  Constant: '<S1553>/Constant'
     *  Constant: '<S1561>/Constant'
     *  Constant: '<S1562>/Constant'
     *  Constant: '<S1569>/Constant'
     *  RelationalOperator: '<S1553>/Compare'
     *  RelationalOperator: '<S1554>/Compare'
     *  RelationalOperator: '<S1561>/Compare'
     *  RelationalOperator: '<S1562>/Compare'
     *  RelationalOperator: '<S1569>/Compare'
     *  RelationalOperator: '<S1570>/Compare'
     */
    Chery_E03_Hp_B.Merge = (uint8_T) Chery_E03_Hp_IfThenElse_a
      (Chery_E03_Hp_B.bBTM_CoolReq_Yes, rtb_Conversion_ej, rtb_Conversion_lu);

    /* End of Outputs for SubSystem: '<S1258>/IfThenElse' */
    /* End of Outputs for SubSystem: '<S42>/Tamb_M25_Mode_Req' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S42>/Switch Case' */
}

/* System initialize for referenced model: 'Chery_E03_Hp' */
void Chery_E03_Hp_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* InitializeConditions for UnitDelay: '<S1145>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_cj = bCONST_1;

  /* InitializeConditions for UnitDelay: '<S1176>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_lq = bCONST_1;

  /* SystemInitialize for Atomic SubSystem: '<S1145>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_p);

  /* End of SystemInitialize for SubSystem: '<S1145>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1145>/DelayJudge2' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge2_f);

  /* End of SystemInitialize for SubSystem: '<S1145>/DelayJudge2' */

  /* SystemInitialize for Atomic SubSystem: '<S1055>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_j);

  /* End of SystemInitialize for SubSystem: '<S1055>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1055>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_d);

  /* End of SystemInitialize for SubSystem: '<S1055>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1070>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_m);

  /* End of SystemInitialize for SubSystem: '<S1070>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1070>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_ki);

  /* End of SystemInitialize for SubSystem: '<S1070>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1085>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_f);

  /* End of SystemInitialize for SubSystem: '<S1085>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1085>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_n);

  /* End of SystemInitialize for SubSystem: '<S1085>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1100>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_n);

  /* End of SystemInitialize for SubSystem: '<S1100>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1100>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_is);

  /* End of SystemInitialize for SubSystem: '<S1100>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1115>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_k);

  /* End of SystemInitialize for SubSystem: '<S1115>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1115>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_m);

  /* End of SystemInitialize for SubSystem: '<S1115>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1130>/DelayJudge' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge_a);

  /* End of SystemInitialize for SubSystem: '<S1130>/DelayJudge' */

  /* SystemInitialize for Atomic SubSystem: '<S1130>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_md);

  /* End of SystemInitialize for SubSystem: '<S1130>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1176>/DelayJudge1' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge1_p4);

  /* End of SystemInitialize for SubSystem: '<S1176>/DelayJudge1' */

  /* SystemInitialize for Atomic SubSystem: '<S1176>/DelayJudge2' */
  Chery_E03_Hp_DelayJudge_Init(&Chery_E03_Hp_DW.DelayJudge2_fm);

  /* End of SystemInitialize for SubSystem: '<S1176>/DelayJudge2' */

  /* SystemInitialize for Atomic SubSystem: '<S1046>/bFlag_Tamb_HeatNotEnough' */
  /* SystemInitialize for Atomic SubSystem: '<S1227>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge_p,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1227>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S1046>/bFlag_Tamb_HeatNotEnough' */

  /* SystemInitialize for Atomic SubSystem: '<S1046>/bFlag_ACDehum_NotEnough' */
  /* SystemInitialize for Atomic SubSystem: '<S1224>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge_b,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1224>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S1046>/bFlag_ACDehum_NotEnough' */

  /* SystemInitialize for Atomic SubSystem: '<S1046>/bFlag_TotalDehum_OverHeat' */
  /* SystemInitialize for Atomic SubSystem: '<S1229>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge_jg,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1229>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S1046>/bFlag_TotalDehum_OverHeat' */

  /* SystemInitialize for Atomic SubSystem: '<S1046>/bFlag_HP_NotEnough' */
  /* SystemInitialize for Atomic SubSystem: '<S1225>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge_j,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1225>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S1046>/bFlag_HP_NotEnough' */

  /* SystemInitialize for Atomic SubSystem: '<S1046>/bFlag_HP_OverHeat' */
  /* SystemInitialize for Atomic SubSystem: '<S1226>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge_h,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1226>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S1046>/bFlag_HP_OverHeat' */

  /* SystemInitialize for Atomic SubSystem: '<S1046>/bFlag_TotalDehum_NotEnough' */
  /* SystemInitialize for Atomic SubSystem: '<S1228>/Hyster_Judge' */
  Chery_E03_Hp_Hyster_Judge_Init(&Chery_E03_Hp_DW.Hyster_Judge_os,
    Chery_E03_Hp_ConstP.pooled3);

  /* End of SystemInitialize for SubSystem: '<S1228>/Hyster_Judge' */
  /* End of SystemInitialize for SubSystem: '<S1046>/bFlag_TotalDehum_NotEnough' */
  /* End of SystemInitialize for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/WorkingModeRequest'
   *
   * Block description for '<S1>/WorkingModeRequest':
   *  Working Mode Request
   *  Working mode request according the AC Request and the Chiller request.

   */
  Chery_E03_Hp_WorkingModeRequest_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/WorkingModeRequest' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/SystemFailureDetection'
   *
   * Block description for '<S1>/SystemFailureDetection':
   *  System DTC detection
   */
  Chery_E03_Hp_SystemFailureDetection_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/SystemFailureDetection' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/Mode_Selection'
   *
   * Block description for '<S1>/Mode_Selection':
   *  ModeSelection
   *  Decide the real work mode according the Mode request and the DTC

   */
  Chery_E03_Hp_Mode_Selection_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/Mode_Selection' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/System_Control'
   *
   * Block description for '<S1>/System_Control':
   *  control
   */
  Chery_E03_Hp_System_Control_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/System_Control' */
}

/* Disable for referenced model: 'Chery_E03_Hp' */
void Chery_E03_Hp_Disable(void)
{
  /* Disable for Atomic SubSystem: '<S1>/System_Control'
   *
   * Block description for '<S1>/System_Control':
   *  control
   */
  Chery_E03_Hp_System_Control_Disable();

  /* End of Disable for SubSystem: '<S1>/System_Control' */
}

/* Start for referenced model: 'Chery_E03_Hp' */
void Chery_E03_Hp_Start(uint16_T *rty_HpO_u16Ncomp_Rpm_Req, boolean_T
  *rty_HpO_bSOV_Eva_Req, boolean_T *rty_HpO_bSOV_OutEva_Req, boolean_T
  *rty_HpO_bSOV_TXVOutEva_Req, uint16_T *rty_HpO_u16EXV_Eva_Pos_Req, uint16_T
  *rty_HpO_u16EXV_Chil_Pos_Req, uint8_T *rty_HpO_u8HpWorkMode_Req, uint8_T
  *rty_HpI_u8AGS_Position_Req, uint8_T *rty_HpO_u8FRFAN_PWM_Req, uint8_T
  *rty_HpO_u8Mix_Left_Req, uint8_T *rty_HpO_u8Mix_Right_Req, uint8_T
  *rty_HpO_u8DTC_Ref_System, uint8_T *rty_HpO_u8DTC_Ref_Component, boolean_T
  *rty_HpO_bDTC_EvaFreeze, boolean_T *rty_HpO_bDTC_OutEvaFreeze, uint8_T
  *rty_HpO_u8TWValve_HC_Req, uint8_T *rty_HpO_u8TWValve_LTR_Req, uint8_T
  *rty_HpO_u8TWValve_BAT_Req, uint8_T *rty_HpO_u8HVCH_Req, uint16_T
  *rty_HpO_u16Pump_HVCH_Req, uint16_T *rty_HpO_u16Pump_Motor_Req, uint16_T
  *rty_HpO_u16Pump_Bat_Req)
{
  /* Start for InitialCondition: '<Root>/IC' */
  Chery_E03_Hp_DW.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC1' */
  Chery_E03_Hp_DW.IC1_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC2' */
  Chery_E03_Hp_DW.IC2_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC3' */
  Chery_E03_Hp_DW.IC3_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC4' */
  Chery_E03_Hp_DW.IC4_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC5' */
  Chery_E03_Hp_DW.IC5_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC7' */
  Chery_E03_Hp_DW.IC7_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC8' */
  Chery_E03_Hp_DW.IC8_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC9' */
  Chery_E03_Hp_DW.IC9_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC10' */
  Chery_E03_Hp_DW.IC10_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC12' */
  Chery_E03_Hp_DW.IC12_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC13' */
  Chery_E03_Hp_DW.IC13_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC14' */
  Chery_E03_Hp_DW.IC14_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC15' */
  Chery_E03_Hp_DW.IC15_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC17' */
  Chery_E03_Hp_DW.IC17_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC18' */
  Chery_E03_Hp_DW.IC18_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC19' */
  Chery_E03_Hp_DW.IC19_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC20' */
  Chery_E03_Hp_DW.IC20_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC25' */
  Chery_E03_Hp_DW.IC25_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC27' */
  Chery_E03_Hp_DW.IC27_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC28' */
  Chery_E03_Hp_DW.IC28_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC29' */
  Chery_E03_Hp_DW.IC29_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC32' */
  Chery_E03_Hp_DW.IC32_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC33' */
  Chery_E03_Hp_DW.IC33_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC34' */
  Chery_E03_Hp_DW.IC34_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC35' */
  Chery_E03_Hp_DW.IC35_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC36' */
  Chery_E03_Hp_DW.IC36_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC37' */
  Chery_E03_Hp_DW.IC37_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC39' */
  Chery_E03_Hp_DW.IC39_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC43' */
  Chery_E03_Hp_DW.IC43_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC44' */
  Chery_E03_Hp_DW.IC44_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC45' */
  Chery_E03_Hp_DW.IC45_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC47' */
  Chery_E03_Hp_DW.IC47_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC51' */
  Chery_E03_Hp_DW.IC51_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC52' */
  Chery_E03_Hp_DW.IC52_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC53' */
  Chery_E03_Hp_DW.IC53_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC60' */
  Chery_E03_Hp_DW.IC60_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC61' */
  Chery_E03_Hp_DW.IC61_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC62' */
  Chery_E03_Hp_DW.IC62_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC63' */
  Chery_E03_Hp_DW.IC63_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC65' */
  Chery_E03_Hp_DW.IC65_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC67' */
  Chery_E03_Hp_DW.IC67_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC68' */
  Chery_E03_Hp_DW.IC68_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC69' */
  Chery_E03_Hp_DW.IC69_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC70' */
  Chery_E03_Hp_DW.IC70_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC71' */
  Chery_E03_Hp_DW.IC71_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC72' */
  Chery_E03_Hp_DW.IC72_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC73' */
  Chery_E03_Hp_DW.IC73_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC74' */
  Chery_E03_Hp_DW.IC74_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC75' */
  Chery_E03_Hp_DW.IC75_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC76' */
  Chery_E03_Hp_DW.IC76_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC77' */
  Chery_E03_Hp_DW.IC77_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC78' */
  Chery_E03_Hp_DW.IC78_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC79' */
  Chery_E03_Hp_DW.IC79_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC80' */
  Chery_E03_Hp_DW.IC80_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC81' */
  Chery_E03_Hp_DW.IC81_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC82' */
  Chery_E03_Hp_DW.IC82_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC83' */
  Chery_E03_Hp_DW.IC83_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC84' */
  Chery_E03_Hp_DW.IC84_FirstOutputTime = true;

  /* Start for Atomic SubSystem: '<S1>/System_Control'
   *
   * Block description for '<S1>/System_Control':
   *  control
   */
  Chery_E03_Hp_System_Control_Start();

  /* End of Start for SubSystem: '<S1>/System_Control' */

  /* Start for InitialCondition: '<Root>/IC85' */
  *rty_HpO_u16Ncomp_Rpm_Req = 0U;
  Chery_E03_Hp_DW.IC85_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC86' */
  *rty_HpO_bSOV_Eva_Req = true;
  Chery_E03_Hp_DW.IC86_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC100' */
  *rty_HpO_u8TWValve_HC_Req = 0U;
  Chery_E03_Hp_DW.IC100_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC101' */
  *rty_HpO_u8TWValve_LTR_Req = 0U;
  Chery_E03_Hp_DW.IC101_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC102' */
  *rty_HpO_u8TWValve_BAT_Req = 0U;
  Chery_E03_Hp_DW.IC102_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC103' */
  *rty_HpO_u8HVCH_Req = 0U;
  Chery_E03_Hp_DW.IC103_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC104' */
  *rty_HpO_u16Pump_HVCH_Req = 0U;
  Chery_E03_Hp_DW.IC104_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC87' */
  *rty_HpO_bSOV_OutEva_Req = true;
  Chery_E03_Hp_DW.IC87_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC106' */
  *rty_HpO_u16Pump_Bat_Req = 0U;
  Chery_E03_Hp_DW.IC106_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC88' */
  *rty_HpO_bSOV_TXVOutEva_Req = true;
  Chery_E03_Hp_DW.IC88_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC89' */
  *rty_HpO_u16EXV_Eva_Pos_Req = 50U;
  Chery_E03_Hp_DW.IC89_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC90' */
  *rty_HpO_u16EXV_Chil_Pos_Req = 50U;
  Chery_E03_Hp_DW.IC90_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC92' */
  *rty_HpI_u8AGS_Position_Req = 100U;
  Chery_E03_Hp_DW.IC92_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC93' */
  *rty_HpO_u8FRFAN_PWM_Req = 20U;
  Chery_E03_Hp_DW.IC93_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC105' */
  *rty_HpO_u16Pump_Motor_Req = 0U;
  Chery_E03_Hp_DW.IC105_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC91' */
  *rty_HpO_u8HpWorkMode_Req = 0U;
  Chery_E03_Hp_DW.IC91_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC96' */
  *rty_HpO_u8DTC_Ref_System = 0U;
  Chery_E03_Hp_DW.IC96_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC98' */
  *rty_HpO_bDTC_EvaFreeze = false;
  Chery_E03_Hp_DW.IC98_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC95' */
  *rty_HpO_u8Mix_Right_Req = 0U;
  Chery_E03_Hp_DW.IC95_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC94' */
  *rty_HpO_u8Mix_Left_Req = 0U;
  Chery_E03_Hp_DW.IC94_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC97' */
  *rty_HpO_u8DTC_Ref_Component = 0U;
  Chery_E03_Hp_DW.IC97_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC99' */
  *rty_HpO_bDTC_OutEvaFreeze = false;
  Chery_E03_Hp_DW.IC99_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC66' */
  Chery_E03_Hp_DW.IC66_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC21' */
  Chery_E03_Hp_DW.IC21_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC22' */
  Chery_E03_Hp_DW.IC22_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC23' */
  Chery_E03_Hp_DW.IC23_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC38' */
  Chery_E03_Hp_DW.IC38_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC40' */
  Chery_E03_Hp_DW.IC40_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC64' */
  Chery_E03_Hp_DW.IC64_FirstOutputTime = true;
}

/* Output and update for referenced model: 'Chery_E03_Hp' */
void Chery_E03_Hp(const uint16_T *rtu_HpI_u16P_Ref_CondOut_A10, const uint16_T
                  *rtu_HpI_u16P_Ref_EvaOut_A10, const uint16_T
                  *rtu_HpI_u16P_Ref_CHILOut_A10, const int16_T
                  *rtu_HpI_s16T_Ref_CHILOut_A10, const int16_T
                  *rtu_HpI_s16T_Ref_EDCIn_A10, const int16_T
                  *rtu_HpI_s16Teva_Front_A10, const int16_T
                  *rtu_HpI_s16TevaSet_Req_A10, const boolean_T *rtu_HpI_bAcSts,
                  const int16_T *rtu_HpI_s16Tamb_A10, const int16_T
                  *rtu_HpI_s16Tincar_Front_A10, const uint8_T *rtu_HpI_u8VehSpd,
                  const uint8_T *rtu_HpI_u8PWM_FrontFAN, const boolean_T
                  *rtu_HpI_bAGS_Status, const uint8_T *rtu_HpI_u8AGS_Position,
                  const uint16_T *rtu_HpI_u16PowerComp, const uint16_T
                  *rtu_HpI_u16Ncomp, const uint16_T *rtu_HpI_u16Power_Max, const
                  uint16_T *rtu_HpI_u16Ncomp_Max, const boolean_T
                  *rtu_HpI_bSOV_Eva, const boolean_T *rtu_HpI_bSOV_OutEva, const
                  boolean_T *rtu_HpI_bSOV_TXVOutEva, const uint16_T
                  *rtu_HpI_u16EXV_Chil_Pos, const uint8_T
                  *rtu_HpI_u8BlwVol_Real_A10, const uint8_T
                  *rtu_HpI_u8ModeStatus_Real, const uint8_T
                  *rtu_HpI_u8IntakePerc_Real, const int16_T
                  *rtu_HpI_s16Tset_Left_A10, const int16_T
                  *rtu_HpI_s16Tset_Right_A10, const int16_T
                  *rtu_HpI_s16Tasd_Left_Req_A10, const int16_T
                  *rtu_HpI_s16Tasd_Right_Req_A10, const int16_T
                  *rtu_HpI_s16TDuct_Left_Out_A10, const int16_T
                  *rtu_HpI_s16TDuct_Right_Out_A10, const boolean_T
                  *rtu_HpI_bEco_Model_Set, const uint8_T *rtu_HpI_u8HVACSts,
                  const boolean_T *rtu_HpI_bFlag_HeatShort_Blw_Req, const
                  int16_T *rtu_HpI_s16T_Wat_BatIn_A10, const int16_T
                  *rtu_HpI_s16T_Wat_HVCHOut_A10, const int16_T
                  *rtu_HpI_s16T_Wat_LTROut_A10, const int16_T
                  *rtu_HpI_s16T_Wat_MotorOut_A10, const uint8_T
                  *rtu_HpI_u8BAT_CoolHeatLv, const int16_T
                  *rtu_HpI_s16T_BAT_Wat_Set_A10, const uint8_T
                  *rtu_HpI_u8Mot_CoolLv, const uint16_T *rtu_HpI_u16Pump_Bat,
                  const uint8_T *rtu_HpI_u8IgnSts, const uint16_T
                  *rtu_HpI_u16PowerHVCH, const boolean_T
                  *rtu_HpI_bDTC_P_Ref_CondOut, const boolean_T
                  *rtu_HpI_bDTC_P_Ref_EvaOut, const boolean_T
                  *rtu_HpI_bDTC_P_Ref_CHILOut, const boolean_T
                  *rtu_HpI_bDTC_T_Ref_CHILOut, const boolean_T
                  *rtu_HpI_bDTC_T_Ref_EDCIn, const boolean_T
                  *rtu_HpI_bDTC_Teva_Front, const boolean_T *rtu_HpI_bDTC_Tamb,
                  const boolean_T *rtu_HpI_bDTC_SOV_Eva, const boolean_T
                  *rtu_HpI_bDTC_SOV_OutEva, const boolean_T
                  *rtu_HpI_bDTC_SOV_TXVOutEva, const boolean_T
                  *rtu_HpI_bDTC_EXV_Eva_Pos, const boolean_T
                  *rtu_HpI_bDTC_EXV_Chil_Pos, const boolean_T
                  *rtu_HpI_bDTC_BLW_Front, const boolean_T
                  *rtu_HpI_bDTC_EDC_Front, const boolean_T
                  *rtu_HpI_bDTC_TWValve_HC, const boolean_T
                  *rtu_HpI_bDTC_TWValve_LTR, const boolean_T
                  *rtu_HpI_bDTC_TWValve_BAT, const boolean_T *rtu_HpI_bDTC_HVCH,
                  const boolean_T *rtu_HpI_bDTC_Pump_HVCH, const boolean_T
                  *rtu_HpI_bDTC_Pump_Motor, const boolean_T
                  *rtu_HpI_bDTC_Pump_Bat, const int16_T
                  *rtu_HpI_s16T_Ref_EDCOut_A10, uint16_T
                  *rty_HpO_u16Ncomp_Rpm_Req, boolean_T *rty_HpO_bSOV_Eva_Req,
                  boolean_T *rty_HpO_bSOV_OutEva_Req, boolean_T
                  *rty_HpO_bSOV_TXVOutEva_Req, uint16_T
                  *rty_HpO_u16EXV_Eva_Pos_Req, uint16_T
                  *rty_HpO_u16EXV_Chil_Pos_Req, uint8_T
                  *rty_HpO_u8HpWorkMode_Req, uint8_T *rty_HpI_u8AGS_Position_Req,
                  uint8_T *rty_HpO_u8FRFAN_PWM_Req, uint8_T
                  *rty_HpO_u8Mix_Left_Req, uint8_T *rty_HpO_u8Mix_Right_Req,
                  uint8_T *rty_HpO_u8DTC_Ref_System, uint8_T
                  *rty_HpO_u8DTC_Ref_Component, boolean_T
                  *rty_HpO_bDTC_EvaFreeze, boolean_T *rty_HpO_bDTC_OutEvaFreeze,
                  uint8_T *rty_HpO_u8TWValve_HC_Req, uint8_T
                  *rty_HpO_u8TWValve_LTR_Req, uint8_T *rty_HpO_u8TWValve_BAT_Req,
                  uint8_T *rty_HpO_u8HVCH_Req, uint16_T
                  *rty_HpO_u16Pump_HVCH_Req, uint16_T *rty_HpO_u16Pump_Motor_Req,
                  uint16_T *rty_HpO_u16Pump_Bat_Req)
{
  uint16_T rtb_Saturation72;
  uint16_T rtb_HpI_u16P_Ref_CondOut_A10;
  uint16_T rtb_HpI_u16P_Ref_EvaOut_A10;
  int16_T rtb_Saturation3;
  int16_T rtb_HpI_s16Teva_Front_A10;
  boolean_T rtb_IC8;
  int16_T rtb_HpI_s16Tamb_A10;
  int16_T rtb_HpI_s16Tincar_Front_A10;
  uint8_T rtb_Saturation66;
  uint8_T rtb_HpI_u8VehSpd;
  uint8_T rtb_HpI_u8PWM_FrontFAN;
  uint8_T rtb_HpI_u8AGS_Position;
  uint8_T rtb_HpI_u8BlwVol_Real_A10;
  uint8_T rtb_HpI_u8ModeStatus_Real;
  uint8_T rtb_HpI_u8IntakePerc_Real;
  int16_T rtb_HpI_s16Tasd_Left_Req_A10;
  int16_T rtb_HpI_s16Tasd_Right_Req_A10;
  int16_T rtb_HpI_s16TDuct_Left_Out_A10;
  int16_T rtb_HpI_s16TDuct_Right_Out_A10;
  uint8_T rtb_IC39;
  uint8_T rtb_HpI_u8BAT_CoolHeatLv;
  int16_T rtb_HpI_s16T_BAT_Wat_Set_A10;
  uint8_T rtb_HpI_u8IgnSts;
  uint16_T rtb_Saturation;
  boolean_T rtb_Compare_ool;
  boolean_T rtb_Compare_pp4;
  boolean_T rtb_Compare_mcw;
  boolean_T rtb_Compare_e4p;
  boolean_T rtb_Compare_o4b;
  boolean_T rtb_Compare_og;
  boolean_T rtb_Compare_in4;
  boolean_T rtb_Compare_oil;
  boolean_T rtb_Compare_lua;
  boolean_T rtb_Compare_dt;
  boolean_T rtb_Compare_cwl;
  boolean_T rtb_Compare_eu;
  boolean_T rtb_Compare_j1u;
  boolean_T rtb_Compare_ia;
  boolean_T rtb_Compare_fd;
  boolean_T rtb_Compare_ge;
  boolean_T rtb_Compare_j1n;
  boolean_T rtb_Compare_gd;
  boolean_T rtb_Compare_d0;
  boolean_T rtb_Compare_gy;
  boolean_T rtb_Compare_bat;
  boolean_T rtb_Compare_c5;
  boolean_T rtb_Compare_kf;
  boolean_T rtb_OR1_ht;
  boolean_T rtb_OR1_a;
  boolean_T rtb_OR1_g;
  boolean_T rtb_Compare_jzl;
  boolean_T rtb_Compare_dc;
  boolean_T rtb_OR1_p;
  boolean_T rtb_Compare_lv;
  boolean_T rtb_OR1_o0;
  boolean_T rtb_Compare_d5;
  boolean_T rtb_Compare_fg;
  boolean_T rtb_SignalCopy;
  boolean_T rtb_SignalCopy_c;
  boolean_T rtb_bFlag_Cmf_NoHeatingReq_n;
  boolean_T rtb_SignalCopy_b;
  boolean_T rtb_SignalCopy_e;
  int32_T rtb_Sum4_e;
  int32_T rtb_Product6;
  int32_T rtb_s32MixEst_Amp10000;
  int32_T rtb_s32MixPcalAmp10000Left;
  boolean_T rtb_Switch2;
  uint16_T rtb_Saturation_nn;
  boolean_T rtb_SignalCopy_i;
  boolean_T rtb_SignalCopy_n;
  boolean_T rtb_SignalCopy_h0;
  boolean_T rtb_SignalCopy_g;
  boolean_T rtb_SignalCopy_fd;
  boolean_T rtb_SignalCopy_j;
  boolean_T rtb_SignalCopy_m1;
  boolean_T rtb_SignalCopy_a;
  boolean_T rtb_SignalCopy_d5;
  boolean_T rtb_SignalCopy_p2;
  boolean_T rtb_SignalCopy_np;
  boolean_T rtb_SignalCopy_l;
  int16_T rtb_Conversion;
  boolean_T rtb_Switch2_iy;
  boolean_T rtb_Switch2_mj;
  boolean_T rtb_Switch2_dt;
  boolean_T rtb_Switch2_af;
  int16_T rtb_R134A_P_a10_T_a10_Table;
  int16_T rtb_R134A_P_a10_T_a10_Table_m;
  boolean_T rtb_Compare_pv;
  boolean_T rtb_Compare_pmg;
  boolean_T rtb_Compare_pvs;
  boolean_T rtb_Compare_ot;
  boolean_T rtb_Compare_m1;
  boolean_T rtb_Compare_gln;
  boolean_T rtb_Compare_nmz;
  int32_T rtb_Product6_tmp;
  int32_T rtb_Sum4_d_tmp;

  /* InitialCondition: '<Root>/IC' */
  if (Chery_E03_Hp_DW.IC_FirstOutputTime) {
    Chery_E03_Hp_DW.IC_FirstOutputTime = false;
    rtb_Saturation72 = 150U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16P_Ref_CondOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC' */

  /* Saturate: '<Root>/Saturation' */
  if (((int32_T)rtb_Saturation72) < 400) {
    rtb_HpI_u16P_Ref_CondOut_A10 = rtb_Saturation72;
  } else {
    rtb_HpI_u16P_Ref_CondOut_A10 = 400U;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* InitialCondition: '<Root>/IC1' */
  if (Chery_E03_Hp_DW.IC1_FirstOutputTime) {
    Chery_E03_Hp_DW.IC1_FirstOutputTime = false;
    rtb_Saturation72 = 150U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16P_Ref_EvaOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC1' */

  /* Saturate: '<Root>/Saturation1' */
  if (((int32_T)rtb_Saturation72) < 400) {
    rtb_HpI_u16P_Ref_EvaOut_A10 = rtb_Saturation72;
  } else {
    rtb_HpI_u16P_Ref_EvaOut_A10 = 400U;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* InitialCondition: '<Root>/IC2' */
  if (Chery_E03_Hp_DW.IC2_FirstOutputTime) {
    Chery_E03_Hp_DW.IC2_FirstOutputTime = false;
    rtb_Saturation72 = 30U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16P_Ref_CHILOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC2' */

  /* Saturate: '<Root>/Saturation2' */
  if (((int32_T)rtb_Saturation72) < 120) {
    Chery_E03_Hp_B.Hp_u16SH_CompInlet = rtb_Saturation72;
  } else {
    Chery_E03_Hp_B.Hp_u16SH_CompInlet = 120U;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* InitialCondition: '<Root>/IC3' */
  if (Chery_E03_Hp_DW.IC3_FirstOutputTime) {
    Chery_E03_Hp_DW.IC3_FirstOutputTime = false;
    rtb_Saturation3 = 200;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_Ref_CHILOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC3' */

  /* Saturate: '<Root>/Saturation3' */
  Chery_E03_Hp_B.AC_s16Tairevaup_E = rtb_Saturation3;
  if (Chery_E03_Hp_B.AC_s16Tairevaup_E > 1500) {
    Chery_E03_Hp_B.AC_s16Tairevaup_E = 1500;
  } else {
    if (Chery_E03_Hp_B.AC_s16Tairevaup_E < -500) {
      Chery_E03_Hp_B.AC_s16Tairevaup_E = -500;
    }
  }

  /* InitialCondition: '<Root>/IC4' */
  if (Chery_E03_Hp_DW.IC4_FirstOutputTime) {
    Chery_E03_Hp_DW.IC4_FirstOutputTime = false;
    rtb_Saturation3 = 300;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_Ref_EDCIn_A10;
  }

  /* End of InitialCondition: '<Root>/IC4' */

  /* Saturate: '<Root>/Saturation4' */
  rtb_HpI_s16Tamb_A10 = rtb_Saturation3;
  if (rtb_HpI_s16Tamb_A10 > 1500) {
    Chery_E03_Hp_B.Conversion_p = 1500;
  } else if (rtb_HpI_s16Tamb_A10 < -500) {
    Chery_E03_Hp_B.Conversion_p = -500;
  } else {
    Chery_E03_Hp_B.Conversion_p = rtb_HpI_s16Tamb_A10;
  }

  /* End of Saturate: '<Root>/Saturation4' */

  /* InitialCondition: '<Root>/IC5' */
  if (Chery_E03_Hp_DW.IC5_FirstOutputTime) {
    Chery_E03_Hp_DW.IC5_FirstOutputTime = false;
    rtb_Saturation3 = 300;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16Teva_Front_A10;
  }

  /* End of InitialCondition: '<Root>/IC5' */

  /* Saturate: '<Root>/Saturation5' */
  rtb_HpI_s16Teva_Front_A10 = rtb_Saturation3;
  if (rtb_HpI_s16Teva_Front_A10 > 800) {
    rtb_HpI_s16Teva_Front_A10 = 800;
  } else {
    if (rtb_HpI_s16Teva_Front_A10 < -500) {
      rtb_HpI_s16Teva_Front_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation5' */

  /* InitialCondition: '<Root>/IC7' */
  if (Chery_E03_Hp_DW.IC7_FirstOutputTime) {
    Chery_E03_Hp_DW.IC7_FirstOutputTime = false;
    rtb_Saturation3 = 200;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16TevaSet_Req_A10;
  }

  /* End of InitialCondition: '<Root>/IC7' */

  /* Saturate: '<Root>/Saturation7' */
  Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10 > 200) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10 = 200;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    if (Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10 < 0) {
      /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
      /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
      Chery_E03_Hp_B.HpI_s16TevaSet_Req_A10 = 0;

      /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
    }
  }

  /* End of Saturate: '<Root>/Saturation7' */

  /* InitialCondition: '<Root>/IC8' */
  if (Chery_E03_Hp_DW.IC8_FirstOutputTime) {
    Chery_E03_Hp_DW.IC8_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bAcSts;
  }

  /* End of InitialCondition: '<Root>/IC8' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_' */
  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.Conversion_a = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) !=
    false);

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_' */

  /* InitialCondition: '<Root>/IC9' */
  if (Chery_E03_Hp_DW.IC9_FirstOutputTime) {
    Chery_E03_Hp_DW.IC9_FirstOutputTime = false;
    rtb_Saturation3 = 200;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16Tamb_A10;
  }

  /* End of InitialCondition: '<Root>/IC9' */

  /* Saturate: '<Root>/Saturation8' */
  rtb_HpI_s16Tamb_A10 = rtb_Saturation3;
  if (rtb_HpI_s16Tamb_A10 > 1500) {
    rtb_HpI_s16Tamb_A10 = 1500;
  } else {
    if (rtb_HpI_s16Tamb_A10 < -500) {
      rtb_HpI_s16Tamb_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation8' */

  /* InitialCondition: '<Root>/IC10' */
  if (Chery_E03_Hp_DW.IC10_FirstOutputTime) {
    Chery_E03_Hp_DW.IC10_FirstOutputTime = false;
    rtb_Saturation3 = 200;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16Tincar_Front_A10;
  }

  /* End of InitialCondition: '<Root>/IC10' */

  /* Saturate: '<Root>/Saturation9' */
  rtb_HpI_s16Tincar_Front_A10 = rtb_Saturation3;
  if (rtb_HpI_s16Tincar_Front_A10 > 1500) {
    rtb_HpI_s16Tincar_Front_A10 = 1500;
  } else {
    if (rtb_HpI_s16Tincar_Front_A10 < -500) {
      rtb_HpI_s16Tincar_Front_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation9' */

  /* InitialCondition: '<Root>/IC12' */
  if (Chery_E03_Hp_DW.IC12_FirstOutputTime) {
    Chery_E03_Hp_DW.IC12_FirstOutputTime = false;
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8VehSpd;
  }

  /* End of InitialCondition: '<Root>/IC12' */

  /* Saturate: '<Root>/Saturation11' */
  rtb_HpI_u8VehSpd = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8VehSpd) >= 240) {
    rtb_HpI_u8VehSpd = 240U;
  }

  /* End of Saturate: '<Root>/Saturation11' */

  /* InitialCondition: '<Root>/IC13' */
  if (Chery_E03_Hp_DW.IC13_FirstOutputTime) {
    Chery_E03_Hp_DW.IC13_FirstOutputTime = false;
    rtb_Saturation66 = 1U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8PWM_FrontFAN;
  }

  /* End of InitialCondition: '<Root>/IC13' */

  /* Saturate: '<Root>/Saturation12' */
  rtb_HpI_u8PWM_FrontFAN = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8PWM_FrontFAN) >= 100) {
    rtb_HpI_u8PWM_FrontFAN = 100U;
  }

  /* End of Saturate: '<Root>/Saturation12' */

  /* InitialCondition: '<Root>/IC14' */
  if (Chery_E03_Hp_DW.IC14_FirstOutputTime) {
    Chery_E03_Hp_DW.IC14_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bAGS_Status;
  }

  /* End of InitialCondition: '<Root>/IC14' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_1' */
  rtb_Compare_fg = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_1' */

  /* InitialCondition: '<Root>/IC15' */
  if (Chery_E03_Hp_DW.IC15_FirstOutputTime) {
    Chery_E03_Hp_DW.IC15_FirstOutputTime = false;
    rtb_Saturation66 = 100U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8AGS_Position;
  }

  /* End of InitialCondition: '<Root>/IC15' */

  /* Saturate: '<Root>/Saturation13' */
  rtb_HpI_u8AGS_Position = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8AGS_Position) >= 100) {
    rtb_HpI_u8AGS_Position = 100U;
  }

  /* End of Saturate: '<Root>/Saturation13' */

  /* InitialCondition: '<Root>/IC17' */
  if (Chery_E03_Hp_DW.IC17_FirstOutputTime) {
    Chery_E03_Hp_DW.IC17_FirstOutputTime = false;
    rtb_Saturation72 = 0U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16PowerComp;
  }

  /* End of InitialCondition: '<Root>/IC17' */

  /* Saturate: '<Root>/Saturation15' */
  if (((int32_T)rtb_Saturation72) < 18000) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16PowerComp = rtb_Saturation72;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16PowerComp = 18000U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation15' */

  /* InitialCondition: '<Root>/IC18' */
  if (Chery_E03_Hp_DW.IC18_FirstOutputTime) {
    Chery_E03_Hp_DW.IC18_FirstOutputTime = false;
    rtb_Saturation72 = 0U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16Ncomp;
  }

  /* End of InitialCondition: '<Root>/IC18' */

  /* Saturate: '<Root>/Saturation16' */
  if (((int32_T)rtb_Saturation72) < 12700) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Ncomp = rtb_Saturation72;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Ncomp = 12700U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation16' */

  /* InitialCondition: '<Root>/IC19' */
  if (Chery_E03_Hp_DW.IC19_FirstOutputTime) {
    Chery_E03_Hp_DW.IC19_FirstOutputTime = false;
    rtb_Saturation72 = 8000U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16Power_Max;
  }

  /* End of InitialCondition: '<Root>/IC19' */

  /* Saturate: '<Root>/Saturation17' */
  if (((int32_T)rtb_Saturation72) < 12600) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Power_Max = rtb_Saturation72;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Power_Max = 12600U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation17' */

  /* InitialCondition: '<Root>/IC20' */
  if (Chery_E03_Hp_DW.IC20_FirstOutputTime) {
    Chery_E03_Hp_DW.IC20_FirstOutputTime = false;
    rtb_Saturation72 = 8000U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16Ncomp_Max;
  }

  /* End of InitialCondition: '<Root>/IC20' */

  /* Saturate: '<Root>/Saturation18' */
  if (((int32_T)rtb_Saturation72) < 8000) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Ncomp_Max = rtb_Saturation72;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Ncomp_Max = 8000U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation18' */

  /* InitialCondition: '<Root>/IC25' */
  if (Chery_E03_Hp_DW.IC25_FirstOutputTime) {
    Chery_E03_Hp_DW.IC25_FirstOutputTime = false;
    rtb_Saturation72 = 50U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16EXV_Chil_Pos;
  }

  /* End of InitialCondition: '<Root>/IC25' */

  /* Saturate: '<Root>/Saturation20' */
  if (((int32_T)rtb_Saturation72) < 576) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16EXV_Chil_Pos = rtb_Saturation72;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16EXV_Chil_Pos = 576U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation20' */

  /* InitialCondition: '<Root>/IC27' */
  if (Chery_E03_Hp_DW.IC27_FirstOutputTime) {
    Chery_E03_Hp_DW.IC27_FirstOutputTime = false;
    rtb_Saturation66 = 40U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8BlwVol_Real_A10;
  }

  /* End of InitialCondition: '<Root>/IC27' */

  /* Saturate: '<Root>/Saturation22' */
  rtb_HpI_u8BlwVol_Real_A10 = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8BlwVol_Real_A10) >= 120) {
    rtb_HpI_u8BlwVol_Real_A10 = 120U;
  }

  /* End of Saturate: '<Root>/Saturation22' */

  /* InitialCondition: '<Root>/IC28' */
  if (Chery_E03_Hp_DW.IC28_FirstOutputTime) {
    Chery_E03_Hp_DW.IC28_FirstOutputTime = false;
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8ModeStatus_Real;
  }

  /* End of InitialCondition: '<Root>/IC28' */

  /* Saturate: '<Root>/Saturation23' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) >= 15) {
    rtb_HpI_u8ModeStatus_Real = 15U;
  }

  /* End of Saturate: '<Root>/Saturation23' */

  /* InitialCondition: '<Root>/IC29' */
  if (Chery_E03_Hp_DW.IC29_FirstOutputTime) {
    Chery_E03_Hp_DW.IC29_FirstOutputTime = false;
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8IntakePerc_Real;
  }

  /* End of InitialCondition: '<Root>/IC29' */

  /* Saturate: '<Root>/Saturation24' */
  rtb_HpI_u8IntakePerc_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8IntakePerc_Real) >= 250) {
    rtb_HpI_u8IntakePerc_Real = 250U;
  }

  /* End of Saturate: '<Root>/Saturation24' */

  /* InitialCondition: '<Root>/IC32' */
  if (Chery_E03_Hp_DW.IC32_FirstOutputTime) {
    Chery_E03_Hp_DW.IC32_FirstOutputTime = false;
    rtb_Saturation3 = 240;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16Tset_Left_A10;
  }

  /* End of InitialCondition: '<Root>/IC32' */

  /* Saturate: '<Root>/Saturation27' */
  Chery_E03_Hp_B.HpI_s16Tset_Left_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16Tset_Left_A10 > 330) {
    Chery_E03_Hp_B.HpI_s16Tset_Left_A10 = 330;
  } else {
    if (Chery_E03_Hp_B.HpI_s16Tset_Left_A10 < 180) {
      Chery_E03_Hp_B.HpI_s16Tset_Left_A10 = 180;
    }
  }

  /* End of Saturate: '<Root>/Saturation27' */

  /* InitialCondition: '<Root>/IC33' */
  if (Chery_E03_Hp_DW.IC33_FirstOutputTime) {
    Chery_E03_Hp_DW.IC33_FirstOutputTime = false;
    rtb_Saturation3 = 240;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16Tset_Right_A10;
  }

  /* End of InitialCondition: '<Root>/IC33' */

  /* Saturate: '<Root>/Saturation28' */
  Chery_E03_Hp_B.HpI_s16Tset_Right_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16Tset_Right_A10 > 330) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_s16Tset_Right_A10 = 330;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    if (Chery_E03_Hp_B.HpI_s16Tset_Right_A10 < 180) {
      /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
      /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
      Chery_E03_Hp_B.HpI_s16Tset_Right_A10 = 180;

      /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
    }
  }

  /* End of Saturate: '<Root>/Saturation28' */

  /* InitialCondition: '<Root>/IC34' */
  if (Chery_E03_Hp_DW.IC34_FirstOutputTime) {
    Chery_E03_Hp_DW.IC34_FirstOutputTime = false;
    rtb_Saturation3 = 250;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16Tasd_Left_Req_A10;
  }

  /* End of InitialCondition: '<Root>/IC34' */

  /* Saturate: '<Root>/Saturation29' */
  rtb_HpI_s16Tasd_Left_Req_A10 = rtb_Saturation3;
  if (rtb_HpI_s16Tasd_Left_Req_A10 > 1500) {
    rtb_HpI_s16Tasd_Left_Req_A10 = 1500;
  } else {
    if (rtb_HpI_s16Tasd_Left_Req_A10 < -500) {
      rtb_HpI_s16Tasd_Left_Req_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation29' */

  /* InitialCondition: '<Root>/IC35' */
  if (Chery_E03_Hp_DW.IC35_FirstOutputTime) {
    Chery_E03_Hp_DW.IC35_FirstOutputTime = false;
    rtb_Saturation3 = 250;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16Tasd_Right_Req_A10;
  }

  /* End of InitialCondition: '<Root>/IC35' */

  /* Saturate: '<Root>/Saturation30' */
  rtb_HpI_s16Tasd_Right_Req_A10 = rtb_Saturation3;
  if (rtb_HpI_s16Tasd_Right_Req_A10 > 1500) {
    rtb_HpI_s16Tasd_Right_Req_A10 = 1500;
  } else {
    if (rtb_HpI_s16Tasd_Right_Req_A10 < -500) {
      rtb_HpI_s16Tasd_Right_Req_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation30' */

  /* InitialCondition: '<Root>/IC36' */
  if (Chery_E03_Hp_DW.IC36_FirstOutputTime) {
    Chery_E03_Hp_DW.IC36_FirstOutputTime = false;
    rtb_Saturation3 = 250;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16TDuct_Left_Out_A10;
  }

  /* End of InitialCondition: '<Root>/IC36' */

  /* Saturate: '<Root>/Saturation31' */
  rtb_HpI_s16TDuct_Left_Out_A10 = rtb_Saturation3;
  if (rtb_HpI_s16TDuct_Left_Out_A10 > 1500) {
    rtb_HpI_s16TDuct_Left_Out_A10 = 1500;
  } else {
    if (rtb_HpI_s16TDuct_Left_Out_A10 < -500) {
      rtb_HpI_s16TDuct_Left_Out_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation31' */

  /* InitialCondition: '<Root>/IC37' */
  if (Chery_E03_Hp_DW.IC37_FirstOutputTime) {
    Chery_E03_Hp_DW.IC37_FirstOutputTime = false;
    rtb_Saturation3 = 250;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16TDuct_Right_Out_A10;
  }

  /* End of InitialCondition: '<Root>/IC37' */

  /* Saturate: '<Root>/Saturation32' */
  rtb_HpI_s16TDuct_Right_Out_A10 = rtb_Saturation3;
  if (rtb_HpI_s16TDuct_Right_Out_A10 > 1500) {
    rtb_HpI_s16TDuct_Right_Out_A10 = 1500;
  } else {
    if (rtb_HpI_s16TDuct_Right_Out_A10 < -500) {
      rtb_HpI_s16TDuct_Right_Out_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation32' */

  /* InitialCondition: '<Root>/IC39' */
  if (Chery_E03_Hp_DW.IC39_FirstOutputTime) {
    Chery_E03_Hp_DW.IC39_FirstOutputTime = false;
    rtb_IC39 = 0U;
  } else {
    rtb_IC39 = *rtu_HpI_u8HVACSts;
  }

  /* End of InitialCondition: '<Root>/IC39' */

  /* InitialCondition: '<Root>/IC43' */
  if (Chery_E03_Hp_DW.IC43_FirstOutputTime) {
    Chery_E03_Hp_DW.IC43_FirstOutputTime = false;
    rtb_Saturation3 = 300;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_Wat_BatIn_A10;
  }

  /* End of InitialCondition: '<Root>/IC43' */

  /* Saturate: '<Root>/Saturation36' */
  Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 > 1500) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 = 1500;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    if (Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 < -500) {
      /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
      /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
      Chery_E03_Hp_B.HpI_s16T_Wat_BatIn_A10 = -500;

      /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
    }
  }

  /* End of Saturate: '<Root>/Saturation36' */

  /* InitialCondition: '<Root>/IC44' */
  if (Chery_E03_Hp_DW.IC44_FirstOutputTime) {
    Chery_E03_Hp_DW.IC44_FirstOutputTime = false;
    rtb_Saturation3 = 300;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_Wat_HVCHOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC44' */

  /* Saturate: '<Root>/Saturation37' */
  Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10 > 1500) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10 = 1500;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    if (Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10 < -500) {
      /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
      /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
      Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10 = -500;

      /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
    }
  }

  /* End of Saturate: '<Root>/Saturation37' */

  /* InitialCondition: '<Root>/IC45' */
  if (Chery_E03_Hp_DW.IC45_FirstOutputTime) {
    Chery_E03_Hp_DW.IC45_FirstOutputTime = false;
    rtb_Saturation3 = 300;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_Wat_LTROut_A10;
  }

  /* End of InitialCondition: '<Root>/IC45' */

  /* Saturate: '<Root>/Saturation38' */
  Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 > 1500) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 = 1500;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    if (Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 < -500) {
      /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
      /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
      Chery_E03_Hp_B.HpI_s16T_Wat_LTROut_A10 = -500;

      /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
    }
  }

  /* End of Saturate: '<Root>/Saturation38' */

  /* InitialCondition: '<Root>/IC47' */
  if (Chery_E03_Hp_DW.IC47_FirstOutputTime) {
    Chery_E03_Hp_DW.IC47_FirstOutputTime = false;
    rtb_Saturation3 = 300;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_Wat_MotorOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC47' */

  /* Saturate: '<Root>/Saturation40' */
  Chery_E03_Hp_B.HpI_s16T_Wat_MotorOut_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16T_Wat_MotorOut_A10 > 1500) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_s16T_Wat_MotorOut_A10 = 1500;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    if (Chery_E03_Hp_B.HpI_s16T_Wat_MotorOut_A10 < -500) {
      /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
      /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
      Chery_E03_Hp_B.HpI_s16T_Wat_MotorOut_A10 = -500;

      /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
    }
  }

  /* End of Saturate: '<Root>/Saturation40' */

  /* InitialCondition: '<Root>/IC51' */
  if (Chery_E03_Hp_DW.IC51_FirstOutputTime) {
    Chery_E03_Hp_DW.IC51_FirstOutputTime = false;
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8BAT_CoolHeatLv;
  }

  /* End of InitialCondition: '<Root>/IC51' */

  /* Saturate: '<Root>/Saturation44' */
  rtb_HpI_u8BAT_CoolHeatLv = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8BAT_CoolHeatLv) >= 15) {
    rtb_HpI_u8BAT_CoolHeatLv = 15U;
  }

  /* End of Saturate: '<Root>/Saturation44' */

  /* InitialCondition: '<Root>/IC52' */
  if (Chery_E03_Hp_DW.IC52_FirstOutputTime) {
    Chery_E03_Hp_DW.IC52_FirstOutputTime = false;
    rtb_Saturation3 = 150;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_BAT_Wat_Set_A10;
  }

  /* End of InitialCondition: '<Root>/IC52' */

  /* Saturate: '<Root>/Saturation45' */
  rtb_HpI_s16T_BAT_Wat_Set_A10 = rtb_Saturation3;
  if (rtb_HpI_s16T_BAT_Wat_Set_A10 > 870) {
    rtb_HpI_s16T_BAT_Wat_Set_A10 = 870;
  } else {
    if (rtb_HpI_s16T_BAT_Wat_Set_A10 < -400) {
      rtb_HpI_s16T_BAT_Wat_Set_A10 = -400;
    }
  }

  /* End of Saturate: '<Root>/Saturation45' */

  /* InitialCondition: '<Root>/IC53' */
  if (Chery_E03_Hp_DW.IC53_FirstOutputTime) {
    Chery_E03_Hp_DW.IC53_FirstOutputTime = false;
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8Mot_CoolLv;
  }

  /* End of InitialCondition: '<Root>/IC53' */

  /* Saturate: '<Root>/Saturation46' */
  Chery_E03_Hp_B.HpI_u8Mot_CoolLv = rtb_Saturation66;
  if (((int32_T)Chery_E03_Hp_B.HpI_u8Mot_CoolLv) >= 15) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u8Mot_CoolLv = 15U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation46' */

  /* InitialCondition: '<Root>/IC60' */
  if (Chery_E03_Hp_DW.IC60_FirstOutputTime) {
    Chery_E03_Hp_DW.IC60_FirstOutputTime = false;
    rtb_Saturation72 = 0U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16Pump_Bat;
  }

  /* End of InitialCondition: '<Root>/IC60' */

  /* Saturate: '<Root>/Saturation53' */
  if (((int32_T)rtb_Saturation72) < 100) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Pump_Bat = rtb_Saturation72;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16Pump_Bat = 100U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation53' */

  /* InitialCondition: '<Root>/IC61' */
  if (Chery_E03_Hp_DW.IC61_FirstOutputTime) {
    Chery_E03_Hp_DW.IC61_FirstOutputTime = false;
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = *rtu_HpI_u8IgnSts;
  }

  /* End of InitialCondition: '<Root>/IC61' */

  /* Saturate: '<Root>/Saturation54' */
  rtb_HpI_u8IgnSts = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8IgnSts) >= 7) {
    rtb_HpI_u8IgnSts = 7U;
  }

  /* End of Saturate: '<Root>/Saturation54' */

  /* InitialCondition: '<Root>/IC62' */
  if (Chery_E03_Hp_DW.IC62_FirstOutputTime) {
    Chery_E03_Hp_DW.IC62_FirstOutputTime = false;
    rtb_Saturation72 = 0U;
  } else {
    rtb_Saturation72 = *rtu_HpI_u16PowerHVCH;
  }

  /* End of InitialCondition: '<Root>/IC62' */

  /* InitialCondition: '<Root>/IC63' */
  if (Chery_E03_Hp_DW.IC63_FirstOutputTime) {
    Chery_E03_Hp_DW.IC63_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_P_Ref_CondOut;
  }

  /* End of InitialCondition: '<Root>/IC63' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_7' */
  rtb_Compare_lua = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_7' */

  /* InitialCondition: '<Root>/IC65' */
  if (Chery_E03_Hp_DW.IC65_FirstOutputTime) {
    Chery_E03_Hp_DW.IC65_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_P_Ref_CHILOut;
  }

  /* End of InitialCondition: '<Root>/IC65' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_9' */
  rtb_Compare_dt = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_9' */

  /* InitialCondition: '<Root>/IC67' */
  if (Chery_E03_Hp_DW.IC67_FirstOutputTime) {
    Chery_E03_Hp_DW.IC67_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_T_Ref_EDCIn;
  }

  /* End of InitialCondition: '<Root>/IC67' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_11' */
  rtb_Compare_cwl = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_11' */

  /* InitialCondition: '<Root>/IC68' */
  if (Chery_E03_Hp_DW.IC68_FirstOutputTime) {
    Chery_E03_Hp_DW.IC68_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_Teva_Front;
  }

  /* End of InitialCondition: '<Root>/IC68' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_12' */
  rtb_Compare_gy = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_12' */

  /* InitialCondition: '<Root>/IC69' */
  if (Chery_E03_Hp_DW.IC69_FirstOutputTime) {
    Chery_E03_Hp_DW.IC69_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_Tamb;
  }

  /* End of InitialCondition: '<Root>/IC69' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_13' */
  rtb_Compare_eu = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_13' */

  /* InitialCondition: '<Root>/IC70' */
  if (Chery_E03_Hp_DW.IC70_FirstOutputTime) {
    Chery_E03_Hp_DW.IC70_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_SOV_Eva;
  }

  /* End of InitialCondition: '<Root>/IC70' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_14' */
  rtb_Compare_j1u = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_14' */

  /* InitialCondition: '<Root>/IC71' */
  if (Chery_E03_Hp_DW.IC71_FirstOutputTime) {
    Chery_E03_Hp_DW.IC71_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_SOV_OutEva;
  }

  /* End of InitialCondition: '<Root>/IC71' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_15' */
  rtb_Compare_ia = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_15' */

  /* InitialCondition: '<Root>/IC72' */
  if (Chery_E03_Hp_DW.IC72_FirstOutputTime) {
    Chery_E03_Hp_DW.IC72_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_SOV_TXVOutEva;
  }

  /* End of InitialCondition: '<Root>/IC72' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_16' */
  rtb_Compare_fd = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_16' */

  /* InitialCondition: '<Root>/IC73' */
  if (Chery_E03_Hp_DW.IC73_FirstOutputTime) {
    Chery_E03_Hp_DW.IC73_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_EXV_Eva_Pos;
  }

  /* End of InitialCondition: '<Root>/IC73' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_17' */
  rtb_Compare_ge = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_17' */

  /* InitialCondition: '<Root>/IC74' */
  if (Chery_E03_Hp_DW.IC74_FirstOutputTime) {
    Chery_E03_Hp_DW.IC74_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_EXV_Chil_Pos;
  }

  /* End of InitialCondition: '<Root>/IC74' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_18' */
  rtb_Compare_j1n = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_18' */

  /* InitialCondition: '<Root>/IC75' */
  if (Chery_E03_Hp_DW.IC75_FirstOutputTime) {
    Chery_E03_Hp_DW.IC75_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_BLW_Front;
  }

  /* End of InitialCondition: '<Root>/IC75' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_19' */
  rtb_Compare_d0 = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_19' */

  /* InitialCondition: '<Root>/IC76' */
  if (Chery_E03_Hp_DW.IC76_FirstOutputTime) {
    Chery_E03_Hp_DW.IC76_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_EDC_Front;
  }

  /* End of InitialCondition: '<Root>/IC76' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_20' */
  rtb_Compare_gd = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_20' */

  /* InitialCondition: '<Root>/IC77' */
  if (Chery_E03_Hp_DW.IC77_FirstOutputTime) {
    Chery_E03_Hp_DW.IC77_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_TWValve_HC;
  }

  /* End of InitialCondition: '<Root>/IC77' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_21' */
  rtb_Compare_bat = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_21' */

  /* InitialCondition: '<Root>/IC78' */
  if (Chery_E03_Hp_DW.IC78_FirstOutputTime) {
    Chery_E03_Hp_DW.IC78_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_TWValve_LTR;
  }

  /* End of InitialCondition: '<Root>/IC78' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_22' */
  rtb_Compare_jzl = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_22' */

  /* InitialCondition: '<Root>/IC79' */
  if (Chery_E03_Hp_DW.IC79_FirstOutputTime) {
    Chery_E03_Hp_DW.IC79_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_TWValve_BAT;
  }

  /* End of InitialCondition: '<Root>/IC79' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_23' */
  rtb_Compare_dc = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_23' */

  /* InitialCondition: '<Root>/IC80' */
  if (Chery_E03_Hp_DW.IC80_FirstOutputTime) {
    Chery_E03_Hp_DW.IC80_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_HVCH;
  }

  /* End of InitialCondition: '<Root>/IC80' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_24' */
  rtb_Compare_kf = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_24' */

  /* InitialCondition: '<Root>/IC81' */
  if (Chery_E03_Hp_DW.IC81_FirstOutputTime) {
    Chery_E03_Hp_DW.IC81_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_Pump_HVCH;
  }

  /* End of InitialCondition: '<Root>/IC81' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_25' */
  rtb_Compare_c5 = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_25' */

  /* InitialCondition: '<Root>/IC82' */
  if (Chery_E03_Hp_DW.IC82_FirstOutputTime) {
    Chery_E03_Hp_DW.IC82_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_Pump_Motor;
  }

  /* End of InitialCondition: '<Root>/IC82' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_26' */
  rtb_Compare_d5 = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_26' */

  /* InitialCondition: '<Root>/IC83' */
  if (Chery_E03_Hp_DW.IC83_FirstOutputTime) {
    Chery_E03_Hp_DW.IC83_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_Pump_Bat;
  }

  /* End of InitialCondition: '<Root>/IC83' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_27' */
  rtb_Compare_lv = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_27' */

  /* InitialCondition: '<Root>/IC84' */
  if (Chery_E03_Hp_DW.IC84_FirstOutputTime) {
    Chery_E03_Hp_DW.IC84_FirstOutputTime = false;
    rtb_Saturation3 = 300;
  } else {
    rtb_Saturation3 = *rtu_HpI_s16T_Ref_EDCOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC84' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_u16P_Ref_CondOut_A10 = rtb_HpI_u16P_Ref_CondOut_A10;

  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_s16Tamb_A10 = rtb_HpI_s16Tamb_A10;

  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_u8VehSpd = rtb_HpI_u8VehSpd;

  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_u16P_Ref_CHILOut_A10 = Chery_E03_Hp_B.Hp_u16SH_CompInlet;

  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_u8BlwVol_Real_A10 = rtb_HpI_u8BlwVol_Real_A10;

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Saturate: '<Root>/Saturation56' */
  Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 = rtb_Saturation3;
  if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 > 1500) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 = 1500;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    if (Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 < -500) {
      /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
      /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
      Chery_E03_Hp_B.HpI_s16T_Ref_EDCOut_A10 = -500;

      /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
    }
  }

  /* End of Saturate: '<Root>/Saturation56' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_u8BAT_CoolHeatLv = rtb_HpI_u8BAT_CoolHeatLv;

  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_s16T_BAT_Wat_Set_A10 = rtb_HpI_s16T_BAT_Wat_Set_A10;

  /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
  Chery_E03_Hp_B.HpI_s16Teva_Front_A10 = rtb_HpI_s16Teva_Front_A10;

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Saturate: '<Root>/Saturation55' */
  if (((int32_T)rtb_Saturation72) < 8000) {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16PowerHVCH = rtb_Saturation72;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
    /* SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0' */
    Chery_E03_Hp_B.HpI_u16PowerHVCH = 8000U;

    /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  }

  /* End of Saturate: '<Root>/Saturation55' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Logic: '<S1145>/Logical Operator1' incorporates:
   *  Constant: '<S1146>/Constant'
   *  Constant: '<S1148>/Constant'
   *  Constant: '<S1149>/Constant'
   *  Constant: '<S1150>/Constant'
   *  Constant: '<S1151>/Constant'
   *  RelationalOperator: '<S1146>/Compare'
   *  RelationalOperator: '<S1148>/Compare'
   *  RelationalOperator: '<S1149>/Compare'
   *  RelationalOperator: '<S1150>/Compare'
   *  RelationalOperator: '<S1151>/Compare'
   */
  rtb_IC8 = (((((Chery_E03_Hp_B.HpI_s16Tset_Left_A10 <= s16TSET_LOW) ||
                (rtb_IC39 == u8HVACStatusFB_CMF_OFF)) || (rtb_IC39 ==
    u8HVACStatusFB_CMF_VENTILATE)) || (rtb_IC39 == u8HVACStatusFB_CMF_OTA)) ||
             (rtb_IC39 == u8HVACStatusFB_CMF_MAXAC));

  /* Outputs for Atomic SubSystem: '<S1145>/DelayJudge1' */
  rtb_SignalCopy_c = ( Chery_E03_Hp_DelayJudge(rtb_IC8,
    &Chery_E03_Hp_ConstB.DelayJudge1_p, &Chery_E03_Hp_DW.DelayJudge1_p) != false);

  /* End of Outputs for SubSystem: '<S1145>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S1145>/DelayJudge2' */
  /* RelationalOperator: '<S1152>/Compare' incorporates:
   *  Constant: '<S1152>/Constant'
   */
  rtb_SignalCopy = ( Chery_E03_Hp_DelayJudge(rtb_IC8 == bCONST_0,
    &Chery_E03_Hp_ConstB.DelayJudge2_f, &Chery_E03_Hp_DW.DelayJudge2_f) != false);

  /* End of Outputs for SubSystem: '<S1145>/DelayJudge2' */

  /* UnitDelay: '<S1145>/Unit Delay' */
  rtb_OR1_ht = Chery_E03_Hp_DW.UnitDelay_DSTATE_cj;

  /* Switch: '<S1145>/Switch1' incorporates:
   *  Constant: '<S1145>/Constant1'
   */
  if (rtb_SignalCopy) {
    rtb_OR1_ht = bCONST_0;
  }

  /* End of Switch: '<S1145>/Switch1' */

  /* Switch: '<S1145>/Switch' incorporates:
   *  Constant: '<S1145>/Constant'
   */
  if (rtb_SignalCopy_c) {
    Chery_E03_Hp_B.bFlag_Cmf_NoHeatingReq = bCONST_1;
  } else {
    Chery_E03_Hp_B.bFlag_Cmf_NoHeatingReq = rtb_OR1_ht;
  }

  /* End of Switch: '<S1145>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1043>/Heating_Stop_Flag_Judge' */
  /* SignalConversion: '<S1048>/TmpSignal ConversionAtSignal CopyInport1' */
  rtb_bFlag_Cmf_NoHeatingReq_n = Chery_E03_Hp_B.bFlag_Cmf_NoHeatingReq;

  /* End of Outputs for SubSystem: '<S1043>/Heating_Stop_Flag_Judge' */

  /* Logic: '<S1043>/OR' */
  rtb_IC8 = (((((((((rtb_Compare_lua || rtb_Compare_dt) || rtb_Compare_cwl) ||
                   rtb_Compare_eu) || rtb_Compare_j1u) || rtb_Compare_ia) ||
                rtb_Compare_fd) || rtb_Compare_ge) || rtb_Compare_j1n) ||
             rtb_Compare_gd);

  /* Logic: '<S1054>/OR1' */
  rtb_OR1_ht = (((((rtb_IC8 || rtb_Compare_d0) || rtb_Compare_gy) ||
                  rtb_Compare_bat) || rtb_Compare_c5) || rtb_Compare_kf);

  /* Logic: '<S1053>/OR1' */
  rtb_OR1_a = (((rtb_Compare_d0 || rtb_Compare_bat) || rtb_Compare_c5) ||
               rtb_Compare_kf);

  /* Logic: '<S1052>/OR1' */
  rtb_OR1_g = ((((rtb_IC8 || rtb_Compare_d0) || rtb_Compare_bat) ||
                rtb_Compare_c5) || rtb_Compare_kf);

  /* Logic: '<S1051>/OR1' */
  rtb_OR1_p = ((((((rtb_IC8 || rtb_Compare_d0) || rtb_Compare_gy) ||
                  rtb_Compare_bat) || rtb_Compare_jzl) || rtb_Compare_dc) ||
               rtb_Compare_c5);

  /* Logic: '<S1050>/OR1' */
  rtb_OR1_o0 = (((((rtb_Compare_bat || rtb_Compare_jzl) || rtb_Compare_dc) ||
                  rtb_Compare_lv) || rtb_Compare_kf) || rtb_Compare_c5);

  /* Logic: '<S1049>/OR1' */
  rtb_Compare_ool = (((((rtb_IC8 || rtb_Compare_bat) || rtb_Compare_jzl) ||
                       rtb_Compare_dc) || rtb_Compare_d5) || rtb_Compare_lv);

  /* Outputs for Atomic SubSystem: '<S1055>/DelayJudge' */
  /* RelationalOperator: '<S1056>/Compare' incorporates:
   *  Constant: '<S1056>/Constant'
   */
  rtb_SignalCopy_i = ( Chery_E03_Hp_DelayJudge(rtb_Compare_ool ==
    bFAILRISK_YES_1, &Chery_E03_Hp_ConstB.DelayJudge_j,
    &Chery_E03_Hp_DW.DelayJudge_j) != false);

  /* End of Outputs for SubSystem: '<S1055>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1055>/DelayJudge1' */
  /* RelationalOperator: '<S1057>/Compare' incorporates:
   *  Constant: '<S1057>/Constant'
   */
  rtb_SignalCopy_n = ( Chery_E03_Hp_DelayJudge(rtb_Compare_ool == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1_d, &Chery_E03_Hp_DW.DelayJudge1_d) != false);

  /* End of Outputs for SubSystem: '<S1055>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S1070>/DelayJudge' */
  /* RelationalOperator: '<S1071>/Compare' incorporates:
   *  Constant: '<S1071>/Constant'
   */
  rtb_SignalCopy_h0 = ( Chery_E03_Hp_DelayJudge(rtb_OR1_o0 == bFAILRISK_YES_1,
    &Chery_E03_Hp_ConstB.DelayJudge_m, &Chery_E03_Hp_DW.DelayJudge_m) != false);

  /* End of Outputs for SubSystem: '<S1070>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1070>/DelayJudge1' */
  /* RelationalOperator: '<S1072>/Compare' incorporates:
   *  Constant: '<S1072>/Constant'
   */
  rtb_SignalCopy_g = ( Chery_E03_Hp_DelayJudge(rtb_OR1_o0 == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1_ki, &Chery_E03_Hp_DW.DelayJudge1_ki) !=
                      false);

  /* End of Outputs for SubSystem: '<S1070>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S1085>/DelayJudge' */
  /* RelationalOperator: '<S1086>/Compare' incorporates:
   *  Constant: '<S1086>/Constant'
   */
  rtb_SignalCopy_fd = ( Chery_E03_Hp_DelayJudge(rtb_OR1_p == bFAILRISK_YES_1,
    &Chery_E03_Hp_ConstB.DelayJudge_f, &Chery_E03_Hp_DW.DelayJudge_f) != false);

  /* End of Outputs for SubSystem: '<S1085>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1085>/DelayJudge1' */
  /* RelationalOperator: '<S1087>/Compare' incorporates:
   *  Constant: '<S1087>/Constant'
   */
  rtb_SignalCopy_j = ( Chery_E03_Hp_DelayJudge(rtb_OR1_p == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1_n, &Chery_E03_Hp_DW.DelayJudge1_n) != false);

  /* End of Outputs for SubSystem: '<S1085>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S1100>/DelayJudge' */
  /* RelationalOperator: '<S1101>/Compare' incorporates:
   *  Constant: '<S1101>/Constant'
   */
  rtb_SignalCopy_m1 = ( Chery_E03_Hp_DelayJudge(rtb_OR1_g == bFAILRISK_YES_1,
    &Chery_E03_Hp_ConstB.DelayJudge_n, &Chery_E03_Hp_DW.DelayJudge_n) != false);

  /* End of Outputs for SubSystem: '<S1100>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1100>/DelayJudge1' */
  /* RelationalOperator: '<S1102>/Compare' incorporates:
   *  Constant: '<S1102>/Constant'
   */
  rtb_SignalCopy_a = ( Chery_E03_Hp_DelayJudge(rtb_OR1_g == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1_is, &Chery_E03_Hp_DW.DelayJudge1_is) !=
                      false);

  /* End of Outputs for SubSystem: '<S1100>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S1115>/DelayJudge' */
  /* RelationalOperator: '<S1116>/Compare' incorporates:
   *  Constant: '<S1116>/Constant'
   */
  rtb_SignalCopy_d5 = ( Chery_E03_Hp_DelayJudge(rtb_OR1_a == bFAILRISK_YES_1,
    &Chery_E03_Hp_ConstB.DelayJudge_k, &Chery_E03_Hp_DW.DelayJudge_k) != false);

  /* End of Outputs for SubSystem: '<S1115>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1115>/DelayJudge1' */
  /* RelationalOperator: '<S1117>/Compare' incorporates:
   *  Constant: '<S1117>/Constant'
   */
  rtb_SignalCopy_p2 = ( Chery_E03_Hp_DelayJudge(rtb_OR1_a == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1_m, &Chery_E03_Hp_DW.DelayJudge1_m) != false);

  /* End of Outputs for SubSystem: '<S1115>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S1130>/DelayJudge' */
  /* RelationalOperator: '<S1131>/Compare' incorporates:
   *  Constant: '<S1131>/Constant'
   */
  rtb_SignalCopy_np = ( Chery_E03_Hp_DelayJudge(rtb_OR1_ht == bFAILRISK_YES_1,
    &Chery_E03_Hp_ConstB.DelayJudge_a, &Chery_E03_Hp_DW.DelayJudge_a) != false);

  /* End of Outputs for SubSystem: '<S1130>/DelayJudge' */

  /* Outputs for Atomic SubSystem: '<S1130>/DelayJudge1' */
  /* RelationalOperator: '<S1132>/Compare' incorporates:
   *  Constant: '<S1132>/Constant'
   */
  rtb_SignalCopy_l = ( Chery_E03_Hp_DelayJudge(rtb_OR1_ht == bFAILRISK_NO_0,
    &Chery_E03_Hp_ConstB.DelayJudge1_md, &Chery_E03_Hp_DW.DelayJudge1_md) !=
                      false);

  /* End of Outputs for SubSystem: '<S1130>/DelayJudge1' */

  /* Logic: '<S1176>/Logical Operator1' incorporates:
   *  Constant: '<S1179>/Constant'
   *  Constant: '<S1180>/Constant'
   *  Constant: '<S1181>/Constant'
   *  Constant: '<S1182>/Constant'
   *  RelationalOperator: '<S1179>/Compare'
   *  RelationalOperator: '<S1180>/Compare'
   *  RelationalOperator: '<S1181>/Compare'
   *  RelationalOperator: '<S1182>/Compare'
   */
  rtb_OR1_ht = ((((rtb_IC39 == u8HVACStatusFB_CMF_OFF) || (rtb_IC39 ==
    u8HVACStatusFB_CMF_VENTILATE)) || (rtb_IC39 == u8HVACStatusFB_CMF_OTA)) ||
                (rtb_IC39 == u8HVACStatusFB_CMF_MAXAC));

  /* Outputs for Atomic SubSystem: '<S1176>/DelayJudge1' */
  rtb_SignalCopy_e = ( Chery_E03_Hp_DelayJudge(rtb_OR1_ht,
    &Chery_E03_Hp_ConstB.DelayJudge1_p4, &Chery_E03_Hp_DW.DelayJudge1_p4) !=
                      false);

  /* End of Outputs for SubSystem: '<S1176>/DelayJudge1' */

  /* Outputs for Atomic SubSystem: '<S1176>/DelayJudge2' */
  /* RelationalOperator: '<S1183>/Compare' incorporates:
   *  Constant: '<S1183>/Constant'
   */
  rtb_SignalCopy_b = ( Chery_E03_Hp_DelayJudge(rtb_OR1_ht == bCONST_0,
    &Chery_E03_Hp_ConstB.DelayJudge2_fm, &Chery_E03_Hp_DW.DelayJudge2_fm) !=
                      false);

  /* End of Outputs for SubSystem: '<S1176>/DelayJudge2' */

  /* UnitDelay: '<S1176>/Unit Delay' */
  rtb_Compare_ool = Chery_E03_Hp_DW.UnitDelay_DSTATE_lq;

  /* Switch: '<S1176>/Switch1' incorporates:
   *  Constant: '<S1176>/Constant1'
   */
  if (rtb_SignalCopy_b) {
    rtb_Compare_ool = bCONST_0;
  }

  /* End of Switch: '<S1176>/Switch1' */

  /* Switch: '<S1176>/Switch' incorporates:
   *  Constant: '<S1176>/Constant'
   *  UnitDelay: '<S1176>/Unit Delay'
   */
  if (rtb_SignalCopy_e) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_lq = bCONST_1;
  } else {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_lq = rtb_Compare_ool;
  }

  /* End of Switch: '<S1176>/Switch' */

  /* MinMax: '<S1162>/Max' */
  if (rtb_HpI_s16Tasd_Left_Req_A10 > rtb_HpI_s16Tasd_Right_Req_A10) {
    rtb_Saturation3 = rtb_HpI_s16Tasd_Left_Req_A10;
  } else {
    rtb_Saturation3 = rtb_HpI_s16Tasd_Right_Req_A10;
  }

  /* End of MinMax: '<S1162>/Max' */

  /* UnitDelay: '<S1047>/Unit Delay' */
  rtb_Saturation66 = Chery_E03_Hp_DW.UnitDelay_DSTATE_pd;

  /* Outputs for Atomic SubSystem: '<S1162>/FirOrderLinear_Filter5' */
  /* Lookup_n-D: '<S1162>/Twat_Cmf_Req_Calculation' incorporates:
   *  Constant: '<S1162>/Constant1'
   *  Constant: '<S1248>/Constant'
   *  Constant: '<S1249>/Constant'
   *  Logic: '<S1047>/Logical Operator'
   *  RelationalOperator: '<S1248>/Compare'
   *  RelationalOperator: '<S1249>/Compare'
   */
  rtb_Conversion = (int16_T) Chery_E03_Hp_FirOrderLinear_Filter
    (look2_is16lu32n16Ds32ds32_binlcs(rtb_HpI_s16Teva_Front_A10, rtb_Saturation3,
      ((int16_T *)&(ACPre_s16TWat_CmfReq.ACPre_s16Teva_u1[0])), ((int16_T *)
       &(ACPre_s16TWat_CmfReq.ACPre_s16_Tasd_Max_u2[0])), ((int16_T *)
       &(ACPre_s16TWat_CmfReq.ACPre_s16TWat_CmfReq_y[0])),
      Chery_E03_Hp_ConstP.Twat_Cmf_Req_Calculation_maxIndex, 9U), (((int32_T)
       rtb_HpI_u8IgnSts) != 0) && (((int32_T)rtb_Saturation66) == 0), 20,
     &Chery_E03_Hp_ConstB.FirOrderLinear_Filter5,
     &Chery_E03_Hp_DW.FirOrderLinear_Filter5, 100);

  /* End of Outputs for SubSystem: '<S1162>/FirOrderLinear_Filter5' */

  /* Outputs for Atomic SubSystem: '<S1162>/IfThenElse' */
  /* SignalConversion: '<S1162>/Signal Copy' incorporates:
   *  Constant: '<S1162>/Constant'
   *  UnitDelay: '<S1176>/Unit Delay'
   */
  Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req = (int16_T) Chery_E03_Hp_IfThenElse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_lq, -400, rtb_Conversion);

  /* End of Outputs for SubSystem: '<S1162>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S1046>/bFlag_Tamb_HeatNotEnough' */
  /* Outputs for Atomic SubSystem: '<S1227>/Hyster_Judge' */
  /* Constant: '<S1227>/Constant' incorporates:
   *  Constant: '<S1227>/Constant1'
   *  Sum: '<S1227>/Sum'
   */
  rtb_Switch2 = ( Chery_E03_Hp_Hyster_Judge(20, (int16_T)
    (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - rtb_HpI_s16Tamb_A10), 0,
    &Chery_E03_Hp_DW.Hyster_Judge_p, Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1227>/Hyster_Judge' */

  /* Switch: '<S1227>/Switch' incorporates:
   *  Constant: '<S1227>/Constant2'
   */
  if (Chery_E03_Hp_B.bFlag_Cmf_NoHeatingReq) {
    Chery_E03_Hp_B.bDTC_Sysmtem_Prco = bCONST_0;
  } else {
    Chery_E03_Hp_B.bDTC_Sysmtem_Prco = rtb_Switch2;
  }

  /* End of Switch: '<S1227>/Switch' */
  /* End of Outputs for SubSystem: '<S1046>/bFlag_Tamb_HeatNotEnough' */

  /* Outputs for Atomic SubSystem: '<S1164>/IfThenElse' */
  /* Logic: '<S1164>/Logical Operator' incorporates:
   *  Constant: '<S1164>/Constant'
   *  Constant: '<S1206>/Constant'
   *  Constant: '<S1207>/Constant'
   *  RelationalOperator: '<S1206>/Compare'
   *  RelationalOperator: '<S1207>/Compare'
   */
  rtb_Saturation3 = (int16_T) Chery_E03_Hp_IfThenElse((rtb_HpI_u8BAT_CoolHeatLv ==
    u8BTM_HeatL4) || (rtb_HpI_u8BAT_CoolHeatLv == u8BTM_HeatL5),
    rtb_HpI_s16T_BAT_Wat_Set_A10, s16TEMP_LIMIT_M40);

  /* End of Outputs for SubSystem: '<S1164>/IfThenElse' */

  /* Switch: '<S1165>/Switch' */
  Chery_E03_Hp_B.Switch = Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req;

  /* Outputs for Atomic SubSystem: '<S1045>/CMF_u16_QBlower_HVAC' */
  /* UnitDelay: '<S1205>/Unit Delay' */
  rtb_Saturation66 = Chery_E03_Hp_DW.UnitDelay_DSTATE_gy;

  /* Product: '<S1205>/Multiply1' incorporates:
   *  Product: '<S1205>/Multiply'
   *  Sum: '<S1205>/Sum'
   */
  rtb_Sum4_e = asr_s32(((int32_T)((uint32_T)(((uint32_T)rtb_Saturation66) * 3U)))
                       + ((int32_T)rtb_HpI_u8BlwVol_Real_A10), 2U);

  /* Saturate: '<S1205>/Saturation' incorporates:
   *  UnitDelay: '<S1205>/Unit Delay'
   */
  if (rtb_Sum4_e > 150) {
    rtb_Sum4_e = 150;
  }

  Chery_E03_Hp_DW.UnitDelay_DSTATE_gy = (uint8_T)rtb_Sum4_e;

  /* End of Saturate: '<S1205>/Saturation' */

  /* Lookup_n-D: '<S1163>/Air_Flow_Rate_Estimation_Fullhot' incorporates:
   *  UnitDelay: '<S1205>/Unit Delay'
   */
  Chery_E03_Hp_B.CMF_u16_QBlower_HVAC = look2_iu8lu32n16tu16_binlcse
    (rtb_HpI_u8ModeStatus_Real, Chery_E03_Hp_DW.UnitDelay_DSTATE_gy, ((uint8_T *)
      &(u16QAir_Estimation_HVPTC_FullHot.u8Mode_HVAC_u1[0])), ((uint8_T *)
      &(u16QAir_Estimation_HVPTC_FullHot.u8HVAC_BlwVol_HVPTC_u2[0])), ((uint16_T
       *)&(u16QAir_Estimation_HVPTC_FullHot.u16QAir_Estimation_HVPTC_FullHot_y[0])),
     Chery_E03_Hp_ConstP.pooled15, 7U);

  /* End of Outputs for SubSystem: '<S1045>/CMF_u16_QBlower_HVAC' */

  /* Outputs for Atomic SubSystem: '<S1046>/bFlag_ACDehum_NotEnough' */
  /* Outputs for Atomic SubSystem: '<S1224>/Hyster_Judge' */
  /* Constant: '<S1224>/Constant' incorporates:
   *  Constant: '<S1224>/Constant1'
   *  Lookup_n-D: '<S1046>/Twater_Max_ACDehum_Y'
   *  Sum: '<S1224>/Sum'
   */
  rtb_Switch2_iy = ( Chery_E03_Hp_Hyster_Judge(20, (int16_T)
    (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
     look2_is16u16lu32n16ts16Ds32ds32_binlcs(rtb_HpI_s16Tamb_A10,
    Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
    &(s16Twater_Max_ACDehum.s16Tamb_ACDehum_u1[0])), ((uint16_T *)
    &(s16Twater_Max_ACDehum.u16_QBlower_HVAC_u2[0])), ((int16_T *)
    &(s16Twater_Max_ACDehum.s16Twater_Max_ACDehum_y[0])),
    Chery_E03_Hp_ConstP.pooled15, 7U)), 0, &Chery_E03_Hp_DW.Hyster_Judge_b,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1224>/Hyster_Judge' */
  /* End of Outputs for SubSystem: '<S1046>/bFlag_ACDehum_NotEnough' */

  /* Lookup_n-D: '<S1046>/Twater_Min_TotalDehum_Y' */
  Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y =
    look2_is16u16lu32n16ts16Ds32ds32_binlcs(rtb_HpI_s16Tamb_A10,
    Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
    &(s16Twater_Min_TotalDehum.s16Tamb_ACDehum_u1[0])), ((uint16_T *)
    &(s16Twater_Min_TotalDehum.u16_QBlower_HVAC_u2[0])), ((int16_T *)
    &(s16Twater_Min_TotalDehum.s16Twater_Min_TotalDehum_y[0])),
    Chery_E03_Hp_ConstP.pooled15, 7U);

  /* Outputs for Atomic SubSystem: '<S1046>/bFlag_TotalDehum_OverHeat' */
  /* Outputs for Atomic SubSystem: '<S1229>/Hyster_Judge' */
  /* Constant: '<S1229>/Constant' incorporates:
   *  Constant: '<S1229>/Constant1'
   *  Sum: '<S1229>/Sum'
   */
  rtb_Switch2_mj = ( Chery_E03_Hp_Hyster_Judge(20, (int16_T)
    (Chery_E03_Hp_B.s16Twater_Min_TotalDehum_Y -
     Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req), 0, &Chery_E03_Hp_DW.Hyster_Judge_jg,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1229>/Hyster_Judge' */
  /* End of Outputs for SubSystem: '<S1046>/bFlag_TotalDehum_OverHeat' */

  /* Lookup_n-D: '<S1046>/s16Twater_Max_HP' */
  Chery_E03_Hp_B.s16Twater_Max_HP_Y = look2_is16u16lu32n16ts16Ds32ds32_binlcs
    (rtb_HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
      &(s16Twater_Max_HP.s16Tamb_HP_u1[0])), ((uint16_T *)
      &(s16Twater_Max_HP.u16_QBlower_HVAC_u2[0])), ((int16_T *)
      &(s16Twater_Max_HP.s16Twater_Max_HP_y[0])), Chery_E03_Hp_ConstP.pooled15,
     7U);

  /* Outputs for Atomic SubSystem: '<S1046>/bFlag_HP_NotEnough' */
  /* Outputs for Atomic SubSystem: '<S1225>/Hyster_Judge' */
  /* Constant: '<S1225>/Constant' incorporates:
   *  Constant: '<S1225>/Constant1'
   *  Sum: '<S1225>/Sum'
   */
  rtb_Switch2_dt = ( Chery_E03_Hp_Hyster_Judge(20, (int16_T)
    (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req - Chery_E03_Hp_B.s16Twater_Max_HP_Y), 0,
    &Chery_E03_Hp_DW.Hyster_Judge_j, Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1225>/Hyster_Judge' */
  /* End of Outputs for SubSystem: '<S1046>/bFlag_HP_NotEnough' */

  /* Lookup_n-D: '<S1046>/s16Twater_Min_HP' */
  Chery_E03_Hp_B.s16Twater_Min_HP_Y = look2_is16u16lu32n16ts16Ds32ds32_binlcs
    (rtb_HpI_s16Tamb_A10, Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
      &(s16Twater_Min_HP.s16Tamb_Common2_u1[0])), ((uint16_T *)
      &(s16Twater_Min_HP.u16_QBlower_HVAC_u2[0])), ((int16_T *)
      &(s16Twater_Min_HP.s16Twater_Min_HP_y[0])), Chery_E03_Hp_ConstP.pooled17,
     10U);

  /* Outputs for Atomic SubSystem: '<S1046>/bFlag_HP_OverHeat' */
  /* Outputs for Atomic SubSystem: '<S1226>/Hyster_Judge' */
  /* Constant: '<S1226>/Constant' incorporates:
   *  Constant: '<S1226>/Constant1'
   *  Sum: '<S1226>/Sum'
   */
  Chery_E03_Hp_B.Switch2 = ( Chery_E03_Hp_Hyster_Judge(20, (int16_T)
    (Chery_E03_Hp_B.s16Twater_Min_HP_Y - Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req), 0,
    &Chery_E03_Hp_DW.Hyster_Judge_h, Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1226>/Hyster_Judge' */
  /* End of Outputs for SubSystem: '<S1046>/bFlag_HP_OverHeat' */

  /* Outputs for Atomic SubSystem: '<S1046>/bFlag_TotalDehum_NotEnough' */
  /* Outputs for Atomic SubSystem: '<S1228>/Hyster_Judge' */
  /* Constant: '<S1228>/Constant' incorporates:
   *  Constant: '<S1228>/Constant1'
   *  Lookup_n-D: '<S1046>/s16Twater_Max_TotalDehum'
   *  Sum: '<S1228>/Sum'
   */
  rtb_Switch2_af = ( Chery_E03_Hp_Hyster_Judge(20, (int16_T)
    (Chery_E03_Hp_B.CMF_s16_Twat_Cmf_Req -
     look2_is16u16lu32n16ts16Ds32ds32_binlcs(rtb_HpI_s16Tamb_A10,
    Chery_E03_Hp_B.CMF_u16_QBlower_HVAC, ((int16_T *)
    &(s16Twater_Max_TotalDehum.s16Tamb_ACDehum_u1[0])), ((uint16_T *)
    &(s16Twater_Max_TotalDehum.u16_QBlower_HVAC_u2[0])), ((int16_T *)
    &(s16Twater_Max_TotalDehum.s16Twater_Max_TotalDehum_y[0])),
    Chery_E03_Hp_ConstP.pooled15, 7U)), 0, &Chery_E03_Hp_DW.Hyster_Judge_os,
    Chery_E03_Hp_ConstP.pooled4) != false);

  /* End of Outputs for SubSystem: '<S1228>/Hyster_Judge' */
  /* End of Outputs for SubSystem: '<S1046>/bFlag_TotalDehum_NotEnough' */

  /* Outputs for Atomic SubSystem: '<S1130>/IfThenElse1' */
  /* Constant: '<S1130>/Constant1' incorporates:
   *  UnitDelay: '<S1130>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_l, bFAILRISK_NO_0,
    Chery_E03_Hp_DW.UnitDelay_DSTATE_c4, &rtb_Compare_ool);

  /* End of Outputs for SubSystem: '<S1130>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S1130>/IfThenElse' */
  /* Constant: '<S1130>/Constant' incorporates:
   *  UnitDelay: '<S1130>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_np, bFAILRISK_YES_1, rtb_Compare_ool,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_c4);

  /* End of Outputs for SubSystem: '<S1130>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S1115>/IfThenElse1' */
  /* Constant: '<S1115>/Constant1' incorporates:
   *  UnitDelay: '<S1115>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_p2, bFAILRISK_NO_0,
    Chery_E03_Hp_DW.UnitDelay_DSTATE_op, &rtb_Compare_ool);

  /* End of Outputs for SubSystem: '<S1115>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S1115>/IfThenElse' */
  /* Constant: '<S1115>/Constant' incorporates:
   *  UnitDelay: '<S1115>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_d5, bFAILRISK_YES_1, rtb_Compare_ool,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_op);

  /* End of Outputs for SubSystem: '<S1115>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S1100>/IfThenElse1' */
  /* Constant: '<S1100>/Constant1' incorporates:
   *  UnitDelay: '<S1100>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_a, bFAILRISK_NO_0,
    Chery_E03_Hp_DW.UnitDelay_DSTATE_my, &rtb_Compare_ool);

  /* End of Outputs for SubSystem: '<S1100>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S1100>/IfThenElse' */
  /* Constant: '<S1100>/Constant' incorporates:
   *  UnitDelay: '<S1100>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_m1, bFAILRISK_YES_1, rtb_Compare_ool,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_my);

  /* End of Outputs for SubSystem: '<S1100>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S1085>/IfThenElse1' */
  /* Constant: '<S1085>/Constant1' incorporates:
   *  UnitDelay: '<S1085>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_j, bFAILRISK_NO_0,
    Chery_E03_Hp_DW.UnitDelay_DSTATE_p0, &rtb_Compare_ool);

  /* End of Outputs for SubSystem: '<S1085>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S1085>/IfThenElse' */
  /* Constant: '<S1085>/Constant' incorporates:
   *  UnitDelay: '<S1085>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_fd, bFAILRISK_YES_1, rtb_Compare_ool,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_p0);

  /* End of Outputs for SubSystem: '<S1085>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S1070>/IfThenElse1' */
  /* Constant: '<S1070>/Constant1' incorporates:
   *  UnitDelay: '<S1070>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_g, bFAILRISK_NO_0,
    Chery_E03_Hp_DW.UnitDelay_DSTATE_e, &rtb_Compare_ool);

  /* End of Outputs for SubSystem: '<S1070>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S1070>/IfThenElse' */
  /* Constant: '<S1070>/Constant' incorporates:
   *  UnitDelay: '<S1070>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_h0, bFAILRISK_YES_1, rtb_Compare_ool,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_e);

  /* End of Outputs for SubSystem: '<S1070>/IfThenElse' */

  /* Outputs for Atomic SubSystem: '<S1055>/IfThenElse1' */
  /* Constant: '<S1055>/Constant1' incorporates:
   *  UnitDelay: '<S1055>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_n, bFAILRISK_NO_0,
    Chery_E03_Hp_DW.UnitDelay_DSTATE_eb, &rtb_Compare_ool);

  /* End of Outputs for SubSystem: '<S1055>/IfThenElse1' */

  /* Outputs for Atomic SubSystem: '<S1055>/IfThenElse' */
  /* Constant: '<S1055>/Constant' incorporates:
   *  UnitDelay: '<S1055>/Unit Delay'
   */
  Chery_E03_Hp_IfThenElse_c(rtb_SignalCopy_i, bFAILRISK_YES_1, rtb_Compare_ool,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_eb);

  /* End of Outputs for SubSystem: '<S1055>/IfThenElse' */

  /* Switch: '<S1161>/Switch' incorporates:
   *  Constant: '<S1161>/Constant'
   *  Constant: '<S1175>/Constant'
   *  RelationalOperator: '<S1175>/Compare'
   */
  if (rtb_Compare_fg != ACPre_bAGS_AVAILABLE) {
    rtb_HpI_u8AGS_Position = ACPre_u8AGS_MAX;
  }

  /* End of Switch: '<S1161>/Switch' */

  /* Outputs for Atomic SubSystem: '<S1045>/Data Type Conversion' */
  rtb_Saturation = (uint16_T) Chery_E03_Hp_DataTypeConversion20(rtb_HpI_u8VehSpd);

  /* End of Outputs for SubSystem: '<S1045>/Data Type Conversion' */

  /* Outputs for Atomic SubSystem: '<S1045>/Data Type Conversion1' */
  rtb_Saturation_nn = (uint16_T) Chery_E03_Hp_DataTypeConversion20
    (rtb_HpI_u8PWM_FrontFAN);

  /* End of Outputs for SubSystem: '<S1045>/Data Type Conversion1' */

  /* Outputs for Atomic SubSystem: '<S1045>/Front_FAN_Speed_Calculation' */
  /* Lookup_n-D: '<S1168>/2-D Lookup Table' */
  rtb_Saturation72 = look2_iu16lu32n16_binlcse(rtb_Saturation_nn, rtb_Saturation,
    ((uint16_T *)&(AC_u16Vair_Front.AC_u16PWM_FrontFAN_u1[0])), ((uint16_T *)
    &(AC_u16Vair_Front.AC_u16Vspd_u2[0])), ((uint16_T *)
    &(AC_u16Vair_Front.AC_u16Vair_Front_y[0])), Chery_E03_Hp_ConstP.pooled15, 7U);

  /* Outputs for Atomic SubSystem: '<S1168>/Data Type Conversion' */
  rtb_Saturation_nn = (uint16_T) Chery_E03_Hp_DataTypeConversion(rtb_Saturation);

  /* End of Outputs for SubSystem: '<S1168>/Data Type Conversion' */

  /* Lookup_n-D: '<S1168>/2-D Lookup Table1' */
  rtb_Saturation66 = look2_iu8u16lu32n16tu8_binlcse(rtb_HpI_u8AGS_Position,
    rtb_Saturation_nn, ((uint8_T *)&(ACPre_u8AGSFactor.ACPre_u8AGS_Position_u1[0])),
    ((uint16_T *)&(ACPre_u8AGSFactor.AC_u16Vspd_u2[0])), ((uint8_T *)
    &(ACPre_u8AGSFactor.ACPre_u8AGSFactor_y[0])),
    Chery_E03_Hp_ConstP.uDLookupTable1_maxIndex, 5U);

  /* Product: '<S1168>/Divide1' incorporates:
   *  Constant: '<S1168>/Constant'
   *  Product: '<S1168>/Divide'
   */
  Chery_E03_Hp_B.AC_u16Vair_Condensor_E = (uint16_T)((((uint32_T)
    rtb_Saturation66) * ((uint32_T)rtb_Saturation72)) / ((uint32_T)u16AMP_100));

  /* End of Outputs for SubSystem: '<S1045>/Front_FAN_Speed_Calculation' */

  /* Outputs for Atomic SubSystem: '<S1045>/High_Pressure_Saturation_Temp_Calculation'
   *
   * Block description for '<S1045>/High_Pressure_Saturation_Temp_Calculation':
   *  Calculatin the SH for the R134a before Compressor Inlet
   *  Use the satuation ti limit the range from 0 to 20 degree
   */
  /* Outputs for Atomic SubSystem: '<S1169>/R134a_SatTempCal_P_A10' */
  rtb_R134A_P_a10_T_a10_Table = (int16_T) Chery_E03_Hp_R134a_SatTempCal_P_A10_
    (rtb_HpI_u16P_Ref_CondOut_A10);

  /* End of Outputs for SubSystem: '<S1169>/R134a_SatTempCal_P_A10' */
  /* End of Outputs for SubSystem: '<S1045>/High_Pressure_Saturation_Temp_Calculation' */

  /* Outputs for Atomic SubSystem: '<S1045>/LowPressure_Saturation_Temp_Calculation'
   *
   * Block description for '<S1045>/LowPressure_Saturation_Temp_Calculation':
   *  Calculatin the SH for the R134a before Compressor Inlet
   *  Use the satuation ti limit the range from 0 to 20 degree
   */
  /* Outputs for Atomic SubSystem: '<S1170>/R134a_SatTempCal_P_A10' */
  Chery_E03_Hp_B.R134A_P_a10_T_a10_Table = (int16_T)
    Chery_E03_Hp_R134a_SatTempCal_P_A10_(Chery_E03_Hp_B.Hp_u16SH_CompInlet);

  /* End of Outputs for SubSystem: '<S1170>/R134a_SatTempCal_P_A10' */
  /* End of Outputs for SubSystem: '<S1045>/LowPressure_Saturation_Temp_Calculation' */

  /* Outputs for Atomic SubSystem: '<S1045>/MidPressure_Saturation_Temp_Calculation'
   *
   * Block description for '<S1045>/MidPressure_Saturation_Temp_Calculation':
   *  Calculatin the SH for the R134a before Compressor Inlet
   *  Use the satuation ti limit the range from 0 to 20 degree
   */
  /* Outputs for Atomic SubSystem: '<S1171>/R134a_SatTempCal_P_A10' */
  rtb_R134A_P_a10_T_a10_Table_m = (int16_T) Chery_E03_Hp_R134a_SatTempCal_P_A10_
    (rtb_HpI_u16P_Ref_EvaOut_A10);

  /* End of Outputs for SubSystem: '<S1171>/R134a_SatTempCal_P_A10' */
  /* End of Outputs for SubSystem: '<S1045>/MidPressure_Saturation_Temp_Calculation' */

  /* Outputs for Atomic SubSystem: '<S1045>/SH_Chil_Outlet_Calculation'
   *
   * Block description for '<S1045>/SH_Chil_Outlet_Calculation':
   *  Super heating of the evaporator outlet/EDC Inlet calculation
   *  For the EXV calculation
   */
  Chery_E03_Hp_SH_Chil_Outlet_Calculation();

  /* End of Outputs for SubSystem: '<S1045>/SH_Chil_Outlet_Calculation' */

  /* Outputs for Atomic SubSystem: '<S1045>/SH_Comp_Inlet_Calculation'
   *
   * Block description for '<S1045>/SH_Comp_Inlet_Calculation':
   *  Super heating of the evaporator outlet/EDC Inlet calculation
   *  For the EXV calculation
   */
  Chery_E03_Hp_SH_Comp_Inlet_Calculation();

  /* End of Outputs for SubSystem: '<S1045>/SH_Comp_Inlet_Calculation' */

  /* Outputs for Atomic SubSystem: '<S1045>/Teva_upstream_Estimation' */
  /* Product: '<S1174>/Product2' incorporates:
   *  Constant: '<S1174>/Constant'
   *  Constant: '<S1174>/Constant1'
   *  Product: '<S1174>/Product'
   *  Product: '<S1174>/Product1'
   *  Sum: '<S1174>/Sum'
   *  Sum: '<S1174>/Sum1'
   */
  rtb_Product6 = div_nde_s32_floor(((((int32_T)u8FLAP_POS_100) - ((int32_T)
    rtb_HpI_u8IntakePerc_Real)) * ((int32_T)rtb_HpI_s16Tincar_Front_A10)) +
    (((int32_T)rtb_HpI_s16Tamb_A10) * ((int32_T)rtb_HpI_u8IntakePerc_Real)),
    (int32_T)u8FLAP_POS_100);

  /* Saturate: '<S1174>/Saturation' */
  if (rtb_Product6 > ((int32_T)s16TEVA_UPLIMIT)) {
    rtb_Product6 = (int32_T)s16TEVA_UPLIMIT;
  } else {
    if (rtb_Product6 < ((int32_T)s16TEVA_DOWNLIMIT)) {
      rtb_Product6 = (int32_T)s16TEVA_DOWNLIMIT;
    }
  }

  /* Saturate: '<Root>/Saturation3' incorporates:
   *  Saturate: '<S1174>/Saturation'
   */
  Chery_E03_Hp_B.AC_s16Tairevaup_E = (int16_T)rtb_Product6;

  /* End of Outputs for SubSystem: '<S1045>/Teva_upstream_Estimation' */

  /* Logic: '<S1046>/OR' incorporates:
   *  Constant: '<S1219>/Constant'
   *  Constant: '<S1220>/Constant'
   *  Constant: '<S1221>/Constant'
   *  RelationalOperator: '<S1219>/Compare'
   *  RelationalOperator: '<S1220>/Compare'
   *  RelationalOperator: '<S1221>/Compare'
   */
  Chery_E03_Hp_B.bBTM_CoolReq_Yes = (((rtb_HpI_u8BAT_CoolHeatLv == u8BTMCOOL_1) ||
    (rtb_HpI_u8BAT_CoolHeatLv == u8BTMCOOL_2)) || (rtb_HpI_u8BAT_CoolHeatLv ==
    u8BTMCOOL_3));

  /* Logic: '<S1046>/OR1' incorporates:
   *  Constant: '<S1222>/Constant'
   *  Constant: '<S1223>/Constant'
   *  RelationalOperator: '<S1222>/Compare'
   *  RelationalOperator: '<S1223>/Compare'
   */
  Chery_E03_Hp_B.bBTM_HeatReq_Yes = ((rtb_HpI_u8BAT_CoolHeatLv == u8BTM_HeatL4) ||
    (rtb_HpI_u8BAT_CoolHeatLv == u8BTM_HeatL5));

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Outputs for Atomic SubSystem: '<S1>/WorkingModeRequest'
   *
   * Block description for '<S1>/WorkingModeRequest':
   *  Working Mode Request
   *  Working mode request according the AC Request and the Chiller request.

   */
  Chery_E03_Hp_WorkingModeRequest();

  /* End of Outputs for SubSystem: '<S1>/WorkingModeRequest' */

  /* Outputs for Atomic SubSystem: '<S36>/MixStepperLeftControl' */
  /* Outputs for Atomic SubSystem: '<S43>/PomiEstCal' */
  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Sum: '<S49>/Sum' incorporates:
   *  Constant: '<S49>/Constant11'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  rtb_HpI_s16Tamb_A10 = (int16_T)(((int16_T)(rtb_HpI_s16Tasd_Left_Req_A10 -
    Chery_E03_Hp_B.HpI_s16Teva_Front_A10)) - 45);

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Saturate: '<S49>/Saturation' */
  if (rtb_HpI_s16Tamb_A10 > s16TEMP_UPLIMIT) {
    rtb_HpI_s16Tamb_A10 = s16TEMP_UPLIMIT;
  } else {
    if (rtb_HpI_s16Tamb_A10 < s16TEMP_POMILIMIT_0) {
      rtb_HpI_s16Tamb_A10 = s16TEMP_POMILIMIT_0;
    }
  }

  /* End of Saturate: '<S49>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S36>/MixStepperRightControl' */
  /* Outputs for Atomic SubSystem: '<S44>/MixFlap_PI' */
  /* Outputs for Atomic SubSystem: '<S44>/PomiEstCal' */
  /* Outputs for Atomic SubSystem: '<S43>/MixFlap_PI' */
  /* Sum: '<S49>/Sum1' incorporates:
   *  Sum: '<S46>/Sum1'
   *  Sum: '<S67>/Sum1'
   *  Sum: '<S70>/Sum1'
   */
  rtb_HpI_s16Teva_Front_A10 = (int16_T)(Chery_E03_Hp_B.HpI_s16T_Wat_HVCHOut_A10
    - Chery_E03_Hp_B.HpI_s16Teva_Front_A10);

  /* End of Outputs for SubSystem: '<S43>/MixFlap_PI' */
  /* End of Outputs for SubSystem: '<S44>/PomiEstCal' */
  /* End of Outputs for SubSystem: '<S44>/MixFlap_PI' */
  /* End of Outputs for SubSystem: '<S36>/MixStepperRightControl' */

  /* Saturate: '<S49>/Saturation1' incorporates:
   *  Sum: '<S49>/Sum1'
   */
  if (rtb_HpI_s16Teva_Front_A10 > s16TEMP_UPLIMIT) {
    rtb_HpI_s16Tincar_Front_A10 = s16TEMP_UPLIMIT;
  } else if (rtb_HpI_s16Teva_Front_A10 < s16TEMP_POMILIMIT_30) {
    rtb_HpI_s16Tincar_Front_A10 = s16TEMP_POMILIMIT_30;
  } else {
    rtb_HpI_s16Tincar_Front_A10 = rtb_HpI_s16Teva_Front_A10;
  }

  /* End of Saturate: '<S49>/Saturation1' */

  /* Product: '<S49>/Product' incorporates:
   *  Constant: '<S49>/Constant'
   */
  rtb_Product6 = div_nde_s32_floor(((int32_T)rtb_HpI_s16Tamb_A10) * ((int32_T)
    u16AMP_1000), (int32_T)rtb_HpI_s16Tincar_Front_A10);

  /* Saturate: '<S49>/Pomi_Limitation' */
  if (rtb_Product6 > ((int32_T)s16POMILIMIT_1000)) {
    rtb_Product6 = (int32_T)s16POMILIMIT_1000;
  } else {
    if (rtb_Product6 < ((int32_T)s16POMILIMIT_0)) {
      rtb_Product6 = (int32_T)s16POMILIMIT_0;
    }
  }

  /* End of Saturate: '<S49>/Pomi_Limitation' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Abs: '<S49>/Abs' incorporates:
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   *  Sum: '<S49>/Sum2'
   */
  rtb_HpI_s16Tamb_A10 = (int16_T)(rtb_HpI_s16TDuct_Left_Out_A10 -
    rtb_HpI_s16Tasd_Left_Req_A10);

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  if (rtb_HpI_s16Tamb_A10 < 0) {
    rtb_HpI_s16Tamb_A10 = (int16_T)(-rtb_HpI_s16Tamb_A10);
  }

  /* End of Abs: '<S49>/Abs' */

  /* Outputs for Atomic SubSystem: '<S49>/IfThenElse' */
  /* UnitDelay: '<S49>/Unit Delay' incorporates:
   *  Constant: '<S49>/Constant1'
   *  RelationalOperator: '<S49>/Relational Operator'
   */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_p5 = (int16_T) Chery_E03_Hp_IfThenElse
    (rtb_HpI_s16Tamb_A10 >= 20, (int16_T)rtb_Product6,
     Chery_E03_Hp_DW.UnitDelay_DSTATE_p5);

  /* End of Outputs for SubSystem: '<S49>/IfThenElse' */
  /* End of Outputs for SubSystem: '<S43>/PomiEstCal' */

  /* Outputs for Atomic SubSystem: '<S43>/POMI_Selction_Accoridng_Mode' */
  /* Lookup_n-D: '<S48>/Pomi_Table_Vent' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_HpI_u8VehSpd = look1_is16lu16n8tu8_binlcse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_p5, ((int16_T *)
      &(u8Pos_MixStepper_Pomi.s16POMI_Mix_Vent[0])), ((uint8_T *)
      &(u8Pos_MixStepper_Pomi.u8Pos_MixStepper_Pomi_y[0])), 10U);

  /* Lookup_n-D: '<S48>/Pomi_Table_Vent//feet' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_HpI_u8PWM_FrontFAN = look1_is16lu16n8tu8_binlcse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_p5, ((int16_T *)
      &(u8Pos_MixStepper_Pomi_95.s16POMI_Mix_VF[0])), ((uint8_T *)
      &(u8Pos_MixStepper_Pomi_95.u8Pos_MixStepper_Pomi_95_y[0])), 11U);

  /* Lookup_n-D: '<S48>/Pomi_Table_Feet' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_HpI_u8AGS_Position = look1_is16lu16n8tu8_binlcse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_p5, ((int16_T *)
      &(u8Pos_MixStepper_Pomi_95.s16POMI_Mix_VF[0])), ((uint8_T *)
      &(u8Pos_MixStepper_Pomi_95.u8Pos_MixStepper_Pomi_95_y[0])), 11U);

  /* Lookup_n-D: '<S48>/Pomi_Table_FeetDef' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_HpI_u8BlwVol_Real_A10 = look1_is16lu16n8tu8_binlcse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_p5, ((int16_T *)
      &(u8Pos_MixStepper_Pomi.s16POMI_Mix_Vent[0])), ((uint8_T *)
      &(u8Pos_MixStepper_Pomi.u8Pos_MixStepper_Pomi_y[0])), 10U);

  /* Lookup_n-D: '<S48>/Pomi_Table_DEF' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_HpI_u8IntakePerc_Real = look1_is16lu16n8tu8_binlcse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_p5, ((int16_T *)
      &(u8Pos_MixStepper_Pomi.s16POMI_Mix_Vent[0])), ((uint8_T *)
      &(u8Pos_MixStepper_Pomi.u8Pos_MixStepper_Pomi_y[0])), 10U);

  /* Lookup_n-D: '<S48>/Pomi_Table_VFD' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_IC39 = look1_is16lu16n8tu8_binlcse(Chery_E03_Hp_DW.UnitDelay_DSTATE_p5,
    ((int16_T *)&(u8Pos_MixStepper_Pomi_95.s16POMI_Mix_VF[0])), ((uint8_T *)
    &(u8Pos_MixStepper_Pomi_95.u8Pos_MixStepper_Pomi_95_y[0])), 11U);

  /* Lookup_n-D: '<S48>/Pomi_Common' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_HpI_u8BAT_CoolHeatLv = look1_is16lu16n8tu8_binlcse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_p5, ((int16_T *)
      &(u8Pos_MixStepper_Pomi.s16POMI_Mix_Vent[0])), ((uint8_T *)
      &(u8Pos_MixStepper_Pomi.u8Pos_MixStepper_Pomi_y[0])), 10U);

  /* Lookup_n-D: '<S48>/Pomi_Table_VD' incorporates:
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_Saturation66 = look1_is16lu16n8tu8_binlcse
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_p5, ((int16_T *)
      &(u8Pos_MixStepper_Pomi_95.s16POMI_Mix_VF[0])), ((uint8_T *)
      &(u8Pos_MixStepper_Pomi_95.u8Pos_MixStepper_Pomi_95_y[0])), 11U);

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Switch: '<S48>/Switch6' incorporates:
   *  Constant: '<S60>/Constant'
   *  RelationalOperator: '<S60>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_VD_6) {
    rtb_Saturation66 = rtb_HpI_u8BAT_CoolHeatLv;
  }

  /* End of Switch: '<S48>/Switch6' */

  /* Switch: '<S48>/Switch5' incorporates:
   *  Constant: '<S59>/Constant'
   *  RelationalOperator: '<S59>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_VFD_5) {
    rtb_IC39 = rtb_Saturation66;
  }

  /* End of Switch: '<S48>/Switch5' */

  /* Switch: '<S48>/Switch4' incorporates:
   *  Constant: '<S58>/Constant'
   *  RelationalOperator: '<S58>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_DEF_4) {
    rtb_HpI_u8IntakePerc_Real = rtb_IC39;
  }

  /* End of Switch: '<S48>/Switch4' */

  /* Switch: '<S48>/Switch3' incorporates:
   *  Constant: '<S57>/Constant'
   *  RelationalOperator: '<S57>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_FD_3) {
    rtb_HpI_u8BlwVol_Real_A10 = rtb_HpI_u8IntakePerc_Real;
  }

  /* End of Switch: '<S48>/Switch3' */

  /* Switch: '<S48>/Switch2' incorporates:
   *  Constant: '<S56>/Constant'
   *  RelationalOperator: '<S56>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_FEET_2) {
    rtb_HpI_u8AGS_Position = rtb_HpI_u8BlwVol_Real_A10;
  }

  /* End of Switch: '<S48>/Switch2' */

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S55>/Constant'
   *  RelationalOperator: '<S55>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_VF_1) {
    rtb_HpI_u8PWM_FrontFAN = rtb_HpI_u8AGS_Position;
  }

  /* End of Switch: '<S48>/Switch' */

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S54>/Constant'
   *  RelationalOperator: '<S54>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_VENT_0) {
    rtb_HpI_u8VehSpd = rtb_HpI_u8PWM_FrontFAN;
  }

  /* End of Switch: '<S48>/Switch1' */
  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Product: '<S48>/Product4' incorporates:
   *  Constant: '<S48>/Constant2'
   */
  rtb_s32MixEst_Amp10000 = (int32_T)((uint32_T)(((uint32_T)rtb_HpI_u8VehSpd) *
    ((uint32_T)u16AMP_10000)));

  /* End of Outputs for SubSystem: '<S43>/POMI_Selction_Accoridng_Mode' */

  /* Outputs for Atomic SubSystem: '<S43>/MixFlap_PI' */
  /* UnitDelay: '<S46>/Unit Delay' */
  rtb_Product6 = Chery_E03_Hp_DW.UnitDelay_DSTATE_p3;

  /* Switch: '<S46>/Switch1' incorporates:
   *  Constant: '<S46>/Constant9'
   *  UnitDelay: '<S43>/Unit Delay'
   */
  if (Chery_E03_Hp_DW.UnitDelay_DSTATE_ap) {
    rtb_Product6 = 0;
  }

  /* End of Switch: '<S46>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Saturate: '<S46>/Saturation3' incorporates:
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   *  Sum: '<S46>/Sum2'
   */
  rtb_HpI_s16Tamb_A10 = (int16_T)(rtb_HpI_s16Tasd_Left_Req_A10 -
    rtb_HpI_s16TDuct_Left_Out_A10);

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  if (rtb_HpI_s16Tamb_A10 > s16TCTRL_DELTA_UPLIMIT) {
    rtb_Saturation3 = s16TCTRL_DELTA_UPLIMIT;
  } else if (rtb_HpI_s16Tamb_A10 < s16TCTRL_DELTA_DOWNLIMIT) {
    rtb_Saturation3 = s16TCTRL_DELTA_DOWNLIMIT;
  } else {
    rtb_Saturation3 = rtb_HpI_s16Tamb_A10;
  }

  /* End of Saturate: '<S46>/Saturation3' */

  /* Product: '<S46>/Product3' incorporates:
   *  Lookup_n-D: '<S46>/Hp_u16Ki_Mix_Normal'
   */
  rtb_Sum4_e = ((int32_T)rtb_Saturation3) * ((int32_T)
    look1_is16lu32n16tu16_binlcse(rtb_HpI_s16Teva_Front_A10, ((int16_T *)
    &(Hp_u16Ki_Mix_Normal.Hp_s16Tdelta_HC_Evap_u1[0])), ((uint16_T *)
    &(Hp_u16Ki_Mix_Normal.Hp_u16Ki_Mix_Normal_y[0])), 4U));

  /* Sum: '<S46>/Sum6' */
  rtb_Sum4_e += rtb_Product6;

  /* RelationalOperator: '<S53>/LowerRelop1' incorporates:
   *  UnitDelay: '<S43>/Unit Delay2'
   */
  rtb_OR1_ht = (rtb_Sum4_e > Chery_E03_Hp_DW.UnitDelay2_DSTATE_f);

  /* Switch: '<S53>/Switch' incorporates:
   *  RelationalOperator: '<S53>/UpperRelop'
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  if (rtb_Sum4_e < Chery_E03_Hp_DW.UnitDelay1_DSTATE_h) {
    rtb_Sum4_e = Chery_E03_Hp_DW.UnitDelay1_DSTATE_h;
  }

  /* End of Switch: '<S53>/Switch' */

  /* Switch: '<S53>/Switch2' incorporates:
   *  UnitDelay: '<S43>/Unit Delay2'
   *  UnitDelay: '<S46>/Unit Delay'
   */
  if (rtb_OR1_ht) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_p3 = Chery_E03_Hp_DW.UnitDelay2_DSTATE_f;
  } else {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_p3 = rtb_Sum4_e;
  }

  /* End of Switch: '<S53>/Switch2' */

  /* Product: '<S46>/Product2' incorporates:
   *  Lookup_n-D: '<S46>/Hp_u16Kp_Mix_Normal'
   */
  rtb_s32MixPcalAmp10000Left = ((int32_T)rtb_Saturation3) * ((int32_T)
    look1_is16lu32n16tu16_binlcse(rtb_HpI_s16Teva_Front_A10, ((int16_T *)
    &(Hp_u16Kp_Mix_Normal.Hp_s16Tdelta_HC_Evap_u1[0])), ((uint16_T *)
    &(Hp_u16Kp_Mix_Normal.Hp_u16Kp_Mix_Normal_y[0])), 4U));

  /* Product: '<S46>/Product7' incorporates:
   *  Constant: '<S46>/Constant7'
   *  Sum: '<S46>/Sum3'
   *  UnitDelay: '<S46>/Unit Delay'
   */
  rtb_Sum4_e = div_nde_s32_floor((rtb_s32MixEst_Amp10000 +
    rtb_s32MixPcalAmp10000Left) + Chery_E03_Hp_DW.UnitDelay_DSTATE_p3, (int32_T)
    u16AMP_10000);

  /* Saturate: '<S46>/Saturation2' */
  if (rtb_Sum4_e > ((int32_T)u8FLAP_POS_100)) {
    rtb_Product6 = (int32_T)u8FLAP_POS_100;
  } else if (rtb_Sum4_e < ((int32_T)u8FLAP_POS_0)) {
    rtb_Product6 = (int32_T)u8FLAP_POS_0;
  } else {
    rtb_Product6 = rtb_Sum4_e;
  }

  /* End of Outputs for SubSystem: '<S43>/MixFlap_PI' */

  /* Outputs for Atomic SubSystem: '<S36>/MixStepperRightControl' */
  /* Outputs for Atomic SubSystem: '<S44>/Mix_ParaILimit' */
  /* Outputs for Atomic SubSystem: '<S43>/Mix_ParaILimit' */
  /* Product: '<S47>/Product6' incorporates:
   *  Constant: '<S47>/Constant13'
   *  Constant: '<S47>/Constant6'
   *  Product: '<S68>/Product6'
   */
  rtb_Product6_tmp = (int32_T)((uint32_T)(((uint32_T)u8FLAP_POS_0) * ((uint32_T)
    u16AMP_10000)));

  /* End of Outputs for SubSystem: '<S44>/Mix_ParaILimit' */
  /* End of Outputs for SubSystem: '<S36>/MixStepperRightControl' */

  /* Sum: '<S47>/Sum5' incorporates:
   *  Product: '<S47>/Product6'
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_h = rtb_Product6_tmp -
    rtb_s32MixEst_Amp10000;

  /* Outputs for Atomic SubSystem: '<S36>/MixStepperRightControl' */
  /* Outputs for Atomic SubSystem: '<S44>/Mix_ParaILimit' */
  /* Product: '<S47>/Product5' incorporates:
   *  Constant: '<S47>/Constant3'
   *  Constant: '<S47>/Constant4'
   *  Product: '<S68>/Product5'
   */
  rtb_Sum4_d_tmp = (int32_T)((uint32_T)(((uint32_T)u8FLAP_POS_100) * ((uint32_T)
    u16AMP_10000)));

  /* End of Outputs for SubSystem: '<S44>/Mix_ParaILimit' */
  /* End of Outputs for SubSystem: '<S36>/MixStepperRightControl' */

  /* Sum: '<S47>/Sum4' incorporates:
   *  Product: '<S47>/Product5'
   */
  rtb_Sum4_e = (rtb_Sum4_d_tmp - rtb_s32MixEst_Amp10000) -
    rtb_s32MixPcalAmp10000Left;

  /* MinMax: '<S47>/Max' incorporates:
   *  Product: '<S47>/Product6'
   */
  if (rtb_Product6_tmp > rtb_Sum4_e) {
    Chery_E03_Hp_DW.UnitDelay2_DSTATE_f = rtb_Product6_tmp;
  } else {
    Chery_E03_Hp_DW.UnitDelay2_DSTATE_f = rtb_Sum4_e;
  }

  /* End of MinMax: '<S47>/Max' */
  /* End of Outputs for SubSystem: '<S43>/Mix_ParaILimit' */

  /* Outputs for Atomic SubSystem: '<S43>/MixFlapReqCal' */
  /* Outputs for Atomic SubSystem: '<S43>/MixFlap_PI' */
  /* Constant: '<S36>/Constant2' incorporates:
   *  Saturate: '<S46>/Saturation2'
   *  UnitDelay: '<S43>/Unit Delay'
   */
  Chery_E03_Hp_MixFlapReqCal(rtb_bFlag_Cmf_NoHeatingReq_n,
    Chery_E03_Hp_B.HpI_s16Tset_Left_A10, bCONST_0, (uint8_T)rtb_Product6,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_ap, &rtb_HpI_u8PWM_FrontFAN);

  /* End of Outputs for SubSystem: '<S43>/MixFlap_PI' */
  /* End of Outputs for SubSystem: '<S43>/MixFlapReqCal' */
  /* End of Outputs for SubSystem: '<S36>/MixStepperLeftControl' */

  /* Outputs for Atomic SubSystem: '<S36>/MixStepperRightControl' */
  /* Outputs for Atomic SubSystem: '<S44>/PomiEstCal' */
  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Sum: '<S70>/Sum' incorporates:
   *  Constant: '<S70>/Constant11'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  rtb_HpI_s16Tamb_A10 = (int16_T)(((int16_T)(rtb_HpI_s16Tasd_Right_Req_A10 -
    Chery_E03_Hp_B.HpI_s16Teva_Front_A10)) - 45);

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Saturate: '<S70>/Saturation' */
  if (rtb_HpI_s16Tamb_A10 > s16TEMP_UPLIMIT) {
    rtb_HpI_s16Tamb_A10 = s16TEMP_UPLIMIT;
  } else {
    if (rtb_HpI_s16Tamb_A10 < s16TEMP_POMILIMIT_0) {
      rtb_HpI_s16Tamb_A10 = s16TEMP_POMILIMIT_0;
    }
  }

  /* End of Saturate: '<S70>/Saturation' */

  /* Saturate: '<S70>/Saturation1' */
  if (rtb_HpI_s16Teva_Front_A10 > s16TEMP_UPLIMIT) {
    rtb_HpI_s16Tincar_Front_A10 = s16TEMP_UPLIMIT;
  } else if (rtb_HpI_s16Teva_Front_A10 < s16TEMP_POMILIMIT_30) {
    rtb_HpI_s16Tincar_Front_A10 = s16TEMP_POMILIMIT_30;
  } else {
    rtb_HpI_s16Tincar_Front_A10 = rtb_HpI_s16Teva_Front_A10;
  }

  /* End of Saturate: '<S70>/Saturation1' */

  /* Product: '<S70>/Product' incorporates:
   *  Constant: '<S70>/Constant'
   */
  rtb_Product6 = div_nde_s32_floor(((int32_T)rtb_HpI_s16Tamb_A10) * ((int32_T)
    u16AMP_1000), (int32_T)rtb_HpI_s16Tincar_Front_A10);

  /* Saturate: '<S70>/Pomi_Limitation' */
  if (rtb_Product6 > ((int32_T)s16POMILIMIT_1000)) {
    rtb_Product6 = (int32_T)s16POMILIMIT_1000;
  } else {
    if (rtb_Product6 < ((int32_T)s16POMILIMIT_0)) {
      rtb_Product6 = (int32_T)s16POMILIMIT_0;
    }
  }

  /* Outputs for Atomic SubSystem: '<S44>/POMI_Selction_Accoridng_Mode' */
  /* Lookup_n-D: '<S69>/Pomi_Table_Vent' incorporates:
   *  Lookup_n-D: '<S69>/Pomi_Common'
   *  Lookup_n-D: '<S69>/Pomi_Table_DEF'
   *  Lookup_n-D: '<S69>/Pomi_Table_FeetDef'
   *  Saturate: '<S70>/Pomi_Limitation'
   */
  rtb_HpI_u8IntakePerc_Real = look1_is16lu16n8tu8_binlcse((int16_T)rtb_Product6,
    ((int16_T *)&(u8Pos_MixStepper_Pomi.s16POMI_Mix_Vent[0])), ((uint8_T *)
    &(u8Pos_MixStepper_Pomi.u8Pos_MixStepper_Pomi_y[0])), 10U);

  /* End of Outputs for SubSystem: '<S44>/PomiEstCal' */
  rtb_Saturation66 = rtb_HpI_u8IntakePerc_Real;

  /* Outputs for Atomic SubSystem: '<S44>/PomiEstCal' */
  /* Lookup_n-D: '<S69>/Pomi_Table_Vent//feet' incorporates:
   *  Lookup_n-D: '<S69>/Pomi_Table_Feet'
   *  Lookup_n-D: '<S69>/Pomi_Table_VD'
   *  Lookup_n-D: '<S69>/Pomi_Table_VFD'
   *  Saturate: '<S70>/Pomi_Limitation'
   */
  rtb_HpI_u8BAT_CoolHeatLv = look1_is16lu16n8tu8_binlcse((int16_T)rtb_Product6,
    ((int16_T *)&(u8Pos_MixStepper_Pomi_95.s16POMI_Mix_VF[0])), ((uint8_T *)
    &(u8Pos_MixStepper_Pomi_95.u8Pos_MixStepper_Pomi_95_y[0])), 11U);

  /* End of Outputs for SubSystem: '<S44>/PomiEstCal' */

  /* Lookup_n-D: '<S69>/Pomi_Table_Feet' */
  rtb_IC39 = rtb_HpI_u8BAT_CoolHeatLv;

  /* Lookup_n-D: '<S69>/Pomi_Table_DEF' */
  rtb_HpI_u8BlwVol_Real_A10 = rtb_HpI_u8IntakePerc_Real;

  /* Lookup_n-D: '<S69>/Pomi_Table_VFD' */
  rtb_HpI_u8AGS_Position = rtb_HpI_u8BAT_CoolHeatLv;

  /* Lookup_n-D: '<S69>/Pomi_Table_VD' */
  rtb_HpI_u8VehSpd = rtb_HpI_u8BAT_CoolHeatLv;

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Switch: '<S69>/Switch6' incorporates:
   *  Constant: '<S81>/Constant'
   *  RelationalOperator: '<S81>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_VD_6) {
    rtb_HpI_u8VehSpd = rtb_HpI_u8IntakePerc_Real;
  }

  /* End of Switch: '<S69>/Switch6' */

  /* Switch: '<S69>/Switch5' incorporates:
   *  Constant: '<S80>/Constant'
   *  RelationalOperator: '<S80>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_VFD_5) {
    rtb_HpI_u8AGS_Position = rtb_HpI_u8VehSpd;
  }

  /* End of Switch: '<S69>/Switch5' */

  /* Switch: '<S69>/Switch4' incorporates:
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S79>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_DEF_4) {
    rtb_HpI_u8BlwVol_Real_A10 = rtb_HpI_u8AGS_Position;
  }

  /* End of Switch: '<S69>/Switch4' */

  /* Switch: '<S69>/Switch3' incorporates:
   *  Constant: '<S78>/Constant'
   *  RelationalOperator: '<S78>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_FD_3) {
    rtb_HpI_u8IntakePerc_Real = rtb_HpI_u8BlwVol_Real_A10;
  }

  /* End of Switch: '<S69>/Switch3' */

  /* Switch: '<S69>/Switch2' incorporates:
   *  Constant: '<S77>/Constant'
   *  RelationalOperator: '<S77>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_FEET_2) {
    rtb_IC39 = rtb_HpI_u8IntakePerc_Real;
  }

  /* End of Switch: '<S69>/Switch2' */

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S76>/Constant'
   *  RelationalOperator: '<S76>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real != u8DIS_MODE_VF_1) {
    rtb_HpI_u8BAT_CoolHeatLv = rtb_IC39;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Switch: '<S69>/Switch1' incorporates:
   *  Constant: '<S75>/Constant'
   *  RelationalOperator: '<S75>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if (rtb_HpI_u8ModeStatus_Real == u8DIS_MODE_VENT_0) {
    rtb_HpI_u8BAT_CoolHeatLv = rtb_Saturation66;
  }

  /* End of Switch: '<S69>/Switch1' */
  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Product: '<S69>/Product4' incorporates:
   *  Constant: '<S69>/Constant2'
   */
  rtb_s32MixEst_Amp10000 = (int32_T)((uint32_T)(((uint32_T)
    rtb_HpI_u8BAT_CoolHeatLv) * ((uint32_T)u16AMP_10000)));

  /* End of Outputs for SubSystem: '<S44>/POMI_Selction_Accoridng_Mode' */

  /* Outputs for Atomic SubSystem: '<S44>/MixFlap_PI' */
  /* UnitDelay: '<S67>/Unit Delay' */
  rtb_Product6 = Chery_E03_Hp_DW.UnitDelay_DSTATE_j;

  /* Switch: '<S67>/Switch1' incorporates:
   *  Constant: '<S67>/Constant9'
   *  UnitDelay: '<S44>/Unit Delay'
   */
  if (Chery_E03_Hp_DW.UnitDelay_DSTATE_oo) {
    rtb_Product6 = 0;
  }

  /* End of Switch: '<S67>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Saturate: '<S67>/Saturation3' incorporates:
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   *  Sum: '<S67>/Sum2'
   */
  rtb_HpI_s16Tamb_A10 = (int16_T)(rtb_HpI_s16Tasd_Right_Req_A10 -
    rtb_HpI_s16TDuct_Right_Out_A10);

  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */
  if (rtb_HpI_s16Tamb_A10 > s16TCTRL_DELTA_UPLIMIT) {
    rtb_Saturation3 = s16TCTRL_DELTA_UPLIMIT;
  } else if (rtb_HpI_s16Tamb_A10 < s16TCTRL_DELTA_DOWNLIMIT) {
    rtb_Saturation3 = s16TCTRL_DELTA_DOWNLIMIT;
  } else {
    rtb_Saturation3 = rtb_HpI_s16Tamb_A10;
  }

  /* End of Saturate: '<S67>/Saturation3' */

  /* Product: '<S67>/Product3' incorporates:
   *  Lookup_n-D: '<S67>/Hp_u16Ki_Mix_Normal'
   */
  rtb_Sum4_e = ((int32_T)rtb_Saturation3) * ((int32_T)
    look1_is16lu32n16tu16_binlcse(rtb_HpI_s16Teva_Front_A10, ((int16_T *)
    &(Hp_u16Ki_Mix_Normal.Hp_s16Tdelta_HC_Evap_u1[0])), ((uint16_T *)
    &(Hp_u16Ki_Mix_Normal.Hp_u16Ki_Mix_Normal_y[0])), 4U));

  /* Sum: '<S67>/Sum6' */
  rtb_Sum4_e += rtb_Product6;

  /* RelationalOperator: '<S74>/LowerRelop1' incorporates:
   *  UnitDelay: '<S44>/Unit Delay2'
   */
  rtb_OR1_ht = (rtb_Sum4_e > Chery_E03_Hp_DW.UnitDelay2_DSTATE_e);

  /* Switch: '<S74>/Switch' incorporates:
   *  RelationalOperator: '<S74>/UpperRelop'
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  if (rtb_Sum4_e < Chery_E03_Hp_DW.UnitDelay1_DSTATE_p) {
    rtb_Sum4_e = Chery_E03_Hp_DW.UnitDelay1_DSTATE_p;
  }

  /* End of Switch: '<S74>/Switch' */

  /* Switch: '<S74>/Switch2' incorporates:
   *  UnitDelay: '<S44>/Unit Delay2'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  if (rtb_OR1_ht) {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_j = Chery_E03_Hp_DW.UnitDelay2_DSTATE_e;
  } else {
    Chery_E03_Hp_DW.UnitDelay_DSTATE_j = rtb_Sum4_e;
  }

  /* End of Switch: '<S74>/Switch2' */

  /* Lookup_n-D: '<S67>/Hp_u16Kp_Mix_Normal' */
  rtb_Saturation = look1_is16lu32n16tu16_binlcse(rtb_HpI_s16Teva_Front_A10,
    ((int16_T *)&(Hp_u16Kp_Mix_Normal.Hp_s16Tdelta_HC_Evap_u1[0])), ((uint16_T *)
    &(Hp_u16Kp_Mix_Normal.Hp_u16Kp_Mix_Normal_y[0])), 4U);

  /* Product: '<S67>/Product2' */
  rtb_Product6 = ((int32_T)rtb_Saturation3) * ((int32_T)rtb_Saturation);

  /* Product: '<S67>/Product7' incorporates:
   *  Constant: '<S67>/Constant7'
   *  Sum: '<S67>/Sum3'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  rtb_Sum4_e = div_nde_s32_floor((rtb_s32MixEst_Amp10000 + rtb_Product6) +
    Chery_E03_Hp_DW.UnitDelay_DSTATE_j, (int32_T)u16AMP_10000);

  /* Saturate: '<S67>/Saturation2' */
  if (rtb_Sum4_e > ((int32_T)u8FLAP_POS_100)) {
    rtb_Sum4_e = (int32_T)u8FLAP_POS_100;
  } else {
    if (rtb_Sum4_e < ((int32_T)u8FLAP_POS_0)) {
      rtb_Sum4_e = (int32_T)u8FLAP_POS_0;
    }
  }

  /* End of Saturate: '<S67>/Saturation2' */
  /* End of Outputs for SubSystem: '<S44>/MixFlap_PI' */

  /* Outputs for Atomic SubSystem: '<S44>/MixFlapReqCal' */
  /* Constant: '<S36>/Constant1' incorporates:
   *  UnitDelay: '<S44>/Unit Delay'
   */
  Chery_E03_Hp_MixFlapReqCal(rtb_bFlag_Cmf_NoHeatingReq_n,
    Chery_E03_Hp_B.HpI_s16Tset_Right_A10, bCONST_0, (uint8_T)rtb_Sum4_e,
    &Chery_E03_Hp_DW.UnitDelay_DSTATE_oo, &rtb_HpI_u8VehSpd);

  /* End of Outputs for SubSystem: '<S44>/MixFlapReqCal' */

  /* Switch: '<S44>/Switch1' incorporates:
   *  RelationalOperator: '<S44>/Relational Operator'
   */
  if (Chery_E03_Hp_B.HpI_s16Tset_Left_A10 ==
      Chery_E03_Hp_B.HpI_s16Tset_Right_A10) {
    rtb_Saturation66 = rtb_HpI_u8PWM_FrontFAN;
  } else {
    rtb_Saturation66 = rtb_HpI_u8BAT_CoolHeatLv;
  }

  /* End of Switch: '<S44>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S41>/Constant'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Logic: '<S44>/Logical Operator'
   *  Logic: '<S44>/Logical Operator1'
   *  RelationalOperator: '<S63>/Compare'
   *  RelationalOperator: '<S64>/Compare'
   *  RelationalOperator: '<S65>/Compare'
   *  SignalConversion: '<S41>/BusConversion_InsertedFor_Bus_AllIn_at_inport_0'
   */
  if ((ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1) &&
      ((rtb_HpI_u8ModeStatus_Real == Flap_u8DIS_MODE_FEET_Sokon) ||
       (rtb_HpI_u8ModeStatus_Real == Flap_u8DIS_MODE_FD_Sokon))) {
    rtb_HpI_u8VehSpd = rtb_Saturation66;
  }

  /* End of Switch: '<S44>/Switch' */
  /* End of Outputs for SubSystem: '<S1>/System_Input_Signal_Bus' */

  /* Outputs for Atomic SubSystem: '<S44>/Mix_ParaILimit' */
  /* Sum: '<S68>/Sum5' incorporates:
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  Chery_E03_Hp_DW.UnitDelay1_DSTATE_p = rtb_Product6_tmp -
    rtb_s32MixEst_Amp10000;

  /* Sum: '<S68>/Sum4' */
  rtb_Sum4_e = (rtb_Sum4_d_tmp - rtb_s32MixEst_Amp10000) - rtb_Product6;

  /* MinMax: '<S68>/Max' */
  if (rtb_Product6_tmp > rtb_Sum4_e) {
    Chery_E03_Hp_DW.UnitDelay2_DSTATE_e = rtb_Product6_tmp;
  } else {
    Chery_E03_Hp_DW.UnitDelay2_DSTATE_e = rtb_Sum4_e;
  }

  /* End of MinMax: '<S68>/Max' */
  /* End of Outputs for SubSystem: '<S44>/Mix_ParaILimit' */
  /* End of Outputs for SubSystem: '<S36>/MixStepperRightControl' */

  /* Outputs for Atomic SubSystem: '<S1>/SystemFailureDetection'
   *
   * Block description for '<S1>/SystemFailureDetection':
   *  System DTC detection
   */
  Chery_E03_Hp_SystemFailureDetection();

  /* End of Outputs for SubSystem: '<S1>/SystemFailureDetection' */

  /* UnitDelay: '<S1>/Unit Delay' */
  Chery_E03_Hp_B.UnitDelay = Chery_E03_Hp_DW.UnitDelay_DSTATE_h1;

  /* Outputs for Atomic SubSystem: '<S1>/Mode_Selection'
   *
   * Block description for '<S1>/Mode_Selection':
   *  ModeSelection
   *  Decide the real work mode according the Mode request and the DTC

   */
  Chery_E03_Hp_Mode_Selection();

  /* End of Outputs for SubSystem: '<S1>/Mode_Selection' */

  /* Outputs for Atomic SubSystem: '<S1>/System_Control'
   *
   * Block description for '<S1>/System_Control':
   *  control
   */
  Chery_E03_Hp_System_Control();

  /* End of Outputs for SubSystem: '<S1>/System_Control' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion' */
  rtb_Saturation = (uint16_T) Chery_E03_Hp_DataTypeConversion
    (Chery_E03_Hp_B.u16Ncomp_Rpm_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion' */

  /* InitialCondition: '<Root>/IC85' */
  if (Chery_E03_Hp_DW.IC85_FirstOutputTime) {
    Chery_E03_Hp_DW.IC85_FirstOutputTime = false;
    *rty_HpO_u16Ncomp_Rpm_Req = 0U;
  } else {
    /* Saturate: '<Root>/Saturation57' */
    rtb_Saturation72 = rtb_Saturation;
    if (((int32_T)rtb_Saturation72) < 8000) {
      *rty_HpO_u16Ncomp_Rpm_Req = rtb_Saturation72;
    } else {
      *rty_HpO_u16Ncomp_Rpm_Req = 8000U;
    }

    /* End of Saturate: '<Root>/Saturation57' */
  }

  /* End of InitialCondition: '<Root>/IC85' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion1' */
  rtb_Compare_ool = ( Chery_E03_Hp_DataTypeConv_b_(Chery_E03_Hp_B.bSOV_Eva_Req)
                     != false);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion1' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_28' */
  /* SignalConversion: '<S38>/Signal Copy1' */
  rtb_Compare_pp4 = ( Chery_E03_Hp_DataTypeConversion13(rtb_Compare_ool) !=
                     false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_28' */

  /* InitialCondition: '<Root>/IC86' */
  if (Chery_E03_Hp_DW.IC86_FirstOutputTime) {
    Chery_E03_Hp_DW.IC86_FirstOutputTime = false;
    *rty_HpO_bSOV_Eva_Req = true;
  } else {
    *rty_HpO_bSOV_Eva_Req = rtb_Compare_pp4;
  }

  /* End of InitialCondition: '<Root>/IC86' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion15' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (Chery_E03_Hp_B.u8TWValve_HC_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion15' */

  /* Saturate: '<Root>/Saturation67' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation67' */

  /* InitialCondition: '<Root>/IC100' */
  if (Chery_E03_Hp_DW.IC100_FirstOutputTime) {
    Chery_E03_Hp_DW.IC100_FirstOutputTime = false;
    *rty_HpO_u8TWValve_HC_Req = 0U;
  } else {
    *rty_HpO_u8TWValve_HC_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC100' */

  /* Sum: '<S235>/Sum' incorporates:
   *  Constant: '<S235>/Constant'
   */
  rtb_HpI_s16Tasd_Left_Req_A10 = (int16_T)(100 - ((int32_T)
    Chery_E03_Hp_B.u8TWValve_LTR_Req));

  /* Outputs for Atomic SubSystem: '<S235>/DataTypeConv_u8_' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8__a
    (rtb_HpI_s16Tasd_Left_Req_A10);

  /* End of Outputs for SubSystem: '<S235>/DataTypeConv_u8_' */

  /* Switch: '<S235>/Switch' incorporates:
   *  Constant: '<S241>/Constant'
   *  Constant: '<S41>/Constant'
   *  RelationalOperator: '<S241>/Compare'
   */
  if (ACPre_u8Project_CheryE03 == ACPre_u8Project_SokonX1) {
    rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  } else {
    rtb_HpI_u8ModeStatus_Real = Chery_E03_Hp_B.u8TWValve_LTR_Req;
  }

  /* End of Switch: '<S235>/Switch' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion16' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (rtb_HpI_u8ModeStatus_Real);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion16' */

  /* Saturate: '<Root>/Saturation68' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation68' */

  /* InitialCondition: '<Root>/IC101' */
  if (Chery_E03_Hp_DW.IC101_FirstOutputTime) {
    Chery_E03_Hp_DW.IC101_FirstOutputTime = false;
    *rty_HpO_u8TWValve_LTR_Req = 0U;
  } else {
    *rty_HpO_u8TWValve_LTR_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC101' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion17' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (Chery_E03_Hp_B.u8TWValve_BAT_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion17' */

  /* Saturate: '<Root>/Saturation69' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation69' */

  /* InitialCondition: '<Root>/IC102' */
  if (Chery_E03_Hp_DW.IC102_FirstOutputTime) {
    Chery_E03_Hp_DW.IC102_FirstOutputTime = false;
    *rty_HpO_u8TWValve_BAT_Req = 0U;
  } else {
    *rty_HpO_u8TWValve_BAT_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC102' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion18' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (Chery_E03_Hp_B.u8HVCH_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion18' */

  /* Saturate: '<Root>/Saturation70' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation70' */

  /* InitialCondition: '<Root>/IC103' */
  if (Chery_E03_Hp_DW.IC103_FirstOutputTime) {
    Chery_E03_Hp_DW.IC103_FirstOutputTime = false;
    *rty_HpO_u8HVCH_Req = 0U;
  } else {
    *rty_HpO_u8HVCH_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC103' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion19' */
  rtb_Saturation = (uint16_T) Chery_E03_Hp_DataTypeConversion
    (Chery_E03_Hp_B.u16Pump_HVCH_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion19' */

  /* InitialCondition: '<Root>/IC104' */
  if (Chery_E03_Hp_DW.IC104_FirstOutputTime) {
    Chery_E03_Hp_DW.IC104_FirstOutputTime = false;
    *rty_HpO_u16Pump_HVCH_Req = 0U;
  } else {
    /* Saturate: '<Root>/Saturation71' */
    rtb_Saturation72 = rtb_Saturation;
    if (((int32_T)rtb_Saturation72) < 100) {
      *rty_HpO_u16Pump_HVCH_Req = rtb_Saturation72;
    } else {
      *rty_HpO_u16Pump_HVCH_Req = 100U;
    }

    /* End of Saturate: '<Root>/Saturation71' */
  }

  /* End of InitialCondition: '<Root>/IC104' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion2' */
  rtb_Compare_ool = ( Chery_E03_Hp_DataTypeConv_b_
                     (Chery_E03_Hp_B.bSOV_OutEva_Req) != false);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion2' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_29' */
  /* SignalConversion: '<S38>/Signal Copy2' */
  rtb_Compare_mcw = ( Chery_E03_Hp_DataTypeConversion13(rtb_Compare_ool) !=
                     false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_29' */

  /* InitialCondition: '<Root>/IC87' */
  if (Chery_E03_Hp_DW.IC87_FirstOutputTime) {
    Chery_E03_Hp_DW.IC87_FirstOutputTime = false;
    *rty_HpO_bSOV_OutEva_Req = true;
  } else {
    *rty_HpO_bSOV_OutEva_Req = rtb_Compare_mcw;
  }

  /* End of InitialCondition: '<Root>/IC87' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion21' */
  rtb_Saturation = (uint16_T) Chery_E03_Hp_DataTypeConversion
    (Chery_E03_Hp_B.u16Pump_Bat_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion21' */

  /* InitialCondition: '<Root>/IC106' */
  if (Chery_E03_Hp_DW.IC106_FirstOutputTime) {
    Chery_E03_Hp_DW.IC106_FirstOutputTime = false;
    *rty_HpO_u16Pump_Bat_Req = 0U;
  } else {
    /* Saturate: '<Root>/Saturation73' */
    rtb_Saturation72 = rtb_Saturation;
    if (((int32_T)rtb_Saturation72) < 100) {
      *rty_HpO_u16Pump_Bat_Req = rtb_Saturation72;
    } else {
      *rty_HpO_u16Pump_Bat_Req = 100U;
    }

    /* End of Saturate: '<Root>/Saturation73' */
  }

  /* End of InitialCondition: '<Root>/IC106' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion3' */
  rtb_Compare_ool = ( Chery_E03_Hp_DataTypeConv_b_
                     (Chery_E03_Hp_B.bSOV_TXVOutEva_Req) != false);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion3' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_30' */
  /* SignalConversion: '<S38>/Signal Copy3' */
  rtb_Compare_e4p = ( Chery_E03_Hp_DataTypeConversion13(rtb_Compare_ool) !=
                     false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_30' */

  /* InitialCondition: '<Root>/IC88' */
  if (Chery_E03_Hp_DW.IC88_FirstOutputTime) {
    Chery_E03_Hp_DW.IC88_FirstOutputTime = false;
    *rty_HpO_bSOV_TXVOutEva_Req = true;
  } else {
    *rty_HpO_bSOV_TXVOutEva_Req = rtb_Compare_e4p;
  }

  /* End of InitialCondition: '<Root>/IC88' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion4' */
  /* Product: '<S234>/Multiply' incorporates:
   *  Product: '<S234>/Divide'
   */
  rtb_Saturation = (uint16_T) Chery_E03_Hp_DataTypeConversion((uint16_T)
    ((int32_T)(((int32_T)((uint32_T)(((uint32_T)
    Chery_E03_Hp_B.u16EXV_Eva_Pos_Req) >> 1))) * 2)));

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion4' */

  /* InitialCondition: '<Root>/IC89' */
  if (Chery_E03_Hp_DW.IC89_FirstOutputTime) {
    Chery_E03_Hp_DW.IC89_FirstOutputTime = false;
    *rty_HpO_u16EXV_Eva_Pos_Req = 50U;
  } else {
    /* Saturate: '<Root>/Saturation58' */
    rtb_Saturation72 = rtb_Saturation;
    if (((int32_T)rtb_Saturation72) < 576) {
      *rty_HpO_u16EXV_Eva_Pos_Req = rtb_Saturation72;
    } else {
      *rty_HpO_u16EXV_Eva_Pos_Req = 576U;
    }

    /* End of Saturate: '<Root>/Saturation58' */
  }

  /* End of InitialCondition: '<Root>/IC89' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion5' */
  rtb_Saturation = (uint16_T) Chery_E03_Hp_DataTypeConversion
    (Chery_E03_Hp_B.u16EXV_Chil_Pos_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion5' */

  /* InitialCondition: '<Root>/IC90' */
  if (Chery_E03_Hp_DW.IC90_FirstOutputTime) {
    Chery_E03_Hp_DW.IC90_FirstOutputTime = false;
    *rty_HpO_u16EXV_Chil_Pos_Req = 50U;
  } else {
    /* Saturate: '<Root>/Saturation59' */
    rtb_Saturation72 = rtb_Saturation;
    if (((int32_T)rtb_Saturation72) < 576) {
      *rty_HpO_u16EXV_Chil_Pos_Req = rtb_Saturation72;
    } else {
      *rty_HpO_u16EXV_Chil_Pos_Req = 576U;
    }

    /* End of Saturate: '<Root>/Saturation59' */
  }

  /* End of InitialCondition: '<Root>/IC90' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion7' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (Chery_E03_Hp_B.u8AGS_Position_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion7' */

  /* Saturate: '<Root>/Saturation61' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation61' */

  /* InitialCondition: '<Root>/IC92' */
  if (Chery_E03_Hp_DW.IC92_FirstOutputTime) {
    Chery_E03_Hp_DW.IC92_FirstOutputTime = false;
    *rty_HpI_u8AGS_Position_Req = 100U;
  } else {
    *rty_HpI_u8AGS_Position_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC92' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion8' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (Chery_E03_Hp_B.u8FRFAN_PWM_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion8' */

  /* Saturate: '<Root>/Saturation62' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation62' */

  /* InitialCondition: '<Root>/IC93' */
  if (Chery_E03_Hp_DW.IC93_FirstOutputTime) {
    Chery_E03_Hp_DW.IC93_FirstOutputTime = false;
    *rty_HpO_u8FRFAN_PWM_Req = 20U;
  } else {
    *rty_HpO_u8FRFAN_PWM_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC93' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion20' */
  rtb_Saturation = (uint16_T) Chery_E03_Hp_DataTypeConversion20
    (Chery_E03_Hp_B.u16Pump_Motor_Req);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion20' */

  /* InitialCondition: '<Root>/IC105' */
  if (Chery_E03_Hp_DW.IC105_FirstOutputTime) {
    Chery_E03_Hp_DW.IC105_FirstOutputTime = false;
    *rty_HpO_u16Pump_Motor_Req = 0U;
  } else {
    /* Saturate: '<Root>/Saturation72' */
    rtb_Saturation72 = rtb_Saturation;
    if (((int32_T)rtb_Saturation72) < 100) {
      *rty_HpO_u16Pump_Motor_Req = rtb_Saturation72;
    } else {
      *rty_HpO_u16Pump_Motor_Req = 100U;
    }

    /* End of Saturate: '<Root>/Saturation72' */
  }

  /* End of InitialCondition: '<Root>/IC105' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion6' */
  /* UnitDelay: '<S1>/Unit Delay' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_h1);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion6' */

  /* Saturate: '<Root>/Saturation60' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 30) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 30U;
  }

  /* End of Saturate: '<Root>/Saturation60' */

  /* InitialCondition: '<Root>/IC91' */
  if (Chery_E03_Hp_DW.IC91_FirstOutputTime) {
    Chery_E03_Hp_DW.IC91_FirstOutputTime = false;
    *rty_HpO_u8HpWorkMode_Req = 0U;
  } else {
    *rty_HpO_u8HpWorkMode_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC91' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion11' */
  /* Switch: '<S38>/Switch1' incorporates:
   *  UnitDelay: '<S322>/Unit Delay'
   */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_((uint8_T)
    (Chery_E03_Hp_DW.UnitDelay_DSTATE_gh ? 1U : 0U));

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion11' */

  /* Saturate: '<Root>/Saturation65' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 1) {
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = 1U;
  }

  /* End of Saturate: '<Root>/Saturation65' */

  /* InitialCondition: '<Root>/IC96' */
  if (Chery_E03_Hp_DW.IC96_FirstOutputTime) {
    Chery_E03_Hp_DW.IC96_FirstOutputTime = false;
    *rty_HpO_u8DTC_Ref_System = 0U;
  } else {
    *rty_HpO_u8DTC_Ref_System = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC96' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion13' */
  rtb_Compare_o4b = ( Chery_E03_Hp_DataTypeConversion13
                     (Chery_E03_Hp_B.Conversion_p1) != false);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion13' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_31' */
  /* SignalConversion: '<S38>/Signal Copy13' */
  rtb_Compare_og = ( Chery_E03_Hp_DataTypeConversion13(rtb_Compare_o4b) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_31' */

  /* InitialCondition: '<Root>/IC98' */
  if (Chery_E03_Hp_DW.IC98_FirstOutputTime) {
    Chery_E03_Hp_DW.IC98_FirstOutputTime = false;
    *rty_HpO_bDTC_EvaFreeze = false;
  } else {
    *rty_HpO_bDTC_EvaFreeze = rtb_Compare_og;
  }

  /* End of InitialCondition: '<Root>/IC98' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion10' */
  /* SignalConversion: '<S36>/Signal Copy1' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_(rtb_HpI_u8VehSpd);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion10' */

  /* Saturate: '<Root>/Saturation64' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation64' */

  /* InitialCondition: '<Root>/IC95' */
  if (Chery_E03_Hp_DW.IC95_FirstOutputTime) {
    Chery_E03_Hp_DW.IC95_FirstOutputTime = false;
    *rty_HpO_u8Mix_Right_Req = 0U;
  } else {
    *rty_HpO_u8Mix_Right_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC95' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion9' */
  /* SignalConversion: '<S36>/Signal Copy' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_
    (rtb_HpI_u8PWM_FrontFAN);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion9' */

  /* Saturate: '<Root>/Saturation63' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 100) {
    rtb_Saturation66 = rtb_HpI_u8ModeStatus_Real;
  } else {
    rtb_Saturation66 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation63' */

  /* InitialCondition: '<Root>/IC94' */
  if (Chery_E03_Hp_DW.IC94_FirstOutputTime) {
    Chery_E03_Hp_DW.IC94_FirstOutputTime = false;
    *rty_HpO_u8Mix_Left_Req = 0U;
  } else {
    *rty_HpO_u8Mix_Left_Req = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC94' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion12' */
  /* Switch: '<S38>/Switch' */
  rtb_Saturation66 = (uint8_T) Chery_E03_Hp_DataTypeConv_u8_((uint8_T)(rtb_IC8 ?
    1U : 0U));

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion12' */

  /* Saturate: '<Root>/Saturation66' */
  rtb_HpI_u8ModeStatus_Real = rtb_Saturation66;
  if (((int32_T)rtb_HpI_u8ModeStatus_Real) < 1) {
    rtb_Saturation66 = 0U;
  } else {
    rtb_Saturation66 = 1U;
  }

  /* End of Saturate: '<Root>/Saturation66' */

  /* InitialCondition: '<Root>/IC97' */
  if (Chery_E03_Hp_DW.IC97_FirstOutputTime) {
    Chery_E03_Hp_DW.IC97_FirstOutputTime = false;
    *rty_HpO_u8DTC_Ref_Component = 0U;
  } else {
    *rty_HpO_u8DTC_Ref_Component = rtb_Saturation66;
  }

  /* End of InitialCondition: '<Root>/IC97' */

  /* Outputs for Atomic SubSystem: '<S38>/Data Type Conversion14' */
  /* Constant: '<S38>/Constant' */
  rtb_Compare_in4 = ( Chery_E03_Hp_DataTypeConversion13(bCONST_0) != false);

  /* End of Outputs for SubSystem: '<S38>/Data Type Conversion14' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_32' */
  /* SignalConversion: '<S38>/Signal Copy14' */
  rtb_Compare_oil = ( Chery_E03_Hp_DataTypeConversion13(rtb_Compare_in4) !=
                     false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_32' */

  /* InitialCondition: '<Root>/IC99' */
  if (Chery_E03_Hp_DW.IC99_FirstOutputTime) {
    Chery_E03_Hp_DW.IC99_FirstOutputTime = false;
    *rty_HpO_bDTC_OutEvaFreeze = false;
  } else {
    *rty_HpO_bDTC_OutEvaFreeze = rtb_Compare_oil;
  }

  /* End of InitialCondition: '<Root>/IC99' */

  /* InitialCondition: '<Root>/IC66' */
  if (Chery_E03_Hp_DW.IC66_FirstOutputTime) {
    Chery_E03_Hp_DW.IC66_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_T_Ref_CHILOut;
  }

  /* End of InitialCondition: '<Root>/IC66' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_10' */
  rtb_Compare_pv = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_10' */

  /* InitialCondition: '<Root>/IC21' */
  if (Chery_E03_Hp_DW.IC21_FirstOutputTime) {
    Chery_E03_Hp_DW.IC21_FirstOutputTime = false;
    rtb_IC8 = true;
  } else {
    rtb_IC8 = *rtu_HpI_bSOV_Eva;
  }

  /* End of InitialCondition: '<Root>/IC21' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_2' */
  rtb_Compare_pmg = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_2' */

  /* InitialCondition: '<Root>/IC22' */
  if (Chery_E03_Hp_DW.IC22_FirstOutputTime) {
    Chery_E03_Hp_DW.IC22_FirstOutputTime = false;
    rtb_IC8 = true;
  } else {
    rtb_IC8 = *rtu_HpI_bSOV_OutEva;
  }

  /* End of InitialCondition: '<Root>/IC22' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_3' */
  rtb_Compare_pvs = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_3' */

  /* InitialCondition: '<Root>/IC23' */
  if (Chery_E03_Hp_DW.IC23_FirstOutputTime) {
    Chery_E03_Hp_DW.IC23_FirstOutputTime = false;
    rtb_IC8 = true;
  } else {
    rtb_IC8 = *rtu_HpI_bSOV_TXVOutEva;
  }

  /* End of InitialCondition: '<Root>/IC23' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_4' */
  rtb_Compare_ot = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_4' */

  /* InitialCondition: '<Root>/IC38' */
  if (Chery_E03_Hp_DW.IC38_FirstOutputTime) {
    Chery_E03_Hp_DW.IC38_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bEco_Model_Set;
  }

  /* End of InitialCondition: '<Root>/IC38' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_5' */
  rtb_Compare_m1 = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_5' */

  /* InitialCondition: '<Root>/IC40' */
  if (Chery_E03_Hp_DW.IC40_FirstOutputTime) {
    Chery_E03_Hp_DW.IC40_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bFlag_HeatShort_Blw_Req;
  }

  /* End of InitialCondition: '<Root>/IC40' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_6' */
  rtb_Compare_gln = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_6' */

  /* InitialCondition: '<Root>/IC64' */
  if (Chery_E03_Hp_DW.IC64_FirstOutputTime) {
    Chery_E03_Hp_DW.IC64_FirstOutputTime = false;
    rtb_IC8 = false;
  } else {
    rtb_IC8 = *rtu_HpI_bDTC_P_Ref_EvaOut;
  }

  /* End of InitialCondition: '<Root>/IC64' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_8' */
  rtb_Compare_nmz = ( Chery_E03_Hp_DataTypeConversion13(rtb_IC8) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_8' */

  /* Update for Atomic SubSystem: '<S1>/System_Input_Signal_Bus' */
  /* Update for UnitDelay: '<S1145>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_cj = Chery_E03_Hp_B.bFlag_Cmf_NoHeatingReq;

  /* Update for UnitDelay: '<S1047>/Unit Delay' */
  Chery_E03_Hp_DW.UnitDelay_DSTATE_pd = rtb_HpI_u8IgnSts;

  /* End of Update for SubSystem: '<S1>/System_Input_Signal_Bus' */
}

/* Model initialize function */
void Chery_E03_Hp_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &Chery_E03_Hp_B), 0,
                sizeof(B_Chery_E03_Hp_c_T));

  /* states (dwork) */
  (void) memset((void *)&Chery_E03_Hp_DW, 0,
                sizeof(DW_Chery_E03_Hp_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

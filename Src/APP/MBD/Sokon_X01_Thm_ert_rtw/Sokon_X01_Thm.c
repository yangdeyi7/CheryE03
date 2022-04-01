/*
 * File: Sokon_X01_Thm.c
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

#include "Sokon_X01_Thm.h"
#include "Sokon_X01_Thm_private.h"
#include "MultiWordAdd.h"
#include "MultiWordSub.h"
#include "look1_is16lu32n16Ds32_binlcs.h"
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

/* Block signals (default storage) */
B_Sokon_X01_Thm_T Sokon_X01_Thm_B;

/* Block states (default storage) */
DW_Sokon_X01_Thm_T Sokon_X01_Thm_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Sokon_X01_Thm_T Sokon_X01_Thm_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Sokon_X01_Thm_T Sokon_X01_Thm_Y;

/* Exported data definition */

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile ACPre_s16LVL_HeatCool_Tab ACPre_s16LVL_HeatCool = {
  { 170, 180, 200, 220, 240, 260, 280, 300, 320, 330 },

  { -300, -200, -100, -50, 0, 50, 100, 150, 200, 300, 400 },

  { 0, 3, 4, 5, 5, 5, 5, 6, 6, 6, 0, 3, 3, 4, 4, 4, 5, 5, 6, 6, 0, 2, 3, 3, 4, 4,
    4, 5, 5, 6, 0, 2, 3, 3, 3, 3, 3, 4, 4, 5, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, -1,
    0, 1, 2, 2, 2, 3, 3, 3, 3, -1, 0, 0, 1, 1, 2, 2, 2, 2, 3, -1, -1, 0, 0, 0, 1,
    1, 1, 1, 2, -2, -1, -1, 0, 0, 0, 1, 1, 1, 2, -2, -2, -2, -1, -1, -1, 0, 0, 1,
    1, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0 }
} ;

volatile ACPre_s16TWat_CmfReq_Tab ACPre_s16TWat_CmfReq = {
  { -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { -200, -100, -50, 0, 50, 100, 200, 300, 400, 500, 600, 650 },

  { -400, -400, -400, -400, -400, -400, -400, -400, -400, -400, -400, -400, -400,
    -400, -400, -400, -400, -400, -400, -400, -400, -400, -400, -400, -400, -400,
    -400, 80, 50, 30, -400, -400, -400, -400, -400, -400, 135, 120, 100, 80,
    -400, -400, -400, -400, -400, 150, 150, 150, 150, 150, -400, -400, -400,
    -400, 300, 300, 300, 300, 250, 250, -400, -400, -400, 440, 390, 360, 345,
    335, 325, 320, -400, -400, 568, 500, 488, 475, 445, 440, 410, 350, -400, 685,
    620, 605, 595, 570, 520, 515, 510, 505, 785, 755, 725, 715, 650, 635, 630,
    625, 620, 800, 785, 770, 765, 700, 690, 685, 670, 660 }
} ;

volatile ACPre_u8AGSFactor_Tab ACPre_u8AGSFactor = {
  { 0U, 20U, 40U, 60U, 100U },

  { 0U, 10U, 40U, 60U, 80U, 100U, 120U },

  { 0U, 20U, 40U, 60U, 100U, 2U, 23U, 44U, 64U, 100U, 5U, 28U, 50U, 70U, 100U,
    10U, 35U, 56U, 75U, 100U, 20U, 42U, 62U, 80U, 100U, 30U, 50U, 68U, 85U, 100U,
    40U, 60U, 75U, 90U, 100U }
} ;

volatile AC_s16ExvCtrl_Ki_Lv3_Tab AC_s16ExvCtrl_Ki_Lv3 = {
  { -100, -60, -30, -20, 0, 20, 40, 70, 100, 150 },

  { 3, 2, 2, 1, 1, 1, 2, 2, 3, 4 }
} ;

volatile AC_s16ExvCtrl_Kp_Lv3_Tab AC_s16ExvCtrl_Kp_Lv3 = {
  { -100, -60, -30, -20, 0, 20, 40, 70, 100, 150 },

  { 1000, 800, 500, 300, 200, 300, 600, 800, 1000, 1200 }
} ;

volatile AC_s16ExvStepsClose_Lv1_Tab AC_s16ExvStepsClose_Lv1 = {
  { -20, 0, 20, 30, 40, 60, 80, 100 },

  { 0, 0, 0, 0, 0, -8, -10, -12 }
} ;

volatile AC_s16ExvStepsClose_Lv2_Tab AC_s16ExvStepsClose_Lv2 = {
  { -20, 0, 20, 40, 50, 70, 100, 150 },

  { 0, 0, 0, 0, 0, 0, -10, -12 }
} ;

volatile AC_s16ExvStepsOpen_Lv1_Tab AC_s16ExvStepsOpen_Lv1 = {
  { -30, 0, 20, 50, 100, 150, 200, 250 },

  { -20, 0, 2, 3, 6, 8, 13, 20 }
} ;

volatile AC_s16ExvStepsOpen_Lv2_Tab AC_s16ExvStepsOpen_Lv2 = {
  { -30, 0, 20, 50, 100, 150, 200, 250 },

  { -20, 0, 2, 3, 7, 11, 15, 25 }
} ;

volatile AC_s16TBatIn_Delta_Lv3_u1_Tab AC_s16TBatIn_Delta_Lv3_u1 = {
  { -100, -60, -30, -20, 0, 20, 40, 70, 100, 150 },

  { -100, -60, -30, -20, 0, 20, 40, 70, 100, 150 }
} ;

volatile AC_s16Teva_CtrlTi_Tab AC_s16Teva_CtrlTi = {
  { -50, -20, -10, 0, 25, 50, 100, 150 },

  { 30, 10, 8, 5, 25, 30, 40, 60 }
} ;

volatile AC_u16Ncomp_PrcoRisk_ValeoEDC_Tab AC_u16Ncomp_PrcoRisk_ValeoEDC = {
  { 200U, 220U, 230U, 245U, 250U, 260U, 270U, 280U },

  { 0U, 2U, 5U, 6U, 10U, 20U, 35U, 50U }
} ;

volatile AC_u16PWM_FAN_AC_Tab AC_u16PWM_FAN_AC = {
  { 0U, 20U, 40U, 60U, 80U, 100U, 120U },

  { 40U, 70U, 120U, 150U, 170U, 210U, 240U },

  { 20U, 0U, 0U, 0U, 0U, 0U, 0U, 50U, 30U, 0U, 0U, 0U, 0U, 0U, 70U, 50U, 30U,
    20U, 0U, 0U, 0U, 80U, 60U, 40U, 30U, 10U, 0U, 0U, 80U, 70U, 60U, 40U, 30U,
    10U, 0U, 80U, 80U, 60U, 50U, 40U, 30U, 0U, 80U, 80U, 80U, 40U, 40U, 30U, 0U
  }
} ;

volatile AC_u16PWM_FAN_HP_Tab AC_u16PWM_FAN_HP = {
  { 0U, 20U, 40U, 60U, 80U, 100U, 120U },

  { 0, 10, 20, 50, 80, 100, 150 },

  { 60U, 60U, 30U, 0U, 0U, 0U, 0U, 60U, 60U, 30U, 0U, 0U, 0U, 0U, 70U, 60U, 30U,
    0U, 0U, 0U, 0U, 70U, 60U, 30U, 0U, 0U, 0U, 0U, 70U, 60U, 30U, 0U, 0U, 0U, 0U,
    70U, 60U, 30U, 0U, 0U, 0U, 0U, 70U, 60U, 30U, 0U, 0U, 0U, 0U }
} ;

volatile AC_u16PWM_FAN_StopMode_Tab AC_u16PWM_FAN_StopMode = {
  { 0U, 20U, 40U, 60U, 80U, 100U, 120U },

  { 0, 10, 20, 50, 80, 100, 150, 200 },

  { 10U, 0U, 0U, 0U, 0U, 0U, 0U, 20U, 0U, 0U, 0U, 0U, 0U, 0U, 40U, 20U, 0U, 0U,
    0U, 0U, 0U, 40U, 30U, 0U, 0U, 0U, 0U, 0U, 50U, 40U, 0U, 0U, 0U, 0U, 0U, 60U,
    50U, 30U, 0U, 0U, 0U, 0U, 80U, 60U, 50U, 0U, 0U, 0U, 0U, 100U, 60U, 50U, 0U,
    0U, 0U, 0U }
} ;

volatile AC_u16Vair_Front_Tab AC_u16Vair_Front = {
  { 0U, 1U, 20U, 40U, 60U, 80U, 100U },

  { 0U, 10U, 40U, 60U, 80U, 100U, 120U },

  { 0U, 5U, 8U, 12U, 15U, 16U, 18U, 5U, 6U, 10U, 15U, 18U, 20U, 22U, 10U, 10U,
    12U, 17U, 20U, 25U, 30U, 12U, 15U, 20U, 30U, 30U, 30U, 30U, 20U, 35U, 35U,
    35U, 35U, 35U, 35U, 38U, 38U, 38U, 38U, 38U, 38U, 38U, 40U, 40U, 40U, 40U,
    40U, 40U, 40U }
} ;

volatile CMF_s8Blw_Dyn_Tab CMF_s8Blw_Dyn = {
  { -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { -300, -200, -100, -50, -20, 0, 20, 50, 100, 200, 300 },

  { 0, 0, 0, 0, 0, 6, 6, 6, 35, 45, 0, 0, 0, 0, 0, 5, 5, 5, 28, 36, 9, 8, 2, 1,
    0, 0, 0, 2, 11, 14, 2, 2, 1, 1, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 2, 2, 1, 1,
    0, 0, 0, 0, -1, -3, 9, 8, 2, 1, 0, 0, 0, 0, -4, -8, 23, 20, 8, 5, 0, 3, 3, 3,
    -9, -12, 45, 40, 15, 10, 0, 6, 6, 6, -12, -16 }
} ;

volatile CMF_s8Blw_VSP_Comp_Tab CMF_s8Blw_VSP_Comp = {
  { 0U, 10U, 20U, 30U, 40U, 50U, 60U, 80U, 100U, 120U },

  { 0U, 20U, 40U, 60U, 80U, 100U },

  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -3, -4, -5, -5, 0, 0, 0,
    -1, -1, -2, -3, -4, -5, -5, 0, 0, 0, -1, -1, -2, -3, -4, -5, -5, 0, 0, 0, -2,
    -4, -6, -10, -12, -14, -18, 0, 0, 0, -2, -4, -8, -10, -12, -15, -20 }
} ;

volatile CMF_u8Blw_LImitation_Tab CMF_u8Blw_LImitation = {
  { 0, 100, 200, 300, 400, 500, 600, 700, 800, 900 },

  { 0, 100, 150, 200, 250, 300, 400, 500, 600, 700, 800 },

  { 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U,
    130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U,
    130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U,
    130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 35U, 35U,
    100U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 35U, 35U, 80U, 100U, 130U,
    130U, 130U, 130U, 130U, 130U, 35U, 35U, 55U, 90U, 100U, 130U, 130U, 130U,
    130U, 130U, 35U, 35U, 45U, 70U, 80U, 100U, 130U, 130U, 130U, 130U, 35U, 35U,
    38U, 55U, 60U, 85U, 110U, 130U, 130U, 130U, 35U, 35U, 36U, 50U, 60U, 85U,
    100U, 110U, 130U, 130U }
} ;

volatile Flap_u16Ki_HVCH_A10000_Tab Flap_u16Ki_HVCH_A10000 = {
  { -100, -50, -20, 0, 50, 100, 200, 300 },

  { 0U, 100U, 200U, 300U, 400U, 500U, 1200U },

  { 30U, 30U, 20U, 8U, 8U, 10U, 10U, 10U, 30U, 30U, 20U, 8U, 8U, 10U, 10U, 10U,
    30U, 30U, 20U, 8U, 8U, 10U, 10U, 10U, 30U, 30U, 20U, 8U, 8U, 10U, 10U, 10U,
    30U, 30U, 20U, 8U, 8U, 10U, 10U, 10U, 30U, 30U, 20U, 8U, 8U, 10U, 10U, 10U,
    30U, 30U, 20U, 8U, 8U, 10U, 10U, 10U }
} ;

volatile Flap_u16Kp_HVCH_A10000_Tab Flap_u16Kp_HVCH_A10000 = {
  { -100, -50, -20, 0, 50, 100, 200, 300 },

  { 0U, 100U, 200U, 300U, 400U, 500U, 1200U },

  { 3000U, 3000U, 2000U, 1000U, 1000U, 1000U, 1000U, 1000U, 3000U, 3000U, 2000U,
    1000U, 1000U, 1000U, 1000U, 1000U, 3000U, 3000U, 2000U, 1000U, 1000U, 1000U,
    1000U, 1000U, 3000U, 3000U, 2000U, 1000U, 1000U, 1000U, 1000U, 1000U, 3000U,
    3000U, 2000U, 1000U, 1000U, 1000U, 1000U, 1000U, 3000U, 3000U, 2000U, 1000U,
    1000U, 1000U, 1000U, 1000U, 3000U, 3000U, 2000U, 1000U, 1000U, 1000U, 1000U,
    1000U }
} ;

volatile HP_s16Ki_EXV_Chil_HPChil_Tab HP_s16Ki_EXV_Chil_HPChil = {
  { -100, -50, -20, 0, 10, 20, 50, 100 },

  { -100, 0, 100, 150, 200, 250, 300, 400, 500 },

  { 6, 3, 2, 2, 2, 2, 3, 5, 6, 3, 2, 2, 2, 2, 3, 5, 6, 3, 2, 2, 2, 2, 3, 5, 6, 3,
    2, 2, 2, 2, 3, 5, 6, 3, 2, 2, 2, 2, 3, 5, 6, 3, 2, 2, 2, 2, 3, 5, 6, 3, 2, 2,
    2, 2, 3, 5, 6, 3, 2, 2, 2, 2, 3, 5, 6, 3, 2, 2, 2, 2, 3, 5 }
} ;

volatile HP_s16Kp_EXV_Chil_HPChil_Tab HP_s16Kp_EXV_Chil_HPChil = {
  { -100, -50, -20, 0, 10, 20, 50, 100 },

  { -100, 0, 100, 150, 200, 250, 300, 400, 500 },

  { 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2000 }
} ;

volatile HP_s16Kp_EXV_EvaCDS_HP_Tab HP_s16Kp_EXV_EvaCDS_HP = {
  { -100, -50, -20, 0, 10, 20, 50, 100 },

  { -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800, 800,
    800, 800, 800, 800, 800, 800, 800, 800, 800, 900, 900, 900, 900, 900, 900,
    900, 900, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1200, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
    1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200, 1200,
    1200, 1200, 1200 }
} ;

volatile HP_u16Pump_HC_Twat_Tab HP_u16Pump_HC_Twat = {
  { 0, 100, 300, 500, 600 },

  { 45U, 50U, 50U, 50U, 50U }
} ;

volatile HP_u16Pump_HVCH_AC_Tab HP_u16Pump_HVCH_AC = {
  { 0, 50, 100, 200, 250, 300, 350, 400 },

  { 0, 30, 50, 80, 100, 150 },

  { 65U, 65U, 65U, 65U, 65U, 65U, 65U, 65U, 70U, 70U, 70U, 70U, 70U, 70U, 70U,
    70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 80U, 80U, 80U, 80U, 80U, 80U,
    80U, 80U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U,
    100U, 100U, 100U, 100U, 100U }
} ;

volatile HP_u16SH_Set_HPCHIL_Tab HP_u16SH_Set_HPCHIL = {
  { 0, 100, 200, 300, 400, 500, 600 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 50U, 50U, 50U, 60U, 70U, 80U, 90U, 50U, 50U, 50U, 60U, 70U, 80U, 90U, 50U,
    50U, 50U, 60U, 70U, 80U, 90U, 50U, 50U, 50U, 60U, 70U, 80U, 90U, 50U, 50U,
    50U, 60U, 70U, 80U, 90U, 50U, 50U, 50U, 60U, 70U, 80U, 90U, 50U, 50U, 50U,
    60U, 70U, 80U, 90U }
} ;

volatile HP_u16_EXV_EvaCDS_HP_Max_Tab HP_u16_EXV_EvaCDS_HP_Max = {
  { 0U, 50U, 80U, 120U, 150U, 200U, 250U, 300U, 400U, 500U },

  { 0U, 80U, 100U, 150U, 200U, 250U, 300U, 400U, 500U, 600U }
} ;

volatile HP_u16_EXV_EvaCDS_HP_Min_Tab HP_u16_EXV_EvaCDS_HP_Min = {
  { 0U, 50U, 80U, 120U, 150U, 200U, 250U, 300U, 400U, 500U },

  { 0U, 50U, 60U, 70U, 85U, 130U, 150U, 150U, 150U, 150U }
} ;

volatile HP_u16_Pratio_Delay_Tab HP_u16_Pratio_Delay = {
  { 17U, 18U, 19U, 20U },

  { 0U, 30U, 20U, 10U }
} ;

volatile HP_u8TWV_HVCH_AC_Tab HP_u8TWV_HVCH_AC = {
  { 0, 50, 100, 200, 250, 300, 350, 400 },

  { -400, -200, 0, 100, 200, 300, 400, 500, 600, 700 },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 20U, 20U, 15U, 10U, 0U, 0U, 0U, 0U, 30U, 25U, 20U, 10U,
    5U, 5U, 5U, 5U, 40U, 40U, 35U, 30U, 25U, 10U, 10U, 10U, 40U, 40U, 35U, 30U,
    25U, 15U, 10U, 10U, 40U, 40U, 35U, 30U, 25U, 25U, 20U, 20U, 40U, 40U, 35U,
    30U, 25U, 25U, 20U, 20U, 40U, 40U, 35U, 30U, 25U, 25U, 20U, 20U }
} ;

volatile Hp_u16Ki_Mix_Normal_Tab Hp_u16Ki_Mix_Normal = {
  { 0, 300, 600, 900, 1200 },

  { 35U, 27U, 20U, 5U, 3U }
} ;

volatile Hp_u16Kp_Mix_Normal_Tab Hp_u16Kp_Mix_Normal = {
  { 0, 300, 600, 900, 1200 },

  { 2160U, 1800U, 1440U, 800U, 400U }
} ;

volatile Thm_s16Blower_SolarCmp_Tab Thm_s16Blower_SolarCmp = {
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 800U, 1000U, 1200U },

  { 0, 100, 120, 150, 200, 250, 280, 300, 350, 400, 450 },

  { 0, 0, 3, 6, 8, 10, 12, 14, 16, 20, 0, 0, 3, 6, 8, 10, 12, 14, 16, 20, 0, 0,
    3, 6, 8, 10, 12, 14, 16, 20, 0, 0, 3, 6, 8, 10, 12, 14, 16, 20, 0, 0, 3, 6,
    8, 10, 12, 14, 16, 20, 0, 0, 3, 6, 8, 10, 12, 14, 16, 20, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -2, -2, -3, -4, -4, -4, -6, 0, 0, -2, -3, -4, -5, -6,
    -8, -10, -10, 0, 0, -2, -3, -4, -5, -6, -8, -10, -10, 0, 0, -2, -3, -4, -5,
    -6, -8, -10, -10 }
} ;

volatile Thm_s16HVCH_OutTw_Cmp_Tab Thm_s16HVCH_OutTw_Cmp = {
  { -400, -300, -200, -150, 0, 50, 100, 150, 200, 300, 400 },

  { 100, 100, 100, 75, 70, 70, 70, 70, 70, 70, 70 }
} ;

volatile Thm_s16Mode_Auto_Tab Thm_s16Mode_Auto = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
    20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
    20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
    20, 20, 20, 0, 10, 10, 10, 10, 10, 20, 20, 30, 30, 0, 10, 10, 10, 10, 10, 20,
    20, 20, 30, 0, 0, 0, 0, 10, 10, 10, 20, 20, 20, 0, 0, 0, 0, 0, 0, 10, 10, 20,
    20, 0, 0, 0, 0, 0, 0, 0, 10, 10, 20 }
} ;

volatile Thm_s16Tasd_Def_Cmp_Tab Thm_s16Tasd_Def_Cmp = {
  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 150, 150, 140, 120, 110, 90, 70, 50, 30, 0, 0 }
} ;

volatile Thm_s16Tasd_Dyn_Tab Thm_s16Tasd_Dyn = {
  { -300, -200, -100, -50, -20, 0, 20, 50, 100, 200, 300 },

  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { -122, -61, -20, -4, -2, 0, 4, 22, 90, 214, 428, -122, -61, -20, -4, -2, 0, 4,
    22, 90, 214, 428, -122, -61, -20, -4, -2, 0, 4, 22, 90, 214, 428, -163, -82,
    -27, -5, -2, 0, 4, 20, 88, 204, 408, -204, -102, -34, -6, -2, 0, 3, 18, 70,
    175, 330, -204, -102, -34, -6, -2, 0, 3, 15, 55, 153, 306, -245, -123, -41,
    -7, -2, 0, 2, 8, 41, 123, 245, -286, -143, -48, -8, -2, 0, 2, 7, 27, 82, 163,
    -306, -153, -51, -9, -2, 0, 2, 7, 26, 79, 158, -316, -158, -53, -10, -2, 0,
    2, 4, 26, 77, 153, -326, -163, -54, -10, -2, 0, 2, 4, 21, 64, 128 }
} ;

volatile Thm_s16Tasd_Eco_Offset_Tab Thm_s16Tasd_Eco_Offset = {
  { -15, -10, -5, 0, 5, 10, 15, 20 },

  { 60, 40, 20, 0, -50, -100, -150, -180 }
} ;

volatile Thm_s16Tasd_SolarCmp_Tab Thm_s16Tasd_SolarCmp = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56,
    -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -56,
    -56, -56, -56, -56, -56, -56, -56, -56, -56, -56, -75, -75, -75, -75, -75,
    -75, -75, -75, -75, -75, -77, -77, -77, -77, -77, -77, -77, -77, -77, -77,
    -77, -77, -77, -77, -77, -77, -77, -77, -77, -77, -83, -83, -83, -83, -83,
    -83, -83, -83, -83, -83, -88, -88, -88, -88, -88, -88, -88, -88, -88, -88,
    -62, -62, -62, -62, -62, -62, -62, -62, -62, -62, -37, -37, -37, -37, -37,
    -37, -37, -37, -37, -37 }
} ;

volatile Thm_s16Tasd_Solar_Cmp_Coefficient_Tab Thm_s16Tasd_Solar_Cmp_Coefficient
  = {
  { 0U, 100U, 200U, 300U, 400U, 500U, 600U, 800U, 1000U, 1200U },

  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 0, 10, 20, 30, 40, 50, 60, 80, 100, 120, 0, 10, 20, 30, 40, 50, 60, 80, 100,
    120, 0, 10, 20, 30, 40, 50, 60, 80, 100, 120, 0, 10, 20, 30, 40, 50, 60, 80,
    100, 120, 0, 10, 20, 30, 40, 50, 60, 80, 100, 120, 0, 10, 20, 30, 40, 50, 60,
    80, 100, 120, 0, 10, 20, 30, 40, 50, 60, 80, 100, 120, 0, 10, 20, 30, 40, 50,
    60, 80, 100, 120, 0, 10, 20, 30, 40, 50, 60, 80, 100, 120, 0, 10, 20, 30, 40,
    50, 60, 80, 100, 120, 0, 10, 20, 30, 40, 50, 60, 80, 100, 120 }
} ;

volatile Thm_s16Tast_Tab Thm_s16Tast = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -300, -200, -150, -100, -50, 0, 50, 100, 150, 200, 300, 400 },

  { -400, 480, 620, 650, 660, 670, 680, 700, 700, 700, -400, 400, 550, 600, 620,
    640, 650, 680, 700, 700, -400, 350, 455, 495, 530, 565, 590, 635, 700, 700,
    -400, 320, 415, 455, 500, 535, 555, 605, 660, 700, -400, 295, 380, 420, 470,
    495, 520, 580, 630, 700, -400, 275, 355, 400, 440, 470, 500, 555, 610, 700,
    -400, 265, 330, 380, 420, 440, 470, 530, 590, 700, -400, 250, 300, 360, 395,
    425, 445, 495, 550, 700, -400, 70, 150, 250, 300, 330, 360, 420, 490, 650,
    -400, 45, 125, 188, 235, 305, 383, 420, 490, 625, -400, 20, 100, 155, 200,
    270, 345, 390, 450, 600, -400, 10, 60, 123, 153, 198, 260, 343, 420, 530,
    -400, 0, 20, 90, 105, 145, 195, 275, 320, 460 }
} ;

volatile Thm_s16Tast_TsetDown_Cmp_Tab Thm_s16Tast_TsetDown_Cmp = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -200, -150, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 6, 6, 6, 6,
    6, 6, 6, 6, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0 }
} ;

volatile Thm_s16Tast_TsetFilFactor_Inc_Cmp_Tab Thm_s16Tast_TsetFilFactor_Inc_Cmp
  = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -200, -150, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 1, 65, 65, 65, 65, 65, 65, 65, 65, 65, 1, 65, 65, 65, 65, 65, 65, 65, 65, 65,
    1, 1, 65, 65, 65, 65, 65, 65, 65, 65, 1, 1, 65, 65, 65, 65, 65, 65, 65, 65,
    1, 1, 1, 65, 65, 65, 65, 65, 65, 65, 1, 1, 1, 1, 40, 40, 40, 40, 40, 40, 1,
    1, 1, 1, 1, 40, 40, 40, 40, 40, 1, 1, 1, 1, 1, 1, 25, 25, 25, 25, 1, 1, 1, 1,
    1, 1, 1, 25, 25, 25, 1, 1, 1, 1, 1, 1, 1, 1, 15, 15, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 15 }
} ;

volatile Thm_s16Toffset_EVA_SET_Tab Thm_s16Toffset_EVA_SET = {
  { 0, 200, 400, 500, 600, 700, 800, 900 },

  { 20, 20, 25, 30, 35, 40, 45, 45 }
} ;

volatile Thm_s16Tsys_Tab Thm_s16Tsys = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 0, 215, 235, 255, 275, 295, 315, 335, 355, 400, 0, 215, 235, 255, 275, 295,
    315, 335, 355, 400, 0, 215, 235, 255, 275, 295, 315, 335, 355, 400, 0, 215,
    235, 255, 275, 295, 315, 335, 355, 400, 0, 215, 235, 255, 275, 295, 315, 335,
    355, 400, 0, 215, 235, 255, 275, 295, 315, 335, 355, 400, 0, 215, 235, 255,
    275, 295, 315, 335, 355, 400, 0, 215, 235, 255, 275, 295, 315, 335, 355, 400,
    0, 215, 235, 255, 275, 295, 315, 335, 355, 400, 0, 215, 235, 255, 275, 295,
    315, 335, 355, 400, 0, 215, 235, 255, 275, 295, 315, 335, 355, 400 }
} ;

volatile Thm_s8LVL_CabHeat_Tab Thm_s8LVL_CabHeat = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 0, 5, 15, 15, 15, 20, 20, 20, 25, 30, 0, 5, 15, 15, 15, 15, 20, 20, 25, 30,
    0, 5, 15, 15, 15, 15, 15, 20, 25, 30, 0, 5, 15, 15, 15, 15, 15, 15, 25, 25,
    0, 5, 10, 15, 15, 15, 15, 15, 15, 20, 0, 0, 5, 10, 10, 10, 10, 10, 10, 15,
    -5, 0, 0, 5, 5, 10, 10, 10, 10, 10, -5, -5, 0, 0, 0, 5, 5, 5, 5, 10, -10, -5,
    -5, 0, 0, 0, 5, 5, 5, 10, -10, -10, -10, -5, -5, -5, 0, 0, 5, 10, -10, -10,
    -10, -10, -10, -5, -5, 0, 0, 10 }
} ;

volatile Thm_u8VBLW_Static_Tab Thm_u8VBLW_Static = {
  { 175U, 180U, 200U, 220U, 240U, 260U, 280U, 300U, 320U, 325U },

  { -400, -300, -200, -100, 0, 50, 100, 150, 200, 300, 400 },

  { 45U, 50U, 55U, 58U, 64U, 69U, 73U, 82U, 90U, 116U, 44U, 48U, 53U, 57U, 63U,
    68U, 72U, 80U, 90U, 113U, 80U, 44U, 48U, 52U, 59U, 66U, 71U, 80U, 90U, 110U,
    80U, 40U, 44U, 50U, 57U, 60U, 64U, 69U, 79U, 103U, 55U, 40U, 44U, 48U, 50U,
    57U, 64U, 70U, 80U, 96U, 58U, 43U, 42U, 44U, 44U, 53U, 62U, 69U, 78U, 90U,
    60U, 45U, 40U, 39U, 38U, 48U, 60U, 68U, 75U, 83U, 63U, 48U, 41U, 37U, 37U,
    45U, 57U, 66U, 73U, 80U, 65U, 50U, 41U, 35U, 36U, 42U, 54U, 64U, 70U, 76U,
    88U, 80U, 68U, 52U, 43U, 38U, 36U, 35U, 42U, 70U, 105U, 96U, 82U, 70U, 58U,
    48U, 42U, 38U, 37U, 56U }
} ;

volatile s16Chil_EXV_Ki_Tab s16Chil_EXV_Ki = {
  { -100, -50, -20, 0, 10, 20, 50, 100 },

  { -6, -3, -1, 0, 0, 1, 2, 5 }
} ;

volatile s16Ki_EXV_EvaCDS_HP_Tab s16Ki_EXV_EvaCDS_HP = {
  { -50, -30, -20, 0, 10, 20, 50, 100 },

  { -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2,
    2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2,
    2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2 }
} ;

volatile s16Twater_Max_ACDehum_Tab s16Twater_Max_ACDehum = {
  { 0, 50, 100, 150, 200, 300, 400 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 50, 50, 100, 150, 200, 300, 450, 50, 50, 100, 150, 200, 300, 450, 50, 50,
    100, 155, 205, 305, 470, 50, 50, 100, 160, 210, 310, 500, 50, 50, 100, 165,
    220, 320, 520, 50, 50, 100, 170, 230, 330, 550, 50, 50, 100, 175, 240, 340,
    550 }
} ;

volatile s16Twater_Max_HP_Tab s16Twater_Max_HP = {
  { -300, -200, -100, -50, 0, 100, 200 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 250, 400, 650, 650, 650, 650, 650, 150, 300, 600, 650, 650, 650, 650, 100,
    250, 550, 650, 650, 650, 650, 80, 200, 500, 600, 650, 650, 650, 50, 180, 450,
    520, 650, 650, 650, 50, 150, 350, 400, 600, 650, 650, 50, 100, 350, 380, 550,
    650, 650 }
} ;

volatile s16Twater_Max_TotalDehum_Tab s16Twater_Max_TotalDehum = {
  { 0, 50, 100, 150, 200, 300, 400 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650,
    650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 560, 600,
    650, 650, 650, 650, 650, 500, 500, 650, 650, 650, 650, 650, 480, 480, 650,
    650, 650, 650, 650 }
} ;

volatile s16Twater_Min_HP_Tab s16Twater_Min_HP = {
  { -300, -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { -200, -50, 0, 100, 160, 200, 290, 380, 550, 650, -200, -80, 0, 100, 160, 180,
    280, 380, 550, 650, -250, -100, 0, 80, 130, 160, 250, 360, 500, 620, -250,
    -120, 0, 60, 100, 140, 220, 340, 480, 600, -250, -150, -20, 40, 70, 130, 190,
    330, 450, 580, -250, -180, -30, 30, 60, 100, 200, 320, 430, 550, -280, -150,
    -50, 0, 50, 90, 200, 300, 400, 500 }
} ;

volatile s16Twater_Min_TotalDehum_Tab s16Twater_Min_TotalDehum = {
  { 0, 50, 100, 150, 200, 300, 400 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 70, 120, 190, 280, 300, 450, 540, 65, 100, 190, 280, 300, 450, 530, 60, 100,
    180, 240, 290, 400, 500, 50, 90, 150, 220, 280, 350, 480, 50, 80, 140, 200,
    260, 330, 440, 40, 80, 130, 200, 250, 320, 430, 30, 70, 130, 200, 230, 300,
    420 }
} ;

volatile u16ACMode_EdcRamp_Tab u16ACMode_EdcRamp = {
  { 50, 100, 150, 200, 300, 400 },

  { 150U, 200U, 220U, 240U, 260U, 280U },

  { 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U,
    130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 130U, 120U, 100U, 100U, 100U,
    100U, 100U, 80U, 60U, 60U, 60U, 60U, 60U, 50U, 50U }
} ;

volatile u16ACNcomp_PrcoRisk_Tab u16ACNcomp_PrcoRisk = {
  { 210U, 220U, 230U, 240U, 250U, 260U, 270U, 280U },

  { 0U, 0U, 0U, 3U, 6U, 12U, 20U, 60U }
} ;

volatile u16Chil_EXV_Kp_Tab u16Chil_EXV_Kp = {
  { -100, -50, -20, 0, 10, 20, 50, 100 },

  { 40U, 40U, 30U, 20U, 10U, 20U, 40U, 40U }
} ;

volatile u16EXV_EvaCDS_Est_TDEDC_Tab u16EXV_EvaCDS_Est_TDEDC = {
  { 0, 30, 50, 100, 120, 150, 200, 250, 300, 400 },

  { 0U, 100U, 150U, 200U, 250U, 300U, 350U, 400U, 450U, 500U, 600U },

  { 83U, 83U, 83U, 83U, 83U, 83U, 83U, 83U, 83U, 83U, 90U, 90U, 90U, 90U, 90U,
    90U, 90U, 90U, 90U, 90U, 98U, 98U, 98U, 98U, 98U, 98U, 98U, 98U, 98U, 98U,
    105U, 105U, 105U, 105U, 105U, 105U, 105U, 105U, 105U, 105U, 113U, 113U, 113U,
    113U, 113U, 113U, 113U, 113U, 113U, 113U, 120U, 120U, 120U, 120U, 120U, 120U,
    120U, 120U, 120U, 120U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U, 128U,
    128U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 135U, 143U, 143U,
    143U, 143U, 143U, 143U, 143U, 143U, 143U, 143U, 150U, 150U, 150U, 150U, 150U,
    150U, 150U, 150U, 150U, 150U, 165U, 165U, 165U, 165U, 165U, 165U, 165U, 165U,
    165U, 165U }
} ;

volatile u16EXV_EvaCDS_Min_2D_Tab u16EXV_EvaCDS_Min_2D = {
  { -300, -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 0U, 50U, 80U, 120U, 150U, 200U, 250U, 300U, 400U, 500U },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 45U, 45U, 45U, 45U, 45U, 50U, 50U,
    50U, 50U, 50U, 55U, 50U, 50U, 50U, 50U, 60U, 60U, 60U, 60U, 60U, 60U, 60U,
    60U, 60U, 60U, 70U, 70U, 70U, 70U, 70U, 80U, 80U, 80U, 80U, 80U, 85U, 85U,
    85U, 85U, 85U, 125U, 125U, 125U, 125U, 125U, 130U, 130U, 130U, 130U, 130U,
    150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U,
    150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U,
    150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U, 150U,
    150U }
} ;

volatile u16EXV_EvaCDS_Pos_HP_Est_Tab u16EXV_EvaCDS_Pos_HP_Est = {
  { -300, -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 0U, 1000U, 2000U, 3000U, 4500U, 6000U, 7500U },

  { 90U, 90U, 90U, 90U, 90U, 90U, 90U, 100U, 110U, 110U, 90U, 90U, 90U, 90U, 90U,
    95U, 95U, 100U, 120U, 130U, 100U, 100U, 100U, 100U, 100U, 110U, 110U, 110U,
    120U, 130U, 110U, 110U, 110U, 110U, 110U, 120U, 120U, 120U, 130U, 140U, 115U,
    115U, 120U, 130U, 135U, 140U, 140U, 140U, 150U, 160U, 130U, 130U, 130U, 140U,
    150U, 160U, 160U, 170U, 180U, 190U, 135U, 135U, 135U, 145U, 160U, 170U, 170U,
    180U, 190U, 200U }
} ;

volatile u16EXV_Eva_Pos_AC_Est_Tab u16EXV_Eva_Pos_AC_Est = {
  { -300, -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 0U, 1000U, 2000U, 3000U, 4500U, 6000U, 7500U },

  { 77U, 77U, 77U, 77U, 77U, 77U, 77U, 77U, 77U, 77U, 99U, 99U, 99U, 125U, 132U,
    90U, 90U, 80U, 80U, 80U, 121U, 121U, 121U, 145U, 154U, 120U, 120U, 120U,
    120U, 120U, 143U, 143U, 143U, 165U, 176U, 140U, 140U, 140U, 140U, 140U, 165U,
    165U, 165U, 187U, 204U, 160U, 160U, 160U, 160U, 160U, 187U, 187U, 187U, 209U,
    231U, 180U, 180U, 180U, 180U, 180U, 220U, 220U, 220U, 242U, 264U, 240U, 240U,
    240U, 240U, 240U }
} ;

volatile u16Edc_ToutReduce_Tab u16Edc_ToutReduce = {
  { 700, 800, 900, 1150, 1200, 1250, 1300, 1350 },

  { 0U, 0U, 0U, 0U, 1U, 1U, 6U, 15U }
} ;

volatile u16Ki_EDC_HP_Tab u16Ki_EDC_HP = {
  { -300, -200, -100, -50, 0, 100, 200 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 21U, 15U, 15U, 10U, 10U, 10U, 10U, 27U, 23U, 15U, 13U, 12U, 10U, 10U, 30U,
    27U, 18U, 14U, 14U, 10U, 10U, 38U, 30U, 24U, 15U, 15U, 11U, 10U, 45U, 38U,
    27U, 20U, 15U, 12U, 10U, 48U, 42U, 30U, 21U, 15U, 14U, 11U, 57U, 45U, 33U,
    23U, 18U, 15U, 12U }
} ;

volatile u16Ki_EDC_TotalDehum_Tab u16Ki_EDC_TotalDehum = {
  { 0, 30, 50, 100, 120, 150, 200, 250, 300, 400 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 9U, 8U, 8U, 7U, 7U, 6U, 6U, 4U, 3U, 3U, 9U, 9U, 8U, 7U, 7U, 6U, 6U, 4U, 3U,
    3U, 14U, 12U, 11U, 9U, 9U, 9U, 9U, 6U, 3U, 3U, 20U, 19U, 17U, 14U, 14U, 13U,
    11U, 9U, 6U, 4U, 26U, 24U, 23U, 20U, 19U, 17U, 14U, 11U, 9U, 6U, 29U, 27U,
    26U, 24U, 21U, 20U, 17U, 14U, 11U, 9U, 34U, 33U, 31U, 29U, 26U, 23U, 19U,
    14U, 11U, 9U }
} ;

volatile u16Kp_EDC_ACChil_Tab u16Kp_EDC_ACChil = {
  { 0, 20, 100, 200, 300, 400, 500 },

  { 0U, 25U, 46U, 63U, 82U, 103U, 125U },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 100U, 100U, 100U, 100U, 100U, 120U, 0U, 100U,
    100U, 100U, 120U, 130U, 170U, 0U, 100U, 110U, 120U, 130U, 190U, 200U, 0U,
    100U, 120U, 130U, 150U, 200U, 220U, 0U, 100U, 130U, 140U, 160U, 220U, 250U,
    0U, 100U, 130U, 140U, 160U, 250U, 300U }
} ;

volatile u16Kp_EDC_HP_Tab u16Kp_EDC_HP = {
  { -300, -200, -100, -50, 0, 100, 200 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 50U, 40U, 30U, 28U, 25U, 20U, 20U, 60U, 50U, 40U, 35U, 30U, 20U, 20U, 80U,
    60U, 50U, 40U, 30U, 30U, 30U, 90U, 80U, 70U, 60U, 50U, 40U, 40U, 140U, 120U,
    100U, 80U, 60U, 50U, 50U, 180U, 150U, 120U, 100U, 80U, 60U, 60U, 200U, 180U,
    150U, 120U, 100U, 80U, 80U }
} ;

volatile u16Kp_EDC_TotalDehum_Tab u16Kp_EDC_TotalDehum = {
  { 0, 30, 50, 100, 120, 150, 200, 250, 300, 400 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 30U, 29U, 28U, 26U, 24U, 22U, 20U, 15U, 12U, 10U, 32U, 30U, 28U, 26U, 24U,
    22U, 20U, 15U, 12U, 10U, 48U, 42U, 37U, 33U, 32U, 31U, 30U, 20U, 12U, 10U,
    70U, 65U, 60U, 50U, 48U, 45U, 40U, 30U, 20U, 15U, 90U, 85U, 80U, 70U, 65U,
    60U, 50U, 40U, 30U, 20U, 100U, 95U, 90U, 83U, 75U, 70U, 60U, 50U, 40U, 30U,
    120U, 115U, 110U, 100U, 90U, 80U, 65U, 50U, 40U, 30U }
} ;

volatile u16Ncomp_AC_Est_Tab u16Ncomp_AC_Est = {
  { 0, 50, 100, 200, 300, 400, 500 },

  { 0U, 25U, 46U, 63U, 82U, 103U, 125U },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 300U, 600U, 2000U, 2000U, 0U, 0U,
    250U, 500U, 900U, 2400U, 2400U, 0U, 100U, 450U, 800U, 1400U, 3500U, 3500U,
    0U, 300U, 600U, 1000U, 2000U, 3800U, 3800U, 0U, 600U, 700U, 1200U, 2700U,
    4500U, 4500U, 0U, 600U, 800U, 1200U, 3200U, 4500U, 4500U }
} ;

volatile u16Ncomp_EXVEst_Tab u16Ncomp_EXVEst = {
  { 38U, 50U, 80U, 100U, 150U, 180U, 200U, 220U },

  { 0U, 600U, 900U, 1000U, 1200U, 1400U, 1500U, 1500U }
} ;

volatile u16Ncomp_EvaRisk_Tab u16Ncomp_EvaRisk = {
  { -30, -20, -10, 0, 10, 20, 25, 30 },

  { 30U, 30U, 30U, 10U, 7U, 3U, 0U, 0U }
} ;

volatile u16Ncomp_EvaRisk_TotalDehum_Tab u16Ncomp_EvaRisk_TotalDehum = {
  { -30, -20, -10, 0, 10, 20, 25, 30 },

  { 40U, 30U, 20U, 0U, 0U, 0U, 0U, 0U }
} ;

volatile u16Ncomp_HP_Est_Tab u16Ncomp_HP_Est = {
  { -300, -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 0, 100, 200, 300, 400, 500, 600 },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1000U, 1000U, 800U, 500U, 300U, 0U,
    0U, 0U, 0U, 0U, 2000U, 2000U, 900U, 600U, 600U, 120U, 0U, 0U, 0U, 0U, 3000U,
    3000U, 2000U, 1200U, 1200U, 900U, 600U, 0U, 0U, 0U, 4000U, 4000U, 3000U,
    1800U, 1800U, 1000U, 900U, 120U, 0U, 0U, 5000U, 5000U, 4000U, 2700U, 2400U,
    1400U, 1200U, 360U, 0U, 0U, 6000U, 6000U, 5200U, 3900U, 2700U, 1800U, 1400U,
    420U, 0U, 0U }
} ;

volatile u16Ncomp_HP_RampSpd_Tab u16Ncomp_HP_RampSpd = {
  { -300, -200, -100, -50, 0, 50, 100, 200, 300, 400 },

  { 11U, 12U, 13U, 14U, 15U, 16U, 18U, 20U, 30U },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 10U, 10U, 10U, 10U, 10U, 15U, 15U,
    15U, 15U, 15U, 15U, 15U, 15U, 15U, 20U, 20U, 20U, 20U, 20U, 20U, 15U, 15U,
    15U, 15U, 30U, 30U, 30U, 30U, 30U, 30U, 20U, 20U, 20U, 20U, 30U, 40U, 40U,
    40U, 40U, 40U, 40U, 40U, 40U, 40U, 60U, 80U, 80U, 80U, 80U, 80U, 80U, 80U,
    80U, 80U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 130U,
    200U, 200U, 200U, 200U, 200U, 120U, 120U, 120U, 120U, 150U, 200U, 250U, 300U,
    300U, 300U }
} ;

volatile u16Ncomp_PowRisk_Tab u16Ncomp_PowRisk = {
  { -1000, -500, -200, -100, 0, 50, 100, 200 },

  { 30U, 20U, 10U, 5U, 3U, 0U, 0U, 0U }
} ;

volatile u16Ncomp_PrciRisk_HP_Tab u16Ncomp_PrciRisk_HP = {
  { 9U, 10U, 11U, 12U, 13U, 14U, 15U, 16U },

  { 60U, 40U, 20U, 10U, 0U, 0U, 0U, 0U }
} ;

volatile u16Ncomp_PrciRisk_TotalDehum_Tab u16Ncomp_PrciRisk_TotalDehum = {
  { 15U, 18U, 20U, 22U, 24U, 26U, 28U, 30U },

  { 60U, 45U, 30U, 20U, 10U, 0U, 0U, 0U }
} ;

volatile u16Ncomp_PrcoRisk_Tab u16Ncomp_PrcoRisk = {
  { 210U, 220U, 230U, 245U, 250U, 260U, 270U, 280U },

  { 0U, 0U, 0U, 0U, 1U, 3U, 35U, 50U }
} ;

volatile u16Ncomp_PresRatio_Risk_Tab u16Ncomp_PresRatio_Risk = {
  { 10U, 12U, 14U, 16U, 17U, 18U, 19U, 20U },

  { 0U, 0U, 0U, 0U, 25U, 30U, 50U, 60U }
} ;

volatile u16Ncomp_TotalDehum_Est_Tab u16Ncomp_TotalDehum_Est = {
  { 0, 30, 50, 100, 120, 150, 200, 250, 300, 400 },

  { 0, 100, 200, 300, 400, 500, 600 },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 300U, 200U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 600U, 400U, 120U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1200U, 900U, 800U,
    600U, 0U, 0U, 0U, 0U, 0U, 0U, 1800U, 1000U, 950U, 900U, 500U, 300U, 120U, 0U,
    0U, 0U, 2400U, 2000U, 1500U, 1200U, 500U, 600U, 360U, 0U, 0U, 0U, 2700U,
    2500U, 2100U, 1500U, 900U, 600U, 420U, 0U, 0U, 0U }
} ;

volatile u16Percent_EDCEst_HP_Tab u16Percent_EDCEst_HP = {
  { -300, -200, -100, -50, 0, 100, 200 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 60U, 60U, 60U, 60U, 60U, 60U, 60U, 85U, 85U, 85U,
    85U, 85U, 85U, 85U, 100U, 100U, 100U, 100U, 100U, 100U, 100U, 133U, 133U,
    133U, 133U, 133U, 133U, 100U, 146U, 146U, 146U, 146U, 146U, 146U, 100U, 170U,
    170U, 170U, 170U, 170U, 170U, 100U }
} ;

volatile u16QAir_Estimation_HVPTC_FullHot_Tab u16QAir_Estimation_HVPTC_FullHot =
{
  { 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  { 0U, 30U, 60U, 90U, 120U, 130U, 150U },

  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 108U, 108U, 97U, 97U, 97U, 108U, 97U, 216U, 216U,
    200U, 189U, 189U, 216U, 189U, 324U, 324U, 306U, 281U, 281U, 324U, 281U, 432U,
    432U, 400U, 378U, 378U, 432U, 378U, 432U, 432U, 400U, 378U, 378U, 432U, 378U,
    432U, 432U, 400U, 378U, 378U, 432U, 378U }
} ;

volatile u16SH_Target_HP_Tab u16SH_Target_HP = {
  { -300, -200, -100, -50, 0, 100, 200 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 30U, 30U, 30U, 30U, 35U, 30U, 40U, 30U, 30U, 30U, 30U, 35U, 40U, 40U, 30U,
    30U, 30U, 30U, 35U, 40U, 40U, 30U, 30U, 30U, 30U, 40U, 45U, 50U, 30U, 30U,
    30U, 30U, 40U, 45U, 50U, 30U, 30U, 30U, 40U, 40U, 45U, 50U, 30U, 30U, 40U,
    40U, 40U, 45U, 50U }
} ;

volatile u16SH_Target_TotalDehum_Tab u16SH_Target_TotalDehum = {
  { 0, 30, 50, 100, 120, 150, 200, 250, 300, 400 },

  { 0U, 120U, 170U, 250U, 350U, 420U, 550U },

  { 20U, 20U, 20U, 20U, 30U, 30U, 30U, 30U, 30U, 40U, 20U, 20U, 20U, 20U, 30U,
    30U, 30U, 30U, 30U, 40U, 20U, 20U, 20U, 20U, 30U, 30U, 30U, 30U, 30U, 40U,
    20U, 20U, 20U, 20U, 30U, 40U, 40U, 40U, 40U, 50U, 20U, 20U, 20U, 30U, 40U,
    50U, 50U, 50U, 50U, 60U, 20U, 20U, 20U, 30U, 40U, 60U, 60U, 60U, 70U, 70U,
    20U, 20U, 20U, 30U, 50U, 60U, 60U, 60U, 80U, 80U }
} ;

volatile u8Pos_MixStepper_Pomi_Tab u8Pos_MixStepper_Pomi = {
  { 33, 93, 124, 157, 204, 266, 343, 419, 468, 548, 793 },

  { 0U, 10U, 20U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U }
} ;

volatile u8Pos_MixStepper_Pomi_95_Tab u8Pos_MixStepper_Pomi_95 = {
  { 34, 40, 112, 143, 169, 195, 235, 284, 365, 422, 530, 781 },

  { 0U, 10U, 20U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 95U, 100U }
} ;

/* Volatile memory section */
/* Definition for custom storage class: Volatile */
volatile boolean_T ACPre_bAGS_AVAILABLE = 1;/* AGS is Available */
volatile int16_T ACPre_s16Temp_Hys_Down = 0;/* The Temperature hysterisis down for the Twat fro the mode select */
volatile int16_T ACPre_s16Temp_Hys_Up = 50;/* The Temperature hysterisis up for Twat for the mode select */
volatile uint8_T ACPre_u8AGS_MAX = 100U;/* AGS max open value */
volatile uint8_T ACPre_u8MotorCoolReq_Yes = 1U;/* The flag of the motor cooling requirement  */
volatile uint8_T ACPre_u8Project_CheryE03 = 2U;/* Chery E03 Project Code 2 */
volatile uint8_T ACPre_u8Project_SokonX1 = 1U;/* Sokon X1 Project Code 1 */
volatile uint8_T CAL_u8BLW_AUTO_8 = 8U;/* Auto Mode of Blower */
volatile uint8_T CAL_u8DIS_MODE_DEF = 4U;/* The HVAC Distribution Mode, Defrost_4 */
volatile uint8_T CAL_u8DIS_MODE_FD = 3U;/* The HVAC Distribution Mode, Feet_Defrost_3 */
volatile uint8_T CAL_u8DIS_MODE_FEET = 2U;/* The HVAC Distribution Mode, Feet_2 */
volatile uint8_T CAL_u8DIS_MODE_VENT = 0U;/* The HVAC Distribution Mode, Vent_0 */
volatile uint8_T CAL_u8DIS_MODE_VF = 1U;/* The HVAC Distribution Mode, BiLvl_VF_1 */
volatile uint8_T CAL_u8INTAK_AUTO_3 = 3U;/* Auto Mode of Intake Flap */
volatile uint8_T CAL_u8INTAK_ManualFRE_2 = 2U;/* ManualFRE of Intake Flap */
volatile uint8_T CAL_u8INTAK_ManualREC_1 = 1U;/* ManualREC of Intake Flap */
volatile uint8_T CAL_u8MODE_AUTO_6 = 6U;/* Auto Mode of Mode */
volatile uint16_T CMF_u16TIMER_10S = 10U;/* The Comfortable Timer 10S, sample time is 1S */
volatile uint8_T CMF_u8BLW_MAX = 120U; /* The BLW output Max 120 */
volatile uint8_T CMF_u8BLW_MIN = 32U;  /* The BLW output min 32 */
volatile uint8_T CMF_u8FLAP_INTAK_FRE = 100U;/* The Intake Flap postion in the Fresh, 100% percent  */
volatile uint8_T CMF_u8FLAP_INTAK_RECY = 0U;/* The Intake Flap postion in the Recycle, 0% percent  */
volatile uint8_T CMF_u8FLAP_INTAK_TwoLayer = 250U;/* The Intake Flap postion in the two layer */
volatile uint8_T CMF_u8MODE_HP_7 = 7U; /* Working mode of the HP */
volatile uint8_T CMF_u8MODE_HP_BatHeat_10 = 10U;/* Working mode of the HP for Cabin heating and Battery heating */
volatile uint8_T CMF_u8MODE_HP_CHILMDCHIL_12 = 12U;/* Working mode of the HP get the Power from Chil and MD Chil */
volatile uint8_T CMF_u8MODE_HP_CHIL_8 = 8U;/* Working mode of the HP with Chiller for Battery Cooling */
volatile uint8_T CMF_u8MODE_HP_MDCHIL_9 = 9U;/* Working mode of the HP with the Heat Recovery from Motor Driver */
volatile boolean_T CmfThm_bConst_0 = 0;/* Constant 0 and false */
volatile boolean_T CmfThm_bConst_1 = 1;/* Constant 1 and True */
volatile uint16_T CmfThm_u16Filter_60s = 600U;/* Filter 60s */
volatile uint16_T CmfThm_u16Sun_DecNum_Filter = 1200U;/* Sun_DecNum_Filter */
volatile uint16_T CmfThm_u16Sun_IncNum_Filter = 300U;/* Sun_IncNum_Filter */
volatile uint8_T CmfThm_u8Filter_15s = 150U;/* Filter 15s */
volatile uint8_T CmfThm_u8Filter_2s = 20U;/* Filter 2s */
volatile uint8_T CmfThm_u8Filter_3s = 30U;/* Filter 3s */
volatile uint8_T CmfThm_u8Filter_6s = 60U;/* Filter 6s */
volatile uint8_T Flap_u8DIS_MODE_FD_Sokon = 3U;/* HVAC Distribution Mode, 3 is FD, Sokon */
volatile uint8_T Flap_u8DIS_MODE_FEET_Sokon = 2U;/* HVAC Distribution Mode, 2 is F, Sokon */
volatile uint8_T Hp_u8TWV_HC_FullCool_Sokon = 0U;/* The 3Way Valve Postion of FullCool for Sokon 0% */
volatile uint8_T Hp_u8TWV_HC_FullHot_Sokon = 100U;/* The 3Way Valve Postion of Fullhot for Sokon 100% */
volatile uint8_T Hp_u8TWV_HC_MiddlePos_Sokon = 50U;/* The 3Way Valve Postion of Middle Position for Sokon 50% */
volatile uint8_T SEN_u8CMFSW_FIRST_2 = 2U;/* SEN_u8CMFSW_FIRST */
volatile uint8_T SEN_u8CMFSW_INIT_0 = 0U;/* SEN_u8CMFSW_INIT */
volatile uint8_T SEN_u8CMFSW_READY_1 = 1U;/* SEN_u8CMFSW_READY */
volatile int16_T THM_s16TASD_NoCompDyn_0 = 0;/* TASD 0, No Comp and Dynamic Compensation */
volatile int16_T THM_s16TASD_UPLIM = 700;/* The TASD Low Limitation 80 degree  */
volatile int16_T THM_s16TEVA_SET_MAX = 150;/* The Teva Setting Max 15 Degree */
volatile int16_T THM_s16TEVA_SET_MIN = 30;/* The Teva Setting Min 3 Degree */
volatile int16_T THM_s16TEVA_SET_STOP = 200;/* The Teva Setting, No Requirement 20 Degree */
volatile uint16_T THM_u16TSET_HI = 325U;/* Pad TSET is HI, Sokon is 32.5 degree */
volatile uint16_T THM_u16TSET_LOW = 175U;/* Pad TSET is low, Sokon is 17.5 degree */
volatile uint8_T THM_u8CONST_2 = 2U;   /* The Constant_2 use for the average */
volatile uint8_T THM_u8HVAC_STS_OFF = 3U;/* The HVAC Status 3,Off MODE */
volatile uint8_T THM_u8HVAC_STS_OTA = 9U;/* The HVAC Status 9, OTA MODE */
volatile uint8_T THM_u8HVAC_STS_VENTILATE = 4U;/* The HVAC Status 4, Ventilate MODE */
volatile boolean_T bCONST_0 = 0;       /* 0 and not meet the condition */
volatile boolean_T bCONST_1 = 1;       /* 1 and not meet the condition */
volatile boolean_T bFAILRISK_NO_0 = 0; /* 0, NO Failure and Risk */
volatile boolean_T bFAILRISK_YES_1 = 1;/* 1, With Failure and Risk */
volatile boolean_T bFAIL_NO_RISK_0 = 0;/* 0 and not meet the condition */
volatile boolean_T bFAIL_RISK_No = 0;  /* 0 and NO failure and no Risk */
volatile boolean_T bFAIL_RISK_YES = 1; /* 1 and with Failure and Risk */
volatile boolean_T bFAIL_RISK_Y_1 = 1; /* 1 and not meet the condition */
volatile boolean_T bFLAG_YES = 1;      /* 1 and not meet the condition */
volatile boolean_T bSOV_Close_0 = 0;   /* SOV Close */
volatile boolean_T bSOV_OPEN_1 = 1;    /* SOV Open */
volatile int16_T s16POMILIMIT_0 = 0;   /* The Temperature Uplimit for Saturation  */
volatile int16_T s16POMILIMIT_1000 = 1000;/* The Temperature Uplimit for Saturation  */
volatile int16_T s16POWER_GAP_NORISK = 300;/* Powercomp limitation  subtract Power comp consume, if more than 300 W, it is safe */
volatile int16_T s16POWER_GAP_RISK = 50;/* Powercomp limitation - Power comp consume,if less than 50 W, it have the risk */
volatile int16_T s16TAD_LOW_30 = 30;   /* Text<3 ¡æ, AC Authority is not  */
volatile int16_T s16TAD_UP_50 = 50;    /* Text>5 ¡æ, AC Authority is OK */
volatile int16_T s16TCTRL_DELTA_DOWNLIMIT = -300;/* The Temperature Down Limit for Saturation */
volatile int16_T s16TCTRL_DELTA_UPLIMIT = 300;/* The Temperature Uplimit for Saturation  */
volatile int16_T s16TEMP_LIMIT_M40 = -400;/* Twater Down limitation, 10±¶·Å´ó±¶Êý */
volatile int16_T s16TEMP_POMILIMIT_0 = 0;/* The Temperature Uplimit for Saturation  */
volatile int16_T s16TEMP_POMILIMIT_30 = 30;/* The Temperature Uplimit for Saturation  */
volatile int16_T s16TEMP_UPLIMIT = 1100;/* The Temperature Uplimit for Saturation  */
volatile int16_T s16TEVA_CTRL_DOWN = -100;/* Teva temperatur control lowlimit -100 (-10¡æ) */
volatile int16_T s16TEVA_CTRL_UP = 175;/* Teva temperatur control uplimit 175 (17.5 ¡æ) */
volatile int16_T s16TEVA_DOWNLIMIT = -400;/* The Teva down Limitation  */
volatile int16_T s16TEVA_FAIL = -30;   /* Teva freeze temperature */
volatile int16_T s16TEVA_FREEZE_NOR = 20;/* the temeprature of evaporator is 2 degree, no freeze risk */
volatile int16_T s16TEVA_FREZEE = 0;   /* Teva freeze risk temperature 0 ¡æ for EDC onf off */
volatile int16_T s16TEVA_NOR = 10;     /* Teva no freeze temperature  */
volatile int16_T s16TEVA_NOR_RESTART = 40;/* Teva freeze risk temperature 4 ¡æ for EDC onf off */
volatile int16_T s16TEVA_UPLIMIT = 800;/* The Teva Up Limitaion */
volatile int16_T s16TEVA_UP_150 = 150; /* Teva setting must lower than 15¡æ */
volatile int16_T s16TSET_LOW = 175;    /* The Set Temperature when the Setting temperature is LOW */
volatile int16_T s16Tw_HVCH_UpLimit = 800;/* HVCH temperature control uplimit 800 (80 ¡æ) */
volatile int16_T s16Tw_HVCH_UpLimitMax = 850;/* HVCH temperature control uplimit 800 (80 ¡æ) */
volatile int32_T s32NCOMP_DOWN_0 = 0;  /* EDC calculation lower limit is 0rpm */
volatile int32_T s32NCOMP_DOWN_LIMIT = 9600;/* The EDC RPM uplimit and the amplification rate is 10, it means 960 RPM */
volatile int32_T s32NCOMP_FOR_ACCHIL = 30000;/* The EDC RPM Estimation section uplimit and the amplification rate is 10, it means 3000 RPM */
volatile int32_T s32NCOMP_ICAL_UP = 60000;/* The EDC RPM Estimation section uplimit and the amplification rate is 10, it means 6000 RPM */
volatile int32_T s32NCOMP_STOP_0 = 0;  /* The EDC RPM 0 when the Compressor Stop */
volatile int32_T s32NCOMP_UP_LIMIT = 70000;/* The EDC RPM uplimit and the amplification rate is 10, it means 7000 RPM */
volatile int32_T s32NCOMP_UP_SPD = 200;/* The EDC RPM Rampup Speed is 20 RPM per sample time (0.1S) and means 200 RPM per seconds */
volatile uint16_T u16AMP_10 = 10U;     /* 10 times amplification rate */
volatile uint16_T u16AMP_100 = 100U;   /* 100 times amplification rate */
volatile uint16_T u16AMP_1000 = 1000U; /* 1000 times amplification rate */
volatile uint16_T u16AMP_10000 = 10000U;/* 10000 times amplification rate */
volatile uint16_T u16CHIL_EXV_MIN_START = 38U;/* chiller edc condition start configure for exv mimunm is 30 steps */
volatile uint16_T u16CONST_0 = 0U;     /* The Constant 1 use for the filter and timer */
volatile uint16_T u16COUNT_0 = 0U;     /* Constant 0, use for initilization  */
volatile uint16_T u16COUNT_1 = 1U;     /* Constant 0, use for initilization  */
volatile uint16_T u16EDC_POWERMIN = 100U;/* Edc startup Power min limitation */
volatile uint16_T u16EDC_RPMMIN = 800U;/* Edc Startup PRM min limitation */
volatile uint16_T u16EXV_CHIL_MIN_0 = 0U;/* Chiller EXV close step 0 */
volatile uint16_T u16NCOMP_STOP_0 = 0U;/* The RPM of the compressor Stop */
volatile uint16_T u16PBALANCE = 40U;   /* The difference of High pressure and low pressure is low than this one, the pressure is balance */
volatile uint16_T u16PCHARGE_FAIL = 25U;/* When the high pressure is low than 2.5 bar, it means the charge failure,the Refrigerant leakage */
volatile uint16_T u16PRCI_FAIL = 15U;  /* System protection Yes if the low pressure low than 1.5 bar */
volatile uint16_T u16PRCI_FAIL_HP = 10U;/* System protection Yes in HP Mode  if the low pressure low than 1.0bar */
volatile uint16_T u16PRCI_NOR = 20U;   /* System Protection No if the low pressure high than 2 bar */
volatile uint16_T u16PRCI_NORFAIL_HP = 13U;/* System Protection No in HP Mode if the low pressure high than 1.3 bar */
volatile uint16_T u16PRCO_FAIL = 280U; /* System protection Yes in the pressure  */
volatile uint16_T u16PRCO_NOR = 220U;  /* System Protection No in the pressure  */
volatile uint16_T u16PRCO_NORISK = 210U;/* System Protection No in the pressure in the 22 bar */
volatile uint16_T u16PRCO_RISK = 250U; /* System protection Yes in the pressure in the 26 bar */
volatile uint16_T u16SH_LOW_LIMIT = 0U;/* Superheat lowlimit 0 ¡æ */
volatile uint16_T u16SH_UP_LIMIT = 500U;/* Superheat uplimit 50 ¡æ */
volatile uint16_T u16TIME_EVAFRE = 5U; /* Eva temperature low than 0¡æ 5S, then define the Eva have the freeze risk */
volatile uint16_T u16TIME_EVAFRE_RELEASE = 100U;/* After the Eva judge the Eva freeze, the on/off time minium is 10s */
volatile uint16_T u16TIMT_EDC_CONF_5 = 5U;/* When the EDC Configulartion more than 0.5s, the EDC can Start */
volatile uint16_T u16VAIR_CONDMIN = 5U;/* The minum Condenser 5  Air flowrate for the AC On 0.5m/s */
volatile uint8_T u8AMP_10 = 10U;       /* 10 times amplification rate */
volatile uint8_T u8AMP_100 = 100U;     /* 100 times amplification rate */
volatile uint8_T u8BLW_VOL_MIN = 20U;  /* The minum HVAC Blw voltage is 3v */
volatile uint8_T u8BTMCOOL_1 = 1U;     /* Battery Cooling Level 1, AC Priority */
volatile uint8_T u8BTMCOOL_2 = 2U;     /* Battery Cooling Level 2, AC Priority (But the condition with compromise) */
volatile uint8_T u8BTMCOOL_3 = 3U;     /* Battery Cooling L3, BTC is priority */
volatile uint8_T u8BTM_CycleL11 = 11U; /* Battery Cycle L11, Battery Internal cycle */
volatile uint8_T u8BTM_HeatL4 = 4U;    /* Battery heating Level 4 */
volatile uint8_T u8BTM_HeatL5 = 5U;    /* Battery heating Level 5 */
volatile uint8_T u8DIS_MODE_DEF_4 = 4U;/* The HVAC Distribution Mode, Defrost_4 */
volatile uint8_T u8DIS_MODE_FD_3 = 3U; /* The HVAC Distribution Mode, Feet_3 */
volatile uint8_T u8DIS_MODE_FEET_2 = 2U;/* The HVAC Distribution Mode, Feet_2 */
volatile uint8_T u8DIS_MODE_VD_6 = 6U; /* The HVAC Distribution Mode, Vent/Defrost_6 */
volatile uint8_T u8DIS_MODE_VENT_0 = 0U;/* The HVAC Distribution Mode, Vent_0 */
volatile uint8_T u8DIS_MODE_VFD_5 = 5U;/* The HVAC Distribution Mode, Vent/Feet/Defrost_5 */
volatile uint8_T u8DIS_MODE_VF_1 = 1U; /* The HVAC Distribution Mode, Vent/Feet_1 */
volatile uint8_T u8FLAP_POS_0 = 0U;    /* 0% Percent of the Flap position  */
volatile uint8_T u8FLAP_POS_100 = 100U;/* 100% Percent of the Flap position  */
volatile uint8_T u8HVACStatusFB_CMF_MAXAC = 5U;/* HVAC Status is MAX AC */
volatile uint8_T u8HVACStatusFB_CMF_OFF = 3U;/* HVAC Status is Off */
volatile uint8_T u8HVACStatusFB_CMF_OTA = 9U;/* HVAC Status is OTA */
volatile uint8_T u8HVACStatusFB_CMF_VENTILATE = 4U;/* HVAC Status is Ventilate */
volatile uint8_T u8MODE_ACCHILLER_2 = 2U;/* Working mode AC + Chiller 2 */
volatile uint8_T u8MODE_AC_1 = 1U;     /* Working mode AC 1, including the AC-Simple Dehumidity Mode. */
volatile uint8_T u8MODE_CHILLER_3 = 3U;/* Working mode Chiller 3 */
volatile uint8_T u8MODE_FAILURE_31 = 31U;/* Working mode Failure 31,Coolant Loop Failure. */
volatile uint8_T u8MODE_FAILURE_4 = 4U;/* Working mode Failure4,Refrigerant Loop Failure */
volatile uint8_T u8MODE_HP_7 = 7U;     /* Working mode of the HP */
volatile uint8_T u8MODE_HP_BatHeat_10 = 10U;/* Working mode of the HP for Cabin heating and Battery heating */
volatile uint8_T u8MODE_HP_CHILMDCHIL_12 = 12U;/* Working mode of the HP get the Power from Chil and MD Chil */
volatile uint8_T u8MODE_HP_CHIL_8 = 8U;/* Working mode of the HP with Chiller for Battery Cooling */
volatile uint8_T u8MODE_HP_MDCHIL_9 = 9U;/* Working mode of the HP with the Heat Recovery from Motor Driver */
volatile uint8_T u8MODE_HVCH_BAT_21 = 21U;/* Working Mode of HVCH heat the Cabin for heating the Comfortable */
volatile uint8_T u8MODE_HVCH_CMF_20 = 20U;/* Working Mode of HVCH heat the Cabin for heating the Comfortable */
volatile uint8_T u8MODE_HVCH_CMF_BAT_22 = 22U;/* Working Mode of HVCH heat the Cabin for heating the Comfortable */
volatile uint8_T u8MODE_STOP_0 = 0U;   /* Working mode Stop 0 */
volatile uint8_T u8MODE_TotalDehum_18 = 18U;/* Working mode of the Total Dehum 18, self-cycle without outer Evaporator or Condensor */
volatile uint8_T u8MODE_TotalDehum_5 = 5U;/* Working mode of the Total Dehum 5, */
volatile uint8_T u8MODE_TotalDehum_CHIL_6 = 6U;/* Working mode of the Total Dehum 6, the Mode of Total Dehum with Chiller */
volatile uint8_T u8RATIO_PRE_NOR = 13U;/* Pressure Ratio Uplimit */
volatile uint8_T u8SAMPLE_TIME_10 = 10U;/* System smple time for the integer calculation, 10 means the sample time is 0.1s */

/*
 * Output and update for atomic system:
 *    '<Root>/DataTypeConv_b_'
 *    '<Root>/DataTypeConv_b_1'
 *    '<Root>/DataTypeConv_b_10'
 *    '<Root>/DataTypeConv_b_11'
 *    '<Root>/DataTypeConv_b_12'
 *    '<Root>/DataTypeConv_b_13'
 *    '<Root>/DataTypeConv_b_14'
 *    '<Root>/DataTypeConv_b_15'
 *    '<Root>/DataTypeConv_b_16'
 *    '<Root>/DataTypeConv_b_17'
 *    ...
 */
boolean_T Sokon_X01_Thm_DataTypeConv_b_(boolean_T rtu_In1)
{
  /* RelationalOperator: '<S36>/Compare' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S69>/DataTypeConv_s16_'
 *    '<S69>/DataTypeConv_s16_1'
 */
int16_T Sokon_X01_Thm_DataTypeConv_s16_(uint16_T rtu_In1)
{
  int16_T rty_Out1_0;
  int32_T y;

  /* Saturate: '<S75>/Saturation' */
  if (((int32_T)rtu_In1) < 32767) {
    y = (int32_T)rtu_In1;
  } else {
    y = 32767;
  }

  rty_Out1_0 = (int16_T)y;

  /* End of Saturate: '<S75>/Saturation' */
  return rty_Out1_0;
}

/* Output and update for atomic system: '<S71>/DataTypeConv_s16_' */
int16_T Sokon_X01_Thm_DataTypeConv_s16__f(uint8_T rtu_In1)
{
  /* Saturate: '<S77>/Saturation' */
  return (int16_T)rtu_In1;
}

/* Output and update for atomic system: '<S73>/DataTypeConv_s16_' */
int16_T Sokon_X01_Thm_DataTypeConv_s16__h(int16_T rtu_In1)
{
  /* Saturate: '<S79>/Saturation' */
  return rtu_In1;
}

/*
 * Output and update for atomic system:
 *    '<S106>/IfThenElse'
 *    '<S118>/IfThenElse'
 *    '<S130>/IfThenElse'
 *    '<S142>/IfThenElse'
 *    '<S154>/IfThenElse'
 *    '<S166>/IfThenElse'
 *    '<S178>/IfThenElse'
 *    '<S190>/IfThenElse'
 *    '<S202>/IfThenElse'
 *    '<S214>/IfThenElse'
 *    ...
 */
void Sokon_X01_Thm_IfThenElse(boolean_T rtu_bIf, int64m_T rtu_Then, int64m_T
  rtu_Else, int64m_T *rty_Out)
{
  /* Switch: '<S110>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S111>/Conversion' */
    *rty_Out = rtu_Then;
  } else {
    /* DataTypeConversion: '<S111>/Conversion' */
    *rty_Out = rtu_Else;
  }

  /* End of Switch: '<S110>/Switch' */
}

/*
 * Output and update for atomic system:
 *    '<S104>/Divide_Safe'
 *    '<S116>/Divide_Safe'
 *    '<S128>/Divide_Safe'
 *    '<S140>/Divide_Safe'
 *    '<S152>/Divide_Safe'
 *    '<S164>/Divide_Safe'
 *    '<S176>/Divide_Safe'
 *    '<S188>/Divide_Safe'
 *    '<S200>/Divide_Safe'
 *    '<S212>/Divide_Safe'
 *    ...
 */
void Sokon_X01_Thm_Divide_Safe(int64m_T rtu_x, int64m_T rtu_y, int64m_T *rty_out,
  const ConstB_Divide_Safe_Sokon_X01_Thm_T *localC)
{
  int64m_T rtb_Conversion_iv;
  int96m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;

  /* Outputs for Atomic SubSystem: '<S106>/IfThenElse' */

  /* RelationalOperator: '<S108>/Compare' incorporates:
   *  Constant: '<S108>/Constant'
   */
  Sokon_X01_Thm_IfThenElse(sMultiWordNe(&rtu_y.chunks[0U],
    &Sokon_X01_Thm_ConstP.pooled2.chunks[0], 2), rtu_y, localC->Conversion,
    &rtb_Conversion_iv);

  /* End of Outputs for SubSystem: '<S106>/IfThenElse' */

  /* Product: '<S106>/Divide' */
  tmp_0 = rtu_x;
  sMultiWordDivNear(&tmp_0.chunks[0U], 2, &rtb_Conversion_iv.chunks[0U], 2,
                    &tmp.chunks[0U], 3, &tmp_1.chunks[0U], 2, &tmp_2.chunks[0U],
                    2, &tmp_3.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp.chunks[0U], 3, &tmp_0.chunks[0U], 2);
  *rty_out = tmp_0;
}

/*
 * Output and update for atomic system:
 *    '<S107>/IfThenElse'
 *    '<S119>/IfThenElse'
 *    '<S131>/IfThenElse'
 *    '<S143>/IfThenElse'
 *    '<S155>/IfThenElse'
 *    '<S167>/IfThenElse'
 *    '<S179>/IfThenElse'
 *    '<S191>/IfThenElse'
 *    '<S203>/IfThenElse'
 *    '<S215>/IfThenElse'
 *    ...
 */
uint16_T Sokon_X01_Thm_IfThenElse_j(boolean_T rtu_bIf, uint16_T rtu_Then,
  uint16_T rtu_Else)
{
  uint16_T rty_Out_0;

  /* Switch: '<S114>/Switch' */
  if (rtu_bIf) {
    /* DataTypeConversion: '<S115>/Conversion' */
    rty_Out_0 = rtu_Then;
  } else {
    /* DataTypeConversion: '<S115>/Conversion' */
    rty_Out_0 = rtu_Else;
  }

  /* End of Switch: '<S114>/Switch' */
  return rty_Out_0;
}

/*
 * Output and update for atomic system:
 *    '<S104>/Divide_Safe1'
 *    '<S116>/Divide_Safe1'
 *    '<S128>/Divide_Safe1'
 *    '<S140>/Divide_Safe1'
 *    '<S152>/Divide_Safe1'
 *    '<S164>/Divide_Safe1'
 *    '<S176>/Divide_Safe1'
 *    '<S188>/Divide_Safe1'
 *    '<S200>/Divide_Safe1'
 *    '<S212>/Divide_Safe1'
 *    ...
 */
void Sokon_X01_Thm_Divide_Safe1(int64m_T rtu_x, uint16_T rtu_y, int64m_T
  *rty_out, const ConstB_Divide_Safe_Sokon_X01_Thm_j_T *localC)
{
  uint16_T rtb_Conversion_ga;
  int96m_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  int64m_T tmp_4;

  /* Outputs for Atomic SubSystem: '<S107>/IfThenElse' */

  /* RelationalOperator: '<S112>/Compare' incorporates:
   *  Constant: '<S112>/Constant'
   */
  rtb_Conversion_ga = (uint16_T) Sokon_X01_Thm_IfThenElse_j(((int32_T)rtu_y) !=
    0, rtu_y, localC->Conversion);

  /* End of Outputs for SubSystem: '<S107>/IfThenElse' */

  /* Product: '<S107>/Divide' */
  tmp_0 = rtu_x;
  uLong2MultiWord((uint32_T)rtb_Conversion_ga, &tmp_1.chunks[0U], 2);
  sMultiWordDivNear(&tmp_0.chunks[0U], 2, &tmp_1.chunks[0U], 2, &tmp.chunks[0U],
                    3, &tmp_2.chunks[0U], 2, &tmp_3.chunks[0U], 2,
                    &tmp_4.chunks[0U], 2);
  sMultiWord2MultiWord(&tmp.chunks[0U], 3, &tmp_0.chunks[0U], 2);
  *rty_out = tmp_0;
}

/*
 * Output and update for atomic system:
 *    '<S88>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S89>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S90>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S91>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S92>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S93>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S95>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S96>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S97>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S98>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    ...
 */
int16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp(int16_T rtu_DataIn,
  boolean_T rtu_bFlagInit, uint8_T rtu_FilterFactor_INC, uint8_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_T *localDW)
{
  int16_T rty_FilterOut_0;
  int64m_T rtb_Product;
  int64m_T rtb_Divide;
  int64m_T rtb_Switch1;
  int64m_T rtb_Divide_d;
  int32_T tmp;
  int64m_T tmp_0;
  int64m_T tmp_1;
  int96m_T tmp_2;
  int96m_T tmp_3;

  /* Product: '<S104>/Product' */
  sLong2MultiWord(((int32_T)rtu_DataIn) * ((int32_T)rtu_u16AmpNumVal),
                  &tmp_0.chunks[0U], 2);
  sMultiWordShl(&tmp_0.chunks[0U], 2, 16U, &rtb_Product.chunks[0U], 2);

  /* UnitDelay: '<S104>/UnitDelay1' */
  rtb_Divide = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S104>/Switch1' incorporates:
   *  RelationalOperator: '<S104>/Relational Operator'
   *  UnitDelay: '<S104>/UnitDelay2'
   */
  if (rtu_DataIn > localDW->UnitDelay2_DSTATE) {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_INC) << 16, &rtb_Switch1.chunks
                    [0U], 2);
  } else {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_DEC) << 16, &rtb_Switch1.chunks
                    [0U], 2);
  }

  /* End of Switch: '<S104>/Switch1' */

  /* Sum: '<S104>/Subtract1' incorporates:
   *  UnitDelay: '<S104>/UnitDelay1'
   */
  tmp_0 = localDW->UnitDelay1_DSTATE;
  MultiWordSub(&rtb_Product.chunks[0U], &tmp_0.chunks[0U], &tmp_1.chunks[0U], 2);

  /* Outputs for Atomic SubSystem: '<S104>/Divide_Safe' */
  Sokon_X01_Thm_Divide_Safe(tmp_1, rtb_Switch1, &rtb_Divide_d,
    &localC->Divide_Safe);

  /* End of Outputs for SubSystem: '<S104>/Divide_Safe' */

  /* Switch: '<S104>/Switch' incorporates:
   *  UnitDelay: '<S104>/UnitDelay1'
   */
  if (rtu_bFlagInit) {
    localDW->UnitDelay1_DSTATE = rtb_Product;
  } else {
    /* Sum: '<S104>/Add1' incorporates:
     *  UnitDelay: '<S104>/UnitDelay1'
     */
    sMultiWord2MultiWord(&rtb_Divide_d.chunks[0U], 2, &tmp_3.chunks[0U], 3);
    sMultiWordShl(&tmp_3.chunks[0U], 3, 16U, &tmp_2.chunks[0U], 3);
    sMultiWord2MultiWord(&tmp_2.chunks[0U], 3, &tmp_0.chunks[0U], 2);
    MultiWordAdd(&tmp_0.chunks[0U], &rtb_Divide.chunks[0U],
                 &localDW->UnitDelay1_DSTATE.chunks[0U], 2);
  }

  /* End of Switch: '<S104>/Switch' */

  /* Outputs for Atomic SubSystem: '<S104>/Divide_Safe1' */
  /* UnitDelay: '<S104>/UnitDelay1' */
  Sokon_X01_Thm_Divide_Safe1(localDW->UnitDelay1_DSTATE, rtu_u16AmpNumVal,
    &rtb_Divide, &localC->Divide_Safe1);

  /* End of Outputs for SubSystem: '<S104>/Divide_Safe1' */

  /* DataTypeConversion: '<S105>/Conversion' */
  sMultiWordShrNear(&rtb_Divide.chunks[0U], 2, 16U, &tmp_0.chunks[0U], 2);
  tmp = sMultiWord2sLongSat(&tmp_0.chunks[0U], 2);
  if (tmp > 32767) {
    tmp = 32767;
  } else {
    if (tmp < -32768) {
      tmp = -32768;
    }
  }

  rty_FilterOut_0 = (int16_T)tmp;

  /* Update for UnitDelay: '<S104>/UnitDelay2' incorporates:
   *  DataTypeConversion: '<S105>/Conversion'
   */
  localDW->UnitDelay2_DSTATE = (int16_T)tmp;
  return rty_FilterOut_0;
}

/*
 * Output and update for atomic system:
 *    '<S82>/FirOrderLinear_Filter'
 *    '<S82>/FirOrderLinear_Filter1'
 *    '<S82>/FirOrderLinear_Filter10'
 *    '<S82>/FirOrderLinear_Filter11'
 *    '<S82>/FirOrderLinear_Filter12'
 *    '<S82>/FirOrderLinear_Filter13'
 *    '<S82>/FirOrderLinear_Filter3'
 *    '<S82>/FirOrderLinear_Filter4'
 *    '<S82>/FirOrderLinear_Filter5'
 *    '<S82>/FirOrderLinear_Filter6'
 *    ...
 */
int16_T Sokon_X01_Thm_FirOrderLinear_Filter(int16_T rtu_DataIn, boolean_T
  rtu_bFlagInit, uint8_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Thm_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Thm_T *localDW, uint16_T rtp_AmpNumVal)
{
  int16_T rty_FilterOut_0;

  /* Outputs for Atomic SubSystem: '<S88>/FirOrderLinear_Filter_DoubleFactor_Amp' */

  /* SignalConversion: '<S88>/TmpSignal ConversionAtFirOrderLinear_Filter_DoubleFactor_AmpInport3' incorporates:
   *  Constant: '<S88>/Constant1'
   */
  rty_FilterOut_0 = (int16_T)
    Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp(rtu_DataIn,
    rtu_bFlagInit, rtu_FilterFactor, rtu_FilterFactor, rtp_AmpNumVal,
    &localC->FirOrderLinear_Filter_DoubleFactor_Amp,
    &localDW->FirOrderLinear_Filter_DoubleFactor_Amp);

  /* End of Outputs for SubSystem: '<S88>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  return rty_FilterOut_0;
}

/*
 * Output and update for atomic system:
 *    '<S94>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S309>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S310>/FirOrderLinear_Filter_DoubleFactor_Amp'
 */
uint16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp_i(uint16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, uint8_T rtu_FilterFactor_INC, uint8_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_l_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_l_T *localDW)
{
  uint16_T rty_FilterOut_0;
  int64m_T rtb_Product;
  int64m_T rtb_Divide;
  int64m_T rtb_Switch1;
  int64m_T rtb_Divide_o;
  uint32_T tmp;
  uint64m_T tmp_0;
  uint64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  int96m_T tmp_4;
  int96m_T tmp_5;

  /* Product: '<S176>/Product' */
  uLong2MultiWord(((uint32_T)rtu_DataIn) * ((uint32_T)rtu_u16AmpNumVal),
                  &tmp_1.chunks[0U], 2);
  uMultiWordShl(&tmp_1.chunks[0U], 2, 16U, &tmp_0.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_0.chunks[0U], 2, &rtb_Product.chunks[0U], 2);

  /* UnitDelay: '<S176>/UnitDelay1' */
  rtb_Divide = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S176>/Switch1' incorporates:
   *  RelationalOperator: '<S176>/Relational Operator'
   *  UnitDelay: '<S176>/UnitDelay2'
   */
  if (rtu_DataIn > localDW->UnitDelay2_DSTATE) {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_INC) << 16, &rtb_Switch1.chunks
                    [0U], 2);
  } else {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_DEC) << 16, &rtb_Switch1.chunks
                    [0U], 2);
  }

  /* End of Switch: '<S176>/Switch1' */

  /* Sum: '<S176>/Subtract1' incorporates:
   *  UnitDelay: '<S176>/UnitDelay1'
   */
  tmp_2 = localDW->UnitDelay1_DSTATE;
  MultiWordSub(&rtb_Product.chunks[0U], &tmp_2.chunks[0U], &tmp_3.chunks[0U], 2);

  /* Outputs for Atomic SubSystem: '<S176>/Divide_Safe' */
  Sokon_X01_Thm_Divide_Safe(tmp_3, rtb_Switch1, &rtb_Divide_o,
    &localC->Divide_Safe);

  /* End of Outputs for SubSystem: '<S176>/Divide_Safe' */

  /* Switch: '<S176>/Switch' incorporates:
   *  UnitDelay: '<S176>/UnitDelay1'
   */
  if (rtu_bFlagInit) {
    localDW->UnitDelay1_DSTATE = rtb_Product;
  } else {
    /* Sum: '<S176>/Add1' incorporates:
     *  UnitDelay: '<S176>/UnitDelay1'
     */
    sMultiWord2MultiWord(&rtb_Divide_o.chunks[0U], 2, &tmp_5.chunks[0U], 3);
    sMultiWordShl(&tmp_5.chunks[0U], 3, 16U, &tmp_4.chunks[0U], 3);
    sMultiWord2MultiWord(&tmp_4.chunks[0U], 3, &tmp_2.chunks[0U], 2);
    MultiWordAdd(&tmp_2.chunks[0U], &rtb_Divide.chunks[0U],
                 &localDW->UnitDelay1_DSTATE.chunks[0U], 2);
  }

  /* End of Switch: '<S176>/Switch' */

  /* Outputs for Atomic SubSystem: '<S176>/Divide_Safe1' */
  /* UnitDelay: '<S176>/UnitDelay1' */
  Sokon_X01_Thm_Divide_Safe1(localDW->UnitDelay1_DSTATE, rtu_u16AmpNumVal,
    &rtb_Divide, &localC->Divide_Safe1);

  /* End of Outputs for SubSystem: '<S176>/Divide_Safe1' */

  /* DataTypeConversion: '<S177>/Conversion' */
  sMultiWordShrNear(&rtb_Divide.chunks[0U], 2, 16U, &tmp_2.chunks[0U], 2);
  tmp = sMultiWord2uLongSat(&tmp_2.chunks[0U], 2);
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  rty_FilterOut_0 = (uint16_T)tmp;

  /* Update for UnitDelay: '<S176>/UnitDelay2' incorporates:
   *  DataTypeConversion: '<S177>/Conversion'
   */
  localDW->UnitDelay2_DSTATE = (uint16_T)tmp;
  return rty_FilterOut_0;
}

/*
 * Output and update for atomic system:
 *    '<S82>/FirOrderLinear_Filter2'
 *    '<S84>/FirOrderLinear_Filter1'
 *    '<S84>/FirOrderLinear_Filter2'
 */
uint16_T Sokon_X01_Thm_FirOrderLinear_Filter2(uint16_T rtu_DataIn, boolean_T
  rtu_bFlagInit, uint8_T rtu_FilterFactor, const
  ConstB_FirOrderLinear_Filter_Sokon_X01_Thm_n_T *localC,
  DW_FirOrderLinear_Filter_Sokon_X01_Thm_o_T *localDW, uint16_T rtp_AmpNumVal)
{
  uint16_T rty_FilterOut_0;

  /* Outputs for Atomic SubSystem: '<S94>/FirOrderLinear_Filter_DoubleFactor_Amp' */

  /* SignalConversion: '<S94>/TmpSignal ConversionAtFirOrderLinear_Filter_DoubleFactor_AmpInport3' incorporates:
   *  Constant: '<S94>/Constant1'
   */
  rty_FilterOut_0 = (uint16_T)
    Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp_i(rtu_DataIn,
    rtu_bFlagInit, rtu_FilterFactor, rtu_FilterFactor, rtp_AmpNumVal,
    &localC->FirOrderLinear_Filter_DoubleFactor_Amp,
    &localDW->FirOrderLinear_Filter_DoubleFactor_Amp);

  /* End of Outputs for SubSystem: '<S94>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  return rty_FilterOut_0;
}

/*
 * Output and update for atomic system:
 *    '<S102>/FirOrderLinear_Filter_DoubleFactor_Amp'
 *    '<S103>/FirOrderLinear_Filter_DoubleFactor_Amp'
 */
uint16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp_c(uint16_T
  rtu_DataIn, boolean_T rtu_bFlagInit, uint16_T rtu_FilterFactor_INC, uint16_T
  rtu_FilterFactor_DEC, uint16_T rtu_u16AmpNumVal, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_h_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Amp_Sokon_X01_Thm_e_T *localDW)
{
  uint16_T rty_FilterOut_0;
  int64m_T rtb_Product;
  int64m_T rtb_Divide;
  int64m_T rtb_Switch1;
  int64m_T rtb_Divide_g;
  uint32_T tmp;
  uint64m_T tmp_0;
  uint64m_T tmp_1;
  int64m_T tmp_2;
  int64m_T tmp_3;
  int96m_T tmp_4;
  int96m_T tmp_5;

  /* Product: '<S272>/Product' */
  uLong2MultiWord(((uint32_T)rtu_DataIn) * ((uint32_T)rtu_u16AmpNumVal),
                  &tmp_1.chunks[0U], 2);
  uMultiWordShl(&tmp_1.chunks[0U], 2, 16U, &tmp_0.chunks[0U], 2);
  uMultiWord2MultiWord(&tmp_0.chunks[0U], 2, &rtb_Product.chunks[0U], 2);

  /* UnitDelay: '<S272>/UnitDelay1' */
  rtb_Divide = localDW->UnitDelay1_DSTATE;

  /* Switch: '<S272>/Switch1' incorporates:
   *  RelationalOperator: '<S272>/Relational Operator'
   *  UnitDelay: '<S272>/UnitDelay2'
   */
  if (rtu_DataIn > localDW->UnitDelay2_DSTATE) {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_INC) << 16, &rtb_Switch1.chunks
                    [0U], 2);
  } else {
    uLong2MultiWord(((uint32_T)rtu_FilterFactor_DEC) << 16, &rtb_Switch1.chunks
                    [0U], 2);
  }

  /* End of Switch: '<S272>/Switch1' */

  /* Sum: '<S272>/Subtract1' incorporates:
   *  UnitDelay: '<S272>/UnitDelay1'
   */
  tmp_2 = localDW->UnitDelay1_DSTATE;
  MultiWordSub(&rtb_Product.chunks[0U], &tmp_2.chunks[0U], &tmp_3.chunks[0U], 2);

  /* Outputs for Atomic SubSystem: '<S272>/Divide_Safe' */
  Sokon_X01_Thm_Divide_Safe(tmp_3, rtb_Switch1, &rtb_Divide_g,
    &localC->Divide_Safe);

  /* End of Outputs for SubSystem: '<S272>/Divide_Safe' */

  /* Switch: '<S272>/Switch' incorporates:
   *  UnitDelay: '<S272>/UnitDelay1'
   */
  if (rtu_bFlagInit) {
    localDW->UnitDelay1_DSTATE = rtb_Product;
  } else {
    /* Sum: '<S272>/Add1' incorporates:
     *  UnitDelay: '<S272>/UnitDelay1'
     */
    sMultiWord2MultiWord(&rtb_Divide_g.chunks[0U], 2, &tmp_5.chunks[0U], 3);
    sMultiWordShl(&tmp_5.chunks[0U], 3, 16U, &tmp_4.chunks[0U], 3);
    sMultiWord2MultiWord(&tmp_4.chunks[0U], 3, &tmp_2.chunks[0U], 2);
    MultiWordAdd(&tmp_2.chunks[0U], &rtb_Divide.chunks[0U],
                 &localDW->UnitDelay1_DSTATE.chunks[0U], 2);
  }

  /* End of Switch: '<S272>/Switch' */

  /* Outputs for Atomic SubSystem: '<S272>/Divide_Safe1' */
  /* UnitDelay: '<S272>/UnitDelay1' */
  Sokon_X01_Thm_Divide_Safe1(localDW->UnitDelay1_DSTATE, rtu_u16AmpNumVal,
    &rtb_Divide, &localC->Divide_Safe1);

  /* End of Outputs for SubSystem: '<S272>/Divide_Safe1' */

  /* DataTypeConversion: '<S273>/Conversion' */
  sMultiWordShrNear(&rtb_Divide.chunks[0U], 2, 16U, &tmp_2.chunks[0U], 2);
  tmp = sMultiWord2uLongSat(&tmp_2.chunks[0U], 2);
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  rty_FilterOut_0 = (uint16_T)tmp;

  /* Update for UnitDelay: '<S272>/UnitDelay2' incorporates:
   *  DataTypeConversion: '<S273>/Conversion'
   */
  localDW->UnitDelay2_DSTATE = (uint16_T)tmp;
  return rty_FilterOut_0;
}

/*
 * Output and update for atomic system:
 *    '<S82>/FirOrderLinear_Filter_DoubleFactor'
 *    '<S82>/FirOrderLinear_Filter_DoubleFactor1'
 */
uint16_T Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor(uint16_T rtu_DataIn,
  boolean_T rtu_bFlagInit, uint16_T rtu_FilterFactor_INC, uint16_T
  rtu_FilterFactor_DEC, const
  ConstB_FirOrderLinear_Filter_DoubleFactor_Sokon_X01_Thm_T *localC,
  DW_FirOrderLinear_Filter_DoubleFactor_Sokon_X01_Thm_T *localDW, uint16_T
  rtp_AmpNumVal)
{
  uint16_T rty_FilterOut_0;

  /* Outputs for Atomic SubSystem: '<S102>/FirOrderLinear_Filter_DoubleFactor_Amp' */

  /* Constant: '<S102>/Constant1' */
  rty_FilterOut_0 = (uint16_T)
    Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor_Amp_c(rtu_DataIn,
    rtu_bFlagInit, rtu_FilterFactor_INC, rtu_FilterFactor_DEC, rtp_AmpNumVal,
    &localC->FirOrderLinear_Filter_DoubleFactor_Amp,
    &localDW->FirOrderLinear_Filter_DoubleFactor_Amp);

  /* End of Outputs for SubSystem: '<S102>/FirOrderLinear_Filter_DoubleFactor_Amp' */
  return rty_FilterOut_0;
}

/* Model step function */
void Sokon_X01_Thm_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_THM_In_u16Tset_Left_A10;
  uint16_T rtb_THM_In_u16Tset_Right_A10;
  uint16_T rtb_THM_In_u16Tset_3Z_A10;
  uint16_T rtb_THM_In_u16Tset_4Z_A10;
  uint16_T rtb_THM_In_u16EXV_Eva_Pos;
  uint16_T rtb_THM_In_u16Rainfall;
  uint16_T rtb_THM_In_u16Solar;
  uint16_T rtb_THM_In_u16Pump_HVCH;
  uint16_T rtb_THM_In_u16Pump_Motor;
  uint16_T rtb_Conversion;
  uint16_T rtb_Conversion_f;
  uint16_T rtb_Conversion_k;
  uint16_T rtb_Conversion_kx;
  uint16_T rtb_Conversion_e;
  uint16_T rtb_THM_In_u16Power_Max;
  uint16_T rtb_THM_In_u16Ncomp_Max;
  uint16_T rtb_THM_In_u16EXV_Chil_Pos;
  uint16_T rtb_THM_In_u16Pump_Bat;
  uint16_T rtb_THM_In_u16PowerComp;
  uint16_T rtb_THM_In_u16Ncomp;
  uint16_T rtb_IC81;
  int16_T rtb_Conversion_n;
  int16_T rtb_Conversion_b;
  int16_T rtb_Conversion_m;
  int16_T rtb_Conversion_l;
  int16_T rtb_Conversion_ky;
  int16_T rtb_Conversion_mn;
  int16_T rtb_Conversion_kr;
  int16_T rtb_Conversion_h;
  int16_T rtb_Conversion_ej;
  int16_T rtb_Conversion_g;
  int16_T rtb_Conversion_gi;
  int16_T rtb_Conversion_c;
  int16_T rtb_Conversion_he;
  int16_T rtb_Conversion_nb;
  int16_T rtb_Conversion_gl;
  int16_T rtb_Conversion_f2;
  int16_T rtb_Conversion_np;
  int16_T rtb_Conversion_i;
  int16_T rtb_Conversion_b5;
  int16_T rtb_Conversion_d;
  int16_T rtb_Conversion_o;
  int16_T rtb_Conversion_g4;
  int16_T rtb_Saturation;
  int16_T rtb_Saturation_f;
  int16_T rtb_Saturation_i;
  int16_T rtb_THM_In_s16Tamb_A10;
  int16_T rtb_THM_In_s16T_Ref_EDCOut_A10;
  int16_T rtb_IC72;
  uint8_T rtb_THM_In_u8Mix_Flap_Position_L;
  uint8_T rtb_THM_In_u8BlwVol_Real_A10;
  uint8_T rtb_THM_In_u8ModeMASts_2Z;
  uint8_T rtb_THM_In_u8ModeMASts_3Z;
  uint8_T rtb_THM_In_u8ModeMASts_4Z;
  uint8_T rtb_THM_In_u8BlwLv_Real;
  uint8_T rtb_THM_In_u8RearBlwVol_Real_A10;
  uint8_T rtb_THM_In_u8ModeStatus_2Z_Real;
  uint8_T rtb_THM_In_u8ModeStatus_3Z_Real;
  uint8_T rtb_THM_In_u8ModeStatus_4Z_Real;
  uint8_T rtb_THM_In_u8ECM_Engine_Status;
  uint8_T rtb_THM_In_u8BlwMASts_2Z;
  uint8_T rtb_THM_In_u8Mix_Flap_Position_R;
  uint8_T rtb_THM_In_u8BlwMASts_3Z;
  uint8_T rtb_THM_In_u8TWValve_HC_Position;
  uint8_T rtb_THM_In_u8TWValve_LTR_Position;
  uint8_T rtb_THM_In_u8TWValve_BAT_Position;
  uint8_T rtb_THM_In_u8HVCH_Status;
  uint8_T rtb_THM_In_u8BlwMASts_4Z;
  uint8_T rtb_THM_In_u8BlwUserHabit;
  uint8_T rtb_THM_In_u8BlwMASts;
  uint8_T rtb_THM_In_u8ModeStatus_Real;
  uint8_T rtb_THM_In_u8VehSpd;
  uint8_T rtb_THM_In_u8IgnSts;
  uint8_T rtb_THM_In_u8Mot_CoolLv;
  uint8_T rtb_THM_In_u8AGS_Position;
  uint8_T rtb_THM_In_u8BAT_CoolHeatLv;
  uint8_T rtb_IC9;
  boolean_T rtb_Compare_e;
  boolean_T rtb_Compare_l;
  boolean_T rtb_Compare_d;
  boolean_T rtb_Compare_p;
  boolean_T rtb_Compare_m;
  boolean_T rtb_Compare_b;
  boolean_T rtb_Compare_ma;
  boolean_T rtb_Compare_i;
  boolean_T rtb_Compare_py;
  boolean_T rtb_Compare_dz;
  boolean_T rtb_Compare_mn;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_a;
  boolean_T rtb_Compare_ie;
  boolean_T rtb_Compare_ay;
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare_ed;
  boolean_T rtb_Compare_fd;
  boolean_T rtb_Compare_m5;
  boolean_T rtb_Compare_n;
  boolean_T rtb_Compare_cs;
  boolean_T rtb_Compare_j;
  boolean_T rtb_Compare_lb;
  boolean_T rtb_Compare_m0;
  boolean_T rtb_Compare_l4;
  boolean_T rtb_Compare_o;
  boolean_T rtb_Compare_h;
  boolean_T rtb_IC4;
  uint8_T rtb_u8CmfSwRunSts;
  boolean_T rtb_IC42;
  int32_T tmp;
  int16_T y;
  uint16_T y_0;

  /* InitialCondition: '<Root>/IC' incorporates:
   *  Inport: '<Root>/THM_In_u16Tset_Left_A10'
   */
  if (Sokon_X01_Thm_DW.IC_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC_FirstOutputTime = false;
    rtb_THM_In_u16Ncomp = 240U;
  } else {
    rtb_THM_In_u16Ncomp = Sokon_X01_Thm_U.THM_In_u16Tset_Left_A10;
  }

  /* End of InitialCondition: '<Root>/IC' */

  /* Saturate: '<Root>/Saturation' */
  if (((int32_T)rtb_THM_In_u16Ncomp) > 330) {
    rtb_THM_In_u16Tset_Left_A10 = 330U;
  } else if (((int32_T)rtb_THM_In_u16Ncomp) < 180) {
    rtb_THM_In_u16Tset_Left_A10 = 180U;
  } else {
    rtb_THM_In_u16Tset_Left_A10 = rtb_THM_In_u16Ncomp;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* InitialCondition: '<Root>/IC1' incorporates:
   *  Inport: '<Root>/THM_In_u16Tset_Right_A10'
   */
  if (Sokon_X01_Thm_DW.IC1_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC1_FirstOutputTime = false;
    rtb_THM_In_u16Ncomp = 240U;
  } else {
    rtb_THM_In_u16Ncomp = Sokon_X01_Thm_U.THM_In_u16Tset_Right_A10;
  }

  /* End of InitialCondition: '<Root>/IC1' */

  /* Saturate: '<Root>/Saturation1' */
  if (((int32_T)rtb_THM_In_u16Ncomp) > 330) {
    rtb_THM_In_u16Tset_Right_A10 = 330U;
  } else if (((int32_T)rtb_THM_In_u16Ncomp) < 180) {
    rtb_THM_In_u16Tset_Right_A10 = 180U;
  } else {
    rtb_THM_In_u16Tset_Right_A10 = rtb_THM_In_u16Ncomp;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* InitialCondition: '<Root>/IC4' incorporates:
   *  Inport: '<Root>/THM_In_bAcSts'
   */
  if (Sokon_X01_Thm_DW.IC4_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC4_FirstOutputTime = false;
    rtb_IC4 = false;
  } else {
    rtb_IC4 = Sokon_X01_Thm_U.THM_In_bAcSts;
  }

  /* End of InitialCondition: '<Root>/IC4' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_' */
  rtb_Compare_l4 = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC4) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_' */

  /* InitialCondition: '<Root>/IC5' incorporates:
   *  Inport: '<Root>/THM_In_u8BlwMASts'
   */
  if (Sokon_X01_Thm_DW.IC5_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC5_FirstOutputTime = false;
    rtb_THM_In_u8BlwMASts = 0U;
  } else {
    rtb_THM_In_u8BlwMASts = Sokon_X01_Thm_U.THM_In_u8BlwMASts;
  }

  /* End of InitialCondition: '<Root>/IC5' */

  /* Saturate: '<Root>/Saturation4' */
  if (((int32_T)rtb_THM_In_u8BlwMASts) >= 15) {
    rtb_THM_In_u8BlwMASts = 15U;
  }

  /* End of Saturate: '<Root>/Saturation4' */

  /* InitialCondition: '<Root>/IC10' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeMASts'
   */
  if (Sokon_X01_Thm_DW.IC10_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC10_FirstOutputTime = false;
    rtb_THM_In_u8Mot_CoolLv = 0U;
  } else {
    rtb_THM_In_u8Mot_CoolLv = Sokon_X01_Thm_U.THM_In_u8ModeMASts;
  }

  /* End of InitialCondition: '<Root>/IC10' */

  /* Saturate: '<Root>/Saturation9' */
  if (((int32_T)rtb_THM_In_u8Mot_CoolLv) >= 7) {
    rtb_THM_In_u8Mot_CoolLv = 7U;
  }

  /* End of Saturate: '<Root>/Saturation9' */

  /* InitialCondition: '<Root>/IC14' incorporates:
   *  Inport: '<Root>/THM_In_u8IntakeMASts'
   */
  if (Sokon_X01_Thm_DW.IC14_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC14_FirstOutputTime = false;
    rtb_THM_In_u8BAT_CoolHeatLv = 0U;
  } else {
    rtb_THM_In_u8BAT_CoolHeatLv = Sokon_X01_Thm_U.THM_In_u8IntakeMASts;
  }

  /* End of InitialCondition: '<Root>/IC14' */

  /* Saturate: '<Root>/Saturation13' */
  if (((int32_T)rtb_THM_In_u8BAT_CoolHeatLv) >= 3) {
    rtb_THM_In_u8BAT_CoolHeatLv = 3U;
  }

  /* End of Saturate: '<Root>/Saturation13' */

  /* Outputs for Atomic SubSystem: '<S73>/JudgeFlag_Sensor_Ready' */
  /* Chart: '<S81>/Sensor_Prepare_Delay' */
  if (((int32_T)Sokon_X01_Thm_DW.u16COUNT_Sensor_Delay) >= 30) {
    rtb_IC4 = true;
  } else {
    rtb_IC4 = false;
    tmp = ((int32_T)Sokon_X01_Thm_DW.u16COUNT_Sensor_Delay) + 1;
    if (tmp > 65535) {
      tmp = 65535;
    }

    Sokon_X01_Thm_DW.u16COUNT_Sensor_Delay = (uint16_T)tmp;
  }

  /* End of Chart: '<S81>/Sensor_Prepare_Delay' */
  /* End of Outputs for SubSystem: '<S73>/JudgeFlag_Sensor_Ready' */

  /* Outputs for Atomic SubSystem: '<S73>/JudgeFirstIGN' */
  /* Chart: '<S80>/JudgeSWFirstRun' incorporates:
   *  UnitDelay: '<S80>/Unit Delay'
   *
   * Block description for '<S80>/JudgeSWFirstRun':
   *  Judge_first_GetVol
   */
  /* get first IGN ON */
  if (rtb_IC4) {
    /* SW after 3s */
    if (!Sokon_X01_Thm_DW.UnitDelay_DSTATE) {
      rtb_u8CmfSwRunSts = SEN_u8CMFSW_FIRST_2;

      /* SW check first, status is 2 */
    } else {
      rtb_u8CmfSwRunSts = SEN_u8CMFSW_READY_1;

      /* SW check ok, status is 1 */
    }
  } else {
    rtb_u8CmfSwRunSts = SEN_u8CMFSW_INIT_0;

    /* SW check inital,status is 0 */
  }

  /* End of Chart: '<S80>/JudgeSWFirstRun' */

  /* Update for UnitDelay: '<S80>/Unit Delay' */
  Sokon_X01_Thm_DW.UnitDelay_DSTATE = rtb_IC4;

  /* End of Outputs for SubSystem: '<S73>/JudgeFirstIGN' */

  /* InitialCondition: '<Root>/IC17' incorporates:
   *  Inport: '<Root>/THM_In_u16P_Ref_CondOut_A10'
   */
  if (Sokon_X01_Thm_DW.IC17_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC17_FirstOutputTime = false;
    rtb_THM_In_u16Ncomp = 150U;
  } else {
    rtb_THM_In_u16Ncomp = Sokon_X01_Thm_U.THM_In_u16P_Ref_CondOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC17' */

  /* RelationalOperator: '<S78>/Compare' incorporates:
   *  Constant: '<S78>/Constant'
   */
  rtb_IC4 = (((int32_T)rtb_u8CmfSwRunSts) == 0);

  /* Saturate: '<Root>/Saturation16' */
  if (((int32_T)rtb_THM_In_u16Ncomp) < 400) {
    y_0 = rtb_THM_In_u16Ncomp;
  } else {
    y_0 = 400U;
  }

  /* End of Saturate: '<Root>/Saturation16' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter2' */
  /* Constant: '<S82>/Constant3' */
  rtb_Conversion_e = (uint16_T) Sokon_X01_Thm_FirOrderLinear_Filter2(y_0,
    rtb_IC4, CmfThm_u8Filter_2s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter2,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter2, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter2' */

  /* InitialCondition: '<Root>/IC18' incorporates:
   *  Inport: '<Root>/THM_In_u16Sun_L'
   */
  if (Sokon_X01_Thm_DW.IC18_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC18_FirstOutputTime = false;
    rtb_THM_In_u16Ncomp = 0U;
  } else {
    rtb_THM_In_u16Ncomp = Sokon_X01_Thm_U.THM_In_u16Sun_L;
  }

  /* End of InitialCondition: '<Root>/IC18' */

  /* Saturate: '<Root>/Saturation17' */
  if (((int32_T)rtb_THM_In_u16Ncomp) < 1275) {
    y_0 = rtb_THM_In_u16Ncomp;
  } else {
    y_0 = 1275U;
  }

  /* End of Saturate: '<Root>/Saturation17' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter_DoubleFactor' */
  /* Constant: '<S82>/Constant5' incorporates:
   *  Constant: '<S82>/Constant6'
   */
  rtb_Conversion_kx = (uint16_T)
    Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor(y_0, rtb_IC4,
    CmfThm_u16Sun_IncNum_Filter, CmfThm_u16Sun_DecNum_Filter,
    &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter_DoubleFactor,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter_DoubleFactor, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter_DoubleFactor' */

  /* InitialCondition: '<Root>/IC19' incorporates:
   *  Inport: '<Root>/THM_In_u16Sun_R'
   */
  if (Sokon_X01_Thm_DW.IC19_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC19_FirstOutputTime = false;
    rtb_THM_In_u16Ncomp = 0U;
  } else {
    rtb_THM_In_u16Ncomp = Sokon_X01_Thm_U.THM_In_u16Sun_R;
  }

  /* End of InitialCondition: '<Root>/IC19' */

  /* Saturate: '<Root>/Saturation18' */
  if (((int32_T)rtb_THM_In_u16Ncomp) < 1275) {
    y_0 = rtb_THM_In_u16Ncomp;
  } else {
    y_0 = 1275U;
  }

  /* End of Saturate: '<Root>/Saturation18' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter_DoubleFactor1' */
  /* Constant: '<S82>/Constant7' incorporates:
   *  Constant: '<S82>/Constant8'
   */
  rtb_Conversion_k = (uint16_T) Sokon_X01_Thm_FirOrderLinear_Filter_DoubleFactor
    (y_0, rtb_IC4, CmfThm_u16Sun_IncNum_Filter, CmfThm_u16Sun_DecNum_Filter,
     &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter_DoubleFactor1,
     &Sokon_X01_Thm_DW.FirOrderLinear_Filter_DoubleFactor1, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter_DoubleFactor1' */

  /* InitialCondition: '<Root>/IC20' incorporates:
   *  Inport: '<Root>/THM_In_s16Tamb_A10'
   */
  if (Sokon_X01_Thm_DW.IC20_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC20_FirstOutputTime = false;
    rtb_THM_In_s16Tamb_A10 = 200;
  } else {
    rtb_THM_In_s16Tamb_A10 = Sokon_X01_Thm_U.THM_In_s16Tamb_A10;
  }

  /* End of InitialCondition: '<Root>/IC20' */

  /* Saturate: '<Root>/Saturation19' */
  if (rtb_THM_In_s16Tamb_A10 > 1500) {
    rtb_THM_In_s16Tamb_A10 = 1500;
  } else {
    if (rtb_THM_In_s16Tamb_A10 < -500) {
      rtb_THM_In_s16Tamb_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation19' */

  /* InitialCondition: '<Root>/IC21' incorporates:
   *  Inport: '<Root>/THM_In_s16Tincar_Front_A10'
   */
  if (Sokon_X01_Thm_DW.IC21_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC21_FirstOutputTime = false;
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 200;
  } else {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = Sokon_X01_Thm_U.THM_In_s16Tincar_Front_A10;
  }

  /* End of InitialCondition: '<Root>/IC21' */

  /* Saturate: '<Root>/Saturation20' */
  if (rtb_THM_In_s16T_Ref_EDCOut_A10 > 1500) {
    y = 1500;
  } else if (rtb_THM_In_s16T_Ref_EDCOut_A10 < -500) {
    y = -500;
  } else {
    y = rtb_THM_In_s16T_Ref_EDCOut_A10;
  }

  /* End of Saturate: '<Root>/Saturation20' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter3' */
  /* Constant: '<S82>/Constant4' */
  rtb_Conversion_f2 = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_15s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter3,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter3, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter3' */

  /* InitialCondition: '<Root>/IC24' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_LV_A10'
   */
  if (Sokon_X01_Thm_DW.IC24_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC24_FirstOutputTime = false;
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 200;
  } else {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = Sokon_X01_Thm_U.THM_In_s16TDuct_LV_A10;
  }

  /* End of InitialCondition: '<Root>/IC24' */

  /* Saturate: '<Root>/Saturation23' */
  if (rtb_THM_In_s16T_Ref_EDCOut_A10 > 1500) {
    y = 1500;
  } else if (rtb_THM_In_s16T_Ref_EDCOut_A10 < -500) {
    y = -500;
  } else {
    y = rtb_THM_In_s16T_Ref_EDCOut_A10;
  }

  /* End of Saturate: '<Root>/Saturation23' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter6' */
  /* Constant: '<S82>/Constant11' */
  rtb_Conversion_he = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter6,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter6, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter6' */

  /* InitialCondition: '<Root>/IC25' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_LF_A10'
   */
  if (Sokon_X01_Thm_DW.IC25_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC25_FirstOutputTime = false;
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 200;
  } else {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = Sokon_X01_Thm_U.THM_In_s16TDuct_LF_A10;
  }

  /* End of InitialCondition: '<Root>/IC25' */

  /* Saturate: '<Root>/Saturation24' */
  if (rtb_THM_In_s16T_Ref_EDCOut_A10 > 1500) {
    y = 1500;
  } else if (rtb_THM_In_s16T_Ref_EDCOut_A10 < -500) {
    y = -500;
  } else {
    y = rtb_THM_In_s16T_Ref_EDCOut_A10;
  }

  /* End of Saturate: '<Root>/Saturation24' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter7' */
  /* Constant: '<S82>/Constant12' */
  rtb_Conversion_c = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter7,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter7, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter7' */

  /* InitialCondition: '<Root>/IC26' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_RV_A10'
   */
  if (Sokon_X01_Thm_DW.IC26_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC26_FirstOutputTime = false;
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 200;
  } else {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = Sokon_X01_Thm_U.THM_In_s16TDuct_RV_A10;
  }

  /* End of InitialCondition: '<Root>/IC26' */

  /* Saturate: '<Root>/Saturation25' */
  if (rtb_THM_In_s16T_Ref_EDCOut_A10 > 1500) {
    y = 1500;
  } else if (rtb_THM_In_s16T_Ref_EDCOut_A10 < -500) {
    y = -500;
  } else {
    y = rtb_THM_In_s16T_Ref_EDCOut_A10;
  }

  /* End of Saturate: '<Root>/Saturation25' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter8' */
  /* Constant: '<S82>/Constant13' */
  rtb_Conversion_gi = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter8,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter8, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter8' */

  /* InitialCondition: '<Root>/IC35' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeStatus_Real'
   */
  if (Sokon_X01_Thm_DW.IC35_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC35_FirstOutputTime = false;
    rtb_THM_In_u8ModeStatus_Real = 0U;
  } else {
    rtb_THM_In_u8ModeStatus_Real = Sokon_X01_Thm_U.THM_In_u8ModeStatus_Real;
  }

  /* End of InitialCondition: '<Root>/IC35' */

  /* Saturate: '<Root>/Saturation34' */
  if (((int32_T)rtb_THM_In_u8ModeStatus_Real) >= 7) {
    rtb_THM_In_u8ModeStatus_Real = 7U;
  }

  /* End of Saturate: '<Root>/Saturation34' */

  /* InitialCondition: '<Root>/IC39' incorporates:
   *  Inport: '<Root>/THM_In_u8IntakePerc_Real'
   */
  if (Sokon_X01_Thm_DW.IC39_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC39_FirstOutputTime = false;
    Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req = 0U;
  } else {
    Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req =
      Sokon_X01_Thm_U.THM_In_u8IntakePerc_Real;
  }

  /* End of InitialCondition: '<Root>/IC39' */

  /* InitialCondition: '<Root>/IC40' incorporates:
   *  Inport: '<Root>/THM_In_u8HVACSts'
   */
  if (Sokon_X01_Thm_DW.IC40_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC40_FirstOutputTime = false;
    Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req = 0U;
  } else {
    Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req = Sokon_X01_Thm_U.THM_In_u8HVACSts;
  }

  /* End of InitialCondition: '<Root>/IC40' */

  /* InitialCondition: '<Root>/IC41' incorporates:
   *  Inport: '<Root>/THM_In_u8VehSpd'
   */
  if (Sokon_X01_Thm_DW.IC41_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC41_FirstOutputTime = false;
    rtb_THM_In_u8VehSpd = 0U;
  } else {
    rtb_THM_In_u8VehSpd = Sokon_X01_Thm_U.THM_In_u8VehSpd;
  }

  /* End of InitialCondition: '<Root>/IC41' */

  /* Saturate: '<Root>/Saturation40' */
  if (((int32_T)rtb_THM_In_u8VehSpd) >= 240) {
    rtb_THM_In_u8VehSpd = 240U;
  }

  /* End of Saturate: '<Root>/Saturation40' */

  /* InitialCondition: '<Root>/IC42' incorporates:
   *  Inport: '<Root>/THM_In_bEco_Model_Set'
   */
  if (Sokon_X01_Thm_DW.IC42_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC42_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bEco_Model_Set;
  }

  /* End of InitialCondition: '<Root>/IC42' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_1' */
  rtb_Compare_m0 = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_1' */

  /* InitialCondition: '<Root>/IC44' incorporates:
   *  Inport: '<Root>/THM_In_u8IgnSts'
   */
  if (Sokon_X01_Thm_DW.IC44_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC44_FirstOutputTime = false;
    rtb_THM_In_u8IgnSts = 0U;
  } else {
    rtb_THM_In_u8IgnSts = Sokon_X01_Thm_U.THM_In_u8IgnSts;
  }

  /* End of InitialCondition: '<Root>/IC44' */

  /* Saturate: '<Root>/Saturation42' */
  if (((int32_T)rtb_THM_In_u8IgnSts) >= 7) {
    rtb_THM_In_u8IgnSts = 7U;
  }

  /* End of Saturate: '<Root>/Saturation42' */

  /* InitialCondition: '<Root>/IC45' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Wat_HVCHOut_A10'
   */
  if (Sokon_X01_Thm_DW.IC45_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC45_FirstOutputTime = false;
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 200;
  } else {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = Sokon_X01_Thm_U.THM_In_s16T_Wat_HVCHOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC45' */

  /* Saturate: '<Root>/Saturation43' */
  if (rtb_THM_In_s16T_Ref_EDCOut_A10 > 1500) {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 1500;
  } else {
    if (rtb_THM_In_s16T_Ref_EDCOut_A10 < -500) {
      rtb_THM_In_s16T_Ref_EDCOut_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation43' */

  /* Lookup_n-D: '<S73>/HVCH_Tw_Cmp' */
  rtb_IC72 = look1_is16lu32n16Ds32_binlcs(rtb_THM_In_s16Tamb_A10, ((int16_T *)
    &(Thm_s16HVCH_OutTw_Cmp.Thm_s16Tamb_A10[0])), ((int16_T *)
    &(Thm_s16HVCH_OutTw_Cmp.Thm_s16HVCH_OutTw_Cmp_A10[0])), 10U);

  /* Outputs for Atomic SubSystem: '<S73>/DataTypeConv_s16_' */
  /* Sum: '<S73>/Add' */
  rtb_IC72 = (int16_T) Sokon_X01_Thm_DataTypeConv_s16__h((int16_T)
    (rtb_THM_In_s16T_Ref_EDCOut_A10 + rtb_IC72));

  /* End of Outputs for SubSystem: '<S73>/DataTypeConv_s16_' */

  /* Saturate: '<S73>/Saturation43' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<S73>/Saturation43' */

  /* Outputs for Atomic SubSystem: '<S83>/FirOrderLinear_Filter14' */
  /* Constant: '<S83>/Constant19' */
  rtb_Conversion_ej = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter14,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter14, 100);

  /* End of Outputs for SubSystem: '<S83>/FirOrderLinear_Filter14' */

  /* InitialCondition: '<Root>/IC46' incorporates:
   *  Inport: '<Root>/THM_In_u8BAT_CoolLv'
   */
  if (Sokon_X01_Thm_DW.IC46_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC46_FirstOutputTime = false;
    rtb_THM_In_u8AGS_Position = 0U;
  } else {
    rtb_THM_In_u8AGS_Position = Sokon_X01_Thm_U.THM_In_u8BAT_CoolLv;
  }

  /* End of InitialCondition: '<Root>/IC46' */

  /* Saturate: '<Root>/Saturation44' */
  if (((int32_T)rtb_THM_In_u8AGS_Position) >= 15) {
    rtb_THM_In_u8AGS_Position = 15U;
  }

  /* End of Saturate: '<Root>/Saturation44' */

  /* InitialCondition: '<Root>/IC55' incorporates:
   *  Inport: '<Root>/THM_In_u16Ncomp'
   */
  if (Sokon_X01_Thm_DW.IC55_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC55_FirstOutputTime = false;
    rtb_THM_In_u16Ncomp = 0U;
  } else {
    rtb_THM_In_u16Ncomp = Sokon_X01_Thm_U.THM_In_u16Ncomp;
  }

  /* End of InitialCondition: '<Root>/IC55' */

  /* Saturate: '<Root>/Saturation52' */
  if (((int32_T)rtb_THM_In_u16Ncomp) >= 12700) {
    rtb_THM_In_u16Ncomp = 12700U;
  }

  /* End of Saturate: '<Root>/Saturation52' */

  /* InitialCondition: '<Root>/IC63' incorporates:
   *  Inport: '<Root>/THM_In_u8Mix_Flap_Position_L'
   */
  if (Sokon_X01_Thm_DW.IC63_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC63_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_L;
  }

  /* End of InitialCondition: '<Root>/IC63' */

  /* Saturate: '<Root>/Saturation57' */
  if (((int32_T)rtb_IC9) < 100) {
    rtb_THM_In_u8Mix_Flap_Position_L = rtb_IC9;
  } else {
    rtb_THM_In_u8Mix_Flap_Position_L = 100U;
  }

  /* End of Saturate: '<Root>/Saturation57' */

  /* UnitDelay: '<S35>/Unit Delay' */
  rtb_IC9 = Sokon_X01_Thm_DW.UnitDelay_36_DSTATE;

  /* ModelReference: '<S35>/CMF' */
  Sokon_X01_Cmf(&rtb_THM_In_u16Tset_Left_A10, &rtb_THM_In_u16Tset_Right_A10,
                &rtb_Compare_l4, &rtb_THM_In_u8BlwMASts,
                &rtb_THM_In_u8Mot_CoolLv, &rtb_THM_In_u8BAT_CoolHeatLv,
                &rtb_Conversion_e, &rtb_Conversion_kx, &rtb_Conversion_k,
                &rtb_THM_In_s16Tamb_A10, &rtb_Conversion_f2, &rtb_Conversion_he,
                &rtb_Conversion_c, &rtb_Conversion_gi,
                &rtb_THM_In_u8ModeStatus_Real,
                &Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req,
                &Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req, &rtb_THM_In_u8VehSpd,
                &rtb_Compare_m0, &rtb_THM_In_u8IgnSts, &rtb_Conversion_ej,
                &rtb_THM_In_u8AGS_Position, &rtb_THM_In_u16Ncomp,
                &rtb_THM_In_u8Mix_Flap_Position_L, &rtb_IC9,
                &Sokon_X01_Thm_B.CmfO_u8HVACMode_Req,
                &Sokon_X01_Thm_B.CmfO_u8HVACIntake_Req,
                &Sokon_X01_Thm_B.CmfO_u8HVACBlwVol_Req_A10,
                &Sokon_X01_Thm_B.CmfO_s16Tasd_Left_Req_A10,
                &Sokon_X01_Thm_B.CmfO_s16Tasd_Right_Req_A10,
                &Sokon_X01_Thm_B.CmfO_s16TDuct_Left_Out_A10,
                &Sokon_X01_Thm_B.CmfO_s16TDuct_Right_Out_A10,
                &Sokon_X01_Thm_B.CmfO_u8TevaSet_Req_A10,
                &Sokon_X01_Thm_B.CmfO_s16Tincar_Setting_Req_A10,
                &Sokon_X01_Thm_B.CmfO_bFlag_HeatShort_Blw_Req,
                &Sokon_X01_Thm_B.CmfO_u16Debug_TasdLStatic_A10,
                &Sokon_X01_Thm_B.CmfO_u16Debug_TasdRStatic_A10,
                &Sokon_X01_Thm_B.CmfO_s16Debug_TasdLSolarCmp_A10,
                &Sokon_X01_Thm_B.CmfO_s16Debug_TasdDefCmp_A10,
                &Sokon_X01_Thm_B.CmfO_s16Debug_TasdEcoCmp_A10,
                &Sokon_X01_Thm_B.CmfO_s16Debug_TasdDyn_A10,
                &Sokon_X01_Thm_B.CmfO_u8Debug_BlwStatic_A10,
                &Sokon_X01_Thm_B.CmfO_s8Debug_BlwVspCmp_A10,
                &Sokon_X01_Thm_B.CmfO_s8Debug_BlwSolarCmp_A10,
                &Sokon_X01_Thm_B.CmfO_s8Debug_BlwDyn_A10,
                &Sokon_X01_Thm_B.CmfO_u8Debug_IntkStatic,
                &Sokon_X01_Thm_B.CmfO_s8Debug_IntkDyn,
                &Sokon_X01_Thm_B.CmfO_u8Debug_ModePerStatic,
                &Sokon_X01_Thm_B.CmfO_s8Debug_LvlCabHeatCool,
                &Sokon_X01_Thm_B.CmfO_u8WindExitmodeDisp,
                &Sokon_X01_Thm_B.CmfO_u8CabinCoolPrioReq,
                &Sokon_X01_Thm_B.CmfO_u8CabinHeatPrioReq,
                &Sokon_X01_Thm_B.CmfO_u16Tw_PTCOut_Set_Pre_A10,
                &Sokon_X01_Thm_B.CmfO_s16Debug_TasdRSolarCmp_A10);

  /* Saturate: '<Root>/Saturation79' */
  if (((int32_T)Sokon_X01_Thm_B.CmfO_u8HVACMode_Req) < 7) {
    rtb_IC9 = Sokon_X01_Thm_B.CmfO_u8HVACMode_Req;
  } else {
    rtb_IC9 = 7U;
  }

  /* End of Saturate: '<Root>/Saturation79' */

  /* InitialCondition: '<Root>/IC106' */
  if (Sokon_X01_Thm_DW.IC106_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC106_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8HVACMode_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8HVACMode_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8HVACMode_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8HVACMode_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC106' */

  /* Saturate: '<Root>/Saturation81' */
  if (((int32_T)Sokon_X01_Thm_B.CmfO_u8HVACBlwVol_Req_A10) < 120) {
    rtb_IC9 = Sokon_X01_Thm_B.CmfO_u8HVACBlwVol_Req_A10;
  } else {
    rtb_IC9 = 120U;
  }

  /* End of Saturate: '<Root>/Saturation81' */

  /* InitialCondition: '<Root>/IC108' */
  if (Sokon_X01_Thm_DW.IC108_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC108_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8HVACBlwVol_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_u8HVACBlwVol_Req_A10 = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8HVACBlwVol_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_u8HVACBlwVol_Req_A10 = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC108' */

  /* Saturate: '<Root>/Saturation82' */
  if (((int32_T)Sokon_X01_Thm_B.CmfO_u8WindExitmodeDisp) < 7) {
    rtb_IC9 = Sokon_X01_Thm_B.CmfO_u8WindExitmodeDisp;
  } else {
    rtb_IC9 = 7U;
  }

  /* End of Saturate: '<Root>/Saturation82' */

  /* InitialCondition: '<Root>/IC109' */
  if (Sokon_X01_Thm_DW.IC109_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC109_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8WindExitmodeDisp' */
    Sokon_X01_Thm_Y.THM_Out_u8WindExitmodeDisp = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8WindExitmodeDisp' */
    Sokon_X01_Thm_Y.THM_Out_u8WindExitmodeDisp = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC109' */

  /* Saturate: '<Root>/Saturation100' */
  if (Sokon_X01_Thm_B.CmfO_s16Tasd_Left_Req_A10 > 1500) {
    rtb_IC72 = 1500;
  } else if (Sokon_X01_Thm_B.CmfO_s16Tasd_Left_Req_A10 < -500) {
    rtb_IC72 = -500;
  } else {
    rtb_IC72 = Sokon_X01_Thm_B.CmfO_s16Tasd_Left_Req_A10;
  }

  /* End of Saturate: '<Root>/Saturation100' */

  /* InitialCondition: '<Root>/IC132' */
  if (Sokon_X01_Thm_DW.IC132_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC132_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_s16Tasd_Left_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_s16Tasd_Left_Req_A10 = 200;
  } else {
    /* Outport: '<Root>/THM_Out_s16Tasd_Left_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_s16Tasd_Left_Req_A10 = rtb_IC72;
  }

  /* End of InitialCondition: '<Root>/IC132' */

  /* Saturate: '<Root>/Saturation101' */
  if (Sokon_X01_Thm_B.CmfO_s16Tasd_Right_Req_A10 > 1500) {
    rtb_IC72 = 1500;
  } else if (Sokon_X01_Thm_B.CmfO_s16Tasd_Right_Req_A10 < -500) {
    rtb_IC72 = -500;
  } else {
    rtb_IC72 = Sokon_X01_Thm_B.CmfO_s16Tasd_Right_Req_A10;
  }

  /* End of Saturate: '<Root>/Saturation101' */

  /* InitialCondition: '<Root>/IC133' */
  if (Sokon_X01_Thm_DW.IC133_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC133_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_s16Tasd_Right_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_s16Tasd_Right_Req_A10 = 200;
  } else {
    /* Outport: '<Root>/THM_Out_s16Tasd_Right_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_s16Tasd_Right_Req_A10 = rtb_IC72;
  }

  /* End of InitialCondition: '<Root>/IC133' */

  /* Saturate: '<Root>/Saturation102' */
  if (((int32_T)Sokon_X01_Thm_B.CmfO_u8TevaSet_Req_A10) < 200) {
    rtb_IC9 = Sokon_X01_Thm_B.CmfO_u8TevaSet_Req_A10;
  } else {
    rtb_IC9 = 200U;
  }

  /* End of Saturate: '<Root>/Saturation102' */

  /* InitialCondition: '<Root>/IC134' */
  if (Sokon_X01_Thm_DW.IC134_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC134_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8TevaSet_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_u8TevaSet_Req_A10 = 200U;
  } else {
    /* Outport: '<Root>/THM_Out_u8TevaSet_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_u8TevaSet_Req_A10 = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC134' */

  /* Saturate: '<Root>/Saturation103' */
  if (Sokon_X01_Thm_B.CmfO_s16Tincar_Setting_Req_A10 > 1500) {
    rtb_IC72 = 1500;
  } else if (Sokon_X01_Thm_B.CmfO_s16Tincar_Setting_Req_A10 < -500) {
    rtb_IC72 = -500;
  } else {
    rtb_IC72 = Sokon_X01_Thm_B.CmfO_s16Tincar_Setting_Req_A10;
  }

  /* End of Saturate: '<Root>/Saturation103' */

  /* InitialCondition: '<Root>/IC135' */
  if (Sokon_X01_Thm_DW.IC135_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC135_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_s16Tincar_Setting_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_s16Tincar_Setting_Req_A10 = 240;
  } else {
    /* Outport: '<Root>/THM_Out_s16Tincar_Setting_Req_A10' */
    Sokon_X01_Thm_Y.THM_Out_s16Tincar_Setting_Req_A10 = rtb_IC72;
  }

  /* End of InitialCondition: '<Root>/IC135' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_32' */
  rtb_Compare_o = ( Sokon_X01_Thm_DataTypeConv_b_
                   (Sokon_X01_Thm_B.CmfO_bFlag_HeatShort_Blw_Req) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_32' */

  /* InitialCondition: '<Root>/IC136' */
  if (Sokon_X01_Thm_DW.IC136_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC136_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_bFlag_HeatShort_Blw_Req' */
    Sokon_X01_Thm_Y.THM_Out_bFlag_HeatShort_Blw_Req = false;
  } else {
    /* Outport: '<Root>/THM_Out_bFlag_HeatShort_Blw_Req' */
    Sokon_X01_Thm_Y.THM_Out_bFlag_HeatShort_Blw_Req = rtb_Compare_o;
  }

  /* End of InitialCondition: '<Root>/IC136' */

  /* InitialCondition: '<Root>/IC47' incorporates:
   *  Inport: '<Root>/THM_In_u16P_Ref_EvaOut_A10'
   */
  if (Sokon_X01_Thm_DW.IC47_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC47_FirstOutputTime = false;
    rtb_THM_In_u16PowerComp = 150U;
  } else {
    rtb_THM_In_u16PowerComp = Sokon_X01_Thm_U.THM_In_u16P_Ref_EvaOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC47' */

  /* Saturate: '<Root>/Saturation45' */
  if (((int32_T)rtb_THM_In_u16PowerComp) < 400) {
    y_0 = rtb_THM_In_u16PowerComp;
  } else {
    y_0 = 400U;
  }

  /* End of Saturate: '<Root>/Saturation45' */

  /* Outputs for Atomic SubSystem: '<S84>/FirOrderLinear_Filter2' */
  /* Constant: '<S84>/Constant3' */
  rtb_Conversion = (uint16_T) Sokon_X01_Thm_FirOrderLinear_Filter2(y_0, rtb_IC4,
    CmfThm_u8Filter_2s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter2_n,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter2_n, 100);

  /* End of Outputs for SubSystem: '<S84>/FirOrderLinear_Filter2' */

  /* InitialCondition: '<Root>/IC48' incorporates:
   *  Inport: '<Root>/THM_In_u16P_Ref_CHILOut_A10'
   */
  if (Sokon_X01_Thm_DW.IC48_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC48_FirstOutputTime = false;
    rtb_THM_In_u16PowerComp = 30U;
  } else {
    rtb_THM_In_u16PowerComp = Sokon_X01_Thm_U.THM_In_u16P_Ref_CHILOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC48' */

  /* Saturate: '<Root>/Saturation46' */
  if (((int32_T)rtb_THM_In_u16PowerComp) < 120) {
    y_0 = rtb_THM_In_u16PowerComp;
  } else {
    y_0 = 120U;
  }

  /* End of Saturate: '<Root>/Saturation46' */

  /* Outputs for Atomic SubSystem: '<S84>/FirOrderLinear_Filter1' */
  /* Constant: '<S84>/Constant1' */
  rtb_Conversion_f = (uint16_T) Sokon_X01_Thm_FirOrderLinear_Filter2(y_0,
    rtb_IC4, CmfThm_u8Filter_2s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter1_k,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter1_k, 100);

  /* End of Outputs for SubSystem: '<S84>/FirOrderLinear_Filter1' */

  /* InitialCondition: '<Root>/IC49' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Ref_CHILOut_A10'
   */
  if (Sokon_X01_Thm_DW.IC49_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC49_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16T_Ref_CHILOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC49' */

  /* Saturate: '<Root>/Saturation47' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation47' */

  /* Outputs for Atomic SubSystem: '<S84>/FirOrderLinear_Filter3' */
  /* Constant: '<S84>/Constant2' */
  rtb_Conversion_h = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_2s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter3_a,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter3_a, 100);

  /* End of Outputs for SubSystem: '<S84>/FirOrderLinear_Filter3' */

  /* InitialCondition: '<Root>/IC50' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Ref_EDCIn_A10'
   */
  if (Sokon_X01_Thm_DW.IC50_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC50_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16T_Ref_EDCIn_A10;
  }

  /* End of InitialCondition: '<Root>/IC50' */

  /* Saturate: '<Root>/Saturation48' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation48' */

  /* Outputs for Atomic SubSystem: '<S84>/FirOrderLinear_Filter4' */
  /* Constant: '<S84>/Constant4' */
  rtb_Conversion_kr = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_2s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter4_o,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter4_o, 100);

  /* End of Outputs for SubSystem: '<S84>/FirOrderLinear_Filter4' */

  /* InitialCondition: '<Root>/IC15' incorporates:
   *  Inport: '<Root>/THM_In_s16Teva_Front_A10'
   */
  if (Sokon_X01_Thm_DW.IC15_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC15_FirstOutputTime = false;
    rtb_IC72 = 0;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16Teva_Front_A10;
  }

  /* End of InitialCondition: '<Root>/IC15' */

  /* Saturate: '<Root>/Saturation14' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation14' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter' */
  /* Constant: '<S82>/Constant1' */
  rtb_Conversion_g4 = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_15s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter' */

  /* Outputs for Atomic SubSystem: '<S71>/DataTypeConv_s16_' */
  rtb_Saturation = (int16_T) Sokon_X01_Thm_DataTypeConv_s16__f
    (Sokon_X01_Thm_B.CmfO_u8TevaSet_Req_A10);

  /* End of Outputs for SubSystem: '<S71>/DataTypeConv_s16_' */

  /* InitialCondition: '<Root>/IC51' incorporates:
   *  Inport: '<Root>/THM_In_u8PWM_FrontFAN'
   */
  if (Sokon_X01_Thm_DW.IC51_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC51_FirstOutputTime = false;
    rtb_IC9 = 1U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8PWM_FrontFAN;
  }

  /* End of InitialCondition: '<Root>/IC51' */

  /* Saturate: '<Root>/Saturation49' */
  if (((int32_T)rtb_IC9) >= 100) {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation49' */

  /* InitialCondition: '<Root>/IC52' incorporates:
   *  Inport: '<Root>/THM_In_bAGS_Status'
   */
  if (Sokon_X01_Thm_DW.IC52_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC52_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bAGS_Status;
  }

  /* End of InitialCondition: '<Root>/IC52' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_2' */
  rtb_Compare_a = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_2' */

  /* InitialCondition: '<Root>/IC53' incorporates:
   *  Inport: '<Root>/THM_In_u8AGS_Position'
   */
  if (Sokon_X01_Thm_DW.IC53_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC53_FirstOutputTime = false;
    rtb_THM_In_u8AGS_Position = 100U;
  } else {
    rtb_THM_In_u8AGS_Position = Sokon_X01_Thm_U.THM_In_u8AGS_Position;
  }

  /* End of InitialCondition: '<Root>/IC53' */

  /* Saturate: '<Root>/Saturation50' */
  if (((int32_T)rtb_THM_In_u8AGS_Position) >= 100) {
    rtb_THM_In_u8AGS_Position = 100U;
  }

  /* End of Saturate: '<Root>/Saturation50' */

  /* InitialCondition: '<Root>/IC54' incorporates:
   *  Inport: '<Root>/THM_In_u16PowerComp'
   */
  if (Sokon_X01_Thm_DW.IC54_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC54_FirstOutputTime = false;
    rtb_THM_In_u16PowerComp = 0U;
  } else {
    rtb_THM_In_u16PowerComp = Sokon_X01_Thm_U.THM_In_u16PowerComp;
  }

  /* End of InitialCondition: '<Root>/IC54' */

  /* Saturate: '<Root>/Saturation51' */
  if (((int32_T)rtb_THM_In_u16PowerComp) >= 18000) {
    rtb_THM_In_u16PowerComp = 18000U;
  }

  /* End of Saturate: '<Root>/Saturation51' */

  /* InitialCondition: '<Root>/IC56' incorporates:
   *  Inport: '<Root>/THM_In_u16Power_Max'
   */
  if (Sokon_X01_Thm_DW.IC56_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC56_FirstOutputTime = false;
    rtb_THM_In_u16Power_Max = 8000U;
  } else {
    rtb_THM_In_u16Power_Max = Sokon_X01_Thm_U.THM_In_u16Power_Max;
  }

  /* End of InitialCondition: '<Root>/IC56' */

  /* Saturate: '<Root>/Saturation53' */
  if (((int32_T)rtb_THM_In_u16Power_Max) >= 12600) {
    rtb_THM_In_u16Power_Max = 12600U;
  }

  /* End of Saturate: '<Root>/Saturation53' */

  /* InitialCondition: '<Root>/IC57' incorporates:
   *  Inport: '<Root>/THM_In_u16Ncomp_Max'
   */
  if (Sokon_X01_Thm_DW.IC57_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC57_FirstOutputTime = false;
    rtb_THM_In_u16Ncomp_Max = 8000U;
  } else {
    rtb_THM_In_u16Ncomp_Max = Sokon_X01_Thm_U.THM_In_u16Ncomp_Max;
  }

  /* End of InitialCondition: '<Root>/IC57' */

  /* Saturate: '<Root>/Saturation54' */
  if (((int32_T)rtb_THM_In_u16Ncomp_Max) >= 8000) {
    rtb_THM_In_u16Ncomp_Max = 8000U;
  }

  /* End of Saturate: '<Root>/Saturation54' */

  /* InitialCondition: '<Root>/IC58' incorporates:
   *  Inport: '<Root>/THM_In_bSOV_Eva'
   */
  if (Sokon_X01_Thm_DW.IC58_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC58_FirstOutputTime = false;
    rtb_IC42 = true;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bSOV_Eva;
  }

  /* End of InitialCondition: '<Root>/IC58' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_3' */
  rtb_Compare_h = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_3' */

  /* InitialCondition: '<Root>/IC59' incorporates:
   *  Inport: '<Root>/THM_In_bSOV_OutEva'
   */
  if (Sokon_X01_Thm_DW.IC59_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC59_FirstOutputTime = false;
    rtb_IC42 = true;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bSOV_OutEva;
  }

  /* End of InitialCondition: '<Root>/IC59' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_4' */
  rtb_Compare_o = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_4' */

  /* InitialCondition: '<Root>/IC60' incorporates:
   *  Inport: '<Root>/THM_In_bSOV_TXVOutEva'
   */
  if (Sokon_X01_Thm_DW.IC60_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC60_FirstOutputTime = false;
    rtb_IC42 = true;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bSOV_TXVOutEva;
  }

  /* End of InitialCondition: '<Root>/IC60' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_5' */
  rtb_Compare_m = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_5' */

  /* InitialCondition: '<Root>/IC62' incorporates:
   *  Inport: '<Root>/THM_In_u16EXV_Chil_Pos'
   */
  if (Sokon_X01_Thm_DW.IC62_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC62_FirstOutputTime = false;
    rtb_THM_In_u16EXV_Chil_Pos = 50U;
  } else {
    rtb_THM_In_u16EXV_Chil_Pos = Sokon_X01_Thm_U.THM_In_u16EXV_Chil_Pos;
  }

  /* End of InitialCondition: '<Root>/IC62' */

  /* Saturate: '<Root>/Saturation56' */
  if (((int32_T)rtb_THM_In_u16EXV_Chil_Pos) >= 576) {
    rtb_THM_In_u16EXV_Chil_Pos = 576U;
  }

  /* End of Saturate: '<Root>/Saturation56' */

  /* InitialCondition: '<Root>/IC33' incorporates:
   *  Inport: '<Root>/THM_In_u8BlwVol_Real_A10'
   */
  if (Sokon_X01_Thm_DW.IC33_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC33_FirstOutputTime = false;
    rtb_THM_In_u8BAT_CoolHeatLv = 0U;
  } else {
    rtb_THM_In_u8BAT_CoolHeatLv = Sokon_X01_Thm_U.THM_In_u8BlwVol_Real_A10;
  }

  /* End of InitialCondition: '<Root>/IC33' */

  /* Saturate: '<Root>/Saturation32' */
  if (((int32_T)rtb_THM_In_u8BAT_CoolHeatLv) < 120) {
    rtb_THM_In_u8BlwVol_Real_A10 = rtb_THM_In_u8BAT_CoolHeatLv;
  } else {
    rtb_THM_In_u8BlwVol_Real_A10 = 120U;
  }

  /* End of Saturate: '<Root>/Saturation32' */

  /* Outputs for Atomic SubSystem: '<S69>/DataTypeConv_s16_' */
  rtb_Saturation_i = (int16_T) Sokon_X01_Thm_DataTypeConv_s16_
    (rtb_THM_In_u16Tset_Left_A10);

  /* End of Outputs for SubSystem: '<S69>/DataTypeConv_s16_' */

  /* Outputs for Atomic SubSystem: '<S69>/DataTypeConv_s16_1' */
  rtb_Saturation_f = (int16_T) Sokon_X01_Thm_DataTypeConv_s16_
    (rtb_THM_In_u16Tset_Right_A10);

  /* End of Outputs for SubSystem: '<S69>/DataTypeConv_s16_1' */

  /* InitialCondition: '<Root>/IC67' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Wat_BatIn_A10'
   */
  if (Sokon_X01_Thm_DW.IC67_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC67_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16T_Wat_BatIn_A10;
  }

  /* End of InitialCondition: '<Root>/IC67' */

  /* Saturate: '<Root>/Saturation61' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation61' */

  /* Outputs for Atomic SubSystem: '<S85>/FirOrderLinear_Filter14' */
  /* Constant: '<S85>/Constant19' */
  rtb_Conversion_ky = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter14_e,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter14_e, 100);

  /* End of Outputs for SubSystem: '<S85>/FirOrderLinear_Filter14' */

  /* InitialCondition: '<Root>/IC68' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Wat_LTROut_A10'
   */
  if (Sokon_X01_Thm_DW.IC68_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC68_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16T_Wat_LTROut_A10;
  }

  /* End of InitialCondition: '<Root>/IC68' */

  /* Saturate: '<Root>/Saturation62' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation62' */

  /* Outputs for Atomic SubSystem: '<S85>/FirOrderLinear_Filter1' */
  /* Constant: '<S85>/Constant1' */
  rtb_Conversion_mn = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter1_f,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter1_f, 100);

  /* End of Outputs for SubSystem: '<S85>/FirOrderLinear_Filter1' */

  /* InitialCondition: '<Root>/IC69' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Wat_MotorOut_A10'
   */
  if (Sokon_X01_Thm_DW.IC69_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC69_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16T_Wat_MotorOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC69' */

  /* Saturate: '<Root>/Saturation63' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation63' */

  /* Outputs for Atomic SubSystem: '<S85>/FirOrderLinear_Filter2' */
  /* Constant: '<S85>/Constant2' */
  rtb_Conversion_l = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter2_h,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter2_h, 100);

  /* End of Outputs for SubSystem: '<S85>/FirOrderLinear_Filter2' */

  /* InitialCondition: '<Root>/IC73' incorporates:
   *  Inport: '<Root>/THM_In_u8BAT_CoolHeatLv'
   */
  if (Sokon_X01_Thm_DW.IC73_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC73_FirstOutputTime = false;
    rtb_THM_In_u8BAT_CoolHeatLv = 0U;
  } else {
    rtb_THM_In_u8BAT_CoolHeatLv = Sokon_X01_Thm_U.THM_In_u8BAT_CoolHeatLv;
  }

  /* End of InitialCondition: '<Root>/IC73' */

  /* Saturate: '<Root>/Saturation67' */
  if (((int32_T)rtb_THM_In_u8BAT_CoolHeatLv) >= 15) {
    rtb_THM_In_u8BAT_CoolHeatLv = 15U;
  }

  /* End of Saturate: '<Root>/Saturation67' */

  /* InitialCondition: '<Root>/IC74' incorporates:
   *  Inport: '<Root>/THM_In_s16T_BAT_Wat_Set_A10'
   */
  if (Sokon_X01_Thm_DW.IC74_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC74_FirstOutputTime = false;
    rtb_IC72 = 150;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16T_BAT_Wat_Set_A10;
  }

  /* End of InitialCondition: '<Root>/IC74' */

  /* Saturate: '<Root>/Saturation68' */
  y = rtb_IC72;
  if (y > 870) {
    rtb_IC72 = 870;
  } else if (y < -400) {
    rtb_IC72 = -400;
  } else {
    rtb_IC72 = y;
  }

  /* End of Saturate: '<Root>/Saturation68' */

  /* InitialCondition: '<Root>/IC75' incorporates:
   *  Inport: '<Root>/THM_In_u8Mot_CoolLv'
   */
  if (Sokon_X01_Thm_DW.IC75_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC75_FirstOutputTime = false;
    rtb_THM_In_u8Mot_CoolLv = 0U;
  } else {
    rtb_THM_In_u8Mot_CoolLv = Sokon_X01_Thm_U.THM_In_u8Mot_CoolLv;
  }

  /* End of InitialCondition: '<Root>/IC75' */

  /* Saturate: '<Root>/Saturation69' */
  if (((int32_T)rtb_THM_In_u8Mot_CoolLv) >= 15) {
    rtb_THM_In_u8Mot_CoolLv = 15U;
  }

  /* End of Saturate: '<Root>/Saturation69' */

  /* InitialCondition: '<Root>/IC82' incorporates:
   *  Inport: '<Root>/THM_In_u16Pump_Bat'
   */
  if (Sokon_X01_Thm_DW.IC82_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC82_FirstOutputTime = false;
    rtb_THM_In_u16Pump_Bat = 49U;
  } else {
    rtb_THM_In_u16Pump_Bat = Sokon_X01_Thm_U.THM_In_u16Pump_Bat;
  }

  /* End of InitialCondition: '<Root>/IC82' */

  /* Saturate: '<Root>/Saturation76' */
  if (((int32_T)rtb_THM_In_u16Pump_Bat) >= 100) {
    rtb_THM_In_u16Pump_Bat = 100U;
  }

  /* End of Saturate: '<Root>/Saturation76' */

  /* InitialCondition: '<Root>/IC83' incorporates:
   *  Inport: '<Root>/THM_In_u16PowerHVCH'
   */
  if (Sokon_X01_Thm_DW.IC83_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC83_FirstOutputTime = false;
    rtb_IC81 = 0U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16PowerHVCH;
  }

  /* End of InitialCondition: '<Root>/IC83' */

  /* Saturate: '<Root>/Saturation77' */
  if (((int32_T)rtb_IC81) >= 8000) {
    rtb_IC81 = 8000U;
  }

  /* End of Saturate: '<Root>/Saturation77' */

  /* InitialCondition: '<Root>/IC84' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_P_Ref_CondOut'
   */
  if (Sokon_X01_Thm_DW.IC84_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC84_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_CondOut;
  }

  /* End of InitialCondition: '<Root>/IC84' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_6' */
  rtb_Compare_p = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_6' */

  /* InitialCondition: '<Root>/IC85' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_P_Ref_EvaOut'
   */
  if (Sokon_X01_Thm_DW.IC85_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC85_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_EvaOut;
  }

  /* End of InitialCondition: '<Root>/IC85' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_7' */
  rtb_Compare_d = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_7' */

  /* InitialCondition: '<Root>/IC86' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_P_Ref_CHILOut'
   */
  if (Sokon_X01_Thm_DW.IC86_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC86_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_CHILOut;
  }

  /* End of InitialCondition: '<Root>/IC86' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_8' */
  rtb_Compare_l = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_8' */

  /* InitialCondition: '<Root>/IC87' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_T_Ref_CHILOut'
   */
  if (Sokon_X01_Thm_DW.IC87_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC87_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_T_Ref_CHILOut;
  }

  /* End of InitialCondition: '<Root>/IC87' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_9' */
  rtb_Compare_e = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_9' */

  /* InitialCondition: '<Root>/IC88' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_T_Ref_EDCIn'
   */
  if (Sokon_X01_Thm_DW.IC88_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC88_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_T_Ref_EDCIn;
  }

  /* End of InitialCondition: '<Root>/IC88' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_10' */
  rtb_Compare_lb = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_10' */

  /* InitialCondition: '<Root>/IC89' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_Teva_Front'
   */
  if (Sokon_X01_Thm_DW.IC89_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC89_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_Teva_Front;
  }

  /* End of InitialCondition: '<Root>/IC89' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_11' */
  rtb_Compare_j = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_11' */

  /* InitialCondition: '<Root>/IC90' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_Tamb'
   */
  if (Sokon_X01_Thm_DW.IC90_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC90_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_Tamb;
  }

  /* End of InitialCondition: '<Root>/IC90' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_12' */
  rtb_Compare_cs = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_12' */

  /* InitialCondition: '<Root>/IC91' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_SOV_Eva'
   */
  if (Sokon_X01_Thm_DW.IC91_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC91_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_SOV_Eva;
  }

  /* End of InitialCondition: '<Root>/IC91' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_13' */
  rtb_Compare_n = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_13' */

  /* InitialCondition: '<Root>/IC92' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_SOV_OutEva'
   */
  if (Sokon_X01_Thm_DW.IC92_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC92_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_SOV_OutEva;
  }

  /* End of InitialCondition: '<Root>/IC92' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_14' */
  rtb_Compare_m5 = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_14' */

  /* InitialCondition: '<Root>/IC93' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_SOV_TXVOutEva'
   */
  if (Sokon_X01_Thm_DW.IC93_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC93_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_SOV_TXVOutEva;
  }

  /* End of InitialCondition: '<Root>/IC93' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_15' */
  rtb_Compare_fd = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_15' */

  /* InitialCondition: '<Root>/IC94' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_EXV_Eva_Pos'
   */
  if (Sokon_X01_Thm_DW.IC94_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC94_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_EXV_Eva_Pos;
  }

  /* End of InitialCondition: '<Root>/IC94' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_16' */
  rtb_Compare_ed = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_16' */

  /* InitialCondition: '<Root>/IC95' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_EXV_Chil_Pos'
   */
  if (Sokon_X01_Thm_DW.IC95_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC95_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_EXV_Chil_Pos;
  }

  /* End of InitialCondition: '<Root>/IC95' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_17' */
  rtb_Compare_c = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_17' */

  /* InitialCondition: '<Root>/IC96' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_BLW_Front'
   */
  if (Sokon_X01_Thm_DW.IC96_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC96_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_BLW_Front;
  }

  /* End of InitialCondition: '<Root>/IC96' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_18' */
  rtb_Compare_ay = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_18' */

  /* InitialCondition: '<Root>/IC97' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_EDC_Front'
   */
  if (Sokon_X01_Thm_DW.IC97_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC97_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_EDC_Front;
  }

  /* End of InitialCondition: '<Root>/IC97' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_19' */
  rtb_Compare_ie = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_19' */

  /* InitialCondition: '<Root>/IC98' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_TWValve_HC'
   */
  if (Sokon_X01_Thm_DW.IC98_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC98_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_TWValve_HC;
  }

  /* End of InitialCondition: '<Root>/IC98' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_20' */
  rtb_Compare_f = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_20' */

  /* InitialCondition: '<Root>/IC99' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_TWValve_LTR'
   */
  if (Sokon_X01_Thm_DW.IC99_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC99_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_TWValve_LTR;
  }

  /* End of InitialCondition: '<Root>/IC99' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_21' */
  rtb_Compare_mn = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_21' */

  /* InitialCondition: '<Root>/IC100' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_TWValve_BAT'
   */
  if (Sokon_X01_Thm_DW.IC100_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC100_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_TWValve_BAT;
  }

  /* End of InitialCondition: '<Root>/IC100' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_22' */
  rtb_Compare_dz = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_22' */

  /* InitialCondition: '<Root>/IC101' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_HVCH'
   */
  if (Sokon_X01_Thm_DW.IC101_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC101_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_HVCH;
  }

  /* End of InitialCondition: '<Root>/IC101' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_23' */
  rtb_Compare_py = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_23' */

  /* InitialCondition: '<Root>/IC102' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_Pump_HVCH'
   */
  if (Sokon_X01_Thm_DW.IC102_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC102_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_Pump_HVCH;
  }

  /* End of InitialCondition: '<Root>/IC102' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_24' */
  rtb_Compare_i = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_24' */

  /* InitialCondition: '<Root>/IC103' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_Pump_Motor'
   */
  if (Sokon_X01_Thm_DW.IC103_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC103_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_Pump_Motor;
  }

  /* End of InitialCondition: '<Root>/IC103' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_25' */
  rtb_Compare_ma = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_25' */

  /* InitialCondition: '<Root>/IC104' incorporates:
   *  Inport: '<Root>/THM_In_bDTC_Pump_Bat'
   */
  if (Sokon_X01_Thm_DW.IC104_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC104_FirstOutputTime = false;
    rtb_IC42 = false;
  } else {
    rtb_IC42 = Sokon_X01_Thm_U.THM_In_bDTC_Pump_Bat;
  }

  /* End of InitialCondition: '<Root>/IC104' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_26' */
  rtb_Compare_b = ( Sokon_X01_Thm_DataTypeConv_b_(rtb_IC42) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_26' */

  /* InitialCondition: '<Root>/IC105' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Ref_EDCOut_A10'
   */
  if (Sokon_X01_Thm_DW.IC105_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC105_FirstOutputTime = false;
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 300;
  } else {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = Sokon_X01_Thm_U.THM_In_s16T_Ref_EDCOut_A10;
  }

  /* End of InitialCondition: '<Root>/IC105' */

  /* Saturate: '<Root>/Saturation78' */
  if (rtb_THM_In_s16T_Ref_EDCOut_A10 > 1500) {
    rtb_THM_In_s16T_Ref_EDCOut_A10 = 1500;
  } else {
    if (rtb_THM_In_s16T_Ref_EDCOut_A10 < -500) {
      rtb_THM_In_s16T_Ref_EDCOut_A10 = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation78' */

  /* ModelReference: '<S35>/HP' incorporates:
   *  Constant: '<S71>/Constant'
   */
  Chery_E03_Hp(&rtb_Conversion_e, &rtb_Conversion, &rtb_Conversion_f,
               &rtb_Conversion_h, &rtb_Conversion_kr, &rtb_Conversion_g4,
               &rtb_Saturation, &rtb_Compare_l4, &rtb_THM_In_s16Tamb_A10,
               &rtb_Conversion_f2, &rtb_THM_In_u8VehSpd, &rtb_IC9,
               &rtb_Compare_a, &rtb_THM_In_u8AGS_Position,
               &rtb_THM_In_u16PowerComp, &rtb_THM_In_u16Ncomp,
               &rtb_THM_In_u16Power_Max, &rtb_THM_In_u16Ncomp_Max,
               &rtb_Compare_h, &rtb_Compare_o, &rtb_Compare_m,
               &rtb_THM_In_u16EXV_Chil_Pos, &rtb_THM_In_u8BlwVol_Real_A10,
               &rtb_THM_In_u8ModeStatus_Real,
               &Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req, &rtb_Saturation_i,
               &rtb_Saturation_f, &Sokon_X01_Thm_B.CmfO_s16Tasd_Left_Req_A10,
               &Sokon_X01_Thm_B.CmfO_s16Tasd_Right_Req_A10,
               &Sokon_X01_Thm_B.CmfO_s16TDuct_Left_Out_A10,
               &Sokon_X01_Thm_B.CmfO_s16TDuct_Right_Out_A10, &rtb_Compare_m0,
               &Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req,
               &Sokon_X01_Thm_B.CmfO_bFlag_HeatShort_Blw_Req, &rtb_Conversion_ky,
               &rtb_Conversion_ej, &rtb_Conversion_mn, &rtb_Conversion_l,
               &rtb_THM_In_u8BAT_CoolHeatLv, &rtb_IC72, &rtb_THM_In_u8Mot_CoolLv,
               &rtb_THM_In_u16Pump_Bat, &rtb_THM_In_u8IgnSts, &rtb_IC81,
               &rtb_Compare_p, &rtb_Compare_d, &rtb_Compare_l, &rtb_Compare_e,
               &rtb_Compare_lb, &rtb_Compare_j, &rtb_Compare_cs, &rtb_Compare_n,
               &rtb_Compare_m5, &rtb_Compare_fd, &rtb_Compare_ed, &rtb_Compare_c,
               &rtb_Compare_ay, &rtb_Compare_ie, &rtb_Compare_f, &rtb_Compare_mn,
               &rtb_Compare_dz, &rtb_Compare_py, &rtb_Compare_i, &rtb_Compare_ma,
               &rtb_Compare_b, &rtb_THM_In_s16T_Ref_EDCOut_A10,
               &Sokon_X01_Thm_B.HpO_u16Ncomp_Rpm_Req,
               &Sokon_X01_Thm_B.HpO_bSOV_Eva_Req,
               &Sokon_X01_Thm_B.HpO_bSOV_OutEva_Req,
               &Sokon_X01_Thm_B.HpO_bSOV_TXVOutEva_Req,
               &Sokon_X01_Thm_B.HpO_u16EXV_Eva_Pos_Req,
               &Sokon_X01_Thm_B.HpO_u16EXV_Chil_Pos_Req,
               &Sokon_X01_Thm_B.HpO_u8HpWorkMode_Req,
               &Sokon_X01_Thm_B.HpI_u8AGS_Position_Req,
               &Sokon_X01_Thm_B.HpO_u8FRFAN_PWM_Req,
               &Sokon_X01_Thm_B.HpO_u8Mix_Left_Req,
               &Sokon_X01_Thm_B.HpO_u8Mix_Right_Req,
               &Sokon_X01_Thm_B.HpO_u8DTC_Ref_System,
               &Sokon_X01_Thm_B.HpO_u8DTC_Ref_Component,
               &Sokon_X01_Thm_B.HpO_bDTC_EvaFreeze,
               &Sokon_X01_Thm_B.HpO_bDTC_OutEvaFreeze,
               &Sokon_X01_Thm_B.HpO_u8TWValve_HC_Req,
               &Sokon_X01_Thm_B.HpO_u8TWValve_LTR_Req,
               &Sokon_X01_Thm_B.HpO_u8TWValve_BAT_Req,
               &Sokon_X01_Thm_B.HpO_u8HVCH_Req,
               &Sokon_X01_Thm_B.HpO_u16Pump_HVCH_Req,
               &Sokon_X01_Thm_B.HpO_u16Pump_Motor_Req,
               &Sokon_X01_Thm_B.HpO_u16Pump_Bat_Req);

  /* Saturate: '<Root>/Saturation83' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u16Ncomp_Rpm_Req) < 8000) {
    rtb_IC81 = Sokon_X01_Thm_B.HpO_u16Ncomp_Rpm_Req;
  } else {
    rtb_IC81 = 8000U;
  }

  /* End of Saturate: '<Root>/Saturation83' */

  /* InitialCondition: '<Root>/IC110' */
  if (Sokon_X01_Thm_DW.IC110_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC110_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u16Ncomp_Rpm_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Ncomp_Rpm_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u16Ncomp_Rpm_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Ncomp_Rpm_Req = rtb_IC81;
  }

  /* End of InitialCondition: '<Root>/IC110' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_27' */
  rtb_Compare_h = ( Sokon_X01_Thm_DataTypeConv_b_
                   (Sokon_X01_Thm_B.HpO_bSOV_Eva_Req) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_27' */

  /* InitialCondition: '<Root>/IC111' */
  if (Sokon_X01_Thm_DW.IC111_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC111_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_bSOV_Eva_Req' */
    Sokon_X01_Thm_Y.THM_Out_bSOV_Eva_Req = true;
  } else {
    /* Outport: '<Root>/THM_Out_bSOV_Eva_Req' */
    Sokon_X01_Thm_Y.THM_Out_bSOV_Eva_Req = rtb_Compare_h;
  }

  /* End of InitialCondition: '<Root>/IC111' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_28' */
  rtb_Compare_h = ( Sokon_X01_Thm_DataTypeConv_b_
                   (Sokon_X01_Thm_B.HpO_bSOV_OutEva_Req) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_28' */

  /* InitialCondition: '<Root>/IC112' */
  if (Sokon_X01_Thm_DW.IC112_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC112_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_bSOV_OutEva_Req' */
    Sokon_X01_Thm_Y.THM_Out_bSOV_OutEva_Req = true;
  } else {
    /* Outport: '<Root>/THM_Out_bSOV_OutEva_Req' */
    Sokon_X01_Thm_Y.THM_Out_bSOV_OutEva_Req = rtb_Compare_h;
  }

  /* End of InitialCondition: '<Root>/IC112' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_29' */
  rtb_Compare_h = ( Sokon_X01_Thm_DataTypeConv_b_
                   (Sokon_X01_Thm_B.HpO_bSOV_TXVOutEva_Req) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_29' */

  /* InitialCondition: '<Root>/IC113' */
  if (Sokon_X01_Thm_DW.IC113_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC113_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_bSOV_TXVOutEva_Req' */
    Sokon_X01_Thm_Y.THM_Out_bSOV_TXVOutEva_Req = true;
  } else {
    /* Outport: '<Root>/THM_Out_bSOV_TXVOutEva_Req' */
    Sokon_X01_Thm_Y.THM_Out_bSOV_TXVOutEva_Req = rtb_Compare_h;
  }

  /* End of InitialCondition: '<Root>/IC113' */

  /* Saturate: '<Root>/Saturation84' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u16EXV_Eva_Pos_Req) < 576) {
    rtb_IC81 = Sokon_X01_Thm_B.HpO_u16EXV_Eva_Pos_Req;
  } else {
    rtb_IC81 = 576U;
  }

  /* End of Saturate: '<Root>/Saturation84' */

  /* InitialCondition: '<Root>/IC114' */
  if (Sokon_X01_Thm_DW.IC114_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC114_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u16EXV_Eva_Pos_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16EXV_Eva_Pos_Req = 50U;
  } else {
    /* Outport: '<Root>/THM_Out_u16EXV_Eva_Pos_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16EXV_Eva_Pos_Req = rtb_IC81;
  }

  /* End of InitialCondition: '<Root>/IC114' */

  /* Saturate: '<Root>/Saturation85' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u16EXV_Chil_Pos_Req) < 576) {
    rtb_IC81 = Sokon_X01_Thm_B.HpO_u16EXV_Chil_Pos_Req;
  } else {
    rtb_IC81 = 576U;
  }

  /* End of Saturate: '<Root>/Saturation85' */

  /* InitialCondition: '<Root>/IC115' */
  if (Sokon_X01_Thm_DW.IC115_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC115_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u16EXV_Chil_Pos_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16EXV_Chil_Pos_Req = 50U;
  } else {
    /* Outport: '<Root>/THM_Out_u16EXV_Chil_Pos_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16EXV_Chil_Pos_Req = rtb_IC81;
  }

  /* End of InitialCondition: '<Root>/IC115' */

  /* Saturate: '<Root>/Saturation86' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8HpWorkMode_Req) < 30) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8HpWorkMode_Req;
  } else {
    rtb_IC9 = 30U;
  }

  /* End of Saturate: '<Root>/Saturation86' */

  /* InitialCondition: '<Root>/IC116' */
  if (Sokon_X01_Thm_DW.IC116_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC116_FirstOutputTime = false;
    Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req = 0U;
  } else {
    Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC116' */

  /* Outport: '<Root>/THM_Out_u8HpWorkMode_Req' */
  Sokon_X01_Thm_Y.THM_Out_u8HpWorkMode_Req =
    Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req;

  /* Saturate: '<Root>/Saturation87' */
  if (((int32_T)Sokon_X01_Thm_B.HpI_u8AGS_Position_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpI_u8AGS_Position_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation87' */

  /* InitialCondition: '<Root>/IC117' */
  if (Sokon_X01_Thm_DW.IC117_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC117_FirstOutputTime = false;
    Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req = 100U;
  } else {
    Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC117' */

  /* Outport: '<Root>/THM_Out_u8AGS_Position_Req' */
  Sokon_X01_Thm_Y.THM_Out_u8AGS_Position_Req =
    Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req;

  /* Saturate: '<Root>/Saturation88' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8FRFAN_PWM_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8FRFAN_PWM_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation88' */

  /* InitialCondition: '<Root>/IC118' */
  if (Sokon_X01_Thm_DW.IC118_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC118_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8FRFAN_PWM_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8FRFAN_PWM_Req = 20U;
  } else {
    /* Outport: '<Root>/THM_Out_u8FRFAN_PWM_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8FRFAN_PWM_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC118' */

  /* Saturate: '<Root>/Saturation89' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8Mix_Left_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8Mix_Left_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation89' */

  /* InitialCondition: '<Root>/IC119' */
  if (Sokon_X01_Thm_DW.IC119_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC119_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8Mix_Left_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8Mix_Left_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8Mix_Left_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8Mix_Left_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC119' */

  /* Saturate: '<Root>/Saturation90' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8Mix_Right_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8Mix_Right_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation90' */

  /* InitialCondition: '<Root>/IC120' */
  if (Sokon_X01_Thm_DW.IC120_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC120_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8Mix_Right_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8Mix_Right_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8Mix_Right_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8Mix_Right_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC120' */

  /* Saturate: '<Root>/Saturation91' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8DTC_Ref_System) < 1) {
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = 1U;
  }

  /* End of Saturate: '<Root>/Saturation91' */

  /* InitialCondition: '<Root>/IC121' */
  if (Sokon_X01_Thm_DW.IC121_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC121_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8DTC_Ref_System' */
    Sokon_X01_Thm_Y.THM_Out_u8DTC_Ref_System = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8DTC_Ref_System' */
    Sokon_X01_Thm_Y.THM_Out_u8DTC_Ref_System = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC121' */

  /* Saturate: '<Root>/Saturation92' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8DTC_Ref_Component) < 1) {
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = 1U;
  }

  /* End of Saturate: '<Root>/Saturation92' */

  /* InitialCondition: '<Root>/IC122' */
  if (Sokon_X01_Thm_DW.IC122_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC122_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8DTC_Ref_Component' */
    Sokon_X01_Thm_Y.THM_Out_u8DTC_Ref_Component = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8DTC_Ref_Component' */
    Sokon_X01_Thm_Y.THM_Out_u8DTC_Ref_Component = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC122' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_30' */
  rtb_Compare_o = ( Sokon_X01_Thm_DataTypeConv_b_
                   (Sokon_X01_Thm_B.HpO_bDTC_EvaFreeze) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_30' */

  /* InitialCondition: '<Root>/IC123' */
  if (Sokon_X01_Thm_DW.IC123_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC123_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_bDTC_EvaFreeze' */
    Sokon_X01_Thm_Y.THM_Out_bDTC_EvaFreeze = false;
  } else {
    /* Outport: '<Root>/THM_Out_bDTC_EvaFreeze' */
    Sokon_X01_Thm_Y.THM_Out_bDTC_EvaFreeze = rtb_Compare_o;
  }

  /* End of InitialCondition: '<Root>/IC123' */

  /* Outputs for Atomic SubSystem: '<Root>/DataTypeConv_b_31' */
  rtb_Compare_o = ( Sokon_X01_Thm_DataTypeConv_b_
                   (Sokon_X01_Thm_B.HpO_bDTC_OutEvaFreeze) != false);

  /* End of Outputs for SubSystem: '<Root>/DataTypeConv_b_31' */

  /* InitialCondition: '<Root>/IC124' */
  if (Sokon_X01_Thm_DW.IC124_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC124_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_bDTC_OutEvaFreeze' */
    Sokon_X01_Thm_Y.THM_Out_bDTC_OutEvaFreeze = false;
  } else {
    /* Outport: '<Root>/THM_Out_bDTC_OutEvaFreeze' */
    Sokon_X01_Thm_Y.THM_Out_bDTC_OutEvaFreeze = rtb_Compare_o;
  }

  /* End of InitialCondition: '<Root>/IC124' */

  /* Saturate: '<Root>/Saturation93' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8TWValve_HC_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8TWValve_HC_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation93' */

  /* InitialCondition: '<Root>/IC125' */
  if (Sokon_X01_Thm_DW.IC125_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC125_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8TWValve_HC_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8TWValve_HC_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8TWValve_HC_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8TWValve_HC_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC125' */

  /* Saturate: '<Root>/Saturation94' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8TWValve_LTR_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8TWValve_LTR_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation94' */

  /* InitialCondition: '<Root>/IC126' */
  if (Sokon_X01_Thm_DW.IC126_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC126_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8TWValve_LTR_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8TWValve_LTR_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8TWValve_LTR_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8TWValve_LTR_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC126' */

  /* Saturate: '<Root>/Saturation95' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8TWValve_BAT_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8TWValve_BAT_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation95' */

  /* InitialCondition: '<Root>/IC127' */
  if (Sokon_X01_Thm_DW.IC127_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC127_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8TWValve_BAT_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8TWValve_BAT_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8TWValve_BAT_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8TWValve_BAT_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC127' */

  /* Saturate: '<Root>/Saturation96' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u8HVCH_Req) < 100) {
    rtb_IC9 = Sokon_X01_Thm_B.HpO_u8HVCH_Req;
  } else {
    rtb_IC9 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation96' */

  /* InitialCondition: '<Root>/IC128' */
  if (Sokon_X01_Thm_DW.IC128_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC128_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8HVCH_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8HVCH_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u8HVCH_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8HVCH_Req = rtb_IC9;
  }

  /* End of InitialCondition: '<Root>/IC128' */

  /* Saturate: '<Root>/Saturation97' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u16Pump_HVCH_Req) < 100) {
    rtb_IC81 = Sokon_X01_Thm_B.HpO_u16Pump_HVCH_Req;
  } else {
    rtb_IC81 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation97' */

  /* InitialCondition: '<Root>/IC129' */
  if (Sokon_X01_Thm_DW.IC129_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC129_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u16Pump_HVCH_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Pump_HVCH_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u16Pump_HVCH_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Pump_HVCH_Req = rtb_IC81;
  }

  /* End of InitialCondition: '<Root>/IC129' */

  /* Saturate: '<Root>/Saturation98' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u16Pump_Motor_Req) < 100) {
    rtb_IC81 = Sokon_X01_Thm_B.HpO_u16Pump_Motor_Req;
  } else {
    rtb_IC81 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation98' */

  /* InitialCondition: '<Root>/IC130' */
  if (Sokon_X01_Thm_DW.IC130_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC130_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u16Pump_Motor_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Pump_Motor_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u16Pump_Motor_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Pump_Motor_Req = rtb_IC81;
  }

  /* End of InitialCondition: '<Root>/IC130' */

  /* Saturate: '<Root>/Saturation99' */
  if (((int32_T)Sokon_X01_Thm_B.HpO_u16Pump_Bat_Req) < 100) {
    rtb_IC81 = Sokon_X01_Thm_B.HpO_u16Pump_Bat_Req;
  } else {
    rtb_IC81 = 100U;
  }

  /* End of Saturate: '<Root>/Saturation99' */

  /* InitialCondition: '<Root>/IC131' */
  if (Sokon_X01_Thm_DW.IC131_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC131_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u16Pump_Bat_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Pump_Bat_Req = 0U;
  } else {
    /* Outport: '<Root>/THM_Out_u16Pump_Bat_Req' */
    Sokon_X01_Thm_Y.THM_Out_u16Pump_Bat_Req = rtb_IC81;
  }

  /* End of InitialCondition: '<Root>/IC131' */

  /* InitialCondition: '<Root>/IC107' */
  if (Sokon_X01_Thm_DW.IC107_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC107_FirstOutputTime = false;

    /* Outport: '<Root>/THM_Out_u8HVACIntake_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8HVACIntake_Req = 100U;
  } else {
    /* Outport: '<Root>/THM_Out_u8HVACIntake_Req' */
    Sokon_X01_Thm_Y.THM_Out_u8HVACIntake_Req =
      Sokon_X01_Thm_B.CmfO_u8HVACIntake_Req;
  }

  /* End of InitialCondition: '<Root>/IC107' */

  /* InitialCondition: '<Root>/IC16' incorporates:
   *  Inport: '<Root>/THM_In_s16Teva_Rear_A10'
   */
  if (Sokon_X01_Thm_DW.IC16_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC16_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16Teva_Rear_A10;
  }

  /* End of InitialCondition: '<Root>/IC16' */

  /* Saturate: '<Root>/Saturation15' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation15' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter1' */
  /* Constant: '<S82>/Constant2' */
  rtb_Conversion_o = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_15s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter1,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter1, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter1' */

  /* InitialCondition: '<Root>/IC28' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_3Z_V_A10'
   */
  if (Sokon_X01_Thm_DW.IC28_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC28_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TDuct_3Z_V_A10;
  }

  /* End of InitialCondition: '<Root>/IC28' */

  /* Saturate: '<Root>/Saturation27' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation27' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter10' */
  /* Constant: '<S82>/Constant15' */
  rtb_Conversion_d = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter10,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter10, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter10' */

  /* InitialCondition: '<Root>/IC29' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_3Z_F_A10'
   */
  if (Sokon_X01_Thm_DW.IC29_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC29_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TDuct_3Z_F_A10;
  }

  /* End of InitialCondition: '<Root>/IC29' */

  /* Saturate: '<Root>/Saturation28' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation28' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter11' */
  /* Constant: '<S82>/Constant16' */
  rtb_Conversion_b5 = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter11,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter11, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter11' */

  /* InitialCondition: '<Root>/IC30' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_4Z_V_A10'
   */
  if (Sokon_X01_Thm_DW.IC30_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC30_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TDuct_4Z_V_A10;
  }

  /* End of InitialCondition: '<Root>/IC30' */

  /* Saturate: '<Root>/Saturation29' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation29' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter12' */
  /* Constant: '<S82>/Constant17' */
  rtb_Conversion_i = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter12,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter12, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter12' */

  /* InitialCondition: '<Root>/IC31' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_4Z_F_A10'
   */
  if (Sokon_X01_Thm_DW.IC31_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC31_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TDuct_4Z_F_A10;
  }

  /* End of InitialCondition: '<Root>/IC31' */

  /* Saturate: '<Root>/Saturation30' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation30' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter13' */
  /* Constant: '<S82>/Constant18' */
  rtb_Conversion_np = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter13,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter13, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter13' */

  /* InitialCondition: '<Root>/IC22' incorporates:
   *  Inport: '<Root>/THM_In_s16Tincar_Rear_A10'
   */
  if (Sokon_X01_Thm_DW.IC22_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC22_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16Tincar_Rear_A10;
  }

  /* End of InitialCondition: '<Root>/IC22' */

  /* Saturate: '<Root>/Saturation21' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation21' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter4' */
  /* Constant: '<S82>/Constant9' */
  rtb_Conversion_gl = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_15s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter4,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter4, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter4' */

  /* InitialCondition: '<Root>/IC23' incorporates:
   *  Inport: '<Root>/THM_In_s16T_Wat_MotorIn_A10'
   */
  if (Sokon_X01_Thm_DW.IC23_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC23_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16T_Wat_MotorIn_A10;
  }

  /* End of InitialCondition: '<Root>/IC23' */

  /* Saturate: '<Root>/Saturation22' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation22' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter5' */
  /* Constant: '<S82>/Constant10' */
  rtb_Conversion_nb = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter5,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter5, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter5' */

  /* InitialCondition: '<Root>/IC27' incorporates:
   *  Inport: '<Root>/THM_In_s16TDuct_RF_A10'
   */
  if (Sokon_X01_Thm_DW.IC27_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC27_FirstOutputTime = false;
    rtb_IC72 = 200;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TDuct_RF_A10;
  }

  /* End of InitialCondition: '<Root>/IC27' */

  /* Saturate: '<Root>/Saturation26' */
  y = rtb_IC72;
  if (y > 1500) {
    y = 1500;
  } else {
    if (y < -500) {
      y = -500;
    }
  }

  /* End of Saturate: '<Root>/Saturation26' */

  /* Outputs for Atomic SubSystem: '<S82>/FirOrderLinear_Filter9' */
  /* Constant: '<S82>/Constant14' */
  rtb_Conversion_g = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_6s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter9,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter9, 100);

  /* End of Outputs for SubSystem: '<S82>/FirOrderLinear_Filter9' */

  /* InitialCondition: '<Root>/IC70' incorporates:
   *  Inport: '<Root>/THM_In_s16TbatMax_A10'
   */
  if (Sokon_X01_Thm_DW.IC70_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC70_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TbatMax_A10;
  }

  /* End of InitialCondition: '<Root>/IC70' */

  /* Saturate: '<Root>/Saturation64' */
  y = rtb_IC72;
  if (y > 870) {
    y = 870;
  } else {
    if (y < -400) {
      y = -400;
    }
  }

  /* End of Saturate: '<Root>/Saturation64' */

  /* Outputs for Atomic SubSystem: '<S85>/FirOrderLinear_Filter3' */
  /* Constant: '<S85>/Constant3' */
  rtb_Conversion_m = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter3_j,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter3_j, 100);

  /* End of Outputs for SubSystem: '<S85>/FirOrderLinear_Filter3' */

  /* InitialCondition: '<Root>/IC71' incorporates:
   *  Inport: '<Root>/THM_In_s16TbatAvr_A10'
   */
  if (Sokon_X01_Thm_DW.IC71_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC71_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TbatAvr_A10;
  }

  /* End of InitialCondition: '<Root>/IC71' */

  /* Saturate: '<Root>/Saturation65' */
  y = rtb_IC72;
  if (y > 870) {
    y = 870;
  } else {
    if (y < -400) {
      y = -400;
    }
  }

  /* End of Saturate: '<Root>/Saturation65' */

  /* Outputs for Atomic SubSystem: '<S85>/FirOrderLinear_Filter4' */
  /* Constant: '<S85>/Constant4' */
  rtb_Conversion_b = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter4_ox,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter4_ox, 100);

  /* End of Outputs for SubSystem: '<S85>/FirOrderLinear_Filter4' */

  /* InitialCondition: '<Root>/IC72' incorporates:
   *  Inport: '<Root>/THM_In_s16TbatMin_A10'
   */
  if (Sokon_X01_Thm_DW.IC72_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC72_FirstOutputTime = false;
    rtb_IC72 = 300;
  } else {
    rtb_IC72 = Sokon_X01_Thm_U.THM_In_s16TbatMin_A10;
  }

  /* End of InitialCondition: '<Root>/IC72' */

  /* Saturate: '<Root>/Saturation66' */
  y = rtb_IC72;
  if (y > 870) {
    y = 870;
  } else {
    if (y < -400) {
      y = -400;
    }
  }

  /* End of Saturate: '<Root>/Saturation66' */

  /* Outputs for Atomic SubSystem: '<S85>/FirOrderLinear_Filter5' */
  /* Constant: '<S85>/Constant5' */
  rtb_Conversion_n = (int16_T) Sokon_X01_Thm_FirOrderLinear_Filter(y, rtb_IC4,
    CmfThm_u8Filter_3s, &Sokon_X01_Thm_ConstB.FirOrderLinear_Filter5_a,
    &Sokon_X01_Thm_DW.FirOrderLinear_Filter5_a, 100);

  /* End of Outputs for SubSystem: '<S85>/FirOrderLinear_Filter5' */

  /* InitialCondition: '<Root>/IC11' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeMASts_2Z'
   */
  if (Sokon_X01_Thm_DW.IC11_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC11_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8ModeMASts_2Z;
  }

  /* End of InitialCondition: '<Root>/IC11' */

  /* Saturate: '<Root>/Saturation10' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8ModeMASts_2Z = rtb_IC9;
  } else {
    rtb_THM_In_u8ModeMASts_2Z = 7U;
  }

  /* End of Saturate: '<Root>/Saturation10' */

  /* InitialCondition: '<Root>/IC12' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeMASts_3Z'
   */
  if (Sokon_X01_Thm_DW.IC12_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC12_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8ModeMASts_3Z;
  }

  /* End of InitialCondition: '<Root>/IC12' */

  /* Saturate: '<Root>/Saturation11' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8ModeMASts_3Z = rtb_IC9;
  } else {
    rtb_THM_In_u8ModeMASts_3Z = 7U;
  }

  /* End of Saturate: '<Root>/Saturation11' */

  /* InitialCondition: '<Root>/IC13' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeMASts_4Z'
   */
  if (Sokon_X01_Thm_DW.IC13_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC13_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8ModeMASts_4Z;
  }

  /* End of InitialCondition: '<Root>/IC13' */

  /* Saturate: '<Root>/Saturation12' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8ModeMASts_4Z = rtb_IC9;
  } else {
    rtb_THM_In_u8ModeMASts_4Z = 7U;
  }

  /* End of Saturate: '<Root>/Saturation12' */

  /* InitialCondition: '<Root>/IC2' incorporates:
   *  Inport: '<Root>/THM_In_u16Tset_3Z_A10'
   */
  if (Sokon_X01_Thm_DW.IC2_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC2_FirstOutputTime = false;
    rtb_IC81 = 240U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16Tset_3Z_A10;
  }

  /* End of InitialCondition: '<Root>/IC2' */

  /* Saturate: '<Root>/Saturation2' */
  if (((int32_T)rtb_IC81) > 330) {
    rtb_THM_In_u16Tset_3Z_A10 = 330U;
  } else if (((int32_T)rtb_IC81) < 180) {
    rtb_THM_In_u16Tset_3Z_A10 = 180U;
  } else {
    rtb_THM_In_u16Tset_3Z_A10 = rtb_IC81;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* InitialCondition: '<Root>/IC3' incorporates:
   *  Inport: '<Root>/THM_In_u16Tset_4Z_A10'
   */
  if (Sokon_X01_Thm_DW.IC3_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC3_FirstOutputTime = false;
    rtb_IC81 = 240U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16Tset_4Z_A10;
  }

  /* End of InitialCondition: '<Root>/IC3' */

  /* Saturate: '<Root>/Saturation3' */
  if (((int32_T)rtb_IC81) > 330) {
    rtb_THM_In_u16Tset_4Z_A10 = 330U;
  } else if (((int32_T)rtb_IC81) < 180) {
    rtb_THM_In_u16Tset_4Z_A10 = 180U;
  } else {
    rtb_THM_In_u16Tset_4Z_A10 = rtb_IC81;
  }

  /* End of Saturate: '<Root>/Saturation3' */

  /* InitialCondition: '<Root>/IC32' incorporates:
   *  Inport: '<Root>/THM_In_u8BlwLv_Real'
   */
  if (Sokon_X01_Thm_DW.IC32_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC32_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8BlwLv_Real;
  }

  /* End of InitialCondition: '<Root>/IC32' */

  /* Saturate: '<Root>/Saturation31' */
  if (((int32_T)rtb_IC9) < 10) {
    rtb_THM_In_u8BlwLv_Real = rtb_IC9;
  } else {
    rtb_THM_In_u8BlwLv_Real = 10U;
  }

  /* End of Saturate: '<Root>/Saturation31' */

  /* InitialCondition: '<Root>/IC34' incorporates:
   *  Inport: '<Root>/THM_In_u8RearBlwVol_Real_A10'
   */
  if (Sokon_X01_Thm_DW.IC34_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC34_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8RearBlwVol_Real_A10;
  }

  /* End of InitialCondition: '<Root>/IC34' */

  /* Saturate: '<Root>/Saturation33' */
  if (((int32_T)rtb_IC9) < 120) {
    rtb_THM_In_u8RearBlwVol_Real_A10 = rtb_IC9;
  } else {
    rtb_THM_In_u8RearBlwVol_Real_A10 = 120U;
  }

  /* End of Saturate: '<Root>/Saturation33' */

  /* InitialCondition: '<Root>/IC36' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeStatus_2Z_Real'
   */
  if (Sokon_X01_Thm_DW.IC36_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC36_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8ModeStatus_2Z_Real;
  }

  /* End of InitialCondition: '<Root>/IC36' */

  /* Saturate: '<Root>/Saturation35' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8ModeStatus_2Z_Real = rtb_IC9;
  } else {
    rtb_THM_In_u8ModeStatus_2Z_Real = 7U;
  }

  /* End of Saturate: '<Root>/Saturation35' */

  /* InitialCondition: '<Root>/IC37' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeStatus_3Z_Real'
   */
  if (Sokon_X01_Thm_DW.IC37_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC37_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8ModeStatus_3Z_Real;
  }

  /* End of InitialCondition: '<Root>/IC37' */

  /* Saturate: '<Root>/Saturation36' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8ModeStatus_3Z_Real = rtb_IC9;
  } else {
    rtb_THM_In_u8ModeStatus_3Z_Real = 7U;
  }

  /* End of Saturate: '<Root>/Saturation36' */

  /* InitialCondition: '<Root>/IC38' incorporates:
   *  Inport: '<Root>/THM_In_u8ModeStatus_4Z_Real'
   */
  if (Sokon_X01_Thm_DW.IC38_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC38_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8ModeStatus_4Z_Real;
  }

  /* End of InitialCondition: '<Root>/IC38' */

  /* Saturate: '<Root>/Saturation37' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8ModeStatus_4Z_Real = rtb_IC9;
  } else {
    rtb_THM_In_u8ModeStatus_4Z_Real = 7U;
  }

  /* End of Saturate: '<Root>/Saturation37' */

  /* InitialCondition: '<Root>/IC43' incorporates:
   *  Inport: '<Root>/THM_In_u8ECM_Engine_Status'
   */
  if (Sokon_X01_Thm_DW.IC43_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC43_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8ECM_Engine_Status;
  }

  /* End of InitialCondition: '<Root>/IC43' */

  /* Saturate: '<Root>/Saturation41' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8ECM_Engine_Status = rtb_IC9;
  } else {
    rtb_THM_In_u8ECM_Engine_Status = 7U;
  }

  /* End of Saturate: '<Root>/Saturation41' */

  /* InitialCondition: '<Root>/IC6' incorporates:
   *  Inport: '<Root>/THM_In_u8BlwMASts_2Z'
   */
  if (Sokon_X01_Thm_DW.IC6_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC6_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8BlwMASts_2Z;
  }

  /* End of InitialCondition: '<Root>/IC6' */

  /* Saturate: '<Root>/Saturation5' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8BlwMASts_2Z = rtb_IC9;
  } else {
    rtb_THM_In_u8BlwMASts_2Z = 7U;
  }

  /* End of Saturate: '<Root>/Saturation5' */

  /* InitialCondition: '<Root>/IC61' incorporates:
   *  Inport: '<Root>/THM_In_u16EXV_Eva_Pos'
   */
  if (Sokon_X01_Thm_DW.IC61_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC61_FirstOutputTime = false;
    rtb_IC81 = 50U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16EXV_Eva_Pos;
  }

  /* End of InitialCondition: '<Root>/IC61' */

  /* Saturate: '<Root>/Saturation55' */
  if (((int32_T)rtb_IC81) < 640) {
    rtb_THM_In_u16EXV_Eva_Pos = rtb_IC81;
  } else {
    rtb_THM_In_u16EXV_Eva_Pos = 640U;
  }

  /* End of Saturate: '<Root>/Saturation55' */

  /* InitialCondition: '<Root>/IC64' incorporates:
   *  Inport: '<Root>/THM_In_u8Mix_Flap_Position_R'
   */
  if (Sokon_X01_Thm_DW.IC64_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC64_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_R;
  }

  /* End of InitialCondition: '<Root>/IC64' */

  /* Saturate: '<Root>/Saturation58' */
  if (((int32_T)rtb_IC9) < 100) {
    rtb_THM_In_u8Mix_Flap_Position_R = rtb_IC9;
  } else {
    rtb_THM_In_u8Mix_Flap_Position_R = 100U;
  }

  /* End of Saturate: '<Root>/Saturation58' */

  /* InitialCondition: '<Root>/IC65' incorporates:
   *  Inport: '<Root>/THM_In_u16Rainfall'
   */
  if (Sokon_X01_Thm_DW.IC65_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC65_FirstOutputTime = false;
    rtb_IC81 = 0U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16Rainfall;
  }

  /* End of InitialCondition: '<Root>/IC65' */

  /* Saturate: '<Root>/Saturation59' */
  if (((int32_T)rtb_IC81) < 500) {
    rtb_THM_In_u16Rainfall = rtb_IC81;
  } else {
    rtb_THM_In_u16Rainfall = 500U;
  }

  /* End of Saturate: '<Root>/Saturation59' */

  /* InitialCondition: '<Root>/IC66' incorporates:
   *  Inport: '<Root>/THM_In_u16Solar'
   */
  if (Sokon_X01_Thm_DW.IC66_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC66_FirstOutputTime = false;
    rtb_IC81 = 0U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16Solar;
  }

  /* End of InitialCondition: '<Root>/IC66' */

  /* Saturate: '<Root>/Saturation60' */
  if (((int32_T)rtb_IC81) < 1500) {
    rtb_THM_In_u16Solar = rtb_IC81;
  } else {
    rtb_THM_In_u16Solar = 1500U;
  }

  /* End of Saturate: '<Root>/Saturation60' */

  /* InitialCondition: '<Root>/IC7' incorporates:
   *  Inport: '<Root>/THM_In_u8BlwMASts_3Z'
   */
  if (Sokon_X01_Thm_DW.IC7_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC7_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8BlwMASts_3Z;
  }

  /* End of InitialCondition: '<Root>/IC7' */

  /* Saturate: '<Root>/Saturation6' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8BlwMASts_3Z = rtb_IC9;
  } else {
    rtb_THM_In_u8BlwMASts_3Z = 7U;
  }

  /* End of Saturate: '<Root>/Saturation6' */

  /* InitialCondition: '<Root>/IC76' incorporates:
   *  Inport: '<Root>/THM_In_u8TWValve_HC_Position'
   */
  if (Sokon_X01_Thm_DW.IC76_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC76_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8TWValve_HC_Position;
  }

  /* End of InitialCondition: '<Root>/IC76' */

  /* Saturate: '<Root>/Saturation70' */
  if (((int32_T)rtb_IC9) < 100) {
    rtb_THM_In_u8TWValve_HC_Position = rtb_IC9;
  } else {
    rtb_THM_In_u8TWValve_HC_Position = 100U;
  }

  /* End of Saturate: '<Root>/Saturation70' */

  /* InitialCondition: '<Root>/IC77' incorporates:
   *  Inport: '<Root>/THM_In_u8TWValve_LTR_Position'
   */
  if (Sokon_X01_Thm_DW.IC77_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC77_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8TWValve_LTR_Position;
  }

  /* End of InitialCondition: '<Root>/IC77' */

  /* Saturate: '<Root>/Saturation71' */
  if (((int32_T)rtb_IC9) < 100) {
    rtb_THM_In_u8TWValve_LTR_Position = rtb_IC9;
  } else {
    rtb_THM_In_u8TWValve_LTR_Position = 100U;
  }

  /* End of Saturate: '<Root>/Saturation71' */

  /* InitialCondition: '<Root>/IC78' incorporates:
   *  Inport: '<Root>/THM_In_u8TWValve_BAT_Position'
   */
  if (Sokon_X01_Thm_DW.IC78_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC78_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8TWValve_BAT_Position;
  }

  /* End of InitialCondition: '<Root>/IC78' */

  /* Saturate: '<Root>/Saturation72' */
  if (((int32_T)rtb_IC9) < 100) {
    rtb_THM_In_u8TWValve_BAT_Position = rtb_IC9;
  } else {
    rtb_THM_In_u8TWValve_BAT_Position = 100U;
  }

  /* End of Saturate: '<Root>/Saturation72' */

  /* InitialCondition: '<Root>/IC79' incorporates:
   *  Inport: '<Root>/THM_In_u8HVCH_Status'
   */
  if (Sokon_X01_Thm_DW.IC79_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC79_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8HVCH_Status;
  }

  /* End of InitialCondition: '<Root>/IC79' */

  /* Saturate: '<Root>/Saturation73' */
  if (((int32_T)rtb_IC9) < 100) {
    rtb_THM_In_u8HVCH_Status = rtb_IC9;
  } else {
    rtb_THM_In_u8HVCH_Status = 100U;
  }

  /* End of Saturate: '<Root>/Saturation73' */

  /* InitialCondition: '<Root>/IC8' incorporates:
   *  Inport: '<Root>/THM_In_u8BlwMASts_4Z'
   */
  if (Sokon_X01_Thm_DW.IC8_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC8_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8BlwMASts_4Z;
  }

  /* End of InitialCondition: '<Root>/IC8' */

  /* Saturate: '<Root>/Saturation7' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8BlwMASts_4Z = rtb_IC9;
  } else {
    rtb_THM_In_u8BlwMASts_4Z = 7U;
  }

  /* End of Saturate: '<Root>/Saturation7' */

  /* InitialCondition: '<Root>/IC80' incorporates:
   *  Inport: '<Root>/THM_In_u16Pump_HVCH'
   */
  if (Sokon_X01_Thm_DW.IC80_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC80_FirstOutputTime = false;
    rtb_IC81 = 0U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16Pump_HVCH;
  }

  /* End of InitialCondition: '<Root>/IC80' */

  /* Saturate: '<Root>/Saturation74' */
  if (((int32_T)rtb_IC81) < 100) {
    rtb_THM_In_u16Pump_HVCH = rtb_IC81;
  } else {
    rtb_THM_In_u16Pump_HVCH = 100U;
  }

  /* End of Saturate: '<Root>/Saturation74' */

  /* InitialCondition: '<Root>/IC81' incorporates:
   *  Inport: '<Root>/THM_In_u16Pump_Motor'
   */
  if (Sokon_X01_Thm_DW.IC81_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC81_FirstOutputTime = false;
    rtb_IC81 = 49U;
  } else {
    rtb_IC81 = Sokon_X01_Thm_U.THM_In_u16Pump_Motor;
  }

  /* End of InitialCondition: '<Root>/IC81' */

  /* Saturate: '<Root>/Saturation75' */
  if (((int32_T)rtb_IC81) < 100) {
    rtb_THM_In_u16Pump_Motor = rtb_IC81;
  } else {
    rtb_THM_In_u16Pump_Motor = 100U;
  }

  /* End of Saturate: '<Root>/Saturation75' */

  /* InitialCondition: '<Root>/IC9' incorporates:
   *  Inport: '<Root>/THM_In_u8BlwUserHabit'
   */
  if (Sokon_X01_Thm_DW.IC9_FirstOutputTime) {
    Sokon_X01_Thm_DW.IC9_FirstOutputTime = false;
    rtb_IC9 = 0U;
  } else {
    rtb_IC9 = Sokon_X01_Thm_U.THM_In_u8BlwUserHabit;
  }

  /* End of InitialCondition: '<Root>/IC9' */

  /* Saturate: '<Root>/Saturation8' */
  if (((int32_T)rtb_IC9) < 7) {
    rtb_THM_In_u8BlwUserHabit = rtb_IC9;
  } else {
    rtb_THM_In_u8BlwUserHabit = 7U;
  }

  /* End of Saturate: '<Root>/Saturation8' */

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  Sokon_X01_Thm_DW.UnitDelay_36_DSTATE = Sokon_X01_Thm_B.HpO_u8HpWorkMode_Req;
}

/* Model initialize function */
void Sokon_X01_Thm_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &Sokon_X01_Thm_B), 0,
                sizeof(B_Sokon_X01_Thm_T));

  /* states (dwork) */
  (void) memset((void *)&Sokon_X01_Thm_DW, 0,
                sizeof(DW_Sokon_X01_Thm_T));

  /* external inputs */
  (void)memset(&Sokon_X01_Thm_U, 0, sizeof(ExtU_Sokon_X01_Thm_T));

  /* external outputs */
  (void) memset((void *)&Sokon_X01_Thm_Y, 0,
                sizeof(ExtY_Sokon_X01_Thm_T));

  /* Model Initialize function for ModelReference Block: '<S35>/CMF' */
  Sokon_X01_Cmf_initialize();

  /* Model Initialize function for ModelReference Block: '<S35>/HP' */
  Chery_E03_Hp_initialize();

  /* Start for InitialCondition: '<Root>/IC' */
  Sokon_X01_Thm_DW.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC1' */
  Sokon_X01_Thm_DW.IC1_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC4' */
  Sokon_X01_Thm_DW.IC4_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC5' */
  Sokon_X01_Thm_DW.IC5_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC10' */
  Sokon_X01_Thm_DW.IC10_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC14' */
  Sokon_X01_Thm_DW.IC14_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC17' */
  Sokon_X01_Thm_DW.IC17_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC18' */
  Sokon_X01_Thm_DW.IC18_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC19' */
  Sokon_X01_Thm_DW.IC19_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC20' */
  Sokon_X01_Thm_DW.IC20_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC21' */
  Sokon_X01_Thm_DW.IC21_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC24' */
  Sokon_X01_Thm_DW.IC24_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC25' */
  Sokon_X01_Thm_DW.IC25_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC26' */
  Sokon_X01_Thm_DW.IC26_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC35' */
  Sokon_X01_Thm_DW.IC35_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC39' */
  Sokon_X01_Thm_B.THM_Out_u8AGS_Position_Req = 0U;
  Sokon_X01_Thm_DW.IC39_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC40' */
  Sokon_X01_Thm_B.THM_Out_u8HpWorkMode_Req = 0U;
  Sokon_X01_Thm_DW.IC40_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC41' */
  Sokon_X01_Thm_DW.IC41_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC42' */
  Sokon_X01_Thm_DW.IC42_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC44' */
  Sokon_X01_Thm_DW.IC44_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC45' */
  Sokon_X01_Thm_DW.IC45_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC46' */
  Sokon_X01_Thm_DW.IC46_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC55' */
  Sokon_X01_Thm_DW.IC55_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC63' */
  Sokon_X01_Thm_DW.IC63_FirstOutputTime = true;

  /* Start for ModelReference: '<S35>/CMF' */
  Sokon_X01_Cmf_Start(&Sokon_X01_Thm_B.CmfO_u8HVACMode_Req,
                      &Sokon_X01_Thm_B.CmfO_u8HVACIntake_Req,
                      &Sokon_X01_Thm_B.CmfO_u8HVACBlwVol_Req_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Tasd_Left_Req_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Tasd_Right_Req_A10,
                      &Sokon_X01_Thm_B.CmfO_s16TDuct_Left_Out_A10,
                      &Sokon_X01_Thm_B.CmfO_s16TDuct_Right_Out_A10,
                      &Sokon_X01_Thm_B.CmfO_u8TevaSet_Req_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Tincar_Setting_Req_A10,
                      &Sokon_X01_Thm_B.CmfO_bFlag_HeatShort_Blw_Req,
                      &Sokon_X01_Thm_B.CmfO_u16Debug_TasdLStatic_A10,
                      &Sokon_X01_Thm_B.CmfO_u16Debug_TasdRStatic_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Debug_TasdLSolarCmp_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Debug_TasdDefCmp_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Debug_TasdEcoCmp_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Debug_TasdDyn_A10,
                      &Sokon_X01_Thm_B.CmfO_u8Debug_BlwStatic_A10,
                      &Sokon_X01_Thm_B.CmfO_s8Debug_BlwVspCmp_A10,
                      &Sokon_X01_Thm_B.CmfO_s8Debug_BlwSolarCmp_A10,
                      &Sokon_X01_Thm_B.CmfO_s8Debug_BlwDyn_A10,
                      &Sokon_X01_Thm_B.CmfO_u8Debug_IntkStatic,
                      &Sokon_X01_Thm_B.CmfO_s8Debug_IntkDyn,
                      &Sokon_X01_Thm_B.CmfO_u8Debug_ModePerStatic,
                      &Sokon_X01_Thm_B.CmfO_s8Debug_LvlCabHeatCool,
                      &Sokon_X01_Thm_B.CmfO_u8WindExitmodeDisp,
                      &Sokon_X01_Thm_B.CmfO_u8CabinCoolPrioReq,
                      &Sokon_X01_Thm_B.CmfO_u8CabinHeatPrioReq,
                      &Sokon_X01_Thm_B.CmfO_u16Tw_PTCOut_Set_Pre_A10,
                      &Sokon_X01_Thm_B.CmfO_s16Debug_TasdRSolarCmp_A10);

  /* Start for InitialCondition: '<Root>/IC106' */
  Sokon_X01_Thm_DW.IC106_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC108' */
  Sokon_X01_Thm_DW.IC108_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC109' */
  Sokon_X01_Thm_DW.IC109_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC132' */
  Sokon_X01_Thm_DW.IC132_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC133' */
  Sokon_X01_Thm_DW.IC133_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC134' */
  Sokon_X01_Thm_DW.IC134_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC135' */
  Sokon_X01_Thm_DW.IC135_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC136' */
  Sokon_X01_Thm_DW.IC136_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC47' */
  Sokon_X01_Thm_DW.IC47_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC48' */
  Sokon_X01_Thm_DW.IC48_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC49' */
  Sokon_X01_Thm_DW.IC49_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC50' */
  Sokon_X01_Thm_DW.IC50_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC15' */
  Sokon_X01_Thm_DW.IC15_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC51' */
  Sokon_X01_Thm_DW.IC51_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC52' */
  Sokon_X01_Thm_DW.IC52_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC53' */
  Sokon_X01_Thm_DW.IC53_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC54' */
  Sokon_X01_Thm_DW.IC54_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC56' */
  Sokon_X01_Thm_DW.IC56_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC57' */
  Sokon_X01_Thm_DW.IC57_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC58' */
  Sokon_X01_Thm_DW.IC58_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC59' */
  Sokon_X01_Thm_DW.IC59_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC60' */
  Sokon_X01_Thm_DW.IC60_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC62' */
  Sokon_X01_Thm_DW.IC62_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC33' */
  Sokon_X01_Thm_DW.IC33_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC67' */
  Sokon_X01_Thm_DW.IC67_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC68' */
  Sokon_X01_Thm_DW.IC68_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC69' */
  Sokon_X01_Thm_DW.IC69_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC73' */
  Sokon_X01_Thm_DW.IC73_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC74' */
  Sokon_X01_Thm_DW.IC74_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC75' */
  Sokon_X01_Thm_DW.IC75_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC82' */
  Sokon_X01_Thm_DW.IC82_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC83' */
  Sokon_X01_Thm_DW.IC83_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC84' */
  Sokon_X01_Thm_DW.IC84_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC85' */
  Sokon_X01_Thm_DW.IC85_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC86' */
  Sokon_X01_Thm_DW.IC86_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC87' */
  Sokon_X01_Thm_DW.IC87_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC88' */
  Sokon_X01_Thm_DW.IC88_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC89' */
  Sokon_X01_Thm_DW.IC89_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC90' */
  Sokon_X01_Thm_DW.IC90_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC91' */
  Sokon_X01_Thm_DW.IC91_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC92' */
  Sokon_X01_Thm_DW.IC92_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC93' */
  Sokon_X01_Thm_DW.IC93_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC94' */
  Sokon_X01_Thm_DW.IC94_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC95' */
  Sokon_X01_Thm_DW.IC95_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC96' */
  Sokon_X01_Thm_DW.IC96_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC97' */
  Sokon_X01_Thm_DW.IC97_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC98' */
  Sokon_X01_Thm_DW.IC98_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC99' */
  Sokon_X01_Thm_DW.IC99_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC100' */
  Sokon_X01_Thm_DW.IC100_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC101' */
  Sokon_X01_Thm_DW.IC101_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC102' */
  Sokon_X01_Thm_DW.IC102_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC103' */
  Sokon_X01_Thm_DW.IC103_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC104' */
  Sokon_X01_Thm_DW.IC104_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC105' */
  Sokon_X01_Thm_DW.IC105_FirstOutputTime = true;

  /* Start for ModelReference: '<S35>/HP' incorporates:
   *  Constant: '<S71>/Constant'
   */
  Chery_E03_Hp_Start(&Sokon_X01_Thm_B.HpO_u16Ncomp_Rpm_Req,
                     &Sokon_X01_Thm_B.HpO_bSOV_Eva_Req,
                     &Sokon_X01_Thm_B.HpO_bSOV_OutEva_Req,
                     &Sokon_X01_Thm_B.HpO_bSOV_TXVOutEva_Req,
                     &Sokon_X01_Thm_B.HpO_u16EXV_Eva_Pos_Req,
                     &Sokon_X01_Thm_B.HpO_u16EXV_Chil_Pos_Req,
                     &Sokon_X01_Thm_B.HpO_u8HpWorkMode_Req,
                     &Sokon_X01_Thm_B.HpI_u8AGS_Position_Req,
                     &Sokon_X01_Thm_B.HpO_u8FRFAN_PWM_Req,
                     &Sokon_X01_Thm_B.HpO_u8Mix_Left_Req,
                     &Sokon_X01_Thm_B.HpO_u8Mix_Right_Req,
                     &Sokon_X01_Thm_B.HpO_u8DTC_Ref_System,
                     &Sokon_X01_Thm_B.HpO_u8DTC_Ref_Component,
                     &Sokon_X01_Thm_B.HpO_bDTC_EvaFreeze,
                     &Sokon_X01_Thm_B.HpO_bDTC_OutEvaFreeze,
                     &Sokon_X01_Thm_B.HpO_u8TWValve_HC_Req,
                     &Sokon_X01_Thm_B.HpO_u8TWValve_LTR_Req,
                     &Sokon_X01_Thm_B.HpO_u8TWValve_BAT_Req,
                     &Sokon_X01_Thm_B.HpO_u8HVCH_Req,
                     &Sokon_X01_Thm_B.HpO_u16Pump_HVCH_Req,
                     &Sokon_X01_Thm_B.HpO_u16Pump_Motor_Req,
                     &Sokon_X01_Thm_B.HpO_u16Pump_Bat_Req);

  /* Start for InitialCondition: '<Root>/IC110' */
  Sokon_X01_Thm_DW.IC110_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC111' */
  Sokon_X01_Thm_DW.IC111_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC112' */
  Sokon_X01_Thm_DW.IC112_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC113' */
  Sokon_X01_Thm_DW.IC113_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC114' */
  Sokon_X01_Thm_DW.IC114_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC115' */
  Sokon_X01_Thm_DW.IC115_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC116' */
  Sokon_X01_Thm_DW.IC116_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC117' */
  Sokon_X01_Thm_DW.IC117_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC118' */
  Sokon_X01_Thm_DW.IC118_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC119' */
  Sokon_X01_Thm_DW.IC119_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC120' */
  Sokon_X01_Thm_DW.IC120_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC121' */
  Sokon_X01_Thm_DW.IC121_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC122' */
  Sokon_X01_Thm_DW.IC122_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC123' */
  Sokon_X01_Thm_DW.IC123_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC124' */
  Sokon_X01_Thm_DW.IC124_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC125' */
  Sokon_X01_Thm_DW.IC125_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC126' */
  Sokon_X01_Thm_DW.IC126_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC127' */
  Sokon_X01_Thm_DW.IC127_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC128' */
  Sokon_X01_Thm_DW.IC128_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC129' */
  Sokon_X01_Thm_DW.IC129_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC130' */
  Sokon_X01_Thm_DW.IC130_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC131' */
  Sokon_X01_Thm_DW.IC131_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC107' */
  Sokon_X01_Thm_DW.IC107_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC16' */
  Sokon_X01_Thm_DW.IC16_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC28' */
  Sokon_X01_Thm_DW.IC28_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC29' */
  Sokon_X01_Thm_DW.IC29_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC30' */
  Sokon_X01_Thm_DW.IC30_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC31' */
  Sokon_X01_Thm_DW.IC31_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC22' */
  Sokon_X01_Thm_DW.IC22_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC23' */
  Sokon_X01_Thm_DW.IC23_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC27' */
  Sokon_X01_Thm_DW.IC27_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC70' */
  Sokon_X01_Thm_DW.IC70_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC71' */
  Sokon_X01_Thm_DW.IC71_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC72' */
  Sokon_X01_Thm_DW.IC72_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC11' */
  Sokon_X01_Thm_DW.IC11_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC12' */
  Sokon_X01_Thm_DW.IC12_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC13' */
  Sokon_X01_Thm_DW.IC13_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC2' */
  Sokon_X01_Thm_DW.IC2_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC3' */
  Sokon_X01_Thm_DW.IC3_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC32' */
  Sokon_X01_Thm_DW.IC32_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC34' */
  Sokon_X01_Thm_DW.IC34_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC36' */
  Sokon_X01_Thm_DW.IC36_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC37' */
  Sokon_X01_Thm_DW.IC37_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC38' */
  Sokon_X01_Thm_DW.IC38_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC43' */
  Sokon_X01_Thm_DW.IC43_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC6' */
  Sokon_X01_Thm_DW.IC6_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC61' */
  Sokon_X01_Thm_DW.IC61_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC64' */
  Sokon_X01_Thm_DW.IC64_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC65' */
  Sokon_X01_Thm_DW.IC65_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC66' */
  Sokon_X01_Thm_DW.IC66_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC7' */
  Sokon_X01_Thm_DW.IC7_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC76' */
  Sokon_X01_Thm_DW.IC76_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC77' */
  Sokon_X01_Thm_DW.IC77_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC78' */
  Sokon_X01_Thm_DW.IC78_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC79' */
  Sokon_X01_Thm_DW.IC79_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC8' */
  Sokon_X01_Thm_DW.IC8_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC80' */
  Sokon_X01_Thm_DW.IC80_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC81' */
  Sokon_X01_Thm_DW.IC81_FirstOutputTime = true;

  /* Start for InitialCondition: '<Root>/IC9' */
  Sokon_X01_Thm_DW.IC9_FirstOutputTime = true;

  /* SystemInitialize for Atomic SubSystem: '<S73>/JudgeFlag_Sensor_Ready' */
  /* SystemInitialize for Chart: '<S81>/Sensor_Prepare_Delay' */
  Sokon_X01_Thm_DW.u16COUNT_Sensor_Delay = 0U;

  /* End of SystemInitialize for SubSystem: '<S73>/JudgeFlag_Sensor_Ready' */

  /* SystemInitialize for ModelReference: '<S35>/CMF' */
  Sokon_X01_Cmf_Init();

  /* SystemInitialize for ModelReference: '<S35>/HP' incorporates:
   *  Constant: '<S71>/Constant'
   */
  Chery_E03_Hp_Init();
}

/* Model terminate function */
void Sokon_X01_Thm_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

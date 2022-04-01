/*
 * File: Hp_Parameter.h
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#ifndef RTW_HEADER_Hp_Parameter_h_
#define RTW_HEADER_Hp_Parameter_h_
#include "rtwtypes.h"

/* Volatile memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Volatile */
extern volatile boolean_T ACPre_bAGS_AVAILABLE;/* AGS is Available */
extern volatile int16_T ACPre_s16Temp_Hys_Down;/* The Temperature hysterisis down for the Twat fro the mode select */
extern volatile int16_T ACPre_s16Temp_Hys_Up;/* The Temperature hysterisis up for Twat for the mode select */
extern volatile uint8_T ACPre_u8AGS_MAX;/* AGS max open value */
extern volatile uint8_T ACPre_u8MotorCoolReq_Yes;/* The flag of the motor cooling requirement  */
extern volatile uint8_T ACPre_u8Project_CheryE03;/* Chery E03 Project Code 2 */
extern volatile uint8_T ACPre_u8Project_SokonX1;/* Sokon X1 Project Code 1 */
extern volatile uint8_T Flap_u8DIS_MODE_FD_Sokon;/* HVAC Distribution Mode, 3 is FD, Sokon */
extern volatile uint8_T Flap_u8DIS_MODE_FEET_Sokon;/* HVAC Distribution Mode, 2 is F, Sokon */
extern volatile uint8_T Hp_u8TWV_HC_FullCool_Sokon;/* The 3Way Valve Postion of FullCool for Sokon 0% */
extern volatile uint8_T Hp_u8TWV_HC_FullHot_Sokon;/* The 3Way Valve Postion of Fullhot for Sokon 100% */
extern volatile uint8_T Hp_u8TWV_HC_MiddlePos_Sokon;/* The 3Way Valve Postion of Middle Position for Sokon 50% */
extern volatile boolean_T bCONST_0;    /* 0 and not meet the condition */
extern volatile boolean_T bCONST_1;    /* 1 and not meet the condition */
extern volatile boolean_T bFAILRISK_NO_0;/* 0, NO Failure and Risk */
extern volatile boolean_T bFAILRISK_YES_1;/* 1, With Failure and Risk */
extern volatile boolean_T bFAIL_NO_RISK_0;/* 0 and not meet the condition */
extern volatile boolean_T bFAIL_RISK_No;/* 0 and NO failure and no Risk */
extern volatile boolean_T bFAIL_RISK_YES;/* 1 and with Failure and Risk */
extern volatile boolean_T bFAIL_RISK_Y_1;/* 1 and not meet the condition */
extern volatile boolean_T bFLAG_YES;   /* 1 and not meet the condition */
extern volatile boolean_T bSOV_Close_0;/* SOV Close */
extern volatile boolean_T bSOV_OPEN_1; /* SOV Open */
extern volatile int16_T s16POMILIMIT_0;/* The Temperature Uplimit for Saturation  */
extern volatile int16_T s16POMILIMIT_1000;/* The Temperature Uplimit for Saturation  */
extern volatile int16_T s16POWER_GAP_NORISK;/* Powercomp limitation  subtract Power comp consume, if more than 300 W, it is safe */
extern volatile int16_T s16POWER_GAP_RISK;/* Powercomp limitation - Power comp consume,if less than 50 W, it have the risk */
extern volatile int16_T s16TAD_LOW_30; /* Text<3 ¡æ, AC Authority is not  */
extern volatile int16_T s16TAD_UP_50;  /* Text>5 ¡æ, AC Authority is OK */
extern volatile int16_T s16TCTRL_DELTA_DOWNLIMIT;/* The Temperature Down Limit for Saturation */
extern volatile int16_T s16TCTRL_DELTA_UPLIMIT;/* The Temperature Uplimit for Saturation  */
extern volatile int16_T s16TEMP_LIMIT_M40;/* Twater Down limitation, 10±¶·Å´ó±¶Êý */
extern volatile int16_T s16TEMP_POMILIMIT_0;/* The Temperature Uplimit for Saturation  */
extern volatile int16_T s16TEMP_POMILIMIT_30;/* The Temperature Uplimit for Saturation  */
extern volatile int16_T s16TEMP_UPLIMIT;/* The Temperature Uplimit for Saturation  */
extern volatile int16_T s16TEVA_CTRL_DOWN;/* Teva temperatur control lowlimit -100 (-10¡æ) */
extern volatile int16_T s16TEVA_CTRL_UP;/* Teva temperatur control uplimit 175 (17.5 ¡æ) */
extern volatile int16_T s16TEVA_DOWNLIMIT;/* The Teva down Limitation  */
extern volatile int16_T s16TEVA_FAIL;  /* Teva freeze temperature */
extern volatile int16_T s16TEVA_FREEZE_NOR;/* the temeprature of evaporator is 2 degree, no freeze risk */
extern volatile int16_T s16TEVA_FREZEE;/* Teva freeze risk temperature 0 ¡æ for EDC onf off */
extern volatile int16_T s16TEVA_NOR;   /* Teva no freeze temperature  */
extern volatile int16_T s16TEVA_NOR_RESTART;/* Teva freeze risk temperature 4 ¡æ for EDC onf off */
extern volatile int16_T s16TEVA_UPLIMIT;/* The Teva Up Limitaion */
extern volatile int16_T s16TEVA_UP_150;/* Teva setting must lower than 15¡æ */
extern volatile int16_T s16TSET_LOW;   /* The Set Temperature when the Setting temperature is LOW */
extern volatile int16_T s16Tw_HVCH_UpLimit;/* HVCH temperature control uplimit 800 (80 ¡æ) */
extern volatile int16_T s16Tw_HVCH_UpLimitMax;/* HVCH temperature control uplimit 800 (80 ¡æ) */
extern volatile int32_T s32NCOMP_DOWN_0;/* EDC calculation lower limit is 0rpm */
extern volatile int32_T s32NCOMP_DOWN_LIMIT;/* The EDC RPM uplimit and the amplification rate is 10, it means 960 RPM */
extern volatile int32_T s32NCOMP_FOR_ACCHIL;/* The EDC RPM Estimation section uplimit and the amplification rate is 10, it means 3000 RPM */
extern volatile int32_T s32NCOMP_ICAL_UP;/* The EDC RPM Estimation section uplimit and the amplification rate is 10, it means 6000 RPM */
extern volatile int32_T s32NCOMP_STOP_0;/* The EDC RPM 0 when the Compressor Stop */
extern volatile int32_T s32NCOMP_UP_LIMIT;/* The EDC RPM uplimit and the amplification rate is 10, it means 7000 RPM */
extern volatile int32_T s32NCOMP_UP_SPD;/* The EDC RPM Rampup Speed is 20 RPM per sample time (0.1S) and means 200 RPM per seconds */
extern volatile uint16_T u16AMP_10;    /* 10 times amplification rate */
extern volatile uint16_T u16AMP_100;   /* 100 times amplification rate */
extern volatile uint16_T u16AMP_1000;  /* 1000 times amplification rate */
extern volatile uint16_T u16AMP_10000; /* 10000 times amplification rate */
extern volatile uint16_T u16CHIL_EXV_MIN_START;/* chiller edc condition start configure for exv mimunm is 30 steps */
extern volatile uint16_T u16CONST_0;   /* The Constant 1 use for the filter and timer */
extern volatile uint16_T u16COUNT_0;   /* Constant 0, use for initilization  */
extern volatile uint16_T u16COUNT_1;   /* Constant 0, use for initilization  */
extern volatile uint16_T u16EDC_POWERMIN;/* Edc startup Power min limitation */
extern volatile uint16_T u16EDC_RPMMIN;/* Edc Startup PRM min limitation */
extern volatile uint16_T u16EXV_CHIL_MIN_0;/* Chiller EXV close step 0 */
extern volatile uint16_T u16NCOMP_STOP_0;/* The RPM of the compressor Stop */
extern volatile uint16_T u16PBALANCE;  /* The difference of High pressure and low pressure is low than this one, the pressure is balance */
extern volatile uint16_T u16PCHARGE_FAIL;/* When the high pressure is low than 2.5 bar, it means the charge failure,the Refrigerant leakage */
extern volatile uint16_T u16PRCI_FAIL; /* System protection Yes if the low pressure low than 1.5 bar */
extern volatile uint16_T u16PRCI_FAIL_HP;/* System protection Yes in HP Mode  if the low pressure low than 1.0bar */
extern volatile uint16_T u16PRCI_NOR;  /* System Protection No if the low pressure high than 2 bar */
extern volatile uint16_T u16PRCI_NORFAIL_HP;/* System Protection No in HP Mode if the low pressure high than 1.3 bar */
extern volatile uint16_T u16PRCO_FAIL; /* System protection Yes in the pressure  */
extern volatile uint16_T u16PRCO_NOR;  /* System Protection No in the pressure  */
extern volatile uint16_T u16PRCO_NORISK;/* System Protection No in the pressure in the 22 bar */
extern volatile uint16_T u16PRCO_RISK; /* System protection Yes in the pressure in the 26 bar */
extern volatile uint16_T u16SH_LOW_LIMIT;/* Superheat lowlimit 0 ¡æ */
extern volatile uint16_T u16SH_UP_LIMIT;/* Superheat uplimit 50 ¡æ */
extern volatile uint16_T u16TIME_EVAFRE;/* Eva temperature low than 0¡æ 5S, then define the Eva have the freeze risk */
extern volatile uint16_T u16TIME_EVAFRE_RELEASE;/* After the Eva judge the Eva freeze, the on/off time minium is 10s */
extern volatile uint16_T u16TIMT_EDC_CONF_5;/* When the EDC Configulartion more than 0.5s, the EDC can Start */
extern volatile uint16_T u16VAIR_CONDMIN;/* The minum Condenser 5  Air flowrate for the AC On 0.5m/s */
extern volatile uint8_T u8AMP_10;      /* 10 times amplification rate */
extern volatile uint8_T u8AMP_100;     /* 100 times amplification rate */
extern volatile uint8_T u8BLW_VOL_MIN; /* The minum HVAC Blw voltage is 3v */
extern volatile uint8_T u8BTMCOOL_1;   /* Battery Cooling Level 1, AC Priority */
extern volatile uint8_T u8BTMCOOL_2;   /* Battery Cooling Level 2, AC Priority (But the condition with compromise) */
extern volatile uint8_T u8BTMCOOL_3;   /* Battery Cooling L3, BTC is priority */
extern volatile uint8_T u8BTM_CycleL11;/* Battery Cycle L11, Battery Internal cycle */
extern volatile uint8_T u8BTM_HeatL4;  /* Battery heating Level 4 */
extern volatile uint8_T u8BTM_HeatL5;  /* Battery heating Level 5 */
extern volatile uint8_T u8DIS_MODE_DEF_4;/* The HVAC Distribution Mode, Defrost_4 */
extern volatile uint8_T u8DIS_MODE_FD_3;/* The HVAC Distribution Mode, Feet_3 */
extern volatile uint8_T u8DIS_MODE_FEET_2;/* The HVAC Distribution Mode, Feet_2 */
extern volatile uint8_T u8DIS_MODE_VD_6;/* The HVAC Distribution Mode, Vent/Defrost_6 */
extern volatile uint8_T u8DIS_MODE_VENT_0;/* The HVAC Distribution Mode, Vent_0 */
extern volatile uint8_T u8DIS_MODE_VFD_5;/* The HVAC Distribution Mode, Vent/Feet/Defrost_5 */
extern volatile uint8_T u8DIS_MODE_VF_1;/* The HVAC Distribution Mode, Vent/Feet_1 */
extern volatile uint8_T u8FLAP_POS_0;  /* 0% Percent of the Flap position  */
extern volatile uint8_T u8FLAP_POS_100;/* 100% Percent of the Flap position  */
extern volatile uint8_T u8HVACStatusFB_CMF_MAXAC;/* HVAC Status is MAX AC */
extern volatile uint8_T u8HVACStatusFB_CMF_OFF;/* HVAC Status is Off */
extern volatile uint8_T u8HVACStatusFB_CMF_OTA;/* HVAC Status is OTA */
extern volatile uint8_T u8HVACStatusFB_CMF_VENTILATE;/* HVAC Status is Ventilate */
extern volatile uint8_T u8MODE_ACCHILLER_2;/* Working mode AC + Chiller 2 */
extern volatile uint8_T u8MODE_AC_1;   /* Working mode AC 1, including the AC-Simple Dehumidity Mode. */
extern volatile uint8_T u8MODE_CHILLER_3;/* Working mode Chiller 3 */
extern volatile uint8_T u8MODE_FAILURE_31;/* Working mode Failure 31,Coolant Loop Failure. */
extern volatile uint8_T u8MODE_FAILURE_4;/* Working mode Failure4,Refrigerant Loop Failure */
extern volatile uint8_T u8MODE_HP_7;   /* Working mode of the HP */
extern volatile uint8_T u8MODE_HP_BatHeat_10;/* Working mode of the HP for Cabin heating and Battery heating */
extern volatile uint8_T u8MODE_HP_CHILMDCHIL_12;/* Working mode of the HP get the Power from Chil and MD Chil */
extern volatile uint8_T u8MODE_HP_CHIL_8;/* Working mode of the HP with Chiller for Battery Cooling */
extern volatile uint8_T u8MODE_HP_MDCHIL_9;/* Working mode of the HP with the Heat Recovery from Motor Driver */
extern volatile uint8_T u8MODE_HVCH_BAT_21;/* Working Mode of HVCH heat the Cabin for heating the Comfortable */
extern volatile uint8_T u8MODE_HVCH_CMF_20;/* Working Mode of HVCH heat the Cabin for heating the Comfortable */
extern volatile uint8_T u8MODE_HVCH_CMF_BAT_22;/* Working Mode of HVCH heat the Cabin for heating the Comfortable */
extern volatile uint8_T u8MODE_STOP_0; /* Working mode Stop 0 */
extern volatile uint8_T u8MODE_TotalDehum_18;/* Working mode of the Total Dehum 18, self-cycle without outer Evaporator or Condensor */
extern volatile uint8_T u8MODE_TotalDehum_5;/* Working mode of the Total Dehum 5, */
extern volatile uint8_T u8MODE_TotalDehum_CHIL_6;/* Working mode of the Total Dehum 6, the Mode of Total Dehum with Chiller */
extern volatile uint8_T u8RATIO_PRE_NOR;/* Pressure Ratio Uplimit */
extern volatile uint8_T u8SAMPLE_TIME_10;/* System smple time for the integer calculation, 10 means the sample time is 0.1s */

#endif                                 /* RTW_HEADER_Hp_Parameter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

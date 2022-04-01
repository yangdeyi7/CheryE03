/*
 * File: CMF_Parameter.h
 *
 * Code generated for Simulink model 'Sokon_X01_Thm'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:36 2022
 */

#ifndef RTW_HEADER_CMF_Parameter_h_
#define RTW_HEADER_CMF_Parameter_h_
#include "rtwtypes.h"

/* Volatile memory section */
/* Exported data declaration */
/* Declaration for custom storage class: Volatile */
extern volatile uint8_T CAL_u8BLW_AUTO_8;/* Auto Mode of Blower */
extern volatile uint8_T CAL_u8DIS_MODE_DEF;/* The HVAC Distribution Mode, Defrost_4 */
extern volatile uint8_T CAL_u8DIS_MODE_FD;/* The HVAC Distribution Mode, Feet_Defrost_3 */
extern volatile uint8_T CAL_u8DIS_MODE_FEET;/* The HVAC Distribution Mode, Feet_2 */
extern volatile uint8_T CAL_u8DIS_MODE_VENT;/* The HVAC Distribution Mode, Vent_0 */
extern volatile uint8_T CAL_u8DIS_MODE_VF;/* The HVAC Distribution Mode, BiLvl_VF_1 */
extern volatile uint8_T CAL_u8INTAK_AUTO_3;/* Auto Mode of Intake Flap */
extern volatile uint8_T CAL_u8INTAK_ManualFRE_2;/* ManualFRE of Intake Flap */
extern volatile uint8_T CAL_u8INTAK_ManualREC_1;/* ManualREC of Intake Flap */
extern volatile uint8_T CAL_u8MODE_AUTO_6;/* Auto Mode of Mode */
extern volatile uint16_T CMF_u16TIMER_10S;/* The Comfortable Timer 10S, sample time is 1S */
extern volatile uint8_T CMF_u8BLW_MAX; /* The BLW output Max 120 */
extern volatile uint8_T CMF_u8BLW_MIN; /* The BLW output min 32 */
extern volatile uint8_T CMF_u8FLAP_INTAK_FRE;/* The Intake Flap postion in the Fresh, 100% percent  */
extern volatile uint8_T CMF_u8FLAP_INTAK_RECY;/* The Intake Flap postion in the Recycle, 0% percent  */
extern volatile uint8_T CMF_u8FLAP_INTAK_TwoLayer;/* The Intake Flap postion in the two layer */
extern volatile uint8_T CMF_u8MODE_HP_7;/* Working mode of the HP */
extern volatile uint8_T CMF_u8MODE_HP_BatHeat_10;/* Working mode of the HP for Cabin heating and Battery heating */
extern volatile uint8_T CMF_u8MODE_HP_CHILMDCHIL_12;/* Working mode of the HP get the Power from Chil and MD Chil */
extern volatile uint8_T CMF_u8MODE_HP_CHIL_8;/* Working mode of the HP with Chiller for Battery Cooling */
extern volatile uint8_T CMF_u8MODE_HP_MDCHIL_9;/* Working mode of the HP with the Heat Recovery from Motor Driver */
extern volatile boolean_T CmfThm_bConst_0;/* Constant 0 and false */
extern volatile boolean_T CmfThm_bConst_1;/* Constant 1 and True */
extern volatile uint16_T CmfThm_u16Filter_60s;/* Filter 60s */
extern volatile uint16_T CmfThm_u16Sun_DecNum_Filter;/* Sun_DecNum_Filter */
extern volatile uint16_T CmfThm_u16Sun_IncNum_Filter;/* Sun_IncNum_Filter */
extern volatile uint8_T CmfThm_u8Filter_15s;/* Filter 15s */
extern volatile uint8_T CmfThm_u8Filter_2s;/* Filter 2s */
extern volatile uint8_T CmfThm_u8Filter_3s;/* Filter 3s */
extern volatile uint8_T CmfThm_u8Filter_6s;/* Filter 6s */
extern volatile uint8_T SEN_u8CMFSW_FIRST_2;/* SEN_u8CMFSW_FIRST */
extern volatile uint8_T SEN_u8CMFSW_INIT_0;/* SEN_u8CMFSW_INIT */
extern volatile uint8_T SEN_u8CMFSW_READY_1;/* SEN_u8CMFSW_READY */
extern volatile int16_T THM_s16TASD_NoCompDyn_0;/* TASD 0, No Comp and Dynamic Compensation */
extern volatile int16_T THM_s16TASD_UPLIM;/* The TASD Low Limitation 80 degree  */
extern volatile int16_T THM_s16TEVA_SET_MAX;/* The Teva Setting Max 15 Degree */
extern volatile int16_T THM_s16TEVA_SET_MIN;/* The Teva Setting Min 3 Degree */
extern volatile int16_T THM_s16TEVA_SET_STOP;/* The Teva Setting, No Requirement 20 Degree */
extern volatile uint16_T THM_u16TSET_HI;/* Pad TSET is HI, Sokon is 32.5 degree */
extern volatile uint16_T THM_u16TSET_LOW;/* Pad TSET is low, Sokon is 17.5 degree */
extern volatile uint8_T THM_u8CONST_2; /* The Constant_2 use for the average */
extern volatile uint8_T THM_u8HVAC_STS_OFF;/* The HVAC Status 3,Off MODE */
extern volatile uint8_T THM_u8HVAC_STS_OTA;/* The HVAC Status 9, OTA MODE */
extern volatile uint8_T THM_u8HVAC_STS_VENTILATE;/* The HVAC Status 4, Ventilate MODE */

#endif                                 /* RTW_HEADER_CMF_Parameter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

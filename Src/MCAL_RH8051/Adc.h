/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Adc                                                     */
/*                                                                            */
/* !Component       : Adc                                                     */
/* !Description     : Interface for Managing the Adc                          */
/*                                                                            */
/* !Module          : Adc                                                     */
/* !Description     : Adc                                                     */
/*                                                                            */
/* !File            : Adc.h                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* all rights reserved                                                        */
/******************************************************************************/
#ifndef ADC_H
#define ADC_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define ADC_SAMPLES_NUM                ((uint8)3)

/*! \Description  The number of ADC identifiers \n
 *  \Range        10 */
//bcc
#define      ADC_u8AI8_J2_20                ((uint8)0)//Sensor_u8WATER1
//#define      ADC_u8AI9_J3_1                 ((uint8)1)
//#define      ADC_u8AI10_J3_2                ((uint8)2)
#define      ADC_u8AI11_J3_3                ((uint8)3)//Sensor_u8WATER2
#define      ADC_u8AI12_J3_4                ((uint8)4)//Sensor_u8HP_P2
//#define      ADC_u8AI13_J3_5                ((uint8)5)
#define      ADC_u8AI14_J3_6                ((uint8)6)//Sensor_u8LP_P
#define      ADC_u8AI15_J3_13               ((uint8)7)//Sensor_u8HP_P1
//#define      ADC_u8AI16_J3_14               ((uint8)8)
//#define      ADC_u8AI_BLW_B_FB_J2_10        ((uint8)9)
//#define      ADC_u8AI_DC_MOTOR_FB_J2_11     ((uint8)10)
#define      ADC_u8AI_BAT_J2_21             ((uint8)11)
#define      ADC_u8AI_SUN_L_J2_12           ((uint8)12)//Sensor_u8LP_T
//#define      ADC_u8AI_SUN_R_J3_7            ((uint8)13)
#define      ADC_u8AI_IGN_J2_1              ((uint8)14)
//#define      ADC_u8AI_BLR_A_FB_J1_14        ((uint8)15)
#define      ADC_u8AI7_J2_19                ((uint8)16)//Sensor_u8INCAR
#define      ADC_u8AI6_J2_18                ((uint8)17)//Sensor_u8AMB
#define      ADC_u8AI5_J2_17                ((uint8)18)//Sensor_u8TDUCT_R_F
#define      ADC_u8AI4_J2_16                ((uint8)19)//Sensor_u8TDUCT_L_F
#define      ADC_u8AI3_J2_15                ((uint8)20)//Sensor_u8TDUCT_R_V
#define      ADC_u8AI2_J2_14                ((uint8)21)//Sensor_u8TDUCT_L_V
#define      ADC_u8AI1_J2_13                ((uint8)22)//Sensor_u8EVAP
#define      ADC_PART1_CHN_NUM              ((uint8)23)
//dc motor
//#define      ADC_u8BAT_ID                   ((uint8)(ADC_PART1_CHN_NUM+0))
//#define      ADC_u8IGN_ID                   ((uint8)(ADC_PART1_CHN_NUM+1))
//#define      ADC_u8COOLANTE_T_ID            ((uint8)(ADC_PART1_CHN_NUM+2))
//#define      ADC_u8SUN_ID                   ((uint8)(ADC_PART1_CHN_NUM+3))
#define      ADC_u8RECY_ID                  ((uint8)(ADC_PART1_CHN_NUM+0))
#define      ADC_u8DEFORST_ID               ((uint8)(ADC_PART1_CHN_NUM+1))
#define      ADC_u8MODER_ID                 ((uint8)(ADC_PART1_CHN_NUM+2))
#define      ADC_u8MODEL_ID                 ((uint8)(ADC_PART1_CHN_NUM+3))
#define      ADC_u8MIXR_ID                  ((uint8)(ADC_PART1_CHN_NUM+4))
#define      ADC_u8MIXL_ID                  ((uint8)(ADC_PART1_CHN_NUM+5))
//#define      ADC_u8NTC1_ID                  ((uint8)(ADC_PART1_CHN_NUM+10))
//#define      ADC_u8NTC2_ID                  ((uint8)(ADC_PART1_CHN_NUM+11))
//#define      ADC_u8NTC3_ID                  ((uint8)(ADC_PART1_CHN_NUM+12))
//#define      ADC_u8NTC4_ID                  ((uint8)(ADC_PART1_CHN_NUM+13))
//#define      ADC_u8NTC5_ID                  ((uint8)(ADC_PART1_CHN_NUM+14))
//#define      ADC_u8NTC6_ID                  ((uint8)(ADC_PART1_CHN_NUM+15))
//#define      ADC_u8VLCL_FB_ID               ((uint8)(ADC_PART1_CHN_NUM+16))
//#define      ADC_u8INCAR_ID                 ((uint8)(ADC_PART1_CHN_NUM+17))
//#define      ADC_u8WT_RADIATOR_ID           ((uint8)(ADC_PART1_CHN_NUM+18))
//#define      ADC_u8WT_PEU_ID                ((uint8)(ADC_PART1_CHN_NUM+19))
//#define      ADC_u8WT_MOTOR_ID              ((uint8)(ADC_PART1_CHN_NUM+20))
//#define      ADC_u8AMB_ID                   ((uint8)(ADC_PART1_CHN_NUM+21))
//#define      ADC_u8EVAP_ID                  ((uint8)(ADC_PART1_CHN_NUM+22))
//#define      ADC_u8NTC8_ID                  ((uint8)(ADC_PART1_CHN_NUM+23))
//#define      ADC_u8NTC7_ID                  ((uint8)(ADC_PART1_CHN_NUM+24))
#define      ADC_u8NUM_ADC                  ((uint8)(ADC_PART1_CHN_NUM+6))
#define      ADC_u8CHN_NUM                  ((uint8)(ADC_PART1_CHN_NUM+6))
/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/*! \Description Initializes ADC module                                       */
/******************************************************************************/
extern void Adc_vidInit( void );
/******************************************************************************/
/*! \Description  Read ADC Value                                              */
/******************************************************************************/
extern uint16 Adc_u16Read(uint8 u8Id);
/******************************************************************************/
/*! \Description  ADC Management                                              */
/******************************************************************************/
extern void   Adc_vidManage(void);


#endif /* ADC_H                                                               */

/*-------------------------------- end of file -------------------------------*/

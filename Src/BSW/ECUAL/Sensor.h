/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Sensor                                                  */
/*                                                                            */
/* !Component       : Sensor                                                  */
/* !Description     : Provides interface for sensor management                */
/*                                                                            */
/* !Module          : Sensor                                                  */
/* !Description     : Provides interface for sensor management                */
/*                                                                            */
/* !File            : Sensor.h                                                */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : uPD70F3375                                              */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/EC$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Sensor.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:12   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
 
#ifndef SENSOR_H
#define SENSOR_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define Sensor_u8EVAP                     ((uint8)0)
#define Sensor_u8WATER1                   ((uint8)1)
#define Sensor_u8WATER2                   ((uint8)2)
#define Sensor_u8AMB                      ((uint8)3)
#define Sensor_u8INCAR                    ((uint8)4)
#define Sensor_u8TDUCT_L_V                ((uint8)5)
#define Sensor_u8TDUCT_R_V                ((uint8)6)
#define Sensor_u8TDUCT_L_F                ((uint8)7)
#define Sensor_u8TDUCT_R_F                ((uint8)8)
#define Sensor_u8LP_T                     ((uint8)9)
#define Sensor_u8LP_P                     ((uint8)10)
#define Sensor_u8HP_P1                    ((uint8)11)
#define Sensor_u8HP_P2                    ((uint8)12)
#define Sensor_u8NUM                      ((uint8)13)


#define Sensor_u8UPPERLIMIT_ADC           ((uint16)1000) 
#define Sensor_u8LOWERLIMIT_ADC           ((uint16)10)


/******************************************************************************/
typedef struct
{
	sint16   s16EvapSensorValue;
	sint16   s16Water1SensorValue;
	sint16   s16Water2SensorValue;
	sint16   s16AmbSensorValue;
	sint16   s16IncarSensorValue;
	sint16   s16DuctLVSensorValue;
	sint16   s16DuctRVSensorValue;
	sint16   s16DuctLFSensorValue;
	sint16   s16DuctRFSensorValue;
	sint16   s16LPTSensorValue;
	sint16   s16LPPSensorValue;
	sint16   s16HP1SensorValue;
	sint16   s16HP2SensorValue;
}Senosr_tstrSampleValue;

typedef union
{
  Senosr_tstrSampleValue  strSampleValue;
  sint16                  s16DataAll[Sensor_u8NUM];
}Sensor_tuniSampleValue;

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef enum
{  
  Sensor_UNKNOWN = 0u,
  Sensor_NORMAL,
  Sensor_SHORT_VCC,
  Sensor_SHORT_GND,
  Sensor_OPEN  
} Sensor_tenuStatus;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void Sensor_vidInit( void );
extern sint16 Sensor_s16Read( uint8 u8Id );
extern void Sensor_vidManage(void);
extern Sensor_tenuStatus Sensor_enuGetCurrentStatus(uint8 u8Id);
#endif /* SENSOR_H */

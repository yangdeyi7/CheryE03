/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#ifndef TLE9410XDRV_H
#define TLE9410XDRV_H

#include "Std_Types.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*! Addresses of the control registers*/
#define  u8ADDR_HB_ACT_1_CTRL           0x83u    /* Half-bridge output control 1*/
#define  u8ADDR_HB_ACT_2_CTRL           0xC3u    /* Half-bridge output control 2*/
#define  u8ADDR_HB_ACT_3_CTRL           0xA3u    /* Half-bridge output control 3*/
/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef enum
{
 /*****************************/	
 TLE9410XDRV_DEFROST,//_4_6,
 TLE9410XDRV_SOV_RLY1,//3
 TLE9410XDRV_SOV_RLY2,//10
 TLE9410XDRV_BLW_RLY3,//11
 TLE9410XDRV_FAN_RLY4,//12
 TLE9410XDRV_SOTXV_RLY5,//9
 /*****************************/	
 TLE9410XDRV_MIXL,//_3_8,
 TLE9410XDRV_MIXR,//_2_10,
 TLE9410XDRV_MODEL,//_5_9,
 TLE9410XDRV_MODER,//_1_7,
 TLE9410XDRV_RECY,//_4_6,
 TLE9410XDRV_FAN_RLY11,
// TLE9410XDRV_FAN_RLY12,
}TLE9410xDRV_tenuId;

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
extern void   TLE9410xDrv_vidInit(void);
extern void   TLE9410xDrv_vidManage(void);
extern void   TLE9410xDrv_vidDcMotorCtrl(TLE9410xDRV_tenuId enuMotorId,uint8 u8HighOutValue,uint8 u8LowOutValue);
extern void TLE9410xDrv_vidRelayCtrl(TLE9410xDRV_tenuId enuRelayId,uint8 u8OutValue);








/*-------------------------------- end of file -------------------------------*/



#endif /* CISB_H */

/*-------------------------------- end of file -------------------------------*/

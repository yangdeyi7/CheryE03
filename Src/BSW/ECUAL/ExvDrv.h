#ifndef EXVDRV_H
#define EXVDRV_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define  u8EXV_CHILLER_ID    0u
#define  u8EXV_EVAP_ID        1u
#define  u8EXV_NUM           2u
#define EXV_NO_FAULT    (0u)
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef enum
{
	EXV_NOT_CAL,
	EXV_CAL_ING,
	EXV_CAL_DONE
} ExvDrv_tenuCaliStatus;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void                    ExvDrv_vidInit(void);
extern void                    ExvDrv_vidCalibration(uint8 u8ExvId);
extern ExvDrv_tenuCaliStatus   ExvDrv_enuGetCalibrationSts(uint8 u8ExvId);
extern void                    ExvDrv_vidSetDestStepPosition(uint8 u8ExvId, uint16 u16StepPosi);
extern uint16                  ExvDrv_u16GetCurrStepPosition(uint8 u8ExvId);
extern uint16                  ExvDrv_u16GetCurrPressSensorValue(uint8 u8ExvId);
extern sint16                  ExvDrv_s16GetCurrTempSensorValue(uint8 u8ExvId);
extern void                    ExvDrv_vidManage(uint8 u8ExvId);
//extern void                    ExvDrv_vidSetInitReq();
extern boolean EXV_bGetEvaFaultStatus(uint8 u8ExvId);


#endif
/*-------------------------------- end of file -------------------------------*/

#ifndef PTCDRV_H
#define PTCDRV_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

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
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void PtcDrv_vidInit(void);
extern void PtcDrv_vidSetPtcHeatingPercentReq(uint8 u8PercentReq);
extern uint8 PtcDrv_u8GetPtcCurrDuty(void);
extern uint16 PtcDrv_u16GetPtcInTwPhy(void);
extern boolean PtcDrv_bGetDtcSts(void);
extern boolean PtcDrv_bGetTempSensorDtcSts(void);
extern uint16 PtcDrv_u16GetCurrVolt(void);
extern uint16 PtcDrv_u16GetCurrCurrent(void);
extern boolean PtcDrv_bGetShutlmmeSts(void);



extern void hvwh_set_CMD_CTPE_EAU_BT(uint8 value);
extern void hvwh_set_COUPURE_CONSO_CPT(uint8 value);
extern void hvwh_set_CMD_PWR_LIMIT_HVWH(uint8 value);
extern void hvwh_set_CDE_PV_LIN(uint8 value);
extern float hvwh_get_TENSION_LV_CTPE_ELEC();
extern float hvwh_get_TEMP_EAU_CPT_BT();
extern float hvwh_get_I_CONSO_CTP_EAU_BT();
extern uint16 u16PowerHVCH();
extern uint16 u16HVCHStatus();
extern void vidAppHvchMng(uint16 u16HVCHpwmReq);
#endif
/*-------------------------------- end of file -------------------------------*/

#ifndef EDCDRV_H
#define EDCDRV_H
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
extern void EdcDrv_vidInit(void);
extern uint16 EdcDrv_u16GetCurrRpm(void);
extern boolean EdcDrv_bGetDtcSts(void);
extern uint16 EdcDrv_u16GetCurrVolt(void);
extern uint16 EdcDrv_u16GetCurrCurrent(void);
extern uint16 EdcDrv_u16GetCurrPwr(void);
extern void vidAppEdcMng(uint16 u16EdcSpdReq);




#endif
/*-------------------------------- end of file -------------------------------*/

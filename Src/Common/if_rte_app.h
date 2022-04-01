
#ifndef IF_RTE_APP_H
#define IF_RTE_APP_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Platform_Types.h"
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
/*************************************TYPES ***********************************/

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void IfRteApp_Set_ACSts( uint8 idata );
extern uint8 IfRteApp_Get_ACSts(void);
extern void IfRteApp_Set_AutoSts( uint8 idata );
extern uint8 IfRteApp_Get_AutoSts(void);
extern void IfRteApp_Set_WorkSts( uint8 idata );
extern uint8 IfRteApp_Get_WorkSts(void);
extern void IfRteApp_Set_BlwSts( uint8 idata );
extern uint8 IfRteApp_Get_BlwSts(void);
extern void IfRteApp_Set_IntakeSts( uint8 idata );
extern uint8 IfRteApp_Get_IntakeSts(void);
extern void IfRteApp_Set_ModeSts( uint8 idata );
extern uint8 IfRteApp_Get_ModeSts(void);
extern void IfRteApp_Set_TsetRSts( uint8 idata );
extern uint8 IfRteApp_Get_TsetRSts(void);
extern void IfRteApp_Set_TsetLSts( uint8 idata );
extern uint8 IfRteApp_Get_TsetLSts(void);
extern void IfRteApp_Set_SyncSts( uint8 idata );
extern uint8 IfRteApp_Get_SyncSts(void);
/********************GET KEY STATE*******************/
extern uint8 IfRteApp_Get_OFFStsFromCAN(void);
extern uint8 IfRteApp_Get_AutoStsFromCAN(void);
extern uint8 IfRteApp_Get_ACStsFromCAN(void);
extern uint8 IfRteApp_Get_BlwStsFromCAN(void);
extern uint8 IfRteApp_Get_IntakeStsFromCAN(void);
extern uint8 IfRteApp_Get_ModeVStsFromCAN(void);
extern uint8 IfRteApp_Get_ModeFStsFromCAN(void);
extern uint8 IfRteApp_Get_ModeDStsFromCAN(void);
extern uint8 IfRteApp_Get_TsetLStsFromCAN(void);
extern uint8 IfRteApp_Get_TsetRStsFromCAN(void);
extern uint8 IfRteApp_Get_SyncStsFromCAN(void);
extern uint8 IfRteApp_Get_CarSpeedFromCAN(void);
extern sint16 IfRteApp_Get_BMSInletFromCAN(void);
extern sint16 IfRteApp_Get_BMSOutletFromCAN(void);
extern sint16 IfRteApp_Get_BMSInletTargetFromCAN(void);
extern uint8 IfRteApp_Get_BMSRequestLevelFromCAN(void);
extern sint16 IfRteApp_Get_BMSTmaxFromCAN(void);
extern sint16 IfRteApp_Get_BMSTavrFromCAN(void);
extern sint16 IfRteApp_Get_BMSTminFromCAN(void);
extern uint8 IfRteApp_Get_DCDCReqFromCAN(void);
extern uint8 IfRteApp_Get_OBCCoolingReqFromCAN(void);
extern uint8 IfRteApp_Get_ADCCFlowReqFromCAN(void);
extern uint8 IfRteApp_Get_TMFFlowReqFromCAN(void);
extern uint8 IfRteApp_Get_TMRFlowReqFromCAN(void);
extern uint8 IfRteApp_Get_EACAllowFromCAN(void);
extern uint8 IfRteApp_Get_HVHAllowFromCAN(void);
/***********************END**************************/
extern void IfRteApp_Set_DataFromCAN(void);
extern void IfRteApp_CANSend(void);

#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/
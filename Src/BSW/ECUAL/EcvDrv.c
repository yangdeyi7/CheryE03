/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "EcvDrv.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define  u8ECV_HVAC_ID       0u
#define  u8ECV_BAT_ID        1u
#define  u8ECV_MOTOR_ID      2u
#define  u8ECV_NUM           3u
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
static boolean   EcvDrv_bEvcDtcSts[u8ECV_NUM];
static uint8     EcvDrv_u8EcvCurrPosi[u8ECV_NUM];
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
extern void EcvDrv_vidInit(void)
{
    uint8  u8Index;
    for(u8Index = 0u; u8Index < u8ECV_NUM; u8Index++)
    {
        EcvDrv_bEvcDtcSts[u8Index] = 0u;
        EcvDrv_u8EcvCurrPosi[u8Index] = 0u;
    }
}


extern void EcvDrv_vidSetEcvPercentPosi(uint8 u8EcvId, uint8 u8PercentPosiReq)
{
    uint8 au8Temp[u8ECV_NUM] = {0u,0u,0u};
    if(u8ECV_HVAC_ID == u8EcvId)
    {
        au8Temp[u8ECV_HVAC_ID] = 1u;
        LinIf_udtSendSignal(LIN_TXSIG_HVAC_TWV_MOVEENABLE, &au8Temp[u8ECV_HVAC_ID]);
        u8PercentPosiReq = u8PercentPosiReq / 0.4;
        LinIf_udtSendSignal(LIN_TXSIG_HVAC_TWV_POSSET, &u8PercentPosiReq);
    }
    else if(u8ECV_BAT_ID == u8EcvId)
    {
        au8Temp[u8ECV_BAT_ID] = 1u;
        LinIf_udtSendSignal(LIN_TXSIG_BAT_TWV_MOVEENABLE, &au8Temp[u8ECV_BAT_ID]);
        u8PercentPosiReq = u8PercentPosiReq / 0.4;
        LinIf_udtSendSignal(LIN_TXSIG_BAT_TWV_POSSET, &u8PercentPosiReq);
    }
    else if(u8ECV_MOTOR_ID == u8EcvId)
    {
        au8Temp[u8ECV_MOTOR_ID] = 1u;
        LinIf_udtSendSignal(LIN_TXSIG_MOTOR_TWV_MOVEENABLE, &au8Temp[u8ECV_MOTOR_ID]);
        u8PercentPosiReq = u8PercentPosiReq / 0.4;
        LinIf_udtSendSignal(LIN_TXSIG_MOTOR_TWV_POSSET, &u8PercentPosiReq);
    }
    else
    {
        
    }
    
}


extern uint8 EcvDrv_u8GetEcvCurrPercentPosi(uint8 u8EcvId)
{
    uint8 au8Temp[u8ECV_NUM] = {0u,0u,0u};
    if(u8ECV_HVAC_ID == u8EcvId)
    {
        LinIf_ReceiveSignal(LIN_RXSIG_HVAC_TWV_REALSTA,     &au8Temp[u8EcvId]);
        EcvDrv_u8EcvCurrPosi[u8EcvId] = au8Temp[u8EcvId] * 0.4;
    }
    else if(u8ECV_BAT_ID == u8EcvId)
    {
        LinIf_ReceiveSignal(LIN_RXSIG_BAT_TWV_REALSTA,     &au8Temp[u8EcvId]);
        EcvDrv_u8EcvCurrPosi[u8EcvId] = au8Temp[u8EcvId] * 0.4;
    }
    else if(u8ECV_MOTOR_ID == u8EcvId)
    {
        LinIf_ReceiveSignal(LIN_RXSIG_MOTOR_TWV_REALSTA,  &au8Temp[u8EcvId]);
        EcvDrv_u8EcvCurrPosi[u8EcvId] = au8Temp[u8EcvId] * 0.4;
    }
    else
    {
        
    }
    
    return EcvDrv_u8EcvCurrPosi[u8EcvId];
}

extern boolean EcvDrv_bGetDtcSts(uint8 u8EcvId)
{
    
    return EcvDrv_bEvcDtcSts[u8EcvId];
}





/*-------------------------------- end of file -------------------------------*/

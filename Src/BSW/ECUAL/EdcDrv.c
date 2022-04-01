
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "EdcDrv.h"
#include "if_rte_app.h"

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
/* DATA DEFINITION                                                            */
/******************************************************************************/
static uint16  EdcDrv_u16EdcCurrRpm;
static uint8   EdcDrv_u8EvcDtcSts;
static uint16  EdcDrv_u16EdcVolt;
static uint16  EdcDrv_u16EdcCurr;
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
extern void EdcDrv_vidInit(void)
{
    EdcDrv_u16EdcCurrRpm = 0u;
	EdcDrv_u8EvcDtcSts = 0u;
	EdcDrv_u16EdcVolt = 0u;
	EdcDrv_u16EdcCurr = 0u;	
}


extern uint16 EdcDrv_u16GetCurrVolt(void)
{
   uint8 u8Temp = 0u;
   LinIf_ReceiveSignal(LIN_RXSIG_EAC_HV_VOLT, &u8Temp);
   EdcDrv_u16EdcVolt = u8Temp * 5u;
   return EdcDrv_u16EdcVolt;
}

extern uint16 EdcDrv_u16GetCurrCurrent(void)
{
   uint8 u8Temp = 0u;
   LinIf_ReceiveSignal(LIN_RXSIG_EAC_HV_INPUTCURR, &u8Temp);
   EdcDrv_u16EdcCurr = u8Temp * 2u;
   return EdcDrv_u16EdcCurr;
}

extern uint16 EdcDrv_u16GetCurrPwr(void)
{
   return (EdcDrv_u16GetCurrVolt()*EdcDrv_u16GetCurrCurrent());
}


extern uint16 EdcDrv_u16GetCurrRpm(void)
{
   uint8 u8Temp = 0u;
   LinIf_ReceiveSignal(LIN_RXSIG_EAC_COMPSPD_EST, &u8Temp);
   EdcDrv_u16EdcCurrRpm = u8Temp*50u;
   return EdcDrv_u16EdcCurrRpm;
}

extern void EdcDrv_vidGetDtcSts(void)
{
    uint8 u8Temp1,u8Temp2,u8Temp3;
    LinIf_ReceiveSignal(LIN_RXSIG_EAC_OFF_SENS_FLT, &u8Temp1);
    LinIf_ReceiveSignal(LIN_RXSIG_EAC_OFF_STALL, &u8Temp2);
    LinIf_ReceiveSignal(LIN_RXSIG_EAC_RSERR, &u8Temp3);
    if((u8Temp1 == 1u)||(u8Temp2 == 1u)||(u8Temp3 == 1u))
    {
      EdcDrv_u8EvcDtcSts = 1u;
    }
    else
    {
      EdcDrv_u8EvcDtcSts = 0u;
    }
    LinIf_udtSendSignal(LIN_TXSIG_EAC_COMP_FAULT_CLAER_RQ, &EdcDrv_u8EvcDtcSts); 
}

extern void vidAppEdcMng(uint16 u16EdcSpdReq)
{
    uint8 u8InitReq = 0u;
    uint8 u8Temp_HVallow = 0u;
    uint8 u8InitmReq = 0u;
    u8Temp_HVallow = IfRteApp_Get_EACAllowFromCAN();
    LinIf_udtSendSignal(LIN_TXSIG_EAC_COMP_ON_RQ, &u8Temp_HVallow); 
    if((u8Temp_HVallow == 0u)||(u16EdcSpdReq < 800u))
    {
      u16EdcSpdReq = 0u;
    }

    u16EdcSpdReq = (uint8)(u16EdcSpdReq / 50u);
    LinIf_udtSendSignal(LIN_TXSIG_EAC_COMPSPD_TARGET, &u16EdcSpdReq); 
    EdcDrv_vidGetDtcSts();
}



/*-------------------------------- end of file -------------------------------*/

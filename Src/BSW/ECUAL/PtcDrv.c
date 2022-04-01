/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "PtcDrv.h"
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

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
extern void PtcDrv_vidInit(void)
{

}

extern void PtcDrv_vidSetPtcHeatingPercentReq(uint8 u8PercentReq)
{

}


extern uint16 PtcDrv_u16GetPtcInTwPhy(void)
{
	uint8 u8Temp = 0u;

    return u8Temp;
}

extern boolean PtcDrv_bGetDtcSts(void)
{
    boolean bPtcDtc = 0u;
    return bPtcDtc;
}

extern boolean PtcDrv_bGetShutlmmeSts(void)
{
	uint8 u8PtcShutlmmeFlag = 0u;

    return u8PtcShutlmmeFlag;
}


extern boolean PtcDrv_bGetTempSensorDtcSts(void)
{
	boolean bRtn = 0u;

    return bRtn;
}



extern uint16 PtcDrv_u16GetCurrVolt(void)
{
  uint16 u16Volt= 0u;

   return u16Volt;
}

extern uint16 PtcDrv_u16GetCurrCurrent(void)
{
   uint16 u16Curr = 0u;

   return u16Curr;
}

extern uint8 PtcDrv_u8GetPtcCurrDuty(void)
{
	uint8 u8Temp = 0u;
    return u8Temp;
}


///////
void hvwh_set_CMD_CTPE_EAU_BT(uint8 value)
{
    l_u8_wr_LI0_CMD_CTPE_EAU_BT(value);
}

void hvwh_set_COUPURE_CONSO_CPT(uint8 value)
{
    l_bool_wr_LI0_COUPURE_CONSO_CPT(value);
}

void hvwh_set_CMD_PWR_LIMIT_HVWH(uint8 value)
{
    l_u8_wr_LI0_CMD_PWR_LIMIT_HVWH(value);
}

void hvwh_set_CDE_PV_LIN(uint8 value)
{
    l_u8_wr_LI0_CDE_PV_LIN(value);
}


float hvwh_get_TENSION_LV_CTPE_ELEC()
{
    return l_u8_rd_LI0_TENSION_LV_CTPE_ELEC()*10.0;
}
float hvwh_get_TEMP_EAU_CPT_BT()
{
    return l_u8_rd_LI0_TEMP_EAU_CPT_BT()*1.0-40;
}

float hvwh_get_I_CONSO_CTP_EAU_BT()
{
    return l_u16_rd_LI0_I_CONSO_CTP_EAU_BT()*0.1;
}

uint16 u16PowerHVCH()
{
    return (hvwh_get_TENSION_LV_CTPE_ELEC()*hvwh_get_I_CONSO_CTP_EAU_BT());
}
uint16 u16HVCHStatus()
{
    uint16 u16HVCHRealPwm = 0u;
    u16HVCHRealPwm = (uint16)(u16PowerHVCH()/80);
    return (u16HVCHRealPwm);
}

void vidAppHvchMng(uint16 u16HVCHpwmReq)
{
    uint8 u8Temp_HVallow = 0u;
    u8Temp_HVallow = IfRteApp_Get_HVHAllowFromCAN();
    if(u8Temp_HVallow == 1u)
    {
      hvwh_set_CMD_PWR_LIMIT_HVWH(100u);    
    }
    else
    {
      hvwh_set_CMD_PWR_LIMIT_HVWH(0u);    
    }
    hvwh_set_CMD_CTPE_EAU_BT(u16HVCHpwmReq);
    hvwh_set_CDE_PV_LIN(1u);
}
/*-------------------------------- end of file -------------------------------*/

/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Blower                                                  */
/*                                                                            */
/* !Component       : Blower                                                  */
/* !Description     : Provides interface for controlling the blower           */
/*                                                                            */
/* !Module          : Blower                                                  */
/* !Description     : Provides interface for controlling the blower           */
/*                                                                            */
/* !File            : Blower.c                                                */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Blower.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:10   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/

 
 /******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Pump.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"

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
static uint16 Pump_u16CurrSpd;




/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/




/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/



/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

void Pump_vidInit(void)
{
    Pump_u16CurrSpd = 0u;
}


void PumpHVAC_vidSetSpdReq(uint16 u16SpdReq)
{
	uint8 u8Temp = 0u;
	u8Temp = 0x3c;
    if(u16SpdReq > 0u)
    {
      u16SpdReq = u16SpdReq*55u; 
      if(u16SpdReq < 1500u)
      {
        u16SpdReq = 1500u;
      }
      else if(u16SpdReq > 6000u)
      {
        u16SpdReq = 6000u;
      }
      else
      {
        /*do nothing*/
      }
    }    
	LinIf_udtSendSignal(LIN_TXSIG_PUMP_ACT_CTRL_byNAD, &u8Temp);
	LinIf_udtSendSignal(LIN_TXSIG_PUMP_ACT_CTRL_byTargetSpeed, &u16SpdReq);
}

uint16 PumpHVAC_u16GetCurrpd(void)
{
  uint16 u16Temp = 0u;
  LinIf_ReceiveSignal(LIN_RXSIG_PUMP_ACT_STATUS_bySpeedStatus, &u16Temp);
  Pump_u16CurrSpd = (uint16)(u16Temp/55u);
  return Pump_u16CurrSpd;
}

void PumpBat_vidSetSpdReq(uint16 u16SpdReq)
{
	uint8 u8Temp = 0u;
	u8Temp = 0x3A;
    if(u16SpdReq > 0u)
    {
      u16SpdReq = u16SpdReq*55u; 
      if(u16SpdReq < 1500u)
      {
        u16SpdReq = 1500u;
      }
      else if(u16SpdReq > 6000u)
      {
        u16SpdReq = 6000u;
      }
      else
      {
        /*do nothing*/
      }
    }    
	LinIf_udtSendSignal(LIN_TXSIG_PUMP_BAT_CTRL_byNAD, &u8Temp);
	LinIf_udtSendSignal(LIN_TXSIG_PUMP_BAT_CTRL_byTargetSpeed, &u16SpdReq);
}

uint16 PumpBat_u16GetCurrpd(void)
{
  uint16 u16Temp = 0u;
  LinIf_ReceiveSignal(LIN_RXSIG_PUMP_BAT_STATUS_bySpeedStatus, &u16Temp);
  Pump_u16CurrSpd = (uint16)(u16Temp/55u);
  return Pump_u16CurrSpd;
}
void PumpMotor_vidSetSpdReq(uint16 u16SpdReq)
{
	uint8 u8Temp = 0u;
	u8Temp = 0x39;
    if(u16SpdReq > 0u)
    {
      u16SpdReq = u16SpdReq*55u; 
      if(u16SpdReq < 1500u)
      {
        u16SpdReq = 1500u;
      }
      else if(u16SpdReq > 6000u)
      {
        u16SpdReq = 6000u;
      }
      else
      {
        /*do nothing*/
      }
    }    
	LinIf_udtSendSignal(LIN_TXSIG_PUMP_MOTOR_CTRL_byNAD, &u8Temp);
	LinIf_udtSendSignal(LIN_TXSIG_PUMP_MOTOR_CTRL_byTargetSpeed, &u16SpdReq);
}

uint16 PumpMotor_u16GetCurrpd(void)
{
  uint16 u16Temp = 0u;
  LinIf_ReceiveSignal(LIN_RXSIG_PUMP_MOTOR_STATUS_bySpeedStatus, &u16Temp);
  Pump_u16CurrSpd = (uint16)(u16Temp/55u);
  return Pump_u16CurrSpd;
}



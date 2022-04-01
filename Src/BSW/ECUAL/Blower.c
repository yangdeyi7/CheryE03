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
#include "Blower.h"
#include "Pwm.h"
#include "ADC.h"
#include "TAB.h"
#include "Eeprom.h"
#include "power.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "Sokon_X01_Thm.h"
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
static uint16 Blower_u16CurrSpd;




/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/




/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/



/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/


extern void Blower_vidInit(void)
{
    Blower_u16CurrSpd = 0u;
}/* End of Blower_vidInit() */

void vidAppBlwMotorMng(uint8 u8BlwVolReq)
{
  uint16 u16BlwSpeed = 0u;
  u16BlwSpeed = (uint16)(u8BlwVolReq*30u);
  Blower_vidSetSpdReq(u16BlwSpeed);
}
extern void Blower_vidSetSpdReq(uint16 u16SpdReq)
{
	uint8 u8Temp = 4u;
	uint16 u16Temp = 0u;
	u16Temp = 4500u;
    LinIf_udtSendSignal(LIN_TXSIG_BLW_BLOWER_RAMP, &u8Temp);
	u8Temp = (uint8)(u16Temp / 20u);
	LinIf_udtSendSignal(LIN_TXSIG_BLW_SAFETY_SPEED, &u8Temp);
	u8Temp = (uint8)(u16SpdReq / 20u);
	LinIf_udtSendSignal(LIN_TXSIG_BLW_BLOWER_SPEED, &u8Temp);
}

extern uint16 Blower_u16GetCurrpd(void)
{
  uint8 u8Temp = 0u;
  LinIf_ReceiveSignal(LIN_RXSIG_BLW_BLOWER_ROTATION_SPEED, &u8Temp);
  Blower_u16CurrSpd = u8Temp * 20;
  //Blower_u16CurrSpd = u8Temp;
  return Blower_u16CurrSpd;
}






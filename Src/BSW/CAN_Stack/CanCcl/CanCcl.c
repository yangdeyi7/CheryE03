/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : CanCcl                                                  */
/*                                                                            */
/* !Component       : CanCcl                                                  */
/* !Description     : CAN communication interface                             */
/*                                                                            */
/* !Module          : CanCcl                                                  */
/* !Description     : CAN communication interface                             */
/*                                                                            */
/* !File            : CanCcl.c                                                */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/CO$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanCcl/CanCcl.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:08   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:06   chunping.yan
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
#include "can.h"
#include "CanIf.h"
#include "s32k144_Dio.h"
#include "Can_Hdl.h"
#include "CanTrcv.h"
#include "CanCcl.h"
#include "CanDiag.h"
#include "CanTp.h"
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
static uint8 CanCcl_u8RxState;
static uint8 CanCcl_u8TxState;
static CanCcl_tenuCanModeType CanCcl_enuCanMode;
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidCclRxTask(void);
static void vidCclTxTask(void);
static void vidCclComStop(void);
static void vidCclComSleep(void);
static void vidCclComWork(void);
/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

static void vidCclRxTask(void)
{
	CanIf_vidRxTask();
}

static void vidCclTxTask(void)
{
	CanIf_vidTxTask();
}


static void vidCclComStop(void)
{
	/*stop can controller*/

	/*standby trcv*/
	CanTrcv_vidSleepTrcvFct();
	
}

static void vidCclComSleep(void)
{
	/*stop can controller*/

	/*sleep trcv*/
	CanTrcv_vidSleepTrcvFct();
	
}



extern void vidCclComWork(void)
{
	CanIf_vidEnableAppComTx2();
	CanIf_vidEnableAppComRx2();
	if (CanCcl_u8TxState == STD_ON)
	{				
		vidCclTxTask();
	}
	if (CanCcl_u8RxState == STD_ON)
	{
		vidCclRxTask();
	}
}

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void CanCcl_vidInit(void)
{
	/*init variables*/
	CanCcl_u8RxState = STD_ON;
	CanCcl_u8TxState = STD_ON;
	/*init trcv*/
	CanTrcv_vidTrcvInitFct();
	/*init CanDrv*/
	Can_vidInit();	
    /*init CanHdl*/
	Can_vidHdlInit();
	/*init CanIf*/
	CanIf_vidInit();
	/*init CanTp*/
	CanTp_vidInit();
	/*init CanDiag*/
	CanDiag_vidInit();
	/*set call back*/
	CanCcl_enuCanMode = CANCCL_CMT_STOP;
}

void CanCcl_vidMainTask(void)
{
	/*mode transition*/
	switch (CanCcl_enuCanMode)
	{
		case CANCCL_CMT_START:
			CanCcl_enuCanMode = CANCCL_CMT_WORK;
			break;
		case CANCCL_CMT_WORK:
			/*do something*/
			vidCclComWork();
			break;
		case CANCCL_CMT_SLEEP:
			vidCclComSleep();
			break;				
		case CANCCL_CMT_STOP:
			vidCclComStop();			
			break;
		default :
		
			break;
	}
	
	CanTp_vidManage();
	CanDiag_vidManage();
}




extern void CanCcl_vidSetCanMode(CanCcl_tenuCanModeType enuCanMode)
{
	CanCcl_enuCanMode = enuCanMode;
}

extern void CanCcl_vidSetTxState(uint8 u8State)
{
	if (u8State == STD_ON)
	{
		CanCcl_u8TxState = STD_ON;		
	}
	else
	{
		CanCcl_u8TxState = STD_OFF;
	}		
}

extern void CanCcl_vidSetRxState(uint8 u8State)
{
	if (u8State == STD_ON)
	{
		CanCcl_u8RxState = STD_ON;		
	}
	else
	{
		CanCcl_u8RxState = STD_OFF;
	}
}

/*-------------------------------- end of file -------------------------------*/

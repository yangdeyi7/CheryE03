/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "ExvDrv.h"


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
static ExvDrv_tenuCaliStatus   ExvDrv_aenuCaliStatus[u8EXV_NUM];
static uint16                  ExvDrv_au16CurrStepPosi[u8EXV_NUM];
static uint16                  ExvDrv_au16PressSensorValue[u8EXV_NUM];
static sint16                  ExvDrv_as16TempSensorValue[u8EXV_NUM];
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
extern void ExvDrv_vidInit(void)
{
    uint8 u8Index;
    for(u8Index = 0u; u8Index < u8EXV_NUM; u8Index++)
    {
		ExvDrv_au16CurrStepPosi[u8Index] = 0u;
		ExvDrv_aenuCaliStatus[u8Index] = EXV_NOT_CAL;
		ExvDrv_au16PressSensorValue[u8Index] = 0u;
		ExvDrv_as16TempSensorValue[u8Index] = 0;
    }
}

extern void  ExvDrv_vidCalibration(uint8 u8ExvId)
{
	uint16 au16Temp[u8EXV_NUM] = {0u,0u};
	static uint8 LOC_au8ExvCalStep[u8EXV_NUM] = {0u,0u};

	switch(LOC_au8ExvCalStep[u8ExvId])
	{
		case 0:
			au16Temp[u8ExvId] = 1u;
			if(u8EXV_CHILLER_ID == u8ExvId)
			{
				LinIf_udtSendSignal(LIN_TXSIG_CHILLER_EXV_INIT_CMD, &au16Temp[u8ExvId]);
				ExvDrv_aenuCaliStatus[u8EXV_CHILLER_ID] = EXV_CAL_ING;
				LOC_au8ExvCalStep[u8ExvId] = 1u;
			}
			else if(u8EXV_EVAP_ID == u8ExvId)
			{
				LinIf_udtSendSignal(LIN_TXSIG_EVAP_EXV_INIT_CMD, &au16Temp[u8ExvId]);
				ExvDrv_aenuCaliStatus[u8EXV_EVAP_ID] = EXV_CAL_ING;
				LOC_au8ExvCalStep[u8ExvId] = 1u;
			}
			else
			{

			}
			break;



		case 1:
			if(u8EXV_CHILLER_ID == u8ExvId)
			{
				LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_POSI_ST, &au16Temp[u8ExvId]);
				if(576u == au16Temp[u8ExvId])
				{
                    au16Temp[u8ExvId] = 0u;
					LinIf_udtSendSignal(LIN_TXSIG_CHILLER_EXV_INIT_CMD, &au16Temp[u8ExvId]);
					au16Temp[u8ExvId] = 1u;
					LinIf_udtSendSignal(LIN_TXSIG_CHILLER_EXV_SELE_CMD, &au16Temp[u8ExvId]);
					ExvDrv_aenuCaliStatus[u8ExvId] = EXV_CAL_DONE;
					LOC_au8ExvCalStep[u8ExvId] = 2u;
				}
			}
			else if(u8EXV_EVAP_ID == u8ExvId)
			{
				LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_POSI_ST, &au16Temp[u8ExvId]);
				if(576u == au16Temp[u8ExvId])
				{
                    au16Temp[u8ExvId] = 0u;
					LinIf_udtSendSignal(LIN_TXSIG_EVAP_EXV_INIT_CMD, &au16Temp[u8ExvId]);
					au16Temp[u8ExvId] = 1u;
					LinIf_udtSendSignal(LIN_TXSIG_EVAP_EXV_SELE_CMD, &au16Temp[u8ExvId]);
					ExvDrv_aenuCaliStatus[u8ExvId] = EXV_CAL_DONE;
					LOC_au8ExvCalStep[u8ExvId] = 2u;
				}
			}
			else
			{

			}
			break;

		default:
			break;
	}
}

extern ExvDrv_tenuCaliStatus ExvDrv_enuGetCalibrationSts(uint8 u8ExvId)
{
     return ExvDrv_aenuCaliStatus[u8ExvId];
}


/****************************************************************************/
extern void  ExvDrv_vidSetDestStepPosition(uint8 u8ExvId, uint16 u16StepPosi)
{   
    uint8 u8MoveReq = 1u;
    if(u8EXV_CHILLER_ID == u8ExvId)
	{
        LinIf_udtSendSignal(LIN_TXSIG_CHILLER_EXV_SELE_CMD, &u8MoveReq);
		LinIf_udtSendSignal(LIN_TXSIG_CHILLER_EXV_POSI_CMD, &u16StepPosi);
	}
	else if(u8EXV_EVAP_ID == u8ExvId)
	{
        LinIf_udtSendSignal(LIN_TXSIG_EVAP_EXV_POSI_CMD, &u16StepPosi);
        LinIf_udtSendSignal(LIN_TXSIG_EVAP_EXV_SELE_CMD, &u8MoveReq);
	}
	else
	{

	}
}
/*uint16 u16_sadexv = 0u;
extern void  ExvDrv_vidSetInitReq()
{
    static uint16 u16Stall_Count1 = 0u,u16Stall_Count2 = 0u;
    uint8 u8EXV_EVAP_Init = 0u,u8CHILLER_EXV_Init = 0u;
    uint8 u8EXV_Evap_Stall = 0u,u8EXV_Chil_Stall = 0u;
    
    LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_STALL_DET, &u8EXV_Chil_Stall);
    LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_STALL_DET, &u8EXV_Evap_Stall);
    u16_sadexv = ExvDrv_u16GetCurrStepPosition(u8EXV_EVAP_ID);
    if(ExvDrv_u16GetCurrStepPosition(u8EXV_EVAP_ID) > 577u)
    {
      u8EXV_EVAP_Init = 1u;
    }
    else if(u8EXV_Evap_Stall == 1u)
    {
      u8EXV_EVAP_Init = 1u;
    }
    else
    {
      u8EXV_EVAP_Init = 0u;
    }

    if(ExvDrv_u16GetCurrStepPosition(u8EXV_CHILLER_ID) > 577u)
    {
      u8CHILLER_EXV_Init = 1u;
    }
    else if(u8EXV_Chil_Stall == 1u)
    {
      u8CHILLER_EXV_Init = 1u;
    }
    else
    {
      u8CHILLER_EXV_Init = 0u;
    }
    LinIf_udtSendSignal(LIN_TXSIG_EVAP_EXV_INIT_CMD, &u8EXV_EVAP_Init); 
    LinIf_udtSendSignal(LIN_TXSIG_CHILLER_EXV_INIT_CMD, &u8CHILLER_EXV_Init);
}*/

extern uint16 ExvDrv_u16GetCurrStepPosition(uint8 u8ExvId)
{
     return ExvDrv_au16CurrStepPosi[u8ExvId];
}


extern uint16 ExvDrv_u16GetCurrPressSensorValue(uint8 u8ExvId)
{

   return ExvDrv_au16PressSensorValue[u8ExvId];
}

extern sint16 ExvDrv_s16GetCurrTempSensorValue(uint8 u8ExvId)
{

   return ExvDrv_as16TempSensorValue[u8ExvId];
}


extern void ExvDrv_vidManage(uint8 u8ExvId)
{
	sint16  s16Tmp = 0;	
	if(EXV_CAL_DONE != ExvDrv_aenuCaliStatus[u8ExvId])
	{
        ExvDrv_vidCalibration(u8ExvId);
	}
    /*else if(EXV_bGetEvaFaultStatus(u8ExvId) == TRUE)
    {
        ExvDrv_aenuCaliStatus[u8ExvId] = EXV_NOT_CAL;
    }*/
	else
	{
		if(u8EXV_CHILLER_ID == u8ExvId)
		{
			LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_POSI_ST, &ExvDrv_au16CurrStepPosi[u8ExvId]);
			
			LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_PRESS_LP, &s16Tmp);
			ExvDrv_au16PressSensorValue[u8ExvId] = s16Tmp/100;
			
			LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_TEMP_AC_LP, &s16Tmp);
			ExvDrv_as16TempSensorValue[u8ExvId] = (s16Tmp - 500);
            SEGGER_RTT_printf(0, "ExvDrv_vidManage-chiller_exv>>>>>>>:%d\r\n",ExvDrv_au16CurrStepPosi[u8ExvId]);
		}
		else if(u8EXV_EVAP_ID == u8ExvId)
		{
			LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_POSI_ST, &ExvDrv_au16CurrStepPosi[u8ExvId]);
			
			LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_PRESS_LP, &s16Tmp);
			ExvDrv_au16PressSensorValue[u8ExvId] = s16Tmp/100;
			
			LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_TEMP_AC_LP, &s16Tmp);
			ExvDrv_as16TempSensorValue[u8ExvId] = (s16Tmp - 500);
		}
		else
		{

		}
	}
}

/******************************************************************************/
/* !Function     : EXV_bGetEvaFaultStatus                                     */
/* !Description  : Get EVA EXV fault status                                   */
/*                                                                            */
/* !Trace_To     :                                                            */
/* !Parameter[in]:                                                            */
/* !Comment      : None                                                       */
/******************************************************************************/
boolean EXV_bGetEvaFaultStatus(uint8 u8ExvId)
{
    boolean bStatus = FALSE;
    uint8 u8EXV_Fault1,u8EXV_Fault2,u8EXV_Fault3;
    uint8 u8EXV_Fault4,u8EXV_Fault5;
    if(u8EXV_CHILLER_ID == u8ExvId)
    {
      LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_STALL_DET, &u8EXV_Fault1);
      LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_COMM_ERR, &u8EXV_Fault2);
      LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_PROT_FAULT, &u8EXV_Fault3);
      LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_VOLT_FAULT, &u8EXV_Fault4);
      LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_FAULT_STALL, &u8EXV_Fault5);
    }
    else if(u8EXV_EVAP_ID == u8ExvId)
    {
      LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_STALL_DET, &u8EXV_Fault1);
      LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_COMM_ERR, &u8EXV_Fault2);
      LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_PROT_FAULT, &u8EXV_Fault3);
      LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_VOLT_FAULT, &u8EXV_Fault4);
      LinIf_ReceiveSignal(LIN_RXSIG_EVAP_EXV_FAULT_STALL, &u8EXV_Fault5);
    }
    else
    {

    }    
    if((EXV_NO_FAULT != u8EXV_Fault2)
     ||(EXV_NO_FAULT != u8EXV_Fault2)
     ||(EXV_NO_FAULT != u8EXV_Fault2)
     ||(EXV_NO_FAULT != u8EXV_Fault2))
    {
      bStatus = TRUE;  
    }
    else
    {
      bStatus = FALSE;  
    }
    return bStatus;
}

/*-------------------------------- end of file -------------------------------*/

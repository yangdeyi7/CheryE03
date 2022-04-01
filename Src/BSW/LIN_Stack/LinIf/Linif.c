/******************************************************************************/
/* PROJECT  :  XXXX                                                           */
/******************************************************************************/
/*!Layer           : LIN                                                      */
/*                                                                            */
/*!Component       : LINIF                                                    */
/*!Description     : Contains the linif function                              */
/*                                                                            */
/*!Module          : Linif                                                    */
/*!Description     : Linif                                                    */
/*                                                                            */
/*!File            : Linif.c                                                  */
/*                                                                            */
/*!Scope           : Private                                                  */
/*                                                                            */
/*!Target          : RH850F1L                                                 */
/*                                                                            */
/*!Vendor          : VALEO Climate Control Shashi                             */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2016 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/******************************************************************************/
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/A$*/
/* $Revision::   1.1     $$Author::   yunxin.liu      $$Date::   Feb 14 2017 $*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/AppESS.h-arc  $
 * 
                                                                              */
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */

/******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Lin_rh850.h"
#include "Linif.h"
#include "Std_Types.h"



/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
static uint8 LinIf_u8Status = LINIF_UNINIT;

#if(LINIF_CHANNEL_NUM > 1)
    /* ScheduleTable handle , also the entry table handle */ 
    static uint8 LinIf_au8SchHandle[LINIF_CHANNEL_NUM];
    /* ScheduleTable queue,used when request a new table */
    static uint8 LinIf_au8SchQueue[LINIF_CHANNEL_NUM]; 
    /* ScheduleTable resume,used when return from runonce table */ 
    static uint8 LinIf_au8SchResumed[LINIF_CHANNEL_NUM];     
    /* Frame handle */
    static uint8 LinIf_au8FrameHandle[LINIF_CHANNEL_NUM];   
    /* channel timer */
    static uint8 LinIf_au8TimerCounter[LINIF_CHANNEL_NUM];
    /* slot time register */
    static uint8 LinIf_au8SlotMaxTime[LINIF_CHANNEL_NUM];    
    /* frame overtime register */
    static uint8 LinIf_au8FrameMaxTime[LINIF_CHANNEL_NUM]; 
    /* table entry register */
    static const LinIf_tstrEntryType* LinIf_apstrTemEntry[LINIF_CHANNEL_NUM];    
    /* sub channel state */
    static LinIf_tenuChSubStateType LinIf_aenuChSubState[LINIF_CHANNEL_NUM];   
    /* channel sleep request*/
    static uint8 LinIf_au8ChSleepRequestFlag[LINIF_CHANNEL_NUM]; 
    /* channel schdele  request*/
    static uint8 LinIf_au8ChSchRequestFlag[LINIF_CHANNEL_NUM]; 

    #define  LinIf_u8SchHandle            LinIf_au8SchHandle[u8Channel]
    #define  LinIf_u8SchQueue             LinIf_au8SchQueue[u8Channel]
    #define  LinIf_u8SchResumed           LinIf_au8SchResumed[u8Channel]
    #define  LinIf_u8FrameHandle          LinIf_au8FrameHandle[u8Channel]
    #define  LinIf_u8TimerCounter         LinIf_au8TimerCounter[u8Channel]
    #define  LinIf_u8SlotMaxTime          LinIf_au8SlotMaxTime[u8Channel]
    #define  LinIf_u8FrameMaxTime         LinIf_au8FrameMaxTime[u8Channel]
    #define  LinIf_pstrTemEntry           LinIf_apstrTemEntry[u8Channel]
    #define  LinIf_enuChSubState          LinIf_aenuChSubState[u8Channel]
    #define  LinIf_u8ChSleepRequestFlag   LinIf_au8ChSleepRequestFlag[u8Channel]
    #define  LinIf_u8ChSchRequestFlag     LinIf_au8ChSchRequestFlag[u8Channel]
       
#else
    static uint8 LinIf_u8SchHandle;                                           
    static uint8 LinIf_u8SchQueue;                                            
    static uint8 LinIf_u8SchResumed;                                                                        
    static uint8 LinIf_u8FrameHandle;                                         
    static uint8 LinIf_u8TimerCounter;                                        
    static uint8 LinIf_u8SlotMaxTime;                                         
    static uint8 LinIf_u8FrameMaxTime;                                        
    static const LinIf_tstrEntryType* LinIf_pstrTemEntry;                          
    static LinIf_tenuChSubStateType LinIf_enuChSubState ;                                         
    static uint8 LinIf_u8ChSleepRequestFlag;                                  
    static uint8 LinIf_u8ChSchRequestFlag;
#endif

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static uint8 u8PduIndex;


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
static void LinIf_vidScheduleTableManager(const uint8 u8Channel)

{
    #if(STD_ON == LINIF_SPORADIC_FRAME_SUPPORTED)
    uint8      temid ;
    uint8          u8Index;
    uint8          u8Sendflag = 0u;
    #endif
    
    /* LIN_tstrPduType    tempdu; */
    /* LinIf_tstrPduInfoType    temppduinfo; */

    /****** SEG4 New Table Switch ******/
    if(STD_ON == LinIf_u8ChSchRequestFlag)
    {
        LinIf_u8ChSchRequestFlag = STD_OFF;
        if(LinIf_u8SchQueue != LinIf_u8SchHandle)
        {
            LinIf_u8SchResumed = LinIf_u8SchHandle;
            /* save last table's entry */
            if(LinIf_enuResumePosition[LinIf_u8SchHandle] == START_FROM_BEGINNING)
            {
                LinIf_au8EntryIndex[LinIf_u8SchHandle] = 0u;
            }
            else
            {
                if(LinIf_au8EntryIndex[LinIf_u8SchHandle] >= 
                                     (Linif_u8TableEntryNum[LinIf_u8SchHandle]))
                {
                    LinIf_au8EntryIndex[LinIf_u8SchHandle] = 0u;
                    if(LinIf_enuRunMode[LinIf_u8SchHandle] == RUN_ONCE)
                    {
                        LinIf_u8SchResumed = 0u;
                    }
                }
            }
            /* switch to a new schedule table */
            LinIf_u8SchHandle = LinIf_u8SchQueue;
            LinIf_u8SlotMaxTime  = 0u;
            LinIf_u8FrameMaxTime = 0u;
            LinIf_u8FrameHandle  = 0u;
            LinIf_pstrTemEntry     = LINIF_NULL;
            
            #if(LinIfScheduleRequestConfirmationUL != LINIF_NO_CALLBACK)
            /*LinIfScheduleRequestConfirmation*/
            if(LINIF_NULL != LinIfScheduleRequestConfirmation)
            {
                LinIfScheduleRequestConfirmation(Channel);
            }
            #endif
        }
    }
    
    /****** SEG4 END ******/
    
    /****** SEG7 shedule table end, reset or Return to resumed Table ******/
    if(0u != LinIf_u8SchHandle)
    {
        if(LinIf_au8EntryIndex[LinIf_u8SchHandle] >= 
                                     (Linif_u8TableEntryNum[LinIf_u8SchHandle]))
        {   
            LinIf_au8EntryIndex[LinIf_u8SchHandle] = 0u;
            if(LinIf_enuRunMode[LinIf_u8SchHandle] == RUN_ONCE)
            {
                /* run once table end,return back to the saved table */
                LinIf_u8SchHandle = LinIf_u8SchResumed;
                LinIf_u8SchQueue  = LinIf_u8SchResumed;
                LinIf_u8SchResumed = 0u;
            }
        }
    }
    /****** SEG7 END ******/ 
    
    /****** SEG8 handle the current slot ******/  
    if(0u != LinIf_u8SchHandle)
    {
        /* switch to a new entry table */
        LinIf_pstrTemEntry = LinIf_apstrEntry[LinIf_u8SchHandle];
        /* get frame information of current slot */
        LinIf_u8SlotMaxTime = 
            LinIf_pstrTemEntry[LinIf_au8EntryIndex[LinIf_u8SchHandle]].u8LinIfDelay;
        LinIf_u8FrameHandle = 
            LinIf_pstrTemEntry[LinIf_au8EntryIndex[LinIf_u8SchHandle]].u8LinIfFrameRef;
        LinIf_u8FrameMaxTime =  LinIf_u8MaxFrameTime[LinIf_u8FrameHandle];
#if 0            
        tempdu.Pid = LinIf_astrPdu[LinIf_u8FrameHandle].Pid;
        tempdu.Cs = LinIf_astrPdu[LinIf_u8FrameHandle].Cs;
        tempdu.Drc = LinIf_astrPdu[LinIf_u8FrameHandle].Drc;
        tempdu.Dl = LinIf_astrPdu[LinIf_u8FrameHandle].Dl;
        tempdu.SduPtr = LinIf_astrPdu[LinIf_u8FrameHandle].SduPtr;
#endif
        //lsy (void)Lin_vidMasterSend(u8Channel,
        //    (LIN_tstrPduType*)&(LinIf_astrPdu[LinIf_u8FrameHandle]));
            
        /* next entry */
        LinIf_au8EntryIndex[LinIf_u8SchHandle]++;
    }
    /****** SEG8 end ******/  
}

static void LinIf_vidFrameStatusCheck(const uint8 u8Channel,
    const LIN_tenuStatusType enustatus)
{
    /* LinIf_tstrPduInfoType testPduInfo; */
    /* uint8 errflag = 0; */
    #if(STD_ON == LINIF_EVENT_TRIGGER_FRAME_SUPPORTED)
    Std_ReturnType tempRet;
    #endif
     
    /****** SEG6 State Read&Process ******/ 
    switch(enustatus)
    {
        case LIN_TX_OK:
 	        #if(STD_ON == LINIF_TP_SUPPORTED)
	        /* diagnostic frame type */
		    if(LinIf_FrameTypeConfig[LinIf_FrameHandle] == MRF)
		    {
		        /* call-back TpTxconfirmation function */
			    if(LinIfTpTxConfirmationUL != LINIF_NULL)
			    {      
				    LinIfTpTxConfirmationUL(0);
			    }
		    }
		    #endif
#if 0        
            /* Call Tx-Confirmation */
            if(LinIfTxConfirmationUL != LINIF_NULL)
            {
                LinIfTxConfirmationUL(LinIf_FrameHandle);
            }
#endif
            break;

        case LIN_RX_OK:
            /* call rx-confirmation */
            /*
            testPduInfo.SduDataPtr = LinIf_astrPdu[LinIf_u8FrameHandle].pu8SduPtr;
            testPduInfo.SduLength = LinIf_astrPdu[LinIf_u8FrameHandle].udtDl;
            */
		    #if(STD_ON == LINIF_TP_SUPPORTED)
	        /* diagnostic frame type */
		    if(SRF == LinIf_FrameTypeConfig[LinIf_FrameHandle])
		    {
		        /* call-back TpRxIndication function */
			    if(LinIfTpRxIndicationUL != LINIF_NULL)
			    {      
				    LinIfTpRxIndicationUL(LinIf_FrameHandle, &testPduInfo);
			    }
		    }
		    #endif
#if 0        
            if(LinIfRxIndicationUL != LINIF_NULL)
            {      
                LinIfRxIndicationUL(LinIf_FrameHandle, &testPduInfo);
            }
#endif
            break;
    
        case LIN_UNINIT:
        case LIN_OPERATIONAL:
        case LIN_RX_HEADER_OK:
            break;
        
        case LIN_ERROR:
            /* report error */
            /* errflag = 1; */
            break;
    
        case LIN_CH_SLEEP:
            break;
        
        default:
            break;
    }
#if 0    
    if(1 == errflag)
    {
        if(LINIF_NULL != LinIf_ErrorIndicatioCallback)
        {
            LinIf_ErrorIndicatioCallback(LinIf_FrameHandle, status);
        }
    }
#endif
    /****** SEG6 END ******/
}

extern void LinIf_vidInit(const void* pu8ConfigPtr)
{
    uint8 u8Index;
    #if(LINIF_CHANNEL_NUM > 1u)
    uint8 u8Channel;
    #else
    /* const uint8 u8Channel = 0u; */
    #endif
    
    #if(LINIF_DEV_ERROR_DETECT == STD_ON)
    if(LinIf_u8Status == LINIF_INIT)
    {
    /* report error */
    } 
    else
    {
    #endif
    
        /*******************************************************************
        * PRQA S 3112   MISRA-C:2004 Rule 14.2
        * ConfigPtr will be used in further version code. In this version,  
        * it's just reversed to fulfill the AUTOSAR API. 
        * The "(void)" is to avoid generate warning information. 
        * This part of code is verified manually and has no impact.
        *******************************************************************/
        (void)pu8ConfigPtr;
        #if(LINIF_CHANNEL_NUM > 1u)
        for(u8Channel = 0u; u8Channel < LINIF_CHANNEL_NUM; u8Channel++)
        {
        #endif
            /* init all internal variables */
            LinIf_enuChSubState   = CHANNEL_UNINIT;
            LinIf_u8SchHandle    = 0u;
            LinIf_u8SchResumed   = 0u;
            LinIf_u8SchQueue     = 0u;
            LinIf_u8FrameHandle  = 0u;
            LinIf_u8TimerCounter = 0u;
            LinIf_u8SlotMaxTime  = 0u;
            LinIf_u8FrameMaxTime = 0u;
            LinIf_pstrTemEntry     = LINIF_NULL;
#if 0
            if(LINIF_SLEEP == LinIf_StartupState[u8Channel])
            {
                LinIf_enuChSubState = CHANNEL_SLEEP;
                (void)Lin_GoToSleepInternal(u8Channel);
            }
            else
#endif
            {
                LinIf_enuChSubState = CHANNEL_OPERATIONAL;
            }
            LinIf_u8ChSleepRequestFlag = LINIF_NO_SLEEP_REQ;
            LinIf_u8ChSchRequestFlag = STD_OFF;
        #if(LINIF_CHANNEL_NUM > 1)
        }
        #endif
    
        for(u8Index = 0u; u8Index < LinIf_u8SchNum; u8Index++)
        {
            LinIf_au8EntryIndex[u8Index] = 0u;
        }

        LinIf_u8Status  = LINIF_INIT;
    }
    
}

extern Std_ReturnType LinIf_udtScheduleRequest
(
    uint8 u8Channel,
    uint8 u8Schedule
)
{
    Std_ReturnType udttem = E_OK;

    #if(LINIF_DEV_ERROR_DETECT == STD_ON)
    if(LinIf_u8Status == LINIF_UNINIT)
    {
        udttem = E_NOT_OK;
    }
    else if(u8Channel >= LINIF_CHANNEL_NUM)
    {
        udttem = E_NOT_OK;
    } 
    else if((u8Schedule >= LinIf_u8SchNum))
    {
        udttem = E_NOT_OK;
    } 
    else if(LinIf_enuChSubState == CHANNEL_SLEEP) 
    {
        udttem = E_NOT_OK;
    }
    else
    {
    #endif  
        /* insert the requst into the queue,and excute it 
           when the next entry arrive */
        if(LinIf_u8SchHandle != u8Schedule)
        {
            LinIf_u8ChSchRequestFlag = STD_ON;
            LinIf_u8SchQueue = u8Schedule;
        }
    #if(LINIF_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
    return udttem;
}

extern void LinIf_vidMainFunction(void)
{
    #if(LINIF_CHANNEL_NUM > 1u)
    uint8 u8Channel;
    #else
    const uint8 u8Channel = 0u;
    #endif
    /* uint8 u8temNullPtr[LIN_MAX_DATA_DLC]; */
    uint8 u8entryArriveFlag = 0u;
    uint8 u8frameMaxArriveFlag = 0u;
    LIN_tenuStatusType enuStatus;
    /* boolean bSleepResult = FALSE; */
    Std_ReturnType udtTempRet;
    /*LIN_tenuStatusType enuTempStatus; */
  
    #if(LINIF_DEV_ERROR_DETECT == STD_ON)
    if(LinIf_u8Status == LINIF_UNINIT)
    {
        /*report error */
    }
    else 
    {
    #endif

        #if(LINIF_CHANNEL_NUM > 1u)
        for(u8Channel = 0u; u8Channel < LINIF_CHANNEL_NUM; u8Channel++)
        {
        #endif
            if(LinIf_enuChSubState == CHANNEL_UNINIT)
            {
                /*report error */
            }
#if 0
            else if(LinIf_enuChSubState == CHANNEL_SLEEP)
            {
                if(LINIF_NO_SLEEP_REQ != LinIf_u8ChSleepRequestFlag )
                {
                    LinIf_u8ChSleepRequestFlag = LINIF_NO_SLEEP_REQ;
                    udtTempRet = Lin_GoToSleepInternal(u8Channel);
                    if(E_OK == udtTempRet)
                    {
                        enuTempStatus = Lin_GetStatus(u8Channel, u8temNullPtr);
                        if(LIN_CH_SLEEP == enuTempStatus)
                        {
                            /* LinIfGotoSleepConfirmation - true */
                            bSleepResult = TRUE;
                        }
                    }
                    
                    #if(LinIfGotoSleepConfirmationUL != LINIF_NO_CALLBACK)
                    if(LINIF_NULL != LinIfGotoSleepConfirmation)
                    {
                        LinIfGotoSleepConfirmation(u8Channel, bSleepResult);
                    }
                    #endif
                }  
            }
#endif
            else /*CHANNEL_OPERATIONAL*/
            {
                /* Null Table */
                if(LINIF_NULL_TABLE == LinIf_u8SchHandle)
                {
                    if(LINIF_INIT_SLEEP_REQ == LinIf_u8ChSleepRequestFlag)
                    {
                        u8entryArriveFlag = 1u;
                    }
                    else if(LINIF_WAIT_SLEEP_STATUS == LinIf_u8ChSleepRequestFlag)
                    {
                        if(LinIf_u8TimerCounter >= LinIf_u8FrameMaxTime)
                        {
                            u8frameMaxArriveFlag = 1u;
                            LinIf_u8TimerCounter = 0u;
                        }
                    }
                    else
                    {
                        u8entryArriveFlag = 1u;
                    }
                }
                /* User Table */
                else
                {
                    if(LinIf_u8TimerCounter == LinIf_u8FrameMaxTime)
                    {
                        u8frameMaxArriveFlag = 1u;
                    }
                    if(LinIf_u8TimerCounter >= LinIf_u8SlotMaxTime)
                    {
                        u8entryArriveFlag = 1u;
                        LinIf_u8TimerCounter = 0u;
                    }
                }
                /* frame max time arrive,check frame status */
                if(1u == u8frameMaxArriveFlag)
                {
                    /* PRQA S 3199 */
                    u8frameMaxArriveFlag = 0u;
                    enuStatus =  Lin_enuGetStatus(u8Channel);
                
                    if(LINIF_WAIT_SLEEP_STATUS == LinIf_u8ChSleepRequestFlag)
                    {
                        LinIf_enuChSubState = CHANNEL_SLEEP;
                        LinIf_u8ChSleepRequestFlag = LINIF_NO_SLEEP_REQ;
                        /* switch to NULL table */
                        LinIf_u8SchHandle = 0u;
                        LinIf_u8SchQueue  = 0u;
                        if(LIN_CH_SLEEP == enuStatus)
                        {
                            /* LinIfGotoSleepConfirmation - true */
                            /* bSleepResult = TRUE; */
                        }
                        
                    }
                    else
                    {
                        LinIf_vidFrameStatusCheck(u8Channel, enuStatus);
                    }
                }
                /* Slot end,new entry arrive  */
                if(1 == u8entryArriveFlag)
                {
                    /* PRQA S 3199 */
                    u8entryArriveFlag = 0u;
                    if(LINIF_INIT_SLEEP_REQ == LinIf_u8ChSleepRequestFlag)
                    {
                        LinIf_u8FrameMaxTime = LINIF_SLEEP_FRAMEMAXTIME;
                        udtTempRet = Lin_udtGoToSleep(u8Channel);
                        if(E_OK == udtTempRet)
                        {
                            LinIf_u8ChSleepRequestFlag = LINIF_WAIT_SLEEP_STATUS;
                        }
                    }
                    else
                    {
					    LinIf_u8TimerCounter = 0u;
                        LinIf_vidScheduleTableManager(u8Channel);
                    }
                }
                /* ticks add */
                LinIf_u8TimerCounter++;
            }  
        #if(LINIF_CHANNEL_NUM > 1u)
        }
        #endif
    #if(LINIF_DEV_ERROR_DETECT == STD_ON)
    }
    #endif

}

#if(LIN_TXSIGNUM > 0)
/*******************************************************************************
* Function Name: LinIf_SendSignal
*                 
* Description:   This service updates the signal object identified by 
*                SignalId with the signal referenced by the SignalDataPtr 
*                parameter  
*                 
* Inputs:        LinTxSignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*       
* Outputs:       E_OK:                      service has been accepted
*                E_NOT_OK:                  service request fail 
* 
* Limitations:   None
*******************************************************************************/
extern Std_ReturnType LinIf_udtSendSignal
(
    uint8 u8LinTxSignalId,
    const void  *pvidSignalDataPtr
)
{                  
    uint8 u8result = E_NOT_OK;

    if(u8LinTxSignalId < LIN_TXSIGNUM)
    {

            if(Lin_vidSendSignalFunPrt[u8LinTxSignalId] != NULL_PTR)
            {
                Lin_vidSendSignalFunPrt[u8LinTxSignalId](pvidSignalDataPtr);  
                u8result = E_OK;        
            }
            else
            {
                u8result = E_NOT_OK;
            } 
    }
    else
    {
        u8result = E_NOT_OK;
    }

    return  u8result;

}
#endif

#if(LIN_RXSIGNUM > 0)
/*******************************************************************************
* Function Name: LinIf_ReceiveSignal
*                 
* Description:   This service copies the data of signal identified by SignalId
*                to the location specified by SignalDataPtr  
*                 
* Inputs:        LinRxSignalId: ignal handle
*                SignalDataPtr: Reference to the location where the received
*                               signal data shall be stored
*       
* Outputs:       E_OK:                      service has been accepted
*                E_NOT_OK:                  service request fail 
* 
* Limitations:   None
*******************************************************************************/
extern Std_ReturnType LinIf_ReceiveSignal
(
    uint8 u8LinRxSignalId, 
    void *pvidSignalDataPtr
)
{

    uint8 u8result = E_NOT_OK;                      

    if(u8LinRxSignalId < LIN_RXSIGNUM)  
    {

            if(Lin_vidReceivedSignalFunPrt[u8LinRxSignalId] != NULL_PTR)
            {
                Lin_vidReceivedSignalFunPrt[u8LinRxSignalId](pvidSignalDataPtr); 
                u8result = E_OK;
            }
            else
            {
                u8result = E_NOT_OK;
            }        
    }
    else
    {
        u8result = E_NOT_OK;
    }

    return  u8result;

}
#endif

Std_ReturnType CopyToLINDiagReqBuff(uint8 CanTpTxSduId, const LinIf_tstrPduInfoType* pData){

  uint8 u8Index;
  uint8* pu8temptr;
  
  pu8temptr = LinIf_astrPdu[3u].pu8SduPtr; 
  for (u8Index = 0u; u8Index < 8u; u8Index++)
     *(pu8temptr + u8Index) = *(pData->SduDataPtr + u8Index);
     
  (void)LinIf_udtScheduleRequest(0u,2u);
  return E_OK;
}

extern void LinIf_vidManage(void)
{
    LIN_tenuStatusType enuLinStatus;
    static uint8 u8DelayRx;
    static uint8 u8DelayTx;

    enuLinStatus = Lin_enuGetStatus(0u);
//#ifdef LIN_SLAVE
    if (LIN_RX_OK == enuLinStatus)
    {
        u8DelayRx = 50u;
        Lin_vidSetStatus(0u, LIN_OPERATIONAL);
    }
    else if (LIN_TX_OK == enuLinStatus)
    {
        u8DelayTx = 50u;
        Lin_vidSetStatus(0u, LIN_OPERATIONAL);
    }
    else
    {
		
    }

    if (0u < u8DelayRx)
    {
        u8DelayRx--;
    }
    else
    {

    }

    if (0u < u8DelayTx)
    {
        u8DelayTx--;
    }
    else
    {

    }
//#else
    /* if ((LIN_RX_OK == enuLinStatus) || (LIN_TX_OK == enuLinStatus)
        || (LIN_OPERATIONAL== enuLinStatus)) */
    {
        LinIf_udtScheduleRequest(0u, 1u);
        LinIf_vidMainFunction();
    }

//#endif
}

extern uint8 LinIf_u8GetFrame(uint8 u8Pid, uint8* pu8Len, uint8* pu8Data)
{
    uint8 u8Result = 0u;
    uint8 u8Index = 0u;
    uint8 u8DataInd;
    
    if ((NULL_PTR != pu8Data) && (0 != pu8Len))
    {
        /* Search for matched Pid */
        while ((u8Index < 4u) && (u8Pid != LinIf_astrPdu[u8Index].udtPid))
        {
            u8Index++;
        }

        if ((4u != u8Index) && (NULL_PTR != pu8Data))
        {
            u8Result = LinIf_astrPdu[u8Index].udtDl;
            for (u8DataInd = 0u; u8DataInd < u8Result; u8DataInd++)
            {
                pu8Data[u8DataInd] = LinIf_astrPdu[u8Index].pu8SduPtr[u8DataInd];
            }
            *pu8Len = u8Result;
        }
        else
        {
        }
    }
    else
    {
    }

    return u8Result;
}

extern uint8 LinIf_u8SetFrame(uint8 u8Pid, uint8* pu8Len, uint8* pu8Data)
{
    uint8 u8Result = 0u;
    uint8 u8Index = 0u;
    uint8 u8DataInd;

    if ((NULL_PTR != pu8Data) && (0 != pu8Len))
    {
        if (8u < *pu8Len)
        {
            *pu8Len = 8u;
        }
    
        /* Search for matched Pid */
        while ((u8Index < 4u) && (u8Pid != LinIf_astrPdu[u8Index].udtPid))
        {
            u8Index++;
        }

        if (4u != u8Index)
        {
            for (u8DataInd = 0u; u8DataInd < *pu8Len; u8DataInd++)
            {
                LinIf_astrPdu[u8Index].pu8SduPtr[u8DataInd] = pu8Data[u8DataInd];
            }
            u8Result = *pu8Len;
        }
        else
        {
        }
    }
    else
    {
    }

    return u8Result;
}


extern const LIN_tstrPduType* Linif_pstrRxHeadCb(uint8 u8ChanNum, uint8 u8Pid)
{
    static uint8 u8Alive = 0;
    uint8 u8Index = 0u;

    (void)u8ChanNum;

    /* Search for matched Pid */
    while ((u8Index < 4u) && (u8Pid != LinIf_astrPdu[u8Index].udtPid))
    {
        u8Index++;
    }
    u8PduIndex = u8Index;

    if (0u == u8Index)
    {
        if (0x0e <= u8Alive)
            u8Alive = 0u;
        else
            u8Alive++;

        LinIf_astrPdu[u8Index].pu8SduPtr[5]
            = (LinIf_astrPdu[u8Index].pu8SduPtr[5] & 0xf0) | (u8Alive & 0x0f);
    }

    return (&(LinIf_astrPdu[u8Index]));
}

extern void Linif_vidRxErrorCb(uint8 u8ChanNum, uint8 u8ErrorCode)
{
}

extern uint8 Linif_u8GetCurFrameHandle(void)
{
    return u8PduIndex;
}

extern LIN_tenuStatusType LinIf_enuGetStatus(void)
{
    return Lin_enuGetStatus(0u);
}

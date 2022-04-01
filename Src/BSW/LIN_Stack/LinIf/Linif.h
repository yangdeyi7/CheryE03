/******************************************************************************/
/* PROJECT  :  XXX                                                            */
/******************************************************************************/
/*!Layer           : LIN                                                      */
/*                                                                            */
/*!Component       : LINIF                                                    */
/*!Description     : Contains the linif function                              */
/*                                                                            */
/*!Module          : Linif                                                    */
/*!Description     : Linif                                                    */
/*                                                                            */
/*!File            : Linif.h                                                  */
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
#ifndef LINIF_H
#define LINIF_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
/* #include "Platform_Types.h" */
#include "Lin_Type_rh850.h"
#include "Lin.h"
#include "LinIf_Cfg.h"
#include "LinIf_Cbk.h"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/* #define LIN_SLAVE */

/*LINIF531:*/
typedef enum
{
    LINIF_TRCV_MODE_NORMAL,
    LINIF_TRCV_MODE_STANDBY,
    LINIF_TRCV_MODE_SLEEP
}LinIf_TrcvModeType;

/*LINIF532:*/
typedef enum
{
    LINIF_TRCV_WU_ERROR,
    LINIF_TRCV_WU_NOT_SUPPORTED,
    LINIF_TRCV_WU_BY_BUS,
    LINIF_TRCV_WU_INTERNALLY,
    LINIF_TRCV_WU_RESET,
    LINIF_TRCV_WU_POWER_ON 
}LinIf_TrcvWakeupReasonType ;

/*LINIF533:*/
typedef enum
{
    LINIF_TRCV_WU_ENABLE,
    LINIF_TRCV_WU_DISABLED,
    LINIF_TRCV_WU_CLEAR
}LinIf_TrcvWakeupModeType ;

/* config type */
typedef enum
{
    START_FROM_BEGINNING = 0,
    CONTINUE_AT_IT_POINT = 1
}LinIf_tenuResumePositionType ;

typedef enum
{
    RUN_CONTINUOUS,
    RUN_ONCE  
}LinIf_tenuRunModeType ;

#define LinIf_ChecksumType Lin_FrameCsModelType

/* schedule entry type */
typedef struct
{
    uint8 u8LinIfDelay;
    uint8 u8LinIfCollisionResolvingRef;     /* use a table index */
    uint8 u8LinIfFrameRef;
}LinIf_tstrEntryType;

/* Linif ch sub state */
typedef enum
{
    CHANNEL_UNINIT,
    CHANNEL_OPERATIONAL,
    CHANNEL_SLEEP
}LinIf_tenuChSubStateType ;

typedef struct
{
   uint8* SduDataPtr;
   uint8 SduLength;
}LinIf_tstrPduInfoType;

/*******************************************************************************
*   Macro define 
*******************************************************************************/
#define LINIF_NULL                 ((void *) 0)

#define LINIF_CLASSIC              LIN_CLASSIC_CS
#define LINIF_ENHANCED             LIN_ENHANCED_CS

#define LINIF_UNINIT               (0)
#define LINIF_INIT                 (1)

/* the following 2 macros are used when Sleep frame is send */
/* uint == ms */
#define LINIF_SLEEP_SLOTMAXTIME    ((uint8)(50/LINIF_TIME_BASE)) 
#define LINIF_SLEEP_FRAMEMAXTIME   ((uint8)(40/LINIF_TIME_BASE))

#define LINIF_NO_SLEEP_REQ         (0)
#define LINIF_INIT_SLEEP_REQ       (1)
#define LINIF_WAIT_SLEEP_STATUS    (2)


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
extern const uint8 LinIf_u8SchNum;
extern const uint8 LinIf_u8FrameNum;
extern uint8 LinIf_au8EntryIndex[];
extern const LIN_tstrPduType LinIf_astrPdu[];
extern const LinIf_tstrEntryType* LinIf_apstrEntry[];
extern const LinIf_tenuResumePositionType LinIf_enuResumePosition[];
extern uint8 LinIf_au8EntryIndex[];
extern const uint8 Linif_u8TableEntryNum[];
extern const LinIf_tenuRunModeType LinIf_enuRunMode[];
extern const uint8 LinIf_u8MaxFrameTime[];

extern void LinIf_vidInit(const void* pu8ConfigPtr);

extern void LinIf_vidManage(void);

extern Std_ReturnType LinIf_udtSendSignal( uint8 u8LinTxSignalId,
    const void  *pvidSignalDataPtr);

extern Std_ReturnType LinIf_ReceiveSignal( uint8 u8LinRxSignalId, 
    void *pvidSignalDataPtr);

extern Std_ReturnType CopyToLINDiagReqBuff(uint8 CanTpTxSduId,
    const LinIf_tstrPduInfoType* pData);

extern uint8 LinIf_u8GetFrame(uint8 u8Pid, uint8* pu8Len, uint8* pu8Data);

extern uint8 LinIf_u8SetFrame(uint8 u8Pid, uint8* pu8Len, uint8* pu8Data);

extern LIN_tenuStatusType LinIf_enuGetStatus(void);

extern uint8 Linif_u8GetCurFrameHandle(void);

/******************************************************************************/

#endif/* LINIF_H */



/******************************************************************************/
/* PROJECT  :  NL_5                                                           */
/******************************************************************************/
/*!Layer           : LIN                                                      */
/*                                                                            */
/*!Component       : LINDRV                                                   */
/*!Description     : Contains the driver of LIN                               */
/*                                                                            */
/*!Module          : LinDrv                                                   */
/*!Description     : LinDrv                                                   */
/*                                                                            */
/*!File            : Lin_Type.h                                               */
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

#ifndef LIN_TYPE_RH850_H
#define LIN_TYPE_RH850_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/*******************************************************************************
*   AutoSar standard Lin Type 
*******************************************************************************/
/*LIN228:PidType */
typedef uint8 LIN_udtFramePidType;  

/*LIN229:CsType */
typedef enum
{
    LIN_CLASSIC_CS = 0x00u,
    LIN_ENHANCED_CS = 0x20u
}LIN_tenuFrameCsModelType;

/*LIN230:response type */
typedef enum
{
    LIN_SLAVE_RESPONSE = 0x00u,
    LIN_MASTER_RESPONSE = 0x10u,
    LIN_SLAVE_TO_SLAVE
}LIN_tenuFrameResponseType;

/*LIN231:DlType */
typedef uint8 LIN_udtFrameDlType;

/*LIN232:PduType */
typedef struct
{
    LIN_udtFramePidType udtPid;
    LIN_tenuFrameCsModelType enuCs;
    LIN_tenuFrameResponseType enuDrc;
    LIN_udtFrameDlType udtDl;
    uint8* pu8SduPtr; 
}LIN_tstrPduType;

/*LIN233:StatusType */
typedef enum
{
    LIN_UNINIT,
    LIN_ERROR,
    LIN_CH_SLEEP, 
    LIN_OPERATIONAL,
    LIN_TX_OK ,
    LIN_RX_HEADER_OK,
    LIN_RX_OK,
}LIN_tenuStatusType;

#endif/* LIN_TYPE_H */

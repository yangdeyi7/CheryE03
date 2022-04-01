/*******************************************************************************
Copyright (C) 2014-2015 Valeo. All Rights Reserved.
* File: SystemAC.c
*
* Descrip:
* C/C++ source code generated on : Wed Doce  2021/12/29
* Embedded hardware selection: NXP->S32K144
* Code generation objectives: Unspecified
* Validation result: Not run

*******************************************************************************/
/*==============================================================================
File Version
--------------------------------------------------------------------------------
版本号     日期                      作者      描述
Rev00       Ver00.00.00	2021/12/29    YDY       Initialization
==============================================================================*/
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "SystemAC.h"
#include "if_rte_app.h"
#include "SystemMng.h"
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
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

void System_vidACInit(void)
{
    SYSTEM_strApp_Data.u8AcSts = AC_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = FALSE;
    IfRteApp_Set_ACSts(SYSTEM_strApp_Data.u8AcSts);   
}

void System_vidACDefault(void)
{
    SYSTEM_strApp_Data.u8AcSts = AC_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = FALSE;
    IfRteApp_Set_ACSts(SYSTEM_strApp_Data.u8AcSts);   
}
/******************************************/
/*  AC regulation                        */
/*  period = 100ms                       */
/******************************************/
void System_vidACRegulation(void)
{
    static uint8 Loc_u8LastAcKeySts = AC_KEY_NOPRESS ;
    uint8  u8AcKeySts = AC_KEY_NOPRESS;
    
    /*******get A/C key state from CAN**********/
    u8AcKeySts = IfRteApp_Get_ACStsFromCAN();
#if 0   
    /*******Judge A/C key is pressed*********/
    if( (AC_KEY_PRESSD == u8AcKeySts) && (AC_KEY_NOPRESS == Loc_u8LastAcKeySts))
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = TRUE;
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = FALSE;
    }
    
    /*******AcSts handle when A/C key is pressed*********/
    if( TRUE == SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress)
    {
      if( AC_STATE_OFF == SYSTEM_strApp_Data.u8AcSts )
      {
        SYSTEM_strApp_Data.u8AcSts = AC_STATE_ON;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = FALSE;
      }
      else if( AC_STATE_ON == SYSTEM_strApp_Data.u8AcSts )
      {
        SYSTEM_strApp_Data.u8AcSts = AC_STATE_OFF;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = FALSE;
      }
      else
      {
        SYSTEM_strApp_Data.u8AcSts = AC_STATE_INIT;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = FALSE;
      }
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAcPress = FALSE;
    }
#else
    if(IfRteApp_Get_ACStsFromCAN()==1)
    {
      SYSTEM_strApp_Data.u8AcSts = AC_STATE_ON;
    }
    else if(IfRteApp_Get_ACStsFromCAN()==2)
    {
      SYSTEM_strApp_Data.u8AcSts = AC_STATE_OFF;
    }
    else
    {
      /*do nothing*/
    }
    if(SYSTEM_strApp_Data.u8WorkSts == SYSTEM_STATE_OFF)
    {
      SYSTEM_strApp_Data.u8AcSts = AC_STATE_OFF;
    }
#endif
    IfRteApp_Set_ACSts( SYSTEM_strApp_Data.u8AcSts );
    /*******Record the last value*********/
    Loc_u8LastAcKeySts = u8AcKeySts;
}
/*-------------------------------- end of file -------------------------------*/

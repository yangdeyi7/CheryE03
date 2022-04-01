/*******************************************************************************
Copyright (C) 2014-2015 Valeo. All Rights Reserved.
* File: SystemAUTO.c
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
�汾��     ����                      ����      ����
Rev00       Ver00.00.00	2021/12/30    YDY       Initialization
==============================================================================*/
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "SystemAuto.h"
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

void System_vidAutoInit(void)
{
    SYSTEM_strApp_Data.u8AutoSts = AUTO_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_AutoSts(SYSTEM_strApp_Data.u8AutoSts);   
}

void System_vidAutoDefault(void)
{
    SYSTEM_strApp_Data.u8AutoSts = AUTO_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_AutoSts(SYSTEM_strApp_Data.u8AutoSts);   
}
/******************************************/
/*  AUTO regulation                       */
/*  period = 100ms                        */
/******************************************/
void System_vidAutoRegulation(void)
{
    static uint8 Loc_u8LastAutoKeySts = AUTO_KEY_NOPRESS ;
    uint8  u8AutoKeySts = AUTO_KEY_NOPRESS;
    
    /*******get auto key state from CAN**********/
    u8AutoKeySts = IfRteApp_Get_AutoStsFromCAN();
#if 0    
    /*******Judge auto key is pressed*********/
    if( (AUTO_KEY_PRESSD == u8AutoKeySts) && (AUTO_KEY_NOPRESS == Loc_u8LastAutoKeySts))
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = TRUE;
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    }
    
    /*******autoSts handle when auto key is pressed*********/
    if( TRUE == SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress)
    {
      if( AUTO_STATE_OFF == SYSTEM_strApp_Data.u8AutoSts )
      {
        SYSTEM_strApp_Data.u8AutoSts = AUTO_STATE_ON;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
      }
      else if( AUTO_STATE_ON == SYSTEM_strApp_Data.u8AutoSts )
      {
        SYSTEM_strApp_Data.u8AutoSts = AUTO_STATE_OFF;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
      }
      else
      {
        SYSTEM_strApp_Data.u8AutoSts = AUTO_STATE_INIT;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
      }
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    }
#else
    //SYSTEM_strApp_Data.u8AutoSts = IfRteApp_Get_AutoStsFromCAN();
    if(IfRteApp_Get_AutoStsFromCAN()==1u)
    {
      SYSTEM_strApp_Data.u8AutoSts = AUTO_STATE_ON;
    }
    else if(IfRteApp_Get_AutoStsFromCAN()==2u)
    {
      SYSTEM_strApp_Data.u8AutoSts = AUTO_STATE_OFF;
    }
    else
    {
      /*do nothing*/
    }
#endif
    IfRteApp_Set_AutoSts( SYSTEM_strApp_Data.u8AutoSts );
    /*******Record the last value*********/
    Loc_u8LastAutoKeySts = u8AutoKeySts;
}
/*-------------------------------- end of file -------------------------------*/

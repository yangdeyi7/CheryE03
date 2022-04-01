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
番号        版本号                    作者       描述
Rev00       Ver00.00.00	2021/12/30    YDY       Initialization
==============================================================================*/
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "SystemBlw.h"
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

void System_vidBlwInit(void)
{
    SYSTEM_strApp_Data.u8BlwSts = BLW_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_BlwSts(SYSTEM_strApp_Data.u8BlwSts);   
}

void System_vidBlwDefault(void)
{
    SYSTEM_strApp_Data.u8BlwSts = BLW_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_BlwSts(SYSTEM_strApp_Data.u8BlwSts);   
}
/******************************************/
/*  AUTO regulation                       */
/*  period = 100ms                        */
/******************************************/
void System_vidBlwRegulation(void)
{
    static BLW_tenuKey_Judge Loc_enuLastBlwKeySts = BLW_NOPRESS ;
    BLW_tenuKey_Judge  enuBlwKeySts = BLW_NOPRESS;
    
    /*******get auto key state from CAN**********/
    enuBlwKeySts = IfRteApp_Get_BlwStsFromCAN();
#if 0
    /********************************************/
    if((enuBlwKeySts == BLW_INCREASE) && (Loc_enuLastBlwKeySts == BLW_NOPRESS))
    {
      if( SYSTEM_strApp_Data.u8BlwSts == BLW_LEVEL_MAX )
      {
        /*do nothing*/
      }
      else
      {
        SYSTEM_strApp_Data.u8BlwSts++;
      }
    }
    else if((enuBlwKeySts == BLW_REDUCE) && (Loc_enuLastBlwKeySts == BLW_NOPRESS))
    {
      if( SYSTEM_strApp_Data.u8BlwSts == BLW_LEVEL_MIN )
      {
        /*do nothing*/
      }
      else
      {
        SYSTEM_strApp_Data.u8BlwSts--;
      }
    }
    else
    {
      /*do nothing*/
    }
#else 
    SYSTEM_strApp_Data.u8BlwSts = IfRteApp_Get_BlwStsFromCAN();
    if(SYSTEM_strApp_Data.u8WorkSts == SYSTEM_STATE_OFF)
    {
      SYSTEM_strApp_Data.u8BlwSts = BLW_LEVEL_MIN;
    }
#endif
    IfRteApp_Set_BlwSts(SYSTEM_strApp_Data.u8BlwSts);
    /***********Record the last value************/
    Loc_enuLastBlwKeySts = enuBlwKeySts;
}
/*-------------------------------- end of file -------------------------------*/

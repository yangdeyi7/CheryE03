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
�汾��     ����                      ����      ����
Rev00       Ver00.00.00	2021/12/29    YDY       Initialization
==============================================================================*/
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "SystemMng.h"
#include "if_rte_app.h"
#include "SystemAuto.h"
#include "SystemAC.h"
#include "SystemBlw.h"
#include "SystemIntake.h"
#include "SystemMode.h"
#include "SystemTset.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
SYSTEM_tuniReceive_Press_ECP  SYSTEM_uniReceive_Press_ECP;
SYSTEM_tstrApp_Data  SYSTEM_strApp_Data;
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
static SYSTEM_tenuFirstOpen_Judge SYSTEM_enuFirstOpen_Judge;
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
static void System_vidWorkInit(void)
{
    SYSTEM_strApp_Data.u8WorkSts = SYSTEM_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_WorkSts(SYSTEM_strApp_Data.u8WorkSts);   
}
static void System_vidWorkDefault(void)
{
    SYSTEM_strApp_Data.u8WorkSts = SYSTEM_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_WorkSts(SYSTEM_strApp_Data.u8WorkSts);   
}
void System_vidMngDefault(void)
{
    System_vidWorkDefault();
    System_vidACDefault();
    System_vidAutoDefault();
    System_vidBlwDefault();
    System_vidIntakeDefault();
    System_vidModeDefault();
    System_vidTsetDefault();
}

static void System_vidWorkRegulation(void)
{
    static uint8 Loc_u8LastWorkKeySts = SYSTEM_KEY_NOPRESS ;
    static uint8 Loc_u8FirstOpenFlag = FALSE ;
    uint8  u8WorkKeySts = SYSTEM_KEY_NOPRESS;
    /*********get OFF key state from CAN**********/
    u8WorkKeySts = IfRteApp_Get_OFFStsFromCAN();
#if 0    
    /**********Judge OFF key is pressed***********/
    if( (SYSTEM_KEY_PRESSD == u8WorkKeySts) && (SYSTEM_KEY_NOPRESS == Loc_u8LastWorkKeySts))
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bWorkPress = TRUE;
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bWorkPress = FALSE;
    }
    
    /*******wORKSts handle when OFF key is pressed*********/
    if( TRUE == SYSTEM_uniReceive_Press_ECP.strChangeJudge.bWorkPress)
    {
      if( SYSTEM_STATE_OFF == SYSTEM_strApp_Data.u8WorkSts )
      {
        if( SYSTEM_FIRST_CLOSE == SYSTEM_enuFirstOpen_Judge)
        {
          SYSTEM_enuFirstOpen_Judge = SYSTEM_FIRST_OPEN;
        }
        else
        {
          SYSTEM_enuFirstOpen_Judge = SYSTEM_NOTFIRST_OPEN;
        }
        SYSTEM_strApp_Data.u8WorkSts = SYSTEM_STATE_ON;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bWorkPress = FALSE;
      }
      else if( SYSTEM_STATE_ON == SYSTEM_strApp_Data.u8WorkSts )
      {
        SYSTEM_strApp_Data.u8WorkSts = SYSTEM_STATE_OFF;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bWorkPress = FALSE;
      }
      else
      {
        SYSTEM_strApp_Data.u8WorkSts = SYSTEM_STATE_INIT;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bWorkPress = FALSE;
      }
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bWorkPress = FALSE;
    }
#else
    if(IfRteApp_Get_OFFStsFromCAN()==1)
    {
      SYSTEM_strApp_Data.u8WorkSts = SYSTEM_STATE_ON;
    }
    else if(IfRteApp_Get_OFFStsFromCAN()==2)
    {
      SYSTEM_strApp_Data.u8WorkSts = SYSTEM_STATE_OFF;
    }
    else
    {
      /*do nothing*/
    }
#endif    
    IfRteApp_Set_WorkSts( SYSTEM_strApp_Data.u8WorkSts );
    /*******Record the last value*********/
    Loc_u8LastWorkKeySts = u8WorkKeySts;
}
/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void System_vidMngInit(void)
{
    System_vidWorkInit();
    System_vidACInit();
    System_vidAutoInit();
    System_vidBlwInit();
    System_vidIntakeInit();
    System_vidModeInit();
    System_vidTsetInit();
}

/*void AppDiag_vidInit(void)
{

	StdLibSS_vidDataSetU8(AppDiag_uniSendToPcDisplayData.u8DataAll,0,sizeof(AppDiag_tstrSendToPcDisplayData));

	StdLibSS_vidDataSetU8(AppDiag_uniRecvFormPcData.u8DataAll,0,sizeof(AppDiag_tstrRecvFormPcData));
}*/
/******************************************/
/*  SYSTEM regulation                        */
/*  period = 100ms                       */
/******************************************/
void System_vidMngRegulation(void)
{
    static uint8 u8Default_Counter; 
    
    if( SYSTEM_DEFAULT_TIMER > u8Default_Counter )
    {
    /********************默认设置*********************/  
      System_vidMngDefault();
      u8Default_Counter++;
    }
    else
    {
      u8Default_Counter = SYSTEM_DEFAULT_TIMER;
      System_vidWorkRegulation();
      //if( SYSTEM_STATE_ON == SYSTEM_strApp_Data.u8WorkSts )
      //{
        //System_vidWorkRegulation();
        System_vidAutoRegulation();
        System_vidACRegulation();
        System_vidBlwRegulation();
        System_vidIntakeRegulation();
        System_vidModeRegulation();
        System_vidTsetRegulation();
      //}
    }
}
/*-------------------------------- end of file -------------------------------*/

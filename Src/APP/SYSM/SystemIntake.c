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
#include "SystemIntake.h"
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

void System_vidIntakeInit(void)
{
    SYSTEM_strApp_Data.u8IntakeSts = INTAKE_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = FALSE;
    IfRteApp_Set_IntakeSts(SYSTEM_strApp_Data.u8IntakeSts);   
}

void System_vidIntakeDefault(void)
{
    SYSTEM_strApp_Data.u8IntakeSts = INTAKE_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = FALSE;
    IfRteApp_Set_IntakeSts(SYSTEM_strApp_Data.u8IntakeSts);   
}
/******************************************/
/*  AC regulation                        */
/*  period = 100ms                       */
/******************************************/
void System_vidIntakeRegulation(void)
{
    static uint8 Loc_u8LastIntakeKeySts = INTAKE_KEY_NOPRESS ;
    uint8  u8IntakeKeySts = INTAKE_KEY_NOPRESS;
    
    /*******get REC key state from CAN**********/
    u8IntakeKeySts = IfRteApp_Get_IntakeStsFromCAN();
#if 0   
    /*******Judge REC key is pressed*********/
    if( (INTAKE_KEY_PRESSD == u8IntakeKeySts) && (INTAKE_KEY_NOPRESS == Loc_u8LastIntakeKeySts))
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = TRUE;
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = FALSE;
    }
    
    /*******AcSts handle when REC key is pressed*********/
    if( TRUE == SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress)
    {
      if( INSIDE_POSITION == SYSTEM_strApp_Data.u8IntakeSts )
      {
        SYSTEM_strApp_Data.u8IntakeSts = OUTSIDE_POSITION;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = FALSE;
      }
      else if( OUTSIDE_POSITION == SYSTEM_strApp_Data.u8IntakeSts )
      {
        SYSTEM_strApp_Data.u8IntakeSts = INSIDE_POSITION;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = FALSE;
      }
      else
      {
        SYSTEM_strApp_Data.u8IntakeSts = INTAKE_STATE_INIT;
        SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = FALSE;
      }
    }
    else
    {
      SYSTEM_uniReceive_Press_ECP.strChangeJudge.bIntakePress = FALSE;
    }
#else
    /*if((IfRteApp_Get_IntakeStsFromCAN()==1u)||((IfRteApp_Get_IntakeStsFromCAN()==2u)))
    {
       SYSTEM_strApp_Data.u8IntakeSts = IfRteApp_Get_IntakeStsFromCAN();    
    }*/
    if(IfRteApp_Get_IntakeStsFromCAN()==1)
    {
      SYSTEM_strApp_Data.u8IntakeSts = INSIDE_POSITION;
    }
    else if(IfRteApp_Get_IntakeStsFromCAN()==2)
    {
      SYSTEM_strApp_Data.u8IntakeSts = OUTSIDE_POSITION;
    }
    else
    {
      
    }
#endif
    IfRteApp_Set_IntakeSts( SYSTEM_strApp_Data.u8IntakeSts );
    /*******Record the last value*********/
    Loc_u8LastIntakeKeySts = u8IntakeKeySts;
}
/*-------------------------------- end of file -------------------------------*/

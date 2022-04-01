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
#include "SystemMode.h"
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

void System_vidModeInit(void)
{
    SYSTEM_strApp_Data.u8ModeSts = MODE_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_ModeSts(SYSTEM_strApp_Data.u8ModeSts);   
}

void System_vidModeDefault(void)
{
    SYSTEM_strApp_Data.u8ModeSts = MODE_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_ModeSts(SYSTEM_strApp_Data.u8ModeSts);   
}
/******************************************/
/*  AUTO regulation                       */
/*  period = 100ms                        */
/******************************************/
void System_vidModeRegulation(void)
{
    static MODE_tenuKey_Judge Loc_enuLastModeKeySts = MODE_NOPRESS ;
    MODE_tenuKey_Judge  enuModeKeySts = MODE_NOPRESS;
#if 0    
    /*******get auto key state from CAN**********/
    if (IfRteApp_Get_ModeVStsFromCAN())
    {
        enuModeKeySts = MODE_FACE_PRESS;
    }
    else if (IfRteApp_Get_ModeFStsFromCAN())
    {
        enuModeKeySts = MODE_FOOT_PRESS;
    }
    else if (IfRteApp_Get_ModeDStsFromCAN())
    {
        enuModeKeySts = MODE_DEFROST_PRESS;
    }
    else
    {
        enuModeKeySts = MODE_NOPRESS;
    }
    /********************************************/
    if((enuModeKeySts == MODE_FACE_PRESS) && (Loc_enuLastModeKeySts == MODE_NOPRESS))
    {
      SYSTEM_strApp_Data.u8ModeSts = MODE_FACE;
    }
    else if((enuModeKeySts == MODE_FOOT_PRESS) && (Loc_enuLastModeKeySts == MODE_NOPRESS))
    {
      SYSTEM_strApp_Data.u8ModeSts = MODE_FOOT;
    }
    else if((enuModeKeySts == MODE_DEFROST_PRESS) && (Loc_enuLastModeKeySts == MODE_NOPRESS))
    {
      SYSTEM_strApp_Data.u8ModeSts = MODE_DEFROST;
    }
    else
    {
      /*do nothing*/
    }

    /************************limited*******************/
    if( SYSTEM_strApp_Data.u8ModeSts > MODE_MAX )
    {
      SYSTEM_strApp_Data.u8ModeSts = MODE_MAX;
    }
    else if ( SYSTEM_strApp_Data.u8ModeSts < MODE_MIN )
    {
      SYSTEM_strApp_Data.u8ModeSts = MODE_MIN;
    }
    else
    {
      /*do nothing*/
    }
#else 
    if(IfRteApp_Get_ModeVStsFromCAN() == 7)
    {
      /*do nothing*/
    }
    else
    {
      SYSTEM_strApp_Data.u8ModeSts = IfRteApp_Get_ModeVStsFromCAN();
    }
    //SYSTEM_strApp_Data.u8ModeSts = IfRteApp_Get_ModeVStsFromCAN();
#endif
    IfRteApp_Set_ModeSts(SYSTEM_strApp_Data.u8ModeSts);
    /***********Record the last value************/
    Loc_enuLastModeKeySts = enuModeKeySts;
}
/*-------------------------------- end of file -------------------------------*/

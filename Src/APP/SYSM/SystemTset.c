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
#include "SystemTset.h"
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
static void vidTsetLRegulation(void)
{
    static TSET_tenuKey_Judge Loc_enuLastTsetLKeySts = TSET_NOPRESS ;
    TSET_tenuKey_Judge  enuTsetLKeySts = TSET_NOPRESS;
    
    /*******get auto key state from CAN**********/
    enuTsetLKeySts = IfRteApp_Get_TsetLStsFromCAN();
#if 0   
    /********************************************/
    if((enuTsetLKeySts == TSET_INCREASE) && (Loc_enuLastTsetLKeySts == TSET_NOPRESS))
    {
        if (SYSTEM_strApp_Data.u8TsetLSts < TSET_HI)
        {
            SYSTEM_strApp_Data.u8TsetLSts ++;
        }
        else
        {
            SYSTEM_strApp_Data.u8TsetLSts = TSET_HI;
        }
    }
    else if((enuTsetLKeySts == TSET_REDUCE) && (Loc_enuLastTsetLKeySts == TSET_NOPRESS))
    {
        if (SYSTEM_strApp_Data.u8TsetLSts > TSET_LO)
        {
            SYSTEM_strApp_Data.u8TsetLSts --;
        }
        else
        {
            SYSTEM_strApp_Data.u8TsetLSts = TSET_LO;
        }
    }
    else
    {
      /*do nothing*/
    }
#else
    SYSTEM_strApp_Data.u8TsetLSts = IfRteApp_Get_TsetLStsFromCAN();
#endif
    IfRteApp_Set_TsetLSts(SYSTEM_strApp_Data.u8TsetLSts);
    /***********Record the last value************/
    Loc_enuLastTsetLKeySts = enuTsetLKeySts;
}

static void vidTsetRRegulation(void)
{
    static TSET_tenuKey_Judge Loc_enuLastTsetRKeySts = TSET_NOPRESS ;
    TSET_tenuKey_Judge  enuTsetRKeySts = TSET_NOPRESS;
    static SYNC_tenuKey_Judge Loc_enuLastSyncKeySts = TSET_NOPRESS ;
    SYNC_tenuKey_Judge  enuSyncKeySts = TSET_NOPRESS;
    
    /*******get auto key state from CAN**********/
    enuTsetRKeySts = IfRteApp_Get_TsetRStsFromCAN();
    enuSyncKeySts = IfRteApp_Get_SyncStsFromCAN();
    /********************************************/
#if 0
    if((enuSyncKeySts == SYNC_PRESSD) && (Loc_enuLastSyncKeySts == SYNC_NOPRESS))
    {
        SYSTEM_strApp_Data.u8SyncSts = SYNC_STATE_SINGLE;
    }
    else
    {
        /*do nothing*/
    }
    
    if((enuTsetRKeySts == TSET_INCREASE) && (Loc_enuLastTsetRKeySts == TSET_NOPRESS))
    {
        SYSTEM_strApp_Data.u8SyncSts = SYNC_STATE_2ZONE;
        if (SYSTEM_strApp_Data.u8TsetRSts < TSET_HI)
        {
            SYSTEM_strApp_Data.u8TsetRSts ++;
        }
        else
        {
            SYSTEM_strApp_Data.u8TsetRSts = TSET_HI;
        }
    }
    else if((enuTsetRKeySts == TSET_REDUCE) && (Loc_enuLastTsetRKeySts == TSET_NOPRESS))
    {
        SYSTEM_strApp_Data.u8SyncSts = SYNC_STATE_2ZONE;
        if (SYSTEM_strApp_Data.u8TsetRSts > TSET_LO)
        {
            SYSTEM_strApp_Data.u8TsetRSts --;
        }
        else
        {
            SYSTEM_strApp_Data.u8TsetRSts = TSET_LO;
        }
    }
    else
    {
      /*do nothing*/
    }    

    if(SYSTEM_strApp_Data.u8SyncSts == SYNC_STATE_SINGLE)
    {
      SYSTEM_strApp_Data.u8TsetRSts = SYSTEM_strApp_Data.u8TsetLSts;
      
    }
#else
    SYSTEM_strApp_Data.u8TsetRSts = IfRteApp_Get_TsetRStsFromCAN();
    SYSTEM_strApp_Data.u8SyncSts = 1u;
#endif    
    IfRteApp_Set_TsetRSts(SYSTEM_strApp_Data.u8TsetRSts);
    IfRteApp_Set_SyncSts(SYSTEM_strApp_Data.u8SyncSts);
    /***********Record the last value************/
    Loc_enuLastTsetRKeySts = enuTsetRKeySts;
    Loc_enuLastSyncKeySts = enuSyncKeySts;
}

void System_vidTsetInit(void)
{
    SYSTEM_strApp_Data.u8TsetRSts = TSET_STATE_INIT;
    SYSTEM_strApp_Data.u8TsetLSts = TSET_STATE_INIT;
    SYSTEM_strApp_Data.u8SyncSts = SYNC_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_TsetRSts(SYSTEM_strApp_Data.u8TsetRSts); 
    IfRteApp_Set_TsetLSts(SYSTEM_strApp_Data.u8TsetLSts);  
}

void System_vidTsetDefault(void)
{
    SYSTEM_strApp_Data.u8TsetRSts = TSET_STATE_INIT;
    SYSTEM_strApp_Data.u8TsetLSts = TSET_STATE_INIT;
    SYSTEM_strApp_Data.u8SyncSts = SYNC_STATE_INIT;
    //SYSTEM_uniReceive_Press_ECP.strChangeJudge.bAutoPress = FALSE;
    IfRteApp_Set_TsetRSts(SYSTEM_strApp_Data.u8TsetRSts); 
    IfRteApp_Set_TsetLSts(SYSTEM_strApp_Data.u8TsetLSts);  
}
/******************************************/
/*  AUTO regulation                       */
/*  period = 100ms                        */
/******************************************/
void System_vidTsetRegulation(void)
{
    vidTsetLRegulation();
    vidTsetRRegulation();
}
/*-------------------------------- end of file -------------------------------*/

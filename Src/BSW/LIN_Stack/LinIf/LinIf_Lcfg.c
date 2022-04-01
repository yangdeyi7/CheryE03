/******************************************************************************/
/* PROJECT  :  XXXX                                                           */
/******************************************************************************/
/*!Layer           : LINIF                                                    */
/*                                                                            */
/*!Component       : LINIF                                                    */
/*!Description     : Contains the interface of LIN                            */
/*                                                                            */
/*!Module          : LinIf                                                    */
/*!Description     : LinIf                                                    */
/*                                                                            */
/*!File            : LinIf_Lcfg.c                                             */
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
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/A$*/
/* $Revision::   1.2     $$Author::   yunxin.liu      $$Date::   Feb 14 2017 $*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/AppESS.c-arc  $
 * 
                                                                              */
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */

/*******************************************************************************
*   Includes 
*******************************************************************************/
#include "LinIf.h"
#include "LinIf_cfg.h"
/* add uplayyer header file if needed */
#include "Mcu.h"
#include "lin_cfg.h"
/*******************************************************************************
*   Lin Com Bufs   
*******************************************************************************/

/********************************CHILLER_EXV************************************/
static LINIF_tuniChillerExvCmd   LINIF_uniChillerExvCmd =
{0x00,0x00,0x00,0x00};
static LINIF_tuniChillerExvResp   LINIF_uniChillerExvResp =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************EVAP_EXV*****************************************/
static LINIF_tuniEvapExvCmd   LINIF_uniEvapExvCmd =
{0x00,0x00,0x00,0x00};
static LINIF_tuniEvapExvResp   LINIF_uniEvapExvResp =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************HVWH*****************************************/
static LINIF_tuniHvwhSet1Cmd   LINIF_uniHvwhSet1Cmd =
{0x00,0x00};
static LINIF_tuniHvwhSet2Cmd   LINIF_uniHvwhSet2Cmd =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static LINIF_tuniHvwhStatusResp   LINIF_uniHvwhStatusResp =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************BLW*****************************************/
static LINIF_tuniBlwCmd   LINIF_uniBlwCmd =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static LINIF_tuniBlwStatus1   LINIF_uniBlwStatus1 =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static LINIF_tuniBlwStatus2   LINIF_uniBlwStatus2 =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************TWV1*****************************************/
static LINIF_tuniTwvHvacCmd   LINIF_uniTwvHvacCmd =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static LINIF_tuniTwvHvacStatus   LINIF_uniTwvHvacStatus =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************TWV2*****************************************/
static LINIF_tuniTwvBatCmd   LINIF_uniTwvBatCmd =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static LINIF_tuniTwvBatStatus   LINIF_uniTwvBatStatus =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************TWV3*****************************************/
static LINIF_tuniTwvMotorCmd   LINIF_uniTwvMotorCmd =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static LINIF_tuniTwvMotorStatus   LINIF_uniTwvMotorStatus =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************EAC*****************************************/
static LINIF_tuniEacCmd   LINIF_uniEacCmd =
{0x00,0x00,0x00};
static LINIF_tuniEacStatus   LINIF_uniEacStatus =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/********************************PUMP*****************************************/
static LINIF_tuniPumpCmd   LINIF_uniPumpCmd =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static LINIF_tuniPumpStatus   LINIF_uniPumpStatus =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*******************************DIAG********************************************/
static  LINIF_tstrDiagRequest          LINIF_strDiagRequest =
{0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
static  LINIF_tstrDiagResponse         LINIF_strDiagResponse =
{0x21, 0x03, 0x62, 0xaa, 0x55, 0x55, 0x55, 0x55};

/*******************************************************************************
*   Config Parameters   
*******************************************************************************/

/* total schedule and frame number */

/* the first schedule table is always null table */
#define LINIF_SCH_NUM                               (4)      
#define LINIF_FRAME_NUM                             (22)

#if(LINIF_SCH_NUM == 0)
#error " LINIF_SCH_NUM can not be 0 "
#endif

#if(LINIF_FRAME_NUM == 0)
#error " LINIF_FRAME_NUM can not be 0 "
#endif

/* varaibles used in LinIf.c */
#define LINIF_START_SEC_VAR_UNSPECIFIED
/*#include "MemMap_HR.h" */

uint8 LinIf_au8EntryIndex[LINIF_SCH_NUM];
 
const uint8 LinIf_u8SchNum = LINIF_SCH_NUM;
const uint8 LinIf_u8FrameNum = LINIF_FRAME_NUM;

/*******************************************************************************
*   Frame Config    
*******************************************************************************/

const LIN_tstrPduType LinIf_astrPdu[LINIF_FRAME_NUM] =
{
/********************************CHILLER_EXV************************************/
    /* frame 0 */
    {
        0x06u,  /*0x06*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        4u,
        LINIF_uniChillerExvCmd._c,           
    },   
    /* frame 1 */
    {
        0x14u,  /* 0x14 */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniChillerExvResp._c,           
    }, 

/********************************EVAP_EXV*****************************************/
    /* frame 2 */
    {
        0x08u,  /*0x08*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        4u,
        LINIF_uniEvapExvCmd._c,           
    },   
    /* frame 3 */
    {
        0xD6u,  /* 0x16 */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniEvapExvResp._c,           
    },
	/********************************HVWH*****************************************/
    /* frame 4 */
    {
        0xC4u,  /*0x04*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        2u,
        LINIF_uniHvwhSet1Cmd._c,           
    },
	/* frame 5 */
    {
        0xFBu,  /*0x3B*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        8u,
        LINIF_uniHvwhSet2Cmd._c,           
    }, 
    /* frame 6 */
    {
        0x25u,  /* 0x25 */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniHvwhStatusResp._c,           
    },
	/********************************BLW*****************************************/
    /* frame 7 */
    {
        0xCAu,  /*0x0A*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        8u,
        LINIF_uniBlwCmd._c,           
    },
    /* frame 8 */
    {
        0x8Bu,  /* 0x0B */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniBlwStatus1._c,           
    }, 
    /* frame 9 */
    {
        0x4Cu,  /* 0x0C */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniBlwStatus2._c,           
    },
	/********************************TWV HVAC****************************************/
    /* frame 10 */
    {
        0xE2u,  /*0x22*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        8u,
        LINIF_uniTwvHvacCmd._c,           
    },   
    /* frame 11 */
    {
        0x64u,  /* 0x24 */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniTwvHvacStatus._c,           
    },
	/********************************TWV BAT*****************************************/
    /* frame 12 */
    {
        0xE7u,  /*0x27*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        8u,
        LINIF_uniTwvBatCmd._c,           
    },   
    /* frame 13 */
    {
        0xE9u,  /* 0x29 */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniTwvBatStatus._c,           
    },
	/********************************TWV MOTOR*****************************************/
    /* frame 14 */
    {
        0x6Au,  /*0x2A*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        8u,
        LINIF_uniTwvMotorCmd._c,           
    },   
    /* frame 15 */
    {
        0xECu,  /* 0x2C */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniTwvMotorStatus._c,           
    },
	/********************************EAC*****************************************/
    /* frame 16 */
    {
        0x1Au,  /*0x1A*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        3u,
        LINIF_uniEacCmd._c,           
    },   
    /* frame 17 */
    {
        0x5Bu,  /* 0x1B */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniEacStatus._c,           
    },
	/********************************Pump*****************************************/
    /* frame 18 */
    {
        0x11u,  /*0x11*/               
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        8u,
        LINIF_uniPumpCmd._c,           
    },   
    /* frame 19 */
    {
        0xd3u,  /* 0x13 */
        LINIF_ENHANCED,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
       LINIF_uniPumpStatus._c,           
    },
   /**************************************************************************/	
    /* frame xxx */
    {
        0x3Cu,                 
        LINIF_CLASSIC,             
#ifndef LIN_SLAVE
        LIN_MASTER_RESPONSE,   
#else
        LIN_SLAVE_RESPONSE,   
#endif
        8u,
        LINIF_strDiagRequest._c,           
    },   
    /* frame xxx */
    {
        0x7Du,  /* 0x3D */
        LINIF_CLASSIC,             
#ifndef LIN_SLAVE
        LIN_SLAVE_RESPONSE,   
#else
        LIN_MASTER_RESPONSE,   
#endif
        8u,
        LINIF_strDiagResponse._c,           
    }   
} ;

const uint8 LinIf_u8MaxFrameTime[LINIF_FRAME_NUM] =
{
	/****/
	1u,            
    1u,
	/****/
	1u,            
    1u,
	/****/
	1u,            
    1u,
	1u,
	/****/
	1u,            
    1u,
	1u,
	/****/
	1u,            
    1u,
	/****/
	1u,            
    1u,
	/****/
	1u,            
    1u,
	/****/
	1u,            
    1u,
	/****/
	1u,            
    1u,
    /****/
    2u,            
    2u
};

/*******************************************************************************
*   Schedule Table Config    
*******************************************************************************/
const LinIf_tstrEntryType LinIf_astrEntry0[LINIF_FRAME_NUM-2] =
{
    {
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        0u,                    /* frame id */
    },
    {
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        1u,                    /* frame id */
    },
    {
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        2u,                    /* frame id */
    },
    {
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        3u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        4u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        5u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        6u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        7u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        8u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        9u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        10u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        11u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        12u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        13u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        14u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        15u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        16u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        17u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        18u,                    /* frame id */
    },
	{
        1u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        19u,                    /* frame id */
    },
};

const LinIf_tstrEntryType LinIf_astrEntry1[1] =
{
    {
        2u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        (LINIF_FRAME_NUM - 2u),    /* frame id */
    }
};

const LinIf_tstrEntryType LinIf_astrEntry2[1] =
{
    {
        3u,                    /* delay to next slot */
        0u,                    /* CollisionResolvingRef */
        (LINIF_FRAME_NUM - 1u),     /* frame id */
    }
};

const LinIf_tenuResumePositionType LinIf_enuResumePosition[LINIF_SCH_NUM] =
{
    START_FROM_BEGINNING,    	/* Null TABLE */
    CONTINUE_AT_IT_POINT, 
    CONTINUE_AT_IT_POINT,
    CONTINUE_AT_IT_POINT
};

const LinIf_tenuRunModeType LinIf_enuRunMode[LINIF_SCH_NUM] =
{
    RUN_CONTINUOUS,          	/* Null TABLE */
    RUN_CONTINUOUS,
    RUN_ONCE,
    RUN_CONTINUOUS
};

const LinIf_tstrEntryType* LinIf_apstrEntry[LINIF_SCH_NUM] =
{
    LINIF_NULL,                 /* Null TABLE */
    LinIf_astrEntry0,
    LinIf_astrEntry1,
    LinIf_astrEntry2
};

const uint8 Linif_u8TableEntryNum[LINIF_SCH_NUM] =
{                          
    0u,                          /* Null TABLE */
    (LINIF_FRAME_NUM - 2u),   
    1u,
    1u
};

#if(LIN_TXSIGNUM > 0)
/*******************************************************************************
*   table for send Signal function
********************************************************************************/
/********************************CHILLER_EXV************************************/
static void Lin_vidSendSigChillerExvPosiCmd(const void* SigValue);
static void Lin_vidSendSigChillerExvSeletCmd(const void* SigValue);
static void Lin_vidSendSigChillerExvInitCmd(const void* SigValue);

static void Lin_vidSendSigChillerExvPosiCmd(const void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//    LINIF_uniChillerExvCmd.strChillerExvCmd.u8ChillerExvPosiCmd_L = ((uint8)(*(uint16 *)SigValue & 0xFFu));
//    LINIF_uniChillerExvCmd.strChillerExvCmd.u8ChillerExvPosiCmd_H = ((uint8)((*(uint16 *)SigValue >> 8u) & 0xFFu));
//    Mcu_vidEnableInterrupts();
    l_u16_wr_LI0_EXV1_Pos_Cmd((*(uint16 *)SigValue));
}
static void Lin_vidSendSigChillerExvSeletCmd(const void* SigValue)
{
    //LINIF_uniChillerExvCmd.strChillerExvCmd.u8ChillerExvSeleCmd = (*(uint8 *)SigValue);
    l_u8_wr_LI0_EXV1_Select_Cmd((*(uint8 *)SigValue));
}
static void Lin_vidSendSigChillerExvInitCmd(const void* SigValue)
{
    //LINIF_uniChillerExvCmd.strChillerExvCmd.u8ChillerExvInitCmd = (*(uint8 *)SigValue);
    l_bool_wr_LI0_EXV1_Initial_Cmd((*(uint8 *)SigValue));
}
/********************************Evap_EXV*****************************************/
static void Lin_vidSendSigEvapExvPosiCmd(const void* SigValue);
static void Lin_vidSendSigEvapExvSeletCmd(const void* SigValue);
static void Lin_vidSendSigEvapExvInitCmd(const void* SigValue);

static void Lin_vidSendSigEvapExvPosiCmd(const void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//    LINIF_uniEvapExvCmd.strEvapExvCmd.u8EvapExvPosiCmd_L = ((uint8)(*(uint16 *)SigValue & 0xFFu));
//    LINIF_uniEvapExvCmd.strEvapExvCmd.u8EvapExvPosiCmd_H = ((uint8)((*(uint16 *)SigValue >> 8u) & 0xFFu));
//    Mcu_vidEnableInterrupts();
    l_u16_wr_LI0_EXV2_Pos_Cmd((*(uint16 *)SigValue));
}
static void Lin_vidSendSigEvapExvSeletCmd(const void* SigValue)
{
    //LINIF_uniEvapExvCmd.strEvapExvCmd.u8EvapExvSeleCmd = (*(uint8 *)SigValue);
    l_u8_wr_LI0_EXV2_Select_Cmd((*(uint8 *)SigValue));
}
static void Lin_vidSendSigEvapExvInitCmd(const void* SigValue)
{
    //LINIF_uniEvapExvCmd.strEvapExvCmd.u8EvapExvInitCmd = (*(uint8 *)SigValue);
    l_bool_wr_LI0_EXV2_Initial_Cmd((*(uint8 *)SigValue));
}

/********************************Hvwh*****************************************/
static void Lin_vidSendSigHvwh_cmd_ctpe_eau_bt(const void* SigValue);
static void Lin_vidSendSigHvwh_coupure_conso_cpt(const void* SigValue);
static void Lin_vidSendSigHvwh_cmd_pwr_limit_hvwh(const void* SigValue);
static void Lin_vidSendSigHvwh_cde_pv_lin(const void* SigValue);

static void Lin_vidSendSigHvwh_cmd_ctpe_eau_bt(const void* SigValue)
{
     //LINIF_uniHvwhSet1Cmd.strHvwhSet1Cmd.u8Hvwh_cmd_ctpe_eau_bt = (*(uint8 *)SigValue);
    l_u8_wr_LI0_CMD_CTPE_EAU_BT((*(uint8 *)SigValue));
}
static void Lin_vidSendSigHvwh_coupure_conso_cpt(const void* SigValue)
{
     //LINIF_uniHvwhSet1Cmd.strHvwhSet1Cmd.u8Hvwh_coupure_conso_cpt = (*(uint8 *)SigValue);
  l_bool_wr_LI0_COUPURE_CONSO_CPT((*(uint8 *)SigValue));
}
static void Lin_vidSendSigHvwh_cmd_pwr_limit_hvwh(const void* SigValue)
{
     //LINIF_uniHvwhSet1Cmd.strHvwhSet1Cmd.u8Hvwh_cmd_pwr_limit_hvwh = (*(uint8 *)SigValue);
  l_u8_wr_LI0_CMD_PWR_LIMIT_HVWH((*(uint8 *)SigValue));
}
static void Lin_vidSendSigHvwh_cde_pv_lin(const void* SigValue)
{
       // LINIF_uniHvwhSet2Cmd.strHvwhSet2Cmd.u8Hvwh_cde_pv_lin = (*(uint8 *)SigValue);
  l_u8_wr_LI0_CDE_PV_LIN((*(uint8 *)SigValue));
}

/********************************Blw*****************************************/
static void Lin_vidSendSigBlw_Rx_Frequency(const void* SigValue);
static void Lin_vidSendSigBlw_Code_Vehicule(const void* SigValue);
static void Lin_vidSendSigBlw_Blower_Ramp(const void* SigValue);
static void Lin_vidSendSigBlw_Blower_Speed(const void* SigValue);
static void Lin_vidSendSigBlw_Safety_Speed(const void* SigValue);

static void Lin_vidSendSigBlw_Rx_Frequency(const void* SigValue)
{
    //Mcu_vidDisableInterrupts();
   // LINIF_uniBlwCmd.strBlwCmd.u8Blw_Rx_Frequency_L = ((uint8)(*(uint16 *)SigValue & 0xFFu));
    //LINIF_uniBlwCmd.strBlwCmd.u8Blw_Rx_Frequency_H = ((uint8)((*(uint16 *)SigValue >> 8u) & 0xFFu));
    //Mcu_vidEnableInterrupts();
    l_u16_wr_LI0_RX_FREQUENCY((*(uint16 *)SigValue));
}
static void Lin_vidSendSigBlw_Code_Vehicule(const void* SigValue)
{
  //LINIF_uniBlwCmd.strBlwCmd.u8Blw_Code_Vehicule = (*(uint8 *)SigValue);
  l_u8_wr_LI0_CODE_VEHICULE((*(uint8 *)SigValue));
}
static void Lin_vidSendSigBlw_Blower_Ramp(const void* SigValue)
{
  //LINIF_uniBlwCmd.strBlwCmd.u8Blw_Blower_Ramp = (*(uint8 *)SigValue);
  l_u8_wr_LI0_BLOWER_RAMP((*(uint8 *)SigValue));
}
static void Lin_vidSendSigBlw_Blower_Speed(const void* SigValue)
{
  //LINIF_uniBlwCmd.strBlwCmd.u8Blw_Blower_Speed = (*(uint8 *)SigValue);
  l_u8_wr_LI0_BLOWER_SPEED((*(uint8 *)SigValue));
}
static void Lin_vidSendSigBlw_Safety_Speed(const void* SigValue)
{
  //LINIF_uniBlwCmd.strBlwCmd.u8Blw_Safety_Speed = (*(uint8 *)SigValue);
  l_u8_wr_LI0_SAFETY_SPEED((*(uint8 *)SigValue));
}

/********************************HVAC TWV*****************************************/
static void Lin_vidSendSigTwvHvac_Hvac_Twv_PosSet(const void* SigValue);
static void Lin_vidSendSigTwvHvac_Hvac_Twv_MoveEnable(const void* SigValue);
static void Lin_vidSendSigTwvHvac_Hvac_Twv_ReqMotorEmgyStop(const void* SigValue);
static void Lin_vidSendSigTwvHvac_Hvac_Twv_ReqMotorOptRecovery(const void* SigValue);

static void Lin_vidSendSigTwvHvac_Hvac_Twv_PosSet(const void* SigValue)
{
   //LINIF_uniTwvHvacCmd.strTwvHvacCmd.u8TwvHvac_Hvac_Twv_PosSet = (*(uint8 *)SigValue);
  l_u8_wr_LI0_HVAC_TWV_PosSet((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvHvac_Hvac_Twv_MoveEnable(const void* SigValue)
{
   //LINIF_uniTwvHvacCmd.strTwvHvacCmd.u8TwvHvac_Hvac_Twv_MoveEnable = (*(uint8 *)SigValue);
  l_bool_wr_LI0_HVAC_TWV_MoveEnable((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvHvac_Hvac_Twv_ReqMotorEmgyStop(const void* SigValue)
{
   //LINIF_uniTwvHvacCmd.strTwvHvacCmd.u8TwvHvac_Hvac_Twv_ReqMotorEmgyStop = (*(uint8 *)SigValue);
  l_bool_wr_LI0_HVAC_TWV_ReqMotorEmgyStop((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvHvac_Hvac_Twv_ReqMotorOptRecovery(const void* SigValue)
{
   //LINIF_uniTwvHvacCmd.strTwvHvacCmd.u8TwvHvac_Hvac_Twv_ReqMotorOptRecovery = (*(uint8 *)SigValue);
  l_bool_wr_LI0_HVAC_TWV_ReqMotorOptRecovery((*(uint8 *)SigValue));
}

/********************************BAT TWV*****************************************/
static void Lin_vidSendSigTwvBat_Bat_Twv_PosSet(const void* SigValue);
static void Lin_vidSendSigTwvBat_Bat_Twv_MoveEnable(const void* SigValue);
static void Lin_vidSendSigTwvBat_Bat_Twv_ReqMotorEmgyStop(const void* SigValue);
static void Lin_vidSendSigTwvBat_Bat_Twv_ReqMotorOptRecovery(const void* SigValue);
static void Lin_vidSendSigTwvBat_Bat_Twv_PosSet(const void* SigValue)
{
   //LINIF_uniTwvBatCmd.strTwvBatCmd.u8TwvBat_Bat_Twv_PosSet = (*(uint8 *)SigValue);
  l_u8_wr_LI0_BAT_TWV_PosSet((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvBat_Bat_Twv_MoveEnable(const void* SigValue)
{
   //LINIF_uniTwvBatCmd.strTwvBatCmd.u8TwvBat_Bat_Twv_MoveEnable = (*(uint8 *)SigValue);
  l_bool_wr_LI0_BAT_TWV_MoveEnable((*(uint8 *)SigValue));
  
}
static void Lin_vidSendSigTwvBat_Bat_Twv_ReqMotorEmgyStop(const void* SigValue)
{
   //LINIF_uniTwvBatCmd.strTwvBatCmd.u8TwvBat_Bat_Twv_ReqMotorEmgyStop = (*(uint8 *)SigValue);
  l_bool_wr_LI0_BAT_TWV_ReqMotorEmgyStop((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvBat_Bat_Twv_ReqMotorOptRecovery(const void* SigValue)
{
  //LINIF_uniTwvBatCmd.strTwvBatCmd.u8TwvBat_Bat_Twv_ReqMotorOptRecovery = (*(uint8 *)SigValue);
  l_bool_wr_LI0_BAT_TWV_ReqMotorOptRecovery((*(uint8 *)SigValue));
}

/********************************MOTOR TWV*****************************************/
static void Lin_vidSendSigTwvMotor_Motor_Twv_PosSet(const void* SigValue);
static void Lin_vidSendSigTwvMotor_Motor_Twv_MoveEnable(const void* SigValue);
static void Lin_vidSendSigTwvMotor_Motor_Twv_ReqMotorEmgyStop(const void* SigValue);
static void Lin_vidSendSigTwvMotor_Motor_Twv_ReqMotorOptRecovery(const void* SigValue);
static void Lin_vidSendSigTwvMotor_Motor_Twv_PosSet(const void* SigValue)
{
     //LINIF_uniTwvMotorCmd.strTwvMotorCmd.u8TwvMotor_Motor_Twv_PosSet = (*(uint8 *)SigValue);
     l_u8_wr_LI0_MOT_TWV_PosSet((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvMotor_Motor_Twv_MoveEnable(const void* SigValue)
{
     //LINIF_uniTwvMotorCmd.strTwvMotorCmd.u8TwvMotor_Motor_Twv_MoveEnable = (*(uint8 *)SigValue);
    l_bool_wr_LI0_MOT_TWV_MoveEnable((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvMotor_Motor_Twv_ReqMotorEmgyStop(const void* SigValue)
{
     //LINIF_uniTwvMotorCmd.strTwvMotorCmd.u8TwvMotor_Motor_Twv_ReqMotorEmgyStop = (*(uint8 *)SigValue);
  l_bool_wr_LI0_MOT_TWV_ReqMotorEmgyStop((*(uint8 *)SigValue));
}
static void Lin_vidSendSigTwvMotor_Motor_Twv_ReqMotorOptRecovery(const void* SigValue)
{
     //LINIF_uniTwvMotorCmd.strTwvMotorCmd.u8TwvMotor_Motor_Twv_ReqMotorOptRecovery = (*(uint8 *)SigValue);
  l_bool_wr_LI0_MOT_TWV_ReqMotorOptRecovery((*(uint8 *)SigValue));
}
/********************************EAC*****************************************/
static void Lin_vidSendSigEac_CompSpd_Target(const void* SigValue);
static void Lin_vidSendSigEac_Comp_On_Rq(const void* SigValue);
static void Lin_vidSendSigEac_Comp_Fault_Clear_Rq(const void* SigValue);
static void Lin_vidSendSigEac_Comp_HvInterLock_Rq(const void* SigValue);
static void Lin_vidSendSigEac_Comp_HvDischarge_Rq(const void* SigValue);

static void Lin_vidSendSigEac_CompSpd_Target(const void* SigValue)
{
    //LINIF_uniEacCmd.strEacCmd.u8Eac_CompSpd_Target = (*(uint8 *)SigValue);
  l_u8_wr_LI0_CompSpd_Target((*(uint8 *)SigValue));
}
static void Lin_vidSendSigEac_Comp_On_Rq(const void* SigValue)
{
 //LINIF_uniEacCmd.strEacCmd.u8Eac_Comp_On_Rq = (*(uint8 *)SigValue);
  l_u8_wr_LI0_Comp_On_Rq((*(uint8 *)SigValue));
}
static void Lin_vidSendSigEac_Comp_Fault_Clear_Rq(const void* SigValue)
{
 //LINIF_uniEacCmd.strEacCmd.u8Eac_Comp_Fault_Clear_Rq = (*(uint8 *)SigValue);
  l_u8_wr_LI0_Comp_Fault_Clear_Rq((*(uint8 *)SigValue));
}
static void Lin_vidSendSigEac_Comp_HvInterLock_Rq(const void* SigValue)
{
 //strEacCmd.u8Eac_Comp_HvInterLock_Rq = (*(uint8 *)SigValue);
  l_u8_wr_LI0_Comp_HvInterlock_Rq((*(uint8 *)SigValue));
}
static void Lin_vidSendSigEac_Comp_HvDischarge_Rq(const void* SigValue)
{
 //LINIF_uniEacCmd.strEacCmd.u8Eac_Comp_HvDischarge_Rq = (*(uint8 *)SigValue);
  l_u8_wr_LI0_Comp_HvDischarge_Rq((*(uint8 *)SigValue));
}


/********************************Pump-hvac*****************************************/
static void Lin_vidSendSigPump_ACT_CTRL_byNAD(const void* SigValue);
static void Lin_vidSendSigPump_ACT_CTRL_byProgram(const void* SigValue);
static void Lin_vidSendSigPump_ACT_CTRL_byStallDetector(const void* SigValue);
static void Lin_vidSendSigPump_ACT_CTRL_byClearEventFlags(const void* SigValue);
static void Lin_vidSendSigPump_ACT_CTRL_byTargetSpeed(const void* SigValue);
static void Lin_vidSendSigPump_ACT_CTRL_byStopMode(const void* SigValue);

static void Lin_vidSendSigPump_ACT_CTRL_byNAD(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_ACT_CTRL_byNAD = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_HVAC_CTRL_byNAD((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_ACT_CTRL_byProgram(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_ACT_CTRL_byProgram = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_HVAC_CTRL_byProgram((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_ACT_CTRL_byStallDetector(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_ACT_CTRL_byStallDetector = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_HVAC_CTRL_byStallDetector((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_ACT_CTRL_byClearEventFlags(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_ACT_CTRL_byClearEventFlags = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_HVAC_CTRL_byClearEventFlags((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_ACT_CTRL_byTargetSpeed(const void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//    LINIF_uniPumpCmd.strPumpCmd.u8Pump_ACT_CTRL_byTargetSpeed_L = ((uint8)(*(uint16 *)SigValue & 0xFFu));
//    LINIF_uniPumpCmd.strPumpCmd.u8Pump_ACT_CTRL_byTargetSpeed_H = ((uint8)((*(uint16 *)SigValue >> 8u) & 0xFFu));
//    Mcu_vidEnableInterrupts();
  l_u16_wr_LI0_PUMP_HVAC_CTRL_byTargetSpeed((*(uint16 *)SigValue));
}
static void Lin_vidSendSigPump_ACT_CTRL_byStopMode(const void* SigValue)
{
    //LINIF_uniPumpCmd.strPumpCmd.u8Pump_ACT_CTRL_byStopMode = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_HVAC_CTRL_byStopMode((*(uint8 *)SigValue));
}
/********************************Pump-bat*****************************************/
static void Lin_vidSendSigPump_BAT_CTRL_byNAD(const void* SigValue);
static void Lin_vidSendSigPump_BAT_CTRL_byProgram(const void* SigValue);
static void Lin_vidSendSigPump_BAT_CTRL_byStallDetector(const void* SigValue);
static void Lin_vidSendSigPump_BAT_CTRL_byClearEventFlags(const void* SigValue);
static void Lin_vidSendSigPump_BAT_CTRL_byTargetSpeed(const void* SigValue);
static void Lin_vidSendSigPump_BAT_CTRL_byStopMode(const void* SigValue);

static void Lin_vidSendSigPump_BAT_CTRL_byNAD(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_BAT_CTRL_byNAD = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_BAT_CTRL_byNAD((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_BAT_CTRL_byProgram(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_BAT_CTRL_byProgram = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_BAT_CTRL_byProgram((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_BAT_CTRL_byStallDetector(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_BAT_CTRL_byStallDetector = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_BAT_CTRL_byStallDetector((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_BAT_CTRL_byClearEventFlags(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_BAT_CTRL_byClearEventFlags = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_BAT_CTRL_byClearEventFlags((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_BAT_CTRL_byTargetSpeed(const void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//    LINIF_uniPumpCmd.strPumpCmd.u8Pump_BAT_CTRL_byTargetSpeed_L = ((uint8)(*(uint16 *)SigValue & 0xFFu));
//    LINIF_uniPumpCmd.strPumpCmd.u8Pump_BAT_CTRL_byTargetSpeed_H = ((uint8)((*(uint16 *)SigValue >> 8u) & 0xFFu));
//    Mcu_vidEnableInterrupts();
  l_u16_wr_LI0_PUMP_BAT_CTRL_byTargetSpeed((*(uint16 *)SigValue));
}
static void Lin_vidSendSigPump_BAT_CTRL_byStopMode(const void* SigValue)
{
    //LINIF_uniPumpCmd.strPumpCmd.u8Pump_BAT_CTRL_byStopMode = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_BAT_CTRL_byStopMode((*(uint8 *)SigValue));
}
/********************************Pump-moter*****************************************/
static void Lin_vidSendSigPump_MOTOR_CTRL_byNAD(const void* SigValue);
static void Lin_vidSendSigPump_MOTOR_CTRL_byProgram(const void* SigValue);
static void Lin_vidSendSigPump_MOTOR_CTRL_byStallDetector(const void* SigValue);
static void Lin_vidSendSigPump_MOTOR_CTRL_byClearEventFlags(const void* SigValue);
static void Lin_vidSendSigPump_MOTOR_CTRL_byTargetSpeed(const void* SigValue);
static void Lin_vidSendSigPump_MOTOR_CTRL_byStopMode(const void* SigValue);

static void Lin_vidSendSigPump_MOTOR_CTRL_byNAD(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_MOTOR_CTRL_byNAD = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_MOTOR_CTRL_byNAD((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_MOTOR_CTRL_byProgram(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_MOTOR_CTRL_byProgram = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_MOTOR_CTRL_byProgram((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_MOTOR_CTRL_byStallDetector(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_MOTOR_CTRL_byStallDetector = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_MOTOR_CTRL_byStallDetector((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_MOTOR_CTRL_byClearEventFlags(const void* SigValue)
{
     //LINIF_uniPumpCmd.strPumpCmd.u8Pump_MOTOR_CTRL_byClearEventFlags = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_MOTOR_CTRL_byClearEventFlags((*(uint8 *)SigValue));
}
static void Lin_vidSendSigPump_MOTOR_CTRL_byTargetSpeed(const void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//    LINIF_uniPumpCmd.strPumpCmd.u8Pump_MOTOR_CTRL_byTargetSpeed_L = ((uint8)(*(uint16 *)SigValue & 0xFFu));
//    LINIF_uniPumpCmd.strPumpCmd.u8Pump_MOTOR_CTRL_byTargetSpeed_H = ((uint8)((*(uint16 *)SigValue >> 8u) & 0xFFu));
//    Mcu_vidEnableInterrupts();
  l_u16_wr_LI0_PUMP_MOTOR_CTRL_byTargetSpeed((*(uint16 *)SigValue));
}
static void Lin_vidSendSigPump_MOTOR_CTRL_byStopMode(const void* SigValue)
{
    //LINIF_uniPumpCmd.strPumpCmd.u8Pump_MOTOR_CTRL_byStopMode = (*(uint8 *)SigValue);
  l_u8_wr_LI0_PUMP_MOTOR_CTRL_byStopMode((*(uint8 *)SigValue));
}
const Lin_vidSendSignalFun Lin_vidSendSignalFunPrt[LIN_TXSIGNUM]=
{
  /*******************************/
  &Lin_vidSendSigChillerExvPosiCmd,
  &Lin_vidSendSigChillerExvSeletCmd,
  &Lin_vidSendSigChillerExvInitCmd,
  /*******************************/
  &Lin_vidSendSigEvapExvPosiCmd,
  &Lin_vidSendSigEvapExvSeletCmd,
  &Lin_vidSendSigEvapExvInitCmd,
  /*******************************/
  &Lin_vidSendSigHvwh_cmd_ctpe_eau_bt,
  &Lin_vidSendSigHvwh_coupure_conso_cpt,
  &Lin_vidSendSigHvwh_cmd_pwr_limit_hvwh,
  &Lin_vidSendSigHvwh_cde_pv_lin,
  /*******************************/
  &Lin_vidSendSigBlw_Rx_Frequency,
  &Lin_vidSendSigBlw_Code_Vehicule,
  &Lin_vidSendSigBlw_Blower_Ramp,
  &Lin_vidSendSigBlw_Blower_Speed,
  &Lin_vidSendSigBlw_Safety_Speed,
  /*******************************/
  &Lin_vidSendSigTwvHvac_Hvac_Twv_PosSet,
  &Lin_vidSendSigTwvHvac_Hvac_Twv_MoveEnable,
  &Lin_vidSendSigTwvHvac_Hvac_Twv_ReqMotorEmgyStop,
  &Lin_vidSendSigTwvHvac_Hvac_Twv_ReqMotorOptRecovery,
  /*******************************/
  &Lin_vidSendSigTwvBat_Bat_Twv_PosSet,
  &Lin_vidSendSigTwvBat_Bat_Twv_MoveEnable,
  &Lin_vidSendSigTwvBat_Bat_Twv_ReqMotorEmgyStop,
  &Lin_vidSendSigTwvBat_Bat_Twv_ReqMotorOptRecovery,
  /*******************************/
  &Lin_vidSendSigTwvMotor_Motor_Twv_PosSet,
  &Lin_vidSendSigTwvMotor_Motor_Twv_MoveEnable,
  &Lin_vidSendSigTwvMotor_Motor_Twv_ReqMotorEmgyStop,
  &Lin_vidSendSigTwvMotor_Motor_Twv_ReqMotorOptRecovery,
   /*******************************/
  &Lin_vidSendSigEac_CompSpd_Target,
  &Lin_vidSendSigEac_Comp_On_Rq,
  &Lin_vidSendSigEac_Comp_Fault_Clear_Rq,
  &Lin_vidSendSigEac_Comp_HvInterLock_Rq,
  &Lin_vidSendSigEac_Comp_HvDischarge_Rq,
  /************pump_hvac*******************/
  &Lin_vidSendSigPump_ACT_CTRL_byNAD,
  &Lin_vidSendSigPump_ACT_CTRL_byProgram,
  &Lin_vidSendSigPump_ACT_CTRL_byStallDetector,
  &Lin_vidSendSigPump_ACT_CTRL_byClearEventFlags,
  &Lin_vidSendSigPump_ACT_CTRL_byTargetSpeed,
  &Lin_vidSendSigPump_ACT_CTRL_byStopMode,
  /************pump_bat*******************/
  &Lin_vidSendSigPump_BAT_CTRL_byNAD,
  &Lin_vidSendSigPump_BAT_CTRL_byProgram,
  &Lin_vidSendSigPump_BAT_CTRL_byStallDetector,
  &Lin_vidSendSigPump_BAT_CTRL_byClearEventFlags,
  &Lin_vidSendSigPump_BAT_CTRL_byTargetSpeed,
  &Lin_vidSendSigPump_BAT_CTRL_byStopMode,
  /************pump_motor*******************/
  &Lin_vidSendSigPump_MOTOR_CTRL_byNAD,
  &Lin_vidSendSigPump_MOTOR_CTRL_byProgram,
  &Lin_vidSendSigPump_MOTOR_CTRL_byStallDetector,
  &Lin_vidSendSigPump_MOTOR_CTRL_byClearEventFlags,
  &Lin_vidSendSigPump_MOTOR_CTRL_byTargetSpeed,
  &Lin_vidSendSigPump_MOTOR_CTRL_byStopMode,
};

#endif

#if(LIN_RXSIGNUM > 0)
/*******************************************************************************
*   table for Receive Signal function
*******************************************************************************/
/********************************CHILLER_EXV************************************/
static void Lin_vidReceiveSigChillerExvPosiSt(void* SigValue);
static void Lin_vidReceiveSigChillerExvMoveSt(void* SigValue);
static void Lin_vidReceiveSigChillerExvStallDet(void* SigValue);
static void Lin_vidReceiveSigChillerExvDefSt(void* SigValue);
static void Lin_vidReceiveSigChillerExvCommErr(void* SigValue);
static void Lin_vidReceiveSigChillerExvIntFault(void* SigValue);
static void Lin_vidReceiveSigChillerExvProtFault(void* SigValue);
static void Lin_vidReceiveSigChillerExvVoltFault(void* SigValue);
static void Lin_vidReceiveSigChillerExvFaultStall(void* SigValue);
static void Lin_vidReceiveSigChillerExvPreLp(void* SigValue);
static void Lin_vidReceiveSigChillerExvTempAcLp(void* SigValue);

static void Lin_vidReceiveSigChillerExvPosiSt(void* SigValue)
{
    //Mcu_vidDisableInterrupts();
	//(*(uint16 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvPosiSt_L + LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvPosiSt_H*256U;
    //Mcu_vidEnableInterrupts();
    (*(uint16 *)SigValue)=l_u16_rd_LI0_EXV1_Position_Feedback();
}
static void Lin_vidReceiveSigChillerExvMoveSt(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvMoveSt;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV1_Movement_Status();
}
static void Lin_vidReceiveSigChillerExvStallDet(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvStallDet;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV1_Stall_Detect();
}
static void Lin_vidReceiveSigChillerExvDefSt(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvDefSt;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV1_Detect_Status();
}
static void Lin_vidReceiveSigChillerExvCommErr(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvComErr;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV1_Communication_Error();
}
static void Lin_vidReceiveSigChillerExvIntFault(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvIntFault;
    (*(uint8 *)SigValue)=l_u8_rd_LI0_EXV1_Internal_Fault();
}
static void Lin_vidReceiveSigChillerExvProtFault(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvProtFault;
   (*(uint8 *)SigValue)=l_u8_rd_LI0_EXV1_Protection_fault();
}
static void Lin_vidReceiveSigChillerExvVoltFault(void* SigValue)
{
   // (*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvVoltFault;
  (*(uint8 *)SigValue)=l_u8_rd_LI0_EXV1_Voltage_Fault();
}
static void Lin_vidReceiveSigChillerExvFaultStall(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvFaultStall;
    (*(uint8 *)SigValue)=l_u8_rd_LI0_EXV1_Position_fault();
  
}
static void Lin_vidReceiveSigChillerExvPreLp(void* SigValue)
{
   // Mcu_vidDisableInterrupts();
	//(*(uint16 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvPreLp_L
   //     | (uint16)((LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvPreLp_H) << 8);
   // Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue)=l_u16_rd_LI0_EXV1_Pressure_Feedback();
}
static void Lin_vidReceiveSigChillerExvTempAcLp(void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) = LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvTempAcLp_L
//        | (uint16)((LINIF_uniChillerExvResp.strChillerExvResp.u8ChillerExvTempAcLp_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue)=l_u16_rd_LI0_EXV1_Temperature_Feedback();
}
/********************************Evap_EXV*****************************************/
static void Lin_vidReceiveSigEvapExvPosiSt(void* SigValue);
static void Lin_vidReceiveSigEvapExvMoveSt(void* SigValue);
static void Lin_vidReceiveSigEvapExvStallDet(void* SigValue);
static void Lin_vidReceiveSigEvapExvDefSt(void* SigValue);
static void Lin_vidReceiveSigEvapExvCommErr(void* SigValue);
static void Lin_vidReceiveSigEvapExvIntFault(void* SigValue);
static void Lin_vidReceiveSigEvapExvProtFault(void* SigValue);
static void Lin_vidReceiveSigEvapExvVoltFault(void* SigValue);
static void Lin_vidReceiveSigEvapExvFaultStall(void* SigValue);
static void Lin_vidReceiveSigEvapExvPreLp(void* SigValue);
static void Lin_vidReceiveSigEvapExvTempAcLp(void* SigValue);

static void Lin_vidReceiveSigEvapExvPosiSt(void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) = (LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvPosiSt_L) + (LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvPosiSt_H)*256u;
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue)=l_u16_rd_LI0_EXV2_Position_Feedback();
}
static void Lin_vidReceiveSigEvapExvMoveSt(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvMoveSt;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV2_Movement_Status();
}
static void Lin_vidReceiveSigEvapExvStallDet(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvStallDet;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV2_Stall_Detect();
}
static void Lin_vidReceiveSigEvapExvDefSt(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvDefSt;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV2_Detect_Status();
}
static void Lin_vidReceiveSigEvapExvCommErr(void* SigValue)
{
    //(*(uint8 *)SigValue) = LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvComErr;
  (*(uint8 *)SigValue)=l_bool_rd_LI0_EXV2_Communication_Error();
}
static void Lin_vidReceiveSigEvapExvIntFault(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_EXV2_Internal_Fault();
      //LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvIntFault;
}
static void Lin_vidReceiveSigEvapExvProtFault(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_EXV2_Protection_fault();
      //LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvProtFault;
}
static void Lin_vidReceiveSigEvapExvVoltFault(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_EXV2_Voltage_Fault();
      //LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvVoltFault;
}
static void Lin_vidReceiveSigEvapExvFaultStall(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_EXV2_Position_fault();
      //LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvFaultStall;
}
static void Lin_vidReceiveSigEvapExvPreLp(void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) = LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvPreLp_L
//        | (uint16)((LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvPreLp_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_EXV2_Pressure_Feedback();
}
static void Lin_vidReceiveSigEvapExvTempAcLp(void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) = LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvTempAcLp_L
//        | (uint16)((LINIF_uniEvapExvResp.strEvapExvResp.u8EvapExvTempAcLp_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_EXV2_Temperature_Feedback();
}
/********************************Hvwh*****************************************/
static void Lin_vidReceiveSigHvwh_temp_eau_cpt_bt(void* SigValue);
static void Lin_vidReceiveSigHvwh_i_conso_ctp_eau_bt(void* SigValue);
static void Lin_vidReceiveSigHvwh_default_ctp_eau(void* SigValue);
static void Lin_vidReceiveSigHvwh_default_secu_ctp_bt(void* SigValue);
static void Lin_vidReceiveSigHvwh_resp_error_ctpe(void* SigValue);
static void Lin_vidReceiveSigHvwh_interlock_status(void* SigValue);
static void Lin_vidReceiveSigHvwh_limit_power_hvwh (void* SigValue);
static void Lin_vidReceiveSigHvwh_default_alim_bt (void* SigValue);
static void Lin_vidReceiveSigHvwh_defaut_fonct_intempestif (void* SigValue);
static void Lin_vidReceiveSigHvwh_defaut_non_fonct_perm(void* SigValue);
static void Lin_vidReceiveSigHvwh_defaut_protection(void* SigValue);
static void Lin_vidReceiveSigHvwh_defaut_sonde_temp(void* SigValue);
static void Lin_vidReceiveSigHvwh_defaut_tension_bt(void* SigValue);
static void Lin_vidReceiveSigHvwh_tension_lv_ctpe_elec(void* SigValue);


static void Lin_vidReceiveSigHvwh_temp_eau_cpt_bt(void* SigValue)
{
   (*(uint8 *)SigValue) = l_u8_rd_LI0_TEMP_EAU_CPT_BT();
     //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_temp_eau_cpt_bt;
}
static void Lin_vidReceiveSigHvwh_i_conso_ctp_eau_bt(void* SigValue)
{
//    Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) = LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_i_conso_ctp_eau_bt_L
//        | (uint16)((LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_i_conso_ctp_eau_bt_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint8 *)SigValue) =l_u16_rd_LI0_I_CONSO_CTP_EAU_BT();
}
static void Lin_vidReceiveSigHvwh_default_ctp_eau(void* SigValue)
{
   (*(uint8 *)SigValue) = l_bool_rd_LI0_DEFAUT_CTP_EAU();
     //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_default_ctp_eau;
}
static void Lin_vidReceiveSigHvwh_default_secu_ctp_bt(void* SigValue)
{
   (*(uint8 *)SigValue) = l_bool_rd_LI0_DEFAUT_SECU_CTP_EAU_BT();
     //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_default_secu_ctp_bt;
}
static void Lin_vidReceiveSigHvwh_resp_error_ctpe(void* SigValue)
{
   (*(uint8 *)SigValue) = l_bool_rd_LI0_RESP_ERROR_CTPE();
     //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_resp_error_ctpe;
}
static void Lin_vidReceiveSigHvwh_interlock_status(void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_INTERLOCK_STATUS();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_interlock_status;
} 
static void Lin_vidReceiveSigHvwh_limit_power_hvwh (void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_LIMIT_POWER_HVWH();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_limit_power_hvwh;
} 
static void Lin_vidReceiveSigHvwh_default_alim_bt (void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_DEFAUT_ALIM_BT();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_default_alim_bt;
}
static void Lin_vidReceiveSigHvwh_defaut_fonct_intempestif (void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_DEFAUT_FONCT_INTEMPESTIF();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_defaut_fonct_intempestif;
}
static void Lin_vidReceiveSigHvwh_defaut_non_fonct_perm(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_DEFAUT_NON_FONCT_PERM();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_defaut_non_fonct_perm;
}
static void Lin_vidReceiveSigHvwh_defaut_protection(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_DEFAUT_PROTECTION();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_defaut_protection;
}
static void Lin_vidReceiveSigHvwh_defaut_sonde_temp(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_DEFAUT_SONDE_TEMP();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_defaut_sonde_temp;
}
static void Lin_vidReceiveSigHvwh_defaut_tension_bt(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_DEFAUT_TENSION_BT();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_defaut_tension_bt;
}
static void Lin_vidReceiveSigHvwh_tension_lv_ctpe_elec(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_TENSION_LV_CTPE_ELEC();
      //LINIF_uniHvwhStatusResp.strHvwhStatusResp.u8Hvwh_tension_lv_ctpe_elec;
}


/********************************Blw*****************************************/
static void Lin_vidReceiveSigBlw_Blower_Status_Motor(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Diag_Flag1(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_ResponseError(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Diag_Flag2(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Ibatt(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Rotation_Speed(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Temperature(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Ubatt(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Supplier(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Umotor(void* SigValue);
static void Lin_vidReceiveSigBlw_Blower_Torque(void* SigValue);


static void Lin_vidReceiveSigBlw_Blower_Status_Motor(void* SigValue)
{
  (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_STATUS_MOTOR();
    //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Status_Motor;
}
static void Lin_vidReceiveSigBlw_Blower_Diag_Flag1(void* SigValue)
{
  (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_DIAG_FLAG1();
    //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Diag_Flag1;
}
static void Lin_vidReceiveSigBlw_Blower_ResponseError(void* SigValue)
{
  (*(uint8 *)SigValue) = l_bool_rd_LI0_BLOWER_ResponseError();
  //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_ResponseError;
}
static void Lin_vidReceiveSigBlw_Blower_Diag_Flag2(void* SigValue)
{
  (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_DIAG_FLAG2();
    //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Diag_Flag2;
}
static void Lin_vidReceiveSigBlw_Blower_Ibatt(void* SigValue)
{
  (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_IBATT();
    //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Ibatt;
}
static void Lin_vidReceiveSigBlw_Blower_Rotation_Speed(void* SigValue)
{
 (*(uint8 *)SigValue) =l_u8_rd_LI0_BLOWER_ROTATION_SPEED();
   //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Rotation_Speed;
}
static void Lin_vidReceiveSigBlw_Blower_Temperature(void* SigValue)
{
 (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_TEMPERATURE();
   //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Temperature;
}
static void Lin_vidReceiveSigBlw_Blower_Ubatt(void* SigValue)
{
 (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_UBATT();
   //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Ubatt;
}
static void Lin_vidReceiveSigBlw_Blower_Supplier(void* SigValue)
{
 (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_SUPPLIER();
   //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Supplier;
}
static void Lin_vidReceiveSigBlw_Blower_Umotor(void* SigValue)
{
 (*(uint8 *)SigValue) = l_u8_rd_LI0_BLOWER_UMOTOR();
   //LINIF_uniBlwStatus1.strBlwStatus1.u8Blw_Blower_Umotor;
}
static void Lin_vidReceiveSigBlw_Blower_Torque(void* SigValue)
{
//   Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) = LINIF_uniBlwStatus2.strBlwStatus2.u8Blw_Blower_Torque_L 
//        | (uint16)((LINIF_uniBlwStatus2.strBlwStatus2.u8Blw_Blower_Torque_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue)=l_u16_rd_LI0_BLOWER_TORQUE();
}

/********************************HVAC TWV*****************************************/
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_Resp_Error(void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_OvervoltageFlt(void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_OverCurrent(void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_OverTempFlt(void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_UnderVoltageFlt (void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_InitSta (void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_Ccwflg (void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_MotorSta (void* SigValue);
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_RealSta(void* SigValue);

static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_Resp_Error(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_TWV_RESP_ERROR();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_Resp_Error;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_OvervoltageFlt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_HVAC_TWV_OvervoltageFlt();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_OvervoltageFlt;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_OverCurrent(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_TWV_OverCurrent();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_OverCurrent;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_OverTempFlt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_TWV_OverTempFlt();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_OverTempFlt;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_UnderVoltageFlt (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_TWV_UnderVoltageFlt();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_UnderVoltageFlt;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_InitSta (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_TWV_InitSta();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_InitSta ;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_Ccwflg (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_TWV_CCWFlg();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_Ccwflg;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_MotorSta (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_HVAC_TWV_MotorSta();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_MotorSta ;
}
static void Lin_vidReceiveSigTwvHvac_Hvac_Twv_RealSta(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_HVAC_TWV_RealSta();
//LINIF_uniTwvHvacStatus.strTwvHvacStatus.u8TwvHvac_Hvac_Twv_RealSta ;
}
/********************************HVAC TWV*****************************************/
static void Lin_vidReceiveSigTwvBat_Bat_Twv_Resp_Error(void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_OvervoltageFlt(void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_OverCurrent(void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_OverTempFlt(void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_UnderVoltageFlt (void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_InitSta (void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_Ccwflg (void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_MotorSta (void* SigValue);
static void Lin_vidReceiveSigTwvBat_Bat_Twv_RealSta(void* SigValue);

static void Lin_vidReceiveSigTwvBat_Bat_Twv_Resp_Error(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_TWV_RESP_ERROR();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_Resp_Error;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_OvervoltageFlt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_HVAC_TWV_OvervoltageFlt();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_OvervoltageFlt;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_OverCurrent(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_TWV_OverCurrent();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_OverCurrent;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_OverTempFlt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_TWV_OverTempFlt();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_OverTempFlt;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_UnderVoltageFlt (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_TWV_UnderVoltageFlt();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_UnderVoltageFlt;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_InitSta (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_TWV_InitSta();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_InitSta ;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_Ccwflg (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_TWV_CCWFlg();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_Ccwflg ;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_MotorSta (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_BAT_TWV_MotorSta();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_MotorSta ;
}
static void Lin_vidReceiveSigTwvBat_Bat_Twv_RealSta(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_BAT_TWV_RealSta();
//LINIF_uniTwvBatStatus.strTwvBatStatus.u8TwvBat_Bat_Twv_RealSta ;
}
/********************************HVAC TWV*****************************************/
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_Resp_Error(void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_OvervoltageFlt(void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_OverCurrent(void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_OverTempFlt(void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_UnderVoltageFlt (void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_InitSta (void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_Ccwflg (void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_MotorSta (void* SigValue);
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_RealSta(void* SigValue);

static void Lin_vidReceiveSigTwvMotor_Motor_Twv_Resp_Error(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_TWV_RESP_ERROR();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_Resp_Error;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_OvervoltageFlt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_HVAC_TWV_OvervoltageFlt();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_OvervoltageFlt;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_OverCurrent(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_TWV_OverCurrent();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_OverCurrent;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_OverTempFlt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_TWV_OverTempFlt();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_OverTempFlt;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_UnderVoltageFlt (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_TWV_UnderVoltageFlt();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_UnderVoltageFlt;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_InitSta (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_TWV_InitSta();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_InitSta;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_Ccwflg (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_TWV_CCWFlg();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_Ccwflg;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_MotorSta (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_MOT_TWV_MotorSta();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_MotorSta;
}
static void Lin_vidReceiveSigTwvMotor_Motor_Twv_RealSta(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_MOT_TWV_RealSta();
//LINIF_uniTwvMotorStatus.strTwvMotorStatus.u8TwvMotor_Motor_Twv_RealSta;

}


/********************************EAC*****************************************/
static void Lin_vidReceiveSigEac_CompSpd_Est(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_HV_InputCurr(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_HV_Volt(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_InvrtTemp(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_InvrtPhaseCurr(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Sp_BrdTemp_Lmt(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Sp_CurrLmt(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Sp_HVVolt_Flt(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Sp_Temp_Excess (void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Sp_Comm_Flt (void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Sp_InvrtPwrSup_Flt(void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Off_Sens_Flt (void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Off_ShrtCurr (void* SigValue);
static void Lin_vidReceiveSigEac_EAC_Off_Stall (void* SigValue);
static void Lin_vidReceiveSigEac_EAC_RsErr(void* SigValue);
static void Lin_vidReceiveSigEac_Comp_HvInterlock_Stat(void* SigValue);
static void Lin_vidReceiveSigEac_Comp_Oprtn_Stat (void* SigValue);

static void Lin_vidReceiveSigEac_CompSpd_Est(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_CompSpd_Est();
//LINIF_uniEacStatus.strEacStatus.u8Eac_CompSpd_Est;
}
static void Lin_vidReceiveSigEac_EAC_HV_InputCurr(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_EAC_HV_InputCurr();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_HV_InputCurr;
}
static void Lin_vidReceiveSigEac_EAC_HV_Volt(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_EAC_HV_Volt();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_HV_Volt;
}
static void Lin_vidReceiveSigEac_EAC_InvrtTemp(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_EAC_InvrtTemp();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_InvrtTemp;
}
static void Lin_vidReceiveSigEac_EAC_InvrtPhaseCurr(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_EAC_InvrtPhaseCurr();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_InvrtPhaseCurr;
}
static void Lin_vidReceiveSigEac_EAC_Sp_BrdTemp_Lmt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Sp_BrdTemp_Lmt();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Sp_BrdTemp_Lmt;
}
static void Lin_vidReceiveSigEac_EAC_Sp_CurrLmt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Sp_CurrLmt();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Sp_CurrLmt;
}
static void Lin_vidReceiveSigEac_EAC_Sp_HVVolt_Flt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Sp_HVVolt_Flt();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Sp_HVVolt_Flt;
}
static void Lin_vidReceiveSigEac_EAC_Sp_Temp_Excess (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Sp_Temp_Excess();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Sp_Temp_Excess;
}
static void Lin_vidReceiveSigEac_EAC_Sp_Comm_Flt (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Sp_Comm_Flt();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Sp_Comm_Flt;
}
static void Lin_vidReceiveSigEac_EAC_Sp_InvrtPwrSup_Flt(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Sp_InvrtPwrSup_Flt();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Sp_InvrtPwrSup_Flt;
}
static void Lin_vidReceiveSigEac_EAC_Off_Sens_Flt (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Off_Sens_Flt();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Off_Sens_Flt ;
}
static void Lin_vidReceiveSigEac_EAC_Off_ShrtCurr (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Off_ShrtCurr();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Off_ShrtCurr;
}
static void Lin_vidReceiveSigEac_EAC_Off_Stall (void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_Off_Stall();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_Off_Stall;
}
static void Lin_vidReceiveSigEac_EAC_RsErr(void* SigValue)
{
(*(uint8 *)SigValue) = l_bool_rd_LI0_EAC_RsErr();
//LINIF_uniEacStatus.strEacStatus.u8Eac_EAC_RsErr;
}
static void Lin_vidReceiveSigEac_Comp_HvInterlock_Stat(void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_Comp_HvInterlock_Stat();
//LINIF_uniEacStatus.strEacStatus.u8Eac_Comp_HvInterlock_Stat;
}
static void Lin_vidReceiveSigEac_Comp_Oprtn_Stat (void* SigValue)
{
(*(uint8 *)SigValue) = l_u8_rd_LI0_Comp_Oprtn_Stat();
//LINIF_uniEacStatus.strEacStatus.u8Eac_Comp_Oprtn_Stat;
}
/********************************PUMP-hvac************************************/
static void Lin_vidReceiveSigPump_ACT_STATUS_byResponseError(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byOverTemperature(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byElectricDefect(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byVoltageError(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byEmergencyOccurred(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_bySpeedError(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byStallOccurred(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byReset(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_bySpeedStatus(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byActualLA(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byActualMotorVoltage(void* SigValue);
static void Lin_vidReceiveSigPump_ACT_STATUS_byFocMode(void* SigValue);

static void Lin_vidReceiveSigPump_ACT_STATUS_byResponseError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_PUMP_HVAC_STATUS_byResponseError();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byResponseError;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byOverTemperature(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_byOverTemperature();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byOverTemperature;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byElectricDefect(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_byElectricDefect();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byElectricDefect;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byVoltageError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_byVoltageError();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byVoltageError;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byEmergencyOccurred(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_byEmergencyOccurred();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byEmergencyOccurred;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_bySpeedError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_bySpeedError();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_bySpeedError;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byStallOccurred(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_byStallOccurred();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byStallOccurred;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byReset(void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_PUMP_HVAC_STATUS_byReset();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byReset;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_bySpeedStatus(void* SigValue)
{
//       Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) =LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_bySpeedStatus_L
//        | (uint16)((LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_bySpeedStatus_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_PUMP_HVAC_STATUS_bySpeedStatus();
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byActualLA(void* SigValue)
{
//       Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) =LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byActualLA_L
//        | (uint16)((LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byActualLA_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_PUMP_HVAC_STATUS_byActualLA();
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byActualMotorVoltage(void* SigValue)
{
      (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_byActualMotorVoltage();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byActualMotorVoltage;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byFocMode(void* SigValue)
{
     (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_HVAC_STATUS_byFocMode();
     //LINIF_uniPumpStatus.strPumpStatus.u8Pump_ACT_STATUS_byFocMode;
}
/********************************PUMP-bat************************************/
static void Lin_vidReceiveSigPump_BAT_STATUS_byResponseError(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byOverTemperature(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byElectricDefect(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byVoltageError(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byEmergencyOccurred(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_bySpeedError(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byStallOccurred(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byReset(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_bySpeedStatus(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byActualLA(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byActualMotorVoltage(void* SigValue);
static void Lin_vidReceiveSigPump_BAT_STATUS_byFocMode(void* SigValue);

static void Lin_vidReceiveSigPump_BAT_STATUS_byResponseError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_PUMP_BAT_STATUS_byResponseError();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byResponseError;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byOverTemperature(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_byOverTemperature();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byOverTemperature;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byElectricDefect(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_byElectricDefect();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byElectricDefect;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byVoltageError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_byVoltageError();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byVoltageError;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byEmergencyOccurred(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_byEmergencyOccurred();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byEmergencyOccurred;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_bySpeedError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_bySpeedError();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_bySpeedError;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byStallOccurred(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_byStallOccurred();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byStallOccurred;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byReset(void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_PUMP_BAT_STATUS_byReset();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byReset;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_bySpeedStatus(void* SigValue)
{
//       Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) =LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_bySpeedStatus_L
//        | (uint16)((LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_bySpeedStatus_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_PUMP_BAT_STATUS_bySpeedStatus();
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byActualLA(void* SigValue)
{
//       Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) =LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byBATualLA_L
//        | (uint16)((LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byBATualLA_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_PUMP_BAT_STATUS_byActualLA();
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byActualMotorVoltage(void* SigValue)
{
      (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_byActualMotorVoltage();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byBATualMotorVoltage;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byFocMode(void* SigValue)
{
     (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_BAT_STATUS_byFocMode();
     //LINIF_uniPumpStatus.strPumpStatus.u8Pump_BAT_STATUS_byFocMode;
}
/********************************PUMP-motor************************************/
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byResponseError(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byOverTemperature(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byElectricDefect(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byVoltageError(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byEmergencyOccurred(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_bySpeedError(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byStallOccurred(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byReset(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_bySpeedStatus(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byActualLA(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byActualMotorVoltage(void* SigValue);
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byFocMode(void* SigValue);

static void Lin_vidReceiveSigPump_MOTOR_STATUS_byResponseError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_PUMP_MOTOR_STATUS_byResponseError();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byResponseError;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byOverTemperature(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byOverTemperature();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byOverTemperature;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byElectricDefect(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byElectricDefect();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byElectricDefect;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byVoltageError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byVoltageError();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byVoltageError;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byEmergencyOccurred(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byEmergencyOccurred();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byEmergencyOccurred;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_bySpeedError(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_bySpeedError();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_bySpeedError;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byStallOccurred(void* SigValue)
{
    (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byStallOccurred();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byStallOccurred;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byReset(void* SigValue)
{
    (*(uint8 *)SigValue) = l_bool_rd_LI0_PUMP_MOTOR_STATUS_byReset();
    //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byReset;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_bySpeedStatus(void* SigValue)
{
//       Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) =LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_bySpeedStatus_L
//        | (uint16)((LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_bySpeedStatus_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_PUMP_MOTOR_STATUS_bySpeedStatus();
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byActualLA(void* SigValue)
{
//       Mcu_vidDisableInterrupts();
//	(*(uint16 *)SigValue) =LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byActualLA_L
//        | (uint16)((LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byActualLA_H) << 8);
//    Mcu_vidEnableInterrupts();
  (*(uint16 *)SigValue) = l_u16_rd_LI0_PUMP_MOTOR_STATUS_byActualLA();
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byActualMotorVoltage(void* SigValue)
{
      (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byActualMotorVoltage();
      //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byActualMotorVoltage;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byFocMode(void* SigValue)
{
     (*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byFocMode();
     //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byFocMode;
}
static void Lin_vidReceiveSigPump_MOTOR_STATUS_byPwmMode(void* SigValue)
{
     //(*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byFocMode();
     //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byFocMode;
}
static void Lin_vidReceiveSigPump_BAT_STATUS_byPwmMode(void* SigValue)
{
     //(*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byFocMode();
     //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byFocMode;
}
static void Lin_vidReceiveSigPump_ACT_STATUS_byPwmMode(void* SigValue)
{
     //(*(uint8 *)SigValue) = l_u8_rd_LI0_PUMP_MOTOR_STATUS_byFocMode();
     //LINIF_uniPumpStatus.strPumpStatus.u8Pump_MOTOR_STATUS_byFocMode;
}
const Lin_vidReceivedSignalFun Lin_vidReceivedSignalFunPrt[LIN_RXSIGNUM]=
{
	&Lin_vidReceiveSigChillerExvPosiSt,
	&Lin_vidReceiveSigChillerExvMoveSt,
	&Lin_vidReceiveSigChillerExvStallDet,
	&Lin_vidReceiveSigChillerExvDefSt,
	&Lin_vidReceiveSigChillerExvCommErr,
	&Lin_vidReceiveSigChillerExvIntFault,
	&Lin_vidReceiveSigChillerExvProtFault,
	&Lin_vidReceiveSigChillerExvVoltFault,
	&Lin_vidReceiveSigChillerExvFaultStall,
	&Lin_vidReceiveSigChillerExvPreLp,
	&Lin_vidReceiveSigChillerExvTempAcLp,
/**********************************************/
	&Lin_vidReceiveSigEvapExvPosiSt,
	&Lin_vidReceiveSigEvapExvMoveSt,
	&Lin_vidReceiveSigEvapExvStallDet,
	&Lin_vidReceiveSigEvapExvDefSt,
	&Lin_vidReceiveSigEvapExvCommErr,
	&Lin_vidReceiveSigEvapExvIntFault,
	&Lin_vidReceiveSigEvapExvProtFault,
	&Lin_vidReceiveSigEvapExvVoltFault,
	&Lin_vidReceiveSigEvapExvFaultStall,
	&Lin_vidReceiveSigEvapExvPreLp,
	&Lin_vidReceiveSigEvapExvTempAcLp,
/**********************************************/
	&Lin_vidReceiveSigHvwh_temp_eau_cpt_bt,
	&Lin_vidReceiveSigHvwh_i_conso_ctp_eau_bt,
	&Lin_vidReceiveSigHvwh_default_ctp_eau,
	&Lin_vidReceiveSigHvwh_default_secu_ctp_bt,
	&Lin_vidReceiveSigHvwh_resp_error_ctpe,
	&Lin_vidReceiveSigHvwh_interlock_status,
	&Lin_vidReceiveSigHvwh_limit_power_hvwh ,
	&Lin_vidReceiveSigHvwh_default_alim_bt ,
	&Lin_vidReceiveSigHvwh_defaut_fonct_intempestif ,
	&Lin_vidReceiveSigHvwh_defaut_non_fonct_perm,
	&Lin_vidReceiveSigHvwh_defaut_protection,
	&Lin_vidReceiveSigHvwh_defaut_sonde_temp,
	&Lin_vidReceiveSigHvwh_defaut_tension_bt,
	&Lin_vidReceiveSigHvwh_tension_lv_ctpe_elec,
	/**********************************************/
	&Lin_vidReceiveSigBlw_Blower_Status_Motor,
	&Lin_vidReceiveSigBlw_Blower_Diag_Flag1,
	&Lin_vidReceiveSigBlw_Blower_ResponseError,
	&Lin_vidReceiveSigBlw_Blower_Diag_Flag2,
	&Lin_vidReceiveSigBlw_Blower_Ibatt,
	&Lin_vidReceiveSigBlw_Blower_Rotation_Speed,
	&Lin_vidReceiveSigBlw_Blower_Temperature,
	&Lin_vidReceiveSigBlw_Blower_Ubatt,
	&Lin_vidReceiveSigBlw_Blower_Supplier,
	&Lin_vidReceiveSigBlw_Blower_Umotor,
	&Lin_vidReceiveSigBlw_Blower_Torque,
/********************************HVAC TWV*****************************************/
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_Resp_Error,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_OvervoltageFlt,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_OverCurrent,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_OverTempFlt,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_UnderVoltageFlt,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_InitSta,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_Ccwflg,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_MotorSta,
	&Lin_vidReceiveSigTwvHvac_Hvac_Twv_RealSta,
/********************************HVAC TWV*****************************************/
	&Lin_vidReceiveSigTwvBat_Bat_Twv_Resp_Error,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_OvervoltageFlt,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_OverCurrent,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_OverTempFlt,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_UnderVoltageFlt,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_InitSta,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_Ccwflg,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_MotorSta,
	&Lin_vidReceiveSigTwvBat_Bat_Twv_RealSta,
/********************************HVAC TWV*****************************************/
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_Resp_Error,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_OvervoltageFlt,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_OverCurrent,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_OverTempFlt,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_UnderVoltageFlt,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_InitSta,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_Ccwflg,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_MotorSta,
	&Lin_vidReceiveSigTwvMotor_Motor_Twv_RealSta,
	/********************************EAC*****************************************/
	&Lin_vidReceiveSigEac_CompSpd_Est,
    &Lin_vidReceiveSigEac_EAC_HV_InputCurr,
    &Lin_vidReceiveSigEac_EAC_HV_Volt,
    &Lin_vidReceiveSigEac_EAC_InvrtTemp,
    &Lin_vidReceiveSigEac_EAC_InvrtPhaseCurr,
    &Lin_vidReceiveSigEac_EAC_Sp_BrdTemp_Lmt,
    &Lin_vidReceiveSigEac_EAC_Sp_CurrLmt,
    &Lin_vidReceiveSigEac_EAC_Sp_HVVolt_Flt,
    &Lin_vidReceiveSigEac_EAC_Sp_Temp_Excess ,
    &Lin_vidReceiveSigEac_EAC_Sp_Comm_Flt ,
    &Lin_vidReceiveSigEac_EAC_Sp_InvrtPwrSup_Flt,
    &Lin_vidReceiveSigEac_EAC_Off_Sens_Flt ,
    &Lin_vidReceiveSigEac_EAC_Off_ShrtCurr ,
    &Lin_vidReceiveSigEac_EAC_Off_Stall ,
    &Lin_vidReceiveSigEac_EAC_RsErr,
    &Lin_vidReceiveSigEac_Comp_HvInterlock_Stat,
    &Lin_vidReceiveSigEac_Comp_Oprtn_Stat ,
	/********************************pump-hvac*****************************************/
	&Lin_vidReceiveSigPump_ACT_STATUS_byResponseError,
	&Lin_vidReceiveSigPump_ACT_STATUS_byOverTemperature,
	&Lin_vidReceiveSigPump_ACT_STATUS_byElectricDefect,
	&Lin_vidReceiveSigPump_ACT_STATUS_byVoltageError,
	&Lin_vidReceiveSigPump_ACT_STATUS_byEmergencyOccurred,
	&Lin_vidReceiveSigPump_ACT_STATUS_bySpeedError,
	&Lin_vidReceiveSigPump_ACT_STATUS_byStallOccurred,
	&Lin_vidReceiveSigPump_ACT_STATUS_byReset,
	&Lin_vidReceiveSigPump_ACT_STATUS_bySpeedStatus,
	&Lin_vidReceiveSigPump_ACT_STATUS_byActualLA,
	&Lin_vidReceiveSigPump_ACT_STATUS_byActualMotorVoltage,
	&Lin_vidReceiveSigPump_ACT_STATUS_byFocMode,
    &Lin_vidReceiveSigPump_ACT_STATUS_byPwmMode,
    /********************************pump-bat*****************************************/
	&Lin_vidReceiveSigPump_BAT_STATUS_byResponseError,
	&Lin_vidReceiveSigPump_BAT_STATUS_byOverTemperature,
	&Lin_vidReceiveSigPump_BAT_STATUS_byElectricDefect,
	&Lin_vidReceiveSigPump_BAT_STATUS_byVoltageError,
	&Lin_vidReceiveSigPump_BAT_STATUS_byEmergencyOccurred,
	&Lin_vidReceiveSigPump_BAT_STATUS_bySpeedError,
	&Lin_vidReceiveSigPump_BAT_STATUS_byStallOccurred,
	&Lin_vidReceiveSigPump_BAT_STATUS_byReset,
	&Lin_vidReceiveSigPump_BAT_STATUS_bySpeedStatus,
	&Lin_vidReceiveSigPump_BAT_STATUS_byActualLA,
	&Lin_vidReceiveSigPump_BAT_STATUS_byActualMotorVoltage,
	&Lin_vidReceiveSigPump_BAT_STATUS_byFocMode,
    &Lin_vidReceiveSigPump_BAT_STATUS_byPwmMode,
    /********************************pump-motor*****************************************/
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byResponseError,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byOverTemperature,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byElectricDefect,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byVoltageError,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byEmergencyOccurred,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_bySpeedError,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byStallOccurred,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byReset,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_bySpeedStatus,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byActualLA,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byActualMotorVoltage,
	&Lin_vidReceiveSigPump_MOTOR_STATUS_byFocMode,
    &Lin_vidReceiveSigPump_MOTOR_STATUS_byPwmMode,
};
#endif


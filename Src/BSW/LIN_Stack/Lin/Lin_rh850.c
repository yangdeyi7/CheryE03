/******************************************************************************/
/* PROJECT  :  XXX                                                            */
/******************************************************************************/
/* !Layer           : Lin                                                     */
/*                                                                            */
/* !Component       : Lin                                                     */
/* !Description     : Provides interface for LIN Driver                       */
/*                                                                            */
/* !Module          : Lin                                                     */
/* !Description     : Provides interface for LIN Driver                       */
/*                                                                            */
/* !File            : Lin.c                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/*!Target          : RH850F1K-S1                                              */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/CO$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Jun 30 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_LIN/LinDrv/LinDrv.c-arc  $
 * 
 *    Rev 1.1   Jun 30 2017 18:19:06   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Lin_rh850.h"
#include "Device.h"
#include "Std_Types.h"
//#include "LinTrcv.h"
#include "LinIf.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
const tstrRLin3n* LIN_apstrRLIN3n[] = 
{
#if 0 //for RH850F1L open this define
    /* RLIN30 function register base */
    ((const tstrRLin3n*)(0xFFCF0000ul)),
    /* RLIN31 function register base */
    ((const tstrRLin3n*)(0xFFCF0040ul)),
    /* RLIN32 function register base */
    ((const tstrRLin3n*)(0xFFCF0080ul)),
    /* RLIN33 function register base */
    ((const tstrRLin3n*)(0xFFCF00C0ul)),
    /* RLIN34 function register base */
    ((const tstrRLin3n*)(0xFFCF0100ul)),
    /* RLIN35 function register base */
    ((const tstrRLin3n*)(0xFFCF0140ul))
#elif 1 //for RH850F1K-S1 open this define,S1 has 4 channels in total
    /* RLIN30 function register base */
    ((const tstrRLin3n*)(0xFFCE2000ul)), /*Channel 0 base address*/
    /* RLIN31 function register base */
    ((const tstrRLin3n*)(0xFFCE2040ul)), /*Channel 1 base address*/
    /* RLIN32 function register base */
    ((const tstrRLin3n*)(0xFFCE2080ul)), /*Channel 2 base address*/
    /* RLIN33 function register base */
    ((const tstrRLin3n*)(0xFFCE20C0ul))  /*Channel 3 base address*/
#endif
};

#if 0
const bitf08_T* LIN_apstrRLINT[] = 
{
    /* RLIN30 interrupt register base */
    ((const bitf08_T*)(0xffff9034ul)),
    /* RLIN31 interrupt register base */
    ((const bitf08_T*)(0xffffa0e2ul)),
    /* RLIN32 interrupt register base */
    ((const bitf08_T*)(0xffffa13aul)),
    /* RLIN33 interrupt register base */
    ((const bitf08_T*)(0xffffa1baul)),
    /* RLIN34 interrupt register base */
    ((const bitf08_T*)(0xffffa1c2ul)),
    /* RLIN35 interrupt register base */
    ((const bitf08_T*)(0xffffa1caul))
};
#endif


const uint8 au8LogictoPhysic[] =
{
    RLIN3NLOGIC0TOPHYSIC
    #if (1u < RLIN3NCHANNELNUM)
        ,RLIN3NLOGIC1TOPHYSIC
        #if (2u < RLIN3NCHANNELNUM)
            ,RLIN3NLOGIC2TOPHYSIC
            #if (3u < RLIN3NCHANNELNUM)
                ,RLIN3NLOGIC3TOPHYSIC
                #if (4u < RLIN3NCHANNELNUM)
                    ,RLIN3NLOGIC4TOPHYSIC
                    #if (5u < RLIN3NCHANNELNUM)
                        ,RLIN3NLOGIC5TOPHYSIC
                    #endif
                #endif
            #endif
        #endif
    #endif
};

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

static boolean LIN_bStartFlag[RLIN3NCHANNELNUM];
/* static tstrRLin3n* pstrRLIN3n = NULL_PTR; */

static LIN_tenuStatusType LIN_enuStatus[RLIN3NCHANNELNUM];

static LIN_tstrPduType* LIN_pstrCurrentpdu[RLIN3NCHANNELNUM];

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
void Lin_vidTxHandle(uint8 u8ChanNum);
void Lin_vidRxHandle(uint8 u8ChanNum);
void Lin_vidErrHandle(uint8 u8ChanNum);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

extern LIN_tenuStatusType Lin_enuGetStatus(uint8 u8ChanNum)
{
    return LIN_enuStatus[u8ChanNum];
}

extern void Lin_vidSetStatus(uint8 u8ChanNum, LIN_tenuStatusType enuLinStatus)
{
    LIN_enuStatus[u8ChanNum] = enuLinStatus;
}
/******************************************************************************
** Function:    RLIN30_init
** Description: Initialize the RLIN30 for UART 
** Parameter:   None
** Return:      None
******************************************************************************/
void Lin_vidInit(uint8 u8ChanNum)
{

}

extern Std_ReturnType Lin_udtGoToSleep(uint8 u8ChanNum)
{
    (void)u8ChanNum;
    return E_OK;
}


void lin_tx_test()
{
    uint16 u16StepPosi=10;
    LinIf_udtSendSignal(LIN_TXSIG_CHILLER_EXV_POSI_CMD, &u16StepPosi);
 
}


void lin_rx_test()
{
    uint16  u16StepPosi=0;
    LinIf_ReceiveSignal(LIN_RXSIG_CHILLER_EXV_POSI_ST,&u16StepPosi);
    SEGGER_RTT_printf(0, "LIN_RXSIG_CHILLER_EXV_POSI_ST>>>>>>>>>>>>>>>:%x,%x\r\n",l_u16_rd_LI0_EXV1_Position_Feedback(),u16StepPosi);
}
#ifdef LIN_SLAVE
void Lin_vidSlaveStart(uint8 u8ChanNum)
{
    tstrRLin3n* pstrRLIN3n;
    pstrRLIN3n = (tstrRLin3n*)LIN_apstrRLIN3n[au8LogictoPhysic[u8ChanNum]] ;
    LIN_bStartFlag[u8ChanNum] = TRUE;
    /* Header reception or wake up transmission/reception is started.*/
    pstrRLIN3n->u8LTRC |= 0x01u;
}

void Lin_vidSlaveStop(uint8 u8ChanNum)
{
    LIN_bStartFlag[u8ChanNum] = FALSE;
}
#else


void Lin_vidMasterSend(uint8 u8ChanNum, LIN_tstrPduType* pstrPdu)
{
//    uint8 u8Index;
//    tstrRLin3n* pstrRLIN3n;
//
//    LIN_pstrCurrentpdu[u8ChanNum] = pstrPdu;
//    LIN_bStartFlag[u8ChanNum] = FALSE;
//    pstrRLIN3n = (tstrRLin3n*)LIN_apstrRLIN3n[au8LogictoPhysic[u8ChanNum]] ;
//    pstrRLIN3n->u8LIDB = pstrPdu->udtPid;
//    if (LIN_MASTER_RESPONSE == pstrPdu->enuDrc)
//    {
//        pstrRLIN3n->u8LDFC = 0x30 | pstrPdu->udtDl;
//        for (u8Index = 0u; u8Index < pstrPdu->udtDl; u8Index++)
//        {
//            pstrRLIN3n->u8LDBR[u8Index] = pstrPdu->pu8SduPtr[u8Index];
//        }
//    }
//    else
//    {
//        pstrRLIN3n->u8LDFC = 0x20 | pstrPdu->udtDl;
//    }
//    pstrRLIN3n->u8LTRC |= 0x01u;
}
#endif
///*******************************************************************************
//* Function Name: RLIN3n_Transmission_interrupt/INTRLIN3nUR0
//* Description  : This function is RLIN3n Transmission interrupt service routine.
//* Arguments    : None
//* Return Value : None
//*******************************************************************************/
//void Lin_vidTxHandle(uint8 u8ChanNum)
//{
//    tstrRLin3n* pstrRLIN3n;
//    pstrRLIN3n = (tstrRLin3n*)LIN_apstrRLIN3n[au8LogictoPhysic[u8ChanNum]] ;
//    pstrRLIN3n->u8LST &= 0xFEu; 
//    LIN_enuStatus[u8ChanNum] = LIN_TX_OK;
//}

///*******************************************************************************
//* Function Name: RLIN3n_Error_interrupt/INTRLIN3nUR2
//* Description  : This function is RLIN3n Transmission interrupt service routine.
//* Arguments    : None
//* Return Value : None
//*******************************************************************************/
//void Lin_vidErrHandle(uint8 u8ChanNum)
//{
//    tstrRLin3n* pstrRLIN3n;
//    pstrRLIN3n = (tstrRLin3n*)LIN_apstrRLIN3n[au8LogictoPhysic[u8ChanNum]] ;
//    LIN_enuStatus[u8ChanNum] = LIN_ERROR;
//    Linif_vidRxErrorCb(u8ChanNum, pstrRLIN3n->u8LEST);
//    pstrRLIN3n->u8LEST &= 0x00u; 
//    /* RH850 F1L group user's manual - hardware.pdf 17.3.2.14 page 842
//       write 0 to the RPER, CSER, FER, FTER, PBER, and BER flags
//       in the RLN3nLEST register in LIN operation mode or LIN wake-up mode.
//       This clears the ERR flag to 0. */
//    /* pstrRLIN3n->u8LST &= 0xF7u; */
//    LIN_enuStatus[u8ChanNum] = LIN_OPERATIONAL;
//
//}

///*******************************************************************************
//* Function Name: RLIN3n_Reception_interrupt/INTRLIN3nUR1
//* Description  : This function is RLIN3n Reception interrupt service routine.
//* Arguments    : None
//* Return Value : None
//*******************************************************************************/
//void Lin_vidRxHandle(uint8 u8ChanNum)
//{  
//    tstrRLin3n* pstrRLIN3n;
//    uint8 u8RecHeadFlag;
//    uint8 u8RecRepFlag;
//    uint8 u8Temp;
//
//    pstrRLIN3n = (tstrRLin3n*)LIN_apstrRLIN3n[au8LogictoPhysic[u8ChanNum]] ;
//    u8RecHeadFlag = pstrRLIN3n->u8LST & 0x80u;  /* get header reception flag  */
//    u8RecRepFlag = pstrRLIN3n->u8LST & 0X02u;   /* get response rception flag */
//
//    if(0u != u8RecHeadFlag)  /* Header successful receive*/
//    {
//        pstrRLIN3n->u8LIE &= 0xF7;/* Disable header interrupt               */
//        pstrRLIN3n->u8LST &= 0X7F;/* clear successful header reception flag */
//
//		
//#ifdef LIN_SLAVE 
//        LIN_pstrCurrentpdu[u8ChanNum] = (LIN_tstrPduType*)Linif_pstrRxHeadCb(u8ChanNum, pstrRLIN3n->u8LIDB);
//        u8Temp = LIN_pstrCurrentpdu[u8ChanNum]->enuCs | LIN_pstrCurrentpdu[u8ChanNum]->enuDrc;
//        pstrRLIN3n->u8LDFC = (u8Temp | LIN_pstrCurrentpdu[u8ChanNum]->udtDl);
//        if (LIN_MASTER_RESPONSE == LIN_pstrCurrentpdu[u8ChanNum]->enuDrc)
//        {
//            for (u8Temp = 0u; u8Temp < LIN_pstrCurrentpdu[u8ChanNum]->udtDl;u8Temp++)
//            {
//                pstrRLIN3n->u8LDBR[u8Temp] = LIN_pstrCurrentpdu[u8ChanNum]->pu8SduPtr[u8Temp];
//            }
//            /* setting RTS=1,response transmission/reception is started */
//            pstrRLIN3n->u8LTRC = 0x02u;
//        }
//        else if (LIN_SLAVE_RESPONSE == LIN_pstrCurrentpdu[u8ChanNum]->enuDrc)
//        {
//            for (u8Temp = 0u; u8Temp < LIN_pstrCurrentpdu[u8ChanNum]->udtDl;u8Temp++)
//            {
//                pstrRLIN3n->u8LDBR[u8Temp] = 0u;
//            }
//            /* setting RTS=1,response transmission/reception is started */
//            pstrRLIN3n->u8LTRC = 0x02u;
//        }
//        else
//        {
//            /* setting LNRR=0, No response request*/
//            pstrRLIN3n->u8LTRC = 0x04;
//        }
//#endif
//		
//        /* enable header reception interrupt */
//        pstrRLIN3n->u8LIE |= 0x08u;
//        LIN_enuStatus[u8ChanNum] = LIN_RX_HEADER_OK;
//    }
//  
//    if(0u != u8RecRepFlag)
//    {
//        /* disable response reception interrupt     */
//        pstrRLIN3n->u8LIE &= 0xFDu;
//        /* clear response reception successful flag */
//        pstrRLIN3n->u8LST &= 0xFDu;
//
//
//        for (u8Temp = 0u; u8Temp < LIN_pstrCurrentpdu[u8ChanNum]->udtDl;u8Temp++)
//        {
//            LIN_pstrCurrentpdu[u8ChanNum]->pu8SduPtr[u8Temp] = pstrRLIN3n->u8LDBR[u8Temp];
//        }
//        
//        pstrRLIN3n->u8LIE |= 0x02u;  /*enable reception interrupt*/
//        LIN_enuStatus[u8ChanNum] = LIN_RX_OK;
//    }
//
//    if (LIN_bStartFlag[u8ChanNum])
//    {
//        pstrRLIN3n->u8LTRC = 0x01u;    /*enabled header reception*/
//    }
//}

///*******************************************************************************
//* Function Name : Lin_TX\RX\ERR_ISR
//*
//* Description   : interrupt routing services
//*
//* Inputs        : None
//*
//* Outputs       : None
//* 
//* Limitations   : None                 
//*******************************************************************************/

//#ifdef RLIN3_PHY0_TO_LOGIC
//__interrupt void INTRLIN30UR0(void)
//{
//    Lin_vidTxHandle(RLIN3_PHY0_TO_LOGIC);
//}
//
//__interrupt void INTRLIN30UR1(void)
//{
//    Lin_vidRxHandle(RLIN3_PHY0_TO_LOGIC);
//}
//
//__interrupt void INTRLIN30UR2(void)
//{
//    Lin_vidErrHandle(RLIN3_PHY0_TO_LOGIC);
//}
//#endif
//
//#ifdef RLIN3_PHY1_TO_LOGIC
//__interrupt void INTRLIN31UR0(void)
//{
//    Lin_vidTxHandle(RLIN3_PHY1_TO_LOGIC);
//}

//__interrupt void INTRLIN31UR1(void)
//{
//    Lin_vidRxHandle(RLIN3_PHY1_TO_LOGIC);
//}
//
//__interrupt void INTRLIN31UR2(void)
//{
//    Lin_vidErrHandle(RLIN3_PHY1_TO_LOGIC);
//}
//#endif

//#if 0
//#ifdef RLIN3_PHY2_TO_LOGIC
//__interrupt void INTRLIN32UR0(void)
//{
//    Lin_vidTxHandle(RLIN3_PHY2_TO_LOGIC);
//}
//
//__interrupt void INTRLIN32UR1(void)
//{
//    Lin_vidRxHandle(RLIN3_PHY2_TO_LOGIC);
//}
//
//__interrupt void INTRLIN32UR2(void)
//{
//    Lin_vidErrHandle(RLIN3_PHY2_TO_LOGIC);
//}
//#endif
//#endif


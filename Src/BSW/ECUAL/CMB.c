/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : CMB                                                     */
/*                                                                            */
/* !Component       : CMB                                                     */
/* !Description     : CMB Control                                             */
/*                                                                            */
/* !Module          : CMB                                                     */
/* !Description     : CMB Control                                             */
/*                                                                            */
/* !File            : CMB.c                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : uPD70F3375                                              */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/EC$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/CMB.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:10   chunping.yan
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
#include "Std_Types.h"
#include "CMB.h"
#include "Elmos.h"
#include "Dio.h"
#include "TLE9410xDrv.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/*! \Description FORNT_DEF active value.
 *  \Range  0
*******************************************************************************/
#define u8FORNT_DEF_ON                ((uint8)0)

/******************************************************************************/
/*! \Description FORNT_DEF inactive value.
 *  \Range  1
*******************************************************************************/
#define u8FORNT_DEF_OFF               ((uint8)1)

/******************************************************************************/
/*! \Description INCAR_FAN active value.
 *  \Range  0
*******************************************************************************/
#define u8INCAR_FAN_ON                ((uint8)0)

/******************************************************************************/
/*! \Description PUMP inactive value.
 *  \Range  1
*******************************************************************************/
#define u8INCAR_FAN_OFF               ((uint8)1)

/******************************************************************************/
/*! \Description HEAT_WIND active value.
 *  \Range  0
*******************************************************************************/
#define u8HEAT_WIND_ON                ((uint8)0)

/******************************************************************************/
/*! \Description HEAT_WIND inactive value.
 *  \Range  1
*******************************************************************************/
#define u8HEAT_WIND_OFF               ((uint8)1)


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
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/*! \Description Data that holds the FORNT_DEF Request state.
*******************************************************************************/
static uint8  CMB_u8FORNT_DEF_Request;

/******************************************************************************/
/*! \Description Data that holds the INCAR FAN Request state.
*******************************************************************************/
static uint8  CMB_u8INCAR_FAN_Request;

/******************************************************************************/
/*! \Description Data that holds the HEAT WIND Request state.
*******************************************************************************/
static uint8  CMB_u8HEAT_WIND_Request;

/******************************************************************************/
/*! \Description Data that holds the FORNT DEF state.
*******************************************************************************/
static uint8  CMB_u8FORNT_DEF_State;

/******************************************************************************/
/*! \Description Data that holds the INCAR FAN state.
*******************************************************************************/
static uint8  CMB_u8INCAR_FAN_State;

/******************************************************************************/
/*! \Description Data that holds the HEAT WIND state.
*******************************************************************************/
static uint8  CMB_u8HEAT_WIND_State;


static uint8  SOV_RLY1_State;
static uint8  SOV_RLY2_State;
static uint8  BLW_RLY3_State;
static uint8  FAN_RLY4_State;
static uint8  SOTXV_RLY5_State;

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function:   CMB_vidInit                                                    */
/*! \Description CMB Initialization service.
    \Return      void.
    \Trace_To    CDD-CMB-
*******************************************************************************/
void CMB_vidInit( void )
{
   /*! Initialize the FORNT_DEF,INCAR_FAN,HEAT_WIND state. */
   CMB_u8FORNT_DEF_State = STD_OFF;
   CMB_u8INCAR_FAN_State  = STD_OFF;
   CMB_u8HEAT_WIND_State = STD_OFF;
   /*! Initialize the FORNT_DEF,INCAR_FAN,HEAT_WIND  request. */
   CMB_u8FORNT_DEF_Request = STD_OFF;
   CMB_u8INCAR_FAN_Request  = STD_OFF;
   CMB_u8HEAT_WIND_Request = STD_OFF;
   
    SOV_RLY1_State  = STD_OFF;
    SOV_RLY2_State  = STD_OFF;
    BLW_RLY3_State  = STD_OFF;
    FAN_RLY4_State  = STD_OFF;
    SOTXV_RLY5_State= STD_OFF;
    
}/* End of CMB_vidInit() */

/******************************************************************************/
/*!Function:   CMB_vidSetSignalState                                          */
/*! \Description Set the signal state.
    \param[in]   enuId : ID of the signal to be set.
    \Range       CMB_DEMAND_FORNT_DEF, CMB_DEMAND_INCAR_FAN, CMB_DEMAND_HEAT_WIND
    \param[in]   enuState : State to be set.
    \Range       STD_OFF, STD_ON
    \Return      void.
    \Trace_To    CDD-CMB-
*******************************************************************************/
void CMB_vidSetSignalState(CMB_tenuId enuId, uint8  u8State)
{
  switch (enuId)
  {
    /*! If the ID is the FORNT_DEF Request ID. */
    case CMB_DEMAND_FORNT_DEF:
      /*! Set the FORNT_DEF Request state. */
      CMB_u8FORNT_DEF_Request = u8State;
      break ;
    
    /*! If the ID is the INCAR_FAN Request ID. */
    case CMB_DEMAND_INCAR_FAN:
      /*! Set the INCAR_FAN Request state. */
      CMB_u8INCAR_FAN_Request = u8State;
      break ;
    
    /*! If the ID is the HEAT_WIND Request ID. */
    case CMB_DEMAND_HEAT_WIND:
      /*! Set the HEAT_WIND state Request. */
      CMB_u8HEAT_WIND_Request = u8State;
      break ;
//      case SOV_RLY1:
//      /*! Set the HEAT_WIND state Request. */
//      SOV_RLY1_State = u8State;
//      break ;
//      case SOV_RLY2:
//      /*! Set the HEAT_WIND state Request. */
//      SOV_RLY2_State = u8State;
//      break ;
      case BLW_RLY3:
      /*! Set the HEAT_WIND state Request. */
      BLW_RLY3_State = u8State;
      break ;
      case FAN_RLY4:
      /*! Set the HEAT_WIND state Request. */
      FAN_RLY4_State = u8State;
      break ;
//      case SOTXV_RLY5:
//      /*! Set the HEAT_WIND state Request. */
//      SOTXV_RLY5_State = u8State;
//      break ;
    
    default :
      break ;
   }
}/* End of CMB_vidSetSignalState() */


/******************************************************************************/
/*!Function:   CMB_vidManageSignals                                           */
/*! \Description Manage the CMB signals.
    \Return      void.
    \Trace_To    CDD-CMB-
*******************************************************************************/
void CMB_vidManageSignals( void )
{
  /*! If the FORNT_DEF Request is active. */
  if (CMB_u8FORNT_DEF_Request == STD_ON)
  {
      /*! Set the FORNT_DEF signal to be active. */
      Elmos_vidWrite(Elmos_FORNT_DEF, u8FORNT_DEF_ON);
      /* Set the FORNT_DEF signal status as active*/
      CMB_u8FORNT_DEF_State = STD_ON;
  }
  /*! If the FORNT_DEF Request is inactive. */
  else
  {
      /*! Set the FORNT_DEF signal to be inactive. */
      Elmos_vidWrite(Elmos_FORNT_DEF, u8FORNT_DEF_OFF);
      /* Set the FORNT_DEF signal status as inactive*/
      CMB_u8FORNT_DEF_State = STD_OFF;
  }

    /*! If the INCAR_FAN Request is active. */
  if (CMB_u8INCAR_FAN_Request == STD_ON)
  {
      /*! Set the INCAR_FAN signal to be active. */
      Elmos_vidWrite(Elmos_INCAR_FAN, u8INCAR_FAN_ON);
      /* Set the INCAR_FAN signal status as active*/
      CMB_u8INCAR_FAN_State = STD_ON;
  }
  /*! If the INCAR_FAN Request is inactive. */
  else
  {
      /*! Set the INCAR_FAN signal to be inactive. */
      Elmos_vidWrite(Elmos_INCAR_FAN, u8INCAR_FAN_OFF);
      /* Set the INCAR_FAN signal status as inactive*/
      CMB_u8INCAR_FAN_State = STD_OFF;
  }

    /*! If the HEAT_WIND Request is active. */
  if (CMB_u8HEAT_WIND_Request == STD_ON)
  {
      /*! Set the HEAT_WIND signal to be active. */
      Elmos_vidWrite(Elmos_HEAT_WIND, u8HEAT_WIND_ON);
      /* Set the HEAT_WIND signal status as active*/
      CMB_u8HEAT_WIND_State = STD_ON;
  }
  /*! If the HEAT_WIND Request is inactive. */
  else
  {
      /*! Set the HEAT_WIND signal to be inactive. */
      Elmos_vidWrite(Elmos_HEAT_WIND, u8HEAT_WIND_OFF);
      /* Set the HEAT_WIND signal status as inactive*/
      CMB_u8HEAT_WIND_State = STD_OFF;
  }
  TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_BLW_RLY3,BLW_RLY3_State);
  TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_FAN_RLY4,FAN_RLY4_State);
  TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_FAN_RLY11,FAN_RLY4_State);
  //TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_FAN_RLY12,FAN_RLY4_State);
}/* End of CMB_vidManageSignals */



/******************************************************************************/
/*!Function:   CMB_enuForntDefStatus                                          */
/*! \Description Get FORNT_DEF Status.
    \Return      FORNT_DEF Status.
    \Trace_To    CDD-CMB- 
*******************************************************************************/
uint8 CMB_enuForntDefStatus( void )
{
   return CMB_u8FORNT_DEF_State;
}

/******************************************************************************/
/*!Function:   CMB_enuIncarFanStatus                                          */
/*! \Description Get INCAR FAN Status.
    \Return      INCAR FAN Status.
    \Trace_To    CDD-CMB- 
*******************************************************************************/
uint8 CMB_enuIncarFanStatus( void )
{
   return CMB_u8INCAR_FAN_State;
}

/******************************************************************************/
/*!Function:   CMB_enuHeatWindStatus                                          */
/*! \Description Get HEAT WIND Status.
    \Return      HEAT WIND Status.
    \Trace_To    CDD-CMB- 
*******************************************************************************/
uint8 CMB_enuHeatWindStatus( void )
{
   return CMB_u8HEAT_WIND_State;
}




/** \} */ /* end of CMB module group */
/** \} */ /* end of ECUAL CMB Component */
/*-------------------------------- end of file -------------------------------*/

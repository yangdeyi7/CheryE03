/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "SovDrv.h"
#include "Dio.h"
#include "TLE9410xDrv.h"

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
/*
  
#define u8SOV_ON                ((uint8)0)
#define u8SOV_OFF               ((uint8)1)

SOV_Eva = u8SOV1_ID    //changbi 
SOV_OutEva = u8SOV2_ID //changkai
SOV_TXVOutEva = u8SOV3_ID//changbi

typedef enum
{
  SOV_BLOCK  = 0,
  SOV_PASSED = 1,
} Sov_tenuPassOrBlockState;

*/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
static uint8  SovDrv_au8Request[u8SOV_NUM];
static uint8  SovDrv_au8State[u8SOV_NUM];
static Sov_tenuPassOrBlockState  Sov_enuPassOrBlockState[u8SOV_NUM];

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
extern void SovDrv_vidInit(void)
{
   SovDrv_au8Request[u8SOV1_ID] = 0u;
   SovDrv_au8Request[u8SOV2_ID] = 1u;
   SovDrv_au8Request[u8SOV3_ID] = 0u;
   SovDrv_au8Request[u8SOV4_ID] = 1u;
   Sov_enuPassOrBlockState[u8SOV1_ID] = SOV_BLOCK;
   Sov_enuPassOrBlockState[u8SOV2_ID] = SOV_PASSED;
   Sov_enuPassOrBlockState[u8SOV3_ID] = SOV_BLOCK;
   Sov_enuPassOrBlockState[u8SOV4_ID] = SOV_PASSED;
}


extern void SovDrv_vidSetSignalState(uint8 u8SovId, uint8 u8SovSwReq)
{
  switch(u8SovId)
  {
      case u8SOV1_ID:
	  SovDrv_au8Request[u8SovId] = u8SovSwReq;
	  break;

      case u8SOV2_ID:
	  SovDrv_au8Request[u8SovId] = u8SovSwReq;
	  break;

      case u8SOV3_ID:
	  SovDrv_au8Request[u8SovId] = u8SovSwReq;
	  break;

	  case u8SOV4_ID:
	  SovDrv_au8Request[u8SovId] = u8SovSwReq;
	  break;

      default :
	  break ;  
  }
}


extern uint8 SovDrv_u8GetCurrSovSts(uint8 u8SovId)
{
  return SovDrv_au8State[u8SovId];
}


extern Sov_tenuPassOrBlockState SovDrv_enuGetSovPassOrBlockSts(uint8 u8SovId)
{
  return Sov_enuPassOrBlockState[u8SovId];
}


extern void SovDrv_vidManage(uint8 u8SovId)
{
   if(u8SovId == u8SOV1_ID)//SOV_Eva changbi
   {
	if(u8SOV_ReqOpen == SovDrv_au8Request[u8SovId])//uppc or mbd request valve passed
	{
	    //Dio_vidWrite(17,0);
        TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOV_RLY1,0);
	    Sov_enuPassOrBlockState[u8SovId] = SOV_PASSED;
	}
	else
	{
	    //Dio_vidWrite(17,1);
        TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOV_RLY1,1);
	    Sov_enuPassOrBlockState[u8SovId] = SOV_BLOCK;
	}
   }
   else if(u8SovId == u8SOV2_ID)//SOV_OutEva changkai
   {
	if(u8SOV_ReqClosed == SovDrv_au8Request[u8SovId])//uppc or mbd request valve block
	{
	    //Dio_vidWrite(18,0);
        TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOV_RLY2,0);
	    Sov_enuPassOrBlockState[u8SovId] = SOV_BLOCK;
	}
	else
	{
	    //Dio_vidWrite(18,1);
        TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOV_RLY2,1);
	    Sov_enuPassOrBlockState[u8SovId] = SOV_PASSED;
	}
   }
   else if(u8SovId == u8SOV3_ID)//SOV_TXVOutEva changbi
   {
	if(u8SOV_ReqOpen == SovDrv_au8Request[u8SovId])//uppc or mbd request valve passed
	{
	    //Dio_vidWrite(19,0);
        TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOTXV_RLY5,0);
	    Sov_enuPassOrBlockState[u8SovId] = SOV_PASSED;
	}
	else
	{
	    //Dio_vidWrite(19,1);
        TLE9410xDrv_vidRelayCtrl(TLE9410XDRV_SOTXV_RLY5,1);
	    Sov_enuPassOrBlockState[u8SovId] = SOV_BLOCK;
	}
   }
   else
   {

   }
}
/*-------------------------------- end of file -------------------------------*/

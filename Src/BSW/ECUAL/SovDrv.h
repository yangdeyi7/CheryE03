#ifndef SOVDRV_H
#define SOVDRV_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define  u8SOV_ReqOpen  1u
#define  u8SOV_ReqClosed 0u
#define  u8SOV1_ID    0u
#define  u8SOV2_ID    1u
#define  u8SOV3_ID    2u
#define  u8SOV4_ID    3u
#define  u8SOV_NUM    4u
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef enum
{
  SOV_BLOCK  = 0,
  SOV_PASSED = 1,
} Sov_tenuPassOrBlockState;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void    SovDrv_vidInit(void);
extern void    SovDrv_vidSetSignalState(uint8 u8SovId, uint8 u8SovSwReq);
extern uint8   SovDrv_u8GetCurrSovSts(uint8 u8SovId);
extern Sov_tenuPassOrBlockState SovDrv_enuGetSovPassOrBlockSts(uint8 u8SovId);
extern void    SovDrv_vidManage(uint8 u8SovId);



#endif
/*-------------------------------- end of file -------------------------------*/

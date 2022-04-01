#ifndef ACTUATOR_H
#define ACTUATOR_H


#define  u8ACT_MIXL        0u
#define  u8ACT_MIXR        1u
#define  u8ACT_MODEL       2u
#define  u8ACT_MODER       3u
#define  u8ACT_DEFROST     4u
#define  u8ACT_RECY        5u
#define  u8ACT_NUM         6u


#define   u8MIXL_MAXHEAT          (uint8)100      //4.01V conform 2021111
#define   u8MIXL_MAXCOOL          (uint8)0        //0.9V  conform 2021111

#define   u8MIXR_MAXHEAT          (uint8)0        //0.91v conform 2021111
#define   u8MIXR_MAXCOOL          (uint8)100      //4.04V conform 2021111

#define   u8MODEL_VENT            ((uint8)0)      //0.46V conform 2021111
#define   u8MODEL_FOOT            ((uint8)49u)    //xxxxV conform 2021111
#define   u8MODEL_DEF             ((uint8)100u)   //4.51V conform 2021111

#define   u8MODER_VENT            ((uint8)100u)   //4.53V conform 2021111
#define   u8MODER_FOOT            ((uint8)42u)    //xxxV  conform 2021111
#define   u8MODER_DEF             ((uint8)0)      //0.46V conform 2021111

#define   u8DEF_CLOSE             (uint8)100      //3.95V conform 2021111
#define   u8DEF_OPEN              (uint8)0        //0.95V conform 2021111

#define   u8REC                   (uint8)100      //4.16V
#define   u8FRE                   (uint8)0        //1.79V


typedef enum
{
  MODEL_UNKNOWN = 0xffu,
  MODEL_VENT = 1u,
  MODEL_FOOT = 3u,
  MODEL_DEF = 5u,
} Actuator_tenuModeLState;



typedef enum
{
  MODER_UNKNOWN = 0xffu,
  MODER_VENT = 1u,
  MODER_FOOT = 3u,
  MODER_DEF = 5u,
} Actuator_tenuModeRState;


/* Actuator run state  */
typedef enum
{
  Actuator_IDLE,
  Actuator_STOP,
  Actuator_BRAKE,
  Actuator_CW,
  Actuator_CCW
} Actuator_tenuState;


/*Actuator failure state DTC use   */ 
typedef enum
{
  Actuator_FeedBackShortToGNDorOPEN ,
  Actuator_FeedBackShortToVCC5,
  Actuator_FeedBackNormal
}Actuator_tenuFailureState;
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
extern void Actuator_vidStop(uint8 u8ActId);
extern void Actuator_vidInit(void);
extern void Actuator_vidManage(uint8 u8ActId);
extern Actuator_tenuState Actuator_enuGetRunState(uint8 u8ActId);
extern void Actuator_vidSetPosition(uint8 u8ActId,uint8 u8Percent);
extern uint8 Actuator_u8GetPosition(uint8 u8ActId);
extern uint8 Actuator_u8GetRecFeedbackVolt(uint8 u8ActId);
extern Actuator_tenuFailureState Actuator_enuGetFailureState(uint8 u8ActId);
extern void Actuator_vidEnableManage(uint8 u8ActId,boolean bEn);
extern uint16 Actuator_u16GetCurrFbAdc(uint8 u8ActId);
extern Actuator_tenuModeLState Actuator_enuGetModeLStatus(void);
extern Actuator_tenuModeRState Actuator_enuGetModeRStatus(void);
extern uint8 Actuator_u8GetModeLStatusMathWithMbd(void);
extern void vidAppMixMotorMng(uint8 u8MixLReq ,uint8 u8MixRReq  );
extern void vidAppModeMotorMng(uint8 u8ModeReq);
extern void vidAppIntakeMotorMng(uint8 u8IntakeReq);
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#endif 

/*-------------------------------- end of file -------------------------------*/

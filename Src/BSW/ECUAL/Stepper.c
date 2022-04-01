/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Stepper                                                 */
/*                                                                            */
/* !Component       : Stepper                                                 */
/* !Description     : Provides interface for controlling the Stepper          */
/*                                                                            */
/* !Module          : Stepper                                                 */
/* !Description     : Provides interface for controlling the Stepper          */
/*                                                                            */
/* !File            : Stepper.c                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Stepper.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:12   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
 /*****************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Stepper.h"
#include "Elmos.h"
#include "Eeprom.h"
#include "Mcu.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description Minimum number of requested steps for the stepper to move.
*******************************************************************************/
#define u8MIN_STEPS_TO_MOVE (uint8)8

/******************************************************************************/
/*! \Description Number of steps used in acceleration ramp for fast speed.
*******************************************************************************/
#define u8NUM_ACC_STEPS_FAST  (uint8)3

/******************************************************************************/
/*! \Description Number of steps used in acceleration ramp for low speed.
*******************************************************************************/
#define u8NUM_ACC_STEPS_SLOW  (uint8)1

/******************************************************************************/
/*! \Description Number of steps used in deceleration.
*******************************************************************************/
#define u8NUM_OF_DECEL_STEPS (uint8)3

/******************************************************************************/
/*! \Description Number of sequences to drive the stepper.
*******************************************************************************/
#define u8NUM_OF_SEQ         (uint8)4

/******************************************************************************/
/*! \Description Nominal speed step time.
*******************************************************************************/
#define u8STEP_TIME_FAST     (uint8)5

/******************************************************************************/
/*! \Description Transition from Nominal and low speed step time.
*******************************************************************************/
#define u8STEP_TIME_TRANS    (uint8)6

/******************************************************************************/
/*! \Description low speed step time.
*******************************************************************************/
#define u8STEP_TIME_SLOW     (uint8)8


/******************************************************************************/
/*! \Description First Acceleration step time.
*******************************************************************************/
#define u8FIRST_ACC_STEP (uint8)11

/******************************************************************************/
/*! \Description Second Acceleration step time.
*******************************************************************************/
#define u8SECOND_ACC_STEP (uint8)8

/******************************************************************************/
/*! \Description Third Acceleration step time.
*******************************************************************************/
#define u8THIRD_ACC_STEP   (uint8)6

/******************************************************************************/
/*! \Description First deceleration step time.
*******************************************************************************/
#define u8FIRST_DECEL_STEP  (uint8)25

/******************************************************************************/
/*! \Description Second deceleration step time.
*******************************************************************************/
#define u8SECOND_DECEL_STEP (uint8)25

/******************************************************************************/
/*! \Description Third deceleration step time.
*******************************************************************************/
#define u8THIRD_DECEL_STEP  (uint8)200


/******************************************************************************/
/*! \Description First sequence to drive the stepper.
*******************************************************************************/
#define u8STEPPER_SEQ_0       (uint8)0x05

/******************************************************************************/
/*! \Description Second sequence to drive the stepper.
*******************************************************************************/
#define u8STEPPER_SEQ_I       (uint8)0x06

/******************************************************************************/
/*! \Description Third sequence to drive the stepper.
*******************************************************************************/
#define u8STEPPER_SEQ_II      (uint8)0x0A

/******************************************************************************/
/*! \Description Fourth sequence to drive the stepper.
*******************************************************************************/
#define u8STEPPER_SEQ_III     (uint8)0x09

/******************************************************************************/
/*! \Description The maximum number of failures while reading the previously
                 written data after which the stepper is consider in failure
                 state.
*******************************************************************************/
#define u8MAX_FAIL_ALLOWED    (uint8)100 //4


/******************************************************************************/
/*! \Description Maximum range for uint8.
*******************************************************************************/
#define u8MAX_UINT8 (uint8)255


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
static const uint8 Stepper_aku8ParaDefaultVal[Stepper_u8NUM_PARAMETERS] =
{
          6     //rec
         ,64    //rec
         ,6     //mode
         ,64    //mode
         ,6     //mixr
         ,104   //mixr
         ,6     //mixl
         ,144   //mixl
         ,1     /* REC   Stepper Rang            */ 
         ,211   /* REC   Stepper Range(467~70)   */
         ,1     /* I   Stepper Rang              */ 
         ,211   /* I   Stepper Range(467~70)     */
	 ,1     /* EXV   Stepper Rang            */ 
         ,211   /* EXV   Stepper Range(467~70)   */ 
/***************************************************************/
         ,40    /* MixL Over Steps               */
         ,40    /* MixR over Steps               */
         ,40    /* ModeF over Steps              */
         ,40    /* ModeR over Steps              */
         ,40    /* REC   over Steps              */
	 ,40    /* I   over Steps              */
	 ,40    /* EXV   over Steps              */
/***************************************************************/        
         ,40    /* MixL blocked steps            */
         ,40    /* MixR blocked steps            */
         ,60    /* ModeF blocked steps           */
         ,40    /* ModeR blocked steps           */
         ,40    /* REC blocked steps             */
	 ,40    /* I blocked steps             */
	 ,40    /* EXV blocked steps             */
/***************************************************************/        
         ,40    /* MixL dynamic Steps            */
         ,40    /* MixR dynamic Steps            */
         ,60    /* ModeF dynamic Steps           */
         ,40    /* ModeR dynamic Steps           */
         ,40    /* REC dynamic Steps             */
	 ,40    /* I dynamic Steps             */
	 ,40    /* EXV dynamic Steps             */
/***************************************************************/        
         ,1     /* MixL  direction  0%->100%     */          
         ,0     /* MixR  direction  100%->0%     */
         ,1     /* ModeF direction  0%->100%     */
         ,1     /* ModeR direction  0%->100%     */
         ,1     /* REC   direction  0%->100%     */
	 ,1     /* I   direction  0%->100%     */
	 ,1     /* EXV   direction  0%->100%     */
/***************************************************************/   
         ,0     /* ModeF Vent Percent             */
         ,25    /* ModeF Vent/Foot Percent       */
         ,50    /* ModeF Foot Percent            */
         ,75    /* ModeF Foot/Def Percent        */
         ,100   /* ModeF Def Percent             */
/***************************************************************/
         ,0     /* ModeR Vent Percent            */
         ,44    /* ModeR Vent/Foot Percent       */
         ,100   /* ModeR Foot Percent            */
};


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
/******************************************************************************/
/*! \Description Enables all interrupts.
*******************************************************************************/
#define vidENABLE_INTERRUPTS()  Mcu_vidEnableInterrupts()

/******************************************************************************/
/*! \Description Disables all interrupts.
*******************************************************************************/
#define vidDISABLE_INTERRUPTS() Mcu_vidDisableInterrupts()

/******************************************************************************/
/*! \Description Macro to control the stepper movement.
*******************************************************************************/
#define vidCONTROL_STEPPER(enuStepperId)                                       \
{                                                                              \
  /*! IF the motor state is not equal to STEPPER_STOPPED */                    \
  if (Stepper_aenuMotorState[enuStepperId] != STEPPER_STOPPED)                 \
  {                                                                            \
    if (LOC_au8RotateTime[enuStepperId] != 0)                                  \
    {                                                                          \
      /*! Decrement the Stepper Rotate Time. */                                \
      LOC_au8RotateTime[enuStepperId]--;                                       \
    }                                                                          \
                                                                               \
  }                                                                            \
  switch (Stepper_aenuMotorState[enuStepperId])                                \
  {                                                                            \
    /*! IF the Motor State is STEPPER_STOPPED THEN */                          \
    case STEPPER_STOPPED:                                                      \
      LOC_abStopMotor[enuStepperId] = FALSE;                                   \
                                                                               \
      /*! IF the current speed is not equal to the requested speed */          \
      if (Stepper_enuReqSpeed != LOC_enuCurrentSpeed)                          \
      {                                                                        \
                                                                               \
        /*! Set the current speed to the requested speed. */                   \
        LOC_enuCurrentSpeed = Stepper_enuReqSpeed;                             \
                                                                               \
      }                                                                        \
      /*! IF the number of steps to move is greater than 0 THEN */             \
      if (Stepper_au8ReqSteps[enuStepperId] > 0)                               \
      {                                                                        \
        /*! Set the rotate time. */                                            \
        LOC_au8RotateTime[enuStepperId] = u8FIRST_ACC_STEP;                    \
                                                                               \
        /*! Set the Motor State to STEPPER_ACC. */                             \
        Stepper_aenuMotorState[enuStepperId] = STEPPER_ACC;                    \
                                                                               \
        /*! Set Acceleration Index to Zero. */                                 \
        LOC_au8AccDecelIndex[enuStepperId] = 0;                                \
                                                                               \
        bSendData = TRUE;                                                      \
                                                                               \
      }                                                                        \
      break ;                                                                  \
                                                                               \
      /*! IF the Motor State is STEPPER_ACC THEN */                            \
    case STEPPER_ACC:                                                          \
                                                                               \
      /*! IF Rotate time equals zero THEN */                                   \
      if (LOC_au8RotateTime[enuStepperId] == 0)                                \
      {                                                                        \
        if (Stepper_au8ReqSteps[enuStepperId] != 0)                            \
        {                                                                      \
          /*! Decrement the Number of requested steps to move. */              \
          Stepper_au8ReqSteps[enuStepperId]--;                                 \
        }                                                                      \
                                                                               \
        /*! Increment the Acceleration Index. */                               \
        LOC_au8AccDecelIndex[enuStepperId]++;                                  \
                                                                               \
        /*! IF the acceleration index is less than the number of               \
            acc. steps */                                                      \
        if (LOC_au8AccDecelIndex[enuStepperId] < u8NumOfAccelSteps)            \
        {                                                                      \
          /*! Set the rotate step time */                                      \
          LOC_au8RotateTime[enuStepperId] =                                    \
              LOC_aku8AccStepTime[LOC_au8AccDecelIndex[enuStepperId]];         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
          /*! Set the Motor state to moving. */                                \
          Stepper_aenuMotorState[enuStepperId] = STEPPER_MOVING;               \
                                                                               \
          /*! Set the rotate step time */                                      \
          LOC_au8RotateTime[enuStepperId] = u8NormalStepTime;                  \
                                                                               \
        }                                                                      \
        bSendData = TRUE;                                                      \
                                                                               \
      }                                                                        \
                                                                               \
      break ;                                                                  \
                                                                               \
      /*! IF the Motor State is STEPPER_MOVING THEN */                         \
    case STEPPER_MOVING:                                                       \
      /*! IF Rotate time equals zero THEN */                                   \
      if (LOC_au8RotateTime[enuStepperId] == 0)                                \
      {                                                                        \
        if (Stepper_au8ReqSteps[enuStepperId] != 0)                            \
        {                                                                      \
          /*! Decrement the Number of requested steps to move. */              \
          Stepper_au8ReqSteps[enuStepperId]--;                                 \
        }                                                                      \
                                                                               \
        /*! IF the current speed is not equal to the requested speed */        \
        if (Stepper_enuReqSpeed != LOC_enuCurrentSpeed)                        \
        {                                                                      \
          /*! Set the step time to the transitional step time (6ms) */         \
          u8NormalStepTime = u8STEP_TIME_TRANS;                                \
                                                                               \
          /*! Set the current speed to the requested speed. */                 \
          LOC_enuCurrentSpeed = Stepper_enuReqSpeed;                           \
                                                                               \
        }                                                                      \
                                                                               \
        /*! If the number of requested steps is less than or equal 2 */        \
        if (Stepper_au8ReqSteps[enuStepperId] == 0)                            \
        {                                                                      \
          /*! Set the rotate step time. */                                     \
          LOC_au8RotateTime[enuStepperId] = LOC_aku8DecelStepTime[0];          \
                                                                               \
          /*! Set the deceleration Index to zero. */                           \
          LOC_au8AccDecelIndex[enuStepperId] = 0;                              \
                                                                               \
          /*! Set Motor state to deceleration. */                              \
          Stepper_aenuMotorState[enuStepperId] = STEPPER_DECEL;                \
        }                                                                      \
        else                                                                   \
        {                                                                      \
          /*! Set the rotate step time */                                      \
          LOC_au8RotateTime[enuStepperId] = u8NormalStepTime;                  \
                                                                               \
        }                                                                      \
        bSendData = TRUE;                                                      \
                                                                               \
      }                                                                        \
                                                                               \
      break ;                                                                  \
                                                                               \
      /*! IF the Motor State is STEPPER_DECEL THEN */                          \
    case STEPPER_DECEL:                                                        \
                                                                               \
      /*! IF Rotate time equals zero THEN */                                   \
      if (LOC_au8RotateTime[enuStepperId] == 0)                                \
      {                                                                        \
                                                                               \
                                                                               \
        /*! Increment Decel Index. */                                          \
        LOC_au8AccDecelIndex[enuStepperId]++;                                  \
                                                                               \
        /*! IF Decel Index is less than the number of decel steps */           \
        if (LOC_au8AccDecelIndex[enuStepperId] < u8NUM_OF_DECEL_STEPS)         \
        {                                                                      \
          /*! Set the stepper's rotate time. */                                \
          LOC_au8RotateTime[enuStepperId] =                                    \
              LOC_aku8DecelStepTime[LOC_au8AccDecelIndex[enuStepperId]];       \
                                                                               \
          /*! If the last deceleration step is reached. */                     \
          if (LOC_au8AccDecelIndex[enuStepperId] == (u8NUM_OF_DECEL_STEPS      \
              - 1))                                                            \
          {                                                                    \
            /*! Set stop motor flag to TRUE. */                                \
            LOC_abStopMotor[enuStepperId] = TRUE;                              \
          }                                                                    \
                                                                               \
          if (Stepper_au8ReqSteps[enuStepperId] != 0)                          \
          {                                                                    \
            /*! Decrement the Number of requested steps to move. */            \
            Stepper_au8ReqSteps[enuStepperId]--;                               \
          }                                                                    \
          bSendData = TRUE;                                                    \
        }                                                                      \
        /*! ELSE */                                                            \
        else                                                                   \
        {                                                                      \
          /*! Set Motor state to STEPPER_STOPPED*/                             \
          Stepper_aenuMotorState[enuStepperId] = STEPPER_STOPPED;              \
                                                                               \
        }                                                                      \
      }                                                                        \
                                                                               \
      break ;                                                                  \
                                                                               \
    default :                                                                  \
      break ;                                                                  \
  }                                                                            \
  /*! IF Send data is TRUE. */                                                 \
  if (bSendData == TRUE)                                                       \
  {                                                                            \
    /*! Read the previously written Elmos data. */                             \
    u8ElmosData = Elmos_u8Read(LOC_akenuElmosId[enuStepperId]);                \
                                                                               \
                                                                               \
    /*! If the Read Value from the Elmos is not equal to previously            \
     written data*/                                                            \
    if (u8ElmosData != LOC_au8PrevElmosData[enuStepperId])                     \
    {                                                                          \
                                                                               \
      LOC_au8SuccessCount[enuStepperId] = 0;                                   \
                                                                               \
      /*! If fail count is greater than or equal 3 */                          \
      if (LOC_au8FailCount[enuStepperId] >= (u8MAX_FAIL_ALLOWED - 1))          \
      {                                                                        \
        /*! Set the stepper failure status to Stepper_FAIL. */                 \
        Stepper_aenuFailureStatus[enuStepperId] = Stepper_FAIL;                \
        Stepper_aenuFailureStatusFb[enuStepperId] = Stepper_FAIL;              \
      }                                                                        \
      /*! ELSE */                                                              \
      else                                                                     \
      {                                                                        \
        /*! Increment Stepper fail count. */                                   \
        LOC_au8FailCount[enuStepperId]++;                                      \
      }                                                                        \
                                                                               \
    }                                                                          \
    /*! ELSE [Data was written successfully ]*/                                \
    else                                                                       \
    {                                                                          \
                                                                               \
      LOC_au8SuccessCount[enuStepperId]++;                                     \
      if (LOC_au8SuccessCount[enuStepperId] == 4)                              \
      {                                                                        \
        LOC_au8FailCount[enuStepperId] = 0;                                    \
        LOC_au8SuccessCount[enuStepperId] = 0;                                 \
        Stepper_aenuFailureStatusFb[enuStepperId] = Stepper_NO_FAIL;           \
      }                                                                        \
                                                                               \
                                                                               \
    }                                                                          \
                                                                               \
    /*! If stop motor flag is FALSE */                                         \
    if (LOC_abStopMotor[enuStepperId] == FALSE)                                \
    {                                                                          \
      /*! Update Motor Phase Index */                                          \
      if (Stepper_aenuMotorDirec[enuStepperId] == Stepper_ROTATE_CW)           \
      {                                                                        \
        if (Stepper_au8SeqIndex[enuStepperId] != 3)                            \
        {                                                                      \
          Stepper_au8SeqIndex[enuStepperId]++;                                 \
        }                                                                      \
        else                                                                   \
        {                                                                      \
          Stepper_au8SeqIndex[enuStepperId] = 0;                               \
        }                                                                      \
                                                                               \
      }                                                                        \
      else                                                                     \
      {                                                                        \
        if (Stepper_au8SeqIndex[enuStepperId] != 0)                            \
        {                                                                      \
          Stepper_au8SeqIndex[enuStepperId]--;                                 \
        }                                                                      \
        else                                                                   \
        {                                                                      \
          Stepper_au8SeqIndex[enuStepperId] = 3;                               \
        }                                                                      \
      }                                                                        \
    }                                                                          \
                                                                               \
                                                                               \
    /*! IF stop motor flag is TRUE */                                          \
    if (LOC_abStopMotor[enuStepperId] == TRUE)                                 \
    {                                                                          \
      /*! Set the data to be written to 0x0F. */                               \
      u8ElmosData = 0x0F;                                                      \
    }                                                                          \
    else                                                                       \
    {                                                                          \
      /*!  Set the data to be written to the current Phase data. */            \
      if (Stepper_aenuMotorState[enuStepperId]!= STEPPER_DECEL)                \
      {                                                                        \
        u8ElmosData = LOC_aku8MotorSeqs[Stepper_au8SeqIndex[enuStepperId]];    \
      }                                                                        \
    }                                                                          \
                                                                               \
    LOC_au8PrevElmosData[enuStepperId] = u8ElmosData;                          \
                                                                               \
    /*! Write data to the Elmos. */                                            \
    Elmos_vidWrite(LOC_akenuElmosId[enuStepperId], u8ElmosData);               \
                                                                               \
  }                                                                            \
}

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/******************************************************************************/
/*! \Description Request State Type.
*******************************************************************************/
typedef enum
{
  REQ_IDLE,
  REQ_ONGOING
} tenuReqState;

/******************************************************************************/
/*! \Description Check State Type.
*******************************************************************************/
typedef enum
{
  CHK_START,
  CHK_STEP_1,
  CHK_STEP_2,
  CHK_STEP_3,
  CHK_DONE
} tenuCheckState;

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/******************************************************************************/
/*! \Description ModeF Voltage to Levels data.
*******************************************************************************/
/*static*/ uint8   Stepper_au8ModeFLevels[7/*Stepper_u8NUM_MODEFLEVELS*/] = {2 ,23,67,55,85,41,98};

/******************************************************************************/
/*! \Description ModeR Voltage to Levels data.
*******************************************************************************/
static uint8   Stepper_au8ModeRLevels[Stepper_u8NUM_MODERLEVELS];

/******************************************************************************/
/*! \Description Rotate direction when moving to Full Range position.
*******************************************************************************/
static Stepper_tenuRotateDirec  Stepper_aenuZeroToFullDirec[Stepper_u8NUM];

/******************************************************************************/
/*! \Description The sequence Index used to drive the stepper.
*******************************************************************************/
static uint8  Stepper_au8SeqIndex[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Current stepper position.
*******************************************************************************/
static uint16 Stepper_au16CurrentPosition[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Requested destination position.
*******************************************************************************/
static uint16 Stepper_au16ReqDestPosition[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper's full range.
*******************************************************************************/
static uint16 Stepper_au16FullRange[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper's change of direction steps.
*******************************************************************************/
static uint8  Stepper_au8ChgOfDirecSteps[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper's Stalling blocking steps.
*******************************************************************************/
static uint8  Stepper_au8StallSteps[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper's Over stepping blocking steps.
*******************************************************************************/
static uint8  Stepper_au8OverSteps[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper's rotation direction.
*******************************************************************************/
static Stepper_tenuRotateDirec  Stepper_aenuMotorDirec[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper's Failure status.
*******************************************************************************/
static Stepper_tenuFailureState Stepper_aenuFailureStatus[Stepper_u8NUM];

static Stepper_tenuFailureState Stepper_aenuFailureStatusFb[Stepper_u8NUM];
/******************************************************************************/
/*! \Description Stepper's stall status.
*******************************************************************************/
static Stepper_tenuStallState   Stepper_aenuStallStatus[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Current requested steps to move.
*******************************************************************************/
static uint8                    Stepper_au8ReqSteps[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper's speed.
*******************************************************************************/
static Stepper_tenuSpeed        Stepper_enuReqSpeed;

/******************************************************************************/
/*! \Description Stop all motors flag.
*******************************************************************************/
static boolean                  Stepper_bStopMotors;

/******************************************************************************/
/*! \Description Initialization done flag.
*******************************************************************************/
static boolean                  Stepper_bInitDone = FALSE;

/******************************************************************************/
/*! \Description Stepper running State.
*******************************************************************************/
static Stepper_tenuMotorState   Stepper_aenuMotorState[Stepper_u8NUM];

/******************************************************************************/
/*! \Description Stepper running check State.
*******************************************************************************/
static tenuCheckState           Stepper_enuCheckState;

/******************************************************************************/
/*! \Description Stepper Pause Control Flag.
*******************************************************************************/
static boolean                  Stepper_bControlPause;

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
/*!Function : Stepper_vidInit.                                                */
/*! \Description Stepper initialization function.
    \return      void
    \Trace_To    CDD-Stepper-0026(0)
*******************************************************************************/
void Stepper_vidInit( void )
{
  uint8   u8Index = 0u;
  //uint8   u8Chk = 0u;
  //uint8   au8StepperParaBuf[Stepper_u8EEP_SIZE];     
  /*! Set the failure status for all steppers to Stepper_UNKNOWN_FAIL. */
  for (u8Index = 0u ; u8Index < Stepper_u8NUM ; u8Index++)
  {
    Stepper_aenuFailureStatus[u8Index] = Stepper_UNKNOWN_FAIL;
    Stepper_aenuFailureStatusFb[u8Index] = Stepper_UNKNOWN_FAIL;
    Stepper_aenuStallStatus[u8Index] = Stepper_STALL_INIT;
    Stepper_au8ReqSteps[u8Index] = 0u;
    Stepper_aenuMotorState[u8Index]=STEPPER_STOPPED;
  } 
  /*! Set the stepper's speed to the nominal speed. */
  Stepper_enuReqSpeed = Stepper_FAST;

  /*! Set the stop all motors flag to FALSE. */
  Stepper_bStopMotors = FALSE;

  /*! Set the Init done flag to TRUE. */
  Stepper_bInitDone = TRUE;
  /* set Steppers Parameters*/
  /*! initial Stepper Running Parameters and ModeF and ModeR position data*/
  /*if use eep data*/
#if 0
  if(TRUE == EEP_bGetEEPValidInfo())
  {
      /*! set stepper running parameters form eep*/
      if(Stepper_u8EEP_SIZE ==
              EEP_u16ReadData((EEP_u16STEPPER_PARA_SUBADDR + EEP_ADDR_STATIC),
                               au8StepperParaBuf, Stepper_u8EEP_SIZE))
        {
            for(u8Index = 0u; u8Index < (Stepper_u8EEP_SIZE-1u);u8Index++)
            {
                u8Chk += au8StepperParaBuf[u8Index];
            }
            u8Chk = 255u - u8Chk;
            /* chk ok */
            if(u8Chk == au8StepperParaBuf[Stepper_u8EEP_SIZE - 1u])
            {
                /*use eep*/
                Stepper_vidSetContext(au8StepperParaBuf);
            }
            /* chk ok */
            else
            {
                /*use default*/
                Stepper_vidSetContext(Stepper_aku8ParaDefaultVal);
            }
        }
        else
        {
            /*use default*/
            Stepper_vidSetContext(Stepper_aku8ParaDefaultVal);
        }
  }
  else
  {
      /*use default*/
      Stepper_vidSetContext(Stepper_aku8ParaDefaultVal);
  }
#endif

  Stepper_au16FullRange[Stepper_REC] = 490u;
  Stepper_au8OverSteps[Stepper_REC] = 40U;
  Stepper_au8StallSteps[Stepper_REC] = 40U;
  Stepper_aenuZeroToFullDirec[Stepper_REC] = (Stepper_tenuRotateDirec)1U;
  
  Stepper_au16FullRange[Stepper_MODE_F] = 2480u;
  Stepper_au8OverSteps[Stepper_MODE_F] = 40U;
  Stepper_au8StallSteps[Stepper_MODE_F] = 40U;
  Stepper_aenuZeroToFullDirec[Stepper_MODE_F] = (Stepper_tenuRotateDirec)1U;
  
  Stepper_au16FullRange[Stepper_MIX_R] = 1240u*2U;
  Stepper_au8OverSteps[Stepper_MIX_R] = 40U;
  Stepper_au8StallSteps[Stepper_MIX_R] = 40U;
  Stepper_aenuZeroToFullDirec[Stepper_MIX_R] = (Stepper_tenuRotateDirec)0U;
  
  Stepper_au16FullRange[Stepper_MIX_L] = 1240u*2U;
  Stepper_au8OverSteps[Stepper_MIX_L] = 40U;
  Stepper_au8StallSteps[Stepper_MIX_L] = 40U;
  Stepper_aenuZeroToFullDirec[Stepper_MIX_L] = (Stepper_tenuRotateDirec)1U;
  
  Stepper_enuCheckState = CHK_START;

  Stepper_vidRecoverPosition();

  Stepper_bControlPause = FALSE;
  
}

/******************************************************************************/
/*!Function : Stepper_vidSetContext.                                          */
/*! \Description This function sets the post build configuration parameters for
                 the stepper.
    \param[in]   pkstrContext : Pointer to context .
    \Range       NOT_NULL
    \return      void.
    \Trace_To    CDD-Stepper-0027(0)
*******************************************************************************/
void Stepper_vidSetContext(const uint8* pku8Context)
{
    uint8   u8Index = 0u;
    /*! IF pkstrContext not equal to null pointer */
    if (pku8Context != 0u)
    { 
        /*! set stepper running parameters*/
        for (u8Index = 0u; u8Index < Stepper_u8NUM; u8Index++)
        {
           Stepper_au16FullRange[u8Index] =
           256u * pku8Context[2u * u8Index] + pku8Context[(2u * u8Index) + 1u];
           
           Stepper_au8OverSteps[u8Index] =
                         pku8Context[u8Index + (2u * Stepper_u8NUM)];
    
           Stepper_au8StallSteps[u8Index] =
                         pku8Context[u8Index + (3u * Stepper_u8NUM)];
    
           Stepper_au8ChgOfDirecSteps[u8Index] =
                         pku8Context[u8Index + (4u * Stepper_u8NUM)];
   
           Stepper_aenuZeroToFullDirec[u8Index] =
          (Stepper_tenuRotateDirec)pku8Context[u8Index + (5u * Stepper_u8NUM)];
           
        }
        for(u8Index = 0u; u8Index < Stepper_u8NUM_MODEFLEVELS; u8Index++)
        {
           Stepper_au8ModeFLevels[u8Index] =
                      pku8Context[u8Index + Stepper_u8NUM_RUNPARA];
        }
        for(u8Index = 0u; u8Index < Stepper_u8NUM_MODERLEVELS; u8Index++)
        {
           Stepper_au8ModeRLevels[u8Index] =
           pku8Context[u8Index + Stepper_u8NUM_RUNPARA +
                                           Stepper_u8NUM_MODEFLEVELS];
        }  
    }
    if(Stepper_au16FullRange[0]<100) 
    {
        Stepper_au16FullRange[0] =
         (uint16)((Stepper_aku8ParaDefaultVal[0] * 256u) +
                   Stepper_aku8ParaDefaultVal[1]);
    }
    if(Stepper_au16FullRange[1]<100)
    {
        Stepper_au16FullRange[1] =
        (uint16)((Stepper_aku8ParaDefaultVal[2] * 256u) +
                Stepper_aku8ParaDefaultVal[3]);
    }
    if(Stepper_au16FullRange[2]<100)
    {
        Stepper_au16FullRange[2] =
            (uint16)((Stepper_aku8ParaDefaultVal[4] * 256u) +
                    Stepper_aku8ParaDefaultVal[5]);
    }
    if(Stepper_au16FullRange[3]<100)
    {
        Stepper_au16FullRange[3] =
            (uint16)((Stepper_aku8ParaDefaultVal[6] * 256u) +
                    Stepper_aku8ParaDefaultVal[7]);
    }
    if(Stepper_au16FullRange[4]<100)
    {
        Stepper_au16FullRange[4] =
            (uint16)((Stepper_aku8ParaDefaultVal[8] * 256u) +
                    Stepper_aku8ParaDefaultVal[9]);
    }
	if(Stepper_au16FullRange[5]<100)
    {
        Stepper_au16FullRange[5] =
            (uint16)((Stepper_aku8ParaDefaultVal[10] * 256u) +
                    Stepper_aku8ParaDefaultVal[11]);
    }
    if(Stepper_au16FullRange[6]<100)
    {
        Stepper_au16FullRange[6] =
            (uint16)((Stepper_aku8ParaDefaultVal[12] * 256u) +
                    Stepper_aku8ParaDefaultVal[13]);
    }
    
    if(Stepper_aenuZeroToFullDirec[0]>1)
    {
        Stepper_aenuZeroToFullDirec[0]=
            (Stepper_tenuRotateDirec)Stepper_aku8ParaDefaultVal[35];
    }
    if(Stepper_aenuZeroToFullDirec[1]>1)
    {
        Stepper_aenuZeroToFullDirec[1]=
            (Stepper_tenuRotateDirec)Stepper_aku8ParaDefaultVal[36];
    }
    if(Stepper_aenuZeroToFullDirec[2]>1)
    {
        Stepper_aenuZeroToFullDirec[2]=
            (Stepper_tenuRotateDirec)Stepper_aku8ParaDefaultVal[37];
    }
    if(Stepper_aenuZeroToFullDirec[3]>1)
    {
        Stepper_aenuZeroToFullDirec[3]=
            (Stepper_tenuRotateDirec)Stepper_aku8ParaDefaultVal[38];
    }
    if(Stepper_aenuZeroToFullDirec[4]>1)
    {
        Stepper_aenuZeroToFullDirec[4]=
            (Stepper_tenuRotateDirec)Stepper_aku8ParaDefaultVal[39];
    }
	if(Stepper_aenuZeroToFullDirec[5]>1)
    {
        Stepper_aenuZeroToFullDirec[5]=
            (Stepper_tenuRotateDirec)Stepper_aku8ParaDefaultVal[40];
    }
    if(Stepper_aenuZeroToFullDirec[6]>1)
    {
        Stepper_aenuZeroToFullDirec[6]=
            (Stepper_tenuRotateDirec)Stepper_aku8ParaDefaultVal[41];
    }

}


/******************************************************************************/
/*!Function : Stepper_vidGetContext.                                          */
/*! \Description Outputs the dynamic variables that need to be saved \n
    \param[out]  pstrContext : Pointer to dynamic context structure.
    \Range       NOT_NULL  \n
    \return      void.
    \Trace_To    CDD-Stepper-0028(0)
*******************************************************************************/
void Stepper_vidGetContext(Stepper_tstrDynmContext* pstrContext)
{
  uint8 u8Index;


  /*! IF pstrContext not equal to null pointer THEN */
  if (pstrContext != 0)
  {
    /*! Set the Motor direction, current position and Motor phase index in
        context structure */
    for (u8Index = 0; u8Index < Stepper_u8NUM; u8Index++)
    {


    }
  }

}


/******************************************************************************/
/*!Function : Stepper_vidSetMotorPosition                                     */
/*! \Description Sets the Motor position.
    \param[in]   enuStepperId : Stepper Id.
    \Range       Stepper_MIX_L, Stepper_MIX_R, Stepper_MODE
    \param[in]   u8Position : Stepper position.
    \Range       0..100
    \return      void
    \Trace_To    CDD-Stepper-0029(0)
*******************************************************************************/
void Stepper_vidSetMotorPosition
(Stepper_tenuStepperId enuStepperId,uint8 u8Position)
{
    uint32 u32Temp;
    /*! convert the requested position from percentage to steps. */
    u32Temp = (uint32)Stepper_au16FullRange[enuStepperId] * (uint32)u8Position;
    u32Temp = u32Temp / 100;
    if(Stepper_enuGetStallState(enuStepperId)  == Stepper_STALL_DONE)
    {
	/*! If the Zero to Full range direction is CCW */
	if (Stepper_aenuZeroToFullDirec[enuStepperId] == Stepper_ROTATE_CCW)
	{
	    /*! Set the requested destination position to Full range minus the
	      converted value. */
	    Stepper_au16ReqDestPosition[enuStepperId] =
		Stepper_au16FullRange[enuStepperId] - (uint16)u32Temp;

	}
	/*! Else */
	else
	{
	    /*! Set the requested destination position to the converted value. */
	    Stepper_au16ReqDestPosition[enuStepperId] = (uint16)u32Temp;
	}
    }
}


/******************************************************************************/
/*!Function : Stepper_vidSetSpeed                                             */
/*! \Description Sets the stepper's speed.
    \param[in]   enuSpeed : Stepper Speed.
    \Range       Stepper_SLOW, Stepper_FAST
    \return      void
    \Trace_To    CDD-Stepper-0030(0)
*******************************************************************************/
void Stepper_vidSetSpeed(Stepper_tenuSpeed enuSpeed)
{

  /*! Set the Stepper's speed. */
  Stepper_enuReqSpeed = enuSpeed;

}



/******************************************************************************/
/*!Function : Stepper_enuGetFailureState                                      */
/*! \Description Returns the failure status of the stepper.
    \param[in]   enuStepperId : Stepper Id.
    \Range       Stepper_MIX_L, Stepper_MIX_R, Stepper_MODE
    \return     Failure status of the stepper.
    \Range      Stepper_UNKNOWN_FAIL, Stepper_NO_FAIL, Stepper_FAIL
    \Trace_To   CDD-Stepper-0033(0)
*******************************************************************************/
Stepper_tenuFailureState Stepper_enuGetFailureState
(
  Stepper_tenuStepperId enuStepperId
)
{

  /*! return the current stepper failure status. */
  return Stepper_aenuFailureStatusFb[enuStepperId];

}


/******************************************************************************/
/*!Function : Stepper_vidStallMotor                                           */
/*! \Description Starts stalling the selected stepper motor.
    \param[in]   enuStepperId : Stepper Id.
    \Range       Stepper_MIX_L, Stepper_MIX_R, Stepper_MODE
    \return      void.
    \Trace_To    CDD-Stepper-0098(0)
*******************************************************************************/
void Stepper_vidStallMotor(Stepper_tenuStepperId enuStepperId)
{

  /*! Start Auto stalling for the selected stepper. */
  Stepper_aenuStallStatus[enuStepperId] = Stepper_STALL_START;


}

/******************************************************************************/
/*!Function : Stepper_enuGetStallState                                        */
/*! \Description Returns the the stalling status of the stepper.
    \param[in]   enuStepperId : Stepper Id.
    \Range       Stepper_MIX_L, Stepper_MIX_R, Stepper_MODE
    \return     Stalling status of the stepper.
    \Range      Stepper_UNKNOWN_FAIL, Stepper_NO_FAIL, Stepper_FAIL
    \Trace_To   CDD-Stepper-0133(0)
*******************************************************************************/
Stepper_tenuStallState Stepper_enuGetStallState
(
  Stepper_tenuStepperId enuStepperId
)
{
  /*! return the stalling status of the stepper. */
  return Stepper_aenuStallStatus[enuStepperId];

}


/******************************************************************************/
/*!Function : Stepper_vidStopMotors                                           */
/*! \Description Request to Stop operation on all motors.
    \return      void
    \Trace_To    CDD-Stepper-0134(0)
*******************************************************************************/
void Stepper_vidStopMotors( void )
{
  /*! Reset Stop Motors Flag to TRUE. */
  Stepper_bStopMotors = TRUE;

}

/******************************************************************************/
/*!Function : Stepper_vidContinueMotors                                       */
/*! \Description Request to Continue operation on all motors.
    \return      void
    \Trace_To    CDD-Stepper-0135(0)
*******************************************************************************/
void Stepper_vidContinueMotors( void )
{
  /*! Reset Stop Motors Flag to FALSE. */
  Stepper_bStopMotors = FALSE;

}

/* !Deviation : Inhibit MISRA rule [3006]: Assembly code used to
    disable and enable interrupts.                                            */
/* PRQA S 3006 ++                                                       */

/******************************************************************************/
/*!Function : Stepper_vidManage                                               */
/*! \Description Steppers manage function.
    \param[in]   enuStepperId : Stepper Id.
    \Range       Stepper_MIX_L, Stepper_MIX_R, Stepper_MODE
    \return      void.
    \Trace_To    CDD-Stepper-0136(0),CDD-Stepper-0137(0),CDD-Stepper-0138(0),
                 CDD-Stepper-0143(0),CDD-Stepper-0139(0),CDD-Stepper-0140(0)
*******************************************************************************/
void Stepper_vidManage(Stepper_tenuStepperId enuStepperId)
{

  static uint8   LOC_au8ExtraStepsCount[Stepper_u8NUM] =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };
  
  static uint16  LOC_au16DestPosition[Stepper_u8NUM] =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };

  static tenuReqState LOC_aenuReqState[Stepper_u8NUM] =
  {
    REQ_IDLE, REQ_IDLE, REQ_IDLE,REQ_IDLE, REQ_IDLE, REQ_IDLE, REQ_IDLE
  };

  static uint8 LOC_au8ReqSteps[Stepper_u8NUM] =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };
  
  static uint16 LOC_au16StepsToMove[Stepper_u8NUM] =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };

  uint16 u16Diff = 0;
  uint8  u8Diff;
  boolean bChangeDirec = FALSE;
  boolean bStopToAcc   = FALSE;
  boolean bStopStepper = FALSE;
  uint8 u8CurrReqSteps;

  uint16  u16CurrentPosition = Stepper_au16CurrentPosition[enuStepperId];
  uint16  u16ReqDestination = Stepper_au16ReqDestPosition[enuStepperId];

	tenuReqState enuReq;
	if (Stepper_bControlPause == TRUE)
	{
		enuReq = (tenuReqState)0xFFu;
	}
	else
	{
		enuReq = LOC_aenuReqState[enuStepperId];
	}

  switch (enuReq)
  {
    /*! IF the stepper request state is REQ_IDLE THEN */
    case REQ_IDLE:

      /*! IF Motor stop request is FALSE and the failure status is
          No fail THEN */
      if ( (Stepper_bStopMotors == FALSE) && 
           (Stepper_aenuFailureStatus[enuStepperId] == Stepper_NO_FAIL))
      {
        /*! IF Stepper's Stall status is STALL_START THEN */
        if (Stepper_aenuStallStatus[enuStepperId] == Stepper_STALL_START)
        {
          /*! Set the stepper's stall status to STALL_ONGOING. */
          Stepper_aenuStallStatus[enuStepperId] = Stepper_STALL_ONGOING;


          /*! If zero to full range rotate direction is CCW Then */
          if (Stepper_aenuZeroToFullDirec[enuStepperId] == Stepper_ROTATE_CCW)
          {
            /*! Set the requested destination to full range. */
            u16ReqDestination = Stepper_au16FullRange[enuStepperId];

            Stepper_au16ReqDestPosition[enuStepperId] = u16ReqDestination;

            /*! Set the current position to zero. */
            u16CurrentPosition = 0;
            Stepper_au16CurrentPosition[enuStepperId] = 0;


          }
          /*! Else */
          else
          {
            /*! Set the requested destination to zero. */
            u16ReqDestination = 0;

            Stepper_au16ReqDestPosition[enuStepperId] = 0;

            /*! Set the current position to full range. */
            u16CurrentPosition = Stepper_au16FullRange[enuStepperId];
            Stepper_au16CurrentPosition[enuStepperId] = u16CurrentPosition;

          }

        }

        /*! IF requested destination position is greater than the current
         position */
        if (u16ReqDestination > u16CurrentPosition)
        {
          /*! If the motor was rotating in counter clock wise direction */
          if (Stepper_aenuMotorDirec[enuStepperId] == Stepper_ROTATE_CCW)
          {
            /*! Set Change direction flag to true */
            bChangeDirec = TRUE;

          }

          u16Diff = u16ReqDestination - u16CurrentPosition;

          /*! If the number of steps to move is greater than or equal 8 */
          if (u16Diff >= u8MIN_STEPS_TO_MOVE)
          {
            /*! Set transition to Acceleration flag to TRUE */
            bStopToAcc = TRUE;

            Stepper_aenuMotorDirec[enuStepperId] = Stepper_ROTATE_CW;

            /*! Set the current destination position to the
             *  requested destination */
            LOC_au16DestPosition[enuStepperId] = u16ReqDestination;

          }

        }
        /*! ELSE IF the current position is greater than the requested
           destination */
        else if (u16ReqDestination < u16CurrentPosition)
        {
          /*! If the motor was rotating in clock wise direction */
          if (Stepper_aenuMotorDirec[enuStepperId] == Stepper_ROTATE_CW)
          {
            /*! Set Change direction flag to true */
            bChangeDirec = TRUE;

          }

          u16Diff = u16CurrentPosition - u16ReqDestination;

          /*! If the number of steps to move is greater than or equal 8 */
          if (u16Diff >= u8MIN_STEPS_TO_MOVE)
          {
            Stepper_aenuMotorDirec[enuStepperId] = Stepper_ROTATE_CCW;
            /*! Set transition to Acceleration flag to TRUE */
            bStopToAcc = TRUE;

            /*! Set the current destination position to the
             *  requested destination */
            LOC_au16DestPosition[enuStepperId] = u16ReqDestination;

          }

        }
        /*! ELSE (Requested destination equal to the current position] */
        else
        {
          /*! Do Nothing */

        }

        if (bStopToAcc == TRUE)
        {
          /*! Set the request state to REQ_ONGOING. */
          LOC_aenuReqState[enuStepperId] = REQ_ONGOING;

          /*! IF change of direction flag is TRUE. */
          if (bChangeDirec == TRUE)
          {
            /*! Set the extra steps count to change of direction steps
             minus the current extra steps count. */
            LOC_au8ExtraStepsCount[enuStepperId] =
                Stepper_au8ChgOfDirecSteps[enuStepperId]
                - LOC_au8ExtraStepsCount[enuStepperId];

          }

          u16Diff = u16Diff + LOC_au8ExtraStepsCount[enuStepperId];
          /*! If the requested destination is zero or full range */
          if ((u16ReqDestination == 0) ||
              (u16ReqDestination == Stepper_au16FullRange[enuStepperId]))

          {
            if (Stepper_aenuStallStatus[enuStepperId] == Stepper_STALL_ONGOING)
            {
              /*! Add stall steps. */
              u16Diff = u16Diff + Stepper_au8StallSteps[enuStepperId];
            }
            else
            {
              u16Diff = u16Diff + Stepper_au8OverSteps[enuStepperId];

            }

          }

          /*! Set the requested steps */
          if (u16Diff <= u8MAX_UINT8)
          {
            Stepper_au8ReqSteps[enuStepperId] = (uint8)u16Diff;
          }
          else
          {
            Stepper_au8ReqSteps[enuStepperId] = u8MAX_UINT8;

          }
          LOC_au16StepsToMove[enuStepperId] = u16Diff;
          LOC_au8ReqSteps[enuStepperId] = Stepper_au8ReqSteps[enuStepperId];

        }

      }
      else if((Stepper_bStopMotors == FALSE) &&
              (Stepper_aenuFailureStatus[enuStepperId] == Stepper_FAIL))
      {
	  /*init stepper for max. 3 times if fail*/

/*	  static uint8 LOC_u8InitTimes=0;
 - 	  if(LOC_u8InitTimes<3)
 - 	  {*/
	      Stepper_vidClearFail(enuStepperId);
	      Stepper_vidSetSpeed(Stepper_FAST);
	      Stepper_vidContinueMotors();
	      Stepper_vidStallMotor(enuStepperId);
	
		LOC_aenuReqState[enuStepperId] = REQ_IDLE;
/*	      LOC_u8InitTimes++;
 - 	  }
 - 	  else
 - 	  {
 - 		  while(1);@/@*$reset$*@/@
 - 	  }*/
		
      }
      break ;

      /*! IF the stepper request state is REQ_ONGOING THEN */
    case REQ_ONGOING:


      u8CurrReqSteps = Stepper_au8ReqSteps[enuStepperId];


      /*! Calculate the number of steps moved during the previous manage cycle*/
      u8Diff = LOC_au8ReqSteps[enuStepperId] - u8CurrReqSteps;


      /*! Update the Total steps required to move. */
      LOC_au16StepsToMove[enuStepperId] -= u8Diff;

      /*! Update the extra steps count and the current position*/
      if (LOC_au8ExtraStepsCount[enuStepperId] >= u8Diff)
      {
        LOC_au8ExtraStepsCount[enuStepperId] -= u8Diff;
      }
      else
      {
        u8Diff = u8Diff - LOC_au8ExtraStepsCount[enuStepperId];
        LOC_au8ExtraStepsCount[enuStepperId] = 0;
        if (Stepper_aenuMotorDirec[enuStepperId] == Stepper_ROTATE_CW)
        {

          if ((Stepper_au16FullRange[enuStepperId] -
               Stepper_au16CurrentPosition[enuStepperId]) >= u8Diff)


          {
            Stepper_au16CurrentPosition[enuStepperId] += u8Diff;
          }
          else
          {
            Stepper_au16CurrentPosition[enuStepperId] =
                Stepper_au16FullRange[enuStepperId];
          }
        }
        else
        {
          if (Stepper_au16CurrentPosition[enuStepperId] >= u8Diff)
          {
            Stepper_au16CurrentPosition[enuStepperId] -= u8Diff;
          }
          else
          {
            Stepper_au16CurrentPosition[enuStepperId] = 0;
          }
        }


      }

      /*! IF the stepper failure status is Stepper_FAIL or stop motors
          request flag is TRUE THEN */

      if ((Stepper_aenuFailureStatus[enuStepperId] == Stepper_FAIL) ||
         (Stepper_bStopMotors == TRUE))
      {
        /*! Set stop stepper flag to TRUE */
        bStopStepper = TRUE;
      }
      /*! ELSE */
      else
      {
        /*! IF remaining steps to destination is greater than 3 */
        if (LOC_au16StepsToMove[enuStepperId] > u8NUM_OF_DECEL_STEPS)
        {
          /*! If the current destination position is not equal to the requested
              destination position THEN */
          if (LOC_au16DestPosition[enuStepperId] != u16ReqDestination)
          {
            LOC_au16DestPosition[enuStepperId] = u16ReqDestination;
            /*! IF the stepper is rotating clock wise */
            if (Stepper_aenuMotorDirec[enuStepperId] == Stepper_ROTATE_CW)
            {

              /*! If the requested destination is less than or equal the
                  current position + 3 */
              if (u16ReqDestination <=
                  (Stepper_au16CurrentPosition[enuStepperId] +
                   u8NUM_OF_DECEL_STEPS))

              {
                /*! Set stop stepper flag to TRUE */
                bStopStepper = TRUE;


                /*! IF current position + 3 is less than or equal full range*/
                if ((Stepper_au16CurrentPosition[enuStepperId] +
                      u8NUM_OF_DECEL_STEPS)
                      <= Stepper_au16FullRange[enuStepperId])
                {
                  /*! Increment the current position by 3 */
                  Stepper_au16CurrentPosition[enuStepperId] +=
                      u8NUM_OF_DECEL_STEPS;
                }
                /*! ELSE */
                else
                {
                  /*! Set the current position to Full range. */
                  Stepper_au16CurrentPosition[enuStepperId] =
                      Stepper_au16FullRange[enuStepperId];
                }

              }
              /*! ELSE */
              else
              {
                /*! Calculate the steps required to move [Req Dest - curr pos]*/
                LOC_au16StepsToMove[enuStepperId] = u16ReqDestination
                                - Stepper_au16CurrentPosition[enuStepperId];
                /*! If the requested destination is Full range */
                if (u16ReqDestination == Stepper_au16FullRange[enuStepperId])
                {
                  /*! Add stalls steps to the required steps to move. */
                  LOC_au16StepsToMove[enuStepperId] +=
                      Stepper_au8OverSteps[enuStepperId];

                }
              }
            }
            /*! ELSE (Rotating CCW) */
            else
            {
              /*! IF the requested destination is greater than or equal the
               *  current position  */
              if ((u16ReqDestination + u8NUM_OF_DECEL_STEPS) >=
                  Stepper_au16CurrentPosition[enuStepperId])
              {
                /*! Set the stop stepper flag to TRUE. */
                bStopStepper = TRUE;
                /*! If current position is greater than 2 */
                if (Stepper_au16CurrentPosition[enuStepperId] >=
                    u8NUM_OF_DECEL_STEPS)
                {
                  /*! Decrement the current position by 3 */
                  Stepper_au16CurrentPosition[enuStepperId] -=
                      u8NUM_OF_DECEL_STEPS;

                }
                /*! ELSE */
                else
                {
                  /*! Set the current position to zero. */
                  Stepper_au16CurrentPosition[enuStepperId] = 0;

                }

              }
              /*! ELSE */
              else
              {
                /*! Calculate the required steps to move [current position -
                    requested destination position */
                LOC_au16StepsToMove[enuStepperId] =
                    Stepper_au16CurrentPosition[enuStepperId]
                                                    - u16ReqDestination;
                /*! IF the requested destination position is zero. */
                if (u16ReqDestination == 0)

                {
                  /*! Add stall steps. */
                  LOC_au16StepsToMove[enuStepperId] +=
                      Stepper_au8OverSteps[enuStepperId];

                }

              }
            }
          }

        }
      }

      /*! If stop stepper flag is TRUE */
      if (bStopStepper == TRUE)
      {
        /*! Set the request state to REQ_IDLE. */
        LOC_aenuReqState[enuStepperId] = REQ_IDLE;

        /* !Deviation : Inhibit MISRA rule [1006]: Assembly code used to
            disable interrupts.                                            */
        /* PRQA S 1006 ++                                                  */
        /*! Disable Interrupts */
        vidDISABLE_INTERRUPTS();

        /*! Compensate the current stepper position from the value calculate
            based on the old version of Stepper_au8ReqSteps[enuStepperId] if
            the Stepper_au8ReqSteps[enuStepperId] has change from the
            interrupt context */

        if (u8CurrReqSteps != Stepper_au8ReqSteps[enuStepperId])
        {
          if (LOC_au8ExtraStepsCount[enuStepperId] == 0)
          {
            if (Stepper_aenuMotorDirec[enuStepperId] == Stepper_ROTATE_CW)
            {
              if (Stepper_au16CurrentPosition[enuStepperId] <
                  Stepper_au16FullRange[enuStepperId])
              {
                Stepper_au16CurrentPosition[enuStepperId]++;
              }
            }
            else
            {
              if (Stepper_au16CurrentPosition[enuStepperId] != 0)
              {
                Stepper_au16CurrentPosition[enuStepperId]--;
              }

            }
          }
          else
          {
            LOC_au8ExtraStepsCount[enuStepperId]--;
          }
        }


        /*! Set the stepper requested steps to zero. */
        Stepper_au8ReqSteps[enuStepperId] = 0;


        /* !Deviation : Inhibit MISRA rule [1006]: Assembly code used to
            disable interrupts.                                             */
        /* PRQA S 1006 ++                                                   */
        /*! Enable Interrupts */
        vidENABLE_INTERRUPTS();
        /* PRQA S 1006 --                                                   */

      }
      /*! ELSE */
      else
      {
        /*! IF the stepper reached the destination position THEN */
        if (LOC_au16StepsToMove[enuStepperId] == 0)
        {
          /*! Set the request state to REQ_IDLE. */
          LOC_aenuReqState[enuStepperId] = REQ_IDLE;

          /*! IF the stall status is Stepper_STALL_ONGOING */
          if (Stepper_aenuStallStatus[enuStepperId] == Stepper_STALL_ONGOING)
          {
            /*! Set the stall status to Stepper_STALL_DONE. */
            Stepper_aenuStallStatus[enuStepperId] = Stepper_STALL_DONE;
          }

        }
        /*! ELSE */
        else
        {

          /*! IF the remaining steps to move is less than or equal to 255 THEN*/
          if (LOC_au16StepsToMove[enuStepperId] <= u8MAX_UINT8)
          {
            /*! Set the requested steps to move to the remaining steps to reach
             *  the destination */
            LOC_au8ReqSteps[enuStepperId] =
                (uint8)LOC_au16StepsToMove[enuStepperId];

          }
          else
          {
            /*! Set the requested steps to move to 255.*/
            LOC_au8ReqSteps[enuStepperId] = u8MAX_UINT8;

          }
          /* !Deviation : Inhibit MISRA rule [1006]: Assembly code used to
              disable interrupts.                                            */
          /* PRQA S 1006 ++                                                  */
          /*! Disable Interrupts */
          vidDISABLE_INTERRUPTS();

          /* PRQA S 1006 --                                                  */
          if (u8CurrReqSteps != Stepper_au8ReqSteps[enuStepperId])
          {
            Stepper_au8ReqSteps[enuStepperId] =
                LOC_au8ReqSteps[enuStepperId] - 1;

          }
          else
          {
            Stepper_au8ReqSteps[enuStepperId] = LOC_au8ReqSteps[enuStepperId];
          }
          /* !Deviation : Inhibit MISRA rule [1006]: Assembly code used to
              disable interrupts.                                             */
          /* PRQA S 1006 ++                                                   */
          /*! Enable Interrupts */
          vidENABLE_INTERRUPTS();
          /* PRQA S 1006 --                                                   */
        }

      }


      break ;

    default :
      break ;

  }

}

/* PRQA S 3006 --                                                       */



/******************************************************************************/
/*!Function : Stepper_vidControl                                              */
/*! \Description Used to drive the steppers.
    \return      void
    \Trace_To    CDD-Stepper-0145(0),CDD-Stepper-0094(0),CDD-Stepper-0144(0),
                 CDD-Stepper-0095(0),CDD-Stepper-0096(0),CDD-Stepper-0097(0),
                 CDD-Stepper-0031(0),CDD-Stepper-0037(0),CDD-Stepper-0038(0),
                 CDD-Stepper-0093(0),CDD-Stepper-0089(0),CDD-Stepper-0148(0),
                 CDD-Stepper-0088(0)
*******************************************************************************/
void Stepper_vidControl( void )
{
  const uint8 LOC_aku8MotorSeqs[u8NUM_OF_SEQ] =
  {
    u8STEPPER_SEQ_0, u8STEPPER_SEQ_I, u8STEPPER_SEQ_II, u8STEPPER_SEQ_III
  };

  const uint8 LOC_aku8AccStepTime[u8NUM_ACC_STEPS_FAST] =
  {
    u8FIRST_ACC_STEP, u8SECOND_ACC_STEP, u8THIRD_ACC_STEP
  };

  const uint8 LOC_aku8DecelStepTime[u8NUM_OF_DECEL_STEPS] =
  {
    u8FIRST_DECEL_STEP, u8SECOND_DECEL_STEP, u8THIRD_DECEL_STEP
  };

  const Elmos_tenuId LOC_akenuElmosId[Stepper_u8NUM] =
  {
    Elmos_StepperA, Elmos_StepperB, Elmos_StepperC,Elmos_StepperD,Elmos_StepperH,Elmos_StepperI,Elmos_StepperE
  };


  static uint8 LOC_au8RotateTime[Stepper_u8NUM]  =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };
  
  static uint8 LOC_au8AccDecelIndex[Stepper_u8NUM] =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };
  static uint8 LOC_au8FailCount[Stepper_u8NUM]   =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };
  static uint8 LOC_au8SuccessCount[Stepper_u8NUM]   =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0
  };

  static boolean LOC_abStopMotor[Stepper_u8NUM] =
  {
    FALSE, FALSE, FALSE,FALSE, FALSE, FALSE, FALSE
  };
  
  uint8   u8ElmosData;
  uint8   u8NumOfAccelSteps;
  uint8   u8NormalStepTime;
  boolean bSendData = FALSE;


  static uint8 LOC_au8PrevElmosData[Stepper_u8NUM] =
  {
    (uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0,(uint8)0, (uint8)0
  };
  static Stepper_tenuSpeed LOC_enuCurrentSpeed = Stepper_FAST;

  /*! If stepper Initialization is Done THEN */
  if ((Stepper_bInitDone == TRUE) && (Stepper_bControlPause == FALSE))
  {
    /*! IF the steppers check is DONE THEN */
    if (Stepper_enuCheckState == CHK_DONE)
    {
      /*! If the stepper speed is Fast */
      if (LOC_enuCurrentSpeed  == Stepper_FAST)
      {
        /*! Set the normal step time to 5 and
         the Number of Acceleration steps to 3. */
        u8NumOfAccelSteps = u8NUM_ACC_STEPS_FAST;
        u8NormalStepTime = u8STEP_TIME_FAST;

      }
      /*! Else  */
      else
      {
        /*! Set the normal step time to 8 and
         the Number of Acceleration steps to 1. */
        u8NumOfAccelSteps = u8NUM_ACC_STEPS_SLOW;
        u8NormalStepTime = u8STEP_TIME_SLOW;
      }

      /* !Deviation : Inhibit MISRA rule [3138]: Null statement due to using
          a function Macro containing braced code statement block             */
      /* PRQA S 3138 ++                                                       */
      vidCONTROL_STEPPER(Stepper_MIX_L);
      bSendData = FALSE;
      vidCONTROL_STEPPER(Stepper_MIX_R);
      bSendData = FALSE;
      vidCONTROL_STEPPER(Stepper_MODE_F);
      bSendData = FALSE;
      vidCONTROL_STEPPER(Stepper_MODE_R);
      bSendData = FALSE;
      vidCONTROL_STEPPER(Stepper_REC);
	  bSendData = FALSE;
      vidCONTROL_STEPPER(Stepper_I);
	  bSendData = FALSE;
      vidCONTROL_STEPPER(Stepper_EXV);

      /* PRQA S 3138 --                                                       */


    }
    /*! ELSE IF stepper check state is CHK_START */
    else if (Stepper_enuCheckState == CHK_START)
    {
      /*! Write all ones to the stepper */
      Elmos_vidWrite(Elmos_StepperA, 0x0F);
      Elmos_vidWrite(Elmos_StepperB, 0x0F);
      Elmos_vidWrite(Elmos_StepperC, 0x0F);
      Elmos_vidWrite(Elmos_StepperD, 0x0F);
      Elmos_vidWrite(Elmos_StepperH, 0x0F);
	  Elmos_vidWrite(Elmos_StepperI, 0x0F);
	  Elmos_vidWrite(Elmos_StepperE, 0x0F);

      /*! Set the stepper check state to CHK_STEP_1 */
      Stepper_enuCheckState = CHK_STEP_1;

    }
    /*! ELSE IF stepper check state is CHK_STEP_1 */
    else if (Stepper_enuCheckState == CHK_STEP_1)
    {
      /*! Write all zeros to the stepper */
      Elmos_vidWrite(Elmos_StepperA, 0);
      Elmos_vidWrite(Elmos_StepperB, 0);
      Elmos_vidWrite(Elmos_StepperC, 0);
      Elmos_vidWrite(Elmos_StepperD, 0);
      Elmos_vidWrite(Elmos_StepperH, 0);
	  Elmos_vidWrite(Elmos_StepperI, 0);
	  Elmos_vidWrite(Elmos_StepperE, 0);

      /*! Set the stepper check state to CHK_STEP_2 */
      Stepper_enuCheckState = CHK_STEP_2;

    }
    /*! ELSE IF stepper check state is CHK_STEP_2 */
    else if (Stepper_enuCheckState == CHK_STEP_2)
    {
      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperA);

      /*! IF the data written is not equal to all ones */
      if (u8ElmosData != 0x0F)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MIX_L] = Stepper_FAIL;
	Stepper_aenuFailureStatusFb[Stepper_MIX_L] = Stepper_FAIL;

      }

      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperB);

      /*! IF the data written is not equal to all ones */
      if (u8ElmosData != 0x0F)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MIX_R] = Stepper_FAIL;
	Stepper_aenuFailureStatusFb[Stepper_MIX_R] = Stepper_FAIL;
      }

      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperC);

      /*! IF the data written is not equal to all ones */
      if (u8ElmosData != 0x0F)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MODE_F] = Stepper_FAIL;
        Stepper_aenuFailureStatusFb[Stepper_MODE_F] = Stepper_FAIL;
      }

       /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperD);

      /*! IF the data written is not equal to all ones */
      if (u8ElmosData != 0x0F)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MODE_R] = Stepper_FAIL;
        Stepper_aenuFailureStatusFb[Stepper_MODE_R] = Stepper_FAIL;
      }

      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperH);

      /*! IF the data written is not equal to all ones */
      if (u8ElmosData != 0x0F)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_REC] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_REC] = Stepper_FAIL;
      }

	  /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperI);

      /*! IF the data written is not equal to all ones */
      if (u8ElmosData != 0x0F)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_I] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_I] = Stepper_FAIL;
      }
	  	  /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperE);

      /*! IF the data written is not equal to all ones */
      if (u8ElmosData != 0x0F)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_EXV] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_EXV] = Stepper_FAIL;
      }


      /*! Write all zeros to the stepper. */
      Elmos_vidWrite(Elmos_StepperA, 0);
      Elmos_vidWrite(Elmos_StepperB, 0);
      Elmos_vidWrite(Elmos_StepperC, 0);
      Elmos_vidWrite(Elmos_StepperD, 0);
      Elmos_vidWrite(Elmos_StepperH, 0);
	  Elmos_vidWrite(Elmos_StepperI, 0);
	  Elmos_vidWrite(Elmos_StepperE, 0);

      /*! Set the stepper check state to CHK_STEP_3. */
      Stepper_enuCheckState = CHK_STEP_3;
    }
    /*! ELSE */
    else
    {

      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperA);

      /*! IF the data written is not equal to all zeros. */
      if (u8ElmosData != 0x00)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MIX_L] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_MIX_L] = Stepper_FAIL;
      }

      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperB);

      /*! IF the data written is not equal to all zeros. */
      if (u8ElmosData != 0x00)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MIX_R] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_MIX_R] = Stepper_FAIL;
      }

      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperC);

      /*! IF the data written is not equal to all zeros. */
      if (u8ElmosData != 0x00)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MODE_F] = Stepper_FAIL;
        Stepper_aenuFailureStatusFb[Stepper_MODE_F] = Stepper_FAIL;
      }

      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperD);

      /*! IF the data written is not equal to all zeros. */
      if (u8ElmosData != 0x00)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_MODE_R] = Stepper_FAIL;
        Stepper_aenuFailureStatusFb[Stepper_MODE_R] = Stepper_FAIL;
      }


      /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperH);

      /*! IF the data written is not equal to all zeros. */
      if (u8ElmosData != 0x00)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_REC] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_REC] = Stepper_FAIL;
      }

	  /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperI);

      /*! IF the data written is not equal to all zeros. */
      if (u8ElmosData != 0x00)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_I] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_I] = Stepper_FAIL;
      }
	  /*! Read the data written to the stepper. */
      u8ElmosData = Elmos_u8Read(Elmos_StepperE);

      /*! IF the data written is not equal to all zeros. */
      if (u8ElmosData != 0x00)
      {
        /*! Set the stepper failure status to Stepper_FAIL. */
        Stepper_aenuFailureStatus[Stepper_EXV] = Stepper_FAIL;
	    Stepper_aenuFailureStatusFb[Stepper_EXV] = Stepper_FAIL;
      }

      if (Stepper_aenuFailureStatus[Stepper_REC] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatus[Stepper_REC] = Stepper_NO_FAIL;

      }

      if (Stepper_aenuFailureStatus[Stepper_MIX_L] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatus[Stepper_MIX_L] = Stepper_NO_FAIL;

      }

      if (Stepper_aenuFailureStatus[Stepper_MIX_R] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatus[Stepper_MIX_R] = Stepper_NO_FAIL;
      }

      if (Stepper_aenuFailureStatus[Stepper_MODE_F] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatus[Stepper_MODE_F] = Stepper_NO_FAIL;

      }

      if (Stepper_aenuFailureStatus[Stepper_MODE_R] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatus[Stepper_MODE_R] = Stepper_NO_FAIL;
      }
	  if (Stepper_aenuFailureStatus[Stepper_I] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatus[Stepper_I] = Stepper_NO_FAIL;

      }
	  if (Stepper_aenuFailureStatus[Stepper_EXV] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatus[Stepper_EXV] = Stepper_NO_FAIL;
	  }

      
/*feedback fail*/
      if (Stepper_aenuFailureStatusFb[Stepper_REC] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatusFb[Stepper_REC] = Stepper_NO_FAIL;

      }

      if (Stepper_aenuFailureStatusFb[Stepper_MIX_L] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatusFb[Stepper_MIX_L] = Stepper_NO_FAIL;

      }

      if (Stepper_aenuFailureStatusFb[Stepper_MIX_R] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatusFb[Stepper_MIX_R] = Stepper_NO_FAIL;

      }

      if (Stepper_aenuFailureStatusFb[Stepper_MODE_F] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatusFb[Stepper_MODE_F] = Stepper_NO_FAIL;

      }

      if (Stepper_aenuFailureStatusFb[Stepper_MODE_R] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatusFb[Stepper_MODE_R] = Stepper_NO_FAIL;

      }
	  if (Stepper_aenuFailureStatusFb[Stepper_I] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatusFb[Stepper_I] = Stepper_NO_FAIL;

      }
	  if (Stepper_aenuFailureStatusFb[Stepper_EXV] != Stepper_FAIL)
      {

        Stepper_aenuFailureStatusFb[Stepper_EXV] = Stepper_NO_FAIL;

      }
      
            /*! Write all zeros to the stepper. */
	  Elmos_vidWrite(Elmos_StepperA, 0xFF);
      Elmos_vidWrite(Elmos_StepperB, 0xFF);
      Elmos_vidWrite(Elmos_StepperC, 0xFF);
      Elmos_vidWrite(Elmos_StepperD, 0xFF);
      Elmos_vidWrite(Elmos_StepperH, 0xFF);
	  Elmos_vidWrite(Elmos_StepperI, 0xFF);
	  Elmos_vidWrite(Elmos_StepperE, 0xFF);
      
      /*! Set the stepper check state to CHK_DONE. */
      Stepper_enuCheckState = CHK_DONE;
    }

  }
  else if (Stepper_bControlPause == TRUE)
  {
	/* Fast Stop the Motors by Write data to the Elmos. */
	  Elmos_vidWrite(Elmos_StepperA, 0x0F);
      Elmos_vidWrite(Elmos_StepperB, 0x0F);
      Elmos_vidWrite(Elmos_StepperC, 0x0F);
      Elmos_vidWrite(Elmos_StepperD, 0x0F);
      Elmos_vidWrite(Elmos_StepperH, 0x0F);
	  Elmos_vidWrite(Elmos_StepperI, 0x0F);
	  Elmos_vidWrite(Elmos_StepperE, 0x0F);
  }
}



/******************************************************************************/
/* !Function    : Stepper_enuMotorState                                       */
/* !Description : This function is called to  */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]: void                                                       */
/* !Comment      :    add 20160612                                            */
/******************************************************************************/
Stepper_tenuMotorState  Stepper_enuMotorState
( Stepper_tenuStepperId enuStepperId )
{
   return Stepper_aenuMotorState[enuStepperId];
}

/******************************************************************************/
/* !Function    : Stepper_vidStartCheck                                       */
/* !Description : This function is called to                                  */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]: void                                                       */
/* !Comment      :                                                            */
/******************************************************************************/
void Stepper_vidStartCheck(void)
{
  Stepper_bInitDone = FALSE;
  Stepper_enuCheckState = CHK_START;
  Stepper_vidInit();
}

/******************************************************************************/
/* !Function    : Stepper_vidSavePosition                                     */
/* !Description : This function is called to                                  */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]: void                                                       */
/* !Comment      :                                                            */
/******************************************************************************/
void Stepper_vidSavePosition(void)
{
    uint8 u8Index;
    uint8 u8Buf[Stepper_u8NUM * 6u];
    for (u8Index = 0 ; u8Index < Stepper_u8NUM ; u8Index++)
    {
		u8Buf[u8Index * 2 + 0u]=Stepper_au16CurrentPosition[u8Index]/256;
		u8Buf[u8Index * 2 + 1u]=Stepper_au16CurrentPosition[u8Index]%256;
		u8Buf[u8Index * 2 + 2u]=Stepper_au16ReqDestPosition[u8Index]/256;
		u8Buf[u8Index * 2 + 3u]=Stepper_au16ReqDestPosition[u8Index]%256;
		u8Buf[u8Index * 2 + 4u]=Stepper_aenuMotorDirec[u8Index];
		u8Buf[u8Index * 2 + 5u]=Stepper_au8SeqIndex[u8Index];
    }
    EEP_u16WriteMultiPage(EEP_ADDR_DYN + 85, u8Buf, Stepper_u8NUM * 6u);
}

/******************************************************************************/
/* !Function    : Stepper_vidRecoverPosition                                  */
/* !Description : This function is called to  */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]: void                                                       */
/* !Comment      :                                                            */
/******************************************************************************/
void Stepper_vidRecoverPosition(void)
{
	uint8 u8Index;
	uint8 u8Buf[Stepper_u8NUM * 6u];

	EEP_u16ReadData(EEP_ADDR_DYN + 85, u8Buf, Stepper_u8NUM * 6u);
	for (u8Index = 0 ; u8Index < Stepper_u8NUM ; u8Index++)
	{
		Stepper_au16CurrentPosition[u8Index]=
		((uint16)(u8Buf[u8Index * 2 + 0u]))*256+u8Buf[u8Index * 2 + 1u];
		if(Stepper_au16CurrentPosition[u8Index] > Stepper_au16FullRange[u8Index])
		{
			Stepper_au16CurrentPosition[u8Index] = Stepper_au16FullRange[u8Index];
		}
		Stepper_au16ReqDestPosition[u8Index] = Stepper_au16CurrentPosition[u8Index];
		Stepper_aenuMotorDirec[u8Index] = 
		(Stepper_tenuRotateDirec)(u8Buf[u8Index * 2 + 4u]);
		if(Stepper_aenuMotorDirec[u8Index] > 1)
		{
			Stepper_aenuMotorDirec[u8Index] = (Stepper_tenuRotateDirec)0;
		}
		Stepper_au8SeqIndex[u8Index] = 0u;
	}
}

/******************************************************************************/
/* !Function    : Stepper_enuGetCurrentPosition                               */
/* !Description : This function is called to                                  */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]: void                                                       */
/* !Comment      :                                                            */
/******************************************************************************/
uint16 Stepper_enuGetCurrentPosition(Stepper_tenuStepperId enuStepperId)
{
  uint16 u16Temp = 0;
  
  u16Temp = ((uint32)Stepper_au16CurrentPosition[enuStepperId]) * 100 / 
	((uint32)Stepper_au16FullRange[enuStepperId]); 

  if(u16Temp>100) u16Temp=100;

  /*! If the Zero to Full range direction is CCW */
  if (Stepper_aenuZeroToFullDirec[enuStepperId] == Stepper_ROTATE_CCW)
  {
      u16Temp=100-u16Temp;
  }
  else
  {
    /*! Set the requested destination position to the converted value. */
    
  }
  
  return u16Temp;  
}/* end of Stepper_enuGetCurrentPosition()  */

/******************************************************************************/
/* !Function    : Stepper_vidClearFail                                        */
/* !Description : This function is called to                                  */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]: enuStepperId                                               */
/* !Comment      :                                                            */
/******************************************************************************/
void Stepper_vidClearFail(Stepper_tenuStepperId enuStepperId)
{
    Stepper_aenuFailureStatus[enuStepperId] = Stepper_NO_FAIL;
}

/******************************************************************************/
/* !Function    : Stepper_vidSetStallDone                                     */
/* !Description :                                                             */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]:                                                            */
/* !Comment      :                                                            */
/******************************************************************************/
void Stepper_vidSetStallDone(Stepper_tenuStepperId enuStepperId)
{
    Stepper_aenuStallStatus[enuStepperId] = Stepper_STALL_DONE;
}

/******************************************************************************/
/* !Function    : Stepper_vidGetModeFPosByLvl                                  */
/* !Description :                                                             */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]:                                                            */
/* !Comment      :                                                            */
/******************************************************************************/
uint8 Stepper_u8GetModeFPosByLvl(uint8 u8Lvl)
{
	uint8 u8Rtn = 0u;
	if (u8Lvl <= (uint8)Stepper_MODE_F_DEF)
	{
		u8Rtn = Stepper_au8ModeFLevels[u8Lvl];
	}
	return u8Rtn;
}

/******************************************************************************/
/* !Function    : Stepper_vidGetModeRPosByLvl                                  */
/* !Description :                                                             */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]:                                                            */
/* !Comment      :                                                            */
/******************************************************************************/
uint8 Stepper_u8GetModeRPosByLvl(uint8 u8Lvl)
{
        uint8 u8Rtn = 0u;
        if (u8Lvl <= (uint8)Stepper_MODE_R_FOOT)
        {
                u8Rtn = Stepper_au8ModeRLevels[u8Lvl];
        }
        return u8Rtn;
}

/******************************************************************************/
/* !Function    : Stepper_vidGetModeLvlByPos                                  */
/* !Description :                                                             */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]:                                                            */
/* !Comment      :                                                            */
/******************************************************************************/
uint8 Stepper_u8GetModeFLvlByPos(uint8 u8Pos)
{
	uint8 u8Rtn;

	if(u8Pos <= (((Stepper_au8ModeFLevels[1])
		+ (Stepper_au8ModeFLevels[0])) / 2u))
	{
		u8Rtn = (uint8)Stepper_MODE_F_VENT;
	}
	else if(u8Pos <= (((Stepper_au8ModeFLevels[2])
		+ (Stepper_au8ModeFLevels[1])) / 2u))
	{
		u8Rtn = (uint8)Stepper_MODE_F_VENTFOOT;
	}
	else if(u8Pos <= (((Stepper_au8ModeFLevels[3])
		+ (Stepper_au8ModeFLevels[2])) / 2u))
	{
		u8Rtn = (uint8)Stepper_MODE_F_FOOT;			
	}
	else if(u8Pos <= (((Stepper_au8ModeFLevels[4])
		+ (Stepper_au8ModeFLevels[3])) / 2u))
	{
		u8Rtn = (uint8)Stepper_MODE_F_FOOTDEF;				
	}
	else
	{
		u8Rtn = (uint8)Stepper_MODE_F_DEF;			
	}
	return u8Rtn;
}


/******************************************************************************/
/* !Function    : Stepper_vidGetModeRLvlByPos                                  */
/* !Description :                                                             */
/* !Trace_To    :                                                             */
/******************************************************************************/
/* !Parameter[in]:                                                            */
/* !Comment      :                                                            */
/******************************************************************************/
uint8 Stepper_u8GetModeRLvlByPos(uint8 u8Pos)
{
        uint8 u8Rtn;

        if(u8Pos <= (((Stepper_au8ModeRLevels[1])
                + (Stepper_au8ModeRLevels[0])) / 2u))
        {
                u8Rtn = (uint8)Stepper_MODE_R_VENT;
        }
        else if(u8Pos <= (((Stepper_au8ModeRLevels[2])
                + (Stepper_au8ModeRLevels[1])) / 2u))
        {
                u8Rtn = (uint8)Stepper_MODE_R_VENTFOOT;                     
        }
        else
        {
                u8Rtn = (uint8)Stepper_MODE_R_FOOT;                      
        }
        return u8Rtn;
}



/*called by App_vidFastManage every 10ms*/
void Stepper_vidLvStop(void) 
{
	Stepper_bControlPause = TRUE;
}

/*called by App_vidManage every 40ms*/
void Stepper_vidLvRecover(void) 
{
	Stepper_bControlPause = FALSE;
}


/** \} */ /* end of Stepper module group */
/** \} */ /* end of Stepper Component group */

/*-------------------------------- end of file -------------------------------*/

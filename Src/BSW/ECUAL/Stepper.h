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
/* !File            : Stepper.h                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Stepper.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:22   chunping.yan
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
 
 
 
#ifndef STEPPER_H
#define STEPPER_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define Stepper_u8NUM                    7u
#define Stepper_u8NUM_RUNPARA            42u
#define Stepper_u8NUM_MODEFLEVELS        5u
#define Stepper_u8NUM_MODERLEVELS        3u
#define Stepper_u8NUM_PARAMETERS        (Stepper_u8NUM_RUNPARA + \
                                         Stepper_u8NUM_MODEFLEVELS + \
                                         Stepper_u8NUM_MODERLEVELS)

#define Stepper_u8EEP_SIZE              (Stepper_u8NUM_RUNPARA + \
                                         Stepper_u8NUM_MODEFLEVELS + \
                                         Stepper_u8NUM_MODERLEVELS + 1u)


       
#define Stepper_MODE_F_VENT              0u
#define Stepper_MODE_F_VENTFOOT          1u
#define Stepper_MODE_F_FOOT              2u
#define Stepper_MODE_F_FOOTDEF           3u
#define Stepper_MODE_F_DEF               4u

#define Stepper_MODE_R_VENT              0u
#define Stepper_MODE_R_VENTFOOT          1u
#define Stepper_MODE_R_FOOT              2u

#define Stepper_u8POS_REC	             0u
#define Stepper_u8POS_FRE	             100u
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
#if 0
typedef enum
{
  Stepper_MIX_L,
  Stepper_MIX_R,
  Stepper_MODE_F,
  Stepper_MODE_R,
  Stepper_REC,
  Stepper_I,
  Stepper_EXV
} Stepper_tenuStepperId;
#else
typedef enum
{
  Stepper_REC,
  Stepper_MODE_F,
  Stepper_MIX_R,
  Stepper_MIX_L,
  Stepper_MODE_R,
  Stepper_I,
  Stepper_EXV
} Stepper_tenuStepperId;
#endif

typedef enum
{
  Stepper_UNKNOWN_FAIL,
  Stepper_NO_FAIL,
  Stepper_FAIL
} Stepper_tenuFailureState;


typedef enum
{
  Stepper_SLOW,
  Stepper_FAST
} Stepper_tenuSpeed;

typedef enum
{
  Stepper_STALL_INIT,
  Stepper_STALL_START,
  Stepper_STALL_ONGOING,
  Stepper_STALL_DONE
}Stepper_tenuStallState;


typedef enum
{
  Stepper_ROTATE_CW,
  Stepper_ROTATE_CCW
}Stepper_tenuRotateDirec;


typedef enum
{
  STEPPER_STOPPED,
  STEPPER_ACC,
  STEPPER_MOVING,
  STEPPER_DECEL
}Stepper_tenuMotorState;


typedef struct
{
  Stepper_tenuRotateDirec  aenuZeroToFullRangeDirec[Stepper_u8NUM];
  Stepper_tenuRotateDirec  aenuMotorDirec[Stepper_u8NUM];
  uint16  au16CurrentPosition[Stepper_u8NUM];
  uint8  au8MotorPhaseIndex[Stepper_u8NUM];
  uint16 au16Range[Stepper_u8NUM];
  uint8  au8StallSteps[Stepper_u8NUM];
  uint8  au8OverSteps[Stepper_u8NUM];
  uint8  au8ChngOfDirecSteps[Stepper_u8NUM];
} Stepper_tstrContext;


typedef struct
{
  Stepper_tenuRotateDirec aenuMotorDirec[Stepper_u8NUM];
  uint16 au16CurrentPosition[Stepper_u8NUM];
  uint8 au8MotorPhaseIndex[Stepper_u8NUM];
} Stepper_tstrDynmContext;


extern uint8   Stepper_au8ModeFLevels[7];
/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
/******************************************************************************/
/*! \Description Stepper initialization function.\n
*******************************************************************************/
extern void Stepper_vidInit( void );

/******************************************************************************/
/*! \Description Sets the speed of all motors. \n
*******************************************************************************/
extern void Stepper_vidSetSpeed(Stepper_tenuSpeed enuSpeed);

/******************************************************************************/
/*! \Description  Set context from EEPROM. \n
*******************************************************************************/
extern void Stepper_vidSetContext(const uint8* pku8Context);

/******************************************************************************/
/*! \Description  Get dynamic context for EEPROM to save it. \n
*******************************************************************************/
extern void Stepper_vidGetContext(Stepper_tstrDynmContext* pstrContext);

/******************************************************************************/
/*! \Description Sets the Motor position. \n
*******************************************************************************/
extern void Stepper_vidSetMotorPosition
(
  Stepper_tenuStepperId enuStepperId,
  uint8                 u8Position
);

/******************************************************************************/
/*! \Description Returns the failure status of the stepper. \n
*******************************************************************************/
extern Stepper_tenuFailureState Stepper_enuGetFailureState
(
  Stepper_tenuStepperId enuStepperId
);

/******************************************************************************/
/*! \Description Returns the Stalling status of the stepper. \n
*******************************************************************************/
extern Stepper_tenuStallState Stepper_enuGetStallState(
    Stepper_tenuStepperId enuStepperId);

/******************************************************************************/
/*! \Description Periodic Service called by Timer. \n
*******************************************************************************/
extern void Stepper_vidControl( void );

/******************************************************************************/
/*! \Description Starts stalling the selected stepper motor. \n
*******************************************************************************/
extern void Stepper_vidStallMotor(Stepper_tenuStepperId enuStepperId);

/******************************************************************************/
/*! \Description Request to Stop operation on all motors. \n
*******************************************************************************/
extern void Stepper_vidStopMotors( void );

/******************************************************************************/
/*! \Description Request to continue operation on all motors. \n
*******************************************************************************/
extern void Stepper_vidContinueMotors( void );

/******************************************************************************/
/*! \Description Steppers Manage Service.  \n
 ******************************************************************************/
extern void Stepper_vidManage(Stepper_tenuStepperId enuStepperId);

/*
extern uint8 Stepper_au8ModeLevels[Stepper_u8NUM_MODELEVELS] ;
*/
extern Stepper_tenuMotorState  Stepper_enuMotorState( Stepper_tenuStepperId enuStepperId );
extern void Stepper_vidStartCheck(void);
extern void Stepper_vidSavePosition(void);
extern void Stepper_vidRecoverPosition(void);
extern uint16 Stepper_enuGetCurrentPosition(Stepper_tenuStepperId enuStepperId);
extern void Stepper_vidClearFail(Stepper_tenuStepperId enuStepperId);
extern void Stepper_vidSetStallDone(Stepper_tenuStepperId enuStepperId);
extern uint8 Stepper_u8GetModeFPosByLvl(uint8 u8Lvl);
extern uint8 Stepper_u8GetModeFLvlByPos(uint8 u8Pos);
extern uint8 Stepper_u8GetModeRPosByLvl(uint8 u8Lvl);
extern uint8 Stepper_u8GetModeRLvlByPos(uint8 u8Pos);
extern void Stepper_vidLvStop(void); /*called by App_vidFastManage every 10ms*/
extern void Stepper_vidLvRecover(void); /*called by App_vidManage every 40ms*/

#endif /* STEPPER_H */

/*-------------------------------- end of file -------------------------------*/

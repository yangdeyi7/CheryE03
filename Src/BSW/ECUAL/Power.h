/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Power                                                   */
/*                                                                            */
/* !Component       : Power                                                   */
/* !Description     : Provides interface for managing power state of the ECU  */
/*                                                                            */
/* !Module          : Power                                                   */
/* !Description     : Provides interface for managing power state of the ECU  */
/*                                                                            */
/* !File            : Power.h                                                 */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Power.h-arc  $
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
 
#ifndef Power_h
#define Power_h

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define Power_enuGetIGNStateRaw()         Power_enuIGNStatusRaw

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
  Power_IGN_UNKNOWN = 0u,
  Power_IGN_OFF,
  Power_IGN_ON
} Power_tenuIGNState;

typedef enum
{
  Power_DTC_UNKNOWN= 0u,
  Power_DTC_OVERVOLTAGE,
  Power_DTC_UNDERVOLTAGE,
  Power_DTC_NORMALVOLTAGE
} Power_tenuDTCState;

typedef enum
{
  Power_LEVEL_RST = 0u,
  Power_LEVEL_LV,
  Power_LEVEL_A,
  Power_LEVEL_B,
  Power_LEVEL_C,
  Power_LEVEL_D,
  Power_LEVEL_HV
} Power_tenuPowerLevel;

typedef enum
{
  Power_STEPPERV_LO = 0u,
  Power_STEPPERV_HI
} Power_tenuStepperV;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void Power_vidInit( void ) ;
extern Power_tenuIGNState Power_enuGetIGNState(void);
extern Power_tenuDTCState Power_enuGetDTCState(void);
extern Power_tenuPowerLevel Power_enuGetPowerLevel(void);
extern void Power_vidManage(void) ;
extern uint16 Power_u16GetBatValue( void );
extern uint16 Power_u16GetIgnValue( void );
extern Power_tenuStepperV Power_enuGetStepperV(void);
extern uint8 Power_u16GetIgnSts( void );



extern Power_tenuIGNState         Power_enuIGNStatusRaw;
#endif

/*-------------------------------- end of file -------------------------------*/ 




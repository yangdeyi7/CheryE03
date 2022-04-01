/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Key                                                     */
/*                                                                            */
/* !Component       : Key                                                     */
/* !Description     : Provides interface for managing keys                    */
/*                                                                            */
/* !Module          : Key                                                     */
/* !Description     : Provides interface for managing keys                    */
/*                                                                            */
/* !File            : Key.h                                                   */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Key.h-arc  $
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
 
 
#ifndef KEY_H
#define KEY_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define Key_u8NUM_OF_KEYS         (uint8)2

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
  Key_DEF,
  Key_RDEF
} Key_tenuId;

typedef enum
{
  Key_UNKNOWN = 0u,
  Key_RELEASED,
  Key_PRESSED,
  Key_STUCK
} Key_tenuStatus;



/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void Key_vidInit( void );
extern Key_tenuStatus Key_enuGetKeyStatus( Key_tenuId enuId );
extern uint8 Key_u8GetNumOfStuckKeys( void );
extern void Key_vidManage( void );
#endif /* KEY_H */

/*-------------------------------- end of file -------------------------------*/

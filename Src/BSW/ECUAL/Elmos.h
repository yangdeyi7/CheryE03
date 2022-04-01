/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Elmos                                                   */
/*                                                                            */
/* !Component       : Elmos                                                   */
/* !Description     : Provides interface for communication with Elmos chip    */
/*                                                                            */
/* !Module          : Elmos                                                   */
/* !Description     : Provides interface for communication with Elmos chip    */
/*                                                                            */
/* !File            : Elmos.h                                                 */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Elmos.h-arc  $
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
 
 


#ifndef ELMOS_H
#define ELMOS_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


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
typedef enum
{
  Elmos_StepperA ,
  Elmos_StepperB ,
  Elmos_StepperC,
  Elmos_StepperD,
  Elmos_StepperH,
  Elmos_StepperI,
  Elmos_StepperE,
  Elmos_FORNT_DEF,
  Elmos_INCAR_FAN,
  Elmos_TBD,
  Elmos_HEAT_WIND
} Elmos_tenuId;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/






/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
extern void Elmos_vidInit( void );
extern void Elmos_vidRefresh( void );
extern void Elmos_vidWrite
(
  Elmos_tenuId enuElmosId,
  uint8        u8Value
);
extern uint8 Elmos_u8Read
(
    Elmos_tenuId enuElmosId
);

#endif /* ELMOS_H */

/*-------------------------------- end of file -------------------------------*/

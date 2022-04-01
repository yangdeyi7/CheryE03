/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : TAB                                                     */
/*                                                                            */
/* !Component       : TAB                                                     */
/* !Description     : make the table be used by cmf etc.                      */
/*                                                                            */
/* !Module          : TAB                                                     */
/* !Description     : make the table be used by cmf etc.                      */
/*                                                                            */
/* !File            : TAB.h                                                   */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Se$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/TAB.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:26   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:16   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
#ifndef TAB_H
#define TAB_H


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
typedef struct{
 sint16 x ;
 sint16 y ;
}TAB16 ;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
/******************************************************************************/
/*! \Description x increase table .
 ******************************************************************************/
/* ->x increase table */
extern sint16 LinInterpolation16(sint16 swInput, const TAB16 *patTable) ;
/******************************************************************************/
/*! \Description x decrease table  .
 ******************************************************************************/
/* ->x decrease table */
extern sint16 LinRevInterpolation16(sint16 swInput, const TAB16 *patTable);
/******************************************************************************/

extern sint16 LinInterpolationXY(sint16 s16X, sint16 s16Y, const sint16 **ps16Tab,uint8 u8Rows,uint8 u8Cols);

extern sint16 LinInterpolation16Dyn(sint16 swInput, const TAB16 *patTable, sint16 *ps16DynData) ;
extern sint16 LinRevInterpolation16Dyn(sint16 swInput, const TAB16 *patTable, sint16 *ps16DynData);

extern sint16 LinInterpolationMidPos(sint16 swInput, const sint16 *pas16Data, sint16 s16Size);  
extern sint16 LinRevInterpolationMidPos(sint16 swInput, const sint16 *pas16Data, sint16 s16Size);
extern sint16 LinInterpolationMidTab(sint16 swInput, const TAB16 *patTable, sint16 s16Size);
extern sint16 LinRevInterpolationMidTab(sint16 swInput, const TAB16 *patTable, sint16 s16Size);

#endif/* TAB_H */




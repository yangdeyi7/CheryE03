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
#ifndef STD_TAB_H
#define STD_TAB_H


/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
/*#include "Cmf.h"*/
#include "Platform_Types.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define MAX(x,y) (uint8)(((x)>(y))?(x):(y))
#define MIN(x,y) (uint8)(((x)<(y))?(x):(y))
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
    sint16 x;
    sint16 y;
}TAB16 ;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern sint16 LinInterpolation16(sint16 s16Input, const TAB16 *patTable);
extern sint16 LinInterpolationXY(sint16 s16X, sint16 s16Y, const sint16 **ps16Tab,uint8 u8Rows,uint8 u8Cols);
extern sint16 LinInterpolation16Dyn(sint16 s16Input, const TAB16 *patTable, sint16 *ps16DynData) ;


#endif


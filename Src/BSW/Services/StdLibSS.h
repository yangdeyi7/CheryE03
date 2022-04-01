/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : StdLibSS                                               */
/*                                                                            */
/* !Component       : StdLibSS                                               */
/* !Description     : Provides interface for getting the StdLibSS of software*/
/*                                                                            */
/* !Module          : StdLibSS                                               */
/* !Description     : Provides interface for getting the StdLibSS of software*/
/*                                                                            */
/* !File            : StdLibSS.h                                             */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/StdLibSS.h-arc  $
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
 
#ifndef STDLIBSS_H
#define STDLIBSS_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Platform_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*for TCC Shashi*/
#ifndef MAX
     #define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

/*get the minimum value of two values                                         */
#ifndef MIN
     #define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef MIN_MAX
	#define MIN_MAX(x,s,l)       (MIN(l,MAX(x,s)))
#endif

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/



/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
/******************************************************************************/
/*! \Description Gets the software StdLibSS.
*******************************************************************************/
extern void StdLibSS_vidDataCopyU8(uint8* pu8Dest,const uint8* pu8Src,uint16 u16Cnt);
extern void StdLibSS_vidDataSetU8(uint8* pu8Dest,uint8 u8Val,uint16 u16Cnt);
extern void StdLibSS_vidMemCpy( void *pvidDest, const void *kpvidSrc, uint16 u16Cnt );

#endif /* STDLIBSS_H */


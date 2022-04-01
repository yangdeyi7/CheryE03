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
/* !File            : StdLibSS.c                                             */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/StdLibSS.c-arc  $
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
 /******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_types.h"
#include "StdLibSS.h"

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


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void StdLibSS_vidDataCopyU8(uint8* pu8Dest,const uint8* pu8Src,uint16 u16Cnt)
{
    uint16 i = 0u;
	if ((pu8Dest != NULL_PTR) && (pu8Src != NULL_PTR))
	{
		for(i = 0u;i < u16Cnt;i++)
		{
			*(pu8Dest + i) = *(pu8Src + i);
		}
	}
}

void StdLibSS_vidDataSetU8(uint8* pu8Dest,uint8 u8Val,uint16 u16Cnt)
{
    uint16 i = 0u;
	if (pu8Dest != NULL_PTR)
	{
		for(i = 0u;i < u16Cnt;i++)
		{
			*(pu8Dest + i) = u8Val;
		}
	}		
}

void StdLibSS_vidMemCpy( void *pvidDest, const void *kpvidSrc, uint16 u16Cnt )
{
	if ((pvidDest != NULL_PTR) && (kpvidSrc != NULL_PTR))
	{  
		char* pDst = (char*)pvidDest;  
		const char* pSrc = (const char*)(kpvidSrc);  
		while (u16Cnt--)  
		{  
			*pDst = *pSrc;  
			pDst++;  
			pSrc++;  
		}  
	}
}



/** \} */ /* end of StdLibSS module group */
/** \} */ /* end of Service StdLibSS Component */

/*-------------------------------- end of file -------------------------------*/

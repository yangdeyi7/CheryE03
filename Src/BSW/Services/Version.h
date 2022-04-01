/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Version                                                 */
/*                                                                            */
/* !Component       : Version                                                 */
/* !Description     : Provides interface for getting the version of software  */
/*                                                                            */
/* !Module          : Version                                                 */
/* !Description     : Provides interface for getting the version of software  */
/*                                                                            */
/* !File            : Vension.h                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/Version.h-arc  $
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
 
#ifndef VERSION_H
#define VERSION_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define VER_u8HWNUMBER_HI	0x06
#define VER_u8HWNUMBER_LO	0x29
#define VER_u8SWNUMBER_HI	0x00
#define VER_u8SWNUMBER_LO	0x30
#define VER_u8MXNUMBER_HI	0x00
#define VER_u8MXNUMBER_LO	0x16


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
	VER_DIT_VMFSPN = 0u, 	/*F187*/
	VER_DIT_SSI,			/*F18A*/
	VER_DIT_SN,				/*F197*/
	VER_DIT_SSECUHVN,		/*F193*/
	VER_DIT_SSECUSVN,		/*F195*/
	VER_DIT_VIN,			/*F190*/
	VER_DIT_ECUDATE,		/*F18B*/	
	VER_DIT_CARDATE,		/*F1A0*/	
	VER_DIT_FIGPRINT,        /*F15A*/
	VER_DIT_BLVER           /*F14A*/
} Version_tenuDidIndType;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void Version_vidInit();
extern uint8 Version_u8GetDid(Version_tenuDidIndType enuDidInd, uint8 *pu8Data);
extern uint8 Version_u8SetDid(Version_tenuDidIndType enuDidInd, uint8 *pu8Data);
#endif /* VERSION_H_ */


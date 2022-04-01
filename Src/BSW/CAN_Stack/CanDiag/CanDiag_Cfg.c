/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : COM_CAN                                                 */
/*                                                                            */
/* !Component       : CanDiag_Cfg                                             */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !Module          : CanDiag_Cfg                                             */
/* !Description     : Can diag interface                                      */
/*                                                                            */
/* !File            : CanDiag_Cfg.c                                           */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/CO$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/COM_CAN/CanDiag/CanDiag_Cfg.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:08   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:04   chunping.yan
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
#include "CanDiag_Cfg.h"

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

const CanDiag_tstrSerSupportType CanDiag_kstrSerSupport[CANDIAG_u8SERIDNUMS] =
{
	{0x10u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x11u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x27u, 
	CANDIAG_u8SESLMT_EXTENDED_MSK/*  | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK */,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL ,
	TRUE},
	{0x28u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x3eu, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x85u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x22u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x23u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE},
	{0x2eu, 
	CANDIAG_u8SESLMT_EXTENDED_MSK /* | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK */,
	CANDIAG_u8SECLMT_LVL1 | CANDIAG_u8SECLMT_LVL2,
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE},
	{0x3du, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK ,
	//CANDIAG_u8SECLMT_LVL1,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE},
/* 	{0x2au, 
	CANDIAG_u8SESLMT_EXTENDED_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL ,
	TRUE}, */
/* 	{0x2cu, 
	CANDIAG_u8SESLMT_EXTENDED_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE}, */
	{0x14u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK ,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x19u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK,
	CANDIAG_u8SECLMT_LVL0,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	{0x2fu, 
	CANDIAG_u8SESLMT_EXTENDED_MSK,
#if 0
	CANDIAG_u8SECLMT_LVL1,
#else
	CANDIAG_u8SECLMT_LVL0,
#endif
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE},
	{0x31u, 
	CANDIAG_u8SESLMT_DEFAULT_MSK | 
	CANDIAG_u8SESLMT_EXTENDED_MSK | 
	CANDIAG_u8SESLMT_PROGRAMMING_MSK,
	CANDIAG_u8SECLMT_LVL0,
	//CANDIAG_u8SECLMT_LVL1 | CANDIAG_u8SECLMT_LVL2,
	CANDIAG_u8ADDRLMT_PHYSICAL | CANDIAG_u8ADDRLMT_FUNCTIONAL,
	TRUE},
	
	{0x34u, 
	0u/* CANDIAG_u8SESLMT_PROGRAMMING_MSK */,
	CANDIAG_u8SECLMT_LVL2,
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE},
	{0x36u, 
	0u/* CANDIAG_u8SESLMT_PROGRAMMING_MSK */,
	CANDIAG_u8SECLMT_LVL2,
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE},
	{0x37u, 
	0u/* CANDIAG_u8SESLMT_PROGRAMMING_MSK */,
	CANDIAG_u8SECLMT_LVL2,
	CANDIAG_u8ADDRLMT_PHYSICAL,
	TRUE}	
	
	
	
};


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/


/*-------------------------------- end of file -------------------------------*/

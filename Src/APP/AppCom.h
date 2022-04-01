/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : App                                                     */
/*                                                                            */
/* !Component       : AppCom                                                  */
/* !Description     : App com    interface                                    */
/*                                                                            */
/* !Module          : AppCom                                                  */
/* !Description     : App com    interface                                    */
/*                                                                            */
/* !File            : AppCom.h                                                */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/AP$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/APP/AppCom.h-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:06   chunping.yan
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

#ifndef APPCOM_H
#define APPCOM_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define AppCom_u8GetCrashSig()												   \
	GetSig_GW_BD_ACU_DirverInfo_ACU_CrashOutputStatus()  /*crash status*/
#define AppCom_u8GetCrankSig()												   \
	1//GetSig_GW_BD_SR_CabinPTCCondition_EMS_EngineStatus()  /*cranking status*/
	
/*D01*/
#define AppCom_bGetLostACUStatus()    (AppCom_bLostACUFlag)  //ACU
#define AppCom_bGetLostHUStatus()	  (AppCom_bLostHU_AC_RegFlag) //HU
//#define AppCom_bGetLostVCUStatus()	  (AppCom_bLostVCU_PT_ACPwrSpdFlag) //VCU
//#define AppCom_bGetLostBMSStatus()    (AppCom_bLostBMS_TempIsoFlag) //BMS
//#define AppCom_bGetLostESPStatus()    (AppCom_bLostESP_GeneralStatusFlag) //ESP
//#define AppCom_bGetLostIPCStatus()    (AppCom_bLostIPC_DisplayInfoFlag)  //IPC


/*M01*/
#define AppCom_bGetLostEMSStatus()    (AppCom_bLostEMSFlag)
#define AppCom_bGetLostESPStatus()    (AppCom_bLostESPFlag)
#define AppCom_bGetLostVCUStatus()    (AppCom_bLostVCUFlag)
#define AppCom_bGetLostRSCMStatus()   (AppCom_bLostRSCMFlag)
#define AppCom_bGetLostIPCStatus()    (AppCom_bLostIPCFlag)
#define AppCom_bGetLostGWStatus()     (AppCom_bLostGWFlag)


#define AppCom_bFptcCommStatus()      (AppCom_bFptCommErrFlag)
#define AppCom_bRptcCommStatus()      (AppCom_bRptCommErrFlag)
#define AppCom_bAcTpvrCommStatus()    (AppCom_bAcTpvrCommErrFlag)
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
extern boolean  AppCom_bLostEMSFlag;
extern boolean  AppCom_bLostRSCMFlag;
extern boolean  AppCom_bLostVCUFlag;
extern boolean  AppCom_bLostESPFlag;
extern boolean  AppCom_bLostIPCFlag;
extern boolean  AppCom_bLostGWFlag;
extern boolean  AppCom_bLostACUFlag;
extern boolean  AppCom_bFptCommErrFlag;
extern boolean  AppCom_bRptCommErrFlag;
extern boolean  AppCom_bAcTpvrCommErrFlag;

#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/

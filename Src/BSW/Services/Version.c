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
/* !File            : Vension.c                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/Version.c-arc  $
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
#include "Version.h"
#include "Eeprom.h"
#include "StdLibSS.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*DID data lenth*/
#define u8VMFSPNDIDNUM             (uint8)12u
#define u8SSIDIDNUM                (uint8)10u
#define u8SNDIDNUM                 (uint8)10u
#define u8SSECUHVNDIDNUM           (uint8)2u
#define u8SSECUSVNDIDNUM           (uint8)2u
#define u8VINDIDNUM                (uint8)17u
#define u8ECUMANUDATENUM           (uint8)3u
#define u8CARMANUDATENUM           (uint8)3u
#define u8FPNUM                    (uint8)10u
#define u8BLVERNUM                 (uint8)1u

/*DID EEP address*/
#define u16EEP_ADDR_TRACE_DID_VMFSPNDIDNUM		(EEP_ADDR_TRACE_DID + 0u)
#define u16EEP_ADDR_TRACE_DID_SSIDIDNUM			(u16EEP_ADDR_TRACE_DID_VMFSPNDIDNUM + u8VMFSPNDIDNUM)
#define u16EEP_ADDR_TRACE_DID_SNDIDNUM			(u16EEP_ADDR_TRACE_DID_SSIDIDNUM + u8SSIDIDNUM)
#define u16EEP_ADDR_TRACE_DID_SSECUHVNDIDNUM	(u16EEP_ADDR_TRACE_DID_SNDIDNUM + u8SNDIDNUM)
#define u16EEP_ADDR_TRACE_DID_SSECUSVNDIDNUM	(u16EEP_ADDR_TRACE_DID_SSECUHVNDIDNUM + u8SSECUHVNDIDNUM)
#define u16EEP_ADDR_TRACE_DID_VINDIDNUM			(u16EEP_ADDR_TRACE_DID_SSECUSVNDIDNUM + u8SSECUSVNDIDNUM)
#define u16EEP_ADDR_TRACE_DID_ECUMANUDATENUM	(u16EEP_ADDR_TRACE_DID_VINDIDNUM + u8VINDIDNUM)
#define u16EEP_ADDR_TRACE_DID_CARMANUDATENUM	(u16EEP_ADDR_TRACE_DID_ECUMANUDATENUM + u8ECUMANUDATENUM)

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
#if 1
/*F187 vehicleManufacturerSparePartNumberDataIdentifier*/
static const uint8 Version_aku8VMSPartNumberDID[u8VMFSPNDIDNUM] = 
{/*12 byte ASCII*/
	'M','0','1','-','8','1','1','2','0','0','0','8'
};
/*F18A systemSupplierIdentifierDataIdentifier*/
static const uint8 Version_aku8SSIDID[u8SSIDIDNUM] = 
{/*10 byte ASCII*/
	'2','A','G',' ',' ',' ',' ',' ',' ',' '
};
/*F197 SystemNameDataIdentifier*/
static const uint8 Version_aku8SNDID[u8SNDIDNUM] = 
{/*10 byte ASCII*/
	'A','C',' ',' ',' ',' ',' ',' ',' ',' '
};

/*F190 VINDataIdentifier*/
static uint8 Version_au8VINDID[u8VINDIDNUM] = 
{/*17 byte ASCII*/
	'A','B','C','D','E','F','G','0','1','2','3','4','5','6','7','8','9'
};
/*F18B ECU manu date*/
static uint8 Version_au8EcuManuDate[u8ECUMANUDATENUM] = 
{/*3 byte BCD*/
	0x17,0x11,0x17
};
/*F1A0 CAR manu date*/
static uint8 Version_au8CarManuDate[u8CARMANUDATENUM] = 
{/*3 byte BCD*/
	0x17,0x11,0x17
};


#endif

/*F193 systemSupplierECUHardwareVersionNumberDataIdentifier*/
static const uint8 Version_au8SSECUHVNDID[u8SSECUHVNDIDNUM] = 
{/*2 byte BCD*/
	VER_u8HWNUMBER_HI,VER_u8HWNUMBER_LO
};
/*F195 SystemSupplierECUSoftwareVersionNumberDataIdentifier*/
static const uint8 Version_aku8SSECUSVNDID[u8SSECUSVNDIDNUM] = 
{/*2 byte BCD*/
	VER_u8SWNUMBER_HI,VER_u8SWNUMBER_LO
};

static uint8 Version_au8FrigerPrint[u8FPNUM] = 
{/*10 byte */
    0x00u,0x18,0x07,0x10,0x00u,0x00u,0x00u,0x00u,0x00u,0x00u
};

static uint8 Version_au8BootSoftwareVersionNumberDataIdentifier[1] = 
{
	0x01
};
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
extern void Version_vidInit()
{
	/*tbd : to load params from EEP*/
	
}

extern uint8 Version_u8GetDid(Version_tenuDidIndType enuDidInd, uint8 *pu8Data)
{
	uint8 u8Rtn = 0u;
	switch (enuDidInd)
	{
		case VER_DIT_VMFSPN : 		/*F187*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_VMFSPNDIDNUM, pu8Data, u8VMFSPNDIDNUM);
			if(u8Rtn < u8VMFSPNDIDNUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_aku8VMSPartNumberDID, u8VMFSPNDIDNUM);
				u8Rtn = u8VMFSPNDIDNUM;
			}
			break;
		case VER_DIT_SSI:			/*F18A*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_SSIDIDNUM, pu8Data, u8SSIDIDNUM);
			if(u8Rtn < u8SSIDIDNUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_aku8SSIDID, u8SSIDIDNUM);
				u8Rtn = u8SSIDIDNUM;
			}
			break;
		case VER_DIT_SN:			/*F197*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_SNDIDNUM, pu8Data, u8SNDIDNUM);
			if(u8Rtn < u8SNDIDNUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_aku8SNDID, u8SNDIDNUM);
				u8Rtn = u8SNDIDNUM;
			}
			break;
		case VER_DIT_SSECUHVN:		/*F193*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_SSECUHVNDIDNUM, pu8Data, u8SSECUHVNDIDNUM);
			if (u8Rtn < u8SSECUHVNDIDNUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_au8SSECUHVNDID, u8SSECUHVNDIDNUM);
				u8Rtn = u8SSECUHVNDIDNUM;				
			}
			break;
		case VER_DIT_SSECUSVN:		/*F195*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_SSECUSVNDIDNUM, pu8Data, u8SSECUSVNDIDNUM);
			if (u8Rtn < u8SSECUHVNDIDNUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_aku8SSECUSVNDID, u8SSECUSVNDIDNUM);
				u8Rtn = u8SSECUSVNDIDNUM;
			}
			break;
		case VER_DIT_VIN:			/*F190*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_VINDIDNUM, pu8Data, u8VINDIDNUM);
			if(u8Rtn < u8VINDIDNUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_au8VINDID, u8VINDIDNUM);
				u8Rtn = u8VINDIDNUM;
			}
			break;
		case VER_DIT_ECUDATE:			/*F18B*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_ECUMANUDATENUM, pu8Data, u8ECUMANUDATENUM);
			if(u8Rtn < u8ECUMANUDATENUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_au8EcuManuDate, u8ECUMANUDATENUM);
				u8Rtn = u8ECUMANUDATENUM;
			}
			break;			
		case VER_DIT_CARDATE:			/*F1A0*/
			u8Rtn = EEP_u16ReadData(u16EEP_ADDR_TRACE_DID_CARMANUDATENUM, pu8Data, u8CARMANUDATENUM);
			if(u8Rtn < u8CARMANUDATENUM)
			{
				StdLibSS_vidDataCopyU8(pu8Data, Version_au8CarManuDate, u8CARMANUDATENUM);
				u8Rtn = u8CARMANUDATENUM;
			}
			break;				
		case VER_DIT_FIGPRINT:          /*F15A*/
			StdLibSS_vidDataCopyU8(pu8Data, Version_au8FrigerPrint, u8FPNUM);
			u8Rtn = u8FPNUM;
			break;
		case VER_DIT_BLVER:              /*F14A*/
			StdLibSS_vidDataCopyU8(pu8Data, Version_au8BootSoftwareVersionNumberDataIdentifier, u8BLVERNUM);
			u8Rtn = u8BLVERNUM;
			break;
		default :
			u8Rtn = 0u;
			break;
	}

	return u8Rtn;
}

extern uint8 Version_u8SetDid(Version_tenuDidIndType enuDidInd, uint8 *pu8Data)
{
	uint8 u8Rtn = 0u;
	switch (enuDidInd)
	{
		case VER_DIT_VIN:			/*F190*/
			EEP_u16WriteMultiPage(u16EEP_ADDR_TRACE_DID_VINDIDNUM, pu8Data, u8VINDIDNUM);
			u8Rtn = u8VINDIDNUM;		
			break;
		case VER_DIT_CARDATE:			/*F1A0*/
			EEP_u16WriteMultiPage(u16EEP_ADDR_TRACE_DID_CARMANUDATENUM, pu8Data, u8CARMANUDATENUM);
			u8Rtn = u8CARMANUDATENUM;		
			break;			
		default :
			u8Rtn = 0u;
			break;
	}
	return u8Rtn;	
}

/** \} */ /* end of Version module group */
/** \} */ /* end of Service Version Component */

/*-------------------------------- end of file -------------------------------*/

/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : App                                                     */
/*                                                                            */
/* !Component       : AppDiag                                                 */
/* !Description     : App diag interface                                      */
/*                                                                            */
/* !Module          : AppDiag                                                 */
/* !Description     : App diag interface                                      */
/*                                                                            */
/* !File            : AppDiag.c                                               */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/APP/AppDiag.c-arc  $
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

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "AppDiag.h"
#include "Eeprom.h"
#include "Power.h"
#include "CanDiag.h"
#include "CanTp.h"
#include "Elmos.h"
#include "Sensor.h"
#include "ADC.h"
#include "Stepper.h"
#include "Cmb.h"
#include "Dio.h"
#include "Blower.h"
#include "Version.h"
#include "LinIf.h"
#include "AppCom.h"
#include "StdLibSS.h"
#include "SovDrv.h"
#include "ExvDrv.h"
#include "EdcDrv.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define u8DATANUMMAX_REQ           (uint8)10u
#define u8LEN_2BYTE                (uint8)2u
#define u8LEN_1BYTE                (uint8)1u


#define u8PRSID62                  (uint8)0x62u
#define u32ENCRYPTCONSTANT	   0x30001101u
#define u32ENCRYPTMASK		   0x30001101u

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
static uint8 AppDiag_u8IoCtrlFlag;



AppDiag_tuniSendToPcDisplayData  AppDiag_uniSendToPcDisplayData;
AppDiag_tuniRecvFormPcData       AppDiag_uniRecvFormPcData;


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidReadBasicDataID(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID ,const uint8 *pu8DidData , uint8 u8DIDLen);
static void vidReadUserDataID_u16(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID ,uint16 u16DIDDta , uint8 u8DIDLen);
static void vidReadUserDataID_u8(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID ,uint8 u8DIDData , uint8 u8DIDLen);
static void vidRead22DiagServiceMulitFrameData(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID);
static uint8 u8ReadBasicDataIDGroup(CanDiag_tstrMsgContextType *pMsgContext,uint16 u16DID );
static void vidSendDataDisplayOnPc(uint8 *pu8DataPtr);
static uint8 u8ReadUserDataIDGroup(CanDiag_tstrMsgContextType *pMsgContext,uint16 u16DID );
static void vidGetDataFromPc(uint8 *pu8DataPtr);
static uint8 u8IOCtrl(uint16 u16DID, uint8 *pu8Data);

static uint32 u32SecCalcLvl1(uint32 Seed, uint32 EncryptConstant);
static uint32 u32SecCalcLvl2(uint8 *seed, uint8 length);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
static uint32 u32SecCalcLvl1(uint32 Seed, uint32 EncryptConstant)
{
	uint32   wSubSeed;//瀹氫箟鍙橀噺wSubSeed-鍥涗釜瀛楄妭
	uint32   wMiddle;//瀹氫箟鍙橀噺wMiddle-鍥涗釜瀛楄妭
	uint32   i,wLastBit,counter;//瀹氫箟鍙橀噺wLastBit-鍥涗釜瀛楄妭
	uint32   wLeft31Bits;//瀹氫箟鍙橀噺wLeft31Bits-鍥涗釜瀛楄妭
	uint32   Key;//瀹氫箟鍙橀噺Key-鍥涗釜瀛楄妭
	uint8    DB1,DB2,DB3;//瀹氫箟鍙橀噺-閮戒负涓€涓瓧鑺?
	sint32 middle;//瀹氫箟鏁村瀷鏁版嵁鍙橀噺
	
	wSubSeed = Seed;//灏嗙瀛愮殑鍊艰祴鍊肩粰鍙橀噺wSubSeed
	middle =(sint32)((EncryptConstant &0x00010000) >> 15) | 
			((EncryptConstant &0x00004000)>> 14); //鎺╃爜涓庡€间綅涓庤繍绠楋紝淇濈暀浣庡瓧鑺傚悗涓や綅
	switch ( middle ) //杩涜switch璇彞杩愮畻
	{ 
		case 0://褰搈iddle鍊间负0锛屾墽琛屼笅闈㈤€昏緫
			wMiddle = (uint32)(Seed & 0x000000ff); //绉嶅瓙涓庡€艰繘琛屼綅涓庤繍绠?
			break;//鎵ц瀹屽悗璺冲嚭
		case 1://褰搈iddle鍊间负1锛屾墽琛屼笅闈㈤€昏緫
			wMiddle = (uint32)((Seed & 0x0000ff00) >> 8); //绉嶅瓙涓庡€艰繘琛屼笌杩愮畻鍚庡彸绉?浣?
			break; //鎵ц瀹屽悗璺冲嚭
		case 2://褰搈iddle鍊间负2锛屾墽琛屼笅闈㈤€昏緫
			wMiddle= (uint32)((Seed & 0x00ff0000) >> 16); //绉嶅瓙涓庡€艰繘琛屼笌杩愮畻鍚庡彸绉?6浣?
			break;//鎵ц瀹屽悗璺冲嚭
		case 3://褰搈iddle鍊间负3锛屾墽琛屼笅闈㈤€昏緫
			wMiddle = (uint32)((Seed & 0xff000000) >> 24); //绉嶅瓙涓庡€艰繘琛屼笌杩愮畻鍚庡彸绉?4浣?
			break; //鎵ц瀹屽悗璺冲嚭
	} 
	DB1 = (uint32)((EncryptConstant & 0x000007F8) >> 3); //鎺╃爜涓庡€间綅涓庤繍绠楋紝淇濈暀浣庡瓧鑺?
	DB2 = (uint32)(((EncryptConstant & 0x7F800000) >> 23)^0xA5); //鎺╃爜涓庡€艰繘琛屼綅杩愮畻鍚庡彸绉?3浣嶏紝鍐嶄笌0xA5杩涜寮傛垨杩愮畻
	DB3 = (uint32)(((EncryptConstant & 0x003FC000) >> 14)^0x5A); //鎺╃爜涓庡€艰繘琛屼綅杩愮畻鍚庡彸绉?4浣嶏紝鍐嶄笌0x5A杩涜寮傛垨杩愮畻
	counter= (uint32)(((wMiddle ^ DB1) & DB2) + DB3 );// wMiddle涓嶥B1寮傛垨鍚庡啀涓嶥B2浣嶈繍绠楋紝鍐嶄笌DB3鐩稿姞鍚庤祴鍊肩粰counter
	for ( i = 0; i < counter; i++ ) //fou璇彞寰幆
	{ 
		wMiddle =((wSubSeed & 0x20000000)/0x20000000) ^ ((wSubSeed & 
		0x01000000)/0x01000000) ^((wSubSeed &0x2000)/0x2000) ^ ((wSubSeed & 
		0x08)/0x08);
		wLastBit = (wMiddle & 0x00000001) ; 
		wSubSeed = (uint32)(wSubSeed << 1); 
		wLeft31Bits = (uint32)(wSubSeed & 0xFFFFFFFE) ;   
		wSubSeed = (uint32)(wLeft31Bits | wLastBit); 
	} //fou寰幆涓紝鎸夌収寰幆璇彞绠楀嚭wSubSeed锛岀洿鍒癷>=counter鍋滄
	if (EncryptConstant & 0x00000002) //if璇彞鍒ゆ柇锛岃嫢琛ㄨ揪寮忎负鐪燂紝鎵ц涓嬮潰璇彞
	{ 
		wLeft31Bits=((wSubSeed & 0x00FF0000)>>16) | ((wSubSeed & 0xFF000000)>>16) | ((wSubSeed & 0x000000FF)<<24) | ((wSubSeed & 0x0000FF00)<<8); 
	} 
	else //if璇彞鍒ゆ柇锛岃嫢琛ㄨ揪寮忎负鍋囷紝鎵ц涓嬮潰璇彞
	{
		wLeft31Bits = wSubSeed;//绗竴涓猣or寰幆涓绠楃殑鍊艰祴鍊肩粰wLeft31Bits	
	}
	Key = wLeft31Bits ^ EncryptConstant;//鏈€鍚庤绠楀嚭鐨剋Left31Bits涓庢帺鐮佷綅寮傛垨寰楀埌鏈€缁圞ey
	return( Key );//杩斿洖Key鍊?
}

static uint32 u32SecCalcLvl2(uint8 *seed, uint8 length)
{
	uint8 key[4] ;
/* 	uint8 *retLen; */
	uint8 i;//瀹氫箟鍙橀噺i
	union { uint8 byte[4];//鐢虫槑涓€涓仈鍚堝彉閲?
			uint32 wort;
			}seedlokal;//瀹氫箟鍙橀噺seedlokal绫诲瀷鍙傝€冭仈鍚堝彉閲忎腑鍙橀噺
	/* The array for SEED starts with [0], the array for KEY starts with [0] */
	/* seed contains the SEED */
	/* length contains the number of bytes of seed */
	/* key contains the KEY */
	/* retLen contains the number of bytes*/
	if (seed[0] == 0 && seed[1] == 0)//if璇彞锛屽垽鏂璼eed[0]鍜宻eed[1]閫昏緫涓庤繍绠楀悗鐨勫€硷紝鑻ュ€间负0锛屾墽琛屼笅闈㈤€昏緫
	{
/* 		*retLen=0; */
	}//retLen鍊间负0
	else//鑻ュ€间负闈?锛屾墽琛屼笅闈㈤€昏緫
	{
		seedlokal.wort = ((uint32)seed[0] << 24) + ((uint32)seed[1] << 16) +((uint32)seed[2] << 8) + (uint32)seed[3];
		for (i=0; i<40; i++)//fou璇彞寰幆锛宨<40锛屽惊鐜墽琛屼笅闈㈤€昏緫锛宨>=40,璺冲嚭寰幆
		{
			if(seedlokal.wort&0x80000000)//if璇彞锛岃嫢琛ㄨ揪寮忚鍙ヤ负鐪燂紝鎵ц涓嬮潰閫昏緫
			{
				seedlokal.wort=seedlokal.wort<<1;
				seedlokal.wort=seedlokal.wort^u32ENCRYPTMASK;
			}
			else//鑻ヨ〃杈惧紡涓哄亣锛屾墽琛屼笅闈㈤€昏緫
			{
				seedlokal.wort=seedlokal.wort<<1;
			}
		}
		for(i=0;i<4;i++)//fou璇彞寰幆锛宨<4锛屽惊鐜墽琛屼笅闈㈤€昏緫锛宨>=4锛岃烦鍑哄惊鐜?
		{
			key[3-i]=(((seedlokal.byte[i] & 0x01) << 7) | ((seedlokal.byte[i] & 0x02) << 5) |
						((seedlokal.byte[i] & 0x04) << 3) | ((seedlokal.byte[i] & 0x08) << 1) |
						((seedlokal.byte[i] & 0x10) >> 1) | ((seedlokal.byte[i] & 0x20) >> 3) |
						((seedlokal.byte[i] & 0x40) >> 5) | ((seedlokal.byte[i] & 0x80) >> 7));
		}
/* 		*retLen=length; */// 杈撳嚭Key鐨勫瓧鑺傞暱搴︿负length
		for(i=0;i<4;i++)
		{
			seedlokal.byte[i] = key[i];
		}
	}
	return seedlokal.wort;//杩斿洖鐪熷疄鍊?
}



static uint8 u8IOCtrl(uint16 u16DID, uint8 *pu8Data)
{
    uint8 u8NRC = 0u;
    switch (u16DID)
    {
        case 0x6100u:


            break;

        case 0x6101u:


            break;

        case 0x6102u:
            /*MODER step set*/
            Stepper_vidSetMotorPosition(Stepper_MODE_R, pu8Data[0]);
            break;

        case 0x6103u:
            /*MODEF step set*/
            Stepper_vidSetMotorPosition(Stepper_MODE_F, pu8Data[0]);
            break;

        case 0x6104u:
            //EdcDrv_vidSetLimitPowerReq(pu8Data[0]*256 + pu8Data[1]);
            break;			
        case 0x6105u:
            //EdcDrv_vidSetRpmReq(pu8Data[0]*256 + pu8Data[1]);
            break;			
        case 0x6106u:
            /*REC step set*/
            Stepper_vidSetMotorPosition(Stepper_REC, pu8Data[0]);
            break;
        case 0x6107u:
            /*MIXL step set*/
            Stepper_vidSetMotorPosition(Stepper_MIX_L, pu8Data[0]);
            break;
        case 0x6108u:
            /*MIXR step set*/
            Stepper_vidSetMotorPosition(Stepper_MIX_R, pu8Data[0]);
            break;

        case 0x6109u:
	        SovDrv_vidSetSignalState(u8SOV1_ID,pu8Data[0]);
            break;

	case 0x610Au:
            SovDrv_vidSetSignalState(u8SOV2_ID,pu8Data[0]);
	    break;

        case 0x6150u:

	    break;

	case 0x610Bu:

	    break;

	case 0x6151u:

	    break;

	case 0x6152u:

	    break;

        case 0x94B0u:

            break;

        default:
            u8NRC = 0x31u;
            break;
    }	
    return u8NRC;
}

static void vidReadBasicDataID(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID ,const uint8 *pu8DidData , uint8 u8DIDLen)
{
	uint8 u8IndRes;
	pMsgContext->resData[pMsgContext->resDataLen] = (uint8)((u16DID & 0xff00) >> 8);
	pMsgContext->resData[pMsgContext->resDataLen + 1] = (uint8)(u16DID & 0x00ff);
	for (u8IndRes = 0u; u8IndRes < u8DIDLen; u8IndRes ++)
	{
		pMsgContext->resData[pMsgContext->resDataLen + 2 + u8IndRes] = pu8DidData[u8IndRes];
	}
}

static uint8 u8ReadBasicDataIDGroup(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID )
{
	uint8 u8NRC = 0u;
	uint16 u16ResLenData = 0u;
	uint8 au8Data[20];
	uint8 u8Len = 0u;
	switch (u16DID)
	{
		case 0xF187u:/*vehicleManufacturerSparePartNumberDataIdentifier  12byte*/
			u8Len = Version_u8GetDid(VER_DIT_VMFSPN, au8Data);
			break;
		case 0xF18Au:/*systemSupplierIdentifierDataIdentifier  10byte*/
			u8Len = Version_u8GetDid(VER_DIT_SSI, au8Data);
			break;
		case 0xF197u:/*SystemNameDataIdentifier  10byte*/
			u8Len = Version_u8GetDid(VER_DIT_SN, au8Data);
			break;
		case 0xF193u:/*systemSupplierECUHardwareVersionNumberDataIdentifier  2byte*/
			u8Len = Version_u8GetDid(VER_DIT_SSECUHVN, au8Data);
			break;
		case 0xF195u:/*SystemSupplierECUSoftwareVersionNumberDataIdentifier  2byte*/
			u8Len = Version_u8GetDid(VER_DIT_SSECUSVN, au8Data);
			break;
		case 0xF190u:/*VINDataIdentifier  17byte*/
			u8Len = Version_u8GetDid(VER_DIT_VIN, au8Data);
			break;
		case 0xF18Bu:/* */
			u8Len = Version_u8GetDid(VER_DIT_ECUDATE, au8Data);
			break;			
		case 0xF1A0u:/* */
			u8Len = Version_u8GetDid(VER_DIT_CARDATE, au8Data);
			break;	
		case 0xF15Au:/* */
			u8Len = Version_u8GetDid(VER_DIT_FIGPRINT, au8Data);
			break;	
		case 0xF14Au:/* */
			u8Len = Version_u8GetDid(VER_DIT_BLVER, au8Data);
			break;				
			
		default:
			pMsgContext->resData[0u] = 0x22u;
			u8NRC = 0x31u;
			break;
	}
	if (u8Len > 0u)
	{
		vidReadBasicDataID(pMsgContext , u16DID , au8Data , u8Len);
		u16ResLenData += (2u + u8Len);
		pMsgContext->resDataLen = pMsgContext->resDataLen + u16ResLenData;
	}
	
	return u8NRC;
}

static void vidReadUserDataID_u16(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID ,uint16 u16DIDDta , uint8 u8DIDLen)
{
	pMsgContext->resData[pMsgContext->resDataLen] = (uint8)((u16DID & 0xff00) >> 8);
	pMsgContext->resData[pMsgContext->resDataLen + 1] = (uint8)(u16DID & 0x00ff);
	pMsgContext->resData[pMsgContext->resDataLen + 2] = (uint8)((u16DIDDta & 0xff00) >> 8);
	pMsgContext->resData[pMsgContext->resDataLen + 3] = (uint8)(u16DIDDta & 0x00ff);
	pMsgContext->resDataLen += (2u + 2u);
}

static void vidReadUserDataID_u8(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID ,uint8 u8DIDData , uint8 u8DIDLen)
{
	pMsgContext->resData[pMsgContext->resDataLen] = (uint8)((u16DID & 0xff00) >> 8);
	pMsgContext->resData[pMsgContext->resDataLen + 1] = (uint8)(u16DID & 0x00ff);
	pMsgContext->resData[pMsgContext->resDataLen + 2] = u8DIDData;
	pMsgContext->resDataLen += (2u + 1u);
}

/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
static void vidSendDataDisplayOnPc(uint8 *pu8DataPtr)
{
    uint16 u16Index;
    for(u16Index = 0u; u16Index < sizeof(AppDiag_tstrSendToPcDisplayData); u16Index++)
    {
	  pu8DataPtr[u16Index] = AppDiag_uniSendToPcDisplayData.u8DataAll[u16Index];
    }
}
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/

static void vidRead22DiagServiceMulitFrameData(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID)
{
	pMsgContext->resData[pMsgContext->resDataLen] = (uint8)((u16DID & 0xff00) >> 8);
	pMsgContext->resData[pMsgContext->resDataLen + 1] = (uint8)(u16DID & 0x00ff);

	vidSendDataDisplayOnPc(&(pMsgContext->resData[pMsgContext->resDataLen + 2]));
	pMsgContext->resDataLen += (2u + sizeof(AppDiag_tstrSendToPcDisplayData));
}


static uint8 u8ReadUserDataIDGroup(CanDiag_tstrMsgContextType *pMsgContext, uint16 u16DID )
{
	uint8 u8NRC = 0u;
	uint16 u16DataTemp = 0u;
	uint8 u8DataTemp = 0u;
	switch (u16DID)
	{
		 /*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2100u:/*FL VENT   2byte*/ 
			//u16DataTemp = Sensor_s16Read(Sensor_u8FL_VENT_ID) + 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2101u:/*FL FOOT temperature  2byte*/
			//u16DataTemp = Sensor_s16Read(Sensor_u8FL_FOOT_ID) + 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2102u:/*FR VENT temperature  2byte*/
			//u16DataTemp = Sensor_s16Read(Sensor_u8FR_VENT_ID) + 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2103u:/*FR FOOT temperature  2byte*/
			//u16DataTemp = Sensor_s16Read(Sensor_u8FR_FOOT_ID) + 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2104u:/*Evaporator temperature  2byte*/
			//u16DataTemp = Sensor_s16Read(Sensor_u8EVAP_ID) + 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2105u:/*AMB temperature  2byte*/
			//u16DataTemp = Sensor_s16Read(Sensor_u8AMB_ID) + 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2106u:/*WATER temperature  2byte*/
			//u16DataTemp = Sensor_s16Read(Sensor_u8WATER_ID)+ 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
		case 0x2107u:/*Solar_L  2byte*/

			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x2108u:/*AC_PressSensor  2byte*/
			//u16DataTemp = Sensor_s16Read(Sensor_u8PRE_ID) + 400U;
			vidReadUserDataID_u16(pMsgContext , u16DID , u16DataTemp , u8LEN_2BYTE);
			break;
			

	    /*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 		
		case 0x2109u:/*ModeF motor step  1byte*/
			u8DataTemp = Stepper_enuGetCurrentPosition(Stepper_MODE_F);
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x210Au:/*ModeR motor step  1byte*/
			u8DataTemp = Stepper_enuGetCurrentPosition(Stepper_MODE_R);
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x210Bu:/*Recycle motor pos  1byte*/
			u8DataTemp = Stepper_enuGetCurrentPosition(Stepper_REC);
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x210Cu:/*Mix_R motor step   1byte*/
			u8DataTemp = Stepper_enuGetCurrentPosition(Stepper_MIX_R);
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x210Du:/*Mix_L motor step   1byte*/
			u8DataTemp = Stepper_enuGetCurrentPosition(Stepper_MIX_L);
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;

			
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 	
		case 0x210Eu:/*BlowerF feedback voltage  1byte*/
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 
		case 0x210Fu:/*BlowerR feedback voltage  1byte*/
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;

			
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 	
		case 0x2110u:/*AC_W-PTC power  1byte*/
			
			break;
			
		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet */ 	
		case 0x2111u:/*AC_A-PTC power set  1byte*/

			break;

		/*refer M01_Questionnaires for Diagnostic_UDSonCAN_AC_V2.2_20180528 DynamicData DID sheet*/ 	
		case 0x2112u:/*3W valve pos_set  1byte*/

			break;
		case 0x2113u:/*AC_SolarSensor  2byte*/

			break;
		case 0x6100u:/*Blower_F PWM*/
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break;
		case 0x6101u:/*Blower_R PWM*/
			vidReadUserDataID_u8(pMsgContext , u16DID , u8DataTemp , u8LEN_1BYTE);
			break; 	
		case 0x6102u:/*Rear mode*/

			break;
		case 0x6103u:/*front mode*/

			break;	
		case 0x6104u:/*front ptc level*/

			break;	
		case 0x6105u:/*rear ptc level*/

			break;	
		case 0x6106u:/*rec pos*/

			break;	
		case 0x6107u:/*mix l pos*/

			break;	
		case 0x6108u:/*mix r pos*/

			break;
		case 0x6109u:/*3W valve pos:real pos*/

			break;
			
		case 0x21FEu : /*read EDC status*/

			break;			
		case 0x21FFu:
			vidRead22DiagServiceMulitFrameData(pMsgContext , u16DID);
			break;
		default:
			pMsgContext->resData[0u] = 0x22u;
			u8NRC = 0x31u;
			break;
	}
	return u8NRC;
}


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/   
/*Rx indication function definition                                           */
/******************************************************************************/
/*SID=0x22 :ReadDataByIdentifier*/
uint8 AppDiag_u8ReadDataByIdentifier(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint8 u8NRC = 0u;
	uint16 u16DID[u8DATANUMMAX_REQ] = {0u};
	uint16 u16Lenth = 0u;
	uint8 u8Ind;
	if((pMsgContext->reqDataLen >= 3u) && (pMsgContext->reqDataLen % 2 == 1u))
	{
		/*do nothing*/
	}
	else
	{
		u8NRC = 0x13u; /*Length wrong*/
	}
	u16Lenth = (pMsgContext->reqDataLen - 1u) / 2u;
	
	if (u16Lenth >= u8DATANUMMAX_REQ)
	{
		u8NRC = 0x31u;/*invalid size*/
	}
	else
	{
		for (u8Ind = 0u; u8Ind < u16Lenth; u8Ind++)
		{
			u16DID[u8Ind] = ((uint16)(pMsgContext->reqData[2 * u8Ind + 1])<<8) | \
							((uint16)(pMsgContext->reqData[2 * u8Ind + 2]));
		}
		for(u8Ind = 0u; u8Ind < u16Lenth; u8Ind++)
		{
			if(((u16DID[u8Ind] >= 0xF180u) && (u16DID[u8Ind] <= 0xF1A0u))||
				((u16DID[u8Ind] >= 0x0100u) && (u16DID[u8Ind] <= 0xEFFFu))||
				((u16DID[u8Ind] >= 0xF100u) && (u16DID[u8Ind] <= 0xF17Fu)))
				{
					/*do nothing*/
				}
			else
			{
				u8NRC = 0x31u;
			}
		}

	}
	
	if(u8NRC == 0x00u)
	{
		for (u8Ind = 0u; u8Ind < u16Lenth; u8Ind++)
		{
			u16DID[u8Ind] = ((uint16)(pMsgContext->reqData[2 * u8Ind + 1])<<8) | \
							((uint16)(pMsgContext->reqData[2 * u8Ind + 2]));
		}
		/*Data handling*/
		pMsgContext->resData[0u] = u8PRSID62;
		pMsgContext->resDataLen = 1u;
		for(u8Ind = 0u; u8Ind < u16Lenth; u8Ind++)
		{
			if((u16DID[u8Ind] >= 0xF180u) && (u16DID[u8Ind] <= 0xF1A0u))
			{
				/*Commom DIDs (0xF180 - 0xF19F)*/
				u8NRC = u8ReadBasicDataIDGroup(pMsgContext , u16DID[u8Ind]);
			}
			else if((u16DID[u8Ind] >= 0x0100u) && (u16DID[u8Ind] <= 0xEFFFu))
			{
				/*VehicleManufactureSpecific (0x0100 - 0xEFFF)*/
				u8NRC = u8ReadUserDataIDGroup(pMsgContext , u16DID[u8Ind]);
			}
			else if((u16DID[u8Ind] >= 0xF100u) && (u16DID[u8Ind] <= 0xF17Fu))
			{
				/*IdentificationOptionVehicleManufacturerSpecific*/
				u8NRC = u8ReadBasicDataIDGroup(pMsgContext , u16DID[u8Ind]);
			}
			else
			{
				pMsgContext->resData[0u] = 0x22u;
				u8NRC = 0x31u;
			}
		}
	}


	return u8NRC;
}

/*service ID=0x23*/
uint8 AppDiag_u8ReadMemoryByAddress(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint32 u32Address = 0x00000000u;
	uint16 u16Size = 0u;
	uint8 u8NRC = 0u;
	uint8 u8PositiveResponseServiceIdentifier = 0x63u;
	if(pMsgContext->reqDataLen == 8u)
	{
		/*do nothing*/
	}
	else
	{
		u8NRC = 0x13u; /*Length wrong*/
	}
	
	
	if(0x24u != pMsgContext->reqData[1])
	{
		/* A negativ response will be generated (only 0x24 supported) */
		u8NRC = 0x22u;
	}
	/* Get the data length which should be Read  */
	u32Address  = 
		(pMsgContext->reqData[2] << 24) + 
		(pMsgContext->reqData[3] << 16) +
		(pMsgContext->reqData[4] << 8) +
		pMsgContext->reqData[5];
	if (u32Address > EEP_ADDR_EEPMAXADDR)
	{
		if (u8NRC == 0u)
		{
			u8NRC = 0x31u; /*invalid address*/
		}
	}
	/*get size*/
	u16Size = (pMsgContext->reqData[6] << 8) + pMsgContext->reqData[7];
	if (u16Size > (CANTP_u16BUFLEN_MAX - 1u))
	{
		if (u8NRC == 0u)
		{
			u8NRC = 0x31u; /*invalid size*/
		}
	}
	
	if (u8NRC == 0u)
	{
		/*1st step : do something*/
			/*nothing need to do*/
		/*2st step : positive response*/
		pMsgContext->resData[0] = u8PositiveResponseServiceIdentifier;
		EEP_u16ReadData(u32Address, &(pMsgContext->resData[1]), u16Size);
		pMsgContext->resDataLen = u16Size + 1u; 
	}

	return u8NRC;
}


/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
static void vidGetDataFromPc(uint8 *pu8DataPtr)
{
    uint8 u8Index;
    for(u8Index = 0u; u8Index < sizeof(AppDiag_tstrRecvFormPcData); u8Index++)
    {
      AppDiag_uniRecvFormPcData.u8DataAll[u8Index] = pu8DataPtr[u8Index];
    }
}
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/


/*service ID=0x3D*/
uint8 AppDiag_u8WriteMemoryByAddress(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint32 u32Address = 0x00000000u;
	uint16 u16Size = 0u;
	uint8 u8NRC = 0u;
	uint8 u8PositiveResponseServiceIdentifier = 0x7Du;
	uint16 u16Datalen;
	
	if(0x24u != pMsgContext->reqData[1])
	{
		/* A negativ response will be generated (only 0x24 supported) */
		u8NRC = 0x22u;
	}
	/* Get the data length which should be Read  */
	u32Address  = 
		(pMsgContext->reqData[2] << 24) + 
		(pMsgContext->reqData[3] << 16) +
		(pMsgContext->reqData[4] << 8) +
		pMsgContext->reqData[5];
	if (u32Address > EEP_ADDR_EEPMAXADDR)
	{
		if (u8NRC == 0u)
		{
			u8NRC = 0x31u; /*invalid address*/
		}
	}
	/*get size*/
	u16Size = (pMsgContext->reqData[6] << 8) + pMsgContext->reqData[7];
	if (u16Size > (CANTP_u16BUFLEN_MAX - 1u))
	{
		if (u8NRC == 0u)
		{
			u8NRC = 0x31u; /*invalid size*/
		}
	}
	
	if(pMsgContext->reqDataLen >= 8u)
	{
		/*do nothing*/
	}
	else
	{
		u8NRC = 0x13u; /*Length wrong*/
	}
	
	if (u8NRC == 0u)
	{
		/*1st step : do something*/
		/*write to EEP*/
		//u16Datalen = EEP_u16WriteMultiPage(u32Address,&(pMsgContext->reqData[8]), u16Size);
	        u16Datalen = u16Size;
	        vidGetDataFromPc(&(pMsgContext->reqData[8]));
		/*2st step : positive response*/
		pMsgContext->resData[0] = u8PositiveResponseServiceIdentifier;
		/*pMsgContext->resData[1] = 0x24u; */ /*sub function*/
		/*pMsgContext->resData[2] = */
		/*pMsgContext->resData[3] = */
		/*pMsgContext->resData[4] = */
		/*pMsgContext->resData[5] = */
		pMsgContext->resData[6] = (u16Datalen / 256u);
		pMsgContext->resData[7] = (u16Datalen % 256u);		
		pMsgContext->resDataLen = 8u; 
	}

	return u8NRC;	
}

void AppDiag_vidECUResetPost(void)
{

	for (;;)
	{
		
	}
	
}

void AppDiag_vidClearIoCtrlFlag(void)
{
	AppDiag_u8IoCtrlFlag = STD_OFF;
}

uint8 AppDiag_u8GetIoCtrlFlag(void)
{
	return AppDiag_u8IoCtrlFlag;
}

void AppDiag_vidInit(void)
{
	AppDiag_u8IoCtrlFlag = STD_OFF;

	StdLibSS_vidDataSetU8(AppDiag_uniSendToPcDisplayData.u8DataAll,0,sizeof(AppDiag_tstrSendToPcDisplayData));

	StdLibSS_vidDataSetU8(AppDiag_uniRecvFormPcData.u8DataAll,0,sizeof(AppDiag_tstrRecvFormPcData));
}

/*service ID=0x2E WriteDataByIdentifier*/
uint8 AppDiag_u8WriteDataByIdentifier(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint16 u16WriteDID;
	uint8 u8NRC = 0u;
	u16WriteDID = ((uint16)(pMsgContext->reqData[1]) << 8) | ((uint16)(pMsgContext->reqData[2]));
	if((u16WriteDID == 0xF190u))
	{
		if((pMsgContext->reqDataLen == 20))
		{
			/*do nothing*/
		}
		else
		{
			u8NRC = 0x13u;
		}
	}
	if((u16WriteDID == 0xF1A0u))
	{
		if((pMsgContext->reqDataLen == 6))
		{
			/*do nothing*/
		}
		else
		{
			u8NRC = 0x13u;
		}
	}
	if(u8NRC == 0x0u)
	{
		switch(u16WriteDID)
		{
			case 0xF190u:/*VINDataIdentifier  17byte*/
				Version_u8SetDid(VER_DIT_VIN, &(pMsgContext->reqData[3]));
				break;
			case 0xF1A0u:/*car manu date  3byte*/
				Version_u8SetDid(VER_DIT_CARDATE, &(pMsgContext->reqData[3]));
				break;			
			default:
				u8NRC = 0x31u;
				break;
		}
	}
	
	if(pMsgContext->reqDataLen >= 3u)
	{
		/*do nothing*/
	}
	else
	{
		u8NRC = 0x13u; /*Length wrong*/
	}
	
	if(u8NRC == 0u)
	{
		/*feedback */
		pMsgContext->resData[0] = 0x6E;
		pMsgContext->resData[1] = (uint8)(u16WriteDID >> 8);
		pMsgContext->resData[2] = (uint8)u16WriteDID;
		pMsgContext->resDataLen = 3;
	}

	return u8NRC;
}

/*service ID=0x2F*/
uint8 AppDiag_u8InputOutputControlByIdentifier(CanDiag_tstrMsgContextType *pMsgContext)
{
	uint8 u8NRC = 0u;
	uint16 u16DID;
	u16DID = (pMsgContext->reqData[1] << 8) + pMsgContext->reqData[2];

	if (pMsgContext->reqData[3] == 0x03u)
	{
		AppDiag_u8IoCtrlFlag = STD_ON;
	}
	else
	{
		/*return control to ECU*/
		AppDiag_u8IoCtrlFlag = STD_OFF;
	}
	if (AppDiag_u8IoCtrlFlag == STD_ON)
	{
		u8NRC = u8IOCtrl(u16DID,&(pMsgContext->reqData[4]));
	}
	
	
	if(pMsgContext->reqDataLen == 5u)
	{
		/*do nothing*/
	}
	else
	{
		u8NRC = 0x13u; /*Length wrong*/
	}
	
	if((pMsgContext->reqData[3] == 0x00u)||(pMsgContext->reqData[3] == 0x03u))
	{
		
	}
	else
	{
		u8NRC = 0x31u; /*no supported*/
	}
	if (u8NRC == 0u)
	{
		/*1st step : do something*/

		/*2st step : positive response*/
		pMsgContext->resData[0] = 0x6Fu;
		/*pMsgContext->resData[1] = */ 
		/*pMsgContext->resData[2] = */
		/*pMsgContext->resData[3] = */
		if (AppDiag_u8IoCtrlFlag == STD_ON)
		{
			/*pMsgContext->resData[4] = */
			pMsgContext->resDataLen = 5u; 
		}
		else
		{
			pMsgContext->resData[4] = 0xFF;
			pMsgContext->resDataLen = 5u; 
		}
	}
	return u8NRC;	
}

boolean AppDiag_bCheckKey(uint8 u8Lvl, uint8* pau8Seeds, uint8* pau8Key)
{
	boolean bRtn = TRUE;
	uint32 u32Key;
	uint32 u32Tmp;

	if (u8Lvl == CANDIAG_u8SECLMT_LVL1)
	{
		u32Tmp = ((uint32)(pau8Seeds[0]) << 24) + 
			((uint32)(pau8Seeds[1]) << 16) +
			((uint32)(pau8Seeds[2]) << 8) + (uint32)(pau8Seeds[3]);
		u32Key = u32SecCalcLvl1(u32Tmp, u32ENCRYPTCONSTANT);
	}
	else if (u8Lvl == CANDIAG_u8SECLMT_LVL2)
	{
		u32Key = u32SecCalcLvl2(pau8Seeds, 4);			
	}
	u32Tmp = ((uint32)(pau8Key[0]) << 24) + 
		((uint32)(pau8Key[1]) << 16) +
		((uint32)(pau8Key[2]) << 8) + (uint32)(pau8Key[3]);
	if (u32Key != u32Tmp)
	{
		bRtn = FALSE;
	}

	return bRtn;
}

boolean AppDiag_bPreConditionCheck(uint8 u8SerId)
{
	boolean bRtn = TRUE;
	if (u8SerId == 0x28u) /*communication control*/
	{
		/*vspd check*/
		if (/*GetSig_GW_BD_ESP_GeneralStatus_ESP_VehicleSpeed()*/1 > 0u)
		{
			bRtn = FALSE;
		}
		/*rpm check*/
		
		/*other check*/
	}
	else if (u8SerId == 0x31u) /*RoutineControl*/
	{
		/*vspd check*/
		if (/*GetSig_GW_BD_ESP_GeneralStatus_ESP_VehicleSpeed()*/1 > 0u)
		{
			bRtn = FALSE;
		}
		/*cranking check*/
		if (AppCom_u8GetCrankSig() == 0x02u) /*crank*/
		{
			bRtn = FALSE;			
		}
		/*power voltage check*/
		if (Power_enuGetPowerLevel() < Power_LEVEL_B)
		{
			bRtn = FALSE;			
		}
		/*rpm check*/
		
	}
	return bRtn;
}
/*-------------------------------- end of file -------------------------------*/

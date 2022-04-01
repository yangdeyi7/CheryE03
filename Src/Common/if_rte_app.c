/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "CanIf_Cfg.h"
#include "if_rte_app.h"
#include "Can_Hdl.h"
#include "can_upper.h"
#include "dbc2struct.h"
#include "EdcDrv.h"
#include "Sensor.h"
#include "PtcDrv.h"
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
static  uint8 Loc_u8OFFKey;
static  uint8 Loc_u8AutoKey;
static  uint8 Loc_u8AcKey;
static  uint8 Loc_u8BlwKey;
static  uint8 Loc_u8IntakeKey;
static  uint8 Loc_u8ModeVKey;
static  uint8 Loc_u8ModeFKey;
static  uint8 Loc_u8ModeDKey;
static  uint8 Loc_u8TsetLKey;
static  uint8 Loc_u8TsetRKey;
static  uint8 Loc_u8SyncKey;

static  uint8 Loc_u8OFFDisplay;
static  uint8 Loc_u8AutoDisplay;
static  uint8 Loc_u8AcDisplay;
static  uint8 Loc_u8BlwDisplay;
static  uint8 Loc_u8IntakeDisplay;
static  uint8 Loc_u8ModeDisplay;
static  uint8 Loc_u8TsetLDisplay;
static  uint8 Loc_u8TsetRDisplay;
static  uint8 Loc_u8SyncDisplay;
/******************************************************************************/
/* LOCAL DATA DEFINITION                                                      */
/******************************************************************************/
/******************************************************************************/
/* GLOBAL DATA DEFINITION                                                     */
/******************************************************************************/
void IfRteApp_Set_ACSts( uint8 idata );
uint8 IfRteApp_Get_ACSts(void);
/********************GET KEY STATE*******************/
void IfRteApp_Set_DataFromCAN(void);
uint8 IfRteApp_Get_OFFStsFromCAN(void);
uint8 IfRteApp_Get_AutoStsFromCAN(void);
uint8 IfRteApp_Get_ACStsFromCAN(void);
uint8 IfRteApp_Get_BlwStsFromCAN(void);
uint8 IfRteApp_Get_IntakeStsFromCAN(void);
uint8 IfRteApp_Get_ModeVStsFromCAN(void);
uint8 IfRteApp_Get_ModeFStsFromCAN(void);
uint8 IfRteApp_Get_ModeDStsFromCAN(void);
uint8 IfRteApp_Get_TsetLStsFromCAN(void);
uint8 IfRteApp_Get_TsetRStsFromCAN(void);
/***********************END**************************/
void IfRteApp_CANSend(void);
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void IfRteApp_Set_WorkSts( uint8 idata )
{
	Loc_u8OFFDisplay = idata;
}
uint8 IfRteApp_Get_WorkSts(void)
{
	return ( Loc_u8OFFDisplay );
}

void IfRteApp_Set_ACSts( uint8 idata )
{
	Loc_u8AcDisplay = idata;
}
uint8 IfRteApp_Get_ACSts(void)
{
	return ( Loc_u8AcDisplay );
}

void IfRteApp_Set_AutoSts( uint8 idata )
{
	Loc_u8AutoDisplay = idata;
}
uint8 IfRteApp_Get_AutoSts(void)
{
	return ( Loc_u8AutoDisplay );
}

void IfRteApp_Set_BlwSts( uint8 idata )
{
	Loc_u8BlwDisplay = idata;
}
uint8 IfRteApp_Get_BlwSts(void)
{
	return ( Loc_u8BlwDisplay );
}

void IfRteApp_Set_IntakeSts( uint8 idata )
{
	Loc_u8IntakeDisplay = idata;
}
uint8 IfRteApp_Get_IntakeSts(void)
{
	return ( Loc_u8IntakeDisplay );
}

void IfRteApp_Set_ModeSts( uint8 idata )
{
	Loc_u8ModeDisplay = idata;
}
uint8 IfRteApp_Get_ModeSts(void)
{
	return ( Loc_u8ModeDisplay );
}

void IfRteApp_Set_TsetRSts( uint8 idata )
{
	Loc_u8TsetRDisplay = idata;
}
uint8 IfRteApp_Get_TsetRSts(void)
{
	return ( Loc_u8TsetRDisplay );
}

void IfRteApp_Set_TsetLSts( uint8 idata )
{
	Loc_u8TsetLDisplay = idata;
}
uint8 IfRteApp_Get_TsetLSts(void)
{
	return ( Loc_u8TsetLDisplay );
}

void IfRteApp_Set_SyncSts( uint8 idata )
{
	Loc_u8SyncDisplay = idata;
}
uint8 IfRteApp_Get_SyncSts(void)
{
	return ( Loc_u8SyncDisplay );
}
int speed_test=0;
uint8 IfRteApp_Get_CarSpeedFromCAN(void)
{
    uint16 u16idata;
    u16idata = (uint16)can_read_singal_with_index(CanSingalIndex_VehicleSpeedVSOSig); 
    speed_test = u16idata;
    if(u16idata > (uint16)250)
    {
      u16idata = 250u;
    }
	return ( (uint8)u16idata );
}

sint16 IfRteApp_Get_BMSInletFromCAN(void)
{
    sint16 s16idata;
    s16idata = (sint16)can_read_singal_with_index(CanSingalIndex_BMS_WaterTemp_Inlet); 
	return ( s16idata );
}
sint16 IfRteApp_Get_BMSOutletFromCAN(void)
{
    sint16 s16idata;
    s16idata = (sint16)can_read_singal_with_index(CanSingalIndex_BMS_WaterTemp_Outlet); 
	return ( s16idata );
}
sint16 IfRteApp_Get_BMSInletTargetFromCAN(void)
{
    sint16 s16idata;
    s16idata = (sint16)can_read_singal_with_index(CanSingalIndex_BMS_WaterTemp_InletTarget); 
	return ( s16idata );
}
uint8 IfRteApp_Get_BMSRequestLevelFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_BMS_HeatRequest_Mode); 
	return ( u8idata );
}

sint16 IfRteApp_Get_BMSTmaxFromCAN(void)
{
    sint16 s16idata;
    s16idata = (sint16)can_read_singal_with_index(CanSingalIndex_BMS_HighestBattTemp); 
	return ( s16idata );
}
sint16 IfRteApp_Get_BMSTavrFromCAN(void)
{
    sint16 s16idata;
    s16idata = (sint16)can_read_singal_with_index(CanSingalIndex_BMS_AverageBattTemp); 
	return ( s16idata );
}
sint16 IfRteApp_Get_BMSTminFromCAN(void)
{
    sint16 s16idata;
    s16idata = (sint16)can_read_singal_with_index(CanSingalIndex_BMS_LowestBattTemp); 
	return ( s16idata );
}
uint8 IfRteApp_Get_DCDCReqFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_DCDC_CoolingReq); 
	return ( u8idata );
}
uint8 IfRteApp_Get_OBCCoolingReqFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_OBC_CoolingReq); 
	return ( u8idata );
}
uint8 IfRteApp_Get_ADCCFlowReqFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_ADCC_CoolantFlowReq); 
	return ( u8idata );
}
uint8 IfRteApp_Get_TMFFlowReqFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_TMF_CoolantFlowReq); 
	return ( u8idata );
}
uint8 IfRteApp_Get_TMRFlowReqFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_TMR_CoolantFlow); 
	return ( u8idata );
}
uint8 IfRteApp_Get_EACAllowFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_VCC_EACAllow); 
	return ( u8idata );
}
uint8 IfRteApp_Get_HVHAllowFromCAN(void)
{
    uint8 u8idata;
    u8idata = (uint8)can_read_singal_with_index(CanSingalIndex_VCC_HVHAllow); 
	return ( u8idata );
}
/***************这里的内容完全可以放到每个按jian单独读取状态的get函数中********************/
void IfRteApp_Set_DataFromCAN(void)
{
#if 0
   Loc_u8OFFKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key7Sts); 
   Loc_u8AutoKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key8Sts);    
   Loc_u8AcKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key14Sts);   
   Loc_u8BlwKey = (uint8)can_read_singal_with_index(CanSingalIndex_BlowLevelPlusMinusSts);    
   Loc_u8IntakeKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key10Sts);   
   Loc_u8ModeVKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key17Sts);   
   Loc_u8ModeFKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key18Sts);   
   Loc_u8ModeDKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key19Sts);   
   Loc_u8TsetLKey = (uint8)can_read_singal_with_index(CanSingalIndex_LeftTempPlusMinusSts);  
   Loc_u8TsetRKey = (uint8)can_read_singal_with_index(CanSingalIndex_RightTempPlusMinusSts);  
   Loc_u8SyncKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key13Sts); 
#else
   Loc_u8OFFKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_SetCLMOn); 
   Loc_u8AutoKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_SetAutoKeySts);    
   Loc_u8AcKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_SetACRequestKeySts);   
   Loc_u8BlwKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_BlowSpeedLevelKeySts);    
   Loc_u8IntakeKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_SetCirculationModeKeySts);   
   Loc_u8ModeVKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_ModeAdjustKeySts);   
   Loc_u8ModeFKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key18Sts);   
   Loc_u8ModeDKey = (uint8)can_read_singal_with_index(CanSingalIndex_Key19Sts);   
   Loc_u8TsetLKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_SetTemperature_L_C);  
   Loc_u8TsetRKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_SetTemperature_R_C);  
   Loc_u8SyncKey = (uint8)can_read_singal_with_index(CanSingalIndex_HU_ZoneSelectionKeySts);
#endif   
}

uint8 IfRteApp_Get_OFFStsFromCAN(void)
{
	return (Loc_u8OFFKey);
}
uint8 IfRteApp_Get_AutoStsFromCAN(void)
{
	return (Loc_u8AutoKey);
}
uint8 IfRteApp_Get_ACStsFromCAN(void)
{
	return (Loc_u8AcKey);
}
uint8 IfRteApp_Get_BlwStsFromCAN(void)
{
	return (Loc_u8BlwKey);
}
uint8 IfRteApp_Get_IntakeStsFromCAN(void)
{
	return (Loc_u8IntakeKey);
}
uint8 IfRteApp_Get_ModeVStsFromCAN(void)
{
	return (Loc_u8ModeVKey);
}
uint8 IfRteApp_Get_ModeFStsFromCAN(void)
{
	return (Loc_u8ModeFKey);
}
uint8 IfRteApp_Get_ModeDStsFromCAN(void)
{
	return (Loc_u8ModeDKey);
}
uint8 IfRteApp_Get_TsetLStsFromCAN(void)
{
	return (Loc_u8TsetLKey);
}
uint8 IfRteApp_Get_TsetRStsFromCAN(void)
{
	return (Loc_u8TsetRKey);
}
uint8 IfRteApp_Get_SyncStsFromCAN(void)
{
	return (Loc_u8SyncKey);
}

static void IfRteApp_CLM_1_DataRefresh(void)
{
    can_write_singal_with_index(CanSingalIndex_ExternalTemperature_F,((float)Sensor_s16Read(Sensor_u8AMB)/10));
    can_write_singal_with_index(CanSingalIndex_ExternalTemperature_C,((float)Sensor_s16Read(Sensor_u8AMB)/10));
    can_write_singal_with_index(CanSingalIndex_ExternalTemperatureFailSts,(float)0);
    can_write_singal_with_index(CanSingalIndex_Reserved_AC_MaxSts,(float)0);
    can_write_singal_with_index(CanSingalIndex_ACRequestCommand,(float)0);
    can_write_singal_with_index(CanSingalIndex_AutoDisplaySts,(float)Loc_u8AutoDisplay);
    can_write_singal_with_index(CanSingalIndex_BlowSpeedLevelDisplaySts,(float)Loc_u8BlwDisplay);
    can_write_singal_with_index(CanSingalIndex_ACRequestDisplaySts,(float)Loc_u8AcDisplay);
    can_write_singal_with_index(CanSingalIndex_FrontDeforest_MaxDisplaySts,(float)0);
    can_write_singal_with_index(CanSingalIndex_ModeAdjustDisplaySts,(float)Loc_u8ModeDisplay);
    can_write_singal_with_index(CanSingalIndex_ISSInhibitACSts,(float)0);
    can_write_singal_with_index(CanSingalIndex_WorkingSts,(float)Loc_u8OFFDisplay);
    can_write_singal_with_index(CanSingalIndex_PM2_5Sts,(float)0);
    can_write_singal_with_index(CanSingalIndex_SelfTestActive,(float)0);
    can_write_singal_with_index(CanSingalIndex_DisplayActive,(float)1);
    can_write_singal_with_index(CanSingalIndex_BlowAdvanceOnSts,(float)0);
    can_write_singal_with_index(CanSingalIndex_BlowDelayOffSts,(float)0);
    can_write_singal_with_index(CanSingalIndex_SetTemperature_L_C,(float)Loc_u8TsetLDisplay);
    can_write_singal_with_index(CanSingalIndex_SetTemperature_R_C,(float)Loc_u8TsetRDisplay);
    can_write_singal_with_index(CanSingalIndex_CirculationModeDisplaySts,(float)Loc_u8IntakeDisplay);
    can_write_singal_with_index(CanSingalIndex_ZoneSelectionDisplaySts,(float)Loc_u8SyncDisplay);
    can_write_singal_with_index(CanSingalIndex_TemperatureUnit,(float)0);
    can_write_singal_with_index(CanSingalIndex_SelfTestResult,(float)0);
    can_write_singal_with_index(CanSingalIndex_SetTemperature_L_F,(float)Loc_u8TsetLDisplay);
    can_write_singal_with_index(CanSingalIndex_SetTemperature_R_F,(float)Loc_u8TsetRDisplay);
    can_write_singal_with_index(CanSingalIndex_Reserved_ANION_request,(float)0);

}

static void IfRteApp_CLM_2_DataRefresh(void)
{
   sint16 s16Ext_temp = 0;
   s16Ext_temp = Sensor_s16Read(Sensor_u8AMB);
   can_write_singal_with_index(CanSingalIndex_CLM2_ExternalTemperature_C,((float)s16Ext_temp/10));
   can_write_singal_with_index(CanSingalIndex_CLM2_ExternalTempFailSts,(float)0);
}

static void IfRteApp_CLM_11_DataRefresh(void)
{
   uint16 u16Edc_Volt = 0;
   uint16 u16Edc_Curr = 0;
   uint16 u16HVH_Volt = 0;
   uint16 u16HVH_Curr = 0;
   
   u16Edc_Volt = EdcDrv_u16GetCurrVolt();
   u16Edc_Curr = EdcDrv_u16GetCurrCurrent();
   u16HVH_Volt = hvwh_get_TENSION_LV_CTPE_ELEC();
   u16HVH_Curr = hvwh_get_I_CONSO_CTP_EAU_BT();

   can_write_singal_with_index(CanSingalIndex_EAC_iHvAcnCpr,(float)u16Edc_Curr);
   can_write_singal_with_index(CanSingalIndex_HVH_DC_curr,(float)u16HVH_Curr);
   can_write_singal_with_index(CanSingalIndex_EAC_uHvAcnCpr,(float)u16Edc_Volt);
   can_write_singal_with_index(CanSingalIndex_CLM_TMRCoolantFlow,(float)15.5);
   can_write_singal_with_index(CanSingalIndex_HVH_HV_voltage,(float)u16HVH_Volt);
   can_write_singal_with_index(CanSingalIndex_CLM_TMFCoolantFlow,(float)15.5);
   if(EdcDrv_u16GetCurrRpm()>800u)
   {
    can_write_singal_with_index(CanSingalIndex_EAC_Sts,(float)1);
   }
   else
   {
    can_write_singal_with_index(CanSingalIndex_EAC_Sts,(float)0);
   }
   if(u16PowerHVCH()>100u)
   {
    can_write_singal_with_index(CanSingalIndex_HVH_Sts,(float)1);
   }
   else
   {
    can_write_singal_with_index(CanSingalIndex_HVH_Sts,(float)0);
   }
   can_write_singal_with_index(CanSingalIndex_CLM_TMRHeatReq,(float)0);
   can_write_singal_with_index(CanSingalIndex_TMR_InletWaterTemp,((float)Sensor_s16Read(Sensor_u8WATER2)/10));
}
void IfRteApp_CANSend(void)
{
   IfRteApp_Set_DataFromCAN();
   IfRteApp_CLM_1_DataRefresh();
   IfRteApp_CLM_2_DataRefresh();
   IfRteApp_CLM_11_DataRefresh();
   Can_u8CanMsgSendIdDatDlc(0,0x51A,canFrames[CanFrameIndex_CLM_1].canbuffer,8u);
   Can_u8CanMsgSendIdDatDlc(1,0x535,canFrames[CanFrameIndex_CLM_2].canbuffer,8u);
   Can_u8CanMsgSendIdDatDlc(2,0x3F6,canFrames[CanFrameIndex_CLM_11].canbuffer,8u);
}
/*******************************END OF FILE************************************/
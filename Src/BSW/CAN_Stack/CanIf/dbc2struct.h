#ifndef __DBC2STRUCT_H__
#define __DBC2STRUCT_H__


/******************************************************************************
*    NOTICE: Auto generate by tool:dbc_2_struct
*            Prohibit modification !!!!!
*            
*            
*    Tools Version  :  1.2
*    DBC file name  :  Body CAN EDU Message List V1.9 Issue.dbc
*    DBC file MD5   :  90d28e7e9c9b1de1a1c91532005834d5
*    Generate Time  :  2022/01/05 13:57:45
*            
*            
*    Author         :  Lan song yi
*            
*            
******************************************************************************/


#define BYTEORDE_MOTOROLA               0
#define BYTEORDE_INTEL                  1
#define VALUETYPE_UINT32                0
#define VALUETYPE_INT32                 1
#define VALUETYPE_FLOAT                 2


/*******************CAN FRAME INDEX MACRO***************/
#define CanFrameIndex_ABS_ESP_G         0
#define CanFrameIndex_ADCC_4            1
#define CanFrameIndex_VCC_7             2
#define CanFrameIndex_TMR_4             3
#define CanFrameIndex_TMR_2             4
#define CanFrameIndex_TMF_4             5
#define CanFrameIndex_TMF_2             6
#define CanFrameIndex_BCM_11            7
#define CanFrameIndex_TIHU_IHU_4        8
#define CanFrameIndex_AC_Diagnosis6     9
#define CanFrameIndex_AC_Diagnosis5     10
#define CanFrameIndex_AC_Diagnosis4     11
#define CanFrameIndex_AC_Diagnosis3     12
#define CanFrameIndex_AC_Diagnosis2     13
#define CanFrameIndex_AC_Diagnosis1     14
#define CanFrameIndex_CLM_11            15
#define CanFrameIndex_CLM_2             16
#define CanFrameIndex_CLM_1             17
#define CanFrameIndex_OBC_4             18
#define CanFrameIndex_OBC_3             19
#define CanFrameIndex_DCDC_1            20
#define CanFrameIndex_BMS_7             21
#define CanFrameIndex_BMS_5             22
#define CanFrameIndex_BMS_4             23
#define CanFrameIndex_BMS_2             24
#define CanFrameIndex_AIPM_2            25
#define CanFrameIndex_AIPM_1            26
#define CanFrameIndex_MAX               26
/*******************SINGAL INDEX MACRO***************/
//CAN FRAME:ABS_ESP_G         CAN ID:0x502
#define CanSingalIndex_VehicleSpeedVSOSigValidData     0
#define CanSingalIndex_VehicleSpeedVSOSig              1
//CAN FRAME:ADCC_4            CAN ID:0x16b
#define CanSingalIndex_ADCC_4_CRC                      2
#define CanSingalIndex_ADCC_4_Message_Counter          3
#define CanSingalIndex_ADCC_DelayReq                   4
#define CanSingalIndex_ADCC_CoolantFlowReq             5
//CAN FRAME:VCC_7             CAN ID:0x3fe
#define CanSingalIndex_VCC_EACAllow                    6
#define CanSingalIndex_VCC_HVHAllow                    7
#define CanSingalIndex_VCC_HVReady                     8
#define CanSingalIndex_VCC_MotorHeatPwrAct             9
#define CanSingalIndex_VCC_EDUSystemPowerLimit         10
//CAN FRAME:TMR_4             CAN ID:0x48b
#define CanSingalIndex_TMR_StatorTemperature           11
#define CanSingalIndex_TMR_InverterTemperature         12
//CAN FRAME:TMR_2             CAN ID:0x31e
#define CanSingalIndex_TMR_CoolantFlow                 13
#define CanSingalIndex_TMR_CoolantTemp                 14
//CAN FRAME:TMF_4             CAN ID:0x45b
#define CanSingalIndex_TMF_StatTemp                    15
#define CanSingalIndex_TMF_InvTemp                     16
//CAN FRAME:TMF_2             CAN ID:0x315
#define CanSingalIndex_TMF_CoolantFlowReq              17
#define CanSingalIndex_TMF_CoolantTemp                 18
//CAN FRAME:BCM_11            CAN ID:0x427
#define CanSingalIndex_RLS_TempDewPoint                19
#define CanSingalIndex_RLS_Humid_Temp_Error            20
#define CanSingalIndex_RLS_HumidSensorValue            21
#define CanSingalIndex_RLS_TempSensorValue             22
//CAN FRAME:TIHU_IHU_4        CAN ID:0x519
#define CanSingalIndex_HU_ZoneSelectionKeySts          23
#define CanSingalIndex_HU_SetCirculationModeKeySts     24
#define CanSingalIndex_HU_SetTemperature_R_C           25
#define CanSingalIndex_HU_SetTemperature_L_C           26
#define CanSingalIndex_HU_ModeAdjustKeySts             27
#define CanSingalIndex_HU_SetMaxFrontDeforestSts       28
#define CanSingalIndex_HU_BlowSpeedLevelKeySts         29
#define CanSingalIndex_HU_SetAutoKeySts                30
#define CanSingalIndex_HU_SetACRequestKeySts           31
#define CanSingalIndex_HU_SetCLMOn                     32
//CAN FRAME:AC_Diagnosis6     CAN ID:0x5a2
//CAN FRAME:AC_Diagnosis5     CAN ID:0x5a1
//CAN FRAME:AC_Diagnosis4     CAN ID:0x5a5
#define CanSingalIndex_Test8_T                         33
#define CanSingalIndex_Test7_T                         34
#define CanSingalIndex_Test6_T                         35
#define CanSingalIndex_Test5_T                         36
#define CanSingalIndex_Test4_T                         37
#define CanSingalIndex_Test3_T                         38
#define CanSingalIndex_Test2_T                         39
#define CanSingalIndex_Test1_P                         40
//CAN FRAME:AC_Diagnosis3     CAN ID:0x5a4
#define CanSingalIndex_PT_Sensor2_T                    41
#define CanSingalIndex_PT_Sensor2_P                    42
#define CanSingalIndex_PT_Sensor1_T                    43
#define CanSingalIndex_PT_Sensor1_P                    44
#define CanSingalIndex_AC_ModeDC_Actual                45
#define CanSingalIndex_AC_ModeDC_Req                   46
#define CanSingalIndex_AC_RecDC_Actual                 47
#define CanSingalIndex_AC_RecDC_Req                    48
//CAN FRAME:AC_Diagnosis2     CAN ID:0x5a7
#define CanSingalIndex_AC_MixDC_Right_Actual           49
#define CanSingalIndex_AC_MixDC_Right_Req              50
#define CanSingalIndex_AC_MixDC_Left_Actual            51
#define CanSingalIndex_AC_MixDC_Left_Req               52
#define CanSingalIndex_AC_u16PUMP3_PWM_Req             53
#define CanSingalIndex_AC_u16PUMP2_PWM_Req             54
#define CanSingalIndex_AC_u16PUMP1_PWM_Req             55
#define CanSingalIndex_AC_u16FRFAN_PWM_Req             56
//CAN FRAME:AC_Diagnosis1     CAN ID:0x5a6
#define CanSingalIndex_EXV2_Postion                    57
#define CanSingalIndex_EXV1_Postion                    58
#define CanSingalIndex_AC_EDC_Power                    59
#define CanSingalIndex_AC_EDC_PowerReq                 60
#define CanSingalIndex_AC_EDC_Speed                    61
#define CanSingalIndex_AC_EDC_SpeedReq                 62
//CAN FRAME:CLM_11            CAN ID:0x3f6
#define CanSingalIndex_TMR_InletWaterTemp              63
#define CanSingalIndex_CLM_TMRHeatReq                  64
#define CanSingalIndex_HVH_Sts                         65
#define CanSingalIndex_EAC_Sts                         66
#define CanSingalIndex_CLM_TMFCoolantFlow              67
#define CanSingalIndex_HVH_HV_voltage                  68
#define CanSingalIndex_CLM_TMRCoolantFlow              69
#define CanSingalIndex_EAC_uHvAcnCpr                   70
#define CanSingalIndex_HVH_DC_curr                     71
#define CanSingalIndex_EAC_iHvAcnCpr                   72
//CAN FRAME:CLM_2             CAN ID:0x535
#define CanSingalIndex_CLM2_ExternalTemperature_C      73
#define CanSingalIndex_CLM2_ExternalTempFailSts        74
//CAN FRAME:CLM_1             CAN ID:0x51a
#define CanSingalIndex_Reserved_ANION_request          75
#define CanSingalIndex_SetTemperature_R_F              76
#define CanSingalIndex_SetTemperature_L_F              77
#define CanSingalIndex_SelfTestResult                  78
#define CanSingalIndex_TemperatureUnit                 79
#define CanSingalIndex_ZoneSelectionDisplaySts         80
#define CanSingalIndex_CirculationModeDisplaySts       81
#define CanSingalIndex_SetTemperature_R_C              82
#define CanSingalIndex_SetTemperature_L_C              83
#define CanSingalIndex_BlowDelayOffSts                 84
#define CanSingalIndex_BlowAdvanceOnSts                85
#define CanSingalIndex_DisplayActive                   86
#define CanSingalIndex_SelfTestActive                  87
#define CanSingalIndex_PM2_5Sts                        88
#define CanSingalIndex_WorkingSts                      89
#define CanSingalIndex_ISSInhibitACSts                 90
#define CanSingalIndex_ModeAdjustDisplaySts            91
#define CanSingalIndex_FrontDeforest_MaxDisplaySts     92
#define CanSingalIndex_ACRequestDisplaySts             93
#define CanSingalIndex_BlowSpeedLevelDisplaySts        94
#define CanSingalIndex_AutoDisplaySts                  95
#define CanSingalIndex_ACRequestCommand                96
#define CanSingalIndex_Reserved_AC_MaxSts              97
#define CanSingalIndex_ExternalTemperatureFailSts      98
#define CanSingalIndex_ExternalTemperature_C           99
#define CanSingalIndex_ExternalTemperature_F           100
//CAN FRAME:OBC_4             CAN ID:0x43c
#define CanSingalIndex_OBC_CoolingReq                  101
//CAN FRAME:OBC_3             CAN ID:0x42b
#define CanSingalIndex_OBC_ChargerTemp                 102
//CAN FRAME:DCDC_1            CAN ID:0x418
#define CanSingalIndex_DCDC_OverTemp                   103
#define CanSingalIndex_DCDC_CoolingReq                 104
#define CanSingalIndex_DCDC_Temp                       105
//CAN FRAME:BMS_7             CAN ID:0x426
#define CanSingalIndex_BMS_AverageBattTemp             106
#define CanSingalIndex_BMS_LowestBattTemp              107
#define CanSingalIndex_BMS_HighestBattTemp             108
//CAN FRAME:BMS_5             CAN ID:0x41b
#define CanSingalIndex_BMS_HeatRequest_Mode            109
#define CanSingalIndex_BMS_Request_Mode                110
//CAN FRAME:BMS_4             CAN ID:0x41f
#define CanSingalIndex_BMS_Request_FlowRate            111
#define CanSingalIndex_BMS_WaterTemp_InletTarget       112
#define CanSingalIndex_BMS_WaterTemp_Outlet            113
#define CanSingalIndex_BMS_WaterTemp_Inlet             114
//CAN FRAME:BMS_2             CAN ID:0x208
#define CanSingalIndex_BMS_Chg_Sts                     115
//CAN FRAME:AIPM_2            CAN ID:0x4f3
#define CanSingalIndex_PM_2_5KeyPresent                116
#define CanSingalIndex_SurfaceTempRaw_C                117
#define CanSingalIndex_OnBoardTempRaw_C                118
#define CanSingalIndex_SolarSenRaw                     119
//CAN FRAME:AIPM_1            CAN ID:0x4f1
#define CanSingalIndex_Key19Sts                        120
#define CanSingalIndex_Key18Sts                        121
#define CanSingalIndex_Key17Sts                        122
#define CanSingalIndex_BlowerSilderSts                 123
#define CanSingalIndex_BlowLevelPlusMinusSts           124
#define CanSingalIndex_Key14Sts                        125
#define CanSingalIndex_BlowerSlidPlusMinusSts          126
#define CanSingalIndex_Key16Sts                        127
#define CanSingalIndex_Key13Sts                        128
#define CanSingalIndex_Key10Sts                        129
#define CanSingalIndex_TemperatureUnitKeySts           130
#define CanSingalIndex_SelfTestActiveKeySts            131
#define CanSingalIndex_Key9Sts                         132
#define CanSingalIndex_Key8Sts                         133
#define CanSingalIndex_Key7Sts                         134
#define CanSingalIndex_Knob3Sts                        135
#define CanSingalIndex_Knob2Sts                        136
#define CanSingalIndex_Key15Sts                        137
#define CanSingalIndex_RightTempPlusMinusSts           138
#define CanSingalIndex_LeftTempPlusMinusSts            139
#define CanSingalIndex_MAX                             139
/*******************CAN FRAME STRUCT***************/
typedef struct
{
  unsigned int    canindex;
  unsigned int    canid;
  unsigned char   bytelen;
  unsigned char   canbuffer[8];
}canFrame_t;
/*******************SINGAL FRAME STRUCT***************/
typedef struct
{
  unsigned int    signalIndex;
  unsigned int    canFrameIndex;
  unsigned char   byteorder;
  unsigned int    bitstart;
  unsigned int    bitlen;
  float           factor;
  float           offset;
  float           singalValue;
}signalFrame_t;

extern canFrame_t canFrames[];
extern signalFrame_t singalFrames[];


#endif

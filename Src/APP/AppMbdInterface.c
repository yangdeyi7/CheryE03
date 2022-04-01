/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "AppMbdInterface.h"
#include "CanIf_Cfg.h"
#include "Sensor.h"
#include "AppDiag.h"
#include "ExvDrv.h"
#include "EcvDrv.h"
#include "SovDrv.h"
#include "Stepper.h"
#include "EdcDrv.h"
#include "Blower.h"
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "Can_Hdl.h"
#include "Pwm.h"
#include "Pump.h"
#include "if_rte_app.h"
#include "Actuator.h"
#include "Fan.h"
#include "PtcDrv.h"
#include "CMB.h"
#include "Power.h"
#include "Sokon_X01_Thm.h"
/************************************DEFINES***********************************/
uint8 u8RLY_InitReq = 1u;
uint16 u16AMB_Set = 0u;
static const uint8 strBlwVolTab[8]={0,36,48,60,72,85,100,120};
/*********************LOCAL FUNCTION DECLARATION*******************************/
static void    vidHpMbdInterfaceRefreshInput(void);
static void    vidCmfMbdInterfaceRefreshInput(void);
/*************************Output***********************************************/
static void    vidAppMbdInterfaceRefreshOutput(void);
/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
static void vidHpMbdInterfaceRefreshInput(void)
{
  /*主驾驶设置温度*/
  Sokon_X01_Thm_U.THM_In_u16Tset_Left_A10    =    (sint16)IfRteApp_Get_TsetLSts()*10;;
  /*副驾驶设置温度*/
  Sokon_X01_Thm_U.THM_In_u16Tset_Right_A10    =    (sint16)IfRteApp_Get_TsetRSts()*10;
  /*3区设置温度*/
  Sokon_X01_Thm_U.THM_In_u16Tset_3Z_A10    =    MBD_INPUT_DEFAULT_NUM240;
  /*4区设置温度*/
  Sokon_X01_Thm_U.THM_In_u16Tset_4Z_A10    =    MBD_INPUT_DEFAULT_NUM240;
  /*PAD界面AC灯开启状态：0;关，1：开*/
  Sokon_X01_Thm_U.THM_In_bAcSts    =    IfRteApp_Get_ACSts();
  /*鼓风机手动还是自动; 0=Off;1=level1;2=Level 2;…;7=Level7;8=AUTO mode;9~15=reserve*/
  Sokon_X01_Thm_U.THM_In_u8BlwMASts    =    IfRteApp_Get_BlwSts();
  /*鼓风机手动还是自动; Blw_Manual_0,1,2,3,4,5,6,7 (Blowr 挡位)；Blw_Auto_8*/
  Sokon_X01_Thm_U.THM_In_u8BlwMASts_2Z    =    MBD_INPUT_DEFAULT_NUM0;
  /*鼓风机手动还是自动; Blw_Manual_0,1,2,3,4,5,6,7 (Blowr 挡位)；Blw_Auto_8*/
  Sokon_X01_Thm_U.THM_In_u8BlwMASts_3Z    =    MBD_INPUT_DEFAULT_NUM0;
  /*鼓风机手动还是自动; Blw_Manual_0,1,2,3,4,5,6,7 (Blowr 挡位)；Blw_Auto_8*/
  Sokon_X01_Thm_U.THM_In_u8BlwMASts_4Z    =    MBD_INPUT_DEFAULT_NUM0;
  /*用户个性化风量设置,自定义配置的最大风量:0=Low;1=Normal;2=High;3=Not used;*/
  Sokon_X01_Thm_U.THM_In_u8BlwUserHabit    =    MBD_INPUT_DEFAULT_NUM3;
  /*模式手动还是自动；0=Off;1=Face;2=Face/Foot;3=Foot;4=F/D;5=DEF;6=AUTO mode;7=Reserve*/
  Sokon_X01_Thm_U.THM_In_u8ModeMASts    =    IfRteApp_Get_ModeSts();
  /*模式手动还是自动；Manual_0_Vent, Manual_1_Vent-Feet, Manual_2_F, Manual_3_F-D, Manual_4_Def, Manual_5_V-F-D, Manual_6_V-D; Mode Auto_250*/
  Sokon_X01_Thm_U.THM_In_u8ModeMASts_2Z    =    MBD_INPUT_DEFAULT_NUM0;
  /*模式手动还是自动；Manual_0_Vent, Manual_1_Vent-Feet, Manual_2_F, Manual_3_F-D, Manual_4_Def, Manual_5_V-F-D, Manual_6_V-D; Mode Auto_250*/
  Sokon_X01_Thm_U.THM_In_u8ModeMASts_3Z    =    MBD_INPUT_DEFAULT_NUM0;
  /*模式手动还是自动；Manual_0_Vent, Manual_1_Vent-Feet, Manual_2_F, Manual_3_F-D, Manual_4_Def, Manual_5_V-F-D, Manual_6_V-D; Mode Auto_250*/
  Sokon_X01_Thm_U.THM_In_u8ModeMASts_4Z    =    MBD_INPUT_DEFAULT_NUM0;
  /*内外循环风门手都还是自动,0=Off,1=Inner air circulation,2=outside air circulation,3=Auto mode*/
  Sokon_X01_Thm_U.THM_In_u8IntakeMASts    =    IfRteApp_Get_IntakeSts()+MBD_INPUT_DEFAULT_NUM1;
  /*滤波后前排蒸发器测量温度*/
  Sokon_X01_Thm_U.THM_In_s16Teva_Front_A10    =    Sensor_s16Read(Sensor_u8EVAP);
  /*滤波后后排蒸发器测量温度*/
  Sokon_X01_Thm_U.THM_In_s16Teva_Rear_A10    =    Sensor_s16Read(Sensor_u8LP_P);
  /*滤波后水冷凝器出口压力值*/
  Sokon_X01_Thm_U.THM_In_u16P_Ref_CondOut_A10    =    (uint16)Sensor_s16Read(Sensor_u8HP_P1);
  /*滤波后阳光值_左*/
  Sokon_X01_Thm_U.THM_In_u16Sun_L    =    MBD_INPUT_DEFAULT_NUM0;
  /*滤波后阳光值_右*/
  Sokon_X01_Thm_U.THM_In_u16Sun_R    =    MBD_INPUT_DEFAULT_NUM0;
  /*滤波后车外温度采集值*/
  Sokon_X01_Thm_U.THM_In_s16Tamb_A10    =    Sensor_s16Read(Sensor_u8AMB);
  /*滤波后前排车内温度采集值*/
  Sokon_X01_Thm_U.THM_In_s16Tincar_Front_A10    =    Sensor_s16Read(Sensor_u8INCAR);
  /*滤波后后排内温采集值*/
  Sokon_X01_Thm_U.THM_In_s16Tincar_Rear_A10    =    Sensor_s16Read(Sensor_u8LP_P);
  /*滤波后内驱动电机入口的水温*/
  Sokon_X01_Thm_U.THM_In_s16T_Wat_MotorIn_A10    =    Sensor_s16Read(Sensor_u8WATER2);
  /*滤波后空调风道出口温度值,Left Vent*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_LV_A10    =    Sensor_s16Read(Sensor_u8TDUCT_L_V);
  /*滤波后空调风道出口温度值,Left Feet*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_LF_A10    =    Sensor_s16Read(Sensor_u8TDUCT_L_F);
  /*滤波后空调风道出口温度值,Right Vent*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_RV_A10    =    Sensor_s16Read(Sensor_u8TDUCT_R_V);
  /*滤波后空调风道出口温度值,Right Feet*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_RF_A10    =    Sensor_s16Read(Sensor_u8TDUCT_R_F);
  /*空调风道温度传感器,Feet_Right*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_3Z_V_A10    =    MBD_INPUT_DEFAULT_NUM240;
  /*空调风道温度传感器,Feet_Right*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_3Z_F_A10    =    MBD_INPUT_DEFAULT_NUM240;
  /*空调风道温度传感器,Feet_Right*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_4Z_V_A10    =    MBD_INPUT_DEFAULT_NUM240;
  /*空调风道温度传感器,Feet_Right*/
  Sokon_X01_Thm_U.THM_In_s16TDuct_4Z_F_A10    =    MBD_INPUT_DEFAULT_NUM240;
  /*鼓风机当前挡位反馈*/
  Sokon_X01_Thm_U.THM_In_u8BlwLv_Real    =    MIN(IfRteApp_Get_BlwSts(),MBD_INPUT_DEFAULT_NUM7);
  /*滤波后鼓风机实际控制电压反馈,0-12V*/
  Sokon_X01_Thm_U.THM_In_u8BlwVol_Real_A10    =    strBlwVolTab[Sokon_X01_Thm_U.THM_In_u8BlwLv_Real];
  /*后鼓风机当前反馈电压*/
  Sokon_X01_Thm_U.THM_In_u8RearBlwVol_Real_A10    =    MBD_INPUT_DEFAULT_NUM0;
  /*模式反馈状态,0=Invalid,1=Face,2=Face/Foot,3=Foot,4=F/D,5=DEF,6=Reserve,7=Reserve*/
  Sokon_X01_Thm_U.THM_In_u8ModeStatus_Real    =    IfRteApp_Get_ModeSts();
  /*模式反馈状态,0_Vent, 1_Vent-Feet, 2_F, 3_F-D, 4_Def, 5_V-F-D, 6_V-D*/
  Sokon_X01_Thm_U.THM_In_u8ModeStatus_2Z_Real    =    MBD_INPUT_DEFAULT_NUM0;
  /*模式反馈状态,0_Vent, 1_Vent-Feet, 2_F, 3_F-D, 4_Def, 5_V-F-D, 6_V-D*/
  Sokon_X01_Thm_U.THM_In_u8ModeStatus_3Z_Real    =    MBD_INPUT_DEFAULT_NUM0;
  /*模式反馈状态,0_Vent, 1_Vent-Feet, 2_F, 3_F-D, 4_Def, 5_V-F-D, 6_V-D*/
  Sokon_X01_Thm_U.THM_In_u8ModeStatus_4Z_Real    =    MBD_INPUT_DEFAULT_NUM0;
  /*Intake反馈的百分比,0=Inner air circulation,1~99 = 全内循环~全外循环中间的线性插值,100=outside air circulation,250=2layerFlow Circulation*/
  if( IfRteApp_Get_IntakeSts() == MBD_INPUT_DEFAULT_NUM1 )
  {
    Sokon_X01_Thm_U.THM_In_u8IntakePerc_Real    =    MBD_INPUT_DEFAULT_NUM0;    
  }
  else if( IfRteApp_Get_IntakeSts() == MBD_INPUT_DEFAULT_NUM2 )
  {
    Sokon_X01_Thm_U.THM_In_u8IntakePerc_Real    =    MBD_INPUT_DEFAULT_NUM100;    
  }
  else
  {
    /*do nothing*/
  }
  /* 0: Invalid,1: AUTO, 2: Defrost , 3: OFF,4: Ventilate, 5: ACMax  6: Manual  7: IKEY  8: 4G  9: OTA  10: Bluetooth */
  if(IfRteApp_Get_WorkSts() == MBD_INPUT_DEFAULT_NUM1)
  {
    Sokon_X01_Thm_U.THM_In_u8HVACSts    =    MBD_INPUT_DEFAULT_NUM6;  
  }
  else
  {
    Sokon_X01_Thm_U.THM_In_u8HVACSts    =    MBD_INPUT_DEFAULT_NUM3;    
  }
  /*滤波后车速*/
  Sokon_X01_Thm_U.THM_In_u8VehSpd    =    IfRteApp_Get_CarSpeedFromCAN();
  /*经济模式,0=Not ECO,1=Eco mode*/
  Sokon_X01_Thm_U.THM_In_bEco_Model_Set    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_Engine Stop; 1_Cranking, 2_Reserved, 3_Running, 7_Fault*/
  Sokon_X01_Thm_U.THM_In_u8ECM_Engine_Status    =    MBD_INPUT_DEFAULT_NUM0;
  /*IGN状态,0=OFF,1=ACC,2=ON,3=Not used,4= Ready*/
  Sokon_X01_Thm_U.THM_In_u8IgnSts    =    Power_u16GetIgnSts();
  /*滤波后内高压水加热器出口的水温*/
  Sokon_X01_Thm_U.THM_In_s16T_Wat_HVCHOut_A10    =    (sint16)(hvwh_get_TEMP_EAU_CPT_BT()*MBD_INPUT_DEFAULT_NUM10);
  /*电池冷却请求,0: No request; 1:   Ac priority; 2~3.   BTC Priority ; 4. Only BTC; */
  if(IfRteApp_Get_BMSRequestLevelFromCAN() == MBD_INPUT_DEFAULT_NUM2)
  {
    Sokon_X01_Thm_U.THM_In_u8BAT_CoolLv    =    MBD_INPUT_DEFAULT_NUM3;
  }
  else if(IfRteApp_Get_BMSRequestLevelFromCAN() == MBD_INPUT_DEFAULT_NUM3)
  {
    Sokon_X01_Thm_U.THM_In_u8BAT_CoolLv    =    MBD_INPUT_DEFAULT_NUM1;
  }
  else
  {
    Sokon_X01_Thm_U.THM_In_u8BAT_CoolLv    =    MBD_INPUT_DEFAULT_NUM0;
  }
  /*滤波后蒸发器出口压力值*/
  Sokon_X01_Thm_U.THM_In_u16P_Ref_EvaOut_A10    =    (uint16)Sensor_s16Read(Sensor_u8HP_P2);
  /*滤波后Chiller出口压力值*/
  Sokon_X01_Thm_U.THM_In_u16P_Ref_CHILOut_A10    =    ExvDrv_u16GetCurrPressSensorValue(u8EXV_CHILLER_ID);
  /*滤波后Chiller出口温度值*/
  Sokon_X01_Thm_U.THM_In_s16T_Ref_CHILOut_A10    =    ExvDrv_s16GetCurrTempSensorValue(u8EXV_CHILLER_ID);
  /*滤波后外压缩机入口温度值*/
  Sokon_X01_Thm_U.THM_In_s16T_Ref_EDCIn_A10    =    Sensor_s16Read(Sensor_u8LP_T);
  /*The Front FAN PWM，当前工作转速*/
  Sokon_X01_Thm_U.THM_In_u8PWM_FrontFAN    =    Sokon_X01_Thm_Y.THM_Out_u8FRFAN_PWM_Req;
  /*主动进气格栅配置状态，0_未安装，1_已安装*/
  Sokon_X01_Thm_U.THM_In_bAGS_Status    =    MBD_INPUT_DEFAULT_NUM0;
  /*主动进气格栅当前开度反馈*/
  Sokon_X01_Thm_U.THM_In_u8AGS_Position    =    MBD_INPUT_DEFAULT_NUM0;
  /*滤波后压缩机当前功率*/
  Sokon_X01_Thm_U.THM_In_u16PowerComp    =    EdcDrv_u16GetCurrPwr();
  /*Compressor real speed*/
  Sokon_X01_Thm_U.THM_In_u16Ncomp    =    EdcDrv_u16GetCurrRpm();
  /*Compressor + PTC max power limit*/
  Sokon_X01_Thm_U.THM_In_u16Power_Max    =    MBD_INPUT_DEFAULT_NUM8000;
  /*Compressor max speed*/
  Sokon_X01_Thm_U.THM_In_u16Ncomp_Max    =    MBD_INPUT_DEFAULT_NUM8000;
  /*SOV Eva,,0_close,1_open*/
  Sokon_X01_Thm_U.THM_In_bSOV_Eva    =    (uint8)SovDrv_enuGetSovPassOrBlockSts(u8SOV1_ID);
  /*Out Eva,,0_close,1_open*/
  Sokon_X01_Thm_U.THM_In_bSOV_OutEva    =    (uint8)SovDrv_enuGetSovPassOrBlockSts(u8SOV2_ID);
  /*TXV of Out Eva,0_close,1_open*/
  Sokon_X01_Thm_U.THM_In_bSOV_TXVOutEva    =    (uint8)SovDrv_enuGetSovPassOrBlockSts(u8SOV3_ID);
  /*EXV_Eva Position*/
  Sokon_X01_Thm_U.THM_In_u16EXV_Eva_Pos    =    ExvDrv_u16GetCurrStepPosition(u8EXV_EVAP_ID);
  /*EXV_Chiller Position*/
  Sokon_X01_Thm_U.THM_In_u16EXV_Chil_Pos    =    ExvDrv_u16GetCurrStepPosition(u8EXV_CHILLER_ID);
  /*The L mixing flap position %*/
  Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_L    =    Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_L;
  /*The R mixing flap position %*/
  Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_R    =    Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_R;
  /*雨量信号*/
  Sokon_X01_Thm_U.THM_In_u16Rainfall    =    MBD_INPUT_DEFAULT_NUM0;
  /*阳光型号*/
  Sokon_X01_Thm_U.THM_In_u16Solar    =    MBD_INPUT_DEFAULT_NUM0;
  /*滤波后内电池入口的水温*/
  Sokon_X01_Thm_U.THM_In_s16T_Wat_BatIn_A10    =    (sint16)IfRteApp_Get_BMSInletFromCAN();
  /*滤波后内低温散热器出口的水温*/
  Sokon_X01_Thm_U.THM_In_s16T_Wat_LTROut_A10    =    Sensor_s16Read(Sensor_u8WATER2);
  /*滤波后内驱动电机出口的水温*/
  Sokon_X01_Thm_U.THM_In_s16T_Wat_MotorOut_A10    =    Sensor_s16Read(Sensor_u8WATER1);
  /*Max battery temperature*/
  Sokon_X01_Thm_U.THM_In_s16TbatMax_A10    =    IfRteApp_Get_BMSTmaxFromCAN();
  /*Average battery temperature*/
  Sokon_X01_Thm_U.THM_In_s16TbatAvr_A10    =    IfRteApp_Get_BMSTavrFromCAN();
  /*The min temperature of Battery*/
  Sokon_X01_Thm_U.THM_In_s16TbatMin_A10    =    IfRteApp_Get_BMSTminFromCAN();
  /*电池冷却请求:0: No request, L1 L2 L3 Cooling, L4 L5 heating, L11 Temperature Balance*/
  if(IfRteApp_Get_BMSRequestLevelFromCAN() == MBD_INPUT_DEFAULT_NUM1)
  {
    Sokon_X01_Thm_U.THM_In_u8BAT_CoolHeatLv = 4u;
  }
  else if(IfRteApp_Get_BMSRequestLevelFromCAN() == MBD_INPUT_DEFAULT_NUM2)
  {
    Sokon_X01_Thm_U.THM_In_u8BAT_CoolHeatLv = 1u;
  }
  else if(IfRteApp_Get_BMSRequestLevelFromCAN() == MBD_INPUT_DEFAULT_NUM3)
  {
    Sokon_X01_Thm_U.THM_In_u8BAT_CoolHeatLv = 11u;
  }
  else
  {
    Sokon_X01_Thm_U.THM_In_u8BAT_CoolHeatLv = 0u;
  }
  /*电池冷却目标水温*/
  Sokon_X01_Thm_U.THM_In_s16T_BAT_Wat_Set_A10    =    (sint16)(IfRteApp_Get_BMSInletTargetFromCAN()*MBD_INPUT_DEFAULT_NUM10);
  /*电机冷却请求,0: No request, L1 Cool Req*/
  if((IfRteApp_Get_TMFFlowReqFromCAN()>2u)||(IfRteApp_Get_TMRFlowReqFromCAN()>2u)||(IfRteApp_Get_ADCCFlowReqFromCAN()>2u))
  {
    Sokon_X01_Thm_U.THM_In_u8Mot_CoolLv    =    MBD_INPUT_DEFAULT_NUM1;  
  }
  else if((IfRteApp_Get_DCDCReqFromCAN()==1u)||(IfRteApp_Get_OBCCoolingReqFromCAN()==1u))
  {
    Sokon_X01_Thm_U.THM_In_u8Mot_CoolLv    =    MBD_INPUT_DEFAULT_NUM1;  
  }
  else
  {
    Sokon_X01_Thm_U.THM_In_u8Mot_CoolLv    =    MBD_INPUT_DEFAULT_NUM0;  
  }
  /*三通比例阀位置反馈, HC*/
  Sokon_X01_Thm_U.THM_In_u8TWValve_HC_Position    =    EcvDrv_u8GetEcvCurrPercentPosi(u8ECV_HVAC_ID);
  /*三通比例阀位置反馈,LTR*/
  Sokon_X01_Thm_U.THM_In_u8TWValve_LTR_Position    =    EcvDrv_u8GetEcvCurrPercentPosi(u8ECV_MOTOR_ID);
  /*三通比例阀位置反馈,BAT*/
  Sokon_X01_Thm_U.THM_In_u8TWValve_BAT_Position    =    EcvDrv_u8GetEcvCurrPercentPosi(u8ECV_BAT_ID);
  /*水PTC实际工作档位反馈*/
  Sokon_X01_Thm_U.THM_In_u8HVCH_Status    =    u16HVCHStatus();
  /*Pump of HVCH*/
  Sokon_X01_Thm_U.THM_In_u16Pump_HVCH    =    (uint16)PumpHVAC_u16GetCurrpd();
  /*Pump of Motor*/
  Sokon_X01_Thm_U.THM_In_u16Pump_Motor    =    (uint16)PumpMotor_u16GetCurrpd();
  /*Pump of Bat*/
  Sokon_X01_Thm_U.THM_In_u16Pump_Bat    =    (uint16)PumpBat_u16GetCurrpd();
  /*滤波后PTC当前功率*/
  Sokon_X01_Thm_U.THM_In_u16PowerHVCH    =    u16PowerHVCH();
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_CondOut    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_EvaOut    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_CHILOut    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_T_Ref_CHILOut    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_T_Ref_EDCIn    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_Teva_Front    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_Tamb    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_SOV_Eva    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_SOV_OutEva    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_SOV_TXVOutEva    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_EXV_Eva_Pos    =    EXV_bGetEvaFaultStatus(u8EXV_EVAP_ID);
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_EXV_Chil_Pos    =    EXV_bGetEvaFaultStatus(u8EXV_CHILLER_ID);
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_BLW_Front    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_EDC_Front    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_TWValve_HC    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_TWValve_LTR    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_TWValve_BAT    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_HVCH    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_Pump_HVCH    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_Pump_Motor    =    MBD_INPUT_DEFAULT_NUM0;
  /*0_No DTC, 1 DTC and Stop*/
  Sokon_X01_Thm_U.THM_In_bDTC_Pump_Bat    =    MBD_INPUT_DEFAULT_NUM0;
  /*滤波后外压缩机排气温度值*/
  Sokon_X01_Thm_U.THM_In_s16T_Ref_EDCOut_A10    =    MBD_INPUT_DEFAULT_NUM0;
  /********************************END**********************************************/
  /**************************data to uppc --> MBD IN********************************/
  /**************************MBD input data display on uppc*************************/
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.Diag_u8manualCtrlMode = AppDiag_uniRecvFormPcData.strRecvFormPcData.Diag_u8manualCtrlMode;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16P_Ref_CondOut_A10 = Sokon_X01_Thm_U.THM_In_u16P_Ref_CondOut_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16P_Ref_EvaOut_A10 = Sokon_X01_Thm_U.THM_In_u16P_Ref_EvaOut_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16P_Ref_CHILOut_A10 = Sokon_X01_Thm_U.THM_In_u16P_Ref_CHILOut_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Ref_CHILOut_A10 = Sokon_X01_Thm_U.THM_In_s16T_Ref_CHILOut_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Ref_EDCIn_A10 = Sokon_X01_Thm_U.THM_In_s16T_Ref_EDCIn_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Teva_Front_A10 = Sokon_X01_Thm_U.THM_In_s16Teva_Front_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Teva_Rear_A10 = Sokon_X01_Thm_U.THM_In_s16Teva_Rear_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16TevaSet_Req_A10 = MBD_INPUT_DEFAULT_NUM0;;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bAcSts = Sokon_X01_Thm_U.THM_In_bAcSts;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Tamb_A10 = Sokon_X01_Thm_U.THM_In_s16Tamb_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Tincar_Front_A10 = Sokon_X01_Thm_U.THM_In_s16Tincar_Front_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Tincar_Rear_A10 = Sokon_X01_Thm_U.THM_In_s16Tincar_Rear_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8VehSpd = Sokon_X01_Thm_U.THM_In_u8VehSpd;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8PWM_FrontFAN = Sokon_X01_Thm_U.THM_In_u8PWM_FrontFAN;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bAGS_Status = Sokon_X01_Thm_U.THM_In_bAGS_Status;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8AGS_Position = Sokon_X01_Thm_U.THM_In_u8AGS_Position;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8VehicleType = MBD_INPUT_DEFAULT_NUM0;;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16PowerComp = Sokon_X01_Thm_U.THM_In_u16PowerComp;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Ncomp = Sokon_X01_Thm_U.THM_In_u16Ncomp;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Power_Max = Sokon_X01_Thm_U.THM_In_u16Power_Max;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Ncomp_Max = Sokon_X01_Thm_U.THM_In_u16Ncomp_Max;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bSOV_Eva = Sokon_X01_Thm_U.THM_In_bSOV_Eva;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bSOV_OutEva = Sokon_X01_Thm_U.THM_In_bSOV_OutEva;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bSOV_TXVOutEva = Sokon_X01_Thm_U.THM_In_bSOV_TXVOutEva;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16EXV_Eva_Pos = Sokon_X01_Thm_U.THM_In_u16EXV_Eva_Pos;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16EXV_Chil_Pos = Sokon_X01_Thm_U.THM_In_u16EXV_Chil_Pos;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Tincar_Setting_Req_A10 = MBD_INPUT_DEFAULT_NUM0;;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8BlwVol_Real_A10 = Sokon_X01_Thm_U.THM_In_u8BlwVol_Real_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8ModeStatus_Real = Sokon_X01_Thm_U.THM_In_u8ModeStatus_Real;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8IntakePerc_Real = Sokon_X01_Thm_U.THM_In_u8IntakePerc_Real;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8Mix_Flap_Position_L = Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_L;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8Mix_Flap_Position_R = Sokon_X01_Thm_U.THM_In_u8Mix_Flap_Position_R;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Tset_Left_A10 = Sokon_X01_Thm_U.THM_In_u16Tset_Left_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Tset_Right_A10 = Sokon_X01_Thm_U.THM_In_u16Tset_Right_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Tasd_Left_Req_A10 = MBD_INPUT_DEFAULT_NUM0;;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16Tasd_Right_Req_A10 = MBD_INPUT_DEFAULT_NUM0;;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16TDuct_Left_Out_A10 = Sokon_X01_Thm_U.THM_In_s16TDuct_LV_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16TDuct_Right_Out_A10 = Sokon_X01_Thm_U.THM_In_s16TDuct_RV_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bEco_Model_Set = Sokon_X01_Thm_U.THM_In_bEco_Model_Set;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8HVACSts = Sokon_X01_Thm_U.THM_In_u8HVACSts;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bFlag_HeatShort_Blw_Req = MBD_INPUT_DEFAULT_NUM0;;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Rainfall = Sokon_X01_Thm_U.THM_In_u16Rainfall;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Solar = Sokon_X01_Thm_U.THM_In_u16Solar;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Wat_BatIn_A10 = Sokon_X01_Thm_U.THM_In_s16T_Wat_BatIn_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Wat_HVCHOut_A10 = Sokon_X01_Thm_U.THM_In_s16T_Wat_HVCHOut_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Wat_LTROut_A10 = Sokon_X01_Thm_U.THM_In_s16T_Wat_LTROut_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Wat_MotorIn_A10 = Sokon_X01_Thm_U.THM_In_s16T_Wat_MotorIn_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Wat_MotorOut_A10 = Sokon_X01_Thm_U.THM_In_s16T_Wat_MotorOut_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16TbatMax_A10 = Sokon_X01_Thm_U.THM_In_s16TbatMax_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16TbatAvr_A10 = Sokon_X01_Thm_U.THM_In_s16TbatAvr_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16TbatMin_A10 = Sokon_X01_Thm_U.THM_In_s16TbatMin_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8BAT_CoolHeatLv = Sokon_X01_Thm_U.THM_In_u8BAT_CoolHeatLv;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_BAT_Wat_Set_A10 = Sokon_X01_Thm_U.THM_In_s16T_BAT_Wat_Set_A10;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8Mot_CoolLv = Sokon_X01_Thm_U.THM_In_u8Mot_CoolLv;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8TWValve_HC_Position = Sokon_X01_Thm_U.THM_In_u8TWValve_HC_Position;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8TWValve_LTR_Position = Sokon_X01_Thm_U.THM_In_u8TWValve_LTR_Position;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8TWValve_BAT_Position = Sokon_X01_Thm_U.THM_In_u8TWValve_BAT_Position;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8HVCH_Status = Sokon_X01_Thm_U.THM_In_u8HVCH_Status;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Pump_HVCH = Sokon_X01_Thm_U.THM_In_u16Pump_HVCH;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Pump_Motor = Sokon_X01_Thm_U.THM_In_u16Pump_Motor;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16Pump_Bat = Sokon_X01_Thm_U.THM_In_u16Pump_Bat;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u8IgnSts = Sokon_X01_Thm_U.THM_In_u8IgnSts;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_u16PowerHVCH = Sokon_X01_Thm_U.THM_In_u16PowerHVCH;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_P_Ref_CondOut = Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_CondOut;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_P_Ref_EvaOut = Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_EvaOut;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_P_Ref_CHILOut = Sokon_X01_Thm_U.THM_In_bDTC_P_Ref_CHILOut;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_T_Ref_CHILOut = Sokon_X01_Thm_U.THM_In_bDTC_T_Ref_CHILOut;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_T_Ref_EDCIn = Sokon_X01_Thm_U.THM_In_bDTC_T_Ref_EDCIn;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_Teva_Front = Sokon_X01_Thm_U.THM_In_bDTC_Teva_Front;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_Tamb = Sokon_X01_Thm_U.THM_In_bDTC_Tamb;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_SOV_Eva = Sokon_X01_Thm_U.THM_In_bDTC_SOV_Eva;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_SOV_OutEva = Sokon_X01_Thm_U.THM_In_bDTC_SOV_OutEva;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_SOV_TXVOutEva = Sokon_X01_Thm_U.THM_In_bDTC_SOV_TXVOutEva;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_EXV_Eva_Pos = Sokon_X01_Thm_U.THM_In_bDTC_EXV_Eva_Pos;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_EXV_Chil_Pos = Sokon_X01_Thm_U.THM_In_bDTC_EXV_Chil_Pos;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_BLW_Front = Sokon_X01_Thm_U.THM_In_bDTC_BLW_Front;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_EDC_Front = Sokon_X01_Thm_U.THM_In_bDTC_EDC_Front;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_TWValve_HC = Sokon_X01_Thm_U.THM_In_bDTC_TWValve_HC;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_TWValve_LTR = Sokon_X01_Thm_U.THM_In_bDTC_TWValve_LTR;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_TWValve_BAT = Sokon_X01_Thm_U.THM_In_bDTC_TWValve_BAT;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_HVCH = Sokon_X01_Thm_U.THM_In_bDTC_HVCH;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_Pump_HVCH = Sokon_X01_Thm_U.THM_In_bDTC_Pump_HVCH;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_Pump_Motor = Sokon_X01_Thm_U.THM_In_bDTC_Pump_Motor;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_bDTC_Pump_Bat = Sokon_X01_Thm_U.THM_In_bDTC_Pump_Bat;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_In_s16T_Ref_EDCOut_A10 = Sokon_X01_Thm_U.THM_In_s16T_Ref_EDCOut_A10;
  /**************************data to uppc --> MBD OUT********************************/
  /**************************MBD output data display on uppc*************************/
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u16Ncomp_Rpm_Req = Sokon_X01_Thm_Y.THM_Out_u16Ncomp_Rpm_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_bSOV_Eva_Req = Sokon_X01_Thm_Y.THM_Out_bSOV_Eva_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_bSOV_OutEva_Req = Sokon_X01_Thm_Y.THM_Out_bSOV_OutEva_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_bSOV_TXVOutEva_Req = Sokon_X01_Thm_Y.THM_Out_bSOV_TXVOutEva_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u16EXV_Eva_Pos_Req = Sokon_X01_Thm_Y.THM_Out_u16EXV_Eva_Pos_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u16EXV_Chil_Pos_Req = Sokon_X01_Thm_Y.THM_Out_u16EXV_Chil_Pos_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8HpWorkMode_Req = Sokon_X01_Thm_Y.THM_Out_u8HpWorkMode_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8AGS_Position_Req = Sokon_X01_Thm_Y.THM_Out_u8AGS_Position_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8FRFAN_PWM_Req = Sokon_X01_Thm_Y.THM_Out_u8FRFAN_PWM_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8Mix_Left_Req = Sokon_X01_Thm_Y.THM_Out_u8Mix_Left_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8Mix_Right_Req = Sokon_X01_Thm_Y.THM_Out_u8Mix_Right_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8DTC_Ref_System = Sokon_X01_Thm_Y.THM_Out_u8DTC_Ref_System;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8DTC_Ref_Component = Sokon_X01_Thm_Y.THM_Out_u8DTC_Ref_Component;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_bDTC_EvaFreeze = Sokon_X01_Thm_Y.THM_Out_bDTC_EvaFreeze;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_bDTC_OutEvaFreeze = Sokon_X01_Thm_Y.THM_Out_bDTC_OutEvaFreeze;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8TWValve_HC_Req = Sokon_X01_Thm_Y.THM_Out_u8TWValve_HC_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8TWValve_LTR_Req = Sokon_X01_Thm_Y.THM_Out_u8TWValve_LTR_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8TWValve_BAT_Req = Sokon_X01_Thm_Y.THM_Out_u8TWValve_BAT_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u8HVCH_Req = Sokon_X01_Thm_Y.THM_Out_u8HVCH_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u16Pump_HVCH_Req = Sokon_X01_Thm_Y.THM_Out_u16Pump_HVCH_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u16Pump_Motor_Req = Sokon_X01_Thm_Y.THM_Out_u16Pump_Motor_Req;
  AppDiag_uniSendToPcDisplayData.strSendToPcDisplayData.THM_Out_u16Pump_Bat_Req = Sokon_X01_Thm_Y.THM_Out_u16Pump_Bat_Req;
}

static void vidiviCtrlMng(void)
{
  vidAppBlwMotorMng(strBlwVolTab[Sokon_X01_Thm_U.THM_In_u8BlwLv_Real]);
  vidAppMixMotorMng(Sokon_X01_Thm_Y.THM_Out_u8Mix_Left_Req,Sokon_X01_Thm_Y.THM_Out_u8Mix_Right_Req);
  vidAppModeMotorMng(Sokon_X01_Thm_Y.THM_Out_u8HVACMode_Req);
  vidAppIntakeMotorMng(Sokon_X01_Thm_Y.THM_Out_u8HVACIntake_Req);
}
static void vidRlyCtrlMng(void)
{

  if(Sokon_X01_Thm_U.THM_In_u8IgnSts == MBD_INPUT_DEFAULT_NUM2)
  {
    u8RLY_InitReq = RLY_ON;
  }
  else
  {
    u8RLY_InitReq = RLY_OFF;
  }
  CMB_vidSetSignalState(FAN_RLY4,u8RLY_InitReq);
  CMB_vidSetSignalState(BLW_RLY3,u8RLY_InitReq); 
}

static void vidWaterWayMng(void)
{
    if((IfRteApp_Get_DCDCReqFromCAN()==1u)||(IfRteApp_Get_OBCCoolingReqFromCAN()==1u))
    {
      //twv position set
      EcvDrv_vidSetEcvPercentPosi(u8ECV_HVAC_ID, 100u);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_BAT_ID, 100u);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_MOTOR_ID,0u);  
      //pump speed set
      PumpHVAC_vidSetSpdReq(0u);
      PumpBat_vidSetSpdReq(0u);
      PumpMotor_vidSetSpdReq(0u);
      //fan speed set
      Fun_vidSetFunDuty(Fun1 ,0u);
      Fun_vidSetFunDuty(Fun2 , 55u);    
    }
    else if((IfRteApp_Get_ADCCFlowReqFromCAN()>2u)||(IfRteApp_Get_TMFFlowReqFromCAN()>2u)||(IfRteApp_Get_TMRFlowReqFromCAN()>2u))
    {
      if((IfRteApp_Get_ADCCFlowReqFromCAN()<15u)&&(IfRteApp_Get_TMFFlowReqFromCAN()<15u)&&(IfRteApp_Get_TMRFlowReqFromCAN()<15u))
      {//twv position set
      EcvDrv_vidSetEcvPercentPosi(u8ECV_HVAC_ID, 100u);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_BAT_ID, 100u);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_MOTOR_ID,0u);  
      //pump speed set
      PumpHVAC_vidSetSpdReq(0u);
      PumpBat_vidSetSpdReq(0u);
      PumpMotor_vidSetSpdReq(0u);
      //fan speed set
      Fun_vidSetFunDuty(Fun1 ,0u);
      Fun_vidSetFunDuty(Fun2 , 0u);  
      }
      else
      {
      EcvDrv_vidSetEcvPercentPosi(u8ECV_HVAC_ID, 100u);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_BAT_ID, 100u);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_MOTOR_ID,0u);  
      PumpHVAC_vidSetSpdReq(0u);
      PumpBat_vidSetSpdReq(0u);
      PumpMotor_vidSetSpdReq(0u);
      Fun_vidSetFunDuty(Fun1 , 0u);
      Fun_vidSetFunDuty(Fun2 , 0u);          
      }
    }
    else
    {
      //twv position set
      EcvDrv_vidSetEcvPercentPosi(u8ECV_HVAC_ID, AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8TWValve_HC_Req);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_BAT_ID, AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8TWValve_BAT_Req);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_MOTOR_ID, AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8TWValve_LTR_Req);  
      //pump speed set
      PumpHVAC_vidSetSpdReq(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16Pump_HVCH_Req);
      PumpBat_vidSetSpdReq(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16Pump_Bat_Req);
      PumpMotor_vidSetSpdReq(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16Pump_Motor_Req);
      //fan speed set
      Fun_vidSetFunDuty(Fun1 , AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8FRFAN_PWM_Req);
      Fun_vidSetFunDuty(Fun2 , AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8FRFAN_PWM_Req);        
    }
}
static void vidAppMbdInterfaceRefreshOutput(void)
{
  //AppDiag_uniRecvFormPcData.strRecvFormPcData.Diag_u8manualCtrlMode = HP_SYSTEM_MANUAL_CTRL;
  vidiviCtrlMng();
  vidRlyCtrlMng();
  /*****************code put here*****************/
  if( HP_SYSTEM_AUTO_CTRL == AppDiag_uniRecvFormPcData.strRecvFormPcData.Diag_u8manualCtrlMode )
  {
    /**************************AUTO control mode*******************************/  
    /**************************use data from MBD OUT***************************/         
    //EDC speed set
    vidAppEdcMng(Sokon_X01_Thm_Y.THM_Out_u16Ncomp_Rpm_Req);
    //SOV status set
    SovDrv_vidSetSignalState(u8SOV1_ID,Sokon_X01_Thm_Y.THM_Out_bSOV_Eva_Req);
    SovDrv_vidSetSignalState(u8SOV2_ID,Sokon_X01_Thm_Y.THM_Out_bSOV_OutEva_Req);
    SovDrv_vidSetSignalState(u8SOV3_ID,Sokon_X01_Thm_Y.THM_Out_bSOV_TXVOutEva_Req);
    //exv position set
    ExvDrv_vidSetDestStepPosition(u8EXV_CHILLER_ID,Sokon_X01_Thm_Y.THM_Out_u16EXV_Chil_Pos_Req);
    ExvDrv_vidSetDestStepPosition(u8EXV_EVAP_ID,Sokon_X01_Thm_Y.THM_Out_u16EXV_Eva_Pos_Req);
    //ExvDrv_vidSetInitReq();
    //ptc power output
    vidAppHvchMng(Sokon_X01_Thm_Y.THM_Out_u8HVCH_Req);
    //twv position set
    EcvDrv_vidSetEcvPercentPosi(u8ECV_HVAC_ID, Sokon_X01_Thm_Y.THM_Out_u8TWValve_HC_Req);
    EcvDrv_vidSetEcvPercentPosi(u8ECV_BAT_ID, Sokon_X01_Thm_Y.THM_Out_u8TWValve_BAT_Req);
    EcvDrv_vidSetEcvPercentPosi(u8ECV_MOTOR_ID, Sokon_X01_Thm_Y.THM_Out_u8TWValve_LTR_Req);
    //pump power output
    PumpHVAC_vidSetSpdReq(Sokon_X01_Thm_Y.THM_Out_u16Pump_HVCH_Req);
    PumpBat_vidSetSpdReq(Sokon_X01_Thm_Y.THM_Out_u16Pump_Bat_Req);
    PumpMotor_vidSetSpdReq(Sokon_X01_Thm_Y.THM_Out_u16Pump_Motor_Req);	
    //fan set
    Fun_vidSetFunDuty(Fun1 , Sokon_X01_Thm_Y.THM_Out_u8FRFAN_PWM_Req);   
    //Fun_vidSetFunDuty(Fun1 , 0u);  
    //Fun_vidSetFunDuty(Fun2 , Sokon_X01_Thm_Y.THM_Out_u8FRFAN_PWM_Req);
  }
  else if( HP_SYSTEM_MANUAL_CTRL == AppDiag_uniRecvFormPcData.strRecvFormPcData.Diag_u8manualCtrlMode )
  {
    /**************************MANNUAL control mode****************************/  
    /**************************use data from UPPC set**************************/
    //EDC speed set
    vidAppEdcMng(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16Ncomp_Rpm_Req);
    //HVCH power set
    vidAppHvchMng(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8HVCH_Req);
    //SOV status set
    SovDrv_vidSetSignalState(u8SOV1_ID,AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_bSOV_Eva_Req);
    SovDrv_vidSetSignalState(u8SOV2_ID,AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_bSOV_OutEva_Req);
    SovDrv_vidSetSignalState(u8SOV3_ID,AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_bSOV_TXVOutEva_Req);
    //exv position set
    ExvDrv_vidSetDestStepPosition(u8EXV_CHILLER_ID,AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16EXV_Chil_Pos_Req);
    ExvDrv_vidSetDestStepPosition(u8EXV_EVAP_ID,AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16EXV_Eva_Pos_Req);
    //ExvDrv_vidSetInitReq();
    //water way mng
    //vidWaterWayMng();
          EcvDrv_vidSetEcvPercentPosi(u8ECV_HVAC_ID, AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8TWValve_HC_Req);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_BAT_ID, AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8TWValve_BAT_Req);
      EcvDrv_vidSetEcvPercentPosi(u8ECV_MOTOR_ID, AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8TWValve_LTR_Req);  
      //pump speed set
      PumpHVAC_vidSetSpdReq(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16Pump_HVCH_Req);
      PumpBat_vidSetSpdReq(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16Pump_Bat_Req);
      PumpMotor_vidSetSpdReq(AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u16Pump_Motor_Req);
      //fan speed set
      Fun_vidSetFunDuty(Fun1 , AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8FRFAN_PWM_Req);
      Fun_vidSetFunDuty(Fun2 , AppDiag_uniRecvFormPcData.strRecvFormPcData.THM_Out_u8FRFAN_PWM_Req); 
  }
  else
  {
    /******upper pc set error value******/
    /*************do nothing*************/
  } 
}


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
extern void AppMbdInterface_vidInit(void)
{
  /********************************MBD data init*********************************/ 
  Sokon_X01_Thm_initialize();
}

extern void AppMbdInterface_vidManage(void)
{
  //mbd input
  vidHpMbdInterfaceRefreshInput();
  //add model step function start
  Sokon_X01_Thm_step();
  vidAppMbdInterfaceRefreshOutput(); 
}



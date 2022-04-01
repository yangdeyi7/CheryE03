/******************************************************************************/
/* PROJECT  :  XXXX                                                           */
/******************************************************************************/
/*!Layer           : LINIF                                                    */
/*                                                                            */
/*!Component       : LINIF                                                    */
/*!Description     : Contains the interface of LIN                            */
/*                                                                            */
/*!Module          : LinIf                                                    */
/*!Description     : LinIf                                                    */
/*                                                                            */
/*!File            : LinIf_cfg.h                                              */
/*                                                                            */
/*!Scope           : Private                                                  */
/*                                                                            */
/*!Target          : RH850F1L                                                 */
/*                                                                            */
/*!Vendor          : VALEO Climate Control Shashi                             */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2016 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/A$*/
/* $Revision::   1.2     $$Author::   yunxin.liu      $$Date::   Feb 14 2017 $*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/AppESS.c-arc  $
 * 
                                                                              */
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */

/******************************************************************************/

#ifndef LINIF_CFG_H
#define LINIF_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Lin_Cfg_rh850.h"
/* #include "LinTp.h" */


/*******************************************************************************
*   Common Macro
*******************************************************************************/
#define  LINIF_CDD              (0)
#define  LINIF_LIN_SM           (1)
#define  LINIF_PDUR             (2)
#define  LINIF_NO_CALLBACK      (3)

#define  LINIF_NORMAL           (0)
#define  LINIF_SLEEP            (1)

/*******************************************************************************
*   LinIfGeneral
*******************************************************************************/
/* LinIfGlobalConfig */
/* This parameter's uint is ms.*/
#define LINIF_TIME_BASE                              (10)/* not supported */

/* LinIfGeneral */
#define LINIF_CANCEL_TRANSMIT_SUPPORTED              STD_ON
                                      
#define LINIF_DEV_ERROR_DETECT                       STD_ON

#define LINIF_MULTIPLE_DRIVER_SUPPORT                STD_OFF/* not supported */

#define LINIF_MULTIPLE_TRCV_DRIVER_SUPPORTED         STD_OFF/* not supported */

#define LINIF_OPTIONAL_REQUEST_SUPPORTED             STD_OFF/* not supported */

#define LINIF_TP_SUPPORTED                           STD_OFF/* not supported */

#define LINIF_COM_SUPPORTED                          STD_OFF

#define LINIF_VERSION_INFO_API                       STD_OFF

#define LINIF_SPORADIC_FRAME_SUPPORTED               STD_OFF

#define LINIF_EVENT_TRIGGER_FRAME_SUPPORTED          STD_OFF

#define LINIF_FIXED_SDU_SUPPORTED                    STD_OFF

#define LINIF_SLAVETOSLAVE_SUPPORTED                 LIN_SLAVETOSLAVE_SUPPORTED

#define LINIF_TRCV_DRIVER_SUPPORTED                  STD_OFF/* not supported */



#define LINIF_VENDOR_ID_VALUE                       ((uint16)128)
#define LINIF_MODULE_ID_VALUE                       ((uint16)82)
#define LINIF_INSTANCE_ID_VALUE_0                   ((uint8)0) 
#define LINIF_SW_MAJOR_VERSION_VALUE                (1)
#define LINIF_SW_MINOR_VERSION_VALUE                (2)
#define LINIF_SW_PATCH_VERSION_VALUE                (0)

/* the linif channel number must equal to lin driver */
#define LINIF_CHANNEL_NUM                           1u  



/*******************************************************************************
*   LinIfChannel
*******************************************************************************/

#if(LINIF_CHANNEL_NUM == 0)
#error " LINIF_CHANNEL_NUM can not be 0 "
#endif

#if(LINIF_CHANNEL_NUM > 1)

#define LINIF_CHANNEL0_ID                           (0) 

#define LINIF_CHANNEL0_INDEX                        (0)/* not supported */

#define LINIF_CHANNEL0_COMM_NETWORK_HANDLE_REF      (0)/* not supported */

#endif

#if(LINIF_CHANNEL_NUM > 2)

#define LINIF_CHANNEL1_ID                           (1) 

#define LINIF_CHANNEL1_INDEX                        (0)/* not supported */

#define LINIF_CHANNEL1_COMM_NETWORK_HANDLE_REF      (0)/* not supported */

#endif


/*******************************************************************************
*   Schedule & Table handle  
*******************************************************************************/
#define LINIF_NULL_TABLE                            (0)/* can not be removed */

/*******************************************************************************
*   Callback Functions On/Off  
*******************************************************************************/
/* Goto sleep Confimation */
#define LinIfGotoSleepConfirmationUL                 LINIF_CDD

extern void sleepIndication(uint8 Channel,boolean success);
#if(LinIfGotoSleepConfirmationUL == LINIF_NO_CALLBACK)

#elif(LinIfGotoSleepConfirmationUL == LINIF_CDD)
    #define  LinIfGotoSleepConfirmationName          sleepIndication
#elif(LinIfGotoSleepConfirmationUL == LINIF_LIN_SM)
    #define  LinIfGotoSleepConfirmationName          LINIF_NULL
#endif

/* Schedule Request Confimation */
#define LinIfScheduleRequestConfirmationUL           LINIF_NO_CALLBACK

#if(LinIfScheduleRequestConfirmationUL == LINIF_NO_CALLBACK)

#elif(LinIfScheduleRequestConfirmationUL == LINIF_CDD)
    #define  LinIfScheduleRequestConfirmationName    LINIF_NULL
#elif(LinIfScheduleRequestConfirmationUL == LINIF_LIN_SM)
    #define  LinIfScheduleRequestConfirmationName    LINIF_NULL
#endif

/* Wakeup  Confimation */
#define LinIfWakeUpConfirmationUL                    LINIF_CDD

extern void wakeIndication(uint8 Channel,boolean success);

#if(LinIfWakeUpConfirmationUL == LINIF_NO_CALLBACK)

#elif(LinIfWakeUpConfirmationUL == LINIF_CDD)
    #define  LinIfWakeUpConfirmationName             wakeIndication
#elif(LinIfWakeUpConfirmationUL == LINIF_LIN_SM)
    #define  LinIfWakeUpConfirmationName             LINIF_NULL
#endif

/* TriggerTransmit  Confimation */
#define LinIfTriggerTransmitUL                       LINIF_CDD

#if(LinIfTriggerTransmitUL == LINIF_NO_CALLBACK)

#elif(LinIfTriggerTransmitUL == LINIF_CDD)
    #define  LinIfTriggerTransmitName                LINIF_NULL
#elif(LinIfTriggerTransmitUL == LINIF_PDUR)
    #define  LinIfTriggerTransmitName                LINIF_NULL
#endif

/* Tx Confimation */
#define LinIfUserTxUL                                LINIF_CDD

#if(LinIfUserTxUL == LINIF_NO_CALLBACK)

#elif(LinIfUserTxUL == LINIF_CDD)
    #define  LinIfUserTxName                         LINIF_NULL
#endif

/* Rx Indication */
/* extern void rxIndication(uint16 LinRxPduId, const LinIf_tstrPduInfoType * PduInfoPtr); */

#define LinIfUserRxIndicationUL                      LINIF_CDD
#if(LinIfUserRxIndicationUL == LINIF_NO_CALLBACK)

#elif(LinIfUserRxIndicationUL == LINIF_CDD)
    #define  LinIfUserRxIndicationName               rxIndication//LINIF_NULL
#endif


/* Error Indication */
#define LinIfErrorIndicationUL                       LINIF_CDD
extern void ERRIndication(uint16 LinPduId, LIN_tenuStatusType status);

#if(LinIfErrorIndicationUL == LINIF_NO_CALLBACK)
  
#elif(LinIfErrorIndicationUL == LINIF_CDD)
    #define  DTC_vidLinErrIndication               ERRIndication // LINIF_NULL
#endif

#if(LINIF_TP_SUPPORTED == STD_ON)
/* TpTx Confimation */
#define LinIfTpTxConfirmationName               Lin_Tp_TxConfirmation//LINIF_NULL

/* TpRx Indication */
#define LinIfTpRxIndicationName                 Lin_Tp_RxIndication//LINIF_NULL
#endif

#if(LINIF_COM_SUPPORTED == STD_OFF)
/*Signal define*/
/*******************************************************************************
*   number of Tx Signal
*******************************************************************************/
/*Chiller Exv cmd 6*/
#define LIN_TXSIG_CHILLER_EXV_POSI_CMD     (0u)
#define LIN_TXSIG_CHILLER_EXV_SELE_CMD     (1u)
#define LIN_TXSIG_CHILLER_EXV_INIT_CMD     (2u) 
/*Evap Exv cmd 8*/
#define LIN_TXSIG_EVAP_EXV_POSI_CMD          (3u)
#define LIN_TXSIG_EVAP_EXV_SELE_CMD          (4u)
#define LIN_TXSIG_EVAP_EXV_INIT_CMD          (5u)
/*Hvwh Set1 cmd 4*/
#define LIN_TXSIG_HVWH_CMD_CTPE_EAU_BT       (6u)
#define LIN_TXSIG_HVWH_COUPURE_CONSO_CPT     (7u)
#define LIN_TXSIG_HVWH_PWR_LIMIT_HVWH        (8u)
/*Hvwh Set2 cmd 59*/
#define LIN_TXSIG_HVWH_CDE_PV_LIN            (9u)
/*Blw cmd 10*/
#define LIN_TXSIG_BLW_RX_FREQUENCY           (10)
#define LIN_TXSIG_BLW_CODE_VEHICULE          (11)
#define LIN_TXSIG_BLW_BLOWER_RAMP            (12)
#define LIN_TXSIG_BLW_BLOWER_SPEED           (13)
#define LIN_TXSIG_BLW_SAFETY_SPEED           (14)
/*TWV_HVAC cmd 34*/
#define LIN_TXSIG_HVAC_TWV_POSSET               (15)
#define LIN_TXSIG_HVAC_TWV_MOVEENABLE           (16)
#define LIN_TXSIG_HVAC_TWV_REQMOTOREMGYSTOP     (17)
#define LIN_TXSIG_HVAC_TWV_REQMOTOROPTRECOVERY  (18)
/*TWV_BAT cmd 39*/
#define LIN_TXSIG_BAT_TWV_POSSET                (19)
#define LIN_TXSIG_BAT_TWV_MOVEENABLE            (20)
#define LIN_TXSIG_BAT_TWV_REQMOTOREMGYSTOP      (21)
#define LIN_TXSIG_BAT_TWV_REQMOTOROPTRECOVERY   (22)
/*TWV_MOTOR cmd 44*/
#define LIN_TXSIG_MOTOR_TWV_POSSET              (23)
#define LIN_TXSIG_MOTOR_TWV_MOVEENABLE          (24)
#define LIN_TXSIG_MOTOR_TWV_REQMOTOREMGYSTOP    (25)
#define LIN_TXSIG_MOTOR_TWV_REQMOTOROPTRECOVERY (26)
/*EAC cmd 0x1a*/
#define LIN_TXSIG_EAC_COMPSPD_TARGET            (27)
#define LIN_TXSIG_EAC_COMP_ON_RQ                (28)
#define LIN_TXSIG_EAC_COMP_FAULT_CLAER_RQ       (29)
#define LIN_TXSIG_EAC_COMP_HVINTERLOCK_RQ       (30)
#define LIN_TXSIG_EAC_COMP_HVDISCHARGE_RQ       (31)
/*Pump-hvac cmd xx*/
#define LIN_TXSIG_PUMP_ACT_CTRL_byNAD              (32)
#define LIN_TXSIG_PUMP_ACT_CTRL_byProgram          (33)
#define LIN_TXSIG_PUMP_ACT_CTRL_byStallDetector    (34)
#define LIN_TXSIG_PUMP_ACT_CTRL_byClearEventFlags  (35)
#define LIN_TXSIG_PUMP_ACT_CTRL_byTargetSpeed      (36)
#define LIN_TXSIG_PUMP_ACT_CTRL_byStopMode         (37)
/*Pump-bat cmd xx*/
#define LIN_TXSIG_PUMP_BAT_CTRL_byNAD              (38)
#define LIN_TXSIG_PUMP_BAT_CTRL_byProgram          (39)
#define LIN_TXSIG_PUMP_BAT_CTRL_byStallDetector    (40)
#define LIN_TXSIG_PUMP_BAT_CTRL_byClearEventFlags  (41)
#define LIN_TXSIG_PUMP_BAT_CTRL_byTargetSpeed      (42)
#define LIN_TXSIG_PUMP_BAT_CTRL_byStopMode         (43)
/*Pump-motor cmd xx*/
#define LIN_TXSIG_PUMP_MOTOR_CTRL_byNAD              (44)
#define LIN_TXSIG_PUMP_MOTOR_CTRL_byProgram          (45)
#define LIN_TXSIG_PUMP_MOTOR_CTRL_byStallDetector    (46)
#define LIN_TXSIG_PUMP_MOTOR_CTRL_byClearEventFlags  (47)
#define LIN_TXSIG_PUMP_MOTOR_CTRL_byTargetSpeed      (48)
#define LIN_TXSIG_PUMP_MOTOR_CTRL_byStopMode         (49)

#define LIN_TXSIGNUM	                           (50u)
/*******************************************************************************
*   number of Rx Signal
*******************************************************************************/
/*Chiller Exv Resp 20*/
#define LIN_RXSIG_CHILLER_EXV_POSI_ST      (0u)
#define LIN_RXSIG_CHILLER_EXV_MVT_ST       (1u)
#define LIN_RXSIG_CHILLER_EXV_STALL_DET    (2u)
#define LIN_RXSIG_CHILLER_EXV_DEF_ST       (3u)
#define LIN_RXSIG_CHILLER_EXV_COMM_ERR     (4u)
#define LIN_RXSIG_CHILLER_EXV_INT_FAULT    (5u)
#define LIN_RXSIG_CHILLER_EXV_PROT_FAULT   (6u)
#define LIN_RXSIG_CHILLER_EXV_VOLT_FAULT   (7u)
#define LIN_RXSIG_CHILLER_EXV_FAULT_STALL  (8u)
#define LIN_RXSIG_CHILLER_EXV_PRESS_LP     (9u)
#define LIN_RXSIG_CHILLER_EXV_TEMP_AC_LP   (10u)
/*Evap Exv Resp x*/
#define LIN_RXSIG_EVAP_EXV_POSI_ST           (11u)
#define LIN_RXSIG_EVAP_EXV_MVT_ST            (12u)
#define LIN_RXSIG_EVAP_EXV_STALL_DET         (13u)
#define LIN_RXSIG_EVAP_EXV_DEF_ST            (14u)
#define LIN_RXSIG_EVAP_EXV_COMM_ERR          (15u)
#define LIN_RXSIG_EVAP_EXV_INT_FAULT         (16u)
#define LIN_RXSIG_EVAP_EXV_PROT_FAULT        (17u)
#define LIN_RXSIG_EVAP_EXV_VOLT_FAULT        (18u)
#define LIN_RXSIG_EVAP_EXV_FAULT_STALL       (19u)
#define LIN_RXSIG_EVAP_EXV_PRESS_LP          (20u)
#define LIN_RXSIG_EVAP_EXV_TEMP_AC_LP        (21u)
/*HVWH STATUS Resp 37*/
#define LIN_RXSIG_HVWH_TEMP_EAU_CPT_T            (22u)
#define LIN_RXSIG_HVWH_I_CONSO_CTP_EAU_BT        (23u)
#define LIN_RXSIG_HVWH_DEFAUT_CTP_EAU            (24u)
#define LIN_RXSIG_HVWH_DEFAUT_SECU_CTP_EAU_BT    (25u)
#define LIN_RXSIG_HVWH_RESP_ERROR_CTPE           (26u)
#define LIN_RXSIG_HVWH_INTERLOCK_STATUS          (27u)
#define LIN_RXSIG_HVWH_LIMIT_POWER_HVWH          (28u)
#define LIN_RXSIG_HVWH_DEFAUT_ALIM_BT            (29u)
#define LIN_RXSIG_HVWH_DEFAUT_FONCT_INTEMPESTIF  (30u)
#define LIN_RXSIG_HVWH_DEFAUT_NON_FONCT_PERM     (31u)
#define LIN_RXSIG_HVWH_DEFAUT_PROTECTION         (32u)
#define LIN_RXSIG_HVWH_DEFAUT_SONDE_TEMP         (33u)
#define LIN_RXSIG_HVWH_DEFAUT_TENSION_BT         (34u)
#define LIN_RXSIG_HVWH_TENSION_LV_CTPE_ELEC      (35u)
/*Blw Status 11*/
#define LIN_RXSIG_BLW_BLOWER_STATUS_MOTOR        (36u)
#define LIN_RXSIG_BLW_BLOWER_DIAG_FLAG1          (37u)
#define LIN_RXSIG_BLW_BLOWER_ResponseError       (38u)
#define LIN_RXSIG_BLW_BLOWER_DIAG_FLAG2          (39u)
#define LIN_RXSIG_BLW_BLOWER_IBATI               (40u)
#define LIN_RXSIG_BLW_BLOWER_ROTATION_SPEED      (41u)
#define LIN_RXSIG_BLW_BLOWER_TEMPERATURE         (42u)
#define LIN_RXSIG_BLW_BLOWER_UBATI               (43u)
#define LIN_RXSIG_BLW_BLOWER_SUPPLIER            (44u)
#define LIN_RXSIG_BLW_BLOWER_UMOTOR              (45u)
/*Blw Status 12*/
#define LIN_RXSIG_BLW_BLOWER_TORQUE              (46u)
/* TWV_HVAC Status 36*/
#define LIN_RXSIG_HVAC_TWV_RESP_ERROR            (47u)
#define LIN_RXSIG_HVAC_HVAC_TWV_OVERVOLTAGEFLT   (48u)
#define LIN_RXSIG_HVAC_TWV_OVERCURRENT           (49u)
#define LIN_RXSIG_HVAC_TWV_OVERTEMPFLT           (50u)
#define LIN_RXSIG_HVAC_TWV_UNDERVOLTAGEFLT       (51u)
#define LIN_RXSIG_HVAC_TWV_INITSTA               (52u)
#define LIN_RXSIG_HVAC_TWV_CCWFLG                (53u)
#define LIN_RXSIG_HVAC_TWV_MOTORSTA              (54u)
#define LIN_RXSIG_HVAC_TWV_REALSTA               (55u)
/* TWV_BAT Status 41*/
#define LIN_RXSIG_BAT_TWV_RESP_ERROR            (56u)
#define LIN_RXSIG_BAT_HVAC_TWV_OVERVOLTAGEFLT   (57u)
#define LIN_RXSIG_BAT_TWV_OVERCURRENT           (58u)
#define LIN_RXSIG_BAT_TWV_OVERTEMPFLT           (59u)
#define LIN_RXSIG_BAT_TWV_UNDERVOLTAGEFLT       (60u)
#define LIN_RXSIG_BAT_TWV_INITSTA               (61u)
#define LIN_RXSIG_BAT_TWV_CCWFLG                (62u)
#define LIN_RXSIG_BAT_TWV_MOTORSTA              (63u)
#define LIN_RXSIG_BAT_TWV_REALSTA               (64u)
/* TWV_MOTOR Status 47*/
#define LIN_RXSIG_MOTOR_TWV_RESP_ERROR            (65u)
#define LIN_RXSIG_MOTOR_HVAC_TWV_OVERVOLTAGEFLT   (66u)
#define LIN_RXSIG_MOTOR_TWV_OVERCURRENT           (67u)
#define LIN_RXSIG_MOTOR_TWV_OVERTEMPFLT           (68u)
#define LIN_RXSIG_MOTOR_TWV_UNDERVOLTAGEFLT       (69u)
#define LIN_RXSIG_MOTOR_TWV_INITSTA               (70u)
#define LIN_RXSIG_MOTOR_TWV_CCWFLG                (71u)
#define LIN_RXSIG_MOTOR_TWV_MOTORSTA              (72u)
#define LIN_RXSIG_MOTOR_TWV_REALSTA               (73u)
/*EAC Status 0x1b*/
#define LIN_RXSIG_EAC_COMPSPD_EST                 (74u)
#define LIN_RXSIG_EAC_HV_INPUTCURR                (75u)
#define LIN_RXSIG_EAC_HV_VOLT                     (76u)
#define LIN_RXSIG_EAC_INVRTTEMP                   (77u)
#define LIN_RXSIG_EAC_INVRTPHASECURR              (78u)
#define LIN_RXSIG_EAC_SP_BRDTEMP_LMT              (79u)
#define LIN_RXSIG_EAC_SP_CURRLMT                  (80u)
#define LIN_RXSIG_EAC_SP_HVVOLT_FLT               (81u)
#define LIN_RXSIG_EAC_SP_TEMP_EXCESS              (82u)
#define LIN_RXSIG_EAC_SP_COMM_FLT                 (83u)
#define LIN_RXSIG_EAC_SP_INVRTPWRSUP_FLT          (84u)
#define LIN_RXSIG_EAC_OFF_SENS_FLT                (85u)
#define LIN_RXSIG_EAC_OFF_SHRTCURR                (86u)
#define LIN_RXSIG_EAC_OFF_STALL                   (87u)
#define LIN_RXSIG_EAC_RSERR                       (88u)
#define LIN_RXSIG_EAC_COMP_HVINTERLOCK_STAT       (89u)
#define LIN_RXSIG_EAC_COMP_OPRTN_STAT             (90u)

/*Pump-hvac Status 0x13*/
#define LIN_RXSIG_PUMP_ACT_STATUS_byResponseError          (91u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byOverTemperature        (92u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byElectricDefect         (93u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byVoltageError           (94u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byEmergencyOccurred      (95u)
#define LIN_RXSIG_PUMP_ACT_STATUS_bySpeedError             (96u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byStallOccurred          (97u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byReset                  (98u)
#define LIN_RXSIG_PUMP_ACT_STATUS_bySpeedStatus            (99u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byActualLA               (100u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byActualMotorVoltage     (101u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byFocMode                (102u)
#define LIN_RXSIG_PUMP_ACT_STATUS_byPwmMode                (103u)
/*Pump-hvac Status 0x17*/
#define LIN_RXSIG_PUMP_BAT_STATUS_byResponseError          (104u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byOverTemperature        (105u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byElectricDefect         (106u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byVoltageError           (107u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byEmergencyOccurred      (108u)
#define LIN_RXSIG_PUMP_BAT_STATUS_bySpeedError             (109u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byStallOccurred          (110u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byReset                  (111u)
#define LIN_RXSIG_PUMP_BAT_STATUS_bySpeedStatus            (112u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byActualLA               (113u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byActualMotorVoltage     (114u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byFocMode                (115u)
#define LIN_RXSIG_PUMP_BAT_STATUS_byPwmMode                (116u)
/*Pump-hvac Status 0x1F*/
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byResponseError          (117u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byOverTemperature        (118u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byElectricDefect         (119u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byVoltageError           (120u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byEmergencyOccurred      (121u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_bySpeedError             (122u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byStallOccurred          (123u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byReset                  (124u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_bySpeedStatus            (125u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byActualLA               (126u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byActualMotorVoltage     (127u)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byFocMode                (128)
#define LIN_RXSIG_PUMP_MOTOR_STATUS_byPwmMode                (129u)

#define LIN_RXSIGNUM                              (130u)

/*****************************************************************************/
typedef struct
{
  uint8 u8ChillerExvPosiCmd_L     :8;
  uint8 u8ChillerExvPosiCmd_H     :8;
  
  uint8 u8ChillerExvSeleCmd       :2;
  uint8 u8ChillerExvInitCmd       :1;
  uint8 u8Res0                    :1;
  uint8 u8Res1                    :4;
  
  uint8 u8Res2                    :8;
}LINIF_tstrChillerExvCmd;


typedef struct
{
  uint8 u8ChillerExvPosiSt_L     :8;
  uint8 u8ChillerExvPosiSt_H     :8;
  
  uint8 u8ChillerExvMoveSt       :1;
  uint8 u8ChillerExvStallDet     :1;
  uint8 u8ChillerExvDefSt        :1;
  uint8 u8ChillerExvComErr       :1;
  uint8 u8Res0                   :4;
  
  uint8 u8ChillerExvIntFault     :2;
  uint8 u8ChillerExvProtFault    :2;
  uint8 u8ChillerExvVoltFault    :2;
  uint8 u8ChillerExvFaultStall   :2;
  
  uint8 u8ChillerExvPreLp_L      :8;
  uint8 u8ChillerExvPreLp_H      :8;
  uint8 u8ChillerExvTempAcLp_L   :8;
  uint8 u8ChillerExvTempAcLp_H   :8;  
}LINIF_tstrChillerExvResp;
/*****************************************************************************/


typedef struct
{
  uint8 u8EvapExvPosiCmd_L     :8;
  uint8 u8EvapExvPosiCmd_H     :8;
  
  uint8 u8EvapExvSeleCmd       :2;
  uint8 u8EvapExvInitCmd       :1;
  uint8 u8Res0               :1;
  uint8 u8Res1               :4;
  
  uint8 u8Res2               :8;
}LINIF_tstrEvapExvCmd;


typedef struct
{
  uint8 u8EvapExvPosiSt_L     :8;
  uint8 u8EvapExvPosiSt_H     :8;
  
  uint8 u8EvapExvMoveSt       :1;
  uint8 u8EvapExvStallDet     :1;
  uint8 u8EvapExvDefSt        :1;
  uint8 u8EvapExvComErr       :1;
  uint8 u8Res0                :4;
  
  uint8 u8EvapExvIntFault     :2;
  uint8 u8EvapExvProtFault    :2;
  uint8 u8EvapExvVoltFault    :2;
  uint8 u8EvapExvFaultStall   :2;
  
  uint8 u8EvapExvPreLp_L      :8;
  uint8 u8EvapExvPreLp_H      :8;
  uint8 u8EvapExvTempAcLp_L   :8;
  uint8 u8EvapExvTempAcLp_H   :8;
}LINIF_tstrEvapExvResp;

/*****************************************************************************/


typedef struct
{
  uint8 u8Hvwh_cmd_ctpe_eau_bt     :7;
  uint8 u8Hvwh_coupure_conso_cpt   :1;
  
  uint8 u8Res0                     :1;
  uint8 u8Hvwh_cmd_pwr_limit_hvwh  :7;
}LINIF_tstrHvwhSet1Cmd;

typedef struct
{
  uint8 u8Hvwh_cde_pv_lin         :8;
  uint8 u8Hvwh_reserve_8          :8;
  uint8 u8Hvwh_reserve_16_L       :8;
  uint8 u8Hvwh_reserve_16_H       :8;
  uint8 u8Hvwh_reserve_16_2_L     :8;
  uint8 u8Hvwh_reserve_16_2_H     :8;
  uint8 u8Hvwh_reserve_16_3_L     :8;
  uint8 u8Hvwh_reserve_16_3_H     :8;
}LINIF_tstrHvwhSet2Cmd;

typedef struct
{
  uint8 u8Hvwh_temp_eau_cpt_bt                  :8;
  uint8 u8Hvwh_i_conso_ctp_eau_bt_L             :8;
  uint8 u8Hvwh_i_conso_ctp_eau_bt_H             :1;
  uint8 u8Hvwh_default_ctp_eau                  :1;
  uint8 u8Hvwh_default_secu_ctp_bt              :1;
  uint8 u8Hvwh_resp_error_ctpe                  :1;
  uint8 u8Hvwh_interlock_status                 :1;
  uint8 u8Hvwh_limit_power_hvwh                 :1;
  uint8 u8Hvwh_reserve_2                        :2;
  uint8 u8Hvwh_default_alim_bt                  :4;
  uint8 u8Hvwh_defaut_fonct_intempestif         :4;
  uint8 u8Hvwh_defaut_non_fonct_perm            :4;
  uint8 u8Hvwh_defaut_protection                :4;
  uint8 u8Hvwh_defaut_sonde_temp                :4;
  uint8 u8Hvwh_defaut_tension_bt                :4;
  uint8 u8Hvwh_tension_lv_ctpe_elec             :8;
  uint8 u8Hvwh_reserve_9                        :8;
}LINIF_tstrHvwhStatusResp;


typedef struct
{
  uint8 u8Blw_Rx_Frequency_L                    :8;
  uint8 u8Blw_Rx_Frequency_H                    :4;
  uint8 u8Res0                                  :4;
  uint8 u8Res1                                  :8;
  uint8 u8Res2                                  :8;
  uint8 u8Blw_Code_Vehicule                     :4;
  uint8 u8Blw_Blower_Ramp                       :4;
  uint8 u8Blw_Blower_Speed                      :8;
  uint8 u8Blw_Safety_Speed                      :8;
  uint8 u8Res3                                  :8;
}LINIF_tstrBlwCmd;

typedef struct
{
  uint8 u8Blw_Blower_Status_Motor               :3;
  uint8 u8Blw_Blower_Diag_Flag1                 :4;
  uint8 u8Blw_Blower_ResponseError              :1;
  uint8 u8Blw_Blower_Diag_Flag2                 :8;
  uint8 u8Blw_Blower_Ibatt                      :8;
  uint8 u8Blw_Blower_Rotation_Speed             :8;
  uint8 u8Blw_Blower_Temperature                :8;
  uint8 u8Blw_Blower_Ubatt                      :8;
  uint8 u8Blw_Blower_Supplier                   :8;
  uint8 u8Blw_Blower_Umotor                     :8;
}LINIF_tstrBlwStatus1;

typedef struct
{
  uint8 u8Blw_Blower_Torque_L                   :8;
  uint8 u8Blw_Blower_Torque_H                   :2;
  uint8 u8Res0                                  :6;
  uint8 u8Res1                                  :8;
  uint8 u8Res2                                  :8;
  uint8 u8Res3                                  :8;
  uint8 u8Res4                                  :8;
  uint8 u8Res5                                  :8;
  uint8 u8Res6                                  :8;
}LINIF_tstrBlwStatus2;


typedef struct
{
	uint8 u8Res0                                :8;
	uint8 u8Res1                                :8;
	uint8 u8Res2                                :8;
	uint8 u8TwvHvac_Hvac_Twv_PosSet             :8;
	uint8 u8TwvHvac_Hvac_Twv_MoveEnable           :1;
	uint8 u8Res3                                  :3;
	uint8 u8TwvHvac_Hvac_Twv_ReqMotorEmgyStop     :1;
	uint8 u8TwvHvac_Hvac_Twv_ReqMotorOptRecovery  :1;
	uint8 u8Res4                                  :2;
	uint8 u8Res5                                :8;
	uint8 u8Res6                                :8;
	uint8 u8Res7                                :8;
}LINIF_tstrTwvHvacCmd;

typedef struct
{
  uint8 u8TwvHvac_Hvac_Twv_Resp_Error           :1;
  uint8 u8TwvHvac_Hvac_Twv_OvervoltageFlt       :1;
  uint8 u8TwvHvac_Hvac_Twv_OverCurrent          :1;
  uint8 u8TwvHvac_Hvac_Twv_OverTempFlt          :1;
  uint8 u8TwvHvac_Hvac_Twv_UnderVoltageFlt      :1;
  uint8 u8TwvHvac_Hvac_Twv_InitSta              :1;
  uint8 u8TwvHvac_Hvac_Twv_Ccwflg               :1;
  uint8 u8TwvHvac_Hvac_Twv_MotorSta             :1;
  uint8 u8TwvHvac_Hvac_Twv_RealSta              :8;
  uint8 u8Res0                                  :8;
  uint8 u8Res1                                  :8;
  uint8 u8Res2                                  :8;
  uint8 u8Res3                                  :8;
  uint8 u8Res4                                  :8;
  uint8 u8Res5                                  :8;
}LINIF_tstrTwvHvacStatus;

typedef struct
{
	uint8 u8Res0                                :8;
	uint8 u8Res1                                :8;
	uint8 u8Res2                                :8;
	uint8 u8TwvBat_Bat_Twv_PosSet               :8;
	uint8 u8TwvBat_Bat_Twv_MoveEnable           :1;
	uint8 u8Res3                                :3;
	uint8 u8TwvBat_Bat_Twv_ReqMotorEmgyStop     :1;
	uint8 u8TwvBat_Bat_Twv_ReqMotorOptRecovery  :1;
	uint8 u8Res4                                :2;
	uint8 u8Res5                                :8;
	uint8 u8Res6                                :8;
	uint8 u8Res7                                :8;
}LINIF_tstrTwvBatCmd;

typedef struct
{
  uint8 u8TwvBat_Bat_Twv_Resp_Error           :1;
  uint8 u8TwvBat_Bat_Twv_OvervoltageFlt       :1;
  uint8 u8TwvBat_Bat_Twv_OverCurrent          :1;
  uint8 u8TwvBat_Bat_Twv_OverTempFlt          :1;
  uint8 u8TwvBat_Bat_Twv_UnderVoltageFlt      :1;
  uint8 u8TwvBat_Bat_Twv_InitSta              :1;
  uint8 u8TwvBat_Bat_Twv_Ccwflg               :1;
  uint8 u8TwvBat_Bat_Twv_MotorSta             :1;
  uint8 u8TwvBat_Bat_Twv_RealSta              :8;
  uint8 u8Res0                                  :8;
  uint8 u8Res1                                  :8;
  uint8 u8Res2                                  :8;
  uint8 u8Res3                                  :8;
  uint8 u8Res4                                  :8;
  uint8 u8Res5                                  :8;
}LINIF_tstrTwvBatStatus;

typedef struct
{
	uint8 u8Res0                                :8;
	uint8 u8Res1                                :8;
	uint8 u8Res2                                :8;
	uint8 u8TwvMotor_Motor_Twv_PosSet           :8;
	uint8 u8TwvMotor_Motor_Twv_MoveEnable           :1;
	uint8 u8Res3                                    :3;
	uint8 u8TwvMotor_Motor_Twv_ReqMotorEmgyStop     :1;
	uint8 u8TwvMotor_Motor_Twv_ReqMotorOptRecovery  :1;
	uint8 u8Res4                                    :2;
	uint8 u8Res5                                :8;
	uint8 u8Res6                                :8;
	uint8 u8Res7                                :8;
}LINIF_tstrTwvMotorCmd;

typedef struct
{
  uint8 u8TwvMotor_Motor_Twv_Resp_Error           :1;
  uint8 u8TwvMotor_Motor_Twv_OvervoltageFlt       :1;
  uint8 u8TwvMotor_Motor_Twv_OverCurrent          :1;
  uint8 u8TwvMotor_Motor_Twv_OverTempFlt          :1;
  uint8 u8TwvMotor_Motor_Twv_UnderVoltageFlt      :1;
  uint8 u8TwvMotor_Motor_Twv_InitSta              :1;
  uint8 u8TwvMotor_Motor_Twv_Ccwflg               :1;
  uint8 u8TwvMotor_Motor_Twv_MotorSta             :1;
  uint8 u8TwvMotor_Motor_Twv_RealSta              :8;
  uint8 u8Res0                                  :8;
  uint8 u8Res1                                  :8;
  uint8 u8Res2                                  :8;
  uint8 u8Res3                                  :8;
  uint8 u8Res4                                  :8;
  uint8 u8Res5                                  :8;
}LINIF_tstrTwvMotorStatus;



typedef struct
{
	uint8 u8Eac_CompSpd_Target                  :8;
	uint8 u8Res0                                :8;
	uint8 u8Eac_Comp_On_Rq                      :2;
	uint8 u8Eac_Comp_Fault_Clear_Rq             :2;
	uint8 u8Eac_Comp_HvInterLock_Rq             :2;
	uint8 u8Eac_Comp_HvDischarge_Rq             :2;
}LINIF_tstrEacCmd;

typedef struct
{
	uint8 u8Eac_CompSpd_Est                     :8;
	uint8 u8Res0                                :8;
	uint8 u8Eac_EAC_HV_InputCurr                :8;
	uint8 u8Eac_EAC_HV_Volt                     :8;
	uint8 u8Eac_EAC_InvrtTemp                   :8;
	uint8 u8Eac_EAC_InvrtPhaseCurr              :8;
	
	uint8 u8Eac_EAC_Sp_BrdTemp_Lmt              :1;
	uint8 u8Eac_EAC_Sp_CurrLmt                  :1;
	uint8 u8Eac_EAC_Sp_HVVolt_Flt               :1;
	uint8 u8Eac_EAC_Sp_Temp_Excess              :1;
	uint8 u8Eac_EAC_Sp_Comm_Flt                 :1;
	uint8 u8Eac_EAC_Sp_InvrtPwrSup_Flt          :1;
	uint8 u8Eac_EAC_Off_Sens_Flt                :1;
	uint8 u8Eac_EAC_Off_ShrtCurr                :1;
	
	uint8 u8Eac_EAC_Off_Stall                   :1;
	uint8 u8Eac_EAC_RsErr                       :1;
	uint8 u8Eac_Comp_HvInterlock_Stat           :3;
	uint8 u8Eac_Comp_Oprtn_Stat                 :3;
}LINIF_tstrEacStatus;


typedef struct
{
	uint8 u8Pump_ACT_CTRL_byNAD                 :8;
	uint8 u8Pump_ACT_CTRL_byProgram             :2;
	uint8 u8Pump_ACT_CTRL_byStallDetector       :2;
	uint8 u8Pump_ACT_CTRL_byClearEventFlags     :4;
	
	uint8 u8Pump_ACT_CTRL_byTargetSpeed_L       :8;
	uint8 u8Pump_ACT_CTRL_byTargetSpeed_H       :8;
	uint8 u8Pump_ACT_CTRL_byReserved4           :8;
	uint8 u8Pump_ACT_CTRL_byReserved5           :8;
	
	uint8 u8Pump_ACT_CTRL_byReserved6           :8;
	uint8 u8Pump_ACT_CTRL_byReserved7           :6;
	uint8 u8Pump_ACT_CTRL_byStopMode            :2;

}LINIF_tstrPumpCmd;

typedef struct
{
	uint8 u8Pump_ACT_STATUS_byResponseError     :1;
	uint8 u8Pump_ACT_STATUS_byReserved1         :1;
	uint8 u8Pump_ACT_STATUS_byOverTemperature   :2;
    uint8 u8Pump_ACT_STATUS_byElectricDefect    :2;
	uint8 u8Pump_ACT_STATUS_byVoltageError      :2;
	
	uint8 u8Pump_ACT_STATUS_byEmergencyOccurred :2;
	uint8 u8Pump_ACT_STATUS_bySpeedError        :2;
	uint8 u8Pump_ACT_STATUS_byStallOccurred     :3;
	uint8 u8Pump_ACT_STATUS_byReset             :1;
	
	uint8 u8Pump_ACT_STATUS_bySpeedStatus_L     :8;
	uint8 u8Pump_ACT_STATUS_bySpeedStatus_H     :8;
	uint8 u8Pump_ACT_STATUS_byActualLA_L        :8;
	uint8 u8Pump_ACT_STATUS_byActualLA_H        :8;
	uint8 u8Pump_ACT_STATUS_byActualMotorVoltage   :8;
	uint8 u8Pump_ACT_STATUS_byFocMode              :8;

}LINIF_tstrPumpStatus;
/*****************************************************************************/

/**********************************************************************/
/***************      union define  Configuration    *******************/
/**********************************************************************/
typedef union 
{
    uint8  _c[4];
    LINIF_tstrChillerExvCmd strChillerExvCmd;                      
}LINIF_tuniChillerExvCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrChillerExvResp strChillerExvResp;                      
}LINIF_tuniChillerExvResp;

typedef union 
{
    uint8  _c[4];
    LINIF_tstrEvapExvCmd strEvapExvCmd;                      
}LINIF_tuniEvapExvCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrEvapExvResp strEvapExvResp;                      
}LINIF_tuniEvapExvResp;

typedef union 
{
    uint8  _c[2];
    LINIF_tstrHvwhSet1Cmd strHvwhSet1Cmd;                      
}LINIF_tuniHvwhSet1Cmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrHvwhSet2Cmd strHvwhSet2Cmd;                      
}LINIF_tuniHvwhSet2Cmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrHvwhStatusResp strHvwhStatusResp;                      
}LINIF_tuniHvwhStatusResp;


typedef union 
{
    uint8  _c[8];
    LINIF_tstrBlwCmd strBlwCmd;                      
}LINIF_tuniBlwCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrBlwStatus1 strBlwStatus1;                      
}LINIF_tuniBlwStatus1;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrBlwStatus2 strBlwStatus2;                      
}LINIF_tuniBlwStatus2;


typedef union 
{
    uint8  _c[8];
    LINIF_tstrTwvHvacCmd strTwvHvacCmd;                      
}LINIF_tuniTwvHvacCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrTwvHvacStatus strTwvHvacStatus;                      
}LINIF_tuniTwvHvacStatus;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrTwvBatCmd strTwvBatCmd;                      
}LINIF_tuniTwvBatCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrTwvBatStatus strTwvBatStatus;                      
}LINIF_tuniTwvBatStatus;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrTwvMotorCmd strTwvMotorCmd;                      
}LINIF_tuniTwvMotorCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrTwvMotorStatus strTwvMotorStatus;                      
}LINIF_tuniTwvMotorStatus;

typedef union 
{
    uint8  _c[3];
    LINIF_tstrEacCmd strEacCmd;                      
}LINIF_tuniEacCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrEacStatus strEacStatus;                      
}LINIF_tuniEacStatus;


typedef union 
{
    uint8  _c[8];
    LINIF_tstrPumpCmd strPumpCmd;                      
}LINIF_tuniPumpCmd;

typedef union 
{
    uint8  _c[8];
    LINIF_tstrPumpStatus strPumpStatus;                      
}LINIF_tuniPumpStatus;




typedef struct 
{
    uint8  _c[8];                    
}LINIF_tstrDiagRequest;

typedef struct 
{
    uint8  _c[8];                    
}LINIF_tstrDiagResponse;



typedef void   (*Lin_vidSendSignalFun)(const void *SigValue);    
typedef void   (*Lin_vidReceivedSignalFun)(void *SigValue);

#if(LIN_TXSIGNUM > 0)
extern const Lin_vidSendSignalFun      Lin_vidSendSignalFunPrt[LIN_TXSIGNUM];
#endif

#if(LIN_RXSIGNUM > 0)
extern const Lin_vidReceivedSignalFun  Lin_vidReceivedSignalFunPrt[LIN_RXSIGNUM];
#endif

#endif /*#if(LINIF_COM_SUPPORTED == STD_ON)*/

#endif/* LINIF_CFG_H */

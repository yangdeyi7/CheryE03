/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
/*user define include */
#include "Std_types.h"
/*Services include */
#include "SchM_Tasks.h"
#include "Wdog.h"
#include "LinIf.h"
#include "Can.h"
#include "CanCcl.h"
/*MCAL include */
#include "Adc.h"
#include "Icu.h"
#include "Port.h"
/*ECUAL include*/
#include "Sensor.h"
#include "Power.h"
#include "Stepper.h"
#include "Blower.h"
#include "Cmb.h"
#include "EdcDrv.h"
#include "ExvDrv.h"
#include "SovDrv.h"
#include "Actuator.h"
/*APP include */
#include "AppMain.h"
#include "SystemMng.h"
#include "ADC_handler.h"
#include "TLE9410xDrv.h"
#include "if_rte_app.h"
/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
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

/******************************************************************************/
/*!Function :   SchM_vidTask10ms                                              */
/*! \Description call 10ms tasks. \n
  \return      void.\n
  \Trace_To :  CDD-SchM-0010(0)
  ******************************************************************************/
void SchM_vidTask10ms( void )
{
   SEGGER_RTT_printf(0, "SchM_vidTask10ms\r\n");
   /*!ADC Management*/
   Adc_vidManage();
   /*! power Management */
   Power_vidManage();
   TLE9410xDrv_vidManage();
  Actuator_vidManage(u8ACT_MIXL);
  Actuator_vidManage(u8ACT_MIXR);
  Actuator_vidManage(u8ACT_MODEL);
  Actuator_vidManage(u8ACT_MODER);
  Actuator_vidManage(u8ACT_DEFROST);
  Actuator_vidManage(u8ACT_RECY);
  Fun_vidManage();
   /*! sensor Management */
   Sensor_vidManage();
   /*Lin Management*/
   LinIf_vidManage();
   /*CAN Statck task*/
   CanCcl_vidMainTask();
   /*!ICU Management*/
   Icu_vidManage();
   /*! App fast Management */
   AppMain_vidFastManage(); 
   /*!set Task finish flag*/
   Wdog_vidTaskFinish(WDG_Task10);
   /*! dog refrsh*/
   Wdog_vidRefresh();

}/* End of SchM_vidTask10ms */ 

/******************************************************************************/
/*!Function :   SchM_vidTask40ms                                              */
/*! \Description call 40ms tasks. \n
  \return      void. \n
  \Trace_To :  CDD-SchM-0011(0)
  *******************************************************************************/
void SchM_vidTask40ms( void )
{
  SEGGER_RTT_printf(0, "SchM_vidTask40ms\r\n");
  /*! dc motor */

  /*! CMB signals Management */
  CMB_vidManageSignals();
  
  /*! ExvDrv Management */ 
  ExvDrv_vidManage(u8EXV_CHILLER_ID);
  ExvDrv_vidManage(u8EXV_EVAP_ID);
  /*! SovDrv Management */ 
  SovDrv_vidManage(u8SOV1_ID);
  SovDrv_vidManage(u8SOV2_ID);
  SovDrv_vidManage(u8SOV3_ID);
  SovDrv_vidManage(u8SOV4_ID);
  /*! Stepper Management */
  //Stepper_vidManage(Stepper_MIX_L);
  //Stepper_vidManage(Stepper_MIX_R);
  //Stepper_vidManage(Stepper_MODE_F);
 // Stepper_vidManage(Stepper_MODE_R); 
  //Stepper_vidManage(Stepper_REC);
 // Stepper_vidManage(Stepper_I);
 // Stepper_vidManage(Stepper_EXV);
  /*! AppMain Management */
  AppMain_vidManage(); 
  //output

  /*! set Task finish flag*/
  Wdog_vidTaskFinish(WDG_Task40);
}/* End of SchM_vidTask40ms */

/******************************************************************************/
/*!Function :   SchM_vidTask100ms                                             */
/*! \Description call 100ms tasks. \n
  \return      void.\n
  \Trace_To :  CDD-SchM-0012(0)  
  *******************************************************************************/

void SchM_vidTask100ms( void ) 
{
   SEGGER_RTT_printf(0, "SchM_vidTask100ms\r\n");
   /*! App Show Management */
   AppMain_vidSlowManage();
   if(Power_u16GetIgnSts() == 2u)
   {
     System_vidMngRegulation();
     IfRteApp_CANSend();   
   }
   else
   {
     System_vidMngDefault();
     AppMain_vidDefault();
     /*do nothing*/
   }
   /*! set Task finish flag*/
   Wdog_vidTaskFinish(WDG_Task100);
   /*! Wdog Managent*/
   Wdog_vidManage();
   //lin_rx_test();
   //can_upper_test();
   //Can_vidSendMsg_test();
  // SEGGER_RTT_printf(0, "adic_ai24:%d\r\n",ADC_u16Read(ADC_AI24_PTA2));
}/* End of SchM_vidTask100ms */

/*-------------------------------- end of file -------------------------------*/

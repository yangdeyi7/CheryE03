/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
/*user define include */
#include "Std_Types.h"
/*Services include */
#include "StartInit.h"
#include "SchM.h"
#include "Wdog.h"
#include "DWdg.h"
#include "Eeprom.h"
#include "DLin.h"
#include "LinIf.h"
#include "Can.h"
#include "CanCcl.h"
#include "Cpu.h"
/*MCAL include */
#include "Mcu.h"
#include "Gpt.h"
#include "Gpt_Cfg.h"
#include "s32k144_Dio.h"
#include "Dio.h"
#include "Adc.h"
#include "Pwm.h"
#include "Icu.h"
#include "Spi.h"
#include "Uart.h"
#include "ADC_handler.h"
#include "FlexNVM.h"
/*ECUAL include*/
#include "EdcDrv.h"
#include "ExvDrv.h"
#include "SovDrv.h"
#include "Blower.h"
#include "Elmos.h"
#include "Stepper.h"
#include "Power.h"
#include "Sensor.h"
#include "Pump.h"
#include "TLE9410xDrv.h"
#include "Actuator.h"
/*APP include */
#include "AppMain.h"



/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/*****************************************************************************/
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
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidMcalInit( void );
static void vidEcualInit( void );
static void vidServicesInit( void );
static void vidAppInit( void );

/******************************************************************************/
/*!Function : vidMcalInit                                                     */
/*! \Description initialize MCAL layer .
  \return      void
  *****************************************************************************/
static void vidMcalInit( void )
{
    /*! Initialize MCU component*/
    //Mcu_vidInit();
    /*! Initialize GPT component*/
    Gpt_vidInit(NULL);
    /*! Initialize DIO component*/
    Dio_vidInit();
    /*! Initialize PWM component*/
    Pwm_vidInit();
    /*! Initialize ICU component*/
//    Icu_vidInit();
    /*! Initialize SPI component*/
    Spi_vidInit(E910);
    /*! Initialize ADC component*/
    Adc_vidInit();
    /*! Initialize UART component*/
    //UART_vidInit();
}

/******************************************************************************/
/*!Function : vidServicesInit                                                 */
/*! \Description initialize SERVICES layer .
  \return      void
  ******************************************************************************/
static void vidServicesInit( void ) 
{
    /*! Initialize Eep component*/ 
    EEP_vidInit();
    /*! Initialize SchM component*/ 
    SchM_vidInit();
    /*! Initialize Wdog component*/ 
    Wdog_vidInit();
    /*! Initialize LinCom component*/
//    Lin_vidInit(0u);
//    LinIf_vidInit(NULL_PTR);
    LIN_vidInit();
    /*! Initialize CanCom component*/
    CanCcl_vidInit();
}

/******************************************************************************/
/*!Function : vidEcualInit                                                   */
/*! \Description initialize ECUAL layer .
  \return      void
  ******************************************************************************/
static void vidEcualInit( void )
{
   /*! Initialize Sensor component*/ 
   Sensor_vidInit();
   /*! Initialize Power component*/ 
   Power_vidInit();
   /*! Initialize Blower component*/ 
   Blower_vidInit();
   /*! Initialize Elmos component*/ 
   Elmos_vidInit();
   /*! Initialize Stepper component*/ 
   Stepper_vidInit();
   /*! Initialize ExvDrv component*/ 
   ExvDrv_vidInit();
   /*! Initialize EdcDrv component*/ 
   EdcDrv_vidInit();
   /*! Initialize SovDrv component*/ 
   SovDrv_vidInit();
   Pump_vidInit();
   //
   TLE9410xDrv_vidInit();
   Actuator_vidInit();
}

/*****************************************************************************/
/*!Function : vidAppInit                                                   */
/*! \Description initialize APP layer .
  \return      void
  ******************************************************************************/
static void vidAppInit( void ) 
{
    /*! Initialize App component*/ 
    AppMain_vidInit();  
    System_vidMngInit();
}


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function:   Start_vidInit                                                  */
/*! \Description call initialization of all functions.
  \return      void.
  ****************************************************************************/ 
void Start_vidInit( void )
{
   
#if(0)
     /*Disable interrupts */
     MCU_vidDisableInterrupts();
    /* system clock initialization */
    (void)CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
            g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    (void)CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
    SystemCoreClockUpdate();
    /*Config FlexNVM as EEPROM */
    (void)FNVM_udtCfgEEP();
    /*****************************************************************************/
    /**********************************MCAL***************************************/
    /*****************************************************************************/
    /* initialization of the DIO */
    DIO_vidInit();
    /* initialization of the 1ms timer */
    GPT_vidInit();
    /* initialization of the ADC */
    ADC_vidInit();
    /* initialization of the SPI */
    SPI_vidInit();
    /* initialization of LIN */
    LIN_vidInit();
    /* initialization of LIN transceiver*/
    LinTrcv_Tja1021_Init(NULL_PTR);
     /*Initialize CanCom component*/
    CanCcl_vidInit();
    TLE9410xDrv_vidInit();
    Actuator_vidInit();
    /*****************************************************************************/
    /**********************************APP**************************************/
    /*****************************************************************************/
    AppMain_vidInit();
    /*****************************************************************************/
    /**********************************ECUAL**************************************/
    /*****************************************************************************/
    /* initialization of the scheduler */
    SchM_vidInit();
    /* initialization of the MCU */
    MCU_vidInit();
     /* enable the global interrupt */
    MCU_vidEnableInterrupts();
    /* initialization of the DWDG/n
    * From reset to this point have to not exceed 34ms*/
    DWdg_vidInit();
#else
     /*Disable interrupts */
     Mcu_vidDisableInterrupts();
     /* system clock initialization */
     CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
     CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
     SystemCoreClockUpdate();
     /*Config FlexNVM as EEPROM */
     FNVM_udtCfgEEP();
     /*! Initialize MCAL */
     vidMcalInit();
     /*! Initialize Services */
     vidServicesInit();
     /*! Initialize ECUAL */
     vidEcualInit();
     /*! Initialize APP */
     vidAppInit();
     /*! Enable the 1ms Timer */    
     Gpt_vidStartTimer(Gpt_OSTM_CH0, &SchM_vidGptCbk);
     
     Mcu_vidInit();
     /* enable the global interrupt */
     Mcu_vidEnableInterrupts();
     /* initialization of the DWDG/n
    * From reset to this point have to not exceed 34ms*/
     Wdog_vidInit();
#endif

    
}

/*-------------------------------- end of file -------------------------------*/

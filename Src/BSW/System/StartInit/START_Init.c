/******************************************************************************/
/* !Layer           : Services                                                */
/*                                                                            */
/* !Component       : Start                                                   */
/* !Description     : INIT CALLER                                             */
/*                                                                            */
/* !Module          : START INIT                                              */
/* !Description     : call all modules initialization functions               */
/*                                                                            */
/* !File            : START_INIT.c                                            */
/*                                                                            */
/* !Scope           : private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS (VALEO INTERBRANCH AUTOMOTIVE SOFTWARE)            */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2019 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/


/*****************************************************************************/
/* INCLUDE FILES                                                             */
/*****************************************************************************/
/*! \Trace_To:HVAC_SCD_SYSTEM_0070#01    */
#include "s32k144_GPT.h"
#include "MCU_Manager.h"
#include "s32k144_DIO.h"
#include "ADC_handler.h"
#include "s32k144_SPI.h"
#include "WDG_Manager.h"
#include "SchM.h"
#include "START_Init.h"
#include "Cpu.h"
#include "DWdg.h"
#include "DLin.h"
//#include "LinTrcv_Tja1021.h"
#include "AppMain.h"
#include "CanCcl.h"
#include "FlexNVM.h"
#include "TLE9410xDrv.h"
#include "Actuator.h"





/*********************** Definition of common types **************************/

/****************** Sources to be used within the module *********************/

/***************** Headers implemented within the module *********************/

/*****************************************************************************/
/* CONSTANTS, MACROS                                                         */
/*****************************************************************************/


/*****************************************************************************/
/* TYPES                                                                     */
/*****************************************************************************/


/*****************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                              */
/*****************************************************************************/


/*****************************************************************************/
/* PRIVATE VARIABLES                                                         */
/*****************************************************************************/


/*****************************************************************************/
/* PUBLIC FUNCTIONS                                                          */
/*****************************************************************************/
/*! \Trace_To: HVAC_SCD_SYSTEM_0004#01,HVAC_SCD_SYSTEM_0005#04     */
extern void START_vidInit(void)
{
    /* Disable the global interrupt */
    MCU_vidDisableInterrupts();

    /* system clock initialization */
    (void)CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
            g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);

    (void)CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    SystemCoreClockUpdate();
    
    
    DIO_vidInit();
//    /*****************************************************************************/
//    /**********************************MCAL***************************************/
//    /*****************************************************************************/
//    /* initialization of the global interrupt */
//    GPT_vidInit();
//#if(STD_ON == PWM_USE_SDK)	
//    FOUT_vidInit(); 
//#else
//    PWM_vidInit();
//#endif
//    /* initialization of the ADC */
//    ADC_vidInit();
//    /* initialization of the SPI */
    SPI_vidInit();
     /* initialization of the MCU */
    //MCU_vidInit();

    /* enable the global interrupt */
    MCU_vidEnableInterrupts();
    tle9410Drv_test();
    while(1);
    
    /*Config FlexNVM as EEPROM */
    (void)FNVM_udtCfgEEP();
    /* initialization of the DIN */
    DIO_vidInit();
    /*****************************************************************************/
    /**********************************MCAL***************************************/
    /*****************************************************************************/
    /* initialization of the global interrupt */
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
    //CanCcl_vidInit();
    
    //motor driver by spi chip tle9410
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

    /**************************************************************************/
}






/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Main                                                    */
/*                                                                            */
/* !Component       : Main                                                    */
/* !Description     : Main                                                    */
/*                                                                            */
/* !Module          : Main                                                    */
/* !Description     : Main                                                    */
/*                                                                            */
/* !File            : Main.c                                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "SchM.h"
#include "StartInit.h"

void  main(void)
{
    SEGGER_RTT_printf(0, "main start\r\n");
    Start_vidInit();
 //   lin_tx_test();
//    while(1)
//    {
//    lin_rx_test();
//    }
//    tle9410Drv_test();
//   while(1);
    //pwm_test();
    //Fun_test();
    SchM_vidScheduler();
}

/*-------------------------------- end of file -------------------------------*/

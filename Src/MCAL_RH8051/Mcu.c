/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Mcu                                                     */
/*                                                                            */
/* !Component       : Mcu                                                     */
/* !Description     : Interface for managing common micro peripherals.        */
/*                                                                            */
/* !Module          : Mcu                                                     */
/* !Description     : Mcu                                                     */
/*                                                                            */
/* !File            : Mcu.c                                                   */
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
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Device.h"
#include "Mcu.h"
#include "MCU_Manager.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

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
/*! \Description  Interrupt nesting counter.
 *! \Range        0..255
*******************************************************************************/
//static uint8 Mcu_u8IntCounter = 0u ;


/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/*******************************************

***********************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function : MCU_vidInit                                                     */
/*! \Description Configure MCU Core for indicated state       \n
    \return      void                                         \n
    \Trace_To    CDD-MCU-0005(0)  
 ******************************************************************************/
void Mcu_vidInit( void )
{
//  /* Prepare 8MHz MainOsc */
//  if((CLKCTLMOSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
//  {
//   CLKCTLMOSCC=0x07;                                                    /* Set MainOSC gain for 8MHz */
//   CLKCTLMOSCST=0x00003E80;                                             /* Set MainOSC stabilization time to 1ms */
//   protected_write(WPROTRPROTCMD0,WPROTRPROTS0,CLKCTLMOSCE,0x01u);      /* Trigger Enable (protected write) */
//   while ((CLKCTLMOSCS&0x04u) != 0x04u);                                /* Wait for active MainOSC */
//  }
//  
//  if((CLKCTLPLL1S&0x04u) != 0x04u)                                      /* Check if PLL needs to be started */
//  {
//    /* Prepare PLL1 */
//    CLKCTLPLL1C=0x1003B;                                                /* 8 MHz MainOSC -> 480MHz VCOUT, 80MHz PPLLOUT */
//    protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLPLL1E,0x01u);     /* Enable PLL */
//    while((CLKCTLPLL1S&0x04u) != 0x04u){}                               /* Wait for active PLL */
//  }
//  
//   /* CPLL1OUT = VCOOUT ¡Á 1/6 = 80 MHz */
//  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_CPUCLKD_CTL,0x01u);
//  while(CLKCTLCKSC_CPUCLKD_ACT != 0x01u);  
//  
//  /* CPLLOUT -> CPU Clock */ 
//  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_CPUCLKS_CTL,0x03u);
//  while(CLKCTLCKSC_CPUCLKS_ACT != 0x03u);
//  
//  /* PPLLOUT -> PPLLCLK = 80MHz */
//  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_PPLLCLKS_CTL,0x03u);
//  while(CLKCTLCKSC_PPLLCLKS_ACT != 0x03u);
//
//  /* Set Peripheral CLK1 to PPLLCLK = 80M (TAUD0,TAUJ1 use this clk)*/
//  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_IPERI1S_CTL,0x01u);
//  while(CLKCTLCKSC_IPERI1S_ACT != 0x01u);
//
//  /* Set Peripheral CLK2 to PPLLCLK2 = 40M (TAUBn,PWGAn,PWBAn,PWSAn use the clk)*/
//  protected_write(WPROTRPROTCMD1,WPROTRPROTS1,CLKCTLCKSC_IPERI2S_CTL,0x01u);
//  while(CLKCTLCKSC_IPERI2S_ACT != 0x01u);
//
//  /* Set RLIN/UART CLK devider = /1= 40M*/
//  protected_write(WPROTRPROTCMD0,WPROTRPROTS0,CLKCTLCKSC_ILIND_CTL,0x01u);
//  while(CLKCTLCKSC_ILIND_ACT != 0x01u);
//
//  /* ADCA0 Clock = PPLLCLK/2 */
//  protected_write(WPROTRPROTCMD0, WPROTRPROTS0, CLKCTLCKSC_AADCAS_CTL, 0x03);
//  while(CLKCTLCKSC_AADCAS_ACT != 0x03);
//
//  /* Select CAN Module Clock PPLLCLK(80MHz) */
//  protected_write(WPROTRPROTCMD1, WPROTRPROTS1, CLKCTLCKSC_ICANS_CTL, 0x03u);
//  while (CLKCTLCKSC_ICANS_ACT != 0x03u);
//
//  /* Select CAN Communication Clock  MainOSC(8MHz)*/
//  protected_write(WPROTRPROTCMD1, WPROTRPROTS1, CLKCTLCKSC_ICANOSCD_CTL, 0x01u);
//  while (CLKCTLCKSC_ICANOSCD_CTL != 0x01u);
  MCU_vidInit();
}/* End of MCU_vidInit() */

/******************************************************************************/
/*!Function : MCU_vidDisableInterrupts                                        */
/*! \Description   Disable all Interrupts .\n 
    \return        void                    \n
    \Trace_To      CDD-MCU-0007(0)  
 ******************************************************************************/
void Mcu_vidDisableInterrupts(void)
{
//  if (Mcu_u8IntCounter == 0)
//  {
//   __DI();
//  }
//  Mcu_u8IntCounter++;
    MCU_vidDisableInterrupts();
}/* End of MCU_vidDisableInterrupts() */
 
/******************************************************************************/
/*!Function : Mcu_vidEnableInterrupts                                         */
/*! \Description   Enable all Interrupts .\n 
    \return        void                   \n
    \Trace_To      CDD-MCU-0008(0)
 ******************************************************************************/ 
void Mcu_vidEnableInterrupts( void )
{
//   /*! If the interrupt counter is greater than zero */
//  if (Mcu_u8IntCounter > 0)
//  {
//    /*! Decrement the Interrupt counter. */
//    Mcu_u8IntCounter--;
//  }
//  /*! If the interrupt counter equals zero */
//  if (Mcu_u8IntCounter == 0)
//  {
//    /*! Clear the global interrupt mask bit. */
//    __EI();
//  }  
    MCU_vidEnableInterrupts();
} /*  End of Mcu_vidEnableInterrupts  */


/** \} */ /* end of Mcu module group */
/** \} */ /* end of MCAL Mcu Component */

/*-------------------------------- end of file ---------------------------------*/

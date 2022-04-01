/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Pwm                                                     */
/*                                                                            */
/* !Component       : Pwm                                                     */
/* !Description     : Managing the generation of PWM output signals           */
/*                                                                            */
/* !Module          : Pwm                                                     */
/* !Description     : Pwm                                                     */
/*                                                                            */
/* !File            : Pwm.c                                                   */
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
#include "s32k144_Pwm.h"
//#include "Pwm_Cfg.h"
#include "Port.h"
#include "Device.h"
#include "fout.h"
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
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function : Pwm_vidInit                                                     */
/*! \Description Initializes PWM. \n    
  \return      void             \n
  \Trace_To    CDD-PWM-0004(0)
  *****************************************************************************/
void Pwm_vidInit(void)
{
  
#if(0)	
    FOUT_vidInit(); 
#else
    PWM_vidInit();
#endif
  
 //   uint8 u8Index;
//	for(u8Index = 0u; u8Index < PWM_u8NUM; u8Index++)
//	{
//		Port_vidSetAltFunc(Pwm_akstrPortCfg[u8Index],
//				           Port_Alt4,
//				           Port_Output);
//	}
///*****************************************************************************/ 
//#if 0
//   /* Set TAUBn Prescaler Clock as 32,clk = PCLK(32M)/32 = 1M */
//   TAUB0TPS   =  (0x0005U);
//#else
//   /* Set TAUBn Prescaler Clock as 32,clk = PCLK(32M)/64 = 0.5M */
//   TAUB0TPS   =  (0x0006U);
//#endif
//   /* Disable TAUB ch0 ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,
//      ch10,ch11,ch12,ch13,ch14,ch15 counter operation */
//   TAUB0TT   =   (0x0001U)|/*ch0*/
//                 (0x0002U)|/*ch1*/
//                 (0x0004U)|/*ch2*/
//                 (0x0008U)|/*ch3*/
//                 (0x0010U)|/*ch4*/
//                 (0x0020U)|/*ch5*/
//                 (0x0040U)|/*ch6*/
//                 (0x0080U);/*ch7*/
//
///*****************************************************************************/
//    /* Set channel 0 setting */
//    TAUB0CMOR0 = (0x0000U)|/* Use CK0 */ 
//                 (0x0000U)|/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0800U)|/* Master */ 
//                 (0x0000U)|/* Software trigger */
//                 (0x0000U)|/* TAUBnCDRm update upon detection
//                             of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0000U)|/* Interval timer mode */ 
//                 (0x0001U);/* INTTAUBnIm is generated */
//    TAUB0CMUR0 = (0x00U);  /* Unused Falling edge */
//
//    
//    /* Set channel 1 setting */
//    TAUB0CMOR1 = (0x0000U) |/* Use CK0 */  
//                 (0x0000U) |/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0000U) |/* Slave */ 
//                 (0x0400U) |/* INTTAUBnIm is the start tri of master channel*/ 
//                 (0x0000U) |/* TAUBnCDRm update upon detection
//                               of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0008U) |/* One-count mode */ 
//                 (0x0001U) ;/* Enables detection. */
//    TAUB0CMUR1 = (0x00U);   /* Unused Falling edge */
//
//    
//    /* Data register for the capture/compare value count clk * (TAUBnCDRm + 1)*/
//    TAUB0CDR0  = (5000U-1U);/*example TAUB0CDR0  = (12500U) ,T = 12500/5 = 2.5ms*/
//    TAUB0CDR1  = (0x0000U); /*example TAUB0CDR1  = (1250U) ,D = 50%*/
//  
///*****************************************************************************/
//    /* Set channel 2 setting */
//    TAUB0CMOR2 = (0x0000U)|/* Use CK0 */ 
//                 (0x0000U)|/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0800U)|/* Master */ 
//                 (0x0000U)|/* Software trigger */
//                 (0x0000U)|/* TAUBnCDRm update upon detection
//                             of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0000U)|/* Interval timer mode */ 
//                 (0x0001U);/* INTTAUBnIm is generated */
//    TAUB0CMUR2 = (0x00U);   /* Unused Falling edge */
//
//    
//    /* Set channel 3 setting */
//    TAUB0CMOR3 = (0x0000U) |/* Use CK0 */  
//                 (0x0000U) |/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0000U) |/* Slave */ 
//                 (0x0400U) |/* INTTAUBnIm is the start tri of master channel*/ 
//                 (0x0000U) |/* TAUBnCDRm update upon detection
//                               of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0008U) |/* One-count mode */ 
//                 (0x0001U) ;/* Enables detection. */
//    TAUB0CMUR3 = (0x00U);   /* Unused Falling edge */
//
//    
//    /* Data register for the capture/compare value count clk * (TAUBnCDRm + 1)*/
//    TAUB0CDR2  = (5000U-1U);/*example TAUB0CDR0  = (12500U) ,T = 12500/5 = 2.5ms*/
//    TAUB0CDR3  = (0x0000U); /*example TAUB0CDR1  = (1250U) ,D = 50%*/
//    
///*****************************************************************************/
//    /* Set channel 4 setting */
//    TAUB0CMOR4 = (0x0000U)|/* Use CK0 */ 
//                 (0x0000U)|/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0800U)|/* Master */ 
//                 (0x0000U)|/* Software trigger */
//                 (0x0000U)|/* TAUBnCDRm update upon detection
//                             of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0000U)|/* Interval timer mode */ 
//                 (0x0001U);/* INTTAUBnIm is generated */
//    TAUB0CMUR4 = (0x00U);   /* Unused Falling edge */
//
//    
//    /* Set channel 5 setting */
//    TAUB0CMOR5 = (0x0000U) |/* Use CK0 */  
//                 (0x0000U) |/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0000U) |/* Slave */ 
//                 (0x0400U) |/* INTTAUBnIm is the start tri of master channel*/ 
//                 (0x0000U) |/* TAUBnCDRm update upon detection
//                               of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0008U) |/* One-count mode */ 
//                 (0x0001U) ;/* Enables detection. */
//    TAUB0CMUR5 = (0x00U);   /* Unused Falling edge */
//
//    
//    /* Data register for the capture/compare value count clk * (TAUBnCDRm + 1)*/
//    TAUB0CDR4  = (5000U-1U);/*example TAUB0CDR0  = (12500U) ,T = 12500/5 = 2.5ms*/
//    TAUB0CDR5  = (0x0000U); /*example TAUB0CDR1  = (1250U) ,D = 50%*/
///*****************************************************************************/
//    
//    /* Set channel 6 setting */
//    TAUB0CMOR6 = (0x0000U)|/* Use CK0 */ 
//                 (0x0000U)|/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0800U)|/* Master */ 
//                 (0x0000U)|/* Software trigger */
//                 (0x0000U)|/* TAUBnCDRm update upon detection
//                             of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0000U)|/* Interval timer mode */ 
//                 (0x0001U);/* INTTAUBnIm is generated */
//    TAUB0CMUR6 = (0x00U);   /* Unused Falling edge */
//
//    
//    /* Set channel 7 setting */
//    TAUB0CMOR7 = (0x0000U) |/* Use CK0 */  
//                 (0x0000U) |/* Operation clock as specified by TAUBnCMORm */ 
//                 (0x0000U) |/* Slave */ 
//                 (0x0400U) |/* INTTAUBnIm is the start tri of master channel*/ 
//                 (0x0000U) |/* TAUBnCDRm update upon detection
//                               of edge of TAUBTTINm and TAUBnOVF update */ 
//                 (0x0008U) |/* One-count mode */ 
//                 (0x0001U) ;/* Enables detection. */
//    TAUB0CMUR7 = (0x00U);   /* Unused Falling edge */
//
//    
//    /* Data register for the capture/compare value count clk * (TAUBnCDRm + 1)*/
//    TAUB0CDR6  = (5000U-1U);/*example TAUB0CDR0  = (12500U) ,T = 12500/5 = 2.5ms*/
//    TAUB0CDR7  = (0x0000U); /*example TAUB0CDR1  = (1250U) ,D = 50%*/
//
//    /* Set output mode setting */
//    TAUB0TOE   = (0x0002U)|/*Enable channel 1*/
//                 (0x0000U)|/*Disable channel 0*/
//                 (0x0008U)|/*Enable channel 3*/
//                 (0x0000U)|/*Disable channel 2*/
//                 (0x0020U)|/*Enable channel 5*/
//                 (0x0000U)|/*Disable channel 4*/
//                 (0x0080U)|/*Enable channel 7*/
//                 (0x0000U);/*Disable channel 6*/
//
//                       
//    TAUB0TOM   = (0x0002U)|/* ch1 Synchronous channel output mode */
//                 (0x0008U)|/* ch3 Synchronous channel output mode */
//                 (0x0020U)|/* ch5 Synchronous channel output mode */
//                 (0x0080U);/* ch7 Synchronous channel output mode */
//
//                
//   /* Enable TAUB ch0 ch1,ch2,ch3,ch4,ch5,ch6,ch7,
//   ch8,ch9,ch10,ch11,ch12,ch13,ch14,ch15 counter operation */
//   TAUB0TS   =  (0x0001U)|/*ch0*/
//                (0x0002U)|/*ch1*/
//                (0x0004U)|/*ch2*/
//                (0x0008U)|/*ch3*/
//                (0x0010U)|/*ch4*/
//                (0x0020U)|/*ch5*/
//                (0x0040U)|/*ch6*/
//                (0x0080U);/*ch7*/

}/* End of PWM_vidInit() */


/******************************************************************************/
/*!Function : Pwm_vidWriteDutyCycle                                           */
/*! \Description Write PWM signal with a specified duty cycle for 
  a certain PWM identifier. \n 
  \param[in]   ID                        \n
  \Range       0....2                    \n
  \param[in]   T cycle(us)               \n
  \Range       0....65536                \n
  \param[in]   Duty cycle                \n
  \Range       0....100                  \n
  \return      void                      \n
  \Trace_To    
  *****************************************************************************/
void PwmOut_vidWriteDutyCycle(uint8 u8Id,uint16 u16DutyCycle)
{
//    switch (u8Id)
//    {
//        case PWM_u8FAN_ID:
//			if(0u == u16DutyCycle)
//            {
//                TAUB0CDR1 = 0u;
//            }
//            else if(1000u == u16DutyCycle)
//            {
//                TAUB0CDR1 =  TAUB0CDR0 + 1u;
//            }
//            else if((u16DutyCycle > 0u) && (u16DutyCycle < 1000u))
//            {
//                TAUB0CDR1 = (uint32)((uint32)((TAUB0CDR0 + 1u) * u16DutyCycle) /
//                        (uint32)(1000u));
//            }
//            else
//            {
//
//            }
//            break;
//
//        case PWM_u8PUMP_ID:
//			if(0u == u16DutyCycle)
//            {
//                TAUB0CDR3 = 0u;
//            }
//            else if(1000u == u16DutyCycle)
//            {
//                TAUB0CDR3 =  TAUB0CDR2 + 1u;
//            }
//            else if((u16DutyCycle > 0u) && (u16DutyCycle < 1000u))
//            {
//                TAUB0CDR3 = (uint32)((uint32)((TAUB0CDR2 + 1u) * u16DutyCycle) /
//                        (uint32)(1000u));
//            }
//            else
//            {
//
//            }
//            break;
//			
//        case PWM_u8BLW_F_ID:
//            if(0u == u16DutyCycle)
//            {
//                TAUB0CDR5 = 0u;
//            }
//            else if(1000u == u16DutyCycle)
//            {
//                TAUB0CDR5 =  TAUB0CDR4 + 1u;
//            }
//            else if((u16DutyCycle > 0u) && (u16DutyCycle < 1000u))
//            {
//                TAUB0CDR5 = (uint32)((uint32)((TAUB0CDR4 + 1u) * u16DutyCycle)/
//                        (uint32)(1000u));
//            }
//            else
//            {
//
//            }
//            break;
//
//        case PWM_u8BLW_R_ID:
//            if(0u == u16DutyCycle)
//            {
//                TAUB0CDR7 = 0u;
//            }
//            else if(1000u == u16DutyCycle)
//            {
//                TAUB0CDR7 =  TAUB0CDR6 + 1u;
//            }
//            else if((u16DutyCycle > 0u) && (u16DutyCycle < 1000u))
//            {
//                TAUB0CDR7 = (uint32)((uint32)((TAUB0CDR6 + 1u) * u16DutyCycle) /
//                        (uint32)(1000u));
//            }
//            else
//            {
//
//            }
//            break;
//
//
//        default :
//            break ;
//    }


} /* End of PWM_vidWriteDutyCycle() */


/** \} */ /* end of PWM module group */
/** \} */ /* end of MCAL PWM Component */

/*-------------------------------- end of file -------------------------------*/

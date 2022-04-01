/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Icu                                                     */
/*                                                                            */
/* !Component       : Icu                                                     */
/* !Description     : Managing the generation of PWM input signals            */
/*                                                                            */
/* !Module          : Icu                                                     */
/* !Description     : Icu                                                     */
/*                                                                            */
/* !File            : Icu.c                                                   */
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
#include "Icu.h"
//#include "Icu_Cfg.h"
#include "Port.h"

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
/*! \Description:Used for storing CAPTURE Pwm Value                           */
/******************************************************************************/
static uint8     Icu_au8CapPwmBuffer[ICU_u8NUM];
/******************************************************************************/
/*! \Description:Used for store capture high level ISR Flag                   */
/******************************************************************************/
static boolean   Icu_bHighLevelCountISRFalg[ICU_u8NUM];
/******************************************************************************/
/*! \Description:Used for store capture low level ISR Flag                    */
/******************************************************************************/
static boolean   Icu_bLowLevelCountISRFalg[ICU_u8NUM];



/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
             

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function : ICU_vidInit                                                     */
/*! \Description Initializes Icu. \n    
    \return      void             \n
    \Trace_To    
*******************************************************************************/
void Icu_vidInit(void)
{
//    uint8 u8LoopIndex;
//    for (u8LoopIndex = 0; u8LoopIndex < ICU_u8NUM; u8LoopIndex++)
//    { 
//	   Port_vidSetAltFunc(Icu_akstrPortCfg[u8LoopIndex],
//			      Port_Alt1,
//			      Port_Input); 
//       Icu_au8CapPwmBuffer[u8LoopIndex] = 0u;
//       Icu_bHighLevelCountISRFalg[u8LoopIndex] = FALSE;
//       Icu_bLowLevelCountISRFalg[u8LoopIndex]  = FALSE;
//    }
//    /*************************************************************************/  
//	/*
//	   Set TAUDn Prescaler Clock as 11,clk = PCLK(80M)/2^11 = 5/128M = 25.6US
//       1HZ = 1000000US,  1000000/25.6 = 39062.5 < 65536 TAUD will not overflow
//       10HZ = 100000US,  100000/25.6  = 3906.25 < 65536 TAUD will not overflow
//       30HZ = 33333.3US, 33333.3/25.6 = 1302.1 < 65536 TAUD will not overflow 
//	*/
//    TAUD0TPS   =  0x000BU;
//	
//   /* Disable TAUD ch0 ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,
//      ch10,ch11,ch12,ch13,ch14,ch15 counter operation */
//    TAUD0TT    = (0x0001U)|/*ch0*/
//                 (0x0002U)|/*ch1*/
//                 (0x0010U)|/*ch4*/
//                 (0x0020U)|/*ch5*/
//                 (0x0040U)|/*ch6*/
//                 (0x0080U)|/*ch7*/
//                 (0x1000U)|/*ch112*/
//                 (0x2000U);/*ch113*/
//    /**************************************************************************/
//	SL_TAUD0SELB_TAUD0I |=  (1 << 0);
//	SL_TAUD0SELB_TAUD0I &= ~(1 << 1); /*input P10_0*/
//	/* Enable INTTAUD0I0 operation and clear request */
//    INTC1MKTAUD0I0  =  1U;
//    INTC1RFTAUD0I0  =  0U;
//    INTC1TBTAUD0I0  =  1U;
//	/* Enable INTTAUD0I1 operation and clear request */
//    INTC2MKTAUD0I1  =  1U;
//    INTC2RFTAUD0I1  =  0U;
//    INTC2TBTAUD0I1  =  1U;
//	/* Set channel 0 setting capture and one_count mode */
//    TAUD0CMOR0 =  0x20CU;
//    /* Set channel 1 setting capture and one_count mode */
//    TAUD0CMOR1 =  0x20CU;
//    /* Detection of rising and falling edges (selects low width measurement)*/
//    TAUD0CMUR0 =  0x02U;
//    /* Detection of rising and falling edges (selects high width measurement)*/
//    TAUD0CMUR1 =  0x03U;
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENL0 = 0x01U; 
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENL1 = 0x01U;
//	/* Enable INTTAUD0I0 operation and clear request */
//    INTC1MKTAUD0I0   =  0U;
//    /* Enable INTTAUD0I1 operation and clear request */
//    INTC2MKTAUD0I1   =  0U;
//	
//#if 0  /*No This Module On PCBA*/
//	/************************************************************************/
//	SL_TAUD0SELB_TAUD0I |=  (1 << 4);
//	SL_TAUD0SELB_TAUD0I &= ~(1 << 5);/*input P10_2*/
//	/* Enable INTTAUD0I4 operation and clear request */
//    INTC1MKTAUD0I4  =  1U;
//    INTC1RFTAUD0I4  =  0U;
//    INTC1TBTAUD0I4  =  1U;
//	/* Enable INTTAUD0I5 operation and clear request */
//    INTC2MKTAUD0I5  =  1U;
//    INTC2RFTAUD0I5  =  0U;
//    INTC2TBTAUD0I5  =  1U;
//    /* Set channel 4 setting capture and one_count mode */
//    TAUD0CMOR4 =  0x20CU;
//    /* Set channel 5 setting capture and one_count mode */
//    TAUD0CMOR5 =  0x20CU;
//    /* Detection of rising and falling edges (selects low width measurement) */
//    TAUD0CMUR4 =  0x02U;
//    /* Detection of rising and falling edges (selects high width measurement) */
//    TAUD0CMUR5 =  0x03U;
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENL4 = 0x01U; 
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENL5 = 0x01U;
//	/* Enable INTTAUD0I6 operation and clear request */
//    INTC1MKTAUD0I4   =  0U;
//    /* Enable INTTAUD0I7 operation and clear request */
//    INTC2MKTAUD0I5   =  0U;
//#endif
//	
//	/************************************************************************/
//	SL_TAUD0SELB_TAUD0I |=  (1 << 6);
//	SL_TAUD0SELB_TAUD0I &= ~(1 << 7);/*input P10_3*/
//	/* Enable INTTAUD0I6 operation and clear request */
//    INTC1MKTAUD0I6  =  1U;
//    INTC1RFTAUD0I6  =  0U;
//    INTC1TBTAUD0I6  =  1U;
//	/* Enable INTTAUD0I7 operation and clear request */
//    INTC2MKTAUD0I7  =  1U;
//    INTC2RFTAUD0I7  =  0U;
//    INTC2TBTAUD0I7  =  1U;
//    /* Set channel 6 setting capture and one_count mode */
//    TAUD0CMOR6 =  0x20CU;
//    /* Set channel 7 setting capture and one_count mode */
//    TAUD0CMOR7 =  0x20CU;
//    /* Detection of rising and falling edges (selects low width measurement) */
//    TAUD0CMUR6 =  0x02U;
//    /* Detection of rising and falling edges (selects high width measurement) */
//    TAUD0CMUR7 =  0x03U;
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENL6 = 0x01U; 
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENL7 = 0x01U;
//	/* Enable INTTAUD0I6 operation and clear request */
//    INTC1MKTAUD0I6   =  0U;
//    /* Enable INTTAUD0I7 operation and clear request */
//    INTC2MKTAUD0I7   =  0U;
//
//	/************************************************************************/
//	SL_TAUD0SELB_TAUD0I &= ~(1 << 12);/*input P10_9*/
//	SL_TAUD0SELB_TAUD0I |=  (1 << 13);
//	/* Enable INTTAUD0I12 operation and clear request */
//    INTC1MKTAUD0I12  =  1U;
//    INTC1RFTAUD0I12  =  0U;
//    INTC1TBTAUD0I12  =  1U;
//	/* Enable INTTAUD0I13 operation and clear request */
//    INTC2MKTAUD0I13  =  1U;
//    INTC2RFTAUD0I13  =  0U;
//    INTC2TBTAUD0I13  =  1U;
//    /* Set channel 12 setting capture and one_count mode */
//    TAUD0CMOR12 =  0x20CU;
//    /* Set channel 13 setting capture and one_count mode */
//    TAUD0CMOR13 =  0x20CU;
//    /* Detection of rising and falling edges (selects low width measurement) */
//    TAUD0CMUR12 =  0x02U;
//    /* Detection of rising and falling edges (selects high width measurement) */
//    TAUD0CMUR13 =  0x03U;
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENH4 = 0x01U; 
//    /* Digital Noise Elimination Enable Control */
//    DNFATAUD0IENH5 = 0x01U;
//	/* Enable INTTAUD0I8 operation and clear request */
//    INTC1MKTAUD0I12   =  0U;
//    /* Enable INTTAUD0I9 operation and clear request */
//    INTC2MKTAUD0I13   =  0U;
//
//	
//    /* Enable TAUD ch0 ch1,ch2,ch3,ch4,ch5,ch6,ch7,
//    ch8,ch9,ch10,ch11,ch12,ch13,ch14,ch15 counter operation */
//    TAUD0TS  |= (0x0001U)|/*ch0*/
//                (0x0002U)|/*ch1*/
//				(0x0010U)|/*ch4*/
//		        (0x0020U)|/*ch5*/
//		        (0x0040U)|/*ch6*/
//                (0x0080U)|/*ch7*/
//				(0x1000U)|/*ch12*/
//                (0x2000U);/*ch13*/
                
}/* End of Icu_vidInit() */



/******************************************************************************/
/*!Function : Icu_u8ReadDutyCycle                                            */
/*! \Description Read the duty value 
     a value in 8 bits. \n
    \param[in]   u8Id : ID of data
    \Range       0  \n
    \return      converted value     \n
    \Trace_To    
 ******************************************************************************/
uint8 Icu_u8ReadDutyCycle(uint8 u8Id)
{
  uint8 u8Result = 0u;
//  /*! if ID is in range */
//  if ( u8Id < ICU_u8NUM)
//  {  
//    u8Result = Icu_au8CapPwmBuffer[u8Id];
//  }
//  /*! else */
//  else 
//  { 
//    /*! return  0 */
//    u8Result = 0u;
//  }
  return u8Result ;
}

/******************************************************************************/
/*!Function : ICU_vidManage                                                   */
/*! \Description Manage ICU   
    \return      void             \n
    \Trace_To  
 ******************************************************************************/
void Icu_vidManage(void)
{
   uint16 u16Temp = 0u;
//   //static uint16 LOC_u16Delay1000msCnt = 0u;
//   static uint16 LOC_u16Delay100msCnt = 0u;
//   static uint16 LOC_u16Delay40msCnt = 0u;
//   /*get ICU buffers*/
//   /****************100ms brush once for captrue 10hz pwm signal****************/   
//   if (LOC_u16Delay100msCnt <= 10u)
//   {
//	  LOC_u16Delay100msCnt++;
//   }
//   else
//   {
//	    LOC_u16Delay100msCnt = 0u;
//		/************************************************************/
//		if (TRUE == Icu_bLowLevelCountISRFalg[ICU_u8PUMP_FB_ID] &&
//			TRUE == Icu_bHighLevelCountISRFalg[ICU_u8PUMP_FB_ID] )
//	    {
//			Icu_bLowLevelCountISRFalg[ICU_u8PUMP_FB_ID] = FALSE;
//			Icu_bHighLevelCountISRFalg[ICU_u8PUMP_FB_ID] = FALSE;
//	        u16Temp = (uint16)(100u * 10u * (TAUD0CDR1 + 1U ) /
//					          ((TAUD0CDR1 + 1U) + (TAUD0CDR0 + 1U)));
//	        Icu_au8CapPwmBuffer[ICU_u8PUMP_FB_ID] = (u16Temp + 5u) / 10u;
//		}
//		else
//		{	
//	        /*! if pwm is 100% or 0%*/
//	        if (0u == Port_u8GetPinLevel(Icu_akstrPortCfg[ICU_u8PUMP_FB_ID]))
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8PUMP_FB_ID] = 0u;
//	        }
//	        else
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8PUMP_FB_ID] = 100u;
//	        }
//		}
//		/************************************************************/
//		if (TRUE == Icu_bLowLevelCountISRFalg[ICU_u8COLDFAN_FB_ID] &&
//			TRUE == Icu_bHighLevelCountISRFalg[ICU_u8COLDFAN_FB_ID] )
//	    {
//			Icu_bLowLevelCountISRFalg[ICU_u8COLDFAN_FB_ID] = FALSE;
//			Icu_bHighLevelCountISRFalg[ICU_u8COLDFAN_FB_ID] = FALSE;
//	        u16Temp = (uint16)(100u * 10u * (TAUD0CDR13 + 1U ) /
//					          ((TAUD0CDR12 + 1U) + (TAUD0CDR13 + 1U)));
//	        Icu_au8CapPwmBuffer[ICU_u8COLDFAN_FB_ID] = (u16Temp + 5u) / 10u;
//		}
//		else
//		{	
//	        /*! if pwm is 100% or 0%*/
//	        if (0u == Port_u8GetPinLevel(Icu_akstrPortCfg[ICU_u8COLDFAN_FB_ID]))
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8COLDFAN_FB_ID] = 0u;
//	        }
//	        else
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8COLDFAN_FB_ID] = 100u;
//	        }
//		}
//		
//   }
//   /****************40ms brush once for captrue 30hz pwm signal****************/   
//   if (LOC_u16Delay40msCnt <= 4u)
//   {
//	  LOC_u16Delay40msCnt++;
//   }
//   else
//   {
//	    LOC_u16Delay40msCnt = 0u;
//		if (TRUE == Icu_bLowLevelCountISRFalg[ICU_u8LIQULD_ID] &&
//			TRUE == Icu_bHighLevelCountISRFalg[ICU_u8LIQULD_ID] )
//	    {
//			Icu_bLowLevelCountISRFalg[ICU_u8LIQULD_ID] = FALSE;
//			Icu_bHighLevelCountISRFalg[ICU_u8LIQULD_ID] = FALSE;
//	        u16Temp = (uint16)(100u * 10u * (TAUD0CDR7 + 1U ) /
//					          ((TAUD0CDR7 + 1U) + (TAUD0CDR6 + 1U)));
//	        Icu_au8CapPwmBuffer[ICU_u8LIQULD_ID] = (u16Temp + 5u) / 10u;
//		}
//		else
//		{	
//	        /*! if pwm is 100% or 0%*/
//	        if (0u == Port_u8GetPinLevel(Icu_akstrPortCfg[ICU_u8LIQULD_ID]))
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8LIQULD_ID] = 0u;
//	        }
//	        else
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8LIQULD_ID] = 100u;
//	        }
//		}
//   }
//#if 0  /*No This Module On PCBA*/
//   /****************1000ms brush once for captrue 1hz pwm signal****************/   
//   if (LOC_u16Delay1000msCnt <= 100u)
//   {
//	  LOC_u16Delay1000msCnt++;
//   }
//   else
//   {
//	    LOC_u16Delay1000msCnt = 0u;
//		if (TRUE == Icu_bLowLevelCountISRFalg[ICU_u8PM25_ID] &&
//			TRUE == Icu_bHighLevelCountISRFalg[ICU_u8PM25_ID] )
//	    {
//			Icu_bLowLevelCountISRFalg[ICU_u8PM25_ID] = FALSE;
//			Icu_bHighLevelCountISRFalg[ICU_u8PM25_ID] = FALSE;
//	        u16Temp = (uint16)(100u * 10u * (TAUD0CDR5 + 1U ) /
//					          ((TAUD0CDR4 + 1U) + (TAUD0CDR5 + 1U)));
//	        Icu_au8CapPwmBuffer[ICU_u8PM25_ID] = (u16Temp + 5u) / 10u;
//		}
//		else
//		{	
//	        /*! if pwm is 100% or 0%*/
//	        if (0u == Port_u8GetPinLevel(Icu_akstrPortCfg[ICU_u8PM25_ID]))
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8PM25_ID] = 0u;
//	        }
//	        else
//	        {
//		       Icu_au8CapPwmBuffer[ICU_u8PM25_ID] = 100u;
//	        }
//		}
//   }
//#endif
}


///******************************************************************************/
///*!Function : INTTAUD0I0                                                    */
///*! \Description INTTAUD0I0 interrupt.                                      \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
////#pragma ghs interrupt
//void INTTAUD0I0(void)
//{
//	//Icu_bLowLevelCountISRFalg[ICU_u8PUMP_FB_ID] = TRUE;
//}
//
//
///******************************************************************************/
///*!Function : INTTAUD0I1                                                      */
///*! \Description INTTAUD0I1 interrupt.                                        \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
////#pragma ghs interrupt
//void INTTAUD0I1(void)
//{
//   // Icu_bHighLevelCountISRFalg[ICU_u8PUMP_FB_ID] = TRUE;
//}
//
//
//
//#if 0  /*No This Module On PCBA*/
///******************************************************************************/
///*!Function : INTTAUD0I4                                                    */
///*! \Description INTTAUD0I4 interrupt.                                      \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
//#pragma ghs interrupt
//void INTTAUD0I4(void)
//{
//	Icu_bLowLevelCountISRFalg[ICU_u8PM25_ID] = TRUE;
//}
//
///******************************************************************************/
///*!Function : INTTAUD0I5                                                      */
///*! \Description INTTAUD0I5 interrupt.                                        \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
//#pragma ghs interrupt
//void INTTAUD0I5(void)
//{
//    Icu_bHighLevelCountISRFalg[ICU_u8PM25_ID] = TRUE;
//}
//#endif
//
//
//
///******************************************************************************/
///*!Function : INTTAUD0I6                                                    */
///*! \Description INTTAUD0I6 interrupt.                                      \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
//#pragma ghs interrupt
//void INTTAUD0I6(void)
//{
//	Icu_bLowLevelCountISRFalg[ICU_u8LIQULD_ID] = TRUE;
//}
//
//
///******************************************************************************/
///*!Function : INTTAUD0I7                                                      */
///*! \Description INTTAUD0I7 interrupt.                                        \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
//#pragma ghs interrupt
//void INTTAUD0I7(void)
//{
//    Icu_bHighLevelCountISRFalg[ICU_u8LIQULD_ID] = TRUE;
//}
//
//
//
///******************************************************************************/
///*!Function : INTTAUD0I12                                                    */
///*! \Description INTTAUD0I13 interrupt.                                      \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
//#pragma ghs interrupt
//void INTTAUD0I12(void)
//{
//	Icu_bLowLevelCountISRFalg[ICU_u8COLDFAN_FB_ID] = TRUE;
//}
//
///******************************************************************************/
///*!Function : INTTAUD0I13                                                      */
///*! \Description INTTAUD0I13 interrupt.                                        \n    
//    \return      void             \n
//    \Trace_To    
// ******************************************************************************/
//#pragma ghs interrupt
//void INTTAUD0I13(void)
//{
//    Icu_bHighLevelCountISRFalg[ICU_u8COLDFAN_FB_ID] = TRUE;
//}






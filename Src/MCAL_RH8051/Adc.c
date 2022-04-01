/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Adc                                                     */
/*                                                                            */
/* !Component       : Adc                                                     */
/* !Description     : Interface for Managing the Adc                          */
/*                                                                            */
/* !Module          : Adc                                                     */
/* !Description     : Adc                                                     */
/*                                                                            */
/* !File            : Adc.c                                                   */
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
#include "Adc.h"
#include "ADC_handler.h"

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
/*!Array of the ADC captured data to be read                        */
/******************************************************************************/
//static uint16 Adc_au16SamplingBuffer[ADC_u8NUM_ADC][ADC_SAMPLES_NUM];

/******************************************************************************/
/*Flag that indicates the number of the whole samples done                    */
//static boolean Adc_bFirstTimeAvg;
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function : Adc_vidInit                                                     */
/*! \Description Initialize ADC module with 10 bits resolution.\n 
    \return      void   \n
    \Trace_To    CDD-ADC-0005(0)
*******************************************************************************/
void Adc_vidInit(void)
{
  
  ADC_vidInit();
  SEGGER_RTT_printf(0, "ADC_vidInit\r\n");
//lsy
//   uint8 u8Index;
//	uint8 u8Index1;
//    for (u8Index = 0u; u8Index < ADC_SAMPLES_NUM; u8Index++)
//    {
//	   for (u8Index1 = 0u; u8Index1 < ADC_u8NUM_ADC; u8Index1++)
//	   {
//	      Adc_au16SamplingBuffer[u8Index][u8Index1] = 0u;
//       }
//	}
//	Adc_bFirstTimeAvg = FALSE;
//    /*use TAUJ ch3 as A/D Conversion Trigger and set 500us Conver once */
//    /* CK0=PCLK(80M)/8 = 10M,CK1=CK2=CK3=PCLK(80M)*/
//    TAUJ0TPS    = 0x03u; 
//    /* ch.3  50us*/
//    TAUJ0CDR3  = 500U - 1U;     
//    /*Interval timer mode*/                                                                   
//    TAUJ0CMOR3 = 0x0000U;
//	/* Upper limit and lower limit are checked for ULLMTBR0*/
//    /*Control the virtual channel Select ANI000(AP0_0) - ANI0015(AP0_15) */
//    ADCA0VCR00     = 0x00000040UL;
//    ADCA0VCR01     = 0x00000041UL;
//    ADCA0VCR02     = 0x00000042UL;
//    ADCA0VCR03     = 0x00000043UL;
//    ADCA0VCR04     = 0x00000044UL;
//    ADCA0VCR05     = 0x00000045UL;
//    ADCA0VCR06     = 0x00000046UL;
//    ADCA0VCR07     = 0x00000047UL;
//    ADCA0VCR08     = 0x00000048UL;
//    ADCA0VCR09     = 0x00000049UL;
//    ADCA0VCR10     = 0x0000004aUL;
//    ADCA0VCR11     = 0x0000004bUL;
//    ADCA0VCR12     = 0x0000004cUL;
//    ADCA0VCR13     = 0x0000004dUL;
//    ADCA0VCR14     = 0x0000004eUL;
//    ADCA0VCR15     = 0x0000004fUL;
//	/*Control the virtual channel Select ANI018(P9_0) - ANI0019(P9_1) */
//	ADCA0VCR18     = 0x00000052UL;
//	ADCA0VCR19     = 0x00000053UL;
//	/*Control the virtual channel Select ANI025(P9_2) - ANI0029(P9_6) */
//	ADCA0VCR25     = 0x00000059UL;
//	ADCA0VCR26     = 0x0000005AUL;
//	ADCA0VCR27     = 0x0000005BUL;
//	ADCA0VCR28     = 0x0000005CUL;
//	ADCA0VCR29     = 0x0000005DUL;
//	/*Control the virtual channel Select ANI031(P8_8) - ANI0032(P8_9) */
//	ADCA0VCR31     = 0x0000005FUL;
//	ADCA0VCR32     = 0x00000060UL;
//    /* Common control the ADCAn  10-bit mode*/
//    ADCA0ADCR      = 0x00000010UL;
//    /* Set sampling time to 24*1/40MHz = 60us */
//    ADCA0SMPCR     = 0x00000018UL;
//    /* Set the upper limit / lower limit error detection threshold*/
//    ADCA0ULLMTBR0  = 0xFFF08000UL;
//    /* Set A/D conversion trigger (hardware trigger) of SGx Use INTTAUJ0I3*/
//    ADCA0SGTSEL1   = 0x00000002UL;
//	ADCA0SGTSEL2   = 0x00000002UL;
//	ADCA0SGTSEL3   = 0x00000002UL;
//    /* trigger A/B is selected for the trigger input to SGx*/
//    ADCA0SGCR1     = 0x00000001UL;
//	ADCA0SGCR2     = 0x00000001UL;
//	ADCA0SGCR3     = 0x00000001UL;
//    /*Start ch ADCA0VCR00,end ch ADCA0VCR015 scans num = 1*/
//    ADCA0SGVCSP1   = 0x00000000UL;
//    ADCA0SGVCEP1   = 0x0000000fUL;
//    ADCA0SGMCYCR1  = 0x00000000UL;
//	/*Start ch ADCA0VCR018,end ch ADCA0VCR019 scans num = 1*/
//    ADCA0SGVCSP2   = 0x00000012UL;
//    ADCA0SGVCEP2   = 0x00000013UL;
//    ADCA0SGMCYCR2  = 0x00000000UL;
//	/*Start ch ADCA0VCR025,end ch ADCA0VCR032 scans num = 1*/
//    ADCA0SGVCSP3   = 0x00000019UL;
//    ADCA0SGVCEP3   = 0x00000020UL;
//    ADCA0SGMCYCR3  = 0x00000000UL;
//    /* Enables the TAUJ ch.3 counter   */
//    TAUJ0TS    |= 0x0008U;
 
}/* End of ADC_vidInit() */

/******************************************************************************/
/*!Function : Adc_vidManage                                                     */
/*! \Description Manage ADC Sample and fliter
     a value in 16 bits. \n
    \Trace_To   
 ******************************************************************************/
void Adc_vidManage(void)
{
  uint8 u8Index;
  ADC_vidManage();
//  SEGGER_RTT_printf(0, "Adc_vidManage\r\n");
//    uint8 u8Index;
//	static uint8 LOC_u8SampleNb = 0u;
//    /*get ADC buffers*/
//    for(u8Index = 0u; u8Index < ADC_u8NUM_ADC; u8Index++)
//    {
//	  //lsy Adc_au16SamplingBuffer[u8Index][LOC_u8SampleNb] = *Adc_pkau32Data[u8Index];
//    }
//	LOC_u8SampleNb++; 
//    if(LOC_u8SampleNb >= ADC_SAMPLES_NUM)
//    {
//	     LOC_u8SampleNb = 0u;
//		 Adc_bFirstTimeAvg = TRUE;
//    }
//      ADC_AI26_PTA0 = 0u,              
//    ADC_AI25_PTA1,  //GAC_HP_P            
//    ADC_AI14_PTA6,  //GAC_CondIN_T              
//    ADC_AI13_PTA7,  //GAC_CondOUT_T                
//    ADC_AI12_PTB0,             
//    ADC_AI11_PTB1,            
//    ADC_AI10_PTB2,  //GAC_LP_T        
//    ADC_AI9_PTB3,  //GAC_HP_T               
//    /*******************************************************************************/
//    ADC_AI4_PTC0,  //GAC_OUTLET1            
//    ADC_AI3_PTC1,  //GAC_EVAP              
//    ADC_AI2_PTC2,  //GAC_BAT              
//    ADC_AI1_PTC3,  //GAC_IGN             
//    ADC_AI8_PTC14, //GAC_OUTLET4                 
//    ADC_AI7_PTC15,        
//    ADC_AI6_PTC16, //GAC_OUTLET3              
//    ADC_AI5_PTC17, //GAC_OUTLET2            
//    /*******************************************************************************/
//    ADC_AI24_PTA2,  //GAC_LP_P         
//    ADC_AI23_PTA3,  //GAC_NEW_ADD_PT_P             
//    ADC_AI22_PTD2,             
//    ADC_AI21_PTD3,              
//    ADC_AI28_PTC6,    
    
//  SEGGER_RTT_printf(0, "Adc_vidManage:bat=%d,ign=%d,mixl=%d,mixr=%d,modell=%d,modelr=%d,intake=%d,forset=%d,hp1=%d,hp2=%d\r\n",
//                    Adc_u16Read(ADC_u8AI_BAT_J2_21),Adc_u16Read(ADC_u8AI_IGN_J2_1),
//                    Adc_u16Read(ADC_u8MIXL_ID),Adc_u16Read(ADC_u8MIXR_ID),
//                    Adc_u16Read(ADC_u8MODEL_ID),Adc_u16Read(ADC_u8MODER_ID),
//                    Adc_u16Read(ADC_u8RECY_ID),Adc_u16Read(ADC_u8DEFORST_ID),
//                    Adc_u16Read(ADC_u8AI15_J3_13),Adc_u16Read(ADC_u8AI12_J3_4),
//                    );
//  for(u8Index=0;u8Index<ADC_MAX_ENUM;u8Index++)
//  {
//    SEGGER_RTT_printf(0, "adc-%d:=%d\r\n",
//                    u8Index,ADC_u16Read(u8Index));
//  }
//  SEGGER_RTT_printf(0, "ADC_AI21_PTD3=%d\r\n",ADC_u16CurrentADCReading(ADC_AI21_PTD3));
//  ;
}
/******************************************************************************/
/*!Function : Adc_u16Read                                                     */
/*! \Description Read the value asynchronously of the ADC and returns
     a value in 16 bits. \n
    \param[in]   u8Id : ID of data
    \Range       0  \n
    \return      converted value     \n
    \Trace_To    CDD-ADC-0007(0)
 ******************************************************************************/
uint16 Adc_u16Read(uint8 u8Id)
{
  uint16 u16Result = 0u;
  
  ADC_tenuChannelsId s32k144_adc_map_id=ADC_MAX_ENUM;
  
  if(u8Id==ADC_u8MIXL_ID)
  {
    s32k144_adc_map_id=ADC_AI10_PTB2;
  }
  else if(u8Id==ADC_u8MIXR_ID)
  {
    s32k144_adc_map_id=ADC_AI9_PTB3;
  }
  else if(u8Id==ADC_u8MODEL_ID)
  {
    s32k144_adc_map_id=ADC_AI5_PTC17;
  }
  else if(u8Id==ADC_u8MODER_ID)
  {
    s32k144_adc_map_id=ADC_AI6_PTC16;
  }
  else if(u8Id==ADC_u8DEFORST_ID)
  {
    s32k144_adc_map_id=ADC_AI8_PTC14;
  }
  else if(u8Id==ADC_u8RECY_ID)
  {
    s32k144_adc_map_id=ADC_AI13_PTA7;
  }
  else if(u8Id==ADC_u8RECY_ID)
  {
    s32k144_adc_map_id=ADC_AI13_PTA7;
  }
  else if(u8Id==ADC_u8AI8_J2_20)
  {
    s32k144_adc_map_id=ADC_AI19_PTB12;
  }
  else if(u8Id==ADC_u8AI11_J3_3)
  {
    s32k144_adc_map_id=ADC_AI18_PTB13;
  }
  else if(u8Id==ADC_u8AI12_J3_4)
  {
    s32k144_adc_map_id=ADC_AI27_PTC7;
  }
  else if(u8Id==ADC_u8AI14_J3_6)
  {
    s32k144_adc_map_id=ADC_AI3_PTC1;
  }
  else if(u8Id==ADC_u8AI15_J3_13)
  {
    s32k144_adc_map_id=ADC_AI28_PTC6;
  }
  else if(u8Id==ADC_u8AI_SUN_L_J2_12)
  {
    s32k144_adc_map_id=ADC_AI4_PTC0;
  }
  else if(u8Id==ADC_u8AI7_J2_19)
  {
    s32k144_adc_map_id=ADC_AI16_PTB15;
  }
  else if(u8Id==ADC_u8AI6_J2_18)
  {
    s32k144_adc_map_id=ADC_AI14_PTA6;
  }
  else if(u8Id==ADC_u8AI5_J2_17)
  {
    s32k144_adc_map_id=ADC_AI20_PTD4;
  }
  else if(u8Id==ADC_u8AI4_J2_16)
  {
    s32k144_adc_map_id=ADC_AI21_PTD3;
  }
  else if(u8Id==ADC_u8AI3_J2_15)
  {
    s32k144_adc_map_id=ADC_AI22_PTD2;
  }
  else if(u8Id==ADC_u8AI2_J2_14)
  {
    s32k144_adc_map_id=ADC_AI23_PTA3;
  }
  else if(u8Id==ADC_u8AI1_J2_13)
  {
    s32k144_adc_map_id=ADC_AI15_PTB16;
  }
  else if(u8Id==ADC_u8AI_BAT_J2_21)
  {
    s32k144_adc_map_id=ADC_AI2_PTC2;
  }
  else if(u8Id==ADC_u8AI_IGN_J2_1)
  {
    s32k144_adc_map_id=ADC_AI1_PTC3;
  }
    
  if(s32k144_adc_map_id!=ADC_MAX_ENUM)
  {
    u16Result=ADC_u16Read(s32k144_adc_map_id);
  }
  return u16Result ;
}/*End of ADC_u16Read() */



/** \} */ /* end of ADC module group */
/** \} */ /* end of MCAL ADC Component */

/*-------------------------------- end of file -------------------------------*/

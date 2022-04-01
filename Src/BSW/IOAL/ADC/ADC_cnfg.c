/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/


/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

#include "ADC_cnfg.h"

/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/
                     
/******************************************************************************/
/* PRIVATE VARIABLES                                                          */
/******************************************************************************/
/*!Comment: Arrays to hold the raw variables for ADC to be used in moving average */
 static uint16 ADC_u16AI26_PTA0Array[ADC_u8AI26_PTA0_Samples];
 static uint16 ADC_u16AI25_PTA1Array[ADC_u8AI25_PTA1_Samples];//GAC_HP_P 
 static uint16 ADC_u16AI14_PTA6Array[ADC_u8AI14_PTA6_Samples];//GAC_CondIN_T 
 static uint16 ADC_u16AI13_PTA7Array[ADC_u8AI13_PTA7_Samples];//GAC_CondOUT_T  
 static uint16 ADC_u16AI12_PTB0Array[ADC_u8AI12_PTB0_Samples];
 static uint16 ADC_u16AI11_PTB1Array[ADC_u8AI11_PTB1_Samples];
 static uint16 ADC_u16AI10_PTB2Array[ADC_u8AI10_PTB2_Samples];//GAC_LP_T  
 static uint16 ADC_u16AI9_PTB3Array[ADC_u8AI9_PTB3_Samples];//GAC_HP_T 
 
 static uint16 ADC_u16AI4_PTC0Array[ADC_u8AI4_PTC0_Samples];//GAC_OUTLET1
 static uint16 ADC_u16AI3_PTC1Array[ADC_u8AI3_PTC1_Samples];//GAC_EVAP 
 static uint16 ADC_u16AI2_PTC2Array[ADC_u8AI2_PTC2_Samples];//GAC_BAT 
 static uint16 ADC_u16AI1_PTC3Array[ADC_u8AI1_PTC3_Samples];//GAC_IGN 
 static uint16 ADC_u16AI8_PTC14Array[ADC_u8AI8_PTC14_Samples];//GAC_OUTLET4 
 static uint16 ADC_u16AI7_PTC15Array[ADC_u8AI7_PTC15_Samples];
 static uint16 ADC_u16AI6_PTC16Array[ADC_u8AI6_PTC16_Samples];//GAC_OUTLET3 
 static uint16 ADC_u16AI5_PTC17Array[ADC_u8AI5_PTC17_Samples];//GAC_OUTLET2  
 
 static uint16 ADC_u16AI24_PTA2Array[ADC_u8AI24_PTA2_Samples];//GAC_LP_P  
 static uint16 ADC_u16AI23_PTA3Array[ADC_u8AI23_PTA3_Samples];//GAC_NEW_ADD_PT_P 
 static uint16 ADC_u16AI22_PTD2Array[ADC_u8AI22_PTD2_Samples];
 static uint16 ADC_u16AI21_PTD3Array[ADC_u8AI21_PTD3_Samples];
 static uint16 ADC_u16AI28_PTC6Array[ADC_u8AI28_PTC6_Samples];
 static uint16 ADC_u16AI27_PTC7Array[ADC_u8AI27_PTC7_Samples];
 static uint16 ADC_u16AI20_PTD4Array[ADC_u8AI20_PTD4_Samples];
 static uint16 ADC_u16AI19_PTB12Array[ADC_u8AI19_PTB12_Samples];//GAC_NEW_ADD_PT_T 
 
 static uint16 ADC_u16AI18_PTB13Array[ADC_u8AI18_PTB13_Samples];//GAC_RECY_FB
 static uint16 ADC_u16AI17_PTB14Array[ADC_u8AI17_PTB14_Samples];//GAC_MODE_FB  
 static uint16 ADC_u16AI32_PTE2Array[ADC_u8AI32_PTE2_Samples];
 static uint16 ADC_u16AI31_PTE6Array[ADC_u8AI31_PTE6_Samples];
 static uint16 ADC_u16AI30_PTA15Array[ADC_u8AI30_PTA15_Samples];
 static uint16 ADC_u16AI29_PTA16Array[ADC_u8AI29_PTA16_Samples];
 static uint16 ADC_u16AI16_PTB15Array[ADC_u8AI16_PTB15_Samples];//GAC_MIXR_FB   
 static uint16 ADC_u16AI15_PTB16Array[ADC_u8AI15_PTB16_Samples];//GAC_MIXL_FB 


 extern const ADC_tstrData ADC_akstreData[ADC_u8NUM_CHNL]=
 {
         {
                 ADC_AI26_PTA0,
                 ADC_u8AI26_PTA0_Samples,
                 ADC_u8AI26_PTA0_CH,
                 ADC_u8AI26_PTA0_Sec,
                 ADC_u16AI26_PTA0Array
         },
         {
                 ADC_AI25_PTA1,
                 ADC_u8AI25_PTA1_Samples,
                 ADC_u8AI25_PTA1_CH,
                 ADC_u8AI25_PTA1_Sec,
                 ADC_u16AI25_PTA1Array
         },
         {
                 ADC_AI14_PTA6,
                 ADC_u8AI14_PTA6_Samples,
                 ADC_u8AI14_PTA6_CH,
                 ADC_u8AI14_PTA6_Sec,
                 ADC_u16AI14_PTA6Array
         },
         {
                 ADC_AI13_PTA7,
                 ADC_u8AI13_PTA7_Samples,
                 ADC_u8AI13_PTA7_CH,
                 ADC_u8AI13_PTA7_Sec,
                 ADC_u16AI13_PTA7Array
         },
         {
                 ADC_AI12_PTB0,
                 ADC_u8AI12_PTB0_Samples,
                 ADC_u8AI12_PTB0_CH,
                 ADC_u8AI12_PTB0_Sec,
                 ADC_u16AI12_PTB0Array
         },
         {
                 ADC_AI11_PTB1,
                 ADC_u8AI11_PTB1_Samples,
                 ADC_u8AI11_PTB1_CH,
                 ADC_u8AI11_PTB1_Sec,
                 ADC_u16AI11_PTB1Array
         },
         {
                 ADC_AI10_PTB2,
                 ADC_u8AI10_PTB2_Samples,
                 ADC_u8AI10_PTB2_CH,
                 ADC_u8AI10_PTB2_Sec,
                 ADC_u16AI10_PTB2Array
         },
         {
                 ADC_AI9_PTB3,
                 ADC_u8AI9_PTB3_Samples,
                 ADC_u8AI9_PTB3_CH,
                 ADC_u8AI9_PTB3_Sec,
                 ADC_u16AI9_PTB3Array
         },
         /********************************************/
         {
                 ADC_AI4_PTC0,
                 ADC_u8AI4_PTC0_Samples,
                 ADC_u8AI4_PTC0_CH,
                 ADC_u8AI4_PTC0_Sec,
                 ADC_u16AI4_PTC0Array
         },
         {
                 ADC_AI3_PTC1,
                 ADC_u8AI3_PTC1_Samples,
                 ADC_u8AI3_PTC1_CH,
                 ADC_u8AI3_PTC1_Sec,
                 ADC_u16AI3_PTC1Array
         },
         {
                 ADC_AI2_PTC2,
                 ADC_u8AI2_PTC2_Samples,
                 ADC_u8AI2_PTC2_CH,
                 ADC_u8AI2_PTC2_Sec,
                 ADC_u16AI2_PTC2Array
         },
         {
                 ADC_AI1_PTC3,
                 ADC_u8AI1_PTC3_Samples,
                 ADC_u8AI1_PTC3_CH,
                 ADC_u8AI1_PTC3_Sec,
                 ADC_u16AI1_PTC3Array
         },
         {
                 ADC_AI8_PTC14,
                 ADC_u8AI8_PTC14_Samples,
                 ADC_u8AI8_PTC14_CH,
                 ADC_u8AI8_PTC14_Sec,
                 ADC_u16AI8_PTC14Array
         },
         {
                 ADC_AI7_PTC15,
                 ADC_u8AI7_PTC15_Samples,
                 ADC_u8AI7_PTC15_CH,
                 ADC_u8AI7_PTC15_Sec,
                 ADC_u16AI7_PTC15Array
         },
         {
                 ADC_AI6_PTC16,
                 ADC_u8AI6_PTC16_Samples,
                 ADC_u8AI6_PTC16_CH,
                 ADC_u8AI6_PTC16_Sec,
                 ADC_u16AI6_PTC16Array
         },
         {
                 ADC_AI5_PTC17,
                 ADC_u8AI5_PTC17_Samples,
                 ADC_u8AI5_PTC17_CH,
                 ADC_u8AI5_PTC17_Sec,
                 ADC_u16AI5_PTC17Array
         },
         /********************************************/
         {
                 ADC_AI24_PTA2,
                 ADC_u8AI24_PTA2_Samples,
                 ADC_u8AI24_PTA2_CH,
                 ADC_u8AI24_PTA2_Sec,
                 ADC_u16AI24_PTA2Array
         },
         {
                 ADC_AI23_PTA3,
                 ADC_u8AI23_PTA3_Samples,
                 ADC_u8AI23_PTA3_CH,
                 ADC_u8AI23_PTA3_Sec,
                 ADC_u16AI23_PTA3Array
         },
         {
                 ADC_AI22_PTD2,
                 ADC_u8AI22_PTD2_Samples,
                 ADC_u8AI22_PTD2_CH,
                 ADC_u8AI22_PTD2_Sec,
                 ADC_u16AI22_PTD2Array
         },
         {
                 ADC_AI21_PTD3,
                 ADC_u8AI21_PTD3_Samples,
                 ADC_u8AI21_PTD3_CH,
                 ADC_u8AI21_PTD3_Sec,
                 ADC_u16AI21_PTD3Array
         },
         {
                 ADC_AI28_PTC6,
                 ADC_u8AI28_PTC6_Samples,
                 ADC_u8AI28_PTC6_CH,
                 ADC_u8AI28_PTC6_Sec,
                 ADC_u16AI28_PTC6Array
         },
         {
                 ADC_AI27_PTC7,
                 ADC_u8AI27_PTC7_Samples,
                 ADC_u8AI27_PTC7_CH,
                 ADC_u8AI27_PTC7_Sec,
                 ADC_u16AI27_PTC7Array
         },
         {
                 ADC_AI20_PTD4,
                 ADC_u8AI20_PTD4_Samples,
                 ADC_u8AI20_PTD4_CH,
                 ADC_u8AI20_PTD4_Sec,
                 ADC_u16AI20_PTD4Array
         },
         {
                 ADC_AI19_PTB12,
                 ADC_u8AI19_PTB12_Samples,
                 ADC_u8AI19_PTB12_CH,
                 ADC_u8AI19_PTB12_Sec,
                 ADC_u16AI19_PTB12Array
         },
         /***********************************/
         {
                 ADC_AI18_PTB13,
                 ADC_u8AI18_PTB13_Samples,
                 ADC_u8AI18_PTB13_CH,
                 ADC_u8AI18_PTB13_Sec,
                 ADC_u16AI18_PTB13Array
         },
         {
                 ADC_AI17_PTB14,
                 ADC_u8AI17_PTB14_Samples,
                 ADC_u8AI17_PTB14_CH,
                 ADC_u8AI17_PTB14_Sec,
                 ADC_u16AI17_PTB14Array
         },
         {
                 ADC_AI32_PTE2,
                 ADC_u8AI32_PTE2_Samples,
                 ADC_u8AI32_PTE2_CH,
                 ADC_u8AI32_PTE2_Sec,
                 ADC_u16AI32_PTE2Array
         },
         {
                 ADC_AI31_PTE6,
                 ADC_u8AI31_PTE6_Samples,
                 ADC_u8AI31_PTE6_CH,
                 ADC_u8AI31_PTE6_Sec,
                 ADC_u16AI31_PTE6Array
         },
         {
                 ADC_AI30_PTA15,
                 ADC_u8AI30_PTA15_Samples,
                 ADC_u8AI30_PTA15_CH,
                 ADC_u8AI30_PTA15_Sec,
                 ADC_u16AI30_PTA15Array
         },
         {
                 ADC_AI29_PTA16,
                 ADC_u8AI29_PTA16_Samples,
                 ADC_u8AI29_PTA16_CH,
                 ADC_u8AI29_PTA16_Sec,
                 ADC_u16AI29_PTA16Array
         },
         {
                 ADC_AI16_PTB15,
                 ADC_u8AI16_PTB15_Samples,
                 ADC_u8AI16_PTB15_CH,
                 ADC_u8AI16_PTB15_Sec,
                 ADC_u16AI16_PTB15Array
         },
         {
                 ADC_AI15_PTB16,
                 ADC_u8AI15_PTB16_Samples,
                 ADC_u8AI15_PTB16_CH,
                 ADC_u8AI15_PTB16_Sec,
                 ADC_u16AI15_PTB16Array
         } 
 };





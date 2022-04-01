#ifndef ADC_CNFG_H
#define ADC_CNFG_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"

/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/


/* !Comment : ADC channel Number       */
#define ADC_u8NUM_CHNL                             ((uint8)32)

/* !Comment : ADC0 channel first channel Number       */
#define ADC0_u8GRUOP0_FIRST_CHNL                   ((uint8)0)

/* !Comment : ADC0 channel end channel Number       */
#define ADC0_u8GRUOP0_END_CHNL                     ((uint8)7)



/* !Comment : ADC1 Group 0 first channel Number       */
#define ADC0_u8GRUOP1_FIRST_CHNL                   ((uint8)8)

/* !Comment : ADC1 Group 0 end channel Number       */
#define ADC0_u8GRUOP1_END_CHNL                     ((uint8)15)



/* !Comment : ADC1 Group 1 first channel Number       */
#define ADC1_u8GRUOP0_FIRST_CHNL                   ((uint8)16)

/* !Comment : ADC1 Group 1 end channel Number       */
#define ADC1_u8GRUOP0_END_CHNL                     ((uint8)23)



/* !Comment : ADC1 Group 1 first channel Number       */
#define ADC1_u8GRUOP1_FIRST_CHNL                   ((uint8)24)

/* !Comment : ADC1 Group 1 end channel Number       */
#define ADC1_u8GRUOP1_END_CHNL                     ((uint8)31)





/* !Comment : Number of AI_PTA0 Samples                               */
#define ADC_u8AI26_PTA0_Samples            ((uint8)1)
/* !Comment : AI_PTA0 ADC channel                                     */
#define ADC_u8AI26_PTA0_CH                 ((uint8)0)
/* !Comment : AI_PTA0 Number of seconds required Multiply by 10       */
#define ADC_u8AI26_PTA0_Sec                ((uint8)1)


/* !Comment : Number of AI_PTA1 Samples                               */
#define ADC_u8AI25_PTA1_Samples            ((uint8)1)
/* !Comment : AI_PTA1 ADC channel                                     */
#define ADC_u8AI25_PTA1_CH                 ((uint8)1)
/* !Comment : AI_PTA1 Number of seconds required Multiply by 10       */
#define ADC_u8AI25_PTA1_Sec                ((uint8)1)


/* !Comment : Number of AI_PTA6 Samples                               */
#define ADC_u8AI14_PTA6_Samples            ((uint8)1)
/* !Comment : AI_PTA6 ADC channel                                     */
#define ADC_u8AI14_PTA6_CH                 ((uint8)2)
/* !Comment : AI_PTA6 Number of seconds required Multiply by 10       */
#define ADC_u8AI14_PTA6_Sec                ((uint8)1)


/* !Comment : Number of AI_PTA7 Samples                               */
#define ADC_u8AI13_PTA7_Samples            ((uint8)1)
/* !Comment : AI_PTA7 ADC channel                                     */
#define ADC_u8AI13_PTA7_CH                 ((uint8)3)
/* !Comment : AI_PTA7 Number of seconds required Multiply by 10       */
#define ADC_u8AI13_PTA7_Sec                ((uint8)1)


/* !Comment : Number of AI_PTB0 Samples                               */
#define ADC_u8AI12_PTB0_Samples            ((uint8)1)
/* !Comment : AI_PTB0 ADC channel                                     */
#define ADC_u8AI12_PTB0_CH                 ((uint8)4)
/* !Comment : AI_PTB0 Number of seconds required Multiply by 10       */
#define ADC_u8AI12_PTB0_Sec                ((uint8)1)

/* !Comment : Number of AI_PTB1 Samples                               */
#define ADC_u8AI11_PTB1_Samples            ((uint8)1)
/* !Comment : AI_PTB1 ADC channel                                     */
#define ADC_u8AI11_PTB1_CH                 ((uint8)5)
/* !Comment : AI_PTB0 Number of seconds required Multiply by 10       */
#define ADC_u8AI11_PTB1_Sec                ((uint8)1)

/* !Comment : Number of AI_PTB2 Samples                               */
#define ADC_u8AI10_PTB2_Samples            ((uint8)1)
/* !Comment : AI_PTB2 ADC channel                                     */
#define ADC_u8AI10_PTB2_CH                 ((uint8)6)
/* !Comment : AI_PTB0 Number of seconds required Multiply by 10       */
#define ADC_u8AI10_PTB2_Sec                ((uint8)1)



/* !Comment : Number of AI_PTB3 Samples                               */
#define ADC_u8AI9_PTB3_Samples            ((uint8)1)
/* !Comment : AI_PTB3 ADC channel                                     */
#define ADC_u8AI9_PTB3_CH                 ((uint8)7)
/* !Comment : AI_PTB3 Number of seconds required Multiply by 10       */
#define ADC_u8AI9_PTB3_Sec                ((uint8)1)
/*******************************************************************************/

/* !Comment : Number of AI_PTC0 Samples                               */
#define ADC_u8AI4_PTC0_Samples            ((uint8)1)
/* !Comment : AI_PTC0 ADC channel                                     */
#define ADC_u8AI4_PTC0_CH                 ((uint8)0)
/* !Comment : AI_PTC0 Number of seconds required Multiply by 10       */
#define ADC_u8AI4_PTC0_Sec                ((uint8)1)

/* !Comment : Number of AI_PTC1 Samples                               */
#define ADC_u8AI3_PTC1_Samples            ((uint8)1)
/* !Comment : AI_PTC1 ADC channel                                     */
#define ADC_u8AI3_PTC1_CH                 ((uint8)1)
/* !Comment : AI_PTC1 Number of seconds required Multiply by 10       */
#define ADC_u8AI3_PTC1_Sec                ((uint8)1)


/* !Comment : Number of AI_PTC2 Samples                               */
#define ADC_u8AI2_PTC2_Samples            ((uint8)1)
/* !Comment : AI_PTC2 ADC channel                                     */
#define ADC_u8AI2_PTC2_CH                 ((uint8)2)
/* !Comment : AI_PTC2 Number of seconds required Multiply by 10       */
#define ADC_u8AI2_PTC2_Sec                ((uint8)1)

/* !Comment : Number of AI_PTC3 Samples                               */
#define ADC_u8AI1_PTC3_Samples            ((uint8)1)
/* !Comment : AI_PTC3 ADC channel                                     */
#define ADC_u8AI1_PTC3_CH                 ((uint8)3)
/* !Comment : AI_PTC3 Number of seconds required Multiply by 10       */
#define ADC_u8AI1_PTC3_Sec                ((uint8)1)

/* !Comment : Number of AI_PTC14 Samples                               */
#define ADC_u8AI8_PTC14_Samples            ((uint8)1)
/* !Comment : AI_PTC14 ADC channel                                     */
#define ADC_u8AI8_PTC14_CH                 ((uint8)4)
/* !Comment : AI_PTC14 Number of seconds required Multiply by 10       */
#define ADC_u8AI8_PTC14_Sec                ((uint8)1)

/* !Comment : Number of AI_PTC15 Samples                               */
#define ADC_u8AI7_PTC15_Samples            ((uint8)1)
/* !Comment : AI_PTC15 ADC channel                                     */
#define ADC_u8AI7_PTC15_CH                 ((uint8)5)
/* !Comment : AI_PTC15 Number of seconds required Multiply by 10       */
#define ADC_u8AI7_PTC15_Sec                ((uint8)1)


/* !Comment : Number of AI_PTC16 Samples                               */
#define ADC_u8AI6_PTC16_Samples            ((uint8)1)
/* !Comment : AI_PTC16 ADC channel                                     */
#define ADC_u8AI6_PTC16_CH                 ((uint8)6)
/* !Comment : AI_PTC16 Number of seconds required Multiply by 10       */
#define ADC_u8AI6_PTC16_Sec                ((uint8)1)


/* !Comment : Number of AI_PTC17 Samples                               */
#define ADC_u8AI5_PTC17_Samples            ((uint8)1)
/* !Comment : AI_PTC17 ADC channel                                     */
#define ADC_u8AI5_PTC17_CH                 ((uint8)7)
/* !Comment : AI_PTC17 Number of seconds required Multiply by 10       */
#define ADC_u8AI5_PTC17_Sec                ((uint8)1)


/*******************************************************************************/

/* !Comment : Number of AI_PTA2 Samples                               */
#define ADC_u8AI24_PTA2_Samples            ((uint8)1)
/* !Comment : AI_PTA2 ADC channel                                     */
#define ADC_u8AI24_PTA2_CH                 ((uint8)0)
/* !Comment : AI_PTA2 Number of seconds required Multiply by 10       */
#define ADC_u8AI24_PTA2_Sec                 ((uint8)1)



/* !Comment : Number of AI_PTA3 Samples                               */
#define ADC_u8AI23_PTA3_Samples            ((uint8)1)
/* !Comment : AI_PTA3 ADC channel                                     */
#define ADC_u8AI23_PTA3_CH                 ((uint8)1)
/* !Comment : AI_PTA3 Number of seconds required Multiply by 10       */
#define ADC_u8AI23_PTA3_Sec                 ((uint8)1)


/* !Comment : Number of AI_PTD2 Samples                               */
#define ADC_u8AI22_PTD2_Samples            ((uint8)1)
/* !Comment : AI_PTD2 ADC channel                                     */
#define ADC_u8AI22_PTD2_CH                 ((uint8)2)
/* !Comment : AI_PTD2 Number of seconds required Multiply by 10       */
#define ADC_u8AI22_PTD2_Sec                 ((uint8)1)


/* !Comment : Number of AI_PTD3 Samples                               */
#define ADC_u8AI21_PTD3_Samples            ((uint8)1)
/* !Comment : AI_PTD3 ADC channel                                     */
#define ADC_u8AI21_PTD3_CH                 ((uint8)3)
/* !Comment : AI_PTD3 Number of seconds required Multiply by 10       */
#define ADC_u8AI21_PTD3_Sec                 ((uint8)1)


/* !Comment : Number of AI_PTC6 Samples                               */
#define ADC_u8AI28_PTC6_Samples            ((uint8)1)
/* !Comment : AI_PTC6 ADC channel                                     */
#define ADC_u8AI28_PTC6_CH                 ((uint8)4)
/* !Comment : AI_PTC6 Number of seconds required Multiply by 10       */
#define ADC_u8AI28_PTC6_Sec                 ((uint8)1)



/* !Comment : Number of AI_PTC7 Samples                               */
#define ADC_u8AI27_PTC7_Samples            ((uint8)1)
/* !Comment : AI_PTC7 ADC channel                                     */
#define ADC_u8AI27_PTC7_CH                 ((uint8)5)
/* !Comment : AI_PTC7 Number of seconds required Multiply by 10       */
#define ADC_u8AI27_PTC7_Sec                 ((uint8)1)


/* !Comment : Number of AI_PTD4 Samples                               */
#define ADC_u8AI20_PTD4_Samples            ((uint8)1)
/* !Comment : AI_PTD4 ADC channel                                     */
#define ADC_u8AI20_PTD4_CH                 ((uint8)6)
/* !Comment : AI_PTD4 Number of seconds required Multiply by 10       */
#define ADC_u8AI20_PTD4_Sec                 ((uint8)1)




/* !Comment : Number of AI_PTB12 Samples                               */
#define ADC_u8AI19_PTB12_Samples            ((uint8)1)
/* !Comment : AI_PTB12 ADC channel                                     */
#define ADC_u8AI19_PTB12_CH                 ((uint8)7)
/* !Comment : AI_PTB12 Number of seconds required Multiply by 10       */
#define ADC_u8AI19_PTB12_Sec                 ((uint8)1)


/*******************************************************************************/

/* !Comment : Number of AI_PTB13 Samples                               */
#define ADC_u8AI18_PTB13_Samples            ((uint8)1)
/* !Comment : AI_PTB13 ADC channel                                     */
#define ADC_u8AI18_PTB13_CH                 ((uint8)0)
/* !Comment : AI_PTB13 Number of seconds required Multiply by 10       */
#define ADC_u8AI18_PTB13_Sec                ((uint8)1)


/* !Comment : Number of AI_PTB14 Samples                               */
#define ADC_u8AI17_PTB14_Samples            ((uint8)1)
/* !Comment : AI_PTB14 ADC channel                                     */
#define ADC_u8AI17_PTB14_CH                 ((uint8)1)
/* !Comment : AI_PTB14 Number of seconds required Multiply by 10       */
#define ADC_u8AI17_PTB14_Sec                 ((uint8)1)


/* !Comment : Number of AI_PTE2 Samples                               */
#define ADC_u8AI32_PTE2_Samples            ((uint8)1)
/* !Comment : AI_PTE2 ADC channel                                     */
#define ADC_u8AI32_PTE2_CH                 ((uint8)2)
/* !Comment : AI_PTE2 Number of seconds required Multiply by 10       */
#define ADC_u8AI32_PTE2_Sec                 ((uint8)1)


/* !Comment : Number of AI_PTE6 Samples                               */
#define ADC_u8AI31_PTE6_Samples            ((uint8)1)
/* !Comment : AI_PTE6 ADC channel                                     */
#define ADC_u8AI31_PTE6_CH                 ((uint8)3)
/* !Comment : AI_PTE6 Number of seconds required Multiply by 10       */
#define ADC_u8AI31_PTE6_Sec                 ((uint8)1)

/* !Comment : Number of AI_PTA15 Samples                               */
#define ADC_u8AI30_PTA15_Samples            ((uint8)1)
/* !Comment : AI_PTA15 ADC channel                                     */
#define ADC_u8AI30_PTA15_CH                 ((uint8)4)
/* !Comment : AI_PTA15 Number of seconds required Multiply by 10       */
#define ADC_u8AI30_PTA15_Sec                 ((uint8)1)

/* !Comment : Number of AI_PTA16 Samples                               */
#define ADC_u8AI29_PTA16_Samples            ((uint8)1)
/* !Comment : AI_PTA16 ADC channel                                     */
#define ADC_u8AI29_PTA16_CH                 ((uint8)5)
/* !Comment : AI_PTA16 Number of seconds required Multiply by 10       */
#define ADC_u8AI29_PTA16_Sec                 ((uint8)1)

/* !Comment : Number of AI_PTB15 Samples                               */
#define ADC_u8AI16_PTB15_Samples            ((uint8)1)
/* !Comment : AI_PTB15 ADC channel                                     */
#define ADC_u8AI16_PTB15_CH                 ((uint8)6)
/* !Comment : AI_PTB15 Number of seconds required Multiply by 10       */
#define ADC_u8AI16_PTB15_Sec                 ((uint8)1)


/* !Comment : Number of AI_PTB16 Samples                               */
#define ADC_u8AI15_PTB16_Samples            ((uint8)1)
/* !Comment : AI_PTA16 ADC channel                                     */
#define ADC_u8AI15_PTB16_CH                 ((uint8)7)
/* !Comment : AI_PTB16 Number of seconds required Multiply by 10       */
#define ADC_u8AI15_PTB16_Sec                ((uint8)1)
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* !Comment : enum of all ports which can be used as analog input             */
typedef enum
{
    ADC_AI26_PTA0 = 0u,              
    ADC_AI25_PTA1,  //GAC_HP_P            
    ADC_AI14_PTA6,  //GAC_CondIN_T              
    ADC_AI13_PTA7,  //GAC_CondOUT_T                
    ADC_AI12_PTB0,             
    ADC_AI11_PTB1,            
    ADC_AI10_PTB2,  //GAC_LP_T        
    ADC_AI9_PTB3,  //GAC_HP_T               
    /*******************************************************************************/
    ADC_AI4_PTC0,  //GAC_OUTLET1            
    ADC_AI3_PTC1,  //GAC_EVAP              
    ADC_AI2_PTC2,  //GAC_BAT              
    ADC_AI1_PTC3,  //GAC_IGN             
    ADC_AI8_PTC14, //GAC_OUTLET4                 
    ADC_AI7_PTC15,        
    ADC_AI6_PTC16, //GAC_OUTLET3              
    ADC_AI5_PTC17, //GAC_OUTLET2            
    /*******************************************************************************/
    ADC_AI24_PTA2,  //GAC_LP_P         
    ADC_AI23_PTA3,  //GAC_NEW_ADD_PT_P             
    ADC_AI22_PTD2,             
    ADC_AI21_PTD3,  //error            
    ADC_AI28_PTC6,          
    ADC_AI27_PTC7,              
    ADC_AI20_PTD4,               
    ADC_AI19_PTB12,  //GAC_NEW_ADD_PT_T            
    /*******************************************************************************/
    ADC_AI18_PTB13,  //GAC_RECY_FB             
    ADC_AI17_PTB14,  //GAC_MODE_FB          
    ADC_AI32_PTE2,            
    ADC_AI31_PTE6,               
    ADC_AI30_PTA15,         
    ADC_AI29_PTA16,             
    ADC_AI16_PTB15,  //GAC_MIXR_FB           
    ADC_AI15_PTB16,  //GAC_MIXL_FB           
    /*******************************************************************************/
    ADC_MAX_ENUM
} ADC_tenuChannelsId;


/* !Comment : structure which contains the configuration of one channel       */
typedef struct
{
    /* The ADC ID                   */
    ADC_tenuChannelsId ADC_enuChannelsId;

    /* The ADC required Samples     */
    uint8 ADC_u8ADCSampleNumber;

    /* The ADC Channel number       */
    uint8 ADC_u8ADCChannel;

    /* The ADC Sample time (multiples of 10) for example 2 is equivalent to 20       */
    uint8 ADC_u8ADCSampleTime;

    /* The ADC Raw value Array       */
    uint16 *ADC_u16ADCRawArray;

} ADC_tstrData;

/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/


 /*!Description : Array of configuration for all channels                     */

 extern const ADC_tstrData ADC_akstreData[ADC_u8NUM_CHNL];


/******************************************************************************/
/* PUBLIC FUNCTIONS                                                           */
/******************************************************************************/

#endif /* ADC_PBCFG_H */



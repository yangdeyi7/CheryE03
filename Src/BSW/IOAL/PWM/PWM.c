/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "device_registers.h"  /* include peripheral declarations S32K144 */
#include "Std_types.h"
#include "s32k144_PWM.h"
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
extern void PWM_vidInit(void)  
{
    PCC->PCCn[PCC_PORTB_INDEX ] |= PCC_PCCn_CGC_MASK;   /* Enable clock for PORTB */
    PCC->PCCn[PCC_PORTD_INDEX ] |= PCC_PCCn_CGC_MASK;   /* Enable clock for PORTD */
    PORTB->PCR[9]  |= PORT_PCR_MUX(2);           		/* Port B9: MUX  = ALT2, FTM3CH1 */
    PORTD->PCR[5]  |= PORT_PCR_MUX(2);           		/* Port D5: MUX  = ALT2, FTM2CH3 */
    PORTD->PCR[11] |= PORT_PCR_MUX(2);           		/* Port D11: MUX = ALT2, FTM2CH1 */

    /* FTM CLK = SYS_CLK = 40M */
    PCC->PCCn[PCC_FTM2_INDEX] &= ~PCC_PCCn_CGC_MASK; 
    PCC->PCCn[PCC_FTM2_INDEX] |= PCC_PCCn_PCS(0) | PCC_PCCn_CGC_MASK;
    FTM2->MODE |= FTM_MODE_WPDIS_MASK;  /* Write protect to registers disabled (default) */
    
    PCC->PCCn[PCC_FTM3_INDEX] &= ~PCC_PCCn_CGC_MASK; 
    PCC->PCCn[PCC_FTM3_INDEX] |= PCC_PCCn_PCS(0) | PCC_PCCn_CGC_MASK;
    FTM3->MODE |= FTM_MODE_WPDIS_MASK;  /* Write protect to registers disabled (default) */
    

    FTM2->MOD  = (20000u - 1u) ; /* 40MHz-->(Pre = 2)-->1/20us ->  ticks -> =1/20* 40000 = 2ms, 500Hz */                              
    FTM2->SC   = FTM_SC_CPWMS_MASK | FTM_SC_PS(1) | FTM_SC_CLKS(1) | FTM_SC_PWMEN1_MASK | FTM_SC_PWMEN3_MASK;  
    
    FTM3->MOD  = (50000u - 1u) ; /* 40MHz-->(Pre = 2)-->1/20us ->  ticks -> =1/20* 50000 = 2.5ms, 400Hz */
    FTM3->SC   = FTM_SC_CPWMS_MASK | FTM_SC_PS(1) | FTM_SC_CLKS(1) | FTM_SC_PWMEN1_MASK;
}
 


extern void PWM_vidWriteDutyCycleFine(uint8 u8Id ,uint16 u16DutyCycleFine)
{
    if(u8Id == PWM_u8BLW)
    {
       /* MSB:MSA (Mode Select)=0b10, Edge Align PWM*/
       /* ELSB:ELSA (Edge/Level Select)=0b10, low true */
       FTM3->CONTROLS[1].CnSC = FTM_CnSC_MSA_MASK | FTM_CnSC_ELSB_MASK;
       FTM3->CONTROLS[1].CnV = (FTM3->MOD + 1u)* u16DutyCycleFine / 1000u; 
    }
    else if(u8Id == PWM_u8OUT1)
    {
        /* MSB:MSA (Mode Select)=0b10, Edge Align PWM*/
        /* ELSB:ELSA (Edge/Level Select)=0b01, high true */
        FTM2->CONTROLS[3].CnSC = FTM_CnSC_MSA_MASK | FTM_CnSC_ELSB_MASK;
        FTM2->CONTROLS[3].CnV = (FTM2->MOD + 1u)* u16DutyCycleFine / 1000u;
    }
    else if(u8Id == PWM_u8OUT2)
    {
        /* MSB:MSA (Mode Select)=0b10, Edge Align PWM*/
        /* ELSB:ELSA (Edge/Level Select)=0b01, high true */
        FTM2->CONTROLS[1].CnSC = FTM_CnSC_MSA_MASK | FTM_CnSC_ELSB_MASK;
        FTM2->CONTROLS[1].CnV = (FTM2->MOD + 1u)* u16DutyCycleFine / 1000u;
    }
    else
    {
      
    }
} /* End of PWM_vidWriteDutyCycle() */





void pwm_test()
{
   PWM_vidWriteDutyCycleFine(PWM_u8OUT1,800);
   PWM_vidWriteDutyCycleFine(PWM_u8OUT2,600);
   PWM_vidWriteDutyCycleFine(PWM_u8BLW,400);
   while(1);
}



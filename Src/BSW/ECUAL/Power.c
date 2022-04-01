/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Power                                                   */
/*                                                                            */
/* !Component       : Power                                                   */
/* !Description     : Provides interface for managing power state of the ECU  */
/*                                                                            */
/* !Module          : Power                                                   */
/* !Description     : Provides interface for managing power state of the ECU  */
/*                                                                            */
/* !File            : Power.c                                                 */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : uPD70F3375                                              */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/EC$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Power.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:12   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
 
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Adc.h"
#include "Power.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description  The number of counts needed to change the Ignition state.
 ******************************************************************************/
#define u8IGN_STABLE_COUNT                     (uint8)10 /*10*10 = 100ms*/

/******************************************************************************/
/*! \Description IGN is ON corresponding ADC value\n
    \Range 297 (6.3V)
*******************************************************************************/
#define u16ADC_IGN_OFF                         (uint16)272

/******************************************************************************/
/*! \Description IGN is ON corresponding ADC value\n
    \Range 269 (6.5V)
*******************************************************************************/
#define u16ADC_IGN_ON                          (uint16)281



/******************************************************************************/
/*! \Description  The number of counts needed to change the current power level.
 ******************************************************************************/
#define u8POWER_STABLE_COUNT                   (uint8)10 /*10*10 = 100ms*/

/******************************************************************************/
/*! \Description When the BAT+ signal decreases to a voltage below this value,\n
                 the power level is considered RST voltage.
    \Range 269 (6.2V)
*******************************************************************************/
#define u16ADC_LEVEL_RST                       (uint16)269

/******************************************************************************/
/*! \Description When the BAT+ signal increases to a voltage greater than \n
                 this value, the power level is considered in LEVEL LV.
    \Range 281 (6.5V)
*******************************************************************************/
#define u16ADC_LEVEL_LV_UP                     (uint16)281

/******************************************************************************/
/*! \Description When the BAT+ signal decreases to a voltage below this value,\n
                 the power level is considered in LEVEL LV.
    \Range 284 (6.6V)
*******************************************************************************/
#define u16ADC_LEVEL_LV_DOWN                   (uint16)284

/******************************************************************************/
/*! \Description When the BAT+ signal increases to a voltage greater than \n
                 this value, the power level is considered in LEVEL A.
    \Range 297 (6.8V)
*******************************************************************************/
#define u16ADC_LEVEL_A_UP                      (uint16)297

/******************************************************************************/
/*! \Description When the BAT+ signal decreases to a voltage below this value,\n
                 the power level is considered in LEVEL A.
    \Range 364 (8.5V)
*******************************************************************************/
#define u16ADC_LEVEL_A_DOWN                    (uint16)364

/******************************************************************************/
/*! \Description When the BAT+ signal increases to a voltage greater than \n
                 this value, the power level is considered in LEVEL B.
    \Range 375 (8.8V)
*******************************************************************************/
#define u16ADC_LEVEL_B_UP                      (uint16)375

/******************************************************************************/
/*! \Description When the BAT+ signal decreases to a voltage below this value,\n
                 the power level is considered in LEVEL B.
    \Range 408 (9.5V)
*******************************************************************************/
#define u16ADC_LEVEL_B_DOWN                    (uint16)408

/******************************************************************************/
/*! \Description When the BAT+ signal increases to a voltage greater than \n
                 this value, the power level is considered in LEVEL C.
    \Range 452 (10.5V)
*******************************************************************************/
#define u16ADC_LEVEL_C_UP                      (uint16)452

/******************************************************************************/
/*! \Description When the BAT+ signal decreases to a voltage below this value,\n
                 the power level is considered in LEVEL C.
    \Range 698 (16.2V)
*******************************************************************************/
#define u16ADC_LEVEL_C_DOWN                    (uint16)698

/******************************************************************************/
/*! \Description When the BAT+ signal increases to a voltage greater than \n
                 this value, the power level is considered in LEVEL D.
    \Range 710 (16.5V)
*******************************************************************************/
#define u16ADC_LEVEL_D_UP                      (uint16)710

/******************************************************************************/
/*! \Description When the BAT+ signal decreases to a voltage below this value,\n
                 the power level is considered in LEVEL D.
    \Range 786 (18.2V)
*******************************************************************************/
#define u16ADC_LEVEL_D_DOWN                    (uint16)786

/******************************************************************************/
/*! \Description When the BAT+ signal increases to a voltage greater than \n
                 this value, the power level is considered in LEVEL HV.
    \Range 797 (18.5V)
*******************************************************************************/
#define u16ADC_LEVEL_HV                        (uint16)797









/******************************************************************************/
/*! \Description  The number of counts needed to change the current power dtc.
 ******************************************************************************/
#define u8POWER_DTC_STABLE_COUNT                (uint8)10 /*10*10 = 100ms*/

/******************************************************************************/
/*! \Description  ADC value when  Low Power Level/Voltage DTC trigger
    \Range 364 (8.5V)
*******************************************************************************/
#define u16ADC_DTC_POWER_LEVEL_UNDER_VOLT      (uint16)364


/******************************************************************************/
/*! \Description  ADC value when high Power Level/Voltage DTC trigger
    \Range 710 (16.5V)
*******************************************************************************/
#define u16ADC_DTC_POWER_LEVEL_EXCEED_VOLT     (uint16)710 








/******************************************************************************/
/*! \Description  The number of counts needed to wait Stepper Power stable
    \Range 10
*******************************************************************************/
#define u16STEPPERV_STABLE_COUNT               (uint16)10  /*10*10 = 100ms*/
/******************************************************************************/
/*! \Description  ADC value when high Stepper Power Voltage is low
    \Range 408 (9.5V)
*******************************************************************************/
#define u16ADC_STEPPERV_LO                     (uint16)408
/******************************************************************************/
/*! \Description  ADC value when high Stepper Power Voltage is high
    \Range 452 (10.5V)
*******************************************************************************/
#define u16ADC_STEPPERV_HI                     (uint16)452 



/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/******************************************************************************/
/*! \Description Different Power Level regions.  \n
 ******************************************************************************/
typedef enum
{
  POWER_REG_RST,
  POWER_UP_DWN_REG_LV,
  POWER_REG_LV,
  POWER_UP_DWN_REG_A,
  POWER_REG_A,
  POWER_UP_DWN_REG_B,
  POWER_REG_B,
  POWER_UP_DWN_REG_C,
  POWER_REG_C,
  POWER_UP_DWN_REG_D,
  POWER_REG_D,
  POWER_UP_DWN_REG_HV,
  POWER_REG_HV
}tenuPowerRegion;


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/******************************************************************************/
/*! \Description Ignition state.  \n
 ******************************************************************************/
static Power_tenuIGNState         Power_enuIGNStatus;
       Power_tenuIGNState         Power_enuIGNStatusRaw;


/******************************************************************************/
/*! \Description Reported Power Level.  \n
 ******************************************************************************/
static Power_tenuPowerLevel       Power_enuLevel;

/******************************************************************************/
/*! \Description Reported Stepper Power .  \n
 ******************************************************************************/
static Power_tenuStepperV         Power_enuStepperV;

/******************************************************************************/
/*! \Description Reported Power Dtc.  \n
 ******************************************************************************/
static Power_tenuDTCState         Power_enuDTCPowerStatus;


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidUpdateIgnitionState(void);
static void vidUpdatePowerLevel(void) ;


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
/******************************************************************************/
/*!Function : vidUpdateIgnitionState                                          */
/*! \Description Updates the IGN current ignition state.
    \return      void.
    \Trace_To:  CDD-Power-
*******************************************************************************/
static void vidUpdateIgnitionState( void )
{
    static uint8 LOC_u8IgnCount = 0u;
    static Power_tenuIGNState  LOC_enuCurrIgn = Power_IGN_OFF;
    uint16 u16ADCVoltage;

    /* get the IGN ADC sampling voltage*/
    u16ADCVoltage = Adc_u16Read(ADC_u8AI_IGN_J2_1);

    if (u16ADCVoltage > u16ADC_IGN_ON)
    {
        LOC_enuCurrIgn = Power_IGN_ON;
    }
    else if (u16ADCVoltage < u16ADC_IGN_OFF)
    {
        LOC_enuCurrIgn = Power_IGN_OFF;
    }

    if (LOC_enuCurrIgn != Power_enuIGNStatus)
    {
        /*! Increment the IGN counter. */
        LOC_u8IgnCount++;
    }
    /*! Else */
    else
    {
        /*! Set the IGN counter to zero. */
        LOC_u8IgnCount = 0u;
    }
	Power_enuIGNStatusRaw = LOC_enuCurrIgn;
    /*! If the IGN counter reaches 10 */
    if (LOC_u8IgnCount >= u8IGN_STABLE_COUNT)
    {
        /*! Set the Ignition state to the currently read ignition. */
        Power_enuIGNStatus = LOC_enuCurrIgn;
        /*! Set the IGN counter to zero. */
        LOC_u8IgnCount = 0u;
    }
} /*end of vidUpdateIgnitionState()  */


/******************************************************************************/
/*!Function : vidUpdatePowerLevel                                             */
/*! \Description Updates the current Power level.
    \return      void.
    \Trace_To:  CDD-Power-
*******************************************************************************/
static void vidUpdatePowerLevel()
{
           uint16                u16ADCVoltage;
           tenuPowerRegion       enuCurrPowerRegion;
    static uint8                 LOC_u8PowerCount = 0u;
    static uint16                LOC_u16DtcPowerCount = 0u;
    static uint16                LOC_u16StepperVCount = 0u;	

    static Power_tenuPowerLevel  LOC_enuCurrPwrLvl = Power_LEVEL_RST;
    static Power_tenuPowerLevel  LOC_enuLastPwrLvl = Power_LEVEL_RST;
    static Power_tenuDTCState    LOC_enuCurrDtcPwrLvl = Power_DTC_NORMALVOLTAGE;
    static Power_tenuDTCState    LOC_enuLastDtcPwrLvl = Power_DTC_NORMALVOLTAGE;
    static Power_tenuStepperV    LOC_enuCurrStepperV = Power_STEPPERV_LO;

    /*! Read the current Batt signal. */
    u16ADCVoltage = Adc_u16Read(ADC_u8AI_BAT_J2_21);

    /*****************POWER LEVEL Handle**************************************/
    /*! Set the current power level region based on the read voltage value */
    if (u16ADCVoltage < u16ADC_LEVEL_RST)
    {
         /*Lvl RST 6.2v*/
        enuCurrPowerRegion = POWER_REG_RST;     
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_LV_UP)
    {
        /*Lvl UP_DOWN LV 6.5v*/
        enuCurrPowerRegion = POWER_UP_DWN_REG_LV;
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_LV_DOWN)
    {
          /*Lvl LV 6.6v*/
        enuCurrPowerRegion = POWER_REG_LV;    
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_A_UP)
    {
        /*Lvl UP_DOWN A 6.8v*/
        enuCurrPowerRegion = POWER_UP_DWN_REG_A;
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_A_DOWN)
    {
         /*Lvl A 8.5v*/
        enuCurrPowerRegion = POWER_REG_A;      
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_B_UP)
    {
        /*Lvl UP_DOWN B 8.8v*/
        enuCurrPowerRegion = POWER_UP_DWN_REG_B;
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_B_DOWN)
    {
         /*Lvl B 9.5v*/
        enuCurrPowerRegion = POWER_REG_B;      
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_C_UP)
    {
        /*Lvl UP_DOWN C 10.5v*/
        enuCurrPowerRegion = POWER_UP_DWN_REG_C;
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_C_DOWN)
    {
        /*Lvl C 16.2v*/
        enuCurrPowerRegion = POWER_REG_C;
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_D_UP)
    {
        /*Lvl UP_DOWN D 16.5v*/
        enuCurrPowerRegion = POWER_UP_DWN_REG_D;
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_D_DOWN)
    {
        /*Lvl D 18.2v*/
        enuCurrPowerRegion = POWER_REG_D;
    }
    else if (u16ADCVoltage < u16ADC_LEVEL_HV)
    {
        /*Lvl UP_DOWN HV 18.5v*/
        enuCurrPowerRegion = POWER_UP_DWN_REG_HV;
    }
    else
    {
        /*Lvl HV*/
        enuCurrPowerRegion = POWER_REG_HV;
    }
/******************************************************************************/
    switch (enuCurrPowerRegion)
    {
         /*******************Lvl RST*********************************/
            /*! IF current power region is POWER_REG_RST */
        case POWER_REG_RST:

            /*! Set the current power level to Power_LEVEL_RST. */
            LOC_enuCurrPwrLvl = Power_LEVEL_RST;

            break ;
        /********************Lvl LV**********************************/
            /*! IF current power region is POWER_UP_DWN_REG_LV */
        case POWER_UP_DWN_REG_LV:

            /*! IF the reported power level is less than or equal
              Power_LEVEL_RST THEN */
            if (LOC_enuCurrPwrLvl <= Power_LEVEL_RST)
            {
                /*! Set the current power level to Power_LEVEL_RST. */
                LOC_enuCurrPwrLvl = Power_LEVEL_RST;

            }
            else
            {
                /*! Set the current power level to Power_LEVEL_LV. */
                LOC_enuCurrPwrLvl = Power_LEVEL_LV;
            }

            break ;

            /*! IF current power region is POWER_REG_LV */
        case POWER_REG_LV:

            /*! Set the current power level to Power_LEVEL_LV. */
            LOC_enuCurrPwrLvl = Power_LEVEL_LV;
            break ;
       /********************Lvl A**********************************/
            /*! IF current power region is POWER_UP_DWN_REG_A */
        case POWER_UP_DWN_REG_A:

            /*! IF the reported power level is less than or equal
              Power_LEVEL_LV THEN */
            if (LOC_enuCurrPwrLvl <= Power_LEVEL_LV)
            {
                /*! Set the current power level to Power_LEVEL_LV. */
                LOC_enuCurrPwrLvl = Power_LEVEL_LV;

            }
            else
            {
                /*! Set the current power level to Power_LEVEL_A. */
                LOC_enuCurrPwrLvl = Power_LEVEL_A;
            }
            break ;

            /*! IF current power region is POWER_REG_A */
        case POWER_REG_A:

            /*! Set the current power level to Power_LEVEL_A. */
            LOC_enuCurrPwrLvl = Power_LEVEL_A;
            break ;
        /********************Lvl B**********************************/
            /*! IF current power region is POWER_UP_DWN_REG_B */
        case POWER_UP_DWN_REG_B:

            /*! IF the reported power level is less than or equal
              Power_LEVEL_A THEN */
            if (LOC_enuCurrPwrLvl <= Power_LEVEL_A)
            {
                /*! Set the current power level to Power_LEVEL_A. */
                LOC_enuCurrPwrLvl = Power_LEVEL_A;

            }
            else
            {
                /*! Set the current power level to Power_LEVEL_B. */
                LOC_enuCurrPwrLvl = Power_LEVEL_B;
            }
            break ;
            /*! IF current power region is POWER_REG_B */
        case POWER_REG_B:

            /*! Set the current power level to Power_LEVEL_B. */
            LOC_enuCurrPwrLvl = Power_LEVEL_B;
            break ;
        /********************Lvl C**********************************/
            /*! IF current power region is POWER_UP_DWN_REG_C */
        case POWER_UP_DWN_REG_C:

            /*! IF the reported power level is less than or equal
              Power_LEVEL_B THEN */
            if (LOC_enuCurrPwrLvl <= Power_LEVEL_B)
            {
                /*! Set the current power level to Power_LEVEL_B. */
                LOC_enuCurrPwrLvl = Power_LEVEL_B;

            }
            else
            {
                /*! Set the current power level to Power_LEVEL_C. */
                LOC_enuCurrPwrLvl = Power_LEVEL_C;
            }
            break ;
       
            /*! IF current power region is POWER_REG_C */
        case POWER_REG_C:

            /*! Set the current power level to Power_LEVEL_C. */
            LOC_enuCurrPwrLvl = Power_LEVEL_C;
            break ;
            
        /********************Lvl D**********************************/
            /*! IF current power region is POWER_UP_DWN_REG_D */
        case POWER_UP_DWN_REG_D:

            /*! IF the reported power level is less than or equal
              Power_LEVEL_C THEN */
            if (LOC_enuCurrPwrLvl <= Power_LEVEL_C)
            {
                /*! Set the current power level to Power_LEVEL_C. */
                LOC_enuCurrPwrLvl = Power_LEVEL_C;

            }
            else
            {
                /*! Set the current power level to Power_LEVEL_D. */
                LOC_enuCurrPwrLvl = Power_LEVEL_D;
            }
            break ;
            
            /*! IF current power region is POWER_REG_D */
        case POWER_REG_D:

            /*! Set the current power level to Power_LEVEL_D. */
            LOC_enuCurrPwrLvl = Power_LEVEL_D;

            break ;
         /********************Lvl HV**********************************/
            /*! IF current power region is POWER_UP_DWN_REG_HV */
        case POWER_UP_DWN_REG_HV:

            /*! IF the reported power level is less than or equal
              Power_LEVEL_D THEN */
            if (LOC_enuCurrPwrLvl <= Power_LEVEL_D)
            {
                /*! Set the current power level to Power_LEVEL_D. */
                LOC_enuCurrPwrLvl = Power_LEVEL_D;

            }
            else
            {
                /*! Set the current power level to Power_LEVEL_HV. */
                LOC_enuCurrPwrLvl = Power_LEVEL_HV;
            }
            break ;
            /*! IF current power region is POWER_REG_HV */
        case POWER_REG_HV:

            /*! Set the current power level to Power_LEVEL_HV. */
            LOC_enuCurrPwrLvl = Power_LEVEL_HV;
            break ;

        default :
            break ;

    }
    /*! If the current power level is different from the reported power level.*/
    if (LOC_enuCurrPwrLvl != Power_enuLevel)
    {
        /*! If the current power level not equal the destination power level.*/
        if (LOC_enuCurrPwrLvl != LOC_enuLastPwrLvl)
        {
            /*! Set the destination power level to the current power level. */
            LOC_enuLastPwrLvl = LOC_enuCurrPwrLvl;
            /*! reset the power count to zero */
            LOC_u8PowerCount = 0u;
        }
        /*! Increment the Power Count. */
        LOC_u8PowerCount++;
    }
    else
    {
        /*! reset the power count to zero. */
        LOC_u8PowerCount = 0u;
    }	

    /*! If the power count reaches 3 */
    if (LOC_u8PowerCount >= u8POWER_STABLE_COUNT)
    {
        /*! reset the power count to zero. */
        LOC_u8PowerCount = 0u;
        /*! Set the reported power level to the current power level. */
        Power_enuLevel = LOC_enuCurrPwrLvl;
    }

    /************************POWER DTC handle*********************************/
    /*! if the voltage more than LVL D,This is over power dtc voltage*/
    if( u16ADCVoltage >= u16ADC_DTC_POWER_LEVEL_EXCEED_VOLT)
    {
        LOC_enuCurrDtcPwrLvl = Power_DTC_OVERVOLTAGE;
    }
    /*! if voltage less than LVL A,this is under power dtc voltage*/  
    else if(u16ADCVoltage <= u16ADC_DTC_POWER_LEVEL_UNDER_VOLT )
    {
        LOC_enuCurrDtcPwrLvl = Power_DTC_UNDERVOLTAGE;
    }
    /*! between LVL A and LVL D,this is normal dtc voltage . */
    else
    {
       LOC_enuCurrDtcPwrLvl = Power_DTC_NORMALVOLTAGE;
    }
    if (LOC_enuCurrDtcPwrLvl != LOC_enuLastDtcPwrLvl)
    {
        /*! Set the destination power level to the current power level. */
        LOC_enuLastDtcPwrLvl = LOC_enuCurrDtcPwrLvl;

        /*! reset the power count to zero */
        LOC_u16DtcPowerCount = 0u;
    }
    if (LOC_u16DtcPowerCount >= u8POWER_DTC_STABLE_COUNT)
    {
        /*! reset the power count to zero. */
        LOC_u16DtcPowerCount = 0u;
        /*! Set the reported power level to the current power level. */
        Power_enuDTCPowerStatus = LOC_enuCurrDtcPwrLvl;
    }
    else
    {
        LOC_u16DtcPowerCount++;
    }

    
    /***********************Stepper Power High/Low handle**********************/
    if( u16ADCVoltage < u16ADC_STEPPERV_LO)
    {
        LOC_enuCurrStepperV = Power_STEPPERV_LO;	
    }
    else if(u16ADCVoltage > u16ADC_STEPPERV_HI)
    {
        LOC_enuCurrStepperV = Power_STEPPERV_HI;
    }
	
	if (LOC_enuCurrStepperV != Power_enuStepperV)
	{
		if (LOC_u16StepperVCount < 10u) /*100ms*/
		{
			LOC_u16StepperVCount++;
		}
		else
		{
			Power_enuStepperV = LOC_enuCurrStepperV;
			LOC_u16StepperVCount = 0u;				
		}
	}
	else
	{
		LOC_u16StepperVCount = 0u;
	}
	
	

}/* End of vidUpdatePowerLevel() */



/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/*!Function : Power_vidInit                                                   */
/*! \Description Power Initialization function.
    \return     void.
    \Trace_To:  CDD-Power-
*******************************************************************************/
extern void Power_vidInit( void )
{
  Power_enuIGNStatus = Power_IGN_UNKNOWN;
  Power_enuIGNStatusRaw = Power_IGN_UNKNOWN;
  Power_enuLevel = Power_LEVEL_RST;
  Power_enuStepperV = Power_STEPPERV_LO;
  Power_enuDTCPowerStatus = Power_DTC_UNKNOWN;
} /* End of Power_vidInit() */


/******************************************************************************/
/*!Function : Power_vidManage                                             */
/*! \Description Updates the current Power level.
    \return     void.
    \Trace_To:  CDD-Power-
*******************************************************************************/
extern void Power_vidManage(void)
{
   vidUpdateIgnitionState();
   vidUpdatePowerLevel();
}/* End of Power_vidManagement() */ 
 
 
/******************************************************************************/
/*!Function : Power_enuGetIGNState                                            */
/*! \Description Get the IGN state from IGN1 digital input       \n
    \return      Power_On;Power_Off                              \n
    \Trace_To:   CDD-Power-
 ******************************************************************************/
extern Power_tenuIGNState Power_enuGetIGNState(void)
{
  return Power_enuIGNStatus ;
}/* End of Power_enuGetIGNState() */

/******************************************************************************/
/*!Function : Power_enuGetDTCBATState                                         */
/*! \Description Get the DTC BAT state        \n
    \return      Power_On;Power_Off           \n
    \Trace_To:  CDD-Power- 
 ******************************************************************************/
extern Power_tenuDTCState Power_enuGetDTCState(void)
{
  return Power_enuDTCPowerStatus ;
}/* End of Power_enuGetIGNState() */


/******************************************************************************/
/*!Function : Power_enuGetPowerLevel                                          */
/*! \Description returns the current Power Level.
    \return     Current Power level.
    \Trace_To   CDD-Power-
*******************************************************************************/
extern Power_tenuPowerLevel Power_enuGetPowerLevel(void)
{	
  /*! Return the current power level. */
  return Power_enuLevel;
}/* End of Power_enuGetPowerLevel() */

/******************************************************************************/
/*!Function : Power_enuGetStepperV                                            */
/*! \Description returns the current Stepper Voltage.
    \return     current Stepper Voltage.
    \Trace_To   CDD-Power-
*******************************************************************************/
extern Power_tenuStepperV Power_enuGetStepperV(void)
{
  return Power_enuStepperV;
}


/******************************************************************************/
/*!Function : Power_u16GetBatValue                                           */
/*! \Description returns the current Power value.
    \return     Current Power value.
    \Trace_To   CDD-Power-
*******************************************************************************/
/* the return value is equal to practical voltage *10  */
extern uint16 Power_u16GetBatValue( void )
{
    uint16 u16BatValue;
    uint16 u16AiBatAdcValue;
    uint32 u32data;
    /*! Calculate BAT ADC Value */ 
    u16AiBatAdcValue = Adc_u16Read(ADC_u8AI_BAT_J2_21);
    /* BAT*15/(15+56.2) = 5*ADC/1024  refer M8X SCHV2.0*/
    u32data = ((uint32)u16AiBatAdcValue) * 5u * 712u / 1024u / 15u;
    u16BatValue = (uint16)u32data;
    return u16BatValue ;
}

/******************************************************************************/
/*!Function : Power_u16GetIgnValue                                           */
/*! \Description returns the current Power value.
    \return     Current Power value.
    \Trace_To   CDD-Power-
*******************************************************************************/
/* the return value is equal to practical voltage *10  */
extern uint16 Power_u16GetIgnValue( void )
{
    uint16 u16IgnValue;
    uint16 u16AiIgnAdcValue;
    uint32 u32data;
    /*! Calculate IGN ADC Value */ 
    u16AiIgnAdcValue = Adc_u16Read(ADC_u8AI_IGN_J2_1);
    /* IGN*15/(15+56.2) = 5*ADC/1024  refer M8X SCHV2.0*/
    u32data = ((uint32)u16AiIgnAdcValue) * 5u * 712u / 1024u / 15u;
    u16IgnValue = (uint16)u32data;
    return u16IgnValue ;
}
int tatauaagag=0;
extern uint8 Power_u16GetIgnSts( void )
{
    uint8 u8IgnSts = 0;
    uint8 u16IgnValue = 0;
    u16IgnValue = Power_u16GetIgnValue();
    tatauaagag = u16IgnValue;
    if((u16IgnValue > 70u)&&(u16IgnValue < 180u))
    {
      u8IgnSts = 2u;
    }
    else
    {
      u8IgnSts = 0u;
    }
    return u8IgnSts ;
}
/** \} */ /* end of Power module group */
/** \} */ /* end of ECUAL Power Component */

/*-------------------------------- end of file -------------------------------*/ 

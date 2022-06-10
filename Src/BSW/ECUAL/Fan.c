/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "fan.h"
#include "s32k144_Pwm.h"
#include "TAB.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description Upper limit of the Fun Duty cycle.
 *  \Range  100
*******************************************************************************/
#define u16DUTY_UPPER_LIMIT              ((uint16)1000)

/**************16***************************************************************/
/*! \Description Fun Duty Change Counter.
 *  \Range  2*40
*******************************************************************************/
#define u8DUTY_CHANGE_CNT               ((uint8)2)


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
static const TAB16 Fun_aku16PwmLvlTab[] =
{
	-32768,0,
     0, 0,     /* BLW_F Pwm Level0*/
    230,1,     /* BLW_F Pwm Level1 */
    251,2,     /* BLW_F Pwm Level2 */
    271,3,     /* BLW_F Pwm Level3 */
    292,4,     /* BLW_F Pwm Level4 */
    313,5,     /* BLW_F Pwm Level5 */
    333,6,     /* BLW_F Pwm Level6 */
    354,7,     /* BLW_F Pwm Level7 */
	375,8,     /* BLW_F Pwm Level8 */
	395,9,     /* BLW_F Pwm Level9 */
	416,10,    /* BLW_F Pwm Level10 */
	437,11,    /* BLW_F Pwm Level11 */
	457,12,    /* BLW_F Pwm Level12 */
	478,13,    /* BLW_F Pwm Level13 */
	499,14,    /* BLW_F Pwm Level14 */
	519,15,    /* BLW_F Pwm Level15 */
	540,16,    /* BLW_F Pwm Level16 */
	561,17,    /* BLW_F Pwm Level17 */
	581,18,    /* BLW_F Pwm Level18 */
	602,19,    /* BLW_F Pwm Level19 */
	623,20,    /* BLW_F Pwm Level20 */
	643,21,    /* BLW_F Pwm Level21 */
	664,22,    /* BLW_F Pwm Level22 */
	685,23,    /* BLW_F Pwm Level23 */
	705,24,    /* BLW_F Pwm Level24 */
	726,25,    /* BLW_F Pwm Level25 */
	747,26,    /* BLW_F Pwm Level26 */
	767,27,    /* BLW_F Pwm Level27 */
	788,28,    /* BLW_F Pwm Level28 */
	809,29,    /* BLW_F Pwm Level29 */
	829,30,    /* BLW_F Pwm Level30 */
	850,31,    /* BLW_F Pwm Level31 */
	32767,31
};

	
static const uint16 Fun_aku16PwmLvlDefaultVal[Fun_u8NUM_FunLEVELS_F] =
{
     0      /* BLW_F Pwm Level0*/
    ,230    /* BLW_F Pwm Level1 */
    ,251    /* BLW_F Pwm Level2 */
    ,271    /* BLW_F Pwm Level3 */
    ,292    /* BLW_F Pwm Level4 */
    ,313    /* BLW_F Pwm Level5 */
    ,333    /* BLW_F Pwm Level6 */
    ,354    /* BLW_F Pwm Level7 */
	,375    /* BLW_F Pwm Level8 */
	,395    /* BLW_F Pwm Level9 */
	,416    /* BLW_F Pwm Level10 */
	,437    /* BLW_F Pwm Level11 */
	,457    /* BLW_F Pwm Level12 */
	,478    /* BLW_F Pwm Level13 */
	,499    /* BLW_F Pwm Level14 */
	,519    /* BLW_F Pwm Level15 */
	,540    /* BLW_F Pwm Level16 */
	,561    /* BLW_F Pwm Level17 */
	,581    /* BLW_F Pwm Level18 */
	,602    /* BLW_F Pwm Level19 */
	,623    /* BLW_F Pwm Level20 */
	,643    /* BLW_F Pwm Level21 */
	,664    /* BLW_F Pwm Level22 */
	,685    /* BLW_F Pwm Level23 */
	,705    /* BLW_F Pwm Level24 */
	,726    /* BLW_F Pwm Level25 */
	,747    /* BLW_F Pwm Level26 */
	,767    /* BLW_F Pwm Level27 */
	,788    /* BLW_F Pwm Level28 */
	,809    /* BLW_F Pwm Level29 */
	,829    /* BLW_F Pwm Level30 */
	,850    /* BLW_F Pwm Level31 */
};

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
/*! \Description Data that holds the current Fun level. \n
*******************************************************************************/
static Fun_tenuFunLevel   Fun_enuFunCurrLevel[Fun_u8NUM];

/******************************************************************************/
/*! \Description Data that holds the voltage of each Fun level. \n
*******************************************************************************/
static uint16   Fun_au16FunPwmLevels_F[Fun_u8NUM_FunLEVELS_F];

/******************************************************************************/
/*! \Description Data that holds the Fun Current Duty. \n
*******************************************************************************/
static uint16   Fun_u16FunCurrDuty[Fun_u8NUM];

/******************************************************************************/
/*! \Description Data that holds the Fun Duty Request. \n
*******************************************************************************/
static uint16   Fun_u16FunDutyRequest[Fun_u8NUM];


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidFunVlclManage(Fun_tenuFunId enuFunId);



/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/*!Function:   vidFunVlclManage                                            */
/*! \Description  Manage the Fun PWM signal     
    \Return      void.
    \Trace_To   CDD-Fun-  
*******************************************************************************/
static void vidFunVlclManage(Fun_tenuFunId enuFunId)
{    
	const  TAB16 *pstrPwmLvlTab;
    /*! If the Fun level requested is not the same as
      the current output Fun level*/
    if (Fun_u16FunCurrDuty[enuFunId] != Fun_u16FunDutyRequest[enuFunId])
    {
        /*! If the Fun level requested > the current output Fun level*/
        if (Fun_u16FunDutyRequest[enuFunId] > Fun_u16FunCurrDuty[enuFunId])
        {
            Fun_u16FunCurrDuty[enuFunId] += 1u ;
            if(Fun1 == enuFunId)
            {
                /*set pwm value*/
                PWM_vidWriteDutyCycleFine(PWM_u8OUT1 ,(Fun_u16FunCurrDuty[enuFunId]));
            }
            else if(Fun2 == enuFunId)
            {

            }
            else
            {

            }
        }
        /* if PWM need decreased ,then decrese to fixed value directly.*/
        else
        {
            if(Fun1 == enuFunId)
            {
                /*set pwm value*/
                PWM_vidWriteDutyCycleFine(PWM_u8OUT1 ,(Fun_u16FunDutyRequest[enuFunId]));
                /*! Make the current Fun level same as the Fun level request. */
                Fun_u16FunCurrDuty[enuFunId] = Fun_u16FunDutyRequest[enuFunId];
				pstrPwmLvlTab = Fun_aku16PwmLvlTab;
				Fun_enuFunCurrLevel[enuFunId] = (Fun_tenuFunLevel)LinInterpolation16(Fun_u16FunCurrDuty[enuFunId], pstrPwmLvlTab);
            }
            else if(Fun2 == enuFunId)
            {

            }
            else
            {
            }
        }
    }
    /***Curr Duty == Request Duty**/
    else
    {
		pstrPwmLvlTab = Fun_aku16PwmLvlTab;
		Fun_enuFunCurrLevel[enuFunId] = (Fun_tenuFunLevel)LinInterpolation16(Fun_u16FunCurrDuty[enuFunId], pstrPwmLvlTab);
    }
}/* end of vidFunVlclManage() */


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function:   Fun_vidInit                                                 */
/*! \Description Fun Initialization service. \n
    \Return      void.
    \Trace_To    CDD-Fun-
*******************************************************************************/
extern void Fun_vidInit(void)
{
    uint8 u8Index = 0u;

    for(u8Index = 0u; u8Index < Fun_u8NUM; u8Index++)
    {
        /*! Initialize the Fun current level. */
        Fun_u16FunCurrDuty[u8Index] = 0u ;
        /*! Initialize the Fun level request. */
        Fun_u16FunDutyRequest[u8Index] = 0u;
        /*! Initialize the Fun current Level. */
        Fun_enuFunCurrLevel[u8Index] = Fun_LEVEL_0;
    }
    /*use default*/
    Fun_vidSetContext(Fun_aku16PwmLvlDefaultVal);
    Fun_vidSetFunDuty(Fun1 , 0u);

}/* End of Fun_vidInit() */

/******************************************************************************/
/*!Function : Fun_vidSetContext.                                          */
/*! \Description This function sets the post build configuration parameters for
                 the stepper.
    \param[in]   pkstrContext : Pointer to context .
    \Range       NOT_NULL
    \return      void.
    \Trace_To    CDD-Stepper-0027(0)
*******************************************************************************/
void Fun_vidSetContext(const uint16* pku16Context)
{
    uint8   u8Index = 0u;
    /*! IF pkstrContext not equal to null pointer */
    if (pku16Context != 0u)
    { 
        for (u8Index = 0u; u8Index < Fun_u8NUM_FunLEVELS_F; u8Index++)
        {
           Fun_au16FunPwmLevels_F[u8Index] = pku16Context[u8Index];
        }
    } 
}



/******************************************************************************/
/*!Function:   Fun_vidSetFunDuty                                        */
/*! \Description Set the Fun level,for Diag IO Control use \n
    \param[in]   enuFunLevel:    The requested Fun Pwm Duty Value.
    \Range      0~100 
    \Return      void.
    \Trace_To   CDD-Fun-
*******************************************************************************/
extern void Fun_vidSetFunDuty
(
  Fun_tenuFunId enuFunId,
  uint16 u16FunDuty
)
{
    u16FunDuty = (uint16)(75u - (uint16)(u16FunDuty/2));
    u16FunDuty = u16FunDuty*10u;
    /*!fix Fun Pwm Duty when resqust Pwm Duty exceed limit. */
    if (u16FunDuty > u16DUTY_UPPER_LIMIT)
    {
        u16FunDuty = u16DUTY_UPPER_LIMIT;
    }
	
    /*! Set the Fun Pwm Duty request. */
    Fun_u16FunDutyRequest[enuFunId] = u16FunDuty;
	
}



/******************************************************************************/
/*!Function:   Fun_u8GetFunDuty                                         */
/*! \Description get the Fun current duty.for Diag  use  \n
    \Return      FunDuty.
    \Trace_To   CDD-Fun-  
*******************************************************************************/
extern uint16 Fun_u16GetFunDuty(Fun_tenuFunId enuFunId)
{
    return Fun_u16FunCurrDuty[enuFunId];
}



/******************************************************************************/
/*!Function:   Fun_vidSetFunLevel                                       */
/*! \Description Set the Fun level. \n
    \param[in]   enuFunLevel:    The requested Fun level.
    \Range       Fun_LEVEL_OFF, Fun_LEVEL_1, Fun_LEVEL_2,
                 Fun_LEVEL_3, Fun_LEVEL_4, Fun_LEVEL_5,
                 Fun_LEVEL_6, Fun_LEVEL_7 \n
    \Return      void.
    \Trace_To   CDD-Fun-
*******************************************************************************/
extern void Fun_vidSetFunLevel
(
  Fun_tenuFunId enuFunId,
  Fun_tenuFunLevel enuFunLevel
)
{
    if(Fun1  == enuFunId)
    {
        /*!fix FunLevel when resqust level exceed limit. */
        if (enuFunLevel >= Fun_u8NUM_FunLEVELS_F)
        {
            enuFunLevel =
                 (Fun_tenuFunLevel)(Fun_u8NUM_FunLEVELS_F - 1u);
        }
        /*!get corresponding Fun Pwm requst*/
        Fun_u16FunDutyRequest[enuFunId] = Fun_au16FunPwmLevels_F[enuFunLevel];
    }
    else if(Fun2  == enuFunId)
    {

    }
    else
    {
        
    }
}


/******************************************************************************/
/*!Function:   Fun_u8GetFunLevel                                         */
/*! \Description get the Fun current Level. \n
    \Return      FunLevel.
    \Trace_To    CDD-Fun- 
*******************************************************************************/
extern Fun_tenuFunLevel Fun_enuGetFunLevel
(
  Fun_tenuFunId enuFunId
)
{
#if 0
    uint16 u16CurrPwmTmp = 0u;
     
    if(Fun_F == enuFunId)
    {
		u16CurrPwmTmp = Fun_u16FunCurrDuty;

        if (Fun_enuFunCurrLevel[enuFunId] == Fun_LEVEL_0)
        {
            if (u16CurrPwmTmp <=
            (((Fun_au16FunPwmLevels_F[0] + Fun_au16FunPwmLevels_F[1]) / 2u) + 2u))
            {
                /*do nothing:keep lvl-0*/
            }
            else
            {
                Fun_enuFunCurrLevel[enuFunId]++;
            }
        }
        else if (Fun_enuFunCurrLevel[enuFunId] == Fun_LEVEL_31)
        {
            if (u16CurrPwmTmp  >=
            (((Fun_au16FunPwmLevels_F[30] + Fun_au16FunPwmLevels_F[31]) / 2u) - 2u))
            {
                /*do nothing:keep lvl-31*/
            }
            else
            {
                Fun_enuFunCurrLevel[enuFunId]--;
            }
        }
        else
        {
            if ((u16CurrPwmTmp  < (((Fun_au16FunPwmLevels_F[Fun_enuFunCurrLevel[enuFunId]] +
                    Fun_au16FunPwmLevels_F[Fun_enuFunCurrLevel[enuFunId] - 1u]) / 2u) - 2u)))
            {
                Fun_enuFunCurrLevel[enuFunId]--;
            }
            else if ((u16CurrPwmTmp  > (((Fun_au16FunPwmLevels_F[Fun_enuFunCurrLevel[enuFunId]] +
                    Fun_au16FunPwmLevels_F[Fun_enuFunCurrLevel[enuFunId] + 1u]) / 2u) + 2u)))
            {
                Fun_enuFunCurrLevel[enuFunId]++;
            }
            else
            {
                /*do nothing:keep lvl-x*/
            }
        }
        if (Fun_enuFunCurrLevel[enuFunId]  > Fun_LEVEL_31)
        {
            Fun_enuFunCurrLevel[enuFunId]  = Fun_LEVEL_31;
        }
    }
    /**************************************************************************/
    else if(Fun_R == enuFunId)
    {

    }
    else
    {

    }
#else

#endif

    return Fun_enuFunCurrLevel[enuFunId];
}



/******************************************************************************/
/*!Function:   Fun_vidManage                                               */
/*! \Description Manage the Fun PWM signal. \n
    \Return      void.
    \Trace_To  CDD-Fun-
*******************************************************************************/
extern void Fun_vidManage()
{  
    vidFunVlclManage(Fun1);
    vidFunVlclManage(Fun2);
}/* End of Fun_vidManage()  */



void Fun_test()
{
    Fun_vidSetFunDuty(Fun1 , 450);
//  while(1)
//    {
//        Fun_vidManage();
//    }
////    PWM_vidWriteDutyCycleFine(PWM_u8BLW ,700);
////    PWM_vidWriteDutyCycleFine(PWM_u8OUT2,300);
////    PWM_vidWriteDutyCycleFine(PWM_u8OUT1,100);
//    while(1);
}

/** \} */ /* end of Fun module group */
/** \} */ /* end of ECUAL Fun Component */

/*-------------------------------- end of file -------------------------------*/



/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Gpt                                                     */
/*                                                                            */
/* !Component       : Gpt                                                     */
/* !Description     : Interface for managing general purpose timer.           */
/*                                                                            */
/* !Module          : Gpt                                                     */
/* !Description     : Gpt                                                     */
/*                                                                            */
/* !File            : Gpt.c                                                   */
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
#include "Device.h"
#include "Std_Types.h"
#include "Gpt.h"
#include "s32k144_GPT.h"
//#include "Gpt_Cfg.h"

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
/** TRUE/FALSE if Timer M Initialized                                    
 ******************************************************************************/
static  boolean                  Gpt_bTimerIsInitialized;

/******************************************************************************/
/*! \Description Pointer to  call back function .  \n
 ******************************************************************************/
 static Gpt_tpfvidTimerCallback  Gpt_pfvidTimerCallback;

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
/*!Function : Gpt_vidInit                                                     */
/*! \Description Initialize  Global variables  .\n 
    \return      void    \n
*******************************************************************************/
void Gpt_vidInit(const Gpt_tstrConfigType* pkstrConfigPtr)
{
    GPT_vidInit();
//	Gpt_bTimerIsInitialized = FALSE;
//		
//    if ( pkstrConfigPtr == NULL_PTR)
//    {
//        /* The Ptr not refering to the right struct                           */
//    }
//    else if(Gpt_bTimerIsInitialized == TRUE)
//    {
//        /* The Timer is Initialized and cant be initialized before calling of
//		   Gpt_vidDeInit()                                                   */
//    }
//    else if( pkstrConfigPtr->u8ChannelNumber > (uint8)MaxNumberofChannels)
//    {
//        /* The Gpt_vidInit is trying to Initialize an undefined channel      */
//    }
//	else
//    {
//		/* To indicate that the timer is initialized                         */
//		Gpt_bTimerIsInitialized = TRUE;
//		/* Disable OSTM0 operation */
//        OSTM0TT = 0x01u;      
//        /* Disable OSTM0 interrupt operation */
//        INTC2MKOSTM0 = 1u;
//        /* clear OSTM0 interrupt request */
//        INTC2RFOSTM0 = 0u;
//		/* Direct jumping to an address by the level of priority */
//        INTC2TBOSTM0 = 1u;
//		/* Set OSTM0 control setting as Interval timer mode */
//        OSTM0CTL = 0x00u;
//	    /* Assign Compare Match reg with required number of ticks.            */
//        OSTM0CMP = Gpt_ku16CMP_Ticks;
//	    /*! Initialize timer callback to 0 */
//        Gpt_pfvidTimerCallback  = (Gpt_tpfvidTimerCallback)0;
//	}
}



/******************************************************************************/
/*!Function : Gpt_vidStartTimer                                               */
/*! \Description Start the timer and pass it the callback to call when the
                 timer fires  .\n 
    \param[in]   Timer callback. \n
    \Range       NOT NULL.  \n   
    \return      void     \n
*******************************************************************************/
void Gpt_vidStartTimer(Gpt_tenuChannelType enuChannel,
		               Gpt_tpfvidTimerCallback  pfvidTimerCallback)
{
    GPT_vidStartSchedTimer();
//	if(enuChannel > (uint8)MaxNumberofChannels)
//    {
//        /*UnDeclared Channels												  */
//    }
//    else if( Gpt_bTimerIsInitialized == FALSE)
//    {
//        /* The Timer is UnInitialized and cant start before calling
//		   of Gpt_vidInit()                                                   */
//    }
//    else
//    {
//        /* Enable OSTM0 interrupt operation */
//        INTC2MKOSTM0 = 0u; 
//        /* Enable OSTM0 operation */
//        OSTM0TS = 0x01u;
//	    /* Load Callback Function for scheduler*/  
//	    Gpt_pfvidTimerCallback =  pfvidTimerCallback;
//	}


}

 /******************************************************************************/
/*!Function : Gpt_vidStopTimer                                                 */
/*! \Description Initialize  Global variables  .\n 
    \return      void    \n
*******************************************************************************/
void  Gpt_vidStopTimer(Gpt_tenuChannelType enuChannel)
{
    GPT_vidDeInit();
//    if(enuChannel > MaxNumberofChannels)
//    {
//        /*UnDeclared Channels												  */
//    }
//    else if( Gpt_bTimerIsInitialized == FALSE)
//    {
//        /* The Timer is Uninitialized and cant stopped before calling of
//		   Gpt_vidInit()                                                      */
//    }
//    else
//    {
//        /* Disable OSTM0 operation */
//        OSTM0TT = 0x01u;      
//        /* Disable OSTM0 interrupt operation */
//        INTC2MKOSTM0 = 1u;
//        /* clear OSTM0 interrupt request */
//        INTC2RFOSTM0 = 0u;
//    }
}



/******************************************************************************/
/*!Function : GPT_vidTimer                                                    */
/*! \Description INTOSTM0 interrupt routine  .
    \return      void
*******************************************************************************/
//#pragma ghs interrupt
//void INTOSTM0( void )
//{
//    if (Gpt_pfvidTimerCallback != NULL_PTR ) 
//    { 
//          /*! call callback function*/
//          Gpt_pfvidTimerCallback();
//    }   
//}
/* End of __interrupt void GPT_vidTimer( void ) */
                                                                             

/** \} */ /* end of GPT module group */
/** \} */ /* end of GPT MCAL Component */

/*-------------------------------- end of file ---------------------------------*/                                           

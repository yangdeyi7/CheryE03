/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
/*user define include */
#include "Std_Types.h"
/*Services include */
#include "SchM.h"
#include "SchM_Tasks.h"
/*MCAL include */
#include "Dio.h"
#include "s32k144_GPT.h"
/*ECUAL include*/
#include "Elmos.h"
#include "Stepper.h"
#include "TLE9410xDrv.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description max value of timing counter.
 *! \Range  80
*******************************************************************************/
#define u16MAX_TASK_PERIOD (uint16)200
 
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
/*! \Description counter to switch exact task.
*******************************************************************************/
static uint16 SchM_u16TimingCounter;

/******************************************************************************/
/*! \Description flag to active scheduler.
*******************************************************************************/
static boolean SchM_bIsSchActive;

/******************************************************************************/
/*! \Description Indicates whether Task 1 should be called or not.
*******************************************************************************/
static boolean SchM_bActivTask1;


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidTick( void );


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/*!Function :   vidTick                                                       */
/*! \Description function to inform that 1ms passed.
    \return      void.
    \Trace_to: 
*******************************************************************************/
static void vidTick( void )
{ 
  /*! If Scheduler Is Active*/
  if (SchM_bIsSchActive == TRUE)
  {
    /*! Increment The SchM Counter */
    SchM_u16TimingCounter++;
    
    /* if SchM counter is equal to 10,20,30 .....*/
    if ( (SchM_u16TimingCounter % 10) == 0)
    {
       /*! Set Activate Task 1 Flag To TRUE*/
       SchM_bActivTask1 = TRUE;
       SEGGER_RTT_printf(0, "SchM_vidGptCbk:%d\r\n",SchM_u16TimingCounter);
    }

    if ( SchM_u16TimingCounter == u16MAX_TASK_PERIOD)
    {
       /*! Reinitialize Timing Counter*/
       SchM_u16TimingCounter = 0;
    }
    
  }

} /* End of vidTick() */ 


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/*!Function :   SchM_vidGptCbk                                                */
/*! \Description call timer and refresh elmos and stepper.
    \return      void.
    \Trace_To :  CDD-SchM-0015(0)
*******************************************************************************/
void SchM_vidGptCbk( void )
{
  /*! Call Tick Function */
  vidTick();
  /*! Refresh Stepper*/
  //Stepper_vidControl();
  /*! Refresh Elmos*/
  //Elmos_vidRefresh(); 
    
} /* End of SchM_vidGptCbk */  

/******************************************************************************/
/*!Function :   SchM_vidInit                                                  */
/*! \Description initialize global variables.
    \return      void.
    \Trace_To :  CDD-SchM-0013(0)
*******************************************************************************/
void SchM_vidInit( void )
{
  /*! Set the activate task 1 flag. */
  SchM_bActivTask1 = TRUE;

  /*! Initialize timing counter to 0*/
  SchM_u16TimingCounter = (uint8)0;

  /*! Initialize flag to active scheduler to False*/
  SchM_bIsSchActive = (boolean) FALSE;
  
  GPT_pfvideOSCallback = &SchM_vidGptCbk;
}


/******************************************************************************/
/*!Function :   SchM_vidScheduler                                             */
/*! \Description call tasks at its time.
    \return      void.
    \Trace_To    CDD-SchM-0014(0)
*******************************************************************************/
void SchM_vidScheduler( void )
{
  /*! Activate scheduler*/
  SchM_bIsSchActive = (boolean) TRUE;
  /*! While One  */
  /*! Deviation : Inhibit PCLINT rule [716]: Infinite loop needed by the Scheduler */
  /*! lint -save -e716 */
  for(; ;)
  {
    SchM_bIsSchActive = (boolean)TRUE;
    switch (SchM_u16TimingCounter) 
    {
      /*! If scheduling timer equal 0*/
      case 0:
      case 1:
      case 2:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
          SchM_vidTask10ms();
        }
        break ;
        /*! If scheduling timer equal 10*/
      case 10:
      case 11:
      case 12:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks and 60ms tasks.*/
          SchM_vidTask10ms();
          SchM_vidTask40ms();         
        }
        break ;
       /*! If scheduling timer equal 20*/
      case 20:
      case 21:
      case 22:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms task and 100ms task*/
	  SchM_vidTask10ms();
          SchM_vidTask100ms(); 	  
        }
        break ;
        /*! If scheduling timer equal 30*/
      case 30:
      case 31:
      case 32:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
          SchM_vidTask10ms();
        }
        break ;
        /*! If scheduling timer equal 40*/
      case 40:
      case 41:
      case 42:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
          SchM_vidTask10ms();  
        }
        break ;
        /*! If scheduling timer equal 50*/
      case 50:
      case 51:
      case 52:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms task*/
          SchM_vidTask10ms();
	  SchM_vidTask40ms();
        }
        break ;
        /*! If scheduling timer equal 60*/
      case 60:
      case 61:
      case 62:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms task*/
          SchM_vidTask10ms();
        }
        break ;  
        /*! If scheduling timer equal 70*/
      case 70:
      case 71:
      case 72:
        /*! IF activate Task 1 Flag is set */
        if (SchM_bActivTask1 == TRUE)
        {
          /*! Reset the Activate Task 1 Flag. */
          SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks and 60ms tasks.*/
          SchM_vidTask10ms();
        }
        break ;  
        /*! If scheduling timer equal 60*/
      case 80:         
      case 81:       
      case 82:       
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break;  
         /*! If scheduling timer equal 90*/
      case 90:
      case 91:         
      case 92: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
	   SchM_vidTask40ms();
         }  
         break; 
         /*! If scheduling timer equal 100*/
      case 100:
      case 101:	 
      case 102: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break;      
      case 110:
      case 111:	 
      case 112: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break; 
      case 120:
      case 121:	 
      case 122: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
           /*! call 10ms tasks and 100ms tasks.*/
           SchM_vidTask10ms();
	   SchM_vidTask100ms();
         }  
         break; 	 
      case 130:
      case 131:	 
      case 132: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
           /*! call 10ms tasks and 60ms tasks.*/
           SchM_vidTask10ms();
	   SchM_vidTask40ms();
         }  
         break; 
      case 140:
      case 141:	 
      case 142: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break; 	 	 
      case 150:
      case 151:	 
      case 152: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break; 	 
      case 160:
      case 161:	 
      case 162: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break; 	 
      case 170:
      case 171:	 
      case 172: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
	   SchM_vidTask40ms();
         }  
         break; 	 
      case 180:
      case 181:	 
      case 182: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break; 	 
      case 190:
      case 191:	 
      case 192: 
         if (SchM_bActivTask1 == TRUE)
         {
          /*! Reset the Activate Task 1 Flag. */
           SchM_bActivTask1 = FALSE;
          /*! call 10ms tasks*/
           SchM_vidTask10ms();
         }  
         break; 	 
      /*! else*/
      default :
        break ;
    }
   
  } 
  /*! lint -restore */
} /* End of SchM_vidScheduler() */

/******************************************************************************/
/* !Function    : SchM_u8GetTimingCounter                                     */
/* !Description : getting the timing counter to be used as seed                 */
/* !Parameter[in]: void                                                       */
/* !Comment      :                                                            */
/*! \Trace_To:        HVAC_SCD_SYSTEM_0057#01                                    */
/******************************************************************************/
uint8 SchM_u8GetTimingCounter( void )
{
   uint8 u8TimingCounter ;
   u8TimingCounter = SchM_u16TimingCounter ;
   return (uint8)u8TimingCounter ;
}


/******************************************************************************/
/* !Function    : SchM_SetActive                                             */
/* !Description : Setting the schedule flg to active state                        */
/* !Parameter[in]: void                                                       */
/* !Comment      :                                                            */
/*! \Trace_To:        HVAC_SCD_SYSTEM_0057#01                                    */
/******************************************************************************/
void SchM_SetActive(void)
{
    /*! Activate scheduler*/
    SchM_bIsSchActive = (boolean) TRUE;
}

/** \} */ /* end of SchM module group */
/** \} */ /* end of Sevice SchM Component */

/*-------------------------------- end of file -------------------------------*/

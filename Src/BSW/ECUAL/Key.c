/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Key                                                     */
/*                                                                            */
/* !Component       : Key                                                     */
/* !Description     : Provides interface for managing keys                    */
/*                                                                            */
/* !Module          : Key                                                     */
/* !Description     : Provides interface for managing keys                    */
/*                                                                            */
/* !File            : Key.c                                                   */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Key.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:10   chunping.yan
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
#include "Key.h"
#include "DIO.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description Key stuck time.
    \Range       6000
    \Unit        10ms
*******************************************************************************/
#define u16KEY_STUCK_TIME            (uint16)6000
/******************************************************************************/
/*! \Description Key unstuck time.
    \Range       200
    \Unit        10ms
*******************************************************************************/
#define u16KEY_UNSTUCK_TIME          (uint16)200

/******************************************************************************/
/*! \Description Key push Normal time.
    \Range       10
    \Unit        10ms
*******************************************************************************/
#define u8KEY_PUSH_TIME_NORMAL       (uint8)5

/******************************************************************************/
/*! \Description Key Delay time.
    \Range       10
    \Unit        10ms
*******************************************************************************/
#define KEY_DELAY_TIME               (uint8)10

/******************************************************************************/
/*! \Description Key Release time.
    \Range       5
    \Unit        10ms
*******************************************************************************/
#define u8KEY_RELEASE_TIME_NORMAL    (uint8)5

/******************************************************************************/
/*! \Description NO Key Input  time.
    \Range       5
    \Unit        10ms
*******************************************************************************/
#define u8KEY_NO_INPUT_TIME          (uint8)10

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
/* DATA DEFINITION                                                            */
/******************************************************************************/
/******************************************************************************/
/*! \Description Used to track the key's pressed time .
*******************************************************************************/
static uint16                 Key_au16PressTime[Key_u8NUM_OF_KEYS];

/******************************************************************************/
/*! \Description Used to track the key's released time .
*******************************************************************************/
static uint16                 Key_au16ReleaseTime[Key_u8NUM_OF_KEYS];

/******************************************************************************/
/*! \Description Used to track the key status.
*******************************************************************************/
static Key_tenuStatus         Key_aenuStatus[Key_u8NUM_OF_KEYS];

/******************************************************************************/
/*! \Description Number of stuck keys.
*******************************************************************************/
static uint8                  Key_u8ErrorNo;


/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void vidKeyCheck_Normal(uint8 u8DioId,Key_tenuId enuKeyIdx);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
/******************************************************************************/
/*!Function: vidKeyCheck_Normal                                               */
/*! \Description Handles the Keys main state machine.
    \param[in]   u8DioId : Dio Index
    \param[in]   enuKeyIdx : Key Index
    \return      void.
    \Trace_To    CDD-Key-
*******************************************************************************/
static void vidKeyCheck_Normal(uint8 u8DioId,Key_tenuId enuKeyIdx)
{
    /*!  temp  variable for store I/O tate  */
    uint8 u8DinResult;
    static uint8 u8KeyDelayTime[Key_u8NUM_OF_KEYS] = {0u,0u};

    /*! Read the push button state */
    u8DinResult = Dio_u8Read(u8DioId);

    if (0u != u8KeyDelayTime[enuKeyIdx])
    {
        u8KeyDelayTime[enuKeyIdx]--;
    }
    else
    {
        /*! if current key state is relaesed */
        if (Key_aenuStatus[enuKeyIdx] == Key_RELEASED )
        {
            /*! if the sampling value is 1 ,meaning not press ,than keep state */ 
            if (1u == u8DinResult)
            {
                /*! clearing  press timer ,for low level diaturb accumulate error  */
                Key_au16PressTime[enuKeyIdx] = 0u;    
            }
            /*! if the sampling value is pressed from release ,than*/
            else
            {
                /*! press timer++ ,*/
                Key_au16PressTime[enuKeyIdx]++ ;
                if (Key_au16PressTime[enuKeyIdx] >= u8KEY_PUSH_TIME_NORMAL)
                {
                    /*! Set the key status to Key_PRESSED. */
                    Key_aenuStatus[enuKeyIdx] = Key_PRESSED;

                    u8KeyDelayTime[enuKeyIdx] = KEY_DELAY_TIME;
                }
            } 

        }

        else if (Key_aenuStatus[enuKeyIdx] == Key_PRESSED) 
        {
            /*! If key is released continuously*/
            if (u8DinResult == 1u)
            {
                /*!  release timer ++ for trace relaese moving */
                Key_au16ReleaseTime[enuKeyIdx]++ ;
                /*! if release sampling value get filter value ,than*/
                if (Key_au16ReleaseTime[enuKeyIdx] > u8KEY_RELEASE_TIME_NORMAL)
                {
                    /*! clear release timer for next release filter*/
                    Key_au16ReleaseTime[enuKeyIdx] = 0u ;
                    /*! clear press timer for next press filter */
                    Key_au16PressTime[enuKeyIdx] = 0u ;
                    /*! change key status*/
                    Key_aenuStatus[enuKeyIdx] = Key_RELEASED;

                    u8KeyDelayTime[enuKeyIdx] = KEY_DELAY_TIME;
                } 

            }
            else
            {
                /*! remove high level disturb during press process .*/
                Key_au16ReleaseTime[enuKeyIdx] = 0u;     
                /*! record the press time for stuck mode trace */
                Key_au16PressTime[enuKeyIdx]++ ;

                if (Key_au16PressTime[enuKeyIdx] > u16KEY_STUCK_TIME)
                {  
                    /*! set the key status to Key_STUCK. */
                    Key_aenuStatus[enuKeyIdx] = Key_STUCK;
                    /*! Increment the number of stuck keys. */
                    Key_u8ErrorNo++;
                    /*! the pressed trace function terminal ,so clear it*/
                    Key_au16PressTime[enuKeyIdx] = 0u ;
                }  

            }
        }

        /*! if is stuck */ 
        else 
        {
            /*! If key is released ,because the EXIT condition is release*/
            if (u8DinResult == 1u)
            {
                /*! tracing the Release time */
                Key_au16ReleaseTime[enuKeyIdx]++;
                if (Key_au16ReleaseTime[enuKeyIdx] > u16KEY_UNSTUCK_TIME)
                {
                    /*! recovered the key state */
                    Key_aenuStatus[enuKeyIdx] = Key_RELEASED;
                    /*! clear releasetime for next timer function */
                    Key_au16ReleaseTime[enuKeyIdx] = 0u;

                    if (Key_u8ErrorNo != 0u)
                    {
                        /*! Decrement the number of stuck keys. */
                        Key_u8ErrorNo--;
                    }
                }
            } 
            else
            {
                Key_au16ReleaseTime[enuKeyIdx] = 0u ;
            }   

        }  

    }       
}/* End of vidKeyCheck_Normal()*/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
 
 /******************************************************************************/
/*!Function : Key_vidInit                                                     */
/*! \Description Key Initialization function.\n
    \return      void.
    \Trace_To    CDD-Key- 
*******************************************************************************/
extern void Key_vidInit(void)
{
   uint8 u8Index;
   /*! For all keys intialize the Push time to zero
     and the application notif to FALSE */
  for (u8Index = 0u ; u8Index < Key_u8NUM_OF_KEYS ; u8Index++)
  {
    Key_au16PressTime[u8Index]  = 0u;
    Key_au16ReleaseTime[u8Index] = 0u ;
    Key_aenuStatus[u8Index] = Key_UNKNOWN;
  }

}/* End of Key_vidInit()*/


/******************************************************************************/
/*!Function : Key_u8GetNumOfStuckKeys                                         */
/*! \Description Returns the number of keys stuck. \n
    \Return      Number of keys stuck.
    \Range       0..10
    \Trace_To    CDD-Key-
*******************************************************************************/
extern uint8 Key_u8GetNumOfStuckKeys()
{
  /*! Return the number of stuck keys. */
  return Key_u8ErrorNo;
}/* End of Key_u8GetNumOfStuckKeys()*/

/******************************************************************************/
/*!Function : Key_vidManage                                                   */
/*! \Description Key Management function.\n
    \return      void.
    \Trace_To     CDD-Key-
*******************************************************************************/
extern void Key_vidManage(void)
{
    uint8 u8Index;
    for (u8Index = 0u ; u8Index < Key_u8NUM_OF_KEYS ; u8Index++)
    {
        vidKeyCheck_Normal(u8Index, (Key_tenuId)u8Index);
    }
}/* End of Key_vidManageNormalKeys() */




/******************************************************************************/
/*!Function : Key_enuGetKeyStatus                                             */
/*! \Description Returns the status of the key. \n
    \param[in]   enuId : Key Id
    \Return      Key Status.
    \Range       Key_PRESSED,Key_STUCK,Key_RELEASED
    \Trace_To    CDD-Key- 
*******************************************************************************/
extern Key_tenuStatus Key_enuGetKeyStatus(Key_tenuId enuId)
{
  Key_tenuStatus enuKeyStatus;
  /*! Set the returned key status to the current key status. */
  enuKeyStatus = Key_aenuStatus[enuId];
  /*! Return the  returned key status variable. */
  return enuKeyStatus;
}/* End of Key_enuGetKeyStatus()*/




/** \} */ /* end of Key module group */
/** \} */ /* end of ECUAL Key Component */

/*-------------------------------- end of file -------------------------------*/

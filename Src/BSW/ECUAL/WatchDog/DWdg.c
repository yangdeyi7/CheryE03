#include "s32k144_DIO.h"
#include "DWdg.h"

/*==============================================================================
*                          LOCAL MACROS, DEFINES
==============================================================================*/

#define u8FIRST_BIT_MASK                                             ((uint8)1)

/*==============================================================================
*                LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/

/*==============================================================================
*                              GLOBAL FUNCTIONS
==============================================================================*/

/*============================================================================*/


/******************************************************************************/
/* !Function    : DWdg_vidInit                                                */
/* !Description : Initialization routine for Watch Dog                        */
/* !Trace_To    : HVAC_SCD_ECUAL_0014#01                                      */
/******************************************************************************/
extern void DWdg_vidInit( void )
{
  /*!Pseudo: Set the pin low                                                   */
  DIO_vidWrite (DIO_u8WDG, (uint8)0);
  /*!Pseudo: Refresh Watchdog during modules initialization                   */
  DWdg_vidWdgRefresh();
}

/******************************************************************************/
/* !Function    : DWdg_vidWdgRefresh                                          */
/* !Description : Refresh physically the watchdog signal                      */
/* !Trace_To    : HVAC_SCD_ECUAL_0016#01                                      */
/******************************************************************************/
extern void DWdg_vidWdgRefresh( void )
{
  SEGGER_RTT_printf(0, "DWdg_vidWdgRefresh\r\n");
  /*!Pseudo: Watchdog pulse _|_  ~10 ms                                       */
  static uint8 LOC_u8OutValue= (uint8)0;
  /*!Pseudo: Toggle the pin value                                             */
  LOC_u8OutValue ^= u8FIRST_BIT_MASK;
  /*!Pseudo: Set watch dog pin                                                */
  DIO_vidWrite (DIO_u8WDG, LOC_u8OutValue);
}


/******************************************************************************/
/* !Function    : DWdg_vidWdgReset                                            */
/* !Description : stuck the CPU till the Watchdog reset                       */
/* !Trace_To    : HVAC_SCD_ECUAL_0018#01                                      */
/******************************************************************************/
extern void DWdg_vidWdgReset( void )
{
    /*!Pseudo: Log in EEPROM if needed*/

    /*!Pseudo: Stuck the CPU till Reset*/
    for(;;)
    {
        /*
        This open loop is implemented here to stuck the PC here to enforce the
        WatchDog chip to reset the MC
        */
    }
}

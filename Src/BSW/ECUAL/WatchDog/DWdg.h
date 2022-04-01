#ifndef DWdg_H
#define DWdg_H


/*! \Trace_To  :
* HVAC_SCD_ECUAL_0001#02
 */
#include "std_Types.h"

/*!Comment: Initialization routine for Watch Dog chip                         */
/*! \Trace_To  :HVAC_SCD_ECUAL_0013#01                                        */
extern void DWdg_vidInit( void );

/*!Comment: Refresh physically the watchdog signal                            */
/*! \Trace_To  :HVAC_SCD_ECUAL_0015#01                                        */
extern void DWdg_vidWdgRefresh( void );

/*!Comment: stuck the CPU till the Watchdog reset                             */
/*! \Trace_To  :HVAC_SCD_ECUAL_0017#01                                        */
extern void DWdg_vidWdgReset( void );

#endif


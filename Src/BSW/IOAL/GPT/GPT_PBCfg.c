/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

#include <stddef.h>
#include "Compiler.h"
#include "Std_Types.h"
#include "GPT_Types.h"
#include "GPT_PBCfg.h"


/******************************************************************************/
/* CONSTANTS, MACROS                                                          */
/******************************************************************************/

/*! \Trace_To: HVAC_SCD_IOAL_0119#01                                         */
CONST(GPT_tstrConfigType, GPT_CONST) GPT_kstreConfigSet=
{
    (uint8)0x01,         /* Number of channel              */
    GPT_MODE_NORMAL,     /* Channel mode                   */
    (GPT_udtPrescaleType)2, /* Prescaler value                */
    NULL,               /* Freeze enable                  */
    TRUE,                /* WakeUp enable                  */
    NULL                /* To Enable/Disable Notification */
};

/*
    A pointer to Callback function must be equalized to the needed Callback 
    function here
*/

/** GPT_pfOSCallback=  Put the callback need to be called */


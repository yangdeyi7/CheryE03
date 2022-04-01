#ifndef GPT_PBCFG_H
#define GPT_PBCFG_H

#include "GPT_Types.h"
/*
    This is the type of the data structure including the configuration set
    required for initializing the GPT timer unit.

*/

typedef struct
{
    /* Number of GPT channels                                                 */
    VAR(uint8, GPT_VAR)                   u8ChannelNumber;
    /* Channel mode                                                           */
    VAR(GPT_tenuModeType, AUTOMATIC)          enuChannelMode;
    /* Prescaler value                                                          */
    VAR(GPT_udtPrescaleType, AUTOMATIC)      u32ChannelPrescale;
    /* Freeze enable                                                            */
    VAR(boolean, static)                  bFreezeEnable;
    /* WakeUp enable                                                           */
    VAR(boolean, static)                  bEnableWakeup;
    /* To Enable/Disable Notification                                         */
    VAR(boolean, static)                  bDisableNotification;


} GPT_tstrConfigType;


/*
    A pointer to Callback function must be declared here
*/
extern P2FUNC(void, AUTOMATIC, GPT_pfvideOSCallback)(void);



/*
    Extern of the configuration structure pointer

*/

extern CONST(GPT_tstrConfigType, GPT_CONST) GPT_kstreConfigSet;

#endif


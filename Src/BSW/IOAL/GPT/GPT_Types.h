#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#include "Std_Types.h"
#include "platform_Types.h"
/*
    Operation for reduced power operation mode. In sleep mode
    only wakeup capable channels are available.
*/

/*! \Trace_To: HVAC_SCD_IOAL_0075#01                                         */
typedef enum{

    GPT_MODE_NORMAL=1,
    GPT_MODE_SLEEP

}GPT_tenuModeType;


/*
    Specifies the behavior of the timer channel after the target time is 
    reached.

    GPT_CH_MODE_CONTINUOUS: After reaching the target time, the timer continues
                            running with the value "zero" again.
    GPT_CH_MODE_ONESHOT   : After reaching the target time, the timer stops
                            automatically (timer expired).
*/

/*! \Trace_To: HVAC_SCD_IOAL_0098#01                                         */
typedef enum{

    GPT_CH_MODE_ONESHOT=0,
    GPT_CH_MODE_CONTINUOUS


}GPT_tenuChannelModeType;


/*
     This type implementation based on a specific micro controller
     platform Used channels, Here we are using only one channel
     which is TIMER M -> Channel0.
     For declaring more timer Channels you have to add more channels
     before "MaxNumberof Channels".
     GPT_MAX_NUM_OF_CHANNELS: indicates the end of the enum

*/

/*! \Trace_To: HVAC_SCD_IOAL_0077#01                                         */
typedef enum{

    GPT_TIMER_M_0 = 0x01,
    GPT_MAX_NUM_OF_CHANNELS

}GPT_tenuChannelType;


/*
    The range of this type is MC dependent (width of the timer
    register) and has to be described by the supplier.

    Type for reading and setting the timer values (in number of ticks).
*/

typedef  uint16   GPT_udtValueType ;



/*
    Gpt prescale type. It specifies the GPT module specific prescaler 
    factor per channel.
*/
typedef VAR(uint32,GPT_VAR) GPT_udtPrescaleType;




#endif


#ifndef S32k144_GPT_H
#define S32k144_GPT_H

#include "GPT_Types.h"
#include "GPT_PBCfg.h"
#include "cpu.h"

/*! \Trace_To:    HVAC_SCD_IOAL_0032#01                                        */
extern FUNC (void,AUTOMATIC) GPT_vidInit(void);


/*! \Trace_To:    HVAC_SCD_IOAL_0033#01                                        */
extern FUNC (void,AUTOMATIC) GPT_vidStartSchedTimer(void);

/*******************************************************************************
*
*   This function is responsible to stop the timer of scheduler.
*
*******************************************************************************/
extern FUNC (void,PUBLIC) GPT_vidDeInit(void);

#endif

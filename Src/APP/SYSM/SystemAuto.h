#ifndef SYSTEMAUTO_H
#define SYSTEMAUTO_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define AUTO_STATE_INIT               0u
#define AUTO_DISPLAY_STATE_INIT       0u
#define AUTO_STATE_ON                 1u
#define AUTO_STATE_OFF                0u
#define AUTO_KEY_PRESSD               1u
#define AUTO_KEY_NOPRESS              0u
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/*************************************TYPES ***********************************/

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/

extern void System_vidAutoInit(void);
extern void System_vidAutoDefault(void);
extern void System_vidAutoRegulation(void);

#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/
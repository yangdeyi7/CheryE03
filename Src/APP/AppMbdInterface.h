#ifndef APPMBDINTERFACE_H
#define APPMBDINTERFACE_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define MAX(x,y) (uint8)(((x)>(y))?(x):(y))
#define MIN(x,y) (uint8)(((x)<(y))?(x):(y))
#define RLY_ON (uint8)0
#define RLY_OFF (uint8)1
#define MBD_INPUT_DEFAULT_NUM0    ((uint8)0)
#define MBD_INPUT_DEFAULT_NUM1    ((uint8)1)
#define MBD_INPUT_DEFAULT_NUM2    ((uint8)2)
#define MBD_INPUT_DEFAULT_NUM3    ((uint8)3)
#define MBD_INPUT_DEFAULT_NUM4    ((uint8)4)
#define MBD_INPUT_DEFAULT_NUM5    ((uint8)5)
#define MBD_INPUT_DEFAULT_NUM6    ((uint8)6)
#define MBD_INPUT_DEFAULT_NUM7    ((uint8)7)
#define MBD_INPUT_DEFAULT_NUM10   ((uint8)10)
#define MBD_INPUT_DEFAULT_NUM100  ((uint8)100)
#define MBD_INPUT_DEFAULT_NUM240  ((uint16)240)
#define MBD_INPUT_DEFAULT_NUM8000 ((uint16)8000)
#define HP_SYSTEM_AUTO_CTRL           ((uint8)0)
#define HP_SYSTEM_MANUAL_CTRL         ((uint8)1)
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* LOCAL DATA DEFINITION                                                      */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL DATA DECLARATION                                                    */
/******************************************************************************/
extern void AppMbdInterface_vidInit(void);
extern void AppMbdInterface_vidManage(void);

#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/


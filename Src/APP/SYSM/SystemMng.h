
#ifndef SYSTEMMNG_H
#define SYSTEMMNG_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Platform_Types.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define SYSTEM_STATE_INIT               0u
#define SYSTEM_DISPLAY_STATE_INIT       0u
#define SYSTEM_STATE_ON                 1u
#define SYSTEM_STATE_OFF                0u
#define SYSTEM_KEY_PRESSD               1u
#define SYSTEM_KEY_NOPRESS              0u
#define SYSTEM_DEFAULT_TIMER            10u
#define  MAX(x,y) (((x)>(y)) ? (x) : (y))
#define  MIN(x,y) (((x) < (y)) ? (x) : (y))
#define OPPOSITE(x) (x = ~x)

typedef enum
{
	SYSTEM_FIRST_CLOSE,
	SYSTEM_FIRST_OPEN,
  SYSTEM_NOTFIRST_OPEN
} SYSTEM_tenuFirstOpen_Judge;
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/*  TYPES                                                                     */
/******************************************************************************/
//typedef unsigned char         boolean;       /*        TRUE .. FALSE        */
//typedef signed char           sint8;         /*        -128 .. +127         */
//typedef unsigned char         uint8;         /*           0 .. 255          */
//typedef signed short          sint16;        /*      -32768 .. +32767       */
//typedef unsigned short        uint16;        /*           0 .. 65535        */
//typedef signed long           sint32;        /* -2147483648 .. +2147483647  */
//typedef unsigned long         uint32;        /*           0 .. 4294967295   */
typedef	struct
{
  boolean bWorkPress;
  boolean bAutoPress;
  boolean bAcPress;
  boolean bBlwPress;
  boolean bIntakePress;
  boolean bModePress;
  boolean bTsetLPress;
  boolean bTsetRPress;
} SYSTEM_tstrReceive_Press;

typedef union
{
  SYSTEM_tstrReceive_Press  strChangeJudge;
  uint8                     u8DataAll[sizeof(SYSTEM_tstrReceive_Press)];
}SYSTEM_tuniReceive_Press_ECP;
extern SYSTEM_tuniReceive_Press_ECP  SYSTEM_uniReceive_Press_ECP;

typedef	struct
{
  uint8 u8WorkSts;
  uint8 u8AutoSts;
  uint8 u8AcSts;
  uint8 u8BlwSts;
  uint8 u8IntakeSts;
  uint8 u8ModeSts;
  uint8 u8TsetLSts;
  uint8 u8TsetRSts;
  uint8 u8SyncSts;
} SYSTEM_tstrApp_Data;
extern SYSTEM_tstrApp_Data  SYSTEM_strApp_Data;

/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/

extern void System_vidMngInit(void);
extern void System_vidMngRegulation(void);
extern void System_vidMngDefault(void);
#endif  /* XXX_H */ 

/*-------------------------------- end of file -------------------------------*/
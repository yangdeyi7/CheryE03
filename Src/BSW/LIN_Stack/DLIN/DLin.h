/*****************************************************************************/
/* PROTECTION AGAINST MULTIPLE INCLUSION                                     */
/*****************************************************************************/
#ifndef DLIN_H
#define DLIN_H


#define  LIN_CM_Start_Init       0x01
#define  LIN_CM_Wait_Init        0x02
#define  LIN_CM_NO_Init          0x00
#define  LIN_CM_EN_MOVE          0x01

#define  LIN_STATUS_Initialized  0x02
#define  LIN_u8SLOT_COUNT        2

typedef enum
{
    LIN_ST_UNINITIAL = 0,
    LIN_ST_INITIALIZING,
    LIN_ST_NORMAL,
    LIN_ST_FAILURE,
} LIN_tenuState;


extern void LIN_vidInit(void);
extern void vidFTM1Isr(void);
void LIN_vidDeInit(void);

#endif



#ifndef S32K144_PWM_H_
#define S32K144_PWM_H_

#include "Std_types.h"

#define PWM_u8BLW                  ((uint8)0)
#define PWM_u8OUT1                 ((uint8)1)
#define PWM_u8OUT2                 ((uint8)2)
#define PWM_u8NUM                  ((uint8)3)


extern void PWM_vidInit(void);
extern void PWM_vidWriteDutyCycleFine(uint8 u8Id ,uint16 u16DutyCycleFine);
#endif /* LPUART_H_ */



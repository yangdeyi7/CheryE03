#ifndef CAN_H
#define CAN_H

#include "device_registers.h"
#include "Std_Types.h"
#include "Can_Type.h"

/*define TX BUF ID*/
#define TX_BUF0_ID    0u
#define TX_BUF1_ID    1u
#define TX_BUF2_ID    2u
#define TX_BUF3_ID    3u
#define TX_BUF4_ID    4u
#define TX_BUF5_ID    5u
#define TX_BUF6_ID    6u
#define TX_BUF7_ID    7u
#define TX_BUF8_ID    8u
#define TX_BUF9_ID    9u
#define TX_BUF_NUM    (TX_BUF9_ID - TX_BUF0_ID + 1)

/*define RX BUF ID*/
#define RX_BUF10_ID   10u
#define RX_BUF11_ID   11u
#define RX_BUF12_ID   12u
#define RX_BUF13_ID   13u
#define RX_BUF14_ID   14u
#define RX_BUF15_ID   15u
#define RX_BUF16_ID   16u
#define RX_BUF17_ID   17u
#define RX_BUF18_ID   18u
#define RX_BUF19_ID   19u
#define RX_BUF20_ID   20u
#define RX_BUF21_ID   21u
#define RX_BUF22_ID   22u
#define RX_BUF23_ID   23u
#define RX_BUF24_ID   24u
#define RX_BUF25_ID   25u
#define RX_BUF26_ID   26u
#define RX_BUF27_ID   27u
#define RX_BUF28_ID   28u
#define RX_BUF29_ID   29u
#define RX_BUF30_ID   30u
#define RX_BUF31_ID   31u
#define RX_BUF_NUM    (RX_BUF31_ID - RX_BUF10_ID + 1)


typedef struct
{
   uint32  u32Id;           /* complete ID                                       */
   uint32  u32TimeStame;
   uint8   u8DLC;           /* Data length reg.:  X X X X DLC3 DLC2 DLC1 DLC0    */
   uint8   au8Data[8];      /* Data 0 .. 7                                       */
} Can_tstrFrame;


extern void   Can_vidInit(void);
extern uint32 Can_u32TrasnimitMsg(uint32 u32MsgBufId, Can_tstrFrame *pstrFrame);
extern void   Can_vidSendMsgManage(void);
extern uint32 Can_u32ReceiveMsg(Can_tstrFrame *pstrFrame);
extern uint8  Can_u8GetBusStatus(void);

#endif


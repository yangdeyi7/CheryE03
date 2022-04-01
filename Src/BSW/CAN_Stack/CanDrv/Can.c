#include "device_registers.h"  /* include peripheral declarations S32K144 */
#include "Std_Types.h"
#include "Can.h"
#include "Can_Hdl.h"
#include "Can_Type.h"


static uint8   u8BusoffFlag;

#define MSG_BUF_SIZE  4    /* Msg Buffer Size. (CAN 2.0AB: 2 hdr +  2 data= 4 words) */

uint32  u32Byte2Dword(uint8* pu8Data, uint8 u8Length);

uint32  u32Byte2Dword(uint8* pu8Data, uint8 u8Length)
{
    uint32_t u32Temp = 0;
    uint8_t u8Len = u8Length;
    uint8_t u8Ind;
    if (4 < u8Len)
    {
        u8Len = 4;
    }
    for (u8Ind = 0; u8Ind < u8Len; u8Ind++)
    {
        u32Temp <<= 8;
        u32Temp += pu8Data[u8Ind];
    }
    return u32Temp;
}


void Can_vidInit(void)
{
	uint8  u8Index = 0u;
	/*CanPort Config*/
	PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK;
	PORTE->PCR[4] |= PORT_PCR_MUX(5); /*Port E4: MUX = ALT5, CAN0_RX*/
	PORTE->PCR[5] |= PORT_PCR_MUX(5); /*Port E5: MUX = ALT5, CAN0_TX*/
    /*Can Register Config*/
	PCC->PCCn[PCC_FlexCAN0_INDEX] |= PCC_PCCn_CGC_MASK; /* CGC=1: enable clock to FlexCAN0 */
	CAN0->MCR |= CAN_MCR_MDIS_MASK;         /* MDIS=1: Disable module before selecting clock */
	CAN0->CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK;  /* CLKSRC=0: Clock Source = oscillator (8 MHz) */
	CAN0->MCR &= ~CAN_MCR_MDIS_MASK;        /* MDIS=0; Enable module config. (Sets FRZ, HALT)*/
	while (!((CAN0->MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT))
	{
        ;
	}
	CAN0->CTRL1 = 0x00DB0006;   /* Configure for 500 KHz bit time */
	                            /* Time quanta freq = 16 time quanta x 500 KHz bit time= 8MHz */
	                            /* PRESDIV+1 = Fclksrc/Ftq = 8 MHz/8 MHz = 1 */
	                            /* so PRESDIV = 0 */
	                            /* PSEG2 = Phase_Seg2 - 1 = 4 - 1 = 3 */
	                            /* PSEG1 = PSEG2 = 3 */
	                            /* PROPSEG= Prop_Seg - 1 = 7 - 1 = 6 */
	                            /* RJW: since Phase_Seg2 >=4, RJW+1=4 so RJW=3. */
	                            /* SMP = 1: use 3 bits per CAN sample */
	                            /* CLKSRC=3 (unchanged): Fcanclk= Fosc = 8MHz */
	for(u8Index = 0u; u8Index < 128u; u8Index++)
	{
		/* CAN0: clear 32 msg bufs x 4 words/msg buf = 128 words*/
	    CAN0->RAMn[u8Index] = 0;      /* Clear msg buf word */
	}
	for(u8Index = 0u; u8Index < 16u; u8Index++)
	{
		  /* In FRZ mode, init CAN0 16 msg buf filters */
	    CAN0->RXIMR[u8Index] = 0xFFFFFFFF;  /* Check all ID bits for incoming messages */
	}
	CAN0->RXMGMASK = 0x1FFFFFFF;  /* Global acceptance mask: check all ID bits */
	CAN0->RAMn[ RX_BUF10_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	                                                /* Msg Buf 10, word 0: Enable for reception */
	                                                /* EDL,BRS,ESI=0: CANFD not used */
	                                                /* CODE=4: MB set to RX inactive */
	                                                /* IDE=0: Standard ID */
	                                                /* SRR, RTR, TIME STAMP = 0: not applicable */
	CAN0->RAMn[ RX_BUF11_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF12_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF13_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF14_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF15_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF16_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF17_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF18_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF19_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF20_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF21_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF22_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF23_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF24_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF25_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF26_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF27_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF28_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF29_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF30_ID * MSG_BUF_SIZE + 0] = 0x04000000;
	CAN0->RAMn[ RX_BUF31_ID * MSG_BUF_SIZE + 0] = 0x04000000;


	CAN0->RAMn[ RX_BUF10_ID * MSG_BUF_SIZE + 1] = (0X502u << 18u); 
	CAN0->RAMn[ RX_BUF11_ID * MSG_BUF_SIZE + 1] = (0X16Bu << 18u); 
	CAN0->RAMn[ RX_BUF12_ID * MSG_BUF_SIZE + 1] = (0X4F1u << 18u); 
	CAN0->RAMn[ RX_BUF13_ID * MSG_BUF_SIZE + 1] = (0X4F3u << 18u); 
	CAN0->RAMn[ RX_BUF14_ID * MSG_BUF_SIZE + 1] = (0x427u << 18u); 
	CAN0->RAMn[ RX_BUF15_ID * MSG_BUF_SIZE + 1] = (0x208u << 18u); 
	CAN0->RAMn[ RX_BUF16_ID * MSG_BUF_SIZE + 1] = (0X41Fu << 18u); 
	CAN0->RAMn[ RX_BUF17_ID * MSG_BUF_SIZE + 1] = (0x41Bu << 18u); 
	CAN0->RAMn[ RX_BUF18_ID * MSG_BUF_SIZE + 1] = (0x426u << 18u); 
	CAN0->RAMn[ RX_BUF19_ID * MSG_BUF_SIZE + 1] = (0x418u << 18u); 
	CAN0->RAMn[ RX_BUF20_ID * MSG_BUF_SIZE + 1] = (0X42Bu << 18u); 
	CAN0->RAMn[ RX_BUF21_ID * MSG_BUF_SIZE + 1] = (0x43Cu << 18u); 
	CAN0->RAMn[ RX_BUF22_ID * MSG_BUF_SIZE + 1] = (0x519u << 18u); 
	CAN0->RAMn[ RX_BUF23_ID * MSG_BUF_SIZE + 1] = (0x45Bu << 18u); 
	CAN0->RAMn[ RX_BUF24_ID * MSG_BUF_SIZE + 1] = (0x48Bu << 18u); 
	CAN0->RAMn[ RX_BUF25_ID * MSG_BUF_SIZE + 1] = (0x3FEu << 18u); 
	CAN0->RAMn[ RX_BUF26_ID * MSG_BUF_SIZE + 1] = (0x7A3u << 18u); 
	CAN0->RAMn[ RX_BUF27_ID * MSG_BUF_SIZE + 1] = (0x7DFu << 18u); 
	CAN0->RAMn[ RX_BUF28_ID * MSG_BUF_SIZE + 1] = (0x315u << 18u); 
	CAN0->RAMn[ RX_BUF29_ID * MSG_BUF_SIZE + 1] = (0x31Eu << 18u); 
	CAN0->RAMn[ RX_BUF30_ID * MSG_BUF_SIZE + 1] = (0x114u << 18u); 
	CAN0->RAMn[ RX_BUF31_ID * MSG_BUF_SIZE + 1] = (0x115u << 18u); 

    CAN0->MCR = 0x0000001F;       /* Negate FlexCAN 1 halt state for 32 MBs */
    /* Open FIFO receives interrupt */
    CAN0->IMASK1 |= (1<<RX_BUF10_ID) |
    		        (1<<RX_BUF11_ID) |
					(1<<RX_BUF12_ID) |
					(1<<RX_BUF13_ID) |
					(1<<RX_BUF14_ID) |
					(1<<RX_BUF15_ID) |
					(1<<RX_BUF16_ID) |
					(1<<RX_BUF17_ID) |
					(1<<RX_BUF18_ID) |
					(1<<RX_BUF19_ID) |
					(1<<RX_BUF20_ID) |
					(1<<RX_BUF21_ID) |
					(1<<RX_BUF22_ID) |
					(1<<RX_BUF23_ID) |
					(1<<RX_BUF24_ID) |
					(1<<RX_BUF25_ID) |
					(1<<RX_BUF26_ID) |
					(1<<RX_BUF27_ID) |
					(1<<RX_BUF28_ID) |
					(1<<RX_BUF29_ID) |
					(1<<RX_BUF30_ID) |
    		        (1<<RX_BUF31_ID);
    CAN0->CTRL2 |= (1<<30U);/*enable bus off interrupt*/

    while ((CAN0->MCR && CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT)
    {
    	/* Good practice: wait for FRZACK to clear (not in freeze mode) */
    	;
    }

    while ((CAN0->MCR && CAN_MCR_NOTRDY_MASK) >> CAN_MCR_NOTRDY_SHIFT)
    {
    	/* Good practice: wait for NOTRDY to clear (module ready)  */
    	;
    }

	S32_NVIC->ICPR[1] = 1 << (81 % 32);  /* IRQ81-CHA0 0-15: clr any pending IRQ*/
	S32_NVIC->ISER[81 >> 5U] = (uint32)(1UL << ((uint32)(81) & (uint32)0x1FU));
	S32_NVIC->IP[81] = 0xb;   /* IRQ81-CAN0 0-15: priority 10 of 0-15*/

	S32_NVIC->ICPR[1] = 1 << (78 % 32);
	S32_NVIC->ISER[78 >> 5U] = (uint32)(1UL << ((uint32)(78) & (uint32)0x1FU));
	S32_NVIC->IP[78] = 0xc;

	u8BusoffFlag = FALSE;

}


#define CODE_SHIFT      (24u)
#define CODE_WIDTH      (4u)
#define CODE_INACTIVE   (0x0u)
#define CODE_TX_FULL    (0xCu)
uint32 Can_u32TrasnimitMsg(uint32 u32MsgBufId, Can_tstrFrame *pstrFrame)
{
	uint32 u32Result = 0u;
	uint32 u32Code =  (CAN0->RAMn[u32MsgBufId * MSG_BUF_SIZE + 0] >> CODE_SHIFT) & ((1 << CODE_WIDTH) - 1u);
	if ((CODE_INACTIVE ==  (u32Code & 0x7u)) || ((CAN0->IFLAG1) & (1 << u32MsgBufId)))
	{
		 /* Clear CAN 0 MB 0 flag without clearing others*/
	    CAN0->IFLAG1 = 0x1 << u32MsgBufId;
	    /* MB0 word 2: data word 0 */
	    CAN0->RAMn[u32MsgBufId*MSG_BUF_SIZE + 2] = u32Byte2Dword(&(pstrFrame->au8Data[0]), 4);
	    /* MB0 word 3: data word 1 */
	    CAN0->RAMn[u32MsgBufId*MSG_BUF_SIZE + 3] = u32Byte2Dword(&(pstrFrame->au8Data[4]), 4);
	    /* MB word 1: Tx msg with STD ID */
	    CAN0->RAMn[u32MsgBufId*MSG_BUF_SIZE + 1] = ((pstrFrame->u32Id) << 18u);
        /* MB0 word 0: *//* EDL,BRS,ESI=0: CANFD not used */
        /* CODE=0xC: Activate msg buf to transmit *//* IDE=0: Standard ID */
        /* SRR=1 Tx frame (not req'd for std ID) */
	    /* RTR = 0: data, not remote tx request frame*//* DLC = 8 bytes */
	    CAN0->RAMn[u32MsgBufId*MSG_BUF_SIZE + 0] = 0x0C400000 | (pstrFrame->u8DLC) << CAN_WMBn_CS_DLC_SHIFT;
	 }
	 else
	 {
	    u32Result = 1;
	 }
	return u32Result;
}



/*! this function only for can send msg test*/
void Can_vidSendMsgManage(void)
{
	uint8  u8Index;
	uint8  u8Index1;
	//static uint8 LOC_u8Cnt = 0u;
    static uint8 LOC_u8Cnt1 = 0u;
	Can_tstrFrame astrFrame[TX_BUF_NUM];
	for(u8Index = 0u; u8Index < TX_BUF_NUM; u8Index++)
    {
		astrFrame[u8Index].u32Id= 0x200u + u8Index;
		astrFrame[u8Index].u8DLC= 8u;
    }
	/*
    if(LOC_u8Cnt < 10u)//100ms cycle
    {
 	   LOC_u8Cnt++;
    }
    else
    {
	    LOC_u8Cnt = 0u;
	*/
	    LOC_u8Cnt1++;
		for(u8Index = 1u; u8Index < TX_BUF_NUM; u8Index++)
        {
			for(u8Index1 = 0u; u8Index1 < 8u; u8Index1++)
			{
				astrFrame[u8Index].au8Data[u8Index1] = LOC_u8Cnt1;
			}

        }
		if(LOC_u8Cnt1 == 255)
		{
			LOC_u8Cnt1 = 0u;
		}
		for(u8Index = 1u; u8Index < TX_BUF_NUM; u8Index++)
		{
			Can_u32TrasnimitMsg(TX_BUF0_ID + u8Index, &astrFrame[u8Index]);
		}
	/*
    }
    */
}

uint32 Can_u32ReceiveMsg(Can_tstrFrame *pstrFrame)
{
	/* Receive msg from ID 0x556 using msg buffer 4 */
  uint8  u8Index;
  uint32 u32Temp;
  uint32 u32MsgBufId;
  uint32 u32Ret = 0;

  u32Temp = CAN0->IFLAG1;

  if ((u32Temp >> RX_BUF10_ID) & 1)
  {
	  u32MsgBufId = RX_BUF10_ID;
  }
  else if ((u32Temp >> RX_BUF11_ID) & 1)
  {
	  u32MsgBufId = RX_BUF11_ID;
  }
  else if ((u32Temp >> RX_BUF12_ID) & 1)
  {
	  u32MsgBufId = RX_BUF12_ID;
  }
  else if ((u32Temp >> RX_BUF13_ID) & 1)
  {
	  u32MsgBufId = RX_BUF13_ID;
  }
  else if ((u32Temp >> RX_BUF14_ID) & 1)
  {
	  u32MsgBufId = RX_BUF14_ID;
  }
  else if ((u32Temp >> RX_BUF15_ID) & 1)
  {
	  u32MsgBufId = RX_BUF15_ID;
  }
  else if ((u32Temp >> RX_BUF16_ID) & 1)
  {
	  u32MsgBufId = RX_BUF16_ID;
  }
   else if ((u32Temp >> RX_BUF17_ID) & 1)
  {
	  u32MsgBufId = RX_BUF17_ID;
  }
  else if ((u32Temp >> RX_BUF18_ID) & 1)
  {
	  u32MsgBufId = RX_BUF18_ID;
  }
   else if ((u32Temp >> RX_BUF19_ID) & 1)
  {
	  u32MsgBufId = RX_BUF19_ID;
  }
  else if ((u32Temp >> RX_BUF20_ID) & 1)
  {
	  u32MsgBufId = RX_BUF20_ID;
  }
   else if ((u32Temp >> RX_BUF21_ID) & 1)
  {
	  u32MsgBufId = RX_BUF21_ID;
  }
  else if ((u32Temp >> RX_BUF22_ID) & 1)
  {
	  u32MsgBufId = RX_BUF22_ID;
  }
  else if ((u32Temp >> RX_BUF23_ID) & 1)
  {
	  u32MsgBufId = RX_BUF23_ID;
  }
  else if ((u32Temp >> RX_BUF24_ID) & 1)
  {
	  u32MsgBufId = RX_BUF24_ID;
  }
  else if ((u32Temp >> RX_BUF25_ID) & 1)
  {
	  u32MsgBufId = RX_BUF25_ID;
  }
  else if ((u32Temp >> RX_BUF26_ID) & 1)
  {
	  u32MsgBufId = RX_BUF26_ID;
  }
  else if ((u32Temp >> RX_BUF27_ID) & 1)
  {
	  u32MsgBufId = RX_BUF27_ID;
  }
  else if ((u32Temp >> RX_BUF28_ID) & 1)
  {
	  u32MsgBufId = RX_BUF28_ID;
  }
  else if ((u32Temp >> RX_BUF29_ID) & 1)
  {
	  u32MsgBufId = RX_BUF29_ID;
  }
  else
  {
      u32Ret = 1;
  }
  if (0 == u32Ret)
  {
    pstrFrame->u32Id = (CAN0->RAMn[u32MsgBufId * MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT ;
    pstrFrame->u8DLC = (CAN0->RAMn[u32MsgBufId * MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;
    for (u8Index=0; u8Index<2; u8Index++)
    {
		  /* Read two words of data (8 bytes) */
		  u32Temp = CAN0->RAMn[u32MsgBufId * MSG_BUF_SIZE + 2 + u8Index];
		  pstrFrame->au8Data[(u8Index << 2) + 0] = (u32Temp >> 24) & 0xFFu;
		  pstrFrame->au8Data[(u8Index << 2) + 1] = (u32Temp >> 16) & 0xFFu;
		  pstrFrame->au8Data[(u8Index << 2) + 2] = (u32Temp >>  8) & 0xFFu;
		  pstrFrame->au8Data[(u8Index << 2) + 3] = (u32Temp >>  0) & 0xFFu;
    }
    pstrFrame->u32TimeStame = (CAN0->RAMn[0 * MSG_BUF_SIZE + 0] & 0x000FFFF);
    u32Temp = CAN0->TIMER;             /* Read TIMER to unlock message buffers */
    
    //SEGGER_RTT_printf(0, "vidCanComRxIndication:id=0x%04x\r\n");
    Can_tstrPduType can_rx_Pdu;   
    can_rx_Pdu.u32CanId=pstrFrame->u32Id;
    can_rx_Pdu.u8Dlc=pstrFrame->u8DLC;
    can_rx_Pdu.pu8Data=pstrFrame->au8Data;
    Can_vidRxHandler(can_rx_Pdu);
  }
  
  CAN0->IFLAG1 = (0x1 << u32MsgBufId); /* Clear CAN 0 MB flag without clearing others*/
  
  return u32Ret;
}

/*! this function only for can send msg test*/
#if 1
void Can_vidSendMsg_test(void)
{
	uint8  u8Index1;
    static uint8 LOC_u8Cnt = 0u;
    Can_tstrFrame astrPdu;

    astrPdu.u32Id = ((0x5a2));
    astrPdu.u8DLC= 8u;
    //astrPdu.pu8Data= Can_au8TxDefaultValue;
    LOC_u8Cnt++;
    for(u8Index1 = 0u; u8Index1 < 8u; u8Index1++)
    {
          astrPdu.au8Data[u8Index1] = LOC_u8Cnt; 
    }
    if(LOC_u8Cnt == 255)
    {
       LOC_u8Cnt = 0u;
    }
    Can_u32TrasnimitMsg(TX_BUF0_ID, &astrPdu);
}
#endif

void CAN0_ORed_0_15_MB_IRQHandler(void)
{
	Can_tstrFrame strFrame;
	boolean bRtn;

	bRtn = Can_u32ReceiveMsg(&strFrame);
	if(TRUE == bRtn)
	{
		/*! save related frame data*/
	}
}

void CAN0_ORed_16_31_MB_IRQHandler(void)
{
	Can_tstrFrame strFrame;
	boolean bRtn;

	bRtn = Can_u32ReceiveMsg(&strFrame);
	if(TRUE == bRtn)
	{
		/*! save related frame data*/
	}
}


uint8 Can_u8GetBusStatus(void)
{
    return u8BusoffFlag;
}


void CAN0_ORed_IRQHandler(void)
{
	CAN0->ESR1 |= (1<<19U);/*clear busoff interrupt flag*/
	u8BusoffFlag = TRUE;
}






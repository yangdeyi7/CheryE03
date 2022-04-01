/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Device.h"
#include "Std_Types.h"
#include "Uart.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description CR char (means '\r\n').
 *  \Range  0x0D 
 ******************************************************************************/
#define u8CARRIAGE_CHAR (uint8)0x0D

/******************************************************************************/
/*! \Description Line feed(means '\n').
 *  \Range  0x0A 
 ******************************************************************************/
#define u8LINE_FEED_CHAR (uint8)0x0A

/******************************************************************************/
/*! \Description RX buffer length.
 *  \Range  20
 ******************************************************************************/
#define u8RX_BUFFER_LEN (uint8)(100u)

 /*****************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
static uint8           UART_u8ProtectionFlag;
static uint8           UART_u16NumOfTxBytes;
static const uint8*    UART_pku8TxBuffer;


/******************************************************************************/
/*! \Description Rx buffer. \n
 ******************************************************************************/
static uint8 UART_au8RxBuffer[u8RX_BUFFER_LEN] =
{
  0 
};
/******************************************************************************/
/*! \Description index of received data. \n
 ******************************************************************************/
static uint8 UART_u8RxIndex;
/******************************************************************************/
/*! \Description flag to ensure that received complete. \n
 ******************************************************************************/
static boolean UART_bRxComplete;



/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
void UART_vidInit( void )
{
    uint8 u8Counter;
    
//    /* RLIN32 is configured in UART mode with 9600 baud*/
//    /* Disable RLIN */ 
//    RLN32LUOER = 0x00;
//    RLN32LCUC  = 0x00;
//
//    /* Clear ICRLIN30UR0(send complete int) request and Disable operation */
//    INTC2MKRLIN32UR0 = 0x1U;
//    INTC2RFRLIN32UR0 = 0x0U;
//    INTC2TBRLIN32UR0 = 0x1U;
//
//    /* Clear ICRLIN30UR1(rece complete int) request and Enable operation */
//    INTC2MKRLIN32UR1 = 0x0U;
//    INTC2RFRLIN32UR1 = 0x0U;
//    INTC2TBRLIN32UR1 = 0x1U;
//
//    /* IN Mode Register/UART Mode Register (LMD) */
//    RLN32LMD = 0x01;    //UART mode
//    //LIN / UART System Clock: fa
//    //Module generates 1 interrupt signal
//    //3-bit majority voting logic for sampling RX data is enabled.
//
//    /* LIN Break Field Configuration Register/UART Configuration Register1 */
//    RLN32LBFC = 0x00;   //UART 8-bit communication
//    //LSB first
//    //Stop Bit 1 bit
//    //Parity Disabled
//    //Without RX inversion
//    //Without RX inversion
//
//    /* LIN / UART Error Detection Enable Register */
//    RLN32LEDE = 0x00;   //No error detection
//
//    /* LIN Wake-up Baud Rate Selector register  */
//    RLN32LWBR = 0x51;   //6 samples per bit  
//
//
//    /* LIN Baud Rate Prescaler1/UART Baud Rate Prescaler */
//    /* Baudrate = PCLK / (((BRP value) + 1)*(number of samples per bit)). */
//    /* 40MHZ/((0x2b5+1)*16)= 9600 baud rate */
//    RLN32LBRP1 = 0x02;  
//    RLN32LBRP0 = 0xb5;  
//
//
//    /* LIN / UART Control Register */
//    RLN32LCUC=0x01;     //Set SW Reset request to inactive
//
//
//    /* UART Operation Enable Register */ 
//    RLN32LUOER=0x03;    //UART Transmission Operation Enable Bit
//    //UART Reception Operation Enable Bit
//
//    /*! Initialize Protection flag                                              */
//    UART_u8ProtectionFlag = 0;
//
//    /*! Initialize Number of bytes remaining to transmit in the buffer          */
//    UART_u16NumOfTxBytes = 0;
//
//    /*! Initialize Pointer to data buffer                                       */
//    UART_pku8TxBuffer = NULL_PTR;
//
//    /*! Initialize   UART_u8RxIndex                                             */
//    UART_u8RxIndex = 0;
//
//    /*! Initialize   UART_bRxComplete                                           */
//    UART_bRxComplete = FALSE;
//
//    /* Set RLIN32RX pin */
//    PORTPIBC0  &= (0xDFFFU);
//    PORTPBDC0  &= (0xDFFFU);
//    PORTPM0    |= (0x2000U); 
//    PORTPMC0   &= (0xDFFFU);
//    PORTPIPC0  &= (0xDFFFU);
//    PORTPFC0   |= (0x2000U);
//    PORTPFCE0  &= (0xDFFFU);
//    PORTPFCAE0 |= (0x2000U);  
//    PORTPMC0   |= (0x2000U);
//    /* Set RLIN32TX pin */
//    PORTPIBC0  &= (0xBFFFU);
//    PORTPBDC0  &= (0xBFFFU);
//    PORTPM0    |= (0x4000U);
//    PORTPMC0   &= (0xBFFFU);
//    PORTPIPC0  &= (0xBFFFU);
//    PORTPFC0   &= (0xBFFFU);
//    PORTPFCE0  &= (0xBFFFU);
//    PORTPFCAE0 &= (0xBFFFU);
//    PORTPMC0   |= (0x4000U); 
//    PORTPM0    &= (0xBFFFU);
//
//    /*! Initialize   UART_au8RxBuffer                                          */
//    for (u8Counter = 0; u8Counter < u8RX_BUFFER_LEN; u8Counter++)
//    {
//	UART_au8RxBuffer[u8Counter] = 0;
//    }
//  
//}
//
///******************************************************************************
//** Function:    UART_udtWriteBuffer
//** Description: Sends out a complete string via UART by using DirectMemoryAccess
//** Parameter:   string to be send
//** Return:      None
//******************************************************************************/
//void UART_vidWriteBuffer(const uint8 * pku8Buffer, uint8 u8Length )
//{
//    if ( pku8Buffer != NULL_PTR) 
//    {
//       /*! Check if protection flag is disabled */
//       if ( UART_u8ProtectionFlag == 0 ) 
//       {
//          /*! Enable protection flag */
//          UART_u8ProtectionFlag = 1;
//	  if ((RLN32LST & 0x10U) == 0U)
//          {
//              RLN32LUTDR = *pku8Buffer ;      
//          }
//          /*! Store the data buffer and
//          the number of bytes to write in global var*/
//          UART_u16NumOfTxBytes = u8Length;
//          UART_pku8TxBuffer = pku8Buffer;
//	  /* Clear ICRLIN30UR0 requestt and enable operation*/
//	  INTC2RFRLIN32UR0 = 0x0U;
//	  INTC2MKRLIN32UR0 = 0x0U;   
//
//       }
//    }
}

//#pragma ghs interrupt
//void INTRLIN32UR2(void)
//{
//
//}
//
//
//#pragma ghs interrupt
//void INTRLIN32UR0(void)
//{
//  if ( UART_pku8TxBuffer != NULL_PTR)
//  {
//    static uint8 LOC_u8TxIndex = 0u;
//    /*! If there are more bytes to transmit */
//    if (UART_u16NumOfTxBytes > 1u)//first byte has been send use UART_vidWriteBuffer,so here must be > 1 not 0
//    {
//      UART_u16NumOfTxBytes--;
//      LOC_u8TxIndex++;
//      RLN32LUTDR = UART_pku8TxBuffer[LOC_u8TxIndex];
//    }
//    else
//    {
//      LOC_u8TxIndex = 0u;
//      /*! ICRLIN30UR0 interrupt disable */
//      INTC2MKRLIN32UR0 = 0x1U;
//      /*! Disable Protection flag so that new data can be written*/
//      UART_u8ProtectionFlag = 0;
//    }
//  }
//}
//
//
//#pragma ghs interrupt
//void INTRLIN32UR1(void)
//{
//   uint16  u16RxData;
//   u16RxData = RLN32LURDR;
//   /*! Call the data received notification. */
//   if (UART_bRxComplete == FALSE)
//   { 
//      if (UART_u8RxIndex >= u8RX_BUFFER_LEN)
//      {
//        UART_u8RxIndex = 0;
//      }
//      UART_au8RxBuffer[UART_u8RxIndex] = (uint8)u16RxData;
//      /*! if message received and enter key pressed */
//      if ((UART_u8RxIndex != 0) &&
//          (UART_au8RxBuffer[UART_u8RxIndex] == u8LINE_FEED_CHAR)&&
//          (UART_au8RxBuffer[UART_u8RxIndex - 1] == u8CARRIAGE_CHAR ))
//      {
//         /*! inform that complete message received */
//         UART_bRxComplete = TRUE;
//      }
//      /*! ELSE*/
//      else
//      {
//         /*! Increase RX index*/
//         UART_u8RxIndex++;
//      }
//
//  }
//}
//
//uint8* UART_pku8RxBuff(void)
//{
//
//   return UART_au8RxBuffer;
//}

/** \} */ /* end of UART module group */
/** \} */ /* end of MCAL UART Component group */

/*-------------------------------- end of file -------------------------------*/

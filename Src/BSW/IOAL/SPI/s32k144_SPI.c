/*=============================================================================
                               INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
 =============================================================================*/

#include "s32k144_SPI.h"
#include "s32k144_DIO.h"
/*==============================================================================
*                              LOCAL MACROS, DEFINES
==============================================================================*/
/*! \Trace_To: HVAC_SCD_IOAL_0125#02  */
/*!Comment: Total number of SPI Channels used                                 */
#define u8NB_SPI_CH                                                           (2u)


/*!Comment: SPI Master transfer timeout                                       */
#define u8TIMEOUT                                                     ((uint8)0x1F)





/*==============================================================================
*                 LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/




/*==============================================================================
*                         LOCAL CONSTANTS
==============================================================================*/

/*==============================================================================
*                              LOCAL VARIABLES
==============================================================================*/

/*To indicates if the Channels are initialized or not                         */

/*! \Trace_To: HVAC_SCD_IOAL_0137#01                                         */
static boolean SPI_bCHsInitialized = FALSE;

/*==============================================================================
*                              GLOBAL CONSTANTS
==============================================================================*/


/*==============================================================================
*                              GLOBAL VARIABLES
==============================================================================*/

/*============================================================================*/

/*==============================================================================
*                              GLOBAL FUNCTIONS
==============================================================================*/

/*============================================================================*/


/*****************************************************************************/
/* !Function     : SPI_vidInit                                               */
/* !Description  : The function SPI_vidInit shall initialize all SPI         */
/*                 used instances                                               */
/* !Trace_To     :                                                           */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_IOAL_0027#01,HVAC_SCD_IOAL_0071#01 */
/*****************************************************************************/
extern void SPI_vidInit(void)
{
    SPI_bCHsInitialized = TRUE;

    /* Initialize SPI0 */
    (void) SPI_MasterInit(&spi1Instance, &spi1_MasterConfig0);
}

/*****************************************************************************/
/* !Function     : SPI_vidDeInit                                             */
/* !Description  : The function SPI_vidDeInit shall deinitialize all SPI     */
/*                 used instances                                               */
/* !Trace_To     :                                                           */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_IOAL_0027#01,HVAC_SCD_IOAL_0071#01 */
/*****************************************************************************/
extern void SPI_vidDeInit(void)
{
    SPI_bCHsInitialized = FALSE;  

    /* Initialize SPI0 */
    SPI_MasterDeinit(&spi1Instance);
}

/*****************************************************************************/
/* !Function     : SPI_bWriteData                                            */
/* !Description  : Service for writing one or more data to an SPI Channel    */
/*                   specified by parameter.                                     */
/* !Trace_To     :                                                               */
/* !Parameter[in]: u8SPIIdentifier: Channel ID                                 */
/* !Range        : uint8 (0..1)                                              */
/* !Parameter[in]: pu8DataBuffer: Pointer to source data buffer                 */
/* !Range        : uint32                                                      */
/* !Parameter[in]: pu8DataBuffer: Size of the data buffer                      */
/* !Range        : uint8                                                      */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_IOAL_0029#01,HVAC_SCD_IOAL_0096#01 */
/*****************************************************************************/
extern boolean  SPI_bWriteData(
        /* !Comment: SPI number                                               */
        /* !Range  : 0..(u8NB_SPI_CH-1)                                       */
        uint8 u8SPIIdentifier,
        /* !Comment: transmit data buffer                                     */
        uint8 pu8DataBuffer[],
        /* !Comment: transmit data buffer size                                */
        uint8 u8DataBufferSize,
        /* !Comment: Mode for W/R , W&R                                       */
        /* !Range  : 0 -> Write .. 1 -> Read/Write                            */
        uint8 u8Mode
)
{
    /* !Comment: Data Buffer Index                                            */
    uint8 u8BufferIndex;
    /* !Comment: Transmission Status                                          */
    status_t enuTxStatus = STATUS_ERROR;
    /* !Comment: Return TX Status                                             */
    boolean bIsTxOk = FALSE;
    /* SPI last transfer status */
    status_t SpiTransmitStatus;
    /* SPI transfer timeout */
    uint16 SpiTimeOut;

    uint8 au8RxDataBuffer[10]= {0u,0u,0u,0u,0u,0u,0u,0u,0u,0u};

    if((SPI_bCHsInitialized == TRUE) && (pu8DataBuffer != NULL_PTR))
    {
        switch (u8SPIIdentifier) {

        /* DSTM */
        case SPI_u8CH0_TLE9410X:
            SpiTimeOut = u8TIMEOUT;

            enuTxStatus = SPI_MasterTransfer(&spi1Instance,
                    (uint8*)pu8DataBuffer,
                    (uint8*)au8RxDataBuffer,
                    (uint16_t)u8DataBufferSize);

            SpiTransmitStatus = SPI_GetStatus(&spi1Instance);

            while ((STATUS_SUCCESS != SpiTransmitStatus) && (SpiTimeOut != 0u))
            {
                SpiTransmitStatus = SPI_GetStatus(&spi1Instance);
                SpiTimeOut--;
            }

            /* enuTxStatus = SPI_MasterTransferBlocking(
                                        &spi1Instance,(uint8 *) pu8DataBuffer,(uint8 *) au8RxDataBuffer,
                                        u8DataBufferSize, (uint8_t) 5); */
            break;
			
        case SPI_u8CH1_TLE9410X:
            SpiTimeOut = u8TIMEOUT;

            enuTxStatus = SPI_MasterTransfer(&spi1Instance,
                    (uint8*)pu8DataBuffer,
                    (uint8*)au8RxDataBuffer,
                    (uint16_t)u8DataBufferSize);

            SpiTransmitStatus = SPI_GetStatus(&spi1Instance);

            while ((STATUS_SUCCESS != SpiTransmitStatus) && (SpiTimeOut != 0u))
            {
                SpiTransmitStatus = SPI_GetStatus(&spi1Instance);
                SpiTimeOut--;
            }

            /* enuTxStatus = SPI_MasterTransferBlocking(
                                        &spi1Instance,(uint8 *) pu8DataBuffer,(uint8 *) au8RxDataBuffer,
                                        u8DataBufferSize, (uint8_t) 5); */
            break;

        default:
            /* invalid SPI channel */
            break;
        }

        if((u8Mode == SPI_u8MODE_READ_WRITE) && (enuTxStatus == STATUS_SUCCESS))
        {
            for(u8BufferIndex = 0u; u8BufferIndex < u8DataBufferSize; u8BufferIndex++)
            {
                pu8DataBuffer[u8BufferIndex]= au8RxDataBuffer[u8BufferIndex];
            }
        }
        else
        {

        }

        if(enuTxStatus == STATUS_SUCCESS)
        {
            bIsTxOk  = (boolean)TRUE;
        }
        else
        {
            bIsTxOk  = (boolean)FALSE;
        }
    }
    else
    {
        bIsTxOk  = (boolean)FALSE;
    }
    return bIsTxOk;
}

/*****************************************************************************/
/* !Function     : SPI_bReadData                                             */
/* !Description  : Service for reading one or more data to an SPI Channel    */
/*                   specified by parameter.                                     */
/* !Trace_To     : HVAC_SCD_IOAL_0030#01                                     */
/* !Parameter[in]: u8SPIIdentifier: Channel ID                                 */
/* !Range        : uint8 (0..1)                                              */
/* !Parameter[in]: pu8DataBuffer: Pointer to source data buffer                 */
/* !Range        : uint32                                                      */
/* !Parameter[in]: u8DataBufferSize: Size of the data buffer                  */
/* !Range        : uint8 (0..10)                                              */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*! \Trace_To: HVAC_SCD_IOAL_0030#01,HVAC_SCD_IOAL_0073#02 */
/*****************************************************************************/
extern boolean  SPI_bReadData(
        /* !Comment: SPI number                                                   */
        /* !Range  : 0..(u8NB_SPI_CH-1)                                           */
        uint8 u8SPIIdentifier,
        /* !Comment: Receive Data Buffer                                          */
        uint8 pu8DataBuffer[],
        /* !Comment: Receive Buffer Size                                          */
        uint8 u8DataBufferSize
)
{
    /* !Comment: Data Buffer Index                                                */
    uint8 u8BufferIndex = 0u;
    /* !Comment: Return Rx Status                                                 */
    boolean bIsRxOk = FALSE;
    /* !Comment: Send Data Buffer                                                 */
    uint8 u8TxDataBuffer = 0xFFu;
    /* !Comment: Send Data Buffer                                                 */
    uint8 u8RxDataBuffer = 0u;
    /* !Comment: Transmission Status                                              */
    status_t enuRxStatus = STATUS_SUCCESS;
    /* last transfer status */
    status_t SpiTransmitStatus;
    /* SPI transfer timeout */
    uint16 SpiTimeOut;

    if((SPI_bCHsInitialized == TRUE) && (pu8DataBuffer != NULL_PTR))
    {
        switch (u8SPIIdentifier) {

        /* DSTM */
        case SPI_u8CH0_TLE9410X:
			DIO_vidWrite(DIO_SPI_CS2,0);
		    DIO_vidWrite(DIO_SPI_CS1,1);
            for(u8BufferIndex= 0u; ((u8BufferIndex < u8DataBufferSize) &&(enuRxStatus == STATUS_SUCCESS)); u8BufferIndex++)
            {
                SpiTimeOut = u8TIMEOUT;

                enuRxStatus = SPI_MasterTransfer(&spi1Instance,
                        (uint8*)&u8TxDataBuffer,
                        (uint8*)&u8RxDataBuffer,
                        (uint16)1);

                SpiTransmitStatus = SPI_GetStatus(&spi1Instance);

                while ((STATUS_SUCCESS != SpiTransmitStatus) && (SpiTimeOut != 0u))
                {
                    SpiTransmitStatus = SPI_GetStatus(&spi1Instance);
                    SpiTimeOut--;
                }

                /* enuRxStatus = SPI_MasterTransferBlocking(
                            &spi1Instance, &u8TxDataBuffer, &u8RxDataBuffer,
                            (uint8_t) 1, (uint8_t) 1); */

                if(enuRxStatus == STATUS_SUCCESS)
                {
                    bIsRxOk  = (boolean)TRUE;
                    pu8DataBuffer[u8BufferIndex] = u8RxDataBuffer;
                }
                else
                {
                    bIsRxOk  = (boolean)FALSE;
                }
            }
			DIO_vidWrite(DIO_SPI_CS2,1);
			DIO_vidWrite(DIO_SPI_CS1,1);
            break;
			
		case SPI_u8CH1_TLE9410X:
			DIO_vidWrite(DIO_SPI_CS2,1);
			DIO_vidWrite(DIO_SPI_CS1,0);
			for(u8BufferIndex= 0u; ((u8BufferIndex < u8DataBufferSize) &&(enuRxStatus == STATUS_SUCCESS)); u8BufferIndex++)
			{
				SpiTimeOut = u8TIMEOUT;

				enuRxStatus = SPI_MasterTransfer(&spi1Instance,
						(uint8*)&u8TxDataBuffer,
						(uint8*)&u8RxDataBuffer,
						(uint16)1);

				SpiTransmitStatus = SPI_GetStatus(&spi1Instance);

				while ((STATUS_SUCCESS != SpiTransmitStatus) && (SpiTimeOut != 0u))
				{
					SpiTransmitStatus = SPI_GetStatus(&spi1Instance);
					SpiTimeOut--;
				}

				/* enuRxStatus = SPI_MasterTransferBlocking(
							&spi1Instance, &u8TxDataBuffer, &u8RxDataBuffer,
							(uint8_t) 1, (uint8_t) 1); */

				if(enuRxStatus == STATUS_SUCCESS)
				{
					bIsRxOk  = (boolean)TRUE;
					pu8DataBuffer[u8BufferIndex] = u8RxDataBuffer;
				}
				else
				{
					bIsRxOk  = (boolean)FALSE;
				}
			}
			DIO_vidWrite(DIO_SPI_CS2,1);
			DIO_vidWrite(DIO_SPI_CS1,1);
			break;

        default:
            /* !Pseudo: Error, u8SPIIdentifier is not valid, result is 0      */
            bIsRxOk=(boolean)FALSE;
            break;
        }
    }
    else
    {
        bIsRxOk  = (boolean)FALSE;
    }
    return (bIsRxOk);
}

/*****************************************************************************/
/* !Function     : SPI_u8SPI0WriteRead                                       */
/* !Description  : Wrapper API for COTS integration                          */
/* !Trace_To     :                                                           */
/* !Parameter[in]: pu8Data: Pointer to source data buffer                     */
/* !Range        : uint8*                                                      */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/

/*! \Trace_To: HVAC_SCD_IOAL_0074#01,HVAC_SCD_IOAL_0031#01 */
#if 0
extern boolean SPI_u8SPI0WriteRead(uint8* pu8Data)
{
    /* MISRA_Justification: Wrapper function due to COTS  */
    /* PRQA S 3200 1 */

    return SPI_bWriteData(SPI_u8CH0_TLE94108, pu8Data, (uint8)1, SPI_u8MODE_READ_WRITE);
}
#endif


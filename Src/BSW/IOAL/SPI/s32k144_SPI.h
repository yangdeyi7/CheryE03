#ifndef S32K144_SPI_H
#define S32K144_SPI_H

#include "Std_Types.h"
#include "spi1.h"

/*!Comment: Declares SPI channels Identifiers                               */
/*****************************      DC MOTOR CHIP    ************************/
#define  SPI_u8CH0_TLE9410X                                             ((uint8)0)
#define  SPI_u8CH1_TLE9410X                                             ((uint8)1)


/*! \Description: Operation Identifier  \n
 *! \Range      : 0 -> Write .. 1 -> Read/Write                             */
 #define SPI_u8MODE_WRITE                                            ((uint8)0)
 #define SPI_u8MODE_READ_WRITE                                        ((uint8)1)
 
/*****************************************************************************/
/* !Function     : SPI_vidInit                                               */
/* !Description  : The function SPI_vidInit shall initialize all SPI         */
/*                 used instances                                               */
/* !Trace_To     : HVAC_SCD_IOAL_0027#01                                        */
/* !Parameter[in]: void                                                         */
/* !Range        :                                                           */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern void SPI_vidInit(void);


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
extern void SPI_vidDeInit(void);


/*****************************************************************************/
/* !Function     : SPI_bWriteData                                            */
/* !Description  : Service for writing one or more data to an SPI Channel    */
/*                   specified by parameter.                                     */
/* !Trace_To     : HVAC_SCD_IOAL_0029#01                                      */
/* !Parameter[in]: u8SPIIdentifier: Channel ID                                 */
/* !Range        : uint8 (0..1)                                              */
/* !Parameter[in]: pu8DataBuffer: Pointer to source data buffer                 */
/* !Range        : uint32                                                      */
/* !Parameter[in]: pu8DataBuffer: Size of the data buffer                      */
/* !Range        : uint8                                                      */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern boolean SPI_bWriteData(uint8 u8SPIIdentifier,
                              uint8 *pu8DataBuffer,
                              uint8 u8DataBufferSize,
                              uint8 u8Mode);
                                          
/*****************************************************************************/
/* !Function     : SPI_bWriteData                                            */
/* !Description  : Service for reading one or more data to an SPI Channel    */
/*                   specified by parameter.                                     */
/* !Trace_To     : HVAC_SCD_IOAL_0030#01                                     */
/* !Parameter[in]: u8SPIIdentifier: Channel ID                                 */
/* !Range        : uint8 (0..1)                                              */
/* !Parameter[in]: pu8DataBuffer: Pointer to source data buffer                 */
/* !Range        : uint32                                                      */
/* !Parameter[in]: u8DataBufferSize: Size of the data buffer                  */
/* !Range        : uint8                                                      */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
extern boolean SPI_bReadData(uint8 u8SPIIdentifier,
                             uint8 *pu8DataBuffer,
                             uint8 u8DataBufferSize);

/*****************************************************************************/
/* !Function     : SPI_u8SPI0WriteRead                                       */
/* !Description  : Wrapper API for COTS integration                          */
/* !Trace_To     : HVAC_SCD_IOAL_0031#01                                      */
/* !Parameter[in]: pu8Data: Pointer to source data buffer                     */
/* !Range        : uint8*                                                      */
/* !Return       : void                                                      */
/* !Range        :                                                           */
/*****************************************************************************/
#if 0
extern boolean SPI_u8SPI0WriteRead(uint8* pu8Data);
#endif
#endif

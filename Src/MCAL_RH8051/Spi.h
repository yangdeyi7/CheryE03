/******************************************************************************/
/* PROJECT  :  CHJ_D01                                                        */
/******************************************************************************/
/* !Layer           : Spi                                                     */
/*                                                                            */
/* !Component       : Spi                                                     */
/* !Description     : Interface for Managing the Spi                          */
/*                                                                            */
/* !Module          : Spi                                                     */
/* !Description     : Spi                                                     */
/*                                                                            */
/* !File            : Spi.h                                                   */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* all rights reserved                                                        */
/******************************************************************************/
#ifndef SPI_H
#define SPI_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Port.h"
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define SPI_u8E910_MOSI_ID              ((uint8)0)
#define SPI_u8E910_CLK_ID               ((uint8)1)
#define SPI_u8M950_MOSI_ID              ((uint8)2)
#define SPI_u8M950_CLK_ID               ((uint8)3)
#define SPI_u8OUTPUT_NUM                ((uint8)4)              


#define SPI_u8E910_MISO_ID              ((uint8)0)
#define SPI_u8M950_MISO_ID              ((uint8)1)
#define SPI_u8INPUT_NUM                 ((uint8)2)

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

typedef enum
{
   E910 = 0u,
   M950 
}Spi_tenuDeviceType;
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
/******************************************************************************/
/*! \Description Initialization Service of the SPI.\n
 ******************************************************************************/
extern void Spi_vidInit(Spi_tenuDeviceType enuDeviceType);
extern Std_ReturnType Spi_udtWriteRead
(
  Spi_tenuDeviceType enuDeviceType,
  uint8* pu8Data
);

Std_ReturnType Spi_udtWriteReadTle9410x(uint16* pu16Data);

#endif /* SPI_H */

/*-------------------------------- end of file -------------------------------*/

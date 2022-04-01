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
/* !File            : Spi.c                                                   */
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
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Device.h"
#include "Std_Types.h"
#include "Spi.h"
#include "s32k144_SPI.h"
//#include "Spi_Cfg.h"
#include "Port.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/*!Function : Spi_vidInit                                                     */
/*! \Description SPI Initialization service.       \n
    \return      void.                             \n
    \Trace_To    
*******************************************************************************/
void Spi_vidInit(Spi_tenuDeviceType enuDeviceType )
{//spi
  SPI_vidInit();
}

/******************************************************************************/
/*!Function : SPI1_udtWriteRead                                                */
/*! \Description   Write/Read Function of the SPI.                    \n
    \param[inout]  u8SpiId    Spi ID                                  \n
    \param[inout]  *pu8Data   Data to be written and read.            \n
    \Range         0..255                                             \n
    \return        RW Status: E_OK -> Passed , E_NOT_OK -> FAILED.    \n
    \Trace_To      CDD-SPI-0007(0)
*******************************************************************************/
Std_ReturnType Spi_udtWriteReadTle9410x(uint16* pu16Data)
{
    Std_ReturnType udtStatus = E_OK;
    uint8 au8AddrDataBuffer[2];
    
    au8AddrDataBuffer[0] = (*pu16Data)   &0xFF;
    au8AddrDataBuffer[1] = (*pu16Data>>8)&0xFF;
    
    SPI_bWriteData(SPI_u8CH0_TLE9410X,au8AddrDataBuffer,1,SPI_u8MODE_READ_WRITE);
    
	return udtStatus;
}

/** \} */ /* end of SPI module group */
/** \} */ /* end of MCAL SPI Component */

/*-------------------------------- end of file -------------------------------*/

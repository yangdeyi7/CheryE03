/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Elmos                                                   */
/*                                                                            */
/* !Component       : Elmos                                                   */
/* !Description     : Provides interface for communication with Elmos chip    */
/*                                                                            */
/* !Module          : Elmos                                                   */
/* !Description     : Provides interface for communication with Elmos chip    */
/*                                                                            */
/* !File            : Elmos.c                                                 */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : uPD70F3375                                              */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/EC$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Elmos.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:10   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
 /******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Elmos.h"
#include "DIO.h"
#include "SPI.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description FRONT_DEF  initial value.
 *  \Range       1
*******************************************************************************/
#define u8FRONT_DEF_INIT_DATA        ((uint8)1)

/******************************************************************************/
/*! \Description INCAR_FAN  initial value.
 *  \Range       1
*******************************************************************************/
#define u8INCAR_FAN_INIT_DATA        ((uint8)1)

/******************************************************************************/
/*! \Description CMB TBD  initial value.
 *  \Range       1
*******************************************************************************/
#define u8TBD_INIT_DATA              ((uint8)1)

/******************************************************************************/
/*! \Description HEAT WIND  initial value.
 *  \Range       1
*******************************************************************************/
#define u8HEAT_WIND_INIT_DATA        ((uint8)1)
/******************************************************************************/
/*! \Description Steppers initial value.
 *  \Range       0x0F
*******************************************************************************/
#define u8STEPPER_INIT_DATA          ((uint8)0x0F)

/******************************************************************************/
/*! \Description Stepper Data Mask
 *  \Range       0x0F
*******************************************************************************/
#define u8STEPPER_MASK               ((uint8)0x0F)

/******************************************************************************/
/*! \Description FRONT_DEF Data Mask
 *  \Range       0x01
*******************************************************************************/
#define u8FRONT_DEF_MASK             ((uint8)1)

/******************************************************************************/
/*! \Description INCAR_FAN Data Mask
 *  \Range       0x01
*******************************************************************************/
#define u8INCAR_FAN_MASK             ((uint8)1)

/******************************************************************************/
/*! \Description CMB TBD Data Mask
 *  \Range       0x01
*******************************************************************************/
#define u8TBD_MASK                   ((uint8)1)

/******************************************************************************/
/*! \Description HEAT WIND  initial value.
 *  \Range       1
*******************************************************************************/
#define u8HEAT_WIND_MASK             ((uint8)1)

/******************************************************************************/
/*! \Description Number of signals handled by the Elmos.
 *  \Range       8
*******************************************************************************/
#define u8NUM_OF_SIG                 ((uint8)11)
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
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
/*! \Description Data to be written through the SPI.
*******************************************************************************/
static uint8 Elmos_au8WrData[u8NUM_OF_SIG];

/******************************************************************************/
/*! \Description Data read from the SPI.
*******************************************************************************/
static uint8 Elmos_au8RdData[u8NUM_OF_SIG];



/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
 
 

/******************************************************************************/
/*!Function : Elmos_vidInit                                                   */
/*! \Description Elmos Initialization service. \n
    \Return      void.
    \Trace_To    CDD-Elmos-
*******************************************************************************/
void Elmos_vidInit( void )
{
//  /*  write the data read from the SPI*/
//  Elmos_au8WrData[Elmos_StepperA] = u8STEPPER_INIT_DATA;
//  Elmos_au8WrData[Elmos_StepperB] = u8STEPPER_INIT_DATA;
//  Elmos_au8WrData[Elmos_StepperC] = u8STEPPER_INIT_DATA;
//  Elmos_au8WrData[Elmos_StepperD] = u8STEPPER_INIT_DATA;
//  Elmos_au8WrData[Elmos_StepperH] = u8STEPPER_INIT_DATA;
//  Elmos_au8WrData[Elmos_StepperI] = u8STEPPER_INIT_DATA;
//  Elmos_au8WrData[Elmos_StepperE] = u8STEPPER_INIT_DATA;
//  Elmos_au8WrData[Elmos_FORNT_DEF] = u8FRONT_DEF_INIT_DATA;
//  Elmos_au8WrData[Elmos_INCAR_FAN] = u8INCAR_FAN_INIT_DATA;
//  Elmos_au8WrData[Elmos_TBD]       = u8TBD_INIT_DATA;
//  Elmos_au8WrData[Elmos_HEAT_WIND] = u8INCAR_FAN_INIT_DATA;
//
//
//  /*! Initialize the data read from the SPI. */
//  Elmos_au8RdData[Elmos_StepperA] = u8STEPPER_INIT_DATA;
//  Elmos_au8RdData[Elmos_StepperB] = u8STEPPER_INIT_DATA;
//  Elmos_au8RdData[Elmos_StepperC] = u8STEPPER_INIT_DATA;
//  Elmos_au8RdData[Elmos_StepperD] = u8STEPPER_INIT_DATA;
//  Elmos_au8RdData[Elmos_StepperH] = u8STEPPER_INIT_DATA;
//  Elmos_au8RdData[Elmos_StepperI] = u8STEPPER_INIT_DATA;
//  Elmos_au8RdData[Elmos_StepperE] = u8STEPPER_INIT_DATA;
//  Elmos_au8RdData[Elmos_FORNT_DEF] = u8FRONT_DEF_INIT_DATA;
//  Elmos_au8RdData[Elmos_INCAR_FAN] = u8INCAR_FAN_INIT_DATA;
//  Elmos_au8RdData[Elmos_TBD]       = u8TBD_INIT_DATA;
//  Elmos_au8RdData[Elmos_HEAT_WIND] = u8INCAR_FAN_INIT_DATA;
//
//  
//  Dio_vidWrite(DIO_u8OUT_E910_DR1_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR2_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR3_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR4_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_RST, 1u);
//

 
}/* End of Elmos_vidInit()*/

/******************************************************************************/
/*!Function : Elmos_vidRefresh                                                */
/*! \Description Refresh Elmos. \n
    \Return      void.
    \Trace_To    CDD-Elmos-
*******************************************************************************/
void Elmos_vidRefresh( void )
{
//  /*! check the spi transmission ,  */
//  Std_ReturnType u8SpiReturn;  
//  uint8          u8Data;
//
//
//  /*! Enable Elmos chip 1 by setting the Elmos 1 CE to Low and
//      the Elmos 2,3 CE to high using Dio_vidWrite. */
//  Dio_vidWrite(DIO_u8OUT_E910_DR1_EN, 0u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR2_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR3_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR4_EN, 1u);
//
//
//  /*! Prepare the mixing left and mixing right stepper motor data to be written:
//      a) Mixing Right in Most si3gnificant nibble.
//      b) Mixing Left in Least significant nibble.  */
// 
//  u8Data = Elmos_au8WrData[Elmos_StepperA];
//  u8Data = (u8Data | (uint8)(Elmos_au8WrData[Elmos_StepperB] << 4u));
//
//  /*! Write the data to the SPI */
//  u8SpiReturn = Spi_udtWriteRead(E910,&u8Data);
//  
//  /*! If SPI_u8WriteRead returns E_OK */
//  if (u8SpiReturn == E_OK)
//  {
//    /*! Set the mixing right and left stepper data using the returned value
//        of SPI_u8WriteRead */
//    Elmos_au8RdData[Elmos_StepperA] = (u8Data & u8STEPPER_MASK);
//    Elmos_au8RdData[Elmos_StepperB] = (u8Data >> 4u);
//  }
//
//
//  /*! Enable Elmos chip 2 by setting the Elmos 2 CE to Low and
//      the Elmos 1,3 CE to high using Dio_vidWrite. */    
//  
//  Dio_vidWrite(DIO_u8OUT_E910_DR1_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR2_EN, 0u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR3_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR4_EN, 1u);
//  
//
//  
//  /*! Prepare the Mode and Recirculation stepper motor data to be written:
//      a) Recirculation in Most significant nibble.
//      b) Mode in Least significant nibble.  */
// 
//  u8Data = Elmos_au8WrData[Elmos_StepperC];
//  u8Data = (u8Data | (uint8)(Elmos_au8WrData[Elmos_StepperD] << 4u));
//
//  /*! Write the data to the SPI */
//  u8SpiReturn = Spi_udtWriteRead(E910,&u8Data);
//  
//  /*! If SPI_u8WriteRead returns E_OK */
//  if (u8SpiReturn == E_OK)
//  {
//    /*! Set the mixing right and left stepper data using the returned value
//        of SPI_u8WriteRead */
//    Elmos_au8RdData[Elmos_StepperC] = (u8Data & u8STEPPER_MASK);
//    Elmos_au8RdData[Elmos_StepperD] = (u8Data >> 4u);
//  }  
//
//
//
//  /*! Enable Elmos chip 3 by setting the Elmos 3 CE to Low and
//      the Elmos 1,2 CE to high using Dio_vidWrite. */    
//  Dio_vidWrite(DIO_u8OUT_E910_DR1_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR2_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR3_EN, 0u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR4_EN, 1u);
//  /*! Prepare the Mode and Recirculation stepper motor data to be written:
//      a) Recirculation in Most significant nibble.
//      b) Mode in Least significant nibble.  */
// 
//  u8Data = Elmos_au8WrData[Elmos_StepperH];
//  u8Data = (u8Data | (uint8)(Elmos_au8WrData[Elmos_StepperI] << 4u));
//
//  /*! Write the data to the SPI */
//  u8SpiReturn = Spi_udtWriteRead(E910,&u8Data);
//  
//  /*! If SPI_u8WriteRead returns E_OK */
//  if (u8SpiReturn == E_OK)
//  {
//    /*! Set the mixing right and left stepper data using the returned value
//        of SPI_u8WriteRead */
//    Elmos_au8RdData[Elmos_StepperH] = (u8Data & u8STEPPER_MASK);
//    Elmos_au8RdData[Elmos_StepperI] = (u8Data >> 4u);
//  }
//  
//  /*! Enable Elmos chip 3 by setting the Elmos 4 CE to Low and
//      the Elmos 1,2 CE to high using Dio_vidWrite. */    
//  Dio_vidWrite(DIO_u8OUT_E910_DR1_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR2_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR3_EN, 1u);
//  Dio_vidWrite(DIO_u8OUT_E910_DR4_EN, 0u);
//
//  /*** OUT0...3 <---> STEEPER***/
//  /*** OUT4 <---> Elmos_FORNT_DEF***/
//  /*** OUT5 <---> Elmos_INCAR_FAN***/
//  /*** OUT6 <---> Elmos_TBD***/
//  /*** OUT7 <---->Elmos_HEAT_WIND***/
//
//  /*!  Prepare the Elmos_FORNT_DEF,Elmos_INCAR_FAN, Elmos_HEAT_WIND and Rec stepper motor data to be written:
//       a) stepper data in low 4 significant bits.
//       b) Elmos_FORNT_DEF in Bit 4
//       c) Elmos_INCAR_FAN in Bit 5
//       d) Elmos_HEAT_WIND in Bit 7
//   */
//  u8Data =  Elmos_au8WrData[Elmos_StepperE];
//  u8Data = (u8Data | ((Elmos_au8WrData[Elmos_FORNT_DEF]  & u8FRONT_DEF_MASK) << 4u));
//  u8Data = (u8Data | ((Elmos_au8WrData[Elmos_INCAR_FAN]  & u8INCAR_FAN_MASK) << 5u));
//  u8Data = (u8Data | ((Elmos_au8WrData[Elmos_TBD]        & u8TBD_MASK)       << 6u));
//  u8Data = (u8Data | ((Elmos_au8WrData[Elmos_HEAT_WIND]  & u8HEAT_WIND_MASK) << 7u));
//  
//  /*! Write the data to the SPI */
//  u8SpiReturn = Spi_udtWriteRead(E910,&u8Data);
//  
//  /*! If SPI_u8WriteRead returns E_OK */
//  if (u8SpiReturn == E_OK)
//  {
//	Elmos_au8RdData[Elmos_StepperE] = (u8Data & u8STEPPER_MASK);
//    Elmos_au8RdData[Elmos_FORNT_DEF]= ((u8Data >> 4u) & u8FRONT_DEF_MASK);
//    Elmos_au8RdData[Elmos_INCAR_FAN]= ((u8Data >> 5u) & u8INCAR_FAN_MASK);
//    Elmos_au8RdData[Elmos_TBD]      = ((u8Data >> 6u) & u8TBD_MASK);
//    Elmos_au8RdData[Elmos_HEAT_WIND]= ((u8Data >> 7u) & u8HEAT_WIND_MASK);
//  }    

} /* end of Elmos_vidRefresh() */

/******************************************************************************/
/*!Function : Elmos_vidWrite                                                  */
/*! \Description Write to Elmos. \n
    \param[in]   enuElmosId : Id of signal to be written.
    \Range       Elmos_BLOWER, Elmos_AC, Elmos_RRDEF, Elmos_MIX_L,
                 Elmos_MIX_R,Elmos_MODE  \n
    \param[in]   u8Value : Data to be written.
    \Range       0..255
    \Return      void.
    \Trace_To    CDD-Elmos-
*******************************************************************************/
void Elmos_vidWrite(Elmos_tenuId enuElmosId, uint8 u8Value)
{

  /*! Set data to be written in Elmos_vidRefresh for enuElmosId with u8Value.  */
  Elmos_au8WrData[enuElmosId] = u8Value;

}/* End of Elmos_vidWrite() */

/******************************************************************************/
/*!Function : Elmos_u8Read                                                    */
/*! \Description Read From Elmos. \n
    \param[in]   enuElmosId : Id of signal to be read.
    \Range       Elmos_BLOWER, Elmos_AC, Elmos_RRDEF, Elmos_MIX_L,
                 Elmos_MIX_R,Elmos_MODE  \n  
    \Return      Read data
    \Trace_To    CDD-Elmos-
*******************************************************************************/
uint8  Elmos_u8Read(Elmos_tenuId enuElmosId)
{

  /*! Return the read data in Elmos_vidRefresh for enuElmosId.*/
  return Elmos_au8RdData[enuElmosId];
}/* End of Elmos_u8Read() */


/** \} */ /* end of Elmos module group */
/** \} */ /* end of ECUAL Elmos Component */

/*-------------------------------- end of file -------------------------------*/

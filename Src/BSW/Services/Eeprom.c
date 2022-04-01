/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : EEPROM                                                  */
/*                                                                            */
/* !Component       : EEPROM                                                  */
/* !Description     : Provides interface for accessing the EEPROM             */
/*                                                                            */
/* !Module          : EEPROM                                                  */
/* !Description     : Provides interface for accessing the EEPROM             */
/*                                                                            */
/* !File            : EEPROM.c                                                */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Se$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Jun 30 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/Eeprom.c-arc  $
 * 
 *    Rev 1.1   Jun 30 2017 18:19:16   chunping.yan
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
//#include "SPI.h"
#include "DIO.h"
#include "Eeprom.h"
#include "FlexNVM.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description ERSR  COMMAND 
 *! \Range   1 
*******************************************************************************/
#define u8WRSR_COMMAND                 (uint8)0x01

/******************************************************************************/
/*! \Description WRITE Command
 *! \Range  2  
*******************************************************************************/
#define u8WRITE_COMMAND                (uint8)0x02

/******************************************************************************/
/*! \Description READ command 
 *! \Range 3 
*******************************************************************************/
#define u8READ_COMMAND                 (uint8)0x03

/******************************************************************************/
/*! \Description WRDI command
 *! \Range 4  
*******************************************************************************/
#define u8WRDI_COMMAND                 (uint8)0x04

/******************************************************************************/
/*! \Description RDSR Command
 *! \Range 5
*******************************************************************************/
#define u8RDSR_COMMAND                 (uint8)0x05

/******************************************************************************/
/*! \Description WREN Command
 *! \Range 6
*******************************************************************************/
#define u8WREN_COMMAND                 (uint8)0x06

/******************************************************************************/
/*! \Description timeout parameter for writting process check
 *! \Range 100
*******************************************************************************/
/* If write multipage, use simulation test >=880 is OK, <=870 is NK */
#define WRITE_TIMEOUT                  (uint16)1000


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
#define CS_ENABLE            Dio_vidWrite(DIO_u8OUT_EEP_CS,0u)
#define CS_DISABLE           Dio_vidWrite(DIO_u8OUT_EEP_CS,1u)

#define WP_ENABLE            Dio_vidWrite(DIO_u8OUT_EEP_WP,1u)
#define WP_DISABLE           Dio_vidWrite(DIO_u8OUT_EEP_WP,0u)

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/*! \Description EEP data Valid Flag
 *! \Range 
*******************************************************************************/
static boolean EEP_bEepValidFlag;

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/

/******************************************************************************/
/*! \Description check the write process finish or not
*******************************************************************************/
//static uint8 u8ReadEepromStatus(void);

/******************************************************************************/
/*! \Description  write WR enable & disable
*******************************************************************************/
//static void vidWriteEepromcommand(uint8 u8Command);

/******************************************************************************/
/*! \Description  set Stepper parameters
*******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/*! function : vidWriteEepromcommand                                          */
/*! \Description : write command to eeprom
    \param[in]   write command.
    \Range       00--->255
    \return      void.
    \Trace_To    CDD-Eeprom-0001(0),CDD-Eeprom-0002(0),CDD-Eeprom-0003(0)
                 CDD-Eeprom-0004(0),CDD-Eeprom-0005(0),CDD-Eeprom-0006(0)
                 CDD-Eeprom-0007(0),CDD-Eeprom-0008(0),CDD-Eeprom-0009(0)
                 CDD-Eeprom-0010(0),CDD-Eeprom-0011(0)
*******************************************************************************/
// static void vidWriteEepromcommand(uint8 u8Command)
// {
////   Std_ReturnType udtSpiReturn = E_OK;
////   uint8          u8Temp = 0u;
////   
////   u8Temp = u8Command;
////   CS_ENABLE;
////   udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
////   if(udtSpiReturn != E_OK)
////   {
////       /*! error handle*/
////   } 
////   CS_DISABLE;   
// } /* end of EEP_vidWritecommand() */

 
/******************************************************************************/
/*! function :   u8ReadEepromStatus                                           */
/*! \Description : Read status  from  EEPROM 
    \return       status value
    \Trace_To    CDD-Eeprom-0001(0),CDD-Eeprom-0002(0),CDD-Eeprom-0003(0)
                 CDD-Eeprom-0004(0),CDD-Eeprom-0005(0),CDD-Eeprom-0006(0)
                 CDD-Eeprom-0007(0),CDD-Eeprom-0008(0),CDD-Eeprom-0009(0)
                 CDD-Eeprom-0010(0),CDD-Eeprom-0011(0)
*******************************************************************************/
// static uint8 u8ReadEepromStatus(void)
// {
////   Std_ReturnType udtSpiReturn = E_OK;
////   uint8          u8Temp = 0u;
////
////   u8Temp = u8RDSR_COMMAND;
////   CS_ENABLE;
////   udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
////   if(udtSpiReturn != E_OK)
////   {
////       /*! error handle*/
////   }
////   else
////   {
////       u8Temp = 0xffu;
////       udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
////       if(udtSpiReturn != E_OK)
////       {
////	   /*! error handle*/
////       }
////   }
////   CS_DISABLE;
////   return u8Temp;
// }  /* end of EEP_u8ReadStatus() */

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

          
/******************************************************************************/
/*! function : EEP_vidInitial                                                 */
/*! \Description  initial EEROM 
    \parameter  NA
    \range      NA
    \return     NA
    \Trace_To   CDD-Eeprom-0004(0),CDD-Eeprom-0005(0),CDD-Eeprom-0006(0),
                CDD-Eeprom-0007(0)
*******************************************************************************/ 
extern void EEP_vidInit(void)
{
  uint8  au8Buf[8];
  if (EEP_u16ReadData(EEP_ADDR_EEPVALID, au8Buf, 8u) == 8u)
  {
      if (au8Buf[0] == 0x55u &&
          au8Buf[1] == 0xAAu &&
          au8Buf[2] == 0xBBu &&
          au8Buf[3] == 0xCCu &&
          au8Buf[4] == 0xDDu &&
          au8Buf[5] == 0xEEu &&
          au8Buf[6] == 0xFFu &&
          au8Buf[7] == 0x55u)
      {
          EEP_bEepValidFlag = TRUE;
      }
      else
      {
          EEP_bEepValidFlag = FALSE;
      }
  }
  
}/* End of EEP_vidInitial */

/******************************************************************************/
/*! function : EEP_bGetEEPValidInfo                                           */
/*! \Description Eep data valid  flag
    \param[in]   none
    \return      EEP_bEepValidFlag
    \Trace_To    CDD-Eeprom-
*******************************************************************************/
extern boolean EEP_bGetEEPValidInfo(void)
{
    return EEP_bEepValidFlag;
}

/******************************************************************************/
/*! function : EEP_u8WriteOneByte                                             */
/*! \Description write one byte data to EEPROM.
    \param[in]   u16Address: Address in which data written.
    \Range       00--->0x0fff
    \param[in]   u8Data: the data to be written in EEPROM.
    \Range       0--->255
    \return      RW Status: E_OK -> Passed , E_NOT_OK -> FAILED.
    \Trace_To    CDD-Eeprom-0001(0),CDD-Eeprom-0002(0),CDD-Eeprom-0003(0)
                 CDD-Eeprom-0004(0)
*******************************************************************************/

extern uint8 EEP_u8WriteOneByte(uint16 u16Address, uint8 u8Data)
{
   // uint8 u8WriteIdleStatus;
    uint8 u8WriteSucessFlag=0;
   // uint16 u16Count = WRITE_TIMEOUT;

    //Std_ReturnType udtSpiReturn = E_OK;
    //uint8          u8Temp = 0u;
    uint32   u32WriteLen=0;
    
    FNVM_udtWriteEEP(u16Address, &u8Data, 1,&u32WriteLen);
    
    return u8WriteSucessFlag;
}/* End of EEP_u8WriteOneByte() */

/******************************************************************************/
/*!  Function:   EEP_u8ReadOneByte                                         */
/*! \Description Read one byte from EEPROM.
    \param[in]   u16Address: Address from which data read.
    \Range       0--->0x0fff
    \return      the data read form EEPROM
    \Trace_To    CDD-Eeprom-0001(0),CDD-Eeprom-0002(0),CDD-Eeprom-0003(0)
                 CDD-Eeprom-0004(0)
*******************************************************************************/
//extern uint8 EEP_u8ReadOneByte(uint16 u16Address)
//{ 
//    uint8  u8WriteIdleStatus = 0u;
//    uint16 u16Count = WRITE_TIMEOUT;
//
//    Std_ReturnType udtSpiReturn = E_OK;
//    uint8          u8Temp = 0u;
//    /*! get the write idle status from EEPROM */
//    u8WriteIdleStatus = u8ReadEepromStatus();
//    /*! read data form Eeprom */
//    while (((u8WriteIdleStatus & 0x01u) != 0x00u) && (u16Count != 0u))
//    { 
//        u16Count -- ;
//        u8WriteIdleStatus = u8ReadEepromStatus();
//    }
//    if (u16Count != 0u)
//    {
//        CS_ENABLE;
//
//	u8Temp = u8READ_COMMAND;
//	udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//	if(udtSpiReturn != E_OK)
//	{
//	    /*! error handle*/
//	}
//	else
//	{
//	    u8Temp = u16Address >> 8u;
//	    udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//	    if(udtSpiReturn != E_OK)
//	    {
//		/*! error handle*/
//	    }
//	    else
//	    {
//		u8Temp = u16Address;
//		udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//		if(udtSpiReturn != E_OK)
//		{
//		    /*! error handle*/
//		}
//		else
//		{
//		    u8Temp = 0xffu;
//		    udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//		    if(udtSpiReturn != E_OK)
//		    {
//			/*! error handle*/
//		    }
//		}
//	    }
//	}
//        /*!take the feeback data from Eeprom*/
//        CS_DISABLE; 
//    }
//    return  u8Temp;
//}/* End of EEP_u8WriteOneByte() */


/******************************************************************************/
/*! function : EEP_u8WriteOnepage                                             */
/*! \Description write one page data to EEPROM.Just write one page (32 bytes)
                 per time, the data over than the 1st page bound will discard.
    \param[in]   u16Address: Address in which data written.
    \Range       00--->0x0fff
    \param[in]   pku8Data:   pointer to data to write.
    \Range       Not NULL
    \param[in]   u16Length: length of data.
    \Range       0--->32
    \return      data lenth which has been written in EEPROM
    \Trace_To    CDD-Eeprom-0005(0),CDD-Eeprom-0006(0),CDD-Eeprom-0007(0)
                 CDD-Eeprom-0008(0),CDD-Eeprom-0009(0)
*******************************************************************************/
//extern uint8 EEP_u8WriteOnePage
//(
//   uint16 u16Address,
//   uint8* pu8Data,
//   uint16 u16Length
//)
//{
////    uint8 u8WriteIdleStatus;
////    uint8 u8WriteLen;
////    uint16 u16Count = WRITE_TIMEOUT;
////
////    Std_ReturnType udtSpiReturn = E_OK;
////    uint8          u8Temp = 0u;
////    /*! get the write idle status from EEPROM  */
////    u8WriteIdleStatus = u8ReadEepromStatus();
////    /*! if write process is not finished ,
////      then wait until writing process finish */
////    while (((u8WriteIdleStatus & 0x01u) != 0x0u) && (u16Count != 0u))
////    { 
////        u16Count -- ;
////        u8WriteIdleStatus = u8ReadEepromStatus();
////    }
////    /*! if not timeout ,then write data to EEPROM*/ 
////    /*  Don't need check the writen endaddress
////        due to the write can not exceed the EEP_ADDR_EEPMAXADDR */
////    if ((0u != u16Count) && (0u != u16Length) && (EEP_ADDR_EEPMAXADDR  >= u16Address))
////    {
////        /* Ensure writen data in one page */
////        u8WriteLen = EEP_u8PAGESIZE - (u16Address & (EEP_u8PAGESIZE - 1u));
////        u8WriteLen = (uint8)(MIN(u8WriteLen, u16Length));
////
////        /*! WP open*/
////        WP_ENABLE;
////        /*! enable write process */
////        vidWriteEepromcommand(u8WREN_COMMAND);
////        /*! write data to indicate address */     
////        CS_ENABLE;
////	
////	u8Temp = u8WRITE_COMMAND;
////	udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
////	if(udtSpiReturn != E_OK)
////	{
////	    /*! error handle*/
////	}
////	else
////	{
////	    u8Temp = u16Address >> 8u;
////	    udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
////	    if(udtSpiReturn != E_OK)
////	    {
////		/*! error handle*/
////	    }
////	    else
////	    {
////		u8Temp = u16Address;
////		udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
////		if(udtSpiReturn != E_OK)
////		{
////		    /*! error handle*/
////		}
////		else
////		{
////		    for (u16Count = 0u; u16Count < u8WriteLen; u16Count++)
////		    {
////			u8Temp = *(pu8Data + u16Count);
////			udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
////			if(udtSpiReturn != E_OK)
////			{
////			    /*! error handle*/
////			}
////		    }
////		}
////	    }
////	}
////        CS_DISABLE; 
////
////        /*! WP CLOSE FOR PROTECTION */
////        WP_DISABLE;
////    }
////    else
////    {
////        u8WriteLen = 0u ;
////    }
//    return u8WriteLen;
//}/* End of EEP_u8WriteOneByte() */


/******************************************************************************/
/*! function : EEP_u16WriteMultiPage                                             */
/*! \Description write Multi page data to EEPROM.
    \param[in]   u16Address: Address in which data written.
    \Range       00--->0x0fff
    \param[in]   pku8Data:   pointer to data to write.
    \Range       Not NULL
    \param[in]   u16Length: length of data.
    \Range       0--->0x0fff
    \return      data lenth which has been written in EEPROM
    \Trace_To    CDD-Eeprom-0010(0),CDD-Eeprom-0011(0)
*******************************************************************************/
extern uint16 EEP_u16WriteMultiPage
(
   uint16 u16Address,
   uint8* pu8Data,
   uint16 u16Length
)
{
//    uint16 u16WriteLen;
//    uint8  u8SinleWriteLen;
//    /*  Don't need check the writen endaddress
//        due to the write can not exceed the EEP_ADDR_EEPMAXADDR */
//    if ((0u != u16Length) && (EEP_ADDR_EEPMAXADDR >= u16Address))
//    {
//        u8SinleWriteLen = EEP_u8WriteOnePage(u16Address, pu8Data, u16Length);
//        u16WriteLen = u8SinleWriteLen;
//        while ((u16WriteLen < u16Length) && (0u != u8SinleWriteLen))
//        {
//            u8SinleWriteLen = EEP_u8WriteOnePage(u16Address + u16WriteLen,
//                                                 pu8Data + u16WriteLen,
//                                                 u16Length - u16WriteLen);              
//            u16WriteLen += u8SinleWriteLen;
//        }
//    }
//    else
//    {
//        u16WriteLen = 0u;
//    }
    uint32 u32WriteLen=0;
    FNVM_udtWriteEEP(u16Address, pu8Data, u16Length,&u32WriteLen);
    
    return (uint16)u32WriteLen;
}


/******************************************************************************/
/*!Function:   EEP_u16ReadData                                                */
/*! \Description Read data to EEPROM.
    \param[in]   u16Address: Address from which data read.
    \Range       0--->0x0fff
    \param[in]   pu8Data:   pointer to data which is readed form EEP.
    \Range       NotNull
    \param[in]   u16Length: length of data.
    \Range       0--->0x0fff
    \return      data lenth which has been readed in EEPROM
    \Trace_To    CDD-Eeprom-0005(0),CDD-Eeprom-0006(0),CDD-Eeprom-0007(0)
                 CDD-Eeprom-0008(0),CDD-Eeprom-0009(0),CDD-Eeprom-0010(0)
                 CDD-Eeprom-0011(0)
*******************************************************************************/
extern uint16 EEP_u16ReadData
(
   uint16 u16Address,
   uint8* pu8Data,
   uint16 u16Length
)
{
//        uint8 u8WriteIdleStatus;
//        uint16 u16ReadLen;
 //       uint16 u16Count = WRITE_TIMEOUT;
	
//        Std_ReturnType udtSpiReturn = E_OK;
//        uint8          u8Temp = 0u;
//        /*! get the write idle status from EEPROM */
//        u8WriteIdleStatus = u8ReadEepromStatus();
//        /*! if write process is not finished ,
//          then wait until writing process finish */
//        while (((u8WriteIdleStatus & 0x01u) != 0x00u) && (u16Count != 0u))
//        { 
//            u16Count -- ;
//            u8WriteIdleStatus = u8ReadEepromStatus();
//        }
//        /*! if not timeout, then read data from EEPROM */ 
//        /*  Don't need check the readed endaddress
//            due to the read can not exceed the EEP_ADDR_EEPMAXADDR */
//        if ((u16Count != 0u) && (EEP_ADDR_EEPMAXADDR >= u16Address))
//        {
//            /* Ensure read data are in valid EEPROM range */
//            u16ReadLen = MIN(u16Length, (EEP_ADDR_EEPMAXADDR + 1u - u16Address));
//            CS_ENABLE;
//	    
//	    u8Temp = u8READ_COMMAND;
//	    udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//	    if(udtSpiReturn != E_OK)
//	    {
//		/*! error handle*/
//	    }
//	    else
//	    {
//		u8Temp = u16Address >> 8u;
//		udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//		if(udtSpiReturn != E_OK)
//		{
//		    /*! error handle*/
//		}
//		else
//		{
//		    u8Temp = u16Address;
//		    udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//		    if(udtSpiReturn != E_OK)
//		    {
//			/*! error handle*/
//		    }
//		    else
//		    {
//			for (u16Count = 0u; u16Count < u16ReadLen; u16Count++)
//			{
//			    u8Temp = 0xffu;
//			    udtSpiReturn = Spi_udtWriteRead(M950,&u8Temp);
//			    if(udtSpiReturn != E_OK)
//			    {
//				/*! error handle*/
//			    }
//			    *pu8Data = u8Temp;
//			    pu8Data++;
//			}
//		    }
//		}
//	    }
//            CS_DISABLE;                 
//        }
//        else
//        {
//            u16ReadLen = 0u ;
//        }
        uint32 u32ReadLen;
        
        FNVM_udtReadEEP(u16Address, pu8Data, u16Length,&u32ReadLen);

        return (uint16)u32ReadLen;
}

/** \} */ /* end of Eeprom module group */
/** \} */ /* end of Sevice Eeprom Component */

/*-------------------------------- end of file -------------------------------*/

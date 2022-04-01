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
/* !File            : EEPROM.h                                                */
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
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/Eeprom.h-arc  $
 * 
 *    Rev 1.1   Jun 30 2017 18:19:16   chunping.yan
 * standardization
 * 
 *    Rev 1.0   Jun 30 2017 09:47:22   CYAN
 * Initial revision.
 * 
 * 
 ******************************************************************************/
#ifndef EEPROM_H
#define EEPROM_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define EEP_u16STEPPER_PARA_SUBADDR          0x0000u


/*********************Blower Parameters Add Start((8+8+1)bytes)*********************/
/******************************************************************************/
/*! \Description Blower Voltage Level address.
 *! \Range 
*******************************************************************************/
#define EEP_u16BLW_VOLT_LEVEL_SUBADDR       (EEP_u16STEPPER_PARA_SUBADDR + 39u)



/******************************************************************************/
/*! \Description static zone size.
 *! \Range  
*******************************************************************************/
#define EEP_u8STATIC_ZONE_SIZE        (EEP_u16BLW_VOLT_LEVEL_SUBADDR + 17u + 1u) 






/******************************************************************************/
/*! \Description EEP zone size.
 *! \Range  
*******************************************************************************/
/* #define EEP_ADDR_STATIC                          0x0000u
#define EEP_ADDR_DYN                             0x0180u
#define EEP_ADDR_FBL                             0x0280u
#define EEP_ADDR_COMFORT                         0x0380u
#define EEP_ADDR_CANO2Z_L                        0x063Cu
#define EEP_ADDR_TRACE                           0x0922u
#define EEP_ADDR_TRACE_DID                       0x0932u
#define EEP_ADDR_DTC                             0x0972u
#define EEP_ADDR_CDS                             0x0BDFu
#define EEP_ADDR_CDSFP                           0x0BFFu
#define EEP_ADDR_SER                             0x0C27u
#define EEP_ADDR_CANO2Z_R                        0x0C37u
#define EEP_ADDR_EEPINFO                         0x0FE0u
#define EEP_ADDR_EEPVALID                        0x0FF0u
#define EEP_ADDR_EEPMAXADDR                      0x0FFFu */

#define EEP_ADDR_STATIC     0x0000u
#define EEP_ADDR_DYN        0x0100u
#define EEP_ADDR_FBL        0x0180u
#define EEP_ADDR_COMFORT    0x0280u
#define EEP_ADDR_Reserved1   0x0B80u
#define EEP_ADDR_TRACE      0x0BA0u
#define EEP_ADDR_TRACE_DID  0x0BC0u
#define EEP_ADDR_DTC        0x0C00u
#define EEP_ADDR_Reserved2        0x0F00u
#define EEP_ADDR_Reserved3      0x0F20u
#define EEP_ADDR_SER        0x0F40u
#define EEP_ADDR_Reserved4   0x0F60u
#define EEP_ADDR_EEPINFO    0x0FC0u
#define EEP_ADDR_EEPVALID   0x0FE0u
#define EEP_ADDR_EEPMAXADDR 0x1FFFu

/*TBD*/
#define EEP_ADDR_CANO2Z_L                        (EEP_ADDR_COMFORT + 661)
#define EEP_ADDR_CANO2Z_R                        (EEP_ADDR_COMFORT + 1150)

/******************************************************************************/
/*! \Description EEP Page size and EEP Range.
 *! \Range  
*******************************************************************************/
#define EEP_u8PAGESIZE                             32u

/*sub address*/
#define EEP_u8STATIC_AUTOSTALLCNT	111u

#define EEP_u8DYN_ONCNT_H			80u
#define EEP_u8DYN_ONCNT_L			81u
#define EEP_u8DYN_OFFCNT_L			82u
#define EEP_u8DYN_STALLSTATUS		83u
#define EEP_u8DYN_ONCNT_LASTSTALL	84u
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
#ifndef MAX
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void    EEP_vidInit(void) ;
extern boolean EEP_bGetEEPValidInfo(void);
extern uint8   EEP_u8WriteOneByte(uint16 u16Address, uint8 u8Data);
extern uint8   EEP_u8ReadOneByte(uint16 u16Address);
extern uint8   EEP_u8WriteOnePage
(
   uint16 u16Address,
   uint8* pu8Data,
   uint16 u16Length
);
extern uint16  EEP_u16WriteMultiPage
(
   uint16 u16Address,
   uint8* pu8Data,
   uint16 u16Length
);
extern uint16  EEP_u16ReadData
(
   uint16 u16Address,
   uint8* pu8Data,
   uint16 u16Length
);

#endif
/*-------------------------------- end of file -------------------------------*/

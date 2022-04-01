/******************************************************************************/
/* PROJECT  :  M8X                                                            */
/******************************************************************************/
/*!Layer           : Service                                                  */
/*                                                                            */
/*!Component       : CRC8                                                     */
/*!Description     : Contains the CRC8 J1850 of the Software                  */
/*                                                                            */
/*!Module          : CRC8                                                     */
/*!Description     : CRC8                                                     */
/*                                                                            */
/*!File            : CRC8.h                                                   */
/*                                                                            */
/*!Scope           : Private                                                  */
/*                                                                            */
/*!Target          : PD70F3375                                                */
/*                                                                            */
/*!Vendor          : m8x (VALEO Climate Control China)                        */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2013 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/CRC8.h-arc  $            
 * 
 *    Rev 1.1   Dec 18 2017 15:24:24   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.0   Feb 08 2017 09:52:32   chunping.yan
 * Initial revision.
 * 
 *    Rev 1.0   Jun 23 2016 18:19:28   chunping.yan
 * Initial revision.
 * 
 *    Rev 1.1   Mar 24 2016 15:34:02   chunping.yan
 * ok
 * 
 *    Rev 1.0   Jan 07 2016 08:23:38   Jiaoyan.Luo
 * Initial revision.

******************************************************************************/
#ifndef CRC8_H
#define CRC8_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

/* 2017.08.28 LYX: change from u8Len to u32Len for support more data */
extern uint8 Crc8_u8Calculate(uint8 u8Data[], uint32 u32Len);
/* 2017.08.28 LYX: change from u8Len to u32Len for support more data */
extern uint8 Crc8_CalXor(uint8 u8Data[], uint32 u32Len);

/******************************************************************************/

#endif/* CRC8_H */



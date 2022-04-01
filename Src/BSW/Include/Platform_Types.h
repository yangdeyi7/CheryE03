/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2014 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Platform_Types.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  Provision of Platform Types for NXP FS32K144
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *      
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Sebastian Schmar              Ssr           Vector Informatik GmbH
 *  Timo Vanoni                   Tvi           Vector Informatik GmbH
 *  Cengiz Uenver                 Uce           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-09  Jk                    Initial creation
 *  01.00.01  2007-11-20  Jk                    Defines for CFG management added
 *  01.00.02  2007-11-27  Jk                    Defines for CFG management adapted
 *  02.00.00  2008-01-28  Jk                    adaaption for AUTOSAR 3.0
 *  02.00.01  2008-03-31  Ssr                   Change xint32 from int to long
 *  02.01.00  2010-01-11  Tvi                   ESCAN00039480: An compiler error occurs if the GHS '-fnone' compiler option is used
 *  02.02.00  2011-05-24  Tvi                   adaption for AUTSOAR 4.0
 *  02.03.00  2014-02-27  Uce                   Update to Template 01.03.02  
 *********************************************************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* AUTOSAR Software Specification Document Version Information */ 

#ifndef TRUE
   #define TRUE   1u
#endif

#ifndef FALSE
   #define FALSE  0u
#endif

#ifndef NULL_PTR
   #define NULL_PTR  ((void *)0)
#endif
                      
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
     
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned char         boolean;       /*        TRUE .. FALSE           */

typedef signed char           sint8;         /*        -128 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32768 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed long           sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long         uint32;        /*           0 .. 4294967295      */


typedef unsigned char         __u8;         /*           0 .. 255             */

typedef unsigned short        __u16;        /*           0 .. 65535           */

typedef unsigned long         __u32;        /*           0 .. 4294967295      */



typedef signed long            sint8_least;   /* At least 7 bit + 1 bit sign    */
typedef unsigned long          uint8_least;   /* At least 8 bit                 */
typedef signed long            sint16_least;  /* At least 15 bit + 1 bit sign   */
typedef unsigned long          uint16_least;  /* At least 16 bit                */
typedef signed long            sint32_least;  /* At least 31 bit + 1 bit sign   */
typedef unsigned long          uint32_least;  /* At least 32 bit                */

typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
                              
#if defined (__NoFloat) || defined (__NoFloat__)
/* 
   if option -fnone is used, floats are deactivated and -D__NoFloat (V4.x.x) or -D__NoFloat__ (V5.x.x) is passed 
   automatically. This violates PLATFORM041 and PLATFORM042. Thus this is an extension to AUTOSAR. 
 */ 
#else
typedef float                 float32;
typedef double                float64;
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PLATFORM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Platform_Types.h
 *********************************************************************************************************************/

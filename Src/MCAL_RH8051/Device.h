//============================================================================
// PROJECT  :  StartUp project
//============================================================================
//                           C O P Y R I G H T
//============================================================================
// Copyright (c) 2013 by Renesas Electronics  GmbH. All rights reserved.
// Arcadiastr.10
// D-40472 Duesseldorf
// Germany
//============================================================================
//
// Warranty Disclaimer :
// Because the Product(s) is licensed free of charge, there is no warranty of
// any kind whatsoever and expressly disclaimed and excluded by NEC, either
// expressed or implied, including but not limited to those for non-
// infringement of intellectual property, merchantability and/or fitness for
// the particular purpose. NEC shall not have any obligation to maintain,
// service or provide bug fixes for the supplied Product(s) and/or the
// Application.
//
// Each User is solely responsible for determining the appropriateness of
// using the Product(s) and assumes all risks associated with its exercise
// of rights under this Agreement, including, but not limited to the risks
// and costs of program errors, compliance with applicable laws, damage to
// or loss of data, programs or equipment, and unavailability or
// interruption of operations.
//
// Limitation of Liability :
// In no event shall NEC be liable to the User for any incidental,
// consequential, indirect, or punitive damage (including but not limited to
// lost profits) regardless of whether such liability is based on breach of
// contract, tort, strict liability, breach of warranties, failure of
// essential purpose or otherwise and even if advised of the possibility of
// such damages. NEC shall not be liable for any services or products provided
// by third party vendors, developers or consultants identified or referred
// to the User by NEC in connection with the Product(s) and/or the
// Application.
//
//============================================================================
//
// Device specific main header file to be included in all source files.
//
//============================================================================

#ifndef   DEVICE_H
#define   DEVICE_H

//================================================================================================
// Global compiler definition
//================================================================================================*/
#define COMP_GHS     1
#define COMP_IAR     2

#if defined (__IAR_SYSTEMS_ASM__)
    #define COMPILER COMP_IAR
#elif defined (__IAR_SYSTEMS_ICC__)
    #define COMPILER COMP_IAR
#else /*GHS */
    #define COMPILER COMP_GHS
#endif

//============================================================================
// Includes
//============================================================================
#if COMPILER == COMP_GHS
  #include "dr7f701684.dvf.h"
  //#include "dr7f701684_0.h"
#endif

#if COMPILER == COMP_IAR
  //#include <ior7f701684xafp.h> lsy del
  //#include <intrinsics.h>      lsy del
#endif

//============================================================================
// Defines
//============================================================================
#define protected_write(preg,pstatus,reg,value)   do{\
                                                  (preg)=0xa5u;\
                                                  (reg)=(value);\
                                                  (reg)=~(value);\
                                                  (reg)=(value);\
                                                  }while((pstatus)==1u)

#define ProtectedWriteReg(preg,reg,value)      \
{                                              \
    preg =  0x000000A5UL;                      \
    reg  =  value;                             \
    reg  = ~value;                             \
    reg  =  value;                             \
}

//#define	NOP()	__asm("nop")

#if COMPILER == COMP_IAR
  #define u16_T unsigned short __no_bit_access 
  #define __EI() __enable_interrupt()
  #define __DI() __disable_interrupt()
#endif

#endif  /* DEVICE_H */

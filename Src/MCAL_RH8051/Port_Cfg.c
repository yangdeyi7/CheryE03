/******************************************************************************/
/* PROJECT  :    CHJ_D01                                                      */
/******************************************************************************/
/* !Layer           : Port                                                    */
/*                                                                            */
/* !Component       : Port                                                    */
/* !Description     : Configure Port Function Management                      */
/*                                                                            */
/* !Module          : Port                                                    */
/* !Description     : Port                                                    */
/*                                                                            */
/* !File            : Port_Cfg.c                                              */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Device.h"
#include "Std_Types.h"
#include "Port_Cfg.h"

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
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
const Port_tstrPReg  Port_astrPortList[]=
{
  {
  	(volatile uint16*)&PORTP0,
    (volatile uint16*)&PORTPNOT0,
    (volatile uint16*)&PORTPM0,
    (volatile uint16*)&PORTPMC0,
    (volatile uint16*)&PORTPFC0,
    (volatile uint16*)&PORTPFCE0,
    (volatile uint16*)&PORTPFCAE0,
    (volatile uint16*)&PORTPIPC0,
    (volatile uint16*)&PORTPIBC0,
    (volatile uint16*)&PORTPPR0,
    (volatile uint16*)&PORTPD0,
    (volatile uint16*)&PORTPU0,
    (volatile uint32*)&PORTPODC0,
    (volatile uint32*)&PORTPDSC0,
    (volatile uint32*)&PORTPPROTS0,
    (volatile uint32*)&PORTPPCMD0
  },
  {
    (volatile uint16*)&PORTP8,
	(volatile uint16*)&PORTPNOT8,
	(volatile uint16*)&PORTPM8,
	(volatile uint16*)&PORTPMC8,
	(volatile uint16*)&PORTPFC8,
	(volatile uint16*)&PORTPFCE8,
	0,
	0,
	(volatile uint16*)&PORTPIBC8,
	(volatile uint16*)&PORTPPR8,
	(volatile uint16*)&PORTPD8,
	(volatile uint16*)&PORTPU8,
	(volatile uint32*)&PORTPODC8,
	0,
	(volatile uint32*)&PORTPPROTS8,
	(volatile uint32*)&PORTPPCMD8
  },
  {
    (volatile uint16*)&PORTP9,
	(volatile uint16*)&PORTPNOT9,
	(volatile uint16*)&PORTPM9,
	(volatile uint16*)&PORTPMC9,
	(volatile uint16*)&PORTPFC9,
	(volatile uint16*)&PORTPFCE9,
	(volatile uint16*)&PORTPMC9,
	0,
	(volatile uint16*)&PORTPIBC9,
	(volatile uint16*)&PORTPPR9,
	(volatile uint16*)&PORTPD9,
	(volatile uint16*)&PORTPU9,
	(volatile uint32*)&PORTPODC9,
	0,
	(volatile uint32*)&PORTPPROTS9,
	(volatile uint32*)&PORTPPCMD9
  },
  {
    (volatile uint16*)&PORTP10,
	(volatile uint16*)&PORTPNOT10,
	(volatile uint16*)&PORTPM10,
	(volatile uint16*)&PORTPMC10,
	(volatile uint16*)&PORTPFC10,
	(volatile uint16*)&PORTPFCE10,
	(volatile uint16*)&PORTPFCAE10,
	(volatile uint16*)&PORTPIPC10,
	(volatile uint16*)&PORTPIBC10,
	(volatile uint16*)&PORTPPR10,
	(volatile uint16*)&PORTPD10,
	(volatile uint16*)&PORTPU10,
	(volatile uint32*)&PORTPODC10,
	(volatile uint32*)&PORTPDSC10,
	(volatile uint32*)&PORTPPROTS10,
	(volatile uint32*)&PORTPPCMD10
  },
  {
    (volatile uint16*)&PORTP11,
	(volatile uint16*)&PORTPNOT11,
	(volatile uint16*)&PORTPM11,
	(volatile uint16*)&PORTPMC11,
	(volatile uint16*)&PORTPFC11,
	(volatile uint16*)&PORTPFCE11,
	(volatile uint16*)&PORTPFCAE11,
	(volatile uint16*)&PORTPIPC11,
	(volatile uint16*)&PORTPIBC11,
	(volatile uint16*)&PORTPPR11,
	(volatile uint16*)&PORTPD11,
	(volatile uint16*)&PORTPU11,
	(volatile uint32*)&PORTPODC11,
	(volatile uint32*)&PORTPDSC11,
	(volatile uint32*)&PORTPPROTS11,
	(volatile uint32*)&PORTPPCMD11
  },
  {
    (volatile uint16*)&PORTAP0,
	(volatile uint16*)&PORTAPNOT0,
	(volatile uint16*)&PORTAPM0,
	0,
	0,
	0,
	0,
	0,
	(volatile uint16*)&PORTAPIBC0,
	(volatile uint16*)&PORTAPPR0,
	0,
	0,
	0,
	0,
	0,
	0
  }
};
/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE FUNCTIONS PROTOTYPES                                               */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/


/** \} */ /* end of Port_Cfg module group */
/** \} */ /* end of MCAL Port_Cfg Component */

/*-------------------------------- end of file -------------------------------*/

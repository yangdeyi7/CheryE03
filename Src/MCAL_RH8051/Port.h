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
/* !File            : Port.h                                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : RH850F1K_S1_R7F7016843                                  */
/*                                                                            */
/* !Vendor          : (VALEO Climate Control China)                           */
/*                                                                            */
/* Coding language  : C                                                       */
/******************************************************************************/
#ifndef PORT_H
#define PORT_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef enum 
{
    Port_0 = 0u,
    Port_8,
    Port_9,
    Port_10,
    Port_11,
    Port_AP0
}Port_tenuPortGroupId;

typedef enum 
{
    Port_Input = 0u,
    Port_Output
}Port_tenuPortDir;

typedef enum 
{
    Port_Alt1 = 0u,
    Port_Alt2,
    Port_Alt3,
    Port_Alt4,
    Port_Alt5,
    Port_Alt6,
    Port_Alt7
}Port_tenuPortAltFunc;

typedef struct
{
	Port_tenuPortGroupId     enuGroupPortId;
    uint8                    u8PinNo;	
}Port_tstrPortCfgType;


typedef struct 
{
    volatile uint16* pu16P_Reg;
    volatile uint16* pu16PNOT_Reg;
    volatile uint16* pu16PM_Reg;
    volatile uint16* pu16PMC_Reg;
    volatile uint16* pu16PFC_Reg;
    volatile uint16* pu16PFCE_Reg;
    volatile uint16* pu16PFCAE_Reg;
    volatile uint16* pu16PIPC_Reg;
    volatile uint16* pu16PIBC_Reg;
    volatile const uint16* pku16PPR_Reg;
    volatile uint16* pu16PD_Reg;
    volatile uint16* pu16PU_Reg;
    volatile uint32* pu16PODC_Reg;
    volatile uint32* pu16PDSC_Reg;
    volatile uint32* pu16PPROTS_Reg;
    volatile uint32* pu16PPCMD_Reg;
}Port_tstrPReg;

/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
extern void Port_vidSetGpioOutput(const Port_tstrPortCfgType strPortCfgType);

extern void Port_vidSetGpioOutputLevel(const Port_tstrPortCfgType strPortCfgType,
	                               uint8  u8Level);
extern void Port_vidSetGpioInput(const Port_tstrPortCfgType strPortCfgType);

extern uint8 Port_u8GetPinLevel(const Port_tstrPortCfgType strPortCfgType);

extern void Port_vidSetAltFunc(const Port_tstrPortCfgType strPortCfgType,
			                   Port_tenuPortAltFunc  enuPortAltFunc,
			                   Port_tenuPortDir enuPortDir);
#endif

/** \} */ /* end of Port module group */
/** \} */ /* end of MCAL Port Component */

/*-------------------------------- end of file -------------------------------*/



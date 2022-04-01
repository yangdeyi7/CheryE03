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
/* !File            : Port.c                                                  */
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
#include "Std_Types.h"
#include "Port.h"
//#include "Port_Cfg.h"


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
/*****************************************************************************
** Function:    Port_vidSetGpioOutput
** Description: Set Port_Pin to GPIO Output. Initial output level is low.
** Parameter:   strPortCfgType: Portgroup and Pin Num
** Return:      None
******************************************************************************/
void Port_vidSetGpioOutput(const Port_tstrPortCfgType strPortCfgType)
{
   // *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PM_Reg   &= ~(1u << strPortCfgType.u8PinNo);
   // *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PMC_Reg  &= ~(1u << strPortCfgType.u8PinNo);
}

/*****************************************************************************
** Function:    Port_vidSetGpioOutputLevel
** Description: Set Port_Pin to GPIO Output. Initial output level is low.
** Parameter:   strPortCfgType: Portgroup and Pin Num
**              u8Level: Output level High or Low
** Return:      None
******************************************************************************/
void Port_vidSetGpioOutputLevel(const Port_tstrPortCfgType strPortCfgType, uint8 u8Level)
{
//    Port_vidSetGpioOutput(strPortCfgType);
//    if(STD_LOW == u8Level)
//    {
//        *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16P_Reg &= ~(1u << strPortCfgType.u8PinNo);
//    }
//    else 
//    {
//        *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16P_Reg |=  (1u << strPortCfgType.u8PinNo);
//    }
}

/*****************************************************************************
** Function:    Port_vidSetGpioInput
** Description: Set Port_Pin to GPIO Input with Port Input Buffer enabled.
** Parameter:   strPortCfgType: Portgroup and Pin Num
** Return:      None
******************************************************************************/
void Port_vidSetGpioInput(const Port_tstrPortCfgType strPortCfgType)
{
//    *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PM_Reg   |=  (1u << strPortCfgType.u8PinNo);
//    *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PIBC_Reg |=  (1u << strPortCfgType.u8PinNo);
//    *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PMC_Reg  &= ~(1u << strPortCfgType.u8PinNo);
}

/*****************************************************************************
** Function:    Port_bGetPinLevel
** Description: Gets the state of a Pin.
**strPortCfgType: Portgroup and Pin Num
** Return:      0 - Pin is low
**              1 - Pin is high
******************************************************************************/
uint8 Port_u8GetPinLevel(const Port_tstrPortCfgType strPortCfgType)
{
    uint16 u16PortLevel;
    uint8  u8PinLevel;
//    
//    u16PortLevel  = *Port_astrPortList[strPortCfgType.enuGroupPortId].pku16PPR_Reg;
//    u16PortLevel &= (1u << strPortCfgType.u8PinNo);
//    
//    if(u16PortLevel == 0u)
//    {
//        u8PinLevel =  0u;
//    }
//    else
//    {
//        u8PinLevel =  1u;
//    }
    return u8PinLevel;
}
/*****************************************************************************
** Function:    Port_vidSetAltFunc
** Description: Configures Port_Pin to the chosen alternative function.
** strPortCfgType: Portgroup and Pin Num
** enuPortAltFunc: Alternative Function (Alt1-Alt7)
** enuPortDir: Input/Output direction
** Return:      None
******************************************************************************/
void Port_vidSetAltFunc(const Port_tstrPortCfgType strPortCfgType,
			                    Port_tenuPortAltFunc  enuPortAltFunc,
			                    Port_tenuPortDir enuPortDir)
{   
//    switch(enuPortAltFunc)
//    {
//        case Port_Alt1:
//		{
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCAE_Reg &= ~(1u << strPortCfgType.u8PinNo); 
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCE_Reg  &= ~(1u << strPortCfgType.u8PinNo);  
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFC_Reg   &= ~(1u << strPortCfgType.u8PinNo);
//		}
//        break;
//        
//        case Port_Alt2:
//		{
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCAE_Reg &= ~(1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCE_Reg  &= ~(1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFC_Reg   |=  (1u << strPortCfgType.u8PinNo);
//		}
//        break;
//        
//        case Port_Alt3:
//		{
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCAE_Reg &= ~(1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCE_Reg  |=  (1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFC_Reg   &= ~(1u << strPortCfgType.u8PinNo);
//		}
//        break;
//        
//        case Port_Alt4:
//		{
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCAE_Reg &= ~(1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCE_Reg  |=  (1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFC_Reg   |=  (1u << strPortCfgType.u8PinNo);
//		}
//        break;
//        
//        case Port_Alt5:
//		{
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCAE_Reg |=  (1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCE_Reg  &= ~(1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFC_Reg   &= ~(1u << strPortCfgType.u8PinNo);
//		}
//        break;
//        
//        case Port_Alt6:
//		{
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCAE_Reg |=  (1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCE_Reg  &= ~(1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFC_Reg   |=  (1u << strPortCfgType.u8PinNo);
//		}
//        break;
//        
//        case Port_Alt7:
//		{
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCAE_Reg |=  (1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFCE_Reg  |=  (1u << strPortCfgType.u8PinNo);
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PFC_Reg   &= ~(1u << strPortCfgType.u8PinNo);
//		}
//        break;
//        
//        default:
//        break;
//    }
//    
//    switch(enuPortDir)
//    {
//        case Port_Input:
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PM_Reg |=  (1u << strPortCfgType.u8PinNo);
//        break;
//        
//        case Port_Output:
//            *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PM_Reg &= ~(1u << strPortCfgType.u8PinNo);
//        break;
//        
//        default:
//        break;
//        
//    }
//    
//    *Port_astrPortList[strPortCfgType.enuGroupPortId].pu16PMC_Reg |= (1u << strPortCfgType.u8PinNo);
}

/** \} */ /* end of Port module group */
/** \} */ /* end of MCAL Port Component */

/*-------------------------------- end of file -------------------------------*/

/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**
**     @file      lin_cfg.c
**
**     @date      11:04:42, 2021-12-21
**
**     @brief     Hardware configuration file
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016 - 2017 NXP
**     All Rights Reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/

/*!
 * @file lin_cfg.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, Could be made static.
 * Function ld_read_by_id_callout is API and shall not be made static.
 * This API is declared in lin_cfg.c so that users can configure the response
 * for  Read by ID request.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block
 * scope if its identifier only appears in a single function.
 * An object with static storage duration declared at block scope cannot be
 * accessed directly from outside the block. g_lin_hardware_ifc, g_lin_tl_descriptor_array,
 * timerGetTimeIntervalCallback are dependent on user configurations,
 * so they shall be declared in lin_cfg.c.
 */

#include "lin.h"


#if (SUPPORT_TRANSPORT_LAYER == 1U)
static lin_tl_pdu_data_t      LI0_tl_tx_queue_data[2];
static lin_tl_pdu_data_t      LI0_tl_rx_queue_data[2];
#endif /* end (SUPPORT_TRANSPORT_LAYER == 1U) */

const l_ifc_handle g_lin_hardware_ifc[HARDWARE_INSTANCE_COUNT] = {INVALID_IFC, INVALID_IFC, LI0};
const l_u32 g_lin_virtual_ifc[LIN_NUM_OF_IFCS] = {2};
volatile l_u8 g_buffer_backup_data[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/* definition and initialization of signal array */
volatile l_u8    g_lin_frame_data_buffer[LIN_FRAME_BUF_SIZE] =
{
  0x00 /* 0 : 00000000 */ /* start of frame LI0_HVWH_SET_1 */

  ,0x01 /* 1 : 00000001 */

  ,0x00 /* 2 : 00000000 */ /* start of frame LI0_HVWH_SET_2 */

  ,0x00 /* 3 : 00000000 */

  ,0x00 /* 4 : 00000000 */

  ,0x00 /* 5 : 00000000 */

  ,0x00 /* 6 : 00000000 */

  ,0x00 /* 7 : 00000000 */

  ,0x00 /* 8 : 00000000 */

  ,0x00 /* 9 : 00000000 */

  ,0x00 /* 10 : 00000000 */ /* start of frame LI0_HVWH_LIN_STATUS1 */

  ,0x00 /* 11 : 00000000 */

  ,0x00 /* 12 : 00000000 */

  ,0x00 /* 13 : 00000000 */

  ,0x00 /* 14 : 00000000 */

  ,0x00 /* 15 : 00000000 */

  ,0x00 /* 16 : 00000000 */

  ,0x00 /* 17 : 00000000 */

  ,0xff /* 18 : 11111111 */ /* start of frame LI0_EAC_Cmd */

  ,0xff /* 19 : 11111111 */

  ,0xff /* 20 : 11111111 */

  ,0xff /* 21 : 11111111 */ /* start of frame LI0_EAC_Status */

  ,0xff /* 22 : 11111111 */

  ,0xff /* 23 : 11111111 */

  ,0xff /* 24 : 11111111 */

  ,0xff /* 25 : 11111111 */

  ,0xff /* 26 : 11111111 */

  ,0xff /* 27 : 11111111 */

  ,0xff /* 28 : 11111111 */

  ,0x00 /* 29 : 00000000 */ /* start of frame LI0_BLW_Cmd */

  ,0xf0 /* 30 : 11110000 */

  ,0xff /* 31 : 11111111 */

  ,0xff /* 32 : 11111111 */

  ,0x80 /* 33 : 10000000 */

  ,0x01 /* 34 : 00000001 */

  ,0xaa /* 35 : 10101010 */

  ,0xff /* 36 : 11111111 */

  ,0x00 /* 37 : 00000000 */ /* start of frame LI0_BLW_Status1 */

  ,0x00 /* 38 : 00000000 */

  ,0x00 /* 39 : 00000000 */

  ,0x00 /* 40 : 00000000 */

  ,0x00 /* 41 : 00000000 */

  ,0x00 /* 42 : 00000000 */

  ,0x00 /* 43 : 00000000 */

  ,0x00 /* 44 : 00000000 */

  ,0xfe /* 45 : 11111110 */ /* start of frame LI0_BLW_Status2 */

  ,0xff /* 46 : 11111111 */

  ,0xff /* 47 : 11111111 */

  ,0xff /* 48 : 11111111 */

  ,0xff /* 49 : 11111111 */

  ,0xff /* 50 : 11111111 */

  ,0xff /* 51 : 11111111 */

  ,0xff /* 52 : 11111111 */

  ,0x00 /* 53 : 00000000 */ /* start of frame LI0_EXV_CHILLER_Cmd */

  ,0x00 /* 54 : 00000000 */

  ,0x00 /* 55 : 00000000 */

  ,0x00 /* 56 : 00000000 */

  ,0x00 /* 57 : 00000000 */ /* start of frame LI0_EXV_CHILLER_Status */

  ,0x00 /* 58 : 00000000 */

  ,0xf0 /* 59 : 11110000 */

  ,0x00 /* 60 : 00000000 */

  ,0x00 /* 61 : 00000000 */

  ,0x00 /* 62 : 00000000 */

  ,0x00 /* 63 : 00000000 */

  ,0x00 /* 64 : 00000000 */

  ,0x00 /* 65 : 00000000 */ /* start of frame LI0_EXV_EVAP_Cmd */

  ,0x00 /* 66 : 00000000 */

  ,0x00 /* 67 : 00000000 */

  ,0x00 /* 68 : 00000000 */

  ,0x00 /* 69 : 00000000 */ /* start of frame LI0_EXV_EVAP_Status */

  ,0x00 /* 70 : 00000000 */

  ,0xf0 /* 71 : 11110000 */

  ,0x00 /* 72 : 00000000 */

  ,0x00 /* 73 : 00000000 */

  ,0x00 /* 74 : 00000000 */

  ,0x00 /* 75 : 00000000 */

  ,0x00 /* 76 : 00000000 */

  ,0xff /* 77 : 11111111 */ /* start of frame LI0_TWV_HVAC_Cmd */

  ,0xff /* 78 : 11111111 */

  ,0xff /* 79 : 11111111 */

  ,0x00 /* 80 : 00000000 */

  ,0xce /* 81 : 11001110 */

  ,0xff /* 82 : 11111111 */

  ,0xff /* 83 : 11111111 */

  ,0xff /* 84 : 11111111 */

  ,0x00 /* 85 : 00000000 */ /* start of frame LI0_TWV_HVAC_Status */

  ,0x00 /* 86 : 00000000 */

  ,0xff /* 87 : 11111111 */

  ,0xff /* 88 : 11111111 */

  ,0xff /* 89 : 11111111 */

  ,0xff /* 90 : 11111111 */

  ,0xff /* 91 : 11111111 */

  ,0xff /* 92 : 11111111 */

  ,0xff /* 93 : 11111111 */ /* start of frame LI0_TWV_BAT_Cmd */

  ,0xff /* 94 : 11111111 */

  ,0xff /* 95 : 11111111 */

  ,0x00 /* 96 : 00000000 */

  ,0xce /* 97 : 11001110 */

  ,0xff /* 98 : 11111111 */

  ,0xff /* 99 : 11111111 */

  ,0xff /* 100 : 11111111 */

  ,0x00 /* 101 : 00000000 */ /* start of frame LI0_TWV_BAT_Status */

  ,0x00 /* 102 : 00000000 */

  ,0xff /* 103 : 11111111 */

  ,0xff /* 104 : 11111111 */

  ,0xff /* 105 : 11111111 */

  ,0xff /* 106 : 11111111 */

  ,0xff /* 107 : 11111111 */

  ,0xff /* 108 : 11111111 */

  ,0xff /* 109 : 11111111 */ /* start of frame LI0_TWV_MOTOR_Cmd */

  ,0xff /* 110 : 11111111 */

  ,0xff /* 111 : 11111111 */

  ,0x00 /* 112 : 00000000 */

  ,0xce /* 113 : 11001110 */

  ,0xff /* 114 : 11111111 */

  ,0xff /* 115 : 11111111 */

  ,0xff /* 116 : 11111111 */

  ,0x00 /* 117 : 00000000 */ /* start of frame LI0_TWV_MOTOR_Status */

  ,0x00 /* 118 : 00000000 */

  ,0xff /* 119 : 11111111 */

  ,0xff /* 120 : 11111111 */

  ,0xff /* 121 : 11111111 */

  ,0xff /* 122 : 11111111 */

  ,0xff /* 123 : 11111111 */

  ,0xff /* 124 : 11111111 */

  ,0x00 /* 125 : 00000000 */ /* start of frame LI0_PUMP_HVAC_CTRL */

  ,0x00 /* 126 : 00000000 */

  ,0x00 /* 127 : 00000000 */

  ,0x00 /* 128 : 00000000 */

  ,0x00 /* 129 : 00000000 */

  ,0x00 /* 130 : 00000000 */

  ,0x00 /* 131 : 00000000 */

  ,0x00 /* 132 : 00000000 */

  ,0x00 /* 133 : 00000000 */ /* start of frame LI0_PUMP_HVAC_STATUS */

  ,0x00 /* 134 : 00000000 */

  ,0x00 /* 135 : 00000000 */

  ,0x00 /* 136 : 00000000 */

  ,0x00 /* 137 : 00000000 */

  ,0x00 /* 138 : 00000000 */

  ,0x00 /* 139 : 00000000 */

  ,0x00 /* 140 : 00000000 */

  ,0x00 /* 141 : 00000000 */ /* start of frame LI0_PUMP_BAT_CTRL */

  ,0x00 /* 142 : 00000000 */

  ,0x00 /* 143 : 00000000 */

  ,0x00 /* 144 : 00000000 */

  ,0x00 /* 145 : 00000000 */

  ,0x00 /* 146 : 00000000 */

  ,0x00 /* 147 : 00000000 */

  ,0x00 /* 148 : 00000000 */

  ,0x00 /* 149 : 00000000 */ /* start of frame LI0_PUMP_BAT_STATUS */

  ,0x00 /* 150 : 00000000 */

  ,0x00 /* 151 : 00000000 */

  ,0x00 /* 152 : 00000000 */

  ,0x00 /* 153 : 00000000 */

  ,0x00 /* 154 : 00000000 */

  ,0x00 /* 155 : 00000000 */

  ,0x00 /* 156 : 00000000 */

  ,0x00 /* 157 : 00000000 */ /* start of frame LI0_PUMP_MOTOR_CTRL */

  ,0x00 /* 158 : 00000000 */

  ,0x00 /* 159 : 00000000 */

  ,0x00 /* 160 : 00000000 */

  ,0x00 /* 161 : 00000000 */

  ,0x00 /* 162 : 00000000 */

  ,0x00 /* 163 : 00000000 */

  ,0x00 /* 164 : 00000000 */

  ,0x00 /* 165 : 00000000 */ /* start of frame LI0_PUMP_MOTOR_STATUS */

  ,0x00 /* 166 : 00000000 */

  ,0x00 /* 167 : 00000000 */

  ,0x00 /* 168 : 00000000 */

  ,0x00 /* 169 : 00000000 */

  ,0x00 /* 170 : 00000000 */

  ,0x00 /* 171 : 00000000 */

  ,0x00 /* 172 : 00000000 */
};

/* definition and initialization of signal array */
volatile l_u8    g_lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{
  0xFF /* 0: start of flag frame LI0_HVWH_SET_1 */

  ,0xFF /* 1: start of flag frame LI0_HVWH_SET_2 */

  ,0xFF /* 2: start of flag frame LI0_HVWH_LIN_STATUS1 */

  ,0xFF /* 3: */

  ,0xFF /* 4: start of flag frame LI0_EAC_Cmd */

  ,0xFF /* 5: start of flag frame LI0_EAC_Status */

  ,0xFF /* 6: */

  ,0xFF /* 7: */

  ,0xFF /* 8: start of flag frame LI0_BLW_Cmd */

  ,0xFF /* 9: start of flag frame LI0_BLW_Status1 */

  ,0xFF /* 10: */

  ,0xFF /* 11: start of flag frame LI0_BLW_Status2 */

  ,0xFF /* 12: start of flag frame LI0_EXV_CHILLER_Cmd */

  ,0xFF /* 13: start of flag frame LI0_EXV_CHILLER_Status */

  ,0xFF /* 14: */

  ,0xFF /* 15: start of flag frame LI0_EXV_EVAP_Cmd */

  ,0xFF /* 16: start of flag frame LI0_EXV_EVAP_Status */

  ,0xFF /* 17: */

  ,0xFF /* 18: start of flag frame LI0_TWV_HVAC_Cmd */

  ,0xFF /* 19: start of flag frame LI0_TWV_HVAC_Status */

  ,0xFF /* 20: */

  ,0xFF /* 21: start of flag frame LI0_TWV_BAT_Cmd */

  ,0xFF /* 22: start of flag frame LI0_TWV_BAT_Status */

  ,0xFF /* 23: */

  ,0xFF /* 24: start of flag frame LI0_TWV_MOTOR_Cmd */

  ,0xFF /* 25: start of flag frame LI0_TWV_MOTOR_Status */

  ,0xFF /* 26: */

  ,0xFF /* 27: start of flag frame LI0_PUMP_HVAC_CTRL */

  ,0xFF /* 28: */

  ,0xFF /* 29: start of flag frame LI0_PUMP_HVAC_STATUS */

  ,0xFF /* 30: */

  ,0xFF /* 31: start of flag frame LI0_PUMP_BAT_CTRL */

  ,0xFF /* 32: */

  ,0xFF /* 33: start of flag frame LI0_PUMP_BAT_STATUS */

  ,0xFF /* 34: */

  ,0xFF /* 35: start of flag frame LI0_PUMP_MOTOR_CTRL */

  ,0xFF /* 36: */

  ,0xFF /* 37: start of flag frame LI0_PUMP_MOTOR_STATUS */

  ,0xFF /* 38: */
};

/* definition and initialization for flag of frame */
volatile l_bool g_lin_frame_flag_handle_tbl[LIN_NUM_OF_FRMS] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

/*************************** Frame flag for updating signal in frame ****************/
volatile l_u8 g_lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



/*****************************sporadic frame*****************************/
/*all sporadic frames for master node*/
/**********************************  Frame table **********************************/
static const lin_frame_t lin_frame_tbl[LIN_NUM_OF_FRMS] ={

    { LIN_FRM_UNCD, 2, LIN_RES_PUB, 0, 0, 1   , (lin_associate_frame_t*)0 }

   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 2, 1, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 10, 2, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 3, LIN_RES_PUB, 18, 4, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 21, 5, 3 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 29, 8, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 37, 9, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 45, 11, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 4, LIN_RES_PUB, 53, 12, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 57, 13, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 4, LIN_RES_PUB, 65, 15, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 69, 16, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 77, 18, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 85, 19, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 93, 21, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 101, 22, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 109, 24, 1 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 117, 25, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 125, 27, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 133, 29, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 141, 31, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 149, 33, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_PUB, 157, 35, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_UNCD, 8, LIN_RES_SUB, 165, 37, 2 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (lin_associate_frame_t*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (lin_associate_frame_t*)0 }
  
};

static l_u8 LI0_lin_configuration_RAM[LI0_LIN_SIZE_OF_CFG]= {0x00, 0x04, 0x3B, 0x25, 0x1A, 0x1B, 0x0A, 0x0B, 0x0C, 0x06, 0x14, 0x08, 0x16, 0x22, 0x24, 0x27, 0x29, 0x2A, 0x2C, 0x11, 0x13, 0x15, 0x17, 0x1C, 0x1F, 0x3C, 0x3D ,0xFF};

static const l_u16  LI0_lin_configuration_ROM[LI0_LIN_SIZE_OF_CFG]= {0x0000, 0x04, 0x3B, 0x25, 0x1A, 0x1B, 0x0A, 0x0B, 0x0C, 0x06, 0x14, 0x08, 0x16, 0x22, 0x24, 0x27, 0x29, 0x2A, 0x2C, 0x11, 0x13, 0x15, 0x17, 0x1C, 0x1F, 0x3C, 0x3D ,0xFFFF};


/********************** Go to sleep Initialization *************************/
/* Delay of this schedule table is: (1.4*(34+10*(8+1))*1000/LIN_speed+jitter) ms */
/* then rounded up to a value is multiple of time base */
static const lin_schedule_data_t LI0_lin_gotosleep_data[1] = {
   {LI0_MasterReq, 2, {0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}
};


/******************** Schedule table Initialization ************************/
static const lin_schedule_data_t LI0_Sch_Normal_data[24] = {

   {LI0_HVWH_SET_1, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_HVWH_SET_2, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_HVWH_LIN_STATUS1, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_EAC_Cmd, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_EAC_Status, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_BLW_Cmd, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_BLW_Status1, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_BLW_Status2, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_EXV_CHILLER_Cmd, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_EXV_EVAP_Cmd, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_EXV_CHILLER_Status, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_EXV_EVAP_Status, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_TWV_HVAC_Cmd, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_TWV_BAT_Cmd, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_TWV_MOTOR_Cmd, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_TWV_HVAC_Status, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_TWV_BAT_Status, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_TWV_MOTOR_Status, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_PUMP_HVAC_CTRL, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_PUMP_BAT_CTRL, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_PUMP_MOTOR_CTRL, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_PUMP_HVAC_STATUS, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_PUMP_BAT_STATUS, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
   , {LI0_PUMP_MOTOR_STATUS, 2, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
};
/******************** Schedule table Initialization ************************/
static const lin_schedule_data_t LI0_DiagRequest_data[1] = {

   {LI0_MasterReq, 6, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
};
/******************** Schedule table Initialization ************************/
static const lin_schedule_data_t LI0_DiagResponse_data[1] = {

   {LI0_SlaveResp, 12, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
  
};


/********************* Schedule table structure Initialization ***************/
static const lin_schedule_t lin_schedule_tbl[LIN_NUM_OF_SCHD_TBL] ={

   /*interface_name = LI0 */
   {0, LIN_SCH_TBL_NULL  ,(lin_schedule_data_t*)0 }
  
   ,{1, LIN_SCH_TBL_GO_TO_SLEEP  , &LI0_lin_gotosleep_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI0_DiagRequest_data[0] }
  
   ,{1, LIN_SCH_TBL_DIAG  , &LI0_DiagResponse_data[0] }
  
   ,{24, LIN_SCH_TBL_NORM  , &LI0_Sch_Normal_data[0] }
  
};
/****************************LIN interface configuration ****************************/
const lin_protocol_user_config_t g_lin_protocol_user_cfg_array[LIN_NUM_OF_IFCS] = {

    /* Interface_name = LI0 */
    {
        .protocol_version = LIN_PROTOCOL_21,         /*lin_protocol_version */
        .language_version = LIN_PROTOCOL_21,         /*lin_language_version */
        .diagnostic_class = LIN_DIAGNOSTIC_CLASS_I,            /* LIN Diagnostic Class */
        .function = (bool)LIN_MASTER,                 /*  function LIN_MASTER*/

        .number_of_configurable_frames = 26,                            /*  num_of_frames */
        .frame_start = 0,                              /*  frame_start */
        .frame_tbl_ptr = lin_frame_tbl,                                          /*  frame_tbl */

        .list_identifiers_ROM_ptr = LI0_lin_configuration_ROM,       /*  *configuration_ROM */
        .list_identifiers_RAM_ptr = LI0_lin_configuration_RAM,       /*  *configuration_RAM */
        .max_idle_timeout_cnt =  10000,     /* Max Idle Timeout Count */
        .num_of_schedules = 5,                                  /*  num_of_schedules */
        .schedule_start = 0,                                  /*  schedule_start */
        .schedule_tbl = lin_schedule_tbl,             /* schedule_tbl */

        .slave_ifc_handle = INVALID_SLAVE_INDEX,
        .master_ifc_handle = LI0_Master,
        .lin_user_config_ptr = &lin1_InitConfig0,
#if (SUPPORT_TRANSPORT_LAYER == 1U)
        .tl_tx_queue_data_ptr = LI0_tl_tx_queue_data,
        .tl_rx_queue_data_ptr = LI0_tl_rx_queue_data,
        .max_message_length = 6             /* Max message length */
#endif /* end (SUPPORT_TRANSPORT_LAYER == 1U) */
    }
};

/*FUNCTION**********************************************************************
 *
 * Function Name : ld_read_by_id_callout
 * Description   : This function is an example of response; real implementation is application-dependent
 *                 You can use one of the following define to set PCI of response frame for
 *                 this service to the correct value
 * Implements    : ld_read_by_id_callout_Activity
 *END**************************************************************************/

l_u8 ld_read_by_id_callout(l_ifc_handle iii, l_u8 id, l_u8 *data)
{
    l_u8 retval = LD_NEGATIVE_RESPONSE;

    /* Get the current configuration */
    const lin_protocol_user_config_t  *prot_user_config_ptr = &g_lin_protocol_user_cfg_array[iii];

    if (prot_user_config_ptr->function == (bool)LIN_SLAVE)
    {
        /* Following code is an example - Real implementation is application-dependent */
        /* the handling does essentially depend on the id of the requested item */
        /* This example implement with ID = 32 - LIN_READ_USR_DEF_MIN */
        if (id == LIN_READ_USR_DEF_MIN)
        {
            /*
            * id received is user defined 32
            */
            /* A positive response is ready to be sent to the user defined request */
            data[0] = (l_u8) (id + 1U);    /* Data user define */
            data[1] = (l_u8) (id + 2U);    /* Data user define */
            data[2] = (l_u8) (id + 3U);    /* Data user define */
            data[3] = (l_u8) (id + 4U);    /* Data user define */
            data[4] = (l_u8) (id + 5U);    /* Data user define */
            retval = LD_POSITIVE_RESPONSE;
        }
        else
        {
            /*
            * id received is user defined 63 - no response
            */
        }
    } /* End (conf->function == _SLAVE_) */
   return retval;
}


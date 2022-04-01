/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined(CLOCK_H)
#define CLOCK_H

#include "device_registers.h"
#include "status.h"


/* S32K144 Clock System Level API header file */
#include "clock_S32K1xx.h"


/*!
 * @file clock.h
 */
 
/*! @addtogroup clock*/
/*! @{*/

/*******************************************************************************
 * Definitions
 ******************************************************************************/


#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Dynamic clock setting
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/
 
 /*!
 * @brief Gets the clock frequency for a specific clock name.
 *
 * This function checks the current clock configurations and then calculates
 * the clock frequency for a specific clock name defined in clock_names_t.
 * Clock modules must be properly configured before using this function. 
 * See features.h for supported clock names for different chip families.
 * The returned value is in Hertz. If it cannot find the clock name
 * or the name is not supported for a specific chip family, it returns an
 * STATUS_UNSUPPORTED. If frequency is required for a peripheral and the
 * module is not clocked, then STATUS_MCU_GATED_OFF status is returned.
 * Frequency is returned if a valid address is provided. If frequency is
 * required for a peripheral that doesn't support protocol clock, the zero 
 * value is provided.
 *
 * @param[in] clockName Clock names defined in clock_names_t
 * @param[out] frequency Returned clock frequency value in Hertz
 * @return status   Error code defined in status_t
 */
status_t CLOCK_DRV_GetFreq(clock_names_t clockName,
                           uint32_t *frequency);
                           

/*!
 * @brief Set clock configuration according to pre-defined structure.
 *
 * This function sets system to target clock configuration; It sets the
 * clock modules registers for clock mode change. 
 *
 * @param[in] config  Pointer to configuration structure.
 *
 * @return Error code.
 *
 * @note If external clock is used in the target mode, please make sure it is
 * enabled, for example, if the external oscillator is used, please setup correctly.
 *
 * @note If the configuration structure is NULL, the function will set a default
 * configuration for clock.
 */
status_t CLOCK_DRV_Init(clock_user_config_t const * config);

/*! @} */


#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/


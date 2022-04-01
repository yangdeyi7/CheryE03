#include "flash_driver.h"
#include "status.h"
#include "FlexNVM.h"
#include "Flash.h"

/* Declare a FLASH config struct which initialized by FlashInit, and will be used by all flash operations */
flash_ssd_config_t flashSSDConfig;

uint8 FNVM_u8GetDepart(void)
{
    uint8 DEPartitionCode;    /* store D/E-Flash Partition Code */

    /* Get DEPART from Flash Configuration Register 1 */
    DEPartitionCode = (uint8)((SIM->FCFG1 & SIM_FCFG1_DEPART_MASK) >> SIM_FCFG1_DEPART_SHIFT);

	return DEPartitionCode;
}

uint8 FNVM_udtCfgEEP(void)
{
    status_t ret;        /* Store the driver APIs return code */
    flash_eeprom_status_t flash_eeprom_status;
    uint8  udtRet;


	/* Always initialize the driver before calling other functions */
	ret = FLASH_DRV_Init(&Flash_InitConfig0, &flashSSDConfig);
    DEV_ASSERT(STATUS_SUCCESS == ret);

	/* Config FlexRAM as EEPROM if it is currently used as traditional RAM */
    if (flashSSDConfig.EEESize == 0u)
    {

        /* Configure FlexRAM as EEPROM and FlexNVM as EEPROM backup region,
         * DEFlashPartition will be failed if the IFR region isn't blank.
         * Refer to the device document for valid EEPROM Data Size Code
         * and FlexNVM Partition Code. For example on S32K144:
         * - EEEDataSizeCode = 0x02u: EEPROM size = 4 Kbytes
         * - DEPartitionCode = 0x08u: EEPROM backup size = 64 Kbytes */
        ret = FLASH_DRV_DEFlashPartition(&flashSSDConfig, u8EEEDATASIZECODE,
        	u8DEPARATITIONCODE, 0x0u, false, true);

        if (STATUS_SUCCESS == ret)
        {
        	/* Re-initialize the driver to update the new EEPROM configuration */
        	ret = FLASH_DRV_Init(&Flash_InitConfig0, &flashSSDConfig);
        }

        if (STATUS_SUCCESS == ret)
        {
        	/* Make FlexRAM available for EEPROM */
        	ret = FLASH_DRV_SetFlexRamFunction(&flashSSDConfig, EEE_ENABLE, 0x00u, &flash_eeprom_status);
        }
        /* DEV_ASSERT(STATUS_SUCCESS == ret); */
    }
    else    /* FLexRAM is already configured as EEPROM */
    {
        /* Make FlexRAM available for EEPROM, make sure that FlexNVM and FlexRAM
         * are already partitioned successfully before */
        ret = FLASH_DRV_SetFlexRamFunction(&flashSSDConfig, EEE_ENABLE, 0x00u, &flash_eeprom_status);
        /* DEV_ASSERT(STATUS_SUCCESS == ret); */
    }

    if (STATUS_SUCCESS == ret)
    {
    	udtRet = FNVM_FULL_OK;
    }
    else
    {
    	udtRet = E_NOT_OK;
    }
    return udtRet;
}

uint8 FNVM_udtWriteEEP(uint32 u32Address, uint8 *pu8Data, uint32 u32Length,uint32 *pu32LenWriten)
{
    uint32 u32LenWriten;
    uint32 u32LenLimit;
	uint8  udtRet;
    status_t ret;        /* Store the driver APIs return code */

    if (flashSSDConfig.EEESize > u32Address)
    {
    	u32LenLimit = flashSSDConfig.EEESize - u32Address;
    	if (u32LenLimit > u32Length)
    	{
    		u32LenLimit = u32Length;
    	}
    	else
    	{
    		;
    	}
    }
    else
    {
		u32LenLimit = 0u;
    }

    /* Try to write data to EEPROM if FlexRAM is configured as EEPROM */
    if ((flashSSDConfig.EEESize != 0u) && (0u != u32LenLimit))
    {
        ret = FLASH_DRV_EEEWrite(&flashSSDConfig,
        	flashSSDConfig.EERAMBase + u32Address, u32LenLimit, pu8Data);
        if (STATUS_SUCCESS == ret)
        {
        	u32LenWriten = u32LenLimit;
        }
        else
        {
        	u32LenWriten = 0u;
        }
    }
    else
    {
    	u32LenWriten = 0u;
    	udtRet = E_NOT_OK;
    }

    if (NULL_PTR != pu32LenWriten)
    {
    	*pu32LenWriten = u32LenWriten;
    }
    else
    {
    	;
    }

    if (u32LenWriten == u32Length)
    {
    	udtRet = FNVM_FULL_OK;
    }
    else if (0u != u32LenWriten)
    {
    	udtRet = FNVM_PART_OK;
    }
    else
    {
    	udtRet = FNVM_ERROR;
    }
    return udtRet;
}

uint8 FNVM_udtReadEEP(uint32 u32Address, uint8 *pu8Data, uint32 u32Length,uint32 *pu32LenRead)
{
    uint32 u32LenRead;
    uint32 u32LenLimit;
	uint8  udtRet;
    uint8  *pu8EEPAddr;
    uint32 u32Ind;

    if (flashSSDConfig.EEESize > u32Address)
    {
    	u32LenLimit = flashSSDConfig.EEESize - u32Address;
    	if (u32LenLimit > u32Length)
    	{
    		u32LenLimit = u32Length;
    	}
    	else
    	{
    		;
    	}
    }
    else
    {
		u32LenLimit = 0u;
    }

    /* Try to write data to EEPROM if FlexRAM is configured as EEPROM */
    if ((flashSSDConfig.EEESize != 0u) && (0u != u32LenLimit))
    {
    	pu8EEPAddr = (uint8 *)(flashSSDConfig.EERAMBase + u32Address);
    	for (u32Ind = 0u; u32Ind < u32LenLimit; u32Ind++)
    	{
    		pu8Data[u32Ind] = pu8EEPAddr[u32Ind];
    	}
    	u32LenRead = u32Ind;
    }
    else
    {
    	u32LenRead = 0u;
    }

    if (NULL_PTR != pu32LenRead)
    {
    	*pu32LenRead = u32LenRead;
    }
    else
    {
    	;
    }

    if (u32LenRead == u32Length)
    {
    	udtRet = FNVM_FULL_OK;
    }
    else if (0u != u32LenRead)
    {
    	udtRet = FNVM_PART_OK;
    }
    else
    {
    	udtRet = FNVM_ERROR;
    }
    return udtRet;
}

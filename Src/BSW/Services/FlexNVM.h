
#ifndef FLEXNVM_H
#define FLEXNVM_H

#include "Std_Types.h"

/* Configure FlexRAM as EEPROM and FlexNVM as EEPROM backup region,
 * DEFlashPartition will be failed if the IFR region isn't blank.
 * Refer to the device document for valid EEPROM Data Size Code
 * and FlexNVM Partition Code. For example on S32K144:
 * - EEEDataSizeCode = 0x02u: EEPROM size = 4 Kbytes
 * - DEPartitionCode = 0x08u: EEPROM backup size = 64 Kbytes */
#define u8EEEDATASIZECODE  (0x02u)
#define u8DEPARATITIONCODE (0x08u)

#define FNVM_FULL_OK   0x00u
#define FNVM_PART_OK   0x01u
#define FNVM_ERROR     0x80u

uint8 FNVM_u8GetDepart(void);

uint8 FNVM_udtCfgEEP(void);

/* DESCRIPTION write data to Flex EEP
 * INPUT u32Address, range is 0 ~ (EEESize - 1)
 * INPUT *pu8Data, data to be write
 * INPUT u32Length, data length, u32Address + u32Length <= EEESize
 * OUTPUT *pu32LenWriten, for return write data length, if no need return can be NULL
 * RETURN status, FNVM_FULL_OK, FNVM_PART_OK or FNVM_ERROR */
uint8 FNVM_udtWriteEEP(uint32 u32Address, uint8 *pu8Data, uint32 u32Length,
	uint32 *pu32LenWriten);

/* DESCRIPTION read data from Flex EEP
 * INPUT u32Address, range is 0 ~ (EEESize - 1)
 * INPUT *pu8Data, data to be read
 * INPUT u32Length, data length, u32Address + u32Length <= EEESize
 * OUTPUT *pu32LenRead, for return read data length, if no need return can be NULL
 * RETURN status, FNVM_FULL_OK, FNVM_PART_OK or FNVM_ERROR */
uint8 FNVM_udtReadEEP(uint32 u32Address, uint8 *pu8Data, uint32 u32Length,
	uint32 *pu32LenRead);

#endif /* FLEXNVM_H */

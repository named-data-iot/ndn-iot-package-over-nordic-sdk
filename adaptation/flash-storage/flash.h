/*
 * Copyright (C) 2019 Tianyuan Yu
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

 #include <stdint.h>
 #include "../adaptation-enums.h"
 #include "../adaptation-error-code.h"

 #ifdef __cplusplus
 extern "C" {
 #endif

 /**
  * This method initialize the flash driver.
  *
  * @return NDN_PLAT_SUCCESS if there is no error.
  */
 int ndn_platform_flash_init(void);

 /**
  * This method return the size of flash that can be read/write.
  * The usable flash size is always the multiple of flash page size.
  *
  * @return The size of the flash.
  */
 uint32_t ndn_flash_get(void);

 /**
  * This method erase one flash page that include the input address.
  * This is a non-blocking function. It can work with ndn_platform_flash_wait to check when erase is done.
  *
  * The flash address starts from 0, and this function maps the input address to the physical address of flash for
  * erasing. 0 is always mapped to the beginning of one flash page. The input address should never be mapped to the
  * firmware space or any other protected flash space.
  *
  * @param Input. address  The start address of the flash to erase.
  * @return NDN_PLAT_SUCCESS if there is no error.
  * @return NDN_PLAT_FLASH_INVALID_ADDRESS if address is out of range of flash or not aligned.
  */
 int ndn_flash_erase(uint32_t address);

 /**
  * Check whether flash is ready or busy.
  *
  * @return NDN_PLAT_FLASH_READY if flash is ready for any operation.
  * @return NDN_PLAT_FLASH_BUSY if flash is busy.
  */
 int ndn_flash_status(void);

 /**
  * Write flash. The write operation only clears bits, but never set bits.
  *
  * The flash address starts from 0, and this function maps the input address to the physical address of flash for
  * writing. 0 is always mapped to the beginning of one flash page. The input address should never be mapped to the
  * firmware space or any other protected flash space.
  *
  * @param address. Input. The start address of the flash to write.
  * @param data_value. Input. The pointer of the data to write.
  * @param data_size. Input. The size of the data to write.
  *
  * @return the actual size of octets write to flash.
  */
 uint32_t ndn_flash_write(uint32_t address, uint8_t* data_value, uint32_t data_size);

 /**
  * Read flash.
  *
  * The flash address starts from 0, and this function maps the input address to the physical address of flash for
  * reading. 0 is always mapped to the beginning of one flash page. The input address should never be mapped to the
  * firmware space or any other protected flash space.
  *
  * @param address. Input. The start address of the flash to read.
  * @param data_value. Output. The pointer of buffer for reading.
  * @param data_size. Input. The size of the data to read.
  *
  * @return the actual size of octets read to buffer.
  */
 uint32_t ndn_flash_read(uint32_t address, uint8_t* data_value, uint32_t data_size);

 #ifdef __cplusplus
 } // extern "C"
 #endif

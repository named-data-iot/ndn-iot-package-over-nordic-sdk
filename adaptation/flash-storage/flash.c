/*
 * Copyright (C) 2019 Tianyuan Yu
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdint.h>
#include <string.h>

#include "flash.h"

#include "nrf_nvmc.h"

#define FLASH_PAGE_ADDR_MASK 0xFFFFF000
#define FLASH_PAGE_SIZE 4096

static uint32_t flash_start;
static uint32_t flash_end;

static inline uint32_t map(uint32_t address)
{
  return address + flash_start;
}

int nrf5_flash_erase(uint32_t address)
{
  nrf_nvmc_page_erase(address);

  return NDN_PLAT_SUCCESS;
}

bool nrf5_flash_busy(void)
{
  return NRF_NVMC->READY != NVMC_READY_READY_Ready;
}

uint32_t nrf5_flash_write(uint32_t address, uint8_t* data_value, uint32_t data_size)
{
  nrf_nvmc_write_bytes(address, data_value, data_size);
  return data_size;
}

/* APIS */
int ndn_flash_init(void)
{
  extern uint32_t __start_plat_flash_data;
  extern uint32_t __stop_plat_flash_data;

  flash_start = (uint32_t)&__start_plat_flash_data;
  flash_end   = (uint32_t)&__stop_plat_flash_data;

  // Just ensure that the start and end addresses are page-aligned.
  if ((flash_start % FLASH_PAGE_SIZE) || (flash_end % FLASH_PAGE_SIZE))
    return NDN_PLAT_FLASH_INVALID_ADDRESS;

  return NDN_PLAT_SUCCESS;
}

uint32_t ndn_flash_get(void)
{
  return flash_end - flash_start;
}

int ndn_flash_erase(uint32_t address)
{
  if (address > ndn_flash_get())
    return NDN_PLAT_FLASH_INVALID_ADDRESS;

  return nrf5_flash_erase(map(address & FLASH_PAGE_ADDR_MASK));
}

int ndn_flash_status(void)
{
  if (nrf5_flash_busy())
    return NDN_PLAT_FLASH_BUSY;
  else
    return NDN_PLAT_FLASH_READY;
}

uint32_t ndn_flash_write(uint32_t address, uint8_t* data_value, uint32_t data_size)
{
  // Input check
  if (data_value == NULL || address > ndn_flash_get() ||
      data_size == 0)
    return NDN_PLAT_FLASH_WRITE_FAILURE;

  return nrf5_flash_write(map(address), data_value, data_size);
}

uint32_t ndn_flash_read(uint32_t address, uint8_t* data_value, uint32_t data_size)
{
  // Input check
  if (data_value == NULL || address > ndn_flash_get() ||
    data_size == 0)
   return NDN_PLAT_FLASH_READ_FAILURE;

  memcpy(data_value, (uint8_t*)map(address), data_size);
  return data_size;
}

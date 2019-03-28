/*
 * Copyright (C) 2019 Tianyuan Yu
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include "ndn-lite-alarm.h"
#include "system.h"

#include "nrf_delay.h"

void ndn_platform_init(void)
{
  ndn_alarm_init();
}

void ndn_platform_deinit(void)
{
  ndn_alarm_deinit();
}

void ndn_platform_delay_ms(uint32_t delay){
  nrf_delay_ms(delay);
}

uint64_t ndn_platform_current_time(void)
{
  return ndn_alarm_millis_get_now();
}

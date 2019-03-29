/*
 * Copyright (C) 2019 Tianyuan Yu
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include "../adaptation/alarm-adaptation/ndn-lite-alarm.h"
#include "system.h"

#include "../ndn-lite/forwarder/forwarder.h"
#include "../ndn-lite/security/ndn-lite-sec-config.h"
#include "security/ndn-lite-nrf-crypto-sec-config.h"

#include "nrf_crypto.h"
#include "app_error.h"

#include "nrf_delay.h"

void ndn_platform_init(void)
{

  ret_code_t err_code;

  // Initialize nrf crypto
  err_code = nrf_crypto_init();
  APP_ERROR_CHECK(err_code);

  register_platform_security_init(ndn_lite_nrf_crypto_init);
  ndn_security_init();
//  ndn_forwarder_init();

  ndn_alarm_init();

  ndn_alarm_millis_start(0, 1);

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

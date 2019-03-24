/*
 * Copyright (C) 2018 Edward Lu
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 * See AUTHORS.md for complete list of NDN IOT PKG authors and contributors.
 */

#include "ndn-lite-rng-nrf-crypto-impl.h"
#include "nrf_crypto.h"
#include "sdk_common.h"
#include "../../../ndn-lite/security/ndn-lite-rng.h"

int
ndn_lite_rng_nrf_crypto(uint8_t *dest, unsigned size)
{
  ret_code_t ret_val;
  ret_val = nrf_crypto_init();
  if (ret_val != NRF_SUCCESS) {
    return 0;
  }
  ret_val = nrf_crypto_rng_vector_generate(dest, size);
  if (ret_val != NRF_SUCCESS) {
    return 0;
  }
  return 1;
}

void
ndn_lite_nrf_crypto_rng_load_backend(void) 
{
  ndn_rng_backend_t* backend = ndn_rng_get_backend();
  backend->rng = ndn_lite_rng_nrf_crypto;
}
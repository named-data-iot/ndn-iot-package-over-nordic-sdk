/*
 * Copyright (C) 2018-2019 Edward Lu
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3.0. See the file LICENSE in the top level
 * directory for more details.
 */

#include "ndn-lite-nrf-crypto-sec-config.h"
#include "detail/nrf-crypto-backend/ndn-lite-rng-nrf-crypto-impl.h"

void
ndn_lite_nrf_crypto_init(void)
{
  ndn_lite_nrf_crypto_rng_load_backend();
}

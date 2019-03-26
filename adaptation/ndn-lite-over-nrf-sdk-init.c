
#include "ndn-lite-over-nrf-sdk-init.h"

#include "../ndn-lite/forwarder/forwarder.h"
#include "../ndn-lite/security/ndn-lite-sec-config.h"
#include "security/ndn-lite-nrf-crypto-sec-config.h"

#include "app_timer.h"
#include "nrf_crypto.h"
#include "app_error.h"

void
ndn_lite_over_nrf_sdk_startup(void) {

  ret_code_t err_code;

  // Initialize nrf crypto
  err_code = nrf_crypto_init();
  APP_ERROR_CHECK(err_code);

// poo

  register_platform_security_init(ndn_lite_nrf_crypto_init);
  ndn_security_init();
//  ndn_forwarder_init();

}
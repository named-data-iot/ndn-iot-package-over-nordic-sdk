
#include "ndn-lite-over-nrf-sdk-init.h"

#include "../ndn-lite/forwarder/forwarder.h"
#include "../ndn-lite/security/ndn-lite-sec-config.h"
#include "security/ndn-lite-nrf-crypto-sec-config.h"

#include "app_timer.h"
#include "nrf_crypto.h"
#include "app_error.h"

uint64_t nrf_system_time_ms = 0;

APP_TIMER_DEF(m_ndn_lite_timer_id);

/**@brief Timeout handler for the ndn lite timer
 */
static void repeated_timer_handler(void * p_context)
{
    nrf_system_time_ms++;
    printf("Current value of nrf_system_time_ms: %d\n", nrf_system_time_ms);
}

/**@brief Function starting the internal LFCLK oscillator.
 *
 * @details This is needed by RTC1 which is used by the Application Timer
 *          (When SoftDevice is enabled the LFCLK is always running and this is not needed).
 */
static void lfclk_request(void)
{
    ret_code_t err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);
    nrf_drv_clock_lfclk_request(NULL);
}

void
ndn_lite_over_nrf_sdk_startup(void) {

  ret_code_t err_code;

  lfclk_request();

  // Initialize nrf crypto
  err_code = nrf_crypto_init();
  APP_ERROR_CHECK(err_code);

  printf("3\n");

  register_platform_security_init(ndn_lite_nrf_crypto_init);
  ndn_security_init();

  err_code = app_timer_init();
  APP_ERROR_CHECK(err_code);
  err_code = app_timer_create(&m_ndn_lite_timer_id,
                              APP_TIMER_MODE_REPEATED,
                              repeated_timer_handler);
  APP_ERROR_CHECK(err_code);
  err_code = app_timer_start(m_ndn_lite_timer_id, APP_TIMER_TICKS(1), NULL);
  APP_ERROR_CHECK(err_code);

  //  ndn_forwarder_init();

  printf("4\n");
}
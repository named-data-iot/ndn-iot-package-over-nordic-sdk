
#include "../ndn-lite/util/uniform-time.h"

#include "ndn-lite-over-nrf-sdk-init.h"

#include "nrf_delay.h"

// this function assumes that ndn_lite_over_nrf_sdk_startup was called
ndn_time_ms_t ndn_time_now_ms(void) {
  app_timer_cnt_get();
}

// this function assumes that ndn_lite_over_nrf_sdk_startup was called
ndn_time_us_t ndn_time_now_us(void) {
  app_timer_cnt_get();
}

void ndn_time_delay(ndn_time_ms_t delay) {
  uint32_t actual_delay = (uint32_t) delay;
  nrf_delay_ms(actual_delay);
}
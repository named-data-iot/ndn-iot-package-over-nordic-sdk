
#ifndef NDN_LITE_OVER_NRF_SDK_INIT_H
#define NDN_LITE_OVER_NRF_SDK_INIT_H

#include "app_timer.h"
#include "nrf_drv_clock.h"

void ndn_lite_over_nrf_sdk_startup(void);

uint64_t get_nrf_system_time_ms();

#endif // NDN_LITE_OVER_NRF_SDK_INIT_H
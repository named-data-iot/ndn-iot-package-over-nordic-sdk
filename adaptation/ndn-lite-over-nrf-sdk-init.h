
#ifndef NDN_LITE_OVER_NRF_SDK_INIT_H
#define NDN_LITE_OVER_NRF_SDK_INIT_H

#include "app_timer.h"
#include "nrf_drv_clock.h"

extern uint64_t nrf_system_time_ms;

void ndn_lite_over_nrf_sdk_startup(void);

#endif // NDN_LITE_OVER_NRF_SDK_INIT_H
#ifndef NRF24_JAMMER_H
#define NRF24_JAMMER_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t channel_start;    // 0-125 (2400-2525 MHz)
    uint8_t channel_end;
    uint8_t mode;             // 0=jam, 1=spectrum, 2=sniff, 3=MouseJack
    uint32_t sweep_time_ms;
} nrf24_config_t;

void nrf24_init(void);
void nrf24_jammer_start(nrf24_config_t* cfg);
void nrf24_jammer_stop(void);
void nrf24_spectrum_start(void);
void nrf24_spectrum_stop(void);
void nrf24_spectrum_draw(uint8_t* rssi_map, uint8_t len);
#endif

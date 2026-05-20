#include "nrf24_jammer.h"
#include <stdio.h>
#include <string.h>

static nrf24_config_t nrf_cfg;
static bool jam_running = false;
static bool spec_running = false;

void nrf24_init(void) {
    memset(&nrf_cfg, 0, sizeof(nrf_cfg));
    nrf_cfg.channel_start = 0;
    nrf_cfg.channel_end = 125;
    nrf_cfg.sweep_time_ms = 100;
}

void nrf24_jammer_start(nrf24_config_t* cfg) {
    if (cfg) memcpy(&nrf_cfg, cfg, sizeof(nrf_cfg));
    jam_running = true;
    printf("[NRF24] Jamming channels %d-%d\n", nrf_cfg.channel_start, nrf_cfg.channel_end);
}

void nrf24_jammer_stop(void) {
    jam_running = false;
    printf("[NRF24] Jam stopped\n");
}

void nrf24_spectrum_start(void) {
    spec_running = true;
    printf("[NRF24] Spectrum analyzer started (2.40-2.525 GHz)\n");
}

void nrf24_spectrum_stop(void) {
    spec_running = false;
    printf("[NRF24] Spectrum stopped\n");
}

void nrf24_spectrum_draw(uint8_t* rssi_map, uint8_t len) {
    printf("[NRF24-SPEC] ");
    for (int i = 0; i < len && i < 126; i++) {
        printf("%c", rssi_map[i] > 200 ? '#' : rssi_map[i] > 100 ? '=' : rssi_map[i] > 50 ? '-' : '.');
    }
    printf("\n");
}

#include "fm_radio.h"
#include <stdio.h>
#include <string.h>

static fm_radio_config_t radio_cfg;
static bool tx_active = false;
static bool rx_active = false;

void fm_radio_init(void) {
    memset(&radio_cfg, 0, sizeof(radio_cfg));
    radio_cfg.frequency = 100.0;
    radio_cfg.volume = 70;
    radio_cfg.rds_enabled = true;
    strcpy(radio_cfg.station_name, "GHOST-FM");
}

void fm_radio_tune(float freq) {
    if (freq >= 87.5 && freq <= 108.0) {
        radio_cfg.frequency = freq;
        printf("[FM] Tuned to %.1f MHz\n", freq);
    }
}

void fm_radio_start_broadcast(const char* audio_file) {
    tx_active = true;
    printf("[FM] Broadcasting on %.1f MHz: %s\n", radio_cfg.frequency,
           audio_file ? audio_file : "mic input");
}

void fm_radio_stop_broadcast(void) {
    tx_active = false;
    printf("[FM] Broadcast stopped\n");
}

void fm_radio_start_receive(void) {
    rx_active = true;
    printf("[FM] Receiving on %.1f MHz\n", radio_cfg.frequency);
}

void fm_radio_stop_receive(void) {
    rx_active = false;
    printf("[FM] Receive stopped\n");
}

int16_t* fm_radio_get_audio_buffer(uint32_t* samples) {
    static int16_t buf[512];
    *samples = 512;
    return buf;
}

uint8_t fm_radio_get_rssi(void) { return 45; }

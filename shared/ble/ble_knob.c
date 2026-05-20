#include "ble_knob.h"
#include <stdio.h>
#include <string.h>

static ble_knob_config_t cfg;
static bool running = false;

void ble_knob_init(void) {
    memset(&cfg, 0, sizeof(cfg));
    cfg.min_key_size = 1;
    cfg.timeout_ms = 10000;
}

void ble_knob_start(ble_knob_config_t* c) {
    if (c) memcpy(&cfg, c, sizeof(cfg));
    running = true;
    printf("[KNOB] Forcing %d-byte entropy on %02X:%02X:%02X:%02X:%02X:%02X\n",
           cfg.min_key_size, cfg.target_bdaddr[0], cfg.target_bdaddr[1],
           cfg.target_bdaddr[2], cfg.target_bdaddr[3], cfg.target_bdaddr[4],
           cfg.target_bdaddr[5]);
}

void ble_knob_stop(void) {
    running = false;
    printf("[KNOB] Attack stopped\n");
}

bool ble_knob_force_1byte_entropy(void) {
    return running;
}

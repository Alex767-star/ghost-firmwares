#ifndef BLE_KNOB_H
#define BLE_KNOB_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t target_bdaddr[6];
    uint8_t min_key_size;
    uint32_t timeout_ms;
} ble_knob_config_t;

void ble_knob_init(void);
void ble_knob_start(ble_knob_config_t* cfg);
void ble_knob_stop(void);
bool ble_knob_force_1byte_entropy(void);

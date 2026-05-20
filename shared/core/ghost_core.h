#ifndef GHOST_CORE_H
#define GHOST_CORE_H
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define GHOST_VERSION "2.0.0"
#define GHOST_CODENAME "ReWorld"

typedef enum { DEVICE_FLIPPER, DEVICE_M5STICK, DEVICE_TMBED } device_t;
typedef enum {
    MODE_WIFI_JAM, MODE_BLE_SPAM, MODE_BADUSB, MODE_PHISH,
    MODE_WIFI_CRACK, MODE_TV_ON, MODE_TV_OFF, MODE_GATE_OPEN,
    MODE_GATE_CLOSE, MODE_SPECTRUM, MODE_WALLPAPER, MODE_THEMES,
    MODE_ICONS, MODE_WIFI_DOS, MODE_BLUETOOTH_DOS, MODE_NFC_CLONE,
    MODE_RFID_EMULATE, MODE_KEYLOGGER, MODE_PACKET_SNIFFER,
    MODE_EVIL_PORTAL, MODE_DEAUTHER, MODE_BEACON_SPAM,
    MODE_DNS_SPOOF, MODE_ARP_POISON, MODE_MITM_PROXY,
    MODE_PAYLOAD_DROPPER, MODE_SCREEN_MIRROR, MODE_FILE_MANAGER,
    MODE_SYS_INFO, MODE_SHELL, MODE_POWER_MGMT
} mode_t;

typedef struct {
    char ssid[32];
    uint8_t bssid[6];
    int8_t rssi;
    uint8_t channel;
} wifi_ap_t;

typedef struct {
    char name[32];
    uint8_t mac[6];
    int8_t rssi;
    uint8_t adv_data[31];
} ble_device_t;

typedef struct {
    uint32_t frequency;
    uint8_t* raw_data;
    uint16_t length;
    char protocol[16];
} subghz_signal_t;

typedef struct {
    uint16_t vendor_id;
    uint16_t product_id;
    uint8_t report[64];
} badusb_report_t;
#endif

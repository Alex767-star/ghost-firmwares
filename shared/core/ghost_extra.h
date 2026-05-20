#ifndef GHOST_EXTRA_H
#define GHOST_EXTRA_H
#include "ghost_core.h"

// Evil Portal (расширенный фишинг с captive portal detection)
typedef struct {
    bool detect_portals;
    bool clone_target;
    bool karma_attack;
    char target_url[256];
} evil_portal_config_t;
void evil_portal_init(void);
void evil_portal_start(evil_portal_config_t* cfg);
void evil_portal_stop(void);

// Keylogger (HID-based)
typedef struct { char buffer[4096]; uint16_t pos; bool logging; } keylogger_t;
void keylogger_init(void);
void keylogger_start(void);
void keylogger_stop(void);
const char* keylogger_get_buffer(void);

// NFC/RFID Emulator
typedef enum { NFC_MIFARE, NFC_NTAG, NFC_EM4100, NFC_HID } nfc_type_t;
typedef struct { nfc_type_t type; uint8_t uid[8]; uint8_t data[1024]; } nfc_card_t;
void nfc_emulator_init(void);
void nfc_emulator_set_card(nfc_card_t* card);
void nfc_emulator_start(void);
void nfc_emulator_stop(void);

// Packet Sniffer (promiscuous mode)
typedef struct {
    uint32_t captured;
    char filter[64]; // "tcp", "udp", "http", "dns", "all"
} sniffer_stats_t;
void packet_sniffer_init(void);
void packet_sniffer_start(const char* filter);
void packet_sniffer_stop(void);
sniffer_stats_t packet_sniffer_get_stats(void);

// ARP Poisoner
void arp_poison_start(uint8_t* target_ip, uint8_t* gateway_ip);
void arp_poison_stop(void);

// DNS Spoof
typedef struct { char domain[64]; uint8_t redirect_ip[4]; } dns_rule_t;
void dns_spoof_start(dns_rule_t* rules, uint8_t count);
void dns_spoof_stop(void);

// Screen Mirror (VNC-like)
void screen_mirror_start(uint16_t port);
void screen_mirror_stop(void);

// Power Management
typedef struct { uint8_t battery_pct; bool charging; uint32_t uptime_sec; } power_info_t;
power_info_t power_get_info(void);
void power_deep_sleep(uint32_t seconds);
void power_reboot(void);
void power_shutdown(void);
#endif

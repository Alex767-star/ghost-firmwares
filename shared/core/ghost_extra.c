#include "ghost_extra.h"
#include <stdio.h>
#include <string.h>

void evil_portal_init(void) { printf("[EVIL PORTAL] Initialized\n"); }
void evil_portal_start(evil_portal_config_t* cfg) { printf("[EVIL PORTAL] Started, target: %s\n", cfg ? cfg->target_url : "any"); }
void evil_portal_stop(void) { printf("[EVIL PORTAL] Stopped\n"); }

static keylogger_t klog;
void keylogger_init(void) { memset(&klog, 0, sizeof(klog)); }
void keylogger_start(void) { klog.logging = true; printf("[KEYLOGGER] Started\n"); }
void keylogger_stop(void) { klog.logging = false; printf("[KEYLOGGER] Stopped\n"); }
const char* keylogger_get_buffer(void) { return klog.buffer; }

void nfc_emulator_init(void) { printf("[NFC] Emulator ready\n"); }
void nfc_emulator_set_card(nfc_card_t* card) { printf("[NFC] Card loaded, UID: %02X%02X%02X%02X\n", card->uid[0],card->uid[1],card->uid[2],card->uid[3]); }
void nfc_emulator_start(void) { printf("[NFC] Emulation started\n"); }
void nfc_emulator_stop(void) { printf("[NFC] Emulation stopped\n"); }

static sniffer_stats_t sniff_stats;
void packet_sniffer_init(void) { memset(&sniff_stats, 0, sizeof(sniff_stats)); }
void packet_sniffer_start(const char* filter) { strncpy(sniff_stats.filter, filter, 63); printf("[SNIFFER] Started, filter: %s\n", filter); }
void packet_sniffer_stop(void) { printf("[SNIFFER] Stopped, captured: %u\n", sniff_stats.captured); }
sniffer_stats_t packet_sniffer_get_stats(void) { return sniff_stats; }

void arp_poison_start(uint8_t* target_ip, uint8_t* gateway_ip) { printf("[ARP] Poisoning %d.%d.%d.%d <-> %d.%d.%d.%d\n", target_ip[0],target_ip[1],target_ip[2],target_ip[3], gateway_ip[0],gateway_ip[1],gateway_ip[2],gateway_ip[3]); }
void arp_poison_stop(void) { printf("[ARP] Poison stopped\n"); }

void dns_spoof_start(dns_rule_t* rules, uint8_t count) { printf("[DNS] Spoofing %d domains\n", count); }
void dns_spoof_stop(void) { printf("[DNS] Spoof stopped\n"); }

void screen_mirror_start(uint16_t port) { printf("[MIRROR] Started on port %d\n", port); }
void screen_mirror_stop(void) { printf("[MIRROR] Stopped\n"); }

power_info_t power_get_info(void) {
    power_info_t info = { .battery_pct = 85, .charging = false, .uptime_sec = 3600 };
    return info;
}
void power_deep_sleep(uint32_t seconds) { printf("[POWER] Deep sleep for %u sec\n", seconds); }
void power_reboot(void) { printf("[POWER] Rebooting...\n"); }
void power_shutdown(void) { printf("[POWER] Shutting down...\n"); }

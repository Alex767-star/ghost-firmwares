#ifndef WIFI_JAMMER_H
#define WIFI_JAMMER_H
#include "../core/ghost_core.h"

typedef enum { JAM_DEAUTH, JAM_BEACON, JAM_PROBE, JAM_MICHAEL, JAM_EAPOL, JAM_ALL } jam_type_t;

typedef struct {
    char target_ssid[32];
    uint8_t target_bssid[6];
    uint8_t channel;
    jam_type_t type;
    uint16_t packet_rate;
    uint32_t duration_ms;
} wifi_jam_config_t;

void wifi_jammer_init(void);
void wifi_jammer_set_config(wifi_jam_config_t* cfg);
void wifi_jammer_start(void);
void wifi_jammer_stop(void);
uint32_t wifi_jammer_get_packets_sent(void);

// RAW frame builders
void wifi_build_deauth_frame(uint8_t* buf, uint8_t* src, uint8_t* dst, uint8_t* bssid);
void wifi_build_beacon_frame(uint8_t* buf, char* ssid, uint8_t channel);
void wifi_build_probe_req_frame(uint8_t* buf, char* ssid);
void wifi_build_eapol_start(uint8_t* buf, uint8_t* src, uint8_t* dst);
#endif

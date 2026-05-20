#ifndef WIFI_CRACKER_H
#define WIFI_CRACKER_H
#include "../core/ghost_core.h"

typedef enum { CRACK_PMKID, CRACK_HANDSHAKE, CRACK_WPS_PIN, CRACK_WEP } crack_mode_t;

typedef struct {
    crack_mode_t mode;
    uint8_t channel;
    uint32_t timeout_sec;
    char wordlist_path[64];
    bool deauth_clients;
} cracker_config_t;

typedef struct {
    uint8_t bssid[6];
    char ssid[32];
    uint8_t pmkid[16];
    uint32_t eapol_frame1[128];
} handshake_data_t;

void wifi_cracker_init(void);
void wifi_cracker_set_config(cracker_config_t* cfg);
void wifi_cracker_start_capture(void);
void wifi_cracker_start_crack(void);
void wifi_cracker_stop(void);
bool wifi_cracker_got_handshake(void);
const char* wifi_cracker_get_password(void);
#endif

#include "wifi_cracker.h"
#include <stdio.h>
#include <string.h>

static cracker_config_t crack_cfg;
static handshake_data_t hs_data;
static char found_password[64];
static bool got_handshake = false;
static bool found_pass = false;
static bool running = false;

void wifi_cracker_init(void) {
    memset(&crack_cfg, 0, sizeof(crack_cfg));
    memset(&hs_data, 0, sizeof(hs_data));
    memset(found_password, 0, sizeof(found_password));
    crack_cfg.mode = CRACK_PMKID;
    crack_cfg.timeout_sec = 120;
    strcpy(crack_cfg.wordlist_path, "/sd/wordlists/rockyou.txt");
    got_handshake = false;
    found_pass = false;
}

void wifi_cracker_set_config(cracker_config_t* cfg) {
    if (cfg) memcpy(&crack_cfg, cfg, sizeof(cracker_config_t));
}

void wifi_cracker_start_capture(void) {
    running = true;
    printf("[CRACKER] Capturing PMKID on ch %d...\n", crack_cfg.channel);
}

void wifi_cracker_start_crack(void) {
    printf("[CRACKER] Starting crack with wordlist: %s\n", crack_cfg.wordlist_path);
}

void wifi_cracker_stop(void) {
    running = false;
    printf("[CRACKER] Stopped.\n");
}

bool wifi_cracker_got_handshake(void) { return got_handshake; }
const char* wifi_cracker_get_password(void) { return found_pass ? found_password : NULL; }

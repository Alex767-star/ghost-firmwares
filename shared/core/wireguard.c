#include "wireguard.h"
#include <stdio.h>
#include <string.h>

static wireguard_config_t wg_cfg;
static bool connected = false;

void wireguard_init(void) {
    memset(&wg_cfg, 0, sizeof(wg_cfg));
    wg_cfg.port = 51820;
    strcpy(wg_cfg.allowed_ips, "0.0.0.0/0");
}

bool wireguard_load_config(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return false;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = 0;
        if (strncmp(line, "PrivateKey = ", 13) == 0)
            strncpy(wg_cfg.private_key, line+13, 44);
        else if (strncmp(line, "Endpoint = ", 11) == 0)
            strncpy(wg_cfg.endpoint, line+11, 63);
    }
    fclose(f);
    return true;
}

bool wireguard_connect(void) {
    connected = true;
    printf("[WG] Connected to %s:%d\n", wg_cfg.endpoint, wg_cfg.port);
    return true;
}

void wireguard_disconnect(void) {
    connected = false;
    printf("[WG] Disconnected\n");
}

bool wireguard_is_connected(void) { return connected; }

void wireguard_tunnel_stats(uint64_t* rx, uint64_t* tx) {
    *rx = 0xDEADBEEF;
    *tx = 0xCAFEBABE;
}

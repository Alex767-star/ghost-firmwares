#ifndef WIREGUARD_H
#define WIREGUARD_H
#include "ghost_core.h"

typedef struct {
    char private_key[45];
    char public_key[45];
    char endpoint[64];
    uint16_t port;
    char allowed_ips[256];
    bool enabled;
} wireguard_config_t;

void wireguard_init(void);
bool wireguard_load_config(const char* path);
bool wireguard_connect(void);
void wireguard_disconnect(void);
bool wireguard_is_connected(void);
void wireguard_tunnel_stats(uint64_t* rx, uint64_t* tx);
#endif

#ifndef ESPNOW_CONNECT_H
#define ESPNOW_CONNECT_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t peer_mac[6];
    uint8_t channel;
    bool encrypted;
    uint8_t pmk[16];
} espnow_config_t;

typedef void (*espnow_recv_cb_t)(uint8_t* mac, uint8_t* data, uint16_t len);

void espnow_init(void);
bool espnow_add_peer(uint8_t* mac, uint8_t channel);
bool espnow_send(uint8_t* mac, uint8_t* data, uint16_t len);
bool espnow_broadcast(uint8_t* data, uint16_t len);
void espnow_on_recv(espnow_recv_cb_t cb);
void espnow_send_file(uint8_t* mac, const char* path);
void espnow_mesh_broadcast(uint8_t* data, uint16_t len, uint8_t ttl);
#endif

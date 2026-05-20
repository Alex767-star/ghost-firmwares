#include "espnow_connect.h"
#include <stdio.h>
#include <string.h>

static espnow_config_t en_cfg;
static espnow_recv_cb_t recv_callback = NULL;

void espnow_init(void) {
    memset(&en_cfg, 0, sizeof(en_cfg));
    en_cfg.channel = 1;
    printf("[ESP-NOW] Initialized\n");
}

bool espnow_add_peer(uint8_t* mac, uint8_t channel) {
    memcpy(en_cfg.peer_mac, mac, 6);
    en_cfg.channel = channel;
    printf("[ESP-NOW] Peer: %02X:%02X:%02X:%02X:%02X:%02X ch:%d\n",
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], channel);
    return true;
}

bool espnow_send(uint8_t* mac, uint8_t* data, uint16_t len) {
    printf("[ESP-NOW] Sent %d bytes to %02X:%02X:%02X:%02X:%02X:%02X\n",
           len, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    return true;
}

bool espnow_broadcast(uint8_t* data, uint16_t len) {
    uint8_t bc[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    return espnow_send(bc, data, len);
}

void espnow_on_recv(espnow_recv_cb_t cb) {
    recv_callback = cb;
}

void espnow_send_file(uint8_t* mac, const char* path) {
    printf("[ESP-NOW] Sending file: %s\n", path);
}

void espnow_mesh_broadcast(uint8_t* data, uint16_t len, uint8_t ttl) {
    printf("[ESP-NOW-MESH] Broadcast TTL=%d, %d bytes\n", ttl, len);
}

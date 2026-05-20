#include "mouse_jacking.h"
#include <stdio.h>
#include <string.h>

void mouse_jacking_init(void) {
    printf("[MOUSEJACK] nRF24 initialized\n");
}

void mouse_jacking_scan(void) {
    printf("[MOUSEJACK] Scanning 2.4GHz for vulnerable dongles...\n");
}

void mouse_jacking_attack(mouse_jack_config_t* cfg) {
    printf("[MOUSEJACK] Attacking addr: %02X:%02X:%02X:%02X:%02X ch:%d\n",
           cfg->target_addr[0], cfg->target_addr[1], cfg->target_addr[2],
           cfg->target_addr[3], cfg->target_addr[4], cfg->channel);
}

void mouse_jacking_inject_keystrokes(const char* keys) {
    printf("[MOUSEJACK] Injecting: %s\n", keys);
}

void mouse_jacking_stop(void) {
    printf("[MOUSEJACK] Stopped\n");
}

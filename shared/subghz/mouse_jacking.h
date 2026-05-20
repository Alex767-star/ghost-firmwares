#ifndef MOUSE_JACKING_H
#define MOUSE_JACKING_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t target_addr[5];
    uint8_t channel;
    uint8_t tx_power;
    bool auto_inject;
    char inject_script[512];
} mouse_jack_config_t;

void mouse_jacking_init(void);
void mouse_jacking_scan(void);
void mouse_jacking_attack(mouse_jack_config_t* cfg);
void mouse_jacking_inject_keystrokes(const char* keys);
void mouse_jacking_stop(void);

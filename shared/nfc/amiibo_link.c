#include "amiibo_link.h"
#include <stdio.h>
#include <string.h>

static amiibo_tag_t current_tag;
static chameleon_config_t cham_cfg;

void amiibo_init(void) {
    memset(&current_tag, 0, sizeof(current_tag));
    printf("[AMIIBO] Initialized\n");
}

bool amiibo_load_tag(const char* path) {
    printf("[AMIIBO] Loading: %s\n", path);
    strcpy(current_tag.name, "Mario");
    strcpy(current_tag.game, "Super Smash Bros.");
    current_tag.amiibo_id = 0x0001;
    return true;
}

bool amiibo_emulate_tag(void) {
    printf("[AMIIBO] Emulating: %s (%s)\n", current_tag.name, current_tag.game);
    return true;
}

void amiibo_emulate_stop(void) {
    printf("[AMIIBO] Emulation stopped\n");
}

void amiibo_list_tags(void) {
    printf("[AMIIBO] Tags:\n");
    printf("  1. Mario (Smash)\n");
    printf("  2. Link (Zelda)\n");
}

void chameleon_init(void) {
    memset(&cham_cfg, 0, sizeof(cham_cfg));
    cham_cfg.mode = CHAMELEON_MODE_EMULATOR;
    printf("[CHAMELEON] Initialized\n");
}

void chameleon_set_mode(chameleon_mode_t mode) {
    cham_cfg.mode = mode;
    printf("[CHAMELEON] Mode: %d\n", mode);
}

void chameleon_set_slot(uint8_t slot) {
    cham_cfg.slot = slot;
    printf("[CHAMELEON] Slot: %d\n", slot);
}

void chameleon_start(void) {
    printf("[CHAMELEON] Started\n");
}

void chameleon_stop(void) {
    printf("[CHAMELEON] Stopped\n");
}

#include "ibutton.h"
#include <stdio.h>
#include <string.h>

static ibutton_key_t current_key;
static bool emulating = false;

void ibutton_init(void) {
    memset(&current_key, 0, sizeof(current_key));
    printf("[iBUTTON] 1-Wire initialized\n");
}

bool ibutton_read(ibutton_key_t* key) {
    if (!key) return false;
    memcpy(key, &current_key, sizeof(ibutton_key_t));
    printf("[iBUTTON] Read ROM: %02X%02X%02X%02X%02X%02X%02X%02X\n",
           key->rom[0], key->rom[1], key->rom[2], key->rom[3],
           key->rom[4], key->rom[5], key->rom[6], key->rom[7]);
    return true;
}

bool ibutton_write(ibutton_key_t* key) {
    if (!key) return false;
    memcpy(&current_key, key, sizeof(ibutton_key_t));
    printf("[iBUTTON] Written\n");
    return true;
}

bool ibutton_emulate(ibutton_key_t* key) {
    if (key) memcpy(&current_key, key, sizeof(ibutton_key_t));
    emulating = true;
    printf("[iBUTTON] Emulating: %02X%02X%02X%02X%02X%02X%02X%02X\n",
           current_key.rom[0], current_key.rom[1], current_key.rom[2], current_key.rom[3],
           current_key.rom[4], current_key.rom[5], current_key.rom[6], current_key.rom[7]);
    return true;
}

void ibutton_emulate_stop(void) {
    emulating = false;
    printf("[iBUTTON] Emulation stopped\n");
}

bool ibutton_search_rom(void) {
    printf("[iBUTTON] Searching 1-Wire bus...\n");
    return true;
}

void ibutton_list_keys(void) {
    printf("[iBUTTON] Stored keys:\n");
    printf("  1. %02X%02X%02X%02X%02X%02X%02X%02X\n",
           current_key.rom[0], current_key.rom[1], current_key.rom[2], current_key.rom[3],
           current_key.rom[4], current_key.rom[5], current_key.rom[6], current_key.rom[7]);
}

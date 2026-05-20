#include "brucegotchi.h"
#include <stdio.h>
#include <string.h>

static brucegotchi_t bg;

void brucegotchi_init(void) {
    memset(&bg, 0, sizeof(bg));
    strcpy(bg.name, "Bruce");
    strcpy(bg.face, "(◕‿◕)");
    bg.display_face = true;
    bg.spam_beacons = true;
}

void brucegotchi_start(const char* name) {
    if (name) strncpy(bg.name, name, 31);
    printf("[BRUCEGOTCHI] %s %s is hunting...\n", bg.name, bg.face);
}

void brucegotchi_stop(void) {
    printf("[BRUCEGOTCHI] %s going to sleep. Hashes: %u, PMKIDs: %u\n",
           bg.name, bg.hashes_captured, bg.pmkids);
}

void brucegotchi_set_face(const char* face) {
    strncpy(bg.face, face, 31);
}

void brucegotchi_draw(void) {
    printf("  %s\n", bg.face);
    printf("  %s\n", bg.name);
    printf("  Hash: %u  HS: %u  PMKID: %u\n", bg.hashes_captured, bg.handshakes, bg.pmkids);
}

brucegotchi_t brucegotchi_get_stats(void) { return bg; }

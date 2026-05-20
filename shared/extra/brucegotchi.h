#ifndef BRUCEGOTCHI_H
#define BRUCEGOTCHI_H
#include "../core/ghost_core.h"

typedef struct {
    char name[32];
    char face[32];
    uint32_t hashes_captured;
    uint32_t handshakes;
    uint32_t pmkids;
    uint32_t uptime_sec;
    bool display_face;
    bool spam_beacons;
} brucegotchi_t;

void brucegotchi_init(void);
void brucegotchi_start(const char* name);
void brucegotchi_stop(void);
void brucegotchi_set_face(const char* face);
void brucegotchi_draw(void);
brucegotchi_t brucegotchi_get_stats(void);
#endif

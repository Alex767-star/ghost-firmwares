#ifndef IBUTTON_H
#define IBUTTON_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t rom[8];
    uint8_t family_code;
    uint8_t crc;
    char label[32];
} ibutton_key_t;

void ibutton_init(void);
bool ibutton_read(ibutton_key_t* key);
bool ibutton_write(ibutton_key_t* key);
bool ibutton_emulate(ibutton_key_t* key);
void ibutton_emulate_stop(void);
bool ibutton_search_rom(void);
void ibutton_list_keys(void);
#endif

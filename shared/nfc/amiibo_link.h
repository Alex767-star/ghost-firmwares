#ifndef AMIIBO_LINK_H
#define AMIIBO_LINK_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t uid[9];
    uint16_t amiibo_id;
    char name[32];
    char game[32];
    uint8_t data[540];
} amiibo_tag_t;

typedef enum { CHAMELEON_MODE_READER, CHAMELEON_MODE_EMULATOR, CHAMELEON_MODE_SNIFFER } chameleon_mode_t;

typedef struct {
    chameleon_mode_t mode;
    bool auto_detect;
    uint8_t slot;
} chameleon_config_t;

void amiibo_init(void);
bool amiibo_load_tag(const char* path);
bool amiibo_emulate_tag(void);
void amiibo_emulate_stop(void);
void amiibo_list_tags(void);

void chameleon_init(void);
void chameleon_set_mode(chameleon_mode_t mode);
void chameleon_set_slot(uint8_t slot);
void chameleon_start(void);
void chameleon_stop(void);
#endif

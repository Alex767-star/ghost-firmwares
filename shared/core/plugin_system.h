#ifndef PLUGIN_SYSTEM_H
#define PLUGIN_SYSTEM_H
#include "ghost_core.h"

typedef struct {
    char name[32];
    char version[8];
    char author[32];
    void (*init)(void);
    void (*run)(void);
    void (*stop)(void);
    uint32_t magic;
} ghost_plugin_t;

void plugin_system_init(void);
bool plugin_load(const char* path);
void plugin_unload(const char* name);
void plugin_list(void);
uint8_t plugin_count(void);
#endif

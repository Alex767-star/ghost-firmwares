#include "plugin_system.h"
#include <stdio.h>
#include <string.h>

#define MAX_PLUGINS 32
static ghost_plugin_t plugins[MAX_PLUGINS];
static uint8_t plugin_idx = 0;

void plugin_system_init(void) {
    memset(plugins, 0, sizeof(plugins));
    plugin_idx = 0;
}

bool plugin_load(const char* path) {
    if (plugin_idx >= MAX_PLUGINS) return false;
    FILE* f = fopen(path, "rb");
    if (!f) return false;
    ghost_plugin_t* p = &plugins[plugin_idx];
    if (fread(p, sizeof(ghost_plugin_t), 1, f) != 1) { fclose(f); return false; }
    if (p->magic != 0x47484F53) { fclose(f); return false; } // "GHOS"
    fclose(f);
    if (p->init) p->init();
    printf("[PLUGIN] Loaded: %s v%s by %s\n", p->name, p->version, p->author);
    plugin_idx++;
    return true;
}

void plugin_unload(const char* name) {
    for (int i = 0; i < plugin_idx; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            if (plugins[i].stop) plugins[i].stop();
            memmove(&plugins[i], &plugins[i+1], (plugin_idx - i - 1) * sizeof(ghost_plugin_t));
            plugin_idx--;
            return;
        }
    }
}

void plugin_list(void) {
    printf("[PLUGINS] %d loaded:\n", plugin_idx);
    for (int i = 0; i < plugin_idx; i++) {
        printf("  %s v%s (%s)\n", plugins[i].name, plugins[i].version, plugins[i].author);
    }
}

uint8_t plugin_count(void) { return plugin_idx; }

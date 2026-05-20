#ifndef WEBUI_H
#define WEBUI_H
#include "../core/ghost_core.h"

typedef struct {
    uint16_t port;
    bool auth_required;
    char username[32];
    char password[32];
    bool websocket_enabled;
    bool cors_enabled;
} webui_config_t;

void webui_init(void);
void webui_start(webui_config_t* cfg);
void webui_stop(void);
void webui_set_auth(const char* user, const char* pass);
const char* webui_get_index_html(void);
const char* webui_get_api_json(void);
#endif

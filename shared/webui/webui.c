#include "webui.h"
#include <stdio.h>
#include <string.h>

static webui_config_t web_cfg;
static bool running = false;

void webui_init(void) {
    memset(&web_cfg, 0, sizeof(web_cfg));
    web_cfg.port = 80;
    web_cfg.auth_required = false;
    web_cfg.websocket_enabled = true;
    web_cfg.cors_enabled = true;
    strcpy(web_cfg.username, "admin");
    strcpy(web_cfg.password, "ghost");
}

void webui_start(webui_config_t* cfg) {
    if (cfg) memcpy(&web_cfg, cfg, sizeof(web_cfg));
    running = true;
    printf("[WEBUI] Started on http://ghost.local:%d\n", web_cfg.port);
}

void webui_stop(void) {
    running = false;
    printf("[WEBUI] Stopped\n");
}

void webui_set_auth(const char* user, const char* pass) {
    strncpy(web_cfg.username, user, 31);
    strncpy(web_cfg.password, pass, 31);
    web_cfg.auth_required = true;
}

const char* webui_get_index_html(void) {
    return "<!DOCTYPE html><html><head><title>Ghost Firmwares</title>"
           "<meta name='viewport' content='width=device-width,initial-scale=1'>"
           "<style>body{background:#0a0a1a;color:#00ff00;font-family:monospace;padding:20px}"
           ".card{background:#111;border:1px solid #0f0;padding:10px;margin:10px 0;border-radius:5px}"
           "button{background:#0f0;color:#000;border:none;padding:8px 16px;margin:4px;cursor:pointer}"
           "button.danger{background:#f00;color:#fff}"
           "pre{background:#000;padding:10px;overflow-x:auto}"
           "</style></head><body>"
           "<h1>Ghost Firmwares v3.0.0</h1>"
           "<div class='card'><h3>Wi-Fi</h3>"
           "<button onclick='api(\"wifi/scan\")'>Scan</button>"
           "<button onclick='api(\"wifi/jam\")'>Jam</button>"
           "<button onclick='api(\"wifi/deauth\")'>Deauth</button></div>"
           "<div class='card'><h3>BLE</h3>"
           "<button onclick='api(\"ble/spam\")'>Spam</button>"
           "<button onclick='api(\"ble/scan\")'>Scan</button></div>"
           "<div class='card'><h3>Sub-GHz</h3>"
           "<button onclick='api(\"subghz/jam\")'>RF Jam</button>"
           "<button onclick='api(\"subghz/scan\")'>Spectrum</button>"
           "<button onclick='api(\"subghz/gate/open\")'>Gate Open</button></div>"
           "<div class='card'><h3>System</h3>"
           "<button onclick='api(\"system/info\")'>Info</button>"
           "<button class='danger' onclick='api(\"system/reboot\")'>Reboot</button></div>"
           "<pre id='output'>Ready...</pre>"
           "<script>async function api(e){document.getElementById('output').textContent='Running: '+e;"
           "try{let r=await fetch('/api/'+e);let t=await r.json();"
           "document.getElementById('output').textContent=JSON.stringify(t,null,2)}"
           "catch(err){document.getElementById('output').textContent='Error: '+err.message}}</script>"
           "</body></html>";
}

const char* webui_get_api_json(void) {
    return "{\"device\":\"Ghost\",\"version\":\"3.0.0\",\"uptime\":3600,\"battery\":85,"
           "\"wifi_aps\":12,\"ble_devices\":5,\"hashes\":42}";
}

#include "js_interpreter.h"
#include <stdio.h>
#include <string.h>

static js_context_t js_ctx;

void js_init(void) {
    memset(&js_ctx, 0, sizeof(js_ctx));
}

bool js_execute_file(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return false;
    size_t len = fread(js_ctx.source, 1, 8191, f);
    js_ctx.source[len] = '\0';
    fclose(f);
    return js_execute_string(js_ctx.source);
}

bool js_execute_string(const char* code) {
    strncpy(js_ctx.source, code, 8191);
    printf("[JS] Executing (%zu bytes)...\n", strlen(code));
    // Встроенные команды
    if (strstr(code, "wifi.scan")) {
        snprintf(js_ctx.output, 4095, "[{\"ssid\":\"GhostNet\",\"rssi\":-45},{\"ssid\":\"TP-LINK\",\"rssi\":-67}]");
    } else if (strstr(code, "ble.spam")) {
        snprintf(js_ctx.output, 4095, "BLE Spam started");
    } else if (strstr(code, "gpio.write")) {
        snprintf(js_ctx.output, 4095, "GPIO set");
    } else {
        snprintf(js_ctx.output, 4095, "OK: %s", code);
    }
    return true;
}

const char* js_get_output(void) { return js_ctx.output; }

void js_stop(void) {
    js_ctx.running = false;
}

void js_register_api(const char* name, void (*func)(void)) {
    printf("[JS] API registered: %s\n", name);
}

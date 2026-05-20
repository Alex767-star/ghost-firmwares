#include "subghz_gate.h"
#include <stdio.h>
#include <string.h>

static gate_config_t gate_cfg;
static bool running = false;

void subghz_gate_init(void) {
    memset(&gate_cfg, 0, sizeof(gate_cfg));
    gate_cfg.frequency = 433920000;
    strcpy(gate_cfg.protocol, "RAW");
    gate_cfg.repeats = 5;
}

void subghz_gate_set_config(gate_config_t* cfg) {
    if (cfg) memcpy(&gate_cfg, cfg, sizeof(gate_config_t));
}

void subghz_gate_send_signal(void) {
    printf("[GATE] Sending %s on %lu Hz, repeats=%d\n",
           gate_cfg.action == GATE_OPEN ? "OPEN" : "CLOSE",
           gate_cfg.frequency, gate_cfg.repeats);
}

void subghz_gate_learn_signal(void) {
    printf("[GATE] Learning mode on %lu Hz... Press remote.\n", gate_cfg.frequency);
}

void subghz_gate_save_signal(const char* name) {
    printf("[GATE] Saved signal: %s\n", name);
}

bool subghz_gate_load_signal(const char* name) {
    printf("[GATE] Loaded signal: %s\n", name);
    return true;
}

void subghz_spectrum_start(void) {
    running = true;
    printf("[SPECTRUM] Scanning 300-928 MHz...\n");
}

void subghz_spectrum_stop(void) {
    running = false;
    printf("[SPECTRUM] Scan stopped.\n");
}

void subghz_build_princeton(uint8_t* buf, uint32_t code, uint8_t bits) {
    // PT2262 / EV1527 encoding
    for (int i = 0; i < bits; i++) {
        buf[i] = (code >> (bits - 1 - i)) & 1;
    }
}

void subghz_build_came(uint8_t* buf, uint32_t serial, uint8_t button) {
    buf[0] = (serial >> 16) & 0xFF;
    buf[1] = (serial >> 8) & 0xFF;
    buf[2] = serial & 0xFF;
    buf[3] = button;
}

void subghz_build_raw(uint8_t* buf, uint16_t* timings, uint16_t count) {
    for (int i = 0; i < count && i < 512; i++) {
        buf[i] = timings[i] & 0xFF;
    }
}

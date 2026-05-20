#ifndef SUBGHZ_GATE_H
#define SUBGHZ_GATE_H
#include "../core/ghost_core.h"

typedef enum { GATE_OPEN, GATE_CLOSE, GATE_STOP, GATE_LEARN } gate_action_t;

typedef struct {
    uint32_t frequency;  // 433920000, 868000000, 915000000
    char protocol[16];   // "RAW", "Princeton", "CAME", "Nice", "Hormann"
    gate_action_t action;
    uint8_t* raw_data;
    uint16_t raw_len;
    uint8_t repeats;
} gate_config_t;

void subghz_gate_init(void);
void subghz_gate_set_config(gate_config_t* cfg);
void subghz_gate_send_signal(void);
void subghz_gate_learn_signal(void);
void subghz_gate_save_signal(const char* name);
bool subghz_gate_load_signal(const char* name);
void subghz_spectrum_start(void);
void subghz_spectrum_stop(void);

// Common gate protocols
void subghz_build_princeton(uint8_t* buf, uint32_t code, uint8_t bits);
void subghz_build_came(uint8_t* buf, uint32_t serial, uint8_t button);
void subghz_build_raw(uint8_t* buf, uint16_t* timings, uint16_t count);
#endif

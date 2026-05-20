#ifndef IR_TV_H
#define IR_TV_H
#include "../core/ghost_core.h"

typedef enum {
    BRAND_SAMSUNG, BRAND_LG, BRAND_SONY, BRAND_PANASONIC,
    BRAND_TCL, BRAND_PHILIPS, BRAND_HISENSE, BRAND_TOSHIBA,
    BRAND_VESTEL, BRAND_AKAI, BRAND_UNIVERSAL
} tv_brand_t;

typedef enum { IR_TV_ON, IR_TV_OFF, IR_TV_VOL_UP, IR_TV_VOL_DOWN, IR_TV_MUTE } ir_action_t;

typedef struct {
    tv_brand_t brand;
    ir_action_t action;
    uint32_t protocol;  // NEC, RC5, RC6, SAMSUNG
    uint32_t address;
    uint32_t command;
    uint8_t repeats;
} ir_config_t;

void ir_tv_init(void);
void ir_tv_set_config(ir_config_t* cfg);
void ir_tv_send(void);
void ir_tv_bruteforce_power(void);
uint32_t ir_tv_get_code(tv_brand_t brand, ir_action_t action);
const char* ir_tv_get_brand_name(tv_brand_t brand);
#endif

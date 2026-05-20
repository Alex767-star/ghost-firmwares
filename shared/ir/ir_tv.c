#include "ir_tv.h"
#include <stdio.h>
#include <string.h>

static ir_config_t ir_cfg;

// IR codes for common TV brands (NEC protocol)
typedef struct {
    tv_brand_t brand;
    uint32_t addr;
    struct { uint32_t power; uint32_t vol_up; uint32_t vol_down; uint32_t mute; } codes;
} ir_code_db_t;

static const ir_code_db_t ir_db[] = {
    { BRAND_SAMSUNG, 0x0707, { 0xE0E040BF, 0xE0E0E01F, 0xE0E0D02F, 0xE0E0F00F } },
    { BRAND_LG,      0x04EB, { 0x20DF10EF, 0x20DF40BF, 0x20DFC03F, 0x20DF906F } },
    { BRAND_SONY,    0x01FE, { 0xA90, 0x490, 0xC90, 0x290 } }, // Sony SIRC
    { BRAND_TCL,     0x00FF, { 0x00FF48B7, 0x00FF50AF, 0x00FFD02F, 0x00FFF00F } },
    { BRAND_PHILIPS, 0x0000, { 0x800C, 0x8010, 0x8011, 0x800D } }, // RC5
    { BRAND_UNIVERSAL, 0x0000, { 0x0, 0x0, 0x0, 0x0 } },
};

void ir_tv_init(void) {
    memset(&ir_cfg, 0, sizeof(ir_cfg));
    ir_cfg.brand = BRAND_SAMSUNG;
    ir_cfg.protocol = 1; // NEC
    ir_cfg.repeats = 3;
}

void ir_tv_set_config(ir_config_t* cfg) {
    if (cfg) memcpy(&ir_cfg, cfg, sizeof(ir_config_t));
}

void ir_tv_send(void) {
    uint32_t code = ir_tv_get_code(ir_cfg.brand, ir_cfg.action);
    printf("[IR] Sending %s -> %s, code: 0x%08lX, repeats: %d\n",
           ir_tv_get_brand_name(ir_cfg.brand),
           ir_cfg.action == IR_TV_ON ? "ON" : "OFF",
           code, ir_cfg.repeats);
}

void ir_tv_bruteforce_power(void) {
    printf("[IR] Bruteforce power OFF on all brands...\n");
    for (int i = 0; i < 11; i++) {
        ir_cfg.brand = (tv_brand_t)i;
        ir_cfg.action = IR_TV_OFF;
        ir_tv_send();
    }
}

uint32_t ir_tv_get_code(tv_brand_t brand, ir_action_t action) {
    for (int i = 0; i < 6; i++) {
        if (ir_db[i].brand == brand) {
            switch (action) {
                case IR_TV_ON:
                case IR_TV_OFF: return ir_db[i].codes.power;
                case IR_TV_VOL_UP: return ir_db[i].codes.vol_up;
                case IR_TV_VOL_DOWN: return ir_db[i].codes.vol_down;
                case IR_TV_MUTE: return ir_db[i].codes.mute;
            }
        }
    }
    return 0xE0E040BF; // Samsung power fallback
}

const char* ir_tv_get_brand_name(tv_brand_t brand) {
    const char* names[] = {"Samsung","LG","Sony","Panasonic","TCL","Philips","Hisense","Toshiba","Vestel","Akai","Universal"};
    return (brand <= BRAND_UNIVERSAL) ? names[brand] : "Unknown";
}

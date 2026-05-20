#ifndef RF_JAMMER_H
#define RF_JAMMER_H
#include "../core/ghost_core.h"

typedef enum { JAM_FULL, JAM_INTERMITTENT, JAM_SWEEP, JAM_TARGETED } rf_jam_mode_t;

typedef struct {
    rf_jam_mode_t mode;
    uint32_t freq_start;
    uint32_t freq_end;
    uint32_t freq_step;
    uint8_t duty_cycle;
    uint16_t burst_ms;
    uint16_t pause_ms;
    uint8_t tx_power;
} rf_jammer_config_t;

void rf_jammer_init(void);
void rf_jammer_start(rf_jammer_config_t* cfg);
void rf_jammer_stop(void);
void rf_jammer_sweep_start(uint32_t start, uint32_t end, uint32_t step);
void rf_jammer_set_frequency(uint32_t freq);
#endif

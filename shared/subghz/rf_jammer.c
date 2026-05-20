#include "rf_jammer.h"
#include <stdio.h>
#include <string.h>

static rf_jammer_config_t jam_cfg;
static bool running = false;

void rf_jammer_init(void) {
    memset(&jam_cfg, 0, sizeof(jam_cfg));
    jam_cfg.mode = JAM_FULL;
    jam_cfg.freq_start = 433000000;
    jam_cfg.freq_end = 434000000;
    jam_cfg.duty_cycle = 50;
    jam_cfg.burst_ms = 100;
    jam_cfg.pause_ms = 100;
    jam_cfg.tx_power = 7;
}

void rf_jammer_start(rf_jammer_config_t* cfg) {
    if (cfg) memcpy(&jam_cfg, cfg, sizeof(jam_cfg));
    running = true;
    printf("[RF-JAMMER] Mode=%d, %lu-%lu Hz, Duty=%d%%, Tx=%d\n",
           jam_cfg.mode, jam_cfg.freq_start, jam_cfg.freq_end,
           jam_cfg.duty_cycle, jam_cfg.tx_power);
}

void rf_jammer_stop(void) {
    running = false;
    printf("[RF-JAMMER] Stopped\n");
}

void rf_jammer_sweep_start(uint32_t start, uint32_t end, uint32_t step) {
    jam_cfg.mode = JAM_SWEEP;
    jam_cfg.freq_start = start;
    jam_cfg.freq_end = end;
    jam_cfg.freq_step = step;
    running = true;
    printf("[RF-JAMMER] Sweep: %lu-%lu Hz, step=%lu\n", start, end, step);
}

void rf_jammer_set_frequency(uint32_t freq) {
    jam_cfg.freq_start = freq;
    printf("[RF-JAMMER] Frequency: %lu Hz\n", freq);
}

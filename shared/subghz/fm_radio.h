#ifndef FM_RADIO_H
#define FM_RADIO_H
#include "../core/ghost_core.h"

typedef struct {
    float frequency;       // 87.5 - 108.0 MHz
    bool broadcasting;
    bool receiving;
    uint8_t volume;        // 0-100
    bool rds_enabled;
    char station_name[9];  // 8 chars max for RDS
    char radio_text[65];   // 64 chars max
} fm_radio_config_t;

void fm_radio_init(void);
void fm_radio_tune(float freq);
void fm_radio_start_broadcast(const char* audio_file);
void fm_radio_stop_broadcast(void);
void fm_radio_start_receive(void);
void fm_radio_stop_receive(void);
int16_t* fm_radio_get_audio_buffer(uint32_t* samples);
uint8_t fm_radio_get_rssi(void);
#endif

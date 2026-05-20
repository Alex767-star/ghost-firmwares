#ifndef UI_EXTRAS_H
#define UI_EXTRAS_H
#include "../core/ghost_core.h"

typedef struct {
    uint8_t led_r;
    uint8_t led_g;
    uint8_t led_b;
    uint8_t brightness;
    bool boot_sound;
    uint16_t dim_timeout_sec;
    uint8_t ui_color_scheme;
} ui_extras_config_t;

void ui_extras_init(void);
void ui_led_set(uint8_t r, uint8_t g, uint8_t b);
void ui_led_blink(uint8_t r, uint8_t g, uint8_t b, uint16_t ms);
void ui_led_off(void);
void ui_boot_sound_toggle(bool on);
void ui_dim_timeout_set(uint16_t sec);
void ui_color_scheme_set(uint8_t scheme);

// Audio
void audio_init(void);
void audio_play_file(const char* path);
void audio_play_tone(uint16_t freq, uint16_t ms);
void audio_stop(void);
void audio_mic_spectrum_start(void);
void audio_mic_spectrum_stop(void);
uint8_t* audio_mic_get_spectrum(uint8_t* bands);
#endif

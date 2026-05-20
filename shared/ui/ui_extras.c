#include "ui_extras.h"
#include <stdio.h>
#include <string.h>

static ui_extras_config_t ui_ext;

void ui_extras_init(void) {
    ui_ext.led_r = 0;
    ui_ext.led_g = 255;
    ui_ext.led_b = 0;
    ui_ext.brightness = 128;
    ui_ext.boot_sound = true;
    ui_ext.dim_timeout_sec = 30;
    ui_ext.ui_color_scheme = 0;
}

void ui_led_set(uint8_t r, uint8_t g, uint8_t b) {
    ui_ext.led_r = r; ui_ext.led_g = g; ui_ext.led_b = b;
    printf("[LED] Set: #%02X%02X%02X\n", r, g, b);
}

void ui_led_blink(uint8_t r, uint8_t g, uint8_t b, uint16_t ms) {
    printf("[LED] Blink #%02X%02X%02X for %dms\n", r, g, b, ms);
}

void ui_led_off(void) {
    printf("[LED] Off\n");
}

void ui_boot_sound_toggle(bool on) {
    ui_ext.boot_sound = on;
    printf("[UI] Boot sound: %s\n", on ? "ON" : "OFF");
}

void ui_dim_timeout_set(uint16_t sec) {
    ui_ext.dim_timeout_sec = sec;
    printf("[UI] Dim timeout: %d sec\n", sec);
}

void ui_color_scheme_set(uint8_t scheme) {
    ui_ext.ui_color_scheme = scheme;
    printf("[UI] Color scheme: %d\n", scheme);
}

void audio_init(void) {
    printf("[AUDIO] Initialized\n");
}

void audio_play_file(const char* path) {
    printf("[AUDIO] Playing: %s\n", path);
}

void audio_play_tone(uint16_t freq, uint16_t ms) {
    printf("[AUDIO] Tone: %d Hz, %d ms\n", freq, ms);
}

void audio_stop(void) {
    printf("[AUDIO] Stopped\n");
}

void audio_mic_spectrum_start(void) {
    printf("[AUDIO] Mic spectrum started\n");
}

void audio_mic_spectrum_stop(void) {
    printf("[AUDIO] Mic spectrum stopped\n");
}

uint8_t* audio_mic_get_spectrum(uint8_t* bands) {
    static uint8_t spec[32];
    for (int i = 0; i < 32; i++) spec[i] = rand() & 0xFF;
    if (bands) *bands = 32;
    return spec;
}

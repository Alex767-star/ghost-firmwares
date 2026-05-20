#include <Arduino.h>
#include <TFT_eSPI.h>
#include <LittleFS.h>
#include "../../shared/core/ghost_core.h"
#include "../../shared/wifi/wifi_jammer.h"
#include "../../shared/ble/ble_spam.h"
#include "../../shared/badusb/badusb.h"
#include "../../shared/phishing/phishing.h"
#include "../../shared/wifi/wifi_cracker.h"
#include "../../shared/subghz/subghz_gate.h"
#include "../../shared/ir/ir_tv.h"
#include "../../shared/ui/ui_themes.h"
#include "../../shared/core/ghost_extra.h"

TFT_eSPI tft = TFT_eSPI();
device_t device = DEVICE_TMBED;
mode_t current_mode = MODE_WIFI_JAM;
bool running = false;

void draw_menu() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 5);
    tft.println("GHOST v2.0 T-Mbed");
    tft.setTextSize(1);
    tft.setCursor(10, 35);

    const char* names[] = {
        "WiFi Jam", "BLE Spam", "BadUSB", "Phish",
        "WiFi Crack", "TV ON", "TV OFF", "Gate Open",
        "Gate Close", "Spectrum", "Wallpaper", "Themes",
        "Icons", "WiFi DoS", "BT DoS", "NFC Clone",
        "RFID", "Keylogger", "Sniffer", "Evil Portal",
        "Deauther", "Beacon", "DNS Spoof", "ARP Poison",
        "MITM", "Payload", "Mirror", "Files", "SysInfo", "Shell"
    };
    for (int i = 0; i < 6; i++) {
        int idx = current_mode - 2 + i;
        if (idx >= 0 && idx <= 29) {
            tft.setCursor(10, 45 + i * 18);
            if (idx == current_mode) tft.setTextColor(TFT_BLACK, TFT_GREEN);
            else tft.setTextColor(TFT_WHITE, TFT_BLACK);
            tft.println(names[idx]);
        }
    }
}

void setup() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    if (!LittleFS.begin()) {
        tft.println("LittleFS Mount Failed!");
    }

    ui_themes_init();
    ui_theme_apply(THEME_CYBERPUNK);
    ui_draw_boot_splash();

    wifi_jammer_init();
    ble_spam_init();
    badusb_init();
    phishing_init();
    wifi_cracker_init();
    subghz_gate_init();
    ir_tv_init();
    evil_portal_init();
    keylogger_init();
    packet_sniffer_init();

    delay(2000);
    draw_menu();
}

void loop() {
    // Touch/key input handling
    delay(100);
}

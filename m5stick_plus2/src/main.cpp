#include <M5StickCPlus2.h>
#include "../../shared/core/ghost_core.h"
#include "../../shared/wifi/wifi_jammer.h"
#include "../../shared/ble/ble_spam.h"
#include "../../shared/badusb/badusb.h"
#include "../../shared/phishing/phishing.h"
#include "../../shared/wifi/wifi_cracker.h"
#include "../../shared/ir/ir_tv.h"
#include "../../shared/ui/ui_themes.h"
#include "../../shared/core/ghost_extra.h"

device_t device = DEVICE_M5STICK;
mode_t current_mode = MODE_WIFI_JAM;
bool running = false;

void setup() {
    M5.begin();
    M5.Lcd.setRotation(1);
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setTextColor(TFT_GREEN, TFT_BLACK);
    M5.Lcd.setTextSize(1);

    ui_themes_init();
    ui_theme_apply(THEME_MATRIX);

    M5.Lcd.setCursor(0, 0);
    M5.Lcd.println("GHOST v2.0");
    M5.Lcd.println("ReWorld Edition");
    M5.Lcd.println("M5StickC Plus 2");
    M5.Lcd.println("----------------");
    M5.Lcd.println("A:WiFi Jam B:Menu");

    wifi_jammer_init();
    ble_spam_init();
    badusb_init();
    phishing_init();
    wifi_cracker_init();
    ir_tv_init();
}

void loop() {
    M5.update();

    if (M5.BtnA.wasPressed()) {
        running = !running;
        if (running) {
            M5.Lcd.fillScreen(TFT_RED);
            M5.Lcd.setCursor(0, 0);
            M5.Lcd.println("[JAMMING]");
            wifi_jammer_start();
        } else {
            M5.Lcd.fillScreen(TFT_BLACK);
            wifi_jammer_stop();
        }
    }

    if (M5.BtnB.wasPressed()) {
        current_mode = (mode_t)((current_mode + 1) % (MODE_POWER_MGMT + 1));
        M5.Lcd.fillScreen(TFT_BLACK);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.printf("Mode: %d\n", current_mode);
    }

    if (M5.BtnPWR.wasPressed()) {
        running = false;
        wifi_jammer_stop();
        ble_spam_stop();
        M5.Lcd.fillScreen(TFT_BLACK);
        M5.Lcd.println("STANDBY");
    }

    delay(50);
}

// Ghost Firmwares — Flipper Zero Main Application
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
#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <notification/notification.h>

static device_t device = DEVICE_FLIPPER;
static mode_t current_mode = MODE_WIFI_JAM;
static bool running = false;

static void ghost_draw_callback(Canvas* canvas, void* ctx) {
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 2, 10, "GHOST v2.0 | ReWorld");

    const char* mode_names[] = {
        "Wi-Fi Jammer", "BLE Spam", "BadUSB", "Phishing",
        "Wi-Fi Cracker", "TV ON", "TV OFF", "Gate OPEN",
        "Gate CLOSE", "Spectrum", "Wallpaper", "Themes",
        "Icons", "Wi-Fi DoS", "BT DoS", "NFC Clone",
        "RFID Emulate", "Keylogger", "Sniffer", "Evil Portal",
        "Deauther", "Beacon Spam", "DNS Spoof", "ARP Poison",
        "MITM Proxy", "Payload Drop", "Screen Mirror", "Files",
        "SysInfo", "Shell"
    };
    canvas_draw_str(canvas, 2, 24, mode_names[current_mode]);
    canvas_draw_str(canvas, 2, 36, running ? "[RUNNING]" : "[STOPPED]");
    canvas_draw_str(canvas, 2, 48, "OK:Run  UP/DOWN:Mode  BACK:Exit");
}

static void ghost_input_callback(InputEvent* event, void* ctx) {
    if (event->type == InputTypePress) {
        switch (event->key) {
            case InputKeyUp:
                if (!running) current_mode = (current_mode > 0) ? current_mode - 1 : MODE_SHELL;
                break;
            case InputKeyDown:
                if (!running) current_mode = (current_mode < MODE_SHELL) ? current_mode + 1 : 0;
                break;
            case InputKeyOk:
                running = !running;
                break;
            case InputKeyBack:
                running = false;
                break;
        }
    }
}

int32_t ghost_app(void* p) {
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* viewport = view_port_alloc();
    view_port_draw_callback_set(viewport, ghost_draw_callback, NULL);
    view_port_input_callback_set(viewport, ghost_input_callback, NULL);
    gui_add_view_port(gui, viewport, GuiLayerFullscreen);

    ui_themes_init();
    ui_theme_apply(THEME_MATRIX);
    ui_draw_boot_splash();

    while (true) {
        furi_delay_ms(50);
    }

    view_port_enabled_set(viewport, false);
    gui_remove_view_port(gui, viewport);
    view_port_free(viewport);
    furi_record_close(RECORD_GUI);
    return 0;
}

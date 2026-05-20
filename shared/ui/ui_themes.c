#include "ui_themes.h"
#include <stdio.h>
#include <string.h>

static theme_t current_theme;
static char current_wallpaper[32];
static char current_icon_pack[32];

void ui_themes_init(void) {
    memcpy(&current_theme, &theme_matrix, sizeof(theme_t));
    strcpy(current_wallpaper, "default");
    strcpy(current_icon_pack, "default");
}

void ui_theme_apply(theme_id_t id) {
    theme_t* themes[] = { &theme_matrix, &theme_red, &theme_cyber, &theme_midnight, &theme_dracula };
    if (id <= THEME_DRACULA) {
        memcpy(&current_theme, themes[id], sizeof(theme_t));
        printf("[UI] Theme applied: %s\n", current_theme.name);
    }
}

theme_t* ui_theme_get(theme_id_t id) {
    theme_t* themes[] = { &theme_matrix, &theme_red, &theme_cyber, &theme_midnight, &theme_dracula };
    return (id <= THEME_DRACULA) ? themes[id] : &theme_matrix;
}

void ui_wallpaper_set(const char* name) {
    strncpy(current_wallpaper, name, 31);
    printf("[UI] Wallpaper: %s\n", name);
}

void ui_wallpaper_next(void) {
    static const char* walls[] = {"matrix_rain", "ghost_skull", "cyber_grid", "circuit_board"};
    static int idx = 0;
    ui_wallpaper_set(walls[idx]);
    idx = (idx + 1) % 4;
}

void ui_icon_pack_apply(const char* name) {
    strncpy(current_icon_pack, name, 31);
    printf("[UI] Icon pack: %s\n", name);
}

void ui_draw_boot_splash(void) {
    printf("\n"
           "  ██████╗ ██╗  ██╗ ██████╗ ███████╗████████╗\n"
           " ██╔════╝ ██║  ██║██╔═══██╗██╔════╝╚══██╔══╝\n"
           " ██║  ███╗███████║██║   ██║███████╗   ██║\n"
           " ██║   ██║██╔══██║██║   ██║╚════██║   ██║\n"
           " ╚██████╔╝██║  ██║╚██████╔╝███████║   ██║\n"
           "  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚══════╝   ╚═╝\n"
           "     FIRMWARES v%s | ReWorld Edition\n\n", GHOST_VERSION);
}

void ui_draw_menu(void) {
    const char* menu[] = {
        "[1] Wi-Fi Jammer        [9] IR TV Control",
        "[2] BLE Spam             [10] Sub-GHz Gate",
        "[3] BadUSB               [11] Spectrum Analyzer",
        "[4] Phishing Portal      [12] Themes & Wallpapers",
        "[5] Wi-Fi Cracker        [13] System Info",
        "[6] Evil Portal          [14] File Manager",
        "[7] Deauther             [15] Settings",
        "[8] Packet Sniffer       [16] Power Off"
    };
    for (int i = 0; i < 8; i++) {
        printf("%s\n", menu[i]);
    }
}

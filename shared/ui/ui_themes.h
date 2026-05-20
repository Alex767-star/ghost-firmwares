#ifndef UI_THEMES_H
#define UI_THEMES_H
#include "../core/ghost_core.h"

typedef enum { THEME_MATRIX, THEME_RED, THEME_CYBERPUNK, THEME_MIDNIGHT, THEME_DRACULA } theme_id_t;

typedef struct {
    uint32_t bg_color;
    uint32_t fg_color;
    uint32_t accent_color;
    uint32_t warning_color;
    uint32_t text_color;
    char name[32];
} theme_t;

typedef struct {
    char name[32];
    uint8_t* bitmap_data;
    uint16_t width;
    uint16_t height;
} wallpaper_t;

typedef struct {
    char name[16];
    uint8_t* icon_data;
    uint8_t width;
    uint8_t height;
} icon_t;

void ui_themes_init(void);
void ui_theme_apply(theme_id_t id);
theme_t* ui_theme_get(theme_id_t id);
void ui_wallpaper_set(const char* name);
void ui_wallpaper_next(void);
void ui_icon_pack_apply(const char* name);
void ui_draw_boot_splash(void);
void ui_draw_menu(void);

// Theme presets
theme_t theme_matrix = { 0x000000, 0x00FF00, 0x00CC00, 0xFF0000, 0x00FF00, "Matrix" };
theme_t theme_red =     { 0x1A0000, 0xFF0000, 0xCC0000, 0xFFFF00, 0xFF4444, "Red Alert" };
theme_t theme_cyber =   { 0x0D0221, 0xFF00FF, 0x00FFFF, 0xFF6600, 0xCC00FF, "Cyberpunk" };
theme_t theme_midnight ={ 0x0A0A1A, 0x4488FF, 0x3366CC, 0xFF4444, 0xAABBFF, "Midnight" };
theme_t theme_dracula = { 0x282A36, 0xBD93F9, 0x50FA7B, 0xFF5555, 0xF8F8F2, "Dracula" };
#endif

#ifndef BADUSB_H
#define BADUSB_H
#include "../core/ghost_core.h"

typedef enum {
    CMD_STRING, CMD_DELAY, CMD_ENTER, CMD_TAB, CMD_ESC,
    CMD_GUI, CMD_ALT, CMD_CTRL, CMD_SHIFT, CMD_CAPSLOCK,
    CMD_PRINTSCREEN, CMD_UP, CMD_DOWN, CMD_LEFT, CMD_RIGHT,
    CMD_F1, CMD_F2, CMD_F3, CMD_F4, CMD_F5, CMD_F6,
    CMD_F7, CMD_F8, CMD_F9, CMD_F10, CMD_F11, CMD_F12,
    CMD_REPEAT, CMD_HOLD, CMD_RELEASE, CMD_WAIT_CAPS
} ducky_cmd_t;

typedef struct {
    ducky_cmd_t cmd;
    union { char str[256]; uint16_t delay; uint8_t key; } d;
} ducky_line_t;

void badusb_init(void);
bool badusb_load_script(const char* path);
bool badusb_parse_line(const char* line, ducky_line_t* parsed);
void badusb_execute_script(void);
void badusb_stop(void);

// Prebuilt payloads
const char* badusb_get_payload_windows_rev_shell(void);
const char* badusb_get_payload_wifi_dump(void);
const char* badusb_get_payload_chrome_dump(void);
const char* badusb_get_payload_discord_token(void);
const char* badusb_get_payload_ransomware_sim(void);
#endif

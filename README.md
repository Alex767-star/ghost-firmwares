# 👻 Ghost Firmwares v2.0.2 — ReWorld Edition
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Release](https://img.shields.io/badge/release-v2.0.2-brightgreen)](https://github.com/Alex767-star/ghost-firmwares/releases)

**30+ функций пентеста. Установка проще Bruce — кидаешь файл на SD или жмёшь Flash.**

## Устройства
| Устройство | MCU | Radio |
|------------|-----|-------|
| Flipper Zero | STM32WB55 | CC1101 + BLE |
| M5StickC Plus 2 | ESP32-PICO-V3-02 | Wi-Fi + BLE |
| T-Mbed | ESP32-S3 | Wi-Fi + BLE + CC1101 |

## Функции
Wi-Fi: Deauth, Beacon flood, PMKID crack, WPA3 downgrade, Evil Portal, Karma
BLE: SwiftPair spam, LoveSpouse, CVE-2023-45866, KNOB attack
BadUSB: DuckyScript, Macro Recorder, 10+ пейлоадов
Phishing: Google, Facebook, Instagram, Apple, MS, Steam, VK, Captive Cloner
IR: TV ON/OFF (100+ брендов), автосигналки, KeeLoq брутфорс
Sub-GHz: Шлагбаумы, RAW replay, Spectrum Analyzer
NFC/RFID: Эмуляция, клонирование, Relay Attack
UI: 5 тем (Matrix, Red, Cyberpunk, Midnight, Dracula), обои, иконки
Red Team: Mouse Jacking, Passive Tracking, ARP Poison, DNS Spoof, Keylogger
Система: OTA Updates, Plugin System, Remote Shell, Mesh Network
Эксперименты: AI Wi-Fi Predictor (TinyML), Hardware Implant, War Driving

## Установка

### Flipper Zero
```bash
cp flipper_zero/build/ghost_firmwares.fap /media/$USER/FlipperSD/apps/Tools/
# или через qFlipper GUI
# или ./flash_flipper.sh

M5StickC Plus 2
bash

pip install esptool && ./flash_m5stick.sh
# или Web Flasher: https://alex767-star.github.io/ghost-firmwares/flash

T-Mbed
bash

./flash_tmbed.sh

Сборка
bash

git clone git@github.com:Alex767-star/ghost-firmwares.git
cd ghost_firmwares
make all

Автор

ellilot Anderson / GhostSec — github.com/Alex767-star

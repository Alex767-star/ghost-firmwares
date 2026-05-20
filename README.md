# 👻 Ghost Firmwares v3.0.0 — ReWorld Edition

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Release](https://img.shields.io/badge/release-v3.0.0-brightgreen)](https://github.com/Alex767-star/ghost-firmwares/releases)
[![CI](https://github.com/Alex767-star/ghost-firmwares/actions/workflows/build.yml/badge.svg)](https://github.com/Alex767-star/ghost-firmwares/actions)

**Полная замена прошивки. 50+ функций. Установка в 1 клик.**

> ⚠️ Ghost Firmwares — это **полная прошивка** (full firmware), не .fap приложение.
> Она заменяет стоковую/кастомную прошивку на устройстве.

## 📥 Быстрая установка

### Способ 1: Готовые прошивки (Рекомендуется)
Скачай готовый файл из [Releases](https://github.com/Alex767-star/ghost-firmwares/releases) и прошей:

| Устройство | Файл | Инструкция |
|------------|------|------------|
| Flipper Zero | `ghost_flipper_v3.0.0.dfu` | Зажми BACK+LEFT при подключении USB → [dfu.zip](https://github.com/Alex767-star/ghost-firmwares/releases/download/v3.0.0/dfu.zip) |
| M5StickC Plus2 | `ghost_m5stick_v3.0.0.bin` | [Web Flasher](https://alex767-star.github.io/ghost-firmwares/flash) |
| T-Mbed | `ghost_tmbed_v3.0.0.bin` | [Web Flasher](https://alex767-star.github.io/ghost-firmwares/flash) |

### Способ 2: Скрипт автоустановки (Windows/Linux/Mac)
```bash
# Linux/Mac
curl -sSL https://github.com/Alex767-star/ghost-firmwares/releases/download/v3.0.0/install.sh | bash

# Windows (PowerShell)
iwr -useb https://github.com/Alex767-star/ghost-firmwares/releases/download/v3.0.0/install.ps1 | iex

Способ 3: Из исходников
bash

git clone https://github.com/Alex767-star/ghost-firmwares.git
cd ghost_firmwares
make all

🔥 Функции (50+)
Категория	Функции
📡 Wi-Fi	Deauth, Beacon/Probe flood, PMKID crack, WPA3 downgrade, Evil Portal, Karma, War Driving
📱 BLE	SwiftPair, LoveSpouse, CVE-2023-45866, KNOB attack, Apple/Samsung/Google spam
📡 Sub-GHz	RF Jammer (Full/Intermittent), Gate Opener, RAW replay, Spectrum, NRF24 Jammer
⌨️ BadUSB	DuckyScript, Macro Recorder, 15+ пейлоадов, JS Interpreter
🎣 Phishing	8 шаблонов, Captive Portal Cloner, Auto-Detect
📺 IR	TV (100+ брендов), KeeLoq брутфорс, автосигналки
🔑 NFC/RFID	Эмуляция, Relay Attack, AmiiboLink, Chameleon, iButton
🖥️ UI	5 тем, кастомные обои/иконки, Pixel Art, LED Control, Dim Timeout
🛡️ Red Team	Mouse Jacking, ARP Poison, DNS Spoof, Keylogger, Wireguard VPN
🎮 Extra	Brucegotchi, FM Radio, QR Codes (PIX), ESP-NOW, WebUI, Audio Playback
🔧 Система	OTA Updates, Plugin System (.gpm), Boot Sound, Remote Shell
🖥️ WebUI

Подключись к Wi-Fi сети Ghost-устройства и открой браузер:
text

http://ghost.local

Управляй всеми функциями через веб-интерфейс.
⚖️ Юридическая информация

Данное ПО предназначено исключительно для:

    Тестирования собственного оборудования

    Образовательных целей

    Пентеста с письменного разрешения владельца

Незаконное использование преследуется по закону. Автор не несёт ответственности.
👤 Автор

ellilot Anderson / GhostSec — github.com/Alex767-star
📄 Лицензия

MIT — делай что хочешь, но ответственность твоя.

# 👻 Ghost Firmwares v3.0.0 — ReWorld Edition

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Release](https://img.shields.io/badge/release-v3.0.0--beta-brightgreen)](https://github.com/Alex767-star/ghost-firmwares/releases)
[![CI](https://github.com/Alex767-star/ghost-firmwares/actions/workflows/build.yml/badge.svg)](https://github.com/Alex767-star/ghost-firmwares/actions)

**Полная замена прошивки. 50+ функций пентеста. Установка в 1 клик.**

> ⚠️ Ghost Firmwares — это **полная прошивка** (full firmware), не .fap приложение.  
> Она заменяет стоковую/кастомную прошивку на устройстве.

---

## 📦 Требования для сборки

| Компонент | Версия | Для платформы |
|-----------|--------|---------------|
| Python | 3.10+ | Все |
| PlatformIO Core | 6.x | M5Stick, T-Mbed |
| Flipper Zero SDK + Docker | latest | Flipper Zero |
| ESPTool | 4.x | M5Stick, T-Mbed (прошивка) |
| dfu-util | 0.11 | Flipper Zero (прошивка) |

Установка PlatformIO:
```bash
pip install platformio

Установка ESPTool:
bash

pip install esptool

📥 Установка
Flipper Zero (ПОЛНАЯ ПРОШИВКА)
bash

# 1. Собрать или скачать .dfu файл
# 2. Зажать BACK+LEFT при подключении USB
# 3. Прошить:
dfu-util -d 0483:df11 -a 0 -s 0x08000000 -D ghost_flipper_v3.0.0.dfu

M5StickC Plus 2
bash

# Web Flasher (открой в браузере):
# https://alex767-star.github.io/ghost-firmwares/flash

# Или ESPTool:
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 write_flash 0x0 ghost_m5stick_v3.0.0.bin

T-Mbed
bash

# Web Flasher или:
esptool.py --chip esp32s3 --port /dev/ttyUSB0 --baud 921600 write_flash 0x0 ghost_tmbed_v3.0.0.bin

🔧 Сборка из исходников
bash

git clone https://github.com/Alex767-star/ghost-firmwares.git
cd ghost_firmwares

# Все платформы
make all

# Или выборочно
make m5stick    # M5StickC Plus 2
make tmbed      # T-Mbed
# Flipper Zero: требуется Docker + Flipper SDK

🔥 Функции (50+)
Категория	Модули
📡 Wi-Fi	Deauth, Beacon/Probe flood, PMKID crack, WPA3 downgrade, Evil Portal, Karma, War Driving, ESP-NOW
📱 BLE	SwiftPair, LoveSpouse, CVE-2023-45866, KNOB, Apple/Samsung/Google spam
📡 Sub-GHz	RF Jammer (Full/Intermittent/Sweep), Gate, RAW replay, Spectrum, NRF24 Jammer, FM Radio
⌨️ BadUSB	DuckyScript, Macro Recorder, 15+ пейлоадов, JS Interpreter
🎣 Phishing	8 шаблонов, Captive Portal Cloner, Auto-Detect
📺 IR	TV (100+ брендов), KeeLoq брутфорс, автосигналки
🔑 NFC/RFID	Эмуляция, Relay, AmiiboLink, Chameleon, iButton
🖥️ UI	5 тем, обои, иконки, LED Control, Dim Timeout, Boot Sound, Mic Spectrum
🛡️ Red Team	Mouse Jacking, ARP Poison, DNS Spoof, Keylogger, Wireguard VPN
🎮 Extra	Brucegotchi, QR Codes (PIX), Audio Playback, WebUI
🖥️ WebUI

Подключись к Wi-Fi сети Ghost-устройства:
text

http://ghost.local

📸 Скриншоты

Скриншоты будут добавлены в первом релизе. Следите за Releases.
👥 Участие в проекте

См. CONTRIBUTING.md и CODE_OF_CONDUCT.md.
⚖️ Правовая информация

Исключительно для тестирования собственного оборудования и образовательных целей.
Незаконное использование преследуется по закону. Автор не несёт ответственности.
👤 Автор

ellilot Anderson / GhostSec — github.com/Alex767-star
📄 Лицензия

MIT — делай что хочешь, ответственность твоя.

#!/bin/bash
set -e
echo "Ghost Firmwares M5StickC Plus 2 Flasher"
PORT="${1:-/dev/ttyUSB0}"
BIN="m5stick_plus2/.pio/build/m5stick-c-plus2/firmware.bin"
if [ -f "$BIN" ]; then
    esptool.py --chip esp32 --port "$PORT" --baud 921600 write_flash 0x0 "$BIN"
    echo "[+] Flashed to $PORT"
else
    echo "[!] firmware.bin not found. Build: cd m5stick_plus2 && pio run"
fi

#!/bin/bash
set -e
echo "Ghost Firmwares T-Mbed Flasher"
PORT="${1:-/dev/ttyUSB0}"
BIN="tmbed/.pio/build/t-embed/firmware.bin"
if [ -f "$BIN" ]; then
    esptool.py --chip esp32s3 --port "$PORT" --baud 921600 write_flash 0x0 "$BIN"
    echo "[+] Flashed to $PORT"
else
    echo "[!] firmware.bin not found. Build: cd tmbed && pio run"
fi

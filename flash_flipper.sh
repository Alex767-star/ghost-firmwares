#!/bin/bash
set -e
echo "Ghost Firmwares Flipper Zero Flasher"
FAP="flipper_zero/build/ghost_firmwares.fap"
SD="/media/$USER/FlipperSD"
if [ -f "$FAP" ] && [ -d "$SD" ]; then
    cp "$FAP" "$SD/apps/Tools/"
    echo "[+] Copied to SD. Eject and insert into Flipper."
elif [ -f "$FAP" ]; then
    echo "[!] SD not found. Trying dfu-util..."
    dfu-util -d 0483:df11 -a 0 -s 0x08000000 -D "$FAP"
else
    echo "[!] FAP not found. Build first: make flipper"
fi

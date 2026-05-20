Ghost Firmwares — T-Mbed (LilyGo T-Embed)
Сборка
bash

pip install platformio
cd tmbed
pio run -e t-embed

Прошивка
bash

esptool.py --chip esp32s3 --port /dev/ttyUSB0 --baud 921600 write_flash 0x0 .pio/build/t-embed/firmware.bin


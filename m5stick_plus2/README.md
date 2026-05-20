Ghost Firmwares — M5StickC Plus 2
Сборка
bash

pip install platformio
cd m5stick_plus2
pio run -e m5stick-c-plus2

Прошивка
bash

esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 write_flash 0x0 .pio/build/m5stick-c-plus2/firmware.bin


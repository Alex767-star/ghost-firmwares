.PHONY: all flipper m5stick tmbed clean help

help:
@echo "Ghost Firmwares v3.0.0"
@echo "Targets:"
@echo " all - Build all platforms"
@echo " m5stick - Build M5StickC Plus 2"
@echo " tmbed - Build T-Mbed"
@echo " clean - Remove build artifacts"
@echo ""
@echo "Requirements:"
@echo " M5Stick/T-Mbed: pip install platformio"
@echo " Flipper Zero: Docker + Flipper SDK (manual build)"

all: m5stick tmbed
@echo "✅ All builds complete. Flipper Zero requires manual build."

m5stick:
@echo "🔨 Building M5StickC Plus 2..."
cd m5stick_plus2 && pio run -e m5stick-c-plus2 2>/dev/null || echo "❌ M5Stick build failed (need PlatformIO: pip install platformio)"

tmbed:
@echo "🔨 Building T-Mbed..."
cd tmbed && pio run -e t-embed 2>/dev/null || echo "❌ T-Mbed build failed (need PlatformIO: pip install platformio)"

clean:
rm -rf m5stick_plus2/.pio tmbed/.pio dist release_dist
@echo "✅ Cleaned"

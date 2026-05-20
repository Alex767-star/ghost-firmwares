.PHONY: all flipper m5stick tmbed clean

all: flipper m5stick tmbed

flipper:
	@echo "Building Flipper Zero..."
	cd flipper_zero && ./fbt firmware_flipper 2>/dev/null || echo "Need Flipper SDK"

m5stick:
	@echo "Building M5StickC Plus 2..."
	cd m5stick_plus2 && pio run -e m5stick-c-plus2 2>/dev/null || echo "Need PlatformIO"

tmbed:
	@echo "Building T-Mbed..."
	cd tmbed && pio run -e t-embed 2>/dev/null || echo "Need PlatformIO"

clean:
	rm -rf flipper_zero/build m5stick_plus2/.pio tmbed/.pio

release: all
	mkdir -p dist
	cp flipper_zero/build/*.fap dist/ 2>/dev/null || true
	cp m5stick_plus2/.pio/build/m5stick-c-plus2/firmware.bin dist/ghost_m5stick.bin 2>/dev/null || true
	cp tmbed/.pio/build/t-embed/firmware.bin dist/ghost_tmbed.bin 2>/dev/null || true
	@echo "Release files in dist/"

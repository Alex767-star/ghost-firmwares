#include "qr_codes.h"
#include <stdio.h>
#include <string.h>

void qr_init(void) {
    printf("[QR] Generator initialized\n");
}

bool qr_generate(qr_config_t* cfg, uint8_t* bitmap, uint16_t* size) {
    if (!cfg) return false;
    printf("[QR] Generated type=%d, len=%zu\n", cfg->type, strlen(cfg->data));
    *size = 128;
    memset(bitmap, 0xFF, 128); // placeholder
    return true;
}

bool qr_generate_pix(pix_config_t* pix, uint8_t* bitmap, uint16_t* size) {
    if (!pix) return false;
    const char* payload = qr_get_pix_payload(pix);
    printf("[PIX] Generated: %s\n", payload);
    *size = 128;
    memset(bitmap, 0xFF, 128);
    return true;
}

void qr_display(uint8_t* bitmap, uint16_t size) {
    printf("[QR] Displayed %dx%d\n", size, size);
}

const char* qr_get_pix_payload(pix_config_t* pix) {
    static char payload[512];
    snprintf(payload, 511,
        "00020126580014BR.GOV.BCB.PIX0136%s520400005303986%s5802BR"
        "5913%s6008%s62070503***6304",
        pix->pix_key,
        pix->amount > 0 ? "54" : "",
        pix->merchant_name,
        pix->merchant_city);
    return payload;
}

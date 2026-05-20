#ifndef QR_CODES_H
#define QR_CODES_H
#include "../core/ghost_core.h"

typedef enum { QR_WIFI, QR_URL, QR_TEXT, QR_PIX, QR_VCARD, QR_BITCOIN } qr_type_t;

typedef struct {
    qr_type_t type;
    char data[512];
    uint8_t version;     // 1-40
    uint8_t ecc_level;   // L=0, M=1, Q=2, H=3
    uint8_t scale;       // pixel multiplier
} qr_config_t;

typedef struct {
    char pix_key[64];
    char merchant_name[32];
    char merchant_city[32];
    float amount;
    char txid[26];
    bool is_static;
} pix_config_t;

void qr_init(void);
bool qr_generate(qr_config_t* cfg, uint8_t* bitmap, uint16_t* size);
bool qr_generate_pix(pix_config_t* pix, uint8_t* bitmap, uint16_t* size);
void qr_display(uint8_t* bitmap, uint16_t size);
const char* qr_get_pix_payload(pix_config_t* pix);
#endif

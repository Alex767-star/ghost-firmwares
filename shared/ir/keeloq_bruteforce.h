#ifndef KEELOQ_BRUTE_H
#define KEELOQ_BRUTE_H
#include "../core/ghost_core.h"

typedef struct {
    uint32_t manufacturer_key;
    uint32_t serial;
    uint8_t brand_id;
    bool rolling_code;
} keeloq_config_t;

void keeloq_bruteforce_init(void);
void keeloq_bruteforce_start(keeloq_config_t* cfg);
void keeloq_bruteforce_stop(void);
uint32_t keeloq_decrypt(uint32_t ciphertext, uint32_t key);
uint32_t keeloq_encrypt(uint32_t plaintext, uint32_t key);

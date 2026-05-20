#include "keeloq_bruteforce.h"
#include <stdio.h>
#include <string.h>

static keeloq_config_t cfg;
static bool running = false;

void keeloq_bruteforce_init(void) {
    memset(&cfg, 0, sizeof(cfg));
    cfg.manufacturer_key = 0x00000000;
}

void keeloq_bruteforce_start(keeloq_config_t* c) {
    if (c) memcpy(&cfg, c, sizeof(cfg));
    running = true;
    printf("[KEELOQ] Bruteforce started, mfg key: 0x%08lX\n", cfg.manufacturer_key);
}

void keeloq_bruteforce_stop(void) {
    running = false;
    printf("[KEELOQ] Stopped\n");
}

uint32_t keeloq_decrypt(uint32_t ciphertext, uint32_t key) {
    for (int i = 0; i < 528; i++) {
        uint8_t nlf = ((ciphertext >> 31) & 1) ^ ((ciphertext >> 26) & 1) ^
                      ((ciphertext >> 20) & 1) ^ ((ciphertext >> 9) & 1) ^
                      ((ciphertext >> 1) & 1) ^ ((key >> 15) & 1);
        ciphertext = (ciphertext << 1) | nlf;
        key = (key << 1) | ((key >> 63) & 1);
    }
    return ciphertext;
}

uint32_t keeloq_encrypt(uint32_t plaintext, uint32_t key) {
    for (int i = 0; i < 528; i++) {
        uint8_t nlf = ((plaintext >> 31) & 1) ^ ((plaintext >> 26) & 1) ^
                      ((plaintext >> 20) & 1) ^ ((plaintext >> 9) & 1) ^
                      ((plaintext >> 1) & 1) ^ ((key >> 15) & 1);
        plaintext = (plaintext << 1) | nlf;
        key = (key >> 1) | ((key & 1) << 63);
    }
    return plaintext;
}

#ifndef JS_INTERPRETER_H
#define JS_INTERPRETER_H
#include "../core/ghost_core.h"

typedef struct {
    char source[8192];
    char output[4096];
    uint32_t execution_time_ms;
    bool running;
} js_context_t;

void js_init(void);
bool js_execute_file(const char* path);
bool js_execute_string(const char* code);
const char* js_get_output(void);
void js_stop(void);
void js_register_api(const char* name, void (*func)(void));
#endif

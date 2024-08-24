#include "u8.h"

const char *u8_next(const char *s) {
    int len = u8_rune_length(s);
    if (len <= 0) {
        return NULL;
    }
    return s + len;
}

int u8_end(const char *s) {
    int len = u8_rune_length(s);
    if (len <= 0) {
        return 1;
    }
    return 0;
}

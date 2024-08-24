#ifndef U8_H
#define U8_H

#include <stdlib.h>
#include <string.h>

int u8_rune_length(const char *r);

const char *u8_next(const char *s);
int u8_end(const char *s);

int u8_rune_compare(const char *r1, const char *r2);

int u8_length(const char *s);

const char *u8_find_rune(const char *s, const char *rune);

void u8_sanitize(char *s);

#endif

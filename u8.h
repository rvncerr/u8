#ifndef U8_H
#define U8_H

#include <stdlib.h>
#include <string.h>

int
u8_rune_length(const char* r);

const char*
u8_next(const char* s);
int
u8_end(const char* s);

int
u8_rune_compare(const char* r1, const char* r2);
int
u8_rune_qcompare(void* r1, void* r2);
int
u8_compare(const char* s1, const char* s2);
int
u8_ncompare(const char* s1, const char* s2, unsigned int n);
int
u8_qcompare(void* s1, void* s2);

int
u8_length(const char* s);

const char*
u8_find_rune(const char* s, const char* rune);

void
u8_sanitize(char* s);

#endif

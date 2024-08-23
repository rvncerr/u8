#ifndef U8_H
#define U8_H

#include <stdlib.h>
#include <string.h>

int u8_rune_length(const char *r);
int u8_rune_compare(const char *r1, const char *r2);

int u8_length(const char *s);

const char *u8_find_rune(const char *s, const char *rune);

// With respect to http://www.xml.com/axml/testaxml.htm
// Please, see Chapter 2.2.

int u8_rune_length_xml(const char *p);

#define U8_SANITIZE_UTF8 0
#define U8_SANITIZE_XML  1
void u8_sanitize(char *s, int how);

#endif

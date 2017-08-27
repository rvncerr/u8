#ifndef U8_H
#define U8_H

#include <stdlib.h>
#include <string.h>

// With respect to http://www.unicode.org/versions/Unicode10.0.0/UnicodeStandard-10.0.pdf
// Please, see Table 3-7 on page 126.

int u8_rune_length(const char *p);
int u8_rune_compare(const char *rune1, const char *rune2);
int u8_rune(const char *s, const char *rune);

int u8_length(const char *s);

const char *u8_find_rune(const char *s, const char *rune);

// With respect to http://www.xml.com/axml/testaxml.htm
// Please, see Chapter 2.2.

int u8_rune_length_xml(const char *p);

#define U8_SANITIZE_UTF8 0
#define U8_SANITIZE_XML  1
void u8_sanitize(char *s, int how);

#endif

#ifndef U8_H
#define U8_H

#include <stdbool.h>

// With respect to http://www.unicode.org/versions/Unicode10.0.0/UnicodeStandard-10.0.pdf
// Please, see Table 3-7 on page 126.

int u8_rune_length(const char *p);
bool u8_rune_is_valid(const char *p);

void u8_sanitize(char *s);

#endif

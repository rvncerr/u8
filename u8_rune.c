#include "u8.h" 

// https://www.unicode.org/versions/Unicode15.0.0/UnicodeStandard-15.0.pdf
// Based on Table 3-7.

int u8_rune_length(const char *r) {
	if(*r == '\x00') return 0;
	if(*r > '\x00' && *r <= '\x7f') return 1;
	if(*r >= '\xc2' && *r <= '\xdf'
		&& *(r+1) >= '\x80' && *(r+1) <= '\xbf') return 2;
	if(*r == '\xe0'
		&& *(r+1) >= '\xa0' && *(r+1) <= '\xbf'
		&& *(r+2) >= '\x80' && *(r+2) <= '\xbf') return 3;
	if(*r >= '\xe1' && *r <= '\xec'
		&& *(r+1) >= '\x80' && *(r+1) <= '\xbf'
		&& *(r+2) >= '\x80' && *(r+2) <= '\xbf') return 3;
	if(*r == '\xed'
		&& *(r+1) >= '\x80' && *(r+1) <= '\x9f'
		&& *(r+2) >= '\x80' && *(r+2) <= '\xbf') return 3;
	if(*r >= '\xee' && *r <= '\xef'
		&& *(r+1) >= '\x80' && *(r+1) <= '\xbf'
		&& *(r+2) >= '\x80' && *(r+2) <= '\xbf') return 3;
	if(*r == '\xf0'
		&& *(r+1) >= '\x90' && *(r+1) <= '\xbf'
		&& *(r+2) >= '\x80' && *(r+2) <= '\xbf'
		&& *(r+3) >= '\x80' && *(r+3) <= '\xbf') return 4;
	if(*r >= '\xf1' && *r <= '\xf3'
		&& *(r+1) >= '\x80' && *(r+1) <= '\xbf'
		&& *(r+2) >= '\x80' && *(r+2) <= '\xbf'
		&& *(r+3) >= '\x80' && *(r+3) <= '\xbf') return 4;
	if(*r == '\xf4'
		&& *(r+1) >= '\x80' && *(r+1) <= '\x8f'
		&& *(r+2) >= '\x80' && *(r+2) <= '\xbf'
		&& *(r+3) >= '\x80' && *(r+3) <= '\xbf') return 4;
	return -1;
}

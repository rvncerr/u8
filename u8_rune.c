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

int u8_rune_compare(const char *r1, const char *r2) {
	int r1_length = u8_rune_length(r1);
	int r2_length = u8_rune_length(r2);

	if(r1_length == r2_length) {
		for(int i = 0; i < r1_length; i++) {
			if(r1[i] != r2[i]) {
				return r1[i] < r2[i] ? -1 : 1;
			}
		}
		return 0;
	} else {
		return r1_length < r2_length ? -1 : 1;
	}
}


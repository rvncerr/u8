#include "u8.h" 

int u8_rune_length(const char *p) {
	if(*p == '\x00') return 0;
	if(*p > '\x00' && *p <= '\x7f') return 1;
	if(*p >= '\xc2' && *p <= '\xdf'
		&& *(p+1) >= '\x80' && *(p+1) <= '\xbf') return 2;
	if(*p == '\xe0'
		&& *(p+1) >= '\xa0' && *(p+1) <= '\xbf'
		&& *(p+2) >= '\x80' && *(p+2) <= '\xbf') return 3;
	if(*p >= '\xe1' && *p <= '\xec'
		&& *(p+1) >= '\x80' && *(p+1) <= '\xbf'
		&& *(p+2) >= '\x80' && *(p+2) <= '\xbf') return 3;
	if(*p == '\xed'
		&& *(p+1) >= '\x80' && *(p+1) <= '\x9f'
		&& *(p+2) >= '\x80' && *(p+2) <= '\xbf') return 3;
	if(*p == '\xf0'
		&& *(p+1) >= '\x90' && *(p+1) <= '\xbf'
		&& *(p+2) >= '\x80' && *(p+2) <= '\xbf'
		&& *(p+3) >= '\x80' && *(p+3) <= '\xbf') return 4;
	if(*p >= '\xf1' && *p <= '\xf3'
		&& *(p+1) >= '\x80' && *(p+1) <= '\xbf'
		&& *(p+2) >= '\x80' && *(p+2) <= '\xbf'
		&& *(p+3) >= '\x80' && *(p+3) <= '\xbf') return 4;
	if(*p == '\xf4'
		&& *(p+1) >= '\x80' && *(p+1) <= '\x8f'
		&& *(p+2) >= '\x80' && *(p+2) <= '\xbf'
		&& *(p+3) >= '\x80' && *(p+3) <= '\xbf') return 4;
	return -1;
}

int u8_rune_compare(const char *rune1, const char *rune2) {
	int rune1_length = u8_rune_length(rune1);
	int rune2_length = u8_rune_length(rune2);

	if(rune1_length == rune2_length) {
		for(int i = 0; i < rune1_length; i++) {
			if(rune1[i] != rune2[i]) {
				return rune1[i] < rune2[i] ? -1 : 1;
			}
		}
		return 0;
	} else {
		return rune1_length < rune2_length ? -1 : 1;
	}
}

int u8_length(const char *s) {
	const char *p = s;
	int length = 0;
	for(;;) {
		int rune_length = u8_rune_length(p);
		if(rune_length < 0) return -1;
		if(rune_length == 0) break;

		p += rune_length;
		length++;
	}
	return length;
}


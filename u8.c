#include "u8.h" 

int u8_rune_length(const char *p) {
	if(*p == 0x00) return 0;
	if(*p > 0x00 && *p <= 0x7f) return 1;
	if(*p >= 0xc2 && *p <= 0xdf
		&& *(p+1) >= 0x80 && *(p+1) <= 0xbf) return 2;
	if(*p == 0xe0
		&& *(p+1) >= 0xa0 && *(p+1) <= 0xbf
		&& *(p+2) >= 0x80 && *(p+2) <= 0xbf) return 3;
	if(*p >= 0xe1 && *p <= 0xec
		&& *(p+1) >= 0x80 && *(p+1) <= 0xbf
		&& *(p+2) >= 0x80 && *(p+2) <= 0xbf) return 3;
	if(*p == 0xed
		&& *(p+1) >= 0x80 && *(p+1) <= 0x9f
		&& *(p+2) >= 0x80 && *(p+2) <= 0xbf) return 3;
	if(*p == 0xf0
		&& *(p+1) >= 0x90 && *(p+1) <= 0xbf
		&& *(p+2) >= 0x80 && *(p+2) <= 0xbf
		&& *(p+3) >= 0x80 && *(p+3) <= 0xbf) return 4;
	if(*p >= 0xf1 && *p <= 0xf3
		&& *(p+1) >= 0x80 && *(p+1) <= 0xbf
		&& *(p+2) >= 0x80 && *(p+2) <= 0xbf
		&& *(p+3) >= 0x80 && *(p+3) <= 0xbf) return 4;
	if(*p == 0xf4
		&& *(p+1) >= 0x80 && *(p+1) <= 0x8f
		&& *(p+2) >= 0x80 && *(p+2) <= 0xbf
		&& *(p+3) >= 0x80 && *(p+3) <= 0xbf) return 4;
	return -1;
}

void u8_make_valid(char *s) {
	char *p = s;
	for(;;) {
		int rune_length = u8_rune_length(p);
		if(rune_length > 0) p += rune_length;
		else if(rune_length == 0) break;
		else { *p = ' '; p++; }
	}
}

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

int u8_rune_length_xml(const char *p) {
	int length = u8_rune_length(p);
	if(length == 1) {
		if(*p == '\x09') return 1;
		if(*p == '\x0a') return 1;
		if(*p == '\x0d') return 1;
		if(*p >= '\x20') return 1;
		return -1;
	}
	if(length == 2) {
		if(*p <= '\xd7') return 2;
		if(*p >= '\xe0') return 2;
		return -1;
	}
	return length;
}

bool u8_rune_is_valid(const char *p) {
	return u8_rune_length(p) != -1;
}

void u8_sanitize(char *s) {
	char *p = s;
	for(;;) {
		int rune_length = u8_rune_length(p);
		if(rune_length > 0) p += rune_length;
		else if(rune_length == 0) break;
		else { *p = ' '; p++; }
	}
}

void u8_sanitize_xml(char *s) {
	char *p = s;
	for(;;) {
		int rune_length = u8_rune_length_xml(p);
		if(rune_length > 0) p += rune_length;
		else if(rune_length == 0) break;
		else { *p = ' '; p++; }
	}
}

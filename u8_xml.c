#include "u8.h"

int u8_rune_length_xml(const char *p) {
	int length = u8_rune_length(p);
	if(length == 1) {
		if(*p != '\x09' && *p != '\x0a' && *p != '\x0d' && *p < '\x20') return -1;
	}
	if(length == 3) {
		if(*p == '\xef' && *(p+1) == '\xbf' && ((*(p+2) == '\xbe') || (*(p+2) == '\xbf'))) return -1;
	}
	return length;
}

bool u8_rune_is_valid_xml(const char *p) {
	return u8_rune_length_xml(p) != -1;
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


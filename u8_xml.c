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



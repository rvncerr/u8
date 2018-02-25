#include "u8.h"

void u8_sanitize(char *s, int how) {
	char *p = s;
	int (*f_rune_length)(const char*);
	
	switch(how) {
	case U8_SANITIZE_UTF8:
		f_rune_length = u8_rune_length;
		break;
	case U8_SANITIZE_XML:
		f_rune_length = u8_rune_length_xml;
		break;
	default:
		return;
	}

	for(;;) {
		int rune_length = f_rune_length(p);
		if(rune_length > 0) p += rune_length;
		else if(rune_length == 0) break;
		else { *p = ' '; p++; }
	}
}


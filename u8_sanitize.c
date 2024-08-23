#include "u8.h"

void u8_sanitize(char *s) {
	char *p = s;

	for(;;) {
		int rune_length = u8_rune_length(p);
		if(rune_length > 0) p += rune_length;
		else if(rune_length == 0) break;
		else { *p = ' '; p++; }
	}
}


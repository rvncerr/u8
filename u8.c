#include "u8.h" 

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


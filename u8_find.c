#include "u8.h" 

const char *u8_find_rune(const char *s, const char *rune) {
	const char *p = s;
	
	for(;;) {
		int p_length = u8_rune_length(p);

		if(p_length < 0) return NULL;
		if(p_length == 0) return NULL;
		if(u8_rune_compare(p, rune) == 0) return p;
		
		p += p_length;
	}
}


#include "CUnit/Basic.h"
#include "u8.h"

void test_u8_rune_length() {
	CU_ASSERT( 0 == u8_rune_length("\x00\x00\x00\x00"));
	CU_ASSERT( 1 == u8_rune_length("\x01\x00\x00\x00"));
	CU_ASSERT( 1 == u8_rune_length("\x7f\x00\x00\x00"));
	CU_ASSERT(-1 == u8_rune_length("\x80\x00\x00\x00"));
	CU_ASSERT(-1 == u8_rune_length("\xc1\x00\x00\x00"));
}

void test_u8_find_rune() {
	const char *source1 = "0123456789abcdef";
	CU_ASSERT(source1      == u8_find_rune(source1, "0"));
	CU_ASSERT(source1 + 1  == u8_find_rune(source1, "1"));
	CU_ASSERT(source1 + 2  == u8_find_rune(source1, "2"));
	CU_ASSERT(source1 + 3  == u8_find_rune(source1, "3"));
	CU_ASSERT(source1 + 4  == u8_find_rune(source1, "4"));
	CU_ASSERT(source1 + 5  == u8_find_rune(source1, "5"));
	CU_ASSERT(source1 + 6  == u8_find_rune(source1, "6"));
	CU_ASSERT(source1 + 7  == u8_find_rune(source1, "7"));
	CU_ASSERT(source1 + 8  == u8_find_rune(source1, "8"));
	CU_ASSERT(source1 + 9  == u8_find_rune(source1, "9"));
	CU_ASSERT(source1 + 10 == u8_find_rune(source1, "a"));
	CU_ASSERT(source1 + 11 == u8_find_rune(source1, "b"));
	CU_ASSERT(source1 + 12 == u8_find_rune(source1, "c"));
	CU_ASSERT(source1 + 13 == u8_find_rune(source1, "d"));
	CU_ASSERT(source1 + 14 == u8_find_rune(source1, "e"));
	CU_ASSERT(source1 + 15 == u8_find_rune(source1, "f"));
	CU_ASSERT(NULL         == u8_find_rune(source1, "g"));

	const char *source2 = "0123456789" "\xc2\xa0" "abcdef";
	CU_ASSERT(source2      == u8_find_rune(source2, "0"));
	CU_ASSERT(source2 + 1  == u8_find_rune(source2, "1"));
	CU_ASSERT(source2 + 2  == u8_find_rune(source2, "2"));
	CU_ASSERT(source2 + 3  == u8_find_rune(source2, "3"));
	CU_ASSERT(source2 + 4  == u8_find_rune(source2, "4"));
	CU_ASSERT(source2 + 5  == u8_find_rune(source2, "5"));
	CU_ASSERT(source2 + 6  == u8_find_rune(source2, "6"));
	CU_ASSERT(source2 + 7  == u8_find_rune(source2, "7"));
	CU_ASSERT(source2 + 8  == u8_find_rune(source2, "8"));
	CU_ASSERT(source2 + 9  == u8_find_rune(source2, "9"));
	CU_ASSERT(source2 + 10 == u8_find_rune(source2, "\xc2\xa0"));
	CU_ASSERT(source2 + 12 == u8_find_rune(source2, "a"));
	CU_ASSERT(source2 + 13 == u8_find_rune(source2, "b"));
	CU_ASSERT(source2 + 14 == u8_find_rune(source2, "c"));
	CU_ASSERT(source2 + 15 == u8_find_rune(source2, "d"));
	CU_ASSERT(source2 + 16 == u8_find_rune(source2, "e"));
	CU_ASSERT(source2 + 17 == u8_find_rune(source2, "f"));
	CU_ASSERT(NULL         == u8_find_rune(source2, "g"));
}

void test_u8_loop() {
	const char *source = "Hello, world! Привет, мир!";

	int counter = 0;
	for(const char *r = source; !u8_end(r); r = u8_next(r)) {
		counter++;
	}
	CU_ASSERT(counter == 26);
}

int main(int argc, char **argv) {
	CU_pSuite pSuite = NULL;
	if(CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();
	
	pSuite = CU_add_suite("Runes", NULL, NULL);
	if(NULL == pSuite) { CU_cleanup_registry(); return CU_get_error(); }
	if(NULL == CU_add_test(pSuite, "u8_rune_length", test_u8_rune_length)) { CU_cleanup_registry(); return CU_get_error(); }

	if(NULL == CU_add_test(pSuite, "u8_find_rune", test_u8_find_rune)) { CU_cleanup_registry(); return CU_get_error(); }

	pSuite = CU_add_suite("Loop", NULL, NULL);
	if(NULL == pSuite) { CU_cleanup_registry(); return CU_get_error(); }
	if(NULL == CU_add_test(pSuite, "u8_loop", test_u8_loop)) { CU_cleanup_registry(); return CU_get_error(); }

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

#include "CUnit/Basic.h"
#include "u8.h"

void test_u8_rune_length() {
	CU_ASSERT( 0 == u8_rune_length("\x00\x00\x00\x00"));
	CU_ASSERT( 1 == u8_rune_length("\x01\x00\x00\x00"));
	CU_ASSERT( 1 == u8_rune_length("\x7f\x00\x00\x00"));
	CU_ASSERT(-1 == u8_rune_length("\x80\x00\x00\x00"));
	CU_ASSERT(-1 == u8_rune_length("\xc1\x00\x00\x00"));
}

void test_u8_rune_length_xml() {
}

int main(int argc, char **argv) {
	CU_pSuite pSuite = NULL;
	if(CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();
	
	pSuite = CU_add_suite("Runes", NULL, NULL);
	if(NULL == pSuite) { CU_cleanup_registry(); return CU_get_error(); }
	if(NULL == CU_add_test(pSuite, "u8_rune_length", test_u8_rune_length)) { CU_cleanup_registry(); return CU_get_error(); }
	if(NULL == CU_add_test(pSuite, "u8_rune_length_xml", test_u8_rune_length_xml)) { CU_cleanup_registry(); return CU_get_error(); }

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

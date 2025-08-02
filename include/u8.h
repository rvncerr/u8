/**
 * @file u8.h
 * @brief UTF-8 Library for C.
 * 
 * This library provides UTF-8 aware versions of common C string functions.
 * While standard C string functions operate on bytes, these functions
 * operate on UTF-8 runes (complete Unicode characters).
 * 
 * A "rune" in this context refers to a single UTF-8 encoded character,
 * which may be 1-4 bytes in length.
 */

#ifndef U8_H
#define U8_H

#include <stdlib.h>
#include <string.h>

/**
 * @brief Get the byte length of a UTF-8 rune.
 * 
 * @param r Pointer to the start of a UTF-8 rune.
 * @return The number of bytes in the rune (1-4), or -1 if invalid.
 */
int u8_rune_length(const char *r);

/**
 * @brief Advance to the next rune in a UTF-8 string.
 * 
 * @note This function in conjunction with u8_end() is used to iterate
 * through a UTF-8 string rune by rune.
 *
 * @code 
 * const char *s = "Hello, 世界";
 * for (const char *r = s; !u8_end(r); r = u8_next(r)) {
 *   printf("%s\n", r);
 * }
 * @endcode
 * 
 * @param s Pointer to current position in UTF-8 string.
 * @return Pointer to the next rune, or NULL if at end or invalid.
 *
 * @see u8_end()
 */
const char *u8_next(const char *s);

/**
 * @brief Check if at the end of a UTF-8 string.
 *
 * @note This function is used in conjunction with u8_next() to iterate
 * through a UTF-8 string rune by rune.
 *
 * @param s Pointer to current position in UTF-8 string.
 * @return 1 if at end (null terminator), 0 otherwise.
 *
 * @see u8_next()
 */
int u8_end(const char *s);

/**
 * @brief Compare two UTF-8 runes.
 * 
 * @param r1 Pointer to first UTF-8 rune.
 * @param r2 Pointer to second UTF-8 rune.
 * @return -1 if r1 < r2, 0 if equal, 1 if r1 > r2.
 */
int u8_rune_compare(const char *r1, const char *r2);

/**s
 * @brief qsort-compatible wrapper for u8_rune_compare.
 * 
 * @code 
 * char *runes[] = {"H", "e", "l", "l", "o"};
 * qsort(runes, 4, sizeof(char *), u8_rune_qcompare);
 * @endcode
 *
 * @param r1 Pointer to first rune (as void*).
 * @param r2 Pointer to second rune (as void*).
 * @return -1 if r1 < r2, 0 if equal, 1 if r1 > r2.
 * 
 * @see qsort() standard library function
 */
int u8_rune_qcompare(void *r1, void *r2);

/**
 * @brief Compare two UTF-8 strings.
 * 
 * @param s1 First null-terminated UTF-8 string.
 * @param s2 Second null-terminated UTF-8 string.
 * @return -1 if s1 < s2, 0 if equal, 1 if s1 > s2.
 */
int u8_compare(const char *s1, const char *s2);

/**
 * @brief Compare up to n runes of two UTF-8 strings.
 * 
 * @param s1 First null-terminated UTF-8 string.
 * @param s2 Second null-terminated UTF-8 string.
 * @param n Maximum number of runes to compare.
 * @return -1 if s1 < s2, 0 if equal (or n runes compared), 1 if s1 > s2.
 */
int u8_ncompare(const char *s1, const char *s2, unsigned int n);

/**
 * @brief qsort-compatible wrapper for u8_compare.
 * 
 * @code 
 * char *strings[] = {"Hello", "World", "Hello", "World"};
 * qsort(strings, 4, sizeof(char *), u8_qcompare);
 * @endcode
 * 
 * @param s1 Pointer to first string (as void*)
 * @param s2 Pointer to second string (as void*)
 * @return -1 if s1 < s2, 0 if equal, 1 if s1 > s2
 */
int u8_qcompare(void *s1, void *s2);

/**
 * @brief Count the number of runes in a UTF-8 string.
 * 
 * @param s Null-terminated UTF-8 string.
 * @return Number of UTF-8 runes in the string.
 */
int u8_length(const char *s);

/**
 * @brief Find the first occurrence of a rune in a string.
 * 
 * @param s Null-terminated UTF-8 string to search in.
 * @param rune UTF-8 rune to search for.
 * @return Pointer to first occurrence of rune, or NULL if not found.
 */
const char *u8_find_rune(const char *s, const char *rune);

/**
 * @brief Sanitize a UTF-8 string by removing invalid sequences.
 * 
 * @param s UTF-8 string to sanitize (modified in-place).
 */
void u8_sanitize(char *s);

#endif

#include "u8.h"

// https://www.unicode.org/versions/Unicode15.0.0/UnicodeStandard-15.0.pdf
// Based on Table 3-7.

int u8_rune_length(const char *r) {
  // If the string is NULL, return -1. This is a sanity check.
  if (!r)
    return -1;

  // Single byte (ASCII).
  if (*r == '\x00')
    return 0;
  if (*r > '\x00' && *r <= '\x7f')
    return 1;

  // Two bytes.
  if (*r >= '\xc2' && *r <= '\xdf') {
    if (*(r + 1) >= '\x80' && *(r + 1) <= '\xbf')
      return 2;
    return -1;
  }

  // Three bytes.
  if (*r == '\xe0') {
    if (*(r + 1) >= '\xa0' && *(r + 1) <= '\xbf' && *(r + 2) >= '\x80' &&
        *(r + 2) <= '\xbf')
      return 3;
    return -1;
  }
  if (*r >= '\xe1' && *r <= '\xec') {
    if (*(r + 1) >= '\x80' && *(r + 1) <= '\xbf' && *(r + 2) >= '\x80' &&
        *(r + 2) <= '\xbf')
      return 3;
    return -1;
  }
  if (*r == '\xed') {
    if (*(r + 1) >= '\x80' && *(r + 1) <= '\x9f' && *(r + 2) >= '\x80' &&
        *(r + 2) <= '\xbf')
      return 3;
    return -1;
  }
  if (*r >= '\xee' && *r <= '\xef') {
    if (*(r + 1) >= '\x80' && *(r + 1) <= '\xbf' && *(r + 2) >= '\x80' &&
        *(r + 2) <= '\xbf')
      return 3;
    return -1;
  }

  // Four bytes.
  if (*r == '\xf0') {
    if (*(r + 1) >= '\x90' && *(r + 1) <= '\xbf' && *(r + 2) >= '\x80' &&
        *(r + 2) <= '\xbf' && *(r + 3) >= '\x80' && *(r + 3) <= '\xbf')
      return 4;
    return -1;
  }
  if (*r >= '\xf1' && *r <= '\xf3') {
    if (*(r + 1) >= '\x80' && *(r + 1) <= '\xbf' && *(r + 2) >= '\x80' &&
        *(r + 2) <= '\xbf' && *(r + 3) >= '\x80' && *(r + 3) <= '\xbf')
      return 4;
    return -1;
  }
  if (*r == '\xf4') {
    if (*(r + 1) >= '\x80' && *(r + 1) <= '\x8f' && *(r + 2) >= '\x80' &&
        *(r + 2) <= '\xbf' && *(r + 3) >= '\x80' && *(r + 3) <= '\xbf')
      return 4;
    return -1;
  }

  return -1;
}

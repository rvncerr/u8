#include "u8.h"

int u8_rune_compare(const char *r1, const char *r2) {
  int r1_length = u8_rune_length(r1);
  int r2_length = u8_rune_length(r2);

  if (r1_length == r2_length) {
    for (int i = 0; i < r1_length; i++) {
      if (r1[i] != r2[i]) {
        return r1[i] < r2[i] ? -1 : 1;
      }
    }
    return 0;
  } else {
    return r1_length < r2_length ? -1 : 1;
  }
}

int u8_rune_qcompare(void *r1, void *r2) {
  return u8_rune_compare((const char *)r1, (const char *)r2);
}

int u8_compare(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s2 != '\0') {
    int r = u8_rune_compare(s1, s2);
    if (r != 0) {
      return r;
    }
    s1 = u8_next(s1);
    s2 = u8_next(s2);
  }
  if (*s1 == '\0' && *s2 == '\0') {
    return 0;
  } else {
    return *s1 == '\0' ? -1 : 1;
  }
}

int u8_ncompare(const char *s1, const char *s2, unsigned int n) {
  while (*s1 != '\0' && *s2 != '\0' && n > 0) {
    int r = u8_rune_compare(s1, s2);
    if (r != 0) {
      return r;
    }
    s1 = u8_next(s1);
    s2 = u8_next(s2);
    n--;
  }
  if (n == 0) {
    return 0;
  } else {
    return *s1 == '\0' ? -1 : 1;
  }
}

int u8_qcompare(void *s1, void *s2) {
  return u8_compare((const char *)s1, (const char *)s2);
}

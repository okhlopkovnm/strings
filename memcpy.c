#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (n == 0 || dest == NULL || src == NULL) return dest;
  const char *s = (const char *)src;
  char *d = (char *)dest;
  for (s21_size_t i = 0; i < n; ++i) {
    d[i] = s[i];
  }
  return dest;
}

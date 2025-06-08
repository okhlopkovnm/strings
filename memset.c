#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *d = (char *)str;
  for (s21_size_t i = 0; i < n; ++i) {
    d[i] = c;
  }
  return str;
}

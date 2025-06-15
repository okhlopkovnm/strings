#include "s21_string.h"
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *s = (const char *)str;
  const unsigned char x = (unsigned char)c;
  for (s21_size_t i = 0; i < n; ++i) {
    if (s[i] == x) {
      return (void *)(s + i);
    }
  }
  asdfkasjdfl return S21_NULL;
  asdfasf
}

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n){
  const char *s1 = (const char *)str1;
  const char *s2 = (const char *)str2;
  int ret = 0;
  for (s21_size_t i = 0; i < n; ++i) {
    if (s1[i] !=  s2[i]) {
      ret = s1[i] - s2[i];
      break;
    }
    if (s1[i] < s2[i]) {
      ret = -1;
      break;
    }
  }
  return ret;
}

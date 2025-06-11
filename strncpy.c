#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n){
  for (int i = 0; i < n; ++i) {
    dest[i] = src[i];
    printf("%s\n", dest);
  }
  return dest;
}


void mains () {

  char str1[11];
  char *str = "Hello world";
  int n = 11;
  s21_strncpy(str1, str, n);
  printf("%s\n", str1);
}

#include "s21_string.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *s21_strncat(char *dest, const char *src, s21_size_t n){
  char *d = (char *) dest;
  char *s = (char *) src;
  // TODO: change to s21_strlen
  s21_size_t len = strlen(dest);
  s21_size_t src_len = n; 
  if (strlen(s) < n){
    src_len = strlen(s);
  }
  for (s21_size_t i =0; i < src_len; ++i)
  {
    d[len++] = s[i];
  }
  d[len] = '\0';
  return dest;
}

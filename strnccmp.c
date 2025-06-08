
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
  int ret = 0;
  for (int i = 0; i < n; ++i){
    ret = str1[i] - str2[i];
    if (ret != 0) {
      break;
    }
  }
  return ret;
}

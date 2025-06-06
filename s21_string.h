#ifndef S21_STRINGS_H
#define S21_STRINGS_H

#define S21_NULL ((void *)0)

typedef unsigned long s21_size_t;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_mmemcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_mmemcpy(void *dest, const void *src, s21_size_t n);
void *s21_mmemset(void *str, int c, s21_size_t n);
char *s21_mstrncat(char *dest, const char *src, s21_size_t n);
char *s21_mstrchr(const char *str, int c);
int s21_mstrncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_mstrncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_mstrcspn(const char *str1, const char *str2);
char *s21_mstrerror(int errnum);
s21_size_t s21_mstrlen(const char *str);
char *s21_mstrpbrk(const char *str1, const char *str2);
char *s21_mstrrchr(const char *str, int c);
char *s21_mstrstr(const char *haystack, const char *needle);
char *s21_mstrtok(char *str, const char *delim);


#endif

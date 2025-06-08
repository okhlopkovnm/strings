#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(memchr_first_symbol) {
  char str[] = "Hello world";
  char c = 'H';
  void *result1 = s21_memchr(str, c, strlen(str));
  void *result2 = memchr(str, c, strlen(str));
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST

START_TEST(memchr_middle_symbol) {
  char str[] = "Hello world";
  char c = 'w';
  void *result1 = s21_memchr(str, c, strlen(str));
  void *result2 = memchr(str, c, strlen(str));
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST

START_TEST(memchr_last_symbol) {
  char str[] = "Hello world";
  char c = 'd';
  void *result1 = s21_memchr(str, c, strlen(str));
  void *result2 = memchr(str, c, strlen(str));
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST

START_TEST(memchr_middle_with_multiple) {
  char str[] = "Hello world";
  char c = 'd';
  void *result1 = s21_memchr(str, c, strlen(str));
  void *result2 = memchr(str, c, strlen(str));
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-overread"
START_TEST(memchr_len_greater) {
  char str[] = "Hello world";
  char c = 'd';
  void *result1 = s21_memchr(str, c, strlen(str) + 100);
  void *result2 = memchr(str, c, strlen(str) + 100);
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST
START_TEST(memchr_len_minus) {
  char str[] = "Hello world";
  char c = 'd';
  void *result1 = s21_memchr(str, c, -10);
  void *result2 = memchr(str, c, -10);
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
#pragma GCC diagnostic pop

START_TEST(memchr_len_0_null) {
  char str[] = "Hello world";
  char c = 'd';
  void *result1 = s21_memchr(str, c, 0);
  void *result2 = memchr(str, c, 0);
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
  ck_assert_ptr_eq(result1, S21_NULL);
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST

START_TEST(memchr_str_empty) {
  char str[] = "";
  char c = 'd';
  void *result1 = s21_memchr(str, c, strlen(str));
  void *result2 = memchr(str, c, strlen(str));
  ck_assert_ptr_eq(result1, S21_NULL);
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST

START_TEST(memchr_c_minus) {
  char str[] = "";
  char c = -1;
  void *result1 = s21_memchr(str, c, strlen(str));
  void *result2 = memchr(str, c, strlen(str));
  ck_assert_ptr_eq(result1, S21_NULL);
  ck_assert_uint_eq((char *)result1 - str, (char *)result2 - str);
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, memchr_first_symbol);
  tcase_add_test(tc_core, memchr_middle_symbol);
  tcase_add_test(tc_core, memchr_last_symbol);
  tcase_add_test(tc_core, memchr_middle_with_multiple);
  tcase_add_test(tc_core, memchr_len_greater);
  tcase_add_test(tc_core, memchr_len_minus);
  suite_add_tcase(s, tc_core);
  TCase *tc_null = tcase_create("null");
  tcase_add_test(tc_core, memchr_len_0_null);
  tcase_add_test(tc_core, memchr_str_empty);
  tcase_add_test(tc_core, memchr_c_minus);
  suite_add_tcase(s, tc_null);
  return s;
}

int main(void) {
  Suite *s = strlen_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int failures = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failures == 0) ? 0 : 1;
}

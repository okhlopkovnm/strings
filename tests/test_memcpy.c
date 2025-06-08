#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(simple_copy) {
  char *str = "Hello world";
  char str1[100] = {0};
  char str2[100] = {0};
  int n = 12;
  void *result1 = s21_memcpy(str1, str, n);
  void *result2 = memcpy(str2, str, n);
  ck_assert_mem_eq(str1, str2, 100);
  ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

START_TEST(copy_5_symbols) {
  char *str = "Hello world";
  char str1[100] = {0};
  char str2[100] = {0};
  int n = 5;
  s21_memcpy(str1, str, n);
  memcpy(str2, str, n);
  ck_assert_mem_eq(str1, str2, 100);
}
END_TEST

START_TEST(copy_0) {
  char *str = "Hello world";
  char str1[100] = {0};
  char str2[100] = {0};
  int n = 0;
  s21_memcpy(str1, str, n);
  memcpy(str2, str, n);
  ck_assert_mem_eq(str1, str2, 100);
}
END_TEST

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-overread"
START_TEST(copy_large) {
  char *str = "Hello world";
  char str1[100] = {0};
  char str2[100] = {0};
  int n = 100;
  s21_memcpy(str1, str, n);
  memcpy(str2, str, n);
  ck_assert_mem_eq(str1, str2, 100);
}
END_TEST
#pragma GCC diagnostic pop

Suite *suite(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, simple_copy);
  tcase_add_test(tc_core, copy_5_symbols);
  tcase_add_test(tc_core, copy_0);
  tcase_add_test(tc_core, copy_large);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  Suite *s = suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int failures = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (failures == 0) ? 0 : 1;
}

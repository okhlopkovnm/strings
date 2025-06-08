#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(cat_whole_word) {
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  char *str = "world";
  int n = 5;
  void *result1 = s21_strncat(str1, str, n);
  void *result2 = strncat(str2, str, n);
  ck_assert_ptr_eq(result1, str1);
  ck_assert_mem_eq(str1, str2, 100);
  ck_assert_str_eq(str1, str2);
  ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

START_TEST(cat_first_3_symbols) {
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  char *str = "world";
  int n = 3;
  void *result1 = s21_strncat(str1, str, n);
  void *result2 = strncat(str2, str, n);
  ck_assert_ptr_eq(result1, str1);
  ck_assert_mem_eq(str1, str2, 100);
  ck_assert_str_eq(str1, str2);
  ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

START_TEST(cat_0_symbols) {
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  char *str = "world";
  int n = 0;
  void *result1 = s21_strncat(str1, str, n);
  void *result2 = strncat(str2, str, n);
  ck_assert_ptr_eq(result1, str1);
  ck_assert_mem_eq(str1, str2, 100);
  ck_assert_str_eq(str1, str2);
  ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

START_TEST(cat_n_large) {
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  char *str = "world";
  int n = 10;
  void *result1 = s21_strncat(str1, str, n);
  void *result2 = strncat(str2, str, n);
  ck_assert_ptr_eq(result1, str1);
  ck_assert_mem_eq(str1, str2, 100);
  ck_assert_str_eq(str1, str2);
  ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

START_TEST(src_empty) {
  char str1[100] = "Hello ";
  char str2[100] = "Hello ";
  char *str = "";
  int n = 10;
  void *result1 = s21_strncat(str1, str, n);
  void *result2 = strncat(str2, str, n);
  ck_assert_ptr_eq(result1, str1);
  ck_assert_mem_eq(str1, str2, 100);
  ck_assert_str_eq(str1, str2);
  ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

START_TEST(dest_empty) {
  char str1[100] = "";
  char str2[100] = "";
  char *str = "world";
  int n = 10;
  void *result1 = s21_strncat(str1, str, n);
  void *result2 = strncat(str2, str, n);
  ck_assert_ptr_eq(result1, str1);
  ck_assert_mem_eq(str1, str2, 100);
  ck_assert_str_eq(str1, str2);
  ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

Suite *suite(void) {
  Suite *s = suite_create("s21_strcat");
  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, cat_whole_word);
  tcase_add_test(tc_core, cat_first_3_symbols);
  tcase_add_test(tc_core, cat_0_symbols);
  tcase_add_test(tc_core, cat_n_large);
  tcase_add_test(tc_core, src_empty);
  tcase_add_test(tc_core, dest_empty);
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

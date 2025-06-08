#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(basic) {
  char *str1 = "Hello world";
  char *str2 = "Hello world";
  int n = 11;
  int n1 = s21_strncmp(str1, str2, n);
  int n2 = strncmp(str1, str2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(first_greater) {
  char *str1 = "Hello world";
  char *str2 = "0ello world";
  int n = 11;
  int n1 = s21_strncmp(str1, str2, n);
  int n2 = strncmp(str1, str2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(first_smaller) {
  char *str1 = "0ello world";
  char *str2 = "Hello world";
  int n = 11;
  int n1 = s21_strncmp(str1, str2, n);
  int n2 = strncmp(str1, str2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(first_empty) {
  char *str1 = "";
  char *str2 = "Hello world";
  int n = 11;
  int n1 = s21_strncmp(str1, str2, n);
  int n2 = strncmp(str1, str2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(second_empty) {
  char *str1 = "Hello world";
  char *str2 = "";
  int n = 11;
  int n1 = s21_strncmp(str1, str2, n);
  int n2 = strncmp(str1, str2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(n_zero) {
  char *str1 = "Hello world";
  char *str2 = "Hello world";
  int n = 0;
  int n1 = s21_strncmp(str1, str2, n);
  int n2 = strncmp(str1, str2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(both_empty) {
  char *str1 = "";
  char *str2 = "";
  int n = 11;
  int n1 = s21_strncmp(str1, str2, n);
  int n2 = strncmp(str1, str2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST
Suite *suite(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, basic);
  tcase_add_test(tc_core, first_greater);
  tcase_add_test(tc_core, first_smaller);
  tcase_add_test(tc_core, first_empty);
  tcase_add_test(tc_core, second_empty);
  tcase_add_test(tc_core, both_empty);
  tcase_add_test(tc_core, n_zero);
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

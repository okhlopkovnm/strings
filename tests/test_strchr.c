#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(basic) {
  char *str = "Hello world";
  int i = 'o';
  char *c1 = s21_strchr(str, i);
  char *c2 = strchr(str, i);
//  printf("res %s\n", c1);
  printf("res %s\n", c2);
  ck_assert_str_eq(c1, c2);
}
END_TEST

Suite *suite(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, basic);
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

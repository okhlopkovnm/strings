#include <check.h>
#include <stdio.h>
#include "s21_string.h"
#include <string.h>

START_TEST(simple_set) {
    char str1[100] = {0};
    char str2[100] = {0};
    int n = 12;
    int c = 'H';
    void *result1 = s21_memset(str1, c, n);
    void *result2 = memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 100);
    ck_assert_str_eq(str1, str2);
    ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

START_TEST(set_0) {
    char str1[100] = {0};
    char str2[100] = {0};
    int n = 0;
    int c = 'H';
    void *result1 = s21_memset(str1, c, n);
    void *result2 = memset(str2, c, n);
    ck_assert_mem_eq(str1, str2, 100);
    ck_assert_str_eq(str1, str2);
    ck_assert_mem_eq(result1, result2, 100);
}
END_TEST

Suite *suite(void) {
    Suite *s = suite_create("s21_memset");
    TCase *tc_core = tcase_create("core");
    tcase_add_test(tc_core, simple_set);
    tcase_add_test(tc_core, set_0);
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

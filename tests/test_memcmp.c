#include <check.h>
#include <stdio.h>
#include "s21_string.h"
#include <string.h>

START_TEST(memcmp_equal) {
    char str1[] = "Hello world";
    char str2[] = "Hello world";
    int result1 = s21_memcmp(str1, str2, strlen(str1));
    int result2 = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(memcmp_first_greater) {
    char str1[] = "Hello world";
    char str2[] = "0ello world";
    int result1 = s21_memcmp(str1, str2, strlen(str1));
    int result2 = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(memcmp_first_smaller) {
    char str1[] = "Hello 1orld";
    char str2[] = "Hello world";
    int result1 = s21_memcmp(str1, str2, strlen(str1));
    int result2 = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(memcmp_first_shorter) {
    char str1[] = "Hello";
    char str2[] = "Hello world";
    int result1 = s21_memcmp(str1, str2, strlen(str1));
    int result2 = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(memcmp_first_longer) {
    char str1[] = "Hello world";
    char str2[] = "Hello";
    int result1 = s21_memcmp(str1, str2, strlen(str1));
    int result2 = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(memcmp_first_empty) {
    char str1[] = "";
    char str2[] = "Hello world";
    int result1 = s21_memcmp(str1, str2, strlen(str1));
    int result2 = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(result1, result2);
    ck_assert_int_eq(result1, 0);
}
END_TEST

START_TEST(memcmp_first_empty2) {
    char str1[] = "";
    char str2[] = "Hello world";
    int result1 = s21_memcmp(str1, str2, strlen(str2));
    int result2 = memcmp(str1, str2, strlen(str2));
    ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(memcmp_second_empty) {
    char str1[] = "Hello world";
    char str2[] = "";
    int result1 = s21_memcmp(str1, str2, strlen(str2));
    int result2 = memcmp(str1, str2, strlen(str2));
    ck_assert_int_eq(result1, result2);
    ck_assert_int_eq(result1, 0);
}
END_TEST

START_TEST(memcmp_both_empty) {
    char str1[] = "";
    char str2[] = "";
    int result1 = s21_memcmp(str1, str2, strlen(str2));
    int result2 = memcmp(str1, str2, strlen(str2));
    ck_assert_int_eq(result1, result2);
    ck_assert_int_eq(result1, 0);
}
END_TEST

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-overread"
START_TEST(memcmp_n_negative) {
    char str1[] = "Hello world";
    char str2[] = "Hello world";
    int n = -100;
    int result1 = s21_memcmp(str1, str2, n);
    int result2 = memcmp(str1, str2, n);
    ck_assert_int_eq(result1, result2);
}
END_TEST
START_TEST(memcmp_n_large) {
    char str1[] = "Hello world";
    char str2[] = "Hello world";
    int n = 100;
    int result1 = s21_memcmp(str1, str2, n);
    int result2 = memcmp(str1, str2, n);
    ck_assert_int_eq(result1, result2);
}
END_TEST
#pragma GCC diagnostic pop

Suite *strlen_suite(void) {
    Suite *s = suite_create("s21_memcmp");
    TCase *tc_core = tcase_create("core");
    tcase_add_test(tc_core, memcmp_equal);
    tcase_add_test(tc_core, memcmp_first_greater);
    tcase_add_test(tc_core, memcmp_first_smaller);
    tcase_add_test(tc_core, memcmp_first_shorter);
    tcase_add_test(tc_core, memcmp_first_longer);
    tcase_add_test(tc_core, memcmp_first_empty);
    tcase_add_test(tc_core, memcmp_first_empty2);
    tcase_add_test(tc_core, memcmp_second_empty);
    tcase_add_test(tc_core, memcmp_both_empty);
    suite_add_tcase(s, tc_core);

    TCase *tc_edge = tcase_create("edge");
    tcase_add_test(tc_core, memcmp_n_negative);
    tcase_add_test(tc_core, memcmp_n_large);
    suite_add_tcase(s, tc_edge);
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

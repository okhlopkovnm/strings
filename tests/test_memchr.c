#include <check.h>
#include <stdio.h>
#include "s21_string.h"
#include <string.h>


START_TEST(memchr_simple) {
    char str[] = "hello world";
    char c = 'w';
    void *result1 = s21_memchr(str, c, strlen(str));
    void *result2 = memchr(str, c, strlen(str));
    ck_assert_uint_eq((char*)result1 - str, (char*)result2 - str);
}
END_TEST

Suite *strlen_suite(void) {
    Suite *s = suite_create("Memchr");
    TCase *tc_core = tcase_create("Case");
    tcase_add_test(tc_core, memchr_simple);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void) {
    printf("test");
    Suite *s = strlen_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    int failures = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (failures == 0) ? 0 : 1;
}

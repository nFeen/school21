#include "test_runner.h"

START_TEST(ok1) {
  const char str1[123] = "321";
  const char str2[123] = "";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(ok2) {
  const char str1[123] = "321";
  const char str2[123] = "32";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(ok3) {
  const char str1[123] = "321";
  const char str2[123] = "32";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(ok4) {
  const char str1[123] = "321";
  const char str2[123] = "32324";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(ok5) {
  const char str1[123] = "421";
  const char str2[123] = "32324";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *s21_strncmp_cases(void) {
  Suite *suite = suite_create("s21_strncmp_cases");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, ok1);
  tcase_add_test(tc, ok2);
  tcase_add_test(tc, ok3);
  tcase_add_test(tc, ok4);
  tcase_add_test(tc, ok5);

  suite_add_tcase(suite, tc);
  return suite;
}

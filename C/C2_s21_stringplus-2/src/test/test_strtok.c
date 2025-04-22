#include "test_runner.h"

START_TEST(ok1) {
  char s21_str[123] = "1234../../s21_string.h533";
  char str[123] = "1234../../s21_string.h533";
  const char *ch = "/";
  ck_assert_str_eq(strtok(str, ch), s21_strtok(s21_str, ch));
  ck_assert_str_eq(strtok(s21_NULL, ch), s21_strtok(s21_NULL, ch));
}
END_TEST

START_TEST(ok2) {
  char s21_str[123] = "1234../..";
  char str[123] = "1234../..";
  const char *ch = "/";
  ck_assert_str_eq(strtok(str, ch), s21_strtok(s21_str, ch));
  ck_assert_str_eq(strtok(s21_NULL, ch), s21_strtok(s21_NULL, ch));
}
END_TEST

START_TEST(ok3) {
  char s21_str[123] = "1234../../";
  char str[123] = "1234../../";
  const char *ch = "/";
  ck_assert_str_eq(strtok(str, ch), s21_strtok(s21_str, ch));
  ck_assert_str_eq(strtok(s21_NULL, ch), s21_strtok(s21_NULL, ch));
  ck_assert_ptr_eq(strtok(s21_NULL, ch), s21_strtok(s21_NULL, ch));
}
END_TEST

Suite *s21_strtok_cases(void) {
  Suite *suite = suite_create("s21_strtok_cases");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, ok1);
  tcase_add_test(tc, ok2);
  tcase_add_test(tc, ok3);

  suite_add_tcase(suite, tc);
  return suite;
}

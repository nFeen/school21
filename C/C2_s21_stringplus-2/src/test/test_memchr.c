#include "test_runner.h"

START_TEST(find) {
  char str[123] = "321";
  int c = '2';
  s21_size_t n = 2;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(notfind1) {
  char str[123] = "321";
  int c = '4';
  s21_size_t n = 3;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(notfind2) {
  char str[123] = "321";
  int c = '1';
  s21_size_t n = 2;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(notfind3) {
  char str[123] = "321";
  int c = '7';
  s21_size_t n = 6;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(findZero) {
  char str[123] = "321";
  int c = '\0';
  s21_size_t n = 6;
  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

Suite *s21_memchr_cases(void) {
  Suite *suite = suite_create("s21_memchr_cases");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, find);
  tcase_add_test(tc, notfind1);
  tcase_add_test(tc, notfind2);
  tcase_add_test(tc, notfind3);
  tcase_add_test(tc, findZero);

  suite_add_tcase(suite, tc);
  return suite;
}
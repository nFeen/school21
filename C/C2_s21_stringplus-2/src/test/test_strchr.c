#include "test_runner.h"

START_TEST(find) {
  const char *str = "321";
  int c = '3';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(notfind) {
  const char *str = "321";
  int c = '6';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(nothing) {
  const char *str = "";
  int c = '2';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(findfirst) {
  const char *str = "321";
  int c = '3';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

Suite *s21_strchr_cases(void) {
  Suite *suite = suite_create("s21_strchr_cases");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, find);
  tcase_add_test(tc, notfind);
  tcase_add_test(tc, nothing);
  tcase_add_test(tc, findfirst);

  suite_add_tcase(suite, tc);
  return suite;
}

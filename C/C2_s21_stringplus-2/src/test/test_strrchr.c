#include "test_runner.h"

START_TEST(ok1) {
  const char str[123] = "321";
  int c = '2';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(ok2) {
  const char str[123] = "321";
  int c = '5';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(ok3) {
  const char str[123] = "321";
  int c = '3';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite *s21_strrchr_cases(void) {
  Suite *suite = suite_create("s21_strrchr_cases");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, ok1);
  tcase_add_test(tc, ok2);
  tcase_add_test(tc, ok3);

  suite_add_tcase(suite, tc);
  return suite;
}

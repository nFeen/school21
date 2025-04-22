#include "test_runner.h"

START_TEST(ok1) {
  const char src[123] = "321";
  char dest[123];
  s21_size_t n = 2;
  ck_assert_ptr_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(ok2) {
  const char src[123] = "321";
  char dest[123] = "dsf";
  s21_size_t n = 4;
  ck_assert_ptr_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(ok3) {
  const char src[123] = "321";
  char dest[123] = "dsf";
  s21_size_t n = 0;
  ck_assert_ptr_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(ok4) {
  const char src[123] = "";
  char dest[123] = "dsf";
  s21_size_t n = 5;
  ck_assert_ptr_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

Suite *s21_strncat_cases(void) {
  Suite *suite = suite_create("s21_strncat_cases");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, ok1);
  tcase_add_test(tc, ok2);
  tcase_add_test(tc, ok3);
  tcase_add_test(tc, ok4);

  suite_add_tcase(suite, tc);
  return suite;
}

#include "test_runner.h"

START_TEST(find) {
  const char *str = "321";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(findEnd) {
  const char *str = "321\034";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(nothing) {
  const char *str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(find2) {
  const char *str = "321\034rtreIasdgUDYTe6r7^RSErER";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *s21_strlen_cases(void) {
  Suite *suite = suite_create("s21_strlen_cases");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, find);
  tcase_add_test(tc, findEnd);
  tcase_add_test(tc, nothing);
  tcase_add_test(tc, find2);

  suite_add_tcase(suite, tc);
  return suite;
}

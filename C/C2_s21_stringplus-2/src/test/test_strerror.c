#include "test_runner.h"

START_TEST(test_strerror) {
  for (int i = -2; i < 136; i++) ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

Suite* s21_strerror_cases(void) {
  Suite* suite = suite_create("s21_strerror_cases");
  TCase* tc = tcase_create("strerror_tc");

  tcase_add_test(tc, test_strerror);

  suite_add_tcase(suite, tc);
  return suite;
}
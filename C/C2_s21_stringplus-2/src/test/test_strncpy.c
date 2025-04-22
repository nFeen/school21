#include "test_runner.h"
START_TEST(test_strncpy) {
  char str[20] = {"abra"};
  char str_1[20] = {"abra"};
  const char str_2[20] = {" cadabra"};
  const char str_3[20] = {" lol"};
  strncpy(str, str_2, 8);
  s21_strncpy(str_1, str_2, 8);
  ck_assert_str_eq(str, str_1);

  strncpy(str, str_3, 8);
  s21_strncpy(str_1, str_3, 8);
  ck_assert_str_eq(str, str_1);

  char dest[10];
  char s21_dest[10];
  const char* src = "hello";

  ck_assert_str_eq(strncpy(dest, src, 10), s21_strncpy(s21_dest, src, 10));
}
END_TEST

Suite* s21_strncpy_cases(void) {
  Suite* suite = suite_create("s21_strncpy_cases");
  TCase* tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, test_strncpy);

  suite_add_tcase(suite, tc);
  return suite;
}
#include "test_runner.h"

START_TEST(find) {
  const char *str1 = "321";
  const char *str2 = "51";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(nothingStr2) {
  const char *str1 = "321";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(nothingStr1) {
  const char *str1 = "";
  const char *str2 = "13";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(nothingStr12) {
  const char *str1 = "321";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(first) {
  const char *str1 = "234245";
  const char *str2 = "12";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *s21_strcspn_cases(void) {
  Suite *suite = suite_create("s21_strcspn_cases");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, find);
  tcase_add_test(tc, nothingStr2);
  tcase_add_test(tc, nothingStr1);
  tcase_add_test(tc, nothingStr12);
  tcase_add_test(tc, first);

  suite_add_tcase(suite, tc);
  return suite;
}

#include "test_runner.h"

START_TEST(test_strstr) {
  char* str = "Try not. Do, or do not. There is no try.";
  const char* target = "not";
  const char* target1 = "not ";
  char* target2 = "";

  char* result = str;
  char* result1 = str;
  char* result2 = str;
  char* result3 = str;
  char* result4 = str;
  char* result5 = str;

  ck_assert_str_eq(strstr(result, target), s21_strstr(result1, target));
  ck_assert_ptr_eq(strstr(result2, target1), s21_strstr(result3, target1));
  ck_assert_str_eq(strstr(result4, target2), s21_strstr(result5, target2));
  ck_assert_ptr_eq(strstr(target2, target1), s21_strstr(target2, target1));

  const char* haystack = "Testing strstr, heh";
  const char* needle = "str";
  char* result_original = strstr(haystack, needle);
  char* result_custom = s21_strstr(haystack, needle);
  ck_assert_str_eq(result_original, result_custom);

  const char* haystack_1 = "This is another example for testing";
  const char* needle_1 = "another";

  char* result_original_1 = strstr(haystack_1, needle_1);
  char* result_custom_1 = s21_strstr(haystack_1, needle_1);
  ck_assert_str_eq(result_original_1, result_custom_1);

  char s1[] = "aaaaasususususpicioussusususpicious";
  const char s2[] = "susp";
  ck_assert_str_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

Suite* s21_strstr_cases(void) {
  Suite* suite = suite_create("s21_strstr_cases");
  TCase* tc = tcase_create("strstr_tc");

  tcase_add_test(tc, test_strstr);

  suite_add_tcase(suite, tc);
  return suite;
}
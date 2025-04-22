#include "test_runner.h"

START_TEST(find) {
  const char str1[255] = "school_21_wefwg3ewfwefwef2dfwf1erger";
  const char str2[255] = "school_21_FFFFwefwg3ewfefwefwef2dfwf1erger";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(notfind1) {
  const char str1[255] = "";
  const char str2[255] = "";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(notfind2) {
  const char str1[255] = "school_21_wefwg3ewfwefwef2dfwf1erger";
  const char str2[255] = "Achool_21_FFFFwefwg3ewfefwefwef2dfwf1erger";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(find3) {
  const char str1[3] = {'R', 'E'};
  const char str2[4] = {'R', 'E', 'D'};
  s21_size_t n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(find4) {
  const char str1[255] = "\0";
  const char str2[255] = "\0";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite* s21_memcmp_cases(void) {
  Suite* suite = suite_create("s21_memcmp_cases");
  TCase* tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, find);
  tcase_add_test(tc, notfind1);
  tcase_add_test(tc, notfind2);
  tcase_add_test(tc, find3);
  tcase_add_test(tc, find4);

  suite_add_tcase(suite, tc);
  return suite;
}

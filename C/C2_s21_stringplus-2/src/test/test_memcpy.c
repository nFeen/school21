#include "test_runner.h"

START_TEST(notFull) {
  const char src[123] = "321";
  char dest[123];
  s21_size_t c = 2;
  ck_assert_ptr_eq(s21_memcpy(dest, src, c), memcpy(dest, src, c));
}
END_TEST

START_TEST(Full) {
  const char src[123] = "321";
  char dest[123];
  s21_size_t c = 3;
  ck_assert_ptr_eq(s21_memcpy(dest, src, c), memcpy(dest, src, c));
}
END_TEST

START_TEST(zero) {
  const char src[123] = "321";
  char dest[123];
  s21_size_t c = 0;
  ck_assert_ptr_eq(s21_memcpy(dest, src, c), memcpy(dest, src, c));
}
END_TEST

START_TEST(destBigger) {
  const char src[123] = "321";
  char dest[123] = "12345";
  s21_size_t c = 3;
  ck_assert_ptr_eq(s21_memcpy(dest, src, c), memcpy(dest, src, c));
}
END_TEST

START_TEST(bitsBigger) {
  const char src[123] = "321";
  char dest[123];
  s21_size_t c = 5;
  ck_assert_ptr_eq(s21_memcpy(dest, src, c), memcpy(dest, src, c));
}
END_TEST

Suite *s21_memcpy_cases(void) {
  Suite *suite = suite_create("s21_memcpy_cases");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, notFull);
  tcase_add_test(tc, Full);
  tcase_add_test(tc, zero);
  tcase_add_test(tc, destBigger);
  tcase_add_test(tc, bitsBigger);

  suite_add_tcase(suite, tc);
  return suite;
}
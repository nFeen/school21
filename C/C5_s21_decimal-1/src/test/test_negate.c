#include "test_runner.h"

START_TEST(minus_zero) {
  s21_decimal dec1 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 0, my_code = s21_negate(dec1, &dec2);
  ck_assert_int_eq(code, my_code);
  ck_assert_int_eq(dec2.bits[3], 0);
}
END_TEST

START_TEST(error_pow1) {
  /// степень > 28
  s21_decimal dec = {{0, 0, 0, 1000000000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 1, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_pow2) {
  /// степень > 28
  s21_decimal dec = {{-1, 0, 0, 0x1D0000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 1, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
}
END_TEST
START_TEST(error_pow3) {
  /// степень > 28
  s21_decimal dec = {{0, 0, 0, 0x1D0000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 1, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_null_pointer) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = 1, my_code = s21_negate(dec, NULL);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_not_zero_on_zero_place1) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, -1946157056}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 1, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_not_zero_on_zero_place2) {
  s21_decimal dec = {{-1, 0, 0, 0x11C0000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 1, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_all_one) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 1, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_minus_pow) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00810000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 1, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(some_value1) {
  s21_decimal dec = {{24, 346, 356, 0}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 0, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
  ck_assert_int_eq(dec.bits[0], dec2.bits[0]);
  ck_assert_int_eq(dec.bits[1], dec2.bits[1]);
  ck_assert_int_eq(dec.bits[2], dec2.bits[2]);
  ck_assert_int_eq(dec.bits[0] & 0x80000000, dec2.bits[0] & 0x80000000);
}
END_TEST

START_TEST(some_value2) {
  s21_decimal dec = {{24, 346, 356, 0x80000000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 0, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
  ck_assert_int_eq(dec.bits[0], dec2.bits[0]);
  ck_assert_int_eq(dec.bits[1], dec2.bits[1]);
  ck_assert_int_eq(dec.bits[2], dec2.bits[2]);
  ck_assert_int_eq(dec.bits[0] & 0x80000000, dec2.bits[0] & 0x80000000);
}
END_TEST

START_TEST(some_value3) {
  s21_decimal dec = {{1, 0, 0, 0x00040000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 0, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
  ck_assert_int_eq(dec.bits[0], dec2.bits[0]);
  ck_assert_int_eq(dec.bits[1], dec2.bits[1]);
  ck_assert_int_eq(dec.bits[2], dec2.bits[2]);
  ck_assert_int_eq(dec.bits[0] & 0x80000000, dec2.bits[0] & 0x80000000);
}
END_TEST

START_TEST(some_value4) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 0, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
  ck_assert_int_eq(dec.bits[0], dec2.bits[0]);
  ck_assert_int_eq(dec.bits[1], dec2.bits[1]);
  ck_assert_int_eq(dec.bits[2], dec2.bits[2]);
  ck_assert_int_eq(dec.bits[0] & 0x80000000, dec2.bits[0] & 0x80000000);
}
END_TEST

START_TEST(some_value5) {
  s21_decimal dec = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal dec2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int code = 0, my_code = s21_negate(dec, &dec2);
  ck_assert_int_eq(code, my_code);
  ck_assert_int_eq(dec.bits[0], dec2.bits[0]);
  ck_assert_int_eq(dec.bits[1], dec2.bits[1]);
  ck_assert_int_eq(dec.bits[2], dec2.bits[2]);
  ck_assert_int_eq(dec.bits[0] & 0x80000000, dec2.bits[0] & 0x80000000);
}
END_TEST

Suite *s21_negate_cases(void) {
  Suite *suite = suite_create("s21_negate_cases");
  TCase *tc = tcase_create("negate_tc");

  /// краевые случаи
  tcase_add_test(tc, minus_zero);

  tcase_add_test(tc, error_pow1);
  tcase_add_test(tc, error_pow2);
  tcase_add_test(tc, error_pow3);
  tcase_add_test(tc, error_null_pointer);
  tcase_add_test(tc, error_not_zero_on_zero_place1);
  tcase_add_test(tc, error_not_zero_on_zero_place2);
  tcase_add_test(tc, error_all_one);
  tcase_add_test(tc, error_minus_pow);

  /// нормальные значения
  tcase_add_test(tc, some_value1);
  tcase_add_test(tc, some_value2);
  tcase_add_test(tc, some_value3);
  tcase_add_test(tc, some_value4);
  tcase_add_test(tc, some_value5);

  suite_add_tcase(suite, tc);
  return suite;
}
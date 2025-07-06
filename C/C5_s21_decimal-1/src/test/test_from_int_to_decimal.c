#include "test_runner.h"

START_TEST(zero) {
  ///+0
  s21_decimal dec;
  int znach = +0, ans = 0;
  int code = 0, my_code = s21_from_int_to_decimal(znach, &dec);
  int my_ans = s21_get_bit_from_int(dec.bits[3], 31);
  ck_assert_int_eq(ans, my_ans);
  ck_assert_int_eq(znach, dec.bits[0]);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(zero_minus) {
  ///-0
  s21_decimal dec;
  int znach = -0;
  int code = 0, my_code = s21_from_int_to_decimal(znach, &dec);
  ck_assert_int_eq(znach, dec.bits[0]);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(normal_value) {
  /// 1234563421
  s21_decimal dec;
  int znach = 1234563421;
  int code = 0, my_code = s21_from_int_to_decimal(znach, &dec);
  int ans = 0,
      my_ans = s21_get_bit_from_int(dec.bits[3], 31);  // проверка на знак
  ck_assert_int_eq(ans, my_ans);
  ck_assert_int_eq(znach, dec.bits[0]);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(minus_normal_value) {
  ///-1234563421
  s21_decimal dec;
  int znach = -1234563421;
  int code = 0, my_code = s21_from_int_to_decimal(znach, &dec);
  int ans = 1,
      my_ans = s21_get_bit_from_int(dec.bits[3], 31);  // проверка на знак
  ck_assert_int_eq(ans, my_ans);
  ck_assert_int_eq(znach, -(int)dec.bits[0]);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(minus_max_value) {
  ///-2147483648
  s21_decimal dec;
  int znach = -2147483648;
  int code = 0, my_code = s21_from_int_to_decimal(znach, &dec);
  int ans = 1,
      my_ans = s21_get_bit_from_int(dec.bits[3], 31);  // проверка на знак
  ck_assert_int_eq(ans, my_ans);
  ck_assert_int_eq(znach, -(int)dec.bits[0]);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(max_value) {
  /// 2147483647
  s21_decimal dec;
  int znach = 2147483647;
  int code = 0, my_code = s21_from_int_to_decimal(znach, &dec);
  int ans = 0,
      my_ans = s21_get_bit_from_int(dec.bits[3], 31);  // проверка на знак
  ck_assert_int_eq(ans, my_ans);
  ck_assert_int_eq(znach, dec.bits[0]);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(no_decimal) {
  /// non_dec
  int znach = 2147483647;
  int code = 1, my_code = s21_from_int_to_decimal(znach, NULL);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(float_plozit) {
  /// 123.4
  s21_decimal dec;
  int znach = 123.4;
  int code = 0, my_code = s21_from_int_to_decimal(znach, &dec);
  ck_assert_int_eq(code, my_code);
  ck_assert_int_eq(123, dec.bits[0]);
}
END_TEST

Suite *s21_from_int_to_decimal_cases(void) {
  Suite *suite = suite_create("s21_from_int_to_decimal_cases");
  TCase *tc = tcase_create("d_to_f_tc");

  /// краевые случаи
  tcase_add_test(tc, zero);
  tcase_add_test(tc, zero_minus);
  tcase_add_test(tc, normal_value);
  tcase_add_test(tc, minus_normal_value);
  tcase_add_test(tc, minus_max_value);
  tcase_add_test(tc, max_value);
  tcase_add_test(tc, no_decimal);
  tcase_add_test(tc, float_plozit);

  suite_add_tcase(suite, tc);
  return suite;
}

#include "test_runner.h"

START_TEST(zero) {
  ///+0
  s21_decimal dec = {{0, 0, 0, 0}};
  float ans = 0.0, my_ans = 1.0;
  int code = 0, my_code = s21_from_decimal_to_float(dec, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(minus_zero) {
  ///-0
  s21_decimal dec = {{0, 0, 0, 0x80000000}};
  float ans = -0.0, my_ans = 1.0;
  int code = 0, my_code = s21_from_decimal_to_float(dec, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_pow1) {
  /// степень > 28
  s21_decimal dec = {{0, 0, 0, 1000000000}};
  float ans = -0.0, my_ans = 1.0;
  int code = 1, my_code = s21_from_decimal_to_float(dec, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_pow2) {
  /// степень > 28
  s21_decimal dec = {{-1, 0, 0, 0x1D0000}};
  ;
  float ans = -0.0, my_ans = 1.0;
  int code = 1, my_code = s21_from_decimal_to_float(dec, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}
END_TEST
START_TEST(error_pow3) {
  /// степень > 28
  s21_decimal dec = {{0, 0, 0, 0x1D0000}};
  ;
  float ans = -0.0, my_ans = 1.0;
  int code = 1, my_code = s21_from_decimal_to_float(dec, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}
END_TEST

START_TEST(error_null_pointer) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_from_decimal_to_float(decimal, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_not_zero_on_zero_place1) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, -1946157056}};
  float my_ans = 0.0f;
  int code = s21_from_decimal_to_float(decimal, &my_ans);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_not_zero_on_zero_place2) {
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_all_one) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(error_minus_pow) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00810000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(max_value) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  float ans = 79228162514264337593543950335.0, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(min_value) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  float ans = -79228162514264337593543950335.0, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(max_value_pow_1) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  float ans = 7922816251426433759354395033.5, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(min_value_pow_1) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  float ans = -7922816251426433759354395033.5, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value1) {
  // 20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  float ans = 20995463066280049462289146839.0, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value2) {
  // -20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  float ans = -20995463066280049462289146839.0, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value3) {
  // 0.0000457763671875
  s21_decimal decimal = {{0x94D74F43, 0x6A, 0x0, 0x100000}};
  float ans = 0.0000457763671875, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value4) {
  // -0.0000457763671875
  s21_decimal decimal = {{0x94D74F43, 0x6A, 0x0, 0x80100000}};
  float ans = -0.0000457763671875, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value5) {
  // 0.000121307373046875
  s21_decimal decimal = {{0x12E10C5B, 0x6E54, 0x0, 0x120000}};
  float ans = 0.000121307373046875, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value6) {
  // -0.000121307373046875
  s21_decimal decimal = {{0x12E10C5B, 0x6E54, 0x0, 0x80120000}};
  float ans = -0.000121307373046875, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value7) {
  // 0.000030517578125
  s21_decimal decimal = {{0x1AFD498D, 0x7, 0x0, 0xF0000}};
  float ans = 0.000030517578125, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value8) {
  // -0.000030517578125
  s21_decimal decimal = {{0x1AFD498D, 0x7, 0x0, 0x800F0000}};
  float ans = -0.000030517578125, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value9) {
  // 0.00008087158203125
  s21_decimal decimal = {{0xF03122F5, 0x75A, 0x0, 0x110000}};
  float ans = 0.00008087158203125, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value10) {
  // -0.00008087158203125
  s21_decimal decimal = {{0xF03122F5, 0x75A, 0x0, 0x80110000}};
  float ans = -0.00008087158203125, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value11) {
  // 0.0000152587890625
  s21_decimal decimal = {{0x86F26FC1, 0x23, 0x0, 0x100000}};
  float ans = 0.0000152587890625, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value12) {
  // -0.0000152587890625
  s21_decimal decimal = {{0x86F26FC1, 0x23, 0x0, 0x80100000}};
  float ans = -0.0000152587890625, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value13) {
  // 0.000040435791015625
  s21_decimal decimal = {{0xB0F5AEC9, 0x24C6, 0x0, 0x120000}};
  float ans = 0.000040435791015625, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value14) {
  // -0.000040435791015625
  s21_decimal decimal = {{0xB0F5AEC9, 0x24C6, 0x0, 0x80120000}};
  float ans = -0.000040435791015625, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value15) {
  // 0.0000000004656612873077392578
  s21_decimal decimal = {{0x7C4A04C2, 0x409F9CBC, 0x0, 0x1C0000}};
  float ans = 0.0000000004656612873077392578, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value16) {
  // -0.0000000004656612873077392578
  s21_decimal decimal = {{0x7C4A04C2, 0x409F9CBC, 0x0, 0x801C0000}};
  float ans = -0.0000000004656612873077392578, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value17) {
  // 2.64735003411769866943359375
  s21_decimal decimal = {{0x53EA698F, 0x4AA64AC6, 0xDAFBD1, 0x1A0000}};
  float ans = 2.64735003411769866943359375, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value18) {
  // -2.64735003411769866943359375
  s21_decimal decimal = {{0x53EA698F, 0x4AA64AC6, 0xDAFBD1, 0x801A0000}};
  float ans = -2.64735003411769866943359375, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value19) {
  // 0.0000000000000000000000000011
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x1C0000}};
  float ans = 0.0000000000000000000000000011, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value20) {
  // -0.0000000000000000000000000011
  s21_decimal decimal = {{0xB, 0x0, 0x0, 0x801C0000}};
  float ans = -0.0000000000000000000000000011, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value21) {
  // 9984710956716346.507786701475
  s21_decimal decimal = {{0x5E7CAA3, 0x8BAB668E, 0x204328C9, 0xC0000}};
  float ans = 9984710956716346.507786701475, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

START_TEST(some_value22) {
  // -9984710956716346.507786701475
  s21_decimal decimal = {{0x5E7CAA3, 0x8BAB668E, 0x204328C9, 0x800C0000}};
  float ans = -9984710956716346.507786701475, my_ans = 0.0f;
  int code = 0, my_code = s21_from_decimal_to_float(decimal, &my_ans);
  ck_assert_float_eq(ans, my_ans);
  ck_assert_int_eq(code, my_code);
}

Suite *s21_decimal_to_float_cases(void) {
  Suite *suite = suite_create("s21_from_decimal_to_float_cases");
  TCase *tc = tcase_create("d_to_f_tc");

  /// краевые случаи
  tcase_add_test(tc, zero);
  tcase_add_test(tc, minus_zero);
  tcase_add_test(tc, error_pow1);
  tcase_add_test(tc, error_pow2);
  tcase_add_test(tc, error_pow3);
  tcase_add_test(tc, error_null_pointer);
  tcase_add_test(tc, error_not_zero_on_zero_place1);
  tcase_add_test(tc, error_not_zero_on_zero_place2);
  tcase_add_test(tc, error_all_one);
  tcase_add_test(tc, error_minus_pow);

  tcase_add_test(tc, max_value);
  tcase_add_test(tc, min_value);
  tcase_add_test(tc, max_value_pow_1);
  tcase_add_test(tc, min_value_pow_1);
  tcase_add_test(tc, some_value1);
  tcase_add_test(tc, some_value2);
  tcase_add_test(tc, some_value3);
  tcase_add_test(tc, some_value4);
  tcase_add_test(tc, some_value5);
  tcase_add_test(tc, some_value6);
  tcase_add_test(tc, some_value7);
  tcase_add_test(tc, some_value8);
  tcase_add_test(tc, some_value9);
  tcase_add_test(tc, some_value10);
  tcase_add_test(tc, some_value11);
  tcase_add_test(tc, some_value12);
  tcase_add_test(tc, some_value13);
  tcase_add_test(tc, some_value14);
  tcase_add_test(tc, some_value15);
  tcase_add_test(tc, some_value16);
  tcase_add_test(tc, some_value17);
  tcase_add_test(tc, some_value18);
  tcase_add_test(tc, some_value19);
  tcase_add_test(tc, some_value20);
  tcase_add_test(tc, some_value21);
  tcase_add_test(tc, some_value22);

  suite_add_tcase(suite, tc);
  return suite;
}
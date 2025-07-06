#include "test.h"
#include "test_from_float_to_decimal.h"
#include "test_runner.h"

START_TEST(test_from_float_to_decimal_unnormal3) {
  float f = INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal4) {
  float f = -INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal5) {
  float f = NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal6) {
  float f = -NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_incorrect1) {
  float f = 1.0f;
  int code = s21_from_float_to_decimal(f, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small) {
  float f = fails_small[_i];
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small_negate) {
  float f = -fails_small[_i];
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok3) {
  // 0.75
  int f = 1061158912;
  // 0.75
  s21_decimal decimal_check = {{0x4B, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok4) {
  // -0.75
  int f = -1086324736;
  // -0.75
  s21_decimal decimal_check = {{0x4B, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok5) {
  // 0.5
  int f = 1056964608;
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok6) {
  // -0.5
  int f = -1090519040;
  // -0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok7) {
  // 0.1875
  int f = 1044381696;
  // 0.1875
  s21_decimal decimal_check = {{0x753, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok8) {
  // -0.1875
  int f = -1103101952;
  // -0.1875
  s21_decimal decimal_check = {{0x753, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok9) {
  // 0.125
  int f = 1040187392;
  // 0.125
  s21_decimal decimal_check = {{0x7D, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok10) {
  // -0.125
  int f = -1107296256;
  // -0.125
  s21_decimal decimal_check = {{0x7D, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok11) {
  // 0.0625
  int f = 1031798784;
  // 0.0625
  s21_decimal decimal_check = {{0x271, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok12) {
  // -0.0625
  int f = -1115684864;
  // -0.0625
  s21_decimal decimal_check = {{0x271, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok13) {
  // 0.015625
  int f = 1015021568;
  // 0.015625
  s21_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok14) {
  // -0.015625
  int f = -1132462080;
  // -0.015625
  s21_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok15) {
  // 0.01171875
  int f = 1010827264;
  // 0.01171875
  s21_decimal decimal_check = {{0x11E1A3, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok16) {
  // -0.01171875
  int f = -1136656384;
  // -0.01171875
  s21_decimal decimal_check = {{0x11E1A3, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok17) {
  // 0.0078125
  int f = 1006632960;
  // 0.0078125
  s21_decimal decimal_check = {{0x1312D, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok18) {
  // -0.0078125
  int f = -1140850688;
  // -0.0078125
  s21_decimal decimal_check = {{0x1312D, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok19) {
  // 0.00390625
  int f = 998244352;
  // 0.00390625
  s21_decimal decimal_check = {{0x5F5E1, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok20) {
  // -0.00390625
  int f = -1149239296;
  // -0.00390625
  s21_decimal decimal_check = {{0x5F5E1, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok25) {
  // 4882.71582
  int f = 1167627706;
  // 4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok26) {
  // -4882.71582
  int f = -979855942;
  // -4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok29) {
  // 4.65661287E-10
  int f = 805306368;
  // 0.0000000004656613
  s21_decimal decimal_check = {{0x470DE5, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok30) {
  // -4.65661287E-10
  int f = -1342177280;
  // -0.0000000004656613
  s21_decimal decimal_check = {{0x470DE5, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok35) {
  // 0.100000001
  int f = 1036831949;
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok36) {
  // -0.100000001
  int f = -1110651699;
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok37) {
  // 0.999000013
  int f = 1065336439;
  // 0.999
  s21_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok55) {
  // 0.0255207196
  int f = 1020334292;
  // 0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok56) {
  // -0.0255207196
  int f = -1127149356;
  // -0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

Suite *s21_f_t_d_cases(void) {
  Suite *suite = suite_create("s21_f_t_d_cases");
  TCase *tc = tcase_create("f_t_d_tc");

  tcase_add_test(tc, test_from_float_to_decimal_ok3);
  tcase_add_test(tc, test_from_float_to_decimal_ok4);
  tcase_add_test(tc, test_from_float_to_decimal_ok5);
  tcase_add_test(tc, test_from_float_to_decimal_ok6);
  tcase_add_test(tc, test_from_float_to_decimal_ok7);
  tcase_add_test(tc, test_from_float_to_decimal_ok8);
  tcase_add_test(tc, test_from_float_to_decimal_ok9);
  tcase_add_test(tc, test_from_float_to_decimal_ok10);
  tcase_add_test(tc, test_from_float_to_decimal_ok11);
  tcase_add_test(tc, test_from_float_to_decimal_ok12);
  tcase_add_test(tc, test_from_float_to_decimal_ok13);
  tcase_add_test(tc, test_from_float_to_decimal_ok14);
  tcase_add_test(tc, test_from_float_to_decimal_ok15);
  tcase_add_test(tc, test_from_float_to_decimal_ok16);
  tcase_add_test(tc, test_from_float_to_decimal_ok17);
  tcase_add_test(tc, test_from_float_to_decimal_ok18);
  tcase_add_test(tc, test_from_float_to_decimal_ok19);
  tcase_add_test(tc, test_from_float_to_decimal_ok20);
  tcase_add_test(tc, test_from_float_to_decimal_ok25);
  tcase_add_test(tc, test_from_float_to_decimal_ok26);
  tcase_add_test(tc, test_from_float_to_decimal_ok29);
  tcase_add_test(tc, test_from_float_to_decimal_ok30);
  tcase_add_test(tc, test_from_float_to_decimal_ok35);
  tcase_add_test(tc, test_from_float_to_decimal_ok36);
  tcase_add_test(tc, test_from_float_to_decimal_ok37);
  tcase_add_test(tc, test_from_float_to_decimal_ok55);
  tcase_add_test(tc, test_from_float_to_decimal_ok56);

  tcase_add_test(tc, test_from_float_to_decimal_unnormal3);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal4);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal5);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal6);

  tcase_add_test(tc, test_from_float_to_decimal_incorrect1);
  tcase_add_test(tc, test_from_float_to_decimal_fail_small_negate);
  tcase_add_test(tc, test_from_float_to_decimal_fail_small);

  suite_add_tcase(suite, tc);
  return suite;
}
void test_from_float_to_decimal(int f, s21_decimal decimal_check) {
  s21_decimal result;

  float_cast_test cast_float;
  cast_float.int32_bytes = f;

  int code = s21_from_float_to_decimal(cast_float.f, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

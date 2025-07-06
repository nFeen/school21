#include "test_runner.h"

START_TEST(big) {
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(ok1) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 0, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0, 0, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(ok2) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 1, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0, 1, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(not_eq) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(fail1) {
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(fail2) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(fail3) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0, 0xFFFFFFFF, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(fail4) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 0xFFFFFFFF, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0, 0, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(fail5) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(1, 0, 0, 0);
  set_scale(&decimal1, 5);
  s21_decimal decimal2 = s21_from_4int_to_decimal(1, 0, 0, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(ok3) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 0, 0);
  set_sign(&decimal1, 1);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0, 0, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(fail7) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 0, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0, 1, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(fail8) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 0, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 1, 0, 0);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

START_TEST(fail9) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 1, 1, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 1, 1, 0);
  set_sign(&decimal2, 1);
  int code = s21_is_equal(decimal1, decimal2);
  ck_assert_int_eq(0, code);
}
END_TEST

Suite *s21_is_equal_cases(void) {
  Suite *suite = suite_create("s21_is_equal_cases");
  TCase *tc = tcase_create("d_to_f_tc");

  /// краевые случаи
  tcase_add_test(tc, ok1);
  tcase_add_test(tc, ok2);
  tcase_add_test(tc, ok3);
  tcase_add_test(tc, big);
  tcase_add_test(tc, not_eq);
  tcase_add_test(tc, fail1);
  tcase_add_test(tc, fail2);
  tcase_add_test(tc, fail3);
  tcase_add_test(tc, fail4);
  tcase_add_test(tc, fail5);
  tcase_add_test(tc, fail7);
  tcase_add_test(tc, fail8);
  tcase_add_test(tc, fail9);

  suite_add_tcase(suite, tc);
  return suite;
}

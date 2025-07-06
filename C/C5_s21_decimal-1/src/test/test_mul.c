#include "test_runner.h"

START_TEST(fail1) {
  ///// 792281625.14264337593543950335
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 786432);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 786432);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(fail2) {
  ///// uncorrect dec
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 0, 1000000000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(fail3) {
  ///// uncorrect dec
  s21_decimal decimal1 = s21_from_4int_to_decimal(-1, 0, 0, 0x11C0000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(fail4) {
  ///// uncorrect dec
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0, 0);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(fail5) {
  ///// small
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(fail6) {
  ///// big
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(fail7) {
  ///// dec2 fail
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0, 0, 0);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(shift_more_then_28) {
  ///// uncorrect dec
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0001);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0, 0);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(big_shift) {
  ///// shift big
  s21_decimal decimal1 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(0, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(small) {
  ///// shift big
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 268435456);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(all_one) {
  ///// 11111111
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000);
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, 0);
}
END_TEST

START_TEST(ok1) {
  ///// 11111111
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0x4F63FFFF, 0xBB0D25CF, 0x1A962D2F, 0x801C0000);
  s21_decimal result;
  s21_decimal check =
      s21_from_4int_to_decimal(0x23B23CAE, 0xEC60363A, 0xD2A415FA, 0x801C0000);
  int code = s21_mul(decimal1, decimal2, &result);
  code = s21_is_equal(result, check);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(ok2) {
  // -7922816251426433759354395032.7
  // 10.000000000000000000000000001
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0x10000001, 0x3E250261, 0x204FCE5E, 0x1B0000);
  s21_decimal result;
  s21_decimal check =
      s21_from_4int_to_decimal(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000);
  int code = s21_mul(decimal1, decimal2, &result);
  code = s21_is_equal(result, check);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(ok3) {
  s21_decimal decimal1 = {{0x4F4FB9DA, 0xC076B0FB, 0x8163398E, 0x800E0000}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  s21_decimal result;
  s21_decimal check = {{2531404942, 0x16C31, 0x0, 0x801C0000}};
  int code = s21_mul(decimal1, decimal2, &result);
  code = s21_is_equal(result, check);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(ok4) {
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0x192F9AB, 0x7C4A04C2, 4294113707, 0x1C0000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000);
  s21_decimal result;
  s21_decimal check =
      s21_from_4int_to_decimal(2582261463, 2135032051, 858822741, 1769472);
  int code = s21_mul(decimal1, decimal2, &result);
  code = s21_is_equal(result, check);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(ok5) {
  s21_decimal decimal1 = s21_from_4int_to_decimal(1, 0, 0, 0);
  s21_decimal decimal2 = s21_from_4int_to_decimal(1, 0, 0, 0);
  s21_decimal result;
  s21_decimal check = s21_from_4int_to_decimal(1, 0, 0, 0);
  int code = s21_mul(decimal1, decimal2, &result);
  code = s21_is_equal(result, check);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(ok6) {
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0x0, 0x55555555, 0x0, 0x80000000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0x69168DB5, 0xDCB4F4B1, 0x16CC701F, 0x180000);
  s21_decimal result;
  s21_decimal check =
      s21_from_4int_to_decimal(0xDEC6BFE8, 0x79C37D33, 0x8C2FC25F, 0x80060000);
  int code = s21_mul(decimal1, decimal2, &result);
  code = s21_is_equal(result, check);
  ck_assert_int_eq(1, code);
}
END_TEST

START_TEST(null) {
  s21_decimal decimal1 =
      s21_from_4int_to_decimal(0x192F9AB, 0x7C4A04C2, 4294113707, 0x1C0000);
  s21_decimal decimal2 =
      s21_from_4int_to_decimal(0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000);
  int code = s21_mul(decimal1, decimal2, NULL);
  ck_assert_int_eq(1, code);
}
END_TEST

Suite *s21_mul_cases(void) {
  Suite *suite = suite_create("s21_mul_cases");
  TCase *tc = tcase_create("d_to_f_tc");

  /// краевые случаи
  tcase_add_test(tc, fail1);
  tcase_add_test(tc, fail2);
  tcase_add_test(tc, fail3);
  tcase_add_test(tc, fail4);
  tcase_add_test(tc, fail5);
  tcase_add_test(tc, fail6);
  tcase_add_test(tc, fail7);
  tcase_add_test(tc, big_shift);
  tcase_add_test(tc, all_one);
  tcase_add_test(tc, shift_more_then_28);
  tcase_add_test(tc, ok1);
  tcase_add_test(tc, ok2);
  tcase_add_test(tc, ok3);
  tcase_add_test(tc, ok4);
  tcase_add_test(tc, ok5);
  tcase_add_test(tc, ok6);
  tcase_add_test(tc, small);
  tcase_add_test(tc, null);

  suite_add_tcase(suite, tc);
  return suite;
}

#include "test_runner.h"

#include "test.h"

int main(void) {
  SRunner *sr;

  sr = srunner_create(NULL);
  srunner_add_suite(sr, add_suite0());
  srunner_add_suite(sr, add_suite1());
  srunner_add_suite(sr, add_suite2());
  srunner_add_suite(sr, add_suite3());
  srunner_add_suite(sr, add_suite4());
  srunner_add_suite(sr, add_suite5());
  srunner_add_suite(sr, add_suite6());
  srunner_add_suite(sr, add_suite7());
  srunner_add_suite(sr, add_suite8());
  srunner_add_suite(sr, add_suite9());

  srunner_add_suite(sr, sub_suite0());
  srunner_add_suite(sr, sub_suite1());
  srunner_add_suite(sr, sub_suite2());
  srunner_add_suite(sr, sub_suite3());
  srunner_add_suite(sr, sub_suite4());
  srunner_add_suite(sr, sub_suite5());
  srunner_add_suite(sr, sub_suite6());
  srunner_add_suite(sr, sub_suite7());
  srunner_add_suite(sr, sub_suite8());
  srunner_add_suite(sr, sub_suite9());

  srunner_add_suite(sr, mul_suite0());
  srunner_add_suite(sr, mul_suite1());
  srunner_add_suite(sr, mul_suite2());
  srunner_add_suite(sr, mul_suite3());
  srunner_add_suite(sr, mul_suite4());
  srunner_add_suite(sr, mul_suite5());
  srunner_add_suite(sr, mul_suite6());
  srunner_add_suite(sr, mul_suite7());
  srunner_add_suite(sr, mul_suite8());
  srunner_add_suite(sr, mul_suite9());

  srunner_add_suite(sr, from_decimal_to_int_suite0());
  srunner_add_suite(sr, from_decimal_to_int_suite1());
  srunner_add_suite(sr, from_decimal_to_int_suite2());
  srunner_add_suite(sr, from_decimal_to_int_suite3());

  srunner_add_suite(sr, floor_suite0());
  srunner_add_suite(sr, floor_suite1());
  srunner_add_suite(sr, floor_suite2());
  srunner_add_suite(sr, floor_suite3());

  srunner_add_suite(sr, round_suite0());
  srunner_add_suite(sr, round_suite1());
  srunner_add_suite(sr, round_suite2());
  srunner_add_suite(sr, round_suite3());

  srunner_add_suite(sr, truncate_suite0());
  srunner_add_suite(sr, truncate_suite1());
  srunner_add_suite(sr, truncate_suite2());
  srunner_add_suite(sr, truncate_suite3());

  srunner_add_suite(sr, s21_mul_cases());
  srunner_add_suite(sr, s21_from_int_to_decimal_cases());
  srunner_add_suite(sr, s21_is_equal_cases());
  srunner_add_suite(sr, s21_is_not_equal_cases());
  srunner_add_suite(sr, s21_is_greater_cases());
  srunner_add_suite(sr, s21_is_greater_or_equal_cases());
  srunner_add_suite(sr, s21_is_less_cases());
  srunner_add_suite(sr, s21_is_less_or_equal_cases());
  srunner_add_suite(sr, s21_decimal_to_float_cases());
  srunner_add_suite(sr, s21_negate_cases());
  srunner_add_suite(sr, s21_div_cases());
  srunner_add_suite(sr, s21_f_t_d_cases());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);

  return 0;
}

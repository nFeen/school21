#ifndef TEST_RUNNER_H_
#define TEST_RUNNER_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"
#include "../s21_helpers.h"

#define SEP "|================================|"
Suite *s21_from_int_to_decimal_cases(void);
Suite *s21_mul_cases(void);
Suite *s21_is_equal_cases(void);
Suite *s21_is_not_equal_cases(void);
Suite *s21_is_greater_cases(void);
Suite *s21_is_greater_or_equal_cases(void);
Suite *s21_is_less_cases(void);
Suite *s21_is_less_or_equal_cases(void);
Suite *s21_decimal_to_float_cases(void);
Suite *s21_negate_cases(void);
Suite *s21_div_cases(void);
Suite *s21_f_t_d_cases(void);

#endif  // TEST_RUNNER_H_

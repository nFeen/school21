#ifndef TEST_RUNNER_H_
#define TEST_RUNNER_H_

#include <check.h>
#include <math.h>
#include <stdio.h>

#include "../s21_helpers.h"
#include "../s21_matrix.h"

#define SEP "|================================|"

Suite *s21_create_matrix_cases(void);
Suite *s21_remove_matrix_cases(void);
Suite *s21_eq_matrix_cases(void);
Suite *s21_sum_matrix_cases(void);
Suite *s21_sub_matrix_cases(void);
Suite *s21_mult_number_cases(void);
Suite *s21_mult_matrix_cases(void);
Suite *s21_transpose_cases(void);
Suite *s21_calc_complements_cases(void);
Suite *s21_determinant_cases(void);
Suite *s21_inverse_matrix_cases(void);

#endif  // TEST_RUNNER_H_

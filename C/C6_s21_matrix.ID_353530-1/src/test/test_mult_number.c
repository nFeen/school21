#include "test_runner.h"

START_TEST(OK1) {
  matrix_t matrix1, matrix3, matrix4;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix3);
  double arr1[123] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  double arr2[231] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  from_array(arr1, &matrix1);
  from_array(arr2, &matrix3);
  int status = s21_mult_number(&matrix1, 2, &matrix4);
  ck_assert_int_eq(OK, status);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&matrix3, &matrix4));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix3);
  s21_remove_matrix(&matrix4);
}
END_TEST

START_TEST(FAIL1) {
  matrix_t matrix1, matrix4;
  matrix1.rows = 0;
  int status = s21_mult_number(&matrix1, 2, &matrix4);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
}
END_TEST

Suite *s21_mult_number_cases(void) {
  Suite *suite = suite_create("s21_mult_number_cases");
  TCase *tc = tcase_create("mult_number_tc");

  tcase_add_test(tc, OK1);
  tcase_add_test(tc, FAIL1);

  suite_add_tcase(suite, tc);
  return suite;
}

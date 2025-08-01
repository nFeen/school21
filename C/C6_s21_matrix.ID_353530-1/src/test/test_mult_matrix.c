#include "test_runner.h"

START_TEST(OK1) {
  matrix_t matrix1, matrix2, matrix3, matrix4;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  s21_create_matrix(3, 3, &matrix3);
  double arr1[123] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  double arr2[231] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
  from_array(arr1, &matrix1);
  from_array(arr1, &matrix2);
  from_array(arr2, &matrix3);
  int status = s21_mult_matrix(&matrix1, &matrix2, &matrix4);
  ck_assert_int_eq(OK, status);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&matrix3, &matrix4));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix3);
  s21_remove_matrix(&matrix4);
}
END_TEST

START_TEST(FAIL1) {
  matrix_t matrix1, matrix2, matrix4;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(4, 4, &matrix2);
  double arr1[123] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  from_array(arr1, &matrix1);
  from_array(arr1, &matrix2);
  int status = s21_mult_matrix(&matrix1, &matrix2, &matrix4);
  ck_assert_int_eq(MATH_FAIL, status);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(FAIL2) {
  matrix_t matrix1, matrix2, matrix4;
  s21_create_matrix(3, 3, &matrix1);
  //   s21_create_matrix(4, 4, &matrix2);
  double arr1[123] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  from_array(arr1, &matrix1);
  //   from_array(arr1, &matrix2);
  matrix2.rows = 0;
  int status = s21_mult_matrix(&matrix1, &matrix2, &matrix4);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
  s21_remove_matrix(&matrix1);
  //   s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(FAIL3) {
  matrix_t matrix1, matrix2, matrix4;
  //   s21_create_matrix(3, 3, &matrix2);
  //   s21_create_matrix(4, 4, &matrix2);
  //   double arr1[123] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  //   from_array(arr1, &matrix2);
  //   from_array(arr1, &matrix2);
  matrix1.rows = 0;
  matrix2.columns = 0;
  int status = s21_mult_matrix(&matrix1, &matrix2, &matrix4);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
  //   s21_remove_matrix(&matrix2);
  //   s21_remove_matrix(&matrix2);
}
END_TEST

Suite *s21_mult_matrix_cases(void) {
  Suite *suite = suite_create("s21_mult_matrix_cases");
  TCase *tc = tcase_create("mult_matrix_tc");

  tcase_add_test(tc, OK1);
  //   tcase_add_test(tc, OK2);
  tcase_add_test(tc, FAIL1);
  tcase_add_test(tc, FAIL2);
  tcase_add_test(tc, FAIL3);

  suite_add_tcase(suite, tc);
  return suite;
}

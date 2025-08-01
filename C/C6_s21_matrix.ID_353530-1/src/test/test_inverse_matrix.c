#include "test_runner.h"

START_TEST(OK1) {
  matrix_t matrix1, matrix3, matrix4;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix3);
  double arr1[123] = {1, 2, 3, 4, 5, 6, 7, 8, 8};
  double arr2[231] = {-2.6666667, 2.6666667, -1, 3.33333333, -4.33333333,
                      2,          -1,        2,  -1};
  from_array(arr1, &matrix1);
  from_array(arr2, &matrix3);
  int status = s21_inverse_matrix(&matrix1, &matrix4);
  ck_assert_int_eq(OK, status);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&matrix3, &matrix4));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix3);
  s21_remove_matrix(&matrix4);
}
END_TEST

START_TEST(OK2) {
  matrix_t matrix1, matrix3, matrix4;
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix3);
  matrix1.matrix[0][0] = 1;
  matrix3.matrix[0][0] = 1;
  int status = s21_inverse_matrix(&matrix1, &matrix4);
  ck_assert_int_eq(OK, status);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&matrix3, &matrix4));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix3);
  s21_remove_matrix(&matrix4);
}
END_TEST

START_TEST(OK3) {
  // printf("fgd");
  matrix_t matrix1, matrix3, matrix4;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix3);
  double arr1[123] = {1, 2, 3, 4};
  double arr2[231] = {-2, 1, 1.5, -0.5};
  from_array(arr1, &matrix1);
  from_array(arr2, &matrix3);
  int status = s21_inverse_matrix(&matrix1, &matrix4);
  ck_assert_int_eq(OK, status);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&matrix3, &matrix4));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix3);
  s21_remove_matrix(&matrix4);
}
END_TEST

START_TEST(FAIL1) {
  matrix_t matrix1, matrix4;
  matrix1.columns = 0;
  int status = s21_inverse_matrix(&matrix1, &matrix4);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
}
END_TEST

START_TEST(FAIL2) {
  matrix_t matrix1, matrix4;
  s21_create_matrix(3, 2, &matrix1);
  int status = s21_inverse_matrix(&matrix1, &matrix4);
  ck_assert_int_eq(MATH_FAIL, status);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(FAIL3) {
  matrix_t matrix1, matrix4;
  s21_create_matrix(3, 3, &matrix1);
  double arr1[123] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  from_array(arr1, &matrix1);
  int status = s21_inverse_matrix(&matrix1, &matrix4);
  ck_assert_int_eq(MATH_FAIL, status);
  s21_remove_matrix(&matrix1);
}
END_TEST

Suite *s21_inverse_matrix_cases(void) {
  Suite *suite = suite_create("s21_inverse_matrix_cases");
  TCase *tc = tcase_create("inverse_matrix_tc");

  tcase_add_test(tc, OK1);
  tcase_add_test(tc, OK2);
  tcase_add_test(tc, OK3);
  tcase_add_test(tc, FAIL1);
  tcase_add_test(tc, FAIL2);
  tcase_add_test(tc, FAIL3);

  suite_add_tcase(suite, tc);
  return suite;
}

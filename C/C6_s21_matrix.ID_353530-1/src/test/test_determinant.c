#include "test_runner.h"

START_TEST(OKIKKKK1) {  // утечка
  matrix_t matrix1;
  s21_create_matrix(3, 3, &matrix1);
  double arr1[123] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double res;
  from_array(arr1, &matrix1);
  int status = s21_determinant(&matrix1, &res);
  ck_assert_int_eq(OK, status);
  ck_assert_double_eq(0, res);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(OK2) {
  matrix_t matrix1;
  s21_create_matrix(1, 1, &matrix1);
  double arr1[123] = {1};
  double res;
  from_array(arr1, &matrix1);
  int status = s21_determinant(&matrix1, &res);
  ck_assert_int_eq(OK, status);
  ck_assert_double_eq(1, res);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(OK3) {
  matrix_t matrix1;
  s21_create_matrix(2, 2, &matrix1);
  double arr1[123] = {1, 1, 1, 2};
  double res;
  from_array(arr1, &matrix1);
  int status = s21_determinant(&matrix1, &res);
  ck_assert_int_eq(OK, status);
  ck_assert_double_eq(1, res);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(FAIL1) {
  matrix_t matrix1;
  matrix1.columns = 0;
  double res;
  int status = s21_determinant(&matrix1, &res);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
}
END_TEST

START_TEST(FAIL2) {  // утечка
  matrix_t matrix1;
  double res;
  s21_create_matrix(3, 2, &matrix1);
  int status = s21_determinant(&matrix1, &res);
  ck_assert_int_eq(MATH_FAIL, status);
  s21_remove_matrix(&matrix1);
}
END_TEST

Suite *s21_determinant_cases(void) {
  Suite *suite = suite_create("s21_determinant_cases");
  TCase *tc = tcase_create("determinant_tc");

  tcase_add_test(tc, OKIKKKK1);
  tcase_add_test(tc, OK2);
  tcase_add_test(tc, OK3);
  tcase_add_test(tc, FAIL1);
  tcase_add_test(tc, FAIL2);
  //   tcase_add_test(tc, FAIL3);

  suite_add_tcase(suite, tc);
  return suite;
}

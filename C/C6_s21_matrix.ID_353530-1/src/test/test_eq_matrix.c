#include "test_runner.h"

START_TEST(OK1) {
  matrix_t matrix1, matrix2;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(OK2) {
  matrix_t matrix1, matrix2;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  full_one(&matrix2);
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(FAIL1) {
  matrix_t matrix1, matrix2;
  s21_create_matrix(3, 3, &matrix1);
  matrix2.rows = -1;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  // s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(FAIL2) {
  matrix_t matrix1, matrix2;
  s21_create_matrix(3, 3, &matrix2);
  matrix1.rows = -1;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&matrix1, &matrix2));
  //   s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(FAIL3) {
  matrix_t matrix1, matrix2;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 2, &matrix2);
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

Suite *s21_eq_matrix_cases(void) {
  Suite *suite = suite_create("s21_eq_matrix_cases");
  TCase *tc = tcase_create("eq_matrix_tc");

  tcase_add_test(tc, OK1);
  tcase_add_test(tc, OK2);
  tcase_add_test(tc, FAIL1);
  tcase_add_test(tc, FAIL2);
  tcase_add_test(tc, FAIL3);

  suite_add_tcase(suite, tc);
  return suite;
}

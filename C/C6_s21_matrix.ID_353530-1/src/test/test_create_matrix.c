#include "test_runner.h"

START_TEST(OK1) {
  matrix_t matrix;
  int status = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(0, status);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(FAIL1) {
  matrix_t matrix;
  int status = s21_create_matrix(0, 3, &matrix);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
  //   s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(FAIL2) {
  matrix_t matrix;
  int status = s21_create_matrix(3, 0, &matrix);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
  //   s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(FAIL3) {
  matrix_t matrix;
  int status = s21_create_matrix(0, 0, &matrix);
  ck_assert_int_eq(INCORRECT_MATRIX, status);
  //   s21_remove_matrix(&matrix);
}
END_TEST

Suite *s21_create_matrix_cases(void) {
  Suite *suite = suite_create("s21_create_matrix_cases");
  TCase *tc = tcase_create("create_matrix_tc");

  tcase_add_test(tc, OK1);
  tcase_add_test(tc, FAIL1);
  tcase_add_test(tc, FAIL2);
  tcase_add_test(tc, FAIL3);

  suite_add_tcase(suite, tc);
  return suite;
}

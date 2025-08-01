#include "test_runner.h"

START_TEST(OK1) {
  matrix_t matrix;
  int status = s21_create_matrix(3, 3, &matrix);
  ck_assert_int_eq(0, status);
  s21_remove_matrix(&matrix);
}
END_TEST

// START_TEST(FAIL1) {
//   matrix_t matrix;
//   s21_remove_matrix(&matrix);
//   ck_assert_int_eq(0, is_matrix_exists(&matrix));
// }
// END_TEST

Suite *s21_remove_matrix_cases(void) {
  Suite *suite = suite_create("s21_remove_matrix_cases");
  TCase *tc = tcase_create("remove_matrix_tc");

  tcase_add_test(tc, OK1);
  //   tcase_add_test(tc, FAIL1);

  suite_add_tcase(suite, tc);
  return suite;
}

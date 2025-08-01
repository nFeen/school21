#include "test_runner.h"

int main(void) {
  Suite *array_tests[] = {
      s21_create_matrix_cases(),    s21_remove_matrix_cases(),
      s21_eq_matrix_cases(),        s21_sum_matrix_cases(),
      s21_sub_matrix_cases(),       s21_mult_number_cases(),
      s21_mult_matrix_cases(),      s21_transpose_cases(),
      s21_calc_complements_cases(), s21_determinant_cases(),
      s21_inverse_matrix_cases()};

  int size = 11;

  for (int i = 0; i < size; i++) {
    printf("%s\n", SEP);
    printf("TEST NUMBER: %d \n", i + 1);

    SRunner *runner = srunner_create(array_tests[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
  }

  return 0;
}

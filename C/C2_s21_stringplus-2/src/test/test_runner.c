#include "test_runner.h"

int main(void) {
  Suite *array_tests[] = {
      s21_strcspn_cases(),  s21_strlen_cases(),  s21_strchr_cases(),
      s21_memcpy_cases(),   s21_memchr_cases(),  s21_strncat_cases(),
      s21_strncmp_cases(),  s21_strrchr_cases(), s21_strtok_cases(),
      s21_memcmp_cases(),   s21_memset_cases(),  s21_strncpy_cases(),
      s21_strerror_cases(), s21_strpbrk_cases(), s21_strstr_cases(),
      s21_sprintf_cases()};

  int size = 16;

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

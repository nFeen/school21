#ifndef TEST_RUNNER_H_
#define TEST_RUNNER_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

#define s21_NULL ((void *)0)

#define SEP "|================================|"

Suite *s21_strcspn_cases(void);
Suite *s21_strlen_cases(void);
Suite *s21_strchr_cases(void);
Suite *s21_memcpy_cases(void);
Suite *s21_memchr_cases(void);
Suite *s21_strncat_cases(void);
Suite *s21_strncmp_cases(void);
Suite *s21_strrchr_cases(void);
Suite *s21_memcmp_cases(void);
Suite *s21_memset_cases(void);
Suite *s21_strncpy_cases(void);
Suite *s21_strerror_cases(void);
Suite *s21_strpbrk_cases(void);
Suite *s21_strstr_cases(void);
Suite *s21_strtok_cases(void);
Suite *s21_sprintf_cases(void);

#endif

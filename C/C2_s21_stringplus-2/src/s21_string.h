#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "s21_errors.h"

typedef unsigned long long s21_size_t;
#define S21_NULL (void *)0

s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strerror(int errnum);
void reverse(char *str);

int s21_sprintf(char *str, const char *format, ...);
void parse_flags(const char **ptr, int *minus, int *plus, int *space);
int is_digit(char c);
int str_to_int(const char *str);
void add_char(char *str, char c, int *pos);
void add_string(char *dest, const char *src, int *pos);
char *int_to_str(long int num);
void format_decimal(char *str, long int value, int *pos, int width,
                    int precision, int minus, int plus, int space);
char *float_to_str(float num, int afterpoint);
void format_float(char *str, float value, int *pos, int width, int precision,
                  int minus, int plus, int space);
void format_string(char *str, const char *value, int *pos, int width,
                   int precision, int minus);
void format_char(char *str, char value, int *pos, int width, int precision,
                 int minus);
void format_wide_string(char *str, const wchar_t *value, int *pos, int width,
                        int precision, int minus);
void apply_format(char specif, va_list args, char length, char *str,
                  int *result, int width, int precision, int minus, int plus,
                  int space);

#endif
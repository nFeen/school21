#ifndef HELPERS_H
#define HELPERS_H

#include "s21_decimal.h"

typedef struct {
  uint32_t bits[7];
  uint16_t scale;
  uint16_t sign;
} ext_decimal;

int get_bit(ext_decimal dec, int index);
void set_bit(ext_decimal *dec, int index, int value);
int get_sign(const s21_decimal *dec);
void set_sign(s21_decimal *dec, int sign);
int get_scale(const s21_decimal *dec);
void set_scale(s21_decimal *dec, int scale);

int is_zero(ext_decimal dec);
int multiply_by_10(ext_decimal *dec);
int divide_by_10(ext_decimal *dec);
int get_last_digit(ext_decimal dec);
int round_decimal(ext_decimal *ext_dec, int last_digit, int has_more_digits);
int normalize_scales(ext_decimal *a, ext_decimal *b);
int compare_bits(ext_decimal a, ext_decimal b);
ext_decimal convert_to_ext(s21_decimal dec);
int shrink_ext(ext_decimal *ext_dec);
ext_decimal to_complement(ext_decimal dec);
int modulus_addition(ext_decimal ext_value_1, ext_decimal ext_value_2,
                     ext_decimal *result, int is_subtraction);
s21_decimal convert_from_ext(ext_decimal ext_dec);
int check(int code, ext_decimal *ext_result, s21_decimal *result);
ext_decimal shift_left(ext_decimal ext_dec, int shift);
int bits_length(ext_decimal ext_dec);
int int_division(ext_decimal *ext_value_1, ext_decimal ext_value_2,
                 ext_decimal *ext_result);

s21_decimal s21_from_4int_to_decimal(int a0, int a1, int a2, int a3);
int s21_get_bit_from_int(int value, int index);
int incorrect_parameter(s21_decimal value);

#endif
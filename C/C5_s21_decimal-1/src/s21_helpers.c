#include "s21_helpers.h"

int get_bit(ext_decimal dec, int index) {
  int part = index / 32;
  int bit = index % 32;
  return (dec.bits[part] >> bit) & 1;
}

void set_bit(ext_decimal *dec, int index, int value) {
  int part = index / 32;
  int bit = index % 32;

  if (value == 1)
    dec->bits[part] |= (1u << bit);
  else
    dec->bits[part] &= ~(1u << bit);
}

int get_sign(const s21_decimal *dec) { return (dec->bits[3] >> 31) & 1; }

void set_sign(s21_decimal *dec, int sign) {
  if (sign == 1)
    dec->bits[3] |= (1u << 31);
  else
    dec->bits[3] &= ~(1u << 31);
}

int get_scale(const s21_decimal *dec) { return (dec->bits[3] >> 16) & 0xFF; }

void set_scale(s21_decimal *dec, int scale) {
  if (scale > 28) scale = 28;
  dec->bits[3] &= ~(0xFF << 16);
  dec->bits[3] |= (scale & 0xFF) << 16;
}

int is_zero(ext_decimal dec) {
  int result = 1;
  for (int i = 0; i < 7 && result != 0; i++) {
    if (dec.bits[i] != 0) result = 0;
  }
  return result;
}

int multiply_by_10(ext_decimal *dec) {
  int return_value = 0;

  uint64_t temp = 0;
  ext_decimal result = {0};
  uint32_t carry = 0;

  for (int i = 0; i < 7; i++) {
    temp = (uint64_t)dec->bits[i] * 10 + carry;
    result.bits[i] = (uint32_t)temp;
    carry = (uint32_t)(temp >> 32);
  }
  if (carry == 0) {
    for (int i = 0; i < 7; i++) {
      dec->bits[i] = result.bits[i];
    }
  } else {
    return_value = 1;
  }

  return return_value;
}

int divide_by_10(ext_decimal *dec) {
  uint64_t temp = 0;
  uint64_t remainder = 0;
  for (int i = 6; i >= 0; i--) {
    temp = (uint64_t)dec->bits[i] + (remainder << 32);
    remainder = temp % 10;
    temp /= 10;
    dec->bits[i] = (uint32_t)temp;
  }
  dec->scale--;
  return remainder;
}

int get_last_digit(ext_decimal dec) {
  uint64_t temp = 0;
  uint64_t remainder = 0;
  for (int i = 6; i >= 0; i--) {
    temp = (uint64_t)dec.bits[i] + (remainder << 32);
    remainder = temp % 10;
  }
  return remainder;
}

int round_decimal(ext_decimal *ext_dec, int last_digit, int has_more_digits) {
  int return_value = 0;
  uint64_t temp = 0;
  uint32_t carry = 0;
  uint32_t copy[3] = {0};
  if (last_digit > 5 ||
      (last_digit == 5 &&
       (has_more_digits || get_last_digit(*ext_dec) % 2 != 0))) {
    for (int i = 0; i < 3; i++) {
      temp = (uint64_t)ext_dec->bits[i] + (i == 0) + carry;
      copy[i] = (uint32_t)temp;
      carry = (uint32_t)(temp >> 32);
    }
    if (carry == 0) {
      ext_dec->bits[0] = copy[0];
      ext_dec->bits[1] = copy[1];
      ext_dec->bits[2] = copy[2];
    } else
      return_value = 1;
  }
  return return_value;
}

int normalize_scales(ext_decimal *a, ext_decimal *b) {
  int a_overflow = 0;
  int b_overflow = 0;

  while (a_overflow == 0 && a->scale < b->scale) {
    if (multiply_by_10(a))
      a_overflow = 1;
    else
      a->scale++;
  }
  int last_digit = 0;
  int has_more_digits = 0;
  if (a_overflow == 1) {
    while (a->scale < b->scale) {
      if (last_digit != 0) {
        has_more_digits = 1;
      }
      last_digit = divide_by_10(b);
    }
    round_decimal(b, last_digit, has_more_digits);
  }
  while (b_overflow == 0 && b->scale < a->scale) {
    if (multiply_by_10(b))
      b_overflow = 1;
    else
      b->scale++;
  }
  if (b_overflow == 1) {
    while (a->scale > b->scale) {
      if (last_digit != 0) {
        has_more_digits = 1;
      }
      last_digit = divide_by_10(a);
    }
    round_decimal(a, last_digit, has_more_digits);
  }

  return 0;
}

int compare_bits(ext_decimal a, ext_decimal b) {
  int result = 0;
  for (int i = 6; i >= 0 && result == 0; i--) {
    if (a.bits[i] > b.bits[i])
      result = 1;
    else if (a.bits[i] < b.bits[i])
      result = -1;
  }
  return result;
}

ext_decimal convert_to_ext(s21_decimal dec) {
  ext_decimal result = {0};
  for (int i = 0; i < 3; i++) {
    result.bits[i] = dec.bits[i];
  }
  result.scale = get_scale(&dec);
  if (is_zero(result))
    result.sign = 0;
  else
    result.sign = get_sign(&dec);
  return result;
}

int shrink_ext(ext_decimal *ext_dec) {
  int return_value = 0;
  int last_digit = 0;
  int has_more_digits = 0;
  for (int i = 6; i >= 0 && return_value == 0; i--) {
    while ((ext_dec->bits[i] != 0 && ((i > 2 && ext_dec->scale > 0) ||
                                      (i <= 2 && ext_dec->scale > 28))) ||
           (i == 0 && ext_dec->scale > 28)) {
      if (last_digit != 0) {
        has_more_digits = 1;
      }
      last_digit = divide_by_10(ext_dec);
    }
    if (i > 2 && ext_dec->bits[i] != 0) return_value = 1;
  }
  if (return_value == 0) {
    if (!round_decimal(ext_dec, last_digit, has_more_digits)) {
      while (ext_dec->scale != 0 && get_last_digit(*ext_dec) == 0) {
        divide_by_10(ext_dec);
      }
    } else
      return_value = 1;
  }
  return return_value;
}

ext_decimal to_complement(ext_decimal dec) {
  uint64_t temp = 0;
  uint32_t carry = 0;
  if (!is_zero(dec)) {
    for (int i = 0; i < 7; i++) {
      temp = (uint64_t)(~(dec.bits[i])) + (i == 0) + carry;
      dec.bits[i] = (uint32_t)temp;
      carry = (uint32_t)(temp >> 32);
    }
  }
  return dec;
}

int modulus_addition(ext_decimal ext_value_1, ext_decimal ext_value_2,
                     ext_decimal *result, int is_subtraction) {
  int return_value = 0;
  uint64_t temp = 0;
  uint32_t carry = 0;
  ext_decimal copy = {0};
  for (int i = 0; i < 7; i++) {
    temp =
        (uint64_t)ext_value_1.bits[i] + (uint64_t)ext_value_2.bits[i] + carry;
    copy.bits[i] = (uint32_t)temp;
    carry = (uint32_t)(temp >> 32);
  }
  if (!is_subtraction && carry != 0)
    return_value = 1;
  else {
    for (int i = 0; i < 7; i++) {
      result->bits[i] = copy.bits[i];
    }
  }
  return return_value;
}

s21_decimal convert_from_ext(ext_decimal ext_dec) {
  s21_decimal result = {0};
  set_scale(&result, ext_dec.scale);
  set_sign(&result, ext_dec.sign);
  for (int i = 0; i < 3; i++) {
    result.bits[i] = ext_dec.bits[i];
  }
  return result;
}

int check(int code, ext_decimal *ext_result, s21_decimal *result) {
  int return_value = 0;
  int not_empty = !is_zero(*ext_result);
  if (!code && !shrink_ext(ext_result)) {
    if (not_empty && is_zero(*ext_result))
      return_value = 2;
    else {
      *result = convert_from_ext(*ext_result);
    }
  } else {
    if (ext_result->sign == 0)
      return_value = 1;
    else
      return_value = 2;
  }
  return return_value;
}

ext_decimal shift_left(ext_decimal ext_dec, int shift) {
  ext_decimal result = {0};
  int part = shift / 32;
  int bit = shift % 32;
  for (int i = 6; i >= part; i--) {
    uint64_t val = (uint64_t)ext_dec.bits[i - part] << bit;
    if (i > part && bit != 0) {
      val |= (uint64_t)ext_dec.bits[i - part - 1] >> (32 - bit);
    }
    result.bits[i] = (uint32_t)val;
  }
  return result;
}

int bits_length(ext_decimal ext_dec) {
  int return_value = 0;
  for (int i = 223; i >= 0 && return_value == 0; i--) {
    if (get_bit(ext_dec, i)) {
      return_value = i + 1;
    }
  }
  return return_value;
}

int int_division(ext_decimal *ext_value_1, ext_decimal ext_value_2,
                 ext_decimal *ext_result) {
  int shift = bits_length(*ext_value_1) - bits_length(ext_value_2);
  while (shift >= 0) {
    ext_decimal shifted_divisor = shift_left(ext_value_2, shift);
    ext_decimal neg_shifted_divisor = to_complement(shifted_divisor);
    while (compare_bits(*ext_value_1, shifted_divisor) >= 0) {
      modulus_addition(*ext_value_1, neg_shifted_divisor, ext_value_1, 1);
      set_bit(ext_result, shift, 1);
    }
    shift--;
  }
  return 0;
}

int incorrect_parameter(s21_decimal value) {
  return (value.bits[3] & 0x7F00FFFF) != 0 || get_scale(&value) > 28;
}

s21_decimal s21_from_4int_to_decimal(int a0, int a1, int a2, int a3) {
  s21_decimal res = {{a0, a1, a2, a3}};
  return res;
}

int s21_get_bit_from_int(int value, int index) {
  int check = 1 << index;
  int result = (value & check) >> index;
  if (result < 0) result = -result;
  return (result);
}
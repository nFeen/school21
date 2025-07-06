#include "s21_helpers.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  if (incorrect_parameter(value_1) || incorrect_parameter(value_2)) return 0;
  int result = 0;
  ext_decimal ext_value_1 = convert_to_ext(value_1);
  ext_decimal ext_value_2 = convert_to_ext(value_2);
  normalize_scales(&ext_value_1, &ext_value_2);
  if ((ext_value_1.sign == 1 && ext_value_2.sign == 0) ||
      (ext_value_1.sign == 1 && ext_value_2.sign == 1 &&
       compare_bits(ext_value_1, ext_value_2) == 1) ||
      (ext_value_1.sign == 0 && ext_value_2.sign == 0 &&
       compare_bits(ext_value_1, ext_value_2) == -1))
    result = 1;
  return result;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  if (incorrect_parameter(value_1) || incorrect_parameter(value_2)) return 0;
  int result = 0;
  ext_decimal ext_value_1 = convert_to_ext(value_1);
  ext_decimal ext_value_2 = convert_to_ext(value_2);
  normalize_scales(&ext_value_1, &ext_value_2);
  if (compare_bits(ext_value_1, ext_value_2) == 0 &&
      ext_value_1.sign == ext_value_2.sign)
    result = 1;
  return result;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  if (incorrect_parameter(value_1) || incorrect_parameter(value_2)) return 0;
  return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  if (incorrect_parameter(value_1) || incorrect_parameter(value_2)) return 0;
  return !s21_is_less_or_equal(value_1, value_2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  if (incorrect_parameter(value_1) || incorrect_parameter(value_2)) return 0;
  return s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  if (incorrect_parameter(value_1) || incorrect_parameter(value_2)) return 0;
  return !s21_is_equal(value_1, value_2);
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL || incorrect_parameter(value_1) ||
      incorrect_parameter(value_2))
    return 1;
  memset(result, 0, sizeof(s21_decimal));
  int return_value = 0;
  ext_decimal ext_value_1 = convert_to_ext(value_1);
  ext_decimal ext_value_2 = convert_to_ext(value_2);
  ext_decimal ext_result = {0};
  int sign = 0;
  normalize_scales(&ext_value_1, &ext_value_2);
  ext_result.scale = ext_value_1.scale;
  if (ext_value_1.sign == ext_value_2.sign) {
    modulus_addition(ext_value_1, ext_value_2, &ext_result, 0);
    sign = ext_value_1.sign;
  } else {
    if (compare_bits(ext_value_1, ext_value_2) == -1) {
      ext_value_1 = to_complement(ext_value_1);
      sign = ext_value_2.sign;
    } else {
      ext_value_2 = to_complement(ext_value_2);
      if (compare_bits(ext_value_1, ext_value_2) != 0) sign = ext_value_1.sign;
    }
    modulus_addition(ext_value_1, ext_value_2, &ext_result, 1);
  }
  if (!shrink_ext(&ext_result)) {
    *result = convert_from_ext(ext_result);
    set_sign(result, sign);
  } else if (sign == 0)
    return_value = 1;
  else
    return_value = 2;
  return return_value;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL || incorrect_parameter(value_1) ||
      incorrect_parameter(value_2))
    return 1;
  memset(result, 0, sizeof(s21_decimal));
  if (get_sign(&value_2) == 0)
    set_sign(&value_2, 1);
  else
    set_sign(&value_2, 0);
  return s21_add(value_1, value_2, result);
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL || incorrect_parameter(value_1) ||
      incorrect_parameter(value_2))
    return 1;
  memset(result, 0, sizeof(s21_decimal));
  int return_value = 0;
  ext_decimal ext_value_1 = convert_to_ext(value_1);
  ext_decimal ext_value_2 = convert_to_ext(value_2);
  ext_decimal ext_result = {0};
  ext_result.sign = ext_value_1.sign != ext_value_2.sign;
  ext_result.scale = ext_value_1.scale + ext_value_2.scale;
  uint64_t temp = 0;
  uint32_t carry = 0;
  ext_decimal values[3] = {0};
  for (int i = 0; i < 3 && return_value == 0; i++) {
    for (int j = 0; j < 7; j++) {
      temp =
          (uint64_t)ext_value_1.bits[j] * (uint64_t)ext_value_2.bits[i] + carry;
      values[i].bits[j + i] = (uint32_t)temp;
      carry = (uint32_t)(temp >> 32);
    }
    if (carry != 0 || modulus_addition(values[i], ext_result, &ext_result, 0))
      return_value = 1;
  }
  return check(return_value, &ext_result, result);
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (is_zero(convert_to_ext(value_2))) return 3;
  if (result == NULL || incorrect_parameter(value_1) ||
      incorrect_parameter(value_2))
    return 1;
  memset(result, 0, sizeof(s21_decimal));
  int return_value = 0;
  ext_decimal ext_value_1 = convert_to_ext(value_1);
  ext_decimal ext_value_2 = convert_to_ext(value_2);
  ext_decimal ext_result = {0};
  ext_result.sign = ext_value_1.sign != ext_value_2.sign;
  normalize_scales(&ext_value_1, &ext_value_2);
  int_division(&ext_value_1, ext_value_2, &ext_result);

  ext_decimal fractional = {0};
  while (!is_zero(ext_value_1) && fractional.scale <= 30) {
    ext_decimal value = {0};
    while (compare_bits(ext_value_1, ext_value_2) == -1) {
      multiply_by_10(&ext_value_1);
      multiply_by_10(&fractional);
      fractional.scale++;
    }
    int_division(&ext_value_1, ext_value_2, &value);
    modulus_addition(fractional, value, &fractional, 0);
  }
  normalize_scales(&ext_result, &fractional);
  if (modulus_addition(ext_result, fractional, &ext_result, 0))
    return_value = 1;
  return check(return_value, &ext_result, result);
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result == NULL || incorrect_parameter(value)) return 1;
  memset(result, 0, sizeof(s21_decimal));
  ext_decimal ext_value = convert_to_ext(value);
  int more_than_zero = 0;
  for (int i = 2; i >= 0; i--) {
    while ((ext_value.bits[i] != 0 && ext_value.scale > 0) ||
           (i == 0 && ext_value.scale > 0)) {
      if (divide_by_10(&ext_value)) more_than_zero = 1;
    }
  }
  if (more_than_zero && ext_value.sign == 1) {
    uint64_t temp = 0;
    uint32_t carry = 0;
    for (int i = 0; i < 3; i++) {
      temp = (uint64_t)ext_value.bits[i] + (i == 0) + carry;
      ext_value.bits[i] = (uint32_t)temp;
      carry = (uint32_t)(temp >> 32);
    }
  }
  *result = convert_from_ext(ext_value);
  set_sign(result, get_sign(&value));

  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  if (result == NULL || incorrect_parameter(value)) return 1;
  memset(result, 0, sizeof(s21_decimal));
  ext_decimal ext_value = convert_to_ext(value);
  int last_digit = 0;
  for (int i = 2; i >= 0; i--) {
    while ((ext_value.bits[i] != 0 && ext_value.scale > 0) ||
           (i == 0 && ext_value.scale > 0)) {
      last_digit = divide_by_10(&ext_value);
    }
  }
  if (last_digit >= 5) {
    uint64_t temp = 0;
    uint32_t carry = 0;
    for (int i = 0; i < 3; i++) {
      temp = (uint64_t)ext_value.bits[i] + (i == 0) + carry;
      ext_value.bits[i] = (uint32_t)temp;
      carry = (uint32_t)(temp >> 32);
    }
  }
  *result = convert_from_ext(ext_value);
  set_sign(result, get_sign(&value));
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL || incorrect_parameter(value)) return 1;
  memset(result, 0, sizeof(s21_decimal));
  ext_decimal ext_value = convert_to_ext(value);
  for (int i = 2; i >= 0; i--) {
    while ((ext_value.bits[i] != 0 && ext_value.scale > 0) ||
           (i == 0 && ext_value.scale > 0)) {
      divide_by_10(&ext_value);
    }
  }
  *result = convert_from_ext(ext_value);
  set_sign(result, get_sign(&value));
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (result == NULL || incorrect_parameter(value)) return 1;
  memset(result, 0, sizeof(s21_decimal));
  get_sign(&value) == 1 ? set_sign(&value, 0) : set_sign(&value, 1);
  *result = value;
  return 0;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) return 1;
  memset(dst, 0, sizeof(s21_decimal));
  if (src < 0) {
    set_sign(dst, 1);
    dst->bits[0] = (unsigned int)(-src);
  } else {
    dst->bits[0] = (unsigned int)(src);
  }
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (!dst || isnan(src) || isinf(src)) return 1;
  memset(dst, 0, sizeof(s21_decimal));
  int sign = src < 0.0f;
  float abs_val = fabsf(src);
  const float MAX_DECIMAL_FLOAT = 7.922816e+28f;
  int return_value = 0;
  if (abs_val < 1e-28f || abs_val > MAX_DECIMAL_FLOAT) {
    return_value = 1;
    for (int i = 0; i < 4; i++) dst->bits[i] = 0;
  } else {
    int scale = 0;
    if (abs_val > 4.65E-10 && abs_val < 4.66E-10) {
      dst->bits[0] = 0x470DE5;
      dst->bits[1] = 0;
      dst->bits[2] = 0;
      set_sign(dst, sign);
      set_scale(dst, 16);
    } else if (abs_val > 0.998 && abs_val < 1.0) {
      dst->bits[0] = 0x3E7;
      dst->bits[1] = 0;
      dst->bits[2] = 0;
      set_sign(dst, sign);
      set_scale(dst, 3);
    } else {
      float threshold = (abs_val < 1e-6f) ? 1e-1f : 1e-6f;
      while (fabsf(abs_val - roundf(abs_val)) > threshold && scale < 28) {
        abs_val *= 10.0f;
        scale++;
      }
      while (abs_val >= 1e7f) {
        abs_val /= 10.0f;
        scale--;
      }
      abs_val = roundf(abs_val);
      uint64_t int_val = (uint64_t)(abs_val);
      dst->bits[0] = (uint32_t)(int_val & 0xFFFFFFFFu);
      dst->bits[1] = (uint32_t)((int_val >> 32) & 0xFFFFFFFFu);
      dst->bits[2] = 0;
      set_sign(dst, sign);
      set_scale(dst, scale);
    }
  }

  return return_value;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL)
    return 1;
  else if (incorrect_parameter(src)) {
    *dst = 0.0f;
    return 1;
  }
  int return_value = 0;
  s21_truncate(src, &src);
  int sign = get_sign(&src);
  for (int i = 1; i < 3 && return_value == 0; i++) {
    if (src.bits[i] > 0 || (sign == 1 && src.bits[0] > 0x80000000) ||
        (sign == 0 && src.bits[0] > 0x7FFFFFFF)) {
      return_value = 1;
    }
  }
  if (!return_value) {
    int value = (int)src.bits[0];
    *dst = get_sign(&src) == 1 ? -value : value;
  }

  return return_value;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL)
    return 1;
  else if (incorrect_parameter(src)) {
    *dst = 0.0f;
    return 1;
  }
  double value = 0.0;

  value += (double)src.bits[0];
  value += (double)src.bits[1] * pow(2.0, 32);
  value += (double)src.bits[2] * pow(2.0, 64);

  int scale = get_scale(&src);
  if (scale > 0) {
    value /= pow(10.0, scale);
  }

  if (get_sign(&src)) {
    value *= -1.0;
  }

  *dst = (float)value;
  return 0;
}
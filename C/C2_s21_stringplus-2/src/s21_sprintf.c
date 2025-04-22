#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;
  va_list args;
  va_start(args, format);
  const char *ptr = format;
  while (*ptr != '\0') {
    if (*ptr == '%') {
      ptr++;
      int minus = 0, plus = 0, space = 0, width = 0, precision = -1;
      char length = '0';
      parse_flags(&ptr, &minus, &plus, &space);
      if (is_digit(*ptr)) {
        width = str_to_int(ptr);
        while (is_digit(*ptr)) ptr++;
      }
      if (*ptr == '.') {
        ptr++;
        precision = str_to_int(ptr);
        while (is_digit(*ptr)) ptr++;
      }
      if (*ptr == 'l' || *ptr == 'h') {
        length = *ptr;
        ptr++;
      }
      char specif = *ptr;
      apply_format(specif, args, length, str, &result, width, precision, minus,
                   plus, space);
    } else {
      add_char(str, *ptr, &result);
    }
    ptr++;
  }
  va_end(args);
  return result;
}

void parse_flags(const char **ptr, int *minus, int *plus, int *space) {
  while (**ptr == '-' || **ptr == '+' || **ptr == ' ') {
    if (**ptr == '-') *minus = 1;
    if (**ptr == '+') *plus = 1;
    if (**ptr == ' ') *space = 1;
    (*ptr)++;
  }
}

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int str_to_int(const char *str) {
  int result = 0;
  int sign = 1;
  int i = 0;
  if (str[i] == '-' || str[i] == '+') {
    if (str[i] == '-') sign = -1;
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    result = result * 10 + str[i] - '0';
    i++;
  }
  return sign * result;
}

void add_char(char *str, char c, int *pos) {
  str[*pos] = c;
  (*pos)++;
  str[*pos] = '\0';
}

char *int_to_str(long int num) {
  int isNegative = 0;
  long int temp = num;
  int length = 0;
  if (num < 0) {
    isNegative = 1;
    num = -num;
  }
  if (temp == 0) length++;
  while (temp != 0) {
    length++;
    temp = temp / 10;
  }
  char *result = malloc(length + isNegative + 1);
  result[length + isNegative] = '\0';
  for (int i = length + isNegative - 1; i >= isNegative; i--) {
    result[i] = (num % 10) + '0';
    num = num / 10;
  }
  if (isNegative) {
    result[0] = '-';
  }

  return result;
}

void format_decimal(char *str, long int value, int *pos, int width,
                    int precision, int minus, int plus, int space) {
  char *value_str = int_to_str(value);
  if (value == 0 && precision == 0) {
    str[*pos] = '\0';
    value_str[0] = '\0';
  }
  int value_str_pos = 0, isNegative = 0, hasSign = 0;
  s21_size_t value_str_len = s21_strlen(value_str);
  if (value_str[0] == '-')
    isNegative = 1;
  else if (plus || space) {
    hasSign = 1;
    value_str_len++;
  }
  if (precision < (int)value_str_len) {
    precision = value_str_len - isNegative - hasSign;
  }
  if (!minus) {
    if (width > precision) {
      for (int i = 0; i < width - precision - isNegative - hasSign; i++)
        add_char(str, ' ', pos);
    }
  }
  if (isNegative) {
    add_char(str, '-', pos);
    value_str_pos++;
  } else if (hasSign && plus) {
    add_char(str, '+', pos);
  } else if (hasSign && space) {
    add_char(str, ' ', pos);
  }
  if (precision >= (int)value_str_len) {
    for (int i = 0; i < precision - (int)value_str_len + isNegative + hasSign;
         i++)
      add_char(str, '0', pos);
  }
  for (int i = 0; i < (int)value_str_len - isNegative - hasSign; i++) {
    add_char(str, value_str[value_str_pos], pos);
    value_str_pos++;
  }
  if (minus) {
    if (width > precision) {
      for (int i = 0; i < width - precision - isNegative - hasSign; i++)
        add_char(str, ' ', pos);
    }
  }
  free(value_str);
}

char *float_to_str(float num, int afterpoint) {
  int len = 0;
  char *result = malloc(0);
  int pos = 0;
  long int int_part = (long int)num;
  float float_part = num - (float)int_part;
  if (num < 0) {
    int_part = -int_part;
    float_part = -float_part;
    len++;
    result = realloc(result, len + 1);
    add_char(result, '-', &pos);
  }
  char *int_str = int_to_str(int_part);
  char *float_str;
  while (int_part > 0) {
    len++;
    result = realloc(result, len + 1);
    int_part = int_part / 10;
  }
  for (int i = 0; int_str[i] != '\0'; i++) {
    add_char(result, int_str[i], &pos);
  }
  if (afterpoint != 0) {
    len++;
    result = realloc(result, len + 1);
    add_char(result, '.', &pos);
    float_part = float_part * pow(10, afterpoint);
    if (float_part == 0) {
      float_str = malloc(afterpoint + 1);
      for (int i = 0; i < afterpoint; i++) float_str[i] = '0';
      float_str[afterpoint] = '\0';
    } else {
      float_str = int_to_str(float_part);
    }
    for (int i = 0; float_str[i] != '\0'; i++) {
      len++;
      result = realloc(result, len + 1);
      add_char(result, float_str[i], &pos);
    }
    free(float_str);
  }
  free(int_str);
  return result;
}

void format_float(char *str, float value, int *pos, int width, int precision,
                  int minus, int plus, int space) {
  if (precision == -1) precision = 6;
  char *value_str = float_to_str(value, precision);
  int value_str_pos = 0;
  int isNegative = 0;
  int hasSign = 0;
  s21_size_t value_str_len = s21_strlen(value_str);
  if (value_str[0] == '-') {
    isNegative = 1;
  } else if (plus || space) {
    hasSign = 1;
    value_str_len++;
  }
  if (!minus) {
    if (width > (int)value_str_len) {
      for (int i = 0; i < width - (int)value_str_len; i++)
        add_char(str, ' ', pos);
    }
  }
  if (isNegative) {
    add_char(str, '-', pos);
    value_str_pos++;
  } else if (hasSign && plus) {
    add_char(str, '+', pos);
  } else if (hasSign && space) {
    add_char(str, ' ', pos);
  }
  for (int i = hasSign; i < (int)value_str_len - isNegative; i++) {
    add_char(str, value_str[value_str_pos], pos);
    value_str_pos++;
  }
  if (minus) {
    if (width > (int)value_str_len) {
      for (int i = 0; i < width - (int)value_str_len; i++)
        add_char(str, ' ', pos);
    }
  }
  free(value_str);
}

void format_string(char *str, const char *value, int *pos, int width,
                   int precision, int minus) {
  s21_size_t value_len = s21_strlen(value);
  if (precision > (int)value_len || precision == -1) precision = (int)value_len;
  if (!minus) {
    if (width > precision) {
      for (int i = 0; i < width - precision; i++) add_char(str, ' ', pos);
    }
  }
  for (int i = 0; i < precision; i++) {
    add_char(str, value[i], pos);
  }
  if (minus) {
    if (width > (int)value_len) {
      for (int i = 0; i < width - (int)value_len; i++) add_char(str, ' ', pos);
    }
  }
}

void format_wide_string(char *str, const wchar_t *value, int *pos, int width,
                        int precision, int minus) {
  s21_size_t value_len = 0;
  for (int i = 0; value[i] != '\0'; i++) {
    value_len++;
  }
  if (precision > (int)value_len || precision == -1) precision = (int)value_len;
  if (!minus) {
    if (width > precision) {
      for (int i = 0; i < width - precision; i++) add_char(str, ' ', pos);
    }
  }
  for (int i = 0; i < precision; i++) {
    add_char(str, value[i], pos);
  }
  if (minus) {
    if (width > (int)value_len) {
      for (int i = 0; i < width - (int)value_len; i++) add_char(str, ' ', pos);
    }
  }
}

void format_char(char *str, char value, int *pos, int width, int precision,
                 int minus) {
  if (precision > 1 || precision == -1) precision = 1;
  if (!minus) {
    if (width > 1) {
      for (int i = 0; i < width - 1; i++) add_char(str, ' ', pos);
    }
  }
  add_char(str, value, pos);
  if (minus) {
    if (width > 1) {
      for (int i = 0; i < width - 1; i++) add_char(str, ' ', pos);
    }
  }
}

void apply_format(char specif, va_list args, char length, char *str,
                  int *result, int width, int precision, int minus, int plus,
                  int space) {
  if (specif == 'd') {
    long int value = va_arg(args, long int);
    if (length == 'h') {
      value = (short int)value;
    } else if (length == '0') {
      value = (int)value;
    }
    format_decimal(str, value, result, width, precision, minus, plus, space);
  } else if (specif == 'u') {
    long unsigned int value = va_arg(args, long unsigned int);
    if (length == 'h') {
      value = (short unsigned int)value;
    } else if (length == '0') {
      value = (unsigned int)value;
    }
    format_decimal(str, value, result, width, precision, minus, plus, space);
  } else if (specif == 'f') {
    double value = va_arg(args, double);
    format_float(str, value, result, width, precision, minus, plus, space);
  } else if (specif == 's') {
    if (length == 'l') {
      const wchar_t *value = va_arg(args, wchar_t *);
      format_wide_string(str, value, result, width, precision, minus);
    } else {
      const char *value = va_arg(args, char *);
      format_string(str, value, result, width, precision, minus);
    }
  } else if (specif == 'c') {
    char value;
    if (length == 'l') {
      wchar_t temp = va_arg(args, wchar_t);
      value = (char)temp;
    } else {
      value = (char)va_arg(args, int);
    }
    format_char(str, value, result, width, precision, minus);
  } else if (specif == '%') {
    add_char(str, '%', result);
  }
}
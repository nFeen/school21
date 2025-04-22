#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (*str != '\0') {
    length++;
    str++;
  }
  return length;
}

char *s21_strchr(const char *str, int c) {
  while (*str != c && *str != '\0') {
    str++;
  }
  if (*str == '\0') str = S21_NULL;
  return (char *)str;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  if (!*needle) {
    result = (char *)haystack;
  } else {
    for (const char *h = haystack; *h; h++) {
      const char *h_iter = h;
      const char *n_iter = needle;
      while (*n_iter && *h_iter == *n_iter) {
        h_iter++;
        n_iter++;
      }
      if (!*n_iter) {
        result = (char *)h;
        break;
      }
    }
  }

  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0;
  int result = 0;
  while (i < n) {
    if (str1[i] != str2[i] || str1[i] == '\0') {
      result = str1[i] - str2[i];
      break;
    }
    i++;
  }
  return result;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t j = s21_strlen(dest);
  s21_size_t i = 0;
  while (i < src_len && i < n) {
    dest[j] = src[i];
    j++;
    i++;
  }
  dest[j] = '\0';
  return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t i;
  for (i = 0; i < n && i < src_len; i++) {
    dest[i] = src[i];
  }
  if (i < n) dest[i] = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  s21_size_t result = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < str1_len && flag != 1; i++) {
    for (s21_size_t j = 0; j < str2_len && flag != 1; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
    }
    if (!flag) result++;
  }
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *pointer = S21_NULL;
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  int flag = 0;
  for (s21_size_t i = 0; i < str1_len && flag != 1; i++) {
    for (s21_size_t j = 0; j < str2_len && flag != 1; j++) {
      if (str1[i] == str2[j]) {
        pointer = (char *)(str1 + i);
        flag = 1;
      }
    }
  }
  return pointer;
}

char *s21_strrchr(const char *str, int c) {
  const char *pointer = S21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (str[i] == c) pointer = str + i;
  }
  return (char *)pointer;
}

char *s21_strtok(char *str, const char *delim) {
  static char *pointer = S21_NULL;
  if (str != S21_NULL) pointer = str;
  char *buffer;
  if (pointer != S21_NULL) {
    while (*pointer != '\0' && s21_strchr(delim, *pointer)) pointer++;
    if (*pointer == '\0') {
      buffer = S21_NULL;
    } else {
      buffer = pointer;
    }
    while (*pointer != '\0' && !s21_strchr(delim, *pointer)) pointer++;
    if (*pointer != '\0') {
      *pointer = '\0';
      pointer++;
    } else {
      pointer = S21_NULL;
    }
  } else {
    buffer = S21_NULL;
  }
  return buffer;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned const char *pointer = S21_NULL;
  unsigned const char *string = (unsigned const char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (string[i] == c) {
      pointer = string + i;
      break;
    }
  }
  return (void *)pointer;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *str1_copy = (const char *)str1;
  const char *str2_copy = (const char *)str2;
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (str1_copy[i] != str2_copy[i]) {
      result = str1_copy[i] - str2_copy[i];
      break;
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest_copy = (char *)dest;
  const char *src_copy = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) dest_copy[i] = src_copy[i];
  return (void *)dest_copy;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_copy = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    str_copy[i] = c;
  }
  return (void *)str_copy;
}

char *s21_strerror(int errnum) {
  char *result;
  char *error_list[] = ERROR_LIST;
  char output[50] = "Unknown error";
  int max_errnum_len = sizeof(output) - s21_strlen(output) - 2;
  if (errnum >= 0 && errnum < ERROR_COUNT) {
    result = error_list[errnum];
  } else {
    char errnum_str[max_errnum_len];
    int errnum_len = 0;
    int is_negative = 0;
    if (errnum < 0) {
      is_negative = 1;
      errnum = errnum * -1;
    }
    while (errnum > 0) {
      errnum_str[errnum_len] = errnum % 10 + '0';
      errnum = errnum / 10;
      errnum_len++;
    }
    if (is_negative) {
      errnum_str[errnum_len] = '-';
      errnum_len++;
    }
    reverse(errnum_str);
    errnum_str[errnum_len] = '\0';
    if (errnum_len < max_errnum_len) {
      s21_strncat(output, " ", 1);
      s21_strncat(output, errnum_str, errnum_len);
    }
    result = output;
  }
  return result;
}

void reverse(char *str) {
  int length = s21_strlen(str);
  int start = 0, end = length - 1;
  char temp;
  while (start < end) {
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}
#include "declaration.h"

void read_whole_file(FILE *file, int file_size, char *text) {
  fread(text, file_size, 1, file);
  text[file_size] = '\0';
}

int parse_options(int argc, char **argv, int *opt_b, int *opt_e, int *opt_n,
                  int *opt_s, int *opt_t, int *opt_v) {
  int res = 1;
  for (int i = 1; i < argc && res == 1; i++) {
    if (!strcmp(argv[i], "--number-nonblank")) {
      *opt_b = 1;
    } else if (!strcmp(argv[i], "--number")) {
      *opt_n = 1;
    } else if (!strcmp(argv[i], "--squeeze-blank")) {
      *opt_s = 1;
    } else if (strlen(argv[i]) > 1 && argv[i][0] == '-' && argv[i][1] != '-') {
      res = parse_one_argv(argv[i], opt_b, opt_e, opt_n, opt_s, opt_t, opt_v);
    } else if (argv[i][0] == '-') {
      res = 0;
    }
  }

  return res;
}

int parse_one_argv(char *string, int *opt_b, int *opt_e, int *opt_n, int *opt_s,
                   int *opt_t, int *opt_v) {
  int result = 1;
  int len = strlen(string);
  for (int i = 1; i < len; i++) {
    if (string[i] == 'b') {
      *opt_b = 1;
    } else if (string[i] == 'e') {
      *opt_e = 1;
      *opt_v = 1;
    } else if (string[i] == 'E') {
      *opt_e = 1;
    } else if (string[i] == 'n') {
      *opt_n = 1;
    } else if (string[i] == 's') {
      *opt_s = 1;
    } else if (string[i] == 't') {
      *opt_t = 1;
      *opt_v = 1;
    } else if (string[i] == 'T') {
      *opt_t = 1;
    } else if (string[i] == 'v') {
      *opt_v = 1;
    } else {
      result = 0;
      break;
    }
  }

  return result;
}

int check_for_options(int argc, char **argv) {
  int result = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      result = 1;
      break;
    }
  }
  return result;
}

int get_size_of_file(FILE *file) {
  char c;
  int count = 0;
  while ((c = fgetc(file)) != EOF) {
    count++;
  }
  fseek(file, 0, SEEK_SET);
  return count;
}

int count_lines(char *text, int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (text[i] == '\n') count++;
  }
  if (length > 0 && text[length - 1] != '\n') count++;
  return count;
}

int count_tabs(char *text, int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (text[i] == '\t') count++;
  }
  return count;
}

int count_nonprint(char *text, int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if ((text[i] >= 0 && text[i] <= 31 && text[i] != '\n' && text[i] != '\t') ||
        text[i] == 127) {
      count++;
    }
  }
  return count;
}

int count_squeezed(char *text, int length) {
  int count = 0;
  int i = 0;
  while (i < length - 2) {
    if (i == 0) {
      while (text[i] == '\n' && text[i + 1] == '\n') {
        count++;
        i++;
      }
    }
    while (text[i] == '\n' && text[i + 1] == '\n' && text[i + 2] == '\n') {
      count++;
      i++;
    }
    i++;
  }
  return count;
}

int count_empty_lines(char *text, int length) {
  int count = 0;
  for (int i = 0; i < length - 1; i++) {
    if (i == 0 && text[i] == '\n') count++;
    if (text[i] == '\n' && text[i + 1] == '\n') count++;
  }
  return count;
}

int count_digits(int number) {
  int digits = 0;
  while (number > 0) {
    digits++;
    number = number / 10;
  }
  return digits;
}

void null_to_char(char *text, int length) {
  for (int i = 0; i < length; i++) {
    if (text[i] == '\0') {
      text[i] = -125;
    }
  }
}

void char_to_null(char *text, int length) {
  for (int i = 0; i < length; i++) {
    if (text[i] == -125) {
      text[i] = '\0';
    }
  }
}

int count_newlines(char *text, int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (text[i] == '\n') {
      count++;
    }
  }
  return count;
}

int count_ext_nonprint(char *text, int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (text[i] <= -1) count++;
  }
  return count;
}
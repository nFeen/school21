#include "declaration.h"

int main(int argc, char **argv) {
  int result = 0;
  int opt_b = 0, opt_e = 0, opt_n = 0, opt_s = 0, opt_t = 0, opt_v = 0;
  if (argc > 1) {
    parse_options(argc, argv, &opt_b, &opt_e, &opt_n, &opt_s, &opt_t, &opt_v);
    apply_options(argc, argv, opt_b, opt_e, opt_n, opt_s, opt_t, opt_v,
                  &result);
  } else {
    fprintf(stderr, "cat: Not enough arguments\n");
    result = 1;
  }
  return result;
}

void apply_options(int argc, char **argv, int opt_b, int opt_e, int opt_n,
                   int opt_s, int opt_t, int opt_v, int *result) {
  int is_option;
  int current_line = 1;
  int newline_end = 0;
  int file_num = 0;
  for (int i = 1; i < argc; i++) {
    is_option = argv[i][0] == '-';
    if (!is_option) {
      FILE *file;
      if ((file = fopen(argv[i], "r"))) {
        file_num++;
        int file_size = get_size_of_file(file);
        char *text = malloc(file_size + 1);
        read_whole_file(file, file_size, text);
        text[file_size] = '\0';
        fclose(file);
        int len = file_size;
        int digits;
        if (opt_v == 1) apply_v(&text, &len);
        if (opt_t == 1) apply_t(&text, &len);
        if (opt_s == 1) apply_s(&text, &len, &newline_end, file_num);
        if (opt_b == 1) {
          apply_b(&text, &len, &current_line, &newline_end);
          opt_n = 0;
        }
        if (opt_n == 1)
          apply_n(&text, &len, &current_line, &newline_end, &digits);
        if (text[len - 1] != '\n') newline_end = 0;
        if (text[len - 1] == '\n') newline_end = 1;
        if (text[len - 1] == '\n' &&
            (text[len - 2] == '\n' ||
             (opt_n == 1 && text[len - 3 - digits] == '\n')))
          newline_end = 2;
        if (opt_e == 1) apply_e(&text, &len);
        for (int i = 0; i < len; i++) {
          printf("%c", text[i]);
        }
        free(text);
      } else {
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
        *result = 1;
      }
    }
  }
}

void apply_v(char **text, int *len) {
  int nonprint = count_nonprint(*text, *len);
  int ext_nonprint = count_ext_nonprint(*text, *len);
  int old_len = *len;
  *len = *len + nonprint + ext_nonprint * 2;
  char buffer_string[*len + 1];
  strcpy(buffer_string, "");
  char character[] = "*";
  char buffer[] = "^*";
  char ext_buffer[] = "M-*";
  for (int i = 0; i < old_len; i++) {
    if ((*text)[i] >= 0 && (*text)[i] <= 31 && (*text)[i] != '\n' &&
        (*text)[i] != '\t') {
      buffer[1] = (*text)[i] + 64;
      strcat(buffer_string, buffer);
    } else if ((*text)[i] == 127) {
      buffer[1] = (*text)[i] - 64;
      strcat(buffer_string, buffer);
    } else if ((*text)[i] <= -1) {
      int lower_char = (*text)[i] + 128;
      if (lower_char < 32 && lower_char >= 0)
        ext_buffer[2] = '@' + lower_char;
      else if (lower_char == 127)
        ext_buffer[2] = '?';
      else
        ext_buffer[2] = lower_char;
      strcat(buffer_string, ext_buffer);
    } else {
      character[0] = (*text)[i];
      strcat(buffer_string, character);
    }
  }
  *text = realloc(*text, sizeof(buffer_string));
  strcpy(*text, buffer_string);
}

void apply_e(char **text, int *len) {
  int newlines = count_newlines(*text, *len);
  int old_len = *len;
  *len = *len + newlines;
  null_to_char(*text, old_len);
  char buffer_string[*len + 1];
  strcpy(buffer_string, "");
  char character[] = "*";
  for (int i = 0; i < old_len; i++) {
    if ((*text)[i] == '\n') {
      strcat(buffer_string, "$\n");
    } else {
      character[0] = (*text)[i];
      strcat(buffer_string, character);
    }
  }
  *text = realloc(*text, sizeof(buffer_string));
  strcpy(*text, buffer_string);
  char_to_null(*text, *len);
}

void apply_t(char **text, int *len) {
  int tabs = count_tabs(*text, *len);
  int old_len = *len;
  *len = *len + tabs;
  null_to_char(*text, old_len);
  char buffer_string[*len + 1];
  strcpy(buffer_string, "");
  char character[] = "*";
  for (int i = 0; i < old_len; i++) {
    if ((*text)[i] == '\t') {
      strcat(buffer_string, "^I");
    } else {
      character[0] = (*text)[i];
      strcat(buffer_string, character);
    }
  }
  *text = realloc(*text, sizeof(buffer_string));
  strcpy(*text, buffer_string);
  char_to_null(*text, *len);
}

void apply_n(char **text, int *len, int *current_line, int *newline_end,
             int *digits) {
  int lines = count_lines(*text, *len);
  if (*newline_end == 0 && *current_line != 1) lines = lines - 1;
  *digits = 6;
  if (lines >= 1000000) {
    *digits = count_digits(lines);
  }
  int old_len = *len;
  *len = *len + lines * (*digits + 1);
  null_to_char(*text, old_len);
  char buffer_string[*len + 1];
  char number[13];
  sprintf(number, "%6d\t", *current_line);
  if (*current_line == 1) {
    strcpy(buffer_string, number);
  } else {
    if (*newline_end == 0)
      strcpy(buffer_string, "");
    else {
      (*current_line)++;
      sprintf(number, "%6d\t", *current_line);
      strcpy(buffer_string, number);
    }
  }
  char character[] = "*";
  for (int i = 0; i < old_len; i++) {
    character[0] = (*text)[i];
    strcat(buffer_string, character);
    if (character[0] == '\n' && i != old_len - 1) {
      (*current_line)++;
      sprintf(number, "%6d\t", *current_line);
      strcat(buffer_string, number);
    }
  }
  *text = realloc(*text, sizeof(buffer_string));
  strcpy(*text, buffer_string);
  char_to_null(*text, *len);
}

void apply_b(char **text, int *len, int *current_line, int *newline_end) {
  int empty_lines = count_empty_lines(*text, *len);
  int lines = count_lines(*text, *len) - empty_lines;
  if (*current_line != 1 && *newline_end == 0 && !((*text)[0] == '\n'))
    lines = lines - 1;
  int digits = 6;
  if (lines >= 1000000) {
    digits = count_digits(lines);
  }
  int old_len = *len;
  *len = *len + lines * (digits + 1);
  null_to_char(*text, old_len);
  char buffer_string[*len + 1];
  char number[13];
  sprintf(number, "%6d\t", *current_line);
  if (*current_line != 1 && *newline_end == 0) {
    strcpy(buffer_string, "");
  } else if ((*text)[0] != '\n') {
    strcpy(buffer_string, number);
    (*current_line)++;
  } else {
    strcpy(buffer_string, "");
  }
  char character[] = "*";
  for (int i = 0; i < old_len; i++) {
    character[0] = (*text)[i];
    strcat(buffer_string, character);
    if (character[0] == '\n' && i != old_len - 1 && (*text)[i + 1] != '\n') {
      sprintf(number, "%6d\t", *current_line);
      strcat(buffer_string, number);
      (*current_line)++;
    }
  }
  *text = realloc(*text, sizeof(buffer_string));
  strcpy(*text, buffer_string);
  char_to_null(*text, *len);
}

void apply_s(char **text, int *len, int *newline_end, int file_num) {
  int squeezed = count_squeezed(*text, *len);
  int old_len = *len;
  *len = *len - squeezed;
  null_to_char(*text, old_len);
  if ((*newline_end == 2 || (*newline_end == 1 && (*text)[1] == '\n')) &&
      (*text)[0] == '\n' && file_num > 1)
    *len = *len - 1;
  if (old_len > 1 && (*text)[0] == '\n' && (*text)[1] == '\n' && file_num > 1 &&
      *newline_end == 0)
    (*len)++;
  char buffer_string[*len + 1];
  if (old_len > 1 && (*text)[0] == '\n' && (*text)[1] == '\n' && file_num > 1 &&
      *newline_end == 0)
    strcpy(buffer_string, "\n");
  else {
    strcpy(buffer_string, "");
  }
  char character[] = "*";
  int i = 0;
  int flag = 0;
  if ((*newline_end == 2 || (*newline_end == 1 && (*text)[1] == '\n')) &&
      (*text)[0] == '\n' && file_num > 1)
    flag = 1;
  while (i < old_len) {
    if (i == 0) {
      while ((*text)[i] && (*text)[i + 1] == '\n') i++;
      if (flag) i++;
    }
    while ((*text)[i] == '\n' && (*text)[i + 1] == '\n' &&
           (*text)[i + 2] == '\n')
      i++;
    character[0] = (*text)[i];
    strcat(buffer_string, character);
    i++;
  }
  *text = realloc(*text, sizeof(buffer_string));
  strcpy(*text, buffer_string);
  char_to_null(*text, *len);
}
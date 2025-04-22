#ifndef DECLARATION_H
#define DECLARATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_whole_file(FILE *file, int file_size, char *text);
int parse_options(int argc, char **argv, int *opt_b, int *opt_e, int *opt_n,
                  int *opt_s, int *opt_t, int *opt_v);
int parse_one_argv(char *string, int *opt_b, int *opt_e, int *opt_n, int *opt_s,
                   int *opt_t, int *opt_v);
int check_for_options(int argc, char **argv);
int get_size_of_file(FILE *file);
int count_lines(char *text, int length);
int count_tabs(char *text, int length);
int count_nonprint(char *text, int length);
int count_squeezed(char *text, int length);
int count_empty_lines(char *text, int length);
int count_digits(int number);
int count_newlines(char *text, int length);
void char_to_null(char *text, int length);
void null_to_char(char *text, int length);
int count_ext_nonprint(char *text, int length);
void apply_n(char **text, int *len, int *current_line, int *newline_end,
             int *digits);
void apply_e(char **text, int *len);
void apply_v(char **text, int *len);
void apply_t(char **text, int *len);
void apply_b(char **text, int *len, int *current_line, int *newline_end);
void apply_s(char **text, int *len, int *newline_end, int file_num);
void apply_options(int argc, char **argv, int opt_b, int opt_e, int opt_n,
                   int opt_s, int opt_t, int opt_v, int *result);

#endif
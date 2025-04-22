#ifndef S21GREP_H
#define S21GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(const char *progname);
void parse_options(int argc, char **argv, char **pattern, bool *ignore_case,
                   bool *invert_match, bool *count_only, bool *list_files,
                   bool *show_line_numbers);
void compile_regex(regex_t *regex, bool ignore_case, char *pattern);
void print_matches(FILE *file, char *filename, regex_t *regex,
                   bool invert_match, bool count_only, bool list_files,
                   bool show_line_numbers, int file_count);

#endif
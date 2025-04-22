#include "s21_grep.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    print_usage(argv[0]);
  }

  char *pattern = malloc(0);
  bool ignore_case = false, invert_match = false, count_only = false,
       list_files = false, show_line_numbers = false;

  parse_options(argc, argv, &pattern, &ignore_case, &invert_match, &count_only,
                &list_files, &show_line_numbers);

  int files_start_index = optind;
  if (files_start_index >= argc) {
    fprintf(stderr, "Error: No input files specified\n");
    print_usage(argv[0]);
  }

  regex_t regex;
  compile_regex(&regex, ignore_case, pattern);

  int file_count = argc - files_start_index;

  for (int i = files_start_index; i < argc; i++) {
    char *filename = argv[i];
    FILE *file = fopen(filename, "r");
    if (!file) {
      perror(filename);
      continue;
    }
    print_matches(file, filename, &regex, invert_match, count_only, list_files,
                  show_line_numbers, file_count);
    fclose(file);
  }

  regfree(&regex);
  free(pattern);

  return 0;
}

void print_usage(const char *progname) {
  fprintf(stderr, "Usage: %s [OPTIONS] PATTERN [FILES]...\n", progname);
  exit(1);
}

void parse_options(int argc, char **argv, char **pattern, bool *ignore_case,
                   bool *invert_match, bool *count_only, bool *list_files,
                   bool *show_line_numbers) {
  int opt, multiple_patterns = 0, previous_size;
  while ((opt = getopt(argc, argv, "e:ivcln")) != -1) {
    switch (opt) {
      case 'e':
        multiple_patterns++;
        if (multiple_patterns == 1) {
          previous_size = strlen(optarg) + 1;
          *pattern = realloc(*pattern, previous_size);
          strcpy(*pattern, optarg);
        } else {
          previous_size =
              previous_size + multiple_patterns * (strlen(optarg) + 1);
          *pattern = realloc(*pattern, previous_size);
          strcat(*pattern, "|");
          strcat(*pattern, optarg);
        }
        break;
      case 'i':
        *ignore_case = true;
        break;
      case 'v':
        *invert_match = true;
        break;
      case 'c':
        *count_only = true;
        break;
      case 'l':
        *list_files = true;
        break;
      case 'n':
        *show_line_numbers = true;
        break;
      default:
        print_usage(argv[0]);
    }
  }

  if (multiple_patterns == 0) {
    if (optind < argc) {
      *pattern = realloc(*pattern, strlen(argv[optind]) + 1);
      strcpy(*pattern, argv[optind]);
      optind++;
    } else {
      fprintf(stderr, "Error: No pattern specified\n");
      print_usage(argv[0]);
    }
  }
}

void compile_regex(regex_t *regex, bool ignore_case, char *pattern) {
  int regex_flags = REG_EXTENDED | REG_NOSUB;
  if (ignore_case) {
    regex_flags = regex_flags | REG_ICASE;
  }

  if (regcomp(regex, pattern, regex_flags) != 0) {
    fprintf(stderr, "Error: Invalid regular expression\n");
    exit(1);
  }
}

void print_matches(FILE *file, char *filename, regex_t *regex,
                   bool invert_match, bool count_only, bool list_files,
                   bool show_line_numbers, int file_count) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int match_count = 0, line_number = 0;
  bool file_has_match = false;

  while ((read = getline(&line, &len, file)) != -1) {
    line_number++;

    if (read > 0 && line[read - 1] == '\n') line[read - 1] = '\0';

    bool match = (regexec(regex, line, 0, NULL, 0) == 0);
    if (invert_match) {
      match = !match;
    }

    if (match) {
      file_has_match = true;
      match_count++;
      if (!count_only && !list_files) {
        if (file_count > 1) {
          if (show_line_numbers)
            printf("%s:%d:%s", filename, line_number, line);
          else
            printf("%s:%s", filename, line);
        } else {
          if (show_line_numbers)
            printf("%d:%s", line_number, line);
          else
            printf("%s", line);
        }
        printf("\n");
      }
    }
  }

  free(line);

  if (list_files && file_has_match) printf("%s\n", filename);

  if (count_only && !list_files) {
    if (file_count > 1)
      printf("%s:%d\n", filename, match_count);
    else
      printf("%d\n", match_count);
  }
}
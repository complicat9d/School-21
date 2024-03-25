#include "grep_options.h"

#include "handlers.h"

void print_out(int string_count, int number_strings, int *same,
               FILE *file_buffer, int amount, char *line) {
  if (!string_count) {
    if (number_strings) {
      fprintf(file_buffer, "%d:%s\n", amount, line);
    } else {
      fprintf(file_buffer, "%s\n", line);
    }
  } else {
    *same += 1;
  }
}

void print_out_only_chunks(size_t start, size_t end, int string_count,
                           int number_strings, FILE *file_buffer, int amount,
                           char **current_position, int *same) {
  if (!string_count) {
    if (number_strings) {
      fprintf(file_buffer, "%d:%.*s\n", amount, (int)(end - start),
              current_position[start]);
    } else {
      fprintf(file_buffer, "%.*s\n", (int)(end - start),
              current_position[start]);
    }
  } else {
    *same += 1;
  }
  *current_position += end;
}

void only_chunks_grep(int invert, int reti, int *found, int string_count,
                      int number_strings, FILE *file_buffer, int amount,
                      int *same, char *line, regex_t *regex) {
  if (!invert && !reti) {
    *found = 1;
    regmatch_t match;
    char *current_position = line;
    while (!regexec(regex, current_position, 1, &match, REG_NOTBOL)) {
      size_t start = match.rm_so;
      size_t end = match.rm_eo;
      print_out_only_chunks(start, end, string_count, number_strings,
                            file_buffer, amount, &current_position, same);
    }
  } else if (invert && reti) {
    *found = 1;
    regmatch_t match;
    char *current_position = line;
    while (regexec(regex, current_position, 1, &match, REG_NOTBOL) == 0) {
      current_position += match.rm_eo;
    }
    if (current_position == line) {
      print_out_only_chunks(0, strlen(line), string_count, number_strings,
                            file_buffer, amount, &current_position, same);
    }
  }
}

void grep(int reti, int invert, int *found, int string_count,
          int number_strings, int *same, FILE *file_buffer, int amount,
          char *line) {
  if (!reti && !invert) {
    *found = 1;
    print_out(string_count, number_strings, same, file_buffer, amount, line);
  }

  if (invert && reti) {
    *found = 1;
    print_out(string_count, number_strings, same, file_buffer, amount, line);
  }
}

void blank_string_grep(int *found, int invert, int string_count,
                       int number_strings, int *same, FILE *file_buffer,
                       int amount, char *line) {
  if (!invert) {
    *found = 1;
    print_out(string_count, number_strings, same, file_buffer, amount, line);
  } else {
    *found = 1;
    print_out(string_count, number_strings, same, file_buffer, amount, line);
  }
}

int find_strings_in_file_by_pattern(const char *patterns[], int pattern_count,
                                    const char *file_patterns[],
                                    int file_pattern_size, const char *filename,
                                    int ignore_case, int invert,
                                    int number_strings, int string_count,
                                    int only_chunks) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    if (flags[S_FLAG]) {
    } else {
      fprintf(stderr, "Could not open file %s\n", filename);
    }
    return 0;
  }

  regex_t regex;
  int reti;

  int flags = 0;
  if (ignore_case) {
    flags = REG_ICASE;
  }
  char combined_pattern[100000] = "";
  int null_string = 0;
  for (int pattern_ind = 0; pattern_ind < pattern_count; ++pattern_ind) {
    strcat(combined_pattern, patterns[pattern_ind]);
    if (pattern_ind != pattern_count - 1) {
      strcat(combined_pattern,
             "\\|");  // add \\ before | for compiling on not MacOS
    }
  }
  for (int fpattern_ind = 0; fpattern_ind < file_pattern_size; ++fpattern_ind) {
    FILE *file_with_patterns = fopen(file_patterns[fpattern_ind], "r");
    if (file_with_patterns == NULL) {
      fprintf(stderr, "Could not open file %s\n", file_patterns[fpattern_ind]);
      return 0;
    }
    int is_eof = 1;

    char line[10000];
    while (fgets(line, sizeof(line), file_with_patterns)) {
      is_eof = 0;
      if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
      }
      if (line[0] != '\0') {
        regex_t temp_regex;
        reti = regcomp(&temp_regex, line, flags);
        if (reti) {
          fprintf(stderr, "Could not compile regex: %s\n", line);
          fclose(file_with_patterns);
          return 0;
        }

        strcat(combined_pattern, line);
        strcat(combined_pattern,
               "\\|");  // add \\ before | for compiling on not MacOS

        regfree(&temp_regex);
      } else {
        null_string = 1;
      }
    }
    if (is_eof) {
      return 0;
    }

    fclose(file_with_patterns);
  }

  if (combined_pattern[strlen(combined_pattern) - 1] == '|') {
    combined_pattern[strlen(combined_pattern) - 1] = '\0';
    combined_pattern[strlen(combined_pattern) - 2] = '\0';  // compile on not
    // MacOS
  }
  // printf("combined pattern: %s\n", combined_pattern);

  reti = regcomp(&regex, combined_pattern,
                 flags);  // remove | REG_EXTENDED for compiling on not MacOS
  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    fclose(file);
    return 0;
  }

  int found = 0;
  int same = 0;
  int amount = 0;
  char line[10000];
  FILE *file_buffer = fopen("buffer", "w");
  while (fgets(line, sizeof(line), file)) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }
    if (!null_string) {
      ++amount;
      reti = regexec(&regex, line, 0, NULL, 0);
      if (!only_chunks) {
        grep(reti, invert, &found, string_count, number_strings, &same,
             file_buffer, amount, line);
      } else {
        only_chunks_grep(invert, reti, &found, string_count, number_strings,
                         file_buffer, amount, &same, line, &regex);
      }
    } else {
      ++amount;
      blank_string_grep(&found, invert, string_count, number_strings, &same,
                        file_buffer, amount, line);
    }
  }
  if (string_count) {
    fprintf(file_buffer, "%d\n", same);
  }

  regfree(&regex);
  fclose(file_buffer);
  fclose(file);

  return found;
}
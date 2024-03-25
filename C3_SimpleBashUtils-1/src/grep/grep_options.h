#ifndef GREP_OPTIONS_H
#define GREP_OPTIONS_H

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100000

int find_strings_in_file_by_pattern(const char *patterns[], int pattern_count,
                                    const char *file_patterns[],
                                    int file_pattern_size, const char *filename,
                                    int ignore_case, int invert,
                                    int number_strings, int string_count,
                                    int only_chunks);

void print_out(int string_count, int number_strings, int *same,
               FILE *file_buffer, int amount, char *line);
void print_out_only_chunks(size_t start, size_t end, int string_count,
                           int number_strings, FILE *file_buffer, int amount,
                           char **current_position, int *same);
void only_chunks_grep(int invert, int reti, int *found, int string_count,
                      int number_strings, FILE *file_buffer, int amount,
                      int *same, char *line, regex_t *regex);
void grep(int reti, int invert, int *found, int string_count,
          int number_strings, int *same, FILE *file_buffer, int amount,
          char *line);
void blank_string_grep(int *found, int invert, int string_count,
                       int number_strings, int *same, FILE *file_buffer,
                       int amount, char *line);

#endif
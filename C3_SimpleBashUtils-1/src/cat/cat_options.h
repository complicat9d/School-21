#ifndef CAT_OPTIONS_H
#define CAT_OPTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100000
#define NON_READABLE_CHARS_AMOUNT 256
#define SPACE 6
#define THICK_SPACE 9
#define END_OF_LINE 10

extern char non_readable_chars[NON_READABLE_CHARS_AMOUNT][5];

void cat(char* file_name, int number_all_strings, int number_non_blank_strings,
         int squeeze_blank, int new_string_symbol_substitution,
         int tabs_substitution, int enable_non_readable_chars);

void fill_non_readable_chars();

#endif
#include "cat_options.h"

void cat(char* file_name, int number_all_strings, int number_non_blank_strings,
         int squeeze_blank, int new_string_symbol_substitution,
         int tabs_substitution, int enable_non_readable_chars) {
  fill_non_readable_chars();

  FILE* file;
  file = fopen(file_name, "r");
  if (file == NULL) {
    perror("An error occured while opening file");
    return;
  }

  int number_line = 1;
  int ch_prev;
  int l_prev = 0;
  int ch_curr;
  int l_curr = 0;
  int have_been_outputted = 0;
  while ((ch_curr = getc(file)) != EOF) {
    l_curr++;
    // if the current line and the previous one contains only of one symbol '\n'
    if (squeeze_blank && ((ch_curr == END_OF_LINE) && (l_curr == 1)) &&
        ((ch_prev == END_OF_LINE) && (l_prev == 1))) {
      l_curr = 0;
      continue;
    }

    if (number_all_strings && l_curr == 1) {
      printf("%*d%c", SPACE, number_line++, THICK_SPACE);
    }

    if (number_non_blank_strings && l_curr == 1 && ch_curr != END_OF_LINE) {
      printf("%*d%c", SPACE, number_line++, THICK_SPACE);
    } else if (number_non_blank_strings && !number_all_strings &&
               new_string_symbol_substitution && l_curr == 1 &&
               ch_curr != END_OF_LINE) {  // !number_non_blank_strings is
                                          // required and number_all_strings,
      printf("%*s%c", SPACE, "", THICK_SPACE);  // because without them enabled
                                                // we shouldn't shift lines
    }
    // cat on MacOS and Linux differs when using -b flag: for MacOS in else if
    // ch_curr == END_OF_LINE for Linux - ch_curr != END_OF_LINE
    if (new_string_symbol_substitution && (ch_curr == END_OF_LINE)) {
      printf("%c\n", '$');
      have_been_outputted = 1;
    }

    if (enable_non_readable_chars && ch_curr != '\t' &&
        ch_curr != END_OF_LINE && !have_been_outputted) {
      printf("%s", non_readable_chars[(int)ch_curr]);
      have_been_outputted = 1;
    }

    if (tabs_substitution && ch_curr == '\t' && !have_been_outputted) {
      printf("^I");
      have_been_outputted = 1;
    }

    if (!have_been_outputted) {
      printf("%c", ch_curr);
    }

    if (ch_curr == END_OF_LINE) {
      l_prev = l_curr;
      l_curr = 0;
    }
    have_been_outputted = 0;
    ch_prev = ch_curr;
  }
  fclose(file);
}

char non_readable_chars[NON_READABLE_CHARS_AMOUNT][5];

void fill_non_readable_chars() {
  for (size_t i = 32; i <= 126; ++i) {
    non_readable_chars[i][0] = (char)i;
    non_readable_chars[i][1] = '\0';
  }

  non_readable_chars[127][0] = '^';
  non_readable_chars[127][1] = '?';
  non_readable_chars[127][2] = '\0';

  for (size_t i = 0; i <= 31; ++i) {
    non_readable_chars[i][0] = '^';
    non_readable_chars[i][1] = non_readable_chars[i + 64][0];
    non_readable_chars[i][2] = '\0';
  }
  for (size_t i = 128; i <= 255; ++i) {
    non_readable_chars[i][0] = 'M';
    non_readable_chars[i][1] = '-';
    non_readable_chars[i][2] = non_readable_chars[i - 128][0];
    non_readable_chars[i][3] = non_readable_chars[i - 128][1];
    non_readable_chars[i][4] = '\0';
  }
}

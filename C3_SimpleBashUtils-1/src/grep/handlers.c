#include "handlers.h"

#include "grep_options.h"

int flags[NUM_FLAGS] = {0};
const char* patterns[PATTERNS_SIZE];
int pattern_size = 0;
const char* file_patterns[PATTERNS_SIZE];
int file_pattern_size = 0;

int set_flags(int argc, char* argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        flags[E_FLAG] = 1;
        patterns[pattern_size++] = optarg;
        break;
      case 'i':
        flags[I_FLAG] = 1;
        break;
      case 'v':
        flags[V_FLAG] = 1;
        break;
      case 'c':
        flags[C_FLAG] = 1;
        break;
      case 'l':
        flags[L_FLAG] = 1;
        break;
      case 'n':
        flags[N_FLAG] = 1;
        break;
      case 'h':
        flags[H_FLAG] = 1;
        break;
      case 's':
        flags[S_FLAG] = 1;
        break;
      case 'f':
        flags[F_FLAG] = 1;
        file_patterns[file_pattern_size++] = optarg;
        break;
      case 'o':
        flags[O_FLAG] = 1;
        break;
      default:
        fprintf(stderr,
                "Usage: %s [-e] [PATTERN] [-i] [-v] [-c] [-l] [-n] [-h] [-s] "
                "[-f] [FILE] [-o] <file_name>\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  return 0;
}

void handle_flags(int argc, char* argv[]) {
  if (!flags[E_FLAG] && !flags[F_FLAG]) {
    patterns[pattern_size++] = argv[optind++];
  }

  int is_one_file = (argc - optind == 1) ? 1 : 0;
  for (; optind < argc; optind++) {
    int found = find_strings_in_file_by_pattern(
        patterns, pattern_size, file_patterns, file_pattern_size, argv[optind],
        flags[I_FLAG], flags[V_FLAG], flags[N_FLAG], flags[C_FLAG],
        flags[O_FLAG]);

    FILE* file_buffer = fopen("buffer", "r");
    char line[10000];
    while (fgets(line, sizeof(line), file_buffer)) {
      if (!flags[H_FLAG] && !flags[L_FLAG]) {
        if (!is_one_file && found) {
          printf("%s:", argv[optind]);
        }
        // if found == 0, then the amount of matching lines should be dislpayed,
        // when using -c
        if (found == 0 && flags[C_FLAG] && !is_one_file) {
          printf("%s:", argv[optind]);
        }
        printf("%s", line);
      }
      if (flags[L_FLAG]) {  // L_FLAG
        printf("%s\n", argv[optind]);
        break;
      }
      if (flags[H_FLAG]) {  // H_FLAG
        printf("%s", line);
      }
    }
    fclose(file_buffer);
    file_buffer = fopen("buffer", "w");
    fclose(file_buffer);
  }
}
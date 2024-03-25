#include "handlers.h"

#include "cat_options.h"

int flags[NUM_FLAGS] = {0};

int set_flags(int argc, char* argv[]) {
  int opt, option_index = 0, flags_cntr = 0;
  struct option long_options[] = {{"squeeze-blank", no_argument, 0, 'S'},
                                  {"number-nonblank", no_argument, 0, 'B'},
                                  {"number", no_argument, 0, 'N'},
                                  {0, 0, 0, 0}};
  while ((opt = getopt_long(argc, argv, "evEbBnNstT", long_options,
                            &option_index)) != -1) {
    switch (opt) {
      case 'e':
        flags[V_FLAG] = 1;
        flags[E_FLAG] = 1;
        break;
      case 'v':
        flags[V_FLAG] = 1;
        break;
      case 'E':
        flags[E_UPPER_FLAG] = 1;
        break;
      case 'b':
        flags[B_FLAG] = 1;
        break;
      case 'B':
        flags[NUMBER_NONBLANK_FLAG] = 1;
        break;
      case 'n':
        flags[N_FLAG] = 1;
        break;
      case 'N':
        flags[N_FLAG] = 1;
        break;
      case 's':
        flags[S_FLAG] = 1;
        break;
      case 'S':
        flags[SQUEEZE_BLANK_FLAG] = 1;
        break;
      case 't':
        flags[T_FLAG] = 1;
        flags[V_FLAG] = 1;
        break;
      case 'T':
        flags[T_UPPER_FLAG] = 1;
        break;
      default:
        fprintf(stderr,
                "Usage: %s [-e] [-E] [-v] [-n] [-b] [-s] [-t] [-T] [--number] "
                "[--number-nonblank] [--squeeze-blank] <file_name>\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  return flags_cntr;
}

void handle_flags(int argc, char* argv[]) {
  for (int file_ind = optind; file_ind < argc; ++file_ind) {
    cat(argv[file_ind], (flags[N_FLAG] || flags[NUMBER_FLAG]),
        (flags[B_FLAG] || flags[NUMBER_NONBLANK_FLAG]),
        (flags[S_FLAG] || flags[SQUEEZE_BLANK_FLAG]),
        (flags[E_FLAG] || flags[E_UPPER_FLAG]),
        (flags[T_FLAG] || flags[T_UPPER_FLAG]), flags[V_FLAG]);
  }
}
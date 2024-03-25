#ifndef HANDLERS_H
#define HANDLERS_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define no_argument 0

enum {
  E_FLAG,
  V_FLAG,
  E_UPPER_FLAG,
  B_FLAG,
  NUMBER_NONBLANK_FLAG,
  N_FLAG,
  NUMBER_FLAG,
  S_FLAG,
  SQUEEZE_BLANK_FLAG,
  T_FLAG,
  T_UPPER_FLAG,
  NUM_FLAGS
};

extern int flags[NUM_FLAGS];

int set_flags(int argc, char* argv[]);
void handle_flags(int argc, char* argv[]);

#endif
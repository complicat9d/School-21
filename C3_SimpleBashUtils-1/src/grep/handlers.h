#ifndef HANDLERS_H
#define HANDLERS_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATTERNS_SIZE 1000

enum {
  E_FLAG,
  I_FLAG,
  V_FLAG,
  C_FLAG,
  L_FLAG,
  N_FLAG,
  H_FLAG,
  S_FLAG,
  F_FLAG,
  O_FLAG,
  NUM_FLAGS
};

extern int flags[NUM_FLAGS];

int set_flags(int argc, char* argv[]);
void handle_flags(int argc, char* argv[]);

#endif
#include "grep_options.h"
#include "handlers.h"

int main(int argc, char* argv[]) {
  set_flags(argc, argv);
  handle_flags(argc, argv);
  return 0;
}
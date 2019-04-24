#include "stdio.h"
#include "mruby_wrapper.h"

int main(int argc, char **argv) {
  surreal_mruby_t* session = surreal_mruby_open();
  surreal_exec_string(session, "puts Surreal.slurp('./Makefile')");
  surreal_mruby_close(session);

  return 0;
}
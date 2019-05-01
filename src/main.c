#include "stdio.h"
#include "mruby_wrapper.h"
#include "surreal_ui.h"

int main(int argc, char **argv) {
  // surreal_mruby_t* session = surreal_mruby_open();
  // surreal_exec_string(session, "puts Surreal.slurp('./Makefile')");
  // surreal_mruby_close(session);

  surreal_global_init_ui(&argc, &argv);
  surreal_ui_t *ui = surreal_open_window();
  surreal_create_editor(ui);
  surreal_ui_wait();

  return 0;
}
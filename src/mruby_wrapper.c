#include "stdlib.h"
#include "mruby_wrapper.h"
#include "surreal_mrb_hooks.h"
#include "mruby.h"
#include "mruby/compile.h"

surreal_mruby_t *surreal_mruby_open() {
  surreal_mruby_t *session = malloc(sizeof(surreal_mruby_t));
  session->mrb = mrb_open();
  initialize_surreal_mrb_hooks(session->mrb);
  return session;
}

void surreal_mruby_close(surreal_mruby_t *session) {
  finalize_surreal_mrb_hooks(session->mrb);
  mrb_close(session->mrb);
  free(session);
}

void surreal_exec_string(surreal_mruby_t *session, char *code) {
  mrb_load_string(session->mrb, code);
}

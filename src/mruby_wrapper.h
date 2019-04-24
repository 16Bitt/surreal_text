#ifndef MRUBY_WRAPPER_H
#define MRUBY_WRAPPER_H 1

#include "mruby.h"

typedef struct {
  mrb_state *mrb;
} surreal_mruby_t;

surreal_mruby_t *surreal_mruby_open();
void surreal_mruby_close(surreal_mruby_t *session);
void surreal_exec_string(surreal_mruby_t *session, char *code);

#endif
#ifndef SURREAL_MRB_HOOKS_H
#define SURREAL_MRB_HOOKS_H 1

#include "mruby.h"

void initialize_surreal_mrb_hooks(mrb_state *mrb);
void finalize_surreal_mrb_hooks(mrb_state *mrb);

#endif
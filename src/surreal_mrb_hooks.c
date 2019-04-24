#include "stdlib.h"
#include "stdio.h"
#include "surreal_mrb_hooks.h"
#include "mruby_wrapper.h"
#include "mruby.h"

static mrb_value surreal_method_test(mrb_state *mrb, mrb_value self)
{
  puts("Extension");
  return self;
}

static mrb_value surreal_method_exec(mrb_state *mrb, mrb_value self)
{
  char *target = NULL;
  mrb_get_args(mrb, "z", &target);
  puts(target);

  return self;
}

static mrb_value surreal_method_slurp(mrb_state *mrb, mrb_value self) {
  char *target = NULL;
  mrb_get_args(mrb, "z", &target);
  if(target == NULL) {
    return mrb_false_value();
  }

  FILE *file = fopen(target, "r");
  if(!file) {
    puts("Couldn't open file for reading...");
    return mrb_false_value();
  }

  fseek(file, 0, SEEK_END);
  size_t length = ftell(file) + 1;
  char *buffer = malloc(length);
  if(!buffer) {
    fclose(file);
    return mrb_false_value();
  }

  fseek(file, 0, SEEK_SET);
  fread(buffer, 1, length, file);
  buffer[length] = 0; // Null terminate the string
  fclose(file);

  mrb_value result = mrb_str_new_cstr(mrb, buffer);
  free(buffer);

  return result;
}

void initialize_surreal_mrb_hooks(mrb_state *mrb) {
  struct RClass *mrb_surreal_class = mrb_define_module(mrb, "Surreal");

  mrb_define_class_method(mrb, mrb_surreal_class, "test", surreal_method_test, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, mrb_surreal_class, "exec", surreal_method_exec, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, mrb_surreal_class, "slurp", surreal_method_slurp, MRB_ARGS_REQ(1));
}

void finalize_surreal_mrb_hooks(mrb_state *mrb) {
  // Cleanup?
}


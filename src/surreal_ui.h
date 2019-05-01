#ifndef SURREAL_UI_H
#define SURREAL_UI_H 1

#include "gtk/gtk.h"
#include "mruby_wrapper.h"

typedef struct {
  GObject *window;
  GtkBuilder *builder;
  surreal_mruby_t *session;
} surreal_ui_t;

void surreal_global_init_ui(int *argc, char ***argv);
void surreal_ui_wait();
surreal_ui_t *surreal_open_window();
void surreal_create_editor(surreal_ui_t *ui);
void surreal_close_window(surreal_ui_t *ui);

#endif
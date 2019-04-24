#include "stdio.h"
#include "stdlib.h"
#include "gtk/gtk.h"
#include "surreal_ui.h"

// Boot up GTK+3
void surreal_global_init_ui(int *argc, char ***argv) {
  gtk_init(argc, argv);
}

void surreal_ui_wait() {
  gtk_main();
}

surreal_ui_t *surreal_open_window() {
  surreal_ui_t *ui = malloc(sizeof(surreal_ui_t));
  ui->builder = gtk_builder_new_from_string("<interface><object id=\"window\" class=\"GtkWindow\"><property name=\"visible\">True</property></object></interface>", -1);
  ui->window = gtk_builder_get_object(ui->builder, "window");
  g_signal_connect(ui->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  return ui;
}

void surreal_close_window(surreal_ui_t *ui) {

}
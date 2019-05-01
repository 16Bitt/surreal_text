#include "stdio.h"
#include "stdlib.h"
#include "gtk/gtk.h"
#include "gtksourceview/gtksource.h"
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
  gtk_window_set_default_size(GTK_WINDOW(ui->window), 600, 400);
  g_signal_connect(ui->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  return ui;
}

void surreal_create_editor(surreal_ui_t *ui) {
  GtkWidget *scroll_win, *src_view;
  GtkSourceLanguageManager *lang_manager;
  GtkSourceBuffer *src_buffer;
  PangoFontDescription *font_desc;

  scroll_win = gtk_scrolled_window_new(NULL, NULL);
  gtk_scrolled_window_set_policy(
    GTK_SCROLLED_WINDOW (scroll_win),
    GTK_POLICY_AUTOMATIC,
    GTK_POLICY_AUTOMATIC
  );
  lang_manager = gtk_source_language_manager_new();
  src_buffer = GTK_SOURCE_BUFFER(gtk_source_buffer_new(NULL));
  g_object_ref(lang_manager);

  g_object_set_data_full(
    G_OBJECT(src_buffer),
    "languages-manager",
    lang_manager,
    (GDestroyNotify) g_object_unref
  );

  src_view = gtk_source_view_new_with_buffer(src_buffer);
  font_desc = pango_font_description_from_string("mono 8");
  gtk_widget_override_font(src_view, font_desc);
  pango_font_description_free(font_desc);

  /* Attach the GtkSourceView to the scrolled Window */
  gtk_container_add(GTK_CONTAINER(scroll_win), GTK_WIDGET(src_view));
  /* And the Scrolled Window to the main Window */
  gtk_container_add(GTK_CONTAINER(ui->window), scroll_win);
  gtk_widget_show_all(scroll_win);
}

void surreal_close_window(surreal_ui_t *ui) {

}
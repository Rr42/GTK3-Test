#include <gtk/gtk.h>
#include "gtk3.h"

static void button1 (GtkWidget *widget, gpointer data)
{

}

static void activate (GtkApplication* app, gpointer user_data)
{
  // Make window
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  // Make button box
  GtkWidget *buttonBox;
  buttonBox = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), buttonBox);

  // Make button
  GtkWidget *button;
  button = gtk_button_new_with_label ("Button 1");
  g_signal_connect (button, "clicked", G_CALLBACK (button1), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
  // Make app
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.git.GTK", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

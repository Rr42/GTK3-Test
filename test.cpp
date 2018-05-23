#include <gtk/gtk.h>
#include "gtk3.h"

static void button1 (GtkWidget *widget, gpointer data)
{
  g_print ("Button1\n");
}

static void activate (GtkApplication* app, gpointer user_data)
{
  /// Make window
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  /// grid to hold multiple witgets
  GtkWidget *windowGrid;
  windowGrid = gtk_grid_new();
  /// Attach grid to window
  gtk_container_add(GTK_CONTAINER(window), windowGrid);
  
  /// Make button
  GtkWidget *button;
  button = gtk_button_new_with_label ("Button1");
  g_signal_connect (button, "clicked", G_CALLBACK (button1), NULL);
  /** g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
   * use to kill window when button is clicked
  */
 
  /** Place the first button in the grid cell (0, 0), and make it fill
   * just 1 cell horizontally and vertically (ie no spanning)
  */
  gtk_grid_attach(GTK_GRID(windowGrid), button, 0, 0, 1, 1);

  /// Make box for 2 radio buttons
  // GtkWidget *radioBox;
  // radioBox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 2); // (orientation, number of rows)
  //gtk_box_set_homogeneous (GTK_BOX(radioBox), TRUE);

  /// Make radio buttons
  GtkWidget *radioButton1, *radioButton2;
  radioButton1 = gtk_radio_button_new_with_label(NULL, "radio1");
  radioButton2 = gtk_radio_button_new_with_label(NULL, "radio2");
  gtk_radio_button_set_group(GTK_RADIO_BUTTON(radioButton2), gtk_radio_button_get_group(GTK_RADIO_BUTTON(radioButton1)));
  gtk_grid_attach(GTK_GRID(windowGrid), radioButton1, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(windowGrid), radioButton2, 0, 2, 1, 1);

  /// Pack radio buttons in radio box
  // gtk_box_pack_start(GTK_BOX (radioBox), radioButton1, FALSE, FALSE, 0);
  // gtk_box_pack_start(GTK_BOX (radioBox), radioButton2, FALSE, FALSE, 0);
  // gtk_box_pack_start (GTK_BOX(windowGrid), radioBox, FALSE, FALSE, 0);

  gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
  /// Make app
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.git.GTK", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

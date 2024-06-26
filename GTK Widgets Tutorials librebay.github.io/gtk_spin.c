#include <gtk/gtk.h>

void closeApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}


int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *spinbutton;
    GtkAdjustment *adjustment;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GtkSpinButton");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);

    adjustment = gtk_adjustment_new(100.0, 50.0, 150.0, 0.5, 1.0, 1.0);
    spinbutton = gtk_spin_button_new(adjustment, 0.01, 2);

    gtk_container_add(GTK_CONTAINER(window), spinbutton);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}.

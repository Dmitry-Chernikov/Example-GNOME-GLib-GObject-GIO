#include <gtk/gtk.h>

int main (int argc, char *argv[]){
    GtkWidget *window;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //GTK_WINDOW_POPUP
    gtk_widget_show(window);
    gtk_main();

    return 0;
}

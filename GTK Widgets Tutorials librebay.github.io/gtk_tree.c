#include <gtk/gtk.h>

enum {
    COLUMN_TITLE,
    COLUMN_ARTIST,
    COLUMN_CATALOGUE,
    N_COLUMNS
};

void closeApp (GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkTreeStore *store; //модель
    GtkWidget *view; //представление
    GtkTreeIter parent_iter, child_iter; //итератор для доступа к колекциям и навигации по ней
    GtkCellRenderer *renderer; //отресовка ячейки типа GtkCellRendererText GtkCellRendererPixBuf GtkCellRendererToggle

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tree");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(closeApp), NULL);

    //модель дерева
    store = gtk_tree_store_new(N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    //вставка в дерево основного узла и дочерних
    gtk_tree_store_append(store, &parent_iter, NULL);
    gtk_tree_store_set(store, &parent_iter,
                        COLUMN_TITLE, "Dark Side of the Moon",
                        COLUMN_ARTIST, "Pink Floyd",
                        COLUMN_CATALOGUE, "B000024D4P",
                        -1);

    gtk_tree_store_append(store, &child_iter, &parent_iter);
    gtk_tree_store_set(store, &child_iter, COLUMN_TITLE, "Speak to Me", -1);

    //передача модели в представление
    view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));

    renderer = gtk_cell_renderer_text_new();
    //добовляем колонки с атрибутами и источником данных
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
                                                COLUMN_TITLE,
                                                "Title", renderer,
                                                "text", COLUMN_TITLE,
                                                NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
                                                COLUMN_ARTIST,
                                                "Catalogue", renderer,
                                                "text", COLUMN_ARTIST,
                                                NULL);
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
                                                COLUMN_CATALOGUE,
                                                "Catalogue", renderer,
                                                "text", COLUMN_CATALOGUE,
                                                NULL);

    gtk_container_add(GTK_CONTAINER(window), view);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

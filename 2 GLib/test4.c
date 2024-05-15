#include <glib.h>
#include <locale.h>

/*Библиотека GLib. Структуры GString и GStrvBuilder. Аргументы командной строки*/

gint main (){
	setlocale(LC_ALL, "");

	GStrvBuilder* builder_strv = g_strv_builder_new();

	g_strv_builder_add(builder_strv, "Катя");

	g_strv_builder_add_many(builder_strv, "Лена","Паша","Дима","Ольга", NULL);

	//g_strv_builder_add_many
	//g_strv_builder_addv

	gchar** strv = g_strv_builder_end(builder_strv); //Создание копии строк

	g_strv_builder_unref(builder_strv);

	for(gint i = 0; strv[i] != NULL; i++){
		g_print("%d: %s\n", i, strv[i]);
	}

	g_print("Всего строк: %d\n", g_strv_length(strv));

	g_strfreev(strv);

	return 0;
}

#include <glib.h>
#include <locale.h>

/*Библиотека GLib. Структуры GString и GStrvBuilder. Аргументы командной строки*/

gint main (){
	setlocale(LC_ALL, "");

	gchar* str = "Катя;Таня;Андрей;Миша;Паша;Ульяна";

	gchar** strv = g_strsplit(str, ";", 0);

	g_print("Всего строк: %d\n", g_strv_length(strv));

	for (gint i = 0; strv[i] != NULL; i++) {

		g_print("%d %s\n", i, strv[i]);
		//g_free(strv[i]);
	}


	//g_free(strv);

	g_strfreev(strv);

	return 0;
}

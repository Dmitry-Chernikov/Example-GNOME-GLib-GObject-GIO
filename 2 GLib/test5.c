#include <glib.h>
#include <locale.h>

/*Библиотека GLib. Структуры GString и GStrvBuilder. Аргументы командной строки*/

// argument count, argument value
gint main (gint argc, gchar** argv){ // argc количество парметров, argv масив команд
	setlocale(LC_ALL, "");

	for (gint i = 0; i < argc; i++){
		gchar* str = g_strreverse(argv[i]);
		//g_print("%d %s\n", i, argv[i]);
		g_print("%s\n", str);
		//g_free(str);
	}

	return 0;
}

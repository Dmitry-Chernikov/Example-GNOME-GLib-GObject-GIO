#include <glib.h>
#include <locale.h>

/*Библиотека GLib. Структуры GRand, GTimeZone, GDateTime*/

// argument count, argument value
gint main (gint argc, gchar** argv){ // argc количество парметров, argv масив команд
	setlocale(LC_ALL, "");

	GRand* rand = g_rand_new();
	g_print("%f\n", g_rand_double(rand));
	g_print("%f\n", g_rand_double_range(rand, 2.5, 45.897));
	g_print("%d\n", g_rand_int(rand));
	g_print("%d\n", g_rand_int_range(rand, 2, 7));
	//g_rand_set_seed();
	//g_rand_set_seed_array();
	g_rand_free(rand);

//	for (gint i = 0; i < argc; i++){
//		gchar* str = g_strreverse(argv[i]);
//		//g_print("%d %s\n", i, argv[i]);
//		g_print("%s\n", str);
//		//g_free(str);
//	}

	return 0;
}

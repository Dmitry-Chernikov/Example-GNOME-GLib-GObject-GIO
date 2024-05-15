#include <glib.h>
#include <locale.h>

/*Библиотека GLib. GQueue, GHashTable*/

//Структуры данных
//Таблица особого формата (ассоциативный массив) GHashTable

void hash_destr(gpointer ptr){
	g_print("Удаляю строку: %s\n", (gchar*) ptr);
	g_free(ptr);
}

void hash_for(gpointer key, gpointer value, gpointer u_data){
	g_print("[%s] = %s\n", (gchar*) key, (gchar*) value);
}

gint main (gint argc, gchar** argv){ // argc количество парметров, argv масив команд
	setlocale(LC_ALL, "");

	GRand* rand = g_rand_new();
	GHashTable* ht = g_hash_table_new_full(g_str_hash,
											g_str_equal,
											hash_destr,
											hash_destr);
	GHashTableIter iter;

	for (gint i = 0; i < 5; i++){
		//вставляем элементы
		g_hash_table_insert(ht,
							 g_strdup_printf("key %d", i),
							 g_strdup_printf("%f", g_rand_double(rand)));
	}

//	g_print("[%s] = %s\n", "key 3", (gchar*) g_hash_table_lookup(ht, "key 3")); // поиск

	g_hash_table_foreach(ht, hash_for, NULL);

	g_hash_table_remove(ht, "key 2");

	g_hash_table_iter_init(&iter, ht);
	gchar* key;
	gchar* value;

	while(g_hash_table_iter_next(&iter, (gpointer*) &key, (gpointer*) &value)){
		g_print("\t\t[%s] = %s\n", key, value);
	}


	g_hash_table_unref(ht);

	return 0;
}

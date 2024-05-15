#include <glib.h>
#include <locale.h>

/*Библиотека GLib. GQueue, GHashTable*/

//Структуры данных
//Очередь GQueue

void queue_destructor(gpointer ptr){//функция удаления элемента из очереди
	g_print("Удаляю строку: %s\n", (gchar*) ptr);
	g_free(ptr);
}

void queue_for(gpointer ptr, gpointer u_data){//функция вывода каждого элемента в очереди
	g_print("%s %s\n", (gchar*) u_data, (gchar*) ptr);
}

gint main (gint argc, gchar** argv){ // argc количество парметров, argv масив команд
	setlocale(LC_ALL, "");

	GRand* rand = g_rand_new();
	GQueue* queue = g_queue_new();

	//gpointer это void* (универсальный указать) к нему можно привести любой указатель
	//g_queue_push_head(queue,);//положить в начало
	//g_queue_push_tail(queue,);//положить в конец
	//g_queue_push_nth(queue,);//позиционная вставка после когото элемента
	//g_queue_pop_head //извлеч из начала
	//g_queue_pop_tail //извлеч из конца
	//g_queue_pop_nth //извлеч из определёной позиции
	//g_queue_is_empty //проверка очерди на пустату
	//g_queue_peek_head //возвращает указатель очердь не трогает

	for (gint i = 0; i < 5; i++){
		gchar* str = g_strdup_printf("%d: %f", i ,g_rand_double(rand));
		g_queue_push_tail(queue, (gpointer) str);
	}

//	while (!g_queue_is_empty(queue)){
//		//gchar* str = (gchar*) g_queue_pop_head(queue);
//		gchar* str = (gchar*) g_queue_pop_tail(queue);
//		g_print("%s\n", str);
//		g_free(str);
//	}

//	for(gint i = 0; i < queue->length; i++){
//		gchar* str = (gchar*) g_queue_peek_nth(queue, i);
//		g_print("%s\n", str);
//	}

	gchar* last_str = NULL;

	for(gint i = queue->length - 1; i >= 0; i--){
		gchar* str = (gchar*) g_queue_peek_nth(queue, i);
		g_print("%s\n", str);
		last_str = str;
	}

	//проходит по всей очереди, вызывая функцию, и подстовляя данные пользователя
	g_queue_foreach(queue, queue_for, "\t\t");

//	if (g_queue_is_empty(queue)){ //проверка очереди на пустоту
//		g_print("Очередь опустело!\n");
//	}


	//g_queue_free(queue);//используеться только тогда когда очередь пустая
	//g_print("тест: %s\n", last_str);

	//GDestroyNotify функциональный тип, предача указатель на функцию

	//проходит по всей очереди вызывая функцию удаления элементов в очереди
	g_queue_free_full(queue, queue_destructor);
	g_print("тест: %s\n", last_str);


	return 0;
}

#include "dict.h"

typedef struct _dict_item dict_item;
typedef struct _dict_info dict_info;

struct _dict_item{

	dict_t data; //пользовательский тип встроенный в инкапсулированную структуру
	//вложенную структуру можно извлеч и работать как с отдельным типом при помщи
	//простого преобразование типа, пример (dict_t*) ((dict_item*) dic)->prev

	//Скрытые поля
	dict_item* next;
	dict_item* prev;
	dict_info* info;
};

struct _dict_info{

	dict_item* head;
	dict_item* tail;
	gint count;
};

dict_t* dict_new(gchar* key, gchar* value){

	dict_item* result = g_new(dict_item, 1);
	result->next = result;
	result->prev = result;
	result->data.key = g_strdup(key);
	result->data.value = g_strdup(value);

	result->info = g_new(dict_info, 1);
	result->info->head = result;
	result->info->tail = result;
	result->info->count = 1;

	return (dict_t*) result;
}

dict_t* dict_push(dict_t* dic, gchar* key, gchar* value){

	if (dic != NULL){

		dict_info* info = ((dict_item*) dic)->info;
		dict_item* item = g_new(dict_item, 1);
		item->data.key = g_strdup(key);
		item->data.value = g_strdup(value);
		item->info = info;

		item->next = info->head;
		item->prev = info->tail;

		info->head->prev = item;
		info->tail->next = item;
		info->tail = item;
		info->count++;

		return (dict_t*)item;
	}else{
		return dict_new(key, value);
	}
}

dict_t* dict_next(dict_t* dic){

	if(dic != NULL){

		return (dict_t*) ((dict_item*) dic)->next;
	}

	return NULL;

}

dict_t* dict_prev(dict_t* dic){

	if(dic != NULL){

		return (dict_t*) ((dict_item*) dic)->prev;
	}

	return NULL;

}

gint dict_count(dict_t* dic){

	if(dic != NULL){

		return ((dict_item*) dic)->info->count;
	}

	return 0;
}

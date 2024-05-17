#include <glib.h>
#include <locale.h>

//GObject наследование механизм основан на вложенных структур

//Кольцевой замкнутый двунаправленный список, в нём сохраняется порядок добавление
//в нём реализуем пару ключ(key) и значение(value)
//используем механизм вложенных структур
//( структура(key,value)->структура(next,rev) )->структура(table_одного_кольца(head,tail,count))
//обёрнутые структуры можно преобразовывать (dict_t*).. , (dict_item*).. ,

#include "dict.h"

gint main (gint argc, gchar** argv){ // argc количество параметров, argv массив команд
	setlocale(LC_ALL, "");

	dict_t* d = NULL;

	d = dict_push(d, "Ключ1", "Значение1");
	d = dict_push(d, "Олег", "Офисный работник");
	d = dict_push(d, "Ключ2", "Значение2");

	for(gint i = 0; i < 9; i++){
		g_print("%s => %s\n", d->key, d->value);
		d = dict_next(d);
	}




	return 0;
}

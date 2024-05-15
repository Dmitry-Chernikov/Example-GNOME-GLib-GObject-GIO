#include <glib.h>
#include <locale.h>

#include "my-cat.h"

gint main (gint argc, gchar** argv){ // argc количество параметров, argv массив команд
	setlocale(LC_ALL, "");

	MyCat* cat1 = my_cat_new();

	my_cat_meow(cat1);
	my_cat_meow(cat1);

	return 0;
}

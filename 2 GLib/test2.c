#include <glib.h>
#include <locale.h>

/*Библиотека GLib. Структуры GString и GStrvBuilder. Аргументы командной строки*/

gint main (){
	setlocale(LC_ALL, "");

	GString* str1 = g_string_new("Hello world!");

	g_print("Строка [%ld]: %s\n", str1->len,str1->str);

	//g_string_free(str1, TRUE); // Если TRUE удаляет всю стркутуру GString
	//gchar* str2 = g_string_free(str1, FALSE); // Если FALSE возврат укозателя на str1->str, удаляет GString

	//g_string_append (str1, " Привет мир!"); //добовляет строку в конец возврат указатель GString
	//g_string_append_c (str1, '@');
	g_string_append_printf(str1, " Привет мир!!! %d", 1337);

	g_print("Строка [%ld]: %s\n", str1->len, str1->str);

	g_string_erase(str1, 10, 20);

	g_print("Строка [%ld]: %s\n", str1->len, str1->str);

	g_string_insert(str1, 5, " МИРРР! "); //вставляет копию строки

	g_print("Строка [%ld]: %s\n", str1->len, str1->str);

	gchar* str2 = g_string_free(str1, FALSE);

	g_print("Строка: %s\n", str2);

	g_free(str2);

	return 0;
}

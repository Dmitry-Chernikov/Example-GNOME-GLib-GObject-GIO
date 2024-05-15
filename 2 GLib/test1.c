#include <glib.h>
#include <locale.h>

/*Класические строки в Си*/

gint main (){

	setlocale(LC_ALL, "");
	//gdouble* arr = g_new(double, 10); // выделение памяти
	//gdouble* arr = g_new0(double, 10); // инициализирует нулями
	//gdouble* arr = g_try_new(double, 10); // не получилось выделить возврат NULL!!!

	//arr = g_renew(double, arr, 20); // изменение памяти
	//g_free(arr); // освобождение памяти

	//memmove(arr1, arr2, 10); // копирование в существующую память 10 в байтах

	//escape последовательность  \n \r \t \0 \b  экранирование слеша \\
	//{'H', 'e', 'l', 'l', 'o', '!', 0}
	// %<модификатор><ширина><.точность><модификатор_размера>тип
	// %d целое число
	// %o целое в 8 виде
	// %u целое без знака
	// %x %X число в 16 виде
	// %f дробное число
	// %e %E в научной нотации
	// %g  %G в научной или обычной авто
	// %s строка
	// %p адрес в 16 виде без знака
	// %l<d-p> 64 битное переменная (модификатор)
	// ширина ">%3d<", 5

	//gchar* str = "Hello!\n";
	//gchar* str2 = "\tHello, world!";
	//g_print("%s", str);
	//g_print("%s", str2);
	//g_print("\n\n\n\t\t\t\tПривет! Привет! Привет! \n");

//	g_print(">%-3d<\n", 5);
//	g_print(">%3d<\n", 5);
//	g_print(">%5d<\n", 5);
//	g_print(">%9d<\n", 5);
//	g_print(">%21d<\n", 5);
//	g_print(">%-4.2f<\n", 5.2345);
//	g_print(">%-9.3f<\n", 5.2345);
//	g_print(">%-21.4f<, %s\n", 5.2345, "test");

//	gchar* str = NULL;
//	str = g_strdup_printf("%d Привет!!! %d", 32, 23);// создаёт строку
//	gchar* str2 = g_strdup(str);// делает копию строки
//	gchar* str3 = g_strjoin(" !!! ", str, str2, NULL); // конкатенация через разделитель
//	gchar* str4 = g_strconcat(str, str2, NULL);
//	g_print ("Строка %s\t%s\n", str, str2);
//	g_print ("Строка 2: %s\n", str3);
//	g_print ("Строка 33333: %s\n", str4);
//	g_free(str);
//	g_free(str2);
//	g_free(str3);
//	g_free(str4);

//	gchar* str = "1,2,3,4,5,6;7,8,9,10";
//	gchar** strs = g_strsplit(str, ",", 0); //возвращает массив указателей на разбитые строки
//	gchar** strs = g_strsplit_set(str, ",;", 0); //несколько разделителей
//	for(gint i = 0; strs[i] != NULL; i++){
//		g_print("%d: %s\n", i, strs[i]);
//	}
//
//	g_strfreev(strs);//Удаление массива строк

//	gint* P1 = g_new(gint, 5);
//
//	for(gint i = 0; i < 5; i++){
//		P1[i] = i;
//	}
//
//	gint* P2 = P1;
//
//	g_free(P1);
//
//	for(gint i = 0; i < 5; i++){
//		g_print("%d ", P2[i]);
//	}
//
//	g_print("\n");
//
//	g_free(P2);

	gchar* str0 = "Строка с ссылкой!";

	gchar* str1 = g_ref_string_new(str0); //выделяет область памяти с копией под контроллем счёта ссылок
	gchar* str2 = g_strdup(str0); //копия строки

	gchar* str1_p = g_ref_string_acquire(str1); //добавляем ссылку и увеличиваем счётчик ссылок
	gchar* str2_p = str2;

	g_print("%s\t%s\n", str1_p, str2_p);

	g_free(str2);
	g_ref_string_release(str1);

	g_print("%s\t%s\n", str1_p, str2_p);

	g_print("%ld\n", g_ref_string_length(str1_p));
	g_ref_string_release(str1);
	g_print("%ld\n", g_ref_string_length(str1_p));

	g_print("%s\t%s\n", str1_p, str2_p);







	return 0;
}

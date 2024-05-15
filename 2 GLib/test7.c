#include <glib.h>
#include <locale.h>

/*Библиотека GLib. Структуры GRand, GTimeZone, GDateTime*/

//Работа с часовым поясом и временем
// argument count, argument value
gint main (gint argc, gchar** argv){ // argc количество парметров, argv масив команд
	setlocale(LC_ALL, "");

	GTimeZone* tz1 = g_time_zone_new_local();
	GTimeZone* tz2 = g_time_zone_new_identifier("+03");
	//GTimeZone* tz2 = g_time_zone_new_utc();

	g_print("%s\n", g_time_zone_get_identifier(tz1));

	GDateTime* dt1 = g_date_time_new_now(tz1);
	GDateTime* dt2 = g_date_time_new_now(tz2);

	g_print("%d\n", g_date_time_get_hour(dt1));

	gchar* str1 = g_date_time_format(dt1, "%d.%m.%Y %H:%M:%S");
	gchar* str2 = g_date_time_format(dt2, "%d.%m.%Y %H:%M:%S");

	g_print("Локальное дата и время: %s\n", str1);
	g_print("Дата и время в другом поясе: %s\n", str2);

	g_free(str1);
	g_free(str2);

	g_date_time_unref(dt1);
	g_date_time_unref(dt2);

	g_time_zone_unref(tz1);
	g_time_zone_unref(tz2);



	return 0;
}

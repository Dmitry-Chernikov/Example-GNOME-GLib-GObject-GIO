#include "my-cat.h"

//Описание структуры объекта
//G_DECLARE_FINAL_TYPE автоматом создаёт тип MyCat (typedef)
//Первым членом в структуре объекта должен быть объект от которого наследуются
// в G_DECLARE_FINAL_TYPE
//структура описанная в "С" файле доступна только в "С" файле
struct _MyCat {
	GObject parent; //Родитель встраивается в структуру создаваемого объекта

	gint mew_counter;
};

//Макрос объявление 1 Название объекта, 2 название змейкой, 3 макрос G_TYPE_OBJECT
//объекта от которого наследуемся GObject, как #define MY_TYPE_CAT my_cat_get_type()
G_DEFINE_TYPE (MyCat, my_cat, G_TYPE_OBJECT)

//Вызывается один раз (создаёт структуру класса),
//нужен чтобы произвести действия над классом. Например перегружать функции родительские.
static void
my_cat_class_init(MyCatClass* self){//Принимает указатель на экземпляр класса
	g_print("Создан класс котиков\n");
}

//Два инициализатора
//Вызывается каждый раз когда создаётся объекта, задача про инициализировать переменные,
//это неполно контекстный конструктор.
static void
my_cat_init(MyCat* self){//Принимает указатель на экземпляр объекта
	self->mew_counter = 0;
	g_print("Котик создан!\n");
}

//Метод заставляет кота мяукать
void
my_cat_meow(MyCat* self){

	g_print("Мяу x%d!\n", ++self->mew_counter);
}

//Обёртка над конструктором, возвращает экземпляр кота
MyCat* my_cat_new(){
	//Объект создаётся методом g_object_new()
	//g_object_new() всегда должна быть обвёрнута как my_cat_new()
	return g_object_new(MY_TYPE_CAT, NULL); //Имеет переменное число аргументов, NULL конец списка аргументов
}

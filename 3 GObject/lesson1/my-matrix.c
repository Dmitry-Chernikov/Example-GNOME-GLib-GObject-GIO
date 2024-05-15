#include <stdarg.h> // имеет четыре функции и один тип для работы с аргументами ...
#include "my-matrix.h"

//Абстракция матрицы, структура описывающая матрицу
struct _mmatrix_t{

	gdouble* data;

	gint rowc;
	gint colc;

};

// Инкапсуляция с помощью static, функция будет видна только внутри этого файла С (сокрытие), сложение матрицы
static void my_matrix_sum_real(gdouble* C, gdouble* A, gdouble* B, gint rowc, gint colc){
	for (gint i = 0; i < rowc; i++) {
		for (gint j = 0; j < colc; j++){
			C[i*colc+j] = A[i*colc+j] + B[i*colc+j];
		}
	}
}
// Инкапсуляция с помощью static, функция будет видна только внутри этого файла С (сокрытие), умножение матрицы
static void my_matrix_dot_real(gdouble* C, gdouble* A, gdouble* B, gint rowc, gint colc, gint rc){
	for(gint i = 0; i < rowc; i++){
		for(gint j = 0; j < colc; j++){

			C[i*colc+j] = 0.0;

			for (gint r = 0; r < rc; r++){
				C[i*colc+j] = C[i*colc+j] + A[i*rc+r] * B[r*colc+j];
			}
		}
	}
}
// Инструмент абстракции матрицы, создание матрицы
mmatrix_t* my_matrix_new(gint rowc, gint colc){
	mmatrix_t* result = g_new(mmatrix_t, 1);
	result->rowc = rowc;
	result->colc = colc;

	result->data = g_new0(gdouble, rowc*colc); // инициализация матрицы нулями

	return result;
}

// Инструмент абстракции матрицы, удаление матрицы
void my_matrix_free(mmatrix_t* matrix){

	if(matrix != NULL){
		g_free(matrix->data);
		g_free(matrix);
	}
}

// Инструмент абстракции матрицы, присваивает значение элементу матрицы
void mm_set(mmatrix_t* matrix, gint i, gint j, gdouble value){
	if (matrix != NULL){
		if ( ((i >= 0) && (i < matrix->rowc)) &&
			 ((j >= 0) && (j < matrix->colc)) ){

			matrix->data[i*matrix->colc + j] = value;
		}
	}
}

// Инструмент абстракции матрицы, возвращает значение элемента матрицы
gdouble mm_get(mmatrix_t* matrix, gint i, gint j){
	if (matrix != NULL){
		if ( ((i >= 0) && (i < matrix->rowc)) &&
			((j >= 0) && (j < matrix->colc)) ){

			return matrix->data[i*matrix->colc + j];
		}
	}
	return 0.0;
}

// Инструмент абстракции матрицы, множественное изменение элементов матрицы
void mm_sets(mmatrix_t* mat, ...){ // ... неизвестное количество аргументов (для работы нужна #include <stdarg.h> )
	if (mat != NULL){
		va_list values; // объявляем лист аргументов функции ...
		va_start(values, mat); // инициализируем, указываем лист и последний аргумент mat из сигнатуры функции

		for (gint i = 0; i < mat->rowc*mat->colc; i++){
			mat->data[i] = va_arg(values, gdouble); // va_arg возвращает последовательно аргумент с заданным типом gdouble
		}
		va_end(values); // освобождение value типа va_list
	}
}

// Инструмент абстракции матрицы, возвращает количество колонок матрицы
gint mm_colc(mmatrix_t* mat){
	if (mat != NULL){
		return mat->colc;
	}

	return -1;
}

// Инструмент абстракции матрицы, возвращает количество строк матрицы
gint mm_rowc(mmatrix_t* mat){
	if (mat != NULL){
		return mat->rowc;
	}

	return -1;
}

// Инструмент абстракции матрицы, сложение матрицы вызвав скрытый метод my_matrix_sum_real
mmatrix_t* mm_sum(mmatrix_t* a, mmatrix_t* b){
	if ((a != NULL) && (b != NULL)){
		if ((a->colc == b->colc) && (b->rowc == b->rowc)){
			mmatrix_t* result = my_matrix_new(a->rowc, a->colc);

			my_matrix_sum_real(result->data, a->data, b->data, a->rowc, a->colc);

			return result;
		}
	}
	return NULL;
}

// Инструмент абстракции матрицы, умножение матрицы вызвав скрытый метод my_matrix_dot_real
mmatrix_t* mm_dot(mmatrix_t* a, mmatrix_t* b){
	if ((a != NULL) && (b != NULL)){
		if ((a->colc == b->rowc)){
			mmatrix_t* result = my_matrix_new(a->rowc, b->colc);

			my_matrix_dot_real(result->data, a->data, b->data, a->rowc, b->colc, a->colc);

			return result;
		}
	}
	return NULL;
}

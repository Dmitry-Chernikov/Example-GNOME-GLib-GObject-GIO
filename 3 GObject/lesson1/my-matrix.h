#ifndef __MY_MATRIX_H__
#define __MY_MATRIX_H__

#include <glib.h>

// Чтобы инкапсулировать (скрыть) поля структуры (абстракции)
// необходимо описание полей структуры вынести из заголовочного файла в С файл

//typedef struct {
//
//	gdouble* data;
//
//	gint rowc;
//	gint colc;
//
//} matrix_t;

// метка (упоминание но не описание) о том что будут типы mmatrix_t
typedef struct _mmatrix_t mmatrix_t;

mmatrix_t* my_matrix_new(gint rowc, gint colc);
void my_matrix_free(mmatrix_t* matrix);

void mm_set(mmatrix_t* matrix, gint i, gint j, gdouble value);
gdouble mm_get(mmatrix_t* matrix, gint i, gint j);
void mm_sets(mmatrix_t* mat, ...);

gint mm_colc(mmatrix_t* mat);
gint mm_rowc(mmatrix_t* mat);

mmatrix_t* mm_sum(mmatrix_t* a, mmatrix_t* b);
mmatrix_t* mm_dot(mmatrix_t* a, mmatrix_t* b);

#endif

#include <glib.h>
#include <locale.h>
#include "my-matrix.h"

// процедура выводит матрицу на экран
void print_matrix(mmatrix_t* mat){
	for (gint i = 0; i < mm_rowc(mat); i++){
		for (gint j = 0; j < mm_colc(mat); j++){
			g_print("%.3f ", mm_get(mat, i , j));
		}
		g_print("\n");
	}
}

gint main (gint argc, gchar** argv){ // argc количество параметров, argv массив команд
	setlocale(LC_ALL, "");
	// создание указателя на тип mmatrix_t
	mmatrix_t* mat1 = my_matrix_new(3, 3);
	mmatrix_t* mat2 = my_matrix_new(3, 3);

//	mat1->data[4] = 7.9;
//	g_print("%f \n", mat1->data[4]);
//	g_print("%d \n", sizeof(mmatrix_t));

//	mm_set(mat1, 1, 1, 14.56);
//	mm_set(mat1, 2, 1, 36.46);

	mm_sets(mat1, 1.44, 1.45, 0.25,
				  5.44, 3.76, 4.83,
				  3.67, 5.78, 4.94);

	mm_sets(mat2, 1.0, 0.0, 0.0,
				  0.0, 1.0, 0.0,
				  0.0, 0.0, 1.0);

	mmatrix_t* matsum = mm_sum(mat1, mat2);
	mmatrix_t* matdot = mm_dot(mat1, mat2);

	print_matrix(matsum);
	g_print("\n");
	print_matrix(matdot);

	my_matrix_free(mat1);
	my_matrix_free(mat2);
	my_matrix_free(matsum);
	my_matrix_free(matdot);

	return 0;
}

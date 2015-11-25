#ifndef MATRIX_H
#define MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

int level_of_null(int **P, int n, int number_of_column);
void swap(int *a, int *b);
void sort_nulls_to_the_main_diagonal(int **P, int n);

#ifdef __cplusplus
}
#endif

#endif // MATRIX_H

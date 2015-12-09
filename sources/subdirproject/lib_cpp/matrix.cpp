#include "matrix.h"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}
int Matrix::level_of_null(int**& P, const int size, const int number_of_column) const
{
    int result = 0;
    for (int i = 0; i < size; ++i)
        if (P[number_of_column][i] == 0)
        {
            result = i;
            break;
        }
    return result;
}


void Matrix::sort_nulls_to_the_main_diagonal(int**& P, const int size) const
{
    int* t;
    int i, j;
    for (i = size - 1; i >= 0; --i)
        for (j = 0; j < i; ++j)
            if (level_of_null(P, size, j) > level_of_null(P, size, j+1)){
                    t = P[j];
                    P[j] = P[j+1];
                    P[j+1] = t;
            }
}

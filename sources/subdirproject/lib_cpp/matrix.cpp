#include "matrix.h"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}
int Matrix::levelOfNull(int**& P, const int size, const int numberOfColumn) const
{
    int result = 0;
    for (int i = 0; i < size; ++i)
        if (P[numberOfColumn][i] == 0)
        {
            result = i;
            break;
        }
    return result;
}


void Matrix::sortNullsToTheMainDiagonal(int**& P, const int size) const
{
    int* t;
    int i, j;
    for (i = size - 1; i >= 0; --i)
        for (j = 0; j < i; ++j)
            if (levelOfNull(P, size, j) > levelOfNull(P, size, j+1)){
                    t = P[j];
                    P[j] = P[j+1];
                    P[j+1] = t;
            }
}

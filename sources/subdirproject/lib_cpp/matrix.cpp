#include "matrix.h"

Matrix::Matrix(int dimension) : dimension(dimension)
{
    if (dimension < 0)
    {
        throw BadDimensionException();
    }
    matrix.resize(dimension);
    for (auto& row : matrix)
    {
        row.resize(dimension);
    }
}

int Matrix::levelOfNull(const int numberOfLine) const
{
    int result = 0;
    for (int i = 0; i < dimension; ++i)
        if (matrix[numberOfLine][i] == 0)
        {
            result = i;
            break;
        }
    return result;
}

void Matrix::sortNullsToTheMainDiagonal()
{
//    for (int i = dimension - 1; i >= 0; --i)
//        for (int j = 0; j < i; ++j)
//            if (levelOfNull(j) > levelOfNull(j + 1))
//            {
//                    vector<int> t = matrix[j];
//                    matrix[j] = matrix[j + 1];
//                    matrix[j + 1] = t;
//            }
        for (int i = 0; i < dimension / 2; ++i)
        {
            vector<int> t = matrix[i];
            matrix[i] = matrix[levelOfNull(i)];
            matrix[levelOfNull(i)] = t;
        }
}

void Matrix::put(int value, int i, int j)
{
    if (i < 0 || i >= dimension || j < 0 || j >= dimension)
    {
        throw WrongAdressException(i, j);
    }
    matrix[i][j] = value;
}

int Matrix::get(int i, int j) const
{
    if (i < 0 || i >= dimension || j < 0 || j >= dimension)
    {
        throw WrongAdressException(i, j);
    }
    return matrix[i][j];
}

int Matrix::getDimension() const
{
    return dimension;
}

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

bool Matrix::isMatrixIncorrect() const
{
    bool result = false;
    for (int i = 0; i < dimension; ++i)
    {
        int counterOnLines = 0;
        int counterOnColumns = 0;
        for (int j = 0; j < dimension; ++j)
        {
            if (matrix[i][j] == 0)
            {
                ++counterOnLines;
            }
            if (matrix[j][i] == 0)
            {
                ++counterOnColumns;
            }
        }
        if (counterOnLines > 1 || counterOnColumns > 1)
        {
            result = true;
            break;
        }
    }
    return result;
}

void Matrix::sortNullsToTheMainDiagonal()
{
    if (isMatrixIncorrect())
    {
        throw BadMatrixException();
    }
    for (int i = 0; i < dimension; ++i)
    {
        int j = levelOfNull(i);
        if (i != j)
        {
            vector<int> t = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = t;
        }
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

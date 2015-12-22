#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class BadDimensionException : public exception
{
    string error;

public:
    BadDimensionException(const char* error) : error(error){}

    string getError() const
    {
        return error;
    }
};

class WrongAdressException : public exception
{
    int i;
    int j;

public:
    WrongAdressException(int i, int j) : i(i), j(j){}

    int getI() const
    {
        return i;
    }

    int getJ() const
    {
        return j;
    }
};

class Matrix
{
    int dimension;
    vector<vector<int>> matrix;
    int levelOfNull(const int numberOfColumn) const;
    const char* ERROR_BAD_DIMENSION = "ERROR: the value of matrix dimension can't be negative";

public:
    Matrix(int dimension);
    ~Matrix();
    void sortNullsToTheMainDiagonal();
    void put(int value, int i, int j);
    int get(int i, int j) const;
    int getDimension() const;
};

#endif // MATRIX_H

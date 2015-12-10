#include <fstream>
#include <iostream>

#include "matrix.h"

using namespace std;

void matrixApp()
{
    ifstream fileInput;
    fileInput.open("matrix.in");

    int matrixSize;
    fileInput >> matrixSize;

    int** matrix;
    matrix = new int* [matrixSize];
    for (int i = 0; i < matrixSize; ++i)
    {
        matrix[i] = new int[matrixSize];
    }
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < matrixSize; ++j)
        {
            fileInput >> matrix[i][j];
        }
    }

    fileInput.close();

    Matrix app;
    app.sortNullsToTheMainDiagonal(matrix, matrixSize);

    ofstream fileOutput;
    fileOutput.open("matrix.out");
    for (int i = 0; i < matrixSize; ++i)
    {
        for (int j = 0; j < matrixSize; ++j)
        {
            fileOutput << matrix[i][j] << " ";
        }
        fileOutput << endl;
    }

    fileOutput.close();

    for (int i = 0; i < matrixSize; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

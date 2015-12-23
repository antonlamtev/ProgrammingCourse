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

    try
    {
        Matrix matrix(matrixSize);

        for (int i = 0; i < matrixSize; ++i)
        {
            for (int j = 0; j < matrixSize; ++j)
            {
                int value;
                fileInput >> value;
                matrix.put(value, i, j);
            }
        }

        fileInput.close();

        matrix.sortNullsToTheMainDiagonal();

        ofstream fileOutput;
        fileOutput.open("matrix.out");
        for (int i = 0; i < matrixSize; ++i)
        {
            for (int j = 0; j < matrixSize; ++j)
            {
                fileOutput << matrix.get(i, j) << " ";
            }
            fileOutput << endl;
        }

        fileOutput.close();
    }
    catch (BadDimensionException& e)
    {
        cout << e.getError() << endl;
    }
    catch (WrongAdressException& e)
    {
        cout << "ERROR: incorrect pair of coordinates (" << e.getI() << ", " << e.getJ() << ")" << endl;
    }
    catch (BadMatrixException& e)
    {
        cout << e.getError() << endl;
    }
}

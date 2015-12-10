#include <iostream>
#include <cstdlib>

#include "tableApp.h"
#include "matrixapp.h"

using namespace std;

int main()
{
    char key;
    do
    {
        system("clear");
        cout << "1)Таблица-ключ-значение\n"
                "2)Сортировка нулей матрицы на главную диагональ\n"
                "3)Выход\n";
        cin >> key;
    }
    while (key < '1' || key > '3');

    switch (key)
    {
        case '1':
        {
            TableApp app;
            app.menu();
            break;
        }
        case '2':
            matrixApp();
            break;
        case '3':
            exit(0);
            break;
    }
    return 0;
}


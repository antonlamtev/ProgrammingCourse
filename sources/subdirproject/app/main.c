#include <stdio.h>
#include <stdlib.h>
#include "exchange.h"
#include "queens.h"
//#include "tests.h"
//#include "equation.h"
#include "matrix.h"


int main(void)
{
    char key;
    do
    {
        system("clear");
        printf("Выберите программу!\n1)Размен\n2)Ферзи\n3)Деление уголком\n4)Матрица\n"
               "5)Тесты\n6)Завершить работу\n");
        scanf("%c", &key);
    }
    while(key < '1' || key > '6' );

    switch(key)
    {
        case '1':
            exchange();
            break;
        case '2':
            queens();
            break;
        case '3':
            equation();
            break;
        case '4':
            matrix();
            break;
        case '5':
            //tests();
            break;
        case '6':
            exit(0);
            break;
    }

    return 0;
}

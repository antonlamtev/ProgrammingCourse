#include <stdio.h>
#include <stdlib.h>
#include "exchange.h"
#include "queens.h"
#include "quotient.h"
#include "matrix.h"

void main_menu(void)
{
    char key;
    do
    {
        system("clear");
        printf("Выберите программу!\n1)Размен\n2)Ферзи\n3)Деление уголком\n4)Матрица\n"
               "5)Симметрирование строк\n6)Тесты\n7)Завершить работу\n");
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
            quotient();
            break;
        case '4':
            matrix();
            break;
        case '5':
            puts("Не готово!");
            break;
        case '6':
            puts("Не готово!");
            break;
        case '7':
            exit(0);
            break;
    }
}

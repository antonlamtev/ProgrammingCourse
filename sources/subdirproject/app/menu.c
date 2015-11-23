#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void main_menu(void)
{
    char key;
    do
    {
        system("clear");
        printf("Выберите программу!\n1)Размен\n2)Ферзи\n3)Деление уголком\n4)Матрица\n"
               "5)Симметрирование строк\n6)Завершить работу\n");
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
            matrix("matrix.in", "matrix.out");
            break;
        case '5':
            lines_symmetrization("lines.in", "lines.out");
            break;
        case '6':
            exit(0);
            break;
    }
}

void further_menu(void)
{
    char key;
    do
    {
        system("clear");
        puts("Вы запустили прогамму без параметров!!!");
        puts("Выберите вариант продолжения");
        puts("1)Получить информацию о пользовании\n2)Завершить программу");
        scanf("%c", &key);
    }
    while (key < '1' || key > '2');
    switch (key)
    {
        case '1':
            help();
            break;
        case '2':
            exit(0);
            break;
    }
}

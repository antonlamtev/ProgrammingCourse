#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "queens.h"

void queens(void)
{
    struct coordinate x, y;
    // Считать координаты шахматной доски координатами матрицы 8х8 от 1 до 8 !!!

    input_with_check(&x.first, &y.first, 1);
    input_with_check(&x.second, &y.second, 2);
    input_with_check(&x.third, &y.third, 3);

    display_result(queens_result(x, y));
}

void queens_parameters(int argc, char** argv)
{
    switch (argc)
    {
        case 2:
            queens();
            break;
        case 8:
        {
            struct coordinate x;
            struct coordinate y;
            x.first = atoi(argv[2]);
            y.first = atoi(argv[3]);
            x.second = atoi(argv[4]);
            y.second = atoi(argv[5]);
            x.third = atoi(argv[6]);
            y.third = atoi(argv[7]);

            display_result(queens_result(x, y));
            break;
        }
        default:
            put_error;
            help_queens();
            break;
    }
}

void input_with_check(int* x, int* y, int number)
{
    do
    {
        printf("Введите координаты %i-го ферзя\n", number);
        scanf("%i%i", x, y);
    }
    while (*x < 1 || *x > 8 || *y < 1 || *y > 8);
}

void display_result(int result)
{
    switch (result)
    {
        case no_one:
            puts("Никто никого не бьет");
            break;
        case everyone:
            puts("Все ферзи бьют друг друга");
            break;
        case OneTwo_OneThree:
            printf("1 и 2 ферзи бьют друг друга\n1 и 3 ферзи бьют друг друга\n");
            break;
        case OneTwo_TwoThree:
            printf("1 и 2 ферзи бьют друг друга\n2 и 3 ферзи бьют друг друга\n");
            break;
        case OneTwo:
            puts("1 и 2 ферзи бьют друг друга");
            break;
        case OneThree_TwoThree:
            printf("1 и 3 ферзи бьют друг друга\n2 и 3 ферзи бьют друг друга\n");
            break;
        case OneThree:
            puts("1 и 3 ферзи бьют друг друга");
            break;
        case TwoThree:
            puts("2 и 3 ферзи бьют друг друга");
            break;
    }
}

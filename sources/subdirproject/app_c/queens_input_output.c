#include <stdio.h>
#include "queens.h"

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

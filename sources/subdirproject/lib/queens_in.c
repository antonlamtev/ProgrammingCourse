#include <stdio.h>

void input_with_check(int *x, int *y, int number)
{
    do
    {
        printf("Введите координаты %i-го ферзя\n", number);
        scanf("%i%i", x, y);
    }
    while (*x < 1 || *x > 8 || *y < 1 || *y > 8);
}

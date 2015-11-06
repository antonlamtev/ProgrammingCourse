#include <stdio.h>

void input_with_check(int *a, int *b, int n)
{
    do
    {
        printf("Введите координаты %i-го ферзя\n", n);
        scanf("%i%i", a, b);
    }
    while (*a < 1 || *a > 8 || *b < 1 || *b > 8);
}

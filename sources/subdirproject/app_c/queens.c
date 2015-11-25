#include <stdio.h>
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

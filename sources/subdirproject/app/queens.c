#include <stdio.h>
#include "queens_out.h"
#include "queens_result.h"
#include "queens_check_for_beating.h"
#include "queens_in.h"

void queens(void)
{
    int x1, x2, x3, y1,y2, y3;

    // Считать координаты шахматной доски координатами матрицы 8х8 от 1 до 8 !!!

    input_with_check(&x1, &y1, 1);
    input_with_check(&x2, &y2, 2);
    input_with_check(&x3, &y3, 3);

    queens_out(queens_result(x1, y1, x2, y2, x3, y3));
}

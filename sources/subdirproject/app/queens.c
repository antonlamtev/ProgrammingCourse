#include <stdio.h>
#include "queens_out.h"
#include "queens_result.h"
#include "queens_check_for_beating.h"
#include "queens_in.h"
#include "queens_operands_declaration.h"

void queens(void)
{
    struct coordinate x, y;
    // Считать координаты шахматной доски координатами матрицы 8х8 от 1 до 8 !!!

    input_with_check(&x.first, &y.first, 1);
    input_with_check(&x.second, &y.second, 2);
    input_with_check(&x.third, &y.third, 3);

    queens_out(queens_result(x, y));
}

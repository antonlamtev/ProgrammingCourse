#include <stdio.h>
#include "quotient_process.h"

void quotient(void)
{
    /// вроде бы у вас везде переменые строчными буквами
    int M, N;
    puts("Введите 2 числа");
    scanf("%i%i", &M, &N);
    puts("");
    quotient_out(M, N);
}

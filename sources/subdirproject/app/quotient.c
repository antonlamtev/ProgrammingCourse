#include <stdio.h>
#include "quotient_process.h"

void quotient(void)
{
    int M, N;
    puts("Введите 2 числа");
    scanf("%i%i", &M, &N);
    quotient_out(M, N);
}

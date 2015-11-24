#include <stdio.h>
#include "quotient.h"

void quotient(void)
{
    int m, n;
    puts("Введите 2 числа");
    scanf("%i%i", &m, &n);
    puts("");
    quotient_out(stdout, m, n);
}

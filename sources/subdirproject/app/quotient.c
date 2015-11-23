#include <stdio.h>
#include "quotient_process.h"

void quotient(void)
{
    //В задании переменные называются именно так заглавными буквами
    /// вроде бы у вас везде переменые строчными буквами
    //int M, N;
    int m, n;
    puts("Введите 2 числа");
    scanf("%i%i", &m, &n);
    puts("");
    quotient_out(stdout, m, n);
}

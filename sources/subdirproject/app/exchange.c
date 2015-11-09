#include <stdio.h>
#include "exchange_out.h"

void exchange(void)
{
    int number;

    do
    {
        puts("Сколько рублей нужно разменять?");
        scanf("%i", &number);
    }
    while (number >= 100);

    exchange_out(number);
}

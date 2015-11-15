#include <stdio.h>
#include "exchange_change.h"

void exchange(void)
{
    int number, fives, twos, ones;

    do
    {
        puts("Сколько рублей нужно разменять?");
        scanf("%i", &number);
    }
    while (number >= 100);

    change_by_coins(number, &fives, &twos, &ones);

    printf("Пятирублёвых монет: %i\nДвухрублёвых монет: %i\nРублёвых монет: %i\n", fives, twos, ones);
}

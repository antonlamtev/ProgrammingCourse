#include <stdio.h>
#include "exchange_change.h"
#include "exchange_structures_declaration.h"

void exchange(void)
{
    int number;
    struct purse coins;

    do
    {
        puts("Сколько рублей нужно разменять?");
        scanf("%i", &number);
    }
    while (number >= 100);

    coins = change_by_coins(number);
    printf("Пятирублёвых монет: %i\nДвухрублёвых монет: %i\nРублёвых монет: %i\n", coins.fives, coins.twos, coins.ones);
}

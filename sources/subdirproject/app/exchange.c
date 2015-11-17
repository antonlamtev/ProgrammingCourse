#include <stdio.h>
#include "exchange_change.h"

void exchange(void)
{
    /// Не думали сделать структуру для монеток?
    // Добавил структуру. По идее структура должна облегчать читаемость программы. Мне как-то не стало легче читать.
    int number;
    struct purse
    {
         int ones;
         int twos;
         int fives;
    };
    struct purse coins;

    do
    {
        puts("Сколько рублей нужно разменять?");
        scanf("%i", &number);
    }
    while (number >= 100);

    change_by_coins(number, &coins.fives, &coins.twos, &coins.ones);

    printf("Пятирублёвых монет: %i\nДвухрублёвых монет: %i\nРублёвых монет: %i\n", coins.fives, coins.twos, coins.ones);
}

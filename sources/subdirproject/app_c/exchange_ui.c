#include <stdio.h>
#include <stdlib.h>

#include "exchange.h"
#include "main.h"

void exchange_output(struct purse coins)
{
    printf("Пятирублёвых монет: %i\n"
           "Двухрублёвых монет: %i\n"
           "Рублёвых монет: %i\n",
           coins.fives, coins.twos, coins.ones);
}

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
    exchange_output(coins);
}

void exchange_parameters(int argc, char** argv)
{
    switch (argc)
    {
        case 2:
            exchange();
            break;
        case 3:
        {
            int num = atoi(argv[2]);
            struct purse coins = change_by_coins(num);
            exchange_output(coins);
            break;
        }
        default:
            put_error;
            help_exchange();
            break;
    }
}

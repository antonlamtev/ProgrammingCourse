#include <stdio.h>
#include <stdlib.h>
#include "exchange.h"
#include "main.h"

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

void exchange_parameters(int argc, char** argv)
{
    int num;
    struct purse coins;
    switch (argc)
    {
        case 2:
            exchange();
            break;
        case 3:
            num = atoi(argv[2]);
            coins = change_by_coins(num);
            printf("Пятирублёвых монет: %i\nДвухрублёвых монет: %i\nРублёвых монет: %i\n", coins.fives, coins.twos, coins.ones);
            break;
        default:
            put_error;
            help_exchange();
            break;
    }
}

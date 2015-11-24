#include "exchange.h"

struct purse change_by_coins(int amount)
{
    struct purse coins;
    coins.fives = amount / 5;
    coins.twos = (amount - (coins.fives * 5)) / 2;
    if (amount % 5 == 3)
        coins.ones = 1;
    else
        coins.ones = 0;
    return coins;
}

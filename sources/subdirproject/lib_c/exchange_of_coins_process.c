#include "exchange.h"

struct purse change_by_coins(int amount)
{
    struct purse coins;
    coins.fives = amount / 5;
    coins.twos = (amount - coins.fives * 5) / 2;
    coins.ones = amount - coins.fives * 5 - coins.twos * 2;
    return coins;
}

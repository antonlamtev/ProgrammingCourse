#include "exchange.h"

struct purse change_by_coins(int amount)
{
    struct purse coins;
    coins.fives = amount / 5;
    coins.twos = (amount % 5) / 2;
    coins.ones = (amount % 5) % 2;
    return coins;
}

#include "exchange.h"

Exchange::Exchange()
{
}

Exchange::~Exchange()
{
}

Coins Exchange::exchangeMoney(const int moneyAmount) const
{
    Coins coins;
    coins.fives = moneyAmount / 5;
    coins.twos = (moneyAmount - coins.fives * 5) / 2;
    coins.ones = moneyAmount - coins.fives * 5 - coins.twos * 2;
    return coins;
}

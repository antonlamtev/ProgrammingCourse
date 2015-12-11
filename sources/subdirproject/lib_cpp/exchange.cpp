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
    coins.twos = (moneyAmount % 5) / 2;
    coins.ones = (moneyAmount % 5) % 2;
    return coins;
}

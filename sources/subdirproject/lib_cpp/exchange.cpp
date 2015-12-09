#include "exchange.h"

Exchange::Exchange()
{
}

Exchange::~Exchange()
{
}

Coins Exchange::exchange_money(const int money_amount) const
{
    Coins coins;
    coins.fives = money_amount / 5;
    coins.twos = (money_amount - coins.fives * 5) / 2;
    coins.ones = money_amount - coins.fives * 5 - coins.twos * 2;
    return coins;
}

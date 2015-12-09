#ifndef EXCHANGE_H
#define EXCHANGE_H

struct Coins
{
    int ones;
    int twos;
    int fives;
};

class Exchange
{
public:
    Exchange();
    ~Exchange();
    Coins exchange_money(const int money_amount) const;
};

#endif // EXCHANGE_H

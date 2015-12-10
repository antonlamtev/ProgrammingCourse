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
    Coins exchangeMoney(const int moneyAmount) const;
};

#endif // EXCHANGE_H

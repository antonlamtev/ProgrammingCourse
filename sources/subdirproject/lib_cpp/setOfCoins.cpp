#include "setOfCoins.h"

SetOfCoins::SetOfCoins(int ones, int twos, int fives, int moneyAmount) : ones(ones), twos(twos), fives(fives), moneyAmount(moneyAmount)
{
    if (moneyAmount > 99 || moneyAmount < 0)
    {
        throw AmountException(ERROR_BAD_AMOUNT);
    }
    if (ones < 0 || twos < 0 || fives < 0)
    {
        throw CoinException(ERROR_BAD_COIN);
    }
}

SetOfCoins::SetOfCoins()
{
}

SetOfCoins::~SetOfCoins()
{
}

void SetOfCoins::putAmount(int moneyAmount)
{
    if (moneyAmount > 99 || moneyAmount < 0)
    {
        throw AmountException(ERROR_BAD_AMOUNT);
    }

    this->moneyAmount = moneyAmount;
}

SetOfCoins& SetOfCoins::exchange()
{
    fives = moneyAmount / 5;
    twos = moneyAmount % 5 / 2;
    ones = moneyAmount % 5 % 2;

    return *this;
}

bool SetOfCoins::operator==(SetOfCoins set)
{
    return ones ==  set.ones && twos ==  set.twos && fives == set.fives;
}

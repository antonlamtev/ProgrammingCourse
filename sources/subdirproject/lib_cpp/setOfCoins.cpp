#include "setOfCoins.h"

void SetOfCoins::throwAmountException(int& moneyAmount) const
{
    if (moneyAmount > 99 || moneyAmount < 0)
    {
        throw AmountException();
    }
}

void SetOfCoins::exchange()
{
    fives = moneyAmount / 5;
    twos = moneyAmount % 5 / 2;
    ones = moneyAmount % 5 % 2;
}

SetOfCoins::SetOfCoins(int moneyAmount) : moneyAmount(moneyAmount)
{
    throwAmountException(moneyAmount);

    exchange();
}


void SetOfCoins::putAmount(int moneyAmount)
{
    throwAmountException(moneyAmount);

    this->moneyAmount = moneyAmount;

    exchange();
}

int SetOfCoins::getOnes() const
{
    return ones;
}

int SetOfCoins::getTwos() const
{
    return twos;
}

int SetOfCoins::getFives() const
{
    return fives;
}

bool SetOfCoins::operator==(SetOfCoins set)
{
    return ones ==  set.ones && twos ==  set.twos && fives == set.fives;
}

#ifndef SETOFCOINS_H
#define SETOFCOINS_H

#include <iostream>
#include <exception>

using namespace std;

class CoinException : public exception
{
    string error;

public:
    CoinException(const char* error) : error(error){}

    string getError() const
    {
        return error;
    }
};

class AmountException : public exception
{
    string error;
public:
    AmountException(const char* error) : error(error){}

    string getError() const
    {
        return error;
    }
};

class SetOfCoins
{
    int ones;
    int twos;
    int fives;
    int moneyAmount;
    const char* ERROR_BAD_AMOUNT = "ERROR: value of moneyAmount you put contradicts the condition";
    const char* ERROR_BAD_COIN = "ERROR: value of coin can not be negative";

public:
    SetOfCoins(int ones, int twos, int fives, int moneyAmount) : ones(ones), twos(twos), fives(fives), moneyAmount(moneyAmount)
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
    SetOfCoins();
    ~SetOfCoins();
    void putAmount(int moneyAmount);
    SetOfCoins& exchange();
    bool operator==(SetOfCoins set);
};

#endif // SETOFCOINS_H

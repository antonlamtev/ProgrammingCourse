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
    const char* ERROR_BAD_AMOUNT = "ERROR: the value of moneyAmount you put contradicts the condition";
    const char* ERROR_BAD_COIN = "ERROR: the value of coin can not be negative";

public:
    SetOfCoins(int ones, int twos, int fives, int moneyAmount);
    SetOfCoins();
    ~SetOfCoins();
    void putAmount(int moneyAmount);
    SetOfCoins& exchange();
    bool operator==(SetOfCoins set);
};

#endif // SETOFCOINS_H

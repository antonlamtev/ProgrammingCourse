#ifndef SETOFCOINS_H
#define SETOFCOINS_H

#include <iostream>
#include <exception>

using namespace std;

class AmountException : public exception
{
public:
    string getError() const
    {
        return "ERROR: the value of moneyAmount you put contradicts the condition";
    }
};

class SetOfCoins
{
    int ones;
    int twos;
    int fives;
    int moneyAmount;

public:
    SetOfCoins(int moneyAmount = 0);
    void throwAmountException(int& moneyAmount) const;
    void putAmount(int moneyAmount);    
    void exchange();
    int getOnes() const;
    int getTwos() const;
    int getFives() const;
    bool operator==(SetOfCoins set);
};

#endif // SETOFCOINS_H

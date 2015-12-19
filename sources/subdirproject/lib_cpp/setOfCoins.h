#ifndef SETOFCOINS_H
#define SETOFCOINS_H

class SetOfCoins
{
    int ones;
    int twos;
    int fives;
    int moneyAmount;
    const char* ERROR_BAD_AMOUNT = "ERROR: value of moneyAmount you put contradicts the condition";
public:
    SetOfCoins(int ones = 0, int twos = 0, int fives = 0, int moneyAmount = 0) : ones(ones), twos(twos), fives(fives), moneyAmount(moneyAmount)
    {
        if (this->moneyAmount > 99 || this->moneyAmount < 0)
            throw ERROR_BAD_AMOUNT;
    }
    ~SetOfCoins();
    void putAmount(int moneyAmount);
    SetOfCoins& exchange();
    bool operator==(SetOfCoins set);
};

#endif // SETOFCOINS_H

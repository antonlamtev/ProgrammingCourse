#ifndef LONGDIVISION_H
#define LONGDIVISION_H

#include <iostream>

class LongDivision
{
public:
    void putResultToArray(char*& array, const int firstNumber, const int secondNumber) const;
private:
    void putNumberCharByCharToArrayWithIndexation(char*& array, const int number, int& index) const;
    void putNSymbolsToArrayWithIndexation(char*& array, const int n, const char symbol, int& index) const;
    int numlen(int number) const;
    int nThDigOfNumber(const int n, const int number) const;
    int power(const int a, const int b) const;
};

#endif // LONGDIVISION_H

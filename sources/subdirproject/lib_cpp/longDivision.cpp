#include "longDivision.h"

LongDivision::LongDivision()
{
}

LongDivision::~LongDivision()
{
}

void LongDivision::putNSymbolsToArrayWithIndexation(char*& array, const int n, const char symbol, int& index) const
{
    for (int i = 0; i < n; ++i)
        array[++index] = symbol;
}

void LongDivision::putNumberCharByCharToArrayWithIndexation(char*& array, const int number, int& index) const
{
    for (int i = 1; i <= numlen(number); ++ i)
        array[++index] = nThDigOfNumber(i, number) + 48;
}

void LongDivision::putResultToArray(char*& array, const int firstNumber,const int secondNumber) const
{
    int dividend, residue, result, product;
    result = firstNumber / secondNumber;
    dividend = firstNumber / power(10, numlen(result) - 1);
    residue = firstNumber % power(10, numlen(result) - 1);
    int indent = dividend;
    int  crutch = 1;
    int index = -1;
    int numberOfAdditionalSpaces;
    for (int i = 1; i <= numlen(result); ++i)
    {
        if (i == 1)
        {
            putNumberCharByCharToArrayWithIndexation(array, dividend, index);
            if (residue != 0)
                putNumberCharByCharToArrayWithIndexation(array, residue, index);
            putNSymbolsToArrayWithIndexation(array, 1, '|', index);
            putNumberCharByCharToArrayWithIndexation(array, secondNumber, index);
            putNSymbolsToArrayWithIndexation(array, 1, '\n', index);
        }

        product = secondNumber *  nThDigOfNumber(i, result);
        putNSymbolsToArrayWithIndexation(array, numlen(indent) - numlen(product), ' ', index);
        putNumberCharByCharToArrayWithIndexation(array, product, index);

        if (i != 1)
            putNSymbolsToArrayWithIndexation(array, 1, '\n', index);

        if (i == 1)
        {
            putNSymbolsToArrayWithIndexation(array, numlen(firstNumber) - numlen(dividend) + 1, ' ', index);

            putNumberCharByCharToArrayWithIndexation(array, result, index);
            putNSymbolsToArrayWithIndexation(array, 1, '\n', index);
        }

        if (i != 1)
            putNSymbolsToArrayWithIndexation(array, numberOfAdditionalSpaces, ' ', index);

        if (crutch == 0)
            putNSymbolsToArrayWithIndexation(array, numlen(dividend) + 1, '-', index);
        else
            putNSymbolsToArrayWithIndexation(array, numlen(dividend), '-', index);

        putNSymbolsToArrayWithIndexation(array, 1, '\n', index);

        numberOfAdditionalSpaces = numlen(indent) - numlen(dividend - product);

        putNSymbolsToArrayWithIndexation(array, numberOfAdditionalSpaces, ' ', index);

        putNumberCharByCharToArrayWithIndexation(array, dividend - product, index);

        if (i != numlen(result))
        {
            putNumberCharByCharToArrayWithIndexation(array, nThDigOfNumber(i, residue), index);
            putNSymbolsToArrayWithIndexation(array, 1, '\n', index);
        }

        crutch = dividend - product;
        dividend = (dividend - product) * 10 + nThDigOfNumber(i, residue);
        indent *= 10;
        indent += nThDigOfNumber(i, residue);

    }
}

int LongDivision::numlen(int number) const
{
    int count;

    if (number)
    {
        count = 0;
        while (number)
        {
            ++count;
            number /= 10;
        }
    }
    else
    {
        count = 1;
    }
    return count;
}

int LongDivision::power(const int a, const int b) const
{
    int result = 1;
    for (int i = 0; i < b; ++i)
    {
        result *= a;
    }
    return result;
}

int LongDivision::nThDigOfNumber(const int n, const int number) const
{
    return (number / power(10, numlen(number) - n)) % 10;
}

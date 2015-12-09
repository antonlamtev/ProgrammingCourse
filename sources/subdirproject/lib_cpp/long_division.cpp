#include "long_division.h"

Long_division::Long_division()
{
}

Long_division::~Long_division()
{
}

void Long_division::put_n_symbols_to_array_with_counter(char*& array, const int n, const char symbol, int& index) const
{
    for (int i = 0; i < n; ++i)
        array[++index] = symbol;
}

void Long_division::put_number_char_by_char_to_array_with_counter(char*& array, const int number, int& index) const
{
    for (int i = 1; i <= numlen(number); ++ i)
        array[++index] = n_th_dig_of_num(i, number) + 48;
}

void Long_division::put_result_to_array(char*& array, const int first_number,const int second_number) const
{
    int dividend, residue, result, product;
    result = first_number / second_number;
    dividend = first_number / power(10, numlen(result) - 1);
    residue = first_number % power(10, numlen(result) - 1);
    int indent = dividend;
    int  crutch = 1; //нужен для правильного числа черточек в случаях, когда разность равна 0 :)
    int index = -1;
    for (int i = 1; i <= numlen(result); ++i)
    {
        if (i == 1)
        {
            put_number_char_by_char_to_array_with_counter(array, dividend, index);
            if (residue != 0)
                put_number_char_by_char_to_array_with_counter(array, residue, index);
            put_n_symbols_to_array_with_counter(array, 1, '|', index);
            put_number_char_by_char_to_array_with_counter(array, second_number, index);
            put_n_symbols_to_array_with_counter(array, 1, '\n', index);
        }

        product = second_number * n_th_dig_of_num(i, result);
        put_n_symbols_to_array_with_counter(array, numlen(indent) - numlen(product), ' ', index);
        put_number_char_by_char_to_array_with_counter(array, product, index);

        if (i != 1)
            put_n_symbols_to_array_with_counter(array, 1, '\n', index);

        if (i == 1)
        {
            put_n_symbols_to_array_with_counter(array, numlen(first_number) - numlen(dividend) + 1, ' ', index);

            put_number_char_by_char_to_array_with_counter(array, result, index);
            put_n_symbols_to_array_with_counter(array, 1, '\n', index);
        }

        int num_of_additional_spaces;

        if (i != 1)
            put_n_symbols_to_array_with_counter(array, num_of_additional_spaces, ' ', index);

        if (crutch == 0)
            put_n_symbols_to_array_with_counter(array, numlen(dividend) + 1, '-', index);
        else
            put_n_symbols_to_array_with_counter(array, numlen(dividend), '-', index);

        put_n_symbols_to_array_with_counter(array, 1, '\n', index);

        num_of_additional_spaces = numlen(indent) - numlen(dividend - product);

        put_n_symbols_to_array_with_counter(array, num_of_additional_spaces, ' ', index);

        put_number_char_by_char_to_array_with_counter(array, dividend - product, index);

        if (i != numlen(result))
        {
            put_number_char_by_char_to_array_with_counter(array, n_th_dig_of_num(i, residue), index);
            put_n_symbols_to_array_with_counter(array, 1, '\n', index);
        }

        crutch = dividend - product;
        dividend = (dividend - product) * 10 + n_th_dig_of_num(i, residue);
        indent = indent * 10 + n_th_dig_of_num(i, residue);

    }
}

int Long_division::numlen(int num) const
{
    int count;

    if (num)
    {
        count = 0;
        while (num)
        {
            ++count;
            num /= 10;
        }
    }
    else
    {
        count = 1;
    }
    return count;
}

int Long_division::power(const int a, const int b) const
{
    int result = 1;
    for (int i = 0; i < b; ++i)
    {
        result *= a;
    }
    return result;
}

int Long_division::n_th_dig_of_num(const int n, const int num) const
{
    return (num / power(10, numlen(num) - n)) % 10;
}

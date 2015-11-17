#include <stdio.h>
#include "quotient_math.h"

void print_n_symbols(int n, char symbol)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%c", symbol);
}

/// Слишком длинная функция, даже читать не буду :)
/// Про такие говорят, "работает и ладно", или хуже
///
/// Но если вы уверены, что ее нельзя разбить на поменьше,
/// то ладно...
void quotient_out(int M, int N)
{
    int dividend, residue, result, i, product;
    /// M  и N не понятно что...
    result = M / N;
    dividend = M / power(10, numlen(result) - 1);
    residue = M % power(10, numlen(result) - 1);
    int indent = dividend;

    int  crutch = 1; //нужен для правильного числа черточек в случаях, когда разность равна 0 :)
    for (i = 1; i <= numlen(result); ++i)
    {
        if (i == 1)
        {
            printf("%i", dividend);
            if (residue != 0)
                printf("%i", residue);
            printf("|%i\n", N);
        }

        product = N * n_th_dig_of_num(i, result);
        print_n_symbols(numlen(indent) - numlen(product), ' ');
        printf("%i", product);

        if (i != 1)
            printf("\n");

        if (i == 1)
        {
            print_n_symbols(numlen(M) - numlen(dividend) + 1, ' ');

            printf("%i\n", result);
        }

        int num_of_additional_spaces;

        if (i != 1)
            print_n_symbols(num_of_additional_spaces, ' ');

        if (crutch == 0)
            print_n_symbols(numlen(dividend) + 1, '-');
        else
            print_n_symbols(numlen(dividend), '-');

        printf("\n");

        print_n_symbols(numlen(indent) - numlen(dividend - product), ' ');

        num_of_additional_spaces = numlen(indent) - numlen(dividend - product);

        printf("%i", dividend - product);
        if (i == numlen(result))
            printf("\n");

        if (i != numlen(result))
            printf("%i\n", n_th_dig_of_num(i, residue));

        crutch = dividend - product;
        dividend = (dividend - product) * 10 + n_th_dig_of_num(i, residue);
        indent = indent * 10 + n_th_dig_of_num(i, residue);

    }
}

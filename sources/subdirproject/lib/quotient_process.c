#include <stdio.h>
#include "quotient_math.h"

void print_n_symbols(int n, char symbol)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%c", symbol);
}

void quotient_out(int M, int N)
{
    int dividend, residue, result;

    result = M / N;
    dividend = M / power(10, numlen(result) - 1);
    residue = M % power(10, numlen(result) - 1);
    int indent = dividend;

    int i;
    for (i = 1; i <= numlen(result); ++i)
    {
        if (i == 1)
        {
            printf("%i", dividend);
            if (residue != 0)
                printf("%i", residue);
            printf("|%i\n", N);
        }

        print_n_symbols(numlen(indent) - numlen(N * n_th_dig_of_num(i, result)), ' ');


        printf("%i", N * n_th_dig_of_num(i, result));

        if (i != 1)
            printf("\n");

        if (i == 1)
        {
            print_n_symbols(numlen(M) - numlen(dividend) + 1, ' ');

            printf("%i\n", result);
        }

        int x;

        if (i != 1)
            print_n_symbols(x, ' ');


        print_n_symbols(numlen(dividend), '-');

        printf("\n");

        print_n_symbols(numlen(indent) - numlen(dividend - N * n_th_dig_of_num(i, result)), ' ');

        x = numlen(indent) - numlen(dividend - N * n_th_dig_of_num(i, result));

        printf("%i", dividend - N * n_th_dig_of_num(i, result));
        if (i == numlen(result))
            printf("\n");

        if (i != numlen(result))
            printf("%i\n", n_th_dig_of_num(i, residue));

        dividend = (dividend - N * n_th_dig_of_num(i, result)) * 10 + n_th_dig_of_num(i, residue);
        indent = indent * 10 + n_th_dig_of_num(i, residue);

    }
}

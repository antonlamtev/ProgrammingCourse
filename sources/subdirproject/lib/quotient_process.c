#include <stdio.h>
#include <stdlib.h>
#include "quotient_math.h"

void print_n_symbols(FILE *stream, int n, char symbol)
{
    int i;
    for (i = 0; i < n; ++i)
        fprintf(stream, "%c", symbol);
}

/// Слишком длинная функция, даже читать не буду :)
/// Про такие говорят, "работает и ладно", или хуже
///
/// Но если вы уверены, что ее нельзя разбить на поменьше,
/// то ладно...
// :)
void quotient_out(FILE *stream, int first_number, int second_number)
{
    int dividend, residue, result, i, product;
    result = first_number / second_number;
    dividend = first_number / power(10, numlen(result) - 1);
    residue = first_number % power(10, numlen(result) - 1);
    int indent = dividend;
    int  crutch = 1; //нужен для правильного числа черточек в случаях, когда разность равна 0 :)
    for (i = 1; i <= numlen(result); ++i)
    {
        if (i == 1)
        {
            fprintf(stream, "%i", dividend);
            if (residue != 0)
                fprintf(stream, "%i", residue);
            fprintf(stream, "|%i\n", second_number);
        }

        product = second_number * n_th_dig_of_num(i, result);
        print_n_symbols(stream, numlen(indent) - numlen(product), ' ');
        fprintf(stream, "%i", product);

        if (i != 1)
            fprintf(stream, "\n");

        if (i == 1)
        {
            print_n_symbols(stream, numlen(first_number) - numlen(dividend) + 1, ' ');

            fprintf(stream, "%i\n", result);
        }

        int num_of_additional_spaces;

        if (i != 1)
            print_n_symbols(stream, num_of_additional_spaces, ' ');

        if (crutch == 0)
            print_n_symbols(stream, numlen(dividend) + 1, '-');
        else
            print_n_symbols(stream, numlen(dividend), '-');

        fprintf(stream, "\n");

        print_n_symbols(stream, numlen(indent) - numlen(dividend - product), ' ');

        num_of_additional_spaces = numlen(indent) - numlen(dividend - product);

        fprintf(stream, "%i", dividend - product);
        if (i == numlen(result))
            fprintf(stream, "\n");

        if (i != numlen(result))
            fprintf(stream, "%i\n", n_th_dig_of_num(i, residue));

        crutch = dividend - product;
        dividend = (dividend - product) * 10 + n_th_dig_of_num(i, residue);
        indent = indent * 10 + n_th_dig_of_num(i, residue);

    }
}

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void matrix(char* input_file_name, char* output_file_name)
{
    FILE* in;
    FILE* out;
    in = fopen(input_file_name, "r");
    out = fopen(output_file_name, "w");
    int** P;
    int n, i, j;
    fscanf(in, "%i", &n);

    P = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; ++i)
        P[i] = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            fscanf(in, "%i\n", &P[i][j]);

    sort_nulls_to_the_main_diagonal(P, n);

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
            fprintf(out, "%i ", P[i][j]);
        fprintf(out, "\n");
    }

    for (i = 0; i < n; ++i)
        free(P[i]);
    free(P);
    fclose(in);
    fclose(out);
    puts("Программа успешно выполнена!");
}

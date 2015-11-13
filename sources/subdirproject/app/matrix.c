#include <stdlib.h>
#include <stdio.h>
#include "matrix_algorithms.h"


void matrix(void)
{
    FILE *in, *out;
    in = fopen("matrix.in", "r");
    out = fopen("matrix.out", "w");
    int **P;
    int n, i, j;
    fscanf(in, "%i", &n);

    P = (int **) malloc(n * sizeof(int*));
    for (i = 0; i < n; ++i)
        P[i] = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            fscanf(in, "%i\n", &P[i][j]);

    buble_sort_of_lines(P, n);

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
}

#include <stdlib.h>
#include <stdio.h>
#include "algorithms_for_matrix.h"


void matrix(void)
{
    FILE *in, *out;
    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");
    int **P;
    int n, i, j/*, k*/;
    fscanf(in, "%i", &n);

    P = (int **) malloc(n * sizeof(int*));
    for (i = 0; i < n; ++i)
        P[i] = (int *) malloc(n * sizeof(int));

//    for (i = 0; i < n; ++i)
//        for (j = 0; j < n; ++j)
//            fscanf(in, "%i\n", &P[i][j]);

//    for (k = n-1; k >= 0; --k)
//        for (i = 0; i < k; ++i)
//            if (level_of_null(P, n, i) > level_of_null(P, n, i+1))
//                    for (j = 0; j < n; ++j)
//                    {
//                        swap(&P[i][j], &P[i+1][j]);
//                    }

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

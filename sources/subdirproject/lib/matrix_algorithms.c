int level_of_null(int **P, int n, int number_of_column)
{
    int result = 0;
    int j, i = number_of_column;
    for (j = 0; j < n; ++j)
        if (P[i][j] == 0)
        {
            result = j;
            break; //на всякий случай
        }
    return result;
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void buble_sort_of_lines(int **P, int n)
{
    int i, j, k;
    for (k = n-1; k >= 0; --k)
        for (i = 0; i < k; ++i)
            if (level_of_null(P, n, i) > level_of_null(P, n, i+1))
                    for (j = 0; j < n; ++j)
                    {
                        swap(&P[i][j], &P[i+1][j]);
                    }
}

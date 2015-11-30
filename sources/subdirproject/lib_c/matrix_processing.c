int level_of_null(int** P, int n, int number_of_column)
{
    int result = 0;
    int i = number_of_column;
    for (int j = 0; j < n; ++j)
        if (P[i][j] == 0)
        {
            result = j;
            break;
        }
    return result;
}

void swap(int* a, int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void sort_nulls_to_the_main_diagonal(int** P, int n)
{
    for (int k = n-1; k >= 0; --k)
        for (int i = 0; i < k; ++i)
            if (level_of_null(P, n, i) > level_of_null(P, n, i+1))
                    for (int j = 0; j < n; ++j)
                    {
                        swap(&P[i][j], &P[i+1][j]);
                    }

}

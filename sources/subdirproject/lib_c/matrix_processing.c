int level_of_null(int** P, int n, int number_of_line)
{
    int result = 0;
    for (int i = 0; i < n; ++i)
        if (P[number_of_line][i] == 0)
        {
            result = i;
            break;
        }
    return result;
}


void sort_nulls_to_the_main_diagonal(int** P, int n)
{
    int* t;
    int i, j;
    for (i = n-1; i >= 0; --i)
        for (j = 0; j < i; ++j)
            if (level_of_null(P, n, j) > level_of_null(P, n, j+1))
            {
                    t = P[j];
                    P[j] = P[j+1];
                    P[j+1] = t;
            }
}

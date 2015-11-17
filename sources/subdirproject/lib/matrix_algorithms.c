int level_of_null(int **P, int n, int number_of_column)
{
    int result = 0;
    int j, i = number_of_column;
    for (j = 0; j < n; ++j)
        if (P[i][j] == 0)
        {
            result = j;
            break;
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


/// Кажется, по заданию у вас
/// 19. В каждом столбце и каждой строке матрицы P(n,n) содержится ровно один нулевой элемент.
/// Перестановкой строк добиться расположения всех нулей по главной диагонали матрицы.
///
/// Сортировка пузырьком?
/// https://en.wikipedia.org/wiki/Bubble_sort
/// Причем здесь она?
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
    /// я не вижу, где строки меняются местами
}

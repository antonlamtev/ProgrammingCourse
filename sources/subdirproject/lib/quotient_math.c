int numlen(int num)
{
    int count;
    if (num == 0)
        count = 1;
    else
    {
        count = 0;
        while (num)
        {
            ++count;
            num /= 10;
        }
    }
    return count;
}

int power(int a, int b)
{
    int i, result = 1;
    for (i = 0; i < b; ++i)
    {
        result *= a;
    }
    return result;
}

int n_th_dig_of_num(int n, int num)
{
    return (num / power(10, numlen(num) - n)) % 10;
}

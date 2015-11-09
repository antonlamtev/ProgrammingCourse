int num_length(int num)
{
    int result = 0;
    while (num)
    {
        ++result;
        num /= 10;
    }
    return result;
}

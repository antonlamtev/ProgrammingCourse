void change_by_coins(int amount, int *fives, int *twos, int *ones)
{
    *fives = amount / 5;
    *twos = (amount - (*fives * 5)) / 2;
    if (amount % 5 == 3)
        *ones = 1;
    else
        *ones = 0;
}

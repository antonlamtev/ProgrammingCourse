const int two = 2, five = 5, one = 1, three = 3;

void change_by_coins(int amount, int *fives, int *twos, int *ones)
{
    *fives = amount / five;
    *twos = (amount - (*fives * five)) / two;
    int result;
    if (amount % five == three)
        result = one;
    else
        result = 0;
    *ones = result;
}

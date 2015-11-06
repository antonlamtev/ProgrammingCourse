const int two = 2, five = 5, one = 1;

int change_by_fives(int amount)
{
    return amount / five;
}

int change_by_twos(int amount)
{
    return (amount - change_by_fives(amount) * five) / two;
}

int change_by_ones(int amount)
{
    return (amount - change_by_fives(amount) * five - change_by_twos(amount) * two);
}


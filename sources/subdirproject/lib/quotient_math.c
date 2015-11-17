/// я бы ради трех (двух) таких функций не стала бы делать отдельный файл,
//            трех (трех)

int numlen(int num)
{
    int count;

    if (num)
    {
        count = 0;
        while (num)
        {
            ++count;
            num /= 10;
        }
    }
    else
    {
        count = 1;
    }
    return count;
}

/// есть, вроде функция в math.h
// есть функция double pow(double, double)
// а мне нужна функция, возвращающая int.

//for (i = 0; i < a; ++i)
//{
//   printf("%i == %i ?\n", power(10,i), (int) pow (10,i));
//    // при нечетных i>1 результат (int) pow() меньше на единицу правильного результата power()
//    // я полагаю, это происходит от того, что pow() реализована через экспоненту и отсюда есть погрешность.
//}

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

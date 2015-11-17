#include "queens_check_for_beating.h"
#include "queens_enum.h"

/// Давайте заведем структуры для координат
int queens_result(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int result = no_one;
    if (check_for_beating(x1, y1, x2, y2))
    {
        if (check_for_beating(x1, y1, x3, y3))
        {
            if (check_for_beating(x3, y3, x2, y2))
            {
                result = everyone;
            }
            else
            {
                result = OneTwo_OneThree;
            }
        }
        else
        {
            if (check_for_beating(x3, y3, x2, y2))
            {
                result = OneTwo_TwoThree;
            }
            else
            {
                result = OneTwo;
            }
        }
    }
    else if (check_for_beating(x1, y1, x3, y3))
    {
        if (check_for_beating(x3, y3, x2, y2))
        {
            result = OneThree_TwoThree;
        }
        else
        {
            result = OneThree;
        }
    }
    else if (check_for_beating(x3, y3, x2, y2))
    {
        result = TwoThree;
    }
    return result;
}

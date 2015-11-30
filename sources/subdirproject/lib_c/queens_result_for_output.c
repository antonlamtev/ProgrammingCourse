#include "queens.h"

int queens_result(struct coordinate x, struct coordinate y)
{
    int result = no_one;
    if (check_for_beating(x.first, y.first, x.second, y.second))
    {
        if (check_for_beating(x.first, y.first, x.third, y.third))
        {
            if (check_for_beating(x.third, y.third, x.second, y.second))
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
            if (check_for_beating(x.third, y.third, x.second, y.second))
            {
                result = OneTwo_TwoThree;
            }
            else
            {
                result = OneTwo;
            }
        }
    }
    else if (check_for_beating(x.first, y.first, x.third, y.third))
    {
        if (check_for_beating(x.third, y.third, x.second, y.second))
        {
            result = OneThree_TwoThree;
        }
        else
        {
            result = OneThree;
        }
    }
    else if (check_for_beating(x.third, y.third, x.second, y.second))
    {
        result = TwoThree;
    }
    return result;
}

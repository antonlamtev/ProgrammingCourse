#include "check_for_beating.h"

int queens_result(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int result = 0;
    if (check_for_beating(x1, y1, x2, y2))
    {
        if (check_for_beating(x1, y1, x3, y3))
        {
            if (check_for_beating(x3, y3, x2, y2))
            {
                result = 1;
            }
            else
            {
                result = 2;
            }
        }
        else
        {
            if (check_for_beating(x3, y3, x2, y2))
            {
                result = 3;
            }
            else
            {
                result = 4;
            }
        }
    }
    else if (check_for_beating(x1, y1, x3, y3))
    {
        if (check_for_beating(x3, y3, x2, y2))
        {
            result = 5;
        }
        else
        {
            result = 6;
        }
    }
    else if (check_for_beating(x3, y3, x2, y2))
    {
        result = 7;
    }
    return result;
}
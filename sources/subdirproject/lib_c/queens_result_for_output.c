#include "queens.h"

int queens_result(struct queen q1, struct queen q2, struct queen q3)
{
    int result = no_one;
    if (check_for_beating(q1, q2))
    {
        if (check_for_beating(q1, q3))
        {
            if (check_for_beating(q2, q3))
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
            if (check_for_beating(q2, q3))
            {
                result = OneTwo_TwoThree;
            }
            else
            {
                result = OneTwo;
            }
        }
    }
    else if (check_for_beating(q1, q3))
    {
        if (check_for_beating(q2, q3))
        {
            result = OneThree_TwoThree;
        }
        else
        {
            result = OneThree;
        }
    }
    else if (check_for_beating(q2, q3))
    {
        result = TwoThree;
    }
    return result;
}

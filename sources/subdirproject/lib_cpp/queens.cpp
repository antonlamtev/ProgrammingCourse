#include "queens.h"

Queens::Queens()
{
}

Queens::~Queens()
{
}

int Queens::check_for_beating(const Queen q1, const Queen q2) const
{
    return (q1.x == q2.x || q1.y == q2.y) || (abs(q1.x-q2.x) == abs(q1.y-q2.y));
}

int Queens::get_result(const Queen q1, const Queen q2, const Queen q3) const
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

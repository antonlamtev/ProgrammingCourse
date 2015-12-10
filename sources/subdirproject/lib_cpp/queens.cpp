#include "queens.h"

Queens::Queens()
{
}

Queens::~Queens()
{
}

int Queens::checkForBeating(const Queen q1, const Queen q2) const
{
    return (q1.x == q2.x || q1.y == q2.y) || (abs(q1.x-q2.x) == abs(q1.y-q2.y));
}

int Queens::getResult(const Queen q1, const Queen q2, const Queen q3) const
{
    int result = NO_ONE;
    if (checkForBeating(q1, q2))
    {
        if (checkForBeating(q1, q3))
        {
            if (checkForBeating(q2, q3))
            {
                result = EVERYONE;
            }
            else
            {
                result = OneTwo_OneThree;
            }
        }
        else
        {
            if (checkForBeating(q2, q3))
            {
                result = OneTwo_TwoThree;
            }
            else
            {
                result = OneTwo;
            }
        }
    }
    else if (checkForBeating(q1, q3))
    {
        if (checkForBeating(q2, q3))
        {
            result = OneThree_TwoThree;
        }
        else
        {
            result = OneThree;
        }
    }
    else if (checkForBeating(q2, q3))
    {
        result = TwoThree;
    }
    return result;
}

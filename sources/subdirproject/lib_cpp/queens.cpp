#include "queens.h"

Queen::Queen(int letter, int numeral) : letter(letter), numeral(numeral)
{
    if (letter < A || letter > H || numeral < 1 || numeral > 8)
    {
        throw CoordinatesException(letter, numeral);
    }
}


bool Queen::amIBeat(Queen queen) const
{
    return letter == queen.letter || numeral == queen.numeral || abs(letter - queen.letter) == abs(numeral - queen.numeral);
}

WhoBeats ThreeQueens::whoBeats(Queen q1, Queen q2, Queen q3)
{
    if (q1.amIBeat(q2))
    {
        if (q1.amIBeat(q3))
        {
            if (q2.amIBeat(q3))
            {
                return EVERYONE;
            }
            else
            {
                return OneTwo_OneThree;
            }
        }
        else if (q2.amIBeat(q3))
        {
            return OneTwo_TwoThree;
        }
        else
        {
            return OneTwo;
        }
    }
    else if (q1.amIBeat(q3))
    {
        if (q2.amIBeat(q3))
        {
            return OneThree_TwoThree;
        }
        else
        {
            return OneThree;
        }
    }
    else if (q2.amIBeat(q3))
    {
        return TwoThree;
    }
    else
    {
        return NO_ONE;
    }
}

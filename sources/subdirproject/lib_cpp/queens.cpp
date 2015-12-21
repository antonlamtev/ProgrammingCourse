#include "queens.h"

Queen::Queen(int letter, int numeral): letter(letter), numeral(numeral)
{
    if (letter < A || letter > H || numeral < 1 || numeral > 8)
    {
        throw CoordinatesException(ERROR_BAD_COORDINATES);
    }
}

Queen::Queen()
{
}

Queen::~Queen()
{
}

bool Queen::amIBeat(Queen queen) const
{
    return letter == queen.letter || numeral == queen.numeral || abs(letter - queen.letter) == abs(numeral - queen.numeral);
}

ThreeQueens::ThreeQueens()
{
}

ThreeQueens::~ThreeQueens()
{
}

WhoBeats ThreeQueens::whoBeats(vector<Queen>& vec)
{
    if (vec[0].amIBeat(vec[1]))
    {
        if (vec[0].amIBeat(vec[2]))
        {
            if (vec[1].amIBeat(vec[2]))
            {
                return EVERYONE;
            }
            else
            {
                return OneTwo_OneThree;
            }
        }
        else if (vec[1].amIBeat(vec[2]))
        {
            return OneTwo_TwoThree;
        }
        else
        {
            return OneTwo;
        }
    }
    else if (vec[0].amIBeat(vec[2]))
    {
        if (vec[1].amIBeat(vec[2]))
        {
            return OneThree_TwoThree;
        }
        else
        {
            return OneThree;
        }
    }
    else if (vec[1].amIBeat(vec[2]))
    {
        return TwoThree;
    }
    else
    {
        return NO_ONE;
    }
}

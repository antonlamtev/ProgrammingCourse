#include "queens.h"

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

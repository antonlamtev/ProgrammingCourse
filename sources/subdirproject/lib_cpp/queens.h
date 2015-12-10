#ifndef QUEENS_H
#define QUEENS_H

#include <cstdlib>

struct Queen
{
    int x;
    int y;
};

enum Who_beat {NO_ONE = 0, EVERYONE, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
               OneThree_TwoThree, OneThree, TwoThree};

class Queens
{
public:
    Queens();
    ~Queens();
    int getResult(const Queen q1, const Queen q2, const Queen q3) const;
private:
    int checkForBeating(const Queen q1, const Queen q2) const;
};

#endif // QUEENS_H

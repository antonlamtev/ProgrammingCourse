#ifndef QUEENS_H
#define QUEENS_H

#include <cstdlib>

struct Queen
{
    int x;
    int y;
};

enum who_beat {no_one = 0, everyone, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
               OneThree_TwoThree, OneThree, TwoThree};

class Queens
{
public:
    Queens();
    ~Queens();
    int get_result(const Queen q1, const Queen q2, const Queen q3) const;
private:
    int check_for_beating(const Queen q1, const Queen q2) const;
};

#endif // QUEENS_H

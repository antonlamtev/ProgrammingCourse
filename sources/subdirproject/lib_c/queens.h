#ifndef QUEENS_H
#define QUEENS_H

#ifdef __cplusplus
extern "C" {
#endif

struct queen
{
    int x;
    int y;
};

int check_for_beating(struct queen q1, struct queen q2);

enum who_beat {no_one = 0, everyone, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
               OneThree_TwoThree, OneThree, TwoThree};

int queens_result(struct queen q1, struct queen q2, struct queen q3);

#ifdef __cplusplus
}
#endif

#endif // QUEENS_H

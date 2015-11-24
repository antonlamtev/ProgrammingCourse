#ifndef QUEENS_H
#define QUEENS_H

#ifdef __cplusplus
extern "C" {
#endif

int check_for_beating(int x1, int y1, int x2, int y2);
struct coordinate
{
    int first;
    int second;
    int third;
};
enum who_beat {no_one = 0, everyone, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
               OneThree_TwoThree, OneThree, TwoThree};
int queens_result(struct coordinate x, struct coordinate y);

#ifdef __cplusplus
}
#endif

#endif // QUEENS_H

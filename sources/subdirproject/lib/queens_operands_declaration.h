#ifndef QUEENS_OPERANDS_DECLARATION
#define QUEENS_OPERANDS_DECLARATION

struct coordinate
{
    int first;
    int second;
    int third;
};
enum who_beat {no_one = 0, everyone, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
               OneThree_TwoThree, OneThree, TwoThree};

#endif // QUEENS_OPERANDS_DECLARATION


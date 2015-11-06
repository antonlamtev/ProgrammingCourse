#include <stdio.h>

void queens_out(int a)
{
    enum who_beat {no_one = 0, everyone, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
                   OneThree_TwoThree, OneThree, TwoThree};
    switch (a)
    {
        case no_one:
            puts("Никто никого не бьет");
            break;
        case everyone:
            puts("Все ферзи бьют друг друга");
            break;
        case OneTwo_OneThree:
            printf("1 и 2 ферзи бьют друг друга\n1 и 3 ферзи бьют друг друга\n");
            break;
        case OneTwo_TwoThree:
            printf("1 и 2 ферзи бьют друг друга\n2 и 3 ферзи бьют друг друга\n");
            break;
        case OneTwo:
            puts("1 и 2 ферзи бьют друг друга");
            break;
        case OneThree_TwoThree:
            printf("1 и 3 ферзи бьют друг друга\n2 и 3 ферзи бьют друг друга\n");
            break;
        case OneThree:
            puts("1 и 3 ферзи бьют друг друга");
            break;
        case TwoThree:
            puts("2 и 3 ферзи бьют друг друга");
            break;       
    }
}

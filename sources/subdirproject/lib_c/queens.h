#ifndef QUEENS_H
#define QUEENS_H

#ifdef __cplusplus
extern "C" {
#endif

/// Я надеялась на структуру с координатами, тогда в эту функцию передать две структуры
int check_for_beating(int x1, int y1, int x2, int y2);

///Координаты -- это x, y -- позиции на шахматном поле
///а здесь что?
struct coordinate
{
    int first;
    int second;
    int third;
};
enum who_beat {no_one = 0, everyone, OneTwo_OneThree, OneTwo_TwoThree, OneTwo,
               OneThree_TwoThree, OneThree, TwoThree};

/// Три королевы же, нужно передать три набора координат,
/// а это даже выглядит дико
int queens_result(struct coordinate x, struct coordinate y);

#ifdef __cplusplus
}
#endif

#endif // QUEENS_H

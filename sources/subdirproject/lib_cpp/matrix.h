#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
    Matrix();
    ~Matrix();
    void sort_nulls_to_the_main_diagonal(int**& P, const int size) const;
private:
    int level_of_null(int**& P, const int size, const int number_of_column) const;
};

#endif // MATRIX_H

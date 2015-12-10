#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
public:
    Matrix();
    ~Matrix();
    void sortNullsToTheMainDiagonal(int**& P, const int size) const;
private:
    int levelOfNull(int**& P, const int size, const int numberOfColumn) const;
};

#endif // MATRIX_H

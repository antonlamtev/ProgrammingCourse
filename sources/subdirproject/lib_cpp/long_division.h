#ifndef LONG_DIVISION_H
#define LONG_DIVISION_H

#include <iostream>

class Long_division
{
public:
    Long_division();
    ~Long_division();
    void put_result_to_array(char*& array, const int first_number, const int second_number) const;
private:
    void put_number_char_by_char_to_array_with_counter(char*& array, const int number, int& index) const;
    void put_n_symbols_to_array_with_counter(char*& array, const int n, const char symbol, int& index) const;
    int numlen(int num) const;
    int n_th_dig_of_num(const int n, const int num) const;
    int power(const int a, const int b) const;
};

#endif // LONG_DIVISION_H

#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <new>

using namespace std;

class Table
{
    /// эти ведь тоже private по факту, зачем разносить на два блока?
    // разнес, т.к посчитал нужным зрительно отделить поля от методов.
    // если это дурной тон, то не буду так делать.
    string* cell;
    int* key;
    int index;
    int current_size;
    const int additional_size = 10;
public:
    Table(int table_size = 2);
    Table(const Table& object);
    ~Table();
    void put(string value, int key);
    /// todo перегрузить оператор индексирования operator[]
    string index_by_key(int key) const;
private:
    void allocate_more_memory(string*& arr, int& already_allocated_size);
    void allocate_more_memory(int*& arr, int& already_allocated_size);
};

#endif // TABLE_H

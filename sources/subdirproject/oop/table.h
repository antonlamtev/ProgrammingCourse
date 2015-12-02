#ifndef TABLE_H
#define TABLE_H

using namespace std;

#include <iostream>

class Table
{
    string* cell;
    int* key;
    int index;
    int current_size;
    const int additional_size = 10;
public:
    Table(int table_size = 2);
    ~Table();
    void put(string value, int key);
    void index_by_key(int key);
private:
    void allocate_more_memory(string*& arr, int& already_allocated_size, const int additional_size);
    void allocate_more_memory(int*& arr, int& already_allocated_size, const int additional_size);
};

#endif // TABLE_H

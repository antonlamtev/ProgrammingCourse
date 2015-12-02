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
public:
    Table(int table_size = 2);
    ~Table();
    void put(string value, int key);
    void index_by_key(int key);
//private:
//    void allocate_more_memory(string*& array, int& already_allocated_memory, int additional_memory);
//    void allocate_more_memory(int*& array, int& already_allocated_memory, int additional_memory);
};

#endif // TABLE_H

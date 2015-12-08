#ifndef TABLE_H
#define TABLE_H

#define ERROR "ERROR: there are not any cells with typed key"
#define ADDITIONAL_SIZE 10

#include <iostream>
#include <new>

using namespace std;

class Table
{
    string* cell;
    int* key;
    int index;
    int current_size;
    void allocate_more_memory();
    string index_by_key(const int key_value);
    void flag_false_exception(bool& flag, string& result);

public:
    Table(int table_size = 5);
    Table(const Table& object);
    ~Table();
    void put(const string value, const int key);
    string operator[](const int key_value);
    int get_current_size() const;
    int get_number_of_elements() const;
};

#endif // TABLE_H

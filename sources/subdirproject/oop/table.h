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
//    const int additional_size = 10;
//    const char* ERROR = "ERROR: there are not any cells with typed key";
    void allocate_more_memory();
    void flag_false_exception(bool& flag, string& result);

public:
    Table(int table_size = 5);
    Table(const Table& object);
    ~Table();
    void put(string value, int key);
    string index_by_key(int key_value);
    string operator[](int key_value);
    int get_current_size();
    int get_number_of_elements();
};

#endif // TABLE_H

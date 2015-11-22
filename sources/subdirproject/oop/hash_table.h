#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define table_size 50

using namespace std;

#include <iostream>

class Hash_table
{
    string table[table_size];
    string key[table_size];
    int ind;
public:
    Hash_table();
    ~Hash_table();
    void add(string element, string key_for_new_element);
    void index_by_key(string key_of_element);
    void copy_a_cell(int ind_of_copying_element, string key_for_new_element);
};

#endif // HASH_TABLE_H

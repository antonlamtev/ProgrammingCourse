#include <iostream>
#include "hash_table.h"

using namespace std;

Hash_table::Hash_table()
{
    cout << "Hash table has been initilized" << endl;
    ind = 0;
}

Hash_table::~Hash_table()
{
    cout << "Hash table has beem destroyed" << endl;
}

void Hash_table::add(string element, string key_for_new_element)
{
    if (ind == table_size)
    {
        cout << "Table is full" << endl;
        return;
    }
    else
    {
        table[ind] = element;
        key[ind] = key_for_new_element;
        ++ind;
    }
}

void Hash_table::index_by_key(string key_of_element)
{
    bool flag = false;
    for (int i = 0; i < ind; ++i)
    {
        if (key[i] == key_of_element)
        {
            cout << table[i] << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "There are not any cells of choosen key" << endl;
    }
}

void Hash_table::copy_a_cell(int ind_of_copying_element, string key_for_new_element)
{
    if (ind == table_size)
    {
        cout << "Table is full" << endl;
        return;
    }
    else
    {
        table[ind] = table[ind_of_copying_element];
        key[ind] = key_for_new_element;
        ++ind;
    }
}

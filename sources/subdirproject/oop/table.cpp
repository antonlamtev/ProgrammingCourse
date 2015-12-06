#include "table.h"

Table::Table(int table_size)
{
    current_size = table_size;
    index = -1;
    cell = new string[table_size];
    key = new int[table_size];
}

Table::Table(const Table &object)
{
    cell = new string[current_size = object.current_size];
    key = new int[current_size];
    for (auto i = 0; i <= (index = object.index); ++i)
    {
        cell[i] = object.cell[i];
        key[i] = object.key[i];
    }
}

Table::~Table()
{
    delete[] cell;
    delete[] key;
}

void Table::allocate_more_memory(string*& arr, int& already_allocated_size)
{
    string* t = new string[already_allocated_size + additional_size];

    for (int i = 0; i < already_allocated_size; ++i)
        t[i] = arr[i];

    delete[] arr;


    arr = t;

    already_allocated_size += additional_size;
}

void Table::allocate_more_memory(int*& arr, int& already_allocated_size)
{
    int* t = new int[already_allocated_size + additional_size];

    for (int i = 0; i < already_allocated_size; ++i)
        t[i] = arr[i];

    delete[] arr;

    arr = t;

    already_allocated_size += additional_size;
}

void Table::put(string cell_value, int key_value)
{
    if (index == current_size - 1)
    {
        int size = current_size;
        /// и зачем передавать cell и key, если они тоже будут доступны
        // нужно передать, чтобы компилятор поянял, какую функцию использовать, для int или для string.
        allocate_more_memory(cell, size);
        allocate_more_memory(key, current_size);
    }
    cell[++index] = cell_value;
    key[index] = key_value;
}


///todo обработка исключений!!!
string Table::index_by_key(int key_value) const
{
    int i;
    for (i = 0; i <= index; ++i)
    {
        if (key[i] == key_value)
        {
            break;
        }
    }
    return cell[i];
}

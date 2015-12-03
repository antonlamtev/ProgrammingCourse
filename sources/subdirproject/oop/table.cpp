#include <iostream>
#include <new>

#include "table.h"

/// можно сделать table_size значения по умолчанию
Table::Table(int table_size)
{
    current_size = table_size;
    index = -1;
    cell = new string[table_size];
    key = new int[table_size];
    cout << "Table has been initialized\n";
    cout << endl;
}

Table::~Table()
{
    delete[] cell;
    delete[] key;
    cout << endl;
    cout << "Table has been destroyed\n";
}

void Table::allocate_more_memory(string*& arr, int& already_allocated_size, const int additional_size)
{
    string* t = new string[already_allocated_size + additional_size];

    for (int i = 0; i < already_allocated_size; ++i)
        t[i] = arr[i];

    delete[] arr;


    arr = t;

    already_allocated_size += additional_size;
}

void Table::allocate_more_memory(int*& arr, int& already_allocated_size, const int additional_size)
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
        /// вы же тут не адрес передаете по факту -- size
        /// и зачем таскать туда-сюда size по методам в одном классе, если можно просто изменить current_size и им пользоваться доступен
        /// зачем передавать additional_size, если это поле класса будет доступно в методе all_m_
        /// и зачем передавать cell и key, если они тоже будут доступны
        allocate_more_memory(cell, size, additional_size);
        size = current_size;
        allocate_more_memory(key, size, additional_size);
        current_size = size;
    }
    cell[++index] = cell_value;
    key[index] = key_value;

    cout << cell[index] << " <======> " << key[index] << endl;
}

void Table::index_by_key(int key_value)
{
    /// флаг нигде не используется, и все равно вы скоро реализуете исключения
    bool flag = true;
    for (int i = 0; i <= index; ++ i)
    {
        if (key[i] == key_value)
        {
            cout << cell[i] << " <======> " << key[i] << endl;
            return;
        }
    }
    if (flag)
    {
        cout << "There are not any cells with choosen key\n";
    }
}

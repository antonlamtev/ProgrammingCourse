#include <iostream>
#include <new>

#include "table.h"

Table::Table(int table_size)
{
    current_size = table_size;
    index = -1;
    cell = new string[table_size];
    key = new int[table_size];
    std::cout << "Table has been initialized\n";
}

Table::~Table()
{
    delete[] cell;
    delete[] key;
    std::cout << "Table has been destroyed\n";
}

//void Table::allocate_more_memory(string*& array, int& already_allocated_memory, int additional_memory)
//{
//    string* temp = new string[already_allocated_memory];

//    for (int i = 0; i < already_allocated_memory; ++i)
//    {
//        temp[i] = array[i];
//    }

//    already_allocated_memory += additional_memory;

//    array = new string[already_allocated_memory];

//    for (int i = 0; i < already_allocated_memory; ++i)
//    {
//        array[i] = temp[i];
//    }

//    delete[] temp;
//}

//void Table::allocate_more_memory(int* &array, int& already_allocated_memory, int additional_memory)
//{
//    int* temp = new int[already_allocated_memory];

//    for (int i = 0; i < already_allocated_memory; ++i)
//    {
//        temp[i] = array[i];
//    }

//    already_allocated_memory += additional_memory;

//    array = new int[already_allocated_memory];

//    for (int i = 0; i < already_allocated_memory; ++i)
//    {
//        array[i] = temp[i];
//    }

//    delete[] temp;
//}

void Table::put(string cell_value, int key_value)
{
    if (index == current_size - 1)
    {
//        int size = current_size;
//        allocate_more_memory(cell, size, 10);
//        size = current_size;
//        allocate_more_memory(key, size, 10);
//        current_size = size;

        string* temp_c = new string[current_size + 10];
        int* temp_k = new int[current_size + 10];

        for (int i = 0; i < current_size; ++i)
        {
            temp_c[i] = cell[i];
            temp_k[i] = key[i];
        }

        current_size += 10;

        cell = new string[current_size];
        key = new int[current_size];

        for (int i = 0; i < current_size; ++i)
        {
            cell[i] = temp_c[i];
            key[i] = temp_k[i];
        }

        delete[] temp_c;
        delete[] temp_k;
    }
    cell[++index] = cell_value;
    key[index] = key_value;

    std::cout << cell[index] << " <======> " << key[index] << std::endl;
}

void Table::index_by_key(int key_value)
{
    bool flag = true;
    for (int i = 0; i <= index; ++ i)
    {
        //std::cout <<key[i] << endl;
        if (key[i] == key_value)
        {
            std::cout << cell[i] << std::endl;
            return;
        }
    }
    if (flag)
    {
        std::cout << "There are not any cells with choosen key\n";
    }
}

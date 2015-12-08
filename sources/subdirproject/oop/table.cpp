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

void Table::allocate_more_memory()
{
    string* temp_cell = new string[current_size + ADDITIONAL_SIZE];
    int* temp_key = new int[current_size + ADDITIONAL_SIZE];

    for (int i = 0; i < current_size; ++i)
    {
        temp_cell[i] = cell[i];
        temp_key[i] = key[i];
    }

    delete[] cell;
    delete[] key;

    cell = temp_cell;
    key = temp_key;

    current_size += ADDITIONAL_SIZE;
}

void Table::put(const string cell_value, const int key_value)
{
    if (index == current_size - 1)
    {
        allocate_more_memory();
    }
    cell[++index] = cell_value;
    key[index] = key_value;
}

void Table::flag_false_exception(bool& flag, string& result)
{
    try
    {
        if (!flag)
        {
            throw ERROR;
        }
    }

    catch (const char* str)
    {
        result = str;
    }
}

string Table::index_by_key(const int key_value)
{
    string result;
    bool flag = false;
    for (auto i = 0; i <= index; ++i)
    {
        if (key[i] == key_value)
        {
            flag = true;
            result = cell[i];
            break;
        }
    }

    flag_false_exception(flag, result);

    return result;
}

string Table::operator[](const int key_value)
{
    return index_by_key(key_value);
}

int Table::get_current_size() const
{
    return current_size;
}

int Table::get_number_of_elements() const
{
    return index + 1;
}

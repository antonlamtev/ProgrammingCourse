#include "table.h"

Table::Table(int tableSize)
{
    currentSize = tableSize;
    index = -1;
    cell = new string[tableSize];
    key = new int[tableSize];
}

Table::Table(const Table &object)
{
    cell = new string[currentSize = object.currentSize];
    key = new int[currentSize];
    for (int i = 0; i <= (index = object.index); ++i)
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

void Table::allocateMoreMemory()
{
    string* tempCell = new string[currentSize + ADDITIONAL_SIZE];
    int* tempKey = new int[currentSize + ADDITIONAL_SIZE];

    for (int i = 0; i < currentSize; ++i)
    {
        tempCell[i] = cell[i];
        tempKey[i] = key[i];
    }

    delete[] cell;
    delete[] key;

    cell = tempCell;
    key = tempKey;

    currentSize += ADDITIONAL_SIZE;
}

void Table::put(const string cellValue, const int keyValue)
{
    if (index == currentSize - 1)
    {
        allocateMoreMemory();
    }
    cell[++index] = cellValue;
    key[index] = keyValue;
}

string Table::operator[](const int keyValue) const
{
    for (auto i = 0; i <= index; ++i)
    {
        if (key[i] == keyValue)
        {
            return cell[i];
        }
    }
    throw NonexistentKeyException(ERROR_CELL_KEY);
}

string Table::getLastElement() const
{
    return cell[index];
}

int Table::getKeyOfLastElement() const
{
    return key[index];
}

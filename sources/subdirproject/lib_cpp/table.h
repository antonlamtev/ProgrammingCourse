#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <new>

using namespace std;

class Table
{
    string* cell;
    int* key;
    int index;
    int currentSize;
    void allocateMoreMemory();
    string indexByKey(const int keyValue);
    const char* ERROR_CELL_KEY = "ERROR: there are not any cells with typed key";
    const int ADDITIONAL_SIZE = 10;

public:
    Table(int tableSize = 5);
    Table(const Table& object);
    ~Table();
    void put(const string value, const int key);
    string operator[](const int keyValue);
    //не нужны по заданию, но нужны для удобного тестирования
    string getLastElement();
    int getKeyOfLastElement();
};

#endif // TABLE_H

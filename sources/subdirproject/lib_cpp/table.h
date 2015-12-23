#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <new>

using namespace std;

class NonexistentKeyException : public exception
{
public:
    string getError()
    {
        return "ERROR: there are not any cells with typed key";
    }
};

class Table
{
    string* cell;
    int* key;
    int index;
    int currentSize;
    void allocateMoreMemory();
    const int ADDITIONAL_SIZE = 10;

public:
    Table(int tableSize = 5);
    Table(const Table& object);
    ~Table();
    void put(const string& value, const int& key);
    string operator[](const int keyValue) const;
    //не нужны по заданию, но нужны для удобного тестирования
    string getLastElement() const;
    int getKeyOfLastElement() const;
};

#endif // TABLE_H

#include <iostream>

#include "table.h"

using namespace std;

int main()
{
    Table table;
    table.put("Gang of four", 128);
    table.put("oop", 256);
    table.put("hello world", 512);
    table.index_by_key(256);
    return 0;
}


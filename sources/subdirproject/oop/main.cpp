#include <iostream>
#include "hash_table.h"

using namespace std;

int main()
{
    Hash_table table;

    table.add("hello world!", "00000000");
    table.add("oop is very cool!", "0000FFFF");
    table.add("Gang of four", "00ABCDEF");
    table.copy_a_cell(1, "000007E0");

    table.index_by_key("00000000");
    table.index_by_key("00000001");
    table.index_by_key("0000FFFF");
    table.index_by_key("00ABCDEF");
    table.index_by_key("000007E0");

    return 0;
}


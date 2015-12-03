#include <iostream>

#include "table.h"

int main()
{
    Table table;

    table.put("Gang of four", 128);
    table.put("oop", 256);
    table.put("hello world", 512);
    table.put("zenit", 64);
    table.put("mufc", 32);
    table.put("politech", 16);
    table.put("c++", 1024);
    cout << endl;
//    Table x(table);
//    table.print_table();
//    cout << endl;
//    x.print_table();

//    table.index_by_key(256);
//    table.index_by_key(32);


//    x.index_by_key(256);
//    x.index_by_key(32);


    return 0;
}


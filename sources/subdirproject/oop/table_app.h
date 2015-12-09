#ifndef TABLE_APP_H
#define TABLE_APP_H

#define EXIT_CODE 9

#include "table.h"

using namespace std;

class Table_app
{
    Table table;
    void put_cell_key();
    void find_cell_by_key();
    void copy_object();

public:
    Table_app();
    ~Table_app();
    void menu();
};

#endif // TABLE_APP_H

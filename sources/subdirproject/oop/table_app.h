#ifndef TABLE_APP_H
#define TABLE_APP_H

#define EXIT_CODE 9

#include "table.h"

#include <cstdlib>

using namespace std;

class Table_app
{
    Table table;
public:
    Table_app();
    ~Table_app();
    void menu();
};

#endif // TABLE_APP_H

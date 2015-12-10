#ifndef TABLEAPP_H
#define TABLEAPP_H

#include "table.h"

using namespace std;

class TableApp
{
    Table table;
    void putCellKey();
    void findCellByKey();
    void copyObject();
    const int EXIT_CODE = 9;
public:
    TableApp();
    ~TableApp();
    void menu();
};

#endif // TABLEAPP_H

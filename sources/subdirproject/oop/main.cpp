#include "table.h"

int main()
{
    Table table;
    table.put("sfd", 227);
    table.put("sgsgad s", 64);
    table.put("mufcggmu", 128);
    table.put("ilr", 256);
    table.put("spb", 32);
    table.put("russia", 1024);

    cout << table.get_number_of_elements() << endl;
    cout << table.get_current_size() << endl;

    cout << table[228] << endl;
    return 0;
}


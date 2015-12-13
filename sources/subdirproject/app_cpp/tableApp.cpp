#include "tableApp.h"
#include "table.h"

TableApp::TableApp()
{

}

TableApp::~TableApp()
{

}

void TableApp::menu()
{
    int key;
    do
    {
        cout << "Выберите вариант\n";
        cout <<"1)Положить в таблицу строковое значение и целочисленный ключ\n"
               "2)Найти строку по ключу\n"
               "3)Копировать текущий объект в другой\n"
               "9)Завершить работу программы\n";
        cin >> key;
        switch (key)
        {
            case 1:
            {
                putCellKey();
                break;
            }
            case 2:
            {
                findCellByKey();
                break;
            }
            case 3:
            {
                copyObject();
                break;
            }
        }
    }
    while (key != EXIT_CODE);
}


void TableApp::putCellKey()
{
    string str;
    int k;
    cout << "Введите строковое значение\n";
    getline(cin >> ws, str);
    cout << "Введите целочисленный ключ\n";
    cin >> k;
    cin.ignore();
    table.put(str, k);
}

void TableApp::findCellByKey()
{
    int k;
    cout << "Введите целочисленный ключ\n";
    cin >> k;
    try
    {
        cout << table[k];
    }
    catch(const char* e)
    {
        cout << e;
    }

    cout << endl;
}

void TableApp::copyObject()
{
    Table newTable(table);
}

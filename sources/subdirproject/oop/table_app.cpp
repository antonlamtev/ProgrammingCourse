#include "table_app.h"
#include "table.h"

Table_app::Table_app()
{

}

Table_app::~Table_app()
{

}

void Table_app::menu()
{
    int key;
    do
    {
        //system("clear");
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
                string str;
                int k;
                cout << "Введите строковое значение\n";
                getline(cin >> ws, str);
                cout << "Введите целочисленный ключ\n";
                cin >> k;
                cin.ignore();
                table.put(str,k);
                break;
            }
            case 2:
            {
                int k;
                cout << "Введите целочисленный ключ\n";
                cin >> k;
                cout << table[k];
                cout << endl;
                break;
            }
            case 3:
            {
                Table new_table(table);
                break;
            }
        }
    }
    while (key != EXIT_CODE);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main_menu.h"
#include "help.h"
#include "exchange.h"
#include "exchange_change.h"
#include "queens.h"
#include "queens_out.h"
#include "queens_result.h"
#include "matrix.h"
#include "quotient.h"
#include "quotient_process.h"
#include "matrix_algorithms.h"
#include "centered_lines.h"
#include "centered_lines_algorithms.h"

#define put_error puts("Неправильный ввод параметров!!!");


int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (!strcmp(argv[1], "--interactive"))
            main_menu();
        else if (!strcmp(argv[1], "--help"))
        {
            if (argc == 2)
                help(0);
            else if (argc == 3)
            {
                if (!strcmp(argv[2], "--exchange"))
                    help(1);
                else if (!strcmp(argv[2], "--queens"))
                    help(2);
                else if (!strcmp(argv[2], "--matrix"))
                    help(3);
                else if (!strcmp(argv[2], "--quotient"))
                    help(4);
                else if (!strcmp(argv[2], "--centered_lines"))
                    help(5);
            }
            else if (argc > 3)
            {
                put_error;
                help(0);
            }
        }
        else if (!strcmp(argv[1], "--exchange"))
        {
            if (argc == 2)
                exchange();
            else if (argc == 3)
            {
                int num = atoi(argv[2]);
                int fives, twos, ones;

                change_by_coins(num, &fives, &twos, &ones);
                printf("Пятирублёвых монет: %i\nДвухрублёвых монет: %i\nРублёвых монет: %i\n", fives, twos, ones);
            }
            else
            {
                put_error;
                help(1);
            }
        }
        else if (!strcmp(argv[1], "--queens"))
        {
            if (argc == 2)
                queens();
            else if (argc == 8)
            {
                int x1 = atoi(argv[2]), y1 = atoi(argv[3]),
                    x2 = atoi(argv[4]), y2 = atoi(argv[5]),
                    x3 = atoi(argv[6]), y3 = atoi(argv[7]);

                queens_out(queens_result(x1, y1, x2, y2, x3, y3));
            }
            else
            {
                put_error;
                help(2);
            }
        }
        else if (!strcmp(argv[1], "--quotient"))
        {
            if (argc == 2)
                quotient();
            else if (argc == 4)
            {
                int M = atoi(argv[2]), N = atoi(argv[3]);
                quotient_out(M, N);
            }
            else
            {
                put_error;
                help(4);
            }
        }
        else if (!strcmp(argv[1], "--matrix"))
        {
            if (argc == 2)
            {
                matrix("matrix.in", "matrix.out");
                puts("Программа выполнена!!!");
            }
            if (argc == 4)
            {
                matrix(argv[2], argv[3]);
                puts("Программа выполнена!!!");
            }
            else if (argc > 4 || argc == 3)
            {
                put_error;
                help(3);
            }
        }
        else if (!strcmp(argv[1], "--centered_lines"))
        {
            if (argc == 2)
            {
                centered_lines("lines.in", "lines.out");
                puts("Программа выполнена!!!");
            }
            else if (argc == 4)
            {
                centered_lines(argv[2], argv[3]);
                puts("Программа выполнена!!!");
            }
            else if (argc == 3 || argc > 4)
            {
                put_error;
                help(5);
            }
        }
        else
        {
            puts("Неправильный параметр командной строки!!!");
            help(0);
        }
    }
    else
    {
        char key;
        do
        {
            system("clear");
            puts("Вы запустили прогамму без параметров!!!");
            puts("Выберите вариант продолжения");
            puts("1)Получить информацию о пользовании\n2)Завершить программу");
            scanf("%c", &key);
        }
        while (key < '1' || key > '2');
        switch (key)
        {
            case '1':
                help(0);
                break;
            case '2':
                exit(0);
                break;
        }
    }
    return 0;
}

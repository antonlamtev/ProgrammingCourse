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
#include "lines_symmetrization.h"
#include "lines_symmetrization_algorithms.h"

#define put_error puts("Неправильный ввод параметров!!!");

/// Хорошо, если работает, но функция длинновата, нужно подумать, как разбить на функции поменьше
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (!strcmp(argv[1], "--interactive"))
            main_menu();
        else if (!strcmp(argv[1], "--help"))
        {
            if (argc == 2)
                help();
            else if (argc == 3)
            {
                if (!strcmp(argv[2], "--exchange"))
                    help_exchange();
                else if (!strcmp(argv[2], "--queens"))
                    help_queens();
                else if (!strcmp(argv[2], "--matrix"))
                    help_matrix();
                else if (!strcmp(argv[2], "--quotient"))
                    help_quotient();
                else if (!strcmp(argv[2], "--lines_symmetrization"))
                    help_lines_symmetrization();
            }
            else if (argc > 3)
            {
                put_error;
                help();
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
                help_exchange();
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
                help_queens();
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
                help_quotient();
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
                help_matrix();
            }
        }
        else if (!strcmp(argv[1], "--lines_symmetrization"))
        {
            if (argc == 2)
            {
                lines_symmetrization("lines.in", "lines.out");
                puts("Программа выполнена!!!");
            }
            else if (argc == 4)
            {
                lines_symmetrization(argv[2], argv[3]);
                puts("Программа выполнена!!!");
            }
            else if (argc == 3 || argc > 4)
            {
                put_error;
                help_lines_symmetrization();
            }
        }
        else
        {
            puts("Неправильный параметр командной строки!!!");
            help();
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
                help();
                break;
            case '2':
                exit(0);
                break;
        }
    }
    return 0;
}

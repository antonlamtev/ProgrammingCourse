#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "exchange.h"
#include "queens.h"
#include "quotient.h"
#include "matrix.h"
#include "lines_symmetrization.h"

#define put_error puts("Неправильный ввод параметров!!!");

void help_parameters(int argc, char** argv)
{
    switch (argc)
    {
        case 2:
            help();
            break;
        case 3:
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
            break;
        default:
            put_error;
            help();
            break;
    }
}

/// Хорошо, если работает, но функция длинновата, нужно подумать, как разбить на функции поменьше
int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        if (!strcmp(argv[1], "--interactive"))
            main_menu();
        else if (!strcmp(argv[1], "--help"))
        {
            help_parameters(argc, argv);
        }
        else if (!strcmp(argv[1], "--exchange"))
        {
            if (argc == 2)
                exchange();
            else if (argc == 3)
            {
                int num = atoi(argv[2]);
                struct purse coins;
                coins = change_by_coins(num);
                printf("Пятирублёвых монет: %i\nДвухрублёвых монет: %i\nРублёвых монет: %i\n", coins.fives, coins.twos, coins.ones);
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
                struct coordinate x;
                struct coordinate y;
                x.first = atoi(argv[2]);
                y.first = atoi(argv[3]);
                x.second = atoi(argv[4]);
                y.second = atoi(argv[5]);
                x.third = atoi(argv[6]);
                y.third = atoi(argv[7]);

                display_result(queens_result(x, y));
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
                int m = atoi(argv[2]), n = atoi(argv[3]);
                int count = 0;
                int index = -1;
                char* buffer = (char*) calloc(1000, sizeof(char));

                put_result_to_array(buffer, m, n, index, &count);
                int i;
                for (i = 0; i <= count; ++i)
                    printf("%c", buffer[i]);

                puts("");
                free(buffer);
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
            }
            if (argc == 4)
            {
                matrix(argv[2], argv[3]);
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
            }
            else if (argc == 4)
            {
                lines_symmetrization(argv[2], argv[3]);
            }
            else if (argc == 3 || argc > 4)
            {
                put_error;
                help_lines_symmetrization();
            }
        }
        else
        {
            put_error;
            help();
        }
    }
    else
    {
        menu_no_parameters();
    }
    return 0;
}

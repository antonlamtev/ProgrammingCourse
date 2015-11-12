#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main_menu.h"
#include "help.h"
#include "exchange.h"
#include "exchange_out.h"
#include "queens.h"
#include "queens_out.h"
#include "queens_result.h"
#include "matrix.h"
#include "quotient.h"
#include "matrix_algorithms.h"
#include "centered_lines.h"

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
                help(0);
        }
        else if (!strcmp(argv[1], "--exchange"))
        {
            if (argc == 2)
                exchange();
            else if (argc == 3)
            {
                int num = atoi(argv[2]);
                exchange_out(num);
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
            else
                help(4);
        }
        else if (!strcmp(argv[1], "--matrix"))
        {
            if (argc == 2)
            {
                matrix();
                puts("Прграмма выполнена!!!");
            }
            if (argc == 4)
            {

                FILE *in, *out;
                in = fopen(argv[2], "r");
                out = fopen(argv[3], "w");
                int **P;
                int n, i, j;
                fscanf(in, "%i", &n);

                P = (int **) malloc(n * sizeof(int*));
                for (i = 0; i < n; ++i)
                    P[i] = (int *) malloc(n * sizeof(int));

                for (i = 0; i < n; ++i)
                    for (j = 0; j < n; ++j)
                        fscanf(in, "%i\n", &P[i][j]);

                buble_sort_of_lines(P, n);

                for (i = 0; i < n; ++i)
                {
                    for (j = 0; j < n; ++j)
                        fprintf(out, "%i ", P[i][j]);
                    fprintf(out, "\n");
                }

                for (i = 0; i < n; ++i)
                    free(P[i]);
                free(P);
                fclose(in);
                fclose(out);
            }
            else if (argc > 4 || argc == 3)
            {
                put_error;
                help(3);
            }
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
    //main_menu();
    return 0;
}

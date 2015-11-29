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

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        if (!strcmp(argv[1], "--interactive") && argc == 2)
            main_menu();
        else if (!strcmp(argv[1], "--help"))
        {
            help_parameters(argc, argv);
        }
        else if (!strcmp(argv[1], "--exchange"))
        {
            exchange_parameters(argc, argv);
        }
        else if (!strcmp(argv[1], "--queens"))
        {
            queens_parameters(argc, argv);
        }
        else if (!strcmp(argv[1], "--quotient"))
        {
            quotient_parameters(argc, argv);
        }
        else if (!strcmp(argv[1], "--matrix"))
        {
            matrix_parameters(argc, argv);
        }
        else if (!strcmp(argv[1], "--lines_symmetrization"))
        {
            lines_symmetrization_parameters(argc, argv);
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

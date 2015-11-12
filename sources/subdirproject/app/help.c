#include <stdio.h>
#include "help_further_help.h"

void help(int key)
{
    switch (key)
    {
        case 0:
            help_help();
            break;
        case 1:
            help_exchange();
            break;
        case 2:
            help_queens();
            break;
        case 3:
            help_matrix();
            break;
        case 4:
            help_quotient();
            break;
        case 5:
            help_centered_lines();
            break;
    }

}

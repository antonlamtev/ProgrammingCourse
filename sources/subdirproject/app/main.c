#include <stdio.h>
#include <string.h>
#include "main_menu.h"
#include "help.h"
#include "exchange.h"


int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "--interactive") == 0)
            main_menu();
        else if (strcmp(argv[1], "--help") == 0)
            help();
        else if ((strcmp(argv[1], "--exchange") == 0))
        {
            exchange();
//            if (argc > 2)
//                exchange();
//            else
//                help();
        }
    }
    //main_menu;
    return 0;
}

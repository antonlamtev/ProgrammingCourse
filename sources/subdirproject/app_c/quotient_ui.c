#include <stdio.h>
#include <stdlib.h>

#include "quotient.h"
#include "main.h"

void quotient(void)
{
    int m, n;
    puts("Введите 2 числа");
    scanf("%i%i", &m, &n);
    puts("");
    char* buffer = (char*) calloc(1000, sizeof(char));

    put_result_to_array(buffer, m, n);

    puts(buffer);

    free(buffer);
}

void quotient_parameters(int argc, char** argv)
{
    switch (argc)
    {
        case 2:
            quotient();
            break;

        case 4:
        {
            int m = atoi(argv[2]), n = atoi(argv[3]);
            char* buffer = (char*) calloc(1000, sizeof(char));

            put_result_to_array(buffer, m, n);

            puts(buffer);

            free(buffer);
            break;
        }
        default:
            put_error;
            help_quotient();
            break;
    }
}

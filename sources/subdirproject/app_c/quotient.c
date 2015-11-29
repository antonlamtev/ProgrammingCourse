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

void quotient_parameters(int argc, char** argv)
{
    int m, n;
    int count;
    int index;
    char* buffer;
    int i;
    switch (argc)
    {
        case 2:
            quotient();
            break;

        case 4:
            m = atoi(argv[2]), n = atoi(argv[3]);
            count = 0;
            index = -1;
            buffer = (char*) calloc(1000, sizeof(char));

            put_result_to_array(buffer, m, n, index, &count);
            for (i = 0; i <= count; ++i)
                printf("%c", buffer[i]);

            puts("");
            free(buffer);
            break;

        default:
            put_error;
            help_quotient();
            break;
    }
}

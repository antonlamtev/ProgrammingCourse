#include <stdio.h>
#include "quotient.h"

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

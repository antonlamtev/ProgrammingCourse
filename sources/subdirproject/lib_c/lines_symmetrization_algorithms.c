#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lines_symmetrization.h"

int determine_file_proportions(char *input_file_name, int *number_of_lines, int *max_length_of_line)
{
    const int maximum_length_of_line = 256;
    FILE *in;
    in = fopen(input_file_name, "r");
    char *str;
    str = (char *) calloc(maximum_length_of_line, sizeof(char));
    int count = 0;
    *max_length_of_line = 0;
    while (!feof(in))
    {
        fgets(str, maximum_length_of_line, in);
        if (strlen(str) > *max_length_of_line) //тут компилятор выдает странное предупреждение. по мне, так
            *max_length_of_line = strlen(str); //вполне нормально сравнивать число со знаком и без
        ++count;
    }
    *number_of_lines = count;
    free(str);
    fclose(in);
    return 1;//пока так. потом сделаю нормально
}

void symmetrize_line(char *final_line, char *initial_line, int max_length_of_line)
{
        int left_indent = (max_length_of_line - strlen(initial_line)) / 2;

        memset(final_line, ' ', left_indent);
        final_line[left_indent] = '\0';
        strcat(final_line, initial_line);
}

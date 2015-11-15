#include <stdio.h>
#include <string.h>

int calculate_max_length(char *str, FILE *input, int *number_of_lines)
{
    const int maximum_length_of_line  = 256;
    int max_length_of_line = 0, count = 0;
    while (!feof(input))
    {
        fgets(str, maximum_length_of_line, input);
        if (strlen(str) > max_length_of_line) //тут компилятор выдает странное предупреждение. по мне, так
            max_length_of_line = strlen(str); //вполне нормально сравнивать число со знаком и без
        ++count;
    }
    *number_of_lines = count;
    return max_length_of_line;
}

void symmetrize_text(char *final_line, char *initial_line, FILE *input, FILE *output, int max_length_of_line, int number_of_lines)
{
    int i;
    for (i = 0; i < number_of_lines; ++i)
    {
        fgets(initial_line, max_length_of_line, input);
        int left_indent = (max_length_of_line - strlen(initial_line)) / 2;

        int j;
        for (j = 0; j < left_indent; ++j)
            final_line[j] = ' ';
        final_line[left_indent] = '\0';
        strcat(final_line, initial_line);
        fputs(final_line, output);
    }
}

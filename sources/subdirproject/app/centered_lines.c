#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "centered_lines_algorithms.h"

/// Первая половина фукнции переместится в calculate_max_length,
/// во вторую половину переместится часть кода связанная с чтением данных из symmetrize_text

void centered_lines(char *input_file_name, char *output_file_name)
{
    FILE *in, *out;
    in = fopen(input_file_name, "r");
    char *str;
    /// можно вынести в макрос в заголовочный файл,
    /// тогда не надо быдет дублировать эту переменную в двух файлах.
    /// если изменить это число здесь, очень легко забыть поменять его в библиотеке
    /// а библиотеку еще и придется перекомпилировать.
    const int maximum_length_of_line = 256;
    str = (char *) calloc(maximum_length_of_line, sizeof(char));
    int max_length_of_line = 0;
    int number_of_lines;
    max_length_of_line = calculate_max_length(str, in, &number_of_lines);
    free(str);
    /// хм... Компилятор не может найти прототип функции.
    /// Может ее не быть в stdio.h?
    /// Действительно! ее там нету... зато есть fclose в пару к fopen
    close(in); //странное предупреждение компилятора. а мне все нравится

    char *initial_line = (char *) calloc (max_length_of_line, sizeof(char));
    char *final_line = (char *) calloc (max_length_of_line, sizeof(char));
    in = fopen(input_file_name, "r");
    out = fopen(output_file_name, "w");

    ///symmetrize_text(final_line, initial_line, in, out, max_length_of_line, number_of_lines);

    int i;
    for (i = 0; i < number_of_lines; ++i)
    {
        fgets(initial_line, max_length_of_line, in);
        symmetrize_text_new(final_line, initial_line, max_length_of_line);
        fputs(final_line, out);
    }

    free(initial_line);
    free(final_line);
    close(in);
    close(out);
}


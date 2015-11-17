#include <stdio.h>
#include <string.h>


/// Я думаю, для этой функции уместно было бы самостоятельно открывать и закрывать файл
///
/// Выглядит неочевидно, когда эта функция "высчитывает максимальную длину",
/// и еще заодно в последнем параметре устанавливает количество строк в файле.
///
/// int determine_file_proportions(char* filename, int* number_of_lines, int* maximum_length)
/// Пусть сделает всю работу и вернет успех или неудачу
///
int calculate_max_length(char *str, FILE *input, int *number_of_lines)
{
    /// можно вынести в макрос в заголовочный файл,
    /// тогда не надо быдет дублировать эту переменную в двух файлах.
    /// если изменить это число здесь, очень легко забыть поменять его в библиотеке
    /// а библиотеку еще и придется перекомпилировать.
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
        /// не думали memset вместо этого цикла?
        for (j = 0; j < left_indent; ++j)
            final_line[j] = ' ';
        final_line[left_indent] = '\0';
        strcat(final_line, initial_line);
        fputs(final_line, output);
    }
}


/// Эта функция не занимается чтением и записью файла.
/// Ее можно использовать читая из файла, записывая в консоль,
/// читая из сети, записывая в файл, и т.д.
/// Таким образом ее проще переиспользовать.
void symmetrize_text_new(char *final_line, char *initial_line, int max_length_of_line)
{
        int left_indent = (max_length_of_line - strlen(initial_line)) / 2;

        int j;
        for (j = 0; j < left_indent; ++j)
            final_line[j] = ' ';
        final_line[left_indent] = '\0';
        strcat(final_line, initial_line);
}

#include <stdio.h>
#include <stdlib.h>
#include "lines_symmetrization.h"
#include "main.h"

void lines_symmetrization(char* input_file_name, char* output_file_name)
{
    FILE* in;
    FILE* out;
    int number_of_lines, max_length_of_line;
    determine_file_proportions(input_file_name, &number_of_lines, &max_length_of_line);

    char* initial_line = (char*) calloc (max_length_of_line, sizeof(char));
    char* final_line = (char*) calloc (max_length_of_line, sizeof(char));
    in = fopen(input_file_name, "r");
    out = fopen(output_file_name, "w");

    int i;
    for (i = 0; i < number_of_lines; ++i)
    {
        fgets(initial_line, max_length_of_line, in);
        symmetrize_line(final_line, initial_line, max_length_of_line);
        fputs(final_line, out);
    }

    free(initial_line);
    free(final_line);
    fclose(in);
    fclose(out);
    puts("Программа успешно выполнена!");
}

void lines_symmetrization_parameters(int argc, char** argv)
{
    switch (argc)
    {
        case 2:
            lines_symmetrization("lines.in", "lines.out");
            break;
        case 4:
            lines_symmetrization(argv[2], argv[3]);
            break;
        default:
            put_error;
            help_lines_symmetrization();
            break;
    }
}

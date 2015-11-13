#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "centered_lines_algorithms.h"



void centered_lines(void)
{
    FILE *in, *out;
    in = fopen("lines.in", "r");
    char *str;
    const int maximum_length_of_line = 256;
    str = (char *) calloc(maximum_length_of_line, sizeof(char));
    int max_length_of_line = 0;
    int number_of_lines;
    max_length_of_line = calculate_max_length(str, in, &number_of_lines);
    free(str);
    close(in);

    char *initial_line = (char *) calloc (max_length_of_line, sizeof(char));
    char *final_line = (char *) calloc (max_length_of_line, sizeof(char));
    in = fopen("lines.in", "r");
    out = fopen("lines.out", "w");
    symmetrize_text(final_line, initial_line, in, out, max_length_of_line, number_of_lines);
    free(initial_line);
    free(final_line);
    close(in);
    close(out);
}


#ifndef LINES_SYMMETRIZATION_H
#define LINES_SYMMETRIZATION_H

#ifdef __cplusplus
extern "C" {
#endif

void symmetrize_line(char *final_line, char *initial_line, int max_length_of_line);
void determine_file_proportions(char *input_file_name, int *number_of_lines, int *max_length_of_line);

#ifdef __cplusplus
}
#endif

#endif // LINES_SYMMETRIZATION_H
